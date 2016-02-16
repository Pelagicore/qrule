/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "ParseException.h"
#include "Skeleton.h"

#include <gen/Printer.h>
#include <QRegExp>



void KRuleVisitor::visitRuleSet(RuleSet* t) {} //abstract class
void KRuleVisitor::visitRule(Rule* t) {} //abstract class
void KRuleVisitor::visitAnalysis(Analysis* t) {} //abstract class
void KRuleVisitor::visitTag(Tag* t) {} //abstract class
void KRuleVisitor::visitSeverity(Severity* t) {} //abstract class
void KRuleVisitor::visitExpr(Expr* t) {} //abstract class
void KRuleVisitor::visitScope(Scope* t) {} //abstract class
void KRuleVisitor::visitParam(Param* t) {} //abstract class

void KRuleVisitor::visitRSet(RSet *rset) {
  rset->listrule_->accept(this);
}

void KRuleVisitor::visitRRule(RRule *rrule) {
  resetRts();
  /* Code For RRule Goes Here */
  rrule->tag_->accept(this);
  rrule->severity_->accept(this);
  rrule->analysis_->accept(this);
  rrule->expr_->accept(this);

  if (!rtBool) {

      KRuleOutput* outp;
      if (failedRules.contains(currentRuleTag)) {
          outp = failedRules[currentRuleTag];
      } else {
          outp = new KRuleOutput(currentRuleTag, currentRuleSeverity, currentRuleAnalysis);
      }
      outp->addCodeOccurrance(scope->getCode());
      failedRules.insert(currentRuleTag, outp);
  }
}

void KRuleVisitor::visitAStatic(AStatic *astatic)
{
  /* Code For AStatic Goes Here */


}

void KRuleVisitor::visitADynamic(ADynamic *adynamic)
{
  /* Code For ADynamic Goes Here */


}

void KRuleVisitor::visitTTag(TTag *ttag)
{
    currentRuleTag = currentRuleTag.fromStdString(ttag->string_);
}

void KRuleVisitor::visitSevWarning(SevWarning *sevwarning)
{
  /* Code For SevWarning Goes Here */


}

void KRuleVisitor::visitSevCritical(SevCritical *sevcritical)
{
  /* Code For SevCritical Goes Here */


}

void KRuleVisitor::visitEInt(EInt *eint)
{
  /* Code For EInt Goes Here */
  visitInteger(eint->integer_);

}

void KRuleVisitor::visitEMinRDepth(EMinRDepth *eminrdepth)
{
  /* Code For EMinRDepth Goes Here */


}

void KRuleVisitor::visitEMaxRDepth(EMaxRDepth *emaxrdepth)
{
  /* Code For EMaxRDepth Goes Here */


}

void KRuleVisitor::visitEDepth(EDepth *edepth)
{
  /* Code For EDepth Goes Here */


}

void KRuleVisitor::visitENrChildren(ENrChildren *enrchildren)
{
  /* Code For ENrChildren Goes Here */


}

void KRuleVisitor::visitERsInScope(ERsInScope *ersinscope){
  /* Code For ERsInScope Goes Here */

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

void KRuleVisitor::visitEIsType(EIsType *eistype)
{
  /* Code For EIsType Goes Here */

  visitString(eistype->string_);

}

void KRuleVisitor::visitEParant(EParant *eparant)
{
  /* Code For EParant Goes Here */

  eparant->expr_->accept(this);

}

void KRuleVisitor::visitENot(ENot *enot)
{
  enot->expr_->accept(this);
  rtBool = !rtBool;
}

void KRuleVisitor::visitEImpl(EImpl *eimpl)
{
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

void KRuleVisitor::visitELtEq(ELtEq *elteq)
{
  /* Code For ELtEq Goes Here */

  elteq->expr_1->accept(this);
  elteq->expr_2->accept(this);

}

void KRuleVisitor::visitEGtEq(EGtEq *egteq)
{
  /* Code For EGtEq Goes Here */

  egteq->expr_1->accept(this);
  egteq->expr_2->accept(this);

}

void KRuleVisitor::visitELt(ELt *elt)
{
  /* Code For ELt Goes Here */

  elt->expr_1->accept(this);
  elt->expr_2->accept(this);

}

void KRuleVisitor::visitEGt(EGt *egt)
{
  /* Code For EGt Goes Here */

  egt->expr_1->accept(this);
  egt->expr_2->accept(this);

}

void KRuleVisitor::visitEEq(EEq *eeq)
{
  /* Code For EEq Goes Here */

  eeq->expr_1->accept(this);
  eeq->expr_2->accept(this);

}

void KRuleVisitor::visitEAnd(EAnd *eand)
{
  eand->expr_1->accept(this);
  const bool b1 = rtBool;
  rtBool = false;
  eand->expr_2->accept(this);
  const bool b2 = rtBool;
  rtBool = b1 && b2;
}

void KRuleVisitor::visitEOr(EOr *eor)
{
  eor->expr_1->accept(this);
  const bool b1 = rtBool;
  rtBool = false;
  eor->expr_2->accept(this);
  const bool b2 = rtBool;
  rtBool = b1 || b2;
}

void KRuleVisitor::visitERelease(ERelease *erelease)
{
  /* Code For ERelease Goes Here */

  erelease->expr_1->accept(this);
  erelease->expr_2->accept(this);

}

void KRuleVisitor::visitENext(ENext *enext)
{
  /* Code For ENext Goes Here */

  enext->expr_1->accept(this);
  enext->expr_2->accept(this);

}

void KRuleVisitor::visitEEventually(EEventually *eeventually)
{
  /* Code For EEventually Goes Here */

  eeventually->expr_->accept(this);

}

void KRuleVisitor::visitEAlways(EAlways *ealways)
{
  /* Code For EAlways Goes Here */

  ealways->expr_->accept(this);

}

void KRuleVisitor::visitEUntil(EUntil *euntil)
{
  /* Code For EUntil Goes Here */

  euntil->expr_1->accept(this);
  euntil->expr_2->accept(this);

}

void KRuleVisitor::visitSParent(SParent *sparent)
{
  /* Code For SParent Goes Here */


}

void KRuleVisitor::visitSFile(SFile *sfile)
{
  /* Code For SFile Goes Here */


}

void KRuleVisitor::visitSChildren(SChildren *schildren)
{
  /* Code For SChildren Goes Here */


}

void KRuleVisitor::visitSSiblings(SSiblings *ssiblings)
{
  /* Code For SSiblings Goes Here */


}

void KRuleVisitor::visitSAny(SAny *sany)
{
  /* Code For SAny Goes Here */


}

void KRuleVisitor::visitPParam(PParam *pparam)
{
  /* Code For PParam Goes Here */

  visitString(pparam->string_);
}


void KRuleVisitor::visitListRule(ListRule* listrule)
{
  for (ListRule::iterator i = listrule->begin() ; i != listrule->end() ; ++i){
    (*i)->accept(this);
  }
}

void KRuleVisitor::visitListExpr(ListExpr* listexpr)
{
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
  /* Code for Ident Goes Here */
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
