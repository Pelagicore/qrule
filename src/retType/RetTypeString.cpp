// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#include "retType/RetTypeString.h"

QString RetTypeString::getData() {
    return data;
}

RetType::RetTypeE RetTypeString::getType() {
    return RetType::RetTypeE::RString;
}
