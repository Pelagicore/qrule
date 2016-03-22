#include "QMLChildren.h"

using namespace QQmlJS::AST;

QList<Node*> children(Node *n) {
    switch(n->kind) {
        case Node::Kind_UiProgram: return children((UiProgram*)n);
        case Node::Kind_UiHeaderItemList: return children((UiHeaderItemList*)n);
        case Node::Kind_UiPragma: return children((UiPragma*)n);
        case Node::Kind_UiImport: return children((UiImport*)n);
        case Node::Kind_UiPublicMember: return children((UiPublicMember*)n);
        case Node::Kind_UiSourceElement: return children((UiSourceElement*)n);
        case Node::Kind_UiObjectDefinition: return children((UiObjectDefinition*)n);
        case Node::Kind_UiObjectInitializer: return children((UiObjectInitializer*)n);
        case Node::Kind_UiObjectBinding: return children((UiObjectBinding*)n);
        case Node::Kind_UiScriptBinding: return children((UiScriptBinding*)n);
        case Node::Kind_UiArrayBinding: return children((UiArrayBinding*)n);
        case Node::Kind_UiParameterList: return children((UiParameterList*)n);
        case Node::Kind_UiObjectMemberList: return children((UiObjectMemberList*)n);
        case Node::Kind_UiArrayMemberList: return children((UiArrayMemberList*)n);
        case Node::Kind_UiQualifiedId: return children((UiQualifiedId*)n);
        case Node::Kind_UiQualifiedPragmaId: return children((UiQualifiedPragmaId*)n);
        case Node::Kind_ThisExpression: return children((ThisExpression*)n);
        case Node::Kind_IdentifierExpression: return children((IdentifierExpression*)n);
        case Node::Kind_NullExpression: return children((NullExpression*)n);
        case Node::Kind_TrueLiteral: return children((TrueLiteral*)n);
        case Node::Kind_FalseLiteral: return children((FalseLiteral*)n);
        case Node::Kind_StringLiteral: return children((StringLiteral*)n);
        case Node::Kind_NumericLiteral: return children((NumericLiteral*)n);
        case Node::Kind_RegExpLiteral: return children((RegExpLiteral*)n);
        case Node::Kind_ArrayLiteral: return children((ArrayLiteral*)n);
        case Node::Kind_ObjectLiteral: return children((ObjectLiteral*)n);
        case Node::Kind_ElementList: return children((ElementList*)n);
        case Node::Kind_Elision: return children((Elision*)n);
        case Node::Kind_PropertyAssignmentList: return children((PropertyAssignmentList*)n);
        case Node::Kind_PropertyNameAndValue: return children((PropertyNameAndValue*)n);
        case Node::Kind_PropertyGetterSetter: return children((PropertyGetterSetter*)n);
        case Node::Kind_NestedExpression: return children((NestedExpression*)n);
        case Node::Kind_IdentifierPropertyName: return children((IdentifierPropertyName*)n);
        case Node::Kind_StringLiteralPropertyName: return children((StringLiteralPropertyName*)n);
        case Node::Kind_NumericLiteralPropertyName: return children((NumericLiteralPropertyName*)n);
        case Node::Kind_ArrayMemberExpression: return children((ArrayMemberExpression*)n);
        case Node::Kind_FieldMemberExpression: return children((FieldMemberExpression*)n);
        case Node::Kind_NewMemberExpression: return children((NewMemberExpression*)n);
        case Node::Kind_NewExpression: return children((NewExpression*)n);
        case Node::Kind_CallExpression: return children((CallExpression*)n);
        case Node::Kind_ArgumentList: return children((ArgumentList*)n);
        case Node::Kind_PostIncrementExpression: return children((PostIncrementExpression*)n);
        case Node::Kind_PostDecrementExpression: return children((PostDecrementExpression*)n);
        case Node::Kind_DeleteExpression: return children((DeleteExpression*)n);
        case Node::Kind_VoidExpression: return children((VoidExpression*)n);
        case Node::Kind_TypeOfExpression: return children((TypeOfExpression*)n);
        case Node::Kind_PreIncrementExpression: return children((PreIncrementExpression*)n);
        case Node::Kind_PreDecrementExpression: return children((PreDecrementExpression*)n);
        case Node::Kind_UnaryPlusExpression: return children((UnaryPlusExpression*)n);
        case Node::Kind_UnaryMinusExpression: return children((UnaryMinusExpression*)n);
        case Node::Kind_TildeExpression: return children((TildeExpression*)n);
        case Node::Kind_NotExpression: return children((NotExpression*)n);
        case Node::Kind_BinaryExpression: return children((BinaryExpression*)n);
        case Node::Kind_ConditionalExpression: return children((ConditionalExpression*)n);
        case Node::Kind_Expression: return children((Expression*)n);
        case Node::Kind_Block: return children((Block*)n);
        case Node::Kind_StatementList: return children((StatementList*)n);
        case Node::Kind_VariableDeclarationList: return children((VariableDeclarationList*)n);
        case Node::Kind_VariableDeclaration: return children((VariableDeclaration*)n);
        case Node::Kind_EmptyStatement: return children((EmptyStatement*)n);
        case Node::Kind_ExpressionStatement: return children((ExpressionStatement*)n);
        case Node::Kind_IfStatement: return children((IfStatement*)n);
        case Node::Kind_DoWhileStatement: return children((DoWhileStatement*)n);
        case Node::Kind_WhileStatement: return children((WhileStatement*)n);
        case Node::Kind_ForStatement: return children((ForStatement*)n);
        case Node::Kind_LocalForStatement: return children((LocalForStatement*)n);
        case Node::Kind_ForEachStatement: return children((ForEachStatement*)n);
        case Node::Kind_LocalForEachStatement: return children((LocalForEachStatement*)n);
        case Node::Kind_ContinueStatement: return children((ContinueStatement*)n);
        case Node::Kind_BreakStatement: return children((BreakStatement*)n);
        case Node::Kind_ReturnStatement: return children((ReturnStatement*)n);
        case Node::Kind_WithStatement: return children((WithStatement*)n);
        case Node::Kind_SwitchStatement: return children((SwitchStatement*)n);
        case Node::Kind_CaseBlock: return children((CaseBlock*)n);
        case Node::Kind_CaseClauses: return children((CaseClauses*)n);
        case Node::Kind_CaseClause: return children((CaseClause*)n);
        case Node::Kind_DefaultClause: return children((DefaultClause*)n);
        case Node::Kind_LabelledStatement: return children((LabelledStatement*)n);
        case Node::Kind_ThrowStatement: return children((ThrowStatement*)n);
        case Node::Kind_TryStatement: return children((TryStatement*)n);
        case Node::Kind_Catch: return children((Catch*)n);
        case Node::Kind_Finally: return children((Finally*)n);
        case Node::Kind_FunctionDeclaration: return children((FunctionDeclaration*)n);
        case Node::Kind_FunctionExpression: return children((FunctionExpression*)n);
        case Node::Kind_FormalParameterList: return children((FormalParameterList*)n);
        case Node::Kind_FunctionBody: return children((FunctionBody*)n);
        case Node::Kind_Program: return children((Program*)n);
        case Node::Kind_SourceElements: return children((SourceElements*)n);
        case Node::Kind_FunctionSourceElement: return children((FunctionSourceElement*)n);
        case Node::Kind_StatementSourceElement: return children((StatementSourceElement*)n);
        case Node::Kind_DebuggerStatement: return children((DebuggerStatement*)n);
    }

    return QList<Node*>();
}

