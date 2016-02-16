#include "outputformatter/xmloutputformatter.h"

QString XMLOutputFormatter::format(){
    QString output = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
    foreach (KRuleOutput* ko, klist){
        QString occurrances = QString();
        foreach (CodeOccurrance occurrance, ko->getOccurrances()) {
            occurrances.append("<occurrance")
                       .append(" row=\"").append(occurrance.row).append("\"")
                       .append(" col=\"").append(occurrance.col).append("\"")
                       .append(" filename=\"").append(occurrance.filename).append("\">")
                       .append(occurrance.code.toHtmlEscaped())
                       .append("</occurrance>");
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
