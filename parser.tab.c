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
    // #include "functions.cpp"
    using namespace std;

    extern int yylex();
    extern int yyparse();
    extern void yyrestart(FILE* file);
    extern FILE* yyin;
    extern int yylineno;
    extern char* yytext;
    void yyerror(string str);
    extern stack<int> indent_stack;
    stack<int> loopStack;
    // stack<string> paramStack;

    int instCount;
    vector<vector<string>> instructions;
    vector<int> makelist(int i);
    void backpatch(vector<int> p, int i);
    void backpatch_str(vector<int> p, string str);
    void create_ins(int type,string i,string op,string arg1,string arg2);
    vector<int> merge(vector<int> p1, vector<int> p2);
    string newTemp();
    char* str_to_ch(string s);
    int tempCount;
    fstream code_out;

    // map<string,ste> global_sym_table;
    ste* global_sym_table = new ste;   //pointer to the head(initialising entry) of the global symbol table
    ste* current_ste = global_sym_table;   //pointer to current symbol table entry (initialised to pointer of head of the global symbol table)  
    int global_offset = 0;

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

#line 142 "parser.tab.c"

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
    RANGE = 258,
    NEWLINE = 259,
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
    ATOM_KEYWORDS = 284,
    STRING = 285,
    NUMBER = 286,
    OPEN_BRACKET = 287,
    CLOSE_BRACKET = 288,
    EQUAL = 289,
    SEMI_COLON = 290,
    COLON = 291,
    COMMA = 292,
    PLUS = 293,
    MINUS = 294,
    MULTIPLY = 295,
    DIVIDE = 296,
    REMAINDER = 297,
    ATTHERATE = 298,
    NEGATION = 299,
    BIT_AND = 300,
    BIT_OR = 301,
    BIT_XOR = 302,
    DOT = 303,
    CURLY_OPEN = 304,
    CURLY_CLOSE = 305,
    SQUARE_OPEN = 306,
    SQUARE_CLOSE = 307,
    LESS_THAN = 308,
    GREATER_THAN = 309,
    EQUAL_EQUAL = 310,
    GREATER_THAN_EQUAL = 311,
    LESS_THAN_EQUAL = 312,
    NOT_EQUAL_ARROW = 313,
    NOT_EQUAL = 314,
    IS = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 73 "parser.y"

    struct node *elem;

#line 259 "parser.tab.c"

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
#define YYFINAL  82
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   467

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  164
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  277

#define YYUNDEFTOK  2
#define YYMAXUTOK   315


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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    94,   101,   106,   110,   113,   116,   122,
     137,   146,   155,   166,   187,   193,   201,   209,   220,   223,
     230,   234,   253,   256,   261,   264,   269,   272,   279,   282,
     285,   290,   295,   312,   315,   320,   338,   341,   349,   352,
     355,   360,   369,   375,   378,   386,   390,   396,   400,   405,
     408,   412,   416,   419,   424,   435,   447,   456,   463,   474,
     485,   495,   502,   515,   527,   542,   549,   555,   571,   596,
     614,   624,   631,   640,   647,   650,   653,   659,   665,   668,
     676,   683,   688,   691,   699,   706,   711,   717,   722,   725,
     737,   740,   743,   746,   749,   752,   755,   758,   761,   764,
     767,   772,   775,   783,   786,   794,   798,   806,   809,   817,
     820,   826,   833,   836,   845,   848,   851,   854,   857,   862,
     868,   872,   875,   878,   882,   885,   893,   897,   909,   917,
     924,   927,   932,   936,   941,   945,   949,   953,   956,   961,
     965,   971,   978,   990,   994,  1001,  1006,  1022,  1030,  1047,
    1051,  1055,  1061,  1081,  1084,  1088,  1097,  1107,  1110,  1117,
    1126,  1129,  1132,  1137,  1140
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RANGE", "NEWLINE", "INDENT", "DEDENT",
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
  "snippet", "funcdef", "func_name", "func_ret_type", "parameters",
  "typedargslist", "typedarg", "tfpdef", "stmt", "simple_stmt",
  "small_stmt_list", "small_stmt", "expr_stmt",
  "eq_testlist_star_expr_plus", "flow_stmt", "break_stmt", "continue_stmt",
  "return_stmt", "global_stmt", "comma_name_star", "compound_stmt",
  "if_stmt", "if_scope", "else_scope", "else_if_scope", "nts_star",
  "while_stmt", "while_scope", "while_expr", "for_stmt", "for_core",
  "for_scope", "range_stmt", "for_test", "suite", "test", "or_test",
  "and_test_star", "and_test", "not_test_star", "not_test", "comparison",
  "comp_op", "expr", "xor_expr", "and_expr", "shift_expr", "arith_expr",
  "term", "term_choice", "factor", "factor_choice", "power", "atom_expr",
  "atom", "STRING_PLUS", "trailer", "testlist", "testlist_list",
  "classdef", "class_name", "arglist", "argument_list", "argument",
  "func_body_suite", "block", "stmt_plus", YY_NULLPTR
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
     315
};
# endif

