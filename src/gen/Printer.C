// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0

/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include <string>
#include "Printer.H"
#define INDENT_WIDTH 2


//You may wish to change render
void PrintAbsyn::render(Char c)
{
  if (c == '{')
  {
     bufAppend('\n');
     indent();
     bufAppend(c);
     _n_ = _n_ + INDENT_WIDTH;
     bufAppend('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppend(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppend(c);
  }
  else if (c == '}')
  {
     int t;
     _n_ = _n_ - INDENT_WIDTH;
     for (t=0; t<INDENT_WIDTH; t++) {
       backup();
     }
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppend(' ');
     bufAppend(c);
     bufAppend(' ');
  }
}
void PrintAbsyn::render(String s_)
{
  const char *s = s_.c_str() ;
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::render(char* s)
{
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::indent()
{
  int n = _n_;
  while (n > 0)
  {
    bufAppend(' ');
    n--;
  }
}
void PrintAbsyn::backup()
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
PrintAbsyn::PrintAbsyn(void)
{
  _i_ = 0; _n_ = 0;
  buf_ = 0;
  bufReset();
}

PrintAbsyn::~PrintAbsyn(void)
{
}

char* PrintAbsyn::print(Visitable *v)
{
  _i_ = 0; _n_ = 0;
  bufReset();
  v->accept(this);
  return buf_;
}
QPointer<RetType> PrintAbsyn::visitRuleSet(RuleSet*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitRSet(RSet* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listrule_) {_i_ = 0; p->listrule_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitRule(Rule*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitRRule(RRule* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->tag_->accept(this);
  _i_ = 0; p->severity_->accept(this);
  _i_ = 0; p->rulecause_->accept(this);
  _i_ = 0; p->astscope_->accept(this);
  _i_ = 0; p->explanation_->accept(this);
  render("::");
  _i_ = 0; p->expr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitASTScope(ASTScope*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitASTGlobally(ASTGlobally* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Globally");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitASTFile(ASTFile* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("File");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitASTImported(ASTImported* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Imported");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitRuleCause(RuleCause*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitRCLang(RCLang* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Language");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitRCPolicy(RCPolicy* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Policy");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitExplanation(Explanation*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitExplan(Explan* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("??");
  visitString(p->string_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitNoexplan(Noexplan* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitListRule(ListRule *listrule)
{
  for (ListRule::const_iterator i = listrule->begin() ; i != listrule->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}QPointer<RetType> PrintAbsyn::visitTag(Tag*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitTTag(TTag* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitString(p->string_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitSeverity(Severity*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitSevInfo(SevInfo* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Info");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitSevWarning(SevWarning* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Warning");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitSevCritical(SevCritical* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("Critical");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitPathQuantifier(PathQuantifier*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitAG(AG* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("AG");
  _i_ = 0; p->expr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitAF(AF* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("AF");
  _i_ = 0; p->expr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitAX(AX* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("AX");
  _i_ = 0; p->expr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitAU(AU* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('A');
  _i_ = 0; p->expr_1->accept(this);
  render('U');
  _i_ = 0; p->expr_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEG(EG* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("EG");
  _i_ = 0; p->expr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEF(EF* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("EF");
  _i_ = 0; p->expr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEX(EX* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("EX");
  _i_ = 0; p->expr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEU(EU* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('E');
  _i_ = 0; p->expr_1->accept(this);
  render('U');
  _i_ = 0; p->expr_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitIAtom(IAtom*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitINrChildren(INrChildren* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  render("nrChildren");

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitIRow(IRow* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  render("row");

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitICol(ICol* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  render("col");

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitIQuant(IQuant* p)
{
  int oldi = _i_;
  if (oldi > 1) render(_L_PAREN);

  visitIdent(p->ident_);
  render('.');
  _i_ = 2; p->iatom_->accept(this);

  if (oldi > 1) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitIInt(IInt* p)
{
  int oldi = _i_;
  if (oldi > 1) render(_L_PAREN);

  visitInteger(p->integer_);

  if (oldi > 1) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitSAtom(SAtom*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitSValue(SValue* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  render("value");

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitSValueType(SValueType* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  render("valueType");

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitSNodeType(SNodeType* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  render("nodeType");

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitSQuant(SQuant* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  visitIdent(p->ident_);
  render('.');
  _i_ = 3; p->satom_->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitSString(SString* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  visitString(p->string_);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitSConcat(SConcat* p)
{
  int oldi = _i_;
  if (oldi > 1) render(_L_PAREN);

  _i_ = 1; p->satom_1->accept(this);
  render('+');
  _i_ = 2; p->satom_2->accept(this);

  if (oldi > 1) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitExpr(Expr*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitETrue(ETrue* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("True");

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEFalse(EFalse* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("False");

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEParant(EParant* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render('(');
  _i_ = 0; p->expr_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitENot(ENot* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  render('!');
  _i_ = 10; p->expr_->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEBEq(EBEq* p)
{
  int oldi = _i_;
  if (oldi > 7) render(_L_PAREN);

  _i_ = 7; p->expr_1->accept(this);
  render('=');
  _i_ = 8; p->expr_2->accept(this);

  if (oldi > 7) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEPossToken(EPossToken* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  visitString(p->string_);
  render("is");
  render("possible");
  render("token");

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEExistToken(EExistToken* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  visitString(p->string_);
  render("is");
  render("existing");
  render("token");

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEILtEq(EILtEq* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 0; p->iatom_1->accept(this);
  render("<=");
  _i_ = 0; p->iatom_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEIGtEq(EIGtEq* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 0; p->iatom_1->accept(this);
  render(">=");
  _i_ = 0; p->iatom_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEILt(EILt* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 0; p->iatom_1->accept(this);
  render('<');
  _i_ = 0; p->iatom_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEIGt(EIGt* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 0; p->iatom_1->accept(this);
  render('>');
  _i_ = 0; p->iatom_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEIEq(EIEq* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 0; p->iatom_1->accept(this);
  render('=');
  _i_ = 0; p->iatom_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEMatch(EMatch* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 0; p->satom_->accept(this);
  render("match");
  visitString(p->string_);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitESEq(ESEq* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 0; p->satom_1->accept(this);
  render('=');
  _i_ = 0; p->satom_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEAnd(EAnd* p)
{
  int oldi = _i_;
  if (oldi > 4) render(_L_PAREN);

  _i_ = 4; p->expr_1->accept(this);
  render('&');
  _i_ = 5; p->expr_2->accept(this);

  if (oldi > 4) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEOr(EOr* p)
{
  int oldi = _i_;
  if (oldi > 4) render(_L_PAREN);

  _i_ = 4; p->expr_1->accept(this);
  render('|');
  _i_ = 5; p->expr_2->accept(this);

  if (oldi > 4) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEForAllQ(EForAllQ* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  render("forAll");
  visitIdent(p->ident_);
  render("in");
  if(p->listfilter_) {_i_ = 0; p->listfilter_->accept(this);}  render(':');
  _i_ = 0; p->expr_->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEExistQ(EExistQ* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  render("exist");
  visitIdent(p->ident_);
  render("in");
  if(p->listfilter_) {_i_ = 0; p->listfilter_->accept(this);}  render(':');
  _i_ = 0; p->expr_->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEPQ(EPQ* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 0; p->pathquantifier_->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitEImpl(EImpl* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 2; p->expr_1->accept(this);
  render("->");
  _i_ = 3; p->expr_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitListExpr(ListExpr *listexpr)
{
  for (ListExpr::const_iterator i = listexpr->begin() ; i != listexpr->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}QPointer<RetType> PrintAbsyn::visitFilter(Filter*p) {} //abstract class

QPointer<RetType> PrintAbsyn::visitFString(FString* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitString(p->string_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

QPointer<RetType> PrintAbsyn::visitListFilter(ListFilter *listfilter)
{
  for (ListFilter::const_iterator i = listfilter->begin() ; i != listfilter->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listfilter->end() - 1) render('.');
  }
}QPointer<RetType> PrintAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
QPointer<RetType> PrintAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
QPointer<RetType> PrintAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
QPointer<RetType> PrintAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
QPointer<RetType> PrintAbsyn::visitIdent(String s)
{
  render(s);
}

ShowAbsyn::ShowAbsyn(void)
{
  buf_ = 0;
  bufReset();
}

ShowAbsyn::~ShowAbsyn(void)
{
}

char* ShowAbsyn::show(Visitable *v)
{
  bufReset();
  v->accept(this);
  return buf_;
}
QPointer<RetType> ShowAbsyn::visitRuleSet(RuleSet* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitRSet(RSet* p)
{
  bufAppend('(');
  bufAppend("RSet");
  bufAppend(' ');
  bufAppend('[');
  if (p->listrule_)  p->listrule_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitRule(Rule* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitRRule(RRule* p)
{
  bufAppend('(');
  bufAppend("RRule");
  bufAppend(' ');
  bufAppend('[');
  if (p->tag_)  p->tag_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->severity_)  p->severity_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->rulecause_)  p->rulecause_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->astscope_)  p->astscope_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->explanation_)  p->explanation_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitASTScope(ASTScope* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitASTGlobally(ASTGlobally* p)
{
  bufAppend("ASTGlobally");
}
QPointer<RetType> ShowAbsyn::visitASTFile(ASTFile* p)
{
  bufAppend("ASTFile");
}
QPointer<RetType> ShowAbsyn::visitASTImported(ASTImported* p)
{
  bufAppend("ASTImported");
}
QPointer<RetType> ShowAbsyn::visitRuleCause(RuleCause* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitRCLang(RCLang* p)
{
  bufAppend("RCLang");
}
QPointer<RetType> ShowAbsyn::visitRCPolicy(RCPolicy* p)
{
  bufAppend("RCPolicy");
}
QPointer<RetType> ShowAbsyn::visitExplanation(Explanation* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitExplan(Explan* p)
{
  bufAppend('(');
  bufAppend("Explan");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitNoexplan(Noexplan* p)
{
  bufAppend("Noexplan");
}
QPointer<RetType> ShowAbsyn::visitListRule(ListRule *listrule)
{
  for (ListRule::const_iterator i = listrule->begin() ; i != listrule->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listrule->end() - 1) bufAppend(", ");
  }
}

QPointer<RetType> ShowAbsyn::visitTag(Tag* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitTTag(TTag* p)
{
  bufAppend('(');
  bufAppend("TTag");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitSeverity(Severity* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitSevInfo(SevInfo* p)
{
  bufAppend("SevInfo");
}
QPointer<RetType> ShowAbsyn::visitSevWarning(SevWarning* p)
{
  bufAppend("SevWarning");
}
QPointer<RetType> ShowAbsyn::visitSevCritical(SevCritical* p)
{
  bufAppend("SevCritical");
}
QPointer<RetType> ShowAbsyn::visitPathQuantifier(PathQuantifier* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitAG(AG* p)
{
  bufAppend('(');
  bufAppend("AG");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitAF(AF* p)
{
  bufAppend('(');
  bufAppend("AF");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitAX(AX* p)
{
  bufAppend('(');
  bufAppend("AX");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitAU(AU* p)
{
  bufAppend('(');
  bufAppend("AU");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEG(EG* p)
{
  bufAppend('(');
  bufAppend("EG");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEF(EF* p)
{
  bufAppend('(');
  bufAppend("EF");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEX(EX* p)
{
  bufAppend('(');
  bufAppend("EX");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEU(EU* p)
{
  bufAppend('(');
  bufAppend("EU");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitIAtom(IAtom* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitINrChildren(INrChildren* p)
{
  bufAppend("INrChildren");
}
QPointer<RetType> ShowAbsyn::visitIRow(IRow* p)
{
  bufAppend("IRow");
}
QPointer<RetType> ShowAbsyn::visitICol(ICol* p)
{
  bufAppend("ICol");
}
QPointer<RetType> ShowAbsyn::visitIQuant(IQuant* p)
{
  bufAppend('(');
  bufAppend("IQuant");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->iatom_)  p->iatom_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitIInt(IInt* p)
{
  bufAppend('(');
  bufAppend("IInt");
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitSAtom(SAtom* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitSValue(SValue* p)
{
  bufAppend("SValue");
}
QPointer<RetType> ShowAbsyn::visitSValueType(SValueType* p)
{
  bufAppend("SValueType");
}
QPointer<RetType> ShowAbsyn::visitSNodeType(SNodeType* p)
{
  bufAppend("SNodeType");
}
QPointer<RetType> ShowAbsyn::visitSQuant(SQuant* p)
{
  bufAppend('(');
  bufAppend("SQuant");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->satom_)  p->satom_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitSString(SString* p)
{
  bufAppend('(');
  bufAppend("SString");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitSConcat(SConcat* p)
{
  bufAppend('(');
  bufAppend("SConcat");
  bufAppend(' ');
  p->satom_1->accept(this);
  bufAppend(' ');
  p->satom_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitExpr(Expr* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitETrue(ETrue* p)
{
  bufAppend("ETrue");
}
QPointer<RetType> ShowAbsyn::visitEFalse(EFalse* p)
{
  bufAppend("EFalse");
}
QPointer<RetType> ShowAbsyn::visitEParant(EParant* p)
{
  bufAppend('(');
  bufAppend("EParant");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitENot(ENot* p)
{
  bufAppend('(');
  bufAppend("ENot");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEBEq(EBEq* p)
{
  bufAppend('(');
  bufAppend("EBEq");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEPossToken(EPossToken* p)
{
  bufAppend('(');
  bufAppend("EPossToken");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(' ');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEExistToken(EExistToken* p)
{
  bufAppend('(');
  bufAppend("EExistToken");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(' ');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEILtEq(EILtEq* p)
{
  bufAppend('(');
  bufAppend("EILtEq");
  bufAppend(' ');
  p->iatom_1->accept(this);
  bufAppend(' ');
  p->iatom_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEIGtEq(EIGtEq* p)
{
  bufAppend('(');
  bufAppend("EIGtEq");
  bufAppend(' ');
  p->iatom_1->accept(this);
  bufAppend(' ');
  p->iatom_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEILt(EILt* p)
{
  bufAppend('(');
  bufAppend("EILt");
  bufAppend(' ');
  p->iatom_1->accept(this);
  bufAppend(' ');
  p->iatom_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEIGt(EIGt* p)
{
  bufAppend('(');
  bufAppend("EIGt");
  bufAppend(' ');
  p->iatom_1->accept(this);
  bufAppend(' ');
  p->iatom_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEIEq(EIEq* p)
{
  bufAppend('(');
  bufAppend("EIEq");
  bufAppend(' ');
  p->iatom_1->accept(this);
  bufAppend(' ');
  p->iatom_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEMatch(EMatch* p)
{
  bufAppend('(');
  bufAppend("EMatch");
  bufAppend(' ');
  bufAppend('[');
  if (p->satom_)  p->satom_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitESEq(ESEq* p)
{
  bufAppend('(');
  bufAppend("ESEq");
  bufAppend(' ');
  p->satom_1->accept(this);
  bufAppend(' ');
  p->satom_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEAnd(EAnd* p)
{
  bufAppend('(');
  bufAppend("EAnd");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEOr(EOr* p)
{
  bufAppend('(');
  bufAppend("EOr");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEForAllQ(EForAllQ* p)
{
  bufAppend('(');
  bufAppend("EForAllQ");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listfilter_)  p->listfilter_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEExistQ(EExistQ* p)
{
  bufAppend('(');
  bufAppend("EExistQ");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listfilter_)  p->listfilter_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEPQ(EPQ* p)
{
  bufAppend('(');
  bufAppend("EPQ");
  bufAppend(' ');
  bufAppend('[');
  if (p->pathquantifier_)  p->pathquantifier_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitEImpl(EImpl* p)
{
  bufAppend('(');
  bufAppend("EImpl");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitListExpr(ListExpr *listexpr)
{
  for (ListExpr::const_iterator i = listexpr->begin() ; i != listexpr->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexpr->end() - 1) bufAppend(", ");
  }
}

QPointer<RetType> ShowAbsyn::visitFilter(Filter* p) {} //abstract class

QPointer<RetType> ShowAbsyn::visitFString(FString* p)
{
  bufAppend('(');
  bufAppend("FString");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
QPointer<RetType> ShowAbsyn::visitListFilter(ListFilter *listfilter)
{
  for (ListFilter::const_iterator i = listfilter->begin() ; i != listfilter->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listfilter->end() - 1) bufAppend(", ");
  }
}

QPointer<RetType> ShowAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
QPointer<RetType> ShowAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
QPointer<RetType> ShowAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
QPointer<RetType> ShowAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
QPointer<RetType> ShowAbsyn::visitIdent(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


