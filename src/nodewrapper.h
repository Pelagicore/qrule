#ifndef NODEWRAPPER_H
#define NODEWRAPPER_H

#include <QList>



class NodeWrapper {
public:
    NodeWrapper(const QStringRef value, const QStringRef valueType, const QStringRef nodeType,
                quint32 row, quint32 col, const QStringRef source, const QList<QStringRef> tokens):
        value(value), valueType(valueType), nodeType(nodeType), row(row), col(col),
        source(source), tokens(tokens) {}

    ~NodeWrapper();

    void addChild(NodeWrapper *node);
    const QStringRef getValue();
    const QStringRef getValueType();
    const QStringRef getNodeType();
    const QStringRef getSource();
    const quint32 getRow();
    const quint32 getCol();
    const QList<NodeWrapper *>& getChildren();
    const QList<QStringRef>& getTokens();

private:
    QList<NodeWrapper *> children;
    const QList<QStringRef> tokens;
    const QStringRef value;
    const QStringRef valueType;
    const QStringRef nodeType;
    const quint32 row;
    const quint32 col;
    const QStringRef source;
};

#endif // NODEWRAPPER_H
