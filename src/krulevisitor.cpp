#include "ParseException.h"
#include "krulevisitor.h"
#include <gen/Printer.H>
#include <QRegExp>
#include "QMLChildren.h"

RetType* KRuleVisitor::visitRuleSet(RuleSet *) {} //abstract class
RetType* KRuleVisitor::visitRule(Rule *) {} //abstract class
RetType* KRuleVisitor::visitASTScope(ASTScope *) {} //abstract class
RetType* KRuleVisitor::visitRuleCause(RuleCause *) {} //abstract class
RetType* KRuleVisitor::visitExplanation(Explanation *) {} //abstract class
RetType* KRuleVisitor::visitTag(Tag *) {} //abstract class
RetType* KRuleVisitor::visitSeverity(Severity *) {} //abstract class
RetType* KRuleVisitor::visitIAtom(IAtom *) {} //abstract class
RetType* KRuleVisitor::visitSAtom(SAtom *) {} //abstract class
RetType* KRuleVisitor::visitExpr(Expr *) {} //abstract class
RetType* KRuleVisitor::visitPathQuantifier(PathQuantifier *) {}
RetType* KRuleVisitor::visitQuantifier(Quantifier *) {}


RetType* KRuleVisitor::visitRSet(RSet *rset) {
    return rset->listrule_->accept(this);
}

RetType* KRuleVisitor::visitRRule(RRule *rrule) {
    try {
        currentRuleTag = extractQString(rrule->tag_->accept(this));
        currentRuleSeverity = extractQString(rrule->severity_->accept(this));
        currentRuleCause = extractQString(rrule->rulecause_->accept(this));
        currentRuleASTScope = extractQString(rrule->astscope_->accept(this));
        currentRuleExplanation = extractQString(rrule->explanation_->accept(this));

        if (!extractBool(rrule->quantifier_->accept(this))) {
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
            outp->addCodeOccurrance(CodeOccurrance(node->getSource().toString(), filename,
                                                   node->getRow(),
                                                   node->getCol()));
            failedRules.insert(currentRuleTag, outp);
        }
    }
    catch(NotImplemented &) {}
}

const QStringRef KRuleVisitor::printable(const SourceLocation &start, const SourceLocation &end) {
    return QStringRef(&code, start.offset, end.offset + end.length - start.offset);
}

const QStringRef KRuleVisitor::getSource(const QQmlJS::AST::Node *exp) {
    return printable(exp->firstSourceLocation(), exp->lastSourceLocation());
}

RetType* KRuleVisitor::visitASTGlobally(ASTGlobally *) {
    return new RetTypeString(QString("Globally"));
}

RetType* KRuleVisitor::visitASTFile(ASTFile *) {
    return new RetTypeString(QString("File"));
}

RetType* KRuleVisitor::visitASTImported(ASTImported *) {
    return new RetTypeString(QString("Imported"));
}

RetType* KRuleVisitor::visitRCLang(RCLang *) {
    return new RetTypeString(QString("Language restriction"));
}

RetType* KRuleVisitor::visitRCPolicy(RCPolicy *) {
    return new RetTypeString(QString("Policy"));
}

RetType* KRuleVisitor::visitExplan(Explan *explan) {
    return new RetTypeString(QString(explan->string_.c_str()));
}

RetType* KRuleVisitor::visitNoexplan(Noexplan *) {
    return new RetTypeBool(false);
}

RetType* KRuleVisitor::visitTTag(TTag *ttag) {
    return new RetTypeString(QString(ttag->string_.c_str()));
}

RetType* KRuleVisitor::visitSevInfo(SevInfo *) {
    return new RetTypeString(QString("Info"));
}

RetType* KRuleVisitor::visitSevWarning(SevWarning *) {
    return new RetTypeString(QString("Warning"));
}

RetType* KRuleVisitor::visitSevCritical(SevCritical *) {
    return new RetTypeString(QString("Critical"));
}

RetType* KRuleVisitor::visitQExpr(QExpr *exp) {
    return exp->expr_->accept(this);
}

RetType* KRuleVisitor::visitQFor(QFor *exp) {
    // TODO: For stuff here
    throw NotImplemented();
}

const bool KRuleVisitor::handleBreakCondition(const bool breakCondition) {
    return breakCondition ? true : false;
}

