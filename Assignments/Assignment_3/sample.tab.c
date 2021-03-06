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
#line 1 "sample.y" /* yacc.c:339  */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
#include <math.h>
#include "trying.h"
int  yylex(void);
void yyerror (char  *); 
typedef unsigned char utf8_t; 		

#line 77 "sample.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "sample.tab.h".  */
#ifndef YY_YY_SAMPLE_TAB_H_INCLUDED
# define YY_YY_SAMPLE_TAB_H_INCLUDED
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
    doctype = 258,
    text = 259,
    openhtml = 260,
    closehtml = 261,
    opentitle = 262,
    closetitle = 263,
    openhead = 264,
    closehead = 265,
    openbody = 266,
    closebody = 267,
    openp = 268,
    closep = 269,
    openbold = 270,
    closebold = 271,
    openit = 272,
    closeit = 273,
    openem = 274,
    closeem = 275,
    openstrong = 276,
    closestrong = 277,
    openmark = 278,
    closemark = 279,
    opensmall = 280,
    closesmall = 281,
    opendel = 282,
    closedel = 283,
    openins = 284,
    closeins = 285,
    opensub = 286,
    closesub = 287,
    opensup = 288,
    closesup = 289,
    opentable = 290,
    closetable = 291,
    opencaption = 292,
    closecaption = 293,
    openth = 294,
    closeth = 295,
    opentd = 296,
    closetd = 297,
    opentr = 298,
    closetr = 299,
    openh1 = 300,
    closeh1 = 301,
    openh2 = 302,
    closeh2 = 303,
    openh3 = 304,
    closeh3 = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "sample.y" /* yacc.c:355  */

	char* string;
	struct codes *test;
	struct top *testtt;

#line 174 "sample.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SAMPLE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 191 "sample.tab.c" /* yacc.c:358  */

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
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   111,   111,   111,   116,   119,   121,   122,   126,   126,
     135,   137,   138,   139,   140,   143,   143,   144,   144,   146,
     145,   151,   150,   156,   155,   163,   162,   168,   167,   172,
     171,   176,   175,   180,   179,   184,   183,   188,   187,   192,
     191,   195,   198,   201,   204,   207,   212,   217,   224,   229,
     233,   237,   241,   245,   249,   253,   257,   261,   262,   263,
     265,   282,   291,   297,   303,   306,   309,   312,   321,   328
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "doctype", "text", "openhtml",
  "closehtml", "opentitle", "closetitle", "openhead", "closehead",
  "openbody", "closebody", "openp", "closep", "openbold", "closebold",
  "openit", "closeit", "openem", "closeem", "openstrong", "closestrong",
  "openmark", "closemark", "opensmall", "closesmall", "opendel",
  "closedel", "openins", "closeins", "opensub", "closesub", "opensup",
  "closesup", "opentable", "closetable", "opencaption", "closecaption",
  "openth", "closeth", "opentd", "closetd", "opentr", "closetr", "openh1",
  "closeh1", "openh2", "closeh2", "openh3", "closeh3", "$accept", "html",
  "$@1", "inhtml", "head", "inhead", "body", "$@2", "inbody", "txt", "$@3",
  "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "$@15", "paragraph", "inpara", "heading", "table", "incaption",
  "intable", "rows", "col", YY_NULLPTR
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
     305
};
# endif

