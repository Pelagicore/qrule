#ifndef KRULEENGINE_ENVIRONMENT_H
#define KRULEENGINE_ENVIRONMENT_H

#include "QString"
#include <Absyn.H>

class EnvParam {
public:
    EnvParam() {}
    virtual ~EnvParam() {}

    QString name;
    QString value;
};

class EnvScope {
public:
    EnvScope(QString name): name(name) {}
    virtual ~EnvScope() {
        foreach (EnvParam *p, params) {
            delete p;
        }
        foreach (EnvScope *s, innerScopes) {
            delete s;
        }
    }

    QString name;
    EnvScope *parent = NULL;
    std::vector<EnvParam*> params;
    std::vector<EnvScope*> innerScopes;
};

class Environment {
public:
    Environment() {}
    virtual ~Environment() {}

    void addParam(QString name, QString value);
    void enterNewScope(QString name);
    void exitCurrentScope();

    void print();

private:
    QString indentStr = " ";
    signed int indent = 0;
    void print(EnvScope *scope);
    EnvScope *rootScope = new EnvScope("ROOT");
    EnvScope *currentScope = rootScope;
};


#endif //KRULEENGINE_ENVIRONMENT_H