RetType* KRuleVisitor::visitAF(AF *p) {
    ENot *v = new ENot(new EPQ(new EG(new ENot(p->expr_->clone()))));
    RetType *r = v->accept(this);
    delete v;
    return r;
}

RetType* KRuleVisitor::visitAG(AG *p) {
    ENot *v = new ENot(new EPQ(new EF(new ENot(p->expr_->clone()))));
    RetType *r = v->accept(this);
    delete v;
    return r;
}

RetType* KRuleVisitor::visitAX(AX *p) {
    ENot *v = new ENot(new EPQ(new EX(new ENot(p->expr_->clone()))));
    RetType *r = v->accept(this);
    delete v;
    return r;
}

RetType* KRuleVisitor::visitAU(AU *p) {
    Expr *e1 = p->expr_1->clone();
    Expr *e2 = p->expr_2->clone();
    ENot *v = new ENot(new EPQ(new EU(new ENot(e2), new ENot(new EOr(e1, e2)))));
    RetType *r = v->accept(this);
    delete v;
    delete e1;
    delete e2;
    return r;
}

RetType* KRuleVisitor::visitEF(EF *p) {
    EU *v = new EU(new ETrue, p->expr_);
    RetType *r = v->accept(this);
    v->expr_2 = nullptr;
    delete v;
    return r;
}

/*
RetType* KRuleVisitor::visitEF(EF *ef) {
    bool success = false;

    if (extractBool(ef->expr_->accept(this))) {
        success = true;
    } else {
        QList<QQmlJS::AST::Node*> childrn = children(node);
        if (!childrn.isEmpty()){
            bool breakCondition = false;
            foreach(QQmlJS::AST::Node *child, childrn) {
                node = child;

                bool res = extractBool(visitEF(ef));
                if (res) {
                    breakCondition = true;
                    break;
                }
            }
            success = handleBreakCondition(breakCondition);
        } else {
            success = false;
        }
    }

    return new RetTypeBool(success);
}
*/

RetType* KRuleVisitor::visitEG(EG *eg) {
    bool success = false;

    if (!extractBool(eg->expr_->accept(this))) {
        success = false;
    } else {
        const QList<NodeWrapper*> childrn = node->getChildren();
        if (!childrn.isEmpty()) {
            bool breakCondition = false;
            foreach(NodeWrapper *child, childrn) {
                node = child;

                bool res = extractBool(visitEG(eg));
                if (res) {
                        breakCondition = true;
                        break;
                }
            }
            success = handleBreakCondition(breakCondition);

        } else {
            success = true;
        }
    }

    return new RetTypeBool(success);
}

RetType* KRuleVisitor::visitEU(EU *eu) {
    bool success = false;

    const bool result2 = extractBool(eu->expr_2->accept(this));
    if (result2) {
        success = true;
    } else {
        const bool result1 = extractBool(eu->expr_1->accept(this));
        if (result1) {
            const QList<NodeWrapper*> childrn = node->getChildren();
            if (!childrn.isEmpty()) {
                bool breakCondition = false;
                foreach(NodeWrapper *child, childrn) {
                    node = child;

                    bool res = extractBool(visitEU(eu));
                    if (res) {
                            breakCondition = true;
                            break;
                    }
                }
                success = handleBreakCondition(breakCondition);
            } else {
                success = false;
            }
        } else {
            success = false;
        }
    }

    return new RetTypeBool(success);
}

RetType* KRuleVisitor::visitEX(EX *ex) {
    bool success = true;

    const QList<NodeWrapper*> childrn = node->getChildren();
    if (!childrn.isEmpty()) {
        bool breakCondition = false;
        foreach(NodeWrapper *child, childrn) {
            node = child;
            bool res = extractBool(ex->expr_->accept(this));
            if (res) {
                    breakCondition = true;
                    break;
            }
        }
        success = handleBreakCondition(breakCondition);
    } else {
        success = false;
    }

    return new RetTypeBool(success);
}

RetType* KRuleVisitor::visitIInt(IInt *ieint) {
    return visitInteger(ieint->integer_);
}

RetType* KRuleVisitor::visitINrChildren(INrChildren *ienrchildren) {
    throw NotImplemented();
}

RetType* KRuleVisitor::visitIFRow(IFRow *) {
    // Todo: Check if in for quantifier and return the row currently quantified over
    // if not quantifying throw exception
    throw NotImplemented();
}

