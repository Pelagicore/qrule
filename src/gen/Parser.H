#ifndef PARSER_HEADER_FILE
#define PARSER_HEADER_FILE

#include<vector>
#include<string>


class RuleSet;
class Rule;
class ASTScope;
class RuleCause;
class Explanation;
class ListRule;
class Tag;
class Severity;
class PathQuantifier;
class IStmnt;
class IExpr;
class Expr;
class ListExpr;

typedef union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  RuleSet* ruleset_;
  Rule* rule_;
  ASTScope* astscope_;
  RuleCause* rulecause_;
  Explanation* explanation_;
  ListRule* listrule_;
  Tag* tag_;
  Severity* severity_;
  PathQuantifier* pathquantifier_;
  IStmnt* istmnt_;
  IExpr* iexpr_;
  Expr* expr_;
  ListExpr* listexpr_;
} YYSTYPE;

RuleSet* pRuleSet(FILE *inp);
RuleSet* pRuleSet(const char *str);
Rule* pRule(FILE *inp);
Rule* pRule(const char *str);
ASTScope* pASTScope(FILE *inp);
ASTScope* pASTScope(const char *str);
RuleCause* pRuleCause(FILE *inp);
RuleCause* pRuleCause(const char *str);
Explanation* pExplanation(FILE *inp);
Explanation* pExplanation(const char *str);
ListRule* pListRule(FILE *inp);
ListRule* pListRule(const char *str);
Tag* pTag(FILE *inp);
Tag* pTag(const char *str);
Severity* pSeverity(FILE *inp);
Severity* pSeverity(const char *str);
PathQuantifier* pPathQuantifier(FILE *inp);
PathQuantifier* pPathQuantifier(const char *str);
IStmnt* pIStmnt(FILE *inp);
IStmnt* pIStmnt(const char *str);
IExpr* pIExpr(FILE *inp);
IExpr* pIExpr(const char *str);
Expr* pExpr(FILE *inp);
Expr* pExpr(const char *str);
ListExpr* pListExpr(FILE *inp);
ListExpr* pListExpr(const char *str);



#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _SYMB_21 280
#define _SYMB_22 281
#define _SYMB_23 282
#define _SYMB_24 283
#define _SYMB_25 284
#define _SYMB_26 285
#define _SYMB_27 286
#define _SYMB_28 287
#define _SYMB_29 288
#define _SYMB_30 289
#define _SYMB_31 290
#define _SYMB_32 291
#define _SYMB_33 292
#define _SYMB_34 293
#define _SYMB_35 294
#define _SYMB_36 295
#define _SYMB_37 296
#define _SYMB_38 297
#define _STRING_ 298
#define _INTEGER_ 299

extern YYSTYPE yylval;

#endif
