#include "ParseException.h"
#include "krulevisitor.h"
#include <gen/Printer.h>
#include <QRegExp>

void KRuleVisitor::visitRuleSet(RuleSet* t) {}
void KRuleVisitor::visitRule(Rule* t) {}
void KRuleVisitor::visitAnalysis(Analysis* t) {}
void KRuleVisitor::visitTag(Tag* t) {}
void KRuleVisitor::visitSeverity(Severity* t) {}
void KRuleVisitor::visitExpr(Expr* t) {}
void KRuleVisitor::visitScope(Scope* t) {}
void KRuleVisitor::visitParam(Param* t) {}

void KRuleVisitor::visitRSet(RSet *rset) {
  rset->listrule_->accept(this);
}

void KRuleVisitor::visitRRule(RRule *rrule) {
  resetRts();
  rrule->tag_->accept(this);
  rrule->severity_->accept(this);
  rrule->analysis_->accept(this);
  rrule->expr_->accept(this);

  try {
      if (!rtBool) {

          KRuleOutput* outp;
          if (failedRules.contains(currentRuleTag)) {
              outp = failedRules[currentRuleTag];
          } else {
              outp = new KRuleOutput(currentRuleTag, currentRuleSeverity, currentRuleAnalysis);
          }
          outp->addCodeOccurrance(scope->codeOccurrance);
          failedRules.insert(currentRuleTag, outp);
      }
  }
  catch(NotImplemented &) {}
}

void KRuleVisitor::visitAStatic(AStatic *astatic) {
    currentRuleAnalysis = "Static";
}

void KRuleVisitor::visitADynamic(ADynamic *adynamic) {
    currentRuleAnalysis = "Dynamic";
}

void KRuleVisitor::visitTTag(TTag *ttag) {
    currentRuleTag = currentRuleTag.fromStdString(ttag->string_);
}

void KRuleVisitor::visitSevWarning(SevWarning *) {
    currentRuleSeverity = "Warning";
}

void KRuleVisitor::visitSevCritical(SevCritical *) {
    currentRuleSeverity = "Critical";
}

void KRuleVisitor::visitEInt(EInt *eint) {
  visitInteger(eint->integer_);
}

void KRuleVisitor::visitEMinRDepth(EMinRDepth *eminrdepth) {
  throw NotImplemented();
}

void KRuleVisitor::visitEMaxRDepth(EMaxRDepth *emaxrdepth) {
  throw NotImplemented();
}

void KRuleVisitor::visitEDepth(EDepth *edepth) {
  throw NotImplemented();
}

void KRuleVisitor::visitENrChildren(ENrChildren *enrchildren) {
  throw NotImplemented();
}

void KRuleVisitor::visitERsInScope(ERsInScope *ersinscope) {
  ersinscope->scope_->accept(this);
}

void KRuleVisitor::visitETrue(ETrue *etrue) {
  rtBool = true;
}

void KRuleVisitor::visitEFalse(EFalse *efalse) {
  rtBool = false;
}

void KRuleVisitor::visitEIsSetRx(EIsSetRx *eisset) {
  eisset->param_->accept(this);
  bool s = false;

  QRegExp regexp = QRegExp(rtString);
  foreach (EnvParam *p, scope->params) {
      if (regexp.exactMatch(p->name)) {
          s = true;
      }
  }
  rtString = "";
  rtBool = s;
}

void KRuleVisitor::visitEIsSet(EIsSet *eisset) {
  eisset->param_->accept(this);
  bool s = false;
  foreach (EnvParam *p, scope->params) {
      if (rtString.compare(p->name) == 0) {
          s = true;
      }
  }
  rtString = "";
  rtBool = s;
}

void KRuleVisitor::visitEIsType(EIsType *eistype) {
  throw NotImplemented();
  visitString(eistype->string_);
}

void KRuleVisitor::visitEParant(EParant *eparant) {
  eparant->expr_->accept(this);
}

void KRuleVisitor::visitENot(ENot *enot) {
  enot->expr_->accept(this);
  rtBool = !rtBool;
}

