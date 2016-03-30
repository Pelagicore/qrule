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

    void endVisit(UiProgram *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiImport *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiHeaderItemList *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiPragma *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiPublicMember *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiSourceElement *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiObjectInitializer *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiObjectBinding *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiScriptBinding *);
    void endVisit(UiArrayBinding *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiParameterList *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiObjectMemberList *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiArrayMemberList *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiQualifiedId *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiQualifiedPragmaId *){ deIndent(); nodeStack.pop(); }
    void endVisit(ThisExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(IdentifierExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(NullExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(TrueLiteral *){ deIndent(); nodeStack.pop(); }
    void endVisit(FalseLiteral *){ deIndent(); nodeStack.pop(); }
    void endVisit(StringLiteral *){ deIndent(); nodeStack.pop(); }
    void endVisit(NumericLiteral *){ deIndent(); nodeStack.pop(); }
    void endVisit(RegExpLiteral *){ deIndent(); nodeStack.pop(); }
    void endVisit(ArrayLiteral *){ deIndent(); nodeStack.pop(); }
    void endVisit(ObjectLiteral *){ deIndent(); nodeStack.pop(); }
    void endVisit(ElementList *){ deIndent(); nodeStack.pop(); }
    void endVisit(Elision *){ deIndent(); nodeStack.pop(); }
    void endVisit(PropertyAssignmentList *){ deIndent(); nodeStack.pop(); }
    void endVisit(PropertyNameAndValue *){ deIndent(); nodeStack.pop(); }
    void endVisit(PropertyGetterSetter *){ deIndent(); nodeStack.pop(); }
    void endVisit(NestedExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(IdentifierPropertyName *){ deIndent(); nodeStack.pop(); }
    void endVisit(StringLiteralPropertyName *){ deIndent(); nodeStack.pop(); }
    void endVisit(NumericLiteralPropertyName *){ deIndent(); nodeStack.pop(); }
    void endVisit(ArrayMemberExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(FieldMemberExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(NewMemberExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(NewExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(CallExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(ArgumentList *){ deIndent(); nodeStack.pop(); }
    void endVisit(PostIncrementExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(PostDecrementExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(DeleteExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(VoidExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(TypeOfExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(PreIncrementExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(PreDecrementExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(UnaryPlusExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(UnaryMinusExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(TildeExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(NotExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(BinaryExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(ConditionalExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(Expression *){ deIndent(); nodeStack.pop(); }
    void endVisit(Block *){ deIndent(); nodeStack.pop(); }
    void endVisit(StatementList *){ deIndent(); nodeStack.pop(); }
    void endVisit(VariableStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(VariableDeclarationList *){ deIndent(); nodeStack.pop(); }
    void endVisit(VariableDeclaration *){ deIndent(); nodeStack.pop(); }
    void endVisit(EmptyStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(ExpressionStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(IfStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(DoWhileStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(WhileStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(ForStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(LocalForStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(ForEachStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(LocalForEachStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(ContinueStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(BreakStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(ReturnStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(WithStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(SwitchStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(CaseBlock *){ deIndent(); nodeStack.pop(); }
    void endVisit(CaseClauses *){ deIndent(); nodeStack.pop(); }
    void endVisit(CaseClause *){ deIndent(); nodeStack.pop(); }
    void endVisit(DefaultClause *){ deIndent(); nodeStack.pop(); }
    void endVisit(LabelledStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(ThrowStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(TryStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(Catch *){ deIndent(); nodeStack.pop(); }
    void endVisit(Finally *){ deIndent(); nodeStack.pop(); }
    void endVisit(FunctionDeclaration *){ deIndent(); nodeStack.pop(); }
    void endVisit(FunctionExpression *){ deIndent(); nodeStack.pop(); }
    void endVisit(FormalParameterList *){ deIndent(); nodeStack.pop(); }
    void endVisit(FunctionBody *){ deIndent(); nodeStack.pop(); }
    void endVisit(Program *){ deIndent(); nodeStack.pop(); }
    void endVisit(SourceElements *){ deIndent(); nodeStack.pop(); }
    void endVisit(FunctionSourceElement *){ deIndent(); nodeStack.pop(); }
    void endVisit(StatementSourceElement *){ deIndent(); nodeStack.pop(); }
    void endVisit(DebuggerStatement *){ deIndent(); nodeStack.pop(); }
    void endVisit(UiObjectDefinition *);

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
    void expandIndent();
};

#endif // KRULEENGINE_QMLVISITOR_H
