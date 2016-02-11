/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "ParseException.h"
#include "Skeleton.H"

#include <Printer.H>



void KRuleVisitor::visitRuleSet(RuleSet* t) {} //abstract class
void KRuleVisitor::visitRule(Rule* t) {} //abstract class
void KRuleVisitor::visitAnalysis(Analysis* t) {} //abstract class
void KRuleVisitor::visitTag(Tag* t) {} //abstract class
void KRuleVisitor::visitSeverity(Severity* t) {} //abstract class
void KRuleVisitor::visitExpr(Expr* t) {} //abstract class
void KRuleVisitor::visitScope(Scope* t) {} //abstract class
void KRuleVisitor::visitParam(Param* t) {} //abstract class

void KRuleVisitor::visitRSet(RSet *rset)
{
  /* Code For RSet Goes Here */

  rset->listrule_->accept(this);

}

void KRuleVisitor::visitRRule(RRule *rrule)
{
  /* Code For RRule Goes Here */
  rrule->tag_->accept(this);
  rrule->severity_->accept(this);
  rrule->analysis_->accept(this);
  rrule->expr_->accept(this);

  if (!rtBool) {
      PrintAbsyn prnt = PrintAbsyn();
      QString reason = prnt.print(rrule);
      throw ParseException(reason.append(" \n ").append(scope->getCode()));
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

void KRuleVisitor::visitERsInScope(ERsInScope *ersinscope)
{
  /* Code For ERsInScope Goes Here */

  ersinscope->scope_->accept(this);

}

void KRuleVisitor::visitETrue(ETrue *etrue)
{
  /* Code For ETrue Goes Here */


}

void KRuleVisitor::visitEFalse(EFalse *efalse)
{
  /* Code For EFalse Goes Here */


}

void KRuleVisitor::visitEIsSet(EIsSet *eisset)
{
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
  /* Code For ENot Goes Here */

  enot->expr_->accept(this);

}

void KRuleVisitor::visitEImpl(EImpl *eimpl)
{
  /* Code For EImpl Goes Here */

  eimpl->expr_1->accept(this);
  eimpl->expr_2->accept(this);

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
  /* Code For EAnd Goes Here */

  eand->expr_1->accept(this);
  eand->expr_2->accept(this);

}

void KRuleVisitor::visitEOr(EOr *eor)
{
  /* Code For EOr Goes Here */

  eor->expr_1->accept(this);
  eor->expr_2->accept(this);

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
  for (ListRule::iterator i = listrule->begin() ; i != listrule->end() ; ++i)
  {
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

void KRuleVisitor::visitChar(Char x) {
}

void KRuleVisitor::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void KRuleVisitor::visitString(String x)
{
    rtString = rtString.fromStdString(x);
}

void KRuleVisitor::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}

bool KRuleVisitor::getResult() {
  return rtBool;
}

