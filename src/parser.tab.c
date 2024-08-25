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
    // #include "data.h"
    // #include "symbol_table.cpp"
    #include "x86.cpp"
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
    stack<string> iterStack;
    // stack<string> paramStack;

    //map<NODE*,map<string,int>> global_offset;

    int instCount;
    vector<vector<string>> instructions;
    vector<int> makelist(int i);
    void backpatch(vector<int> p, int i);
    void backpatch_str(vector<int> p, string str);
    void create_ins(int type,string i,string op,string arg1,string arg2);
    vector<int> merge(vector<int> p1, vector<int> p2);
    void vector_copy(vector<string> v1,vector<string> v2);
    string newTemp();
    char* str_to_ch(string s);
    int tempCount;
    fstream code_out;
    string typecast(string , string, string);

    // map<string,ste> global_sym_table;
    ste* global_sym_table = new ste;   //pointer to the head(initialising entry) of the global symbol table
    ste* current_ste = global_sym_table;   //pointer to current symbol table entry (initialised to pointer of head of the global symbol table)  
    map<string, ste*> class_map;

    int endline=0;

    int funcOffset = 0;

    int inClass = 0;
    int ischild = 0;
    string className;
    unordered_map <string, int> typeMap;
    int isatom=0;
    int incheck=0;
    int isinsquare =0;


    //m3 start
    int stack_offset=16;    //8 bytes for rbp and 8 bytes for rip
    map<string, int> offset_map;
    map<string,string> class_parent;
    map<string,int> class_offset_map;
    int class_offset =0;
    string curr_class="";
    // map<string, int> string_map_mohak;
    map<string, string> obj_class;
    //m3 end

    char* numtochar( int num){  
        char* c = new char[100];
        int i=0;
        while(num>0){
            c[i] = num%10 + '0';
            num/=10;
            i++;
        }
        c[i]='\0';
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

#line 168 "parser.tab.c"

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
    IS = 314,
    TRUE = 315,
    FALSE = 316,
    NUMBER = 317,
    NONE = 318,
    LEN = 319,
    PRINT = 320,
    D_MAIN = 321,
    D_NAME = 322,
    SELF = 323
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 99 "parser.y"

    struct node *elem;

#line 293 "parser.tab.c"

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
#define YYFINAL  88
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   743

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  313

#define YYUNDEFTOK  2
#define YYMAXUTOK   323


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   120,   127,   135,   142,   146,   149,   152,
     159,   189,   217,   239,   265,   269,   325,   329,   335,   352,
     366,   379,   388,   411,   414,   446,   458,   497,   500,   505,
     508,   513,   516,   528,   531,   534,   539,   578,   661,   664,
     719,   845,   888,   921,   924,   952,   955,   958,   963,   975,
     982,   987,  1000,  1006,  1013,  1018,  1024,  1027,  1032,  1037,
    1040,  1045,  1065,  1084,  1099,  1109,  1114,  1126,  1134,  1145,
    1157,  1174,  1189,  1209,  1226,  1248,  1256,  1265,  1300,  1331,
    1360,  1370,  1381,  1394,  1401,  1404,  1407,  1413,  1418,  1421,
    1434,  1446,  1451,  1454,  1467,  1479,  1484,  1495,  1508,  1513,
    1520,  1524,  1555,  1558,  1561,  1564,  1567,  1570,  1573,  1576,
    1579,  1583,  1586,  1592,  1595,  1632,  1635,  1672,  1676,  1713,
    1716,  1754,  1757,  1797,  1838,  1841,  1885,  1888,  1891,  1894,
    1897,  1902,  1921,  1925,  1928,  1931,  1935,  1938,  1959,  1962,
    2158,  2199,  2271,  2305,  2319,  2349,  2355,  2359,  2365,  2382,
    2389,  2395,  2424,  2430,  2433,  2440,  2451,  2463,  2477,  2485,
    2491,  2497,  2510,  2516,  2530,  2540,  2570,  2590,  2652,  2681,
    2705,  2729,  2802,  2806,  2812,  2815,  2843,  2850,  2861,  2882,
    2887,  2903,  2906
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
  "GLOBAL", "ATOM_KEYWORDS", "STRING", "OPEN_BRACKET", "CLOSE_BRACKET",
  "EQUAL", "SEMI_COLON", "COLON", "COMMA", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "REMAINDER", "ATTHERATE", "NEGATION", "BIT_AND", "BIT_OR",
  "BIT_XOR", "DOT", "CURLY_OPEN", "CURLY_CLOSE", "SQUARE_OPEN",
  "SQUARE_CLOSE", "LESS_THAN", "GREATER_THAN", "EQUAL_EQUAL",
  "GREATER_THAN_EQUAL", "LESS_THAN_EQUAL", "NOT_EQUAL_ARROW", "NOT_EQUAL",
  "IS", "TRUE", "FALSE", "NUMBER", "NONE", "LEN", "PRINT", "D_MAIN",
  "D_NAME", "SELF", "$accept", "M", "N", "for_else_N", "file", "snippet",
  "funcdef", "T", "func_name", "func_ret_type", "parameters",
  "typedargslist", "typedarg", "tfpdef", "stmt", "simple_stmt",
  "small_stmt_list", "small_stmt", "expr_stmt", "obj_dec",
  "eq_testlist_star_expr_plus", "flow_stmt", "break_stmt", "continue_stmt",
  "return_stmt", "global_stmt", "comma_name_star", "compound_stmt",
  "if_stmt", "if_expr", "d_expr", "if_scope", "else_scope",
  "else_if_scope", "nts_star", "while_stmt", "while_scope", "while_expr",
  "for_stmt", "for_core", "for_scope", "range_stmt", "for_test", "suite",
  "test", "or_test", "and_test_star", "and_test", "not_test_star",
  "not_test", "comparison", "comp_op", "expr", "xor_expr", "and_expr",
  "shift_expr", "arith_expr", "term", "term_choice", "factor",
  "factor_choice", "power", "atom_expr", "S", "atom", "STRING_PLUS",
  "trailer", "testlist", "testlist_list", "classdef", "class_declare",
  "class_body_suite", "funcdef_plus", "arglist", "argument_list",
  "argument", "stmt_plus", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

#define YYPACT_NINF (-255)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-96)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     119,   119,  -255,  -255,  -255,  -255,   635,  -255,  -255,   635,
      15,    26,    30,  -255,    -5,   415,  -255,  -255,  -255,   -18,
    -255,  -255,  -255,  -255,  -255,     2,    56,    32,    89,  -255,
    -255,   119,  -255,    18,  -255,  -255,    63,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,   459,  -255,  -255,  -255,   675,    34,
    -255,    81,    82,    84,    86,  -255,   173,    62,    64,    65,
      20,     7,  -255,   675,  -255,     6,  -255,  -255,  -255,    77,
    -255,  -255,  -255,  -255,    87,    79,  -255,    88,    91,  -255,
    -255,    80,    90,  -255,   503,   635,   635,   111,  -255,  -255,
    -255,   220,   635,    75,    95,    96,  -255,   635,    99,   116,
     635,   635,   318,  -255,  -255,  -255,   120,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,   118,   675,   675,   675,   675,   675,
     675,   675,  -255,  -255,  -255,  -255,  -255,   675,  -255,   675,
     547,   125,  -255,  -255,   635,   591,   147,    -6,     9,   139,
    -255,   141,  -255,  -255,   103,   123,   126,  -255,  -255,  -255,
    -255,   127,   129,  -255,   274,   128,  -255,  -255,   161,  -255,
    -255,    12,  -255,   635,   635,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,     7,     7,  -255,  -255,  -255,    48,   132,   134,
    -255,   135,  -255,   635,   133,  -255,   138,   167,  -255,   140,
     162,    -2,    49,  -255,   143,     3,   274,    91,  -255,  -255,
    -255,  -255,   635,  -255,   274,   172,  -255,  -255,  -255,   274,
     154,  -255,   635,   635,   157,   166,  -255,   635,   635,  -255,
     635,   137,   177,  -255,   163,   179,     3,   159,  -255,   183,
    -255,   183,   635,  -255,  -255,   164,  -255,  -255,  -255,    55,
     371,   274,   185,   635,  -255,  -255,   170,  -255,  -255,  -255,
    -255,  -255,    36,  -255,  -255,   274,    50,  -255,  -255,   274,
      83,   371,    17,   192,   195,    58,  -255,  -255,   206,  -255,
    -255,   178,  -255,  -255,  -255,  -255,  -255,   180,   635,  -255,
    -255,   208,  -255,   201,   182,  -255,   635,  -255,   274,  -255,
     184,  -255,   186,  -255,   188,  -255,   274,  -255,  -255,   274,
    -255,  -255,   274,   274,  -255,    55,  -255,    83,   187,  -255,
    -255,   274,  -255
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,   151,    67,    75,    80,     0,    48,    49,    50,
       0,     0,     0,   154,   156,     0,   133,   134,   135,     0,
     145,    98,    99,   152,   155,     0,     0,     0,     0,     5,
      59,     7,    27,     0,    31,    33,     0,    34,    45,    46,
      47,    35,    28,    56,     0,    57,     2,    58,     0,   164,
      87,     0,    88,     0,    92,    97,   100,   113,   115,   117,
     119,   121,   124,     0,   132,   136,   138,   153,    38,   162,
      60,     8,    96,    51,   169,     0,    15,     0,    52,   157,
     147,   164,     0,   150,     0,     0,     0,     0,     1,     9,
      30,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,     0,     2,     2,   109,     0,   102,   103,   104,
     105,   106,   107,   108,   111,     0,     0,     0,     0,     0,
       0,     0,   130,   126,   128,   129,   127,     0,   131,     0,
       0,     0,   145,   139,   163,     0,     0,     0,     0,     0,
      53,     0,   146,   149,     0,     0,     0,   144,    29,    32,
      41,    43,     0,     2,     0,     0,    76,     2,     0,    36,
      39,   165,    42,     0,     0,   110,   112,   101,   114,   116,
     118,   120,   122,   123,   125,   137,   158,     0,   179,     0,
     176,   177,   141,     0,   166,   170,     0,     0,   168,    25,
      14,     0,     0,    21,    23,     0,     0,    54,   165,   148,
     142,   143,     0,    66,     0,     0,    84,    64,     2,     0,
       0,    79,     0,     0,    89,    93,   161,     0,     0,   159,
       0,     0,     0,   171,     0,     0,     0,     0,    20,     0,
      18,     0,     0,    16,    17,     0,    10,    55,    44,    61,
       0,     0,    77,     0,    37,    40,     0,   180,   178,   140,
     167,   174,     0,    26,    14,     0,     0,    22,    24,     0,
       0,   181,     0,    73,     0,     0,    83,   160,     0,   172,
     175,     0,    12,    19,    11,    68,    69,     0,     0,    63,
     182,     0,    85,     0,     0,    81,     0,   173,     0,     2,
       0,    86,     0,     2,     0,    13,     0,     2,     2,     0,
      82,    62,     0,     0,    78,    70,    74,     0,     0,    71,
       2,     0,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -255,   -92,  -254,  -255,  -255,    23,  -197,   -56,  -255,    10,
    -255,     8,     4,  -255,  -202,     1,  -255,   148,  -255,  -255,
     -85,  -255,  -255,  -255,  -255,  -255,    41,  -255,  -255,   -32,
    -255,  -255,  -247,  -255,   -67,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,   -39,  -191,    -9,  -255,  -255,    92,  -255,    -3,
     144,  -255,   -38,   136,   142,   145,  -255,   -20,  -255,   -55,
    -255,  -255,  -255,   122,  -255,   238,  -255,   -11,  -255,  -255,
    -255,  -255,  -255,    39,    45,   131,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    97,   260,   264,    28,    29,    30,   227,    77,   235,
     138,   192,   193,   194,    31,   206,    33,    34,    35,    36,
     150,    37,    38,    39,    40,    41,   140,    42,    43,    94,
      95,    44,   277,   278,   279,    45,    46,   155,    47,    98,
      48,   211,   265,   207,    49,    50,    51,    52,    53,    54,
      55,   115,    56,    57,    58,    59,    60,    61,   127,    62,
      63,    64,    65,    84,    66,    67,   133,    68,    69,    70,
      75,   188,   252,   179,   180,   181,   262
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    32,    32,    72,    82,   236,    81,   189,   128,   283,
      99,   163,   164,   239,   129,   233,   160,   122,   242,   212,
     195,   281,    90,   282,    71,    14,   190,   251,    74,   119,
     228,    83,    32,    85,   229,    96,   292,   130,   261,    76,
     268,   100,   269,    78,   196,   213,   123,   124,   125,   126,
     263,   307,    91,   131,    89,   270,   132,   120,   121,   261,
     308,   204,   191,    11,   272,   209,   234,   101,   274,   102,
      -3,    -3,   174,   144,   175,    81,   145,   146,   168,    87,
     216,   230,   273,   151,   217,   231,   231,    86,   156,    88,
     285,   159,   151,   162,   286,    87,    92,   295,   275,   276,
     172,   173,   103,   -91,   104,   301,   -95,   116,   304,   118,
     117,   305,   306,   134,   136,   141,   241,   238,   135,   137,
     312,   178,   142,     1,   147,   184,   178,   139,   245,   152,
     153,   154,     2,     3,   157,   158,     4,     5,   182,   165,
     166,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,   187,   197,   198,   199,   200,    16,    17,   201,   203,
     202,   215,    18,   208,   210,   218,   219,    19,   222,    20,
     223,   220,   224,   226,   221,   225,   232,   240,   -90,    21,
      22,    23,    24,    25,    26,   243,   -94,    27,   249,   250,
      11,   253,   105,   151,   255,   106,   189,   296,   271,   259,
      -4,   299,   267,   244,   151,   302,   303,    -3,   178,   247,
     284,   178,   287,   288,   291,   289,   275,   293,   311,   297,
     300,   298,   310,   258,   148,   107,   108,   109,   110,   111,
     112,   113,   114,     2,   266,   257,   254,   256,   237,   149,
     309,    32,     6,     7,     8,     9,   290,   294,    12,    13,
      14,    15,    79,   169,   183,   214,   246,    16,    17,   167,
     170,   280,    32,    18,   171,   248,   186,     0,    19,    96,
      20,     0,     0,     0,     0,     0,     0,   266,   205,     0,
      21,    22,    23,    24,    25,    26,     0,     2,    27,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     9,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
       0,    16,    17,     0,     0,     0,     0,    18,     0,     0,
       0,     0,    19,     0,    20,     0,     0,     0,     0,     0,
     161,     2,     0,     0,    21,    22,    23,    24,    25,    26,
       6,     0,    27,     0,     0,     0,     0,    13,    14,    15,
       0,     0,     0,     0,     0,    16,    17,     0,     0,     0,
       0,    18,     0,     0,     0,     0,    19,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    22,
      23,    24,    25,    26,     2,     3,    27,     0,     4,     5,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,     0,     0,    16,    17,
       0,     0,     0,     0,    18,     0,     0,     0,     0,    19,
       0,    20,     0,     0,     0,     0,     0,     0,     2,     0,
       0,    21,    22,    23,    24,    25,    26,     6,     0,    27,
       0,     0,     0,     0,    13,    14,    15,    80,     0,     0,
       0,     0,    16,    17,     0,     0,     0,     0,    18,     0,
       0,     0,     0,    19,     0,    20,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    21,    22,    23,    24,    25,
      26,     6,     0,    27,     0,     0,     0,     0,    13,    14,
      15,     0,     0,     0,     0,     0,    16,    17,     0,     0,
       0,     0,    18,     0,     0,     0,     0,    19,     0,    20,
       0,     0,     0,     0,     0,     0,     2,     0,     0,    21,
      22,    23,    24,    25,    26,     6,    93,    27,     0,     0,
       0,     0,    13,    14,    15,     0,     0,     0,     0,     0,
      16,    17,     0,     0,     0,     0,    18,     0,     0,     0,
       0,    19,     0,    20,   143,     0,     0,     0,     0,     0,
       2,     0,     0,    21,    22,    23,    24,    25,    26,     6,
       0,    27,     0,     0,     0,     0,    13,    14,    15,   176,
       0,     0,     0,     0,    16,    17,     0,     0,     0,     0,
      18,     0,     0,     0,     0,    19,     0,    20,     0,     0,
       0,     0,     0,     0,     2,     0,     0,    21,    22,    23,
      24,    25,    26,     6,     0,   177,     0,     0,     0,     0,
      13,    14,    15,   185,     0,     0,     0,     0,    16,    17,
       0,     0,     0,     0,    18,     0,     0,     0,     0,    19,
       0,    20,     0,     0,     0,     0,     0,     0,     2,     0,
       0,    21,    22,    23,    24,    25,    26,     6,     0,    27,
       0,     0,     0,     0,    13,    14,    15,     0,     0,     0,
       0,     0,    16,    17,     0,     0,     0,     0,    18,     0,
       0,     0,     0,    19,     0,    20,     0,     0,     2,     0,
       0,     0,     0,     0,     0,    21,    22,    23,    24,    25,
      26,     0,     0,    27,    13,    14,    15,     0,     0,     0,
       0,     0,    16,    17,     0,     0,     0,     0,    18,     0,
       0,     0,     0,    19,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
       9,     0,     1,     6,    15,   196,    15,    13,    63,   263,
      48,   103,   104,   204,     8,    12,   101,    10,   209,     7,
      11,     4,     4,     6,     1,    30,    32,   224,    13,     9,
      32,    49,    31,    31,    36,    44,   283,    31,   240,    13,
       4,     7,     6,    13,    35,    33,    39,    40,    41,    42,
     241,   305,    34,    47,    31,   252,    50,    37,    38,   261,
     307,   153,    68,    27,   255,   157,    63,    33,   259,    35,
      15,    16,   127,    84,   129,    84,    85,    86,   116,    47,
      32,    32,    32,    92,    36,    36,    36,    31,    97,     0,
      32,   100,   101,   102,    36,    47,    33,   288,    15,    16,
     120,   121,    21,    21,    20,   296,    20,    45,   299,    44,
      46,   302,   303,    36,    35,    35,   208,   202,    31,    31,
     311,   130,    32,     4,    13,   134,   135,    36,   213,    54,
      35,    35,    13,    14,    35,    19,    17,    18,    13,    19,
      22,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,     4,    13,    12,    51,    32,    37,    38,    32,    30,
      33,   164,    43,    35,     3,    33,    32,    48,    35,    50,
      32,    36,     5,    11,   183,    35,    33,     5,    21,    60,
      61,    62,    63,    64,    65,    31,    20,    68,    51,    12,
      27,    12,    19,   202,    35,    22,    13,   289,   254,    35,
      15,   293,    32,   212,   213,   297,   298,    15,   217,   218,
      15,   220,     6,    35,     6,    35,    15,    35,   310,    35,
      32,    35,    35,   232,     4,    52,    53,    54,    55,    56,
      57,    58,    59,    13,   243,   231,   226,   229,   197,    91,
     307,   240,    22,    23,    24,    25,   278,   286,    28,    29,
      30,    31,    14,   117,   132,   163,   217,    37,    38,   115,
     118,   261,   261,    43,   119,   220,   135,    -1,    48,   278,
      50,    -1,    -1,    -1,    -1,    -1,    -1,   286,     4,    -1,
      60,    61,    62,    63,    64,    65,    -1,    13,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      12,    13,    -1,    -1,    60,    61,    62,    63,    64,    65,
      22,    -1,    68,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    65,    13,    14,    68,    -1,    17,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    60,    61,    62,    63,    64,    65,    22,    -1,    68,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    60,    61,    62,    63,    64,
      65,    22,    -1,    68,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    60,
      61,    62,    63,    64,    65,    22,    67,    68,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    60,    61,    62,    63,    64,    65,    22,
      -1,    68,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    60,    61,    62,
      63,    64,    65,    22,    -1,    68,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    60,    61,    62,    63,    64,    65,    22,    -1,    68,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      65,    -1,    -1,    68,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    13,    14,    17,    18,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    37,    38,    43,    48,
      50,    60,    61,    62,    63,    64,    65,    68,    73,    74,
      75,    83,    84,    85,    86,    87,    88,    90,    91,    92,
      93,    94,    96,    97,   100,   104,   105,   107,   109,   113,
     114,   115,   116,   117,   118,   119,   121,   122,   123,   124,
     125,   126,   128,   129,   130,   131,   133,   134,   136,   137,
     138,    74,   118,   113,    13,   139,    13,    77,    13,   134,
      32,   113,   136,    49,   132,    31,    31,    47,     0,    74,
       4,    34,    33,    67,    98,    99,   113,    70,   108,   121,
       7,    33,    35,    21,    20,    19,    22,    52,    53,    54,
      55,    56,    57,    58,    59,   120,    45,    46,    44,     9,
      37,    38,    10,    39,    40,    41,    42,   127,   128,     8,
      31,    47,    50,   135,    36,    31,    35,    31,    79,    36,
      95,    35,    32,    51,   136,   113,   113,    13,     4,    86,
      89,   113,    54,    35,    35,   106,   113,    35,    19,   113,
      89,    12,   113,    70,    70,    19,    22,   119,   121,   122,
     123,   124,   126,   126,   128,   128,    32,    68,   113,   142,
     143,   144,    13,   132,   113,    32,   144,     4,   140,    13,
      32,    68,    80,    81,    82,    11,    35,    13,    12,    51,
      32,    32,    33,    30,    70,     4,    84,   112,    35,    70,
       3,   110,     7,    33,   116,   118,    32,    36,    33,    32,
      36,   113,    35,    32,     5,    35,    11,    76,    32,    36,
      32,    36,    33,    12,    63,    78,   112,    95,    89,   112,
       5,    70,   112,    31,   113,    89,   142,   113,   143,    51,
      12,    75,   141,    12,    78,    35,    80,    81,   113,    35,
      71,    83,   145,   112,    72,   111,   113,    32,     4,     6,
      75,    76,   112,    32,   112,    15,    16,   101,   102,   103,
     145,     4,     6,    71,    15,    32,    36,     6,    35,    35,
      98,     6,   101,    35,   111,   112,    70,    35,    35,    70,
      32,   112,    70,    70,   112,   112,   112,    71,   101,   103,
      35,    70,   112
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    72,    73,    74,    74,    74,    74,
      75,    75,    75,    75,    76,    77,    78,    78,    79,    79,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    88,    89,    89,    90,    90,    90,    91,    92,
      93,    93,    94,    94,    95,    95,    96,    96,    96,    96,
      96,    97,    97,    97,    97,    98,    99,   100,   101,   102,
     103,   103,   103,   104,   104,   105,   106,   107,   107,   108,
     109,   110,   110,   111,   112,   112,   112,   113,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   118,   118,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   122,   122,   123,   123,   124,
     124,   125,   125,   125,   126,   126,   127,   127,   127,   127,
     127,   128,   128,   129,   129,   129,   130,   130,   131,   131,
     131,   131,   131,   131,   131,   132,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   134,   134,   135,   135,
     135,   135,   136,   136,   137,   137,   137,   137,   138,   139,
     139,   139,   140,   140,   141,   141,   142,   143,   143,   144,
     144,   145,   145
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,     1,     1,     1,     2,     2,
       5,     7,     7,     9,     0,     1,     1,     1,     3,     5,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     3,
       2,     1,     3,     1,     1,     1,     3,     5,     1,     3,
       5,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     2,     3,     1,     1,     1,     1,
       1,     5,    10,     7,     4,     1,     3,     1,     1,     1,
       5,     7,    10,     6,    11,     1,     1,     5,    10,     3,
       1,     4,     6,     1,     1,     4,     5,     1,     1,     4,
       4,     1,     1,     4,     4,     1,     2,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     2,
       5,     3,     4,     4,     3,     0,     3,     2,     4,     3,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       5,     3,     1,     2,     1,     3,     3,     5,     4,     1,
       3,     4,     4,     5,     1,     2,     1,     1,     3,     1,
       3,     1,     2
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
#line 114 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal M");
        (yyval.elem)->ins = instCount+1;
}
#line 1805 "parser.tab.c"
    break;

  case 3:
