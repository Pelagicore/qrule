#ifndef KRULEENGINE_H
#define KRULEENGINE_H

#include "krulevisitor.h"

#include <QMap>
#include <QString>
#include <QFileInfo>

#include <output/KRuleOutput.h>

#include "ParseException.h"

#include "gen/Parser.H"
#include "gen/Printer.H"
#include "gen/Absyn.H"

#include "private/qqmljslexer_p.h"
#include "private/qqmljsparser_p.h"
#include "private/qqmljsengine_p.h"
#include "QmlVisitor.h"

class KRuleEngine {
public:
    KRuleEngine(const QString &kRuleFilename,bool s_setDot);

    QList<KRuleOutput*> verifyQMLFiles(const QStringList &qmlFilenames);
private:
    RuleSet* kruleTree;
    QMap<QString, KRuleOutput*> verifyQMLFile(const QString &qmlFilename);

    QString readCode(QString qmlFilename);
    QMap<QString, KRuleOutput*> mergeOccurranceMap(QMap<QString, KRuleOutput*> m1, QMap<QString, KRuleOutput*> m2);

    bool createDot;
};

#endif // KRULEENGINE_H
