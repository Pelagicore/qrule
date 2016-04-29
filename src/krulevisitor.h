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
    KRuleVisitor(NodeWrapper *node):
        node(node) {}

    QPointer<RetType> visitRuleSet(RuleSet* p);
    QPointer<RetType> visitRule(Rule* p);
    QPointer<RetType> visitASTScope(ASTScope* p);
    QPointer<RetType> visitRuleCause(RuleCause* p);
    QPointer<RetType> visitExplanation(Explanation* p);
    QPointer<RetType> visitTag(Tag* p);
    QPointer<RetType> visitSeverity(Severity* p);
    QPointer<RetType> visitPathQuantifier(PathQuantifier* p);
    QPointer<RetType> visitIAtom(IAtom* p);
    QPointer<RetType> visitSAtom(SAtom* p);
    QPointer<RetType> visitExpr(Expr* p);
    QPointer<RetType> visitFilter(Filter* p);
    QPointer<RetType> visitRSet(RSet* p);
    QPointer<RetType> visitRRule(RRule* p);
    QPointer<RetType> visitASTGlobally(ASTGlobally* p);
    QPointer<RetType> visitASTFile(ASTFile* p);
    QPointer<RetType> visitASTImported(ASTImported* p);
    QPointer<RetType> visitRCLang(RCLang* p);
    QPointer<RetType> visitRCPolicy(RCPolicy* p);
    QPointer<RetType> visitExplan(Explan* p);
    QPointer<RetType> visitNoexplan(Noexplan* p);
    QPointer<RetType> visitTTag(TTag* p);
    QPointer<RetType> visitSevInfo(SevInfo* p);
    QPointer<RetType> visitSevWarning(SevWarning* p);
    QPointer<RetType> visitSevCritical(SevCritical* p);
    QPointer<RetType> visitAG(AG* p);
    QPointer<RetType> visitAF(AF* p);
    QPointer<RetType> visitAX(AX* p);
    QPointer<RetType> visitAU(AU* p);
    QPointer<RetType> visitEG(EG* p);
    QPointer<RetType> visitEF(EF* p);
    QPointer<RetType> visitEX(EX* p);
    QPointer<RetType> visitEU(EU* p);
    QPointer<RetType> visitIFRow(IFRow* p);
    QPointer<RetType> visitIFCol(IFCol* p);
    QPointer<RetType> visitIInt(IInt* p);
    QPointer<RetType> visitINrChildren(INrChildren* p);
    QPointer<RetType> visitIRow(IRow* p);
    QPointer<RetType> visitICol(ICol* p);
    QPointer<RetType> visitSString(SString* p);
    QPointer<RetType> visitSFValue(SFValue* p);
    QPointer<RetType> visitSValue(SValue* p);
    QPointer<RetType> visitSValueType(SValueType* p);
    QPointer<RetType> visitSNodeType(SNodeType* p);
    QPointer<RetType> visitSConcat(SConcat* p);
    QPointer<RetType> visitETrue(ETrue* p);
    QPointer<RetType> visitEFalse(EFalse* p);
    QPointer<RetType> visitEParant(EParant* p);
    QPointer<RetType> visitENot(ENot* p);
    QPointer<RetType> visitEBEq(EBEq* p);
    QPointer<RetType> visitEPossToken(EPossToken* p);
    QPointer<RetType> visitEExistToken(EExistToken* p);
    QPointer<RetType> visitEILtEq(EILtEq* p);
    QPointer<RetType> visitEIGtEq(EIGtEq* p);
    QPointer<RetType> visitEILt(EILt* p);
    QPointer<RetType> visitEIGt(EIGt* p);
    QPointer<RetType> visitEIEq(EIEq* p);
    QPointer<RetType> visitEMatch(EMatch* p);
    QPointer<RetType> visitESEq(ESEq* p);
    QPointer<RetType> visitEAnd(EAnd* p);
    QPointer<RetType> visitEOr(EOr* p);
    QPointer<RetType> visitEFirstOrdQ(EFirstOrdQ* p);
    QPointer<RetType> visitEPQ(EPQ* p);
    QPointer<RetType> visitEImpl(EImpl* p);
    QPointer<RetType> visitFString(FString* p);
    QPointer<RetType> visitListRule(ListRule* p);
    QPointer<RetType> visitListExpr(ListExpr* p);
    QPointer<RetType> visitListFilter(ListFilter* p);

    QPointer<RetType> visitInteger(Integer p);
    QPointer<RetType> visitString(String p);

    QPointer<RetType> visitChar(Char) {}
    QPointer<RetType> visitDouble(Double) {}
    QPointer<RetType> visitIdent(Ident) {}


    QMap<QString, KRuleOutput*> getFailures();

private:

    const bool handleBreakCondition(const bool breakCondition);

    QString overPaths;
    const bool extractBool(const QPointer<RetType> &ret);
    const QString extractQString(const QPointer<RetType> &ret);
    const quint32 extractUInt(const QPointer<RetType> &ret);

    NodeWrapper *node;
    NodeWrapper *blameNode;
    QList<NodeWrapper*> quantifiedNode;

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
