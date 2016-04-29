// Copyright (C) 2016 Pelagicore
//
// You may use this file under the terms of the GPLv3 license.
// See the file LICENSE from this package for details.
//
// SPDX-License-Identifier: GPL-3.0

/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "lkrule.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "Absyn.H"
typedef struct yy_buffer_state *YY_BUFFER_STATE;
int yyparse(void);
int yylex(void);
YY_BUFFER_STATE yy_scan_string(const char *str);
void yy_delete_buffer(YY_BUFFER_STATE buf);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(const char *str)
{
  extern char *yytext;
  fprintf(stderr,"error: line %d: %s at %s\n",
    yy_mylinenumber, str, yytext);
}



static RuleSet* YY_RESULT_RuleSet_ = 0;
RuleSet* pRuleSet(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_RuleSet_;
  }
}
RuleSet* pRuleSet(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_RuleSet_;
  }
}

static Rule* YY_RESULT_Rule_ = 0;
Rule* pRule(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Rule_;
  }
}
Rule* pRule(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Rule_;
  }
}

static ASTScope* YY_RESULT_ASTScope_ = 0;
ASTScope* pASTScope(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ASTScope_;
  }
}
ASTScope* pASTScope(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ASTScope_;
  }
}

static RuleCause* YY_RESULT_RuleCause_ = 0;
RuleCause* pRuleCause(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_RuleCause_;
  }
}
RuleCause* pRuleCause(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_RuleCause_;
  }
}

static Explanation* YY_RESULT_Explanation_ = 0;
Explanation* pExplanation(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Explanation_;
  }
}
Explanation* pExplanation(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Explanation_;
  }
}

static ListRule* YY_RESULT_ListRule_ = 0;
ListRule* pListRule(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListRule_;
  }
}
ListRule* pListRule(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListRule_;
  }
}

static Tag* YY_RESULT_Tag_ = 0;
Tag* pTag(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Tag_;
  }
}
Tag* pTag(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Tag_;
  }
}

static Severity* YY_RESULT_Severity_ = 0;
Severity* pSeverity(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Severity_;
  }
}
Severity* pSeverity(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Severity_;
  }
}

static PathQuantifier* YY_RESULT_PathQuantifier_ = 0;
PathQuantifier* pPathQuantifier(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_PathQuantifier_;
  }
}
PathQuantifier* pPathQuantifier(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_PathQuantifier_;
  }
}

static IAtom* YY_RESULT_IAtom_ = 0;
IAtom* pIAtom(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_IAtom_;
  }
}
IAtom* pIAtom(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_IAtom_;
  }
}

static SAtom* YY_RESULT_SAtom_ = 0;
SAtom* pSAtom(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_SAtom_;
  }
}
SAtom* pSAtom(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_SAtom_;
  }
}

static Expr* YY_RESULT_Expr_ = 0;
Expr* pExpr(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Expr_;
  }
}
Expr* pExpr(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Expr_;
  }
}

static ListExpr* YY_RESULT_ListExpr_ = 0;
ListExpr* pListExpr(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExpr_;
  }
}
ListExpr* pListExpr(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExpr_;
  }
}

static Filter* YY_RESULT_Filter_ = 0;
Filter* pFilter(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Filter_;
  }
}
Filter* pFilter(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Filter_;
  }
}

static ListFilter* YY_RESULT_ListFilter_ = 0;
ListFilter* pListFilter(FILE *inp)
{
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFilter_;
  }
}
ListFilter* pListFilter(const char *str)
{
  YY_BUFFER_STATE buf;
  int result;
  yy_mylinenumber = 1;
  initialize_lexer(0);
  buf = yy_scan_string(str);
  result = yyparse();
  yy_delete_buffer(buf);
  if (result)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFilter_;
  }
}




