// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
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
                .append("\" astscope=\"").append(ko->astscope)
                .append("\" rulecause=\"").append(ko->rulecause)
                .append("\">\n");
        QString kruleEndTag = "</krule>\n";
        QString explanationTag = QString().append("<explanation>\n").append(ko->explanation).append("\n</explanation>");

        output.append(kruleStartTag.append(occurrances).append(explanationTag).append(kruleEndTag));
    }
    output.chop(1);
    return output;
}
