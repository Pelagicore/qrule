#include "nodewrapper.h"
#include <QDebug>

NodeWrapper::~NodeWrapper() {
    foreach(const NodeWrapper* n, children) {
        delete n;
    }
}

void NodeWrapper::addChild(NodeWrapper *node) {
    children.append(node);
}

const QStringRef NodeWrapper::getSource() {
    return source;
}

const QString NodeWrapper::getValue() {
    return value;
}

const QString NodeWrapper::getValueType() {
    return valueType;
}

const QString NodeWrapper::getNodeType() {
    return nodeType;
}

const quint32 NodeWrapper::getRow() {
    return row;
}

const quint32 NodeWrapper::getCol() {
    return col;
}

const QList<NodeWrapper *>& NodeWrapper::getChildren() {
    return children;
}

const QMap<QString, bool>& NodeWrapper::getTokenMap() {
    return tokenMap;
}

void NodeWrapper::print() {
    innerPrint(0);
}

void NodeWrapper::innerPrint(const int indent) {
    QString indentStr("    ");
    indentStr = indentStr.repeated(indent);

    qDebug() << indentStr<< nodeType  << value;
    foreach(NodeWrapper* n, children) {
        n->innerPrint(indent + 1);
    }
}

const QList<NodeWrapper*> NodeWrapper::getNodes(const QString &comparisonNodeType) {
    QList<NodeWrapper*> nodes = QList<NodeWrapper*>();
    innerGetNodes(comparisonNodeType, nodes);
    return nodes;
}

void NodeWrapper::innerGetNodes(const QString &comparisonNodeType, QList<NodeWrapper*> &nodes) {
    foreach(NodeWrapper* child, children) {
        child->innerGetNodes(comparisonNodeType, nodes);
    }
    if (nodeType == comparisonNodeType) {
        nodes.append(this);
    }
}
