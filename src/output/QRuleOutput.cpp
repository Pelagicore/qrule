// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#include "output/QRuleOutput.h"

void QRuleOutput::addCodeOccurrance(CodeOccurrance codeOccurrance) {
    codeOccurrances.append(codeOccurrance);
}

void QRuleOutput::addCodeOccurrances(QRuleOutput* kro) {
    codeOccurrances += kro->codeOccurrances;
}

QList<CodeOccurrance>& QRuleOutput::getOccurrances() {
    return codeOccurrances;
}
bool QRuleOutput::operator ==(const QRuleOutput &other){
    return this->tag==other.tag;
}