#line 120 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal N");
        (yyval.elem)->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
#line 1815 "parser.tab.c"
    break;

  case 4:
#line 127 "parser.y"
                  {
        (yyval.elem) = create_node(1, "Marker Non-terminal for_else_N");
        create_ins(1, iterStack.top(), "+", iterStack.top(), "1");
        (yyval.elem)->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
#line 1826 "parser.tab.c"
    break;

  case 5:
#line 135 "parser.y"
              {
                (yyval.elem) = (yyvsp[0].elem);
                endline = instCount+1;
                create_ins(0, "EOF", "", "", "");
            }
#line 1836 "parser.tab.c"
    break;

  case 6:
#line 142 "parser.y"
                 {
       (yyval.elem)=(yyvsp[0].elem);
	   (yyval.elem)->ins = instCount+1;
    }
#line 1845 "parser.tab.c"
    break;

  case 7:
#line 146 "parser.y"
            { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1853 "parser.tab.c"
    break;

  case 8:
#line 149 "parser.y"
                       { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1861 "parser.tab.c"
    break;

  case 9:
#line 152 "parser.y"
                   {  
        (yyval.elem) = create_node(3, "snippet", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
    }
#line 1871 "parser.tab.c"
    break;

  case 10:
#line 159 "parser.y"
                                              {
            (yyval.elem) = create_node(6, "funcdef", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));

            //STE code start
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-3].elem)->addr, (yyvsp[-2].elem)->num_params, (yyvsp[-4].elem)->lineno, 1);
            //STE code end

			// create_ins(0,$5->return_param,"=","PopParam","");
            create_ins(0,"Stackpointer -"+to_string(funcOffset),"","","");
            funcOffset=0;
            create_ins(0,"goto","ra","","");
            create_ins(0, "return", "", "", "");

            create_ins(0,"EndFunc","","","");
            backpatch_str((yyvsp[0].elem)->nextlist, "ra");
            // thisTemps.push(reg1);

            //populate in symbol table
            populate_fun_par_type(current_ste,(yyvsp[-2].elem)->func_par_type);

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[0].elem)->stack_width;
            current_ste->stack_width = (yyval.elem)->stack_width;
            current_ste->offset_map = offset_map;
            stack_offset = 16;
            offset_map.clear();
            //m3 end

        }
#line 1906 "parser.tab.c"
    break;

  case 11:
#line 189 "parser.y"
                                                                        {
            (yyval.elem) = create_node(8, "funcdef", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));

            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-5].elem)->addr, (yyvsp[-4].elem)->num_params, (yyvsp[-6].elem)->lineno, 1,(yyvsp[-2].elem)->addr);
            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Stackpointer -"+to_string(funcOffset),"","","");
            funcOffset=0;
            create_ins(0,"goto","ra","","");
            if(chartostring((yyvsp[-2].elem)->addr) == "None"){
                //cerr<<"return instruction created"<<endl;
                create_ins(0, "return", "", "", "");
            }
            create_ins(0,"EndFunc","","","");

            //populate in symbol table
            populate_fun_par_type(current_ste,(yyvsp[-4].elem)->func_par_type);

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[0].elem)->stack_width;
            current_ste->stack_width = (yyval.elem)->stack_width;
            current_ste->offset_map = offset_map;
            stack_offset = 16;
            offset_map.clear();
            
            //m3 end
        }
#line 1939 "parser.tab.c"
    break;

  case 12:
#line 217 "parser.y"
                                                                 {
            (yyval.elem) = create_node(8, "funcdef", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-5].elem)->addr, 0, (yyvsp[-6].elem)->lineno, 1);

            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Stackpointer -"+to_string(funcOffset),"","","");
            funcOffset=0;
            create_ins(0,"goto","ra","","");
            create_ins(0, "return", "", "", "");

            create_ins(0,"EndFunc","","","");

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[0].elem)->stack_width;
            current_ste->stack_width = (yyval.elem)->stack_width;
            current_ste->offset_map = offset_map;
            stack_offset = 16;
            offset_map.clear();
            //m3 end
        }
#line 1966 "parser.tab.c"
    break;

  case 13:
#line 239 "parser.y"
                                                                                         {
            (yyval.elem) = create_node(10, "funcdef", (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-7].elem)->addr, 0, (yyvsp[-8].elem)->lineno, 1,(yyvsp[-3].elem)->addr);

            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Stackpointer -"+to_string(funcOffset),"","","");
            funcOffset=0;
            create_ins(0,"goto","ra","","");
            if(chartostring((yyvsp[-3].elem)->addr) == "None"){
                create_ins(0, "return", "", "", "");
            }
            create_ins(0,"EndFunc","","","");

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[0].elem)->stack_width;
            current_ste->stack_width = (yyval.elem)->stack_width;
            current_ste->offset_map = offset_map;
            stack_offset = 16;
            offset_map.clear();
            
            //m3 end
        }
#line 1995 "parser.tab.c"
    break;

  case 14:
#line 265 "parser.y"
         {
        stack_offset = 8;
}
#line 2003 "parser.tab.c"
    break;

  case 15:
#line 270 "parser.y"
    {   
        (yyval.elem)=(yyvsp[0].elem);

        if(inClass==0) create_ins(0,chartostring((yyvsp[0].elem)->addr)+":","","","");
        else create_ins(0,className+"."+chartostring((yyvsp[0].elem)->addr)+":","","","");

        create_ins(0,"BeginFunc","","","");
        // paramStack.pop(); //popping return address
        create_ins(0,"PushParam","RBP","","");
        create_ins(0,"ra","=","PopParam","");

        //STE code start
        ste* lookup_ste = current_ste;
        //here I am adding it should not be init
        if(lookup(lookup_ste, (yyvsp[0].elem)->addr) == NULL || chartostring((yyvsp[0].elem)->addr) == "__init__"){
            current_ste = insert_entry_new_scope(current_ste);
            ste* help = current_ste->prev_scope;
            populate_new_scope(help, "FUNCTION", (yyvsp[0].elem)->addr, 0, 0, 1);
        }
        else if(same_lookup(lookup_ste, (yyvsp[0].elem)->addr) == NULL){
            current_ste = insert_entry_new_scope(current_ste);
            ste* help = current_ste->prev_scope;
            populate_new_scope(help, "FUNCTION", (yyvsp[0].elem)->addr, 0, 0, 1);
        }
        else{ //print_ste(global_sym_table, 0);
            cerr<<"Error: Function "<<(yyvsp[0].elem)->addr<<" already declared in same scope at line number " << lookup(lookup_ste, (yyvsp[0].elem)->addr)->lineno << "\n";
            exit(1);
        }
        //STE code end

    }
#line 2039 "parser.tab.c"
    break;

  case 16:
#line 325 "parser.y"
                        {
        (yyval.elem)=(yyvsp[0].elem);
        get_prev_scope(current_ste)->return_type = (yyvsp[0].elem)->addr;
    }
#line 2048 "parser.tab.c"
    break;

  case 17:
#line 329 "parser.y"
          {
        (yyval.elem)=(yyvsp[0].elem);
        get_prev_scope(current_ste)->return_type = "None";
    }
#line 2057 "parser.tab.c"
    break;

  case 18:
#line 335 "parser.y"
                                                     {  
            (yyval.elem) = create_node(4, "parameters", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[-1].elem)->num_params;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;

            get_prev_scope(current_ste)->num_params = (yyval.elem)->num_params;
            get_prev_scope(current_ste)->func_par_type = (yyvsp[-1].elem)->func_par_type;

            //handle vector of par type 
            (yyval.elem)->func_par_type = (yyvsp[-1].elem)->func_par_type;

            //m3 tsart
            //$$->stack_width = $2->stack_width;
            stack_offset=8;
            //m3 end 
        }
