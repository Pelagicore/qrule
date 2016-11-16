// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#ifndef QRULEENGINE_RETTYPE_H
#define QRULEENGINE_RETTYPE_H

#include <QObject>


class RetType: public QObject {
public:
    enum RetTypeE {RInt, RString, RBool};
    virtual RetTypeE getType() = 0;
};

#endif // QRULEENGINE_RETTYPE_H
