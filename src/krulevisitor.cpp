#include "ParseException.h"
#include "krulevisitor.h"
#include <gen/Printer.h>
#include <QRegExp>
#include "retType/RetTypeBool.h"
#include "retType/RetTypeString.h"
#include "retType/RetTypeUInt.h"

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
  try {
      rrule->tag_->accept(this);
      rrule->severity_->accept(this);
      rrule->analysis_->accept(this);
      rrule->expr_->accept(this);

      if (!getBoolRet()) {
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

void KRuleVisitor::visitAStatic(AStatic *) {
    currentRuleAnalysis = "Static";
}

void KRuleVisitor::visitADynamic(ADynamic *) {
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

void KRuleVisitor::visitETrue(ETrue *) {
    changeRet(new RetTypeBool(true));
}

void KRuleVisitor::visitEFalse(EFalse *) {
    changeRet(new RetTypeBool(false));
}

void KRuleVisitor::visitEIsSetRx(EIsSetRx *eisset) {
  eisset->param_->accept(this);
  bool s = false;

  QRegExp regexp = QRegExp(getStringRet());
  foreach (EnvParam *p, scope->params) {
      if (regexp.exactMatch(p->name)) {
          s = true;
      }
  }
  changeRet(new RetTypeBool(s));
}

void KRuleVisitor::visitEIsSet(EIsSet *eisset) {
  eisset->param_->accept(this);
  bool s = false;
  QString param = getStringRet();
  foreach (EnvParam *p, scope->params) {
      if (param.compare(p->name) == 0) {
          s = true;
      }
  }
  changeRet(new RetTypeBool(s));
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
  changeRet(new RetTypeBool(!getBoolRet()));
}

void KRuleVisitor::visitEImpl(EImpl *eimpl) {
  eimpl->expr_1->accept(this);
  const bool leftExpression = getBoolRet();
  bool rtBool;
  if (leftExpression == true) {
      eimpl->expr_2->accept(this);
      const bool rightExpression = getBoolRet();
      rtBool = rightExpression == true;
  } else {
      rtBool = true;
  }
  changeRet(new RetTypeBool(rtBool));
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
  const bool b1 = getBoolRet();
  eand->expr_2->accept(this);
  const bool b2 = getBoolRet();
  changeRet(new RetTypeBool(b1 && b2));
}

void KRuleVisitor::visitEOr(EOr *eor) {
  eor->expr_1->accept(this);
  const bool b1 = getBoolRet();
  eor->expr_2->accept(this);
  const bool b2 = getBoolRet();
  changeRet(new RetTypeBool(b1 || b2));
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
    changeRet(new RetTypeUInt((quint32)x));
}

void KRuleVisitor::visitString(String x) {
    changeRet(new RetTypeString(QString(x.c_str())));
}

QMap<QString, KRuleOutput*> KRuleVisitor::getFailures() {
    return failedRules;
}

void KRuleVisitor::changeRet(RetType *ret) {
    if (ret != NULL) {
       delete this->ret;
    }
    this->ret = ret;
}

void KRuleVisitor::assertType(RetType::RetTypeE type) {
    if (ret->getType() != type) {
        throw BadType();
    }
}

bool KRuleVisitor::getBoolRet() {
    assertType(RetType::RetTypeE::RBool);
    return ((RetTypeBool*)ret)->getData();
}

QString KRuleVisitor::getStringRet() {
    assertType(RetType::RetTypeE::RString);
    return ((RetTypeString*)ret)->getData();
}

quint32 KRuleVisitor::getUIntRet() {
    assertType(RetType::RetTypeE::RInt);
    return ((RetTypeUInt*)ret)->getData();
}
