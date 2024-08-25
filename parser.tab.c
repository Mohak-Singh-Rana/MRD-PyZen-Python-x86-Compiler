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
//     #include "data.cpp"
//     #include "symbol_table.h"
    #include "symbol_table.cpp"
    #include "functions.cpp"
    using namespace std;

    extern int yylex();
    extern int yyparse();
    extern void yyrestart(FILE* file);
    extern FILE* yyin;
    extern int yylineno;
    extern char* yytext;
    void yyerror(string str);
    extern stack<int> indent_stack;

    int instCount;
    vector<vector<string>> instructions;
    vector<int> makelist(int i);
    void backpatch(vector<int> p, int i);
    void create_ins(int type,string i,string op,string arg1,string arg2);
    vector<int> merge(vector<int> p1, vector<int> p2);
    string newTemp();
    char* str_to_ch(string s);
    int tempCount;
    fstream code_out;

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

#line 136 "parser.tab.c"

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
    INDENT = 259,
    DEDENT = 260,
    ASSIGN_OPERATOR = 261,
    POWER_OPERATOR = 262,
    SHIFT_OPER = 263,
    FLOOR_DIV_OPER = 264,
    ARROW_OPER = 265,
    TYPE_HINT = 266,
    NAME = 267,
    IF = 268,
    ELSE = 269,
    ELIF = 270,
    WHILE = 271,
    FOR = 272,
    IN = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    BREAK = 277,
    CONTINUE = 278,
    RETURN = 279,
    CLASS = 280,
    DEF = 281,
    GLOBAL = 282,
    ATOM_KEYWORDS = 283,
    STRING = 284,
    NUMBER = 285,
    OPEN_BRACKET = 286,
    CLOSE_BRACKET = 287,
    EQUAL = 288,
    SEMI_COLON = 289,
    COLON = 290,
    COMMA = 291,
    PLUS = 292,
    MINUS = 293,
    MULTIPLY = 294,
    DIVIDE = 295,
    REMAINDER = 296,
    ATTHERATE = 297,
    NEGATION = 298,
    BIT_AND = 299,
    BIT_OR = 300,
    BIT_XOR = 301,
    DOT = 302,
    CURLY_OPEN = 303,
    CURLY_CLOSE = 304,
    SQUARE_OPEN = 305,
    SQUARE_CLOSE = 306,
    LESS_THAN = 307,
    GREATER_THAN = 308,
    EQUAL_EQUAL = 309,
    GREATER_THAN_EQUAL = 310,
    LESS_THAN_EQUAL = 311,
    NOT_EQUAL_ARROW = 312,
    NOT_EQUAL = 313,
    IS = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "parser.y"

    struct node *elem;

#line 252 "parser.tab.c"

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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   444

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  149
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

