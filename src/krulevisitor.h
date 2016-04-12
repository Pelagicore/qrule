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
    RetType* visitRuleSet(RuleSet*);
    RetType* visitRule(Rule*);
    RetType* visitASTScope(ASTScope*);
    RetType* visitRuleCause(RuleCause*);
    RetType* visitExplanation(Explanation*);
    RetType* visitTag(Tag*);
    RetType* visitSeverity(Severity*);
    RetType* visitQuantifier(Quantifier*);
    RetType* visitPathQuantifier(PathQuantifier*);
    RetType* visitIAtom(IAtom*);
    RetType* visitSAtom(SAtom*);
    RetType* visitExpr(Expr*);
    RetType* visitRSet(RSet*);
    RetType* visitRRule(RRule*);
    RetType* visitASTGlobally(ASTGlobally*);
    RetType* visitASTFile(ASTFile*);
    RetType* visitASTImported(ASTImported*);
    RetType* visitRCLang(RCLang*);
    RetType* visitRCPolicy(RCPolicy*);
    RetType* visitExplan(Explan*);
    RetType* visitNoexplan(Noexplan*);
    RetType* visitTTag(TTag*);
    RetType* visitSevInfo(SevInfo*);
    RetType* visitSevWarning(SevWarning*);
    RetType* visitSevCritical(SevCritical*);
    RetType* visitQExpr(QExpr*);
    RetType* visitQFor(QFor*);
    RetType* visitAG(AG*);
    RetType* visitAF(AF*);
    RetType* visitAX(AX*);
    RetType* visitAU(AU*);
    RetType* visitEG(EG*);
    RetType* visitEF(EF*);
    RetType* visitEX(EX*);
    RetType* visitEU(EU*);
    RetType* visitIFRow(IFRow*);
    RetType* visitIFCol(IFCol*);
    RetType* visitIInt(IInt*);
    RetType* visitINrChildren(INrChildren*);
    RetType* visitIRow(IRow*);
    RetType* visitICol(ICol*);
    RetType* visitSString(SString*);
    RetType* visitSFValue(SFValue*);
    RetType* visitSValue(SValue*);
    RetType* visitSValueType(SValueType*);
    RetType* visitSNodeType(SNodeType*);
    RetType* visitSConcat(SConcat*);
    RetType* visitETrue(ETrue*);
    RetType* visitEFalse(EFalse*);
    RetType* visitEParant(EParant*);
    RetType* visitENot(ENot*);
    RetType* visitEImpl(EImpl*);
    RetType* visitEBEq(EBEq*);
    RetType* visitEPossToken(EPossToken*);
    RetType* visitEExistToken(EExistToken*);
    RetType* visitEILtEq(EILtEq*);
    RetType* visitEIGtEq(EIGtEq*);
    RetType* visitEILt(EILt*);
    RetType* visitEIGt(EIGt*);
    RetType* visitEIEq(EIEq*);
    RetType* visitEMatch(EMatch*);
    RetType* visitESEq(ESEq*);
    RetType* visitEAnd(EAnd*);
    RetType* visitEOr(EOr*);
    RetType* visitEPQ(EPQ*);
    RetType* visitListRule(ListRule*);
    RetType* visitListExpr(ListExpr*);

    RetType* visitInteger(Integer);
    RetType* visitString(String);

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
    NodeWrapper *quantifiedNode;

    void assertType(RetType* ret, RetType::RetTypeE type);
    QString currentRuleTag = "";
    QString currentRuleSeverity = "";
    QString currentRuleASTScope = "";
    QString currentRuleCause = "";
    QString currentRuleExplanation = "";
    QMap<QString, KRuleOutput*> failedRules;
};


#endif // KRULEENGINE_KRULEVISITOR_H
