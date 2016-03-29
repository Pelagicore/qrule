#ifndef NODEWRAPPER_H
#define NODEWRAPPER_H

#include <QList>



class NodeWrapper {
public:
    NodeWrapper(QString value, QString type, quint32 row, quint32 col, QString context):
        value(value), type(type), row(row), col(col), context(context) {}

    void addChild(const NodeWrapper &node);
    void flushLabels();

private:
    QList<const NodeWrapper &> children;
    QString value;
    QString type;
    quint32 row;
    quint32 col;
    QString context;
};

#endif // NODEWRAPPER_H
