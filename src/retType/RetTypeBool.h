// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
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
