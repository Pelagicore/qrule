/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"



void Skeleton::visitRuleSet(RuleSet* t) {} //abstract class
void Skeleton::visitRule(Rule* t) {} //abstract class
void Skeleton::visitAnalysis(Analysis* t) {} //abstract class
void Skeleton::visitTag(Tag* t) {} //abstract class
void Skeleton::visitSeverity(Severity* t) {} //abstract class
void Skeleton::visitExpr(Expr* t) {} //abstract class
void Skeleton::visitScope(Scope* t) {} //abstract class
void Skeleton::visitParam(Param* t) {} //abstract class

void Skeleton::visitRSet(RSet *rset)
{
  /* Code For RSet Goes Here */

  rset->listrule_->accept(this);

}

void Skeleton::visitRRule(RRule *rrule)
{
  /* Code For RRule Goes Here */

  val += 1;
  rrule->tag_->accept(this);
  rrule->severity_->accept(this);
  rrule->analysis_->accept(this);
  rrule->expr_->accept(this);

}

void Skeleton::visitAStatic(AStatic *astatic)
{
  /* Code For AStatic Goes Here */


}

void Skeleton::visitADynamic(ADynamic *adynamic)
{
  /* Code For ADynamic Goes Here */


}

void Skeleton::visitTTag(TTag *ttag)
{
  /* Code For TTag Goes Here */

  visitString(ttag->string_);

}

void Skeleton::visitSevWarning(SevWarning *sevwarning)
{
  /* Code For SevWarning Goes Here */


}

void Skeleton::visitSevCritical(SevCritical *sevcritical)
{
  /* Code For SevCritical Goes Here */


}

void Skeleton::visitEInt(EInt *eint)
{
  /* Code For EInt Goes Here */
  visitInteger(eint->integer_);

}

void Skeleton::visitEMinRDepth(EMinRDepth *eminrdepth)
{
  /* Code For EMinRDepth Goes Here */


}

void Skeleton::visitEMaxRDepth(EMaxRDepth *emaxrdepth)
{
  /* Code For EMaxRDepth Goes Here */


}

void Skeleton::visitEDepth(EDepth *edepth)
{
  /* Code For EDepth Goes Here */


}

void Skeleton::visitENrChildren(ENrChildren *enrchildren)
{
  /* Code For ENrChildren Goes Here */


}

void Skeleton::visitERsInScope(ERsInScope *ersinscope)
{
  /* Code For ERsInScope Goes Here */

  ersinscope->scope_->accept(this);

}

void Skeleton::visitETrue(ETrue *etrue)
{
  /* Code For ETrue Goes Here */


}

void Skeleton::visitEFalse(EFalse *efalse)
{
  /* Code For EFalse Goes Here */


}

void Skeleton::visitEIsSet(EIsSet *eisset)
{
  /* Code For EIsSet Goes Here */

  eisset->param_->accept(this);

}

void Skeleton::visitEIsType(EIsType *eistype)
{
  /* Code For EIsType Goes Here */

  visitString(eistype->string_);

}

void Skeleton::visitEParant(EParant *eparant)
{
  /* Code For EParant Goes Here */

  eparant->expr_->accept(this);

}

void Skeleton::visitENot(ENot *enot)
{
  /* Code For ENot Goes Here */

  enot->expr_->accept(this);

}

void Skeleton::visitEImpl(EImpl *eimpl)
{
  /* Code For EImpl Goes Here */

  eimpl->expr_1->accept(this);
  eimpl->expr_2->accept(this);

}

void Skeleton::visitELtEq(ELtEq *elteq)
{
  /* Code For ELtEq Goes Here */

  elteq->expr_1->accept(this);
  elteq->expr_2->accept(this);

}

void Skeleton::visitEGtEq(EGtEq *egteq)
{
  /* Code For EGtEq Goes Here */

  egteq->expr_1->accept(this);
  egteq->expr_2->accept(this);

}

void Skeleton::visitELt(ELt *elt)
{
  /* Code For ELt Goes Here */

  elt->expr_1->accept(this);
  elt->expr_2->accept(this);

}

void Skeleton::visitEGt(EGt *egt)
{
  /* Code For EGt Goes Here */

  egt->expr_1->accept(this);
  egt->expr_2->accept(this);

}

void Skeleton::visitEEq(EEq *eeq)
{
  /* Code For EEq Goes Here */

  eeq->expr_1->accept(this);
  eeq->expr_2->accept(this);

}

void Skeleton::visitEAnd(EAnd *eand)
{
  /* Code For EAnd Goes Here */

  eand->expr_1->accept(this);
  eand->expr_2->accept(this);

}

void Skeleton::visitEOr(EOr *eor)
{
  /* Code For EOr Goes Here */

  eor->expr_1->accept(this);
  eor->expr_2->accept(this);

}

void Skeleton::visitERelease(ERelease *erelease)
{
  /* Code For ERelease Goes Here */

  erelease->expr_1->accept(this);
  erelease->expr_2->accept(this);

}

void Skeleton::visitENext(ENext *enext)
{
  /* Code For ENext Goes Here */

  enext->expr_1->accept(this);
  enext->expr_2->accept(this);

}

void Skeleton::visitEEventually(EEventually *eeventually)
{
  /* Code For EEventually Goes Here */

  eeventually->expr_->accept(this);

}

void Skeleton::visitEAlways(EAlways *ealways)
{
  /* Code For EAlways Goes Here */

  ealways->expr_->accept(this);

}

void Skeleton::visitEUntil(EUntil *euntil)
{
  /* Code For EUntil Goes Here */

  euntil->expr_1->accept(this);
  euntil->expr_2->accept(this);

}

void Skeleton::visitSParent(SParent *sparent)
{
  /* Code For SParent Goes Here */


}

void Skeleton::visitSFile(SFile *sfile)
{
  /* Code For SFile Goes Here */


}

void Skeleton::visitSChildren(SChildren *schildren)
{
  /* Code For SChildren Goes Here */


}

void Skeleton::visitSSiblings(SSiblings *ssiblings)
{
  /* Code For SSiblings Goes Here */


}

void Skeleton::visitSAny(SAny *sany)
{
  /* Code For SAny Goes Here */


}

void Skeleton::visitPParam(PParam *pparam)
{
  /* Code For PParam Goes Here */

  visitString(pparam->string_);

}


void Skeleton::visitListRule(ListRule* listrule)
{
  for (ListRule::iterator i = listrule->begin() ; i != listrule->end() ; ++i)
  {
    (*i)->accept(this);
  }
}

void Skeleton::visitListExpr(ListExpr* listexpr)
{
  for (ListExpr::iterator i = listexpr->begin() ; i != listexpr->end() ; ++i)
  {
    (*i)->accept(this);
  }
}


void Skeleton::visitInteger(Integer x)
{
  /* Code for Integer Goes Here */
}

void Skeleton::visitChar(Char x)
{
  /* Code for Char Goes Here */
}

void Skeleton::visitDouble(Double x)
{
  /* Code for Double Goes Here */
}

void Skeleton::visitString(String x)
{
  /* Code for String Goes Here */
}

void Skeleton::visitIdent(Ident x)
{
  /* Code for Ident Goes Here */
}

unsigned int Skeleton::getResult() {
  return val;
}

