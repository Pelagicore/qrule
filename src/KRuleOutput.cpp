#include "KRuleOutput.h"

void KRuleOutput::addCodeOccurrance(QString codeOccurrance) {
    codeOccurrances.append(codeOccurrance);
}

void KRuleOutput::addCodeOccurrances(KRuleOutput* kro) {
    codeOccurrances += kro->codeOccurrances;
}

const QList<QString>& KRuleOutput::getOccurrances() {
    return codeOccurrances;
}
