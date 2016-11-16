// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#ifndef QRULEENGINE_H
#define QRULEENGINE_H

#include "qrulevisitor.h"

#include <QMap>
#include <QString>
#include <QFileInfo>
#include <QPair>

#include <output/QRuleOutput.h>

#include "ParseException.h"

#include "gen/Parser.H"
#include "gen/Printer.H"
#include "gen/Absyn.H"

#include "private/qqmljslexer_p.h"
#include "private/qqmljsparser_p.h"
#include "private/qqmljsengine_p.h"
#include "QmlVisitor.h"
#include <QDir>


/*!
 * \brief The QRuleEngine class Verifies a set of QRules on QML files.
 */
class QRuleEngine {
public:
    /*!
     * \brief QRuleEngine::QRuleEngine Constructs a QRuleEngine by parsing a given QRule file.
     * \param qruleFilename A QString representing the path to the QRule file containing the rules to use.
     * \param importPaths a QStringList that specifes import paths. Can be empty.
     */
    QRuleEngine(const QString &qRuleFilename, QString importPath);

    /*!
     * \brief QRuleEngine::verifyQMLFiles Verifies the given QML files against the rules given at construction of this object.
     * \param qmlFilenames A list of the paths to all the QML files that should be verifed.
     * \return Any rule violations formatted as QRuleOutput
     */
    QList<QRuleOutput*> verifyQMLFiles(const QStringList &qmlFilenames, const bool renderDot);

private:

    QMap<QString, QRuleOutput*> ruleViolations;
    QMap<QString, NodeWrapper*> importedASTs;

    RuleSet* qruleTree;
    void verifyQMLFile(const QFileInfo &qmlFilename, const bool renderDot);

    QString readCode(QString qmlFilename);
    void mergeOccurranceMap(const QMap<QString, QRuleOutput*> &map);

    QMap<QString, QPair<float, QFileInfo>> parseQmlDirFile(const QFileInfo &qmldirFile, const float version);

    QFileInfo importPath;

    void parseUriImports(NodeWrapper* wrappedRoot, QMap<QString, QString> &importAliasMap, const bool renderDot);
    void parseLiteralImports(NodeWrapper* wrappedRoot, QMap<QString, QString> &importAliasMap, const QFileInfo &qmlFilename, const bool renderDot);
    void extendAvailableFiles(const QFileInfo &qmlFilename, QMap<QString, QList<QFileInfo>> &avalibleFiles, QDir directory);
};

#endif // QRULEENGINE_H
