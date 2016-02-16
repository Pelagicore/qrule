#include "output/xmloutputformatter.h"

QString XMLOutputFormatter::format(){
    QString output = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    foreach (KRuleOutput* ko, klist){
        QString occurrances = QString();
        foreach (CodeOccurrance occurrance, ko->getOccurrances()) {
            occurrances.append("<occurrance")
                       .append(" row=\"").append(std::to_string(occurrance.row).c_str()).append("\"")
                       .append(" col=\"").append(std::to_string(occurrance.col).c_str()).append("\"")
                       .append(" filename=\"").append(occurrance.filename).append("\">\n")
                       .append(occurrance.code.toHtmlEscaped())
                       .append("\n</occurrance>\n");
        }

        QString kruleStartTag = QString().append("<krule tag=\"").append(ko->tag)
                .append("\" severity=\"").append(ko->severity)
                .append("\" analysisMode=\"").append(ko->analysisMode)
                .append("\">");
        QString kruleEndTag = "</krule>\n";

        output.append(kruleStartTag.append(occurrances).append(kruleEndTag));
    }
    output.chop(1);
    return output;
}
