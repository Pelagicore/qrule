#include "QmlVisitor.h"


void QmlVisitor::endVisit(UiObjectDefinition*) {
    env->exitCurrentScope();
    deIndent();
}
bool QmlVisitor::visit(UiObjectDefinition *exp) {
    debug(exp);
    QString newScopeName = getSource(exp->qualifiedTypeNameId).toString();
    env->enterNewScope(newScopeName, filename,
                       exp->firstSourceLocation().startLine,
                       exp->firstSourceLocation().startColumn,
                       getSource(exp).toString());
    return true; }

bool QmlVisitor::visit(IdentifierExpression *exp) {
    debug(exp);
    notPairedParamValue = getSource(exp).toString();

    return true; }

bool QmlVisitor::visit(UiScriptBinding *exp)  {
    debug(exp);
    notPairedParamName = getSource(exp->qualifiedId).toString();
    return true;
}

void QmlVisitor::endVisit(UiScriptBinding*) {
    env->addParam(notPairedParamName, notPairedParamValue);
    notPairedParamName  = "";
    notPairedParamValue = "";
    deIndent();
}

void QmlVisitor::deIndent() {
    indent.chop(2);
}

void QmlVisitor::expandIndent() {
    indent.append("  ");
}

void QmlVisitor::debug(const QQmlJS::AST::Node *exp) {
/*
    QString name = QString(typeid(*exp).name());
    name = name.remove(QRegExp(".*AST[0-9]*"));
    qDebug() << indent << name
             << getSource(exp);
    expandIndent();
*/
}

const QStringRef QmlVisitor::printable(const SourceLocation &start, const SourceLocation &end) {
    return QStringRef(&_code, start.offset, end.offset + end.length - start.offset);
}

const QStringRef QmlVisitor::getSource(const QQmlJS::AST::Node *exp) {
    return printable(exp->firstSourceLocation(), exp->lastSourceLocation());
}

bool QmlVisitor::visit(TrueLiteral *exp) {
    debug(exp);
    notPairedParamValue = "true";
    return true;
}

bool QmlVisitor::visit(FalseLiteral *exp) {
    debug(exp);
    notPairedParamValue = "false";
    return true;
}
