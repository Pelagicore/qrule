#ifndef KRULEENGINE_ENVIRONMENTVERIFIERQML_H
#define KRULEENGINE_ENVIRONMENTVERIFIERQML_H

#include "Environment.h"
#include "Skeleton.h"

class EnvironmentVisitorQml: public EnvironmentVisitor {
public:
    EnvironmentVisitorQml(RuleSet *kruleSet):
        kruleSet(kruleSet){}

    bool visit(EnvScope *scope);
private:
    RuleSet *kruleSet;
};



#endif //KRULEENGINE_ENVIRONMENTVERIFIERQML_H
