#include "QmlVisitor.h"


void QmlVisitor::endVisit(UiObjectDefinition*) {
    deIndent();
}
bool QmlVisitor::visit(UiObjectDefinition *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(IdentifierExpression *exp) {
    debug(exp);

    return true; }

bool QmlVisitor::visit(UiScriptBinding *exp)  {
    debug(exp);
    return true;
}

void QmlVisitor::endVisit(UiScriptBinding*) {
    deIndent();
}

void QmlVisitor::deIndent() {
    indent.chop(4);
}

void QmlVisitor::expandIndent() {
    indent.append("    ");
}

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

    nodeStack.push(n);
    return true;
}

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

    nodeStack.push(n);
    return true; }

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
    nodeStack.push(n);
    return true; }

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
    nodeStack.push(n);
    return true; }

bool QmlVisitor::visit(UiObjectMember *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(UiQualifiedPragmaId *exp) {
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
    nodeStack.push(n);
    return true; }

bool QmlVisitor::visit(UiSourceElement *exp) {
    debug(exp);
    return true; }

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
    nodeStack.push(n);
    return true; }

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
    nodeStack.push(n);
    return true; }

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
            nodeStack.push(n);
        }
    } else {
        nodeStack.push(n);
    }
    return true; }

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
    nodeStack.push(n);
    return true; }

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
    nodeStack.push(n);
    return true; }

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
    nodeStack.push(n);
    return true; }

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
    return true; }

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
            nodeStack.push(n);
        }
    } else {
        nodeStack.push(n);
    }
    return true; }

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
            nodeStack.push(n);
        }
    } else {
        nodeStack.push(n);
    }
    return true; }

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
    nodeStack.push(n);

    return true; }

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
    nodeStack.push(n);

    return true; }

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
    nodeStack.push(n);

    return true; }

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
    nodeStack.push(n);
    return true;
}

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
    nodeStack.push(n);
    return true;
}

bool QmlVisitor::visit(StringLiteral *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(NumericLiteral *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(RegExpLiteral *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ArrayLiteral *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ObjectLiteral *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ElementList *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(Elision *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(PropertyAssignmentList *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(PropertyGetterSetter *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(NestedExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(IdentifierPropertyName *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(StringLiteralPropertyName *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(NumericLiteralPropertyName *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ArrayMemberExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(FieldMemberExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(NewMemberExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(NewExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(CallExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ArgumentList *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(PostIncrementExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(PostDecrementExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(DeleteExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(VoidExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(TypeOfExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(PreIncrementExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(PreDecrementExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(UnaryPlusExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(UnaryMinusExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(TildeExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(NotExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(BinaryExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ConditionalExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(Block *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(StatementList *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(VariableDeclarationList *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(VariableDeclaration *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(EmptyStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ExpressionStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(IfStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(DoWhileStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(WhileStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ForStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(LocalForStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ForEachStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(LocalForEachStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ContinueStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(BreakStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ReturnStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(WithStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(SwitchStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(CaseBlock *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(CaseClauses *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(CaseClause *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(DefaultClause *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(LabelledStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(ThrowStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(TryStatement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(Catch *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(Finally *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(FunctionDeclaration *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(FunctionExpression *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(FormalParameterList *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(Program *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(SourceElements *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(FunctionSourceElement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(StatementSourceElement *exp) {
    debug(exp);
    return true; }

bool QmlVisitor::visit(DebuggerStatement *exp) {
    debug(exp);
    return true; }

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

void QmlVisitor::allEnd() {
    deIndent();
    if (nodeStack.length() > 1) {
        nodeStack.pop();
    }
}
