// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#ifndef QRULEENGINE_RETTYPEUINT_H
#define QRULEENGINE_RETTYPEUINT_H

#include "retType/RetType.h"
#include <QString>

class RetTypeUInt: public RetType {
public:
    RetTypeUInt(quint32 data): data(data) {}
    ~RetTypeUInt() {}

    RetTypeE getType();
    quint32 getData();
private:
    quint32 data;
};

#endif // QRULEENGINE_RETTYPEUINT_H
