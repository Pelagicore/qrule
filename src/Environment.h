#ifndef KRULEENGINE_ENVIRONMENT_H
#define KRULEENGINE_ENVIRONMENT_H


#include <Absyn.H>

struct param {
    String name;
    String value;
};

struct scope {
    String name;
    std::vector<param> params;
    std::vector<scope> innerScopes;
};

class ScopeBuilder {
public:

    void visitas(scope s);

private:
    scope rootScope;
};


#endif //KRULEENGINE_ENVIRONMENT_H
