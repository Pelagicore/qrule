/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Sergio Martins <sergio.martins@kdab.com>
** Contact: http://www.qt.io/licensing/
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <stdio.h>
#include "gen/Parser.H"
#include "gen/Printer.H"
#include "gen/Absyn.H"
#include "Skeleton.H"

#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QCommandLineParser>
#include <QCoreApplication>

#include "QmlVisitor.h"
#include "private/qqmljslexer_p.h"
#include "private/qqmljsparser_p.h"
#include "private/qqmljsengine_p.h"

static bool verifyKrules(QQmlJS::AST::UiProgram *qmlAST, RuleSet *kruleTree, const bool silent) {
    Skeleton *skeleton = new Skeleton();
    kruleTree->accept(skeleton);
    if (!silent) {
        printf("%i", skeleton->getResult());
    }
    return true;
}

static QQmlJS::AST::UiProgram* parseQML(const QString qmlFilename, QmlVisitor *qv,const bool silent) {
    QFile file(qmlFilename);
    if (!file.open(QFile::ReadOnly)) {
        qWarning() << "Failed to open file" << qmlFilename << file.error();
        exit(-1);
    }

    QString code = QString::fromUtf8(file.readAll());
    file.close();

    qv->setCode(code);
    QQmlJS::Engine engine;
    QQmlJS::Lexer lexer(&engine);

    QFileInfo info(qmlFilename);
    bool isJavaScript = info.suffix().toLower() == QLatin1String("js");
    lexer.setCode(code, /*line = */ 1, /*qmlMode=*/ !isJavaScript);
    QQmlJS::Parser parser(&engine);
    bool success = isJavaScript ? parser.parseProgram() : parser.parse();

    if (!success && !silent) {
        foreach (const QQmlJS::DiagnosticMessage &m, parser.diagnosticMessages()) {
            qWarning("%s:%d : %s", qPrintable(qmlFilename), m.loc.startLine, qPrintable(m.message));
        }
    }

    return parser.ast();
}

static RuleSet* parseKRuleFile(const QString kruleFilename, const bool silent) {
    const char* flnm = kruleFilename.toUtf8().data();

    FILE *kruleFile = fopen(flnm, "r");
    if (!kruleFile) {
      qWarning() << "Error opening input file.\n";
      exit(1);
    }
    RuleSet *kruleTree = pRuleSet(kruleFile);

    if (kruleTree) {
        if (!silent) {
            ShowAbsyn s = ShowAbsyn();
            qDebug() << s.show(kruleTree);
            qDebug() << "[Linearized Tree]\n";
            PrintAbsyn p = PrintAbsyn();
            qDebug() << p.print(kruleTree);
        }
        return kruleTree;
    } else {
        exit(-1);
    }
}

int main(int argv, char *argc[]) {
    // Setup commandline parser
    QCoreApplication app(argv, argc);
    QCoreApplication::setApplicationName("qmllint");
    QCoreApplication::setApplicationVersion("1.0");
    QCommandLineParser parser;
    parser.setApplicationDescription(QLatin1String("QML syntax verifier"));
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption silentOption(QStringList() << "s" << "silent", QLatin1String("Don't output syntax errors"));
    parser.addOption(silentOption);

    parser.addPositionalArgument(QLatin1String("krule"), QLatin1String("KRule rules file"));
    parser.addPositionalArgument(QLatin1String("files"), QLatin1String("list of qml or js files to verify"));

    parser.process(app);

    // Verify parsed arguments
    if (parser.positionalArguments().length() < 2) {
        parser.showHelp(-1);
    }

    const bool silent = parser.isSet(silentOption);

    // Parse KRule
    QStringList parsedArguments = parser.positionalArguments();
    const QString &kruleFilename = parsedArguments.takeFirst();

    RuleSet *kruleTree = parseKRuleFile(kruleFilename, silent);

    // Run verification
    bool success = true;
    QmlVisitor *qv = new QmlVisitor("");
    foreach (const QString &filename, parsedArguments) {
        QQmlJS::AST::UiProgram *qmlAST = parseQML(filename, qv, silent);
        qmlAST->accept(qv);
        success &= verifyKrules(qmlAST, kruleTree, silent);
    }

    return success ? 0 : -1;
}