#define YYPACT_NINF -130

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-130)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -130,     6,     8,  -130,    35,    52,    61,    65,  -130,  -130,
      62,    63,  -130,  -130,    66,    68,  -130,    -3,    74,   -26,
      26,    53,    59,    75,    76,    77,    79,    81,    88,   -34,
      89,    90,    91,    84,    -3,    -3,    -3,    -3,  -130,    96,
      98,    33,    -2,    55,    60,   105,   106,   107,   108,   109,
     110,   101,   100,   113,   102,   114,    99,   103,    97,   104,
      94,    93,   120,    28,    92,  -130,    83,    85,    86,  -130,
    -130,  -130,  -130,  -130,   111,   112,  -130,   130,   131,  -130,
     121,   134,   122,   135,   124,   119,   118,   123,   117,   125,
    -130,  -130,   129,  -130,   132,  -130,  -130,  -130,  -130,  -130,
    -130,   115,   146,   146,   116,  -130,  -130,  -130,  -130,  -130,
    -130,   126,   127,    26,   133,    26,   136,    26,    26,    26,
      26,    26,    26,    33,   138,    33,   141,    33,    33,    33,
      33,    33,    33,   128,  -130,   137,   139,   128,    33,    33,
      26,    26,  -130,   147,  -130,   144,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,    28,    28,  -130,  -130,  -130,  -130,  -130,
      26,    26,    33,    33,  -130,  -130,  -130,  -130,  -130,  -130
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,     8,     7,
       0,     0,     3,     4,     0,     0,     5,    14,     0,    15,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    14,    14,    14,     6,     0,
       0,    41,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,     0,     0,     0,     9,
      10,    11,    12,    13,     0,     0,    16,     0,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    17,     0,    19,     0,    25,    27,    33,    39,    29,
      31,     0,     0,     0,     0,    60,    57,    58,    59,    35,
      37,     0,     0,    56,     0,    56,     0,    56,    56,    56,
      56,    56,    56,    41,     0,    41,     0,    41,    41,    41,
      41,    41,    41,     0,    69,     0,     0,    64,    41,    41,
      56,    56,    44,     0,    45,     0,    48,    49,    52,    55,
      50,    51,    18,    23,    20,    21,    26,    28,    34,    40,
      30,    32,    61,    66,    68,    63,    36,    38,    53,    54,
      56,    56,    41,    41,    65,    67,    47,    46,    24,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,    -1,   -41,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,   -14,  -130,  -130,  -130,  -129,  -125,
      64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,    11,    13,    14,    33,    34,
      41,   123,   125,   173,   172,   127,   128,   131,   132,   129,
     138,   139,   130,    35,    51,    36,    37,    64,    65,   104,
     135
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      76,    19,    42,    62,   162,    39,     3,    40,   165,    63,
      20,     4,    21,    43,    22,    44,    23,    45,    24,    46,
      25,    47,    26,    48,    27,    49,    28,    50,    79,    77,
      42,    78,    29,    70,    71,    72,    73,    19,   174,   175,
       5,    43,    30,    44,    31,    45,    32,    46,    21,    47,
      22,    48,    23,    49,    24,    50,    25,    52,    26,    80,
      27,     6,    28,    54,    82,     9,    15,   102,    10,   103,
      53,    12,    81,    16,    55,    83,    18,    17,    38,    56,
      57,    58,   152,    59,   154,    60,   156,   157,   158,   159,
     160,   161,    61,    66,    67,    68,    69,   166,   167,   142,
      74,   144,    75,   146,   147,   148,   149,   150,   151,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    94,    95,
      93,    97,    99,   100,   101,    96,   168,   169,   105,   106,
      98,   178,   179,   107,   111,   112,   108,   113,   114,   116,
     115,   118,   119,   109,   117,   121,   110,   124,   126,   120,
     134,   143,   145,   133,   153,   122,   176,   177,   140,   155,
     137,   141,   171,   170,     0,     0,     0,   136,     0,     0,
       0,    63,     0,     0,     0,     0,     0,   163,     0,     0,
       0,   164
};