QList<Node*> children(UiProgram *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->headers);
    ls.append(exp->members);
    return ls;
}
QList<Node*> children(UiHeaderItemList *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->headerItem);
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}
QList<Node*> children(UiPragma *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->pragmaType);
    return ls;
}
QList<Node*> children(UiImport *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->importUri);
    return ls;
}
QList<Node*> children(UiPublicMember *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->binding);
    ls.append(exp->parameters);
    ls.append(exp->statement);
    return ls;
}
QList<Node*> children(UiSourceElement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->sourceElement);
    return ls;
}
QList<Node*> children(UiObjectDefinition *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->initializer);
    ls.append(exp->qualifiedTypeNameId);
    return ls;
}
QList<Node*> children(UiObjectInitializer *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->members);
    return ls;
}
QList<Node*> children(UiObjectBinding *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->initializer);
    ls.append(exp->qualifiedId);
    ls.append(exp->qualifiedTypeNameId);
    return ls;
}
QList<Node*> children(UiScriptBinding *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->qualifiedId);
    return ls;
}
QList<Node*> children(UiArrayBinding *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->qualifiedId);
    ls.append(exp->members);
    return ls;
}
QList<Node*> children(UiParameterList *exp) {
    QList<Node*> ls = QList<Node*>();
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}
QList<Node*> children(UiObjectMemberList *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->member);
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}
QList<Node*> children(UiArrayMemberList *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->member);
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}
QList<Node*> children(UiQualifiedId *exp) {
    QList<Node*> ls = QList<Node*>();
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}
QList<Node*> children(UiQualifiedPragmaId *exp) {
    QList<Node*> ls = QList<Node*>();
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}

