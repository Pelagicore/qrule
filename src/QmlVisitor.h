#ifndef KRULEENGINE_QMLVISITOR_H
#define KRULEENGINE_QMLVISITOR_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "private/qqmljsengine_p.h"
#include "private/qqmljslexer_p.h"
#include "private/qqmljsast_p.h"
#include "private/qqmljsmemorypool_p.h"
#include "private/qqmljsastvisitor_p.h"
#include <QtCore/qdebug.h>
#include <QtCore/qcoreapplication.h>
#include <string.h>
#include <QDebug>
#include <QtCore/QCoreApplication>
#include "private/qqmljsparser_p.h"
#include <QtCore/qvarlengtharray.h>
#include <QFile>
#include <typeinfo>
#include "environment/Environment.h"


using namespace QQmlJS::AST;

class QmlVisitor: public QQmlJS::AST::Visitor {
public:
    QmlVisitor(QString code, QString filename): _code(code), filename(filename){}
    virtual ~QmlVisitor() {
        delete env;
    }

    virtual bool visit(FunctionBody *exp) {
        debug(exp);
        return true;
    }


    virtual bool visit(UiImport *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiQualifiedId *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiObjectInitializer *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiObjectMember *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiQualifiedPragmaId *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiSourceElement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiArrayBinding *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiProgram *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiHeaderItemList *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiPragma *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiPublicMember *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiObjectBinding *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiScriptBinding *exp);

    virtual bool visit(UiParameterList *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiObjectMemberList *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UiArrayMemberList *exp) {
        debug(exp);
        return true; }