#line 592 "Parser.C" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _ERROR_ = 258,
    _SYMB_0 = 259,
    _SYMB_1 = 260,
    _SYMB_2 = 261,
    _SYMB_3 = 262,
    _SYMB_4 = 263,
    _SYMB_5 = 264,
    _SYMB_6 = 265,
    _SYMB_7 = 266,
    _SYMB_8 = 267,
    _SYMB_9 = 268,
    _SYMB_10 = 269,
    _SYMB_11 = 270,
    _SYMB_12 = 271,
    _SYMB_13 = 272,
    _SYMB_14 = 273,
    _SYMB_15 = 274,
    _SYMB_16 = 275,
    _SYMB_17 = 276,
    _SYMB_18 = 277,
    _SYMB_19 = 278,
    _SYMB_20 = 279,
    _SYMB_21 = 280,
    _SYMB_22 = 281,
    _SYMB_23 = 282,
    _SYMB_24 = 283,
    _SYMB_25 = 284,
    _SYMB_26 = 285,
    _SYMB_27 = 286,
    _SYMB_28 = 287,
    _SYMB_29 = 288,
    _SYMB_30 = 289,
    _SYMB_31 = 290,
    _SYMB_32 = 291,
    _SYMB_33 = 292,
    _SYMB_34 = 293,
    _SYMB_35 = 294,
    _SYMB_36 = 295,
    _SYMB_37 = 296,
    _SYMB_38 = 297,
    _SYMB_39 = 298,
    _SYMB_40 = 299,
    _SYMB_41 = 300,
    _SYMB_42 = 301,
    _SYMB_43 = 302,
    _SYMB_44 = 303,
    _SYMB_45 = 304,
    _SYMB_46 = 305,
    _SYMB_47 = 306,
    _SYMB_48 = 307,
    _SYMB_49 = 308,
    _SYMB_50 = 309,
    _STRING_ = 310,
    _INTEGER_ = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 529 "lkrule.y" /* yacc.c:355  */

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
  IAtom* iatom_;
  SAtom* satom_;
  Expr* expr_;
  ListExpr* listexpr_;
  Filter* filter_;
  ListFilter* listfilter_;