QList<Node*> children(ThisExpression *) {
    return QList<Node*>();
}

QList<Node*> children(IdentifierExpression *) {
    return QList<Node*>();
}

QList<Node*> children(NullExpression *) {
    return QList<Node*>();
}

QList<Node*> children(TrueLiteral *) {
    return QList<Node*>();
}

QList<Node*> children(FalseLiteral *) {
    return QList<Node*>();
}

QList<Node*> children(StringLiteral *) {
    return QList<Node*>();
}

QList<Node*> children(NumericLiteral *) {
    return QList<Node*>();
}

QList<Node*> children(RegExpLiteral *) {
    return QList<Node*>();
}

QList<Node*> children(ArrayLiteral *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->elements);
    ls.append(exp->elision);
    return ls;
}

QList<Node*> children(ObjectLiteral *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->properties);
    return ls;
}

QList<Node*> children(ElementList *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->elision);
    ls.append(exp->expression);
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}

QList<Node*> children(Elision *exp) {
    QList<Node*> ls = QList<Node*>();
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}

QList<Node*> children(PropertyAssignmentList *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->assignment);
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}

QList<Node*> children(PropertyNameAndValue *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->name);
    ls.append(exp->value);
    return ls;
}

QList<Node*> children(PropertyGetterSetter *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->name);
    ls.append(exp->formals);
    ls.append(exp->functionBody);
    return ls;
}

QList<Node*> children(NestedExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(IdentifierPropertyName *) {
    return QList<Node*>();
}

QList<Node*> children(StringLiteralPropertyName *) {
    return QList<Node*>();
}

QList<Node*> children(NumericLiteralPropertyName *) {
    return QList<Node*>();
}

QList<Node*> children(ArrayMemberExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->base);
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(FieldMemberExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->base);
    return ls;
}

QList<Node*> children(NewMemberExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->arguments);
    ls.append(exp->base);
    return ls;
}

QList<Node*> children(NewExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(CallExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->arguments);
    ls.append(exp->base);
    return ls;
}

QList<Node*> children(ArgumentList *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}

QList<Node*> children(PostIncrementExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->base);
    return ls;
}

QList<Node*> children(PostDecrementExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->base);
    return ls;
}

