#ifndef KRULEENGINE_RETTYPE_H
#define KRULEENGINE_RETTYPE_H

#include <QObject>


class RetType: public QObject {
public:
    enum RetTypeE {RInt, RString, RBool};
    virtual RetTypeE getType() = 0;
};

#endif // KRULEENGINE_RETTYPE_H
