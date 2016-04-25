// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
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
