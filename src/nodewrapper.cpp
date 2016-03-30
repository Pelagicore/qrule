#include "nodewrapper.h"

NodeWrapper::~NodeWrapper() {
    foreach(const NodeWrapper* n, children) {
        delete n;
    }
}

void NodeWrapper::addChild(const NodeWrapper *node) {
    children.append(node);
}

const QStringRef NodeWrapper::getSource() {
    return source;
}

const QStringRef NodeWrapper::getValue() {
    return value;
}

const QStringRef NodeWrapper::getValueType() {
    return valueType;
}

const QStringRef NodeWrapper::getNodeType() {
    return nodeType;
}

const quint32 NodeWrapper::getRow() {
    return row;
}

const quint32 NodeWrapper::getCol() {
    return col;
}

const QList<const NodeWrapper *>& NodeWrapper::getChildren() {
    return children;
}

const QList<QStringRef>& NodeWrapper::getTokens() {
    return tokens;
}
