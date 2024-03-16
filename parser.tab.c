/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"
  
    /*definitions*/
    #include <bits/stdc++.h>
    #include "data.h"
	#include "symbol_table.cpp"
    using namespace std;

    extern int yylex();
    extern int yyparse();
    extern void yyrestart(FILE* file);
    extern FILE* yyin;
    extern int yylineno;
    extern char* yytext;
    void yyerror(string str);
    extern stack<int> indent_stack;

    char* numtochar( int num){
        string s="0";
        while(num>0){
            s.push_back(num%10+'0');
            num/=10;
        }
        reverse(s.begin(),s.end());
        int n=s.size();
        char* c= (char*)malloc(sizeof(char)*(n+1));
        for( int i=0;i<n;i++){  
            c[i]=s[i];
        }
        c[n]='\0';
        return c;
    }
    int chartonum(char * c){
        int i=0;
        int num=0;
        while(c[i]!='\0'){
            num*=10;
            num+=c[i]-'0';
            i++;
        }
        return num;
    } 
    string chartostring(char* c){
        string s;
        int i=0;
        while(c[i]!='\0'){
            s.push_back(c[i]);
            i++;
        }
        return s;
    }

#line 122 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NEWLINE = 258,
    ASYNC = 259,
    INDENT = 260,
    DEDENT = 261,
    ASSIGN_OPERATOR = 262,
    POWER_OPERATOR = 263,
    SHIFT_OPER = 264,
    FLOOR_DIV_OPER = 265,
    ARROW_OPER = 266,
    TYPE_HINT = 267,
    NAME = 268,
    IF = 269,
    ELSE = 270,
    ELIF = 271,
    WHILE = 272,
    FOR = 273,
    IN = 274,
    AND = 275,
    OR = 276,
    NOT = 277,
    BREAK = 278,
    CONTINUE = 279,
    RETURN = 280,
    CLASS = 281,
    DEF = 282,
    GLOBAL = 283,
    NONLOCAL = 284,
    ASSERT = 285,
    ATOM_KEYWORDS = 286,
    STRING = 287,
    NUMBER = 288,
    OPEN_BRACKET = 289,
    CLOSE_BRACKET = 290,
    EQUAL = 291,
    SEMI_COLON = 292,
    COLON = 293,
    COMMA = 294,
    PLUS = 295,
    MINUS = 296,
    MULTIPLY = 297,
    DIVIDE = 298,
    REMAINDER = 299,
    ATTHERATE = 300,
    NEGATION = 301,
    BIT_AND = 302,
    BIT_OR = 303,
    BIT_XOR = 304,
    DOT = 305,
    CURLY_OPEN = 306,
    CURLY_CLOSE = 307,
    SQUARE_OPEN = 308,
    SQUARE_CLOSE = 309,
    LESS_THAN = 310,
    GREATER_THAN = 311,
    EQUAL_EQUAL = 312,
    GREATER_THAN_EQUAL = 313,
    LESS_THAN_EQUAL = 314,
    NOT_EQUAL_ARROW = 315,
    NOT_EQUAL = 316,
    IS = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 53 "parser.y"

    struct node *elem;

#line 241 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  109
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   678

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  215
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  325

#define YYUNDEFTOK  2
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   123,   123,   128,   131,   134,   137,   142,   146,   149,
     152,   157,   163,   166,   171,   174,   179,   182,   187,   190,
     195,   199,   204,   207,   212,   215,   218,   221,   224,   229,
     232,   235,   240,   243,   248,   251,   256,   259,   264,   267,
     272,   275,   280,   285,   288,   291,   296,   300,   304,   307,
     312,   315,   319,   323,   328,   331,   335,   338,   342,   345,
     348,   351,   354,   357,   361,   365,   368,   373,   376,   379,
     382,   386,   389,   393,   396,   400,   403,   406,   411,   414,
     418,   421,   425,   428,   432,   435,   440,   443,   447,   450,
     455,   458,   463,   466,   471,   474,   477,   480,   483,   486,
     489,   492,   495,   498,   501,   506,   511,   514,   519,   522,
     527,   530,   535,   538,   543,   546,   549,   553,   556,   561,
     564,   567,   570,   573,   578,   581,   585,   588,   591,   595,
     598,   603,   606,   609,   614,   617,   620,   623,   626,   629,
     632,   635,   638,   641,   644,   648,   651,   656,   659,   662,
     666,   669,   673,   676,   681,   684,   687,   692,   695,   699,
     702,   706,   709,   712,   715,   718,   722,   725,   729,   732,
     736,   739,   743,   746,   750,   753,   757,   760,   763,   766,
     769,   772,   777,   780,   784,   787,   791,   794,   798,   801,
     806,   809,   812,   817,   820,   824,   827,   832,   835,   838,
     841,   844,   849,   852,   856,   859,   863,   866,   870,   873,
     877,   880,   883,   888,   892,   896
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NEWLINE", "ASYNC", "INDENT", "DEDENT",
  "ASSIGN_OPERATOR", "POWER_OPERATOR", "SHIFT_OPER", "FLOOR_DIV_OPER",
  "ARROW_OPER", "TYPE_HINT", "NAME", "IF", "ELSE", "ELIF", "WHILE", "FOR",
  "IN", "AND", "OR", "NOT", "BREAK", "CONTINUE", "RETURN", "CLASS", "DEF",
  "GLOBAL", "NONLOCAL", "ASSERT", "ATOM_KEYWORDS", "STRING", "NUMBER",
  "OPEN_BRACKET", "CLOSE_BRACKET", "EQUAL", "SEMI_COLON", "COLON", "COMMA",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "REMAINDER", "ATTHERATE",
  "NEGATION", "BIT_AND", "BIT_OR", "BIT_XOR", "DOT", "CURLY_OPEN",
  "CURLY_CLOSE", "SQUARE_OPEN", "SQUARE_CLOSE", "LESS_THAN",
  "GREATER_THAN", "EQUAL_EQUAL", "GREATER_THAN_EQUAL", "LESS_THAN_EQUAL",
  "NOT_EQUAL_ARROW", "NOT_EQUAL", "IS", "$accept", "file", "snippet",
  "funcdef", "parameters", "typedargslist", "typedarg", "tfpdef", "stmt",
  "simple_stmt", "small_stmt_list", "small_stmt", "expr_stmt",
  "eq_testlist_star_expr_plus", "annassign", "testlist_star_expr",
  "expr_choice_list", "expr_choice", "augassign", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "global_stmt",
  "nonlocal_stmt", "assert_stmt", "comma_name_star", "compound_stmt",
  "async_stmt", "async_choice", "if_stmt", "while_stmt", "for_stmt",
  "suite", "nts_star", "test", "or_test", "and_test_star", "and_test",
  "not_test_star", "not_test", "comparison", "comp_op", "star_expr",
  "expr", "xor_expr", "and_expr", "shift_expr", "arith_expr", "term",
  "term_choice", "factor", "factor_choice", "power", "atom_expr", "atom",
  "STRING_PLUS", "testlist_comp", "named_or_star_list", "named_or_star",
  "trailer", "subscriptlist", "subscriptlist_list", "subscript",
  "exprlist", "expr_or_star_expr_list", "expr_or_star_expr", "testlist",
  "testlist_list", "dictorsetmaker", "A", "A_list", "B", "B_list",
  "classdef", "arglist", "argument_list", "argument", "comp_iter",
  "sync_comp_for", "comp_for", "comp_if", "func_body_suite", "stmt_plus",
  "comma_test", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

