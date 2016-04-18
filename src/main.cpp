#include "kruleengine.h"

#include <stdio.h>

#include <QDebug>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <output/xmloutputformatter.h>

void printOutput(const QList<KRuleOutput*> &ruleViolations) {
    OutputFormatter* xof = new XMLOutputFormatter(ruleViolations);
    qDebug() << xof->format().toStdString().c_str();

    QFile fl("output.xml");
    fl.open(QIODevice::WriteOnly);
    fl.write(xof->format().toStdString().c_str());
    fl.close();
    delete xof;
}

int main(int argv, char *argc[]) {
    // Setup commandline parser
    QCoreApplication app(argv, argc);
    QCoreApplication::setApplicationName("KRuleEngine");
    QCoreApplication::setApplicationVersion("1.0");
    QCommandLineParser commandLine;
    commandLine.setApplicationDescription(QLatin1String("Semantic rule engine for verifying QML code."));
    commandLine.addHelpOption();
    commandLine.addVersionOption();

    commandLine.addPositionalArgument(QLatin1String("krule"), QLatin1String("KRule rules file"));
    commandLine.addPositionalArgument(QLatin1String("files"), QLatin1String("list of qml or js files to verify"));

    commandLine.process(app);

    // Display help instead of running the KRule Engine if too few arguments were given
    if (commandLine.positionalArguments().length() < 2) {
        commandLine.showHelp(-1);
    }

    QStringList arguments = commandLine.positionalArguments();
    QString kruleFilename = arguments.takeFirst();
    KRuleEngine kruleEngine = KRuleEngine(kruleFilename);

    QList<KRuleOutput*> violations = kruleEngine.verifyQMLFiles(arguments);

    printOutput(violations);

    return violations.isEmpty() ? 0 : 1;
}
