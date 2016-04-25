// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#include "kruleengine.h"

KRuleEngine::KRuleEngine(const QString &kruleFilename, bool s_setDot) {
    FILE *kruleFile = fopen(kruleFilename.toStdString().c_str(), "r");
    createDot = s_setDot;
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

QList<KRuleOutput*> KRuleEngine::verifyQMLFiles(const QStringList &qmlFilenames) {
    QMap<QString, KRuleOutput*> ruleViolationsMap;
    foreach (const QString &qmlFilename, qmlFilenames) {
        QMap<QString, KRuleOutput*> otherMap = verifyQMLFile(qmlFilename);
        ruleViolationsMap = mergeOccurranceMap(ruleViolationsMap, otherMap);
    }

    return ruleViolationsMap.values();
}

QMap<QString, KRuleOutput*> KRuleEngine::verifyQMLFile(const QString &qmlFilename) {
    QString code = readCode(qmlFilename);

    QQmlJS::Engine engine;
    QQmlJS::Lexer lexer = QQmlJS::Lexer(&engine);

    QFileInfo info(qmlFilename);
    bool isJavaScript = info.suffix().toLower() == QLatin1String("js");
    lexer.setCode(code, /*line = */ 1, /*qmlMode=*/ !isJavaScript);
    QQmlJS::Parser parser = QQmlJS::Parser(&engine);
    bool success = isJavaScript ? parser.parseProgram() : parser.parse();

    if (!success) {
        foreach (const QQmlJS::DiagnosticMessage &m, parser.diagnosticMessages()) {
            qWarning("%s:%d : %s", qPrintable(qmlFilename), m.loc.startLine, qPrintable(m.message));

        }
    }

    // Parse the QML AST and produce a wrapped version of it.
    QmlVisitor qmlVisitor = QmlVisitor(code, qmlFilename);
    parser.ast()->accept(&qmlVisitor);
    NodeWrapper* wrappedRoot = qmlVisitor.getWrappedRoot();
    wrappedRoot->print();

    KRuleVisitor kruleVisitor = KRuleVisitor(qmlFilename, code, wrappedRoot);
    kruleTree->accept(&kruleVisitor);
    
    // create dot files of the wrapped AST
    if(createDot)
    {
        QString dotFile = qmlFilename;
        if(isJavaScript){
            dotFile.chop(2);
        }else{
            dotFile.chop(3);
        }
        dotFile.append("dot");
        QFile fl2(dotFile);
        if(fl2.open(QFile::WriteOnly | QFile::Truncate)){
            QTextStream out(&fl2);
            out << "digraph {" << qmlVisitor.getWrappedRoot()->getOutput() << " }";

        }
    }
    return kruleVisitor.getFailures();

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

QMap<QString, KRuleOutput*> KRuleEngine::mergeOccurranceMap(QMap<QString, KRuleOutput*> m1, QMap<QString, KRuleOutput*> m2) {
    foreach(QString key, m2.keys()) {
        if (m1.contains(key)) {
            KRuleOutput* ko = m1[key];
            ko->addCodeOccurrances(m2[key]);
            m1.insert(key, ko);
        } else {
            m1.insert(key, m2[key]);
        }
    }
    return m1;
}
