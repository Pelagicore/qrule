// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#ifndef KRULEENGINE_RETTYPE_H
#define KRULEENGINE_RETTYPE_H

#include <QObject>


class RetType: public QObject {
public:
    enum RetTypeE {RInt, RString, RBool};
    virtual RetTypeE getType() = 0;
};

#endif // KRULEENGINE_RETTYPE_H
