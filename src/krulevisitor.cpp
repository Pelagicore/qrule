#include "ParseException.h"
#include "krulevisitor.h"
#include <gen/Printer.H>
#include <QRegExp>
#include "QMLChildren.h"

RetType* KRuleVisitor::visitRuleSet(RuleSet* t) {} //abstract class
RetType* KRuleVisitor::visitRule(Rule* t) {} //abstract class
RetType* KRuleVisitor::visitASTScope(ASTScope* t) {} //abstract class
RetType* KRuleVisitor::visitRuleCause(RuleCause* t) {} //abstract class
RetType* KRuleVisitor::visitExplanation(Explanation* t) {} //abstract class
RetType* KRuleVisitor::visitTag(Tag* t) {} //abstract class
RetType* KRuleVisitor::visitSeverity(Severity* t) {} //abstract class
RetType* KRuleVisitor::visitOverPaths(OverPaths* t) {} //abstract class
RetType* KRuleVisitor::visitPathSpecific(PathSpecific* t) {} //abstract class
RetType* KRuleVisitor::visitIStmnt(IStmnt* t) {} //abstract class
RetType* KRuleVisitor::visitIExpr(IExpr* t) {} //abstract class
RetType* KRuleVisitor::visitExpr(Expr* t) {} //abstract class
RetType* KRuleVisitor::visitType(Type* t) {} //abstract class
RetType* KRuleVisitor::visitParam(Param* t) {} //abstract class


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

        if (!extractBool(rrule->expr_->accept(this))) {
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
            outp->addCodeOccurrance(CodeOccurrance(getSource(node).toString(), filename,
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

RetType* KRuleVisitor::visitSevWarning(SevWarning *) {
    return new RetTypeString(QString("Warning"));
}

RetType* KRuleVisitor::visitSevCritical(SevCritical *) {
    return new RetTypeString(QString("Critical"));
}

RetType* KRuleVisitor::visitAll(All *all){
    overPaths = "A";
    return all->pathspecific_->accept(this);
}

RetType* KRuleVisitor::visitExist(Exist *exist) {
    overPaths = "E";
    return exist->pathspecific_->accept(this);
}

const bool KRuleVisitor::handleBreakCondition(const bool breakCondition) {
    if (overPaths == "A") {
        return breakCondition ? false : true;
    } else if (overPaths == "E") {
        return breakCondition ? true : false;
    } else {
        throw NotImplemented();
    }
}

RetType* KRuleVisitor::visitFuture(Future *future) {
    bool success = false;

    if (extractBool(future->expr_->accept(this))) {
        success = true;
    } else {
        QList<QQmlJS::AST::Node*> childrn = children(node);
        if (!childrn.isEmpty()){
            bool breakCondition = false;
            foreach(QQmlJS::AST::Node *child, childrn) {
                node = child;

                bool res = extractBool(visitFuture(future));
                if ((overPaths == "A" && !res) ||( overPaths == "E" && res)) {
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

RetType* KRuleVisitor::visitGlobally(Globally *globally) {
    bool success = false;

    if (!extractBool(globally->expr_->accept(this))) {
        success = false;
    } else {
        QList<QQmlJS::AST::Node*> childrn = children(node);
        if (!childrn.isEmpty()) {
            bool breakCondition = false;
            foreach(QQmlJS::AST::Node *child, childrn) {
                node = child;

                bool res = extractBool(visitGlobally(globally));
                if ((overPaths == "A" && !res) ||( overPaths == "E" && res)) {
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

RetType* KRuleVisitor::visitUntil(Until *until) {
    bool success = false;

    const bool result2 = extractBool(until->expr_2->accept(this));
    if (result2) {
        success = true;
    } else {
        const bool result1 = extractBool(until->expr_1->accept(this));
        if (result1) {
            QList<QQmlJS::AST::Node*> childrn = children(node);
            if (!childrn.isEmpty()) {
                bool breakCondition = false;
                foreach(QQmlJS::AST::Node *child, childrn) {
                    node = child;

                    bool res = extractBool(visitUntil(until));
                    if ((overPaths == "A" && !res) ||( overPaths == "E" && res)) {
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

RetType* KRuleVisitor::visitNext(Next *next) {
    bool success = true;

    QList<QQmlJS::AST::Node*> childrn = children(node);
    if (!childrn.isEmpty()) {
        bool breakCondition = false;
        foreach(QQmlJS::AST::Node *child, childrn) {
            node = child;
            bool res = extractBool(next->expr_->accept(this));
            if ((overPaths == "A" && !res) ||( overPaths == "E" && res)) {
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

RetType* KRuleVisitor::visitIEInt(IEInt *ieint) {
    return visitInteger(ieint->integer_);
}

RetType* KRuleVisitor::visitIENrChildren(IENrChildren *ienrchildren) {
    throw NotImplemented();
}

RetType* KRuleVisitor::visitIELtEq(IELtEq *ielteq) {
    quint32 i1 = extractUInt(ielteq->iexpr_->accept(this));
    quint32 i2 = extractUInt(ielteq->istmnt_->accept(this));
    return new RetTypeBool(i1 <= i2);
}

RetType* KRuleVisitor::visitIEGtEq(IEGtEq *iegteq) {
    quint32 i1 = extractUInt(iegteq->iexpr_->accept(this));
    quint32 i2 = extractUInt(iegteq->istmnt_->accept(this));
    return new RetTypeBool(i1 >= i2);
}

RetType* KRuleVisitor::visitIELt(IELt *ielt) {
    quint32 i1 = extractUInt(ielt->iexpr_->accept(this));
    quint32 i2 = extractUInt(ielt->istmnt_->accept(this));
    return new RetTypeBool(i1 < i2);
}

RetType* KRuleVisitor::visitIEGt(IEGt *iegt) {
    quint32 i1 = extractUInt(iegt->iexpr_->accept(this));
    quint32 i2 = extractUInt(iegt->istmnt_->accept(this));
    return new RetTypeBool(i1 > i2);
}

RetType* KRuleVisitor::visitIEq(IEq *ieq) {
    quint32 i1 = extractUInt(ieq->istmnt_1->accept(this));
    quint32 i2 = extractUInt(ieq->istmnt_2->accept(this));
    return new RetTypeBool(i1 == i2);
}

RetType* KRuleVisitor::visitIEStmnt(IEStmnt *iestmnt) {
    return iestmnt->istmnt_->accept(this);
}

RetType* KRuleVisitor::visitETrue(ETrue *) {
    return new RetTypeBool(true);
}

RetType* KRuleVisitor::visitEFalse(EFalse *) {
    return new RetTypeBool(false);
}

RetType* KRuleVisitor::visitENodeVal(ENodeVal *enodeval) {
    bool s = false;

    QRegExp regexp = QRegExp(QString(enodeval->string_.c_str()));
    QString nodeCode;

    nodeCode = getSource(node).toString();

    if (regexp.exactMatch(nodeCode)) {
        s = true;
    }
    qDebug() << regexp.pattern() << " ? " << nodeCode << s;
    return new RetTypeBool(s);
}

RetType* KRuleVisitor::visitEType(EType *etype) {
    throw NotImplemented();
    return etype->type_->accept(this);
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

RetType* KRuleVisitor::visitEIExpr(EIExpr *eiexpr) {
    return eiexpr->iexpr_->accept(this);
}

RetType* KRuleVisitor::visitEEq(EEq *eeq){
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

RetType* KRuleVisitor::visitEOverPaths(EOverPaths *eoverpaths) {
    return eoverpaths->overpaths_->accept(this);
}

RetType* KRuleVisitor::visitTType(TType *ttype) {
    return new RetTypeString(QString(ttype->string_.c_str()));
}

RetType* KRuleVisitor::visitPParam(PParam *pparam) {
    return new RetTypeString(QString(pparam->string_.c_str()));
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
