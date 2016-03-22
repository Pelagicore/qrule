#include "ParseException.h"
#include "krulevisitor.h"
#include <gen/Printer.H>
#include <QRegExp>
#include "QMLChildren.h"

void KRuleVisitor::visitRuleSet(RuleSet* t) {} //abstract class
void KRuleVisitor::visitRule(Rule* t) {} //abstract class
void KRuleVisitor::visitASTScope(ASTScope* t) {} //abstract class
void KRuleVisitor::visitRuleCause(RuleCause* t) {} //abstract class
void KRuleVisitor::visitExplanation(Explanation* t) {} //abstract class
void KRuleVisitor::visitTag(Tag* t) {} //abstract class
void KRuleVisitor::visitSeverity(Severity* t) {} //abstract class
void KRuleVisitor::visitOverPaths(OverPaths* t) {} //abstract class
void KRuleVisitor::visitPathSpecific(PathSpecific* t) {} //abstract class
void KRuleVisitor::visitIStmnt(IStmnt* t) {} //abstract class
void KRuleVisitor::visitIExpr(IExpr* t) {} //abstract class
void KRuleVisitor::visitExpr(Expr* t) {} //abstract class
void KRuleVisitor::visitType(Type* t) {} //abstract class
void KRuleVisitor::visitParam(Param* t) {} //abstract class


void KRuleVisitor::visitRSet(RSet *rset) {
  rset->listrule_->accept(this);
}

void KRuleVisitor::visitRRule(RRule *rrule) {
  try {
      rrule->tag_->accept(this);
      rrule->severity_->accept(this);
      rrule->rulecause_->accept(this);
      rrule->astscope_->accept(this);
      rrule->explanation_->accept(this);
      rrule->expr_->accept(this);

      if (!getBoolRet()) {
          KRuleOutput* outp;
          if (failedRules.contains(currentRuleTag)) {
              outp = failedRules[currentRuleTag];
          } else {
              outp = new KRuleOutput(currentRuleTag, currentRuleSeverity,
                                     currentRuleASTScope, currentRuleCause, currentRuleExplanation);
          }
          /*
           * NEEDS MOAR WORK
           * kolla upp hur node sätts på tillbaka vägen
           * borde kanske inte använda oldNode för att skriva tillbaka
           * för att kunna komma åt var det bråkar
           */
          outp->addCodeOccurrance(CodeOccurrance(*(getSource(node).string()),
                                                 filename,
                                                 node->firstSourceLocation().startLine,
                                                 node->firstSourceLocation().startColumn));
          failedRules.insert(currentRuleTag, outp);
      }
  }
  catch(NotImplemented &) {}
}

const QStringRef KRuleVisitor::printable(const SourceLocation &start, const SourceLocation &end) {
    return QStringRef(&code, start.offset, end.offset + end.length - start.offset);
}

const QStringRef KRuleVisitor::getSource(const QQmlJS::AST::Node *exp) {
    const SourceLocation start = exp->firstSourceLocation();
    const SourceLocation end = exp->firstSourceLocation();
    return printable(start, end);
}

void KRuleVisitor::visitASTGlobally(ASTGlobally *astglobally) {
}

void KRuleVisitor::visitASTFile(ASTFile *astfile) {
}

void KRuleVisitor::visitASTImported(ASTImported *astimported) {
}

void KRuleVisitor::visitRCLang(RCLang *rclang) {
}

void KRuleVisitor::visitRCPolicy(RCPolicy *rcpolicy) {
}

void KRuleVisitor::visitExplan(Explan *explan) {
  visitString(explan->string_);
}

