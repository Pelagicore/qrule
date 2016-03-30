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

class KRuleVisitor : public Visitor {
public:
    KRuleVisitor(QString filename, QString code, NodeWrapper *node):
        filename(filename), code(code), node(node) {}
    RetType* visitRuleSet(RuleSet* p);
    RetType* visitRule(Rule* p);
    RetType* visitASTScope(ASTScope* p);
    RetType* visitRuleCause(RuleCause* p);
    RetType* visitExplanation(Explanation* p);
    RetType* visitTag(Tag* p);
    RetType* visitSeverity(Severity* p);
    RetType* visitPathQuantifier(PathQuantifier *p);
    RetType* visitIStmnt(IStmnt* p);
    RetType* visitIExpr(IExpr* p);
    RetType* visitExpr(Expr* p);
    RetType* visitRSet(RSet* p);
    RetType* visitRRule(RRule* p);
    RetType* visitASTGlobally(ASTGlobally* p);
    RetType* visitASTFile(ASTFile* p);
    RetType* visitASTImported(ASTImported* p);
    RetType* visitRCLang(RCLang* p);
    RetType* visitRCPolicy(RCPolicy* p);
    RetType* visitExplan(Explan* p);
    RetType* visitNoexplan(Noexplan* p);
    RetType* visitTTag(TTag* p);
    RetType* visitSevWarning(SevWarning* p);
    RetType* visitSevCritical(SevCritical* p);
    RetType* visitAG(AG *p);
    RetType* visitAF(AF *p);
    RetType* visitAX(AX *p);
    RetType* visitAU(AU *p);
    RetType* visitEG(EG *p);
    RetType* visitEF(EF *p);
    RetType* visitEX(EX *p);
    RetType* visitEU(EU *p);
    RetType* visitIEInt(IEInt* p);
    RetType* visitIENrChildren(IENrChildren* p);
    RetType* visitIERow(IERow *p);
    RetType* visitIECol(IECol *p);
    RetType* visitIELtEq(IELtEq* p);
    RetType* visitIEGtEq(IEGtEq* p);
    RetType* visitIELt(IELt* p);
    RetType* visitIEGt(IEGt* p);
    RetType* visitIEq(IEq* p);
    RetType* visitIEStmnt(IEStmnt* p);
    RetType* visitETrue(ETrue* p);
    RetType* visitEFalse(EFalse* p);
    RetType* visitEValue(EValue *p);
    RetType* visitEValueType(EValueType *p);
    RetType* visitENodeType(ENodeType *p);
    RetType* visitEParant(EParant* p);
    RetType* visitENot(ENot* p);
    RetType* visitEImpl(EImpl* p);
    RetType* visitEIExpr(EIExpr* p);
    RetType* visitEEq(EEq* p);
    RetType* visitEAnd(EAnd* p);
    RetType* visitEOr(EOr* p);
    RetType* visitEPQ(EPQ *p);
    RetType* visitListRule(ListRule* p);
    RetType* visitListExpr(ListExpr* p);

    RetType* visitInteger(Integer x);
    RetType* visitChar(Char x) {}
    RetType* visitDouble(Double x) {}
    RetType* visitString(String x);
    RetType* visitIdent(Ident x) {}

    QMap<QString, KRuleOutput*> getFailures();

private:

    const QStringRef printable(const QQmlJS::AST::SourceLocation &start, const QQmlJS::AST::SourceLocation &end);
    const QStringRef getSource(const QQmlJS::AST::Node *exp);

    const bool handleBreakCondition(const bool breakCondition);

    QString overPaths;
    const bool extractBool(RetType *ret);
    const QString extractQString(RetType *ret);
    const quint32 extractUInt(RetType *ret);

    QString filename;
    QString code;

    NodeWrapper *node;

    void assertType(RetType* ret, RetType::RetTypeE type);
    QString currentRuleTag = "";
    QString currentRuleSeverity = "";
    QString currentRuleASTScope = "";
    QString currentRuleCause = "";
    QString currentRuleExplanation = "";
    QMap<QString, KRuleOutput*> failedRules;
};


#endif // KRULEENGINE_KRULEVISITOR_H
