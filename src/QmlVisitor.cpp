#include "QmlVisitor.h"


bool QmlVisitor::visit(UiObjectDefinition *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }

void QmlVisitor::endVisit(UiObjectDefinition*) { commonEndVisit(); }

bool QmlVisitor::visit(IdentifierExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    NodeWrapper *n = new NodeWrapper(exp->name.toString(), QString("String"), QString("IdentifierExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }

    pushStack(n);
    return true; }
void QmlVisitor::endVisit(IdentifierExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(UiScriptBinding *exp)  {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->colonToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ScriptBinding"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }

    pushStack(n);
    return true;
}
void QmlVisitor::endVisit(UiScriptBinding *) { commonEndVisit(); }

bool QmlVisitor::visit(FunctionBody *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("FunctionBody"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }

    pushStack(n);
    return true;
}
void QmlVisitor::endVisit(FunctionBody *) { commonEndVisit(); }

bool QmlVisitor::visit(UiImport *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->asToken));
    tokens.append(toQStringRef(exp->importToken));
    tokens.append(toQStringRef(exp->semicolonToken));
    tokens.append(toQStringRef(exp->versionToken));
    tokens.append(toQStringRef(exp->fileNameToken));
    NodeWrapper *n = new NodeWrapper(exp->importId.toString(), QString("String"), QString("Import"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);

    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }

    pushStack(n);
    return true; }
void QmlVisitor::endVisit(UiImport *) { commonEndVisit(); }

QStringRef QmlVisitor::toQStringRef(const SourceLocation &sl) {
    return QStringRef(&_code, sl.offset, sl.length);
}


bool QmlVisitor::visit(UiQualifiedId *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->name.toString(), QString("String"), QString("QualifiedId"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(UiQualifiedId *) { commonEndVisit(); }

bool QmlVisitor::visit(UiObjectInitializer *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->lbraceToken));
    tokens.append(toQStringRef(exp->rbraceToken));

    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ObjectInitializer"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(UiObjectInitializer *) { commonEndVisit(); }

bool QmlVisitor::visit(UiObjectMember *exp) {
    debug(exp);
    // ABSTRACT
    dontPopAtEnd();
    return true; }

bool QmlVisitor::visit(UiQualifiedPragmaId *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->name.toString(), QString("String"), QString("QualifiedPragmaId"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(UiQualifiedPragmaId *) { commonEndVisit(); }

bool QmlVisitor::visit(UiSourceElement *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(UiSourceElement *) { commonEndVisit(); }

bool QmlVisitor::visit(UiArrayBinding *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->colonToken));
    tokens.append(toQStringRef(exp->lbracketToken));
    tokens.append(toQStringRef(exp->rbracketToken));

    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ArrayBinding"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(UiArrayBinding *) { commonEndVisit(); }

bool QmlVisitor::visit(UiProgram *exp) {
    debug(exp);
    QList<QStringRef> tokens;

    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ProgramRoot"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(UiProgram *) { commonEndVisit(); }

bool QmlVisitor::visit(UiHeaderItemList *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    const QString nodeType = QString("HeaderItemList");
    NodeWrapper *n = new NodeWrapper(QString(), QString(), nodeType,
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        NodeWrapper *t = nodeStack.top();
        t->addChild(n);

        if (t->getNodeType().compare(nodeType) != 0) {
            pushStack(n);
        } else {
            dontPopAtEnd();
        }
    } else {
        pushStack(n);
    }
    return true; }
void QmlVisitor::endVisit(UiHeaderItemList *) { commonEndVisit(); }

bool QmlVisitor::visit(UiPragma *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->semicolonToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("Pragma"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(UiPragma *) { commonEndVisit(); }

bool QmlVisitor::visit(UiPublicMember *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->semicolonToken));
    tokens.append(toQStringRef(exp->colonToken));
    tokens.append(toQStringRef(exp->defaultToken));
    tokens.append(toQStringRef(exp->identifierToken));
    tokens.append(toQStringRef(exp->propertyToken));
    tokens.append(toQStringRef(exp->readonlyToken));
    tokens.append(toQStringRef(exp->typeModifierToken));
    tokens.append(toQStringRef(exp->typeToken));
    NodeWrapper *n = new NodeWrapper(exp->memberType.toString(), QString("String"), QString("PublicMember"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(UiPublicMember *) { commonEndVisit(); }

bool QmlVisitor::visit(UiObjectBinding *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->colonToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ObjectBinding"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(UiObjectBinding *) { commonEndVisit(); }

bool QmlVisitor::visit(UiParameterList *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->commaToken));
    tokens.append(toQStringRef(exp->identifierToken));
    tokens.append(toQStringRef(exp->propertyTypeToken));
    NodeWrapper *p = new NodeWrapper(QString(), QString(), QString("Parameter"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    NodeWrapper *n = new NodeWrapper(exp->name.toString(), QString("String"), QString("Name"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), QList<QStringRef>());
    NodeWrapper *t = new NodeWrapper(exp->type.toString(), QString("String"), QString("Type"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), QList<QStringRef>());
    p->addChild(n);
    p->addChild(t);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(p);
    }
    pushStack(p);
    return true; }
void QmlVisitor::endVisit(UiParameterList *) { commonEndVisit(); }

bool QmlVisitor::visit(UiObjectMemberList *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    const QString nodeType = QString("ObjectMemberList");
    NodeWrapper *n = new NodeWrapper(QString(), QString(), nodeType,
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        NodeWrapper *t = nodeStack.top();
        t->addChild(n);

        if (t->getNodeType().compare(nodeType) != 0) {
            pushStack(n);
        } else {
            dontPopAtEnd();
        }
    } else {
        pushStack(n);
    }
    return true; }
void QmlVisitor::endVisit(UiObjectMemberList *) { commonEndVisit(); }

bool QmlVisitor::visit(UiArrayMemberList *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    const QString nodeType = QString("ArrayMemberList");
    NodeWrapper *n = new NodeWrapper(QString(), QString(), nodeType,
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        NodeWrapper *t = nodeStack.top();
        t->addChild(n);

        if (t->getNodeType().compare(nodeType) != 0) {
            pushStack(n);
        } else {
            dontPopAtEnd();
        }
    } else {
        pushStack(n);
    }
    return true; }
void QmlVisitor::endVisit(UiArrayMemberList *) { commonEndVisit(); }

bool QmlVisitor::visit(VariableStatement *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->declarationKindToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("VariableStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(VariableStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(ThisExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->thisToken));
    NodeWrapper *n = new NodeWrapper(QString("this"), QString("Token"), QString("ThisExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(ThisExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(NullExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->nullToken));
    NodeWrapper *n = new NodeWrapper(QString("null"), QString("Token"), QString("NullExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(NullExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(TrueLiteral *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->trueToken));
    NodeWrapper *n = new NodeWrapper(QString("true"), QString("bool"), QString("TrueLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true;
}
void QmlVisitor::endVisit(TrueLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(FalseLiteral *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->falseToken));
    NodeWrapper *n = new NodeWrapper(QString("false"), QString("bool"), QString("FalseLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true;
}
void QmlVisitor::endVisit(FalseLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(StringLiteral *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->literalToken));
    NodeWrapper *n = new NodeWrapper(exp->value.toString(), QString("String"), QString("StringLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(StringLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(NumericLiteral *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->literalToken));
    NodeWrapper *n = new NodeWrapper(QString::number(exp->value), QString("Double"), QString("NumericLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(NumericLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(RegExpLiteral *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->literalToken));
    NodeWrapper *n = new NodeWrapper(exp->pattern.toString(), QString("String"), QString("RegExpLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(RegExpLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(ArrayLiteral *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->commaToken));
    tokens.append(toQStringRef(exp->lbracketToken));
    tokens.append(toQStringRef(exp->rbracketToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ArrayLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(ArrayLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(ObjectLiteral *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->lbraceToken));
    tokens.append(toQStringRef(exp->rbraceToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ObjectLiteral"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(ObjectLiteral *) { commonEndVisit(); }

bool QmlVisitor::visit(ElementList *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(ElementList *) { commonEndVisit(); }

bool QmlVisitor::visit(Elision *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(Elision *) { commonEndVisit(); }

bool QmlVisitor::visit(PropertyAssignmentList *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    const QString nodeType = QString("PropertyAssignmentList");
    NodeWrapper *n = new NodeWrapper(QString(), QString(), nodeType,
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        NodeWrapper *t = nodeStack.top();
        t->addChild(n);

        if (t->getNodeType().compare(nodeType) != 0) {
            pushStack(n);
        } else {
            dontPopAtEnd();
        }
    } else {
        pushStack(n);
    }
    return true; }
void QmlVisitor::endVisit(PropertyAssignmentList *) { commonEndVisit(); }

bool QmlVisitor::visit(PropertyGetterSetter *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->lbraceToken));
    tokens.append(toQStringRef(exp->rbraceToken));
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));
    tokens.append(toQStringRef(exp->getSetToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("PropertyGetterSetter"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(PropertyGetterSetter *) { commonEndVisit(); }
void QmlVisitor::endVisit(PropertyNameAndValue *) { commonEndVisit(); }

bool QmlVisitor::visit(NestedExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("NestedExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(NestedExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(IdentifierPropertyName *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->propertyNameToken));
    NodeWrapper *n = new NodeWrapper(exp->id.toString(), QString("String"), QString("IdentifierPropertyName"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(IdentifierPropertyName *) { commonEndVisit(); }

bool QmlVisitor::visit(StringLiteralPropertyName *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->propertyNameToken));
    NodeWrapper *n = new NodeWrapper(exp->id.toString(), QString("String"), QString("StringLiteralPropertyName"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(StringLiteralPropertyName *) { commonEndVisit(); }

bool QmlVisitor::visit(NumericLiteralPropertyName *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->propertyNameToken));
    NodeWrapper *n = new NodeWrapper(QString::number(exp->id), QString("Double"), QString("NumericLiteralPropertyName"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(NumericLiteralPropertyName *) { commonEndVisit(); }

bool QmlVisitor::visit(ArrayMemberExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->lbracketToken));
    tokens.append(toQStringRef(exp->rbracketToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("ArrayMemberExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(ArrayMemberExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(FieldMemberExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->dotToken));
    tokens.append(toQStringRef(exp->identifierToken));
    NodeWrapper *n = new NodeWrapper(exp->name.toString(), QString("String"), QString("FieldMemberExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(FieldMemberExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(NewMemberExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->newToken));
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("NewMemberExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(NewMemberExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(NewExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->newToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("NewExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(NewExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(CallExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("CallExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(CallExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(ArgumentList *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    const QString nodeType = QString("ArgumentList");
    NodeWrapper *n = new NodeWrapper(QString(), QString(), nodeType,
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        NodeWrapper *t = nodeStack.top();
        t->addChild(n);

        if (t->getNodeType().compare(nodeType) != 0) {
            pushStack(n);
        } else {
            dontPopAtEnd();
        }
    } else {
        pushStack(n);
    }
    return true; }
void QmlVisitor::endVisit(ArgumentList *) { commonEndVisit(); }

bool QmlVisitor::visit(PostIncrementExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->incrementToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("PostIncrementExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(PostIncrementExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(PostDecrementExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->decrementToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("PostDecrementExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(PostDecrementExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(DeleteExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->deleteToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("DeleteExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(DeleteExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(VoidExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->voidToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("VoidExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(VoidExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(TypeOfExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->typeofToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("TypeOfExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(TypeOfExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(PreIncrementExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->incrementToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("PreIncrementExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(PreIncrementExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(PreDecrementExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->decrementToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("PreDecrementExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(PreDecrementExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(UnaryPlusExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->plusToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("UnaryPlusExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if (!nodeStack.isEmpty()) {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(UnaryPlusExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(UnaryMinusExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->minusToken));
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("UnaryMinusExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    addWrapper(n);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(UnaryMinusExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(TildeExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;

    tokens.append(toQStringRef(exp->tildeToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("TildeExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(TildeExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(NotExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;

    tokens.append(toQStringRef(exp->notToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("NotExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(NotExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(BinaryExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->operatorToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("BinaryExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(BinaryExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(ConditionalExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->questionToken));
    tokens.append(toQStringRef(exp->colonToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("ConditionalExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(ConditionalExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(Block *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->lbraceToken));
    tokens.append(toQStringRef(exp->rbraceToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("Block"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);


    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(Block *) { commonEndVisit(); }

bool QmlVisitor::visit(StatementList *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(StatementList *) { commonEndVisit(); }

bool QmlVisitor::visit(VariableDeclarationList *exp) {
    debug(exp);
    // not done crap
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->commaToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("VariableDeclaration"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);


    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(VariableDeclarationList *) { commonEndVisit(); }

bool QmlVisitor::visit(VariableDeclaration *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->name.toString(),QString("String"), QString("VariableDeclaration"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);



    return true; }
void QmlVisitor::endVisit(VariableDeclaration *) { commonEndVisit(); }

bool QmlVisitor::visit(EmptyStatement *exp) {
    debug(exp);
    //ok
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->semicolonToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("EmptyStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(EmptyStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(ExpressionStatement *exp) {
    debug(exp);
    //ok
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->semicolonToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("ExpressionStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(ExpressionStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(IfStatement *exp) {
    debug(exp);
    //ok
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->ifToken));
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));
    tokens.append(toQStringRef(exp->elseToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("IfStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(IfStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(DoWhileStatement *exp) {
    debug(exp);
    //ok
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->whileToken));
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));
    tokens.append(toQStringRef(exp->semicolonToken));
    tokens.append(toQStringRef(exp->doToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("DoWhileStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(DoWhileStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(WhileStatement *exp) {
    debug(exp);
    //ok
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->whileToken));
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("WhileStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(WhileStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(ForStatement *exp) {
    debug(exp);
    //ok
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->forToken));
    tokens.append(toQStringRef(exp->firstSemicolonToken));
    tokens.append(toQStringRef(exp->secondSemicolonToken));
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("ForStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(ForStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(LocalForStatement *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->forToken));
    tokens.append(toQStringRef(exp->firstSemicolonToken));
    tokens.append(toQStringRef(exp->varToken));
    tokens.append(toQStringRef(exp->secondSemicolonToken));
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("LocalForStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(LocalForStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(ForEachStatement *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->forToken));
    tokens.append(toQStringRef(exp->inToken));
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("ForEachStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(ForEachStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(LocalForEachStatement *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->forToken));
    tokens.append(toQStringRef(exp->inToken));
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->varToken));
    tokens.append(toQStringRef(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("LocalForEachStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(LocalForEachStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(ContinueStatement *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->semicolonToken));
    tokens.append(toQStringRef(exp->continueToken));
    tokens.append(toQStringRef(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->label.toString(),QString("String"), QString("ContinueStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(ContinueStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(BreakStatement *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->semicolonToken));
    tokens.append(toQStringRef(exp->breakToken));
    tokens.append(toQStringRef(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->label.toString(),QString("String"), QString("BreakStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(BreakStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(ReturnStatement *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->semicolonToken));
    tokens.append(toQStringRef(exp->returnToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("ReturnStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(ReturnStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(WithStatement *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));
    tokens.append(toQStringRef(exp->withToken));


    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("WithStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(WithStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(SwitchStatement *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));
    tokens.append(toQStringRef(exp->switchToken));


    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("SwitchStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(SwitchStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(CaseBlock *exp) {
    debug(exp);
    //maybe remove and add all children to SwitchStatement instead
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->lbraceToken));
    tokens.append(toQStringRef(exp->rbraceToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("CaseBlock"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(CaseBlock *) { commonEndVisit(); }

bool QmlVisitor::visit(CaseClauses *exp) {
    debug(exp);
    //Holder for lists of CaseClause
    QList<QStringRef> tokens;

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("CaseClauses"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(CaseClauses *) { commonEndVisit(); }

bool QmlVisitor::visit(CaseClause *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->colonToken));
    tokens.append(toQStringRef(exp->caseToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("CaseClause"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(CaseClause *) { commonEndVisit(); }

bool QmlVisitor::visit(DefaultClause *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->colonToken));
    tokens.append(toQStringRef(exp->defaultToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("DefaultClause"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(DefaultClause *) { commonEndVisit(); }

bool QmlVisitor::visit(LabelledStatement *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->colonToken));
    tokens.append(toQStringRef(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->label.toString(),QString("String"), QString("LabelledStatement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(LabelledStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(ThrowStatement *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->semicolonToken));
    tokens.append(toQStringRef(exp->throwToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("Throw"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(ThrowStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(TryStatement *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->tryToken));

    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("Try"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    return true; }
void QmlVisitor::endVisit(TryStatement *) { commonEndVisit(); }

bool QmlVisitor::visit(Catch *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->catchToken));
    tokens.append(toQStringRef(exp->identifierToken));
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rparenToken));

    NodeWrapper *n = new NodeWrapper(exp->name.toString(),QString("String"), QString("Catch"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(Catch *) { commonEndVisit(); }

bool QmlVisitor::visit(Finally *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->finallyToken));
    NodeWrapper *n = new NodeWrapper(QString(),QString(), QString("Finally"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);
    return true; }
void QmlVisitor::endVisit(Finally *) { commonEndVisit(); }

bool QmlVisitor::visit(FunctionDeclaration *exp) {
    debug(exp);
    // should be empty, removed from wrapped-AST.
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(FunctionDeclaration *) { commonEndVisit(); }

bool QmlVisitor::visit(FunctionExpression *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->functionToken));
    tokens.append(toQStringRef(exp->identifierToken));
    tokens.append(toQStringRef(exp->lbraceToken));
    tokens.append(toQStringRef(exp->rparenToken));
    tokens.append(toQStringRef(exp->lparenToken));
    tokens.append(toQStringRef(exp->rbraceToken));

    NodeWrapper *n = new NodeWrapper(exp->name.toString(),QString("String") , QString("FunctionExpression"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(FunctionExpression *) { commonEndVisit(); }

bool QmlVisitor::visit(FormalParameterList *exp) {
    debug(exp);
    // should add children to parent.
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->commaToken));
    tokens.append(toQStringRef(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->name.toString(), QString("String"), QString("FormalParameterList"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    //pushStack(n);
    dontPopAtEnd();

    return true; }
void QmlVisitor::endVisit(FormalParameterList *) { commonEndVisit(); }

bool QmlVisitor::visit(Program *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("Program"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(Program *) { commonEndVisit(); }

bool QmlVisitor::visit(SourceElements *exp) {
    debug(exp);

    QList<QStringRef> tokens;
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("SourceElements"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(SourceElements *) { commonEndVisit(); }

bool QmlVisitor::visit(FunctionSourceElement *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("FunctionSourceElement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);

    return true; }
void QmlVisitor::endVisit(FunctionSourceElement *) { commonEndVisit(); }

bool QmlVisitor::visit(StatementSourceElement *exp) {
    debug(exp);
    QList<QStringRef> tokens;
    NodeWrapper *n = new NodeWrapper(QString(), QString(), QString("StatementSourceElement"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    if(!nodeStack.empty())
    {
        nodeStack.top()->addChild(n);
    }
    pushStack(n);


    /*
    QList<QStringRef> tokens;
    tokens.append(toQStringRef(exp->identifierToken));

    NodeWrapper *n = new NodeWrapper(exp->name, QStringRef("String"), QStringRef("QualifiedId"),
                                     exp->firstSourceLocation().startLine,
                                     exp->firstSourceLocation().startColumn,
                                     getSource(exp), tokens);
    nodeStack.last()->addChild(n);
    pushStack(n);
    */

    return true; }
void QmlVisitor::endVisit(StatementSourceElement *) { commonEndVisit(); }

bool QmlVisitor::visit(DebuggerStatement *exp) {
    debug(exp);
    dontPopAtEnd();
    return true; }
void QmlVisitor::endVisit(DebuggerStatement *) { commonEndVisit(); }

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

const QStringRef QmlVisitor::printable(const SourceLocation &start, const SourceLocation &end) {
    return QStringRef(&_code, start.offset, end.offset + end.length - start.offset);
}

const QStringRef QmlVisitor::getSource(const QQmlJS::AST::Node *exp) {
    return printable(exp->firstSourceLocation(), exp->lastSourceLocation());
}

NodeWrapper* QmlVisitor::getWrappedRoot() {
    return rootNode;
}

void QmlVisitor::endVisit(Expression *) { commonEndVisit(); }

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