#define YYUNDEFTOK  2
#define YYMAXUTOK   314


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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   140,   147,   152,   156,   159,   162,   168,
     171,   174,   177,   182,   188,   191,   197,   200,   207,   211,
     217,   220,   225,   228,   233,   236,   242,   245,   248,   254,
     258,   263,   268,   271,   278,   281,   289,   292,   295,   300,
     305,   309,   312,   317,   321,   327,   331,   336,   339,   342,
     345,   348,   353,   359,   366,   374,   382,   392,   397,   401,
     404,   407,   412,   418,   425,   434,   440,   443,   451,   458,
     463,   466,   474,   481,   486,   492,   497,   500,   512,   515,
     518,   521,   524,   527,   530,   533,   536,   539,   542,   547,
     550,   558,   561,   569,   573,   581,   584,   592,   595,   601,
     608,   611,   620,   623,   626,   629,   632,   637,   643,   647,
     650,   653,   657,   660,   668,   671,   675,   681,   684,   688,
     691,   695,   699,   703,   707,   710,   714,   719,   723,   729,
     733,   737,   743,   746,   751,   754,   760,   763,   766,   771,
     774,   779,   782,   788,   791,   798,   801,   804,   809,   812
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NEWLINE", "INDENT", "DEDENT",
  "ASSIGN_OPERATOR", "POWER_OPERATOR", "SHIFT_OPER", "FLOOR_DIV_OPER",
  "ARROW_OPER", "TYPE_HINT", "NAME", "IF", "ELSE", "ELIF", "WHILE", "FOR",
  "IN", "AND", "OR", "NOT", "BREAK", "CONTINUE", "RETURN", "CLASS", "DEF",
  "GLOBAL", "ATOM_KEYWORDS", "STRING", "NUMBER", "OPEN_BRACKET",
  "CLOSE_BRACKET", "EQUAL", "SEMI_COLON", "COLON", "COMMA", "PLUS",
  "MINUS", "MULTIPLY", "DIVIDE", "REMAINDER", "ATTHERATE", "NEGATION",
  "BIT_AND", "BIT_OR", "BIT_XOR", "DOT", "CURLY_OPEN", "CURLY_CLOSE",
  "SQUARE_OPEN", "SQUARE_CLOSE", "LESS_THAN", "GREATER_THAN",
  "EQUAL_EQUAL", "GREATER_THAN_EQUAL", "LESS_THAN_EQUAL",
  "NOT_EQUAL_ARROW", "NOT_EQUAL", "IS", "$accept", "M", "N", "file",
  "snippet", "funcdef", "parameters", "typedargslist", "typedarg",
  "tfpdef", "stmt", "simple_stmt", "small_stmt_list", "small_stmt",
  "expr_stmt", "eq_testlist_star_expr_plus", "flow_stmt", "break_stmt",
  "continue_stmt", "return_stmt", "global_stmt", "comma_name_star",
  "compound_stmt", "if_stmt", "while_stmt", "for_stmt", "suite",
  "nts_star", "test", "or_test", "and_test_star", "and_test",
  "not_test_star", "not_test", "comparison", "comp_op", "expr", "xor_expr",
  "and_expr", "shift_expr", "arith_expr", "term", "term_choice", "factor",
  "factor_choice", "power", "atom_expr", "atom", "STRING_PLUS", "trailer",
  "testlist", "testlist_list", "classdef", "arglist", "argument_list",
  "argument", "func_body_suite", "stmt_plus", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF (-189)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-74)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     204,   204,  -189,  -189,   371,  -189,   394,   371,  -189,  -189,
     371,     8,    11,    35,  -189,    44,  -189,   302,  -189,  -189,
    -189,    40,   238,    94,  -189,  -189,   204,  -189,    19,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
      74,  -189,    76,    80,    87,    91,  -189,   139,    59,    66,
      73,    64,    37,  -189,   394,  -189,    10,  -189,  -189,  -189,
      86,  -189,  -189,    79,   371,   105,  -189,  -189,   -17,    95,
      92,  -189,  -189,  -189,    97,  -189,  -189,    81,  -189,  -189,
    -189,    21,   371,   371,   371,  -189,  -189,  -189,   109,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,   110,   394,   394,   394,
     394,   394,   394,   394,  -189,  -189,  -189,  -189,  -189,   394,
    -189,   394,   325,   121,   371,  -189,   371,  -189,   103,   371,
     348,   113,    -4,     5,   127,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,   114,   115,   371,   371,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,    37,    37,  -189,  -189,  -189,   116,   120,
     117,  -189,  -189,   107,  -189,   113,  -189,   111,   124,   130,
     160,  -189,  -189,   132,    52,    -7,  -189,   135,   154,   234,
      92,   371,   371,   152,   156,   371,  -189,   371,  -189,    20,
     113,   113,   113,   138,   279,   166,   167,   234,  -189,   168,
     371,   144,   177,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
      70,   169,   171,  -189,   113,   279,    65,  -189,   147,  -189,
    -189,  -189,   234,   279,   151,   371,  -189,   174,   155,  -189,
    -189,   194,  -189,   234,  -189,    85,  -189,   165,   173,   113,
    -189,  -189,   196,  -189,   113,  -189,  -189,  -189,  -189,  -189,
     113,   113,    20,  -189,    78,   175,  -189,  -189,   113,  -189
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,   126,   122,     0,     2,     0,     0,    39,    40,
      41,     0,     0,     0,   125,   127,   123,     0,   109,   110,
     111,     0,     0,     0,     4,    50,     6,    20,     0,    24,
      26,    27,    36,    37,    38,    28,    21,    47,    48,    49,
     134,    65,     0,    66,     0,    70,    75,    76,    89,    91,
      93,    95,    97,   100,     0,   108,   112,   114,   124,    32,
     132,    51,     7,     0,     0,     0,    74,    42,     0,     0,
      43,   128,   118,   134,     0,   121,   120,     0,     1,     8,
      23,     0,     0,     0,     0,     2,     2,    85,     0,    78,
      79,    80,    81,    82,    83,    84,    87,     0,     0,     0,
       0,     0,     0,     0,   106,   102,   104,   105,   103,     0,
     107,     0,     0,     0,     0,   115,   133,     2,     0,     0,
       0,     0,     0,     0,     0,    44,   117,   119,    22,    25,
      31,    33,    34,    29,     0,     0,    86,    88,    77,    90,
      92,    94,    96,    98,    99,   101,   113,   129,   143,     0,
     139,   141,   116,     0,   135,     0,     2,     0,     0,     0,
       0,    59,   136,    18,     0,     0,    14,    16,     0,     0,
      45,     0,     0,    67,    71,     0,   130,   140,   131,    52,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,   145,     9,    46,    35,    30,   144,   142,
       0,    55,    57,   137,     0,   148,     0,    19,     0,    11,
      15,    17,     0,     0,     0,     0,    54,     0,     0,   138,
     149,     0,    60,     0,    10,     0,     2,     0,     0,     0,
      61,    12,     0,   146,     0,     2,     2,    58,   147,    53,
       0,     0,    62,    56,     0,     0,    63,     2,     0,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,   -81,  -188,  -189,    30,  -189,  -189,  -189,    13,  -189,
    -110,     0,  -189,   122,  -189,    33,  -189,  -189,  -189,  -189,
    -189,    36,  -189,  -189,  -189,  -189,  -143,   -35,    -1,  -189,
    -189,    77,  -189,    -5,   125,  -189,     1,   119,   136,   118,
    -189,    18,  -189,   -44,  -189,  -189,  -189,  -189,   209,  -189,
     -11,  -189,  -189,   123,  -189,    61,  -157,  -186
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    64,   200,    23,    24,    25,   123,   165,   166,   167,
      26,   161,    28,    29,    30,   131,    31,    32,    33,    34,
      35,   125,    36,    37,    38,    39,   162,   216,    40,    41,
      42,    43,    44,    45,    46,    97,    47,    48,    49,    50,
      51,    52,   109,    53,    54,    55,    56,    57,    58,   115,
      59,    60,    61,   149,   150,   151,   194,   206
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    27,    66,    63,   134,   135,    74,    65,   163,    67,
     110,    77,   179,   217,   120,   168,    73,   111,   121,   220,
      68,    73,    80,    69,   128,   188,    27,   225,   164,   189,
     209,    62,     2,     3,    -3,    -3,   155,   201,   202,   203,
     169,   112,     7,     8,     9,    10,   104,    70,    13,    14,
      15,    16,    17,    81,   244,   224,    79,   113,    18,    19,
     114,   219,   186,   118,    20,   145,   231,   146,   221,    21,
     222,    22,   101,    15,   205,   180,   105,   106,   107,   108,
      82,   130,   132,   133,   214,   215,   237,   187,   232,    75,
     233,   239,   245,   215,    78,   205,    85,   242,   243,   139,
     -69,   102,   103,   205,    98,   249,    86,    83,   157,    84,
     -73,   148,    99,   153,   117,   154,   160,   100,    73,   148,
     143,   144,   116,   119,     2,     3,   122,   136,   124,   126,
     174,   137,   127,   152,     7,     8,     9,    10,   156,   170,
      13,    14,    15,    16,    17,   234,   181,   171,   172,   175,
      18,    19,   176,   177,   240,   241,    20,    87,   178,   182,
      88,    21,   183,    22,   184,   191,   248,   185,   190,   193,
     132,   197,   -68,   204,   198,   -72,   148,   207,   208,   212,
     163,   213,   223,    -3,    27,   218,   226,   193,   228,   211,
     229,    89,    90,    91,    92,    93,    94,    95,    96,   230,
     235,   238,   210,   129,   196,    27,   195,     1,   236,   246,
     247,   173,   193,    27,   227,     2,     3,     4,   140,   142,
       5,     6,   138,   193,    71,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,   141,   192,   199,     0,
       0,    18,    19,   159,     0,     2,     3,    20,     0,     2,
       3,     0,    21,     0,    22,     7,     8,     9,    10,     7,
       0,    13,    14,    15,    16,    17,    14,    15,    16,    17,
       0,    18,    19,     0,     0,    18,    19,    20,     0,     0,
       0,    20,    21,     0,    22,     0,    21,     0,    22,    76,
       2,     3,     4,     0,     0,     5,     6,     0,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     0,     0,     2,     3,     0,    18,    19,     0,     0,
       0,     0,    20,     7,     0,     0,     0,    21,     0,    22,
      14,    15,    16,    17,    72,     0,     2,     3,     0,    18,
      19,     0,     0,     0,     0,    20,     7,     0,     0,     0,
      21,     0,    22,    14,    15,    16,    17,   147,     0,     2,
       3,     0,    18,    19,     0,     0,     0,     0,    20,     7,
       0,     0,     0,    21,     0,    22,    14,    15,    16,    17,
     158,     0,     2,     3,     0,    18,    19,     0,     0,     0,
       0,    20,     7,     0,     0,     0,    21,     0,    22,    14,
      15,    16,    17,     0,     0,     2,     3,     0,    18,    19,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    21,
       0,    22,    14,    15,    16,    17,     0,     0,     0,     0,
       0,    18,    19,     0,     0,     0,     0,    20,     0,     0,
       0,     0,    21,     0,    22
};

