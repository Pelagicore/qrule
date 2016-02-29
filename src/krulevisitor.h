#ifndef SKELETON_HEADER
#define SKELETON_HEADER
/* You might want to change the above name. */

#include "gen/Absyn.h"
#include "environment/Environment.h"
#include "output/KRuleOutput.h"

#include <QMap>

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

class KRuleVisitor : public Visitor {
public:
    KRuleVisitor(EnvScope *scope): scope(scope){}
    void visitRuleSet(RuleSet* p);
    void visitRule(Rule* p);
    void visitAnalysis(Analysis* p);
    void visitTag(Tag* p);
    void visitSeverity(Severity* p);
    void visitExpr(Expr* p);
    void visitScope(Scope* p);
    void visitParam(Param* p);
    void visitRSet(RSet* p);
    void visitRRule(RRule* p);
    void visitAStatic(AStatic* p);
    void visitADynamic(ADynamic* p);
    void visitTTag(TTag* p);
    void visitSevWarning(SevWarning* p);
    void visitSevCritical(SevCritical* p);
    void visitEInt(EInt* p);
    void visitEMinRDepth(EMinRDepth* p);
    void visitEMaxRDepth(EMaxRDepth* p);
    void visitEDepth(EDepth* p);
    void visitENrChildren(ENrChildren* p);
    void visitERsInScope(ERsInScope* p);
    void visitETrue(ETrue* p);
    void visitEFalse(EFalse* p);
    void visitEIsSetRx(EIsSetRx* p);
    void visitEIsSet(EIsSet* p);
    void visitEIsType(EIsType* p);
    void visitEParant(EParant* p);
    void visitENot(ENot* p);
    void visitEImpl(EImpl* p);
    void visitELtEq(ELtEq* p);
    void visitEGtEq(EGtEq* p);
    void visitELt(ELt* p);
    void visitEGt(EGt* p);
    void visitEEq(EEq* p);
    void visitEAnd(EAnd* p);
    void visitEOr(EOr* p);
    void visitERelease(ERelease* p);
    void visitENext(ENext* p);
    void visitEEventually(EEventually* p);
    void visitEAlways(EAlways* p);
    void visitEUntil(EUntil* p);
    void visitSParent(SParent* p);
    void visitSFile(SFile* p);
    void visitSChildren(SChildren* p);
    void visitSSiblings(SSiblings* p);
    void visitSAny(SAny* p);
    void visitListRule(ListRule* p);
    void visitListExpr(ListExpr* p);

    void visitPParam(PParam* p);

    void visitInteger(Integer x);
    void visitString(String x);

    QMap<QString, KRuleOutput*> getFailures();

private:
    void changeRet(RetType* ret);
    bool getBoolRet();
    QString getStringRet();
    quint32 getUIntRet();

    void assertType(RetType::RetTypeE type);
    EnvScope *scope;
    QString currentRuleTag = "";
    QString currentRuleSeverity = "";
    QString currentRuleAnalysis = "";
    RetType* ret = NULL;
    QMap<QString, KRuleOutput*> failedRules;
};


#endif
