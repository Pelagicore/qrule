// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#include "kruleengine.h"



/*!
 * \brief KRuleEngine::KRuleEngine Constructs a QRuleEngine by parsing a given QRule file.
 * \param kruleFilename A QString representing the path to the QRule file containing the rules to use.
 * \param importPaths a QStringList that specifes import paths. Can be empty.
 */
KRuleEngine::KRuleEngine(const QString &kruleFilename, QString path): importPath(path) {
    FILE *kruleFile = fopen(kruleFilename.toStdString().c_str(), "r");

    if (!kruleFile) {
      qWarning() << "Error opening krule file: " << kruleFilename;
      throw ParseException(QString(kruleFilename).prepend("Could not open KRule file "));
    }
    kruleTree = pRuleSet(kruleFile);

    if (kruleTree) {
    } else {
        throw ParseException("Could not parse KRulefile");
    }
}

/*!
 * \brief KRuleEngine::verifyQMLFiles Verifies the given QML files against the rules given at construction of this object.
 * \param qmlFilenames A list of the paths to all the QML files that should be verifed.
 * \return Any rule violations formatted as QRuleOutput
 */
QList<KRuleOutput*> KRuleEngine::verifyQMLFiles(const QStringList &qmlFilenames, bool renderDot) {

    foreach (const QString &qmlFilename, qmlFilenames) {
        verifyQMLFile(qmlFilename, renderDot);
    }
    return ruleViolations.values();
}


void KRuleEngine::extendAvailableFiles(const QFileInfo &qmlFilename, QMap<QString, QList<QFileInfo>> &avalibleFiles,
                                       QDir directory) {
    const QStringList nameFilter("*.qml");
    QStringList qmlFiles = directory.entryList(nameFilter);

    foreach (QString s, qmlFiles) {
        QFileInfo qFile = QFileInfo(directory,s);
        if(qFile != qmlFilename) {
            QList<QFileInfo> list;
            if(avalibleFiles.contains(qmlFilename.absoluteFilePath())) {
                list =avalibleFiles.take(qmlFilename.absoluteFilePath());
            }
            list.append(qFile);
            avalibleFiles.insert(qmlFilename.absoluteFilePath(),list);
        }
    }
}

void KRuleEngine::parseLiteralImports(NodeWrapper* wrappedRoot, QMap<QString, QString> &importAliasMap,
                                      const QFileInfo &qmlFilename, const bool renderDot) {
    QMap<QString, QList<QFileInfo>> avalibleFiles;

    QDir directory = qmlFilename.dir();
    extendAvailableFiles(qmlFilename, avalibleFiles, directory);

    foreach(NodeWrapper* importNode, wrappedRoot->getNodes("ImportLiteral")) {
        if (importNode->getToken("fileNameToken").contains("\"")) {
            QFileInfo info = QFileInfo(qmlFilename.canonicalPath().append("/")
                                       .append(importNode->getToken("fileNameToken").replace("\"","")));
            if (importNode->hasToken("asToken")) {
                importAliasMap.insert(info.absoluteFilePath(), importNode->getValue());
            }

            //catalog add all sub files to importlist and run verifyQMLFile
            if (info.completeSuffix() == "") {
                QDir directory(info.absoluteFilePath().append("/"));
                extendAvailableFiles(qmlFilename, avalibleFiles, directory);
            }

            foreach (QFileInfo f, avalibleFiles.take(qmlFilename.absoluteFilePath())) {
                foreach(NodeWrapper* objectDef, wrappedRoot->getNodes("ObjectDefinition")) {
                    if (objectDef->getValue() == f.baseName()) {

                        if (!importedASTs.contains(f.absoluteFilePath())) {
                             verifyQMLFile(f, renderDot);
                        }

                        importAliasMap.insert(f.absoluteFilePath(), f.baseName());

                    }
                }
            }
        }
    }
}

