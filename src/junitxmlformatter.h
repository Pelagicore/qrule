// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0

#ifndef JUNITXMLFORMATTER_H
#define JUNITXMLFORMATTER_H

#include "output/outputformatter.h"

class JUnitXMLFormatter: public OutputFormatter {
public:
    JUnitXMLFormatter(QList<KRuleOutput*> klist):OutputFormatter(klist) {}
};

#endif // JUNITXMLFORMATTER_H