#line 2079 "parser.tab.c"
    break;

  case 19:
#line 352 "parser.y"
                                                              {
            (yyval.elem) = create_node(6, "parameters", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[-1].elem)->num_params;
            (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;
            get_prev_scope(current_ste)->num_params = (yyval.elem)->num_params;
            get_prev_scope(current_ste)->func_par_type = (yyvsp[-1].elem)->func_par_type;
            //handle vector of par type 
            (yyval.elem)->func_par_type = (yyvsp[-1].elem)->func_par_type;
            //m3 tsart
            //$$->stack_width = $4->stack_width;
            stack_offset=8;
            //m3 end 
        }
#line 2098 "parser.tab.c"
    break;

  case 20:
#line 366 "parser.y"
                                          {
            (yyval.elem) = create_node(3, "parameters", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
            (yyval.elem)->num_params = 0;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;

            //m3 start
            //check while class
            stack_offset=8;
            //m3 end
        }
#line 2114 "parser.tab.c"
    break;

  case 21:
#line 379 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;
            (yyval.elem)->ins = instCount+1;
            
            // paramStack.pop();
			create_ins(0,(yyvsp[0].elem)->addr,"=","PopParam","");

        }
#line 2128 "parser.tab.c"
    break;

  case 22:
#line 388 "parser.y"
                                         {  
            (yyval.elem) = create_node(4, "typedargslist", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->num_params = (yyvsp[-2].elem)->num_params + 1;
            (yyval.elem)->ins = instCount+1;
            // paramStack.pop();
			create_ins(0,(yyvsp[0].elem)->addr,"=","PopParam","");

            //handle vector of par type 
            (yyval.elem)->func_par_type = (yyvsp[-2].elem)->func_par_type;
            for(int i=0;i < (yyvsp[0].elem)->func_par_type.size(); i++){
                (yyval.elem)->func_par_type.push_back((yyvsp[0].elem)->func_par_type[i]);
            }

        }
#line 2149 "parser.tab.c"
    break;

  case 23:
#line 411 "parser.y"
                   {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2157 "parser.tab.c"
    break;

  case 24:
#line 414 "parser.y"
                            {  
            (yyval.elem) = create_node(4, "typedarg", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");    //is this instruction needed?????

            //typecheck
            //curretnly doing only for LHS, checked for LHS
            if(lookup(current_ste, (yyvsp[-2].elem)->addr) == NULL){
                cerr<<"Error: Undeclared variable "<<(yyvsp[-2].elem)->addr<<" on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                exit(1);
            }
            else{
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,(yyvsp[-1].elem)->addr);
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch in formal argument assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
                }
            }
            //typecheck end

            //handle vector of par type 
            (yyval.elem)->func_par_type = (yyvsp[-2].elem)->func_par_type;

            //m3 start
            //$$->stack_width = $1->stack_width + $3->stack_width;
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;
            //m3 end
        }
#line 2192 "parser.tab.c"
    break;

  case 25:
#line 446 "parser.y"
             {  
            (yyval.elem)=(yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
            
            if(lookup(current_ste, (yyvsp[0].elem)->addr) == NULL){
                cerr<<"Error: Undeclared variable "<<(yyvsp[0].elem)->addr<<" on line "<<(yyvsp[0].elem)->lineno<<"\n";
                exit(1);
            }
            else{
                (yyval.elem)->atom_type = lookup(current_ste, (yyvsp[0].elem)->addr)->type;
            }
        }
#line 2209 "parser.tab.c"
    break;

  case 26:
#line 458 "parser.y"
                               {  
            (yyval.elem) = create_node(4, "tfpdef", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem)); 
			(yyval.elem)->ins = instCount+1;
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;

            //Type check start 
            (yyvsp[-2].elem)->atom_type = (yyvsp[0].elem)->addr; //see type kya hai exactly
            (yyval.elem)->atom_type = (yyvsp[0].elem)->addr; 
            //symbol table entry me type niche daal dia hai
            //Type check end

            //STE code start
            ste* lookup_ste = current_ste;
            //print_ste(lookup_ste, 0);
            if(lookup(lookup_ste, (yyvsp[-2].elem)->addr) == NULL){
                current_ste = insert_entry_same_scope(current_ste, "VARIABLE", (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr, (yyvsp[-2].elem)->lineno, 1);
            }
            else if(same_lookup(lookup_ste, (yyvsp[-2].elem)->addr) == NULL){
                current_ste = insert_entry_same_scope(current_ste, "VARIABLE", (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr, (yyvsp[-2].elem)->lineno, 1);
            }
            
            else{ 
                cerr<<"Error: Variable "<<(yyvsp[-2].elem)->addr<<" already declared on line "<<lookup(lookup_ste, (yyvsp[-2].elem)->addr)->lineno<<"\n";
                exit(1);
            }
            //STE code end 

            //handle vector of par type 
            (yyval.elem)->func_par_type.push_back(chartostring((yyvsp[0].elem)->addr));

            //m3 start 
            //$$->stack_width = 8;
            offset_map[chartostring((yyvsp[-2].elem)->addr)] = stack_offset;
            stack_offset+=8;
            //m3 end
        }
#line 2251 "parser.tab.c"
    break;

  case 27:
#line 497 "parser.y"
                        { 
        	(yyval.elem)=(yyvsp[0].elem);
        }
#line 2259 "parser.tab.c"
    break;

  case 28:
#line 500 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem); 
        }
#line 2267 "parser.tab.c"
    break;

  case 29:
#line 505 "parser.y"
                                                {  
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 2275 "parser.tab.c"
    break;

  case 30:
#line 508 "parser.y"
                                   {  
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 2283 "parser.tab.c"
    break;

  case 31:
#line 513 "parser.y"
                                {   
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2291 "parser.tab.c"
    break;

  case 32:
#line 516 "parser.y"
                                                     {  
            (yyval.elem) = create_node(3, "small_stmt_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, (yyvsp[0].elem)->nextlist);
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;

            //M3 start
            (yyval.elem)->stack_width = (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //M3 end
        }
#line 2306 "parser.tab.c"
    break;

  case 33:
#line 528 "parser.y"
                            {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 2314 "parser.tab.c"
    break;

  case 34:
#line 531 "parser.y"
                        {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 2322 "parser.tab.c"
    break;

  case 35:
#line 534 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2330 "parser.tab.c"
    break;

  case 36:
#line 539 "parser.y"
                                     { 
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
             
            string oper="";
            int i=0;
            while((yyvsp[-1].elem)->addr[i]!='='){
                oper.push_back((yyvsp[-1].elem)->addr[i]);
                i++;
            }

            //typecheck
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,(yyvsp[-1].elem)->addr);
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch in assignment on line number "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
                }
                string temp = newTemp();
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    create_ins(1, temp, oper,chartostring((yyvsp[-2].elem)->addr) ,"("+ret_type+")"+chartostring((yyvsp[0].elem)->addr));
                    create_ins(0, (yyvsp[-2].elem)->addr, "=", temp, "");
                }
                else if(ret_type != (yyvsp[-2].elem)->atom_type){
                    create_ins(1, temp, oper, "("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr),chartostring((yyvsp[0].elem)->addr));
                    create_ins(0, (yyvsp[-2].elem)->addr, "=", temp, "");
                }
                else{
                    create_ins(1, temp, oper, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
                    create_ins(0, (yyvsp[-2].elem)->addr, "=", temp, "");
                }
            //typecheck done

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[temp] = -stack_offset;
            stack_offset+=8;
            //m3end
        }
#line 2374 "parser.tab.c"
    break;

  case 37:
#line 578 "parser.y"
                                                    { // Is this rule really required?  x:int += 5
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;
            

            //runtime support start
            funcOffset += get_width((yyvsp[-2].elem)->addr);
            create_ins(0, "Stackpointer +"+to_string(get_width((yyvsp[-2].elem)->addr)), "", "", "");
            //runetime support end

            //STE code start
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[-4].elem)->addr) == NULL){
                current_ste = insert_entry_same_scope(current_ste, "VARIABLE", (yyvsp[-4].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[-4].elem)->lineno, 1);
            }
            else{
                cerr<<"Error: Variable "<<(yyvsp[-4].elem)->addr<<" already declared on line "<<lookup(lookup_ste, (yyvsp[-4].elem)->addr)->lineno<<"\n";
                exit(1);
            }
            //STE code end

            //Type checking
            (yyvsp[-4].elem)->atom_type = (yyvsp[-2].elem)->addr;
            string oper="";
            int i=0;
            while((yyvsp[-1].elem)->addr[i]!='='){
                oper.push_back((yyvsp[-1].elem)->addr[i]);
                i++;
            }
            //Type checking end
            //typecheck
                string ret_type=typecast((yyvsp[-4].elem)->atom_type,(yyvsp[0].elem)->atom_type,(yyvsp[-1].elem)->addr);
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-4].elem)->lineno<<"\n";
                    exit(1);
                }
                string temp = newTemp();
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    create_ins(1, temp, oper, chartostring((yyvsp[-4].elem)->addr),"("+ret_type+")"+chartostring((yyvsp[0].elem)->addr));
                    create_ins(0, (yyvsp[-4].elem)->addr, "=", temp, "");
                }
                else if(ret_type != (yyvsp[-4].elem)->atom_type){
                    create_ins(1, temp, oper, "("+ret_type+")"+chartostring((yyvsp[-4].elem)->addr),chartostring((yyvsp[0].elem)->addr));
                    create_ins(0, (yyvsp[-4].elem)->addr, "=", temp, "");
                }
                else{
                    create_ins(1, temp, oper, (yyvsp[-4].elem)->addr, (yyvsp[0].elem)->addr);
                    create_ins(0, (yyvsp[-4].elem)->addr, "=", temp, "");
                }
            //typecheck done

            //M3 START
            (yyval.elem)->stack_width = 8 + 8 + (yyvsp[-4].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[chartostring((yyvsp[-4].elem)->addr)] = -stack_offset;
            stack_offset+=8;
            offset_map[temp] = -stack_offset;
            stack_offset+=8;
            //M3 END

        }
#line 2440 "parser.tab.c"
    break;

  case 38:
#line 661 "parser.y"
                   {
			(yyval.elem)=(yyvsp[0].elem);
        }
#line 2448 "parser.tab.c"
    break;

  case 39:
#line 664 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
			// create_ins(0, $1->addr, $2->addr, $3->addr, ""); 

            if(chartostring((yyvsp[-2].elem)->type) == "self_call"){
                //cout<<"test eq testlistex: "<<$1->atom_type<<" "<<$3->atom_type<<endl;
                ste* lookup_ste = lookup(current_ste, (yyvsp[-2].elem)->class_param);

                if(lookup_ste == NULL){
                    cerr<<"Error: Variable "<<(yyvsp[-2].elem)->class_param<<" not declared on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
                }
                else{
                    //cout<<"lookup_ste->type: "<<lookup_ste->type<<" $3->atom_type: "<<$3->atom_type<<endl;
                    if(lookup_ste->type != (yyvsp[0].elem)->atom_type){
                        cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                        exit(1);
                    }
                    else{
                        create_ins(0, (yyvsp[-2].elem)->addr, "=", (yyvsp[0].elem)->addr, "");
                    }
                }
            }
            else if(chartostring((yyvsp[-2].elem)->type)=="object_call"){
                if((yyvsp[-2].elem)->atom_type != (yyvsp[0].elem)->atom_type){
                    cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                }
                else{
                    create_ins(0, (yyvsp[-2].elem)->addr, "=", (yyvsp[0].elem)->addr, "");  
                }
            }
            
            else{
            //typecheck
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"=");
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    create_ins(0, (yyvsp[-2].elem)->addr, "=", "("+ret_type+")"+chartostring((yyvsp[0].elem)->addr),"");
                }
                else{
                    create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
                }
            }
            //typecheck done

            //M3 START
            (yyval.elem)->stack_width = (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 2507 "parser.tab.c"
    break;

  case 40:
#line 719 "parser.y"
                                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem));
			(yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;
            //runtime support
            funcOffset += get_width((yyvsp[-2].elem)->addr);
            string st=str_to_ch((yyvsp[-2].elem)-> addr);

            string check = chartostring((yyvsp[0].elem)->addr);

            if(st=="str" && check.find("\"") != string::npos){  //x:str = "hello"
                // string_map_mohak[chartostring($1->addr)] = $5->str_len;
                create_ins(0, "Heapalloc",to_string(chartostring((yyvsp[0].elem)->addr).size()-2), "", "");
            }
            // else if(st=="str"){ //y:str = x
            //     string_map_mohak[chartostring($1->addr)] = string_map_mohak[chartostring($5->addr)];
            //     create_ins(0, "Heapalloc",to_string(string_map_mohak[chartostring($5->addr)]), "", "");
            //     if($5->atom_type == "str"){
            //         $5->addr = str_to_ch(chartostring($5->addr)+":str");
            //     }
            // }

            if(st == "int" || st == "float" || st == "bool" || st == "str") {
                create_ins(0, "Stackpointer +"+to_string(get_width((yyvsp[-2].elem)->addr)), "", "", "");
            }
            // cout<<"yes "<<$3->addr<<endl;

			//create_ins(0, $1->addr, $4->addr, $5->addr, ""); 
            (yyvsp[-4].elem)->atom_type = (yyvsp[-2].elem)->addr;
            if(chartostring((yyvsp[-4].elem)->type) == "self_call"){
                ste* prev_ste = get_prev_scope(current_ste);
                ste* prev_prev_ste = prev_ste->prev;
                prev_prev_ste = insert_entry_same_scope(prev_prev_ste, "VARIABLE", (yyvsp[-4].elem)->class_param,(yyvsp[-2].elem)->addr, (yyvsp[-4].elem)->lineno,1);
                prev_prev_ste->next = prev_ste;
                prev_ste->prev = prev_prev_ste;
            }

            //STE code start
            else{
                ste* lookup_ste = current_ste;
                if(lookup(lookup_ste, (yyvsp[-4].elem)->addr) == NULL){
                    current_ste = insert_entry_same_scope(current_ste, "VARIABLE", (yyvsp[-4].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[-4].elem)->lineno, 1, (yyvsp[0].elem)->list_size);
                }
                else{
                    cerr<<"Error: Variable "<<(yyvsp[-4].elem)->addr<<" already declared on line "<<lookup(lookup_ste, (yyvsp[-4].elem)->addr)->lineno<<"\n";
                    exit(1);
                }
            }
            //STE code end

            //typecheck
                string ret_type=typecast((yyvsp[-4].elem)->atom_type,(yyvsp[0].elem)->atom_type,"=");
                
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-4].elem)->lineno<<"\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    create_ins(0, (yyvsp[-4].elem)->addr, "=", "("+ret_type+")"+chartostring((yyvsp[0].elem)->addr),"");
                    // else create_ins(0, chartostring($1->addr)+":str", "=", "("+ret_type+")"+chartostring($5->addr),"");
                }
                else{
                    create_ins(0, (yyvsp[-4].elem)->addr, "=", (yyvsp[0].elem)->addr, "");
                    // else create_ins(0, chartostring($1->addr)+":str", "=", $5->addr, "");
                }
            //typecheck done

            //M3 START
            
            // for __init__ function and when it is self, it should not add so see that 
            //but there may be possibility of t0 setting up here, think!!
            if(chartostring((yyvsp[-4].elem)->type) == "self_call"){
                // I need class and I think it should run always , not sure
                if(curr_class!=""){
                    ste* pre_class = class_map[curr_class];
                    pre_class->class_offset_map[(yyvsp[-4].elem)->class_param]=class_offset;
                    class_offset += 8;
                }
            }
            else{
                (yyval.elem)->stack_width = 8 + (yyvsp[-4].elem)->stack_width + (yyvsp[0].elem)->stack_width;
                offset_map[chartostring((yyvsp[-4].elem)->addr)] = -stack_offset;
                stack_offset+=8;
            }
            

            //M3 END
        }