void KRuleVisitor::visitEImpl(EImpl *eimpl) {
  eimpl->expr_1->accept(this);
  const bool leftExpression = rtBool;
  if (leftExpression == true) {
      eimpl->expr_2->accept(this);
      const bool rightExpression = rtBool;
      rtBool = rightExpression == true;
  } else {
      rtBool = true;
  }
}

void KRuleVisitor::visitELtEq(ELtEq *elteq) {
  throw NotImplemented();
  elteq->expr_1->accept(this);
  elteq->expr_2->accept(this);

}

void KRuleVisitor::visitEGtEq(EGtEq *egteq) {
  throw NotImplemented();

  egteq->expr_1->accept(this);
  egteq->expr_2->accept(this);

}

void KRuleVisitor::visitELt(ELt *elt) {
  throw NotImplemented();

  elt->expr_1->accept(this);
  elt->expr_2->accept(this);

}

void KRuleVisitor::visitEGt(EGt *egt) {
  throw NotImplemented();

  egt->expr_1->accept(this);
  egt->expr_2->accept(this);

}

void KRuleVisitor::visitEEq(EEq *eeq) {
  throw NotImplemented();

  eeq->expr_1->accept(this);
  eeq->expr_2->accept(this);

}

void KRuleVisitor::visitEAnd(EAnd *eand) {
  eand->expr_1->accept(this);
  const bool b1 = rtBool;
  rtBool = false;
  eand->expr_2->accept(this);
  const bool b2 = rtBool;
  rtBool = b1 && b2;
}

void KRuleVisitor::visitEOr(EOr *eor) {
  eor->expr_1->accept(this);
  const bool b1 = rtBool;
  rtBool = false;
  eor->expr_2->accept(this);
  const bool b2 = rtBool;
  rtBool = b1 || b2;
}

void KRuleVisitor::visitERelease(ERelease *erelease) {
  throw NotImplemented();

  erelease->expr_1->accept(this);
  erelease->expr_2->accept(this);

}

void KRuleVisitor::visitENext(ENext *enext) {
  throw NotImplemented();

  enext->expr_1->accept(this);
  enext->expr_2->accept(this);

}

void KRuleVisitor::visitEEventually(EEventually *eeventually) {
  throw NotImplemented();

  eeventually->expr_->accept(this);

}

void KRuleVisitor::visitEAlways(EAlways *ealways) {
  throw NotImplemented();

  ealways->expr_->accept(this);

}

void KRuleVisitor::visitEUntil(EUntil *euntil) {
  throw NotImplemented();

  euntil->expr_1->accept(this);
  euntil->expr_2->accept(this);

}

void KRuleVisitor::visitSParent(SParent *sparent) {
  throw NotImplemented();
}

void KRuleVisitor::visitSFile(SFile *sfile) {
  throw NotImplemented();
}

void KRuleVisitor::visitSChildren(SChildren *schildren) {
  throw NotImplemented();
}

void KRuleVisitor::visitSSiblings(SSiblings *ssiblings) {
  throw NotImplemented();
}

void KRuleVisitor::visitSAny(SAny *sany) {
  throw NotImplemented();
}

void KRuleVisitor::visitPParam(PParam *pparam) {
  visitString(pparam->string_);
}


void KRuleVisitor::visitListRule(ListRule* listrule) {
  for (ListRule::iterator i = listrule->begin() ; i != listrule->end() ; ++i){
    (*i)->accept(this);
  }
}

void KRuleVisitor::visitListExpr(ListExpr* listexpr) {
  for (ListExpr::iterator i = listexpr->begin() ; i != listexpr->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void KRuleVisitor::visitInteger(Integer x) {
    rtInt = x;
}

void KRuleVisitor::visitString(String x) {
    rtString = rtString.fromStdString(x);
}

void KRuleVisitor::visitIdent(Ident x)
{
  throw NotImplemented();
}

QMap<QString, KRuleOutput*> KRuleVisitor::getFailures() {
  return failedRules;
}

void KRuleVisitor::resetRts() {
    rtBool = false;
    rtInt  = 0;
    rtString = "";
}

void KRuleVisitor::visitChar(Char x) {}
void KRuleVisitor::visitDouble(Double x) {}