#define YYPACT_NINF (-258)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-90)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,    40,    69,  -258,  -258,   579,   579,   602,   579,  -258,
    -258,   533,    16,    22,    24,    29,   579,  -258,    18,  -258,
     508,  -258,  -258,   625,  -258,    89,   483,    94,  -258,  -258,
      40,  -258,     8,  -258,  -258,  -258,    77,    59,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,  -258,    86,    83,    91,    90,    98,  -258,  -258,   442,
      80,    85,    92,    67,    82,  -258,   625,  -258,    25,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,    99,   107,  -258,  -258,
     113,   108,  -258,  -258,  -258,    45,   116,   112,   112,   114,
    -258,  -258,  -258,  -258,   125,   126,    30,  -258,   625,  -258,
     129,  -258,   117,    30,   132,    30,   135,  -258,   122,  -258,
    -258,  -258,   245,  -258,   533,   579,  -258,   579,   533,   579,
     579,   579,  -258,   159,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,   157,   625,   625,   625,   625,   625,   625,   625,  -258,
    -258,  -258,  -258,  -258,   625,  -258,   625,   182,   167,   556,
    -258,   280,   280,   579,   602,   390,   280,    26,     3,   168,
    -258,  -258,   579,  -258,  -258,   533,   164,   602,  -258,  -258,
    -258,   579,  -258,  -258,   441,  -258,   533,  -258,  -258,  -258,
    -258,   147,   148,  -258,  -258,   146,  -258,   172,   170,   176,
    -258,  -258,  -258,  -258,  -258,  -258,  -258,    82,    82,  -258,
    -258,   579,  -258,   579,    13,   153,   158,  -258,  -258,   579,
     160,   145,   162,  -258,   198,  -258,   128,   192,   171,  -258,
     173,   175,  -258,   174,     9,    -3,  -258,   183,   206,   312,
     112,  -258,  -258,  -258,   202,  -258,   129,  -258,  -258,  -258,
     533,   579,   579,  -258,  -258,   579,  -258,  -258,   406,  -258,
     579,  -258,   556,   355,   187,   579,   211,   189,   280,   280,
     194,   218,   222,   312,  -258,   223,   579,   199,   233,  -258,
    -258,  -258,   579,  -258,  -258,  -258,  -258,  -258,  -258,  -258,
     355,   103,   280,   201,   204,   280,   228,  -258,   280,  -258,
     207,  -258,  -258,  -258,   312,   355,    81,  -258,   240,  -258,
    -258,   280,   280,  -258,   212,  -258,   312,  -258,   130,   579,
    -258,  -258,  -258,  -258,   236,  -258,   280,  -258,   249,  -258,
      81,  -258,  -258,  -258,  -258
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,   144,   140,     0,     0,     0,     0,    46,
      47,    48,     0,     0,     0,     0,     0,   143,   145,   141,
       0,   126,   127,     0,   128,     0,     0,     0,     2,    61,
       4,    18,     0,    22,    24,    31,    32,    36,    38,    25,
      43,    44,    45,    26,    27,    28,    19,    63,    58,    59,
      60,    40,    80,     0,    82,     0,    86,    91,    41,    92,
     106,   108,   110,   112,   114,   117,     0,   125,   129,   131,
     142,    62,     5,    65,    64,    66,     0,     0,   171,   170,
       0,   166,   168,    90,    49,     0,     0,    50,    52,    54,
     146,   135,   152,   153,     0,   148,   150,   105,     0,   139,
     186,   187,     0,   184,   177,   188,   180,   137,     0,     1,
       6,    21,     0,    42,     0,     0,    29,     0,    37,     0,
       0,     0,   101,     0,    94,    95,    96,    97,    98,    99,
     100,   103,     0,     0,     0,     0,     0,     0,     0,   123,
     119,   121,   122,   120,     0,   124,     0,     0,     0,     0,
     132,     0,     0,     0,   167,     0,     0,     0,     0,     0,
      51,    53,     0,    55,   134,   149,     0,     0,   206,   147,
     183,     0,   138,   176,   178,   179,   181,   136,    20,    23,
      33,    32,    34,   174,    30,   172,    39,     0,    83,    87,
     102,   104,    93,   107,   109,   111,   113,   115,   116,   118,
     130,     0,   154,     0,   197,     0,   193,   195,   133,   162,
     161,     0,   157,   159,     0,    75,    67,    71,     0,   169,
       0,     0,   190,    16,     0,     0,    12,    14,     0,     0,
      56,   215,   151,   207,     0,   182,     0,   185,   186,   189,
       0,   173,     0,   200,   201,     0,   198,   155,   194,   163,
     164,   156,   158,     0,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,   210,
       7,    57,     0,    35,   175,    81,   199,   196,   165,   160,
     213,     0,     0,     0,     0,     0,    73,   191,     0,    17,
       0,    10,    13,    15,     0,     0,   204,   214,     0,    76,
      68,     0,     0,    72,     0,   192,     0,     8,     0,     0,
     205,   202,   203,    77,    78,    70,     0,     9,     0,   211,
     208,    79,    74,   212,   209
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -258,  -258,    21,   254,  -258,  -258,    -6,  -258,  -240,     0,
    -258,   149,  -258,   150,  -258,    -9,  -258,   142,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,   -81,  -258,  -258,  -258,
    -258,  -258,   260,   -96,   -48,    -1,  -116,  -258,   151,  -258,
      -2,   140,  -258,     1,     5,   154,   155,   161,  -258,    20,
    -258,   -56,  -258,  -258,  -258,  -258,   263,   256,  -258,   119,
    -258,  -258,  -258,    37,   133,  -258,   163,   165,  -258,  -258,
     127,  -258,   123,  -258,  -258,   152,  -258,    68,     7,   166,
     -87,  -258,  -217,  -257,  -258
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,    28,    29,   158,   225,   226,   227,    30,   215,
      32,    33,    34,    35,   116,    36,    37,    38,   117,    39,
      40,    41,    42,    43,    44,    45,   160,    46,    47,    74,
      48,    49,    50,   216,   256,    51,    52,    53,    54,    55,
      56,    57,   132,    58,    59,    60,    61,    62,    63,    64,
     144,    65,    66,    67,    68,    69,    70,    94,    95,    96,
     150,   211,   212,   213,    80,    81,    82,   184,   185,   102,
     103,   104,   105,   106,    71,   205,   206,   207,   310,   168,
     311,   312,   270,   281,   163
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    31,    84,   187,    76,    77,    83,   161,    78,   169,
     145,   111,    79,   280,   228,    89,   173,   166,   175,    92,
     262,    93,    72,   297,   100,    92,   101,    93,    97,    85,
      31,   167,   264,   146,   166,    86,   265,    87,   308,   223,
     280,   229,    88,     1,     2,   112,   291,   263,   167,   245,
      18,   110,     3,     4,     5,   280,   217,     6,     7,   147,
     222,   224,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   148,   136,   307,   149,   155,
      21,    22,    23,   156,   113,   166,    24,     7,   199,   317,
     200,    25,   139,    26,   109,   309,    13,    98,   118,   167,
     119,     3,     4,   170,   120,   181,   298,   137,   138,   299,
     121,     8,   -85,   114,   182,   115,   183,   246,   -89,   189,
      17,    18,    19,    20,   140,   141,   142,   143,   133,    21,
      22,    23,   153,   318,   134,    24,   319,   151,   193,   135,
      25,    99,    26,   254,   255,   152,   204,   154,   210,   271,
     157,   159,   183,   162,   204,    78,   296,   197,   198,    79,
     164,   231,   286,   287,    92,   165,    93,   171,    78,   172,
     235,   174,    79,   236,   176,   238,   177,   101,   190,   191,
     208,   230,   167,   114,   240,   241,   300,   242,   247,   303,
     201,   -84,   305,   320,     3,     4,   -88,   248,   250,   251,
     243,   252,   244,   253,     8,   314,   315,   257,   249,   258,
     260,   259,   261,    17,    18,    19,    20,   202,   267,   266,
     322,   272,    21,    22,   203,   282,   284,   285,    24,   269,
     289,   273,   288,    25,   290,    26,   223,   294,   295,   301,
     274,   275,   302,   304,   276,   306,   313,   204,   178,   278,
     316,   210,   255,    31,   283,   323,    73,     3,     4,   292,
     186,   179,    75,   269,   180,   293,   321,     8,     9,    10,
      11,   188,   192,    14,    15,    16,    17,    18,    19,    20,
      31,    90,   108,   214,   232,    21,    22,    23,   194,   279,
     195,    24,     3,     4,   269,    31,    25,   196,    26,   239,
     234,   237,     8,     9,    10,    11,   269,   221,    14,    15,
      16,    17,    18,    19,    20,   268,   277,   219,   218,     0,
      21,    22,    23,     0,     3,     4,    24,   324,     0,     0,
       0,    25,   233,    26,     8,     9,    10,    11,     0,     0,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,    21,    22,    23,     0,     0,     0,    24,     2,
       0,     0,     0,    25,     0,    26,     0,     3,     4,     5,
       0,     0,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,    21,    22,    23,   201,     0,
       0,    24,     3,     4,     0,     0,    25,     0,    26,     0,
       0,     0,     8,     0,   201,     0,     0,     0,     3,     4,
       0,    17,    18,    19,    20,   220,     0,     0,     8,     0,
      21,    22,   203,     0,     0,     0,    24,    17,    18,    19,
      20,    25,     0,    26,     0,     0,    21,    22,   203,    98,
       0,     0,    24,     3,     4,     0,     0,    25,     0,    26,
       0,   122,     0,     8,   123,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,    24,     0,     0,
       0,     0,    25,     0,    26,     3,     4,   124,   125,   126,
     127,   128,   129,   130,   131,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,     0,     0,
       3,     4,     0,    21,    22,    23,     0,     0,     0,    24,
       8,     0,     0,     0,    25,     0,    26,   107,     0,    17,
      18,    19,    20,    91,     0,     3,     4,     0,    21,    22,
      23,     0,     0,     0,    24,     8,     0,     0,     0,    25,
       0,    26,     0,     0,    17,    18,    19,    20,     3,     4,
       0,     0,     0,    21,    22,    23,     0,     0,     8,    24,
       0,     0,     0,     0,    25,     0,    26,    17,    18,    19,
      20,     3,     4,     0,   209,     0,    21,    22,     0,     0,
       0,     8,    24,     0,     0,     0,     0,    25,     0,    26,
      17,    18,    19,    20,     3,     4,     0,     0,     0,    21,
      22,     0,     0,     0,     0,    24,     0,     0,     0,     0,
      25,     0,    26,    17,    18,    19,    20,     3,     4,     0,
       0,     0,    21,    22,    23,     0,     0,     0,    24,     0,
       0,     0,     0,    25,     0,    26,    17,    18,    19,    20,
       0,     0,     0,     0,     0,    21,    22,     0,     0,     0,
       0,    24,     0,     0,     0,     0,    25,     0,    26
};

