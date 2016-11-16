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
#line 2 "lqrule.y" /* yacc.c:339  */

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
    _STRING_ = 309,
    _INTEGER_ = 310,
    _IDENT_ = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 529 "lqrule.y" /* yacc.c:355  */

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
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

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
       0,   640,   640,   642,   644,   645,   646,   648,   649,   651,
     652,   654,   655,   657,   659,   660,   661,   663,   664,   665,
     666,   667,   668,   669,   670,   672,   673,   674,   675,   677,
     678,   679,   681,   683,   684,   685,   686,   688,   689,   690,
     692,   693,   695,   697,   698,   699,   700,   702,   703,   705,
     706,   708,   709,   710,   711,   712,   713,   714,   715,   716,
     717,   719,   720,   721,   723,   724,   725,   726,   728,   729,
     731,   733,   735,   737,   742,   744,   745,   746
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
  "_STRING_", "_INTEGER_", "_IDENT_", "$accept", "RuleSet", "Rule",
  "ASTScope", "RuleCause", "Explanation", "ListRule", "Tag", "Severity",
  "PathQuantifier", "IAtom2", "IAtom1", "IAtom", "SAtom3", "SAtom2",
  "SAtom1", "SAtom", "Expr10", "Expr9", "Expr7", "Expr6", "Expr4", "Expr3",
  "Expr2", "Expr", "Expr1", "Expr5", "Expr8", "Filter", "ListFilter", YY_NULLPTR
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

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -87,    20,   -31,   -87,   -87,   -87,   105,   -87,   -87,   -87,
       1,   -87,   -87,   -14,   -87,   -87,   -87,    84,   -29,   -87,
      26,   -87,     5,     5,    13,     5,     5,     5,     5,     5,
       5,     5,     5,   -87,   -87,   -87,   -18,    -5,   -87,   -87,
     -87,   -87,   -87,    17,   -87,    59,   -87,   -87,   -87,   147,
     -87,   -87,   110,    81,   -87,   -87,    67,   -87,    23,   -87,
     113,   -87,   -87,   -87,   -87,   122,    35,   132,     5,   -87,
     104,   -87,   -87,   -87,   107,   -87,   -87,   -87,    99,   102,
     -27,   100,    57,    57,    57,    57,    57,    31,    31,    95,
     121,    69,    69,     5,   -87,   -87,   -87,     5,     5,   101,
     101,   103,   106,    48,   -87,   -87,    57,   149,   -87,   -87,
     -87,   -87,   -87,    31,   -87,   157,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   158,   148,   150,   -87,
     -87,   159,   161,    78,    16,   101,     5,     5,   -87,   -87,
     -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     2,     1,    13,    12,     0,    16,    14,    15,
       0,     7,     8,     0,     5,     4,     6,     0,     0,    10,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    43,    27,     0,     0,    35,    25,
      26,    33,    34,    38,    30,     0,    66,    31,    32,     0,
      39,    41,    42,     0,    48,    73,    60,    72,    67,    69,
      71,     3,    70,    63,    50,     0,     0,     0,     0,    47,
       0,    18,    17,    19,     0,    22,    21,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    36,    45,     0,     0,    75,
      75,     0,     0,     0,    29,    37,     0,     0,    57,    53,
      54,    55,    56,     0,    38,     0,    40,    59,    58,    49,
      61,    62,    68,    20,    24,    74,    76,     0,     0,    52,
      51,     0,     0,     0,     0,    75,     0,     0,    77,    65,
      64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -69,   -87,   -12,   -80,    79,   -87,   -21,   151,   -87,   -87,
     -87,   -87,    80,   -87,   -22,   -87,    19,    82,   -87,   -86
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,    17,    13,    20,     2,     6,    10,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    67,    62,    63,    64,   126,   127
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,   105,    66,    70,    71,    72,    73,    74,    75,    76,
      77,    65,   104,    23,   128,   101,    24,    14,    15,    16,
       3,    68,   102,     4,   113,    21,    25,    26,    27,    28,
      22,    29,    30,    31,    32,    33,    11,    12,    78,   113,
      91,    92,    34,    33,    95,    35,    36,    88,    37,   138,
      34,    79,    38,    39,   105,    40,   103,    41,    42,    43,
      44,    45,    80,    38,   104,   106,    81,   117,    41,    42,
     108,   109,   110,   111,   112,   123,   124,    23,    38,    90,
      24,    89,   132,    41,    42,   114,   106,   115,    35,    18,
      19,   131,   132,    88,   131,    38,    39,    35,    40,    33,
      41,    42,   114,    44,    45,    39,    34,    40,   103,    35,
     120,   121,    44,   107,   139,   140,    38,    39,    35,    40,
      87,    41,    42,    43,    44,    45,    39,    89,    40,    68,
       7,    94,    24,    93,    82,    83,    84,    85,    86,     8,
      35,    96,    97,    99,     9,    98,   100,    38,    39,   118,
      40,    33,    41,    42,   129,   125,   133,   130,    34,    82,
      83,    84,    85,    86,   134,   135,   116,   136,    94,   137,
      95,     0,   119,   122,     0,    69
};

