#ifndef QMLCHILDREN_H
#define QMLCHILDREN_H

#include <QList>
#include "private/qqmljsast_p.h"

using namespace QQmlJS::AST;
QList<Node*> children(Node *);
QList<Node*> children(UiProgram *);
QList<Node*> children(UiHeaderItemList *);
QList<Node*> children(UiPragma *);
QList<Node*> children(UiImport *);
QList<Node*> children(UiPublicMember *);
QList<Node*> children(UiSourceElement *);
QList<Node*> children(UiObjectDefinition *);
QList<Node*> children(UiObjectInitializer *);
QList<Node*> children(UiObjectBinding *);
QList<Node*> children(UiScriptBinding *);
QList<Node*> children(UiArrayBinding *);
QList<Node*> children(UiParameterList *);
QList<Node*> children(UiObjectMemberList *);
QList<Node*> children(UiArrayMemberList *);
QList<Node*> children(UiQualifiedId *);
QList<Node*> children(UiQualifiedPragmaId *);

QList<Node*> children(ThisExpression *);

QList<Node*> children(IdentifierExpression *);

QList<Node*> children(NullExpression *);

QList<Node*> children(TrueLiteral *);

QList<Node*> children(FalseLiteral *);

QList<Node*> children(StringLiteral *);

QList<Node*> children(NumericLiteral *);

QList<Node*> children(RegExpLiteral *);

QList<Node*> children(ArrayLiteral *);

QList<Node*> children(ObjectLiteral *);

QList<Node*> children(ElementList *);

QList<Node*> children(Elision *);

QList<Node*> children(PropertyAssignmentList *);

QList<Node*> children(PropertyNameAndValue *);

QList<Node*> children(PropertyGetterSetter *);

QList<Node*> children(NestedExpression *);

QList<Node*> children(IdentifierPropertyName *);

QList<Node*> children(StringLiteralPropertyName *);

QList<Node*> children(NumericLiteralPropertyName *);

QList<Node*> children(ArrayMemberExpression *);

QList<Node*> children(FieldMemberExpression *);

QList<Node*> children(NewMemberExpression *);

QList<Node*> children(NewExpression *);

QList<Node*> children(CallExpression *);

QList<Node*> children(ArgumentList *);

QList<Node*> children(PostIncrementExpression *);

QList<Node*> children(PostDecrementExpression *);

QList<Node*> children(DeleteExpression *);

QList<Node*> children(VoidExpression *);

QList<Node*> children(TypeOfExpression *);

QList<Node*> children(PreIncrementExpression *);

QList<Node*> children(PreDecrementExpression *);

QList<Node*> children(UnaryPlusExpression *);

QList<Node*> children(UnaryMinusExpression *);

QList<Node*> children(TildeExpression *);

QList<Node*> children(NotExpression *);

QList<Node*> children(BinaryExpression *);

QList<Node*> children(ConditionalExpression *);

QList<Node*> children(Expression *);

QList<Node*> children(Block *);

QList<Node*> children(StatementList *);

QList<Node*> children(VariableStatement *);

QList<Node*> children(VariableDeclarationList *);

QList<Node*> children(VariableDeclaration *);

QList<Node*> children(EmptyStatement *);

QList<Node*> children(ExpressionStatement *);

QList<Node*> children(IfStatement *);

QList<Node*> children(DoWhileStatement *);

QList<Node*> children(WhileStatement *);

QList<Node*> children(ForStatement *);

QList<Node*> children(LocalForStatement *);

QList<Node*> children(ForEachStatement *);

QList<Node*> children(LocalForEachStatement *);

QList<Node*> children(ContinueStatement *);

QList<Node*> children(BreakStatement *);

QList<Node*> children(ReturnStatement *);

QList<Node*> children(WithStatement *);

QList<Node*> children(SwitchStatement *);

QList<Node*> children(CaseBlock *);

QList<Node*> children(CaseClauses *);

QList<Node*> children(CaseClause *);

QList<Node*> children(DefaultClause *);

QList<Node*> children(LabelledStatement *);

QList<Node*> children(ThrowStatement *);

QList<Node*> children(TryStatement *);

QList<Node*> children(Catch *);

QList<Node*> children(Finally *);

QList<Node*> children(FunctionDeclaration *);

QList<Node*> children(FunctionExpression *);

QList<Node*> children(FormalParameterList *);

QList<Node*> children(FunctionBody *);

QList<Node*> children(Program *);

QList<Node*> children(SourceElements *);

QList<Node*> children(FunctionSourceElement *);

QList<Node*> children(StatementSourceElement *);

QList<Node*> children(DebuggerStatement *);


#endif // QMLCHILDREN_H
