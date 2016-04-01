#ifndef KRULEENGINE_QMLVISITOR_H
#define KRULEENGINE_QMLVISITOR_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QStack>
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
#include "nodewrapper.h"
#include <QtCore/qvarlengtharray.h>
#include <QFile>
#include <typeinfo>


using namespace QQmlJS::AST;

class QmlVisitor: public QQmlJS::AST::Visitor {
public:
    QmlVisitor(QString code, QString filename): _code(code), filename(filename){}
    virtual ~QmlVisitor() {
    }

    bool visit(FunctionBody *);
    bool visit(UiImport *);
    bool visit(UiQualifiedId *);
    bool visit(UiObjectInitializer *);
    bool visit(UiObjectMember *);
    bool visit(UiQualifiedPragmaId *);
    bool visit(UiSourceElement *);
    bool visit(UiArrayBinding *);
    bool visit(UiProgram *);
    bool visit(UiHeaderItemList *);
    bool visit(UiPragma *);
    bool visit(UiPublicMember *);
    bool visit(UiObjectBinding *);
    bool visit(UiScriptBinding *exp);
    bool visit(UiParameterList *);
    bool visit(UiObjectMemberList *);
    bool visit(UiArrayMemberList *);
    bool visit(VariableStatement *);
    bool visit(ThisExpression *);
    bool visit(NullExpression *);
    bool visit(TrueLiteral *exp);
    bool visit(FalseLiteral *exp);
    bool visit(StringLiteral *);
    bool visit(NumericLiteral *);
    bool visit(RegExpLiteral *);
    bool visit(ArrayLiteral *);
    bool visit(ObjectLiteral *);
    bool visit(ElementList *);
    bool visit(Elision *);
    bool visit(PropertyAssignmentList *);
    bool visit(PropertyGetterSetter *);
    bool visit(NestedExpression *);
    bool visit(IdentifierPropertyName *);
    bool visit(StringLiteralPropertyName *);
    bool visit(NumericLiteralPropertyName *);
    bool visit(ArrayMemberExpression *);
    bool visit(FieldMemberExpression *);
    bool visit(NewMemberExpression *);
    bool visit(NewExpression *);
    bool visit(CallExpression *);
    bool visit(ArgumentList *);
    bool visit(PostIncrementExpression *);
    bool visit(PostDecrementExpression *);
    bool visit(DeleteExpression *);
    bool visit(VoidExpression *);
    bool visit(TypeOfExpression *);
    bool visit(PreIncrementExpression *);
    bool visit(PreDecrementExpression *);
    bool visit(UnaryPlusExpression *);
    bool visit(UnaryMinusExpression *);
    bool visit(TildeExpression *);
    bool visit(NotExpression *);
    bool visit(BinaryExpression *);
    bool visit(ConditionalExpression *);
    bool visit(Block *);
    bool visit(StatementList *);
    bool visit(VariableDeclarationList *);
    bool visit(VariableDeclaration *);
    bool visit(EmptyStatement *);
    bool visit(ExpressionStatement *);
    bool visit(IfStatement *);
    bool visit(DoWhileStatement *);
    bool visit(WhileStatement *);
    bool visit(ForStatement *);
    bool visit(LocalForStatement *);
    bool visit(ForEachStatement *);
    bool visit(LocalForEachStatement *);
    bool visit(ContinueStatement *);
    bool visit(BreakStatement *);
    bool visit(ReturnStatement *);
    bool visit(WithStatement *);
    bool visit(SwitchStatement *);
    bool visit(CaseBlock *);
    bool visit(CaseClauses *);
    bool visit(CaseClause *);
    bool visit(DefaultClause *);
    bool visit(LabelledStatement *);
    bool visit(ThrowStatement *);
    bool visit(TryStatement *);
    bool visit(Catch *);
    bool visit(Finally *);
    bool visit(FunctionDeclaration *);
    bool visit(FunctionExpression *);
    bool visit(FormalParameterList *);
    bool visit(Program *);
    bool visit(SourceElements *);
    bool visit(FunctionSourceElement *);
    bool visit(StatementSourceElement *);
    bool visit(DebuggerStatement *);
    bool visit(IdentifierExpression *);
    bool visit(UiObjectDefinition *);

