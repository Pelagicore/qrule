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

const QList<NodeWrapper*> NodeWrapper::getNodes(QString comparisonNodeType) {
    QStringList list = comparisonNodeType.split('.');
    QList<NodeWrapper*> nodes = QList<NodeWrapper*>();
    innerGetNodes(list, list, nodes);
    return nodes;
}

void NodeWrapper::innerGetNodes(QStringList searchList, const QStringList& originalList, QList<NodeWrapper*>& nodes) {
    QString str = searchList.takeFirst();
    if (nodeType == str) {
        nodes.append(this);
    }
    if (searchList.isEmpty()) {
        searchList = originalList;
    }
    foreach(NodeWrapper* child, children) {
        child->innerGetNodes(searchList, originalList, nodes);
    }
}
