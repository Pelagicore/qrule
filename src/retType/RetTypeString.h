#ifndef KRULEENGINE_RETTYPESTRING_H
#define KRULEENGINE_RETTYPESTRING_H

#include "retType/RetType.h"
#include <QString>

class RetTypeString: public RetType {
public:
    RetTypeString(QString data): data(data) {}
    ~RetTypeString() {}

    RetTypeE getType();
    QString getData();
private:
    QString data;
};

#endif // KRULEENGINE_RETTYPESTRING_H