#define YYPACT_NINF (-198)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     104,   104,    47,  -198,  -198,  -198,   412,  -198,  -198,   412,
      30,    40,    70,  -198,   -11,  -198,   343,  -198,  -198,  -198,
     -18,   167,    86,  -198,  -198,   104,  -198,    14,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,   412,  -198,  -198,
    -198,   416,     8,  -198,    68,    90,    93,    95,  -198,     5,
      74,    67,    71,    38,    26,  -198,   416,  -198,     6,  -198,
    -198,  -198,    87,  -198,  -198,   366,   412,  -198,  -198,  -198,
    -198,   -10,  -198,   105,    88,  -198,  -198,   102,   106,  -198,
    -198,    97,  -198,  -198,  -198,   221,   109,   412,   110,   121,
     412,   412,   111,  -198,  -198,  -198,   122,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,   125,   416,   416,   416,   416,   416,
     416,   416,  -198,  -198,  -198,  -198,  -198,   416,  -198,   416,
     137,   412,  -198,   117,   119,   120,  -198,   107,   389,   251,
       7,    19,   145,  -198,   148,  -198,  -198,  -198,  -198,  -198,
     126,  -198,  -198,   158,  -198,  -198,   130,    18,   412,   412,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,    26,    26,  -198,
    -198,  -198,   129,   412,  -198,   412,  -198,   131,   135,   164,
    -198,  -198,   136,    63,    51,  -198,   139,   162,   281,    88,
    -198,   251,  -198,   251,   143,  -198,   412,   412,   412,   155,
     161,   172,  -198,  -198,   251,   149,   320,   174,   162,   281,
    -198,   175,   412,  -198,   151,   185,  -198,  -198,  -198,  -198,
      89,   251,   176,   412,  -198,  -198,  -198,  -198,  -198,   251,
     320,    29,  -198,   156,  -198,  -198,  -198,   281,   320,    94,
     176,   179,    59,  -198,  -198,  -198,   189,  -198,   281,  -198,
      91,  -198,  -198,   165,   412,  -198,   187,   171,  -198,   412,
    -198,  -198,   202,  -198,  -198,   173,   177,  -198,   181,  -198,
     251,  -198,  -198,   251,  -198,  -198,   251,   251,  -198,    89,
    -198,    94,   184,  -198,  -198,   251,  -198
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,   135,    57,    65,    70,     0,    41,    42,    43,
       0,     0,     0,   138,   139,   136,     0,   121,   122,   123,
       0,     0,     0,     4,    52,     6,    22,     0,    26,    28,
      29,    38,    39,    40,    30,    23,    49,     0,    50,     2,
      51,     0,   145,    77,     0,    78,     0,    82,    87,    88,
     101,   103,   105,   107,   109,   112,     0,   120,   124,   126,
     137,    33,   143,    53,     7,     0,     0,   127,    86,    44,
     152,     0,    13,     0,    45,   140,   131,   145,     0,   134,
     133,     0,     1,     8,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     2,    97,     0,    90,    91,    92,
      93,    94,    95,    96,    99,     0,     0,     0,     0,     0,
       0,     0,   118,   114,   116,   117,   115,     0,   119,     0,
       0,   144,   141,   157,     0,   153,   155,     0,     0,     0,
       0,     0,     0,    46,     0,   130,   132,    24,    27,     2,
       0,    66,     2,     0,    31,    34,    36,   146,     0,     0,
      98,   100,    89,   102,   104,   106,   108,   110,   111,   113,
     125,   129,   147,     0,   142,   154,   128,     0,     0,     0,
      74,   149,    20,     0,     0,    16,    18,     0,     0,    47,
     146,     0,     2,     0,     0,    69,     0,     0,     0,    79,
      83,     0,   158,   156,     0,     0,     0,     0,     0,     0,
      15,     0,     0,    14,     0,     0,   160,     9,   159,    48,
      54,     0,    67,     0,    37,    32,    35,   148,   150,     0,
     163,     0,    21,     0,    11,    17,    19,     0,     0,     0,
      63,     0,     0,    73,   151,   164,     0,    75,     0,    10,
       0,    58,    59,     0,     0,    56,     0,     0,    71,     0,
      76,    12,     0,   161,     2,     0,     0,     2,     0,   162,
       0,     2,     2,     0,    72,    55,     0,     0,    68,    60,
      64,     0,     0,    61,     2,     0,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -198,   -91,  -196,  -198,    16,  -198,  -198,    12,  -198,  -198,
      11,  -198,  -183,     4,  -198,   132,  -198,   -85,  -198,  -198,
    -198,  -198,  -198,    36,  -198,  -198,  -198,  -171,  -198,   -50,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -173,    -9,
    -198,  -198,    75,  -198,    -5,   123,  -198,   -35,   115,   118,
     124,  -198,    -4,  -198,   -47,  -198,  -198,  -198,  -198,   213,
    -198,    64,  -198,  -198,  -198,   101,  -198,    65,  -188,  -198,
    -197
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    87,   229,    22,    23,    24,    73,   204,   131,   174,
     175,   176,    25,   170,    27,    28,    29,   145,    30,    31,
      32,    33,    34,   133,    35,    36,    37,   243,   244,   245,
      38,    39,   140,    40,    88,    41,   185,   232,   171,    42,
      43,    44,    45,    46,    47,    48,   105,    49,    50,    51,
      52,    53,    54,   117,    55,    56,    57,    58,    59,    60,
      67,    61,    62,    63,    71,   124,   125,   126,   207,   208,
     221
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    68,   148,   149,    26,    26,    89,    77,   210,   118,
     212,   224,    77,   220,   119,    90,   231,    64,    84,    14,
     172,   218,   128,   235,    95,   187,   129,    96,    86,    26,
     177,   240,    79,   236,   246,   237,   112,   220,   230,   239,
     173,    83,    91,    70,    92,   220,   234,   109,   181,    85,
     251,   183,   188,    72,   120,   178,   123,   127,    97,    98,
      99,   100,   101,   102,   103,   104,   113,   114,   115,   116,
     159,   153,   160,   271,   198,   256,   110,   111,   141,    65,
      78,   144,   146,    74,   200,    81,    82,   265,   201,    93,
     268,   211,   248,   269,   270,   252,   249,   253,    66,   199,
     272,   214,   276,   216,    -3,    -3,   157,   158,     1,   241,
     242,   -81,   162,    94,   107,   -85,   108,     2,     3,   123,
     106,     4,     5,   147,   121,   132,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   130,   134,   135,
     143,   150,    17,    18,   190,   139,   142,   151,    19,   136,
     161,   163,   164,    20,   192,    21,   123,   165,   179,   166,
     180,   184,   182,   260,   186,   191,   263,   194,   195,   196,
     266,   267,   197,   202,   203,   213,   -80,   146,   215,   146,
       2,   -84,   206,   275,   217,   219,   222,   227,   172,     6,
     228,    -3,   238,   226,   247,   250,    13,    14,    15,    16,
      26,   254,   241,   206,   233,    17,    18,   257,   259,   261,
     223,    19,   225,   262,   264,   209,    20,   138,    21,    80,
     274,   273,   154,   189,    26,   137,   155,    75,   152,   168,
     193,   206,    26,   156,     2,   255,     0,     0,     0,     0,
     258,     0,   206,     6,     7,     8,     9,     0,     0,    12,
      13,    14,    15,    16,     0,   169,     0,     0,     0,    17,
      18,     0,     0,     0,     2,    19,     0,     0,     0,     0,
      20,     0,    21,     6,     7,     8,     9,     0,     0,    12,
      13,    14,    15,    16,     0,   205,     0,     0,     0,    17,
      18,     0,     0,     0,     2,    19,     0,     0,     0,     0,
      20,     0,    21,     6,     7,     8,     9,     0,     0,    12,
      13,    14,    15,    16,     0,     0,     0,     0,     0,    17,
      18,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      20,     0,    21,     2,     3,     0,     0,     4,     5,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,     0,     2,     0,    17,    18,
       0,     0,     0,     0,    19,     6,     0,     0,     0,    20,
       0,    21,    13,    14,    15,    16,    76,     0,     0,     2,
       0,    17,    18,     0,     0,     0,     0,    19,     6,     0,
       0,     0,    20,     0,    21,    13,    14,    15,    16,   122,
       0,     0,     2,     0,    17,    18,     0,     0,     0,     0,
      19,     6,     0,     0,     0,    20,     0,    21,    13,    14,
      15,    16,   167,     0,     0,     2,     0,    17,    18,     2,
       0,     0,     0,    19,     6,     0,     0,     0,    20,     0,
      21,    13,    14,    15,    16,    13,    14,    15,    16,     0,
      17,    18,     0,     0,    17,    18,    19,     0,     0,     0,
      19,    20,     0,    21,     0,    20,     0,    21
};