RetType* KRuleVisitor::visitIFCol(IFCol *) {
    // Todo: Check if in for quantifier and return the col currently quantified over
    // if not quantifying throw exception
    throw NotImplemented();
}

RetType* KRuleVisitor::visitIRow(IRow *) {
    return new RetTypeUInt(node->getRow());
}

RetType* KRuleVisitor::visitICol(ICol *) {
    return new RetTypeUInt(node->getCol());
}

RetType* KRuleVisitor::visitEILtEq(EILtEq *ielteq) {
    quint32 i1 = extractUInt(ielteq->iatom_1->accept(this));
    quint32 i2 = extractUInt(ielteq->iatom_2->accept(this));
    return new RetTypeBool(i1 <= i2);
}

RetType* KRuleVisitor::visitEIGtEq(EIGtEq *iegteq) {
    quint32 i1 = extractUInt(iegteq->iatom_1->accept(this));
    quint32 i2 = extractUInt(iegteq->iatom_2->accept(this));
    return new RetTypeBool(i1 >= i2);
}

RetType* KRuleVisitor::visitEILt(EILt *ielt) {
    quint32 i1 = extractUInt(ielt->iatom_1->accept(this));
    quint32 i2 = extractUInt(ielt->iatom_2->accept(this));
    return new RetTypeBool(i1 < i2);
}

RetType* KRuleVisitor::visitEIGt(EIGt *iegt) {
    quint32 i1 = extractUInt(iegt->iatom_1->accept(this));
    quint32 i2 = extractUInt(iegt->iatom_2->accept(this));
    return new RetTypeBool(i1 > i2);
}

RetType* KRuleVisitor::visitEIEq(EIEq *ieq) {
    quint32 i1 = extractUInt(ieq->iatom_1->accept(this));
    quint32 i2 = extractUInt(ieq->iatom_2->accept(this));
    return new RetTypeBool(i1 == i2);
}

RetType* KRuleVisitor::visitETrue(ETrue *) {
    return new RetTypeBool(true);
}

RetType* KRuleVisitor::visitEFalse(EFalse *) {
    return new RetTypeBool(false);
}

RetType* KRuleVisitor::visitSValue(SValue *) {
    return new RetTypeString(node->getValue());
}

RetType* KRuleVisitor::visitSValueType(SValueType *) {
    return new RetTypeString(node->getValueType());
}

RetType* KRuleVisitor::visitSNodeType(SNodeType *) {
    return new RetTypeString(node->getNodeType());
}

RetType* KRuleVisitor::visitSString(SString *exp) {
    return new RetTypeString(QString(exp->string_.c_str()));
}

RetType* KRuleVisitor::visitSFValue(SFValue *exp) {
    // Todo: Check if in for quantifier and return the value currently quantified over
    // if not quantifying throw exception
    throw NotImplemented();
}

RetType* KRuleVisitor::visitSConcat(SConcat *exp) {
    QString s1 = extractQString(exp->satom_1->accept(this));
    QString s2 = extractQString(exp->satom_2->accept(this));
    return new RetTypeString(s1 + s2);
}

RetType* KRuleVisitor::visitEPossToken(EPossToken *exp) {
    throw NotImplemented();
}

RetType* KRuleVisitor::visitEExistToken(EExistToken *exp) {
    throw NotImplemented();
}

RetType* KRuleVisitor::visitEMatch(EMatch *exp) {
    bool s = false;

    QRegExp regexp = QRegExp(QString(exp->string_.c_str()));
    QString toMatch = extractQString(exp->satom_->accept(this));
    if (regexp.exactMatch(toMatch)) {
        s = true;
    }
    qDebug() << regexp.pattern() << " ? " << node->getValue() << s;
    return new RetTypeBool(s);
}

RetType* KRuleVisitor::visitESEq(ESEq *exp) {

    QString s1 = extractQString(exp->satom_1->accept(this));
    QString s2 = extractQString(exp->satom_2->accept(this));

    return new RetTypeBool(s1 == s2);
}

RetType* KRuleVisitor::visitEParant(EParant *eparant) {
    return eparant->expr_->accept(this);
}

RetType* KRuleVisitor::visitENot(ENot *enot) {
    return new RetTypeBool(!extractBool(enot->expr_->accept(this)));
}