#line 708 "Parser.C" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 725 "Parser.C" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   637,   637,   639,   641,   642,   643,   645,   646,   648,
     649,   651,   652,   654,   656,   657,   658,   660,   661,   662,
     663,   664,   665,   666,   667,   669,   670,   671,   672,   673,
     674,   676,   677,   678,   679,   680,   681,   683,   684,   686,
     688,   689,   690,   691,   693,   694,   696,   697,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   708,   710,   711,
     712,   714,   715,   716,   718,   719,   721,   723,   725,   727,
     732,   734,   735,   736
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ERROR_", "_SYMB_0", "_SYMB_1",
  "_SYMB_2", "_SYMB_3", "_SYMB_4", "_SYMB_5", "_SYMB_6", "_SYMB_7",
  "_SYMB_8", "_SYMB_9", "_SYMB_10", "_SYMB_11", "_SYMB_12", "_SYMB_13",
  "_SYMB_14", "_SYMB_15", "_SYMB_16", "_SYMB_17", "_SYMB_18", "_SYMB_19",
  "_SYMB_20", "_SYMB_21", "_SYMB_22", "_SYMB_23", "_SYMB_24", "_SYMB_25",
  "_SYMB_26", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_SYMB_30", "_SYMB_31",
  "_SYMB_32", "_SYMB_33", "_SYMB_34", "_SYMB_35", "_SYMB_36", "_SYMB_37",
  "_SYMB_38", "_SYMB_39", "_SYMB_40", "_SYMB_41", "_SYMB_42", "_SYMB_43",
  "_SYMB_44", "_SYMB_45", "_SYMB_46", "_SYMB_47", "_SYMB_48", "_SYMB_49",
  "_SYMB_50", "_STRING_", "_INTEGER_", "$accept", "RuleSet", "Rule",
  "ASTScope", "RuleCause", "Explanation", "ListRule", "Tag", "Severity",
  "PathQuantifier", "IAtom", "SAtom2", "SAtom1", "SAtom", "Expr10",
  "Expr9", "Expr7", "Expr6", "Expr4", "Expr3", "Expr2", "Expr", "Expr1",
  "Expr5", "Expr8", "Filter", "ListFilter", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -33

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-33)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -33,     3,   -32,   -33,   -33,   -33,    31,   -33,   -33,   -33,
      15,   -33,   -33,   -12,   -33,   -33,   -33,    77,   -30,   -33,
      36,   -33,     5,     5,     0,     5,     5,     5,     5,   -14,
       5,     5,     5,     5,   -33,    -7,   -33,     7,   -33,    -8,
     -33,   -33,   -33,   -33,   -33,    26,   -33,   -33,    56,   -33,
      70,    -9,   -33,   -33,    69,   -33,    74,   -33,    75,   -33,
     -33,   -33,   -33,     8,    80,     5,   -33,    59,   -33,   -33,
     -33,   -33,    64,   -33,   -33,   -33,   -33,   -33,   -33,    76,
      88,   -26,    73,    73,    73,    73,    73,    33,    33,    57,
       6,    54,    54,     5,   -33,   -33,     5,     5,    -8,     5,
      61,    62,   -33,   -33,   -33,   -33,   -33,    33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   106
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     2,     1,    13,    12,     0,    16,    14,    15,
       0,     7,     8,     0,     5,     4,     6,     0,     0,    10,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,    40,     0,    30,    71,
      35,    28,    29,    33,    34,    31,    27,    62,     0,    38,
      39,     0,    45,    69,    57,    68,    63,    65,    67,     3,
      66,    60,    47,     0,     0,     0,    44,     0,    18,    17,
      19,    26,     0,    22,    21,    23,    25,    32,    70,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    42,     0,     0,    71,     0,
       0,     0,    54,    50,    51,    52,    53,     0,    31,    37,
      56,    55,    46,    58,    59,    64,    20,    24,    73,    61,
      49,    48,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
      35,    38,   -33,   -23,    99,   -33,   -33,   -33,   -33,    34,
     -33,   -21,   -33,     9,    40,   -33,    28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,    17,    13,    20,     2,     6,    10,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    64,    60,    61,    62,    79,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      63,    59,    88,     3,    67,    68,    69,    70,    65,    72,
      73,    74,    75,    23,    65,    24,    24,    94,   100,    88,
      14,    15,    16,     4,   101,    21,    25,    26,    27,    28,
      29,    34,    30,    31,    32,    33,    34,    34,    89,    36,
      22,   107,    71,    35,    36,    36,    37,    78,    38,    76,
      39,    11,    12,    40,    41,    89,    42,     7,    43,    44,
      45,    46,    23,    77,    24,   110,     8,    82,    83,    84,
      85,    86,    81,     9,    37,   116,   117,    87,   119,    29,
      90,    40,    18,    19,   122,    34,    43,    44,   108,    95,
      91,    92,    35,    36,    93,    37,    98,    38,    29,    96,
     113,   114,    40,    41,    97,    42,    99,    43,    44,    45,
      46,    35,   111,   120,   121,    94,    38,   102,   103,   104,
     105,   106,    41,    66,    42,   109,   118,   115,     0,    46,
     112
};

static const yytype_int8 yycheck[] =
{
      23,    22,    11,     0,    25,    26,    27,    28,     8,    30,
      31,    32,    33,     8,     8,    10,    10,     9,    44,    11,
      32,    33,    34,    55,    50,    55,    21,    22,    23,    24,
      25,    31,    27,    28,    29,    30,    31,    31,    47,    39,
       4,     8,    56,    38,    39,    39,    41,    55,    43,    56,
      45,    36,    37,    48,    49,    47,    51,    26,    53,    54,
      55,    56,     8,    56,    10,    88,    35,    11,    12,    13,
      14,    15,    46,    42,    41,    96,    97,     7,    99,    25,
      11,    48,     5,     6,   107,    31,    53,    54,    55,     9,
      16,    17,    38,    39,    19,    41,    20,    43,    25,    40,
      91,    92,    48,    49,    40,    51,    18,    53,    54,    55,
      56,    38,    55,    52,    52,     9,    43,    82,    83,    84,
      85,    86,    49,    24,    51,    87,    98,    93,    -1,    56,
      90
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    63,     0,    55,    59,    64,    26,    35,    42,
      65,    36,    37,    61,    32,    33,    34,    60,     5,     6,
      62,    55,     4,     8,    10,    21,    22,    23,    24,    25,
      27,    28,    29,    30,    31,    38,    39,    41,    43,    45,
      48,    49,    51,    53,    54,    55,    56,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    70,    78,     8,    71,    78,    78,    78,
      78,    56,    78,    78,    78,    78,    56,    56,    55,    82,
      83,    46,    11,    12,    13,    14,    15,     7,    11,    47,
      11,    16,    17,    19,     9,     9,    40,    40,    20,    18,
      44,    50,    67,    67,    67,    67,    67,     8,    55,    68,
      70,    55,    81,    80,    80,    76,    78,    78,    83,    78,
      52,    52,    70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      71,    71,    71,    71,    72,    72,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      75,    76,    76,    76,    77,    77,    78,    79,    80,    81,
      82,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     7,     1,     1,     1,     1,     1,     2,
       1,     0,     2,     1,     1,     1,     1,     2,     2,     2,
       4,     2,     2,     2,     4,     2,     2,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     3,     3,     2,     1,     3,     1,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     4,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     0,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 637 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.ruleset_) = new RSet((yyvsp[0].listrule_)); YY_RESULT_RuleSet_= (yyval.ruleset_); }
