#ifndef KRULEOUTPUT_H
#define KRULEOUTPUT_H

#include <QList>
#include <QString>



class KRuleOutput {
public:
    KRuleOutput(QString tag, QString severity, QString analysisMode):
        tag(tag), severity(severity), analysisMode(analysisMode) {}

    QString toXML();
    QString toString();
    void addCodeOccurrance(QString codeOccurrance);
    void addCodeOccurrances(KRuleOutput* kro);

    const QString tag;
    const QString severity;
    const QString analysisMode;
private:
    QList<QString> codeOccurrances;
};

#endif // KRULEOUTPUT_H
