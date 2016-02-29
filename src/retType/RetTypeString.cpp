#include "retType/RetTypeString.h"

QString RetTypeString::getData() {
    return data;
}

RetType::RetTypeE RetTypeString::getType() {
    return RetType::RetTypeE::RString;
}
