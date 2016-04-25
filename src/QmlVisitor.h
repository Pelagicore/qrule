// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
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


class QmlVisitor: public QQmlJS::AST::Visitor {
public:
    QmlVisitor(QString code, QString filename): _code(code), filename(filename){}
    virtual ~QmlVisitor() {
    }

    bool visit(QQmlJS::AST::FunctionBody *);
    bool visit(QQmlJS::AST::UiImport *);
    bool visit(QQmlJS::AST::UiQualifiedId *);
    bool visit(QQmlJS::AST::UiObjectInitializer *);
    bool visit(QQmlJS::AST::UiObjectMember *);
    bool visit(QQmlJS::AST::UiQualifiedPragmaId *);
    bool visit(QQmlJS::AST::UiSourceElement *);
    bool visit(QQmlJS::AST::UiArrayBinding *);
    bool visit(QQmlJS::AST::UiProgram *);
    bool visit(QQmlJS::AST::UiHeaderItemList *);
    bool visit(QQmlJS::AST::UiPragma *);
    bool visit(QQmlJS::AST::UiPublicMember *);
    bool visit(QQmlJS::AST::UiObjectBinding *);
    bool visit(QQmlJS::AST::UiScriptBinding *exp);
    bool visit(QQmlJS::AST::UiParameterList *);
    bool visit(QQmlJS::AST::UiObjectMemberList *);
    bool visit(QQmlJS::AST::UiArrayMemberList *);
    bool visit(QQmlJS::AST::VariableStatement *);
    bool visit(QQmlJS::AST::ThisExpression *);
    bool visit(QQmlJS::AST::NullExpression *);
    bool visit(QQmlJS::AST::TrueLiteral *exp);
    bool visit(QQmlJS::AST::FalseLiteral *exp);
    bool visit(QQmlJS::AST::StringLiteral *);
    bool visit(QQmlJS::AST::NumericLiteral *);
    bool visit(QQmlJS::AST::RegExpLiteral *);
    bool visit(QQmlJS::AST::ArrayLiteral *);
    bool visit(QQmlJS::AST::ObjectLiteral *);
    bool visit(QQmlJS::AST::ElementList *);
    bool visit(QQmlJS::AST::Elision *);
    bool visit(QQmlJS::AST::PropertyAssignmentList *);
    bool visit(QQmlJS::AST::PropertyGetterSetter *);
    bool visit(QQmlJS::AST::PropertyNameAndValue *);
    bool visit(QQmlJS::AST::NestedExpression *);
    bool visit(QQmlJS::AST::IdentifierPropertyName *);
    bool visit(QQmlJS::AST::StringLiteralPropertyName *);
    bool visit(QQmlJS::AST::NumericLiteralPropertyName *);
    bool visit(QQmlJS::AST::ArrayMemberExpression *);
    bool visit(QQmlJS::AST::FieldMemberExpression *);
    bool visit(QQmlJS::AST::NewMemberExpression *);
    bool visit(QQmlJS::AST::NewExpression *);
    bool visit(QQmlJS::AST::CallExpression *);
    bool visit(QQmlJS::AST::ArgumentList *);
    bool visit(QQmlJS::AST::PostIncrementExpression *);
    bool visit(QQmlJS::AST::PostDecrementExpression *);
    bool visit(QQmlJS::AST::DeleteExpression *);
    bool visit(QQmlJS::AST::VoidExpression *);
    bool visit(QQmlJS::AST::TypeOfExpression *);
    bool visit(QQmlJS::AST::PreIncrementExpression *);
    bool visit(QQmlJS::AST::PreDecrementExpression *);
    bool visit(QQmlJS::AST::UnaryPlusExpression *);
    bool visit(QQmlJS::AST::UnaryMinusExpression *);
    bool visit(QQmlJS::AST::TildeExpression *);
    bool visit(QQmlJS::AST::NotExpression *);
    bool visit(QQmlJS::AST::BinaryExpression *);
    bool visit(QQmlJS::AST::ConditionalExpression *);
    bool visit(QQmlJS::AST::Block *);
    bool visit(QQmlJS::AST::StatementList *);
    bool visit(QQmlJS::AST::VariableDeclarationList *);
    bool visit(QQmlJS::AST::VariableDeclaration *);
    bool visit(QQmlJS::AST::EmptyStatement *);
    bool visit(QQmlJS::AST::ExpressionStatement *);
    bool visit(QQmlJS::AST::IfStatement *);
    bool visit(QQmlJS::AST::DoWhileStatement *);
    bool visit(QQmlJS::AST::WhileStatement *);
    bool visit(QQmlJS::AST::ForStatement *);
    bool visit(QQmlJS::AST::LocalForStatement *);
    bool visit(QQmlJS::AST::ForEachStatement *);
    bool visit(QQmlJS::AST::LocalForEachStatement *);
    bool visit(QQmlJS::AST::ContinueStatement *);
    bool visit(QQmlJS::AST::BreakStatement *);
    bool visit(QQmlJS::AST::ReturnStatement *);
    bool visit(QQmlJS::AST::WithStatement *);
    bool visit(QQmlJS::AST::SwitchStatement *);
    bool visit(QQmlJS::AST::CaseBlock *);
    bool visit(QQmlJS::AST::CaseClauses *);
    bool visit(QQmlJS::AST::CaseClause *);
    bool visit(QQmlJS::AST::DefaultClause *);
    bool visit(QQmlJS::AST::LabelledStatement *);
    bool visit(QQmlJS::AST::ThrowStatement *);
    bool visit(QQmlJS::AST::TryStatement *);
    bool visit(QQmlJS::AST::Catch *);
    bool visit(QQmlJS::AST::Finally *);
    bool visit(QQmlJS::AST::FunctionDeclaration *);
    bool visit(QQmlJS::AST::FunctionExpression *);
    bool visit(QQmlJS::AST::FormalParameterList *);
    bool visit(QQmlJS::AST::Program *);
    bool visit(QQmlJS::AST::SourceElements *);
    bool visit(QQmlJS::AST::FunctionSourceElement *);
    bool visit(QQmlJS::AST::StatementSourceElement *);
    bool visit(QQmlJS::AST::DebuggerStatement *);
    bool visit(QQmlJS::AST::IdentifierExpression *);
    bool visit(QQmlJS::AST::UiObjectDefinition *);