static const yytype_int16 yycheck[] =
{
       0,     1,     7,     4,    85,    86,    17,     6,    12,    10,
      54,    22,   155,   201,    31,    10,    17,     7,    35,   205,
      12,    22,     3,    12,     3,    32,    26,   213,    32,    36,
     187,     1,    11,    12,    14,    15,   117,   180,   181,   182,
      35,    31,    21,    22,    23,    24,     9,    12,    27,    28,
      29,    30,    31,    34,   242,   212,    26,    47,    37,    38,
      50,   204,    10,    64,    43,   109,   223,   111,     3,    48,
       5,    50,     8,    29,   184,   156,    39,    40,    41,    42,
       6,    82,    83,    84,    14,    15,   229,    35,     3,    49,
       5,   234,    14,    15,     0,   205,    20,   240,   241,    98,
      20,    37,    38,   213,    45,   248,    19,    33,   119,    35,
      19,   112,    46,   114,    35,   116,     3,    44,   119,   120,
     102,   103,    36,    18,    11,    12,    31,    18,    36,    32,
     135,    21,    51,    12,    21,    22,    23,    24,    35,    12,
      27,    28,    29,    30,    31,   226,    35,    33,    33,    33,
      37,    38,    32,    36,   235,   236,    43,    18,    51,    35,
      21,    48,    32,    50,     4,    11,   247,    35,    33,   169,
     171,   172,    20,    35,   175,    19,   177,    11,    11,    35,
      12,     4,    35,    14,   184,    14,    35,   187,    14,   190,
      35,    52,    53,    54,    55,    56,    57,    58,    59,     5,
      35,     5,   189,    81,   171,   205,   170,     3,    35,   244,
      35,   134,   212,   213,   215,    11,    12,    13,    99,   101,
      16,    17,    97,   223,    15,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,   100,     3,   177,    -1,
      -1,    37,    38,   120,    -1,    11,    12,    43,    -1,    11,
      12,    -1,    48,    -1,    50,    21,    22,    23,    24,    21,
      -1,    27,    28,    29,    30,    31,    28,    29,    30,    31,
      -1,    37,    38,    -1,    -1,    37,    38,    43,    -1,    -1,
      -1,    43,    48,    -1,    50,    -1,    48,    -1,    50,    51,
      11,    12,    13,    -1,    -1,    16,    17,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    11,    12,    -1,    37,    38,    -1,    -1,
      -1,    -1,    43,    21,    -1,    -1,    -1,    48,    -1,    50,
      28,    29,    30,    31,    32,    -1,    11,    12,    -1,    37,
      38,    -1,    -1,    -1,    -1,    43,    21,    -1,    -1,    -1,
      48,    -1,    50,    28,    29,    30,    31,    32,    -1,    11,
      12,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,    21,
      -1,    -1,    -1,    48,    -1,    50,    28,    29,    30,    31,
      32,    -1,    11,    12,    -1,    37,    38,    -1,    -1,    -1,
      -1,    43,    21,    -1,    -1,    -1,    48,    -1,    50,    28,
      29,    30,    31,    -1,    -1,    11,    12,    -1,    37,    38,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    11,    12,    13,    16,    17,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    37,    38,
      43,    48,    50,    63,    64,    65,    70,    71,    72,    73,
      74,    76,    77,    78,    79,    80,    82,    83,    84,    85,
      88,    89,    90,    91,    92,    93,    94,    96,    97,    98,
      99,   100,   101,   103,   104,   105,   106,   107,   108,   110,
     111,   112,    64,    88,    61,    96,    93,    88,    12,    12,
      12,   108,    32,    88,   110,    49,    51,   110,     0,    64,
       3,    34,     6,    33,    35,    20,    19,    18,    21,    52,
      53,    54,    55,    56,    57,    58,    59,    95,    45,    46,
      44,     8,    37,    38,     9,    39,    40,    41,    42,   102,
     103,     7,    31,    47,    50,   109,    36,    35,    88,    18,
      31,    35,    31,    66,    36,    81,    32,    51,     3,    73,
      88,    75,    88,    88,    61,    61,    18,    21,    94,    96,
      97,    98,    99,   101,   101,   103,   103,    32,    88,   113,
     114,   115,    12,    88,    88,    61,    35,   110,    32,   113,
       3,    71,    86,    12,    32,    67,    68,    69,    10,    35,
      12,    33,    33,    91,    93,    33,    32,    36,    51,    86,
      61,    35,    35,    32,     4,    35,    10,    35,    32,    36,
      33,    11,     3,    71,   116,    81,    75,    88,    88,   115,
      62,    86,    86,    86,    35,    70,   117,    11,    11,   116,
      68,    88,    35,     4,    14,    15,    87,    62,    14,    86,
     117,     3,     5,    35,   116,   117,    35,    88,    14,    35,
       5,   116,     3,     5,    61,    35,    35,    86,     5,    86,
      61,    61,    86,    86,    62,    14,    87,    35,    61,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    64,    64,    64,    65,
      65,    65,    65,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    73,    74,
      74,    74,    74,    74,    75,    75,    76,    76,    76,    77,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    82,
      82,    82,    83,    83,    83,    84,    84,    85,    85,    86,
      86,    86,    87,    87,    87,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   100,   100,
     101,   101,   102,   102,   102,   102,   102,   103,   103,   104,
     104,   104,   105,   105,   106,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   108,   108,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   112,   113,
     113,   114,   114,   115,   115,   116,   116,   116,   117,   117
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     2,     2,     5,
       7,     6,     8,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     3,     2,     1,     3,     1,     1,     1,     3,
       5,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     2,     3,     1,     1,     1,
       1,     1,     5,    10,     7,     6,    11,     6,     9,     1,
       4,     5,     5,     7,    10,     1,     1,     4,     4,     1,
       1,     4,     4,     1,     2,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     3,     2,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     3,     1,     2,     1,     3,     4,     6,     7,     1,
       2,     1,     3,     1,     3,     1,     4,     5,     1,     2
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
#line 134 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal M");
        (yyval.elem)->ins = instCount+1;
}
#line 1660 "parser.tab.c"
    break;

  case 3:
