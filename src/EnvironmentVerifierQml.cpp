#include "EnvironmentVerifierQml.h"

bool EnvironmentVisitorQml::visit(EnvScope *scope) {
    KRuleVisitor kruleVisitor = KRuleVisitor(scope);
    kruleSet->accept(&kruleVisitor);
    return kruleVisitor.getResult();
}
