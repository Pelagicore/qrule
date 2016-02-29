#include "retType/RetTypeBool.h"

bool RetTypeBool::getData() {
    return data;
}

RetType::RetTypeE RetTypeBool::getType() {
    return RetType::RetTypeE::RBool;
}
