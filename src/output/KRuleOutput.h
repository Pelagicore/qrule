// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0
#ifndef KRULEOUTPUT_H
#define KRULEOUTPUT_H

#include <QList>
#include <QString>

class CodeOccurrance {
public:
    CodeOccurrance(QString code, QString filename, quint32 row, quint32 col):
        code(code), filename(filename), row(row), col(col) {}
    ~CodeOccurrance() {}

    QString code;
    QString filename;
    quint32 row;
    quint32 col;
};

class KRuleOutput {
public:
    KRuleOutput(QString tag, QString severity, QString astscope,
                QString rulecause, QString explanation):
        tag(tag), severity(severity), astscope(astscope),
        rulecause(rulecause), explanation(explanation) {}
    ~KRuleOutput() {}

    void addCodeOccurrance(CodeOccurrance codeOccurrance);
    void addCodeOccurrances(KRuleOutput* kro);

    const QString tag;
    const QString severity;
    const QString astscope;
    const QString rulecause;
    const QString explanation;
    QList<CodeOccurrance>& getOccurrances();
    bool operator==(const KRuleOutput &k);
private:
    QList<CodeOccurrance> codeOccurrances;
};

#endif // KRULEOUTPUT_H