void KRuleEngine::parseUriImports(NodeWrapper* wrappedRoot, QMap<QString, QString> &importAliasMap, const bool renderDot) {
    foreach(NodeWrapper* importNode, wrappedRoot->getNodes("ImportUri")) {
        QFileInfo info = QFileInfo(importPath.absoluteFilePath().append("/")
                                   .append(importNode->getToken("fileNameToken"))
                                   .replace(".","/").append("/qmldir"));

        QMap<QString, QPair<float,QFileInfo>> qmldirInfo =
            parseQmlDirFile(info, importNode->getToken("versionToken").toFloat());

        QString prefix = "";
        if (importNode->hasToken("asToken")) {
            prefix = QString(importNode->getValue()).append(".");
        }

        foreach (QString key, qmldirInfo.keys()) {
            const QString fullName = prefix + key;
            QFileInfo f = qmldirInfo.value(key).second;
            foreach(NodeWrapper* objectDef, wrappedRoot->getNodes("ObjectDefinition")) {
                if (objectDef->getValue() == fullName) {
                    if (!importedASTs.contains(f.absoluteFilePath())) {
                         verifyQMLFile(f, renderDot);
                    }

                    importAliasMap.insert(f.absoluteFilePath(), fullName);
                }
            }
        }
    }
}

void KRuleEngine::verifyQMLFile(const QFileInfo &qmlFilename, const bool renderDot) {

    // Parse QML code
    QString code = readCode(qmlFilename.absoluteFilePath());

    QQmlJS::Engine engine;
    QQmlJS::Lexer lexer = QQmlJS::Lexer(&engine);

    QFileInfo info(qmlFilename);
    bool isJavaScript = info.suffix().toLower() == QLatin1String("js");
    lexer.setCode(code, /*line = */ 1, /*qmlMode=*/ !isJavaScript);
    QQmlJS::Parser parser = QQmlJS::Parser(&engine);
    bool successfullParse = isJavaScript ? parser.parseProgram() : parser.parse();

    if (!successfullParse) {
        foreach (const QQmlJS::DiagnosticMessage &m, parser.diagnosticMessages()) {
            qWarning("%s:%d : %s", qPrintable(qmlFilename.absoluteFilePath()),
                     m.loc.startLine, qPrintable(m.message));
        }
    }

    // Wrap QML AST
    QmlVisitor qmlVisitor = QmlVisitor(code, qmlFilename.absoluteFilePath());
    parser.ast()->accept(&qmlVisitor);
    NodeWrapper* wrappedRoot = qmlVisitor.getWrappedRoot();

    // Parse and verify all imports
    QMap<QString, QString> importAliasMap;
    parseUriImports(wrappedRoot, importAliasMap, renderDot);
    parseLiteralImports(wrappedRoot, importAliasMap, qmlFilename, renderDot);

    // Merge imported ASTs into top AST
    QList<NodeWrapper*> nodes = wrappedRoot->getNodes("ObjectDefinition");
    foreach(NodeWrapper* objectNode, nodes) {
        foreach(QString importedPath, importedASTs.keys()) {
            QString importName;
            if (importAliasMap.contains(importedPath)) {
                importName = importAliasMap.value(importedPath);
            } else {
                importName = QFileInfo(importedPath).baseName();
            }
            if (objectNode->getValue() == importName) {
                NodeWrapper* importedNode = importedASTs.value(importedPath);
                objectNode->merge(*importedNode);
            }
        }
    }

    // Verify wrapped AST
    KRuleVisitor kruleVisitor = KRuleVisitor(wrappedRoot);
    kruleTree->accept(&kruleVisitor);
    mergeOccurranceMap(kruleVisitor.getFailures());

    // Add top object node to map over imported asts
    NodeWrapper* objectPointer;
    if (wrappedRoot->getChildren().first()->getNodeType() == "ObjectDefinition") {
        objectPointer = new NodeWrapper(wrappedRoot->getChildren().first());
    } else {
        objectPointer = new NodeWrapper(wrappedRoot->getChildren().last());
    }

    importedASTs.insert(qmlFilename.absoluteFilePath(), objectPointer);

    // Create dot files of the wrapped AST
    if(renderDot) {
        QString dotFile = qmlFilename.absoluteFilePath();
        if(isJavaScript){
            dotFile.chop(2);
        } else {
            dotFile.chop(3);
        }
        dotFile.append("dot");
        QFile fl2(dotFile);
        if(fl2.open(QFile::WriteOnly | QFile::Truncate)){
            QTextStream out(&fl2);
            out << "digraph {" << qmlVisitor.getWrappedRoot()->getOutput() << " }";

        }
    }
}


