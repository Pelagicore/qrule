#ifndef KRULEENGINE_RETTYPEBOOL_H
#define KRULEENGINE_RETTYPEBOOL_H

#include "retType/RetType.h"

class RetTypeBool: public RetType {
public:
    RetTypeBool(bool data): data(data) {}
    ~RetTypeBool() {}

    RetTypeE getType();
    bool getData();
private:
    bool data;
};

#endif // KRULEENGINE_RETTYPEBOOL_H
