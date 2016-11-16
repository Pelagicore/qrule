// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#ifndef QRULEXMLOUTPUTFORMATTER_H
#define QRULEXMLOUTPUTFORMATTER_H

#include "output/outputformatter.h"

class XMLOutputFormatter: public OutputFormatter {
public:
    XMLOutputFormatter(QList<QRuleOutput*> klist):OutputFormatter(klist) {}
    ~XMLOutputFormatter() {}
    QString format();

};

#endif // QRULEXMLOUTPUTFORMATTER_H