static const yytype_int16 yycheck[] =
{
       0,     1,    11,   119,     5,     6,     8,    88,     7,    96,
      66,     3,     7,   253,    11,    16,   103,     4,   105,    20,
      11,    20,     1,   280,    25,    26,    25,    26,    23,    13,
      30,    18,    35,     8,     4,    13,    39,    13,   295,    13,
     280,    38,    13,     3,     4,    37,   263,    38,    18,    36,
      32,    30,    12,    13,    14,   295,   152,    17,    18,    34,
     156,    35,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    50,     9,   294,    53,    34,
      40,    41,    42,    38,     7,     4,    46,    18,   144,   306,
     146,    51,    10,    53,     0,    14,    27,     8,    39,    18,
      14,    12,    13,    98,    21,   114,     3,    40,    41,     6,
      20,    22,    21,    36,   115,    38,   117,   204,    20,   121,
      31,    32,    33,    34,    42,    43,    44,    45,    48,    40,
      41,    42,    19,     3,    49,    46,     6,    38,   133,    47,
      51,    52,    53,    15,    16,    38,   147,    39,   149,   230,
      34,    39,   153,    39,   155,   154,   272,   137,   138,   154,
      35,   162,   258,   259,   165,    39,   165,    38,   167,    52,
     171,    39,   167,   174,    39,   176,    54,   176,    19,    22,
      13,    13,    18,    36,    36,    39,   282,    15,    35,   285,
       8,    21,   288,   309,    12,    13,    20,    39,    38,    54,
     201,    39,   203,     5,    22,   301,   302,    15,   209,    38,
      35,    38,    38,    31,    32,    33,    34,    35,    12,    36,
     316,    19,    40,    41,    42,    38,    15,    38,    46,   229,
      12,   240,    38,    51,    12,    53,    13,    38,     5,    38,
     241,   242,    38,    15,   245,    38,     6,   248,     3,   250,
      38,   252,    16,   253,   255,     6,     2,    12,    13,   265,
     118,   112,     2,   263,   114,   266,   314,    22,    23,    24,
      25,   120,   132,    28,    29,    30,    31,    32,    33,    34,
     280,    18,    26,     3,   165,    40,    41,    42,   134,   252,
     135,    46,    12,    13,   294,   295,    51,   136,    53,   176,
     167,   174,    22,    23,    24,    25,   306,   155,    28,    29,
      30,    31,    32,    33,    34,     3,   248,   154,   153,    -1,
      40,    41,    42,    -1,    12,    13,    46,   320,    -1,    -1,
      -1,    51,   166,    53,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    46,     4,
      -1,    -1,    -1,    51,    -1,    53,    -1,    12,    13,    14,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,     8,    -1,
      -1,    46,    12,    13,    -1,    -1,    51,    -1,    53,    -1,
      -1,    -1,    22,    -1,     8,    -1,    -1,    -1,    12,    13,
      -1,    31,    32,    33,    34,    35,    -1,    -1,    22,    -1,
      40,    41,    42,    -1,    -1,    -1,    46,    31,    32,    33,
      34,    51,    -1,    53,    -1,    -1,    40,    41,    42,     8,
      -1,    -1,    46,    12,    13,    -1,    -1,    51,    -1,    53,
      -1,    19,    -1,    22,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    -1,    53,    12,    13,    55,    56,    57,
      58,    59,    60,    61,    62,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    -1,    -1,
      12,    13,    -1,    40,    41,    42,    -1,    -1,    -1,    46,
      22,    -1,    -1,    -1,    51,    -1,    53,    54,    -1,    31,
      32,    33,    34,    35,    -1,    12,    13,    -1,    40,    41,
      42,    -1,    -1,    -1,    46,    22,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    31,    32,    33,    34,    12,    13,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    22,    46,
      -1,    -1,    -1,    -1,    51,    -1,    53,    31,    32,    33,
      34,    12,    13,    -1,    38,    -1,    40,    41,    -1,    -1,
      -1,    22,    46,    -1,    -1,    -1,    -1,    51,    -1,    53,
      31,    32,    33,    34,    12,    13,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    -1,    53,    31,    32,    33,    34,    12,    13,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    -1,    53,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    51,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    12,    13,    14,    17,    18,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    40,    41,    42,    46,    51,    53,    64,    65,    66,
      71,    72,    73,    74,    75,    76,    78,    79,    80,    82,
      83,    84,    85,    86,    87,    88,    90,    91,    93,    94,
      95,    98,    99,   100,   101,   102,   103,   104,   106,   107,
     108,   109,   110,   111,   112,   114,   115,   116,   117,   118,
     119,   137,    65,    66,    92,    95,    98,    98,   106,   107,
     127,   128,   129,   103,    78,    13,    13,    13,    13,    98,
     119,    35,    98,   106,   120,   121,   122,   107,     8,    52,
      98,   106,   132,   133,   134,   135,   136,    54,   120,     0,
      65,     3,    37,     7,    36,    38,    77,    81,    39,    14,
      21,    20,    19,    22,    55,    56,    57,    58,    59,    60,
      61,    62,   105,    48,    49,    47,     9,    40,    41,    10,
      42,    43,    44,    45,   113,   114,     8,    34,    50,    53,
     123,    38,    38,    19,    39,    34,    38,    34,    67,    39,
      89,    89,    39,   147,    35,    39,     4,    18,   142,   143,
     107,    38,    52,   143,    39,   143,    39,    54,     3,    74,
      76,    78,    98,    98,   130,   131,    80,    99,   101,   103,
      19,    22,   104,   107,   108,   109,   110,   112,   112,   114,
     114,     8,    35,    42,    98,   138,   139,   140,    13,    38,
      98,   124,   125,   126,     3,    72,    96,    96,   130,   129,
      35,   138,    96,    13,    35,    68,    69,    70,    11,    38,
      13,    98,   122,   142,   127,    98,    98,   133,    98,   135,
      36,    39,    15,    98,    98,    36,   143,    35,    39,    98,
      38,    54,    39,     5,    15,    16,    97,    15,    38,    38,
      35,    38,    11,    38,    35,    39,    36,    12,     3,    72,
     145,    89,    19,    78,    98,    98,    98,   140,    98,   126,
      71,   146,    38,    98,    15,    38,    96,    96,    38,    12,
      12,   145,    69,    98,    38,     5,    99,   146,     3,     6,
      96,    38,    38,    96,    15,    96,    38,   145,   146,    14,
     141,   143,   144,     6,    96,    96,    38,   145,     3,     6,
      99,    97,    96,     6,   141
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    65,    65,    66,    66,    66,
      66,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    74,    75,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    82,    82,    82,    83,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    90,    90,    90,    91,    92,    92,    93,    93,    93,
      93,    94,    94,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   106,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   114,   114,   115,   115,   115,   116,
     116,   117,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   119,   120,   120,   120,
     121,   121,   122,   122,   123,   123,   123,   124,   124,   125,
     125,   126,   126,   126,   126,   126,   127,   127,   128,   128,
     129,   129,   130,   130,   131,   131,   132,   132,   132,   132,
     132,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     137,   137,   137,   138,   138,   139,   139,   140,   140,   140,
     140,   140,   141,   141,   142,   142,   143,   143,   144,   144,
     145,   145,   145,   146,   146,   147
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     2,     5,     7,     8,
       6,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       3,     2,     1,     3,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     3,     2,     4,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     2,     3,     2,     3,     2,     3,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     4,     7,     5,
       8,     4,     7,     6,     9,     1,     4,     5,     4,     5,
       1,     5,     1,     3,     3,     1,     1,     3,     3,     1,
       2,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     3,     2,     3,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       1,     3,     1,     1,     2,     3,     3,     1,     2,     1,
       3,     1,     1,     2,     2,     3,     1,     2,     1,     3,
       1,     1,     1,     2,     1,     3,     2,     1,     2,     2,
       1,     2,     3,     2,     1,     3,     1,     1,     1,     3,
       4,     6,     7,     1,     2,     1,     3,     1,     2,     3,
       2,     2,     1,     1,     4,     5,     1,     2,     2,     3,
       1,     4,     5,     1,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 123 "parser.y"
              {
    
 }
#line 1753 "parser.tab.c"
    break;

  case 3:
#line 128 "parser.y"
                 {
       
    }
#line 1761 "parser.tab.c"
    break;

  case 4:
#line 131 "parser.y"
            { 
        
    }
#line 1769 "parser.tab.c"
    break;

  case 5:
#line 134 "parser.y"
                       { 
        
    }
#line 1777 "parser.tab.c"
    break;

  case 6:
#line 137 "parser.y"
                   {  
        
    }
#line 1785 "parser.tab.c"
    break;

  case 7:
#line 142 "parser.y"
                                                    {  
            

        }
#line 1794 "parser.tab.c"
    break;

  case 8:
#line 146 "parser.y"
                                                                         {  
            
        }
#line 1802 "parser.tab.c"
    break;

  case 9:
#line 149 "parser.y"
                                                                                         {  
            
        }
#line 1810 "parser.tab.c"
    break;

  case 10:
#line 152 "parser.y"
                                                                    {
            
        }
#line 1818 "parser.tab.c"
    break;

  case 11:
#line 157 "parser.y"
                                                     {  
            
            
        }
#line 1827 "parser.tab.c"
    break;

  case 12:
#line 163 "parser.y"
                            {  
            
        }
#line 1835 "parser.tab.c"
    break;

  case 13:
#line 166 "parser.y"
                                         {  
            
        }
#line 1843 "parser.tab.c"
    break;

  case 14:
#line 171 "parser.y"
                   {  
            
        }
#line 1851 "parser.tab.c"
    break;

  case 15:
#line 174 "parser.y"
                            {  
            
        }
#line 1859 "parser.tab.c"
    break;

  case 16:
#line 179 "parser.y"
             {  
            
        }
#line 1867 "parser.tab.c"
    break;

  case 17:
#line 182 "parser.y"
                               {  
                
        }
#line 1875 "parser.tab.c"
    break;

  case 18:
#line 187 "parser.y"
                        { 
           
        }
#line 1883 "parser.tab.c"
    break;

  case 19:
#line 190 "parser.y"
                            { 
            
        }
#line 1891 "parser.tab.c"
    break;

  case 20:
#line 195 "parser.y"
                                                {  
            
        
        }
#line 1900 "parser.tab.c"
    break;

  case 21:
#line 199 "parser.y"
                                   {  
            
        }
#line 1908 "parser.tab.c"
    break;

  case 22:
#line 204 "parser.y"
                                {   
            
        }
#line 1916 "parser.tab.c"
    break;

  case 23:
#line 207 "parser.y"
                                                     {  
           
        }
#line 1924 "parser.tab.c"
    break;

  case 24:
#line 212 "parser.y"
                            {  
           
        }
#line 1932 "parser.tab.c"
    break;

  case 25:
#line 215 "parser.y"
                        {  
           
        }
#line 1940 "parser.tab.c"
    break;

  case 26:
#line 218 "parser.y"
                            {  
            
        }
#line 1948 "parser.tab.c"
    break;

  case 27:
#line 221 "parser.y"
                            {  
            
        }
#line 1956 "parser.tab.c"
    break;

  case 28:
#line 224 "parser.y"
                            {  
            
        }
#line 1964 "parser.tab.c"
    break;

  case 29:
#line 229 "parser.y"
                                         {   
           
        }
#line 1972 "parser.tab.c"
    break;

  case 30:
#line 232 "parser.y"
                                                {  
            
        }
#line 1980 "parser.tab.c"
    break;

  case 31:
#line 235 "parser.y"
                                     { 
           
        }
#line 1988 "parser.tab.c"
    break;

  case 32:
#line 240 "parser.y"
                                               {  
            
        }
#line 1996 "parser.tab.c"
    break;

  case 33:
#line 243 "parser.y"
                                                              {  
           
        }
#line 2004 "parser.tab.c"
    break;

  case 34:
#line 248 "parser.y"
                        {  
            
        }
#line 2012 "parser.tab.c"
    break;

  case 35:
#line 251 "parser.y"
                                                {  
            
        }
#line 2020 "parser.tab.c"
    break;

  case 36:
#line 256 "parser.y"
                                     {  
          
        }
#line 2028 "parser.tab.c"
    break;

  case 37:
#line 259 "parser.y"
                                  {   
            
        }
#line 2036 "parser.tab.c"
    break;

  case 38:
#line 264 "parser.y"
                                { 
            
        }
#line 2044 "parser.tab.c"
    break;

  case 39:
#line 267 "parser.y"
                                                { 
            
        }
#line 2052 "parser.tab.c"
    break;

  case 40:
#line 272 "parser.y"
                    {  
            
        }
#line 2060 "parser.tab.c"
    break;

  case 41:
#line 275 "parser.y"
                      {  
            
        }
#line 2068 "parser.tab.c"
    break;

  case 42:
#line 280 "parser.y"
                            {  
           
        }
#line 2076 "parser.tab.c"
    break;

  case 43:
#line 285 "parser.y"
                        {  
            
        }
#line 2084 "parser.tab.c"
    break;

  case 44:
#line 288 "parser.y"
                            {  
            
        }
#line 2092 "parser.tab.c"
    break;

  case 45:
#line 291 "parser.y"
                         {  
            
        }
#line 2100 "parser.tab.c"
    break;

  case 46:
#line 296 "parser.y"
                    {  
            
        }
#line 2108 "parser.tab.c"
    break;

  case 47:
#line 300 "parser.y"
                            {  
            
        }
#line 2116 "parser.tab.c"
    break;

  case 48:
#line 304 "parser.y"
                        {  
            
        }
#line 2124 "parser.tab.c"
    break;

  case 49:
#line 307 "parser.y"
                                        {  
           
        }
#line 2132 "parser.tab.c"
    break;

  case 50:
#line 312 "parser.y"
                            {  
            
        }
#line 2140 "parser.tab.c"
    break;

  case 51:
#line 315 "parser.y"
                                      {   
            
        }
#line 2148 "parser.tab.c"
    break;

  case 52:
#line 319 "parser.y"
                                 { 
            
            
        }
#line 2157 "parser.tab.c"
    break;

  case 53:
#line 323 "parser.y"
                                        {  
            
        }
#line 2165 "parser.tab.c"
    break;

  case 54:
#line 328 "parser.y"
                          {  
            
        }
#line 2173 "parser.tab.c"
    break;

  case 55:
#line 331 "parser.y"
                                  {  
           
        }
#line 2181 "parser.tab.c"
    break;

  case 56:
#line 335 "parser.y"
                               {  
           
        }
#line 2189 "parser.tab.c"
    break;

  case 57:
#line 338 "parser.y"
                                        {  
            
        }
#line 2197 "parser.tab.c"
    break;

  case 58:
#line 342 "parser.y"
                            { 
            
        }
#line 2205 "parser.tab.c"
    break;

  case 59:
#line 345 "parser.y"
                       {  
           
        }
#line 2213 "parser.tab.c"
    break;

  case 60:
#line 348 "parser.y"
                       {  
            
        }
#line 2221 "parser.tab.c"
    break;

  case 61:
#line 351 "parser.y"
                       {  
            
        }
#line 2229 "parser.tab.c"
    break;

  case 62:
#line 354 "parser.y"
                       {  
           
        }
#line 2237 "parser.tab.c"
    break;

  case 63:
#line 357 "parser.y"
                       {  
            
        }
#line 2245 "parser.tab.c"
    break;

  case 64:
#line 361 "parser.y"
                                {  
            
        }
#line 2253 "parser.tab.c"
    break;

  case 65:
#line 365 "parser.y"
                        { 
            
        }
#line 2261 "parser.tab.c"
    break;

  case 66:
#line 368 "parser.y"
                    {  
            
        }
#line 2269 "parser.tab.c"
    break;

  case 67:
#line 373 "parser.y"
                                 {  
           
        }
#line 2277 "parser.tab.c"
    break;

  case 68:
#line 376 "parser.y"
                                                 {  
            
        }
#line 2285 "parser.tab.c"
    break;

  case 69:
#line 379 "parser.y"
                                          {  
            
        }
#line 2293 "parser.tab.c"
    break;

  case 70:
#line 382 "parser.y"
                                                          {
            
        }
#line 2301 "parser.tab.c"
    break;

  case 71:
#line 386 "parser.y"
                                     {  
            
        }
#line 2309 "parser.tab.c"
    break;

  case 72:
#line 389 "parser.y"
                                                   {   
           
        }
#line 2317 "parser.tab.c"
    break;

  case 73:
#line 393 "parser.y"
                                                  { 
            
        }
#line 2325 "parser.tab.c"
    break;

  case 74:
#line 396 "parser.y"
                                                                  { 
            
        }
#line 2333 "parser.tab.c"
    break;

  case 75:
#line 400 "parser.y"
                    { 
            
        }
#line 2341 "parser.tab.c"
    break;

  case 76:
#line 403 "parser.y"
                                            { 
            
        }
#line 2349 "parser.tab.c"
    break;

  case 77:
#line 406 "parser.y"
                                                    { 
            
        }
#line 2357 "parser.tab.c"
    break;

  case 78:
#line 411 "parser.y"
                                  {  
            
        }
#line 2365 "parser.tab.c"
    break;

  case 79:
#line 414 "parser.y"
                                          {  
            
        }
#line 2373 "parser.tab.c"
    break;

  case 80:
#line 418 "parser.y"
                { 
            
        }
#line 2381 "parser.tab.c"
    break;

  case 81:
#line 421 "parser.y"
                                        {  
            
        }
#line 2389 "parser.tab.c"
    break;

  case 82:
#line 425 "parser.y"
                     { 
            
        }
#line 2397 "parser.tab.c"
    break;

  case 83:
#line 428 "parser.y"
                                       {  
            
        }
#line 2405 "parser.tab.c"
    break;

  case 84:
#line 432 "parser.y"
                                          {
            
        }
#line 2413 "parser.tab.c"
    break;

  case 85:
#line 435 "parser.y"
                     { 
            
        }
#line 2421 "parser.tab.c"
    break;

  case 86:
#line 440 "parser.y"
                    {
            
        }
#line 2429 "parser.tab.c"
    break;

  case 87:
#line 443 "parser.y"
                                        {  
            
        }
#line 2437 "parser.tab.c"
    break;

  case 88:
#line 447 "parser.y"
                                            { 
            
        }
#line 2445 "parser.tab.c"
    break;

  case 89:
#line 450 "parser.y"
                     { 
            
        }
#line 2453 "parser.tab.c"
    break;

  case 90:
#line 455 "parser.y"
                         { 
            
        }
#line 2461 "parser.tab.c"
    break;

  case 91:
#line 458 "parser.y"
                        { 
            
        }
#line 2469 "parser.tab.c"
    break;

  case 92:
#line 463 "parser.y"
                  {
            
        }
#line 2477 "parser.tab.c"
    break;

  case 93:
#line 466 "parser.y"
                                   { 
            
        }
#line 2485 "parser.tab.c"
    break;

  case 94:
#line 471 "parser.y"
                    {
        
    }
#line 2493 "parser.tab.c"
    break;

  case 95:
#line 474 "parser.y"
                    { 
       
     }
#line 2501 "parser.tab.c"
    break;

  case 96:
#line 477 "parser.y"
                    { 
        
     }
#line 2509 "parser.tab.c"
    break;

  case 97:
#line 480 "parser.y"
                            { 
        
     }
#line 2517 "parser.tab.c"
    break;

  case 98:
#line 483 "parser.y"
                        {
        
     }
#line 2525 "parser.tab.c"
    break;

  case 99:
#line 486 "parser.y"
                        {
        
      }
#line 2533 "parser.tab.c"
    break;

  case 100:
#line 489 "parser.y"
                   {
       
     }
#line 2541 "parser.tab.c"
    break;

  case 101:
#line 492 "parser.y"
            {  
        
    }
#line 2549 "parser.tab.c"
    break;

  case 102:
#line 495 "parser.y"
                { 
        
     }
#line 2557 "parser.tab.c"
    break;

  case 103:
#line 498 "parser.y"
            { 
        
     }
#line 2565 "parser.tab.c"
    break;

  case 104:
#line 501 "parser.y"
                { 
        
     }
#line 2573 "parser.tab.c"
    break;

  case 105:
#line 506 "parser.y"
                            { 
            
        }
#line 2581 "parser.tab.c"
    break;

  case 106:
#line 511 "parser.y"
                  { 
            
        }
#line 2589 "parser.tab.c"
    break;

  case 107:
#line 514 "parser.y"
                                  {  
            
        }
#line 2597 "parser.tab.c"
    break;

  case 108:
#line 519 "parser.y"
                   { 
            
        }
#line 2605 "parser.tab.c"
    break;

  case 109:
#line 522 "parser.y"
                                       {  
            
        }
#line 2613 "parser.tab.c"
    break;

  case 110:
#line 527 "parser.y"
                       { 
            
        }
#line 2621 "parser.tab.c"
    break;

  case 111:
#line 530 "parser.y"
                                        {  
            
        }
#line 2629 "parser.tab.c"
    break;

  case 112:
#line 535 "parser.y"
                         { 
                
            }
#line 2637 "parser.tab.c"
    break;

  case 113:
#line 538 "parser.y"
                                                 { 
                
             }
#line 2645 "parser.tab.c"
    break;

  case 114:
#line 543 "parser.y"
                 { 
                
            }
#line 2653 "parser.tab.c"
    break;

  case 115:
#line 546 "parser.y"
                                   { 
                
            }
#line 2661 "parser.tab.c"
    break;

  case 116:
#line 549 "parser.y"
                                    { 
                
             }
#line 2669 "parser.tab.c"
    break;

  case 117:
#line 553 "parser.y"
             {
            
        }
#line 2677 "parser.tab.c"
    break;

  case 118:
#line 556 "parser.y"
                                  {
            
         }
#line 2685 "parser.tab.c"
    break;

  case 119:
#line 561 "parser.y"
                            { 
            
        }
#line 2693 "parser.tab.c"
    break;

  case 120:
#line 564 "parser.y"
                        { 
            
        }
#line 2701 "parser.tab.c"
    break;

  case 121:
#line 567 "parser.y"
                        { 
            
        }
#line 2709 "parser.tab.c"
    break;

  case 122:
#line 570 "parser.y"
                        { 
           
        }
#line 2717 "parser.tab.c"
    break;

  case 123:
#line 573 "parser.y"
                           { 
            
        }
#line 2725 "parser.tab.c"
    break;

  case 124:
#line 578 "parser.y"
                                    {  
            
        }
#line 2733 "parser.tab.c"
    break;

  case 125:
#line 581 "parser.y"
                    { 
            
        }
#line 2741 "parser.tab.c"
    break;

  case 126:
#line 585 "parser.y"
                            {
            
        }
#line 2749 "parser.tab.c"
    break;

  case 127:
#line 588 "parser.y"
                     { 
            
        }
#line 2757 "parser.tab.c"
    break;

  case 128:
#line 591 "parser.y"
                     { 
            
        }
#line 2765 "parser.tab.c"
    break;

  case 129:
#line 595 "parser.y"
                        { 
            
        }
#line 2773 "parser.tab.c"
    break;

  case 130:
#line 598 "parser.y"
                                            { 
            
        }
#line 2781 "parser.tab.c"
    break;

  case 131:
#line 603 "parser.y"
                {  
            
        }
#line 2789 "parser.tab.c"
    break;

  case 132:
#line 606 "parser.y"
                            {  
            
        }
#line 2797 "parser.tab.c"
    break;

  case 133:
#line 609 "parser.y"
                             { 
            
        }
#line 2805 "parser.tab.c"
    break;

  case 134:
#line 614 "parser.y"
                                                { 
        
    }
#line 2813 "parser.tab.c"
    break;

  case 135:
#line 617 "parser.y"
                                    {
        
    }
#line 2821 "parser.tab.c"
    break;

  case 136:
#line 620 "parser.y"
                                                { 
        
    }
#line 2829 "parser.tab.c"
    break;

  case 137:
#line 623 "parser.y"
                                {
        
     }
#line 2837 "parser.tab.c"
    break;

  case 138:
#line 626 "parser.y"
                                                { 
        
    }
#line 2845 "parser.tab.c"
    break;

  case 139:
#line 629 "parser.y"
                                { 
        
     }
#line 2853 "parser.tab.c"
    break;

  case 140:
#line 632 "parser.y"
                {
        
     }
#line 2861 "parser.tab.c"
    break;

  case 141:
#line 635 "parser.y"
                    { 
        
    }
#line 2869 "parser.tab.c"
    break;

  case 142:
#line 638 "parser.y"
                        { 
       
    }
#line 2877 "parser.tab.c"
    break;

  case 143:
#line 641 "parser.y"
                        { 
        
    }
#line 2885 "parser.tab.c"
    break;

  case 144:
#line 644 "parser.y"
                    { 
        
     }
#line 2893 "parser.tab.c"
    break;

  case 145:
#line 648 "parser.y"
                        {
            
        }
#line 2901 "parser.tab.c"
    break;

  case 146:
#line 651 "parser.y"
                                { 
            
        }
#line 2909 "parser.tab.c"
    break;

  case 147:
#line 656 "parser.y"
                                            { 
            
        }
#line 2917 "parser.tab.c"
    break;

  case 148:
#line 659 "parser.y"
                                { 
            
        }
#line 2925 "parser.tab.c"
    break;

  case 149:
#line 662 "parser.y"
                                        { 
            
        }
#line 2933 "parser.tab.c"
    break;

  case 150:
#line 666 "parser.y"
                                        { 
            
        }
#line 2941 "parser.tab.c"
    break;

  case 151:
#line 669 "parser.y"
                                                    { 
            
        }
#line 2949 "parser.tab.c"
    break;

  case 152:
#line 673 "parser.y"
                        { 
            
        }
#line 2957 "parser.tab.c"
    break;

  case 153:
#line 676 "parser.y"
                        { 
            
        }
#line 2965 "parser.tab.c"
    break;

  case 154:
#line 681 "parser.y"
                                     { 
            
        }
#line 2973 "parser.tab.c"
    break;

  case 155:
#line 684 "parser.y"
                                              {
            
         }
#line 2981 "parser.tab.c"
    break;

  case 156:
#line 687 "parser.y"
                                                        {
            
         }
#line 2989 "parser.tab.c"
    break;

  case 157:
#line 692 "parser.y"
                                       {
            
        }
#line 2997 "parser.tab.c"
    break;

  case 158:
#line 695 "parser.y"
                                       { 
            
        }
#line 3005 "parser.tab.c"
    break;

  case 159:
#line 699 "parser.y"
                                    { 
            
        }
#line 3013 "parser.tab.c"
    break;

  case 160:
#line 702 "parser.y"
                                                { 
            
        }
#line 3021 "parser.tab.c"
    break;

  case 161:
#line 706 "parser.y"
                    { 
            
        }
#line 3029 "parser.tab.c"
    break;

  case 162:
#line 709 "parser.y"
                    {  
            
        }
#line 3037 "parser.tab.c"
    break;

  case 163:
#line 712 "parser.y"
                         { 
            
        }
#line 3045 "parser.tab.c"
    break;

  case 164:
#line 715 "parser.y"
                         { 
            
        }
#line 3053 "parser.tab.c"
    break;

  case 165:
#line 718 "parser.y"
                              {
            
        }
#line 3061 "parser.tab.c"
    break;

  case 166:
#line 722 "parser.y"
                                   {
            
        }
#line 3069 "parser.tab.c"
    break;

  case 167:
#line 725 "parser.y"
                                        { 
            
        }
#line 3077 "parser.tab.c"
    break;

  case 168:
#line 729 "parser.y"
                                            { 
            
        }
#line 3085 "parser.tab.c"
    break;

  case 169:
#line 732 "parser.y"
                                                            { 
            
        }
#line 3093 "parser.tab.c"
    break;

  case 170:
#line 736 "parser.y"
                                { 
            
        }
#line 3101 "parser.tab.c"
    break;

  case 171:
#line 739 "parser.y"
                        { 
            
        }
#line 3109 "parser.tab.c"
    break;

  case 172:
#line 743 "parser.y"
                           { 
            
        }
#line 3117 "parser.tab.c"
    break;

  case 173:
#line 746 "parser.y"
                                {
            
         }
#line 3125 "parser.tab.c"
    break;

  case 174:
#line 750 "parser.y"
                            {
            
        }
#line 3133 "parser.tab.c"
    break;

  case 175:
#line 753 "parser.y"
                                    { 
            
        }
#line 3141 "parser.tab.c"
    break;

  case 176:
#line 757 "parser.y"
                             {
            
        }
#line 3149 "parser.tab.c"
    break;

  case 177:
#line 760 "parser.y"
                    { 
            
        }
#line 3157 "parser.tab.c"
    break;

  case 178:
#line 763 "parser.y"
                          { 
            
        }
#line 3165 "parser.tab.c"
    break;

  case 179:
#line 766 "parser.y"
                           {
           
        }
#line 3173 "parser.tab.c"
    break;

  case 180:
#line 769 "parser.y"
                       {
            
         }
#line 3181 "parser.tab.c"
    break;

  case 181:
#line 772 "parser.y"
                            { 
            
        }
#line 3189 "parser.tab.c"
    break;

  case 182:
#line 777 "parser.y"
                    { 
            
        }
#line 3197 "parser.tab.c"
    break;

  case 183:
#line 780 "parser.y"
                            { 
            
        }
#line 3205 "parser.tab.c"
    break;

  case 184:
#line 784 "parser.y"
             { 
            
        }
#line 3213 "parser.tab.c"
    break;

  case 185:
#line 787 "parser.y"
                            { 
            
        }
#line 3221 "parser.tab.c"
    break;

  case 186:
#line 791 "parser.y"
         {
                 
        }
#line 3229 "parser.tab.c"
    break;

  case 187:
#line 794 "parser.y"
                        { 
               
        }
#line 3237 "parser.tab.c"
    break;

  case 188:
#line 798 "parser.y"
            { 
            
        }
#line 3245 "parser.tab.c"
    break;

  case 189:
#line 801 "parser.y"
                            { 
            
        }
#line 3253 "parser.tab.c"
    break;

  case 190:
#line 806 "parser.y"
                                      { 
            
        }
#line 3261 "parser.tab.c"
    break;

  case 191:
#line 809 "parser.y"
                                                                 { 
            
        }
#line 3269 "parser.tab.c"
    break;

  case 192:
#line 812 "parser.y"
                                                                         { 
           
        }
#line 3277 "parser.tab.c"
    break;

  case 193:
#line 817 "parser.y"
                           { 
            
        }
#line 3285 "parser.tab.c"
    break;

  case 194:
#line 820 "parser.y"
                                 { 
           
        }
#line 3293 "parser.tab.c"
    break;

  case 195:
#line 824 "parser.y"
                            { 
            
        }
#line 3301 "parser.tab.c"
    break;

  case 196:
#line 827 "parser.y"
                                        { 
            
        }
#line 3309 "parser.tab.c"
    break;

  case 197:
#line 832 "parser.y"
                {
               
        }
#line 3317 "parser.tab.c"
    break;

  case 198:
#line 835 "parser.y"
                            {
            
        }
#line 3325 "parser.tab.c"
    break;

  case 199:
#line 838 "parser.y"
                            { 
            
        }
#line 3333 "parser.tab.c"
    break;

  case 200:
#line 841 "parser.y"
                                { 
            
        }
#line 3341 "parser.tab.c"
    break;

  case 201:
#line 844 "parser.y"
                            {  
            
        }
#line 3349 "parser.tab.c"
    break;

  case 202:
#line 849 "parser.y"
                        { 
            
        }
#line 3357 "parser.tab.c"
    break;

  case 203:
#line 852 "parser.y"
                    { 
            
        }
#line 3365 "parser.tab.c"
    break;

  case 204:
#line 856 "parser.y"
                                            {
           
        }
#line 3373 "parser.tab.c"
    break;

  case 205:
#line 859 "parser.y"
                                                { 
            
        }
#line 3381 "parser.tab.c"
    break;

  case 206:
#line 863 "parser.y"
                            {
            
        }
#line 3389 "parser.tab.c"
    break;

  case 207:
#line 866 "parser.y"
                                { 
            
        }
#line 3397 "parser.tab.c"
    break;

  case 208:
#line 870 "parser.y"
                            {
            
        }
#line 3405 "parser.tab.c"
    break;

  case 209:
#line 873 "parser.y"
                                { 
           
        }
#line 3413 "parser.tab.c"
    break;

  case 210:
#line 877 "parser.y"
                                { 
            
        }
#line 3421 "parser.tab.c"
    break;

  case 211:
#line 880 "parser.y"
                                            { 
            
        }
#line 3429 "parser.tab.c"
    break;

  case 212:
#line 883 "parser.y"
                                                    { 
            
        }
#line 3437 "parser.tab.c"
    break;

  case 213:
#line 888 "parser.y"
                    {
            
        
        }
#line 3446 "parser.tab.c"
    break;

  case 214:
#line 892 "parser.y"
                            { 
            
        }
#line 3454 "parser.tab.c"
    break;

  case 215:
#line 896 "parser.y"
                        {
            
        }
#line 3462 "parser.tab.c"
    break;


#line 3466 "parser.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 900 "parser.y"


void yyerror(string str){
    fprintf(stderr, "Error: %s at line number %d offending token: %s\n", str.c_str(), yylineno, yytext);
    exit(1);
}

int main(int argc, char* argv[]){    
    yydebug=1;
    FILE* yyin; 
    bool inset = false, outset = false;
    indent_stack.push(0);

    for (int i=0; i< argc; i++){
        if (strcmp(argv[i], "-help") == 0){
            cerr<<"Usage: ./run.sh [-help] [-input <filename>] [-output <filename>] [-verbose]\n";
            cerr<< "Example: ./myASTGenerator -input input.txt -output output.txt\n";
        }
        else if (strcmp(argv[i], "-input") == 0){
            yyin = fopen(argv[i+1], "r");
            yyrestart(yyin);
            inset = true;
        }
        else if (strcmp(argv[i], "-output") == 0){
            freopen(argv[i+1], "w", stdout);
            outset = true;
        }
        else if (strcmp(argv[i], "-verbose") == 0){
            cerr<<"Verbose Output directed to parser.output\n";
        }
    }
    if (!inset){
        cerr<< "Input not set, see help\n";
        return 0;
    }
    if (!outset){
        cerr<< "Output not set, see help\n";
        return 0;
    } 
    yyparse();
    fclose(yyin); 
    return 0;

}
