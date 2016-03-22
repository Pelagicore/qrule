#ifndef KRULEENGINE_KRULEVISITOR_H
#define KRULEENGINE_KRULEVISITOR_H

#include "gen/Absyn.H"
#include "environment/Environment.h"
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

class KRuleVisitor : public Visitor {
public:
    KRuleVisitor(QString filename, QString code, QQmlJS::AST::Node *node):
        filename(filename), code(code), node(node) {}
    void visitRuleSet(RuleSet* p);
    void visitRule(Rule* p);
    void visitASTScope(ASTScope* p);
    void visitRuleCause(RuleCause* p);
    void visitExplanation(Explanation* p);
    void visitTag(Tag* p);
    void visitSeverity(Severity* p);
    void visitOverPaths(OverPaths* p);
    void visitPathSpecific(PathSpecific* p);
    void visitIStmnt(IStmnt* p);
    void visitIExpr(IExpr* p);
    void visitExpr(Expr* p);
    void visitType(Type* p);
    void visitParam(Param* p);
    void visitRSet(RSet* p);
    void visitRRule(RRule* p);
    void visitASTGlobally(ASTGlobally* p);
    void visitASTFile(ASTFile* p);
    void visitASTImported(ASTImported* p);
    void visitRCLang(RCLang* p);
    void visitRCPolicy(RCPolicy* p);
    void visitExplan(Explan* p);
    void visitNoexplan(Noexplan* p);
    void visitTTag(TTag* p);
    void visitSevWarning(SevWarning* p);
    void visitSevCritical(SevCritical* p);
    void visitAll(All* p);
    void visitExist(Exist* p);
    void visitFuture(Future* p);
    void visitGlobally(Globally* p);
    void visitUntil(Until* p);
    void visitNext(Next* p);
    void visitIEInt(IEInt* p);
    void visitIENrChildren(IENrChildren* p);
    void visitIELtEq(IELtEq* p);
    void visitIEGtEq(IEGtEq* p);
    void visitIELt(IELt* p);
    void visitIEGt(IEGt* p);
    void visitIEq(IEq* p);
    void visitIEStmnt(IEStmnt* p);
    void visitETrue(ETrue* p);
    void visitEFalse(EFalse* p);
    void visitENodeVal(ENodeVal* p);
    void visitEType(EType* p);
    void visitEParant(EParant* p);
    void visitENot(ENot* p);
    void visitEImpl(EImpl* p);
    void visitEIExpr(EIExpr* p);
    void visitEEq(EEq* p);
    void visitEAnd(EAnd* p);
    void visitEOr(EOr* p);
    void visitEOverPaths(EOverPaths* p);
    void visitTType(TType* p);
    void visitPParam(PParam* p);
    void visitListRule(ListRule* p);
    void visitListExpr(ListExpr* p);

    void visitInteger(Integer x);
    void visitChar(Char x) {}
    void visitDouble(Double x) {}
    void visitString(String x);
    void visitIdent(Ident x) {}

    QMap<QString, KRuleOutput*> getFailures();

private:

    const QStringRef printable(const QQmlJS::AST::SourceLocation &start, const QQmlJS::AST::SourceLocation &end);
    const QStringRef getSource(const QQmlJS::AST::Node *exp);

    QString overPaths;
    void changeRet(RetType* ret);
    bool getBoolRet();
    QString getStringRet();
    quint32 getUIntRet();

    QString filename;
    QString code;

    QQmlJS::AST::Node *node;

    void assertType(RetType::RetTypeE type);
    QString currentRuleTag = "";
    QString currentRuleSeverity = "";
    QString currentRuleASTScope = "";
    QString currentRuleCause = "";
    QString currentRuleExplanation = "";
    RetType* ret = NULL;
    QMap<QString, KRuleOutput*> failedRules;
};


#endif // KRULEENGINE_KRULEVISITOR_H
