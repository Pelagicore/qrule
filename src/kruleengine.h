// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#ifndef KRULEENGINE_H
#define KRULEENGINE_H

#include "krulevisitor.h"

#include <QMap>
#include <QString>
#include <QFileInfo>
#include <QPair>

#include <output/KRuleOutput.h>

#include "ParseException.h"

#include "gen/Parser.H"
#include "gen/Printer.H"
#include "gen/Absyn.H"

#include "private/qqmljslexer_p.h"
#include "private/qqmljsparser_p.h"
#include "private/qqmljsengine_p.h"
#include "QmlVisitor.h"
#include <QDir>



class KRuleEngine {
public:
    KRuleEngine(const QString &kRuleFilename, bool s_setDot, QString path);

    QList<KRuleOutput*> verifyQMLFiles(const QStringList &qmlFilenames);
private:

    QMap<QString, KRuleOutput*> ruleViolations;
    QMap<QString, NodeWrapper*> importedASTs;


    RuleSet* kruleTree;
    void verifyQMLFile(const QFileInfo &qmlFilename);


    QString readCode(QString qmlFilename);
    void mergeOccurranceMap(const QMap<QString, KRuleOutput*> &map);

    QMap<QString, QPair<float, QFileInfo>> parseQmlDirFile(const QFileInfo &qmldirFile, const float version);

    bool createDot;
    QFileInfo path;

};

#endif // KRULEENGINE_H