    void endVisit(UiProgram *);
    void endVisit(UiImport *);
    void endVisit(UiHeaderItemList *);
    void endVisit(UiPragma *);
    void endVisit(UiPublicMember *);
    void endVisit(UiSourceElement *);
    void endVisit(UiObjectInitializer *);
    void endVisit(UiObjectBinding *);
    void endVisit(UiScriptBinding *);
    void endVisit(UiArrayBinding *);
    void endVisit(UiParameterList *);
    void endVisit(UiObjectMemberList *);
    void endVisit(UiArrayMemberList *);
    void endVisit(UiQualifiedId *);
    void endVisit(UiQualifiedPragmaId *);
    void endVisit(ThisExpression *);
    void endVisit(IdentifierExpression *);
    void endVisit(NullExpression *);
    void endVisit(TrueLiteral *);
    void endVisit(FalseLiteral *);
    void endVisit(StringLiteral *);
    void endVisit(NumericLiteral *);
    void endVisit(RegExpLiteral *);
    void endVisit(ArrayLiteral *);
    void endVisit(ObjectLiteral *);
    void endVisit(ElementList *);
    void endVisit(Elision *);
    void endVisit(PropertyAssignmentList *);
    void endVisit(PropertyNameAndValue *);
    void endVisit(PropertyGetterSetter *);
    void endVisit(NestedExpression *);
    void endVisit(IdentifierPropertyName *);
    void endVisit(StringLiteralPropertyName *);
    void endVisit(NumericLiteralPropertyName *);
    void endVisit(ArrayMemberExpression *);
    void endVisit(FieldMemberExpression *);
    void endVisit(NewMemberExpression *);
    void endVisit(NewExpression *);
    void endVisit(CallExpression *);
    void endVisit(ArgumentList *);
    void endVisit(PostIncrementExpression *);
    void endVisit(PostDecrementExpression *);
    void endVisit(DeleteExpression *);
    void endVisit(VoidExpression *);
    void endVisit(TypeOfExpression *);
    void endVisit(PreIncrementExpression *);
    void endVisit(PreDecrementExpression *);
    void endVisit(UnaryPlusExpression *);
    void endVisit(UnaryMinusExpression *);
    void endVisit(TildeExpression *);
    void endVisit(NotExpression *);
    void endVisit(BinaryExpression *);
    void endVisit(ConditionalExpression *);
    void endVisit(Expression *);
    void endVisit(Block *);
    void endVisit(StatementList *);
    void endVisit(VariableStatement *);
    void endVisit(VariableDeclarationList *);
    void endVisit(VariableDeclaration *);
    void endVisit(EmptyStatement *);
    void endVisit(ExpressionStatement *);
    void endVisit(IfStatement *);
    void endVisit(DoWhileStatement *);
    void endVisit(WhileStatement *);
    void endVisit(ForStatement *);
    void endVisit(LocalForStatement *);
    void endVisit(ForEachStatement *);
    void endVisit(LocalForEachStatement *);
    void endVisit(ContinueStatement *);
    void endVisit(BreakStatement *);
    void endVisit(ReturnStatement *);
    void endVisit(WithStatement *);
    void endVisit(SwitchStatement *);
    void endVisit(CaseBlock *);
    void endVisit(CaseClauses *);
    void endVisit(CaseClause *);
    void endVisit(DefaultClause *);
    void endVisit(LabelledStatement *);
    void endVisit(ThrowStatement *);
    void endVisit(TryStatement *);
    void endVisit(Catch *);
    void endVisit(Finally *);
    void endVisit(FunctionDeclaration *);
    void endVisit(FunctionExpression *);
    void endVisit(FormalParameterList *);
    void endVisit(FunctionBody *);
    void endVisit(Program *);
    void endVisit(SourceElements *);
    void endVisit(FunctionSourceElement *);
    void endVisit(StatementSourceElement *);
    void endVisit(DebuggerStatement *);
    void endVisit(UiObjectDefinition *);


    NodeWrapper* getWrappedRoot();

private:
    QString indent = "";

    QString notPairedParamValue = "";
    QString notPairedParamName  = "";
    QString _code;

    QString filename;

    NodeWrapper *rootNode = nullptr;
    QStack<NodeWrapper*> nodeStack;
    void pushStack(NodeWrapper*);
    void popStack();

    void addWrapper(NodeWrapper *n);

    QStringRef toQStringRef(const SourceLocation &sl);
    const QStringRef getSource(const QQmlJS::AST::Node *);
    const QStringRef printable(const SourceLocation &start, const SourceLocation &end);

    void debug(const QQmlJS::AST::Node *);
    void deIndent();
    void expandIndent();
};

#endif // KRULEENGINE_QMLVISITOR_H
