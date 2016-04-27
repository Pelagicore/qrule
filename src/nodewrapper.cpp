// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0

#include "nodewrapper.h"
#include <QDebug>

NodeWrapper::NodeWrapper(const NodeWrapper *other):
    row(other->row),
    col(other->col),
    value(other->value),
    valueType(other->valueType),
    nodeType(other->nodeType),
    source(other->source),
    fileName(other->fileName),
    tokenMap(other->tokenMap) {
    foreach(NodeWrapper* child, other->children) {
        addChild(new NodeWrapper(child));
    }
}

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
const QFileInfo NodeWrapper::getFileName(){
    return fileName;
}

const QList<NodeWrapper *>& NodeWrapper::getChildren() {
    return children;
}

const QMap<QString, QString>& NodeWrapper::getTokenMap() {
    return tokenMap;
}

void NodeWrapper::print() {
    innerPrint(0);
}

void NodeWrapper::innerPrint(const int indent) {
    QString indentStr("    ");
    indentStr = indentStr.repeated(indent);

    qDebug() << indentStr<< nodeType  << value;
    foreach(NodeWrapper* n, children) {    QString outPut = "";
        n->innerPrint(indent + 1);
    }
}

QString NodeWrapper::getOutput(){

        QString name = getId();
        QString output;

        if (!children.isEmpty()) {
        QString bind = QString(name).append(" -> {");
        foreach(NodeWrapper* child, children) {
            QString childName = child->getId();
            bind = bind.append(childName).append(" ");
            output = output.append(child->getOutput());
        }
        bind.chop(1);
        bind = bind.append("};\n");
        output = output.append(bind);
        }
        return output;
}

const QList<NodeWrapper*> NodeWrapper::getNodes(QString comparisonNodeType) {
    QStringList list = comparisonNodeType.split('.');
    QList<NodeWrapper*> nodes = QList<NodeWrapper*>();
    innerGetNodes(list, list, nodes);
    return nodes;
}

void NodeWrapper::innerGetNodes(QStringList searchList, const QStringList& originalList, QList<NodeWrapper*>& nodes) {
    QString str = searchList.takeFirst();
    if (nodeType != str) {
        searchList = originalList;
    } else if (searchList.isEmpty()) {
        nodes.append(this);
        searchList = originalList;
    }
    foreach(NodeWrapper* child, children) {
        child->innerGetNodes(searchList, originalList, nodes);

    }
}

const QString NodeWrapper::getId() {
    QString name = QString().append(nodeType)
                            .append("_v").append(QString(value).replace(".", "_").replace(" ", "_"))
                            .append("_r").append(QString::number(row))
                            .append("_c").append(QString::number(col));
    return name;
}

bool NodeWrapper::hasToken(const QString &key) {
    return !tokenMap.value(key).isEmpty();
}

QString NodeWrapper::getToken(const QString &key) {
    return tokenMap.value(key);
}

bool NodeWrapper::dropNode(NodeWrapper* node) {
    if (!children.isEmpty()) {
       foreach(NodeWrapper* child, children) {
           if (*child == *node) {
               delete child;
               children.removeOne(child);
               return true;
           } else if (child->dropNode(node)) {
               return true;
           }
       }
       return false;
    } else {
        return false;
    }
}

inline bool NodeWrapper::operator==(NodeWrapper &other) {
    return getId() == other.getId();
}

inline bool NodeWrapper::operator!=(NodeWrapper &other) {
    return !(this->operator==(other));
}

void NodeWrapper::merge(const NodeWrapper &other) {
    foreach(NodeWrapper* ochild, other.children) {
        bool add = true;
        foreach(NodeWrapper* child, children) {
            if (ochild->getValue() == child->getValue() &&
                ochild->getNodeType() == child->getNodeType()) {
                if (ochild->getNodeType() == "ScriptBinding") {
                    add = false;
                }

            }
        }
        if (add) {
            addChild(new NodeWrapper(ochild));
        }
    }
}