static const yytype_int16 yycheck[] =
{
       9,     6,    93,    94,     0,     1,    41,    16,   181,    56,
     183,   199,    21,   196,     8,     7,   212,     1,     4,    30,
      13,   194,    32,   220,    19,     7,    36,    22,    37,    25,
      11,   228,    50,     4,   230,     6,    10,   220,   211,   227,
      33,    25,    34,    13,    36,   228,   219,     9,   139,    35,
     238,   142,    34,    13,    48,    36,    65,    66,    53,    54,
      55,    56,    57,    58,    59,    60,    40,    41,    42,    43,
     117,   106,   119,   269,    11,   246,    38,    39,    87,    32,
      16,    90,    91,    13,    33,    21,     0,   260,    37,    21,
     263,   182,    33,   266,   267,     4,    37,     6,    51,    36,
     271,   186,   275,   188,    15,    16,   110,   111,     4,    15,
      16,    21,   121,    20,    47,    20,    45,    13,    14,   128,
      46,    17,    18,    12,    37,    37,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    32,    36,    33,
      19,    19,    38,    39,   149,    36,    36,    22,    44,    52,
      13,    34,    33,    49,   163,    51,   165,    37,    13,    52,
      12,     3,    36,   254,    34,    36,   257,    36,    33,     5,
     261,   262,    36,    34,    12,    32,    21,   186,   187,   188,
      13,    20,   178,   274,    12,    36,    12,    36,    13,    22,
       5,    15,    36,   202,    15,     6,    29,    30,    31,    32,
     196,    36,    15,   199,   213,    38,    39,    36,     6,    36,
     198,    44,   201,    36,    33,   179,    49,    85,    51,    52,
      36,   271,   107,   148,   220,     4,   108,    14,   105,   128,
     165,   227,   228,   109,    13,   244,    -1,    -1,    -1,    -1,
     249,    -1,   238,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    32,    -1,     4,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    13,    44,    -1,    -1,    -1,    -1,
      49,    -1,    51,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    32,    -1,     4,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    13,    44,    -1,    -1,    -1,    -1,
      49,    -1,    51,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      49,    -1,    51,    13,    14,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    13,    -1,    38,    39,
      -1,    -1,    -1,    -1,    44,    22,    -1,    -1,    -1,    49,
      -1,    51,    29,    30,    31,    32,    33,    -1,    -1,    13,
      -1,    38,    39,    -1,    -1,    -1,    -1,    44,    22,    -1,
      -1,    -1,    49,    -1,    51,    29,    30,    31,    32,    33,
      -1,    -1,    13,    -1,    38,    39,    -1,    -1,    -1,    -1,
      44,    22,    -1,    -1,    -1,    49,    -1,    51,    29,    30,
      31,    32,    33,    -1,    -1,    13,    -1,    38,    39,    13,
      -1,    -1,    -1,    44,    22,    -1,    -1,    -1,    49,    -1,
      51,    29,    30,    31,    32,    29,    30,    31,    32,    -1,
      38,    39,    -1,    -1,    38,    39,    44,    -1,    -1,    -1,
      44,    49,    -1,    51,    -1,    49,    -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    13,    14,    17,    18,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    38,    39,    44,
      49,    51,    64,    65,    66,    73,    74,    75,    76,    77,
      79,    80,    81,    82,    83,    85,    86,    87,    91,    92,
      94,    96,   100,   101,   102,   103,   104,   105,   106,   108,
     109,   110,   111,   112,   113,   115,   116,   117,   118,   119,
     120,   122,   123,   124,    65,    32,    51,   121,   105,   100,
      13,   125,    13,    67,    13,   120,    33,   100,   122,    50,
      52,   122,     0,    65,     4,    35,   100,    62,    95,   108,
       7,    34,    36,    21,    20,    19,    22,    53,    54,    55,
      56,    57,    58,    59,    60,   107,    46,    47,    45,     9,
      38,    39,    10,    40,    41,    42,    43,   114,   115,     8,
      48,    37,    33,   100,   126,   127,   128,   100,    32,    36,
      32,    69,    37,    84,    36,    33,    52,     4,    76,    36,
      93,   100,    36,    19,   100,    78,   100,    12,    62,    62,
      19,    22,   106,   108,   109,   110,   111,   113,   113,   115,
     115,    13,   100,    34,    33,    37,    52,    33,   126,     4,
      74,    99,    13,    33,    70,    71,    72,    11,    36,    13,
      12,    62,    36,    62,     3,    97,    34,     7,    34,   103,
     105,    36,   100,   128,    36,    33,     5,    36,    11,    36,
      33,    37,    34,    12,    68,     4,    74,   129,   130,    84,
      99,    62,    99,    32,    78,   100,    78,    12,    99,    36,
      73,   131,    12,    68,   129,    71,   100,    36,     5,    63,
      99,    63,    98,   100,    99,   131,     4,     6,    36,   129,
     131,    15,    16,    88,    89,    90,    63,    15,    33,    37,
       6,   129,     4,     6,    36,   100,    88,    36,   100,     6,
      62,    36,    36,    62,    33,    99,    62,    62,    99,    99,
      99,    63,    88,    90,    36,    62,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    65,    65,    65,    65,    66,
      66,    66,    66,    67,    68,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    77,    77,    77,    78,    78,    79,    79,
      79,    80,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    86,    86,    86,    87,    88,    89,
      90,    90,    90,    91,    91,    92,    93,    94,    94,    95,
      96,    97,    97,    98,    99,    99,    99,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   112,   113,   113,   114,   114,   114,   114,   114,   115,
     115,   116,   116,   116,   117,   117,   118,   118,   118,   118,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   120,
     120,   121,   121,   122,   122,   123,   123,   123,   123,   124,
     124,   124,   125,   126,   126,   127,   127,   128,   128,   129,
     130,   130,   130,   131,   131
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     2,     2,     5,
       7,     6,     8,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     3,     2,     1,     3,     1,     1,
       1,     3,     5,     1,     3,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     2,     3,     1,
       1,     1,     1,     1,     5,    10,     7,     1,     1,     1,
       5,     7,    10,     6,    11,     1,     1,     5,    10,     3,
       1,     4,     6,     1,     1,     4,     5,     1,     1,     4,
       4,     1,     1,     4,     4,     1,     2,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     3,     1,     2,     4,     3,
       3,     2,     3,     2,     2,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     2,     1,     3,     3,     5,     4,
       6,     7,     1,     1,     2,     1,     3,     1,     3,     1,
       1,     4,     5,     1,     2
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
#line 88 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal M");
        (yyval.elem)->ins = instCount+1;
}
#line 1694 "parser.tab.c"
    break;

  case 3:
#line 94 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal N");
        (yyval.elem)->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
#line 1704 "parser.tab.c"
    break;

  case 4:
