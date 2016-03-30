#include "nodewrapper.h"

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

const QList<QStringRef>& NodeWrapper::getTokens() {
    return tokens;
}