    void endVisit(QQmlJS::AST::UiProgram *);
    void endVisit(QQmlJS::AST::UiImport *);
    void endVisit(QQmlJS::AST::UiHeaderItemList *);
    void endVisit(QQmlJS::AST::UiPragma *);
    void endVisit(QQmlJS::AST::UiPublicMember *);
    void endVisit(QQmlJS::AST::UiSourceElement *);
    void endVisit(QQmlJS::AST::UiObjectInitializer *);
    void endVisit(QQmlJS::AST::UiObjectBinding *);
    void endVisit(QQmlJS::AST::UiScriptBinding *);
    void endVisit(QQmlJS::AST::UiArrayBinding *);
    void endVisit(QQmlJS::AST::UiParameterList *);
    void endVisit(QQmlJS::AST::UiObjectMemberList *);
    void endVisit(QQmlJS::AST::UiArrayMemberList *);
    void endVisit(QQmlJS::AST::UiQualifiedId *);
    void endVisit(QQmlJS::AST::UiQualifiedPragmaId *);
    void endVisit(QQmlJS::AST::ThisExpression *);
    void endVisit(QQmlJS::AST::IdentifierExpression *);
    void endVisit(QQmlJS::AST::NullExpression *);
    void endVisit(QQmlJS::AST::TrueLiteral *);
    void endVisit(QQmlJS::AST::FalseLiteral *);
    void endVisit(QQmlJS::AST::StringLiteral *);
    void endVisit(QQmlJS::AST::NumericLiteral *);
    void endVisit(QQmlJS::AST::RegExpLiteral *);
    void endVisit(QQmlJS::AST::ArrayLiteral *);
    void endVisit(QQmlJS::AST::ObjectLiteral *);
    void endVisit(QQmlJS::AST::ElementList *);
    void endVisit(QQmlJS::AST::Elision *);
    void endVisit(QQmlJS::AST::PropertyAssignmentList *);
    void endVisit(QQmlJS::AST::PropertyNameAndValue *);
    void endVisit(QQmlJS::AST::PropertyGetterSetter *);
    void endVisit(QQmlJS::AST::NestedExpression *);
    void endVisit(QQmlJS::AST::IdentifierPropertyName *);
    void endVisit(QQmlJS::AST::StringLiteralPropertyName *);
    void endVisit(QQmlJS::AST::NumericLiteralPropertyName *);
    void endVisit(QQmlJS::AST::ArrayMemberExpression *);
    void endVisit(QQmlJS::AST::FieldMemberExpression *);
    void endVisit(QQmlJS::AST::NewMemberExpression *);
    void endVisit(QQmlJS::AST::NewExpression *);
    void endVisit(QQmlJS::AST::CallExpression *);
    void endVisit(QQmlJS::AST::ArgumentList *);
    void endVisit(QQmlJS::AST::PostIncrementExpression *);
    void endVisit(QQmlJS::AST::PostDecrementExpression *);
    void endVisit(QQmlJS::AST::DeleteExpression *);
    void endVisit(QQmlJS::AST::VoidExpression *);
    void endVisit(QQmlJS::AST::TypeOfExpression *);
    void endVisit(QQmlJS::AST::PreIncrementExpression *);
    void endVisit(QQmlJS::AST::PreDecrementExpression *);
    void endVisit(QQmlJS::AST::UnaryPlusExpression *);
    void endVisit(QQmlJS::AST::UnaryMinusExpression *);
    void endVisit(QQmlJS::AST::TildeExpression *);
    void endVisit(QQmlJS::AST::NotExpression *);
    void endVisit(QQmlJS::AST::BinaryExpression *);
    void endVisit(QQmlJS::AST::ConditionalExpression *);
    void endVisit(QQmlJS::AST::Expression *);
    void endVisit(QQmlJS::AST::Block *);
    void endVisit(QQmlJS::AST::StatementList *);
    void endVisit(QQmlJS::AST::VariableStatement *);
    void endVisit(QQmlJS::AST::VariableDeclarationList *);
    void endVisit(QQmlJS::AST::VariableDeclaration *);
    void endVisit(QQmlJS::AST::EmptyStatement *);
    void endVisit(QQmlJS::AST::ExpressionStatement *);
    void endVisit(QQmlJS::AST::IfStatement *);
    void endVisit(QQmlJS::AST::DoWhileStatement *);
    void endVisit(QQmlJS::AST::WhileStatement *);
    void endVisit(QQmlJS::AST::ForStatement *);
    void endVisit(QQmlJS::AST::LocalForStatement *);
    void endVisit(QQmlJS::AST::ForEachStatement *);
    void endVisit(QQmlJS::AST::LocalForEachStatement *);
    void endVisit(QQmlJS::AST::ContinueStatement *);
    void endVisit(QQmlJS::AST::BreakStatement *);
    void endVisit(QQmlJS::AST::ReturnStatement *);
    void endVisit(QQmlJS::AST::WithStatement *);
    void endVisit(QQmlJS::AST::SwitchStatement *);
    void endVisit(QQmlJS::AST::CaseBlock *);
    void endVisit(QQmlJS::AST::CaseClauses *);
    void endVisit(QQmlJS::AST::CaseClause *);
    void endVisit(QQmlJS::AST::DefaultClause *);
    void endVisit(QQmlJS::AST::LabelledStatement *);
    void endVisit(QQmlJS::AST::ThrowStatement *);
    void endVisit(QQmlJS::AST::TryStatement *);
    void endVisit(QQmlJS::AST::Catch *);
    void endVisit(QQmlJS::AST::Finally *);
    void endVisit(QQmlJS::AST::FunctionDeclaration *);
    void endVisit(QQmlJS::AST::FunctionExpression *);
    void endVisit(QQmlJS::AST::FormalParameterList *);
    void endVisit(QQmlJS::AST::FunctionBody *);
    void endVisit(QQmlJS::AST::Program *);
    void endVisit(QQmlJS::AST::SourceElements *);
    void endVisit(QQmlJS::AST::FunctionSourceElement *);
    void endVisit(QQmlJS::AST::StatementSourceElement *);
    void endVisit(QQmlJS::AST::DebuggerStatement *);
    void endVisit(QQmlJS::AST::UiObjectDefinition *);


    NodeWrapper* getWrappedRoot();

private:
    QString indent = "";

    QString notPairedParamValue = "";
    QString notPairedParamName  = "";
    QString _code;

    QString filename;

    NodeWrapper *rootNode = nullptr;
    QStack<NodeWrapper*> nodeStack;
    QStack<bool> shouldPopStack;
    void pushStack(NodeWrapper*);
    void commonEndVisit();
    void dontPopAtEnd();

    void addWrapper(NodeWrapper *n);

    const bool isTokenPresent(const QQmlJS::AST::SourceLocation &sl);
    const QStringRef getSource(const QQmlJS::AST::Node *);
    const QStringRef printable(const QQmlJS::AST::SourceLocation &start, const QQmlJS::AST::SourceLocation &end);

    void debug(const QQmlJS::AST::Node *);
    void deIndent();
    void expandIndent();
};

#endif // KRULEENGINE_QMLVISITOR_H
