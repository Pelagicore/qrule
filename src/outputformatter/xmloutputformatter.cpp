#include "outputformatter/xmloutputformatter.h"

QString XMLOutputFormatter::format(){
    QString output = "";
    foreach (KRuleOutput* ko, klist){
        QString occurrances = QString();
        foreach (QString occurrance, ko->getOccurrances()) {
            occurrances.append("<occurrance>").append(occurrance).append("</occurrance>");
        }

        QString kruleStartTag = QString().append("<krule tag=\"").append(ko->tag)
                .append("\" severity=\"").append(ko->severity)
                .append("\" analysisMode=\"").append(ko->analysisMode)
                .append("\">");
        QString kruleEndTag = "</krule>";

        output.append(kruleStartTag.append(occurrances).append(kruleEndTag));
    }
    return output;
}