/*!
 * \brief KRuleEngine::parseQmlDirFile parses a qmldir file.
 * \param qmldirFile The path to the qmldir file to parse.
 * \param version 1.0
 * \return The mapping of references to a pair of version and file path, for each member of the module. Will return empty map if the file does not exists.
 */
QMap<QString, QPair<float,QFileInfo>> KRuleEngine::parseQmlDirFile(const QFileInfo &qmldirFile, const float version) {
    QMap<QString, QPair<float, QFileInfo>> filemap;
    if (qmldirFile.exists()) {

        // Read qmldir file
        QString filePath = qmldirFile.absoluteFilePath();

        QFile file(filePath);
        file.open(QIODevice::ReadOnly);

        QTextStream in(&file);
        QStringList lines;
        while(!in.atEnd()) {
            QString line = in.readLine();
            lines.append(line);
        }

        file.close();

        // Iterate over each line
        QDir d = qmldirFile.dir();
        foreach(QString line, lines) {
            QString lc = QString(line);
            bool comment = lc.replace(" ", "").replace("\t", "").at(0) == '#';

            if (!comment) {
                QStringList cols = line.split(" ");

                QString type = cols.first();
                QString reference;
                float readVersion = 0;
                if (type == "module") {
                    reference = cols.at(1);
                }
                else if (type == "internal") {
                } else if (type == "plugin") {
                } else if (type == "typeinfo") {
                } else if (type == "classname") {
                } else if (type == "depends") {

                    // Find all dependancies and parse them aswell
                    reference = cols.at(1);
                    readVersion = cols.at(2).toFloat();
                    QMap<QString, QPair<float, QFileInfo>> result = parseQmlDirFile(QFileInfo(d, reference), version);

                    // Prefix with the module name to make them look like a part of this module
                    QString prefix = qmldirFile.dir().dirName();
                    foreach(QString key, result.keys()) {
                        filemap.insert(prefix + "." + key, result.value(key));
                    }

                } else if (type == "designersupported") {
                    reference = cols.at(1);
                } else {
                    if (type == "singleton") {
                       reference = cols.at(1);
                      readVersion = cols.at(2).toFloat();
                    } else {
                       type = "default";
                       reference = cols.at(0);
                       readVersion = cols.at(1).toFloat();
                    }

                    // Add object with reference mapping and version number
                    // Make sure that only the latest version that is not newer than the requested
                    // version is selected.
                    if (readVersion <= version &&
                            (!filemap.contains(reference) || readVersion > filemap.value(reference).first)) {
                        filemap.insert(reference, QPair<float, QFileInfo>(readVersion, QFileInfo(d, cols.last())));
                    }
                }
            }
        }
    }

    return filemap;
}

QString KRuleEngine::readCode(QString qmlFilename) {
    QFile file(qmlFilename);
    if (!file.open(QFile::ReadOnly)) {
        qWarning() << "Failed to open file" << qmlFilename << file.error();
        throw ParseException(qmlFilename.prepend("Could not open file "));
    }

    QString code = QString::fromUtf8(file.readAll());
    file.close();
    return code;
}

void KRuleEngine::mergeOccurranceMap(const QMap<QString, KRuleOutput*> &map) {
    foreach(QString key, map.keys()) {
        if (ruleViolations.contains(key)) {
            KRuleOutput* ko = ruleViolations[key];
            ko->addCodeOccurrances(map[key]);
            ruleViolations.insert(key, ko);
        } else {
            ruleViolations.insert(key, map[key]);
        }
    }
}
