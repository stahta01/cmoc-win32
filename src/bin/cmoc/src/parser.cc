/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.yy"

/*  $Id: parser.yy,v 1.25 2016/06/29 18:40:54 sarrazip Exp $

    CMOC - A C-like cross-compiler
    Copyright (C) 2003-2016 Pierre Sarrazin <http://sarrazip.com/>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "DeclarationSequence.h"
#include "WordConstantExpr.h"
#include "IdentifierExpr.h"
#include "VariableExpr.h"
#include "FunctionCallExpr.h"
#include "StringLiteralExpr.h"
#include "BinaryOpExpr.h"
#include "UnaryOpExpr.h"
#include "CastExpr.h"
#include "CompoundStmt.h"
#include "IfStmt.h"
#include "SwitchStmt.h"
#include "LabeledStmt.h"
#include "WhileStmt.h"
#include "ForStmt.h"
#include "JumpStmt.h"
#include "Scope.h"
#include "FunctionDef.h"
#include "FormalParameter.h"
#include "FormalParamList.h"
#include "AssemblerStmt.h"
#include "TranslationUnit.h"
#include "ObjectMemberExpr.h"
#include "ClassDef.h"
#include "ConditionalExpr.h"
#include "DeclarationSpecifierList.h"
#include "Pragma.h"

#include <string.h>
#include <time.h>

using namespace std;

int yyparse(void);
int yylex(void);
void yyerror(const char *msg);
extern char *yytext;

extern string sourceFilename;  // defined in lexer.ll
extern int lineno;  // defined in lexer.ll
int numErrors = 0;  // error counter for yyerror()
int numWarnings = 0;

const TypeDesc *rejectTypeKeyword(const char *keyword)
{
    errormsg("unsupported type keyword `%s'", keyword);
    return TranslationUnit::getTypeManager().getIntType(WORD_TYPE, true);
}



/* Line 268 of yacc.c  */
#line 143 "parser.cc"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     STRLIT = 259,
     PRAGMA = 260,
     CHARLIT = 261,
     REAL = 262,
     TYPE_NAME = 263,
     INT = 264,
     CHAR = 265,
     SHORT = 266,
     LONG = 267,
     FLOAT = 268,
     DOUBLE = 269,
     SIGNED = 270,
     UNSIGNED = 271,
     VOID = 272,
     PLUS_PLUS = 273,
     MINUS_MINUS = 274,
     IF = 275,
     ELSE = 276,
     WHILE = 277,
     DO = 278,
     FOR = 279,
     EQUALS_EQUALS = 280,
     BANG_EQUALS = 281,
     LOWER_EQUALS = 282,
     GREATER_EQUALS = 283,
     AMP_AMP = 284,
     PIPE_PIPE = 285,
     LT_LT = 286,
     GT_GT = 287,
     BREAK = 288,
     CONTINUE = 289,
     RETURN = 290,
     ASM = 291,
     VERBATIM_ASM = 292,
     STRUCT = 293,
     UNION = 294,
     THIS = 295,
     PLUS_EQUALS = 296,
     MINUS_EQUALS = 297,
     ASTERISK_EQUALS = 298,
     SLASH_EQUALS = 299,
     PERCENT_EQUALS = 300,
     LT_LT_EQUALS = 301,
     GT_GT_EQUALS = 302,
     CARET_EQUALS = 303,
     AMP_EQUALS = 304,
     PIPE_EQUALS = 305,
     RIGHT_ARROW = 306,
     INTERRUPT = 307,
     SIZEOF = 308,
     ELLIPSIS = 309,
     TYPEDEF = 310,
     SWITCH = 311,
     CASE = 312,
     DEFAULT = 313,
     REGISTER = 314,
     GOTO = 315,
     EXTERN = 316,
     STATIC = 317
   };
#endif
/* Tokens.  */
#define ID 258
#define STRLIT 259
#define PRAGMA 260
#define CHARLIT 261
#define REAL 262
#define TYPE_NAME 263
#define INT 264
#define CHAR 265
#define SHORT 266
#define LONG 267
#define FLOAT 268
#define DOUBLE 269
#define SIGNED 270
#define UNSIGNED 271
#define VOID 272
#define PLUS_PLUS 273
#define MINUS_MINUS 274
#define IF 275
#define ELSE 276
#define WHILE 277
#define DO 278
#define FOR 279
#define EQUALS_EQUALS 280
#define BANG_EQUALS 281
#define LOWER_EQUALS 282
#define GREATER_EQUALS 283
#define AMP_AMP 284
#define PIPE_PIPE 285
#define LT_LT 286
#define GT_GT 287
#define BREAK 288
#define CONTINUE 289
#define RETURN 290
#define ASM 291
#define VERBATIM_ASM 292
#define STRUCT 293
#define UNION 294
#define THIS 295
#define PLUS_EQUALS 296
#define MINUS_EQUALS 297
#define ASTERISK_EQUALS 298
#define SLASH_EQUALS 299
#define PERCENT_EQUALS 300
#define LT_LT_EQUALS 301
#define GT_GT_EQUALS 302
#define CARET_EQUALS 303
#define AMP_EQUALS 304
#define PIPE_EQUALS 305
#define RIGHT_ARROW 306
#define INTERRUPT 307
#define SIZEOF 308
#define ELLIPSIS 309
#define TYPEDEF 310
#define SWITCH 311
#define CASE 312
#define DEFAULT 313
#define REGISTER 314
#define GOTO 315
#define EXTERN 316
#define STATIC 317




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 74 "parser.yy"

    char *str;
    char character;
    double real;
    int integer;
    BasicType basicType;
    const TypeDesc *typeDesc;
    DeclarationSpecifierList *declarationSpecifierList;
    Tree *tree;
    CompoundStmt *compoundStmt;
    TreeSequence *treeSequence;
    FormalParamList *formalParamList;
    FormalParameter *formalParameter;
    DeclarationSequence *declarationSequence;
    Declarator *declarator;
    std::vector<Declarator *> *declaratorVector;
    Declaration *declaration;
    BinaryOpExpr::Op binop;
    UnaryOpExpr::Op unop;
    Scope *scope;
    FunctionDef *functionDef;
    std::vector<std::string> *strList;
    ClassDef *classDef;
    ClassDef::ClassMember *classMember;
    FilenameAndLineNo *filenameAndLineNo;
    std::vector<ClassDef::ClassMember *> *classMemberList;



