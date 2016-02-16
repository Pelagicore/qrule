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

QMap<QString, KRuleOutput*> Environment::accept(EnvironmentVisitor *envv) {
    if (rootScope == NULL) {
        return QMap<QString, KRuleOutput*>();
    } else {
        return rootScope->accept(envv);
    }
}

QMap<QString, KRuleOutput*> EnvScope::accept(EnvironmentVisitor *envv) {
    QMap<QString, KRuleOutput*> map;
    foreach(EnvScope *scope, innerScopes) {
        QMap<QString, KRuleOutput*> inner = scope->accept(envv);
        map = mergeOccurranceMap(map, inner);
    }
    map = mergeOccurranceMap(map, envv->visit(this));
    return map;
}

QMap<QString, KRuleOutput*> mergeOccurranceMap(QMap<QString, KRuleOutput*> m1, QMap<QString, KRuleOutput*> m2) {
    foreach(QString key, m2.keys()) {
        if (m1.contains(key)) {
            KRuleOutput* ko = m1[key];
            ko->addCodeOccurrances(m2[key]);
            m1.insert(key, ko);
        } else {
            m1.insert(key, m2[key]);
        }
    }
    return m1;
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
