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
#include "Parser.H"
#include "Printer.H"
#include "Absyn.H"
#include "Skeleton.H"

#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QCommandLineParser>
#include <QCoreApplication>

#include <private/qv4value_inl_p.h>
#include <private/qqmljslexer_p.h>
#include <private/qqmljsparser_p.h>
#include <private/qqmljsengine_p.h>

static bool verifyKrules(QQmlJS::AST::UiProgram *qmlAST, RuleSet *kruleTree)
{
    Skeleton *skeleton = new Skeleton();
    kruleTree->accept(skeleton);
    printf("%i", skeleton->getResult());
    return true;
}

static bool lint_file(const QString &filename, const RuleSet *kruleTree, bool silent)
{
    QFile file(filename);
    if (!file.open(QFile::ReadOnly)) {
        qWarning() << "Failed to open file" << filename << file.error();
        return false;
    }

    QString code = QString::fromUtf8(file.readAll());
    file.close();

    QQmlJS::Engine engine;
    QQmlJS::Lexer lexer(&engine);

    QFileInfo info(filename);
    bool isJavaScript = info.suffix().toLower() == QLatin1String("js");
    lexer.setCode(code, /*line = */ 1, /*qmlMode=*/ !isJavaScript);
    QQmlJS::Parser parser(&engine);
    bool success = isJavaScript ? parser.parseProgram() : parser.parse();

    if (!success && !silent) {
        foreach (const QQmlJS::DiagnosticMessage &m, parser.diagnosticMessages()) {
            qWarning("%s:%d : %s", qPrintable(filename), m.loc.startLine, qPrintable(m.message));
        }
    }

    return success;
}

int main(int argv, char *argc[])
{
    QCoreApplication app(argv, argc);
    QCoreApplication::setApplicationName("qmllint");
    QCoreApplication::setApplicationVersion("1.0");
    QCommandLineParser parser;
    parser.setApplicationDescription(QLatin1String("QML syntax verifier"));
    parser.addHelpOption();
    parser.addVersionOption();
    QCommandLineOption silentOption(QStringList() << "s" << "silent", QLatin1String("Don't output syntax errors"));
    parser.addOption(silentOption);

    // END WITH KRULE
    parser.addPositionalArgument(QLatin1String("krule"), QLatin1String("KRule rules file"));
    // QML FILES
    parser.addPositionalArgument(QLatin1String("files"), QLatin1String("list of qml or js files to verify"));


    parser.process(app);

    if (parser.positionalArguments().isEmpty()) {
        parser.showHelp(-1);
    }

    bool silent = parser.isSet(silentOption);
    bool success = true;
    printf("%i\n", silent);

    const QString &kruleFilename = parser.positionalArguments().first();
    FILE *kruleFile = fopen(kruleFilename, "r");
    if (!input)
    {
      fprintf(stderr, "Error opening input file.\n");
      exit(1);
    }
    /* The default entry point is used. For other options see Parser.H */
    RuleSet *kruleTree = pRuleSet(kruleFile);
    if (kruleTree) {
        ShowAbsyn *s = new ShowAbsyn();
        printf("%s\n\n", s->show(parse_tree));
        printf("[Linearized Tree]\n");
        PrintAbsyn *p = new PrintAbsyn();
        printf("%s\n\n", p->print(parse_tree));

        foreach (const QString &filename, parser.positionalArguments()) {
            success &= lint_file(filename, kruleTree, silent);
        }

        return success ? 0 : -1;
    }
    return -1;
}