#line 1900 "Parser.C" /* yacc.c:1646  */
    break;

  case 3:
#line 639 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.rule_) = new RRule((yyvsp[-6].tag_), (yyvsp[-5].severity_), (yyvsp[-4].rulecause_), (yyvsp[-3].astscope_), (yyvsp[-2].explanation_), (yyvsp[0].expr_)); YY_RESULT_Rule_= (yyval.rule_); }
#line 1906 "Parser.C" /* yacc.c:1646  */
    break;

  case 4:
#line 641 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.astscope_) = new ASTGlobally(); YY_RESULT_ASTScope_= (yyval.astscope_); }
#line 1912 "Parser.C" /* yacc.c:1646  */
    break;

  case 5:
#line 642 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.astscope_) = new ASTFile(); YY_RESULT_ASTScope_= (yyval.astscope_); }
#line 1918 "Parser.C" /* yacc.c:1646  */
    break;

  case 6:
#line 643 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.astscope_) = new ASTImported(); YY_RESULT_ASTScope_= (yyval.astscope_); }
#line 1924 "Parser.C" /* yacc.c:1646  */
    break;

  case 7:
#line 645 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.rulecause_) = new RCLang(); YY_RESULT_RuleCause_= (yyval.rulecause_); }
#line 1930 "Parser.C" /* yacc.c:1646  */
    break;

  case 8:
#line 646 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.rulecause_) = new RCPolicy(); YY_RESULT_RuleCause_= (yyval.rulecause_); }
#line 1936 "Parser.C" /* yacc.c:1646  */
    break;

  case 9:
#line 648 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.explanation_) = new Explan((yyvsp[0].string_)); YY_RESULT_Explanation_= (yyval.explanation_); }
#line 1942 "Parser.C" /* yacc.c:1646  */
    break;

  case 10:
#line 649 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.explanation_) = new Noexplan(); YY_RESULT_Explanation_= (yyval.explanation_); }
#line 1948 "Parser.C" /* yacc.c:1646  */
    break;

  case 11:
#line 651 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.listrule_) = new ListRule(); YY_RESULT_ListRule_= (yyval.listrule_); }
#line 1954 "Parser.C" /* yacc.c:1646  */
    break;

  case 12:
#line 652 "lkrule.y" /* yacc.c:1646  */
    {  (yyvsp[-1].listrule_)->push_back((yyvsp[0].rule_)) ; (yyval.listrule_) = (yyvsp[-1].listrule_) ; YY_RESULT_ListRule_= (yyval.listrule_); }
#line 1960 "Parser.C" /* yacc.c:1646  */
    break;

  case 13:
#line 654 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.tag_) = new TTag((yyvsp[0].string_)); YY_RESULT_Tag_= (yyval.tag_); }
#line 1966 "Parser.C" /* yacc.c:1646  */
    break;

  case 14:
#line 656 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.severity_) = new SevInfo(); YY_RESULT_Severity_= (yyval.severity_); }
#line 1972 "Parser.C" /* yacc.c:1646  */
    break;

  case 15:
#line 657 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.severity_) = new SevWarning(); YY_RESULT_Severity_= (yyval.severity_); }
#line 1978 "Parser.C" /* yacc.c:1646  */
    break;

  case 16:
