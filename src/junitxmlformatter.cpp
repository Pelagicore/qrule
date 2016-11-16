// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0

#include "junitxmlformatter.h"

#include <QMap>

QString JUnitXMLFormatter::format() {
    QString output = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";

    QMap<QString, int> sevMap;
    foreach (QRuleOutput* ko, klist){
        const QString key = ko->severity;
        int nr;
        if (sevMap.contains(key)) {
            nr = sevMap.value(key);
        } else {
            nr = 0;
        }
        sevMap.insert(key, nr + 1);
    }

    output += "<testsuites errors=\"";
    output += QString::number(sevMap.value("Critical"));
    output += "\" failures=\"";
    output += QString::number(sevMap.value("Warning"));
    output += "\" tests=\"";
    output += QString::number(0);
    output += "\" time=\"";
    output += QString::number(0);
    output += "\">\n";
    foreach (QRuleOutput* ko, klist){
        QString occurrances = QString();
        foreach (CodeOccurrance occurrance, ko->getOccurrances()) {
            occurrances.append("<occurrance")
                       .append(" row=\"").append(std::to_string(occurrance.row).c_str()).append("\"")
                       .append(" col=\"").append(std::to_string(occurrance.col).c_str()).append("\"")
                       .append(" filename=\"").append(occurrance.filename).append("\">\n")
                       .append(occurrance.code.toHtmlEscaped())
                       .append("\n</occurrance>\n");
        }

        QString qruleStartTag = QString().append("<testcase classname=\"\" name=\"").append(ko->tag)
                .append("\" severity=\"").append(ko->severity)
                .append("\" astscope=\"").append(ko->astscope)
                .append("\" rulecause=\"").append(ko->rulecause)
                .append("\">\n");
        QString qruleEndTag = "</testcase>\n";
        QString explanationTag = QString().append("<explanation>\n").append(ko->explanation).append("\n</explanation>");

        output.append(qruleStartTag.append(occurrances).append(explanationTag).append(qruleEndTag));
    }
    output.chop(1);
    return output.append("</testsuites>");
}