/* Line 293 of yacc.c  */
#line 333 "parser.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 345 "parser.cc"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   811

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  206
/* YYNRULES -- Number of states.  */
#define YYNSTATES  334

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,     2,     2,     2,    83,    77,     2,
      71,    72,    64,    80,    63,    81,    86,    82,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    73,    67,
      78,    68,    79,    74,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    76,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,    75,    66,    85,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    20,
      22,    26,    28,    32,    35,    37,    40,    42,    44,    47,
      50,    52,    56,    57,    59,    62,    66,    68,    71,    73,
      76,    78,    80,    82,    84,    86,    88,    90,    92,    95,
      97,   103,   108,   110,   112,   114,   116,   118,   120,   122,
     124,   126,   128,   130,   132,   134,   135,   136,   138,   142,
     144,   148,   151,   153,   155,   156,   161,   166,   170,   175,
     183,   190,   191,   193,   195,   199,   204,   206,   210,   211,
     213,   215,   218,   222,   224,   228,   230,   232,   235,   237,
     239,   241,   243,   245,   247,   249,   251,   255,   258,   261,
     264,   268,   276,   284,   290,   292,   298,   303,   307,   309,
     311,   314,   315,   317,   319,   321,   327,   329,   331,   333,
     335,   337,   339,   341,   343,   345,   347,   349,   351,   357,
     359,   363,   365,   369,   371,   375,   377,   381,   383,   387,
     389,   393,   395,   397,   399,   403,   405,   409,   413,   415,
     417,   419,   421,   423,   427,   429,   431,   433,   437,   439,
     441,   443,   445,   448,   451,   454,   459,   462,   464,   466,
     468,   470,   472,   474,   476,   481,   483,   485,   491,   498,
     503,   506,   509,   513,   517,   519,   521,   523,   525,   527,
     531,   533,   536,   537,   539,   541,   545,   552,   558,   560,
     561,   564,   570,   572,   580,   583,   585
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      88,     0,    -1,    89,    -1,    90,    -1,    89,    90,    -1,
      91,    -1,   101,    -1,     5,    -1,   102,   114,    99,    -1,
      93,    -1,    93,    63,    54,    -1,    94,    -1,    93,    63,
      94,    -1,   102,   114,    -1,    98,    -1,    98,    96,    -1,
      97,    -1,    64,    -1,    64,    97,    -1,   104,    98,    -1,
     104,    -1,    65,   100,    66,    -1,    -1,   124,    -1,   102,
      67,    -1,   102,   112,    67,    -1,   103,    -1,   103,   102,
      -1,   104,    -1,   104,   102,    -1,    52,    -1,    55,    -1,
      36,    -1,    59,    -1,    62,    -1,    61,    -1,   109,    -1,
     105,    -1,   106,     3,    -1,     8,    -1,   106,     3,    65,
     119,    66,    -1,   106,    65,   119,    66,    -1,    38,    -1,
      39,    -1,     9,    -1,    10,    -1,    11,    -1,    15,    -1,
      16,    -1,   108,    -1,    12,    -1,    13,    -1,    14,    -1,
     107,    -1,    17,    -1,    -1,    -1,   113,    -1,   112,    63,
     113,    -1,   114,    -1,   114,    68,   117,    -1,    97,   114,
      -1,   115,    -1,     3,    -1,    -1,   115,    69,   129,    70,
      -1,   115,    71,    92,    72,    -1,   115,    71,    72,    -1,
     115,    71,    17,    72,    -1,    71,    64,     3,    72,    71,
     116,    72,    -1,    71,    64,    72,    71,   116,    72,    -1,
      -1,    92,    -1,   131,    -1,    65,   118,    66,    -1,    65,
     118,    63,    66,    -1,   117,    -1,   118,    63,   117,    -1,
      -1,   120,    -1,   121,    -1,   120,   121,    -1,    98,   122,
      67,    -1,   123,    -1,   122,    63,   123,    -1,   114,    -1,
     125,    -1,   124,   125,    -1,   128,    -1,   101,    -1,    99,
      -1,   157,    -1,   126,    -1,   160,    -1,   162,    -1,   164,
      -1,    60,     3,    67,    -1,    33,    67,    -1,    34,    67,
      -1,    35,    67,    -1,    35,   130,    67,    -1,    36,    71,
       4,    63,     3,    72,    67,    -1,    36,    71,     4,    63,
       4,    72,    67,    -1,    36,    71,     4,    72,    67,    -1,
      37,    -1,     3,   110,   111,    73,   125,    -1,    57,   127,
      73,   125,    -1,    58,    73,   125,    -1,   133,    -1,    67,
      -1,   130,    67,    -1,    -1,   130,    -1,   131,    -1,   133,
      -1,   148,   110,   111,   132,   131,    -1,    68,    -1,    41,
      -1,    42,    -1,    43,    -1,    44,    -1,    45,    -1,    48,
      -1,    49,    -1,    50,    -1,    46,    -1,    47,    -1,   134,
      -1,   134,    74,   130,    73,   133,    -1,   135,    -1,   134,
      30,   135,    -1,   136,    -1,   135,    29,   136,    -1,   137,
      -1,   136,    75,   137,    -1,   138,    -1,   137,    76,   138,
      -1,   139,    -1,   138,    77,   139,    -1,   141,    -1,   139,
     140,   141,    -1,    25,    -1,    26,    -1,   142,    -1,   141,
     143,   142,    -1,   144,    -1,   142,    31,   144,    -1,   142,
      32,   144,    -1,    78,    -1,    27,    -1,    79,    -1,    28,
      -1,   146,    -1,   144,   145,   146,    -1,    80,    -1,    81,
      -1,   150,    -1,   146,   147,   150,    -1,    64,    -1,    82,
      -1,    83,    -1,   151,    -1,   149,   150,    -1,    18,   148,
      -1,    19,   148,    -1,    53,    71,    95,    72,    -1,    53,
     148,    -1,    80,    -1,    81,    -1,    77,    -1,    64,    -1,
      84,    -1,    85,    -1,   148,    -1,    71,    95,    72,   150,
      -1,   152,    -1,   153,    -1,   152,   110,   111,    71,    72,
      -1,   152,   110,   111,    71,   156,    72,    -1,   152,    69,
     130,    70,    -1,   152,    18,    -1,   152,    19,    -1,   152,
      86,     3,    -1,   152,    51,     3,    -1,     3,    -1,    40,
      -1,     7,    -1,     6,    -1,   154,    -1,    71,   130,    72,
      -1,     4,    -1,   154,     4,    -1,    -1,   156,    -1,   130,
      -1,   156,    63,   130,    -1,    20,    71,   158,    72,   125,
     159,    -1,    56,    71,   130,    72,   125,    -1,   130,    -1,
      -1,    21,   125,    -1,    22,    71,   161,    72,   125,    -1,
     130,    -1,    23,   125,    22,    71,   161,    72,    67,    -1,
     155,    67,    -1,   101,    -1,    24,    71,   110,   111,   163,
     110,   111,   129,    67,   110,   111,   155,    72,   110,   111,
     125,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   140,   140,   144,   150,   159,   160,   161,   165,   188,
     189,   193,   194,   199,   208,   209,   217,   221,   222,   226,
     227,   231,   236,   237,   243,   252,   298,   300,   302,   304,
     309,   310,   311,   312,   313,   314,   318,   319,   320,   321,
     325,   337,   353,   354,   358,   359,   360,   361,   362,   363,
     368,   369,   370,   374,   375,   379,   383,   387,   388,   394,
     395,   399,   404,   408,   414,   417,   422,   427,   432,   438,
     444,   452,   453,   457,   458,   459,   463,   464,   468,   469,
     473,   480,   490,   508,   509,   513,   519,   520,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   540,   543,   546,   550,   556,   557,   561,   565,
     566,   570,   571,   575,   579,   580,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   599,   600,   605,
     606,   611,   612,   617,   618,   622,   623,   627,   628,   632,
     633,   638,   639,   643,   644,   648,   649,   651,   656,   657,
     658,   659,   663,   664,   668,   669,   673,   674,   678,   679,
     680,   684,   685,   686,   687,   688,   689,   693,   694,   695,
     696,   697,   698,   702,   703,   711,   722,   723,   726,   729,
     731,   733,   735,   737,   742,   743,   744,   745,   746,   747,
     751,   752,   761,   762,   766,   767,   771,   772,   776,   780,
     781,   785,   789,   793,   797,   798,   802
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRLIT", "PRAGMA", "CHARLIT",
  "REAL", "TYPE_NAME", "INT", "CHAR", "SHORT", "LONG", "FLOAT", "DOUBLE",
  "SIGNED", "UNSIGNED", "VOID", "PLUS_PLUS", "MINUS_MINUS", "IF", "ELSE",
  "WHILE", "DO", "FOR", "EQUALS_EQUALS", "BANG_EQUALS", "LOWER_EQUALS",
  "GREATER_EQUALS", "AMP_AMP", "PIPE_PIPE", "LT_LT", "GT_GT", "BREAK",
  "CONTINUE", "RETURN", "ASM", "VERBATIM_ASM", "STRUCT", "UNION", "THIS",
  "PLUS_EQUALS", "MINUS_EQUALS", "ASTERISK_EQUALS", "SLASH_EQUALS",
  "PERCENT_EQUALS", "LT_LT_EQUALS", "GT_GT_EQUALS", "CARET_EQUALS",
  "AMP_EQUALS", "PIPE_EQUALS", "RIGHT_ARROW", "INTERRUPT", "SIZEOF",
  "ELLIPSIS", "TYPEDEF", "SWITCH", "CASE", "DEFAULT", "REGISTER", "GOTO",
  "EXTERN", "STATIC", "','", "'*'", "'{'", "'}'", "';'", "'='", "'['",
  "']'", "'('", "')'", "':'", "'?'", "'|'", "'^'", "'&'", "'<'", "'>'",
  "'+'", "'-'", "'/'", "'%'", "'!'", "'~'", "'.'", "$accept", "goal",
  "translation_unit", "external_declaration", "function_definition",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "type_name", "abstract_declarator", "pointer",
  "specifier_qualifier_list", "compound_stmt", "stmt_list_opt",
  "declaration", "declaration_specifiers", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "non_void_basic_type", "unsupported_basic_type", "basic_type",
  "save_src_fn", "save_line_no", "init_declarator_list", "init_declarator",
  "declarator", "direct_declarator", "parameter_type_list_opt",
  "initializer", "initializer_list", "struct_declaration_list_opt",
  "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "stmt_list", "stmt",
  "labeled_stmt", "constant_expr", "expr_stmt", "expr_opt", "expr",
  "assignment_expr", "assignment_op", "conditional_expr",
  "logical_or_expr", "logical_and_expr", "inclusive_or_expr",
  "exclusive_or_expr", "and_expr", "equality_expr", "equality_op",
  "rel_expr", "shift_expr", "rel_op", "add_expr", "add_op", "mul_expr",
  "mul_op", "unary_expr", "unary_op", "cast_expr", "postfix_expr_ex",
  "postfix_expr", "primary_expr", "strlit_seq", "expr_list_opt",
  "expr_list", "selection_stmt", "if_cond", "else_part_opt", "while_stmt",
  "while_cond", "do_while_stmt", "for_init", "for_stmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    44,    42,   123,   125,    59,    61,    91,
      93,    40,    41,    58,    63,   124,    94,    38,    60,    62,
      43,    45,    47,    37,    33,   126,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    89,    89,    90,    90,    90,    91,    92,
      92,    93,    93,    94,    95,    95,    96,    97,    97,    98,
      98,    99,   100,   100,   101,   101,   102,   102,   102,   102,
     103,   103,   103,   103,   103,   103,   104,   104,   104,   104,
     105,   105,   106,   106,   107,   107,   107,   107,   107,   107,
     108,   108,   108,   109,   109,   110,   111,   112,   112,   113,
     113,   114,   114,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   117,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   122,   122,   123,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   126,   126,   126,   127,   128,
     128,   129,   129,   130,   131,   131,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   133,   133,   134,
     134,   135,   135,   136,   136,   137,   137,   138,   138,   139,
     139,   140,   140,   141,   141,   142,   142,   142,   143,   143,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   147,
     147,   148,   148,   148,   148,   148,   148,   149,   149,   149,
     149,   149,   149,   150,   150,   151,   152,   152,   152,   152,
     152,   152,   152,   152,   153,   153,   153,   153,   153,   153,
     154,   154,   155,   155,   156,   156,   157,   157,   158,   159,
     159,   160,   161,   162,   163,   163,   164
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     1,
       3,     1,     3,     2,     1,     2,     1,     1,     2,     2,
       1,     3,     0,     1,     2,     3,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       5,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     0,     1,     3,     1,
       3,     2,     1,     1,     0,     4,     4,     3,     4,     7,
       6,     0,     1,     1,     3,     4,     1,     3,     0,     1,
       1,     2,     3,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     2,
       3,     7,     7,     5,     1,     5,     4,     3,     1,     1,
       2,     0,     1,     1,     1,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     3,     1,     3,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     2,     2,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     5,     6,     4,
       2,     2,     3,     3,     1,     1,     1,     1,     1,     3,
       1,     2,     0,     1,     1,     3,     6,     5,     1,     0,
       2,     5,     1,     7,     2,     1,    16
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,    39,    44,    45,    46,    50,    51,    52,    47,
      48,    54,    32,    42,    43,    30,    31,    33,    35,    34,
       0,     2,     3,     5,     6,    64,    26,    28,    37,     0,
      53,    49,    36,     1,     4,    63,    17,    24,     0,    64,
       0,    57,    59,    62,    27,    29,    38,    78,    18,     0,
      61,    64,    25,    22,     0,     8,   111,     0,    78,    64,
      20,     0,    79,    80,     0,     0,    58,    59,   184,   190,
     187,   186,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,   104,   185,     0,     0,     0,     0,     0,   170,
     109,     0,   169,   167,   168,   171,   172,    90,     0,    89,
      64,    23,    86,    92,    88,     0,   113,   114,   127,   129,
     131,   133,   135,   137,   139,   143,   145,   152,   173,     0,
     156,   161,   175,   176,   188,    91,    93,    94,    95,   184,
       0,    60,    73,     0,   112,    54,    67,     0,     9,    11,
      64,     0,    85,     0,    83,    19,    41,    81,     0,    71,
      56,     0,   163,   164,     0,     0,     0,    55,    97,    98,
      99,     0,     0,     0,   166,     0,     0,   108,   173,     0,
       0,     0,    14,     0,    21,    87,   110,     0,     0,     0,
       0,     0,     0,   141,   142,     0,   149,   151,   148,   150,
       0,     0,     0,   154,   155,     0,   158,   159,   160,     0,
      56,   162,   180,   181,     0,     0,     0,    56,   191,    76,
       0,    65,    68,    66,     0,    13,    40,    64,    82,    71,
      72,     0,     0,   198,     0,   202,     0,     0,    56,   100,
       0,     0,     0,     0,   107,    96,     0,    15,    16,   189,
     130,     0,   132,   134,   136,   138,   140,   144,   146,   147,
     153,   157,     0,   183,     0,   182,     0,     0,    74,    10,
      12,    84,     0,    70,     0,     0,     0,     0,   192,     0,
       0,   165,     0,   106,   174,     0,   117,   118,   119,   120,
     121,   125,   126,   122,   123,   124,   116,     0,   179,     0,
      75,    77,    69,   105,   199,   201,     0,   205,   194,     0,
     193,    55,     0,     0,   103,   197,   128,   115,   177,     0,
       0,   196,     0,   204,     0,    56,     0,     0,   178,   200,
     203,   195,   111,   101,   102,     0,    55,    56,   192,     0,
      55,    56,     0,   206
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,   220,   138,   139,   171,   237,
      39,    59,    97,    98,    99,   100,    26,    27,    28,    29,
      30,    31,    32,   150,   222,    40,    41,    67,    43,   221,
     131,   210,    61,    62,    63,   143,   144,   101,   102,   103,
     166,   104,   133,   105,   106,   287,   107,   108,   109,   110,
     111,   112,   113,   185,   114,   115,   190,   116,   195,   117,
     199,   118,   119,   120,   121,   122,   123,   124,   299,   300,
     125,   224,   311,   126,   226,   127,   301,   128
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -174
static const yytype_int16 yypact[] =
{
     683,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,  -174,
      15,   683,  -174,  -174,  -174,    13,   749,   749,  -174,    16,
    -174,  -174,  -174,  -174,  -174,  -174,   -25,  -174,   -10,    26,
     -11,  -174,    -1,   -31,  -174,  -174,   -32,   301,  -174,    11,
    -174,    26,  -174,   267,   442,  -174,   552,   668,   301,    26,
     301,    -7,   301,  -174,    -2,    -8,  -174,    14,     6,  -174,
    -174,  -174,   571,   571,    17,    23,   267,    31,    36,    41,
     461,    39,  -174,  -174,   590,    46,   552,    45,   109,  -174,
    -174,   168,  -174,  -174,  -174,  -174,  -174,  -174,    55,  -174,
      13,   267,  -174,  -174,  -174,    56,  -174,  -174,    -9,    99,
      57,    58,    54,    47,    22,    43,    25,   -41,   428,   552,
    -174,  -174,    18,  -174,   131,  -174,  -174,  -174,  -174,  -174,
     442,  -174,  -174,    66,  -174,    65,  -174,    67,    77,  -174,
      26,    75,  -174,    -5,  -174,  -174,  -174,  -174,    72,   749,
    -174,   552,  -174,  -174,   552,   552,   122,  -174,  -174,  -174,
    -174,    78,   143,   168,  -174,   552,    79,  -174,  -174,   267,
      83,    84,   -25,    85,  -174,  -174,  -174,   552,   552,   552,
     552,   552,   552,  -174,  -174,   552,  -174,  -174,  -174,  -174,
     552,   552,   552,  -174,  -174,   552,  -174,  -174,  -174,   552,
    -174,  -174,  -174,  -174,   148,   552,   152,  -174,  -174,  -174,
       5,  -174,  -174,  -174,   738,  -174,  -174,    26,  -174,   749,
    -174,    87,    88,  -174,    90,  -174,    91,    93,  -174,  -174,
     -12,    94,    95,   267,  -174,  -174,   552,  -174,  -174,  -174,
      99,    92,    57,    58,    54,    47,    22,    43,    25,    25,
     -41,  -174,   538,  -174,    98,  -174,   102,   373,  -174,  -174,
    -174,  -174,    97,  -174,   267,   267,   267,   552,   350,    82,
     123,  -174,   267,  -174,  -174,   552,  -174,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,  -174,  -174,   552,  -174,   480,
    -174,  -174,  -174,  -174,   173,  -174,   117,  -174,  -174,   128,
     133,  -174,   126,   129,  -174,  -174,  -174,  -174,  -174,    -6,
     267,  -174,   135,  -174,   552,  -174,   136,   147,  -174,  -174,
    -174,  -174,   552,  -174,  -174,   149,  -174,  -174,   552,   138,
    -174,  -174,   267,  -174
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,  -174,  -174,   179,  -174,   158,  -174,     8,    61,  -174,
     -26,   -43,   177,  -174,     1,     4,  -174,   -15,  -174,  -174,
    -174,  -174,  -174,  -113,  -173,  -174,   169,   -13,  -174,     7,
    -119,  -174,   167,  -174,   165,  -174,    12,  -174,   -73,  -174,
    -174,  -174,   -94,   -56,   -52,  -174,   -78,  -174,    53,    52,
      60,    62,    59,  -174,    49,    48,  -174,  -100,  -174,    51,
    -174,   -66,  -174,  -106,  -174,  -174,  -174,  -174,   -92,   -47,
    -174,  -174,  -174,  -174,   -23,  -174,  -174,  -174
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -56
static const yytype_int16 yytable[] =
{
     134,    24,   132,   156,    25,   200,   152,   153,   167,   207,
      48,   209,    42,   201,    64,    33,    35,   145,   164,    46,
     168,   177,    24,   196,   161,    25,    50,   252,   175,    35,
      44,    45,    60,    58,   256,   173,   202,   203,    56,    36,
      57,   197,   198,    60,   228,    60,   142,    60,   172,   186,
     187,   269,    51,   168,    49,   268,    52,   314,   217,   146,
     270,   140,   218,   149,    53,   178,   318,    54,   257,   204,
     148,   258,   183,   184,   191,   192,    60,    36,   132,   -55,
      37,    47,    54,    65,    38,   302,   303,   205,   154,   -55,
      36,   248,   249,   251,   155,   173,   234,    38,   223,   225,
     188,   189,   157,   158,   206,   193,   194,   173,   159,   232,
     162,   168,   170,   168,   168,   168,   168,   165,   169,   168,
     172,   174,   241,   176,   168,   168,   168,   215,   179,   168,
     274,   182,   180,   168,   181,   208,   211,   212,   291,   213,
     214,   216,   322,   219,   227,   229,   238,   230,    60,   254,
     235,   253,   233,   140,   328,   255,   236,   239,   332,   263,
     273,   264,   265,   266,   267,   275,   271,   272,   288,   292,
     168,   129,    69,   289,    70,    71,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    72,    73,   315,   312,
     304,   293,   294,   295,   310,   313,   314,   306,   316,   305,
      34,   317,   320,   323,   142,   132,    13,    14,    83,   168,
     330,   225,   298,   327,   324,   137,   326,   331,   140,    55,
      66,    84,   260,   140,   231,   141,   262,   147,   325,   261,
     240,   242,    89,   298,   246,   307,   329,   319,   247,    91,
     243,   245,   309,   244,   296,    92,   250,     0,    93,    94,
       0,     0,    95,    96,     0,     0,     0,     0,   321,   333,
       0,     0,     0,     0,     0,     0,   134,     0,     0,   297,
      68,    69,   298,    70,    71,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    72,    73,    74,     0,    75,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    13,    14,    83,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    15,
      84,     0,    16,    85,    86,    87,    17,    88,    18,    19,
       0,    89,    53,     0,    90,     0,     0,     0,    91,    13,
      14,     0,     0,     0,    92,     0,     0,    93,    94,     0,
       0,    95,    96,   129,    69,     0,    70,    71,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    72,    73,
       0,     0,     0,     0,     0,     0,   129,    69,     0,    70,
      71,     0,     0,     0,     0,     0,    12,     0,    13,    14,
      83,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    84,     0,    16,     0,     0,     0,    17,
       0,    18,    19,    83,    89,     0,     0,     0,     0,     0,
       0,    91,     0,     0,     0,     0,    84,    92,     0,     0,
      93,    94,     0,     0,    95,    96,     0,    89,   130,   290,
       0,     0,     0,     0,    91,   129,    69,     0,    70,    71,
      92,     0,     0,    93,    94,     0,     0,    95,    96,     0,
      72,    73,     0,     0,   129,    69,     0,    70,    71,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,    72,
      73,     0,    83,   129,    69,     0,    70,    71,     0,     0,
       0,     0,     0,     0,     0,    84,   -55,     0,    72,    73,
       0,    83,     0,     0,     0,     0,    89,   130,     0,     0,
       0,     0,     0,    91,    84,     0,     0,     0,     0,    92,
      83,     0,    93,    94,     0,    89,    95,    96,   160,     0,
       0,     0,    91,    84,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,    89,    95,    96,     0,     0,     0,
       0,    91,   308,     0,     0,   129,    69,    92,    70,    71,
      93,    94,     0,     0,    95,    96,     0,     0,     0,     0,
      72,    73,     0,     0,   129,    69,     0,    70,    71,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,    72,
      73,     0,    83,   129,    69,     0,    70,    71,     0,     0,
       0,     0,     0,     0,     0,    84,   286,     0,    72,    73,
       0,    83,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,    91,    84,     0,     0,     0,     0,    92,
      83,     0,    93,    94,     0,    89,    95,    96,     0,     0,
       0,     0,   151,    84,     0,     0,     0,     0,    92,     0,
       0,    93,    94,     0,    89,    95,    96,     0,     0,     0,
       0,   163,     0,     0,     0,     0,     0,    92,     0,     0,
      93,    94,     0,     0,    95,    96,     2,     3,     4,     5,
       6,     7,     8,     9,    10,   135,     0,     0,     1,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,     0,     0,    12,     0,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      15,    13,    14,    16,     0,     0,     0,    17,     0,    18,
      19,     0,     0,     0,     0,    15,     0,     0,    16,     0,
     136,     0,    17,     0,    18,    19,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,     0,     0,
       0,     0,     0,     0,    12,     0,    13,    14,     0,     0,
       0,     0,     0,     0,     0,    12,     0,    13,    14,     0,
      15,     0,   259,    16,     0,     0,     0,    17,     0,    18,
      19,    15,     0,     0,    16,     0,     0,     0,    17,     0,
      18,    19
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-174))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      56,     0,    54,    76,     0,   118,    72,    73,    86,   122,
      36,   130,    25,   119,     3,     0,     3,    60,    84,     3,
      86,    30,    21,    64,    80,    21,    39,   200,   101,     3,
      26,    27,    47,    65,   207,    91,    18,    19,    69,    64,
      71,    82,    83,    58,   157,    60,    59,    62,    91,    27,
      28,    63,    63,   119,    64,   228,    67,    63,    63,    66,
      72,    57,    67,    71,    65,    74,    72,    68,    63,    51,
      72,    66,    25,    26,    31,    32,    91,    64,   130,    73,
      67,    65,    68,    72,    71,     3,     4,    69,    71,    71,
      64,   191,   192,   199,    71,   151,   169,    71,   154,   155,
      78,    79,    71,    67,    86,    80,    81,   163,    67,   165,
      71,   177,     3,   179,   180,   181,   182,    71,    73,   185,
     163,    66,   178,    67,   190,   191,   192,   140,    29,   195,
     236,    77,    75,   199,    76,     4,    70,    72,   257,    72,
      63,    66,   315,    71,    22,    67,   172,     4,   163,   205,
      67,     3,    73,   149,   327,     3,    72,    72,   331,    72,
     233,    73,    72,    72,    71,    73,    72,    72,    70,    72,
     236,     3,     4,    71,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   301,    72,
      67,   264,   265,   266,    21,    67,    63,   275,    72,   272,
      21,    72,    67,    67,   217,   257,    38,    39,    40,   275,
      72,   267,   268,   326,    67,    57,    67,   330,   214,    42,
      51,    53,   214,   219,   163,    58,   219,    62,   322,   217,
     177,   179,    64,   289,   185,   287,   328,   310,   190,    71,
     180,   182,   289,   181,   267,    77,   195,    -1,    80,    81,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,   314,   332,
      -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,   268,
       3,     4,   328,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    64,    65,    -1,    67,    -1,    -1,    -1,    71,    38,
      39,    -1,    -1,    -1,    77,    -1,    -1,    80,    81,    -1,
      -1,    84,    85,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,     6,
       7,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,
      40,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    -1,    55,    -1,    -1,    -1,    59,
      -1,    61,    62,    40,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    53,    77,    -1,    -1,
      80,    81,    -1,    -1,    84,    85,    -1,    64,    65,    66,
      -1,    -1,    -1,    -1,    71,     3,     4,    -1,     6,     7,
      77,    -1,    -1,    80,    81,    -1,    -1,    84,    85,    -1,
      18,    19,    -1,    -1,     3,     4,    -1,     6,     7,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    18,
      19,    -1,    40,     3,     4,    -1,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    68,    -1,    18,    19,
      -1,    40,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    -1,    71,    53,    -1,    -1,    -1,    -1,    77,
      40,    -1,    80,    81,    -1,    64,    84,    85,    67,    -1,
      -1,    -1,    71,    53,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    -1,    64,    84,    85,    -1,    -1,    -1,
      -1,    71,    72,    -1,    -1,     3,     4,    77,     6,     7,
      80,    81,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,
      18,    19,    -1,    -1,     3,     4,    -1,     6,     7,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    18,
      19,    -1,    40,     3,     4,    -1,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    68,    -1,    18,    19,
      -1,    40,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    53,    -1,    -1,    -1,    -1,    77,
      40,    -1,    80,    81,    -1,    64,    84,    85,    -1,    -1,
      -1,    -1,    71,    53,    -1,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    -1,    64,    84,    85,    -1,    -1,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      80,    81,    -1,    -1,    84,    85,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      52,    38,    39,    55,    -1,    -1,    -1,    59,    -1,    61,
      62,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    -1,
      72,    -1,    59,    -1,    61,    62,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    39,    -1,
      52,    -1,    54,    55,    -1,    -1,    -1,    59,    -1,    61,
      62,    52,    -1,    -1,    55,    -1,    -1,    -1,    59,    -1,
      61,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    36,    38,    39,    52,    55,    59,    61,    62,
      88,    89,    90,    91,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,    90,     3,    64,    67,    71,    97,
     112,   113,   114,   115,   102,   102,     3,    65,    97,    64,
     114,    63,    67,    65,    68,    99,    69,    71,    65,    98,
     104,   119,   120,   121,     3,    72,   113,   114,     3,     4,
       6,     7,    18,    19,    20,    22,    23,    24,    33,    34,
      35,    36,    37,    40,    53,    56,    57,    58,    60,    64,
      67,    71,    77,    80,    81,    84,    85,    99,   100,   101,
     102,   124,   125,   126,   128,   130,   131,   133,   134,   135,
     136,   137,   138,   139,   141,   142,   144,   146,   148,   149,
     150,   151,   152,   153,   154,   157,   160,   162,   164,     3,
      65,   117,   131,   129,   130,    17,    72,    92,    93,    94,
     102,   119,   114,   122,   123,    98,    66,   121,    72,    71,
     110,    71,   148,   148,    71,    71,   125,    71,    67,    67,
      67,   130,    71,    71,   148,    71,   127,   133,   148,    73,
       3,    95,    98,   130,    66,   125,    67,    30,    74,    29,
      75,    76,    77,    25,    26,   140,    27,    28,    78,    79,
     143,    31,    32,    80,    81,   145,    64,    82,    83,   147,
     110,   150,    18,    19,    51,    69,    86,   110,     4,   117,
     118,    70,    72,    72,    63,   114,    66,    63,    67,    71,
      92,   116,   111,   130,   158,   130,   161,    22,   110,    67,
       4,    95,   130,    73,   125,    67,    72,    96,    97,    72,
     135,   130,   136,   137,   138,   139,   141,   142,   144,   144,
     146,   150,   111,     3,   130,     3,   111,    63,    66,    54,
      94,   123,   116,    72,    73,    72,    72,    71,   111,    63,
      72,    72,    72,   125,   150,    73,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    68,   132,    70,    71,
      66,   117,    72,   125,   125,   125,   161,   101,   130,   155,
     156,   163,     3,     4,    67,   125,   133,   131,    72,   156,
      21,   159,    72,    67,    63,   110,    72,    72,    72,   125,
      67,   130,   111,    67,    67,   129,    67,   110,   111,   155,
      72,   110,   111,   125
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 140 "parser.yy"
    { TranslationUnit::instance().setDefinitionList((yyvsp[(1) - (1)].treeSequence)); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 145 "parser.yy"
    {
                (yyval.treeSequence) = new TreeSequence();
                if ((yyvsp[(1) - (1)].tree))
                    (yyval.treeSequence)->addTree((yyvsp[(1) - (1)].tree)); 
            }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 151 "parser.yy"
    {
                (yyval.treeSequence) = (yyvsp[(1) - (2)].treeSequence);
                if ((yyvsp[(2) - (2)].tree))
                    (yyval.treeSequence)->addTree((yyvsp[(2) - (2)].tree));
            }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 159 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].functionDef); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 160 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].declarationSequence); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 161 "parser.yy"
    { (yyval.tree) = new Pragma((yyvsp[(1) - (1)].str)); free((yyvsp[(1) - (1)].str)); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 166 "parser.yy"
    {
                DeclarationSpecifierList *dsl = (yyvsp[(1) - (3)].declarationSpecifierList);
                Declarator *di = (yyvsp[(2) - (3)].declarator);

                // Example: In byte **f() {}, dsl represents "byte" and
                // di represents **f. Hence, di contains a pointer level of 2,
                // which is applied to the TypeDesc found in dsl, i.e., "byte".
                // di also contains the name of the function, "f".
                //
                (yyval.functionDef) = new FunctionDef(di->getId(),
                                     di->processPointerLevel(dsl->getTypeDesc()),
                                     di->getFormalParamList(),
                                     dsl->isInterruptServiceFunction(),
                                     dsl->isAssemblyOnly());
                (yyval.functionDef)->setLineNo(di->getSourceFilename(), di->getLineNo());
                (yyval.functionDef)->setBody((yyvsp[(3) - (3)].compoundStmt));
                delete di;
                delete dsl;
            }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 188 "parser.yy"
    { (yyval.formalParamList) = (yyvsp[(1) - (1)].formalParamList); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 189 "parser.yy"
    { (yyval.formalParamList) = (yyvsp[(1) - (3)].formalParamList); (yyval.formalParamList)->endWithEllipsis(); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 193 "parser.yy"
    { (yyval.formalParamList) = new FormalParamList(); if ((yyvsp[(1) - (1)].formalParameter)) (yyval.formalParamList)->addTree((yyvsp[(1) - (1)].formalParameter)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 195 "parser.yy"
    { (yyval.formalParamList) = (yyvsp[(1) - (3)].formalParamList); if ((yyvsp[(3) - (3)].formalParameter)) (yyval.formalParamList)->addTree((yyvsp[(3) - (3)].formalParameter)); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 200 "parser.yy"
    {
                    (yyval.formalParameter) = (yyvsp[(2) - (2)].declarator)->createFormalParameter((yyvsp[(1) - (2)].declarationSpecifierList)->getTypeDesc());
                    delete (yyvsp[(1) - (2)].declarationSpecifierList);
                    delete (yyvsp[(2) - (2)].declarator);
                }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 208 "parser.yy"
    { (yyval.typeDesc) = (yyvsp[(1) - (1)].declarationSpecifierList)->getTypeDesc(); delete (yyvsp[(1) - (1)].declarationSpecifierList); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 210 "parser.yy"
    {
                    (yyval.typeDesc) = TranslationUnit::getTypeManager().getPointerTo((yyvsp[(1) - (2)].declarationSpecifierList)->getTypeDesc(), size_t((yyvsp[(2) - (2)].integer)));
                    delete (yyvsp[(1) - (2)].declarationSpecifierList);
                }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 217 "parser.yy"
    { (yyval.integer) = (yyvsp[(1) - (1)].integer); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 221 "parser.yy"
    { (yyval.integer) = 1; }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 222 "parser.yy"
    { (yyval.integer) = (yyvsp[(2) - (2)].integer) + 1; }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 226 "parser.yy"
    { (yyval.declarationSpecifierList) = (yyvsp[(2) - (2)].declarationSpecifierList); (yyval.declarationSpecifierList)->add((yyvsp[(1) - (2)].typeDesc)); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 227 "parser.yy"
    { (yyval.declarationSpecifierList) = new DeclarationSpecifierList(); (yyval.declarationSpecifierList)->add((yyvsp[(1) - (1)].typeDesc)); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 232 "parser.yy"
    { (yyval.compoundStmt) = (yyvsp[(2) - (3)].compoundStmt); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 236 "parser.yy"
    { (yyval.compoundStmt) = new CompoundStmt(); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 237 "parser.yy"
    { (yyval.compoundStmt) = (yyvsp[(1) - (1)].compoundStmt); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 244 "parser.yy"
    {
                            const TypeDesc *td = (yyvsp[(1) - (2)].declarationSpecifierList)->getTypeDesc();
                            assert(td->type != SIZELESS_TYPE);
                            if (td->type != CLASS_TYPE)
                                errormsg("declaring a variable with a type but without a variable name");
                            (yyval.declarationSequence) = new DeclarationSequence(td);
                            delete (yyvsp[(1) - (2)].declarationSpecifierList);
                        }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 253 "parser.yy"
    {
                            const TypeDesc *td = (yyvsp[(1) - (3)].declarationSpecifierList)->getTypeDesc();
                            assert(td->type != SIZELESS_TYPE);
                            TypeManager &tm = TranslationUnit::getTypeManager();
                            if ((yyvsp[(1) - (3)].declarationSpecifierList)->isTypeDefinition())
                            {
                                if (! (yyvsp[(1) - (3)].declarationSpecifierList)->isModifierLegalOnVariable())
                                    errormsg("illegal modifier used on typedef");
                                for (std::vector<Declarator *>::iterator it = (yyvsp[(2) - (3)].declaratorVector)->begin(); it != (yyvsp[(2) - (3)].declaratorVector)->end(); ++it)
                                    (void) tm.addTypeDef(td, *it);  // destroys the Declarator object
                                (yyval.declarationSequence) = NULL;
                            }
                            else if (0) //(yyvsp[(1) - (3)].declarationSpecifierList)->isExternDeclaration())
                            {
                                // Ignore the declarators in a 'extern' declaration because
                                // separate compilation is not supported.
                                for (std::vector<Declarator *>::iterator it = (yyvsp[(2) - (3)].declaratorVector)->begin(); it != (yyvsp[(2) - (3)].declaratorVector)->end(); ++it)
                                    delete *it;
                                (yyval.declarationSequence) = NULL;
                            }
                            else
                            {
                                (yyval.declarationSequence) = new DeclarationSequence(td);
                                
                                bool undefClass = (td->type == CLASS_TYPE
                                                   && TranslationUnit::instance().getClassDef(td->className) == NULL);

                                for (std::vector<Declarator *>::iterator it = (yyvsp[(2) - (3)].declaratorVector)->begin(); it != (yyvsp[(2) - (3)].declaratorVector)->end(); ++it)
                                {
                                    Declarator *d = *it;
                                    if (undefClass && d->getPointerLevel() == 0)
                                        errormsg("declaring `%s' of undefined type struct `%s'",
                                                 d->getId().c_str(), td->className.c_str());

                                    (yyval.declarationSequence)->processDeclarator(d, *(yyvsp[(1) - (3)].declarationSpecifierList));  // destroys the Declarator object
                                }
                            }
                            delete (yyvsp[(2) - (3)].declaratorVector);  // destroy the Declarator vector
                            delete (yyvsp[(1) - (3)].declarationSpecifierList);
                        }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 299 "parser.yy"
    { (yyval.declarationSpecifierList) = new DeclarationSpecifierList(); if ((yyvsp[(1) - (1)].integer) != -1) (yyval.declarationSpecifierList)->add(DeclarationSpecifierList::Specifier((yyvsp[(1) - (1)].integer))); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 301 "parser.yy"
    { (yyval.declarationSpecifierList) = (yyvsp[(2) - (2)].declarationSpecifierList); if ((yyvsp[(1) - (2)].integer) != -1) (yyval.declarationSpecifierList)->add(DeclarationSpecifierList::Specifier((yyvsp[(1) - (2)].integer))); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 303 "parser.yy"
    { (yyval.declarationSpecifierList) = new DeclarationSpecifierList(); (yyval.declarationSpecifierList)->add((yyvsp[(1) - (1)].typeDesc)); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 305 "parser.yy"
    { (yyval.declarationSpecifierList) = (yyvsp[(2) - (2)].declarationSpecifierList); (yyval.declarationSpecifierList)->add((yyvsp[(1) - (2)].typeDesc)); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 309 "parser.yy"
    { (yyval.integer) = DeclarationSpecifierList::INTERRUPT_SPEC; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 310 "parser.yy"
    { (yyval.integer) = DeclarationSpecifierList::TYPEDEF_SPEC; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 311 "parser.yy"
    { (yyval.integer) = DeclarationSpecifierList::ASSEMBLY_ONLY_SPEC; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 312 "parser.yy"
    { (yyval.integer) = -1; /* not supported, ignored */ }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 313 "parser.yy"
    { (yyval.integer) = DeclarationSpecifierList::STATIC_SPEC; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 314 "parser.yy"
    { (yyval.integer) = DeclarationSpecifierList::EXTERN_SPEC; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 318 "parser.yy"
    { (yyval.typeDesc) = (yyvsp[(1) - (1)].typeDesc); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 319 "parser.yy"
    { (yyval.typeDesc) = (yyvsp[(1) - (1)].typeDesc); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 320 "parser.yy"
    { (yyval.typeDesc) = TranslationUnit::getTypeManager().getClassType((yyvsp[(2) - (2)].str), (yyvsp[(1) - (2)].integer) == UNION, true); free((yyvsp[(2) - (2)].str)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 321 "parser.yy"
    { (yyval.typeDesc) = (yyvsp[(1) - (1)].typeDesc); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 326 "parser.yy"
    {
                        ClassDef *classDef = (yyvsp[(4) - (5)].classDef);
                        assert(classDef);
                        classDef->setName((yyvsp[(2) - (5)].str));
                        classDef->setUnion((yyvsp[(1) - (5)].integer) == UNION);
                        TranslationUnit::instance().getGlobalScope().declareClass(classDef);
                        const TypeDesc *td = TranslationUnit::getTypeManager().getClassType((yyvsp[(2) - (5)].str), (yyvsp[(1) - (5)].integer) == UNION, true);
                        assert(td);
                        (yyval.typeDesc) = td;
                        free((yyvsp[(2) - (5)].str));
                    }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 338 "parser.yy"
    {
                        string anonStructName = "AnonStruct_" + (yyvsp[(3) - (4)].classDef)->getLineNo();
                        ClassDef *classDef = (yyvsp[(3) - (4)].classDef);
                        assert(classDef);
                        classDef->setName(anonStructName);
                        classDef->setUnion((yyvsp[(1) - (4)].integer) == UNION);
                        TranslationUnit::instance().getGlobalScope().declareClass(classDef);
                        const TypeDesc *td = TranslationUnit::getTypeManager().getClassType(anonStructName, (yyvsp[(1) - (4)].integer) == UNION, true);
                        assert(td);
                        (yyval.typeDesc) = td;
                    }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 353 "parser.yy"
    { (yyval.integer) = STRUCT; }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 354 "parser.yy"
    { (yyval.integer) = UNION;  }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 358 "parser.yy"
    { (yyval.typeDesc) = TranslationUnit::getTypeManager().getIntType(WORD_TYPE, true); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 359 "parser.yy"
    { (yyval.typeDesc) = TranslationUnit::getTypeManager().getIntType(BYTE_TYPE, true); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 360 "parser.yy"
    { (yyval.typeDesc) = TranslationUnit::getTypeManager().getIntType(WORD_TYPE, true); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 361 "parser.yy"
    { (yyval.typeDesc) = TranslationUnit::getTypeManager().getSizelessType(true);  }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 362 "parser.yy"
    { (yyval.typeDesc) = TranslationUnit::getTypeManager().getSizelessType(false); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 368 "parser.yy"
    { (yyval.typeDesc) = rejectTypeKeyword("long");   }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 369 "parser.yy"
    { (yyval.typeDesc) = rejectTypeKeyword("float");  }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 370 "parser.yy"
    { (yyval.typeDesc) = rejectTypeKeyword("double"); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 374 "parser.yy"
    { (yyval.typeDesc) = (yyvsp[(1) - (1)].typeDesc); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 375 "parser.yy"
    { (yyval.typeDesc) = TranslationUnit::getTypeManager().getVoidType(); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 379 "parser.yy"
    { (yyval.str) = strdup(sourceFilename.c_str()); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 383 "parser.yy"
    { (yyval.integer) = lineno; }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 387 "parser.yy"
    { (yyval.declaratorVector) = new std::vector<Declarator *>(); (yyval.declaratorVector)->push_back((yyvsp[(1) - (1)].declarator)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 388 "parser.yy"
    { (yyval.declaratorVector) = (yyvsp[(1) - (3)].declaratorVector); (yyval.declaratorVector)->push_back((yyvsp[(3) - (3)].declarator)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 394 "parser.yy"
    { (yyval.declarator) = (yyvsp[(1) - (1)].declarator); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 395 "parser.yy"
    { (yyval.declarator) = (yyvsp[(1) - (3)].declarator); (yyval.declarator)->setInitExpr((yyvsp[(3) - (3)].tree)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 399 "parser.yy"
    {
                                            (yyval.declarator) = (yyvsp[(2) - (2)].declarator);
                                            for (int i = 0; i < (yyvsp[(1) - (2)].integer); ++i)
                                                (yyval.declarator)->incPointerLevel();
                                        }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 404 "parser.yy"
    { (yyval.declarator) = (yyvsp[(1) - (1)].declarator); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 409 "parser.yy"
    {
                (yyval.declarator) = new Declarator((yyvsp[(1) - (1)].str), sourceFilename, lineno);
                free((yyvsp[(1) - (1)].str));
            }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 414 "parser.yy"
    {
                (yyval.declarator) = new Declarator(string(), sourceFilename, lineno);
            }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 418 "parser.yy"
    {
                (yyval.declarator) = (yyvsp[(1) - (4)].declarator);
                (yyval.declarator)->addArraySizeExpr((yyvsp[(3) - (4)].tree));
            }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 423 "parser.yy"
    {
                (yyval.declarator) = (yyvsp[(1) - (4)].declarator);
                (yyval.declarator)->setFormalParamList((yyvsp[(3) - (4)].formalParamList));
            }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 428 "parser.yy"
    {
                (yyval.declarator) = (yyvsp[(1) - (3)].declarator);
                (yyval.declarator)->setFormalParamList(new FormalParamList());
            }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 434 "parser.yy"
    {
                (yyval.declarator) = (yyvsp[(1) - (4)].declarator);
                (yyval.declarator)->setFormalParamList(new FormalParamList());
            }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 439 "parser.yy"
    {
                (yyval.declarator) = new Declarator((yyvsp[(3) - (7)].str), sourceFilename, lineno);
                (yyval.declarator)->setAsFunctionPointer();
                free((yyvsp[(3) - (7)].str));
            }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 445 "parser.yy"
    {
                (yyval.declarator) = new Declarator(string(), sourceFilename, lineno);
                (yyval.declarator)->setAsFunctionPointer();
            }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 452 "parser.yy"
    { (yyval.formalParamList) = new FormalParamList(); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 453 "parser.yy"
    { (yyval.formalParamList) = (yyvsp[(1) - (1)].formalParamList);   }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 457 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 458 "parser.yy"
    { (yyval.tree) = (yyvsp[(2) - (3)].treeSequence); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 459 "parser.yy"
    { (yyval.tree) = (yyvsp[(2) - (4)].treeSequence); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 463 "parser.yy"
    { (yyval.treeSequence) = new TreeSequence((yyvsp[(1) - (1)].tree)); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 464 "parser.yy"
    { (yyval.treeSequence) = (yyvsp[(1) - (3)].treeSequence); (yyval.treeSequence)->addTree((yyvsp[(3) - (3)].tree)); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 468 "parser.yy"
    { (yyval.classDef) = new ClassDef(); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 469 "parser.yy"
    { (yyval.classDef) = (yyvsp[(1) - (1)].classDef); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 474 "parser.yy"
    {
                    (yyval.classDef) = new ClassDef();
                    for (std::vector<ClassDef::ClassMember *>::iterator it = (yyvsp[(1) - (1)].classMemberList)->begin(); it != (yyvsp[(1) - (1)].classMemberList)->end(); ++it)
                        (yyval.classDef)->addDataMember(*it);
                    delete (yyvsp[(1) - (1)].classMemberList);  // destroy the std::vector<ClassDef::ClassMember *>
                }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 481 "parser.yy"
    {
                    (yyval.classDef) = (yyvsp[(1) - (2)].classDef);
                    for (std::vector<ClassDef::ClassMember *>::iterator it = (yyvsp[(2) - (2)].classMemberList)->begin(); it != (yyvsp[(2) - (2)].classMemberList)->end(); ++it)
                        (yyval.classDef)->addDataMember(*it);
                    delete (yyvsp[(2) - (2)].classMemberList);  // destroy the std::vector<ClassDef::ClassMember *>
                }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 491 "parser.yy"
    {
                    // Return a tree sequence of ClassMembers defined by struct_declarator_list.
                    const TypeDesc *td = (yyvsp[(1) - (3)].declarationSpecifierList)->getTypeDesc(); 
                    (yyval.classMemberList) = new std::vector<ClassDef::ClassMember *>();
                    for (std::vector<Declarator *>::iterator it = (yyvsp[(2) - (3)].declaratorVector)->begin(); it != (yyvsp[(2) - (3)].declaratorVector)->end(); ++it)
                    {
                        Declarator *declarator = *it;
                        ClassDef::ClassMember *member = new ClassDef::ClassMember(
                                                                declarator->processPointerLevel(td),
                                                                declarator);  // Declarator now owned by 'member'
                        (yyval.classMemberList)->push_back(member);
                    }
                    delete (yyvsp[(1) - (3)].declarationSpecifierList);
                    delete (yyvsp[(2) - (3)].declaratorVector);  // destroy the vector<Declarator *>, but not the Declarators
                }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 508 "parser.yy"
    { (yyval.declaratorVector) = new std::vector<Declarator *>(); (yyval.declaratorVector)->push_back((yyvsp[(1) - (1)].declarator)); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 509 "parser.yy"
    { (yyval.declaratorVector) = (yyvsp[(1) - (3)].declaratorVector); (yyval.declaratorVector)->push_back((yyvsp[(3) - (3)].declarator)); }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 513 "parser.yy"
    { (yyval.declarator) = (yyvsp[(1) - (1)].declarator); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 519 "parser.yy"
    { (yyval.compoundStmt) = new CompoundStmt(); if ((yyvsp[(1) - (1)].tree) != NULL) (yyval.compoundStmt)->addTree((yyvsp[(1) - (1)].tree)); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 520 "parser.yy"
    { (yyval.compoundStmt) = (yyvsp[(1) - (2)].compoundStmt); if ((yyvsp[(2) - (2)].tree) != NULL) (yyval.compoundStmt)->addTree((yyvsp[(2) - (2)].tree)); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 524 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 525 "parser.yy"
    { (yyval.tree) = ((yyvsp[(1) - (1)].declarationSequence) ? (yyvsp[(1) - (1)].declarationSequence) : new TreeSequence()); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 526 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].compoundStmt); }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 527 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 528 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 529 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 530 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 531 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 532 "parser.yy"
    { (yyval.tree) = new JumpStmt((yyvsp[(2) - (3)].str)); free((yyvsp[(2) - (3)].str)); }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 533 "parser.yy"
    { (yyval.tree) = new JumpStmt(JumpStmt::BRK, NULL); }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 534 "parser.yy"
    { (yyval.tree) = new JumpStmt(JumpStmt::CONT, NULL); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 535 "parser.yy"
    { (yyval.tree) = new JumpStmt(JumpStmt::RET, NULL); }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 536 "parser.yy"
    { (yyval.tree) = new JumpStmt(JumpStmt::RET, (yyvsp[(2) - (3)].tree)); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 538 "parser.yy"
    { (yyval.tree) = new AssemblerStmt((yyvsp[(3) - (7)].str), (yyvsp[(5) - (7)].str), true);
                          free((yyvsp[(3) - (7)].str)); free((yyvsp[(5) - (7)].str)); }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 541 "parser.yy"
    { (yyval.tree) = new AssemblerStmt((yyvsp[(3) - (7)].str), (yyvsp[(5) - (7)].str), false);
                          free((yyvsp[(3) - (7)].str)); free((yyvsp[(5) - (7)].str)); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 544 "parser.yy"
    { (yyval.tree) = new AssemblerStmt((yyvsp[(3) - (5)].str), "", false);
                          free((yyvsp[(3) - (5)].str)); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 546 "parser.yy"
    { (yyval.tree) = new AssemblerStmt(yytext); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 551 "parser.yy"
    {
                                      (yyval.tree) = new LabeledStmt((yyvsp[(1) - (5)].str), TranslationUnit::instance().generateLabel('L'), (yyvsp[(5) - (5)].tree));
                                      (yyval.tree)->setLineNo((yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].integer));
                                      free((yyvsp[(1) - (5)].str)); free((yyvsp[(2) - (5)].str));
                                    }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 556 "parser.yy"
    { (yyval.tree) = new LabeledStmt((yyvsp[(2) - (4)].tree), (yyvsp[(4) - (4)].tree)); }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 557 "parser.yy"
    { (yyval.tree) = new LabeledStmt((yyvsp[(3) - (3)].tree)); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 561 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 565 "parser.yy"
    { (yyval.tree) = new TreeSequence(); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 566 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (2)].tree); }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 570 "parser.yy"
    { (yyval.tree) = NULL; }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 571 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 575 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 579 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 581 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr((yyvsp[(4) - (5)].binop), (yyvsp[(1) - (5)].tree), (yyvsp[(5) - (5)].tree)); free((yyvsp[(2) - (5)].str)); }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 585 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::ASSIGNMENT; }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 586 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::INC_ASSIGN; }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 587 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::DEC_ASSIGN; }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 588 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::MUL_ASSIGN; }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 589 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::DIV_ASSIGN; }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 590 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::MOD_ASSIGN; }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 591 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::XOR_ASSIGN; }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 592 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::AND_ASSIGN; }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 593 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::OR_ASSIGN; }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 594 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::LEFT_ASSIGN; }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 595 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::RIGHT_ASSIGN; }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 599 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 601 "parser.yy"
    { (yyval.tree) = new ConditionalExpr((yyvsp[(1) - (5)].tree), (yyvsp[(3) - (5)].tree), (yyvsp[(5) - (5)].tree)); }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 605 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 607 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr(BinaryOpExpr::LOGICAL_OR, (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 611 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 613 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr(BinaryOpExpr::LOGICAL_AND, (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 617 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 619 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr(BinaryOpExpr::BITWISE_OR, (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 622 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 624 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr(BinaryOpExpr::BITWISE_XOR, (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 627 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 629 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr(BinaryOpExpr::BITWISE_AND, (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 632 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 634 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr((yyvsp[(2) - (3)].binop), (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 638 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::EQUALITY; }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 639 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::INEQUALITY; }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 643 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 644 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr((yyvsp[(2) - (3)].binop), (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 648 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 649 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr(
                                        BinaryOpExpr::LEFT_SHIFT, (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 651 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr(
                                        BinaryOpExpr::RIGHT_SHIFT, (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 656 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::INFERIOR; }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 657 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::INFERIOR_OR_EQUAL; }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 658 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::SUPERIOR; }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 659 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::SUPERIOR_OR_EQUAL; }
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 663 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 664 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr((yyvsp[(2) - (3)].binop), (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 668 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::ADD; }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 669 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::SUB; }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 673 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 674 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr((yyvsp[(2) - (3)].binop), (yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].tree)); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 678 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::MUL; }
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 679 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::DIV; }
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 680 "parser.yy"
    { (yyval.binop) = BinaryOpExpr::MOD; }
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 684 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 685 "parser.yy"
    { (yyval.tree) = new UnaryOpExpr((yyvsp[(1) - (2)].unop), (yyvsp[(2) - (2)].tree)); }
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 686 "parser.yy"
    { (yyval.tree) = new UnaryOpExpr(UnaryOpExpr::PREINC, (yyvsp[(2) - (2)].tree)); }
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 687 "parser.yy"
    { (yyval.tree) = new UnaryOpExpr(UnaryOpExpr::PREDEC, (yyvsp[(2) - (2)].tree)); }
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 688 "parser.yy"
    { (yyval.tree) = new UnaryOpExpr((yyvsp[(3) - (4)].typeDesc)); }
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 689 "parser.yy"
    { (yyval.tree) = new UnaryOpExpr(UnaryOpExpr::SIZE_OF, (yyvsp[(2) - (2)].tree)); }
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 693 "parser.yy"
    { (yyval.unop) = UnaryOpExpr::IDENTITY; }
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 694 "parser.yy"
    { (yyval.unop) = UnaryOpExpr::NEG; }
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 695 "parser.yy"
    { (yyval.unop) = UnaryOpExpr::ADDRESS_OF; }
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 696 "parser.yy"
    { (yyval.unop) = UnaryOpExpr::INDIRECTION; }
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 697 "parser.yy"
    { (yyval.unop) = UnaryOpExpr::BOOLEAN_NEG; }
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 698 "parser.yy"
    { (yyval.unop) = UnaryOpExpr::BITWISE_NOT; }
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 702 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 703 "parser.yy"
    { (yyval.tree) = new CastExpr((yyvsp[(2) - (4)].typeDesc), (yyvsp[(4) - (4)].tree)); }
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 712 "parser.yy"
    { IdentifierExpr *ie = dynamic_cast<IdentifierExpr *>((yyvsp[(1) - (1)].tree));
                  if (ie != NULL) {
                    (yyval.tree) = new VariableExpr(ie->getId());
                    (yyval.tree)->copyLineNo(*ie);
                    delete (yyvsp[(1) - (1)].tree);
                  }
                  else (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 722 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 724 "parser.yy"
    { (yyval.tree) = new FunctionCallExpr((yyvsp[(1) - (5)].tree), new TreeSequence());
                          free((yyvsp[(2) - (5)].str)); }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 727 "parser.yy"
    { (yyval.tree) = new FunctionCallExpr((yyvsp[(1) - (6)].tree), (yyvsp[(5) - (6)].treeSequence));
                          free((yyvsp[(2) - (6)].str)); }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 730 "parser.yy"
    { (yyval.tree) = new BinaryOpExpr(BinaryOpExpr::ARRAY_REF, (yyvsp[(1) - (4)].tree), (yyvsp[(3) - (4)].tree)); }
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 732 "parser.yy"
    { (yyval.tree) = new UnaryOpExpr(UnaryOpExpr::POSTINC, (yyvsp[(1) - (2)].tree)); }
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 734 "parser.yy"
    { (yyval.tree) = new UnaryOpExpr(UnaryOpExpr::POSTDEC, (yyvsp[(1) - (2)].tree)); }
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 736 "parser.yy"
    { (yyval.tree) = new ObjectMemberExpr((yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].str), true); free((yyvsp[(3) - (3)].str)); }
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 738 "parser.yy"
    { (yyval.tree) = new ObjectMemberExpr((yyvsp[(1) - (3)].tree), (yyvsp[(3) - (3)].str), false); free((yyvsp[(3) - (3)].str)); }
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 742 "parser.yy"
    { (yyval.tree) = new IdentifierExpr((yyvsp[(1) - (1)].str)); free((yyvsp[(1) - (1)].str)); }
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 743 "parser.yy"
    { (yyval.tree) = new IdentifierExpr("this"); }
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 744 "parser.yy"
    { (yyval.tree) = new WordConstantExpr((yyvsp[(1) - (1)].real), true, (yyvsp[(1) - (1)].real) <= 0x7FFF); }
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 745 "parser.yy"
    { (yyval.tree) = new WordConstantExpr((int8_t) (yyvsp[(1) - (1)].character), false, true); }
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 746 "parser.yy"
    { (yyval.tree) = new StringLiteralExpr((yyvsp[(1) - (1)].str)); free((yyvsp[(1) - (1)].str)); }
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 747 "parser.yy"
    { (yyval.tree) = (yyvsp[(2) - (3)].tree); }
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 751 "parser.yy"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 752 "parser.yy"
    {
                            (yyval.str) = (char *) malloc(strlen((yyvsp[(1) - (2)].str)) + strlen((yyvsp[(2) - (2)].str)) + 1);
                            strcpy((yyval.str), (yyvsp[(1) - (2)].str));
                            strcat((yyval.str), (yyvsp[(2) - (2)].str));
                            free((yyvsp[(1) - (2)].str)); free((yyvsp[(2) - (2)].str));
                        }
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 761 "parser.yy"
    { (yyval.treeSequence) = NULL; }
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 762 "parser.yy"
    { (yyval.treeSequence) = (yyvsp[(1) - (1)].treeSequence); }
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 766 "parser.yy"
    { (yyval.treeSequence) = new TreeSequence((yyvsp[(1) - (1)].tree)); }
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 767 "parser.yy"
    { (yyval.treeSequence) = (yyvsp[(1) - (3)].treeSequence); (yyval.treeSequence)->addTree((yyvsp[(3) - (3)].tree)); }
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 771 "parser.yy"
    { (yyval.tree) = new IfStmt((yyvsp[(3) - (6)].tree), (yyvsp[(5) - (6)].tree), (yyvsp[(6) - (6)].tree)); }
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 772 "parser.yy"
    { (yyval.tree) = new SwitchStmt((yyvsp[(3) - (5)].tree), (yyvsp[(5) - (5)].tree)); }
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 776 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 199:

/* Line 1806 of yacc.c  */
#line 780 "parser.yy"
    { (yyval.tree) = NULL; }
    break;

  case 200:

/* Line 1806 of yacc.c  */
#line 781 "parser.yy"
    { (yyval.tree) = (yyvsp[(2) - (2)].tree); }
    break;

  case 201:

/* Line 1806 of yacc.c  */
#line 785 "parser.yy"
    { (yyval.tree) = new WhileStmt((yyvsp[(3) - (5)].tree), (yyvsp[(5) - (5)].tree), false); }
    break;

  case 202:

/* Line 1806 of yacc.c  */
#line 789 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].tree); }
    break;

  case 203:

/* Line 1806 of yacc.c  */
#line 793 "parser.yy"
    { (yyval.tree) = new WhileStmt((yyvsp[(5) - (7)].tree), (yyvsp[(2) - (7)].tree), true); }
    break;

  case 204:

/* Line 1806 of yacc.c  */
#line 797 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (2)].treeSequence); }
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 798 "parser.yy"
    { (yyval.tree) = (yyvsp[(1) - (1)].declarationSequence); }
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 806 "parser.yy"
    { if ( (yyvsp[(5) - (16)].tree))  (yyvsp[(5) - (16)].tree)->setLineNo((yyvsp[(3) - (16)].str), (yyvsp[(4) - (16)].integer));
                                  if ( (yyvsp[(8) - (16)].tree))  (yyvsp[(8) - (16)].tree)->setLineNo((yyvsp[(6) - (16)].str), (yyvsp[(7) - (16)].integer));
                                  if ((yyvsp[(12) - (16)].treeSequence)) (yyvsp[(12) - (16)].treeSequence)->setLineNo((yyvsp[(10) - (16)].str), (yyvsp[(11) - (16)].integer));
                                  (yyvsp[(16) - (16)].tree)->setLineNo((yyvsp[(14) - (16)].str), (yyvsp[(15) - (16)].integer));
                                  (yyval.tree) = new ForStmt((yyvsp[(5) - (16)].tree), (yyvsp[(8) - (16)].tree), (yyvsp[(12) - (16)].treeSequence), (yyvsp[(16) - (16)].tree));
                                  free((yyvsp[(3) - (16)].str)); free((yyvsp[(6) - (16)].str)); free((yyvsp[(10) - (16)].str)); free((yyvsp[(14) - (16)].str));
                                }
    break;



/* Line 1806 of yacc.c  */
#line 3622 "parser.cc"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 815 "parser.yy"


