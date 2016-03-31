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

    void endVisit(UiProgram *){ allEnd(); }
    void endVisit(UiImport *){ allEnd(); }
    void endVisit(UiHeaderItemList *){ allEnd(); }
    void endVisit(UiPragma *){ allEnd(); }
    void endVisit(UiPublicMember *){ allEnd(); }
    void endVisit(UiSourceElement *){ allEnd(); }
    void endVisit(UiObjectInitializer *){ allEnd(); }
    void endVisit(UiObjectBinding *){ allEnd(); }
    void endVisit(UiScriptBinding *);
    void endVisit(UiArrayBinding *){ allEnd(); }
    void endVisit(UiParameterList *){ allEnd(); }
    void endVisit(UiObjectMemberList *){ allEnd(); }
    void endVisit(UiArrayMemberList *){ allEnd(); }
    void endVisit(UiQualifiedId *){ allEnd(); }
    void endVisit(UiQualifiedPragmaId *){ allEnd(); }
    void endVisit(ThisExpression *){ allEnd(); }
    void endVisit(IdentifierExpression *){ allEnd(); }
    void endVisit(NullExpression *){ allEnd(); }
    void endVisit(TrueLiteral *){ allEnd(); }
    void endVisit(FalseLiteral *){ allEnd(); }
    void endVisit(StringLiteral *){ allEnd(); }
    void endVisit(NumericLiteral *){ allEnd(); }
    void endVisit(RegExpLiteral *){ allEnd(); }
    void endVisit(ArrayLiteral *){ allEnd(); }
    void endVisit(ObjectLiteral *){ allEnd(); }
    void endVisit(ElementList *){ allEnd(); }
    void endVisit(Elision *){ allEnd(); }
    void endVisit(PropertyAssignmentList *){ allEnd(); }
    void endVisit(PropertyNameAndValue *){ allEnd(); }
    void endVisit(PropertyGetterSetter *){ allEnd(); }
    void endVisit(NestedExpression *){ allEnd(); }
    void endVisit(IdentifierPropertyName *){ allEnd(); }
    void endVisit(StringLiteralPropertyName *){ allEnd(); }
    void endVisit(NumericLiteralPropertyName *){ allEnd(); }
    void endVisit(ArrayMemberExpression *){ allEnd(); }
    void endVisit(FieldMemberExpression *){ allEnd(); }
    void endVisit(NewMemberExpression *){ allEnd(); }
    void endVisit(NewExpression *){ allEnd(); }
    void endVisit(CallExpression *){ allEnd(); }
    void endVisit(ArgumentList *){ allEnd(); }
    void endVisit(PostIncrementExpression *){ allEnd(); }
    void endVisit(PostDecrementExpression *){ allEnd(); }
    void endVisit(DeleteExpression *){ allEnd(); }
    void endVisit(VoidExpression *){ allEnd(); }
    void endVisit(TypeOfExpression *){ allEnd(); }
    void endVisit(PreIncrementExpression *){ allEnd(); }
    void endVisit(PreDecrementExpression *){ allEnd(); }
    void endVisit(UnaryPlusExpression *){ allEnd(); }
    void endVisit(UnaryMinusExpression *){ allEnd(); }
    void endVisit(TildeExpression *){ allEnd(); }
    void endVisit(NotExpression *){ allEnd(); }
    void endVisit(BinaryExpression *){ allEnd(); }
    void endVisit(ConditionalExpression *){ allEnd(); }
    void endVisit(Expression *){ allEnd(); }
    void endVisit(Block *){ allEnd(); }
    void endVisit(StatementList *){ allEnd(); }
    void endVisit(VariableStatement *){ allEnd(); }
    void endVisit(VariableDeclarationList *){ allEnd(); }
    void endVisit(VariableDeclaration *){ allEnd(); }
    void endVisit(EmptyStatement *){ allEnd(); }
    void endVisit(ExpressionStatement *){ allEnd(); }
    void endVisit(IfStatement *){ allEnd(); }
    void endVisit(DoWhileStatement *){ allEnd(); }
    void endVisit(WhileStatement *){ allEnd(); }
    void endVisit(ForStatement *){ allEnd(); }
    void endVisit(LocalForStatement *){ allEnd(); }
    void endVisit(ForEachStatement *){ allEnd(); }
    void endVisit(LocalForEachStatement *){ allEnd(); }
    void endVisit(ContinueStatement *){ allEnd(); }
    void endVisit(BreakStatement *){ allEnd(); }
    void endVisit(ReturnStatement *){ allEnd(); }
    void endVisit(WithStatement *){ allEnd(); }
    void endVisit(SwitchStatement *){ allEnd(); }
    void endVisit(CaseBlock *){ allEnd(); }
    void endVisit(CaseClauses *){ allEnd(); }
    void endVisit(CaseClause *){ allEnd(); }
    void endVisit(DefaultClause *){ allEnd(); }
    void endVisit(LabelledStatement *){ allEnd(); }
    void endVisit(ThrowStatement *){ allEnd(); }
    void endVisit(TryStatement *){ allEnd(); }
    void endVisit(Catch *){ allEnd(); }
    void endVisit(Finally *){ allEnd(); }
    void endVisit(FunctionDeclaration *){ allEnd(); }
    void endVisit(FunctionExpression *){ allEnd(); }
    void endVisit(FormalParameterList *){ allEnd(); }
    void endVisit(FunctionBody *){ allEnd(); }
    void endVisit(Program *){ allEnd(); }
    void endVisit(SourceElements *){ allEnd(); }
    void endVisit(FunctionSourceElement *){ allEnd(); }
    void endVisit(StatementSourceElement *){ allEnd(); }
    void endVisit(DebuggerStatement *){ allEnd(); }
    void endVisit(UiObjectDefinition *);

    NodeWrapper* getWrappedRoot();

private:
    QString indent = "";

    QString notPairedParamValue = "";
    QString notPairedParamName  = "";
    QString _code;

    QString filename;

    QStack<NodeWrapper*> nodeStack;

    QStringRef toQStringRef(const SourceLocation &sl);
    const QStringRef getSource(const QQmlJS::AST::Node *);
    const QStringRef printable(const SourceLocation &start, const SourceLocation &end);
    void debug(const QQmlJS::AST::Node *);
    void deIndent();
    void allEnd();
    void expandIndent();
};

#endif // KRULEENGINE_QMLVISITOR_H
