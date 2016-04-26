// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#include "QmlVisitor.h"


bool QmlVisitor::visit(QQmlJS::AST::UiObjectDefinition *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;

    QQmlJS::AST::UiQualifiedId* next = exp->qualifiedTypeNameId->next;
    QString name = exp->qualifiedTypeNameId->name.toString();
    while (next != nullptr) {
        name.append(".").append(next->name);
        next = next->next;
    }
    NodeWrapper *n = new NodeWrapper(name, QString("String"), QString("ObjectDefinition"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }

    pushStack(n);
    return true; }

void QmlVisitor::endVisit(QQmlJS::AST::UiObjectDefinition*) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::IdentifierExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    NodeWrapper *n = new NodeWrapper(exp->name.toString(), QString("String"), QString("IdentifierExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }

    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::IdentifierExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiScriptBinding *exp)  {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("colonToken", isTokenPresent(exp->colonToken));
    QQmlJS::AST::UiQualifiedId* next = exp->qualifiedId->next;
    QString name = exp->qualifiedId->name.toString();
    while (next != nullptr) {
        name.append(".").append(next->name);
        next = next->next;
    }
    NodeWrapper *n = new NodeWrapper(name, QString(), QString("ScriptBinding"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }

    pushStack(n);
    return true;
}
void QmlVisitor::endVisit(QQmlJS::AST::UiScriptBinding *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::FunctionBody *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("FunctionBody"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }

    pushStack(n);
    return true;
}
void QmlVisitor::endVisit(QQmlJS::AST::FunctionBody *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiImport *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("asToken", isTokenPresent(exp->asToken));
    tokenMap.insert("importToken", isTokenPresent(exp->importToken));
    tokenMap.insert("semicolonToken", isTokenPresent(exp->semicolonToken));
    tokenMap.insert("versionToken", isTokenPresent(exp->versionToken));
    tokenMap.insert("fileNameToken", isTokenPresent(exp->fileNameToken));

    QString name;
    if (exp->importUri != nullptr) {
        QQmlJS::AST::UiQualifiedId* next = exp->importUri->next;
        name = exp->importUri->name.toString();
        while (next != nullptr) {
            name.append(".").append(next->name);
            next = next->next;
        }
    } else if (!exp->importId.isNull()) {
        name = exp->importId.toString();
    } else if (!exp->fileName.isNull()) {
        name = exp->fileName.toString();
    } else {
        name = "CASE NOT COVERED";
    }

    NodeWrapper *n = new NodeWrapper(name, QString("String"), QString("Import"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);

    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }

    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiImport *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiQualifiedId *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiQualifiedId *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiObjectInitializer *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiObjectInitializer *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiObjectMember *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }

bool QmlVisitor::visit(QQmlJS::AST::UiQualifiedPragmaId *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiQualifiedPragmaId *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiSourceElement *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiSourceElement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiArrayBinding *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("colonToken", isTokenPresent(exp->colonToken));
    tokenMap.insert("lbracketToken", isTokenPresent(exp->lbracketToken));
    tokenMap.insert("rbracketToken", isTokenPresent(exp->rbracketToken));

    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ArrayBinding"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiArrayBinding *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiProgram *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;

    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ProgramRoot"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiProgram *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiHeaderItemList *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    const QString nodeType = QString("HeaderItemList");
    NodeWrapper *n = new NodeWrapper(QString(), QString(), nodeType,
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        NodeWrapper *t = nodeStack.top();

        if (t->getNodeType().compare(nodeType) != 0) {
            t->addChild(n);
            pushStack(n);
        } else {
            dontPopAtEnd();
        }
    } else {
        pushStack(n);
    }
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiHeaderItemList *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiPragma *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("semicolonToken", isTokenPresent(exp->semicolonToken));

    QQmlJS::AST::UiQualifiedPragmaId* next = exp->pragmaType->next;
    QString name = exp->pragmaType->name.toString();
    while (next != nullptr) {
        name.append(".").append(next->name);
    }

    NodeWrapper *n = new NodeWrapper(name, QString(), QString("Pragma"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiPragma *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiPublicMember *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    NodeWrapper *v = new NodeWrapper(exp->name.toString(), QString("String"), QString("PublicMemberName"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    NodeWrapper *t = new NodeWrapper(exp->memberType.toString(), QString("String"), QString("PublicMemberType"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    tokenMap.insert("semicolonToken", isTokenPresent(exp->semicolonToken));
    tokenMap.insert("colonToken", isTokenPresent(exp->colonToken));
    tokenMap.insert("defaultToken", isTokenPresent(exp->defaultToken));
    tokenMap.insert("identifierToken", isTokenPresent(exp->identifierToken));
    tokenMap.insert("propertyToken", isTokenPresent(exp->propertyToken));
    tokenMap.insert("readonlyToken", isTokenPresent(exp->readonlyToken));
    tokenMap.insert("typeModifierToken", isTokenPresent(exp->typeModifierToken));
    tokenMap.insert("typeToken", isTokenPresent(exp->typeToken));
    NodeWrapper *n = new NodeWrapper("", "", QString("PublicMember"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    n->addChild(v);
    n->addChild(t);
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiPublicMember *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiObjectBinding *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("colonToken", isTokenPresent(exp->colonToken));

    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ObjectBinding"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiObjectBinding *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiParameterList *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("commaToken", isTokenPresent(exp->commaToken));
    tokenMap.insert("identifierToken", isTokenPresent(exp->identifierToken));
    tokenMap.insert("propertyTypeToken", isTokenPresent(exp->propertyTypeToken));
    NodeWrapper *p = new NodeWrapper(QString(), QString(), QString("Parameter"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    NodeWrapper *n = new NodeWrapper(exp->name.toString(), QString("String"), QString("Name"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), QMap<QString, bool>(), filename);
    NodeWrapper *t = new NodeWrapper(exp->type.toString(), QString("String"), QString("Type"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), QMap<QString, bool>(), filename);
    p->addChild(n);
    p->addChild(t);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(p);
    }
    pushStack(p);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiParameterList *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiObjectMemberList *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiObjectMemberList *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UiArrayMemberList *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    const QString nodeType = QString("ArrayMemberList");
    NodeWrapper *n = new NodeWrapper(QString(), QString(), nodeType,
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        NodeWrapper *t = nodeStack.top();

        if (t->getNodeType().compare(nodeType) != 0) {
            t->addChild(n);
            pushStack(n);
        } else {
            dontPopAtEnd();
        }
    } else {
        pushStack(n);
    }
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UiArrayMemberList *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::VariableStatement *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("declarationKindToken", isTokenPresent(exp->declarationKindToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("VariableStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::VariableStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ThisExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("thisToken", isTokenPresent(exp->thisToken));
    NodeWrapper *n = new NodeWrapper(QString("this"), QString("Token"), QString("ThisExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ThisExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::NullExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("nullToken", isTokenPresent(exp->nullToken));
    NodeWrapper *n = new NodeWrapper(QString("null"), QString("Token"), QString("NullExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::NullExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::TrueLiteral *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("trueToken", isTokenPresent(exp->trueToken));
    NodeWrapper *n = new NodeWrapper(QString("true"), QString("bool"), QString("TrueLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true;
}
void QmlVisitor::endVisit(QQmlJS::AST::TrueLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::FalseLiteral *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("falseToken", isTokenPresent(exp->falseToken));
    NodeWrapper *n = new NodeWrapper(QString("false"), QString("bool"), QString("FalseLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true;
}
void QmlVisitor::endVisit(QQmlJS::AST::FalseLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::StringLiteral *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("literalToken", isTokenPresent(exp->literalToken));
    NodeWrapper *n = new NodeWrapper(exp->value.toString(), QString("String"), QString("StringLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::StringLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::NumericLiteral *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("literalToken", isTokenPresent(exp->literalToken));
    NodeWrapper *n = new NodeWrapper(QString::number(exp->value), QString("Double"), QString("NumericLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::NumericLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::RegExpLiteral *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("literalToken", isTokenPresent(exp->literalToken));
    NodeWrapper *n = new NodeWrapper(exp->pattern.toString(), QString("String"), QString("RegExpLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::RegExpLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ArrayLiteral *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("commaToken", isTokenPresent(exp->commaToken));
    tokenMap.insert("lbracketToken", isTokenPresent(exp->lbracketToken));
    tokenMap.insert("rbracketToken", isTokenPresent(exp->rbracketToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ArrayLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ArrayLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ObjectLiteral *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("lbraceToken", isTokenPresent(exp->lbraceToken));
    tokenMap.insert("rbraceToken", isTokenPresent(exp->rbraceToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ObjectLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ObjectLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ElementList *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ElementList *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::Elision *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::Elision *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::PropertyAssignmentList *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::PropertyAssignmentList *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::PropertyGetterSetter *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("lbraceToken", isTokenPresent(exp->lbraceToken));
    tokenMap.insert("rbraceToken", isTokenPresent(exp->rbraceToken));
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));
    tokenMap.insert("getSetToken", isTokenPresent(exp->getSetToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("PropertyGetterSetter"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }

    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::PropertyGetterSetter *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::PropertyNameAndValue *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("lbraceToken", isTokenPresent(exp->colonToken));
    tokenMap.insert("rbraceToken", isTokenPresent(exp->commaToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("PropertyNameAndValue"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }

    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::PropertyNameAndValue *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::NestedExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("NestedExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::NestedExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::IdentifierPropertyName *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("porpertyNameToken", isTokenPresent(exp->propertyNameToken));
    NodeWrapper *n = new NodeWrapper(exp->id.toString(), QString("String"), QString("IdentifierPropertyName"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::IdentifierPropertyName *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::StringLiteralPropertyName *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("propertyNameToken", isTokenPresent(exp->propertyNameToken));
    NodeWrapper *n = new NodeWrapper(exp->id.toString(), QString("String"), QString("StringLiteralPropertyName"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::StringLiteralPropertyName *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::NumericLiteralPropertyName *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("propertyNameToken", isTokenPresent(exp->propertyNameToken));
    NodeWrapper *n = new NodeWrapper(QString::number(exp->id), QString("Double"), QString("NumericLiteralPropertyName"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::NumericLiteralPropertyName *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ArrayMemberExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("lbracketToken", isTokenPresent(exp->lbracketToken));
    tokenMap.insert("rbracketToken", isTokenPresent(exp->rbracketToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ArrayMemberExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ArrayMemberExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::FieldMemberExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("dotToken", isTokenPresent(exp->dotToken));
    tokenMap.insert("identifierToken", isTokenPresent(exp->identifierToken));
    NodeWrapper *n = new NodeWrapper(exp->name.toString(), QString("String"), QString("FieldMemberExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::FieldMemberExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::NewMemberExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("newToken", isTokenPresent(exp->newToken));
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("NewMemberExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::NewMemberExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::NewExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("newToken", isTokenPresent(exp->newToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("NewExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::NewExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::CallExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("CallExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::CallExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ArgumentList *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    const QString nodeType = QString("ArgumentList");
    NodeWrapper *n = new NodeWrapper(QString(), QString(), nodeType,
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        NodeWrapper *t = nodeStack.top();

        if (t->getNodeType().compare(nodeType) != 0) {
            t->addChild(n);
            pushStack(n);
        } else {
            dontPopAtEnd();
        }
    } else {
        pushStack(n);
    }
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ArgumentList *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::PostIncrementExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("incrementToken", isTokenPresent(exp->incrementToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("PostIncrementExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::PostIncrementExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::PostDecrementExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("decrementToken", isTokenPresent(exp->decrementToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("PostDecrementExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::PostDecrementExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::DeleteExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("deleteToken", isTokenPresent(exp->deleteToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("DeleteExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::DeleteExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::VoidExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("voidToken", isTokenPresent(exp->voidToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("VoidExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::VoidExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::TypeOfExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("typeofToken", isTokenPresent(exp->typeofToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("TypeOfExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::TypeOfExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::PreIncrementExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("incrementToken", isTokenPresent(exp->incrementToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("PreIncrementExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::PreIncrementExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::PreDecrementExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("decrementToken", isTokenPresent(exp->decrementToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("PreDecrementExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::PreDecrementExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UnaryPlusExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("plusToken", isTokenPresent(exp->plusToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("UnaryPlusExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UnaryPlusExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::UnaryMinusExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("minusToken", isTokenPresent(exp->minusToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("UnaryMinusExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    addWrapper(n);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::UnaryMinusExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::TildeExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;

    tokenMap.insert("tildeToken", isTokenPresent(exp->tildeToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("TildeExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::TildeExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::NotExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;

    tokenMap.insert("notToken", isTokenPresent(exp->notToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("NotExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::NotExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::BinaryExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("operatorToken", isTokenPresent(exp->operatorToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("BinaryExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::BinaryExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ConditionalExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("questionToken", isTokenPresent(exp->questionToken));
    tokenMap.insert("colonToken", isTokenPresent(exp->colonToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("ConditionalExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ConditionalExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::Block *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("lbraceToken", isTokenPresent(exp->lbraceToken));
    tokenMap.insert("rbraceToken", isTokenPresent(exp->rbraceToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("Block"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);


    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::Block *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::StatementList *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::StatementList *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::VariableDeclarationList *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    const QString nodeType = QString("VariableDeclaraionList");
    NodeWrapper *n = new NodeWrapper(QString(), QString(), nodeType,
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        NodeWrapper *t = nodeStack.top();

        if (t->getNodeType().compare(nodeType) != 0) {
            t->addChild(n);
            pushStack(n);
        } else {
            dontPopAtEnd();
        }
    } else {
        pushStack(n);
    }
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::VariableDeclarationList *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::VariableDeclaration *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("identifierToken", isTokenPresent(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->name.toString(),QString("String"), QString("VariableDeclaration"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::VariableDeclaration *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::EmptyStatement *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("semicolonToken", isTokenPresent(exp->semicolonToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("EmptyStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::EmptyStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ExpressionStatement *exp) {
    debug(exp);
    dontPopAtEnd();

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ExpressionStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::IfStatement *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("ifToken", isTokenPresent(exp->ifToken));
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));
    tokenMap.insert("elseToken", isTokenPresent(exp->elseToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("IfStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::IfStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::DoWhileStatement *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("whileToken", isTokenPresent(exp->whileToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("lparenToken", isTokenPresent(exp->rparenToken));
    tokenMap.insert("semicolonToken", isTokenPresent(exp->semicolonToken));
    tokenMap.insert("doToken", isTokenPresent(exp->doToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("DoWhileStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::DoWhileStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::WhileStatement *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("whileToken", isTokenPresent(exp->whileToken));
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("WhileStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::WhileStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ForStatement *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("forToken", isTokenPresent(exp->forToken));
    tokenMap.insert("firstSemicolonToken", isTokenPresent(exp->firstSemicolonToken));
    tokenMap.insert("secondSemicolonToken", isTokenPresent(exp->secondSemicolonToken));
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("ForStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ForStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::LocalForStatement *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("forToken", isTokenPresent(exp->forToken));
    tokenMap.insert("firstSemicolonToken", isTokenPresent(exp->firstSemicolonToken));
    tokenMap.insert("varToken", isTokenPresent(exp->varToken));
    tokenMap.insert("secondSemicolonToken", isTokenPresent(exp->secondSemicolonToken));
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("LocalForStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::LocalForStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ForEachStatement *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("forToken", isTokenPresent(exp->forToken));
    tokenMap.insert("inToken", isTokenPresent(exp->inToken));
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("ForEachStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ForEachStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::LocalForEachStatement *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("forToken", isTokenPresent(exp->forToken));
    tokenMap.insert("inToken", isTokenPresent(exp->inToken));
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("varToken", isTokenPresent(exp->varToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("LocalForEachStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::LocalForEachStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ContinueStatement *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("semicolonToken", isTokenPresent(exp->semicolonToken));
    tokenMap.insert("continueToken", isTokenPresent(exp->continueToken));
    tokenMap.insert("identifierToken", isTokenPresent(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->label.toString(),QString("String"), QString("ContinueStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ContinueStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::BreakStatement *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("semicolonToken", isTokenPresent(exp->semicolonToken));
    tokenMap.insert("breakToken", isTokenPresent(exp->breakToken));
    tokenMap.insert("identifierToken", isTokenPresent(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->label.toString(),QString("String"), QString("BreakStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::BreakStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ReturnStatement *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("semicolonToken", isTokenPresent(exp->semicolonToken));
    tokenMap.insert("returnToken", isTokenPresent(exp->returnToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("ReturnStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ReturnStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::WithStatement *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));
    tokenMap.insert("withToken", isTokenPresent(exp->withToken));


    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("WithStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::WithStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::SwitchStatement *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));
    tokenMap.insert("switchToken", isTokenPresent(exp->switchToken));


    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("SwitchStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::SwitchStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::CaseBlock *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("lbraceToken", isTokenPresent(exp->lbraceToken));
    tokenMap.insert("rbraceToken", isTokenPresent(exp->rbraceToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("CaseBlock"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::CaseBlock *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::CaseClauses *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("CaseClauses"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::CaseClauses *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::CaseClause *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("colonToken", isTokenPresent(exp->colonToken));
    tokenMap.insert("caseToken", isTokenPresent(exp->caseToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("CaseClause"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::CaseClause *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::DefaultClause *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("colonToken", isTokenPresent(exp->colonToken));
    tokenMap.insert("defaultToken", isTokenPresent(exp->defaultToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("DefaultClause"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::DefaultClause *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::LabelledStatement *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("colonToken", isTokenPresent(exp->colonToken));
    tokenMap.insert("identifierToken", isTokenPresent(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->label.toString(),QString("String"), QString("LabelledStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::LabelledStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::ThrowStatement *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("semicolonToken", isTokenPresent(exp->semicolonToken));
    tokenMap.insert("throwToken", isTokenPresent(exp->throwToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("ThrowStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::ThrowStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::TryStatement *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("tryToken", isTokenPresent(exp->tryToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("TryStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::TryStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::Catch *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("catchToken", isTokenPresent(exp->catchToken));
    tokenMap.insert("identifierToken", isTokenPresent(exp->identifierToken));
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(exp->name.toString(),QString("String"), QString("Catch"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::Catch *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::Finally *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    tokenMap.insert("finallyToken", isTokenPresent(exp->finallyToken));
    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("Finally"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::Finally *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::FunctionDeclaration *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("FunctionDeclaration"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::FunctionDeclaration *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::FunctionExpression *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    tokenMap.insert("functionToken", isTokenPresent(exp->functionToken));
    tokenMap.insert("identifierToken", isTokenPresent(exp->identifierToken));
    tokenMap.insert("lbraceToken", isTokenPresent(exp->lbraceToken));
    tokenMap.insert("rbraceToken", isTokenPresent(exp->rbraceToken));
    tokenMap.insert("rparenToken", isTokenPresent(exp->rparenToken));
    tokenMap.insert("lparenToken", isTokenPresent(exp->lparenToken));

    NodeWrapper *n = new NodeWrapper(exp->name.toString(),QString("String") , QString("FunctionExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::FunctionExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::FormalParameterList *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    const QString nodeType = QString("FormalParameterList");
    NodeWrapper *n = new NodeWrapper(QString(), QString(), nodeType,
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if (!nodeStack.isEmpty()) {
        NodeWrapper *t = nodeStack.top();

        if (t->getNodeType().compare(nodeType) != 0) {
            t->addChild(n);
            pushStack(n);
        } else {
            dontPopAtEnd();
        }
    } else {
        pushStack(n);
    }

    /////////////////////////////////////////////////////////////////////////////////////

    tokenMap.insert("commaToken", isTokenPresent(exp->commaToken));
    tokenMap.insert("identifierToken", isTokenPresent(exp->identifierToken));
    NodeWrapper *p = new NodeWrapper(exp->name.toString(), QString("String"), QString("FormalParameter"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty()) {
        nodeStack.top()->addChild(p);
    }
    if (exp->next != nullptr) {
        visit(exp->next);
        endVisit(exp->next);
    }

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::FormalParameterList *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::Program *exp) {
    debug(exp);

    QMap<QString, bool> tokenMap;
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("Program"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::Program *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::SourceElements *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::SourceElements *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::FunctionSourceElement *exp) {
    debug(exp);
    QMap<QString, bool> tokenMap;
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("FunctionSourceElement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokenMap, filename);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::FunctionSourceElement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::StatementSourceElement *exp) {
    debug(exp);
    dontPopAtEnd();

    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::StatementSourceElement *) { commonEndVisit(); }

bool QmlVisitor::visit(QQmlJS::AST::DebuggerStatement *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(QQmlJS::AST::DebuggerStatement *) { commonEndVisit(); }

void QmlVisitor::debug(const QQmlJS::AST::Node *exp) {
    QString name = QString(typeid(*exp).name());

    name = name.remove(QRegExp(".*AST[0-9]*"));
    name.chop(1);

    QString source = getSource(exp).toString();
    const int max = 70;
    if (source.length() > max) {
        source.chop(source.length() - max);
    }

    qDebug() << indent << name
             << source;
    expandIndent();
}

const QStringRef QmlVisitor::printable(const QQmlJS::AST::SourceLocation &start, const QQmlJS::AST::SourceLocation &end) {
    return QStringRef(&_code, start.offset, end.offset + end.length - start.offset);
}

const QStringRef QmlVisitor::getSource(const QQmlJS::AST::Node *exp) {
    return printable(exp->firstSourceLocation(), exp->lastSourceLocation());
}

NodeWrapper* QmlVisitor::getWrappedRoot() {
    return rootNode;
}

void QmlVisitor::endVisit(QQmlJS::AST::Expression *) { commonEndVisit(); }

void QmlVisitor::deIndent() {
    indent.chop(4);
}

void QmlVisitor::expandIndent() {
    indent.append("    ");
}

void QmlVisitor::pushStack(NodeWrapper* n) {
    if (nodeStack.isEmpty() && rootNode == nullptr) {
        rootNode = n;
    }
    shouldPopStack.push(true);
    nodeStack.push(n);
}

void QmlVisitor::commonEndVisit() {
    deIndent();
    if (!nodeStack.isEmpty() && shouldPopStack.pop()) {
        nodeStack.pop();
    }
}

void QmlVisitor::addWrapper(NodeWrapper *n)
{
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
}

void QmlVisitor::dontPopAtEnd() {
    shouldPopStack.push(false);
}

const bool QmlVisitor::isTokenPresent(const QQmlJS::AST::SourceLocation &sl) {
    return QStringRef(&_code, sl.offset, sl.length).length() > 0;
}
