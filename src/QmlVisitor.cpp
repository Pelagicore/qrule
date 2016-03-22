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

bool QmlVisitor::visit(TrueLiteral *exp) {
    debug(exp);
    return true;
}

bool QmlVisitor::visit(FalseLiteral *exp) {
    debug(exp);
    return true;
}