void KRuleVisitor::visitNoexplan(Noexplan *noexplan) {
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

void KRuleVisitor::visitAll(All *all){
    overPaths = "A";
    all->pathspecific_->accept(this);
}

void KRuleVisitor::visitExist(Exist *exist) {
    overPaths = "E";
    exist->pathspecific_->accept(this);
}

void KRuleVisitor::visitFuture(Future *future) {
    future->expr_->accept(this);
    bool success = false;

    if (getBoolRet()) {
        success = true;
    } else {
        QList<QQmlJS::AST::Node*> childrn = children(node);
        if (!childrn.isEmpty()){
            QQmlJS::AST::Node *oldNode = node;
            bool breakCondition = false;
            foreach(QQmlJS::AST::Node *child, childrn) {
                node = child;
                visitFuture(future);
                node = oldNode;

                bool res = getBoolRet();
                if ((overPaths == "A" && !res) ||( overPaths == "E" && res)) {
                        breakCondition = true;
                        break;
                }
            }
            if (overPaths == "A") {
                success = breakCondition ? false : true;
            } else if (overPaths == "E") {
                success = breakCondition ? true : false;
            }
        } else {
            success = false;
        }
    }

    changeRet(new RetTypeBool(success));
}

void KRuleVisitor::visitGlobally(Globally *globally) {
    globally->expr_->accept(this);
    bool success = false;

    if (!getBoolRet()) {
        success = false;
    } else {
        QList<QQmlJS::AST::Node*> childrn = children(node);
        if (!childrn.isEmpty()) {
            QQmlJS::AST::Node *oldNode = node;
            bool breakCondition = false;
            foreach(QQmlJS::AST::Node *child, childrn) {
                node = child;
                visitGlobally(globally);
                node = oldNode;

                bool res = getBoolRet();
                if ((overPaths == "A" && !res) ||( overPaths == "E" && res)) {
                        breakCondition = true;
                        break;
                }
            }
            if (overPaths == "A") {
                success = breakCondition ? false : true;
            } else if (overPaths == "E") {
                success = breakCondition ? true : false;
            }

        } else {
            success = true;
        }
    }

    changeRet(new RetTypeBool(success));
}

void KRuleVisitor::visitUntil(Until *until) {
    until->expr_1->accept(this);
    bool r1 = getBoolRet();
    until->expr_2->accept(this);
    bool r2 = getBoolRet();
    bool success = false;

    if (r2) {
        success = true;
    } else {
        if (r1) {
            QList<QQmlJS::AST::Node*> childrn = children(node);
            if (!childrn.isEmpty()) {
                QQmlJS::AST::Node *oldNode = node;
                bool breakCondition = false;
                foreach(QQmlJS::AST::Node *child, childrn) {
                    node = child;
                    visitUntil(until);
                    node = oldNode;

                    bool res = getBoolRet();
                    if ((overPaths == "A" && !res) ||( overPaths == "E" && res)) {
                            breakCondition = true;
                            break;
                    }
                }
                if (overPaths == "A") {
                    success = breakCondition ? false : true;
                } else if (overPaths == "E") {
                    success = breakCondition ? true : false;
                }
            } else {
                success = false;
            }
        } else {
            success = false;
        }
    }

    changeRet(new RetTypeBool(success));
}

void KRuleVisitor::visitNext(Next *next) {
    bool success = true;

    QList<QQmlJS::AST::Node*> childrn = children(node);
    if (!childrn.isEmpty()) {
        QQmlJS::AST::Node *oldNode = node;
        bool breakCondition = false;
        foreach(QQmlJS::AST::Node *child, childrn) {
            node = child;
            next->expr_->accept(this);
            node = oldNode;

            bool res = getBoolRet();
            if ((overPaths == "A" && !res) ||( overPaths == "E" && res)) {
                    breakCondition = true;
                    break;
            }
        }
        if (overPaths == "A") {
            success = breakCondition ? false : true;
        } else if (overPaths == "E") {
            success = breakCondition ? true : false;
        }
    } else {
        success = false;
    }

    changeRet(new RetTypeBool(success));
}

void KRuleVisitor::visitIEInt(IEInt *ieint) {
  visitInteger(ieint->integer_);
}

void KRuleVisitor::visitIENrChildren(IENrChildren *ienrchildren) {
}

void KRuleVisitor::visitIELtEq(IELtEq *ielteq) {
  throw NotImplemented();
  ielteq->iexpr_->accept(this);
  ielteq->istmnt_->accept(this);
}

void KRuleVisitor::visitIEGtEq(IEGtEq *iegteq) {
  throw NotImplemented();
  iegteq->iexpr_->accept(this);
  iegteq->istmnt_->accept(this);
}

void KRuleVisitor::visitIELt(IELt *ielt) {
  throw NotImplemented();
  ielt->iexpr_->accept(this);
  ielt->istmnt_->accept(this);
}

void KRuleVisitor::visitIEGt(IEGt *iegt) {
  throw NotImplemented();
  iegt->iexpr_->accept(this);
  iegt->istmnt_->accept(this);
}

void KRuleVisitor::visitIEq(IEq *ieq) {
  throw NotImplemented();
  ieq->istmnt_1->accept(this);
  ieq->istmnt_2->accept(this);
}

void KRuleVisitor::visitIEStmnt(IEStmnt *iestmnt) {
  throw NotImplemented();
  iestmnt->istmnt_->accept(this);
}

void KRuleVisitor::visitETrue(ETrue *) {
    changeRet(new RetTypeBool(true));
}

void KRuleVisitor::visitEFalse(EFalse *) {
    changeRet(new RetTypeBool(false));
}

void KRuleVisitor::visitENodeVal(ENodeVal *enodeval) {
  visitString(enodeval->string_);
  bool s = false;

  QRegExp regexp = QRegExp(getStringRet());
  QString nodeCode;

  nodeCode = getSource(node).toString();
  qDebug() << nodeCode;

  if (regexp.exactMatch(nodeCode)) {
      s = true;
  }
  changeRet(new RetTypeBool(s));
}

void KRuleVisitor::visitEType(EType *etype) {
  throw NotImplemented();
  etype->type_->accept(this);
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

void KRuleVisitor::visitEIExpr(EIExpr *eiexpr) {
  eiexpr->iexpr_->accept(this);
}

void KRuleVisitor::visitEEq(EEq *eeq){
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

void KRuleVisitor::visitEOverPaths(EOverPaths *eoverpaths)
{
  eoverpaths->overpaths_->accept(this);
}

void KRuleVisitor::visitTType(TType *ttype) {
  visitString(ttype->string_);
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
    delete this->ret;
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
