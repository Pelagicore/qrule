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

  RetType* visitRuleSet(RuleSet *p); /* abstract class */
  RetType* visitRSet(RSet *p);
  RetType* visitRule(Rule *p); /* abstract class */
  RetType* visitRRule(RRule *p);
  RetType* visitASTScope(ASTScope *p); /* abstract class */
  RetType* visitASTGlobally(ASTGlobally *p);
  RetType* visitASTFile(ASTFile *p);
  RetType* visitASTImported(ASTImported *p);
  RetType* visitRuleCause(RuleCause *p); /* abstract class */
  RetType* visitRCLang(RCLang *p);
  RetType* visitRCPolicy(RCPolicy *p);
  RetType* visitExplanation(Explanation *p); /* abstract class */
  RetType* visitExplan(Explan *p);
  RetType* visitNoexplan(Noexplan *p);
  RetType* visitListRule(ListRule* p);
  RetType* visitTag(Tag *p); /* abstract class */
  RetType* visitTTag(TTag *p);
  RetType* visitSeverity(Severity *p); /* abstract class */
  RetType* visitSevInfo(SevInfo *p);
  RetType* visitSevWarning(SevWarning *p);
  RetType* visitSevCritical(SevCritical *p);
  RetType* visitQuantifier(Quantifier *p); /* abstract class */
  RetType* visitQExpr(QExpr *p);
  RetType* visitQFor(QFor *p);
  RetType* visitPathQuantifier(PathQuantifier *p); /* abstract class */
  RetType* visitAG(AG *p);
  RetType* visitAF(AF *p);
  RetType* visitAX(AX *p);
  RetType* visitAU(AU *p);
  RetType* visitEG(EG *p);
  RetType* visitEF(EF *p);
  RetType* visitEX(EX *p);
  RetType* visitEU(EU *p);
  RetType* visitIAtom(IAtom *p); /* abstract class */
  RetType* visitIFRow(IFRow *p);
  RetType* visitIFCol(IFCol *p);
  RetType* visitIInt(IInt *p);
  RetType* visitINrChildren(INrChildren *p);
  RetType* visitIRow(IRow *p);
  RetType* visitICol(ICol *p);
  RetType* visitSAtom(SAtom *p); /* abstract class */
  RetType* visitSString(SString *p);
  RetType* visitSFValue(SFValue *p);
  RetType* visitSValue(SValue *p);
  RetType* visitSValueType(SValueType *p);
  RetType* visitSNodeType(SNodeType *p);
  RetType* visitSConcat(SConcat *p);
  RetType* visitExpr(Expr *p); /* abstract class */
  RetType* visitETrue(ETrue *p);
  RetType* visitEFalse(EFalse *p);
  RetType* visitEParant(EParant *p);
  RetType* visitENot(ENot *p);
  RetType* visitEImpl(EImpl *p);
  RetType* visitEBEq(EBEq *p);
  RetType* visitEPossToken(EPossToken *p);
  RetType* visitEExistToken(EExistToken *p);
  RetType* visitEILtEq(EILtEq *p);
  RetType* visitEIGtEq(EIGtEq *p);
  RetType* visitEILt(EILt *p);
  RetType* visitEIGt(EIGt *p);
  RetType* visitEIEq(EIEq *p);
  RetType* visitEMatch(EMatch *p);
  RetType* visitESEq(ESEq *p);
  RetType* visitEAnd(EAnd *p);
  RetType* visitEOr(EOr *p);
  RetType* visitEPQ(EPQ *p);
  RetType* visitListExpr(ListExpr* p);

  RetType* visitInteger(Integer i);
  RetType* visitDouble(Double d);
  RetType* visitChar(Char c);
  RetType* visitString(String s);
  RetType* visitIdent(String s);
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

  RetType* visitRuleSet(RuleSet *p); /* abstract class */
  RetType* visitRSet(RSet *p);
  RetType* visitRule(Rule *p); /* abstract class */
  RetType* visitRRule(RRule *p);
  RetType* visitASTScope(ASTScope *p); /* abstract class */
  RetType* visitASTGlobally(ASTGlobally *p);
  RetType* visitASTFile(ASTFile *p);
  RetType* visitASTImported(ASTImported *p);
  RetType* visitRuleCause(RuleCause *p); /* abstract class */
  RetType* visitRCLang(RCLang *p);
  RetType* visitRCPolicy(RCPolicy *p);
  RetType* visitExplanation(Explanation *p); /* abstract class */
  RetType* visitExplan(Explan *p);
  RetType* visitNoexplan(Noexplan *p);
  RetType* visitListRule(ListRule* p);
  RetType* visitTag(Tag *p); /* abstract class */
  RetType* visitTTag(TTag *p);
  RetType* visitSeverity(Severity *p); /* abstract class */
  RetType* visitSevInfo(SevInfo *p);
  RetType* visitSevWarning(SevWarning *p);
  RetType* visitSevCritical(SevCritical *p);
  RetType* visitQuantifier(Quantifier *p); /* abstract class */
  RetType* visitQExpr(QExpr *p);
  RetType* visitQFor(QFor *p);
  RetType* visitPathQuantifier(PathQuantifier *p); /* abstract class */
  RetType* visitAG(AG *p);
  RetType* visitAF(AF *p);
  RetType* visitAX(AX *p);
  RetType* visitAU(AU *p);
  RetType* visitEG(EG *p);
  RetType* visitEF(EF *p);
  RetType* visitEX(EX *p);
  RetType* visitEU(EU *p);
  RetType* visitIAtom(IAtom *p); /* abstract class */
  RetType* visitIFRow(IFRow *p);
  RetType* visitIFCol(IFCol *p);
  RetType* visitIInt(IInt *p);
  RetType* visitINrChildren(INrChildren *p);
  RetType* visitIRow(IRow *p);
  RetType* visitICol(ICol *p);
  RetType* visitSAtom(SAtom *p); /* abstract class */
  RetType* visitSString(SString *p);
  RetType* visitSFValue(SFValue *p);
  RetType* visitSValue(SValue *p);
  RetType* visitSValueType(SValueType *p);
  RetType* visitSNodeType(SNodeType *p);
  RetType* visitSConcat(SConcat *p);
  RetType* visitExpr(Expr *p); /* abstract class */
  RetType* visitETrue(ETrue *p);
  RetType* visitEFalse(EFalse *p);
  RetType* visitEParant(EParant *p);
  RetType* visitENot(ENot *p);
  RetType* visitEImpl(EImpl *p);
  RetType* visitEBEq(EBEq *p);
  RetType* visitEPossToken(EPossToken *p);
  RetType* visitEExistToken(EExistToken *p);
  RetType* visitEILtEq(EILtEq *p);
  RetType* visitEIGtEq(EIGtEq *p);
  RetType* visitEILt(EILt *p);
  RetType* visitEIGt(EIGt *p);
  RetType* visitEIEq(EIEq *p);
  RetType* visitEMatch(EMatch *p);
  RetType* visitESEq(ESEq *p);
  RetType* visitEAnd(EAnd *p);
  RetType* visitEOr(EOr *p);
  RetType* visitEPQ(EPQ *p);
  RetType* visitListExpr(ListExpr* p);

  RetType* visitInteger(Integer i);
  RetType* visitDouble(Double d);
  RetType* visitChar(Char c);
  RetType* visitString(String s);
  RetType* visitIdent(String s);
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

