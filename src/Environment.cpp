#include "Environment.h"
#include <QDebug>

void Environment::addParam(QString name, QString value) {
    EnvParam *newParam = new EnvParam();
    newParam->name = name;
    newParam->value = value;
    currentScope->params.push_back(newParam);
}

void Environment::enterNewScope(QString name) {
    EnvScope *newScope = new EnvScope(name);
    newScope->parent = currentScope;
    currentScope->innerScopes.push_back(newScope);
    currentScope = newScope;
}

void Environment::exitCurrentScope() {
    if (currentScope->parent) {
        currentScope = currentScope->parent;
    }
}

void Environment::print(){
    print(rootScope);
}

void Environment::print(EnvScope *scope) {
    qInfo() << indentStr.repeated(indent) << scope->name;

    indent += 2;
    foreach(EnvParam *p, scope->params) {
        qInfo() << indentStr.repeated(indent) << p->name << ": " << p->value;
    }
    foreach(EnvScope *s, scope->innerScopes) {
        print(s);
    }
    indent -= 2;
}
