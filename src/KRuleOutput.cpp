#include "KRuleOutput.h"

QString KRuleOutput::toXML() {
    QString occurrances = QString();
    foreach (QString occurrance, codeOccurrances) {
        occurrances.append("<occurrance>").append(occurrance).append("</occurrance>");
    }

    QString ret = "<krule tag=\"";
    return ret.append(tag).append("\" severity=\"").append(severity).append("\" analysisMode=\"").append(analysisMode).append("\">")
                          .append(occurrances).append( "</krule>");
}

QString KRuleOutput::toString() {
    QString occurrances = QString();
    foreach (QString occurrance, codeOccurrances) {
        occurrances.append(occurrance).append("\n");
    }
    return QString().append(tag).append(" ").append(severity).append(" ").append(analysisMode).append(":\n").append(occurrances);
}

void KRuleOutput::addCodeOccurrance(QString codeOccurrance) {
    codeOccurrances.append(codeOccurrance);
}

void KRuleOutput::addCodeOccurrances(KRuleOutput* kro) {
    codeOccurrances += kro->codeOccurrances;
}
