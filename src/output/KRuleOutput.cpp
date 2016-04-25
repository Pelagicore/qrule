// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#include "output/KRuleOutput.h"

void KRuleOutput::addCodeOccurrance(CodeOccurrance codeOccurrance) {
    codeOccurrances.append(codeOccurrance);
}

void KRuleOutput::addCodeOccurrances(KRuleOutput* kro) {
    codeOccurrances += kro->codeOccurrances;
}

QList<CodeOccurrance>& KRuleOutput::getOccurrances() {
    return codeOccurrances;
}
