#include "retType/RetTypeUInt.h"

quint32 RetTypeUInt::getData() {
    return data;
}

RetType::RetTypeE RetTypeUInt::getType() {
    return RetType::RetTypeE::RInt;
}
