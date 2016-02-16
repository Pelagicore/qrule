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
