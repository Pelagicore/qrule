#include "Environment.h"
#include <QDebug>

void Environment::addParam(QString name, QString value) {
    EnvParam *newParam = new EnvParam();
    newParam->name = name;
    newParam->value = value;
    currentScope->params.push_back(newParam);
}

void Environment::enterNewScope(QString name, QString file, quint32 row, quint32 col, QString code) {
    EnvScope *newScope = new EnvScope(name, file, row, col, code);
    if (rootScope == NULL) {
        rootScope = newScope;
        currentScope = rootScope;
    } else {
        newScope->parent = currentScope;
        currentScope->innerScopes.push_back(newScope);
        currentScope = newScope;
    }
}

void Environment::exitCurrentScope() {
    if (currentScope->parent) {
        currentScope = currentScope->parent;
    }
}

bool Environment::accept(EnvironmentVisitor *envv) {
    if (rootScope == NULL) {
        return false;
    } else {
        return rootScope->accept(envv);
    }
}

bool EnvScope::accept(EnvironmentVisitor *envv) {
    bool success = true;
    foreach(EnvScope *scope, innerScopes) {
        success &= scope->accept(envv);
    }
    success &= envv->visit(this);
    return success;
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

QString EnvScope::getCode(){
    QString rt = "";
    return rt.append(file).append(" ")
            .append(std::to_string(row).c_str())
            .append(":")
            .append(std::to_string(col).c_str())
            .append(":\n")
            .append(code);
}