#line 2600 "parser.tab.c"
    break;

  case 41:
#line 845 "parser.y"
                                                  {
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
			// create_ins(0, $1->obj_name, $2->addr, $3->addr, ""); 

            //runtime support
            // create_ins(0, "Stackpointer +xxx", "", "", "");
            // create_ins(0,"call memalloc 1","","","");
            // create_ins(0,"Stackpointer -yyy","","","");



            // $1->atom_type = str_to_ch($1->class_name);
            
            if(chartostring((yyvsp[-2].elem)->type) == "self_call"){
                ste* prev_ste = get_prev_scope(current_ste);
                ste* prev_prev_ste = prev_ste->prev;
                prev_prev_ste = insert_entry_same_scope(prev_prev_ste, "VARIABLE", (yyvsp[-2].elem)->class_param,(yyvsp[-2].elem)->class_name, (yyvsp[-2].elem)->lineno,1);
                prev_prev_ste->next = prev_ste;
                prev_ste->prev = prev_prev_ste;
            }

            //STE code start
            else{
                ste* lookup_ste = current_ste;
                if(lookup(lookup_ste, (yyvsp[-2].elem)->obj_name) == NULL){
                    current_ste = insert_entry_same_scope(current_ste, "OBJECT", (yyvsp[-2].elem)->obj_name, (yyvsp[-2].elem)->class_name, (yyvsp[-2].elem)->lineno, 1, (yyvsp[0].elem)->list_size);
                }
                else{
                    cerr<<"Error: Variable "<<(yyvsp[-2].elem)->obj_name<<" already declared on line "<<lookup(lookup_ste, (yyvsp[-2].elem)->obj_name)->lineno<<"\n";
                    exit(1);
                }
            }
            //m3 start pending
                // do we have do handle like self.a : LALRPARSER = LALRPARSER('abc',...);
                (yyval.elem)->stack_width = (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end

        }
#line 2645 "parser.tab.c"
    break;

  case 42:
#line 888 "parser.y"
                         {
    (yyval.elem)= create_node(4,"Obj_eq",(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));
    (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
    (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;

    if(chartostring((yyvsp[-2].elem)->type) == "self_call"){
        (yyval.elem)->class_param = (yyvsp[-2].elem)->class_param;
    }
    cerr<<(yyvsp[-2].elem)->addr<<endl;
    (yyval.elem)->obj_name = (yyvsp[-2].elem)->addr;
    // cerr<<"out"<<endl;
    (yyval.elem)->class_name = (yyvsp[0].elem)->addr;
    (yyval.elem)->type = (yyvsp[-2].elem)->type;

    if(class_map.find(chartostring((yyvsp[0].elem)->addr))!=class_map.end()){
        (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
        offset_map[chartostring((yyvsp[-2].elem)->addr)] = -stack_offset;
        stack_offset+=8;

        //create instructions 
        create_ins(0,"create_obj",to_string(class_map[chartostring((yyvsp[0].elem)->addr)]->class_width),(yyvsp[-2].elem)->addr,"");
        obj_class[chartostring((yyvsp[-2].elem)->addr)] = chartostring((yyvsp[0].elem)->addr);
    }
    else{
        cerr<<"Error: Class "<<(yyvsp[0].elem)->addr<<" not defined on line "<<(yyvsp[-2].elem)->lineno<<"\n";
        exit(1);
    }


}
#line 2680 "parser.tab.c"
    break;

  case 43:
#line 921 "parser.y"
                                 {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2688 "parser.tab.c"
    break;

  case 44:
#line 924 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            //create_ins(0, $1->addr, $2->addr, $3->addr, "");
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;    //x=y=z
            //typecheking start
                (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"=");
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    create_ins(0, (yyvsp[-2].elem)->addr, "=", "("+ret_type+")"+chartostring((yyvsp[0].elem)->addr),"");
                }
                else{
                    create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
                }
            //typecheck done

            //M3 START
            (yyval.elem)->stack_width = (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //M3 END
        }
#line 2719 "parser.tab.c"
    break;

  case 45:
#line 952 "parser.y"
                        {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2727 "parser.tab.c"
    break;

  case 46:
#line 955 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2735 "parser.tab.c"
    break;

  case 47:
#line 958 "parser.y"
                         {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2743 "parser.tab.c"
    break;

  case 48:
#line 963 "parser.y"
                    {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = instCount+1; 
            //cout<<$$->ins;
            create_ins(0, "goto", "", "", "");
            (yyval.elem)->nextlist = makelist((yyval.elem)->ins);
            // int temp = loopStack.top();
            // loopStack.pop();
            // if(loopStack.size()!=0)create_ins(0, "goto", to_string(loopStack.top()), "", "");
            // loopStack.push(temp);
        }
#line 2759 "parser.tab.c"
    break;

  case 49:
#line 975 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = instCount+1;
            create_ins(1, iterStack.top(), "+", iterStack.top(), "1");
            create_ins(0, "goto", to_string(loopStack.top()), "", "");
        }
#line 2770 "parser.tab.c"
    break;

  case 50:
#line 982 "parser.y"
                        {  
            (yyval.elem)=(yyvsp[0].elem);
            //create_ins(0,"return","","","");

        }
#line 2780 "parser.tab.c"
    break;

  case 51:
#line 987 "parser.y"
                          {  
            (yyval.elem) = (yyvsp[0].elem); //ye saih hai?
            (yyval.elem)->ins = (yyvsp[0].elem)->ins; //ye bhi??
            
            // m3 commented 3 lines
            // $$->return_param = str_to_ch(newTemp());
            // create_ins(0,$$->return_param,"=",$2->addr,"");
            // create_ins(0,"return",$$->return_param,"","");
            create_ins(0,"return",(yyvsp[0].elem)->addr,"","");
            //m3 end
        }
#line 2796 "parser.tab.c"
    break;

  case 52:
#line 1000 "parser.y"
                           {  
            (yyval.elem) = create_node(3, "global_stmt", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
                       
        }
#line 2807 "parser.tab.c"
    break;

  case 53:
#line 1006 "parser.y"
                                      {   
            (yyval.elem) = create_node(4, "global_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
        }
#line 2817 "parser.tab.c"
    break;

  case 54:
#line 1013 "parser.y"
                               {  
            (yyval.elem) = create_node(3, "comma_name_star", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
        }
#line 2827 "parser.tab.c"
    break;

  case 55:
#line 1018 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "comma_name_star", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
        }
#line 2837 "parser.tab.c"
    break;

  case 56:
#line 1024 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);  
        }
#line 2845 "parser.tab.c"
    break;

  case 57:
#line 1027 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
            iterStack.pop();
            loopStack.pop();
        }
#line 2855 "parser.tab.c"
    break;

  case 58:
#line 1032 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
            iterStack.pop();
            loopStack.pop();
        }
#line 2865 "parser.tab.c"
    break;

  case 59:
#line 1037 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2873 "parser.tab.c"
    break;

  case 60:
#line 1040 "parser.y"
                       {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 2881 "parser.tab.c"
    break;

  case 61:
#line 1045 "parser.y"
                                            {  
           (yyval.elem)=create_node(6, "if_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
           (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
           backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
           (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;

           //changed here
           //$$->nextlist = merge($2->falselist, $5->nextlist);
              (yyval.elem)->nextlist = (yyvsp[0].elem)->nextlist;
              backpatch((yyvsp[-3].elem)->falselist, instCount+1);
            //change end
            //STE code start
            // current_ste = get_prev_scope(current_ste);  
            //STE code end

            //M3 start
            (yyval.elem)->stack_width = (yyvsp[-3].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //M3 end

        }
#line 2906 "parser.tab.c"
    break;

  case 62:
#line 1065 "parser.y"
                                                                      {  
            (yyval.elem) = create_node(11, "if_else_stmt", (yyvsp[-9].elem),(yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-9].elem)->lineno;
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            vector<int> temp = merge((yyvsp[-5].elem)->nextlist, (yyvsp[-4].elem)->nextlist);
            //$$->nextlist = merge(temp, $10->nextlist);
            (yyval.elem)->nextlist = (yyvsp[0].elem)->nextlist;
            backpatch(temp,instCount+1);

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end

            //M3 start
            (yyval.elem)->stack_width = (yyvsp[-8].elem)->stack_width + (yyvsp[-5].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //M3 end

        }
#line 2930 "parser.tab.c"
    break;

  case 63:
#line 1084 "parser.y"
                                                       {  
            (yyval.elem) = create_node(8, "if_elif_stmt", (yyvsp[-6].elem),(yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            (yyval.elem)->lineno = (yyvsp[-6].elem)->lineno;
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);     
            vector<int> temp = merge((yyvsp[-2].elem)->nextlist, (yyvsp[-1].elem)->nextlist);
            //$$->nextlist = merge(temp, $7->nextlist); 
            (yyval.elem)->nextlist= (yyvsp[0].elem)->nextlist;
            backpatch(temp,instCount+1);

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-5].elem)->stack_width + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width; 
              
            //m3 end
        }
#line 2950 "parser.tab.c"
    break;

  case 64:
#line 1099 "parser.y"
                                      {
            (yyval.elem) = create_node(5, "if_stmt", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 2963 "parser.tab.c"
    break;

  case 65:
#line 1109 "parser.y"
             {
        (yyval.elem) = (yyvsp[0].elem);
        incheck=0;
}
#line 2972 "parser.tab.c"
    break;

  case 66:
#line 1114 "parser.y"
                                   {
            incheck=0;
            string dunder = chartostring((yyvsp[0].elem)->addr);
            if(dunder != "\"__main__\""){
                cerr<<"Error: Dunder name should be __main__\n";
                exit(1);
            }
            else{
                (yyval.elem)->ins = instCount;
            }
        }
#line 2988 "parser.tab.c"
    break;

  case 67:
#line 1126 "parser.y"
            {
        (yyval.elem)=(yyvsp[0].elem);
        incheck=1;
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "IF", "IF", 0, $1->lineno, 0);
    }
#line 2999 "parser.tab.c"
    break;

  case 68:
#line 1134 "parser.y"
                {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        // current_ste = get_prev_scope(current_ste);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "ELSE", "ELSE", 0, $1->lineno, 1);

        //STE code end
    }
#line 3013 "parser.tab.c"
    break;

  case 69:
#line 1145 "parser.y"
                   {
        (yyval.elem)=(yyvsp[0].elem);
        incheck=1;
        //STE code start
        // current_ste = get_prev_scope(current_ste);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "ELSE_IF", "ELSE_IF", 0, $1->lineno, 1);
        //STE code end
    }
#line 3027 "parser.tab.c"
    break;

  case 70:
#line 1157 "parser.y"
                                                {  
            (yyval.elem)=create_node(6, "elif_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            //$$->nextlist = merge($2->falselist, $5->nextlist);
            backpatch((yyvsp[-3].elem)->falselist,instCount+1);
            (yyval.elem)->nextlist = (yyvsp[0].elem)->nextlist;

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end

            //M3 start
            (yyval.elem)->stack_width = (yyvsp[-3].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //M3 end
        }
#line 3049 "parser.tab.c"
    break;

  case 71:
#line 1174 "parser.y"
                                                          {  
            (yyval.elem) = create_node(8, "elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-5].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-6].elem)->lineno;
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);
            //$$->nextlist = merge($5->nextlist, merge($6->nextlist, $7->nextlist));
            backpatch(merge((yyvsp[-1].elem)->nextlist, (yyvsp[-2].elem)->nextlist),instCount+1);
            (yyval.elem)->nextlist = (yyvsp[0].elem)->nextlist;

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-5].elem)->stack_width + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;

            //m3 end
        }
#line 3069 "parser.tab.c"
    break;

  case 72:
#line 1189 "parser.y"
                                                                          {  
            (yyval.elem) = create_node(11, "elif_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-8].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-9].elem)->lineno;
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            //$$->nextlist = merge($5->nextlist, merge($6->nextlist,$10->nextlist));
            backpatch(merge((yyvsp[-4].elem)->nextlist,(yyvsp[-5].elem)->nextlist),instCount+1);
            (yyval.elem)->nextlist = (yyvsp[0].elem)->nextlist;

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-8].elem)->stack_width + (yyvsp[-5].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 3092 "parser.tab.c"
    break;

  case 73:
#line 1209 "parser.y"
                                                     {  
            (yyval.elem) = create_node(7, "while_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-5].elem)->lineno;
            //$$->nextlist = $3->falselist;
            create_ins(0, "goto", to_string((yyvsp[-4].elem)->ins), "", "");
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            backpatch((yyvsp[0].elem)->nextlist, instCount+1);
            backpatch((yyvsp[-3].elem)->falselist, instCount+1);
            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end

            //M3 start
            (yyval.elem)->stack_width =(yyvsp[-3].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //M3 end
        }
#line 3114 "parser.tab.c"
    break;

  case 74:
#line 1226 "parser.y"
                                                                                     {   
			(yyval.elem) = create_node(12, "while_else_stmt", (yyvsp[-10].elem), (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-9].elem)->ins;
            // create_ins(0,$$->return_param,"=",$2->addr,"");
            // create_ins(0,"return",$$->return_param,"","");
            (yyval.elem)->lineno = (yyvsp[-10].elem)->lineno;
			backpatch((yyvsp[-4].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-5].elem)->nextlist, (yyvsp[-1].elem)->ins);
			backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
			backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
			(yyval.elem)->nextlist = (yyvsp[0].elem)->nextlist; //verify //verified 

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end

            //m3 start
            (yyval.elem)->stack_width =(yyvsp[-8].elem)->stack_width+ (yyvsp[-5].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 3139 "parser.tab.c"
    break;

  case 75:
#line 1248 "parser.y"
                   {
        (yyval.elem)=(yyvsp[0].elem);
        incheck=1;
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "WHILE", "WHILE", 0, $1->lineno, 0);
    }
#line 3150 "parser.tab.c"
    break;

  case 76:
#line 1256 "parser.y"
                   { 
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            iterStack.push((yyval.elem)->addr);
            loopStack.push((yyval.elem)->ins);
            incheck=0;
            // cout<<"out of while_test"<<endl;
        }
#line 3163 "parser.tab.c"
    break;

  case 77:
#line 1265 "parser.y"
                                              { 
            (yyval.elem) = create_node(6, "for_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;

            //print
            // cout<<instCount<<endl;
            //print end

            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            //removed now
            //$$->nextlist = $2->falselist;   //check this filling //checked

            // create_ins(1, $2->for_it, "+", $2->for_it, "1");
            // backpatch($5->nextlist, instCount); //suite nextlist will be patched to update statement of for loop
            create_ins(1, (yyvsp[-3].elem)->addr, "+", (yyvsp[-3].elem)->addr, "1");
            create_ins(0, "goto", to_string((yyvsp[-3].elem)->ins), "", "");
                //commented one is old
                    //backpatch($5->nextlist, $2->ins); //suite nextlist will be patched to update statement of for loop
                    backpatch((yyvsp[0].elem)->nextlist, instCount+1); 
                //end
            backpatch((yyvsp[-3].elem)->falselist, instCount+1); //ye add karke do entry ho gayi
            
            
            //backpatch($5->nextlist, instCount+1); 

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end   


            //M3 start
            (yyval.elem)->stack_width = (yyvsp[-3].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 3203 "parser.tab.c"
    break;

  case 78:
#line 1300 "parser.y"
                                                                           { 
            (yyval.elem) = create_node(11, "for_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-9].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-9].elem)->lineno;

            (yyvsp[0].elem)->nextlist = merge((yyvsp[0].elem)->nextlist, makelist(instCount+1));
            create_ins(0, "goto", "", "", "");
            
            // create_ins(1, $2->for_it, "+", $2->for_it, "1");
            backpatch((yyvsp[-4].elem)->nextlist, instCount+1); 
            backpatch((yyvsp[-5].elem)->nextlist, instCount+1);
            // backpatch($6->nextlist, $2->ins); 
            // backpatch($5->nextlist, $2->ins);
            create_ins(0, "goto", to_string((yyvsp[-8].elem)->ins), "", "");

            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);

            (yyval.elem)->nextlist = (yyvsp[0].elem)->nextlist; //verify

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-8].elem)->stack_width + (yyvsp[-5].elem)->stack_width + (yyvsp[0].elem)->stack_width;

            //m3 end
        }
#line 3237 "parser.tab.c"
    break;

  case 79:
#line 1331 "parser.y"
                               { 
            
            (yyval.elem) = create_node(3, "for_core", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));

            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            create_ins(0, (yyvsp[-2].elem)->addr, "=", to_string(chartonum((yyvsp[0].elem)->for_start)), "");
            // create_ins(0, $1->addr, "=", to_string(chartonum($3->for_start)-1), "");

            // create_ins(1, $1->addr, "+", $1->addr, "1");
            string temp = newTemp();
            create_ins(1, temp, "<", (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->for_end);
            iterStack.push((yyvsp[-2].elem)->addr);
            loopStack.push(instCount);
            (yyval.elem)->ins = instCount;
            (yyval.elem)->truelist = makelist(instCount+1);
            (yyval.elem)->falselist = makelist(instCount+2);
            create_ins(0, "if", temp, "goto", "");
            create_ins(0, "goto", "", "", "");

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[temp]=-stack_offset;
            stack_offset += 8;
            
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;
            //m3 end
        }
#line 3269 "parser.tab.c"
    break;

  case 80:
#line 1360 "parser.y"
               {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        //loopStack.push($$->ins);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "FOR", "FOR", 0, $1->lineno, 0);
        //STE code end
    }
#line 3282 "parser.tab.c"
    break;

  case 81:
#line 1370 "parser.y"
                                                      {
            (yyval.elem) = create_node(5, "range_stmt", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-3].elem)->lineno;
            (yyval.elem)->for_end = (yyvsp[-1].elem)->addr;
            (yyval.elem)->for_start = strdup("0");

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-1].elem)->stack_width;
            //m3 end
        }
#line 3298 "parser.tab.c"
    break;

  case 82:
#line 1381 "parser.y"
                                                                   {
            (yyval.elem) = create_node(7, "range_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-5].elem)->lineno;
            (yyval.elem)->for_end = (yyvsp[-1].elem)->addr;
            (yyval.elem)->for_start = (yyvsp[-3].elem)->addr;
            
            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-3].elem)->stack_width + (yyvsp[-1].elem)->stack_width;
            //m3 end
        }
#line 3314 "parser.tab.c"
    break;

  case 83:
#line 1394 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            //loopStack.push($$->ins);
        }
#line 3324 "parser.tab.c"
    break;

  case 84:
#line 1401 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3332 "parser.tab.c"
    break;

  case 85:
#line 1404 "parser.y"
                                            {
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 3340 "parser.tab.c"
    break;

  case 86:
#line 1407 "parser.y"
                                                    { 
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 3348 "parser.tab.c"
    break;

  case 87:
#line 1413 "parser.y"
                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3356 "parser.tab.c"
    break;

  case 88:
#line 1418 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3364 "parser.tab.c"
    break;

  case 89:
#line 1421 "parser.y"
                                         {  
            (yyval.elem) = create_node(5, "or_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-3].elem)->lineno;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-3].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 3381 "parser.tab.c"
    break;

  case 90:
#line 1434 "parser.y"
                                            {
            (yyval.elem) = create_node(5, "and_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-3].elem)->lineno;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-3].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 3398 "parser.tab.c"
    break;

  case 91:
#line 1446 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3406 "parser.tab.c"
    break;

  case 92:
#line 1451 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3414 "parser.tab.c"
    break;

  case 93:
#line 1454 "parser.y"
                                          {  
            (yyval.elem) = create_node(5, "and_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-3].elem)->lineno;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-3].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 3431 "parser.tab.c"
    break;

  case 94:
#line 1467 "parser.y"
                                              { 
            (yyval.elem) = create_node(5, "not_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-3].elem)->lineno;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-3].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 3448 "parser.tab.c"
    break;

  case 95:
#line 1479 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3456 "parser.tab.c"
    break;

  case 96:
#line 1484 "parser.y"
                         { 
            (yyval.elem) = create_node(3, "not_test", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
            (yyval.elem)->truelist = (yyvsp[0].elem)->falselist;
            (yyval.elem)->falselist = (yyvsp[0].elem)->truelist;

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 3472 "parser.tab.c"
    break;

  case 97:
#line 1495 "parser.y"
                        { 
            (yyval.elem)=(yyvsp[0].elem);

            // cout<< "in comp "<<$$->addr<<endl;
            // cout<<"isatom = "<<isatom<<" "<<incheck<<" "<<yytext<<endl;
            if(isatom && incheck && !isinsquare){
                (yyval.elem)->truelist = makelist(instCount+1);
                (yyval.elem)->falselist = makelist(instCount+2);
                create_ins(0, "if", (yyval.elem)->addr, "goto", "");
                // cout<<"checking "<<$$->addr<<endl;
                create_ins(0, "goto", "", "", "");
            }
        }
#line 3490 "parser.tab.c"
    break;

  case 98:
#line 1508 "parser.y"
              {
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->truelist = makelist(instCount+1);
            create_ins(0, "goto", "", "", "");
        }
#line 3500 "parser.tab.c"
    break;

  case 99:
#line 1513 "parser.y"
               {
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->falselist = makelist(instCount+2);
            create_ins(0, "goto", "", "", "");
        }
#line 3510 "parser.tab.c"
    break;

  case 100:
#line 1520 "parser.y"
                  {
            (yyval.elem)=(yyvsp[0].elem);
            
        }
#line 3519 "parser.tab.c"
    break;

  case 101:
#line 1524 "parser.y"
                                   { 
            (yyval.elem)=create_node(4, "comparison", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            if(incheck) isatom=0;
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->addr = str_to_ch(newTemp());
            // cout<<"checking2 "<<$$->addr<<endl;
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            (yyval.elem)->truelist = makelist(instCount+1);
            (yyval.elem)->falselist = makelist(instCount+2);
            (yyval.elem)->atom_type = "bool";
            //typechecking error
               if(((yyvsp[-2].elem)->atom_type == "str" && (yyvsp[0].elem)->atom_type != "str") || ((yyvsp[-2].elem)->atom_type != "str" && (yyvsp[0].elem)->atom_type == "str")){
                    cerr<<"Error: Type mismatch in comparison on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
               }
            //typechecking error end
            if(incheck){
                create_ins(0, "if", (yyval.elem)->addr, "goto", "");
                create_ins(0, "goto", "", "", "");
            }

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[chartostring((yyval.elem)->addr)]=-stack_offset;
            stack_offset += 8;
            //m3 end
        }
#line 3552 "parser.tab.c"
    break;

  case 102:
#line 1555 "parser.y"
                    {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3560 "parser.tab.c"
    break;

  case 103:
#line 1558 "parser.y"
                    { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 3568 "parser.tab.c"
    break;

  case 104:
#line 1561 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3576 "parser.tab.c"
    break;

  case 105:
#line 1564 "parser.y"
                            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3584 "parser.tab.c"
    break;

  case 106:
#line 1567 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3592 "parser.tab.c"
    break;

  case 107:
#line 1570 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3600 "parser.tab.c"
    break;

  case 108:
#line 1573 "parser.y"
                   {
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 3608 "parser.tab.c"
    break;

  case 109:
#line 1576 "parser.y"
            {  
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3616 "parser.tab.c"
    break;

  case 110:
#line 1579 "parser.y"
                { 
        (yyval.elem) = create_node(3, "NOT IN", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
    }
#line 3625 "parser.tab.c"
    break;

  case 111:
#line 1583 "parser.y"
            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3633 "parser.tab.c"
    break;

  case 112:
#line 1586 "parser.y"
                { 
        (yyval.elem) = create_node(3, "IS NOT", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
    }
#line 3642 "parser.tab.c"
    break;

  case 113:
#line 1592 "parser.y"
                  { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3650 "parser.tab.c"
    break;

  case 114:
#line 1595 "parser.y"
                                  {  
            (yyval.elem) = create_node(4, "expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            //$$->addr = str_to_ch(newTemp());
            //create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);

            //type_checking
            //Type_checking
            string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"|");
            if(ret_type == "Error"){
                cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                exit(1);
            }
            (yyval.elem)->addr = str_to_ch(newTemp());
            if(ret_type != (yyvsp[0].elem)->atom_type){
                create_ins(1, (yyval.elem)->addr, "|", str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)),(yyvsp[-2].elem)->addr);
                (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
            }
            else if(ret_type != (yyvsp[-2].elem)->atom_type){
                create_ins(1, (yyval.elem)->addr, "|", str_to_ch("("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr)),(yyvsp[0].elem)->addr);
                (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
            }
            else{
                create_ins(1, (yyval.elem)->addr, "|", (yyvsp[0].elem)->addr,(yyvsp[-2].elem)->addr);
                (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
            }
            //typecheck end

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[chartostring((yyval.elem)->addr)]=-stack_offset;
            stack_offset += 8;
            //m3 end
        }
#line 3690 "parser.tab.c"
    break;

  case 115:
#line 1632 "parser.y"
                   { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3698 "parser.tab.c"
    break;

  case 116:
#line 1635 "parser.y"
                                       {  
            (yyval.elem) = create_node(4, "xor_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            //$$->addr = str_to_ch(newTemp());
            //create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);

            //type_checking
            //Type_checking
            string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"^");
            if(ret_type == "Error"){
                cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                exit(1);
            }
            (yyval.elem)->addr = str_to_ch(newTemp());
            if(ret_type != (yyvsp[0].elem)->atom_type){
                create_ins(1, (yyval.elem)->addr, "^", str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)),(yyvsp[-2].elem)->addr);
                (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
            }
            else if(ret_type != (yyvsp[-2].elem)->atom_type){
                create_ins(1, (yyval.elem)->addr, "^", str_to_ch("("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr)),(yyvsp[0].elem)->addr);
                (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
            }
            else{
                create_ins(1, (yyval.elem)->addr, "^", (yyvsp[0].elem)->addr,(yyvsp[-2].elem)->addr);
                (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
            }
            //typecheck end

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[chartostring((yyval.elem)->addr)]=-stack_offset;
            stack_offset += 8;
            //m3 end
        }
#line 3738 "parser.tab.c"
    break;

  case 117:
#line 1672 "parser.y"
                       { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 3747 "parser.tab.c"
    break;

  case 118:
#line 1676 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "and_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            //$$->addr = str_to_ch(newTemp());
            //create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);
            
            //type_checking
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"&");
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
                }
                (yyval.elem)->addr = str_to_ch(newTemp());
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    create_ins(1, (yyval.elem)->addr, "&", str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)),(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
                else if(ret_type != (yyvsp[-2].elem)->atom_type){
                    create_ins(1, (yyval.elem)->addr, "&", str_to_ch("("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr)),(yyvsp[0].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
                }
                else{
                    create_ins(1, (yyval.elem)->addr, "&", (yyvsp[0].elem)->addr,(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
            //typecheck end

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[chartostring((yyval.elem)->addr)]=-stack_offset;
            stack_offset += 8;
            //m3 end
        }
#line 3787 "parser.tab.c"
    break;

  case 119:
#line 1713 "parser.y"
                         { 
                (yyval.elem) = (yyvsp[0].elem); 
            }
#line 3795 "parser.tab.c"
    break;

  case 120:
#line 1716 "parser.y"
                                                 { 
                (yyval.elem) = create_node(4, "shift_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
                // $$->addr = str_to_ch(newTemp());
                // create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);

                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,(yyvsp[-1].elem)->addr);
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)),(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
                else if(ret_type != (yyvsp[-2].elem)->atom_type){
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, str_to_ch("("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr)),(yyvsp[0].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
                }
                else{
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr,(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
            //typecheck end

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[chartostring((yyval.elem)->addr)]=-stack_offset;
            stack_offset += 8;
            //m3 end
            }
#line 3836 "parser.tab.c"
    break;

  case 121:
#line 1754 "parser.y"
                 { 
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 3844 "parser.tab.c"
    break;

  case 122:
#line 1757 "parser.y"
                                   { 
                
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
                //$$->addr = str_to_ch(newTemp());
                //create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);
                //type_checking
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"+");
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    //string temp = newTemp(); 
                    (yyval.elem)->addr = str_to_ch(newTemp()); 
                    create_ins(1, (yyval.elem)->addr, "+", (yyvsp[-2].elem)->addr,str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)));
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
                else if(ret_type != (yyvsp[-2].elem)->atom_type){
                    //string temp = newTemp();
                    (yyval.elem)->addr = str_to_ch(newTemp()); 
                    create_ins(1, (yyval.elem)->addr, "+", str_to_ch("("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr)),(yyvsp[0].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
                }
                else{
                    //string temp = newTemp();
                    (yyval.elem)->addr = str_to_ch(newTemp()); 
                    create_ins(1, (yyval.elem)->addr, "+", (yyvsp[-2].elem)->addr,(yyvsp[0].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
                //typecheck end

                //m3 start
                (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
                offset_map[chartostring((yyval.elem)->addr)]=-stack_offset;
                stack_offset += 8;
                //m3 end
            }
#line 3889 "parser.tab.c"
    break;

  case 123:
#line 1797 "parser.y"
                                    { 
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
                //$$->addr = str_to_ch(newTemp());
                //create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);

                //type_checking
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"-");
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    //string temp = newTemp();
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "-", (yyvsp[-2].elem)->addr,str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)));
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
                else if(ret_type != (yyvsp[-2].elem)->atom_type){
                    //string temp = newTemp();
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "-", str_to_ch("("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr)),(yyvsp[0].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
                }
                else{
                    //string temp = newTemp();
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "-", (yyvsp[-2].elem)->addr,(yyvsp[0].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
            //typecheck end
                //m3 start
                (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
                offset_map[chartostring((yyval.elem)->addr)]=-stack_offset;
                //cout<<offset_map["t0"]<<endl;
                stack_offset += 8;
                //m3 end
            }
#line 3934 "parser.tab.c"
    break;

  case 124:
#line 1838 "parser.y"
             {
            (yyval.elem) = (yyvsp[0].elem); 
        }
#line 3942 "parser.tab.c"
    break;

  case 125:
#line 1841 "parser.y"
                                  {
            (yyval.elem) = create_node(4, "term", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            // $$->addr = str_to_ch(newTemp());
            // create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);

            //type_checking
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,(yyvsp[-1].elem)->addr);
                //cout<<$1->atom_type<<" "<<$3->atom_type<<" "<<ret_type<<endl;
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    //string temp = newTemp();
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr,str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)));
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
                else if(ret_type != (yyvsp[-2].elem)->atom_type){
                    //string temp = newTemp();
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, str_to_ch("("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr)),(yyvsp[0].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
                }
                else{
                    //string temp = newTemp();
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr,(yyvsp[0].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
            //typecheck end

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[chartostring((yyval.elem)->addr)]=-stack_offset;
            stack_offset += 8;
            //m3 end
        
		}
#line 3989 "parser.tab.c"
    break;

  case 126:
#line 1885 "parser.y"
                            { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3997 "parser.tab.c"
    break;

  case 127:
#line 1888 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 4005 "parser.tab.c"
    break;

  case 128:
#line 1891 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 4013 "parser.tab.c"
    break;

  case 129:
#line 1894 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 4021 "parser.tab.c"
    break;

  case 130:
#line 1897 "parser.y"
                           { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 4029 "parser.tab.c"
    break;

  case 131:
#line 1902 "parser.y"
                                    {  
            (yyval.elem) = create_node(3, "factor", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
            (yyval.elem)->addr = str_to_ch(newTemp());
            (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr,"", (yyvsp[0].elem)->addr);

            if((yyvsp[0].elem)->atom_type=="str"){
                cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-1].elem)->lineno<<"\n";
                exit(1);
            }

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[0].elem)->stack_width;
            offset_map[chartostring((yyval.elem)->addr)]=-stack_offset;
            stack_offset += 8;
            //m3 end
        }
#line 4053 "parser.tab.c"
    break;

  case 132:
#line 1921 "parser.y"
                    { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 4061 "parser.tab.c"
    break;

  case 133:
#line 1925 "parser.y"
                            {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 4069 "parser.tab.c"
    break;

  case 134:
#line 1928 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 4077 "parser.tab.c"
    break;

  case 135:
#line 1931 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 4085 "parser.tab.c"
    break;

  case 136:
#line 1935 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 4093 "parser.tab.c"
    break;

  case 137:
#line 1938 "parser.y"
                                            { 
            (yyval.elem) = create_node(4, "power", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);

            if((yyvsp[-2].elem)->atom_type=="str" || (yyvsp[0].elem)->atom_type=="str"){
                cerr<<"Error: Type mismatch in assignment on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                exit(1);
            }

            //m3 start
            (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
            (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[chartostring((yyval.elem)->addr)]=-stack_offset;
            stack_offset += 8;
            //m3 end
        }
#line 4117 "parser.tab.c"
    break;

  case 138:
#line 1959 "parser.y"
                {  
            (yyval.elem) = (yyvsp[0].elem);  
        }
#line 4125 "parser.tab.c"
    break;

  case 139:
#line 1962 "parser.y"
                            {   //this is function call
            (yyval.elem) = create_node(3, "atom_expr", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
            string temp = newTemp();
            (yyval.elem)->addr = str_to_ch(temp);
            //create_ins(0, temp, "=" ,"call "+chartostring($1->addr), "");
            // create_ins(0,"call",chartostring($1->addr),"","");
            // create_ins(0,"PopParamAll",to_string($2->num_params),"","");
            // create_ins(0, "PopParamra", temp, "", "");
            backpatch((yyvsp[0].elem)->nextlist, instCount);

            ste* function_ste = new ste;
            if(chartostring((yyvsp[-1].elem)->type) == "self_call"){
                ste* lookup_ste = lookup(current_ste, (yyvsp[-1].elem)->class_param);
                function_ste=lookup_ste;
                //print_ste(global_sym_table,0);
                if(lookup_ste == NULL){
                    cerr<<"Error: Function in selfcall "<<(yyvsp[-1].elem)->class_param<<" not declared in class on line "<< (yyvsp[-1].elem)->lineno <<"\n";
                    exit(1);
                }

                create_ins(0,"call","self",chartostring((yyvsp[-1].elem)->addr),"");
                create_ins(0,"PopParamAll",to_string((yyvsp[0].elem)->num_params),"","");
                create_ins(0, "PopParamra", temp, "", "");
                (yyval.elem)->atom_type = lookup_ste->return_type;
            }
            
            else if(chartostring((yyvsp[-1].elem)->type) == "class_call"){ 
                string class_name = "";
                int i=0;
                while((yyvsp[-1].elem)->addr[i] != '.'){
                    class_name.push_back((yyvsp[-1].elem)->addr[i]);
                    i++;
                }

                if(class_map.find(class_name) == class_map.end()){
                    cerr<<"Error: Class "<<class_name<<" not declared on line "<<(yyvsp[-1].elem)->lineno<<"\n";
                    exit(1);
                }
                ste* class_ste = class_map[class_name];
                    //cout<<"atom_exprr: class call "<<class_name<<endl;
            
                  //here
                    ste* lookup_ste = single_rev_lookup(class_ste->next_scope, (yyvsp[-1].elem)->class_param); 
                    if(lookup_ste == NULL){
                        lookup_ste = lookup(class_ste->next_scope, (yyvsp[-1].elem)->class_param);
                    }
                    if(lookup_ste == NULL){
                        cerr<<"Error: Function "<<(yyvsp[-1].elem)->class_param<<" not declared in class "<<class_name<<" at line "<<(yyvsp[-1].elem)->lineno<<"\n";
                        exit(1);
                    }
                    //print_ste(lookup_ste,0);
                    //cout<<lookup_ste->type<<endl;
                    // if(lookup_ste->type != "FUNCTION"){
                    //     cerr<<"Error: "<<$1->class_param<<" is not a function\n";
                    //     exit(1);
                    // }
                    //cout<< lookup_ste->return_type<< "in classfunc"<<endl;
                    function_ste=lookup_ste;
                    (yyval.elem)->atom_type = lookup_ste->return_type;
                    //cout<<$$->atom_type<<endl;
                
            }
            else if(chartostring((yyvsp[-1].elem)->type) == "object_call"){ 
                (yyval.elem)->type = str_to_ch("object_call");
                //cout<<"in object call"<<endl;
                //typecheck handle
                string object_name = "";
                int i=0;
                while((yyvsp[-1].elem)->addr[i] != '.'){
                    object_name.push_back((yyvsp[-1].elem)->addr[i]);
                    i++;
                }
                i++;
                ste* lookup_ste = lookup(current_ste, object_name);
                if(class_map.find(lookup_ste->type) == class_map.end()){
                    cerr<<"Error: Class "<<lookup_ste->type<<" not declared in line "<<(yyvsp[-1].elem)->lineno<<"\n";
                    exit(1);
                }
                else{
                    lookup_ste = class_map[lookup_ste->type];
                }
                string func_name = "";
                while((yyvsp[-1].elem)->addr[i] != '\0'){
                    func_name.push_back((yyvsp[-1].elem)->addr[i]);
                    i++;
                } 
                //cout<<"function name: "<<func_name<<endl;
                //single rev matlab usi scope me dekhega, hume usi me chahiye kyuki
                lookup_ste = lookup_ste->next_scope;
                ste* lookup_ste2 = single_rev_lookup(lookup_ste, func_name);
                if(lookup_ste2 == NULL){
                    lookup_ste2 = lookup(lookup_ste, func_name);
                }
                if(lookup_ste2 == NULL){
                    cerr<<"Error: Function "<<func_name<<" not declared in object "<<object_name<<" at line "<<(yyvsp[-1].elem)->lineno<<"\n";
                    exit(1);
                }
                else{
                    if(lookup_ste2->type != "FUNCTION"){
                        cerr<<"Error: "<<func_name<<" is not a function, line: "<<(yyvsp[-1].elem)->lineno<<"\n";
                        exit(1);
                    }
                    function_ste=lookup_ste2;
                    (yyval.elem)->atom_type = lookup_ste2->return_type;
                }

                create_ins(0,"call","obj",chartostring((yyvsp[-1].elem)->addr),"");
                create_ins(0,"PopParamAll",to_string((yyvsp[0].elem)->num_params),"","");
                create_ins(0, "PopParamra", temp, "", "");

            }
            else if(chartostring((yyvsp[-1].elem)->type) == "class_constructor"){ 
                //LALRparser(self,"abc") is type wale
                (yyval.elem)->type = str_to_ch("class_constructor");

                //// cout<<"check: "<<$1->addr<<endl;
                (yyval.elem)->atom_type = ((yyvsp[-1].elem)->addr);
                //// cout<<$$->atom_type<<endl;
                // $$->atom_type = "object";


                //add 3ac for calling constructor if required// I think it will be in test colon test equal eqtes

                //see that the parameters passed are correct and type checking
                ste* lookup_ste;
                if(class_map.find(chartostring((yyvsp[-1].elem)->addr))==class_map.end()){
                    cerr<<"Error: Class "<<(yyvsp[-1].elem)->addr<<" not declared on line "<<(yyvsp[-1].elem)->lineno<<"\n";
                }
                else{
                    lookup_ste=class_map[chartostring((yyvsp[-1].elem)->addr)];
                }
                lookup_ste=single_rev_lookup(lookup_ste->next_scope,"__init__");
                if(lookup_ste == NULL){ 
                    function_ste->num_params = 0;
                }
                else{
                    function_ste=lookup_ste;
                } 
                create_ins(0,"call","class",chartostring((yyvsp[-1].elem)->addr),"");
                create_ins(0,"PopParamAll",to_string((yyvsp[0].elem)->num_params),"","");
                // create_ins(0, "PopParamra", temp, "", "");
            }
            else{ 
            //typecheck
                (yyval.elem)->type = str_to_ch("function_call");
                ste* lookup_ste = lookup(current_ste, (yyvsp[-1].elem)->addr);
                // cout<<"in";
                if(lookup_ste == NULL){ //print_ste(current_ste,2);
                    
                    cerr<<"Error: Function "<<(yyvsp[-1].elem)->addr<<" not declared on line "<<(yyvsp[-1].elem)->lineno<<"\n";
                    exit(1);
                } //else wala part is by chatgpt
                else{
                    //Type_checking
                    //cout<<lookup_ste->type<<endl;
                    if(lookup_ste->type != "FUNCTION"){
                        cerr<<"Error: "<<(yyvsp[-1].elem)->addr<<" is not a function at line "<<(yyvsp[-1].elem)->addr<<"\n";
                        exit(1);
                    }
                    function_ste=lookup_ste;
                    (yyval.elem)->atom_type = lookup_ste->return_type;
                    // cout<<"in atm_func"<<endl;
                    //cout<<function_ste->num_params<<endl;
                }
                create_ins(0,"call","function",chartostring((yyvsp[-1].elem)->addr),"");
                create_ins(0,"PopParamAll",to_string((yyvsp[0].elem)->num_params),"","");
                create_ins(0, "PopParamra", temp, "", "");
            }
            //endtypecheck

            //function ke parameters ka type check idhar 
            //cout<<$2->func_par_type.size()<<" "<<function_ste->func_par_type.size()<<endl;
            if(function_ste->num_params != (yyvsp[0].elem)->num_params){ 
                //cout<<"Checking number of parameters: "<<function_ste->num_params<<" "<<$2->num_params<<endl;
                cerr<<"Error: Number of parameters mismatch on line "<<(yyvsp[-1].elem)->lineno<<"\n";
                exit(1);
            }
            //cout<<"para check start"<<endl;
            for(int i=0;i< (yyvsp[0].elem)->func_par_type.size();i++){ //cout<<function_ste->func_par_type.size()<<endl;
                //cout<<$2->func_par_type[i]<<" "<< function_ste->func_par_type[i]<<endl;
                if((yyvsp[0].elem)->func_par_type[i] != function_ste->func_par_type[i]){
                    cerr<<"Error: Mismatch of a parameter in function: "<<function_ste->lexeme<<" at line "<<(yyvsp[-1].elem)->lineno<<"\n";
                    exit(1);
                }
            }
            //cout<<"para check end"<<endl;

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-1].elem)->stack_width;
            offset_map[temp]=-stack_offset;
            stack_offset += 8;
            //m3 end

        }
#line 4326 "parser.tab.c"
    break;

  case 140:
#line 2158 "parser.y"
                                                   {   //array access
            (yyval.elem) = create_node(6, "atom_expr", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            //$$->atom_type= $1->atom_type; //check this
            string temp = str_to_ch(newTemp());
            (yyval.elem)->addr = str_to_ch(temp);
            //cout<<"in atom_expr "<<temp<<endl;
            create_ins(1, (yyval.elem)->addr, "*", (yyvsp[-1].elem)->addr, to_string(get_width(lookup(current_ste, (yyvsp[-4].elem)->addr)->type)));
            (yyval.elem)->addr = str_to_ch(chartostring((yyvsp[-4].elem)->addr) + "["+chartostring((yyval.elem)->addr)+"]");

            //typechecking handle and $$->atom_type also

            (yyval.elem)->type= str_to_ch("array_element");
            ste* lookup_ste = lookup(current_ste, (yyvsp[-4].elem)->addr);
            int i=0;
            string array_type="";
            while(lookup_ste->type[i] != '['){
                i++;
            }
            i++;
            while(lookup_ste->type[i] != ']'){
                array_type.push_back(lookup_ste->type[i]);
                i++;
            }
            if((yyvsp[-1].elem)->atom_type != "int"){
                cerr<<"Error: Array index is not an integer at line "<<(yyvsp[-4].elem)->lineno<<"\n";
                exit(1);
            }
            (yyval.elem)->atom_type = array_type;
            //cout<<$$->atom_type<<endl;
             //check this suppose a[2] hai to hum a ka type dekhenge

             //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-4].elem)->stack_width + (yyvsp[-1].elem)->stack_width;
            offset_map[temp]=-stack_offset;
            stack_offset += 8;
            isinsquare=0;
             //m3 end

        }
#line 4372 "parser.tab.c"
    break;

  case 141:
#line 2199 "parser.y"
                             { 
            // cout<<"symbol table in atom_expr"<<endl; 
            // print_ste(global_sym_table,0);
            (yyval.elem) = create_node(4, "atom_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(chartostring((yyvsp[-2].elem)->addr) + "." + chartostring((yyvsp[0].elem)->addr));

            //typechecking handle and $$->addtype also

            //for objects like in sirs testcase3 obj.print_name() or obj.x 
            ste*  lookup_ste = lookup(current_ste, (yyvsp[-2].elem)->addr);
            if(lookup_ste == NULL){
                cerr<<"Error: Object "<<(yyvsp[-2].elem)->addr<<" not declared at line "<<(yyvsp[-2].elem)->lineno<<"\n";
                exit(1);
            }
            //cout<<lookup_ste->token<<endl;
            if(lookup_ste -> token == "OBJECT"){
                (yyval.elem)->type = str_to_ch("object_call");
                //see what else to do
                lookup_ste = lookup(lookup_ste, (yyvsp[0].elem)->addr);

                if(lookup_ste != NULL){
                    (yyval.elem)->atom_type = lookup_ste->type;
                }
            }
            //here it ends
            else{
                (yyval.elem)->type = str_to_ch("class_call");
                //cout<<$1->addr<<endl; 
                //print_ste(global_sym_table,0);
                //here also should I check using class map? may be no because abhi jaha current_ste hai waha se kuch class shyd access na ho paye 
                ste* lookup_ste = lookup(current_ste, (yyvsp[-2].elem)->addr);
                if(lookup_ste == NULL){
                    cerr<<"Error: Class "<<(yyvsp[-2].elem)->addr<<" not declared on line "<<(yyvsp[-2].elem)->lineno<<"\n";
                    exit(1);
                } //else wala part is by chatgpt
                else{
                    //Type_checking
                    if(lookup_ste->type != "CLASS"){ //public3 wala part me lalrparser ka type yaha khali aa rha check
                        //cout<<"check "<<lookup_ste->lexeme<<" "<<lookup_ste->type<<endl;
                        lookup_ste = lookup(current_ste, lookup_ste->type);
                        //cout<<"check lexeme "<<lookup_ste->lexeme<<endl;
                        //why we are setting $$->addr again
                        (yyval.elem)->addr = str_to_ch(lookup_ste->lexeme + "." + chartostring((yyvsp[0].elem)->addr));
                    }
                    (yyval.elem)->class_param = ((yyvsp[0].elem)->addr);
                    //we need to get atom_type here, //it will be only for already defined
                    //function wale ka to upar trailer me jaake set ho jayega, yaha pe hume sirf normal wale ka nikalna hoga (kisi object ka)
                }
            }

            //m3 start pending $$->atom_type in else
                //$$->stack_width = get_width($3->atom_type) + $1->stack_width;
            //m3 end
            
            // ste* lookup_ste2 = lookup(current_ste,$1->addr);
            // if(lookup_ste2 ->token == "OBJECT"){
            //     string classname= lookup_ste2 -> type;
            //     lookup_ste2 = class_map[classname]; //symboltable entry of class
            //     ste* attribute = lookup(lookup_ste2,$3->addr);
            //     if(attribute == NULL){
            //         attribute = single_rev_lookup(lookup_ste2->next_scope,$3->addr);
            //     }
            //     if(attribute!= NULL){ 
            //         $$->atom_type = attribute->type;
            //     }
            //     //error condition daal sakte
            // //cout<< "atom expr dot name: "<<$$->atom_type<<endl;
            // }

        }
#line 4449 "parser.tab.c"
    break;

  case 142:
#line 2271 "parser.y"
                                              { 
            (yyval.elem) = create_node(5, "atom_expr", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-3].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            //$$->addr = str_to_ch("len("+chartostring($3->addr)+")");
            (yyval.elem)->atom_type = "int";
            int list_size;

            if(chartostring((yyvsp[-1].elem)->type) == "NAME"){
                    ste* lookup_ste = lookup(current_ste, (yyvsp[-1].elem)->addr);
                    if(lookup_ste == NULL){
                        cerr<<"Error: List "<<(yyvsp[-1].elem)->addr<<" not declared at line "<<(yyvsp[-1].elem)->lineno<<"\n";
                        exit(1);
                    }
                }
            else{
                if((yyvsp[-1].elem)->atom_type != "list[int]" && (yyvsp[-1].elem)->atom_type != "list[float]" && (yyvsp[-1].elem)->atom_type != "list[str]" && (yyvsp[-1].elem)->atom_type != "list[bool]"){
                    cerr<<"Error: len() can only be applied to list of int, float, str or bool at line "<<(yyvsp[-1].elem)->lineno<<"\n";
                    exit(1);
                }
            }

            // if($3->type == str_to_ch("NAME")){
            //     ste* lookup_ste = lookup(current_ste, $3->addr);
            //     list_size = lookup_ste->list_size;
            // }
            // else{    
            //     list_size = $3->list_size;
            // }
            create_ins(0, "call", "len", (yyvsp[-1].elem)->addr, "");
            string temp = newTemp();
            create_ins(0, "PopParamra", temp, "","");
            (yyval.elem)->addr = str_to_ch(temp);
        }
#line 4488 "parser.tab.c"
    break;

  case 143:
#line 2305 "parser.y"
                                                { 
            (yyval.elem) = create_node(5, "atom_expr", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-3].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            //$$->addr = str_to_ch("print("+chartostring($3->addr)+")");
            (yyval.elem)->atom_type = "None";
            // create_ins(0, "PushParam", $3->addr, "", "");
            create_ins(0, "call", "print", (yyvsp[-1].elem)->addr, "");
            // create_ins(0, "PopParamAll", "1", "", "");

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-1].elem)->stack_width;
            //m3 end
        }
#line 4507 "parser.tab.c"
    break;

  case 144:
#line 2319 "parser.y"
                        {
            (yyval.elem) = create_node(4, "atom_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch("self."+chartostring((yyvsp[0].elem)->addr));

            (yyval.elem)->type = str_to_ch("self_call");

            ste* lookup_ste = lookup(current_ste, (yyvsp[0].elem)->addr);
            //include error rule
            (yyval.elem)->class_param = (yyvsp[0].elem)->addr;
            
            //we need to get atom_type here, 
            //function wale ka to upar trailer me jaake set ho jayega, yaha pe hume sirf normal wal eka nikalna hoga
            ste* lookup_ste2 = lookup(current_ste,"self");
            string classname= lookup_ste2 -> token;
            lookup_ste2 = class_map[classname];
            //print_ste(lookup_ste2,0);
            ste* attribute = lookup(lookup_ste2,(yyvsp[0].elem)->addr);     //FOR INHERITANCE
            if(attribute == NULL){
                attribute = single_rev_lookup(lookup_ste2->next_scope,(yyvsp[0].elem)->addr);
            }
            if(attribute!= NULL){ 
                (yyval.elem)->atom_type = attribute->type;
            }
            //cout<<"self dot name: "<< $$->atom_type<<endl;

        }
#line 4540 "parser.tab.c"
    break;

  case 145:
#line 2349 "parser.y"
            {
    isinsquare=1;
}
#line 4548 "parser.tab.c"
    break;

  case 146:
#line 2355 "parser.y"
                                         { 
        (yyval.elem)=(yyvsp[-1].elem);      
        incheck=0;
    }
#line 4557 "parser.tab.c"
    break;

  case 147:
#line 2359 "parser.y"
                                    {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
        (yyval.elem)->ins = instCount+1;
    }
#line 4567 "parser.tab.c"
    break;

  case 148:
#line 2365 "parser.y"
                                             { 
        (yyval.elem) = (yyvsp[-1].elem);
        isinsquare=0;
        (yyval.elem)->atom_type = "list["+(yyvsp[-1].elem)->atom_type+"]";
        string type = "";
        int i=0;
        while((yyvsp[-1].elem)->atom_type[i] != '['){
            i++;
        }
        i++;
        while((yyvsp[-1].elem)->atom_type[i] != ']'){
            type.push_back((yyvsp[-1].elem)->atom_type[i]);
            i++;
        }
        create_ins(0,"Heapalloc", to_string((yyvsp[-1].elem)->list_size), "", "");
        funcOffset += get_width(type) * (yyvsp[-1].elem)->list_size;
    }
#line 4589 "parser.tab.c"
    break;

  case 149:
#line 2382 "parser.y"
                                  {
        (yyval.elem) = create_node(4, "atom", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
        (yyval.elem)->ins = instCount+1;
        isinsquare=0;
    }
#line 4600 "parser.tab.c"
    break;

  case 150:
#line 2389 "parser.y"
                                { 
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
        (yyval.elem)->ins = instCount+1;
    }
#line 4610 "parser.tab.c"
    break;

  case 151:
#line 2395 "parser.y"
              {
        if(incheck) isatom=1;
        (yyval.elem)->type = str_to_ch("NAME");  //is this required?
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;

        //cout<< $1->addr<<endl;
        //here we are adding the atom_type if it exists in the symbol table
        ste* lookup_ste = lookup(current_ste, (yyvsp[0].elem)->addr);
        //cout<< $1->addr<<endl;
        if( lookup_ste ){
            if(lookup_ste->is_func_class){  //class will not be parsed from here
                (yyval.elem)->atom_type = lookup_ste->return_type;
            }
            else{
                (yyval.elem)->atom_type = lookup_ste->type;
            }
        }
        //is else required

        //for constructor part I am adding here 
        string class_name = "";
        if(class_map.find(chartostring((yyvsp[0].elem)->addr)) != class_map.end()){
            class_name = chartostring((yyvsp[0].elem)->addr);
            (yyval.elem)->type = str_to_ch("class_constructor");
            // $$->atom_type = "object";
            (yyval.elem)->atom_type = ((yyvsp[0].elem)->addr);
        }
    }
#line 4644 "parser.tab.c"
    break;

  case 152:
#line 2424 "parser.y"
                   { 
        if(incheck) isatom=1;
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
        // cout<<$$->atom_type<<endl;
    }
#line 4655 "parser.tab.c"
    break;

  case 153:
#line 2430 "parser.y"
                        { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 4663 "parser.tab.c"
    break;

  case 154:
#line 2433 "parser.y"
                        { 
        if(incheck) isatom=1;
        (yyval.elem)->atom_type="bool";
        (yyval.elem)->type=str_to_ch("bool");
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 4675 "parser.tab.c"
    break;

  case 155:
#line 2440 "parser.y"
                { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
        (yyval.elem)->atom_type="None";
    }
#line 4685 "parser.tab.c"
    break;

  case 156:
#line 2451 "parser.y"
                        {
            (yyval.elem) = (yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
            (yyval.elem)->type=str_to_ch("str");
            (yyval.elem)->atom_type="str";

            //m3 start
            //cout<<$1->addr<<endl;
            (yyval.elem)->str_len = chartostring((yyvsp[0].elem)->addr).size()-2;
            //cout<<$$->str_len<<endl;
            //m3 end
        }
#line 4702 "parser.tab.c"
    break;

  case 157:
#line 2463 "parser.y"
                                { 
            (yyval.elem) = create_node(3, "STRING_PLUS", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->atom_type="str";
            (yyval.elem)->type=str_to_ch("str");

            //m3 start
            (yyval.elem)->str_len = (yyvsp[-1].elem)->str_len + (yyvsp[0].elem)->str_len;
            //m3 end

        }
#line 4719 "parser.tab.c"
    break;

  case 158:
#line 2477 "parser.y"
                                     { 
            (yyval.elem) = create_node(3, "trailer", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
            (yyval.elem)->ins = instCount+1;

            create_ins(0, "PushParamra", "", "", "");
            (yyval.elem)->nextlist = makelist(instCount);
        }
#line 4732 "parser.tab.c"
    break;

  case 159:
#line 2485 "parser.y"
                                              {
            (yyval.elem)=(yyvsp[-1].elem);

            //func_par_type
            (yyval.elem)->func_par_type = (yyvsp[-1].elem)->func_par_type;
        }
#line 4743 "parser.tab.c"
    break;

  case 160:
#line 2491 "parser.y"
                                                         {
            (yyval.elem)=(yyvsp[-1].elem);

            //func_par_type
            (yyval.elem)->func_par_type = (yyvsp[-1].elem)->func_par_type;
        }
#line 4754 "parser.tab.c"
    break;

  case 161:
#line 2497 "parser.y"
                                          {
            (yyval.elem) = create_node(4, "trailer", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->ins = instCount+1;
        }
#line 4764 "parser.tab.c"
    break;

  case 162:
#line 2510 "parser.y"
                           { 
            //cout<<$1->atom_type<<endl; 
            (yyval.elem) = (yyvsp[0].elem);
            if(isinsquare) (yyval.elem)-> addr = str_to_ch(chartostring((yyvsp[0].elem)->addr) + "]");
            else (yyval.elem)-> addr = (yyvsp[0].elem)->addr;
        }
#line 4775 "parser.tab.c"
    break;

  case 163:
#line 2516 "parser.y"
                                {
            (yyval.elem)=create_node(3,"testlist",(yyvsp[-1].elem),(yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
            (yyval.elem)->list_size = (yyvsp[-1].elem)->list_size;
            (yyval.elem)->atom_type = (yyvsp[-1].elem)->atom_type;
            if(isinsquare) (yyval.elem)-> addr = str_to_ch(chartostring((yyvsp[-1].elem)->addr) + "]");
            else (yyval.elem)-> addr = (yyvsp[-1].elem)->addr;

            //M3 start
            (yyval.elem)->stack_width = (yyvsp[-1].elem)->stack_width;
            //M3 end
        }
#line 4793 "parser.tab.c"
    break;

  case 164:
#line 2530 "parser.y"
                            {
            (yyval.elem) = (yyvsp[0].elem);
            (yyval.elem)->list_size = 1;
            if(isinsquare)(yyval.elem)-> addr = str_to_ch( "[" + chartostring((yyvsp[0].elem)->addr));
            else (yyval.elem)-> addr = (yyvsp[0].elem)->addr;
            

            // //function parameters check 
            // $$->func_par_type.push_back($1->atom_type);
        }
#line 4808 "parser.tab.c"
    break;

  case 165:
#line 2540 "parser.y"
                              {
            (yyval.elem) = create_node(4, "testlist_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->list_size = 1;
            (yyvsp[-2].elem)->atom_type = (yyvsp[0].elem)->addr;
            //$$->atom_type = "list["+$1->atom_type+"]"; //ye kyu kia hai bc
            (yyval.elem)->atom_type = (yyvsp[0].elem)->addr; //ye karke wo lassi wla test case pass hua
            //STE code start
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[-2].elem)->addr) == NULL){
                current_ste = insert_entry_same_scope(current_ste, "VARIABLE", (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr, (yyvsp[-2].elem)->lineno, 1);
            }
            else{
                cerr<<"Error: Variable "<<(yyvsp[-2].elem)->addr<<" already declared at line "<<lookup(lookup_ste, (yyvsp[-2].elem)->addr)->lineno<<"\n";
                exit(1);
            }
            //STE code end

            // //function parameters check 
            // $$->func_par_type.push_back(chartostring($3->addr));

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width;
            offset_map[chartostring((yyvsp[-2].elem)->addr)] = -stack_offset;
            stack_offset += 8;
            //m3 end

        }
#line 4843 "parser.tab.c"
    break;

  case 166:
#line 2570 "parser.y"
                                    { 
            (yyval.elem) = create_node(4, "testlist_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->list_size = (yyvsp[-2].elem)->list_size + 1;
            //cout<<$1->addr<<endl;
            (yyval.elem)-> addr = str_to_ch(chartostring((yyvsp[-2].elem)->addr) + "," + chartostring((yyvsp[0].elem)->addr));
            (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
            //$$->atom_type = "list["+$3->atom_type+"]";
            //cout<<$$->addr<<endl;
            // cout<<$3->atom_type<<endl;

            // //function parameters check 
            // $$->func_par_type = $1->func_par_type;
            // $$->func_par_type.push_back($3->atom_type);

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 4868 "parser.tab.c"
    break;

  case 167:
#line 2590 "parser.y"
                                                   { 
            (yyval.elem) = create_node(6, "testlist_list", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;

            (yyvsp[-2].elem)->atom_type = (yyvsp[0].elem)->addr;
            (yyval.elem)->atom_type = "list["+(yyvsp[-2].elem)->atom_type+"]";

            //STE code start
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[-2].elem)->addr) == NULL){
                current_ste = insert_entry_same_scope(current_ste, "VARIABLE", (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr, (yyvsp[-2].elem)->lineno, 1);
            }
            else{
                cerr<<"Error: Variable "<<(yyvsp[-2].elem)->addr<<" already declared on line "<<lookup(lookup_ste, (yyvsp[-2].elem)->addr)->lineno<<"\n";
                exit(1);
            }
            //STE code end

            // //function parameters check 
            // $$->func_par_type = $1->func_par_type;
            // $$->func_par_type.push_back(chartostring($5->addr));

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-4].elem)->stack_width + (yyvsp[-2].elem)->stack_width + get_width((yyvsp[0].elem)->addr);
            offset_map[chartostring((yyvsp[-2].elem)->addr)] = -stack_offset;
            stack_offset += get_width((yyvsp[0].elem)->addr);
            //m3 end
        }
#line 4902 "parser.tab.c"
    break;

  case 168:
#line 2652 "parser.y"
                                                    {
            (yyval.elem) = create_node(5, "classdef", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem),(yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-3].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            //yaha condition check ki class declare kaunsa use ho rha hai
            if(ischild==0){
                current_ste = get_prev_scope(current_ste);
                populate_new_scope(current_ste, "CLASS", (yyvsp[-2].elem)->addr, 0, (yyvsp[-3].elem)->lineno, 1);
                //class_map[className]=current_ste; 
            }
            else{
                ischild=0;
                current_ste = get_prev_scope(current_ste);
                populate_new_scope(current_ste, "CLASS", (yyvsp[-2].elem)->addr, 0, (yyvsp[-3].elem)->lineno, 1);
                current_ste= lookup(current_ste, "global_head");
                while(current_ste->next!=NULL){
                    current_ste = current_ste->next;
                }
            }

            //m3start
            ste* class_ste = class_map[chartostring((yyvsp[-2].elem)->addr)];
            class_ste->class_width = class_offset;
            class_offset = 0;
            curr_class="";
            //m3 end
        }
#line 4934 "parser.tab.c"
    break;

  case 169:
#line 2681 "parser.y"
                     {
            (yyval.elem)=(yyvsp[0].elem);
            inClass=1;
            className = chartostring((yyvsp[0].elem)->addr);


            //STE code start
            ste* lookup_ste = current_ste;
            if(class_map.find(chartostring((yyvsp[0].elem)->addr)) == class_map.end()){
                current_ste = insert_entry_new_scope(current_ste);
                class_map[chartostring((yyvsp[0].elem)->addr)]=current_ste->prev_scope;
                current_ste = insert_entry_same_scope(current_ste,chartostring((yyvsp[0].elem)->addr),"self","CLASS",(yyvsp[0].elem)->lineno,0);
            }
            else{
                cerr<<"Error: Class "<<(yyvsp[0].elem)->addr<<" already declared on line "<<class_map[chartostring((yyvsp[0].elem)->addr)] ->lineno<<"\n";
                exit(1);
            }
            //STE code end 

            //m3 start
            curr_class = chartostring((yyvsp[0].elem)->addr);
            // class_offset = 8;
            //mm3 end
        }
#line 4963 "parser.tab.c"
    break;

  case 170:
#line 2705 "parser.y"
                                         {
            (yyval.elem)=(yyvsp[-2].elem);
            inClass=1;
            className = chartostring((yyvsp[-2].elem)->addr);


            //STE code start
            ste* lookup_ste = current_ste;
            if(class_map.find(chartostring((yyvsp[-2].elem)->addr)) == class_map.end()){
                current_ste = insert_entry_new_scope(current_ste);
                class_map[chartostring((yyvsp[-2].elem)->addr)]=current_ste->prev_scope;
                current_ste = insert_entry_same_scope(current_ste,chartostring((yyvsp[-2].elem)->addr),"self","CLASS",(yyvsp[-2].elem)->lineno,0);
            }
            else{
                cerr<<"Error: Class "<<(yyvsp[-2].elem)->addr<<" already declared at line "<<class_map[chartostring((yyvsp[-2].elem)->addr)]->lineno<<"\n";
                exit(1);
            }
            //STE code end 

            //m3 start
            curr_class = chartostring((yyvsp[-2].elem)->addr);
            // class_offset = 8;
            //mm3 end
        }
#line 4992 "parser.tab.c"
    break;

  case 171:
#line 2729 "parser.y"
                                                  {
            (yyval.elem) = create_node(5, "class_declare", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-3].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->addr = (yyvsp[-3].elem)->addr;
            inClass=1;
            ischild=1; 
            className = chartostring((yyvsp[-3].elem)->addr);
            // cout<<"in class dec: "<<chartostring($3->addr)<<endl;
            if(class_map.find(chartostring((yyvsp[-1].elem)->addr)) == class_map.end()){
                cerr<<"Error: Class "<<(yyvsp[-1].elem)->addr<<" not declared at line "<<(yyvsp[-1].elem)->lineno<<"\n";
                exit(1);
            }
            else{
                current_ste = class_map[chartostring((yyvsp[-1].elem)->addr)];
                if(current_ste!=NULL )current_ste = current_ste->next_scope;
            }
            if(current_ste== NULL){
                cerr<<"Error: Class "<<(yyvsp[-1].elem)->addr<<" not declared at line "<<(yyvsp[-1].elem)->lineno<<"\n";
                exit(1);
            }
            while(current_ste->next!=NULL){
                current_ste = current_ste->next;
            }
            ste* lookup_ste = current_ste;
            if(class_map.find(chartostring((yyvsp[-3].elem)->addr)) == class_map.end()) {
                current_ste = insert_entry_new_scope(current_ste);
                class_map[chartostring((yyvsp[-3].elem)->addr)]=current_ste->prev_scope;
                current_ste = insert_entry_same_scope(current_ste,chartostring((yyvsp[-3].elem)->addr),"self","CLASS",(yyvsp[-3].elem)->lineno,0);
            }
            else{
                cerr<<"Error: Class "<<(yyvsp[-3].elem)->addr<<" already declared at line "<<class_map[chartostring((yyvsp[-3].elem)->addr)]->lineno<<"\n";
                exit(1);
            }

            //m3 start
            class_parent[chartostring((yyvsp[-3].elem)->addr)]=chartostring((yyvsp[-1].elem)->addr);
            ste* child_ste = class_map[chartostring((yyvsp[-3].elem)->addr)];
            ste* parent_ste = class_map[chartostring((yyvsp[-1].elem)->addr)];
            child_ste->class_offset_map = parent_ste->class_offset_map;
            class_offset = parent_ste->class_width;
            curr_class = chartostring((yyvsp[-3].elem)->addr);
            //m3 end

        }
#line 5042 "parser.tab.c"
    break;

  case 172:
#line 2802 "parser.y"
                                                        { 
            (yyval.elem)=(yyvsp[-1].elem);
            inClass=0;
        }
#line 5051 "parser.tab.c"
    break;

  case 173:
#line 2806 "parser.y"
                                                        { 
            (yyval.elem)=(yyvsp[-2].elem);
            inClass=0;
        }
#line 5060 "parser.tab.c"
    break;

  case 174:
#line 2812 "parser.y"
                       { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 5068 "parser.tab.c"
    break;

  case 175:
#line 2815 "parser.y"
                                 { 
            (yyval.elem)=create_node(3,"funcdef_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 5078 "parser.tab.c"
    break;

  case 176:
#line 2843 "parser.y"
                           { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 5086 "parser.tab.c"
    break;

  case 177:
#line 2850 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;

            //create_ins(0, "PushParam", "RBP", "", "");
            (yyval.elem)->ins = instCount+1;
            (yyval.elem)->nextlist = makelist(instCount+1);
            create_ins(0, "PushParamra", "", "", "");
            create_ins(0, "PushParam", (yyvsp[0].elem)->addr, "", "");
        
        }
#line 5102 "parser.tab.c"
    break;

  case 178:
#line 2861 "parser.y"
                                        { 
            (yyval.elem) = create_node(4, "argument_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[0].elem)->num_params + 1;

            create_ins(0, "PushParam", (yyvsp[-2].elem)->addr, "", "");
            (yyval.elem)->nextlist = (yyvsp[0].elem)->nextlist;

            //function par type
            (yyval.elem)->func_par_type = (yyvsp[-2].elem)->func_par_type;
            for(int i=0;i< (yyvsp[0].elem)->func_par_type.size();i++){
                (yyval.elem)->func_par_type.push_back((yyvsp[0].elem)->func_par_type[i]);
            }

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 5126 "parser.tab.c"
    break;

  case 179:
#line 2882 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
            //for function parameter typecheck
            (yyval.elem)->func_par_type.push_back((yyvsp[0].elem)->atom_type);
        }
#line 5136 "parser.tab.c"
    break;

  case 180:
#line 2887 "parser.y"
                            { 
            (yyval.elem) = create_node(4, "argument", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");

            //for function parameter typecheck
            (yyval.elem)->func_par_type.push_back((yyvsp[-2].elem)->atom_type);

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 5154 "parser.tab.c"
    break;

  case 181:
#line 2903 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 5162 "parser.tab.c"
    break;

  case 182:
#line 2906 "parser.y"
                            { 
            
            (yyval.elem)=create_node(3,"stmt_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
			(yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
            (yyval.elem)->nextlist = merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist);
            //$$->nextlist = $2->nextlist;

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-1].elem)->stack_width+(yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 5179 "parser.tab.c"
    break;


#line 5183 "parser.tab.c"

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
#line 2919 "parser.y"


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
    /* cout<<instruction.size()<<endl; */
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

void MakeIRFile(ofstream& code_out)
{
	int tabs=0;
	for(int i=0;i<instructions.size();i++)
	{
		if(instructions[i][1]=="EndFunc") tabs--;
		//cout << i+1 << "\t" << string(tabs,'\t');
		code_out << i+1 << "\t" << string(tabs,'\t');
		if(instructions[i][0]=="0")
		{
			for(int j=1;j<instructions[i].size();j++)
			{
                if((instructions[i][j]) == "goto"){
                    if(instructions[i].size()==5 && instructions[i][j+1]==""){ 
                        instructions[i].push_back(to_string(endline));
                    }
                }				
                //cout << instructions[i][j] << (instructions[i][j].length()?" ":"");
				code_out << instructions[i][j] << (instructions[i][j].length()?" ":"");
			}
			if(instructions[i][1]=="BeginFunc") tabs++;
		}
		else
		{
			//cout << instructions[i][1] << " = " << instructions[i][3] << " " << instructions[i][2] << " " << instructions[i][4];
			code_out << instructions[i][1] << " = " << instructions[i][3] << " " << instructions[i][2] << " " << instructions[i][4];
		}
		//cout << endl;
		code_out << endl;
	}
}

void vector_copy(vector<string> v1,vector<string> v2){
    for(int i=0;i<v1.size();i++){
        v2.push_back(v1[i]);
    }
}

string typecast(string typ1,string typ2,string op)
{
	bool valid = (typeMap.find(typ1)!= typeMap.end()) && (typeMap.find(typ2)!= typeMap.end());
	int t1,t2;
	if (valid)
	{	
		t1=typeMap[typ1];
		t2=typeMap[typ2];
	}
	if (op=="=" )
	{
		if (valid)
		{
			if (t1>=t2)
				return typ1;
			else
				return "Error";
		}
		else
		{
			if (typ1==typ2)
				return typ1;
			else
				return "Error";
		}
	}
	if (op =="-" )
	{
		if (valid)
		{
			if (t1>=t2)
				return typ1;
			else
				return typ2;
		}
		else
		{
			if (typ1==typ2)
				return typ1;
			else
				return "Error";
		}
	}
	if(op=="+")
	{
		if (valid)
		{
			if (t1>=t2)
				return typ1;
			else 
				return typ2;
		}
		else
		{
			if (typ1=="String" || typ2=="String")
				return "String";
			if (typ1==typ2)
				return typ1;
			else
				return "Error";
		}
	}
	if (op==">" || op == "<" || op=="<=" || op==">=" || op=="==" || op=="!=")
	{
		if (valid)
		{
			return "bool";
		}
		else
		{
			if (typ1==typ2) //for string
				return "bool";
			else
				return "Error";
		}
	}
	if (op=="&&" || op=="||")
	{
		if (typ1==typ2 && typ1=="bool")
			return "bool";
		else
			return "Error";
	}
	if (op=="*" || op=="/" || op=="%")
	{
		if (valid)
		{
			if (t1>=t2)
				return typ1;
			else
				return typ2;
		}
		else
		{
			return "Error";
		}
	}
	if (op=="&" || op=="|" || op=="^" || op=="<<" || op==">>")
	{
		if (valid)
		{
			if (t1>=t2)
				return typ1;
			else
				return typ2;
		}
		else
		{
			return "Error";
		}
	}

	if (op=="+=")
	{
		if (valid)
		{
			if (t1>=t2)
				return typ1;
			else
				return "Error";
		}
		else
		{
			/* if (typ1=="String")
				return "String"; */
			if (typ1==typ2)
				return typ1;
			else
				return "Error";
		}
	}
	if (op=="-=" || op=="*=" || op=="/=" || op=="%=" || op=="&=" || op=="|=" || op=="^=" || op=="<<=" || op==">>=" || op=="//=" || op=="**=")
    {
        if (valid)
        {
            if (t1>=t2)
                return typ1;
            else
                return "Error";
        }
        else
        {
            return "Error";
        }
    }
	
	if (typ1 == typ2)
		return typ1;
	if (typ1 == "" || typ2 == "")
		return typ1+typ2;
	return "Error";

}

ste* setup_global_sym_table(ste* curr_ste){
    curr_ste->lexeme = "global_head";
    curr_ste->type = "GLOBAL_HEAD";
    curr_ste = insert_entry_same_scope(curr_ste, "BOOL", "True", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "BOOL", "False", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "ELSE", "else", "RESERVED_KEYWORD", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "NONE", "None", "RESERVED_KEYWORD", -1, -1);
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
    curr_ste = insert_entry_same_scope(curr_ste, "LEN", "len", "RESERVED_FUNCTION", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "PRINT", "print", "RESERVED_FUNCTION", -1, -1);
    curr_ste = insert_entry_same_scope(curr_ste, "RANGE", "range", "RESERVED_FUNCTION", -1, -1);
    return curr_ste;
}

void printToCSV(ste* curr,int level,int sublevel,ofstream& fout){
    if(curr->lexeme != "global_head" && curr->lexeme != "scope_head" && curr->type != "RESERVED_KEYWORD" && curr->type != "RESERVED_FUNCTION"){
        fout<<level<<","<<sublevel<<","<<curr->token<<","<<curr->lexeme<<","<<curr->type<<","<<curr->lineno<<","<<curr->is_func_class<<","<<curr->return_type<<","<<curr->stack_width<<","<<endl;
        fout<<"size="<<curr->offset_map.size()<<endl;
        for (const auto& pair : curr->offset_map) {
            fout << pair.first << " => " << pair.second << endl;
        }
        fout<<endl;
    }
    if (curr->next_scope != NULL)
    {   
        printToCSV(curr->next_scope,level+1,0,fout);
    }
    if (curr->next != NULL)
    {
        printToCSV(curr->next,level,sublevel+1,fout);
    }
}


int main(int argc, char* argv[]){    
    /* cout<<"Hello\n"; */
    FILE* yyin = fopen(argv[1],"r");
    yyrestart(yyin); 

    bool inset = false, outset = false;
    indent_stack.push(0);

    typeMap["None"] = 0;
    typeMap["bool"] = 1;
	typeMap["int"] = 1;
	typeMap["float"] = 3;
	typeMap["str"] = 4;

    typeMap["list[int]"] = 6;
    typeMap["list[bool]"] = 6;
    typeMap["list[float]"] = 7;
    typeMap["list[str]"] = 8;

    string srcfile="";
    int j=3;
    while(argv[1][j] != '/'){
        j++;
    }
    j++;
    while(argv[1][j] != '.'){
        srcfile.push_back(argv[1][j]);
        j++;
    }

    yyrestart(yyin);

    /* for (int i=0; i< argc; i++){
        if (strcmp(argv[i], "-help") == 0){
            cerr<<"Usage: ./run.sh [-help] [-input <filename>] [-output <filename>] [-verbose]\n";
            cerr<< "Example: ./myASTGenerator -input input.txt -output output.txt\n";
        }
        else if (strcmp(argv[i], "-input") == 0){
            yyin = fopen(argv[i+1], "r");
            int j=3;
            while(argv[i+1][j] != '/'){
                j++;
            }
            j++;
            while(argv[i+1][j] != '.'){
                srcfile.push_back(argv[i+1][j]);
                j++;
            }

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
    } */
    /* if (!outset){
        cerr<< "Output not set, see help\n";
        return 0;
    }  */

/*--------------------------------------------------------------*/

        // Open the output file
        /* fout.open(output_file.c_str(),ios::out); */
        //code_out.open("./output/3AC.txt",ios::out);
        // Get the DOT file template from the file
        /* ifstream infile("./DOT_Template.txt"); */
        /* string line; */
        /* while (getline(infile, line)) */
                /* fout << line << endl; */

/*--------------------------------------------------------------*/

    instCount=0;
    tempCount=0;
    yydebug=1; 
    current_ste = setup_global_sym_table(current_ste);
    /* cout<<"Parsing Started\n"; */
    yyparse();
    fclose(yyin); 

    //print_ste(global_sym_table,0);

/*--------------------------------------------------------------*/
   

// Create 3AC file
    ofstream code_out;
    string filename1 = "./outputs/3AC/"+srcfile+".txt";
    //cout<<filename1<<endl;
    code_out.open(filename1);
    MakeIRFile(code_out);

// CSV code
    ofstream fout;
    string filename = "./outputs/SymTab/"+srcfile+".csv";
    //cout<<filename<<endl;
    fout.open(filename);

    fout<<"Level,Sublevel,Token,Lexeme,Type,Line Number,Is Function/Class,Return Type\n";

    printToCSV(global_sym_table,0,-22,fout);

// Close the output file
    code_out.close();

/*--------------------------------------------------------------*/

    //m3 start
    create_x86();
    //m3 end

    return 0;

}
