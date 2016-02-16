#ifndef OUTPUTPRINTER_H
#define OUTPUTPRINTER_H

#include "KRuleOutput.h"
#include <QList>
#include <QString>

class OutputFormatter {
public:
    OutputFormatter(QList<KRuleOutput*> klist): klist(klist) {}
    virtual ~OutputFormatter() {}
    virtual QString format() = 0;

protected:
    QList<KRuleOutput*> klist;
};

#endif // OUTPUTPRINTER_H
