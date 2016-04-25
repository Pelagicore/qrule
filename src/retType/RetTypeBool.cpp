// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#include "retType/RetTypeBool.h"

bool RetTypeBool::getData() {
    return data;
}

RetType::RetTypeE RetTypeBool::getType() {
    return RetType::RetTypeE::RBool;
}
