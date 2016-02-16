#ifndef KRULEENGINE_ENVIRONMENT_H
#define KRULEENGINE_ENVIRONMENT_H

#include "QString"
#include <gen/Absyn.h>
#include "EnvironmentVerifier.h"
#include <QList>
#include <QMap>
#include "KRuleOutput.h"

class EnvironmentVisitor;

class EnvParam {
public:
    EnvParam() {}
    virtual ~EnvParam() {}

    QString name;
    QString value;
};

QMap<QString, KRuleOutput*> mergeOccurranceMap(QMap<QString, KRuleOutput*> m1, QMap<QString, KRuleOutput*> m2);

class EnvScope {
public:
    EnvScope(QString name, QString file, quint32 row, quint32 col, QString code):
        name(name), file(file), row(row), col(col), code(code) {}
    virtual ~EnvScope() {
        foreach (EnvParam *p, params) {
            delete p;
        }
        foreach (EnvScope *s, innerScopes) {
            delete s;
        }
    }

    QMap<QString, KRuleOutput*> accept(EnvironmentVisitor*);

    QString getCode();
    QString name;
    EnvScope *parent = NULL;
    std::vector<EnvParam*> params;
    std::vector<EnvScope*> innerScopes;
private:
    const QString code;
    const QString file;
    const quint32 row;
    const quint32 col;
};

class Environment {
public:
    Environment() {}
    virtual ~Environment() {}

    void addParam(QString name, QString value);
    void enterNewScope(QString name, QString file, quint32 row, quint32 col, QString code);
    void exitCurrentScope();

    QMap<QString, KRuleOutput*> accept(EnvironmentVisitor *);
    void print();

private:
    QString indentStr = " ";
    signed int indent = 0;
    void print(EnvScope *scope);
    EnvScope *rootScope = NULL;
    EnvScope *currentScope = rootScope;
};

class EnvironmentVisitor {
public:
    virtual QMap<QString, KRuleOutput*> visit(EnvScope *scope) = 0;

};

#endif //KRULEENGINE_ENVIRONMENT_H
