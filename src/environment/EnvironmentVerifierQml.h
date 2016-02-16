#ifndef KRULEENGINE_ENVIRONMENTVERIFIERQML_H
#define KRULEENGINE_ENVIRONMENTVERIFIERQML_H

#include "environment/Environment.h"
#include "krulevisitor.h"

class EnvironmentVisitorQml: public EnvironmentVisitor {
public:
    EnvironmentVisitorQml(RuleSet *kruleSet):
        kruleSet(kruleSet){}

    QMap<QString, KRuleOutput*> visit(EnvScope *scope);
private:
    RuleSet *kruleSet;
};



#endif //KRULEENGINE_ENVIRONMENTVERIFIERQML_H