QList<Node*> children(DeleteExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(VoidExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(TypeOfExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(PreIncrementExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(PreDecrementExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(UnaryPlusExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(UnaryMinusExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(TildeExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(NotExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(BinaryExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->left);
    ls.append(exp->right);
    return ls;
}

QList<Node*> children(ConditionalExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    ls.append(exp->ok);
    ls.append(exp->ko);
    return ls;
}

QList<Node*> children(Expression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->left);
    ls.append(exp->right);
    return ls;
}

QList<Node*> children(Block *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->statements);
    return ls;
}

QList<Node*> children(StatementList *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->statement);
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}

QList<Node*> children(VariableStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->declarations);
    return ls;
}

QList<Node*> children(VariableDeclarationList *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->declaration);
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}

QList<Node*> children(VariableDeclaration *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(EmptyStatement *) {
    return QList<Node*>();
}

QList<Node*> children(ExpressionStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(IfStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    ls.append(exp->ok);
    ls.append(exp->ko);
    return ls;
}

QList<Node*> children(DoWhileStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    ls.append(exp->statement);
    return ls;
}

QList<Node*> children(WhileStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    ls.append(exp->statement);
    return ls;
}

QList<Node*> children(ForStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->initialiser);
    ls.append(exp->condition);
    ls.append(exp->expression);
    ls.append(exp->statement);
    return ls;
}

QList<Node*> children(LocalForStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->declarations);
    ls.append(exp->condition);
    ls.append(exp->expression);
    ls.append(exp->statement);
    return ls;
}

QList<Node*> children(ForEachStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->initialiser);
    ls.append(exp->expression);
    ls.append(exp->statement);
    return ls;
}

QList<Node*> children(LocalForEachStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->declaration);
    ls.append(exp->expression);
    ls.append(exp->statement);
    return ls;
}

QList<Node*> children(ContinueStatement *) {
    return QList<Node*>();
}

QList<Node*> children(BreakStatement *) {
    return QList<Node*>();
}

QList<Node*> children(ReturnStatement *) {
    return QList<Node*>();
}

QList<Node*> children(WithStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    ls.append(exp->statement);
    return ls;
}

QList<Node*> children(SwitchStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    ls.append(exp->block);
    return ls;
}

QList<Node*> children(CaseBlock *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->clauses);
    ls.append(exp->defaultClause);
    ls.append(exp->moreClauses);
    return ls;
}

QList<Node*> children(CaseClauses *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->clause);
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}

QList<Node*> children(CaseClause *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    ls.append(exp->statements);
    return ls;
}

QList<Node*> children(DefaultClause *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->statements);
    return ls;
}

QList<Node*> children(LabelledStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->statement);
    return ls;
}

QList<Node*> children(ThrowStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->expression);
    return ls;
}

QList<Node*> children(TryStatement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->statement);
    ls.append(exp->catchExpression);
    ls.append(exp->finallyExpression);
    return ls;
}

QList<Node*> children(Catch *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->statement);
    return ls;
}

QList<Node*> children(Finally *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->statement);
    return ls;
}

QList<Node*> children(FunctionDeclaration *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->formals);
    ls.append(exp->body);
    return ls;
}

QList<Node*> children(FunctionExpression *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->formals);
    ls.append(exp->body);
    return ls;
}

QList<Node*> children(FormalParameterList *exp) {
    QList<Node*> ls = QList<Node*>();
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}

QList<Node*> children(FunctionBody *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->elements);
    return ls;
}

QList<Node*> children(Program *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->elements);
    return ls;
}

QList<Node*> children(SourceElements *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->element);
    if (exp->next != nullptr) {
        ls.append(exp->next);
    }
    return ls;
}

QList<Node*> children(FunctionSourceElement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->declaration);
    return ls;
}

QList<Node*> children(StatementSourceElement *exp) {
    QList<Node*> ls = QList<Node*>();
    ls.append(exp->statement);
    return ls;
}

QList<Node*> children(DebuggerStatement *) {
    return QList<Node*>();
}
