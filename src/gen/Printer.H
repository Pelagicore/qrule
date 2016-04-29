// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0

#ifndef PRINTER_HEADER
#define PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Certain applications may improve performance by changing the buffer size */
#define BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define _L_PAREN '('
#define _R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
void render(char* s);
  void indent(void);
  void backup(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char* print(Visitable* v);

  QPointer<RetType> visitRuleSet(RuleSet *p); /* abstract class */
  QPointer<RetType> visitRSet(RSet *p);
  QPointer<RetType> visitRule(Rule *p); /* abstract class */
  QPointer<RetType> visitRRule(RRule *p);
  QPointer<RetType> visitASTScope(ASTScope *p); /* abstract class */
  QPointer<RetType> visitASTGlobally(ASTGlobally *p);
  QPointer<RetType> visitASTFile(ASTFile *p);
  QPointer<RetType> visitASTImported(ASTImported *p);
  QPointer<RetType> visitRuleCause(RuleCause *p); /* abstract class */
  QPointer<RetType> visitRCLang(RCLang *p);
  QPointer<RetType> visitRCPolicy(RCPolicy *p);
  QPointer<RetType> visitExplanation(Explanation *p); /* abstract class */
  QPointer<RetType> visitExplan(Explan *p);
  QPointer<RetType> visitNoexplan(Noexplan *p);
  QPointer<RetType> visitListRule(ListRule* p);
  QPointer<RetType> visitTag(Tag *p); /* abstract class */
  QPointer<RetType> visitTTag(TTag *p);
  QPointer<RetType> visitSeverity(Severity *p); /* abstract class */
  QPointer<RetType> visitSevInfo(SevInfo *p);
  QPointer<RetType> visitSevWarning(SevWarning *p);
  QPointer<RetType> visitSevCritical(SevCritical *p);
  QPointer<RetType> visitPathQuantifier(PathQuantifier *p); /* abstract class */
  QPointer<RetType> visitAG(AG *p);
  QPointer<RetType> visitAF(AF *p);
  QPointer<RetType> visitAX(AX *p);
  QPointer<RetType> visitAU(AU *p);
  QPointer<RetType> visitEG(EG *p);
  QPointer<RetType> visitEF(EF *p);
  QPointer<RetType> visitEX(EX *p);
  QPointer<RetType> visitEU(EU *p);
  QPointer<RetType> visitIAtom(IAtom *p); /* abstract class */
  QPointer<RetType> visitIFRow(IFRow *p);
  QPointer<RetType> visitIFCol(IFCol *p);
  QPointer<RetType> visitIInt(IInt *p);
  QPointer<RetType> visitINrChildren(INrChildren *p);
  QPointer<RetType> visitIRow(IRow *p);
  QPointer<RetType> visitICol(ICol *p);
  QPointer<RetType> visitSAtom(SAtom *p); /* abstract class */
  QPointer<RetType> visitSString(SString *p);
  QPointer<RetType> visitSFValue(SFValue *p);
  QPointer<RetType> visitSValue(SValue *p);
  QPointer<RetType> visitSValueType(SValueType *p);
  QPointer<RetType> visitSNodeType(SNodeType *p);
  QPointer<RetType> visitSConcat(SConcat *p);
  QPointer<RetType> visitExpr(Expr *p); /* abstract class */
  QPointer<RetType> visitETrue(ETrue *p);
  QPointer<RetType> visitEFalse(EFalse *p);
  QPointer<RetType> visitEParant(EParant *p);
  QPointer<RetType> visitENot(ENot *p);
  QPointer<RetType> visitEBEq(EBEq *p);
  QPointer<RetType> visitEPossToken(EPossToken *p);
  QPointer<RetType> visitEExistToken(EExistToken *p);
  QPointer<RetType> visitEILtEq(EILtEq *p);
  QPointer<RetType> visitEIGtEq(EIGtEq *p);
  QPointer<RetType> visitEILt(EILt *p);
  QPointer<RetType> visitEIGt(EIGt *p);
  QPointer<RetType> visitEIEq(EIEq *p);
  QPointer<RetType> visitEMatch(EMatch *p);
  QPointer<RetType> visitESEq(ESEq *p);
  QPointer<RetType> visitEAnd(EAnd *p);
  QPointer<RetType> visitEOr(EOr *p);
  QPointer<RetType> visitEFirstOrdQ(EFirstOrdQ *p);
  QPointer<RetType> visitEPQ(EPQ *p);
  QPointer<RetType> visitEImpl(EImpl *p);
  QPointer<RetType> visitListExpr(ListExpr* p);
  QPointer<RetType> visitFilter(Filter *p); /* abstract class */
  QPointer<RetType> visitFString(FString *p);
  QPointer<RetType> visitListFilter(ListFilter* p);

  QPointer<RetType> visitInteger(Integer i);
  QPointer<RetType> visitDouble(Double d);
  QPointer<RetType> visitChar(Char c);
  QPointer<RetType> visitString(String s);
  QPointer<RetType> visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufAppend(String str)
  {
    const char* s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char* show(Visitable* v);

  QPointer<RetType> visitRuleSet(RuleSet *p); /* abstract class */
  QPointer<RetType> visitRSet(RSet *p);
  QPointer<RetType> visitRule(Rule *p); /* abstract class */
  QPointer<RetType> visitRRule(RRule *p);
  QPointer<RetType> visitASTScope(ASTScope *p); /* abstract class */
  QPointer<RetType> visitASTGlobally(ASTGlobally *p);
  QPointer<RetType> visitASTFile(ASTFile *p);
  QPointer<RetType> visitASTImported(ASTImported *p);
  QPointer<RetType> visitRuleCause(RuleCause *p); /* abstract class */
  QPointer<RetType> visitRCLang(RCLang *p);
  QPointer<RetType> visitRCPolicy(RCPolicy *p);
  QPointer<RetType> visitExplanation(Explanation *p); /* abstract class */
  QPointer<RetType> visitExplan(Explan *p);
  QPointer<RetType> visitNoexplan(Noexplan *p);
  QPointer<RetType> visitListRule(ListRule* p);
  QPointer<RetType> visitTag(Tag *p); /* abstract class */
  QPointer<RetType> visitTTag(TTag *p);
  QPointer<RetType> visitSeverity(Severity *p); /* abstract class */
  QPointer<RetType> visitSevInfo(SevInfo *p);
  QPointer<RetType> visitSevWarning(SevWarning *p);
  QPointer<RetType> visitSevCritical(SevCritical *p);
  QPointer<RetType> visitPathQuantifier(PathQuantifier *p); /* abstract class */
  QPointer<RetType> visitAG(AG *p);
  QPointer<RetType> visitAF(AF *p);
  QPointer<RetType> visitAX(AX *p);
  QPointer<RetType> visitAU(AU *p);
  QPointer<RetType> visitEG(EG *p);
  QPointer<RetType> visitEF(EF *p);
  QPointer<RetType> visitEX(EX *p);
  QPointer<RetType> visitEU(EU *p);
  QPointer<RetType> visitIAtom(IAtom *p); /* abstract class */
  QPointer<RetType> visitIFRow(IFRow *p);
  QPointer<RetType> visitIFCol(IFCol *p);
  QPointer<RetType> visitIInt(IInt *p);
  QPointer<RetType> visitINrChildren(INrChildren *p);
  QPointer<RetType> visitIRow(IRow *p);
  QPointer<RetType> visitICol(ICol *p);
  QPointer<RetType> visitSAtom(SAtom *p); /* abstract class */
  QPointer<RetType> visitSString(SString *p);
  QPointer<RetType> visitSFValue(SFValue *p);
  QPointer<RetType> visitSValue(SValue *p);
  QPointer<RetType> visitSValueType(SValueType *p);
  QPointer<RetType> visitSNodeType(SNodeType *p);
  QPointer<RetType> visitSConcat(SConcat *p);
  QPointer<RetType> visitExpr(Expr *p); /* abstract class */
  QPointer<RetType> visitETrue(ETrue *p);
  QPointer<RetType> visitEFalse(EFalse *p);
  QPointer<RetType> visitEParant(EParant *p);
  QPointer<RetType> visitENot(ENot *p);
  QPointer<RetType> visitEBEq(EBEq *p);
  QPointer<RetType> visitEPossToken(EPossToken *p);
  QPointer<RetType> visitEExistToken(EExistToken *p);
  QPointer<RetType> visitEILtEq(EILtEq *p);
  QPointer<RetType> visitEIGtEq(EIGtEq *p);
  QPointer<RetType> visitEILt(EILt *p);
  QPointer<RetType> visitEIGt(EIGt *p);
  QPointer<RetType> visitEIEq(EIEq *p);
  QPointer<RetType> visitEMatch(EMatch *p);
  QPointer<RetType> visitESEq(ESEq *p);
  QPointer<RetType> visitEAnd(EAnd *p);
  QPointer<RetType> visitEOr(EOr *p);
  QPointer<RetType> visitEFirstOrdQ(EFirstOrdQ *p);
  QPointer<RetType> visitEPQ(EPQ *p);
  QPointer<RetType> visitEImpl(EImpl *p);
  QPointer<RetType> visitListExpr(ListExpr* p);
  QPointer<RetType> visitFilter(Filter *p); /* abstract class */
  QPointer<RetType> visitFString(FString *p);
  QPointer<RetType> visitListFilter(ListFilter* p);

  QPointer<RetType> visitInteger(Integer i);
  QPointer<RetType> visitDouble(Double d);
  QPointer<RetType> visitChar(Char c);
  QPointer<RetType> visitString(String s);
  QPointer<RetType> visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufAppend(String str)
  {
    const char* s = str.c_str();
    bufAppend(s);
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};




#endif