static const yytype_int16 yycheck[] =
{
      41,     4,     4,    37,   133,    31,     0,    33,   137,    43,
      13,     3,    15,    15,    17,    17,    19,    19,    21,    21,
      23,    23,    25,    25,    27,    27,    29,    29,    42,    31,
       4,    33,    35,    34,    35,    36,    37,     4,   163,   164,
       5,    15,    45,    17,    47,    19,    49,    21,    15,    23,
      17,    25,    19,    27,    21,    29,    23,     4,    25,     4,
      27,     9,    29,     4,     4,     4,     4,    39,     7,    41,
      17,     6,    17,    10,    15,    15,     8,    11,     4,     4,
       4,     4,   123,     4,   125,     4,   127,   128,   129,   130,
     131,   132,     4,     4,     4,     4,    12,   138,   139,   113,
       4,   115,     4,   117,   118,   119,   120,   121,   122,     4,
       4,     4,     4,     4,     4,    14,    16,     4,     4,    20,
      18,    24,    28,    30,     4,    22,   140,   141,    36,    46,
      26,   172,   173,    48,     4,     4,    50,    16,     4,     4,
      18,    22,    24,    32,    20,    28,    34,    18,    16,    26,
       4,    18,    16,    38,    16,    30,   170,   171,    32,    18,
      44,    34,    18,    16,    -1,    -1,    -1,   103,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,    53,     0,     3,     5,     9,    54,    55,     4,
       7,    56,     6,    57,    58,     4,    10,    11,     8,     4,
      13,    15,    17,    19,    21,    23,    25,    27,    29,    35,
      45,    47,    49,    59,    60,    74,    76,    77,     4,    31,
      33,    61,     4,    15,    17,    19,    21,    23,    25,    27,
      29,    75,     4,    17,     4,    15,     4,     4,     4,     4,
       4,     4,    37,    43,    78,    79,     4,     4,     4,    12,
      59,    59,    59,    59,     4,     4,    60,    31,    33,    75,
       4,    17,     4,    15,     4,     4,     4,     4,     4,     4,
      14,    16,     4,    18,     4,    20,    22,    24,    26,    28,
      30,     4,    39,    41,    80,    36,    46,    48,    50,    32,
      34,     4,     4,    16,     4,    18,     4,    20,    22,    24,
      26,    28,    30,    62,    18,    63,    16,    66,    67,    70,
      73,    68,    69,    38,     4,    81,    81,    44,    71,    72,
      32,    34,    75,    18,    75,    16,    75,    75,    75,    75,
      75,    75,    60,    16,    60,    18,    60,    60,    60,    60,
      60,    60,    79,    40,    42,    79,    60,    60,    75,    75,
      16,    18,    65,    64,    80,    80,    75,    75,    60,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    53,    52,    54,    55,    56,    56,    58,    57,
      59,    59,    59,    59,    59,    61,    60,    62,    60,    63,
      60,    64,    60,    65,    60,    66,    60,    67,    60,    68,
      60,    69,    60,    70,    60,    71,    60,    72,    60,    73,
      60,    60,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      77,    78,    78,    79,    79,    80,    80,    80,    80,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     2,     3,     4,     1,     0,     4,
       2,     2,     2,     2,     0,     0,     3,     0,     5,     0,
       5,     0,     7,     0,     7,     0,     5,     0,     5,     0,
       5,     0,     5,     0,     5,     0,     6,     0,     6,     0,
       5,     0,     3,     2,     4,     4,     6,     6,     4,     4,
       4,     4,     4,     5,     5,     4,     0,     3,     3,     3,
       3,     4,     1,     4,     3,     4,     3,     4,     3,     1
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
#line 111 "sample.y" /* yacc.c:1646  */
    {    char *x= "\\documentclass[11pt]{article} \n\\usepackage{amsmath,textcomp,amssymb,geometry,graphicx,enumerate, ulem, xcolor} \n\\usepackage{algorithm} \n\\usepackage[noend]{algpseudocode}\n\\usepackage{hyperref}\n\\usepackage{tabto}\n\n" ;
printf( "%s\n" ,x);}
#line 1389 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 116 "sample.y" /* yacc.c:1646  */
    {}
#line 1395 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 119 "sample.y" /* yacc.c:1646  */
    {}
#line 1401 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 121 "sample.y" /* yacc.c:1646  */
    {printf("\n\\title{%s}", (yyvsp[0].string));free((yyvsp[0].string));}
#line 1407 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 122 "sample.y" /* yacc.c:1646  */
    {printf("\n\\title{%s}", (yyvsp[0].string)); free((yyvsp[0].string)); }
#line 1413 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "sample.y" /* yacc.c:1646  */
    {printf("\n\\begin{document} \n\\maketitle \n"); }
#line 1419 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 128 "sample.y" /* yacc.c:1646  */
    {
	//printf("\n\n%s\n\n", $2); 
	printf("\n\\end{document} \n"); 
	}
#line 1428 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "sample.y" /* yacc.c:1646  */
    {/*printf("%s",$1);*/}
#line 1434 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 137 "sample.y" /* yacc.c:1646  */
    {/*printf("para\n");$$=strdup(strcat(strdup($1),strdup($2)));*/ }
#line 1440 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 138 "sample.y" /* yacc.c:1646  */
    {/*printf("head\n");$$=strdup(strcat(strdup($1),strdup($2)));*/ }
#line 1446 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 139 "sample.y" /* yacc.c:1646  */
    {/*printf("fda\n");$$=strdup(strcat(strdup($1),strdup($2)));*/}
#line 1452 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 140 "sample.y" /* yacc.c:1646  */
    {}
#line 1458 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 143 "sample.y" /* yacc.c:1646  */
    {printf("%s", (yyvsp[0].string));}
#line 1464 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 144 "sample.y" /* yacc.c:1646  */
    {printf("\\textbf{%s}", (yyvsp[-1].string));}
#line 1470 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 146 "sample.y" /* yacc.c:1646  */
    {
								printf("\n\\textit{%s}\n", (yyvsp[-1].string));
										}
#line 1478 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 151 "sample.y" /* yacc.c:1646  */
    {
								printf("\n\\textit{\\textbf{%s}}\n", (yyvsp[-2].string));
										}
#line 1486 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 156 "sample.y" /* yacc.c:1646  */
    {
								printf("\n\\textbf{\\textit{%s}}\n", (yyvsp[-2].string));
										}
#line 1494 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 163 "sample.y" /* yacc.c:1646  */
    {
								printf("\n\\emph{%s}\n", (yyvsp[-1].string));	
								}
#line 1502 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 168 "sample.y" /* yacc.c:1646  */
    {
										printf("\n\\textbf{%s}\n", (yyvsp[-1].string));	
										}
#line 1510 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 172 "sample.y" /* yacc.c:1646  */
    {
											printf("\n\\sout{%s}\n", (yyvsp[-1].string));	
											}
#line 1518 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 176 "sample.y" /* yacc.c:1646  */
    {
											printf("\n\\underline{%s}\n", (yyvsp[-1].string));	
											}
#line 1526 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 180 "sample.y" /* yacc.c:1646  */
    {
											printf("\n\\colorbox{yellow}{%s}\n", (yyvsp[-1].string));	
											}
#line 1534 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 184 "sample.y" /* yacc.c:1646  */
    {
											printf("\n%s$_{%s}$\n", (yyvsp[-3].string),(yyvsp[-1].string));	
											}
#line 1542 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 188 "sample.y" /* yacc.c:1646  */
    {
											printf("\n%s$^{%s}$\n", (yyvsp[-3].string),(yyvsp[-1].string));	
											}
#line 1550 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 192 "sample.y" /* yacc.c:1646  */
    {
											printf("\n\\small{%s}\n", (yyvsp[-1].string));	
											}
#line 1558 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 195 "sample.y" /* yacc.c:1646  */
    {}
#line 1564 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 198 "sample.y" /* yacc.c:1646  */
    {}
#line 1570 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 201 "sample.y" /* yacc.c:1646  */
    {
								printf("\n\\par{%s}\n", (yyvsp[-1].string));
								}
#line 1578 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 204 "sample.y" /* yacc.c:1646  */
    {	
								printf("\n\\par{\\textbf{%s}}\n", (yyvsp[-2].string));
									}
#line 1586 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 208 "sample.y" /* yacc.c:1646  */
    {
								printf("\n\\par{\\textit{%s}}\n", (yyvsp[-2].string));
										}
#line 1594 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 213 "sample.y" /* yacc.c:1646  */
    {
								printf("\n\\par{\\textit{\\textbf{%s}}}\n", (yyvsp[-3].string));
										}
#line 1602 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 218 "sample.y" /* yacc.c:1646  */
    {
								printf("\n\\par{\\textbf{\\textit{%s}}}\n", (yyvsp[-3].string));
										}
#line 1610 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 225 "sample.y" /* yacc.c:1646  */
    {
								printf("\n\\par{\\emph{%s}}\n", (yyvsp[-2].string));	
								}
#line 1618 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 230 "sample.y" /* yacc.c:1646  */
    {
										printf("\n\\par{\\textbf{%s}}\n", (yyvsp[-2].string));	
										}
#line 1626 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 234 "sample.y" /* yacc.c:1646  */
    {
											printf("\n\\par{\\sout{%s}}\n", (yyvsp[-2].string));	
											}
#line 1634 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 238 "sample.y" /* yacc.c:1646  */
    {
											printf("\n\\par{\\underline{%s}}\n", (yyvsp[-2].string));	
											}
#line 1642 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 242 "sample.y" /* yacc.c:1646  */
    {
											printf("\n\\par{\\colorbox{yellow}{%s}}\n", (yyvsp[-2].string));	
											}
#line 1650 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 246 "sample.y" /* yacc.c:1646  */
    {
											printf("\n\\par{%s$_{%s}$}\n", (yyvsp[-4].string),(yyvsp[-2].string));	
											}
#line 1658 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 250 "sample.y" /* yacc.c:1646  */
    {
											printf("\n\\par{%s$^{%s}$}\n", (yyvsp[-4].string),(yyvsp[-2].string));	
											}
#line 1666 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 254 "sample.y" /* yacc.c:1646  */
    {
											printf("\n\\par{\\small%s}\n", (yyvsp[-2].string));	
											}
#line 1674 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 257 "sample.y" /* yacc.c:1646  */
    {}
#line 1680 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 261 "sample.y" /* yacc.c:1646  */
    {printf("\n\\section{%s}\n", (yyvsp[-1].string));}
#line 1686 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 262 "sample.y" /* yacc.c:1646  */
    {printf("\n\\subsection{%s}\n", (yyvsp[-1].string));}
#line 1692 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 263 "sample.y" /* yacc.c:1646  */
    {printf("\n\\subsubsection{%s}\n", (yyvsp[-1].string));}
#line 1698 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 266 "sample.y" /* yacc.c:1646  */
    {
					(yyval.test)->count = (yyvsp[-1].testtt)->count;																	
				//	$$->code = strdup($2->code);
					printf("\\begin{table}\n\\centering\n");
					printf("\n%s\n",(yyvsp[-1].testtt)->code1);
					printf("\\begin{tabular}{");	
					int temp;
					temp = (yyval.test)->count;
					for(int i=0; i<temp; i++){
						printf("|c|");	
					}
					printf("}");
					printf("\n%s\n",(yyvsp[-1].testtt)->code2);
					printf("\\end{tabular}\n\\end{table}\n");	
					}
#line 1718 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 282 "sample.y" /* yacc.c:1646  */
    {   
														char* temp;
														char* temp2;
														temp=strdup(strcat(strdup("\\caption{"),strdup((yyvsp[-2].string))));
														temp2=strdup(strcat(strdup(temp),strdup("}\n")));
														(yyval.testtt)->code1 = strdup(strcat(strdup(temp),strdup("}\n")));
														(yyval.testtt)->code2 = strdup((yyvsp[0].test)->code);
														(yyval.testtt)->count = (yyvsp[0].test)->count;
													}
#line 1732 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 291 "sample.y" /* yacc.c:1646  */
    {
				(yyval.testtt)->code2 = strdup((yyvsp[0].test)->code);
				(yyval.testtt)->count = (yyvsp[0].test)->count;
				(yyval.testtt)->code1 = strdup("");	
				}
#line 1742 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 297 "sample.y" /* yacc.c:1646  */
    {char* temp;
										temp=strdup(strcat(strdup((yyvsp[-2].test)->code),strdup(" \\\\ \n")));
										(yyval.test)->code=strdup(strcat(temp,strdup((yyvsp[0].test)->code)));
										(yyval.test)->count = (yyvsp[-2].test)->count;
										free((yyvsp[-2].test)->code);free((yyvsp[0].test)->code); 
										}
#line 1753 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 303 "sample.y" /* yacc.c:1646  */
    {(yyval.test)->code = strdup((yyvsp[-1].test)->code);   free((yyvsp[-1].test)->code);
									 }
#line 1760 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 306 "sample.y" /* yacc.c:1646  */
    {(yyval.test)->code = strdup(strcat(strdup(strcat(strdup((yyvsp[-2].test)->code),strdup(" & "))),strdup((yyvsp[0].test)->code)));
								(yyval.test)->count = (yyvsp[0].test)->count + 1;free((yyvsp[-2].test)->code);free((yyvsp[0].test)->code);
							}
#line 1768 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 309 "sample.y" /* yacc.c:1646  */
    {(yyval.test)->code = strdup((yyvsp[-1].test)->code);
							(yyval.test)->count = 1;free((yyvsp[-1].test)->code);
							}
#line 1776 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 312 "sample.y" /* yacc.c:1646  */
    {char* temp;
								char* temp2;
								char* temp3;
								temp=strdup(strcat(strdup("\\textbf{"),strdup((yyvsp[-2].test)->code)));
								temp2=strdup(strcat(strdup(temp),strdup("}")));
								temp3=strdup(strcat(strdup(temp2),strdup(" & ")));
								(yyval.test)->code=strdup(strcat(temp3,strdup((yyvsp[0].test)->code)));
								(yyval.test)->count = (yyvsp[0].test)->count + 1;free((yyvsp[-2].test)->code);free((yyvsp[0].test)->code);
							}
#line 1790 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 321 "sample.y" /* yacc.c:1646  */
    { char* temp;
							char* temp2;
							temp=strdup(strcat(strdup("\\textbf{"),strdup((yyvsp[-1].test)->code)));
							(yyval.test)->code = strdup(strcat(strdup(temp),strdup("}")));
							(yyval.test)->count = 1;free((yyvsp[-1].test)->code);
							}
#line 1801 "sample.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 328 "sample.y" /* yacc.c:1646  */
    {
		(yyval.test)->code = strdup((yyvsp[0].string));
		}
#line 1809 "sample.tab.c" /* yacc.c:1646  */
    break;


#line 1813 "sample.tab.c" /* yacc.c:1646  */
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
#line 334 "sample.y" /* yacc.c:1906  */



int main(){
	yyparse();
    return 0;
}


void yyerror(char* str)
{
    printf("\n%s",str);
}