#line 658 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.severity_) = new SevCritical(); YY_RESULT_Severity_= (yyval.severity_); }
#line 1984 "Parser.C" /* yacc.c:1646  */
    break;

  case 17:
#line 660 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new AG((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 1990 "Parser.C" /* yacc.c:1646  */
    break;

  case 18:
#line 661 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new AF((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 1996 "Parser.C" /* yacc.c:1646  */
    break;

  case 19:
#line 662 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new AX((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2002 "Parser.C" /* yacc.c:1646  */
    break;

  case 20:
#line 663 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new AU((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2008 "Parser.C" /* yacc.c:1646  */
    break;

  case 21:
#line 664 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new EG((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2014 "Parser.C" /* yacc.c:1646  */
    break;

  case 22:
#line 665 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new EF((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2020 "Parser.C" /* yacc.c:1646  */
    break;

  case 23:
#line 666 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new EX((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2026 "Parser.C" /* yacc.c:1646  */
    break;

  case 24:
#line 667 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new EU((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2032 "Parser.C" /* yacc.c:1646  */
    break;

  case 25:
#line 669 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = new IFRow((yyvsp[0].int_)); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2038 "Parser.C" /* yacc.c:1646  */
    break;

  case 26:
#line 670 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = new IFCol((yyvsp[0].int_)); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2044 "Parser.C" /* yacc.c:1646  */
    break;

  case 27:
#line 671 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = new IInt((yyvsp[0].int_)); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2050 "Parser.C" /* yacc.c:1646  */
    break;

  case 28:
#line 672 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = new INrChildren(); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2056 "Parser.C" /* yacc.c:1646  */
    break;

  case 29:
#line 673 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = new IRow(); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2062 "Parser.C" /* yacc.c:1646  */
    break;

  case 30:
#line 674 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = new ICol(); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2068 "Parser.C" /* yacc.c:1646  */
    break;

  case 31:
#line 676 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SString((yyvsp[0].string_)); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2074 "Parser.C" /* yacc.c:1646  */
    break;

  case 32:
#line 677 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SFValue((yyvsp[0].int_)); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2080 "Parser.C" /* yacc.c:1646  */
    break;

  case 33:
#line 678 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SValue(); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2086 "Parser.C" /* yacc.c:1646  */
    break;

  case 34:
#line 679 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SValueType(); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2092 "Parser.C" /* yacc.c:1646  */
    break;

  case 35:
#line 680 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SNodeType(); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2098 "Parser.C" /* yacc.c:1646  */
    break;

  case 36:
#line 681 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = (yyvsp[-1].satom_); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2104 "Parser.C" /* yacc.c:1646  */
    break;

  case 37:
#line 683 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SConcat((yyvsp[-2].satom_), (yyvsp[0].satom_)); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2110 "Parser.C" /* yacc.c:1646  */
    break;

  case 38:
#line 684 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = (yyvsp[0].satom_); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2116 "Parser.C" /* yacc.c:1646  */
    break;

  case 39:
#line 686 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = (yyvsp[0].satom_); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2122 "Parser.C" /* yacc.c:1646  */
    break;

  case 40:
#line 688 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ETrue(); YY_RESULT_Expr_= (yyval.expr_); }
#line 2128 "Parser.C" /* yacc.c:1646  */
    break;

  case 41:
#line 689 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EFalse(); YY_RESULT_Expr_= (yyval.expr_); }
#line 2134 "Parser.C" /* yacc.c:1646  */
    break;

  case 42:
#line 690 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EParant((yyvsp[-1].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2140 "Parser.C" /* yacc.c:1646  */
    break;

  case 43:
#line 691 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[-1].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2146 "Parser.C" /* yacc.c:1646  */
    break;

  case 44:
#line 693 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ENot((yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2152 "Parser.C" /* yacc.c:1646  */
    break;

  case 45:
#line 694 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2158 "Parser.C" /* yacc.c:1646  */
    break;

  case 46:
#line 696 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EBEq((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2164 "Parser.C" /* yacc.c:1646  */
    break;

  case 47:
#line 697 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2170 "Parser.C" /* yacc.c:1646  */
    break;

  case 48:
#line 699 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EPossToken((yyvsp[-3].string_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2176 "Parser.C" /* yacc.c:1646  */
    break;

  case 49:
#line 700 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EExistToken((yyvsp[-3].string_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2182 "Parser.C" /* yacc.c:1646  */
    break;

  case 50:
#line 701 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EILtEq((yyvsp[-2].iatom_), (yyvsp[0].iatom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2188 "Parser.C" /* yacc.c:1646  */
    break;

  case 51:
#line 702 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EIGtEq((yyvsp[-2].iatom_), (yyvsp[0].iatom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2194 "Parser.C" /* yacc.c:1646  */
    break;

  case 52:
#line 703 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EILt((yyvsp[-2].iatom_), (yyvsp[0].iatom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2200 "Parser.C" /* yacc.c:1646  */
    break;

  case 53:
#line 704 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EIGt((yyvsp[-2].iatom_), (yyvsp[0].iatom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2206 "Parser.C" /* yacc.c:1646  */
    break;

  case 54:
#line 705 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EIEq((yyvsp[-2].iatom_), (yyvsp[0].iatom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2212 "Parser.C" /* yacc.c:1646  */
    break;

  case 55:
#line 706 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EMatch((yyvsp[-2].satom_), (yyvsp[0].string_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2218 "Parser.C" /* yacc.c:1646  */
    break;

  case 56:
#line 707 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ESEq((yyvsp[-2].satom_), (yyvsp[0].satom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2224 "Parser.C" /* yacc.c:1646  */
    break;

  case 57:
#line 708 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2230 "Parser.C" /* yacc.c:1646  */
    break;

  case 58:
#line 710 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EAnd((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2236 "Parser.C" /* yacc.c:1646  */
    break;

  case 59:
#line 711 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EOr((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2242 "Parser.C" /* yacc.c:1646  */
    break;

  case 60:
#line 712 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2248 "Parser.C" /* yacc.c:1646  */
    break;

  case 61:
#line 714 "lkrule.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-2].listfilter_)->begin(),(yyvsp[-2].listfilter_)->end()) ;(yyval.expr_) = new EFirstOrdQ((yyvsp[-2].listfilter_), (yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2254 "Parser.C" /* yacc.c:1646  */
    break;

  case 62:
#line 715 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EPQ((yyvsp[0].pathquantifier_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2260 "Parser.C" /* yacc.c:1646  */
    break;

  case 63:
#line 716 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2266 "Parser.C" /* yacc.c:1646  */
    break;

  case 64:
#line 718 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EImpl((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2272 "Parser.C" /* yacc.c:1646  */
    break;

  case 65:
#line 719 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2278 "Parser.C" /* yacc.c:1646  */
    break;

  case 66:
#line 721 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2284 "Parser.C" /* yacc.c:1646  */
    break;

  case 67:
#line 723 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2290 "Parser.C" /* yacc.c:1646  */
    break;

  case 68:
#line 725 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2296 "Parser.C" /* yacc.c:1646  */
    break;

  case 69:
#line 727 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2302 "Parser.C" /* yacc.c:1646  */
    break;

  case 70:
#line 732 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.filter_) = new FString((yyvsp[0].string_)); YY_RESULT_Filter_= (yyval.filter_); }
#line 2308 "Parser.C" /* yacc.c:1646  */
    break;

  case 71:
#line 734 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.listfilter_) = new ListFilter(); YY_RESULT_ListFilter_= (yyval.listfilter_); }
#line 2314 "Parser.C" /* yacc.c:1646  */
    break;

  case 72:
#line 735 "lkrule.y" /* yacc.c:1646  */
    {  (yyval.listfilter_) = new ListFilter() ; (yyval.listfilter_)->push_back((yyvsp[0].filter_)); YY_RESULT_ListFilter_= (yyval.listfilter_); }
#line 2320 "Parser.C" /* yacc.c:1646  */
    break;

  case 73:
#line 736 "lkrule.y" /* yacc.c:1646  */
    {  (yyvsp[0].listfilter_)->push_back((yyvsp[-2].filter_)) ; (yyval.listfilter_) = (yyvsp[0].listfilter_) ; YY_RESULT_ListFilter_= (yyval.listfilter_); }
#line 2326 "Parser.C" /* yacc.c:1646  */
    break;


#line 2330 "Parser.C" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