RetType* KRuleVisitor::visitEImpl(EImpl *eimpl) {
    const bool leftExpression = extractBool(eimpl->expr_1->accept(this));
    bool rtBool;
    if (leftExpression == true) {
        const bool rightExpression = extractBool(eimpl->expr_2->accept(this));
        rtBool = rightExpression == true;
    } else {
        rtBool = true;
    }
    return new RetTypeBool(rtBool);
}

RetType* KRuleVisitor::visitEBEq(EBEq *eeq){
    const bool b1 = extractBool(eeq->expr_1->accept(this));
    const bool b2 = extractBool(eeq->expr_2->accept(this));
    return new RetTypeBool(b1 == b2);
}

RetType* KRuleVisitor::visitEAnd(EAnd *eand) {
    const bool b1 = extractBool(eand->expr_1->accept(this));
    const bool b2 = extractBool(eand->expr_2->accept(this));
    return new RetTypeBool(b1 && b2);
}

RetType* KRuleVisitor::visitEOr(EOr *eor) {
    const bool b1 = extractBool(eor->expr_1->accept(this));
    const bool b2 = extractBool(eor->expr_2->accept(this));
    return new RetTypeBool(b1 || b2);
}

RetType* KRuleVisitor::visitEPQ(EPQ *epq) {
    return epq->pathquantifier_->accept(this);
}

/**
 * @brief KRuleVisitor::visitListRule Iterates over the defined rules.
 * @param listrule
 * @return
 */
RetType* KRuleVisitor::visitListRule(ListRule* listrule) {
    for (ListRule::iterator i = listrule->begin() ; i != listrule->end() ; ++i) {
      (*i)->accept(this);
    }
    return nullptr;
}

// Not sure if this is actually needed ... maybe delete this?
RetType* KRuleVisitor::visitListExpr(ListExpr* listexpr) {
    for (ListExpr::iterator i = listexpr->begin() ; i != listexpr->end() ; ++i) {
      (*i)->accept(this);
    }
    return nullptr;
}


RetType* KRuleVisitor::visitInteger(Integer x) {
    return new RetTypeUInt((quint32)x);
}

RetType* KRuleVisitor::visitString(String x) {
    return new RetTypeString(QString(x.c_str()));
}

QMap<QString, KRuleOutput*> KRuleVisitor::getFailures() {
    return failedRules;
}

void KRuleVisitor::assertType(RetType* ret, RetType::RetTypeE type) {
    if (ret == nullptr || ret->getType() != type) {
        throw BadType();
    }
}

/**
 * @brief KRuleVisitor::extractBool Tries to extract boolean data from the provided RetType.
 *
 * Tries to extract boolean data from the provided RetType.
 * If this is successfull then the pointer will be deleted.
 * Else if this is not possible BadType will be thrown.
 *
 * @param ret The RetType to extract data from and finally delete.
 * @return The extracted boolean data.
 * @throws BadType if the provided RetType does not contain boolean data.
 */
const bool KRuleVisitor::extractBool(RetType *ret) {
    assertType(ret, RetType::RetTypeE::RBool);
    const bool b = ((RetTypeBool*)ret)->getData();
    delete ret;
    return b;
}

/**
 * @brief KRuleVisitor::extractQString Tries to extract QString data from the provided RetType.
 *
 * Tries to extract QString data from the provided RetType.
 * If this is successfull then the pointer will be deleted.
 * Else if this is not possible BadType will be thrown.
 *
 * @param ret The RetType to extract data from and finally delete.
 * @return The extracted QString data.
 * @throws BadType if the provided RetType does not contain QString data.
 */
const QString KRuleVisitor::extractQString(RetType *ret) {
    assertType(ret, RetType::RetTypeE::RString);
    const QString str = ((RetTypeString*)ret)->getData();
    delete ret;
    return str;
}

/**
 * @brief KRuleVisitor::extractUInt Tries to extract 32 bits unsigned integer data from the provided RetType.
 *
 * Tries to extract 32 bits unsigned integer data from the provided RetType.
 * If this is successfull then the pointer will be deleted.
 * Else if this is not possible BadType will be thrown.
 *
 * @param ret The RetType to extract data from and finally delete.
 * @return The extracted 32 bit unsigned integer.
 * @throws BadType if the provided RetType does not contain an integer.
 */
const quint32 KRuleVisitor::extractUInt(RetType *ret) {
    assertType(ret, RetType::RetTypeE::RInt);
    const quint32 i = ((RetTypeUInt*)ret)->getData();
    delete ret;
    return i;
}
