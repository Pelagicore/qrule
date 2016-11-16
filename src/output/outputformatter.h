// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#ifndef OUTPUTPRINTER_H
#define OUTPUTPRINTER_H

#include "QRuleOutput.h"
#include <QList>
#include <QString>

class OutputFormatter {
public:
    OutputFormatter(QList<QRuleOutput*> klist): klist(klist) {}
    virtual ~OutputFormatter() {}
    virtual QString format() = 0;

protected:
    QList<QRuleOutput*> klist;
};

#endif // OUTPUTPRINTER_H