static const yytype_int16 yycheck[] =
{
      22,    81,    23,    25,    26,    27,    28,    29,    30,    31,
      32,    23,    81,     8,   100,    42,    11,    31,    32,    33,
       0,     8,    49,    54,     8,    54,    21,    22,    23,    24,
       4,    26,    27,    28,    29,    30,    35,    36,    56,     8,
      17,    18,    37,    30,     9,    40,    41,    12,    43,   135,
      37,    56,    47,    48,   134,    50,     8,    52,    53,    54,
      55,    56,    45,    47,   133,     8,     7,    88,    52,    53,
      82,    83,    84,    85,    86,    97,    98,     8,    47,    12,
      11,    46,   103,    52,    53,    54,     8,    56,    40,     5,
       6,   103,   113,    12,   106,    47,    48,    40,    50,    30,
      52,    53,    54,    55,    56,    48,    37,    50,     8,    40,
      91,    92,    55,    56,   136,   137,    47,    48,    40,    50,
      10,    52,    53,    54,    55,    56,    48,    46,    50,     8,
      25,     9,    11,    20,    12,    13,    14,    15,    16,    34,
      40,     9,    38,    44,    39,    38,    44,    47,    48,    54,
      50,    30,    52,    53,    51,    54,     7,    51,    37,    12,
      13,    14,    15,    16,     7,     7,    87,    19,     9,    19,
       9,    -1,    90,    93,    -1,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    63,     0,    54,    59,    64,    25,    34,    39,
      65,    35,    36,    61,    31,    32,    33,    60,     5,     6,
      62,    54,     4,     8,    11,    21,    22,    23,    24,    26,
      27,    28,    29,    30,    37,    40,    41,    43,    47,    48,
      50,    52,    53,    54,    55,    56,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    69,    73,    81,     8,    74,
      81,    81,    81,    81,    81,    81,    81,    81,    56,    56,
      45,     7,    12,    13,    14,    15,    16,    10,    12,    46,
      12,    17,    18,    20,     9,     9,     9,    38,    38,    44,
      44,    42,    49,     8,    67,    70,     8,    56,    69,    69,
      69,    69,    69,     8,    54,    56,    71,    73,    54,    84,
      83,    83,    79,    81,    81,    54,    85,    86,    86,    51,
      51,    69,    73,     7,     7,     7,    19,    19,    86,    81,
      81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    60,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    67,    68,
      68,    68,    69,    70,    70,    70,    70,    71,    71,    71,
      72,    72,    73,    74,    74,    74,    74,    75,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    79,    79,    79,    79,    80,    80,
      81,    82,    83,    84,    85,    86,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     7,     1,     1,     1,     1,     1,     2,
       1,     0,     2,     1,     1,     1,     1,     2,     2,     2,
       4,     2,     2,     2,     4,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       3,     1,     1,     1,     1,     3,     3,     2,     1,     3,
       1,     4,     4,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     6,     6,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     0,     1,     3
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
#line 640 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.ruleset_) = new RSet((yyvsp[0].listrule_)); YY_RESULT_RuleSet_= (yyval.ruleset_); }
#line 1914 "Parser.C" /* yacc.c:1646  */
    break;

  case 3:
#line 642 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.rule_) = new RRule((yyvsp[-6].tag_), (yyvsp[-5].severity_), (yyvsp[-4].rulecause_), (yyvsp[-3].astscope_), (yyvsp[-2].explanation_), (yyvsp[0].expr_)); YY_RESULT_Rule_= (yyval.rule_); }
#line 1920 "Parser.C" /* yacc.c:1646  */
    break;

  case 4:
#line 644 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.astscope_) = new ASTGlobally(); YY_RESULT_ASTScope_= (yyval.astscope_); }
#line 1926 "Parser.C" /* yacc.c:1646  */
    break;

  case 5:
#line 645 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.astscope_) = new ASTFile(); YY_RESULT_ASTScope_= (yyval.astscope_); }
#line 1932 "Parser.C" /* yacc.c:1646  */
    break;

  case 6:
#line 646 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.astscope_) = new ASTImported(); YY_RESULT_ASTScope_= (yyval.astscope_); }
#line 1938 "Parser.C" /* yacc.c:1646  */
    break;

  case 7:
#line 648 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.rulecause_) = new RCLang(); YY_RESULT_RuleCause_= (yyval.rulecause_); }
#line 1944 "Parser.C" /* yacc.c:1646  */
    break;

  case 8:
#line 649 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.rulecause_) = new RCPolicy(); YY_RESULT_RuleCause_= (yyval.rulecause_); }
#line 1950 "Parser.C" /* yacc.c:1646  */
    break;

  case 9:
#line 651 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.explanation_) = new Explan((yyvsp[0].string_)); YY_RESULT_Explanation_= (yyval.explanation_); }
#line 1956 "Parser.C" /* yacc.c:1646  */
    break;

  case 10:
#line 652 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.explanation_) = new Noexplan(); YY_RESULT_Explanation_= (yyval.explanation_); }
#line 1962 "Parser.C" /* yacc.c:1646  */
    break;

  case 11:
#line 654 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.listrule_) = new ListRule(); YY_RESULT_ListRule_= (yyval.listrule_); }
#line 1968 "Parser.C" /* yacc.c:1646  */
    break;

  case 12:
#line 655 "lqrule.y" /* yacc.c:1646  */
    {  (yyvsp[-1].listrule_)->push_back((yyvsp[0].rule_)) ; (yyval.listrule_) = (yyvsp[-1].listrule_) ; YY_RESULT_ListRule_= (yyval.listrule_); }
#line 1974 "Parser.C" /* yacc.c:1646  */
    break;

  case 13:
#line 657 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.tag_) = new TTag((yyvsp[0].string_)); YY_RESULT_Tag_= (yyval.tag_); }
#line 1980 "Parser.C" /* yacc.c:1646  */
    break;

  case 14:
#line 659 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.severity_) = new SevInfo(); YY_RESULT_Severity_= (yyval.severity_); }
#line 1986 "Parser.C" /* yacc.c:1646  */
    break;

  case 15:
#line 660 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.severity_) = new SevWarning(); YY_RESULT_Severity_= (yyval.severity_); }
#line 1992 "Parser.C" /* yacc.c:1646  */
    break;

  case 16:
#line 661 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.severity_) = new SevCritical(); YY_RESULT_Severity_= (yyval.severity_); }
#line 1998 "Parser.C" /* yacc.c:1646  */
    break;

  case 17:
#line 663 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new AG((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2004 "Parser.C" /* yacc.c:1646  */
    break;

  case 18:
#line 664 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new AF((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2010 "Parser.C" /* yacc.c:1646  */
    break;

  case 19:
#line 665 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new AX((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2016 "Parser.C" /* yacc.c:1646  */
    break;

  case 20:
#line 666 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new AU((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2022 "Parser.C" /* yacc.c:1646  */
    break;

  case 21:
#line 667 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new EG((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2028 "Parser.C" /* yacc.c:1646  */
    break;

  case 22:
#line 668 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new EF((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2034 "Parser.C" /* yacc.c:1646  */
    break;

  case 23:
#line 669 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new EX((yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2040 "Parser.C" /* yacc.c:1646  */
    break;

  case 24:
#line 670 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.pathquantifier_) = new EU((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_PathQuantifier_= (yyval.pathquantifier_); }
#line 2046 "Parser.C" /* yacc.c:1646  */
    break;

  case 25:
#line 672 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = new INrChildren(); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2052 "Parser.C" /* yacc.c:1646  */
    break;

  case 26:
#line 673 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = new IRow(); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2058 "Parser.C" /* yacc.c:1646  */
    break;

  case 27:
#line 674 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = new ICol(); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2064 "Parser.C" /* yacc.c:1646  */
    break;

  case 28:
#line 675 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = (yyvsp[-1].iatom_); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2070 "Parser.C" /* yacc.c:1646  */
    break;

  case 29:
#line 677 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = new IQuant((yyvsp[-2].string_), (yyvsp[0].iatom_)); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2076 "Parser.C" /* yacc.c:1646  */
    break;

  case 30:
#line 678 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = new IInt((yyvsp[0].int_)); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2082 "Parser.C" /* yacc.c:1646  */
    break;

  case 31:
#line 679 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = (yyvsp[0].iatom_); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2088 "Parser.C" /* yacc.c:1646  */
    break;

  case 32:
#line 681 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.iatom_) = (yyvsp[0].iatom_); YY_RESULT_IAtom_= (yyval.iatom_); }
#line 2094 "Parser.C" /* yacc.c:1646  */
    break;

  case 33:
#line 683 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SValue(); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2100 "Parser.C" /* yacc.c:1646  */
    break;

  case 34:
#line 684 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SValueType(); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2106 "Parser.C" /* yacc.c:1646  */
    break;

  case 35:
#line 685 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SNodeType(); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2112 "Parser.C" /* yacc.c:1646  */
    break;

  case 36:
#line 686 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = (yyvsp[-1].satom_); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2118 "Parser.C" /* yacc.c:1646  */
    break;

  case 37:
#line 688 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SQuant((yyvsp[-2].string_), (yyvsp[0].satom_)); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2124 "Parser.C" /* yacc.c:1646  */
    break;

  case 38:
#line 689 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SString((yyvsp[0].string_)); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2130 "Parser.C" /* yacc.c:1646  */
    break;

  case 39:
#line 690 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = (yyvsp[0].satom_); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2136 "Parser.C" /* yacc.c:1646  */
    break;

  case 40:
#line 692 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = new SConcat((yyvsp[-2].satom_), (yyvsp[0].satom_)); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2142 "Parser.C" /* yacc.c:1646  */
    break;

  case 41:
#line 693 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = (yyvsp[0].satom_); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2148 "Parser.C" /* yacc.c:1646  */
    break;

  case 42:
#line 695 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.satom_) = (yyvsp[0].satom_); YY_RESULT_SAtom_= (yyval.satom_); }
#line 2154 "Parser.C" /* yacc.c:1646  */
    break;

  case 43:
#line 697 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ETrue(); YY_RESULT_Expr_= (yyval.expr_); }
#line 2160 "Parser.C" /* yacc.c:1646  */
    break;

  case 44:
#line 698 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EFalse(); YY_RESULT_Expr_= (yyval.expr_); }
#line 2166 "Parser.C" /* yacc.c:1646  */
    break;

  case 45:
#line 699 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EParant((yyvsp[-1].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2172 "Parser.C" /* yacc.c:1646  */
    break;

  case 46:
#line 700 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[-1].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2178 "Parser.C" /* yacc.c:1646  */
    break;

  case 47:
#line 702 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ENot((yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2184 "Parser.C" /* yacc.c:1646  */
    break;

  case 48:
#line 703 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2190 "Parser.C" /* yacc.c:1646  */
    break;

  case 49:
#line 705 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EBEq((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2196 "Parser.C" /* yacc.c:1646  */
    break;

  case 50:
#line 706 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2202 "Parser.C" /* yacc.c:1646  */
    break;

  case 51:
#line 708 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EPossToken((yyvsp[-3].string_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2208 "Parser.C" /* yacc.c:1646  */
    break;

  case 52:
#line 709 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EExistToken((yyvsp[-3].string_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2214 "Parser.C" /* yacc.c:1646  */
    break;

  case 53:
#line 710 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EILtEq((yyvsp[-2].iatom_), (yyvsp[0].iatom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2220 "Parser.C" /* yacc.c:1646  */
    break;

  case 54:
#line 711 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EIGtEq((yyvsp[-2].iatom_), (yyvsp[0].iatom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2226 "Parser.C" /* yacc.c:1646  */
    break;

  case 55:
#line 712 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EILt((yyvsp[-2].iatom_), (yyvsp[0].iatom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2232 "Parser.C" /* yacc.c:1646  */
    break;

  case 56:
#line 713 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EIGt((yyvsp[-2].iatom_), (yyvsp[0].iatom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2238 "Parser.C" /* yacc.c:1646  */
    break;

  case 57:
#line 714 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EIEq((yyvsp[-2].iatom_), (yyvsp[0].iatom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2244 "Parser.C" /* yacc.c:1646  */
    break;

  case 58:
#line 715 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EMatch((yyvsp[-2].satom_), (yyvsp[0].string_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2250 "Parser.C" /* yacc.c:1646  */
    break;

  case 59:
#line 716 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new ESEq((yyvsp[-2].satom_), (yyvsp[0].satom_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2256 "Parser.C" /* yacc.c:1646  */
    break;

  case 60:
#line 717 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2262 "Parser.C" /* yacc.c:1646  */
    break;

  case 61:
#line 719 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EAnd((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2268 "Parser.C" /* yacc.c:1646  */
    break;

  case 62:
#line 720 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EOr((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2274 "Parser.C" /* yacc.c:1646  */
    break;

  case 63:
#line 721 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2280 "Parser.C" /* yacc.c:1646  */
    break;

  case 64:
#line 723 "lqrule.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-2].listfilter_)->begin(),(yyvsp[-2].listfilter_)->end()) ;(yyval.expr_) = new EForAllQ((yyvsp[-4].string_), (yyvsp[-2].listfilter_), (yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2286 "Parser.C" /* yacc.c:1646  */
    break;

  case 65:
#line 724 "lqrule.y" /* yacc.c:1646  */
    {  std::reverse((yyvsp[-2].listfilter_)->begin(),(yyvsp[-2].listfilter_)->end()) ;(yyval.expr_) = new EExistQ((yyvsp[-4].string_), (yyvsp[-2].listfilter_), (yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2292 "Parser.C" /* yacc.c:1646  */
    break;

  case 66:
#line 725 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EPQ((yyvsp[0].pathquantifier_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2298 "Parser.C" /* yacc.c:1646  */
    break;

  case 67:
#line 726 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2304 "Parser.C" /* yacc.c:1646  */
    break;

  case 68:
#line 728 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = new EImpl((yyvsp[-2].expr_), (yyvsp[0].expr_)); YY_RESULT_Expr_= (yyval.expr_); }
#line 2310 "Parser.C" /* yacc.c:1646  */
    break;

  case 69:
#line 729 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2316 "Parser.C" /* yacc.c:1646  */
    break;

  case 70:
#line 731 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2322 "Parser.C" /* yacc.c:1646  */
    break;

  case 71:
#line 733 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2328 "Parser.C" /* yacc.c:1646  */
    break;

  case 72:
#line 735 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2334 "Parser.C" /* yacc.c:1646  */
    break;

  case 73:
#line 737 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.expr_) = (yyvsp[0].expr_); YY_RESULT_Expr_= (yyval.expr_); }
#line 2340 "Parser.C" /* yacc.c:1646  */
    break;

  case 74:
#line 742 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.filter_) = new FString((yyvsp[0].string_)); YY_RESULT_Filter_= (yyval.filter_); }
#line 2346 "Parser.C" /* yacc.c:1646  */
    break;

  case 75:
#line 744 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.listfilter_) = new ListFilter(); YY_RESULT_ListFilter_= (yyval.listfilter_); }
#line 2352 "Parser.C" /* yacc.c:1646  */
    break;

  case 76:
#line 745 "lqrule.y" /* yacc.c:1646  */
    {  (yyval.listfilter_) = new ListFilter() ; (yyval.listfilter_)->push_back((yyvsp[0].filter_)); YY_RESULT_ListFilter_= (yyval.listfilter_); }
#line 2358 "Parser.C" /* yacc.c:1646  */
    break;

  case 77:
#line 746 "lqrule.y" /* yacc.c:1646  */
    {  (yyvsp[0].listfilter_)->push_back((yyvsp[-2].filter_)) ; (yyval.listfilter_) = (yyvsp[0].listfilter_) ; YY_RESULT_ListFilter_= (yyval.listfilter_); }
#line 2364 "Parser.C" /* yacc.c:1646  */
    break;


#line 2368 "Parser.C" /* yacc.c:1646  */
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
