// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#ifndef KRULEENGINE_KRULEVISITOR_H
#define KRULEENGINE_KRULEVISITOR_H

#include "gen/Absyn.H"
#include "nodewrapper.h"
#include "output/KRuleOutput.h"
#include "retType/RetTypeBool.h"
#include "retType/RetTypeString.h"
#include "retType/RetTypeUInt.h"
#include <QMap>
#include <private/qqmljsast_p.h>

class NotImplemented : public std::exception {
public:
    NotImplemented() {}
    ~NotImplemented() {}
    const char* what() { return "Feature not yet implemented!"; }
};

class BadType : public std::exception {
public:
    BadType() {}
    ~BadType() {}
    const char* what() { return "Bad type"; }
};

class NoQuantification : public std::exception {
public:
    NoQuantification() {}
    ~NoQuantification() {}
    const char* what() {
        return "The tokens R C and V can only be used while quantifing using forAll";
    }
};


class KRuleVisitor : public Visitor {
public:
    KRuleVisitor(QString filename, QString code, NodeWrapper *node):
        filename(filename), code(code), node(node) {}
    QPointer<RetType> visitRuleSet(RuleSet*);
    QPointer<RetType> visitRule(Rule*);
    QPointer<RetType> visitASTScope(ASTScope*);
    QPointer<RetType> visitRuleCause(RuleCause*);
    QPointer<RetType> visitExplanation(Explanation*);
    QPointer<RetType> visitTag(Tag*);
    QPointer<RetType> visitSeverity(Severity*);
    QPointer<RetType> visitQuantifier(Quantifier*);
    QPointer<RetType> visitPathQuantifier(PathQuantifier*);
    QPointer<RetType> visitIAtom(IAtom*);
    QPointer<RetType> visitSAtom(SAtom*);
    QPointer<RetType> visitExpr(Expr*);
    QPointer<RetType> visitRSet(RSet*);
    QPointer<RetType> visitRRule(RRule*);
    QPointer<RetType> visitASTGlobally(ASTGlobally*);
    QPointer<RetType> visitASTFile(ASTFile*);
    QPointer<RetType> visitASTImported(ASTImported*);
    QPointer<RetType> visitRCLang(RCLang*);
    QPointer<RetType> visitRCPolicy(RCPolicy*);
    QPointer<RetType> visitExplan(Explan*);
    QPointer<RetType> visitNoexplan(Noexplan*);
    QPointer<RetType> visitTTag(TTag*);
    QPointer<RetType> visitSevInfo(SevInfo*);
    QPointer<RetType> visitSevWarning(SevWarning*);
    QPointer<RetType> visitSevCritical(SevCritical*);
    QPointer<RetType> visitQExpr(QExpr*);
    QPointer<RetType> visitQFor(QFor*);
    QPointer<RetType> visitAG(AG*);
    QPointer<RetType> visitAF(AF*);
    QPointer<RetType> visitAX(AX*);
    QPointer<RetType> visitAU(AU*);
    QPointer<RetType> visitEG(EG*);
    QPointer<RetType> visitEF(EF*);
    QPointer<RetType> visitEX(EX*);
    QPointer<RetType> visitEU(EU*);
    QPointer<RetType> visitIFRow(IFRow*);
    QPointer<RetType> visitIFCol(IFCol*);
    QPointer<RetType> visitIInt(IInt*);
    QPointer<RetType> visitINrChildren(INrChildren*);
    QPointer<RetType> visitIRow(IRow*);
    QPointer<RetType> visitICol(ICol*);
    QPointer<RetType> visitSString(SString*);
    QPointer<RetType> visitSFValue(SFValue*);
    QPointer<RetType> visitSValue(SValue*);
    QPointer<RetType> visitSValueType(SValueType*);
    QPointer<RetType> visitSNodeType(SNodeType*);
    QPointer<RetType> visitSConcat(SConcat*);
    QPointer<RetType> visitETrue(ETrue*);
    QPointer<RetType> visitEFalse(EFalse*);
    QPointer<RetType> visitEParant(EParant*);
    QPointer<RetType> visitENot(ENot*);
    QPointer<RetType> visitEImpl(EImpl*);
    QPointer<RetType> visitEBEq(EBEq*);
    QPointer<RetType> visitEPossToken(EPossToken*);
    QPointer<RetType> visitEExistToken(EExistToken*);
    QPointer<RetType> visitEILtEq(EILtEq*);
    QPointer<RetType> visitEIGtEq(EIGtEq*);
    QPointer<RetType> visitEILt(EILt*);
    QPointer<RetType> visitEIGt(EIGt*);
    QPointer<RetType> visitEIEq(EIEq*);
    QPointer<RetType> visitEMatch(EMatch*);
    QPointer<RetType> visitESEq(ESEq*);
    QPointer<RetType> visitEAnd(EAnd*);
    QPointer<RetType> visitEOr(EOr*);
    QPointer<RetType> visitEPQ(EPQ*);
    QPointer<RetType> visitListRule(ListRule*);
    QPointer<RetType> visitListExpr(ListExpr*);

    QPointer<RetType> visitInteger(Integer);
    QPointer<RetType> visitString(String);

    QMap<QString, KRuleOutput*> getFailures();

private:

    const QStringRef printable(const QQmlJS::AST::SourceLocation &start, const QQmlJS::AST::SourceLocation &end);
    const QStringRef getSource(const QQmlJS::AST::Node *exp);

    const bool handleBreakCondition(const bool breakCondition);

    QString overPaths;
    const bool extractBool(const QPointer<RetType> &ret);
    const QString extractQString(const QPointer<RetType> &ret);
    const quint32 extractUInt(const QPointer<RetType> &ret);

    QString filename;
    QString code;

    NodeWrapper *node;
    NodeWrapper *quantifiedNode;

    QString indent;

    void assertType(const QPointer<RetType> &ret, RetType::RetTypeE type);
    QString currentRuleTag = "";
    QString currentRuleSeverity = "";
    QString currentRuleASTScope = "";
    QString currentRuleCause = "";
    QString currentRuleExplanation = "";
    QMap<QString, KRuleOutput*> failedRules;
};


#endif // KRULEENGINE_KRULEVISITOR_H