    virtual bool visit(VariableStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ThisExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(NullExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(TrueLiteral *exp);

    virtual bool visit(FalseLiteral *exp);

    virtual bool visit(StringLiteral *exp) {
        debug(exp);
        return true; }

    virtual bool visit(NumericLiteral *exp) {
        debug(exp);
        return true; }

    virtual bool visit(RegExpLiteral *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ArrayLiteral *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ObjectLiteral *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ElementList *exp) {
        debug(exp);
        return true; }

    virtual bool visit(Elision *exp) {
        debug(exp);
        return true; }

    virtual bool visit(PropertyAssignmentList *exp) {
        debug(exp);
        return true; }

    virtual bool visit(PropertyGetterSetter *exp) {
        debug(exp);
        return true; }

    virtual bool visit(NestedExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(IdentifierPropertyName *exp) {
        debug(exp);
        return true; }

    virtual bool visit(StringLiteralPropertyName *exp) {
        debug(exp);
        return true; }

    virtual bool visit(NumericLiteralPropertyName *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ArrayMemberExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(FieldMemberExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(NewMemberExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(NewExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(CallExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ArgumentList *exp) {
        debug(exp);
        return true; }

    virtual bool visit(PostIncrementExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(PostDecrementExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(DeleteExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(VoidExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(TypeOfExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(PreIncrementExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(PreDecrementExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UnaryPlusExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(UnaryMinusExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(TildeExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(NotExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(BinaryExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ConditionalExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(Block *exp) {
        debug(exp);
        return true; }

    virtual bool visit(StatementList *exp) {
        debug(exp);
        return true; }

    virtual bool visit(VariableDeclarationList *exp) {
        debug(exp);
        return true; }

    virtual bool visit(VariableDeclaration *exp) {
        debug(exp);
        return true; }

    virtual bool visit(EmptyStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ExpressionStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(IfStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(DoWhileStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(WhileStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ForStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(LocalForStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ForEachStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(LocalForEachStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ContinueStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(BreakStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ReturnStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(WithStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(SwitchStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(CaseBlock *exp) {
        debug(exp);
        return true; }

    virtual bool visit(CaseClauses *exp) {
        debug(exp);
        return true; }

    virtual bool visit(CaseClause *exp) {
        debug(exp);
        return true; }

    virtual bool visit(DefaultClause *exp) {
        debug(exp);
        return true; }

    virtual bool visit(LabelledStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(ThrowStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(TryStatement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(Catch *exp) {
        debug(exp);
        return true; }

    virtual bool visit(Finally *exp) {
        debug(exp);
        return true; }

    virtual bool visit(FunctionDeclaration *exp) {
        debug(exp);
        return true; }

    virtual bool visit(FunctionExpression *exp) {
        debug(exp);
        return true; }

    virtual bool visit(FormalParameterList *exp) {
        debug(exp);
        return true; }

    virtual bool visit(Program *exp) {
        debug(exp);
        return true; }

    virtual bool visit(SourceElements *exp) {
        debug(exp);
        return true; }

    virtual bool visit(FunctionSourceElement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(StatementSourceElement *exp) {
        debug(exp);
        return true; }

    virtual bool visit(DebuggerStatement *exp) {
        debug(exp);
        return true; }

    virtual void endVisit(UiProgram *){ deIndent(); }
    virtual void endVisit(UiImport *){ deIndent(); }
    virtual void endVisit(UiHeaderItemList *){ deIndent(); }
    virtual void endVisit(UiPragma *){ deIndent(); }
    virtual void endVisit(UiPublicMember *){ deIndent(); }
    virtual void endVisit(UiSourceElement *){ deIndent(); }
    virtual void endVisit(UiObjectInitializer *){ deIndent(); }
    virtual void endVisit(UiObjectBinding *){ deIndent(); }
    virtual void endVisit(UiScriptBinding *);
    virtual void endVisit(UiArrayBinding *){ deIndent(); }
    virtual void endVisit(UiParameterList *){ deIndent(); }
    virtual void endVisit(UiObjectMemberList *){ deIndent(); }
    virtual void endVisit(UiArrayMemberList *){ deIndent(); }
    virtual void endVisit(UiQualifiedId *){ deIndent(); }
    virtual void endVisit(UiQualifiedPragmaId *){ deIndent(); }
    virtual void endVisit(ThisExpression *){ deIndent(); }
    virtual void endVisit(IdentifierExpression *){ deIndent(); }
    virtual void endVisit(NullExpression *){ deIndent(); }
    virtual void endVisit(TrueLiteral *){ deIndent(); }
    virtual void endVisit(FalseLiteral *){ deIndent(); }
    virtual void endVisit(StringLiteral *){ deIndent(); }
    virtual void endVisit(NumericLiteral *){ deIndent(); }
    virtual void endVisit(RegExpLiteral *){ deIndent(); }
    virtual void endVisit(ArrayLiteral *){ deIndent(); }
    virtual void endVisit(ObjectLiteral *){ deIndent(); }
    virtual void endVisit(ElementList *){ deIndent(); }
    virtual void endVisit(Elision *){ deIndent(); }
    virtual void endVisit(PropertyAssignmentList *){ deIndent(); }
    virtual void endVisit(PropertyNameAndValue *){ deIndent(); }
    virtual void endVisit(PropertyGetterSetter *){ deIndent(); }
    virtual void endVisit(NestedExpression *){ deIndent(); }
    virtual void endVisit(IdentifierPropertyName *){ deIndent(); }
    virtual void endVisit(StringLiteralPropertyName *){ deIndent(); }
    virtual void endVisit(NumericLiteralPropertyName *){ deIndent(); }
    virtual void endVisit(ArrayMemberExpression *){ deIndent(); }
    virtual void endVisit(FieldMemberExpression *){ deIndent(); }
    virtual void endVisit(NewMemberExpression *){ deIndent(); }
    virtual void endVisit(NewExpression *){ deIndent(); }
    virtual void endVisit(CallExpression *){ deIndent(); }
    virtual void endVisit(ArgumentList *){ deIndent(); }
    virtual void endVisit(PostIncrementExpression *){ deIndent(); }
    virtual void endVisit(PostDecrementExpression *){ deIndent(); }
    virtual void endVisit(DeleteExpression *){ deIndent(); }
    virtual void endVisit(VoidExpression *){ deIndent(); }
    virtual void endVisit(TypeOfExpression *){ deIndent(); }
    virtual void endVisit(PreIncrementExpression *){ deIndent(); }
    virtual void endVisit(PreDecrementExpression *){ deIndent(); }
    virtual void endVisit(UnaryPlusExpression *){ deIndent(); }
    virtual void endVisit(UnaryMinusExpression *){ deIndent(); }
    virtual void endVisit(TildeExpression *){ deIndent(); }
    virtual void endVisit(NotExpression *){ deIndent(); }
    virtual void endVisit(BinaryExpression *){ deIndent(); }
    virtual void endVisit(ConditionalExpression *){ deIndent(); }
    virtual void endVisit(Expression *){ deIndent(); }
    virtual void endVisit(Block *){ deIndent(); }
    virtual void endVisit(StatementList *){ deIndent(); }
    virtual void endVisit(VariableStatement *){ deIndent(); }
    virtual void endVisit(VariableDeclarationList *){ deIndent(); }
    virtual void endVisit(VariableDeclaration *){ deIndent(); }
    virtual void endVisit(EmptyStatement *){ deIndent(); }
    virtual void endVisit(ExpressionStatement *){ deIndent(); }
    virtual void endVisit(IfStatement *){ deIndent(); }
    virtual void endVisit(DoWhileStatement *){ deIndent(); }
    virtual void endVisit(WhileStatement *){ deIndent(); }
    virtual void endVisit(ForStatement *){ deIndent(); }
    virtual void endVisit(LocalForStatement *){ deIndent(); }
    virtual void endVisit(ForEachStatement *){ deIndent(); }
    virtual void endVisit(LocalForEachStatement *){ deIndent(); }
    virtual void endVisit(ContinueStatement *){ deIndent(); }
    virtual void endVisit(BreakStatement *){ deIndent(); }
    virtual void endVisit(ReturnStatement *){ deIndent(); }
    virtual void endVisit(WithStatement *){ deIndent(); }
    virtual void endVisit(SwitchStatement *){ deIndent(); }
    virtual void endVisit(CaseBlock *){ deIndent(); }
    virtual void endVisit(CaseClauses *){ deIndent(); }
    virtual void endVisit(CaseClause *){ deIndent(); }
    virtual void endVisit(DefaultClause *){ deIndent(); }
    virtual void endVisit(LabelledStatement *){ deIndent(); }
    virtual void endVisit(ThrowStatement *){ deIndent(); }
    virtual void endVisit(TryStatement *){ deIndent(); }
    virtual void endVisit(Catch *){ deIndent(); }
    virtual void endVisit(Finally *){ deIndent(); }
    virtual void endVisit(FunctionDeclaration *){ deIndent(); }
    virtual void endVisit(FunctionExpression *){ deIndent(); }
    virtual void endVisit(FormalParameterList *){ deIndent(); }
    virtual void endVisit(FunctionBody *){ deIndent(); }
    virtual void endVisit(Program *){ deIndent(); }
    virtual void endVisit(SourceElements *){ deIndent(); }
    virtual void endVisit(FunctionSourceElement *){ deIndent(); }
    virtual void endVisit(StatementSourceElement *){ deIndent(); }
    virtual void endVisit(DebuggerStatement *){ deIndent(); }

    virtual bool visit(IdentifierExpression *);
    virtual bool visit(UiObjectDefinition *);
    virtual void endVisit(UiObjectDefinition *);

    Environment* getEnvironment() { return env; }

private:
    Environment* env = new Environment();
    QString indent = "";

    QString notPairedParamValue = "";
    QString notPairedParamName  = "";
    QString _code;

    QString filename;

    const QStringRef getSource(const QQmlJS::AST::Node *);
    const QStringRef printable(const SourceLocation &start, const SourceLocation &end);
    void debug(const QQmlJS::AST::Node *);
    void deIndent();
    void expandIndent();
};

#endif // KRULEENGINE_QMLVISITOR_H