#line 140 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal N");
        (yyval.elem)->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
#line 1670 "parser.tab.c"
    break;

  case 4:
#line 147 "parser.y"
              {
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 1678 "parser.tab.c"
    break;

  case 5:
#line 152 "parser.y"
                 {
       (yyval.elem)=(yyvsp[0].elem);
	   (yyval.elem)->ins = instCount+1;
    }
#line 1687 "parser.tab.c"
    break;

  case 6:
#line 156 "parser.y"
            { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1695 "parser.tab.c"
    break;

  case 7:
#line 159 "parser.y"
                       { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1703 "parser.tab.c"
    break;

  case 8:
#line 162 "parser.y"
                   {  
        (yyval.elem) = create_node(3, "snippet", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
    }
#line 1712 "parser.tab.c"
    break;

  case 9:
#line 168 "parser.y"
                                                    {  
            
        }
#line 1720 "parser.tab.c"
    break;

  case 10:
#line 171 "parser.y"
                                                                         {  
            
        }
#line 1728 "parser.tab.c"
    break;

  case 11:
#line 174 "parser.y"
                                                                    {
            
        }
#line 1736 "parser.tab.c"
    break;

  case 12:
#line 177 "parser.y"
                                                                                         {  
            
        }
#line 1744 "parser.tab.c"
    break;

  case 13:
#line 182 "parser.y"
                                                     {  
            (yyval.elem) = create_node(4, "parameters", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 1753 "parser.tab.c"
    break;

  case 14:
#line 188 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1761 "parser.tab.c"
    break;

  case 15:
#line 191 "parser.y"
                                         {  
            (yyval.elem) = create_node(4, "typedargslist", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 1770 "parser.tab.c"
    break;

  case 16:
#line 197 "parser.y"
                   {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1778 "parser.tab.c"
    break;

  case 17:
#line 200 "parser.y"
                            {  
            (yyval.elem) = create_node(4, "typedarg", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");    //is this instruction needed?????
        }
#line 1788 "parser.tab.c"
    break;

  case 18:
#line 207 "parser.y"
             {  
            (yyval.elem)=(yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
        }
#line 1797 "parser.tab.c"
    break;

  case 19:
#line 211 "parser.y"
                               {  
            (yyval.elem) = create_node(4, "tfpdef", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem)); 
			(yyval.elem)->ins = instCount+1;
        }
#line 1806 "parser.tab.c"
    break;

  case 20:
#line 217 "parser.y"
                        { 
        	(yyval.elem)=(yyvsp[0].elem);
        }
#line 1814 "parser.tab.c"
    break;

  case 21:
#line 220 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem); 
        }
#line 1822 "parser.tab.c"
    break;

  case 22:
#line 225 "parser.y"
                                                {  
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 1830 "parser.tab.c"
    break;

  case 23:
#line 228 "parser.y"
                                   {  
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 1838 "parser.tab.c"
    break;

  case 24:
#line 233 "parser.y"
                                {   
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1846 "parser.tab.c"
    break;

  case 25:
#line 236 "parser.y"
                                                     {  
           (yyval.elem) = create_node(3, "small_stmt_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
		   (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 1855 "parser.tab.c"
    break;

  case 26:
#line 242 "parser.y"
                            {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1863 "parser.tab.c"
    break;

  case 27:
#line 245 "parser.y"
                        {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1871 "parser.tab.c"
    break;

  case 28:
#line 248 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1879 "parser.tab.c"
    break;

  case 29:
#line 254 "parser.y"
                           {    //list of test COLON test???
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 1888 "parser.tab.c"
    break;

  case 30:
#line 258 "parser.y"
                                            {
            (yyval.elem) = create_node(6, "expr_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            create_ins(0, (yyvsp[-4].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
		}
#line 1898 "parser.tab.c"
    break;

  case 31:
#line 263 "parser.y"
                                    { 
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            // Here add instruction 
        }
#line 1908 "parser.tab.c"
    break;

  case 32:
#line 268 "parser.y"
                   {
			(yyval.elem)=(yyvsp[0].elem);
        }
#line 1916 "parser.tab.c"
    break;

  case 33:
#line 271 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-2].elem)->ins;
			create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, ""); 
        }
#line 1926 "parser.tab.c"
    break;

  case 34:
#line 278 "parser.y"
                                 {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1934 "parser.tab.c"
    break;

  case 35:
#line 281 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;    //x=y=z
        }
#line 1945 "parser.tab.c"
    break;

  case 36:
#line 289 "parser.y"
                        {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1953 "parser.tab.c"
    break;

  case 37:
#line 292 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1961 "parser.tab.c"
    break;

  case 38:
#line 295 "parser.y"
                         {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1969 "parser.tab.c"
    break;

  case 39:
#line 300 "parser.y"
                    {  
            
            
        }
#line 1978 "parser.tab.c"
    break;

  case 40:
#line 305 "parser.y"
                            {  
            
        }
#line 1986 "parser.tab.c"
    break;

  case 41:
#line 309 "parser.y"
                        {  
            
        }
#line 1994 "parser.tab.c"
    break;

  case 42:
#line 312 "parser.y"
                          {  
            
        }
#line 2002 "parser.tab.c"
    break;

  case 43:
#line 317 "parser.y"
                           {  
            (yyval.elem) = create_node(3, "global_stmt", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 2011 "parser.tab.c"
    break;

  case 44:
#line 321 "parser.y"
                                      {   
            (yyval.elem) = create_node(4, "global_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 2020 "parser.tab.c"
    break;

  case 45:
#line 327 "parser.y"
                               {  
            (yyval.elem) = create_node(3, "comma_name_star", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 2029 "parser.tab.c"
    break;

  case 46:
#line 331 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "comma_name_star", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 2038 "parser.tab.c"
    break;

  case 47:
#line 336 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);  
        }
#line 2046 "parser.tab.c"
    break;

  case 48:
#line 339 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2054 "parser.tab.c"
    break;

  case 49:
#line 342 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2062 "parser.tab.c"
    break;

  case 50:
#line 345 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2070 "parser.tab.c"
    break;

  case 51:
#line 348 "parser.y"
                       {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 2078 "parser.tab.c"
    break;

  case 52:
#line 353 "parser.y"
                                   {  
           (yyval.elem)=create_node(6, "if_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
           (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
           backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
           (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);
        }
#line 2089 "parser.tab.c"
    break;

  case 53:
#line 359 "parser.y"
                                                       {  
            (yyval.elem) = create_node(11, "if_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            vector<int> temp = merge((yyvsp[-5].elem)->nextlist, (yyvsp[-4].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);
        }
#line 2101 "parser.tab.c"
    break;

  case 54:
#line 366 "parser.y"
                                              {  
            (yyval.elem) = create_node(8, "if_elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);     
            vector<int> temp = merge((yyvsp[-2].elem)->nextlist, (yyvsp[-1].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);
        }
#line 2113 "parser.tab.c"
    break;

  case 55:
#line 374 "parser.y"
                                         {  
            (yyval.elem) = create_node(7, "while_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            backpatch((yyvsp[0].elem)->nextlist, (yyvsp[-4].elem)->ins);
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = (yyvsp[-3].elem)->falselist;
            create_ins(0, "goto", to_string((yyvsp[-4].elem)->ins), "", "");
        }
#line 2126 "parser.tab.c"
    break;

  case 56:
#line 382 "parser.y"
                                                                   {   
			(yyval.elem) = create_node(12, "while_else_stmt", (yyvsp[-10].elem), (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-9].elem)->ins;
			backpatch((yyvsp[-4].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-5].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
			backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
			(yyval.elem)->nextlist = merge((yyvsp[-4].elem)->nextlist, (yyvsp[0].elem)->nextlist); //verify
        }
#line 2140 "parser.tab.c"
    break;

  case 57:
#line 392 "parser.y"
                                              { 
            // $$ = create_node(7, "for_stmt", $1, $2, $3, $4, $5, $6);
            // $$->ins = $2->ins;

        }
#line 2150 "parser.tab.c"
    break;

  case 58:
#line 397 "parser.y"
                                                              { 
            
        }
#line 2158 "parser.tab.c"
    break;

  case 59:
#line 401 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2166 "parser.tab.c"
    break;

  case 60:
#line 404 "parser.y"
                                            {
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 2174 "parser.tab.c"
    break;

  case 61:
#line 407 "parser.y"
                                                    { 
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 2182 "parser.tab.c"
    break;

  case 62:
#line 412 "parser.y"
                                    {  
            (yyval.elem)=create_node(6, "elif_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);
        }
#line 2193 "parser.tab.c"
    break;

  case 63:
#line 418 "parser.y"
                                              {  
            (yyval.elem) = create_node(8, "elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-5].elem)->ins;
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist));
        }
#line 2205 "parser.tab.c"
    break;

  case 64:
#line 425 "parser.y"
                                                        {  
            (yyval.elem) = create_node(11, "elif_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-8].elem)->ins;
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-5].elem)->nextlist, merge((yyvsp[-4].elem)->nextlist,(yyvsp[0].elem)->nextlist));
        }
#line 2217 "parser.tab.c"
    break;

  case 65:
#line 434 "parser.y"
                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2225 "parser.tab.c"
    break;

  case 66:
#line 440 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2233 "parser.tab.c"
    break;

  case 67:
#line 443 "parser.y"
                                         {  
            (yyval.elem) = create_node(5, "or_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;
        }
#line 2245 "parser.tab.c"
    break;

  case 68:
#line 451 "parser.y"
                                            {
            (yyval.elem) = create_node(5, "and_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;
        }
#line 2257 "parser.tab.c"
    break;

  case 69:
#line 458 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2265 "parser.tab.c"
    break;

  case 70:
#line 463 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2273 "parser.tab.c"
    break;

  case 71:
#line 466 "parser.y"
                                          {  
            (yyval.elem) = create_node(5, "and_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;
        }
#line 2285 "parser.tab.c"
    break;

  case 72:
#line 474 "parser.y"
                                              { 
            (yyval.elem) = create_node(5, "not_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;
        }
#line 2297 "parser.tab.c"
    break;

  case 73:
#line 481 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2305 "parser.tab.c"
    break;

  case 74:
#line 486 "parser.y"
                         { 
            (yyval.elem) = create_node(3, "not_test", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->truelist = (yyvsp[0].elem)->falselist;
            (yyval.elem)->falselist = (yyvsp[0].elem)->truelist;
        }
#line 2316 "parser.tab.c"
    break;

  case 75:
#line 492 "parser.y"
                        { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2324 "parser.tab.c"
    break;

  case 76:
#line 497 "parser.y"
                  {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2332 "parser.tab.c"
    break;

  case 77:
#line 500 "parser.y"
                                   { 
            (yyval.elem)=create_node(4, "comparison", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            (yyval.elem)->truelist = makelist(instCount+1);
            (yyval.elem)->falselist = makelist(instCount+2);
            create_ins(0, "if", (yyval.elem)->addr, "goto", "");
            create_ins(0, "goto", "", "", "");
        }
#line 2347 "parser.tab.c"
    break;

  case 78:
#line 512 "parser.y"
                    {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2355 "parser.tab.c"
    break;

  case 79:
#line 515 "parser.y"
                    { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2363 "parser.tab.c"
    break;

  case 80:
#line 518 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2371 "parser.tab.c"
    break;

  case 81:
#line 521 "parser.y"
                            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2379 "parser.tab.c"
    break;

  case 82:
#line 524 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2387 "parser.tab.c"
    break;

  case 83:
#line 527 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2395 "parser.tab.c"
    break;

  case 84:
#line 530 "parser.y"
                   {
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2403 "parser.tab.c"
    break;

  case 85:
#line 533 "parser.y"
            {  
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2411 "parser.tab.c"
    break;

  case 86:
#line 536 "parser.y"
                { 
        (yyval.elem) = create_node(3, "NOT IN", (yyvsp[-1].elem), (yyvsp[0].elem));
    }
#line 2419 "parser.tab.c"
    break;

  case 87:
#line 539 "parser.y"
            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2427 "parser.tab.c"
    break;

  case 88:
#line 542 "parser.y"
                { 
        (yyval.elem) = create_node(3, "IS NOT", (yyvsp[-1].elem), (yyvsp[0].elem));
    }
#line 2435 "parser.tab.c"
    break;

  case 89:
#line 547 "parser.y"
                  { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2443 "parser.tab.c"
    break;

  case 90:
#line 550 "parser.y"
                                  {  
            (yyval.elem) = create_node(4, "expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2454 "parser.tab.c"
    break;

  case 91:
#line 558 "parser.y"
                   { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2462 "parser.tab.c"
    break;

  case 92:
#line 561 "parser.y"
                                       {  
            (yyval.elem) = create_node(4, "xor_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2473 "parser.tab.c"
    break;

  case 93:
#line 569 "parser.y"
                       { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2482 "parser.tab.c"
    break;

  case 94:
#line 573 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "and_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2493 "parser.tab.c"
    break;

  case 95:
#line 581 "parser.y"
                         { 
                (yyval.elem) = (yyvsp[0].elem); 
            }
#line 2501 "parser.tab.c"
    break;

  case 96:
#line 584 "parser.y"
                                                 { 
                (yyval.elem) = create_node(4, "shift_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2512 "parser.tab.c"
    break;

  case 97:
#line 592 "parser.y"
                 { 
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 2520 "parser.tab.c"
    break;

  case 98:
#line 595 "parser.y"
                                   { 
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2531 "parser.tab.c"
    break;

  case 99:
#line 601 "parser.y"
                                    { 
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2542 "parser.tab.c"
    break;

  case 100:
#line 608 "parser.y"
             {
            (yyval.elem) = (yyvsp[0].elem); 
        }
#line 2550 "parser.tab.c"
    break;

  case 101:
#line 611 "parser.y"
                                  {
            (yyval.elem) = create_node(4, "term", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        
		}
#line 2562 "parser.tab.c"
    break;

  case 102:
#line 620 "parser.y"
                            { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2570 "parser.tab.c"
    break;

  case 103:
#line 623 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2578 "parser.tab.c"
    break;

  case 104:
#line 626 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2586 "parser.tab.c"
    break;

  case 105:
#line 629 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2594 "parser.tab.c"
    break;

  case 106:
#line 632 "parser.y"
                           { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2602 "parser.tab.c"
    break;

  case 107:
#line 637 "parser.y"
                                    {  
            (yyval.elem) = create_node(3, "factor", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr,"", (yyvsp[0].elem)->addr);
        }
#line 2613 "parser.tab.c"
    break;

  case 108:
#line 643 "parser.y"
                    { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2621 "parser.tab.c"
    break;

  case 109:
#line 647 "parser.y"
                            {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2629 "parser.tab.c"
    break;

  case 110:
#line 650 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2637 "parser.tab.c"
    break;

  case 111:
#line 653 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2645 "parser.tab.c"
    break;

  case 112:
#line 657 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2653 "parser.tab.c"
    break;

  case 113:
#line 660 "parser.y"
                                            { 
            (yyval.elem) = create_node(4, "power", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2664 "parser.tab.c"
    break;

  case 114:
#line 668 "parser.y"
                {  
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2672 "parser.tab.c"
    break;

  case 115:
#line 671 "parser.y"
                            {  
            (yyval.elem) = create_node(3, "atom_expr", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 2681 "parser.tab.c"
    break;

  case 116:
#line 675 "parser.y"
                             { 
            (yyval.elem) = create_node(4, "atom_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 2690 "parser.tab.c"
    break;

  case 117:
#line 681 "parser.y"
                                           { 
        (yyval.elem)=(yyvsp[-1].elem);
    }
#line 2698 "parser.tab.c"
    break;

  case 118:
#line 684 "parser.y"
                                    {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 2707 "parser.tab.c"
    break;

  case 119:
#line 688 "parser.y"
                                           { 
        (yyval.elem) = (yyvsp[-1].elem);
    }
#line 2715 "parser.tab.c"
    break;

  case 120:
#line 691 "parser.y"
                                {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 2724 "parser.tab.c"
    break;

  case 121:
#line 695 "parser.y"
                                { 
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 2733 "parser.tab.c"
    break;

  case 122:
#line 699 "parser.y"
                {
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
     }
#line 2742 "parser.tab.c"
    break;

  case 123:
#line 703 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 2751 "parser.tab.c"
    break;

  case 124:
#line 707 "parser.y"
                        { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2759 "parser.tab.c"
    break;

  case 125:
#line 710 "parser.y"
                        { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 2768 "parser.tab.c"
    break;

  case 126:
#line 714 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 2777 "parser.tab.c"
    break;

  case 127:
#line 719 "parser.y"
                        {
            (yyval.elem) = (yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
        }
#line 2786 "parser.tab.c"
    break;

  case 128:
#line 723 "parser.y"
                                { 
            (yyval.elem) = create_node(3, "STRING_PLUS", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 2795 "parser.tab.c"
    break;

  case 129:
#line 729 "parser.y"
                                     { 
            (yyval.elem) = create_node(3, "trailer", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 2804 "parser.tab.c"
    break;

  case 130:
#line 733 "parser.y"
                                              {
            (yyval.elem) = create_node(4, "trailer", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 2813 "parser.tab.c"
    break;

  case 131:
#line 737 "parser.y"
                                       {
            (yyval.elem) = create_node(4, "trailer", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 2822 "parser.tab.c"
    break;

  case 132:
#line 743 "parser.y"
                           { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2830 "parser.tab.c"
    break;

  case 133:
#line 746 "parser.y"
                                {
            (yyval.elem)=create_node(3,"testlist",(yyvsp[-1].elem),(yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
        }
#line 2839 "parser.tab.c"
    break;

  case 134:
#line 751 "parser.y"
                            {
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2847 "parser.tab.c"
    break;

  case 135:
#line 754 "parser.y"
                                    { 
            (yyval.elem) = create_node(4, "testlist_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 2856 "parser.tab.c"
    break;

  case 136:
#line 760 "parser.y"
                                      { 
            
        }
#line 2864 "parser.tab.c"
    break;

  case 137:
#line 763 "parser.y"
                                                                 { 
            
        }
#line 2872 "parser.tab.c"
    break;

  case 138:
#line 766 "parser.y"
                                                                         { 
           
        }
#line 2880 "parser.tab.c"
    break;

  case 139:
#line 771 "parser.y"
                           { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2888 "parser.tab.c"
    break;

  case 140:
#line 774 "parser.y"
                                 { 
            (yyval.elem) = create_node(3, "arglist", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 2897 "parser.tab.c"
    break;

  case 141:
#line 779 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2905 "parser.tab.c"
    break;

  case 142:
#line 782 "parser.y"
                                        { 
            (yyval.elem) = create_node(4, "argument_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 2914 "parser.tab.c"
    break;

  case 143:
#line 788 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2922 "parser.tab.c"
    break;

  case 144:
#line 791 "parser.y"
                            { 
            (yyval.elem) = create_node(4, "argument", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
        }
#line 2932 "parser.tab.c"
    break;

  case 145:
#line 798 "parser.y"
                                { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2940 "parser.tab.c"
    break;

  case 146:
#line 801 "parser.y"
                                            { 
            (yyval.elem) = (yyvsp[-1].elem);
        }
#line 2948 "parser.tab.c"
    break;

  case 147:
#line 804 "parser.y"
                                                    { 
            (yyval.elem) = (yyvsp[-2].elem);
        }
#line 2956 "parser.tab.c"
    break;

  case 148:
#line 809 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2964 "parser.tab.c"
    break;

  case 149:
#line 812 "parser.y"
                            { 
            (yyval.elem)=create_node(3,"stmt_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
        }
#line 2973 "parser.tab.c"
    break;


#line 2977 "parser.tab.c"

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
#line 817 "parser.y"


void yyerror(string str){
    fprintf(stderr, "Error: %s at line number %d offending token: %s\n", str.c_str(), yylineno, yytext);
    exit(1);
}

char* str_to_ch(string s)
{
	char* result_chr = new char[s.size()+1];
	strcpy(result_chr,s.c_str());
	return result_chr;
}

vector<int> makelist(int i){
	return vector<int>{i};
}

void create_ins(int type,string i,string op,string arg1,string arg2){
	vector<string> instruction{to_string(type),i,op,arg1,arg2};
	instructions.push_back(instruction);
	instCount++;
}

void backpatch(vector<int>p, int i){
	for(int j=0;j<p.size();j++)
		instructions[p[j]-1].push_back(to_string(i));
}

vector<int> merge(vector<int> p1, vector<int> p2){
        vector<int> merged;
        merged.reserve(p1.size() + p2.size());
        merged.insert(merged.end(), p1.begin(), p1.end());
        merged.insert(merged.end(), p2.begin(), p2.end());
	return merged;
}

string newTemp(){
	return "t"+to_string(tempCount++);
}

void MakeIRFile()
{
	int tabs=0;
	for(int i=0;i<instructions.size();i++)
	{
		if(instructions[i][1]=="EndFunc") tabs--;
		cout << i+1 << "\t" << string(tabs,'\t');
		code_out << i+1 << "\t" << string(tabs,'\t');
		if(instructions[i][0]=="0")
		{
			for(int j=1;j<instructions[i].size();j++)
			{
				cout << instructions[i][j] << (instructions[i][j].length()?" ":"");
				code_out << instructions[i][j] << (instructions[i][j].length()?" ":"");
			}
			if(instructions[i][1]=="BeginFunc") tabs++;
		}
		else
		{
			cout << instructions[i][1] << " = " << instructions[i][3] << " " << instructions[i][2] << " " << instructions[i][4];
			code_out << instructions[i][1] << " = " << instructions[i][3] << " " << instructions[i][2] << " " << instructions[i][4];
		}
		cout << endl;
		code_out << endl;
	}
}

int main(int argc, char* argv[]){    
    /* cout<<"Hello\n"; */
    FILE* yyin = fopen(argv[1],"r");
    yyrestart(yyin); 

    /* bool inset = false, outset = false; */
    indent_stack.push(0);

    /* for (int i=0; i< argc; i++){
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
    }  */

/*--------------------------------------------------------------*/

        // Open the output file
        /* fout.open(output_file.c_str(),ios::out); */
        code_out.open("./output/3AC.txt",ios::out);
        // Get the DOT file template from the file
        /* ifstream infile("./DOT_Template.txt"); */
        /* string line; */
        /* while (getline(infile, line)) */
                /* fout << line << endl; */

/*--------------------------------------------------------------*/

    instCount=0;
    tempCount=0;
    yydebug=1;
    /* cout<<"Parsing Started\n"; */
    yyparse();
    fclose(yyin); 

/*--------------------------------------------------------------*/

// Create 3AC file
    MakeIRFile();

// Close the output file
    code_out.close();

/*--------------------------------------------------------------*/
    return 0;

}