#line 101 "parser.y"
              {
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 1712 "parser.tab.c"
    break;

  case 5:
#line 106 "parser.y"
                 {
       (yyval.elem)=(yyvsp[0].elem);
	   (yyval.elem)->ins = instCount+1;
    }
#line 1721 "parser.tab.c"
    break;

  case 6:
#line 110 "parser.y"
            { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1729 "parser.tab.c"
    break;

  case 7:
#line 113 "parser.y"
                       { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1737 "parser.tab.c"
    break;

  case 8:
#line 116 "parser.y"
                   {  
        (yyval.elem) = create_node(3, "snippet", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
    }
#line 1746 "parser.tab.c"
    break;

  case 9:
#line 122 "parser.y"
                                                        {
            //STE code start
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-3].elem)->addr, (yyvsp[-1].elem)->num_params, (yyvsp[-4].elem)->lineno, 1);
            //STE code end
            (yyval.elem)->ins = instCount+1;

            // thisTemps.pop();
			// create_ins(0,$5->return_param,"=","PopParam","");
            create_ins(0,"goto","ra","","");
            create_ins(0,"EndFunc","","","");
            backpatch_str((yyvsp[0].elem)->nextlist, "ra");
            // thisTemps.push(reg1);

        }
#line 1766 "parser.tab.c"
    break;

  case 10:
#line 137 "parser.y"
                                                                                  {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-5].elem)->addr, (yyvsp[-3].elem)->num_params, (yyvsp[-6].elem)->lineno, 1);
           
            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Goto","ra","","");
            create_ins(0,"EndFunc","","","");
        }
#line 1780 "parser.tab.c"
    break;

  case 11:
#line 146 "parser.y"
                                                                         {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-4].elem)->addr, 0, (yyvsp[-5].elem)->lineno, 1);

            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Goto","ra","","");
            create_ins(0,"EndFunc","","","");
        }
#line 1794 "parser.tab.c"
    break;

  case 12:
#line 155 "parser.y"
                                                                                                 {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-6].elem)->addr, 0, (yyvsp[-7].elem)->lineno, 1);

            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Goto","ra","","");
            create_ins(0,"EndFunc","","","");
        }
#line 1808 "parser.tab.c"
    break;

  case 13:
#line 167 "parser.y"
    {   
        (yyval.elem)=(yyvsp[0].elem);

        create_ins(0,chartostring((yyvsp[0].elem)->addr)+":","","","");
        create_ins(0,"BeginFunc","","","");
        // paramStack.pop(); //popping return address
        create_ins(0,"ra","=","PopParam","");

        //STE code start
        ste* lookup_ste = current_ste;
        if(lookup(lookup_ste, (yyvsp[0].elem)->addr) == NULL){
            current_ste = insert_entry_new_scope(current_ste);
        }
        else{
            cerr<<"Error: Function "<<(yyvsp[0].elem)->addr<<" already declared\n";
            exit(1);
        }
        //STE code end
    }
#line 1832 "parser.tab.c"
    break;

  case 14:
#line 187 "parser.y"
                        {
        (yyval.elem)=(yyvsp[0].elem);
        get_prev_scope(current_ste)->return_type = (yyvsp[0].elem)->addr;
    }
#line 1841 "parser.tab.c"
    break;

  case 15:
#line 193 "parser.y"
                                                     {  
            (yyval.elem) = create_node(4, "parameters", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[-1].elem)->num_params;
            // cout<<"parameterts done"<<endl;
        }
#line 1852 "parser.tab.c"
    break;

  case 16:
#line 201 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;
            (yyval.elem)->ins = instCount+1;
            
            // paramStack.pop();
			create_ins(0,(yyvsp[0].elem)->addr,"=","PopParam","");
        }
#line 1865 "parser.tab.c"
    break;

  case 17:
#line 209 "parser.y"
                                         {  
            (yyval.elem) = create_node(4, "typedargslist", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;

            (yyval.elem)->num_params = (yyvsp[-2].elem)->num_params + 1;
            (yyval.elem)->ins = instCount+1;
            // paramStack.pop();
			create_ins(0,(yyvsp[0].elem)->addr,"=","PopParam","");
        }
#line 1879 "parser.tab.c"
    break;

  case 18:
#line 220 "parser.y"
                   {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1887 "parser.tab.c"
    break;

  case 19:
#line 223 "parser.y"
                            {  
            (yyval.elem) = create_node(4, "typedarg", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");    //is this instruction needed?????
        }
#line 1897 "parser.tab.c"
    break;

  case 20:
#line 230 "parser.y"
             {  
            (yyval.elem)=(yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
        }
#line 1906 "parser.tab.c"
    break;

  case 21:
#line 234 "parser.y"
                               {  
            (yyval.elem) = create_node(4, "tfpdef", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem)); 
			(yyval.elem)->ins = instCount+1;
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;

            //STE code start
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[-2].elem)->addr) == NULL){
                current_ste = insert_entry_same_scope(current_ste, "VARIABLE", (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr, (yyvsp[-2].elem)->lineno, 1);
            }
            else{
                cerr<<"Error: Variable "<<(yyvsp[-2].elem)->addr<<" already declared\n";
                exit(1);
            }
            //STE code end

        }
#line 1928 "parser.tab.c"
    break;

  case 22:
#line 253 "parser.y"
                        { 
        	(yyval.elem)=(yyvsp[0].elem);
        }
#line 1936 "parser.tab.c"
    break;

  case 23:
#line 256 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem); 
        }
#line 1944 "parser.tab.c"
    break;

  case 24:
#line 261 "parser.y"
                                                {  
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 1952 "parser.tab.c"
    break;

  case 25:
#line 264 "parser.y"
                                   {  
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 1960 "parser.tab.c"
    break;

  case 26:
#line 269 "parser.y"
                                {   
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1968 "parser.tab.c"
    break;

  case 27:
#line 272 "parser.y"
                                                     {  
           (yyval.elem) = create_node(3, "small_stmt_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
		   (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
           (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, (yyvsp[0].elem)->nextlist);
        }
#line 1978 "parser.tab.c"
    break;

  case 28:
#line 279 "parser.y"
                            {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1986 "parser.tab.c"
    break;

  case 29:
#line 282 "parser.y"
                        {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1994 "parser.tab.c"
    break;

  case 30:
#line 285 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2002 "parser.tab.c"
    break;

  case 31:
#line 290 "parser.y"
                                     { 
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            // Here add instruction 
        }
#line 2012 "parser.tab.c"
    break;

  case 32:
#line 295 "parser.y"
                                                    { 
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            // Here add instruction 

            //STE code start
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[-4].elem)->addr) == NULL){
                current_ste = insert_entry_same_scope(current_ste, "VARIABLE", (yyvsp[-4].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[-4].elem)->lineno, 1);
            }
            else{
                cerr<<"Error: Variable "<<(yyvsp[-4].elem)->addr<<" already declared\n";
                exit(1);
            }
            //STE code end

        }
#line 2034 "parser.tab.c"
    break;

  case 33:
#line 312 "parser.y"
                   {
			(yyval.elem)=(yyvsp[0].elem);
        }
#line 2042 "parser.tab.c"
    break;

  case 34:
#line 315 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-2].elem)->ins;
			create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, ""); 
        }
#line 2052 "parser.tab.c"
    break;

  case 35:
#line 320 "parser.y"
                                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem));
			(yyval.elem)->ins = (yyvsp[-4].elem)->ins;
			create_ins(0, (yyvsp[-4].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, ""); 
            //STE code start
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[-4].elem)->addr) == NULL){
                current_ste = insert_entry_same_scope(current_ste, "VARIABLE", (yyvsp[-4].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[-4].elem)->lineno, 1, (yyvsp[0].elem)->list_size);
                // cout<<$1->addr<<" "<<current_ste->offset<<endl;
            }
            else{
                cerr<<"Error: Variable "<<(yyvsp[-4].elem)->addr<<" already declared\n";
                exit(1);
            }
            //STE code end
        }
