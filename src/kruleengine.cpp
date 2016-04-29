// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#include "kruleengine.h"

#include <QDir>

KRuleEngine::KRuleEngine(const QString &kruleFilename, bool s_setDot, QString path):createDot(s_setDot), path(path) {
    FILE *kruleFile = fopen(kruleFilename.toStdString().c_str(), "r");

    if (!kruleFile) {
      qWarning() << "Error opening krule file: " << kruleFilename;
      throw ParseException(QString(kruleFilename).prepend("Could not open KRule file "));
    }
    kruleTree = pRuleSet(kruleFile);

    if (kruleTree) {
        ShowAbsyn s = ShowAbsyn();
    //    qDebug() << s.show(kruleTree);
    //    qDebug() << "[Linearized Tree]\n";
        PrintAbsyn p = PrintAbsyn();
    //    qDebug() << p.print(kruleTree);
    } else {
        throw ParseException("Could not parse KRulefile");
    }
}

/**
 * @brief KRuleEngine::verifyQMLFiles
 * @param qmlFilenames
 * @return
 */
QList<KRuleOutput*> KRuleEngine::verifyQMLFiles(const QStringList &qmlFilenames) {

    foreach (const QString &qmlFilename, qmlFilenames) {
        QString p="";
        verifyQMLFile(p.append(path).append(qmlFilename));
    }
    return ruleViolations.values();
}


void KRuleEngine::verifyQMLFile(const QFileInfo &qmlFilename) {

    QString code = readCode(qmlFilename.absoluteFilePath());

    QQmlJS::Engine engine;
    QQmlJS::Lexer lexer = QQmlJS::Lexer(&engine);

    QFileInfo info(qmlFilename);
    bool isJavaScript = info.suffix().toLower() == QLatin1String("js");
    lexer.setCode(code, /*line = */ 1, /*qmlMode=*/ !isJavaScript);
    QQmlJS::Parser parser = QQmlJS::Parser(&engine);
    bool success = isJavaScript ? parser.parseProgram() : parser.parse();

    if (!success) {
        foreach (const QQmlJS::DiagnosticMessage &m, parser.diagnosticMessages()) {
            qWarning("%s:%d : %s", qPrintable(qmlFilename.absoluteFilePath()), m.loc.startLine, qPrintable(m.message));

        }
    }

    // with import -- do the same but extend without imports.
    QmlVisitor qmlVisitor = QmlVisitor(code, qmlFilename.absoluteFilePath());
    parser.ast()->accept(&qmlVisitor);

    NodeWrapper* wrappedRoot = qmlVisitor.getWrappedRoot();

    //1. Get list of imports.
    QList<NodeWrapper*> importFiles = wrappedRoot->getNodes("Import");
    QMap<QString, QString> importAliasMap;
    foreach(NodeWrapper* importNode, importFiles) {
        if (importNode->getToken("fileNameToken").contains("\"")) {
            QFileInfo info = QFileInfo(qmlFilename.canonicalPath().append("/")
                                       .append(importNode->getToken("fileNameToken").replace("\"","")));
            if (importNode->hasToken("asToken")) {
                importAliasMap.insert(info.absoluteFilePath(), importNode->getValue());
            }
            if (!importedASTs.contains(info.absoluteFilePath())) {
                verifyQMLFile(info);
            }
        }
    }


    //2. Add imported file to AST.
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

    wrappedRoot->print();

    // VERIFY
    KRuleVisitor kruleVisitor = KRuleVisitor(wrappedRoot);
    kruleTree->accept(&kruleVisitor);
    mergeOccurranceMap(kruleVisitor.getFailures());

    // ADD TO IMPORTEDASTSdirectorydirecdirectorytory
    NodeWrapper* objectPointer;
    if (wrappedRoot->getChildren().first()->getNodeType() == "ObjectDefinition") {
        objectPointer = new NodeWrapper(wrappedRoot->getChildren().first());
    } else {
        objectPointer = new NodeWrapper(wrappedRoot->getChildren().last());
    }

    importedASTs.insert(qmlFilename.absoluteFilePath(), objectPointer);


    // create dot files of the wrapped AST
    if(createDot)
    {
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

QMap<QString, QPair<float,QFileInfo>> KRuleEngine::parseQmlDirFile(const QFileInfo &qmldirFile, const float version) {
    QMap<QString, QPair<float, QFileInfo>> filemap;
    if (qmldirFile.exists()) {
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
                  // reference = cols.at(1);
                } else if (type == "plugin") {
                  //  reference = cols.at(1);
                } else if (type == "typeinfo") {
                  //  reference = cols.at(1);
                } else if (type == "classname") {
                  //  reference = cols.at(1);
                } else if (type == "depends") {
                    reference = cols.at(1);
                    readVersion = cols.at(2).toFloat();
                    QMap<QString, QPair<float, QFileInfo>> result =
                            parseQmlDirFile(QFileInfo(d, reference), version);
                    filemap.unite(result);

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