#line 2073 "parser.tab.c"
    break;

  case 36:
#line 338 "parser.y"
                                 {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2081 "parser.tab.c"
    break;

  case 37:
#line 341 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;    //x=y=z
        }
#line 2092 "parser.tab.c"
    break;

  case 38:
#line 349 "parser.y"
                        {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2100 "parser.tab.c"
    break;

  case 39:
#line 352 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2108 "parser.tab.c"
    break;

  case 40:
#line 355 "parser.y"
                         {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2116 "parser.tab.c"
    break;

  case 41:
#line 360 "parser.y"
                    {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = instCount+1;
            int temp = loopStack.top();
            loopStack.pop();
            create_ins(0, "goto", to_string(loopStack.top()), "", "");
            loopStack.push(temp);
        }
#line 2129 "parser.tab.c"
    break;

  case 42:
#line 369 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = instCount+1;
            create_ins(0, "goto", to_string(loopStack.top()), "", "");
        }
#line 2139 "parser.tab.c"
    break;

  case 43:
#line 375 "parser.y"
                        {  
            create_ins(0,"return","","","");
        }
#line 2147 "parser.tab.c"
    break;

  case 44:
#line 378 "parser.y"
                          {  
            (yyval.elem)->return_param = str_to_ch(newTemp());
            create_ins(0,(yyval.elem)->return_param,"=",(yyvsp[0].elem)->addr,"");
            // paramStack.push($$->return_param);
            create_ins(0,"return",(yyval.elem)->return_param,"","");
        }
#line 2158 "parser.tab.c"
    break;

  case 45:
#line 386 "parser.y"
                           {  
            (yyval.elem) = create_node(3, "global_stmt", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 2167 "parser.tab.c"
    break;

  case 46:
#line 390 "parser.y"
                                      {   
            (yyval.elem) = create_node(4, "global_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 2176 "parser.tab.c"
    break;

  case 47:
#line 396 "parser.y"
                               {  
            (yyval.elem) = create_node(3, "comma_name_star", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 2185 "parser.tab.c"
    break;

  case 48:
#line 400 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "comma_name_star", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 2194 "parser.tab.c"
    break;

  case 49:
#line 405 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);  
        }
#line 2202 "parser.tab.c"
    break;

  case 50:
#line 408 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
            loopStack.pop();
        }
#line 2211 "parser.tab.c"
    break;

  case 51:
#line 412 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
            loopStack.pop();
        }
#line 2220 "parser.tab.c"
    break;

  case 52:
#line 416 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2228 "parser.tab.c"
    break;

  case 53:
#line 419 "parser.y"
                       {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 2236 "parser.tab.c"
    break;

  case 54:
#line 424 "parser.y"
                                         {  
           (yyval.elem)=create_node(6, "if_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
           (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
           backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
           (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);

            //STE code start
            // current_ste = get_prev_scope(current_ste);  
            //STE code end

        }
#line 2252 "parser.tab.c"
    break;

  case 55:
#line 435 "parser.y"
                                                                   {  
            (yyval.elem) = create_node(11, "if_else_stmt", (yyvsp[-9].elem),(yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            vector<int> temp = merge((yyvsp[-5].elem)->nextlist, (yyvsp[-4].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end

        }
#line 2269 "parser.tab.c"
    break;

  case 56:
#line 447 "parser.y"
                                                    {  
            (yyval.elem) = create_node(8, "if_elif_stmt", (yyvsp[-6].elem),(yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);     
            vector<int> temp = merge((yyvsp[-2].elem)->nextlist, (yyvsp[-1].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);    
        }
#line 2281 "parser.tab.c"
    break;

  case 57:
#line 456 "parser.y"
            {
        (yyval.elem)=(yyvsp[0].elem);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "IF", "IF", 0, $1->lineno, 0);
    }
#line 2291 "parser.tab.c"
    break;

  case 58:
#line 463 "parser.y"
                {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        // current_ste = get_prev_scope(current_ste);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "ELSE", "ELSE", 0, $1->lineno, 1);

        //STE code end
    }
#line 2305 "parser.tab.c"
    break;

  case 59:
#line 474 "parser.y"
                   {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        // current_ste = get_prev_scope(current_ste);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "ELSE_IF", "ELSE_IF", 0, $1->lineno, 1);
        //STE code end
    }
#line 2318 "parser.tab.c"
    break;

  case 60:
#line 485 "parser.y"
                                             {  
            (yyval.elem)=create_node(6, "elif_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end
        }
#line 2333 "parser.tab.c"
    break;

  case 61:
#line 495 "parser.y"
                                                       {  
            (yyval.elem) = create_node(8, "elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-5].elem)->ins;
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist));
        }
#line 2345 "parser.tab.c"
    break;

  case 62:
#line 502 "parser.y"
                                                                       {  
            (yyval.elem) = create_node(11, "elif_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-8].elem)->ins;
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-5].elem)->nextlist, merge((yyvsp[-4].elem)->nextlist,(yyvsp[0].elem)->nextlist));

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end
        }
#line 2361 "parser.tab.c"
    break;

  case 63:
#line 515 "parser.y"
                                                     {  
            (yyval.elem) = create_node(7, "while_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            backpatch((yyvsp[0].elem)->nextlist, (yyvsp[-4].elem)->ins);
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = (yyvsp[-3].elem)->falselist;
            create_ins(0, "goto", to_string((yyvsp[-4].elem)->ins), "", "");

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end
        }
#line 2378 "parser.tab.c"
    break;

  case 64:
#line 527 "parser.y"
                                                                                     {   
			(yyval.elem) = create_node(12, "while_else_stmt", (yyvsp[-10].elem), (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-9].elem)->ins;
			backpatch((yyvsp[-4].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-5].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
			backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
			(yyval.elem)->nextlist = (yyvsp[0].elem)->nextlist; //verify //verified 

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end
        }
#line 2396 "parser.tab.c"
    break;

  case 65:
#line 542 "parser.y"
                   {
        (yyval.elem)=(yyvsp[0].elem);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "WHILE", "WHILE", 0, $1->lineno, 0);
    }
#line 2406 "parser.tab.c"
    break;

  case 66:
#line 549 "parser.y"
                   { 
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            loopStack.push((yyval.elem)->ins);
        }
#line 2416 "parser.tab.c"
    break;

  case 67:
#line 555 "parser.y"
                                              { 
            (yyval.elem) = create_node(6, "for_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;

            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = (yyvsp[-3].elem)->falselist;   //check this filling //checked

            // create_ins(1, $2->for_it, "+", $2->for_it, "1");
            // backpatch($5->nextlist, instCount); //suite nextlist will be patched to update statement of for loop
            backpatch((yyvsp[0].elem)->nextlist, (yyvsp[-3].elem)->ins); //suite nextlist will be patched to update statement of for loop
            create_ins(0, "goto", to_string((yyvsp[-3].elem)->ins), "", "");

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end            
        }
#line 2437 "parser.tab.c"
    break;

  case 68:
#line 571 "parser.y"
                                                                  { 
            (yyval.elem) = create_node(11, "for_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-9].elem)->ins;

            (yyvsp[0].elem)->nextlist = merge((yyvsp[0].elem)->nextlist, makelist(instCount+1));
            create_ins(0, "goto", "", "", "");
            
            // create_ins(1, $2->for_it, "+", $2->for_it, "1");
            // backpatch($6->nextlist, instCount); 
            // backpatch($5->nextlist, instCount);
            backpatch((yyvsp[-4].elem)->nextlist, (yyvsp[-8].elem)->ins); 
            backpatch((yyvsp[-5].elem)->nextlist, (yyvsp[-8].elem)->ins);
            create_ins(0, "goto", to_string((yyvsp[-8].elem)->ins), "", "");

            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);

            (yyval.elem)->nextlist = (yyvsp[0].elem)->nextlist; //verify

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end
        }
#line 2465 "parser.tab.c"
    break;

  case 69:
#line 596 "parser.y"
                               { 
            (yyval.elem) = create_node(3, "for_core", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));


            create_ins(0, (yyvsp[-2].elem)->addr, "=", to_string(chartonum((yyvsp[0].elem)->for_start)-1), "");

            create_ins(1, (yyvsp[-2].elem)->addr, "+", (yyvsp[-2].elem)->addr, "1");
            loopStack.push(instCount);
            (yyval.elem)->ins = instCount;
            string temp = newTemp();
            create_ins(1, temp, "<", (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->for_end);
            (yyval.elem)->truelist = makelist(instCount+1);
            (yyval.elem)->falselist = makelist(instCount+2);
            create_ins(0, "if", temp, "goto", "");
            create_ins(0, "goto", "", "", "");        
        }
#line 2486 "parser.tab.c"
    break;

  case 70:
#line 614 "parser.y"
               {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        //loopStack.push($$->ins);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "FOR", "FOR", 0, $1->lineno, 0);
        //STE code end
    }
#line 2499 "parser.tab.c"
    break;

  case 71:
#line 624 "parser.y"
                                                      {
            (yyval.elem) = create_node(5, "range_stmt", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;

            (yyval.elem)->for_end = (yyvsp[-1].elem)->addr;
            (yyval.elem)->for_start = strdup("0");
        }
#line 2511 "parser.tab.c"
    break;

  case 72:
#line 631 "parser.y"
                                                               {
            (yyval.elem) = create_node(7, "range_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;

            (yyval.elem)->for_end = (yyvsp[-1].elem)->addr;
            (yyval.elem)->for_start = (yyvsp[-3].elem)->addr;
        }
#line 2523 "parser.tab.c"
    break;

  case 73:
#line 640 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            //loopStack.push($$->ins);
        }
#line 2533 "parser.tab.c"
    break;

  case 74:
#line 647 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2541 "parser.tab.c"
    break;

  case 75:
#line 650 "parser.y"
                                            {
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 2549 "parser.tab.c"
    break;

  case 76:
#line 653 "parser.y"
                                                    { 
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 2557 "parser.tab.c"
    break;

  case 77:
#line 659 "parser.y"
                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2565 "parser.tab.c"
    break;

  case 78:
#line 665 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2573 "parser.tab.c"
    break;

  case 79:
#line 668 "parser.y"
                                         {  
            (yyval.elem) = create_node(5, "or_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;
        }
#line 2585 "parser.tab.c"
    break;

  case 80:
#line 676 "parser.y"
                                            {
            (yyval.elem) = create_node(5, "and_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;
        }
#line 2597 "parser.tab.c"
    break;

  case 81:
#line 683 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2605 "parser.tab.c"
    break;

  case 82:
#line 688 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2613 "parser.tab.c"
    break;

  case 83:
#line 691 "parser.y"
                                          {  
            (yyval.elem) = create_node(5, "and_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;
        }
#line 2625 "parser.tab.c"
    break;

  case 84:
#line 699 "parser.y"
                                              { 
            (yyval.elem) = create_node(5, "not_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;
        }
#line 2637 "parser.tab.c"
    break;

  case 85:
#line 706 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2645 "parser.tab.c"
    break;

  case 86:
#line 711 "parser.y"
                         { 
            (yyval.elem) = create_node(3, "not_test", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->truelist = (yyvsp[0].elem)->falselist;
            (yyval.elem)->falselist = (yyvsp[0].elem)->truelist;
        }
#line 2656 "parser.tab.c"
    break;

  case 87:
#line 717 "parser.y"
                        { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2664 "parser.tab.c"
    break;

  case 88:
#line 722 "parser.y"
                  {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2672 "parser.tab.c"
    break;

  case 89:
#line 725 "parser.y"
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
#line 2687 "parser.tab.c"
    break;

  case 90:
#line 737 "parser.y"
                    {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2695 "parser.tab.c"
    break;

  case 91:
#line 740 "parser.y"
                    { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2703 "parser.tab.c"
    break;

  case 92:
#line 743 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2711 "parser.tab.c"
    break;

  case 93:
#line 746 "parser.y"
                            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2719 "parser.tab.c"
    break;

  case 94:
#line 749 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2727 "parser.tab.c"
    break;

  case 95:
#line 752 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2735 "parser.tab.c"
    break;

  case 96:
#line 755 "parser.y"
                   {
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2743 "parser.tab.c"
    break;

  case 97:
#line 758 "parser.y"
            {  
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2751 "parser.tab.c"
    break;

  case 98:
#line 761 "parser.y"
                { 
        (yyval.elem) = create_node(3, "NOT IN", (yyvsp[-1].elem), (yyvsp[0].elem));
    }
#line 2759 "parser.tab.c"
    break;

  case 99:
#line 764 "parser.y"
            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2767 "parser.tab.c"
    break;

  case 100:
#line 767 "parser.y"
                { 
        (yyval.elem) = create_node(3, "IS NOT", (yyvsp[-1].elem), (yyvsp[0].elem));
    }
#line 2775 "parser.tab.c"
    break;

  case 101:
#line 772 "parser.y"
                  { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2783 "parser.tab.c"
    break;

  case 102:
#line 775 "parser.y"
                                  {  
            (yyval.elem) = create_node(4, "expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2794 "parser.tab.c"
    break;

  case 103:
#line 783 "parser.y"
                   { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2802 "parser.tab.c"
    break;

  case 104:
#line 786 "parser.y"
                                       {  
            (yyval.elem) = create_node(4, "xor_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2813 "parser.tab.c"
    break;

  case 105:
#line 794 "parser.y"
                       { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2822 "parser.tab.c"
    break;

  case 106:
#line 798 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "and_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2833 "parser.tab.c"
    break;

  case 107:
#line 806 "parser.y"
                         { 
                (yyval.elem) = (yyvsp[0].elem); 
            }
#line 2841 "parser.tab.c"
    break;

  case 108:
#line 809 "parser.y"
                                                 { 
                (yyval.elem) = create_node(4, "shift_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2852 "parser.tab.c"
    break;

  case 109:
#line 817 "parser.y"
                 { 
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 2860 "parser.tab.c"
    break;

  case 110:
#line 820 "parser.y"
                                   { 
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2871 "parser.tab.c"
    break;

  case 111:
#line 826 "parser.y"
                                    { 
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2882 "parser.tab.c"
    break;

  case 112:
#line 833 "parser.y"
             {
            (yyval.elem) = (yyvsp[0].elem); 
        }
#line 2890 "parser.tab.c"
    break;

  case 113:
#line 836 "parser.y"
                                  {
            (yyval.elem) = create_node(4, "term", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        
		}
#line 2902 "parser.tab.c"
    break;

  case 114:
#line 845 "parser.y"
                            { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2910 "parser.tab.c"
    break;

  case 115:
#line 848 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2918 "parser.tab.c"
    break;

  case 116:
#line 851 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2926 "parser.tab.c"
    break;

  case 117:
#line 854 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2934 "parser.tab.c"
    break;

  case 118:
#line 857 "parser.y"
                           { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2942 "parser.tab.c"
    break;

  case 119:
#line 862 "parser.y"
                                    {  
            (yyval.elem) = create_node(3, "factor", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr,"", (yyvsp[0].elem)->addr);
        }
#line 2953 "parser.tab.c"
    break;

  case 120:
#line 868 "parser.y"
                    { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2961 "parser.tab.c"
    break;

  case 121:
#line 872 "parser.y"
                            {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2969 "parser.tab.c"
    break;

  case 122:
#line 875 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2977 "parser.tab.c"
    break;

  case 123:
#line 878 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2985 "parser.tab.c"
    break;

  case 124:
#line 882 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2993 "parser.tab.c"
    break;

  case 125:
#line 885 "parser.y"
                                            { 
            (yyval.elem) = create_node(4, "power", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 3004 "parser.tab.c"
    break;

  case 126:
#line 893 "parser.y"
                {  
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 3013 "parser.tab.c"
    break;

  case 127:
#line 897 "parser.y"
                       {   //this is function call
            (yyval.elem) = create_node(3, "atom_expr", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;

            string temp = newTemp();
            (yyval.elem)->addr = str_to_ch(temp);
            create_ins(0, temp, "=" ,"call "+chartostring((yyvsp[-1].elem)->addr), "");
            create_ins(0, "PopParam", temp, "", "");
            backpatch((yyvsp[0].elem)->nextlist, instCount);


        }
#line 3030 "parser.tab.c"
    break;

  case 128:
#line 909 "parser.y"
                                            {
            (yyval.elem) = create_node(5, "atom_expr", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;

            string temp = newTemp();
            create_ins(1, temp, "*", (yyvsp[-1].elem)->addr, to_string(get_width(lookup(current_ste, (yyvsp[-3].elem)->addr)->type)));
            (yyval.elem)->addr = str_to_ch(chartostring((yyvsp[-3].elem)->addr) + "["+temp+"]");
        }
#line 3043 "parser.tab.c"
    break;

  case 129:
#line 917 "parser.y"
                             { 
            (yyval.elem) = create_node(4, "atom_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 3052 "parser.tab.c"
    break;

  case 130:
#line 924 "parser.y"
                                           { 
        (yyval.elem)=(yyvsp[-1].elem);
    }
#line 3060 "parser.tab.c"
    break;

  case 131:
#line 927 "parser.y"
                                    {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 3069 "parser.tab.c"
    break;

  case 132:
#line 932 "parser.y"
                                           { 
        (yyval.elem) = (yyvsp[-1].elem);
        
    }
#line 3078 "parser.tab.c"
    break;

  case 133:
#line 936 "parser.y"
                                {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 3087 "parser.tab.c"
    break;

  case 134:
#line 941 "parser.y"
                                { 
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 3096 "parser.tab.c"
    break;

  case 135:
#line 945 "parser.y"
                {
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
     }
#line 3105 "parser.tab.c"
    break;

  case 136:
#line 949 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 3114 "parser.tab.c"
    break;

  case 137:
#line 953 "parser.y"
                        { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 3122 "parser.tab.c"
    break;

  case 138:
#line 956 "parser.y"
                        { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 3131 "parser.tab.c"
    break;

  case 139:
#line 961 "parser.y"
                        {
            (yyval.elem) = (yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
        }
#line 3140 "parser.tab.c"
    break;

  case 140:
#line 965 "parser.y"
                                { 
            (yyval.elem) = create_node(3, "STRING_PLUS", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 3149 "parser.tab.c"
    break;

  case 141:
#line 971 "parser.y"
                                     { 
            (yyval.elem) = create_node(3, "trailer", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;

            create_ins(0, "PushParam", "", "", "");
            (yyval.elem)->nextlist = makelist(instCount);
        }
#line 3161 "parser.tab.c"
    break;

  case 142:
#line 978 "parser.y"
                                              {
            (yyval.elem)=(yyvsp[-1].elem);

        }
#line 3170 "parser.tab.c"
    break;

  case 143:
#line 990 "parser.y"
                           { 
            (yyval.elem) = (yyvsp[0].elem);
            (yyval.elem)-> addr = str_to_ch(chartostring((yyvsp[0].elem)->addr) + "]");
        }
#line 3179 "parser.tab.c"
    break;

  case 144:
#line 994 "parser.y"
                                {
            (yyval.elem)=create_node(3,"testlist",(yyvsp[-1].elem),(yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
            (yyval.elem)->list_size = (yyvsp[-1].elem)->list_size;
            (yyval.elem)-> addr = str_to_ch(chartostring((yyvsp[-1].elem)->addr) + "]");
        }
#line 3190 "parser.tab.c"
    break;

  case 145:
#line 1001 "parser.y"
                            {
            (yyval.elem) = (yyvsp[0].elem);
            (yyval.elem)->list_size = 1;
            (yyval.elem)-> addr = str_to_ch( "[" + chartostring((yyvsp[0].elem)->addr));
        }
#line 3200 "parser.tab.c"
    break;

  case 146:
#line 1006 "parser.y"
                              {
            (yyval.elem) = create_node(4, "testlist_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;

            //STE code start
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[-2].elem)->addr) == NULL){
                current_ste = insert_entry_same_scope(current_ste, "VARIABLE", (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr, (yyvsp[-2].elem)->lineno, 1);
            }
            else{
                cerr<<"Error: Variable "<<(yyvsp[-2].elem)->addr<<" already declared\n";
                exit(1);
            }
            //STE code end

        }
#line 3221 "parser.tab.c"
    break;

  case 147:
#line 1022 "parser.y"
                                    { 
            (yyval.elem) = create_node(4, "testlist_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->list_size = (yyvsp[-2].elem)->list_size + 1;
            //cout<<$1->addr<<endl;
            (yyval.elem)-> addr = str_to_ch(chartostring((yyvsp[-2].elem)->addr) + "," + chartostring((yyvsp[0].elem)->addr));
            //cout<<$$->addr<<endl;
        }
#line 3234 "parser.tab.c"
    break;

  case 148:
#line 1030 "parser.y"
                                                   { 
            (yyval.elem) = create_node(6, "testlist_list", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;

            //STE code start
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[-2].elem)->addr) == NULL){
                current_ste = insert_entry_same_scope(current_ste, "VARIABLE", (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr, (yyvsp[-2].elem)->lineno, 1);
            }
            else{
                cerr<<"Error: Variable "<<(yyvsp[-2].elem)->addr<<" already declared\n";
                exit(1);
            }
            //STE code end
        }
#line 3254 "parser.tab.c"
    break;

  case 149:
#line 1047 "parser.y"
                                            { 
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "CLASS", (yyvsp[-2].elem)->addr, 0, (yyvsp[-3].elem)->lineno, 1);
        }
#line 3263 "parser.tab.c"
    break;

  case 150:
#line 1051 "parser.y"
                                                                       { 
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "CLASS", (yyvsp[-4].elem)->addr, 0, (yyvsp[-5].elem)->lineno, 1);
        }
#line 3272 "parser.tab.c"
    break;

  case 151:
#line 1055 "parser.y"
                                                                               { 
           current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "CLASS", (yyvsp[-5].elem)->addr, (yyvsp[-3].elem)->num_params, (yyvsp[-6].elem)->lineno, 1);
        }
#line 3281 "parser.tab.c"
    break;

  case 152:
#line 1061 "parser.y"
                 {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        ste* lookup_ste = current_ste;
        if(lookup(lookup_ste, (yyvsp[0].elem)->addr) == NULL){
            current_ste = insert_entry_new_scope(current_ste);
        }
        else{
            cerr<<"Error: Class "<<(yyvsp[0].elem)->addr<<" already declared\n";
            exit(1);
        }
        //STE code end

        create_ins(0, chartostring((yyvsp[0].elem)->addr)+":","","","");
        create_ins(0,"BeginClass","","","");
        
}
#line 3303 "parser.tab.c"
    break;

  case 153:
#line 1081 "parser.y"
                           { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3311 "parser.tab.c"
    break;

  case 154:
#line 1084 "parser.y"
                                 { 
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 3319 "parser.tab.c"
    break;

  case 155:
#line 1088 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;

            (yyval.elem)->ins = instCount+1;
            (yyval.elem)->nextlist = makelist(instCount+1);
            create_ins(0, "PushParam", "", "", "");
            create_ins(0, "PushParam", (yyvsp[0].elem)->addr, "", "");
        }
#line 3333 "parser.tab.c"
    break;

  case 156:
#line 1097 "parser.y"
                                        { 
            (yyval.elem) = create_node(4, "argument_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[-2].elem)->num_params + 1;

            create_ins(0, "PushParam", (yyvsp[0].elem)->addr, "", "");
            (yyval.elem)->nextlist = (yyvsp[-2].elem)->nextlist;
        }
#line 3346 "parser.tab.c"
    break;

  case 157:
#line 1107 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3354 "parser.tab.c"
    break;

  case 158:
#line 1110 "parser.y"
                            { 
            (yyval.elem) = create_node(4, "argument", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
        }
#line 3364 "parser.tab.c"
    break;

  case 159:
#line 1118 "parser.y"
                {
                    (yyval.elem) = (yyvsp[0].elem);
                    (yyval.elem)->ins = instCount+1;

                    // backpatch($1->nextlist,$$->ins);
                }
#line 3375 "parser.tab.c"
    break;

  case 160:
#line 1126 "parser.y"
                      { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3383 "parser.tab.c"
    break;

  case 161:
#line 1129 "parser.y"
                                            { 
            (yyval.elem) = (yyvsp[-1].elem);
        }
#line 3391 "parser.tab.c"
    break;

  case 162:
#line 1132 "parser.y"
                                                    { 
            (yyval.elem) = (yyvsp[-2].elem);
        }
#line 3399 "parser.tab.c"
    break;

  case 163:
#line 1137 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3407 "parser.tab.c"
    break;

  case 164:
#line 1140 "parser.y"
                            { 
            (yyval.elem)=create_node(3,"stmt_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
            (yyval.elem)->nextlist = merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist);
        }
#line 3417 "parser.tab.c"
    break;


#line 3421 "parser.tab.c"

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
#line 1146 "parser.y"


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

void backpatch_str(vector<int>p, string str){
	for(int j=0;j<p.size();j++)
		instructions[p[j]-1].push_back(str);
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


ste* setup_global_sym_table(ste* curr_ste){
    curr_ste->lexeme = "global_head";
    curr_ste->type = "GLOBAL_HEAD";
    curr_ste = insert_entry_same_scope(curr_ste, "ATOM_KEYWORDS", "True", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "ATOM_KEYWORDS", "False", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "ELSE", "else", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "ATOM_KEYWORDS", "None", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "BREAK", "break", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "IN", "in", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "CLASS", "class", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "IS", "is", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "RETURN", "return", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "AND", "and", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "CONTINUE", "continue", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "FOR", "for", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "DEF", "def", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "WHILE", "while", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "GLOBAL", "global", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "NOT", "not", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "ELIF", "elif", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "IF", "if", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "OR", "or", "RESERVED_KEYWORD", -1, -1);
    return curr_ste;
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
    /* yydebug=1; */
    current_ste = setup_global_sym_table(current_ste);
    /* cout<<"Parsing Started\n"; */
    yyparse();
    fclose(yyin); 

    print_ste(global_sym_table,0);

/*--------------------------------------------------------------*/

// Create 3AC file
    MakeIRFile();

// Close the output file
    code_out.close();

/*--------------------------------------------------------------*/
    return 0;

}
