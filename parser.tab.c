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
    using namespace std;

    extern int yylex();
    extern int yyparse();
    extern void yyrestart(FILE* file);
    extern FILE* yyin;
    extern int yylineno;
    extern char* yytext;

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
    struct label{
        int num;
        string l;
        bool terminal;
    } ;
    struct edge{
        int a;
        int b;
        string l;
    };
    vector<int> remove_label;
    vector<label> labels;
    vector<edge> edges;
    extern char* addlabel(string c, bool term = false){  
        int n=labels.size()+1;
        label q;
        q.num=n*10;
        q.l=c;
        q.terminal=term;
        if(c=="TRAILER1" || c=="ATOM1"){
                remove_label.push_back(n*10);
        }
        labels.push_back(q);
        return numtochar(n);
    }
    extern void addedge(char* a, char* b, string l=""){ 
        edge q;
        q.a=chartonum(a);
        q.b=chartonum(b);
        q.l=l;
        edges.push_back(q);
        
    }
    extern stack<int> indent_stack;

    void yyerror(string str);

    void print_ast(){
        cout << "digraph ASTVisual {\n ordering = out ;\n";
        for(auto e: labels){
            string s;
            for( auto e1: e.l){
                if(e1=='\"' || e1=='\\'  ){
                    s.push_back('\\');
                }
                s.push_back(e1);
            } 
            if(s!="ATOM1" && s!="TRAILER1" && e.terminal == false) cout<<e.num<<" [ label=\""<<s<<"\"]\n";
            else if(s!="ATOM1" && s!="TRAILER1" && e.terminal==true) cout<<e.num<<" [ label=\""<<s<<"\", color = \"red\", shape=\"box\"]\n";
        }
        for(auto e: edges){
            string s;

            for( auto e1: e.l){
                if(e1=='\"' || e1=='\\'){
                    s.push_back('\\');
                }
                s.push_back(e1);
            } 
            if(find(remove_label.begin(),remove_label.end(),e.b)==remove_label.end()) cout<<e.a<< " -> "<<e.b << "[ label=\""<<s<<"\"]\n";
        }
        cout << "  }\n";
    }
    

#line 182 "parser.tab.c"

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
#line 113 "parser.y"

    char* val;

#line 301 "parser.tab.c"

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
#define YYFINAL  111
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   655

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  217
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  327

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
       0,   180,   180,   183,   186,   187,   188,   189,   192,   193,
     194,   195,   198,   201,   202,   205,   206,   209,   210,   213,
     214,   217,   218,   221,   222,   225,   226,   227,   228,   229,
     232,   233,   234,   237,   238,   241,   242,   245,   246,   249,
     250,   253,   254,   257,   260,   261,   262,   264,   266,   268,
     269,   272,   273,   275,   276,   279,   280,   282,   283,   285,
     286,   287,   288,   289,   290,   292,   294,   295,   298,   299,
     300,   301,   303,   304,   306,   307,   309,   310,   311,   314,
     315,   317,   319,   320,   322,   323,   325,   326,   329,   330,
     332,   333,   336,   337,   340,   341,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   356,   359,   360,
     363,   364,   367,   368,   371,   372,   375,   376,   377,   379,
     380,   383,   384,   385,   386,   387,   390,   391,   393,   394,
     395,   397,   398,   401,   402,   403,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   418,   419,   422,
     423,   424,   426,   427,   429,   430,   433,   434,   435,   438,
     439,   441,   442,   444,   445,   446,   447,   448,   450,   451,
     453,   454,   456,   457,   459,   460,   462,   463,   465,   466,
     467,   468,   469,   470,   473,   474,   476,   477,   479,   480,
     482,   483,   486,   487,   488,   491,   492,   494,   495,   496,
     497,   498,   499,   500,   503,   504,   506,   507,   509,   510,
     512,   513,   515,   516,   517,   520,   521,   523
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
  "NOT_EQUAL_ARROW", "NOT_EQUAL", "IS", "$accept", "file", "file_input",
  "snippet", "funcdef", "parameters", "typedargslist", "typedarg",
  "tfpdef", "stmt", "simple_stmt", "small_stmt_list", "small_stmt",
  "expr_stmt", "eq_testlist_star_expr_plus", "annassign",
  "testlist_star_expr", "expr_choice_list", "expr_choice", "augassign",
  "flow_stmt", "break_stmt", "continue_stmt", "return_stmt", "global_stmt",
  "nonlocal_stmt", "assert_stmt", "comma_name_star", "compound_stmt",
  "async_stmt", "async_choice", "if_stmt", "while_stmt", "for_stmt",
  "suite", "nts_star", "namedexpr_test", "test", "or_test",
  "and_test_star", "and_test", "not_test_star", "not_test", "comparison",
  "comp_op", "star_expr", "expr", "xor_expr", "and_expr", "shift_expr",
  "arith_expr", "term", "term_choice", "factor", "factor_choice", "power",
  "atom_expr", "atom", "STRING_PLUS", "testlist_comp",
  "named_or_star_list", "named_or_star", "trailer", "subscriptlist",
  "subscriptlist_list", "subscript", "exprlist", "expr_or_star_expr_list",
  "expr_or_star_expr", "testlist", "testlist_list", "dictorsetmaker", "A",
  "A_list", "B", "B_list", "classdef", "arglist", "argument_list",
  "argument", "comp_iter", "sync_comp_for", "comp_for", "comp_if",
  "func_body_suite", "stmt_plus", "comma_test", YY_NULLPTR
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

#define YYPACT_NINF (-261)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-92)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      42,    42,    14,  -261,  -261,   556,   556,   579,   556,  -261,
    -261,   510,    29,    40,    68,    78,   556,  -261,    57,  -261,
     485,  -261,  -261,   602,  -261,    90,   459,    96,  -261,  -261,
    -261,    42,  -261,    20,  -261,  -261,  -261,    72,    62,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,    93,    83,    88,    95,   100,  -261,  -261,
     125,    85,    80,    87,    97,     6,  -261,   602,  -261,    27,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,   101,  -261,   108,
    -261,  -261,   133,   114,  -261,  -261,  -261,    -4,   121,   123,
     123,   128,  -261,  -261,  -261,  -261,   134,   132,    34,  -261,
     602,  -261,   135,  -261,   124,    34,   139,    34,   150,  -261,
     136,  -261,  -261,  -261,   247,  -261,   510,   556,  -261,   556,
     510,   556,   556,   556,  -261,   173,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,   171,   602,   602,   602,   602,   602,   602,
     602,  -261,  -261,  -261,  -261,  -261,   602,  -261,   602,   392,
     183,   533,  -261,   282,   282,   556,   579,   427,   282,     4,
      25,   185,  -261,  -261,   556,  -261,  -261,   510,   188,   579,
    -261,  -261,  -261,   556,  -261,  -261,   443,  -261,   510,  -261,
    -261,  -261,  -261,   165,   167,  -261,  -261,   166,  -261,   196,
     191,   193,  -261,  -261,  -261,  -261,  -261,  -261,  -261,     6,
       6,  -261,  -261,   556,  -261,   556,    81,   179,   176,  -261,
    -261,   556,   178,   163,   184,  -261,   219,  -261,   111,   210,
     192,  -261,   194,   199,  -261,   197,    76,    -6,  -261,   190,
     224,   314,   123,  -261,  -261,  -261,   220,  -261,   135,  -261,
    -261,  -261,   510,   556,   556,  -261,  -261,   556,  -261,  -261,
     187,  -261,   556,  -261,   533,   357,   203,   556,   229,   207,
     282,   282,   209,   236,   240,   314,  -261,   244,   556,   223,
     253,  -261,  -261,  -261,   556,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,   357,    37,   282,   225,   226,   282,   251,  -261,
     282,  -261,   230,  -261,  -261,  -261,   314,   357,   131,  -261,
     256,  -261,  -261,   282,   282,  -261,   235,  -261,   314,  -261,
      94,   556,  -261,  -261,  -261,  -261,   258,  -261,   282,  -261,
     277,  -261,   131,  -261,  -261,  -261,  -261
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,   146,   142,     0,     0,     0,     0,    47,
      48,    49,     0,     0,     0,     0,     0,   145,   147,   143,
       0,   128,   129,     0,   130,     0,     0,     0,     2,     3,
      62,     5,    19,     0,    23,    25,    32,    33,    37,    39,
      26,    44,    45,    46,    27,    28,    29,    20,    64,    59,
      60,    61,    41,    82,     0,    84,     0,    88,    93,    42,
      94,   108,   110,   112,   114,   116,   119,     0,   127,   131,
     133,   144,    63,     6,    66,    65,    67,     0,    81,     0,
     173,   172,     0,   168,   170,    92,    50,     0,     0,    51,
      53,    55,   148,   137,   154,   155,     0,   150,   152,   107,
       0,   141,   188,   189,     0,   186,   179,   190,   182,   139,
       0,     1,     7,    22,     0,    43,     0,     0,    30,     0,
      38,     0,     0,     0,   103,     0,    96,    97,    98,    99,
     100,   101,   102,   105,     0,     0,     0,     0,     0,     0,
       0,   125,   121,   123,   124,   122,     0,   126,     0,     0,
       0,     0,   134,     0,     0,     0,   169,     0,     0,     0,
       0,     0,    52,    54,     0,    56,   136,   151,     0,     0,
     208,   149,   185,     0,   140,   178,   180,   181,   183,   138,
      21,    24,    34,    33,    35,   176,    31,   174,    40,     0,
      85,    89,   104,   106,    95,   109,   111,   113,   115,   117,
     118,   120,   132,     0,   156,     0,   199,     0,   195,   197,
     135,   164,   163,     0,   159,   161,     0,    76,    68,    72,
       0,   171,     0,     0,   192,    17,     0,     0,    13,    15,
       0,     0,    57,   217,   153,   209,     0,   184,     0,   187,
     188,   191,     0,   175,     0,   202,   203,     0,   200,   157,
     196,   165,   166,   158,   160,     0,     0,     0,    70,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,   212,     8,    58,     0,    36,   177,    83,   201,   198,
     167,   162,   215,     0,     0,     0,     0,     0,    74,   193,
       0,    18,     0,    11,    14,    16,     0,     0,   206,   216,
       0,    77,    69,     0,     0,    73,     0,   194,     0,     9,
       0,     0,   207,   204,   205,    78,    79,    71,     0,    10,
       0,   213,   210,    80,    75,   214,   211
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -261,  -261,  -261,    13,   284,  -261,  -261,    17,  -261,  -169,
       0,  -261,   177,  -261,   174,  -261,    -5,  -261,   172,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,   -81,  -261,  -261,
    -261,  -261,  -261,   297,   -96,   -15,    -3,    -1,  -114,  -261,
     180,  -261,     2,   169,  -261,     1,     5,   182,   195,   181,
    -261,    19,  -261,   -54,  -261,  -261,  -261,  -261,   291,   294,
    -261,   154,  -261,  -261,  -261,    71,   160,  -261,   175,   186,
    -261,  -261,   158,  -261,   152,  -261,  -261,   200,  -261,    99,
      18,   198,   -87,  -261,  -218,  -260,  -261
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,    28,    29,    30,   160,   227,   228,   229,    31,
     217,    33,    34,    35,    36,   118,    37,    38,    39,   119,
      40,    41,    42,    43,    44,    45,    46,   162,    47,    48,
      75,    49,    50,    51,   218,   258,    94,    52,    53,    54,
      55,    56,    57,    58,   134,    59,    60,    61,    62,    63,
      64,    65,   146,    66,    67,    68,    69,    70,    71,    96,
      97,    98,   152,   213,   214,   215,    82,    83,    84,   186,
     187,   104,   105,   106,   107,   108,    72,   207,   208,   209,
     312,   170,   313,   314,   272,   283,   165
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    32,    77,    79,    78,    78,    86,   189,    80,   163,
      85,   171,    81,   147,    73,    91,   141,   225,   175,    78,
     177,    95,   299,   113,   102,    78,   103,    95,    99,   266,
     157,    32,     7,   267,   158,   148,   230,   310,   168,   226,
     300,    13,    87,   301,   112,     1,     2,   293,   142,   143,
     144,   145,   169,    88,     3,     4,     5,   114,   219,     6,
       7,   149,   224,   231,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   150,   309,   115,
     151,    89,    21,    22,    23,   168,   282,   264,    24,    18,
     319,    90,   201,    25,   202,    26,   111,   320,   100,   169,
     321,   120,     3,     4,   122,   172,   138,   121,   116,   -87,
     117,   183,     8,   282,   265,   123,   184,   247,   185,   248,
     -91,    17,    18,    19,    20,   191,   256,   257,   282,   136,
      21,    22,    23,   135,   137,   168,    24,   139,   140,   153,
     195,    25,   101,    26,   124,   311,   154,   125,   206,   169,
     212,   273,   155,   156,   185,   159,   206,    80,   199,   200,
     298,    81,   161,   233,   288,   289,    78,   164,    95,   166,
      80,   167,   237,   173,    81,   238,   174,   240,   176,   103,
     126,   127,   128,   129,   130,   131,   132,   133,   302,   178,
     179,   305,   192,   193,   307,   203,   210,   322,   232,     3,
       4,   116,   245,   242,   246,   243,   169,   316,   317,     8,
     251,   244,   -86,   -90,   249,   250,   252,   253,    17,    18,
      19,    20,   324,   254,   255,   259,   268,    21,    22,   205,
     260,   271,   261,    24,   262,   263,   269,   275,    25,   274,
      26,   284,   276,   277,   286,   287,   278,   290,   291,   206,
     180,   280,   292,   212,   285,    32,    78,   225,   297,     3,
       4,   296,   315,   303,   304,   271,   306,   295,   308,     8,
       9,    10,    11,   318,   257,    14,    15,    16,    17,    18,
      19,    20,    32,   325,   294,   216,    74,    21,    22,    23,
     182,   181,   188,    24,     3,     4,   271,    32,    25,    76,
      26,   323,   190,   194,     8,     9,    10,    11,   271,    92,
      14,    15,    16,    17,    18,    19,    20,   270,   196,   198,
     110,   234,    21,    22,    23,   281,     3,     4,    24,   236,
     241,   221,   197,    25,   239,    26,     8,     9,    10,    11,
     326,   220,    14,    15,    16,    17,    18,    19,    20,   279,
       0,     0,     0,     0,    21,    22,    23,   223,     0,     0,
      24,     2,     0,     0,     0,    25,   235,    26,     0,     3,
       4,     5,     0,     0,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,    21,    22,    23,
     203,     0,     0,    24,     3,     4,     0,     0,    25,     0,
      26,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    19,    20,   204,     0,     0,
       0,     0,    21,    22,   205,   203,     0,     0,    24,     3,
       4,     0,     0,    25,     0,    26,     0,     0,     0,     8,
       0,   100,     0,     0,     0,     3,     4,     0,    17,    18,
      19,    20,   222,     0,     0,     8,     0,    21,    22,   205,
       0,     3,     4,    24,    17,    18,    19,    20,    25,     0,
      26,     8,     0,    21,    22,     0,     0,     0,     0,    24,
      17,    18,    19,    20,    25,     0,    26,     3,     4,    21,
      22,    23,     0,     0,     0,    24,     0,     8,     0,     0,
      25,     0,    26,   109,     0,     0,    17,    18,    19,    20,
      93,     0,     3,     4,     0,    21,    22,    23,     0,     0,
       0,    24,     8,     0,     0,     0,    25,     0,    26,     0,
       0,    17,    18,    19,    20,     3,     4,     0,     0,     0,
      21,    22,    23,     0,     0,     8,    24,     0,     0,     0,
       0,    25,     0,    26,    17,    18,    19,    20,     3,     4,
       0,   211,     0,    21,    22,     0,     0,     0,     8,    24,
       0,     0,     0,     0,    25,     0,    26,    17,    18,    19,
      20,     3,     4,     0,     0,     0,    21,    22,     0,     0,
       0,     0,    24,     0,     0,     0,     0,    25,     0,    26,
      17,    18,    19,    20,     3,     4,     0,     0,     0,    21,
      22,    23,     0,     0,     0,    24,     0,     0,     0,     0,
      25,     0,    26,    17,    18,    19,    20,     0,     0,     0,
       0,     0,    21,    22,     0,     0,     0,     0,    24,     0,
       0,     0,     0,    25,     0,    26
};

static const yytype_int16 yycheck[] =
{
       0,     1,     5,     6,     5,     6,    11,   121,     7,    90,
       8,    98,     7,    67,     1,    16,    10,    13,   105,    20,
     107,    20,   282,     3,    25,    26,    25,    26,    23,    35,
      34,    31,    18,    39,    38,     8,    11,   297,     4,    35,
       3,    27,    13,     6,    31,     3,     4,   265,    42,    43,
      44,    45,    18,    13,    12,    13,    14,    37,   154,    17,
      18,    34,   158,    38,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    50,   296,     7,
      53,    13,    40,    41,    42,     4,   255,    11,    46,    32,
     308,    13,   146,    51,   148,    53,     0,     3,     8,    18,
       6,    39,    12,    13,    21,   100,     9,    14,    36,    21,
      38,   116,    22,   282,    38,    20,   117,    36,   119,   206,
      20,    31,    32,    33,    34,   123,    15,    16,   297,    49,
      40,    41,    42,    48,    47,     4,    46,    40,    41,    38,
     135,    51,    52,    53,    19,    14,    38,    22,   149,    18,
     151,   232,    19,    39,   155,    34,   157,   156,   139,   140,
     274,   156,    39,   164,   260,   261,   167,    39,   167,    35,
     169,    39,   173,    38,   169,   176,    52,   178,    39,   178,
      55,    56,    57,    58,    59,    60,    61,    62,   284,    39,
      54,   287,    19,    22,   290,     8,    13,   311,    13,    12,
      13,    36,   203,    36,   205,    39,    18,   303,   304,    22,
     211,    15,    21,    20,    35,    39,    38,    54,    31,    32,
      33,    34,   318,    39,     5,    15,    36,    40,    41,    42,
      38,   231,    38,    46,    35,    38,    12,   242,    51,    19,
      53,    38,   243,   244,    15,    38,   247,    38,    12,   250,
       3,   252,    12,   254,   257,   255,   257,    13,     5,    12,
      13,    38,     6,    38,    38,   265,    15,   268,    38,    22,
      23,    24,    25,    38,    16,    28,    29,    30,    31,    32,
      33,    34,   282,     6,   267,     3,     2,    40,    41,    42,
     116,   114,   120,    46,    12,    13,   296,   297,    51,     2,
      53,   316,   122,   134,    22,    23,    24,    25,   308,    18,
      28,    29,    30,    31,    32,    33,    34,     3,   136,   138,
      26,   167,    40,    41,    42,   254,    12,    13,    46,   169,
     178,   156,   137,    51,   176,    53,    22,    23,    24,    25,
     322,   155,    28,    29,    30,    31,    32,    33,    34,   250,
      -1,    -1,    -1,    -1,    40,    41,    42,   157,    -1,    -1,
      46,     4,    -1,    -1,    -1,    51,   168,    53,    -1,    12,
      13,    14,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
       8,    -1,    -1,    46,    12,    13,    -1,    -1,    51,    -1,
      53,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    40,    41,    42,     8,    -1,    -1,    46,    12,
      13,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    22,
      -1,     8,    -1,    -1,    -1,    12,    13,    -1,    31,    32,
      33,    34,    35,    -1,    -1,    22,    -1,    40,    41,    42,
      -1,    12,    13,    46,    31,    32,    33,    34,    51,    -1,
      53,    22,    -1,    40,    41,    -1,    -1,    -1,    -1,    46,
      31,    32,    33,    34,    51,    -1,    53,    12,    13,    40,
      41,    42,    -1,    -1,    -1,    46,    -1,    22,    -1,    -1,
      51,    -1,    53,    54,    -1,    -1,    31,    32,    33,    34,
      35,    -1,    12,    13,    -1,    40,    41,    42,    -1,    -1,
      -1,    46,    22,    -1,    -1,    -1,    51,    -1,    53,    -1,
      -1,    31,    32,    33,    34,    12,    13,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    22,    46,    -1,    -1,    -1,
      -1,    51,    -1,    53,    31,    32,    33,    34,    12,    13,
      -1,    38,    -1,    40,    41,    -1,    -1,    -1,    22,    46,
      -1,    -1,    -1,    -1,    51,    -1,    53,    31,    32,    33,
      34,    12,    13,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    -1,    53,
      31,    32,    33,    34,    12,    13,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      51,    -1,    53,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    51,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    12,    13,    14,    17,    18,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    40,    41,    42,    46,    51,    53,    64,    65,    66,
      67,    72,    73,    74,    75,    76,    77,    79,    80,    81,
      83,    84,    85,    86,    87,    88,    89,    91,    92,    94,
      95,    96,   100,   101,   102,   103,   104,   105,   106,   108,
     109,   110,   111,   112,   113,   114,   116,   117,   118,   119,
     120,   121,   139,    66,    67,    93,    96,    99,   100,    99,
     108,   109,   129,   130,   131,   105,    79,    13,    13,    13,
      13,   100,   121,    35,    99,   108,   122,   123,   124,   109,
       8,    52,   100,   108,   134,   135,   136,   137,   138,    54,
     122,     0,    66,     3,    37,     7,    36,    38,    78,    82,
      39,    14,    21,    20,    19,    22,    55,    56,    57,    58,
      59,    60,    61,    62,   107,    48,    49,    47,     9,    40,
      41,    10,    42,    43,    44,    45,   115,   116,     8,    34,
      50,    53,   125,    38,    38,    19,    39,    34,    38,    34,
      68,    39,    90,    90,    39,   149,    35,    39,     4,    18,
     144,   145,   109,    38,    52,   145,    39,   145,    39,    54,
       3,    75,    77,    79,   100,   100,   132,   133,    81,   101,
     103,   105,    19,    22,   106,   109,   110,   111,   112,   114,
     114,   116,   116,     8,    35,    42,   100,   140,   141,   142,
      13,    38,   100,   126,   127,   128,     3,    73,    97,    97,
     132,   131,    35,   140,    97,    13,    35,    69,    70,    71,
      11,    38,    13,   100,   124,   144,   129,   100,   100,   135,
     100,   137,    36,    39,    15,   100,   100,    36,   145,    35,
      39,   100,    38,    54,    39,     5,    15,    16,    98,    15,
      38,    38,    35,    38,    11,    38,    35,    39,    36,    12,
       3,    73,   147,    90,    19,    79,   100,   100,   100,   142,
     100,   128,    72,   148,    38,    99,    15,    38,    97,    97,
      38,    12,    12,   147,    70,   100,    38,     5,   101,   148,
       3,     6,    97,    38,    38,    97,    15,    97,    38,   147,
     148,    14,   143,   145,   146,     6,    97,    97,    38,   147,
       3,     6,   101,    98,    97,     6,   143
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    66,    66,    66,    66,    67,    67,
      67,    67,    68,    69,    69,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    75,    75,
      76,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    82,    83,    83,    83,    84,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    91,    91,    91,    91,    92,    93,    93,    94,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    98,
      98,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   113,   114,
     114,   115,   115,   115,   115,   115,   116,   116,   117,   117,
     117,   118,   118,   119,   119,   119,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   122,
     122,   122,   123,   123,   124,   124,   125,   125,   125,   126,
     126,   127,   127,   128,   128,   128,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     134,   134,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   139,   140,   140,   141,   141,   142,
     142,   142,   142,   142,   143,   143,   144,   144,   145,   145,
     146,   146,   147,   147,   147,   148,   148,   149
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     5,     7,
       8,     6,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     3,     2,     1,     3,     1,     1,     1,     1,     1,
       2,     3,     1,     1,     3,     2,     4,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     2,     3,     2,     3,     2,     3,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     4,     7,
       5,     8,     4,     7,     6,     9,     1,     4,     5,     4,
       5,     1,     1,     5,     1,     3,     3,     1,     1,     3,
       3,     1,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     3,     1,     2,     3,     3,     2,     3,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     2,     1,     3,     1,     1,     2,     3,     3,     1,
       2,     1,     3,     1,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     1,     1,     2,     1,     3,     2,     1,
       2,     2,     1,     2,     3,     2,     1,     3,     1,     1,
       1,     3,     4,     6,     7,     1,     2,     1,     3,     1,
       2,     3,     2,     2,     1,     1,     4,     5,     1,     2,
       2,     3,     1,     4,     5,     1,     2,     2
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
#line 180 "parser.y"
                 {(yyval.val)=(yyvsp[0].val); }
#line 1807 "parser.tab.c"
    break;

  case 3:
#line 183 "parser.y"
                    {(yyval.val)=(yyvsp[0].val); }
#line 1813 "parser.tab.c"
    break;

  case 5:
#line 187 "parser.y"
            { (yyval.val)=(yyvsp[0].val); }
#line 1819 "parser.tab.c"
    break;

  case 6:
#line 188 "parser.y"
                       { (yyval.val)=(yyvsp[0].val); }
#line 1825 "parser.tab.c"
    break;

  case 7:
#line 189 "parser.y"
                   { (yyval.val) = addlabel("SNIPPET"); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 1831 "parser.tab.c"
    break;

  case 8:
#line 192 "parser.y"
                                                    { (yyval.val) = addlabel("FUNCTION"); (yyvsp[-3].val) = addlabel(string("NAME\n (")+chartostring((yyvsp[-3].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-3].val)); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 1837 "parser.tab.c"
    break;

  case 9:
#line 193 "parser.y"
                                                                         { (yyval.val) = addlabel("FUNCTION"); (yyvsp[-5].val) = addlabel(string("NAME\n (")+chartostring((yyvsp[-5].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-5].val)); addedge((yyval.val),(yyvsp[-4].val)); (yyvsp[-2].val) = addlabel(string("TYPE\n (")+chartostring((yyvsp[-2].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-2].val));  addedge((yyval.val),(yyvsp[0].val)); }
#line 1843 "parser.tab.c"
    break;

  case 10:
#line 194 "parser.y"
                                                                                         { (yyval.val) = addlabel("FUNCTION"); (yyvsp[-6].val) = addlabel(string("NAME\n (")+chartostring((yyvsp[-6].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-6].val)); (yyvsp[-2].val) = addlabel(string("TYPE\n (")+chartostring((yyvsp[-2].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-2].val));  addedge((yyval.val),(yyvsp[0].val)); }
#line 1849 "parser.tab.c"
    break;

  case 11:
#line 195 "parser.y"
                                                                    { (yyval.val) = addlabel("FUNCTION"); (yyvsp[-4].val) = addlabel(string("NAME\n (")+chartostring((yyvsp[-4].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-4].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 1855 "parser.tab.c"
    break;

  case 12:
#line 198 "parser.y"
                                                     { (yyval.val) = (yyvsp[-1].val); }
#line 1861 "parser.tab.c"
    break;

  case 13:
#line 201 "parser.y"
                            { (yyval.val)=(yyvsp[0].val); }
#line 1867 "parser.tab.c"
    break;

  case 14:
#line 202 "parser.y"
                                     { (yyval.val) = addlabel("ARGUMENTS"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 1873 "parser.tab.c"
    break;

  case 15:
#line 205 "parser.y"
                   { (yyval.val)=(yyvsp[0].val); }
#line 1879 "parser.tab.c"
    break;

  case 16:
#line 206 "parser.y"
                             { (yyval.val) = addlabel(string("EQUAL\n")+"(=)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 1885 "parser.tab.c"
    break;

  case 17:
#line 209 "parser.y"
             { (yyval.val) = addlabel(string("NAME\n (")+chartostring((yyvsp[0].val)) + string(")"),true); }
#line 1891 "parser.tab.c"
    break;

  case 18:
#line 210 "parser.y"
                                {  (yyval.val) = addlabel("PARAMETER"); (yyvsp[-2].val) = addlabel(string("NAME\n (")+chartostring((yyvsp[-2].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-2].val)); (yyvsp[0].val) = addlabel(string("TYPE\n (")+chartostring((yyvsp[0].val)) + string(")"),true); addedge((yyval.val),(yyvsp[0].val)); }
#line 1897 "parser.tab.c"
    break;

  case 19:
#line 213 "parser.y"
                        {(yyval.val)=(yyvsp[0].val); }
#line 1903 "parser.tab.c"
    break;

  case 20:
#line 214 "parser.y"
                     {(yyval.val)=(yyvsp[0].val); }
#line 1909 "parser.tab.c"
    break;

  case 21:
#line 217 "parser.y"
                                                { (yyval.val) = (yyvsp[-2].val); }
#line 1915 "parser.tab.c"
    break;

  case 22:
#line 218 "parser.y"
                                           { (yyval.val)=(yyvsp[-1].val); }
#line 1921 "parser.tab.c"
    break;

  case 23:
#line 221 "parser.y"
                                { (yyval.val)=(yyvsp[0].val);  }
#line 1927 "parser.tab.c"
    break;

  case 24:
#line 222 "parser.y"
                                                            { (yyval.val) = addlabel("SMALL_STMT_LIST"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 1933 "parser.tab.c"
    break;

  case 25:
#line 225 "parser.y"
                            {(yyval.val)=(yyvsp[0].val);  }
#line 1939 "parser.tab.c"
    break;

  case 26:
#line 226 "parser.y"
                            { (yyval.val)=(yyvsp[0].val); }
#line 1945 "parser.tab.c"
    break;

  case 27:
#line 227 "parser.y"
                                { (yyval.val)=(yyvsp[0].val); }
#line 1951 "parser.tab.c"
    break;

  case 28:
#line 228 "parser.y"
                                { (yyval.val)=(yyvsp[0].val); }
#line 1957 "parser.tab.c"
    break;

  case 29:
#line 229 "parser.y"
                                {(yyval.val)=(yyvsp[0].val);  }
#line 1963 "parser.tab.c"
    break;

  case 30:
#line 232 "parser.y"
                                         {  (yyval.val) = addlabel("EXPRESSION_STMT"); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 1969 "parser.tab.c"
    break;

  case 31:
#line 233 "parser.y"
                                                      { (yyval.val) = (yyvsp[-1].val); addedge((yyval.val),(yyvsp[-2].val));  addedge((yyval.val),(yyvsp[0].val)); }
#line 1975 "parser.tab.c"
    break;

  case 32:
#line 234 "parser.y"
                                           {(yyval.val)=(yyvsp[0].val); }
#line 1981 "parser.tab.c"
    break;

  case 33:
#line 237 "parser.y"
                                               { (yyval.val)=(yyvsp[0].val); }
#line 1987 "parser.tab.c"
    break;

  case 34:
#line 238 "parser.y"
                                                                                          { (yyval.val) = addlabel(string("EQUAL\n")+"(=)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 1993 "parser.tab.c"
    break;

  case 35:
#line 241 "parser.y"
                        { (yyval.val)=(yyvsp[0].val); }
#line 1999 "parser.tab.c"
    break;

  case 36:
#line 242 "parser.y"
                                                    { (yyval.val) = addlabel(string("EQUAL\n")+"(=)");  addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2005 "parser.tab.c"
    break;

  case 37:
#line 245 "parser.y"
                                     { (yyval.val)=(yyvsp[0].val); }
#line 2011 "parser.tab.c"
    break;

  case 38:
#line 246 "parser.y"
                                                  {  (yyval.val)=(yyvsp[-1].val); }
#line 2017 "parser.tab.c"
    break;

  case 39:
#line 249 "parser.y"
                                { (yyval.val)=(yyvsp[0].val); }
#line 2023 "parser.tab.c"
    break;

  case 40:
#line 250 "parser.y"
                                                            { (yyval.val) = addlabel("EXPR_CHOICE"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2029 "parser.tab.c"
    break;

  case 41:
#line 253 "parser.y"
                    { (yyval.val)=(yyvsp[0].val); }
#line 2035 "parser.tab.c"
    break;

  case 42:
#line 254 "parser.y"
                            { (yyval.val)=(yyvsp[0].val); }
#line 2041 "parser.tab.c"
    break;

  case 43:
#line 257 "parser.y"
                            { (yyval.val) = addlabel(string("ASSIGN_OP\n (")+chartostring((yyvsp[0].val))+string(")")); }
#line 2047 "parser.tab.c"
    break;

  case 44:
#line 260 "parser.y"
                        { (yyval.val)=(yyvsp[0].val); }
#line 2053 "parser.tab.c"
    break;

  case 45:
#line 261 "parser.y"
                                {(yyval.val)=(yyvsp[0].val); }
#line 2059 "parser.tab.c"
    break;

  case 46:
#line 262 "parser.y"
                             { (yyval.val)=(yyvsp[0].val); }
#line 2065 "parser.tab.c"
    break;

  case 47:
#line 264 "parser.y"
                    { (yyval.val) = addlabel(string("BREAK\n")+"(break)",true); }
#line 2071 "parser.tab.c"
    break;

  case 48:
#line 266 "parser.y"
                            { (yyval.val) = addlabel(string("CONTINUE\n")+"(continue)",true); }
#line 2077 "parser.tab.c"
    break;

  case 49:
#line 268 "parser.y"
                        { (yyval.val) = addlabel(string("RETURN\n")+"(return)",true); }
#line 2083 "parser.tab.c"
    break;

  case 50:
#line 269 "parser.y"
                                            { (yyval.val) = addlabel("RETURN"); addedge((yyval.val),(yyvsp[0].val)); }
#line 2089 "parser.tab.c"
    break;

  case 51:
#line 272 "parser.y"
                            { (yyval.val) = addlabel("GLOBAL_NAME"); (yyvsp[0].val) = addlabel(string("NAME\n (")+chartostring((yyvsp[0].val)) + string(")"),true); addedge((yyval.val),(yyvsp[0].val),"GLOBAL") ; }
#line 2095 "parser.tab.c"
    break;

  case 52:
#line 273 "parser.y"
                                          {  (yyval.val) = addlabel("GLOBAL_NAME"); (yyvsp[-1].val) = addlabel(string("NAME\n (")+chartostring((yyvsp[-1].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-1].val),"GLOBAL") ; addedge((yyval.val),(yyvsp[0].val)); }
#line 2101 "parser.tab.c"
    break;

  case 53:
#line 275 "parser.y"
                                 { (yyval.val) = addlabel("NONLOCAL_NAME"); (yyvsp[0].val) = addlabel(string("NAME\n (")+chartostring((yyvsp[0].val)) + string(")"),true); addedge((yyval.val),(yyvsp[0].val),"NONLOCAL") ; }
#line 2107 "parser.tab.c"
    break;

  case 54:
#line 276 "parser.y"
                                            { (yyval.val) = addlabel("NONLOCAL_NAME"); (yyvsp[-1].val) = addlabel(string("NAME\n (")+chartostring((yyvsp[-1].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-1].val),"NONLOCAL") ; addedge((yyval.val),(yyvsp[0].val)); }
#line 2113 "parser.tab.c"
    break;

  case 55:
#line 279 "parser.y"
                          { (yyval.val) = addlabel(string("ASSERT\n") + "(assert)"); addedge((yyval.val),(yyvsp[0].val)); }
#line 2119 "parser.tab.c"
    break;

  case 56:
#line 280 "parser.y"
                                          { (yyval.val) = addlabel("ASSERT"); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val));  }
#line 2125 "parser.tab.c"
    break;

  case 57:
#line 282 "parser.y"
                               { (yyval.val) = addlabel(string("NAME\n (")+chartostring((yyvsp[0].val)) + string(")"),true); }
#line 2131 "parser.tab.c"
    break;

  case 58:
#line 283 "parser.y"
                                                { (yyval.val) = addlabel("NAME_LIST"); (yyvsp[-1].val) = addlabel(string("NAME\n (")+chartostring((yyvsp[-1].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2137 "parser.tab.c"
    break;

  case 59:
#line 285 "parser.y"
                            { (yyval.val)=(yyvsp[0].val); }
#line 2143 "parser.tab.c"
    break;

  case 60:
#line 286 "parser.y"
                                { (yyval.val)=(yyvsp[0].val); }
#line 2149 "parser.tab.c"
    break;

  case 61:
#line 287 "parser.y"
                            { (yyval.val)=(yyvsp[0].val); }
#line 2155 "parser.tab.c"
    break;

  case 62:
#line 288 "parser.y"
                            { (yyval.val)=(yyvsp[0].val); }
#line 2161 "parser.tab.c"
    break;

  case 63:
#line 289 "parser.y"
                            { (yyval.val)=(yyvsp[0].val); }
#line 2167 "parser.tab.c"
    break;

  case 64:
#line 290 "parser.y"
                                {(yyval.val)=(yyvsp[0].val); }
#line 2173 "parser.tab.c"
    break;

  case 65:
#line 292 "parser.y"
                                { (yyval.val) = addlabel("ASYNC"); addedge((yyval.val),(yyvsp[0].val)); }
#line 2179 "parser.tab.c"
    break;

  case 66:
#line 294 "parser.y"
                        { (yyval.val)=(yyvsp[0].val); }
#line 2185 "parser.tab.c"
    break;

  case 67:
#line 295 "parser.y"
                        { (yyval.val)=(yyvsp[0].val);  }
#line 2191 "parser.tab.c"
    break;

  case 68:
#line 298 "parser.y"
                                           { (yyval.val) = addlabel("IF"); addedge((yyval.val),(yyvsp[-2].val),"EXPRESSION"); addedge((yyval.val),(yyvsp[0].val),"SUITE"); }
#line 2197 "parser.tab.c"
    break;

  case 69:
#line 299 "parser.y"
                                                               { (yyval.val) = addlabel("IF_ELSE"); addedge((yyval.val),(yyvsp[-5].val),"IF_EXPR"); addedge((yyval.val),(yyvsp[-3].val),"IF_SUITE"); addedge((yyval.val),(yyvsp[0].val),"ELSE_SUITE"); }
#line 2203 "parser.tab.c"
    break;

  case 70:
#line 300 "parser.y"
                                                        { (yyval.val) = addlabel("IF_ELIF"); addedge((yyval.val),(yyvsp[-3].val),"EXPRESSION"); addedge((yyval.val),(yyvsp[-1].val),"IF_SUITE"); addedge((yyval.val),(yyvsp[0].val),"ELIF"); }
#line 2209 "parser.tab.c"
    break;

  case 71:
#line 301 "parser.y"
                                                                        {(yyval.val) = addlabel("IF_ELIF_ELSE"); addedge((yyval.val),(yyvsp[-6].val),"IF_EXPR"); addedge((yyval.val),(yyvsp[-4].val),"IF_SUITE"); addedge((yyval.val),(yyvsp[-3].val),"ELIF"); addedge((yyval.val),(yyvsp[0].val),"ELSE_SUITE");}
#line 2215 "parser.tab.c"
    break;

  case 72:
#line 303 "parser.y"
                                               { (yyval.val) = addlabel("WHILE"); addedge((yyval.val),(yyvsp[-2].val),"EPRESSION"); addedge((yyval.val),(yyvsp[0].val),"SUITE"); }
#line 2221 "parser.tab.c"
    break;

  case 73:
#line 304 "parser.y"
                                                                     { (yyval.val) = addlabel("WHILE"); addedge((yyval.val),(yyvsp[-5].val),"EPRESSION"); addedge((yyval.val),(yyvsp[-3].val),"SUITE"); addedge((yyval.val),(yyvsp[0].val),"SUITE");  }
#line 2227 "parser.tab.c"
    break;

  case 74:
#line 306 "parser.y"
                                                  {(yyval.val) = addlabel("FOR_IN"); addedge((yyval.val),(yyvsp[-4].val),"EPRESSION_LS"); addedge((yyval.val),(yyvsp[-2].val),"TEST_LS"); addedge((yyval.val),(yyvsp[0].val),"SUITE"); }
#line 2233 "parser.tab.c"
    break;

  case 75:
#line 307 "parser.y"
                                                                          {(yyval.val) = addlabel("FOR_IN_ELSE"); addedge((yyval.val),(yyvsp[-7].val),"EPRESSION_LS"); addedge((yyval.val),(yyvsp[-5].val),"TEST_LS"); addedge((yyval.val),(yyvsp[-3].val),"SUITE"); addedge((yyval.val),(yyvsp[0].val),"SUITE"); }
#line 2239 "parser.tab.c"
    break;

  case 76:
#line 309 "parser.y"
                    { (yyval.val)=(yyvsp[0].val); }
#line 2245 "parser.tab.c"
    break;

  case 77:
#line 310 "parser.y"
                                                { (yyval.val)=(yyvsp[-1].val); }
#line 2251 "parser.tab.c"
    break;

  case 78:
#line 311 "parser.y"
                                                        { (yyval.val)=(yyvsp[-2].val); }
#line 2257 "parser.tab.c"
    break;

  case 79:
#line 314 "parser.y"
                                            { (yyval.val)=addlabel("ELIF"); addedge((yyval.val),(yyvsp[-2].val),"EXPRESSION"); addedge((yyval.val),(yyvsp[0].val),"SUITE"); }
#line 2263 "parser.tab.c"
    break;

  case 80:
#line 315 "parser.y"
                                                        {(yyval.val)=addlabel("ELIF"); addedge((yyval.val),(yyvsp[-3].val),"EXPRESSION"); addedge((yyval.val),(yyvsp[-1].val),"SUITE"); addedge((yyval.val),(yyvsp[0].val));}
#line 2269 "parser.tab.c"
    break;

  case 81:
#line 317 "parser.y"
                        { (yyval.val)=(yyvsp[0].val); }
#line 2275 "parser.tab.c"
    break;

  case 82:
#line 319 "parser.y"
                { (yyval.val)=(yyvsp[0].val);  }
#line 2281 "parser.tab.c"
    break;

  case 83:
#line 320 "parser.y"
                                        { (yyval.val)=addlabel("IF_ELSE"); addedge((yyval.val),(yyvsp[-4].val),"OR_TEST"); addedge((yyval.val),(yyvsp[-2].val),"OR_TEST"); addedge((yyval.val),(yyvsp[0].val),"TEST"); }
#line 2287 "parser.tab.c"
    break;

  case 84:
#line 322 "parser.y"
                     { (yyval.val)=(yyvsp[0].val); }
#line 2293 "parser.tab.c"
    break;

  case 85:
#line 323 "parser.y"
                                       { (yyval.val) = addlabel(string("OR\n")+"(or)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2299 "parser.tab.c"
    break;

  case 86:
#line 325 "parser.y"
                                          { (yyval.val) = addlabel(string("OR\n")+"(or)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2305 "parser.tab.c"
    break;

  case 87:
#line 326 "parser.y"
                             { (yyval.val)=(yyvsp[0].val); }
#line 2311 "parser.tab.c"
    break;

  case 88:
#line 329 "parser.y"
                    { (yyval.val)=(yyvsp[0].val); }
#line 2317 "parser.tab.c"
    break;

  case 89:
#line 330 "parser.y"
                                        { (yyval.val) = addlabel(string("AND\n")+"(and)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2323 "parser.tab.c"
    break;

  case 90:
#line 332 "parser.y"
                                            { (yyval.val) = addlabel(string("AND\n")+"(and)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2329 "parser.tab.c"
    break;

  case 91:
#line 333 "parser.y"
                         { (yyval.val)=(yyvsp[0].val); }
#line 2335 "parser.tab.c"
    break;

  case 92:
#line 336 "parser.y"
                         { (yyval.val) = addlabel(string("NOT\n")+"(not)"); addedge((yyval.val),(yyvsp[0].val)); }
#line 2341 "parser.tab.c"
    break;

  case 93:
#line 337 "parser.y"
                            { (yyval.val)=(yyvsp[0].val);  }
#line 2347 "parser.tab.c"
    break;

  case 94:
#line 340 "parser.y"
                  { (yyval.val)=(yyvsp[0].val); }
#line 2353 "parser.tab.c"
    break;

  case 95:
#line 341 "parser.y"
                                       { (yyval.val) = (yyvsp[-1].val); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2359 "parser.tab.c"
    break;

  case 96:
#line 343 "parser.y"
                    { (yyval.val) = addlabel(string("LESS_THAN\n")+"(<)"); }
#line 2365 "parser.tab.c"
    break;

  case 97:
#line 344 "parser.y"
                    { (yyval.val) = addlabel(string("GREATER_THAN\n")+"(>)"); }
#line 2371 "parser.tab.c"
    break;

  case 98:
#line 345 "parser.y"
                    { (yyval.val) = addlabel(string("EQUAL_EQUAL\n")+"(==)"); }
#line 2377 "parser.tab.c"
    break;

  case 99:
#line 346 "parser.y"
                            { (yyval.val) = addlabel(string("GREATER_THAN_EQUAL\n")+"(>=)"); }
#line 2383 "parser.tab.c"
    break;

  case 100:
#line 347 "parser.y"
                        { (yyval.val) = addlabel(string("LESS_THAN_EQUAL\n")+"(<=)"); }
#line 2389 "parser.tab.c"
    break;

  case 101:
#line 348 "parser.y"
                        { (yyval.val) = addlabel(string("NOT_EQUAL_ARROW\n")+"(!=)"); }
#line 2395 "parser.tab.c"
    break;

  case 102:
#line 349 "parser.y"
                   { (yyval.val) = addlabel(string("NOT_EQUAL\n")+"(!=)"); }
#line 2401 "parser.tab.c"
    break;

  case 103:
#line 350 "parser.y"
            { (yyval.val) = addlabel(string("IN\n")+"(in)"); }
#line 2407 "parser.tab.c"
    break;

  case 104:
#line 351 "parser.y"
                { (yyval.val) = addlabel(string("NOT_IN\n")+"(not in)"); }
#line 2413 "parser.tab.c"
    break;

  case 105:
#line 352 "parser.y"
            { (yyval.val) = addlabel(string("IS\n")+"(is)"); }
#line 2419 "parser.tab.c"
    break;

  case 106:
#line 353 "parser.y"
                { (yyval.val) = addlabel(string("IS_NOT\n")+"(is not)"); }
#line 2425 "parser.tab.c"
    break;

  case 107:
#line 356 "parser.y"
                            { (yyval.val) = addlabel("STAR_EXPR"); (yyvsp[-1].val) = addlabel(string("MULTIPLY\n")+"(*)"); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2431 "parser.tab.c"
    break;

  case 108:
#line 359 "parser.y"
                  { (yyval.val)=(yyvsp[0].val); }
#line 2437 "parser.tab.c"
    break;

  case 109:
#line 360 "parser.y"
                                  { (yyval.val) = addlabel(string("BIT_OR\n")+"(|)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2443 "parser.tab.c"
    break;

  case 110:
#line 363 "parser.y"
                   { (yyval.val)=(yyvsp[0].val); }
#line 2449 "parser.tab.c"
    break;

  case 111:
#line 364 "parser.y"
                                      { (yyval.val) = addlabel(string("BIT_XOR\n")+"(^)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2455 "parser.tab.c"
    break;

  case 112:
#line 367 "parser.y"
                       { (yyval.val)=(yyvsp[0].val); }
#line 2461 "parser.tab.c"
    break;

  case 113:
#line 368 "parser.y"
                                         { (yyval.val) = addlabel(string("BIT_AND\n")+"(&)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2467 "parser.tab.c"
    break;

  case 114:
#line 371 "parser.y"
                         { (yyval.val)=(yyvsp[0].val); }
#line 2473 "parser.tab.c"
    break;

  case 115:
#line 372 "parser.y"
                                                 { (yyval.val) = addlabel(string("SHIFT_OPER\n (")+ chartostring((yyvsp[-1].val)) + string(")")); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2479 "parser.tab.c"
    break;

  case 116:
#line 375 "parser.y"
                 { (yyval.val)=(yyvsp[0].val); }
#line 2485 "parser.tab.c"
    break;

  case 117:
#line 376 "parser.y"
                                   { (yyval.val) = addlabel(string("PLUS\n")+"(+)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2491 "parser.tab.c"
    break;

  case 118:
#line 377 "parser.y"
                                    { (yyval.val) = addlabel(string("MINUS\n")+"(-)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2497 "parser.tab.c"
    break;

  case 119:
#line 379 "parser.y"
             {(yyval.val)=(yyvsp[0].val);}
#line 2503 "parser.tab.c"
    break;

  case 120:
#line 380 "parser.y"
                                  { (yyval.val) = (yyvsp[-1].val); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2509 "parser.tab.c"
    break;

  case 121:
#line 383 "parser.y"
                            { (yyval.val) = addlabel(string("MULTIPLY\n")+"(*)"); }
#line 2515 "parser.tab.c"
    break;

  case 122:
#line 384 "parser.y"
                            { (yyval.val) = addlabel(string("ATTHERATE\n")+"(@)");}
#line 2521 "parser.tab.c"
    break;

  case 123:
#line 385 "parser.y"
                            { (yyval.val) = addlabel(string("DIVIDE\n")+"(/)");}
#line 2527 "parser.tab.c"
    break;

  case 124:
#line 386 "parser.y"
                            { (yyval.val) = addlabel(string("REMAINDER\n")+"(%)");}
#line 2533 "parser.tab.c"
    break;

  case 125:
#line 387 "parser.y"
                               { (yyval.val) = addlabel(string("FLOOR_DIV_OP\n")+"(//)");}
#line 2539 "parser.tab.c"
    break;

  case 126:
#line 390 "parser.y"
                                    { (yyval.val) = (yyvsp[-1].val); addedge((yyval.val),(yyvsp[0].val)); }
#line 2545 "parser.tab.c"
    break;

  case 127:
#line 391 "parser.y"
                    { (yyval.val)=(yyvsp[0].val); }
#line 2551 "parser.tab.c"
    break;

  case 128:
#line 393 "parser.y"
                            {(yyval.val) = addlabel(string("PLUS\n")+"(+)",true); }
#line 2557 "parser.tab.c"
    break;

  case 129:
#line 394 "parser.y"
                            {(yyval.val) = addlabel(string("MINUS\n")+"(-)",true);  }
#line 2563 "parser.tab.c"
    break;

  case 130:
#line 395 "parser.y"
                            {(yyval.val) = addlabel(string("NEGATION\n")+"(~)",true); }
#line 2569 "parser.tab.c"
    break;

  case 131:
#line 397 "parser.y"
                        { (yyval.val)=(yyvsp[0].val); }
#line 2575 "parser.tab.c"
    break;

  case 132:
#line 398 "parser.y"
                                            { (yyval.val) = addlabel(string("POWER_OP\n")+"(**)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2581 "parser.tab.c"
    break;

  case 133:
#line 401 "parser.y"
                { (yyval.val)=(yyvsp[0].val); }
#line 2587 "parser.tab.c"
    break;

  case 134:
#line 402 "parser.y"
                            { (yyval.val) = addlabel("ATOM_EXPR"); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2593 "parser.tab.c"
    break;

  case 135:
#line 403 "parser.y"
                             {(yyval.val)=addlabel("."); addedge((yyval.val),(yyvsp[-2].val)); (yyvsp[0].val)=addlabel(string("NAME\n (")+chartostring((yyvsp[0].val)) + string(")"),true); addedge((yyval.val),(yyvsp[0].val)); }
#line 2599 "parser.tab.c"
    break;

  case 136:
#line 406 "parser.y"
                                                { (yyval.val)=(yyvsp[-1].val); }
#line 2605 "parser.tab.c"
    break;

  case 137:
#line 407 "parser.y"
                                    {(yyval.val)=addlabel("ATOM1"); }
#line 2611 "parser.tab.c"
    break;

  case 138:
#line 408 "parser.y"
                                                {(yyval.val)=(yyvsp[-1].val); }
#line 2617 "parser.tab.c"
    break;

  case 139:
#line 409 "parser.y"
                                {(yyval.val)=addlabel("ATOM1"); }
#line 2623 "parser.tab.c"
    break;

  case 140:
#line 410 "parser.y"
                                                {(yyval.val)=(yyvsp[-1].val); }
#line 2629 "parser.tab.c"
    break;

  case 141:
#line 411 "parser.y"
                                {(yyval.val)=addlabel("ATOM1");  }
#line 2635 "parser.tab.c"
    break;

  case 142:
#line 412 "parser.y"
                {(yyval.val)=addlabel(string("NAME\n (")+chartostring((yyvsp[0].val)) + string(")"),true);  }
#line 2641 "parser.tab.c"
    break;

  case 143:
#line 413 "parser.y"
                    {(yyval.val)=addlabel(string("NUMBER\n (")+chartostring((yyvsp[0].val)) + string(")"),true); }
#line 2647 "parser.tab.c"
    break;

  case 144:
#line 414 "parser.y"
                        {(yyval.val)=(yyvsp[0].val); }
#line 2653 "parser.tab.c"
    break;

  case 145:
#line 415 "parser.y"
                        {(yyval.val)=addlabel(string("ATOM_KEYWORD\n (")+chartostring((yyvsp[0].val)) + string(")"),true); }
#line 2659 "parser.tab.c"
    break;

  case 146:
#line 416 "parser.y"
                    {(yyval.val)=addlabel(string("TYPE\n (")+chartostring((yyvsp[0].val)) + string(")"),true);  }
#line 2665 "parser.tab.c"
    break;

  case 147:
#line 418 "parser.y"
                        {(yyval.val)=addlabel(string("STRING\n (")+chartostring((yyvsp[0].val)) + string(")"),true); }
#line 2671 "parser.tab.c"
    break;

  case 148:
#line 419 "parser.y"
                                    { (yyval.val)=addlabel("STRING_PLUS"); (yyvsp[-1].val)=addlabel(string("STRING\n (")+chartostring((yyvsp[-1].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val),"STR_PLUS"); }
#line 2677 "parser.tab.c"
    break;

  case 149:
#line 422 "parser.y"
                                            { (yyval.val) = addlabel("TESTLIST_COMP"); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2683 "parser.tab.c"
    break;

  case 150:
#line 423 "parser.y"
                                            { (yyval.val)=(yyvsp[0].val); }
#line 2689 "parser.tab.c"
    break;

  case 151:
#line 424 "parser.y"
                                            { (yyval.val)=(yyvsp[-1].val); }
#line 2695 "parser.tab.c"
    break;

  case 152:
#line 426 "parser.y"
                                        { (yyval.val)=(yyvsp[0].val); }
#line 2701 "parser.tab.c"
    break;

  case 153:
#line 427 "parser.y"
                                                                { (yyval.val) = addlabel("NAMED_LIST"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2707 "parser.tab.c"
    break;

  case 154:
#line 429 "parser.y"
                                  { (yyval.val)=(yyvsp[0].val); }
#line 2713 "parser.tab.c"
    break;

  case 155:
#line 430 "parser.y"
                                { (yyval.val)=(yyvsp[0].val); }
#line 2719 "parser.tab.c"
    break;

  case 156:
#line 433 "parser.y"
                                     {  (yyval.val) = addlabel("TRAILER1");  }
#line 2725 "parser.tab.c"
    break;

  case 157:
#line 434 "parser.y"
                                              {  (yyval.val) = (yyvsp[-1].val); }
#line 2731 "parser.tab.c"
    break;

  case 158:
#line 435 "parser.y"
                                                        { (yyval.val) = (yyvsp[-1].val); }
#line 2737 "parser.tab.c"
    break;

  case 159:
#line 438 "parser.y"
                                       { (yyval.val)=(yyvsp[0].val); }
#line 2743 "parser.tab.c"
    break;

  case 160:
#line 439 "parser.y"
                                               { (yyval.val)=(yyvsp[-1].val); }
#line 2749 "parser.tab.c"
    break;

  case 161:
#line 441 "parser.y"
                                    {(yyval.val)=(yyvsp[0].val); }
#line 2755 "parser.tab.c"
    break;

  case 162:
#line 442 "parser.y"
                                                            { (yyval.val) = addlabel("SUBSCRIPT_LIST"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2761 "parser.tab.c"
    break;

  case 163:
#line 444 "parser.y"
                    {(yyval.val)=(yyvsp[0].val); }
#line 2767 "parser.tab.c"
    break;

  case 164:
#line 445 "parser.y"
                    {(yyval.val)=addlabel("DELIM\n(:)",true);  }
#line 2773 "parser.tab.c"
    break;

  case 165:
#line 446 "parser.y"
                         { (yyval.val)=(yyvsp[0].val); }
#line 2779 "parser.tab.c"
    break;

  case 166:
#line 447 "parser.y"
                         {(yyval.val)=(yyvsp[-1].val); }
#line 2785 "parser.tab.c"
    break;

  case 167:
#line 448 "parser.y"
                              {(yyval.val)=addlabel("SUBSCRIPT"); addedge((yyval.val),(yyvsp[-2].val),"TEST"); addedge((yyval.val),(yyvsp[0].val),"TEST"); }
#line 2791 "parser.tab.c"
    break;

  case 168:
#line 450 "parser.y"
                                   {(yyval.val)=(yyvsp[0].val); }
#line 2797 "parser.tab.c"
    break;

  case 169:
#line 451 "parser.y"
                                        {(yyval.val)=(yyvsp[-1].val); }
#line 2803 "parser.tab.c"
    break;

  case 170:
#line 453 "parser.y"
                                            {(yyval.val)=(yyvsp[0].val); }
#line 2809 "parser.tab.c"
    break;

  case 171:
#line 454 "parser.y"
                                                                            {(yyval.val)=addlabel("EXPR_OR_STAR_LIST"); addedge((yyval.val),(yyvsp[-2].val),"EXPR_OR_STAR_list"); addedge((yyval.val),(yyvsp[0].val),"EXPR_OR_STAR"); }
#line 2815 "parser.tab.c"
    break;

  case 172:
#line 456 "parser.y"
                                {(yyval.val)=(yyvsp[0].val); }
#line 2821 "parser.tab.c"
    break;

  case 173:
#line 457 "parser.y"
                                {(yyval.val)=(yyvsp[0].val); }
#line 2827 "parser.tab.c"
    break;

  case 174:
#line 459 "parser.y"
                           {(yyval.val)=(yyvsp[0].val); }
#line 2833 "parser.tab.c"
    break;

  case 175:
#line 460 "parser.y"
                                {(yyval.val)= (yyvsp[-1].val); }
#line 2839 "parser.tab.c"
    break;

  case 176:
#line 462 "parser.y"
                            {(yyval.val)=(yyvsp[0].val); }
#line 2845 "parser.tab.c"
    break;

  case 177:
#line 463 "parser.y"
                                        {(yyval.val)=addlabel("TESTLIST_LIST"); addedge((yyval.val),(yyvsp[-2].val),"TESTLIST_list"); addedge((yyval.val),(yyvsp[0].val),"TEST"); }
#line 2851 "parser.tab.c"
    break;

  case 178:
#line 465 "parser.y"
                             {(yyval.val)=addlabel("DICTORSETMAKER"); addedge((yyval.val),(yyvsp[-1].val),"A"); addedge((yyval.val),(yyvsp[0].val),"COMP_FOR"); }
#line 2857 "parser.tab.c"
    break;

  case 179:
#line 466 "parser.y"
                          {(yyval.val)=(yyvsp[0].val); }
#line 2863 "parser.tab.c"
    break;

  case 180:
#line 467 "parser.y"
                                {(yyval.val)=(yyvsp[-1].val); }
#line 2869 "parser.tab.c"
    break;

  case 181:
#line 468 "parser.y"
                               {(yyval.val)=addlabel("DICTORSETMAKER"); addedge((yyval.val),(yyvsp[-1].val),"B"); addedge((yyval.val),(yyvsp[0].val),"COMP_FOR"); }
#line 2875 "parser.tab.c"
    break;

  case 182:
#line 469 "parser.y"
                           {(yyval.val)=(yyvsp[0].val); }
#line 2881 "parser.tab.c"
    break;

  case 183:
#line 470 "parser.y"
                                {(yyval.val)=(yyvsp[-1].val); }
#line 2887 "parser.tab.c"
    break;

  case 184:
#line 473 "parser.y"
                    { (yyval.val)=addlabel("A"); addedge((yyval.val),(yyvsp[-2].val),"TEST"); addedge((yyval.val),(yyvsp[0].val),"TEST"); }
#line 2893 "parser.tab.c"
    break;

  case 185:
#line 474 "parser.y"
                            {(yyval.val)=addlabel(string("POWER_OP\n")+"(**)"); addedge((yyval.val),(yyvsp[0].val)); }
#line 2899 "parser.tab.c"
    break;

  case 186:
#line 476 "parser.y"
             {(yyval.val)=(yyvsp[0].val); }
#line 2905 "parser.tab.c"
    break;

  case 187:
#line 477 "parser.y"
                            {(yyval.val)=addlabel("A_LIST"); addedge((yyval.val),(yyvsp[-2].val),"A_list"); addedge((yyval.val),(yyvsp[0].val),"A");}
#line 2911 "parser.tab.c"
    break;

  case 188:
#line 479 "parser.y"
         {(yyval.val)=(yyvsp[0].val); }
#line 2917 "parser.tab.c"
    break;

  case 189:
#line 480 "parser.y"
                    {(yyval.val)=(yyvsp[0].val); }
#line 2923 "parser.tab.c"
    break;

  case 190:
#line 482 "parser.y"
            {(yyval.val)=(yyvsp[0].val); }
#line 2929 "parser.tab.c"
    break;

  case 191:
#line 483 "parser.y"
                            {(yyval.val)=addlabel("B_LIST"); addedge((yyval.val),(yyvsp[-2].val),"B_list"); addedge((yyval.val),(yyvsp[0].val),"B"); }
#line 2935 "parser.tab.c"
    break;

  case 192:
#line 486 "parser.y"
                                      {(yyval.val)=addlabel("CLASS"); (yyvsp[-2].val)=addlabel(string("NAME\n (")+chartostring((yyvsp[-2].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2941 "parser.tab.c"
    break;

  case 193:
#line 487 "parser.y"
                                                                 {(yyval.val)=addlabel("CLASS"); (yyvsp[-4].val)=addlabel(string("NAME\n (")+chartostring((yyvsp[-4].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-4].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2947 "parser.tab.c"
    break;

  case 194:
#line 488 "parser.y"
                                                                         {(yyval.val)=addlabel("CLASS"); (yyvsp[-5].val)=addlabel(string("NAME\n (")+chartostring((yyvsp[-5].val)) + string(")"),true); addedge((yyval.val),(yyvsp[-5].val)); addedge((yyval.val),(yyvsp[-3].val)); addedge((yyval.val),(yyvsp[0].val));}
#line 2953 "parser.tab.c"
    break;

  case 195:
#line 491 "parser.y"
                           {(yyval.val)=(yyvsp[0].val); }
#line 2959 "parser.tab.c"
    break;

  case 196:
#line 492 "parser.y"
                                 {(yyval.val)=(yyvsp[-1].val); }
#line 2965 "parser.tab.c"
    break;

  case 197:
#line 494 "parser.y"
                            {(yyval.val)=(yyvsp[0].val); }
#line 2971 "parser.tab.c"
    break;

  case 198:
#line 495 "parser.y"
                                            { (yyval.val)=addlabel("ARGUMENT_LIST"); addedge((yyval.val),(yyvsp[-2].val),"ARG_LIST"); addedge((yyval.val),(yyvsp[0].val),"ARG"); }
#line 2977 "parser.tab.c"
    break;

  case 199:
#line 496 "parser.y"
                {(yyval.val)=(yyvsp[0].val); }
#line 2983 "parser.tab.c"
    break;

  case 200:
#line 497 "parser.y"
                        {(yyval.val)=addlabel("ARGUEMENT"); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2989 "parser.tab.c"
    break;

  case 201:
#line 498 "parser.y"
                        { (yyval.val)=addlabel(string("EQUAL\n")+"(=)"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 2995 "parser.tab.c"
    break;

  case 202:
#line 499 "parser.y"
                            { (yyval.val)=addlabel(string("POWER_OPER\n")+"(**)"); addedge((yyval.val),(yyvsp[0].val)); }
#line 3001 "parser.tab.c"
    break;

  case 203:
#line 500 "parser.y"
                        { (yyval.val)=addlabel(string("MULTIPLY\n")+"(*)"); addedge((yyval.val),(yyvsp[0].val)); }
#line 3007 "parser.tab.c"
    break;

  case 204:
#line 503 "parser.y"
                        {(yyval.val)=(yyvsp[0].val); }
#line 3013 "parser.tab.c"
    break;

  case 205:
#line 504 "parser.y"
                        {(yyval.val)=(yyvsp[0].val); }
#line 3019 "parser.tab.c"
    break;

  case 206:
#line 506 "parser.y"
                                            {(yyval.val)=addlabel("FOR_IN"); addedge((yyval.val),(yyvsp[-2].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 3025 "parser.tab.c"
    break;

  case 207:
#line 507 "parser.y"
                                                        {(yyval.val)=addlabel("FOR_IN"); addedge((yyval.val),(yyvsp[-3].val)); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 3031 "parser.tab.c"
    break;

  case 208:
#line 509 "parser.y"
                            {(yyval.val)=(yyvsp[0].val); }
#line 3037 "parser.tab.c"
    break;

  case 209:
#line 510 "parser.y"
                                {(yyval.val)=addlabel("ASYNC"); addedge((yyval.val),(yyvsp[0].val)); }
#line 3043 "parser.tab.c"
    break;

  case 210:
#line 512 "parser.y"
                            {(yyval.val)=addlabel("IF"); addedge((yyval.val),(yyvsp[0].val),"OR_TEST"); }
#line 3049 "parser.tab.c"
    break;

  case 211:
#line 513 "parser.y"
                                {(yyval.val)=addlabel("IF"); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 3055 "parser.tab.c"
    break;

  case 212:
#line 515 "parser.y"
                                {(yyval.val)=(yyvsp[0].val); }
#line 3061 "parser.tab.c"
    break;

  case 213:
#line 516 "parser.y"
                                                    {(yyval.val)=(yyvsp[-1].val); }
#line 3067 "parser.tab.c"
    break;

  case 214:
#line 517 "parser.y"
                                                            {(yyval.val)=(yyvsp[-2].val); }
#line 3073 "parser.tab.c"
    break;

  case 215:
#line 520 "parser.y"
                    {(yyval.val)=(yyvsp[0].val); }
#line 3079 "parser.tab.c"
    break;

  case 216:
#line 521 "parser.y"
                            {(yyval.val)=addlabel("MANY_STMT"); addedge((yyval.val),(yyvsp[-1].val)); addedge((yyval.val),(yyvsp[0].val)); }
#line 3085 "parser.tab.c"
    break;

  case 217:
#line 523 "parser.y"
                        {(yyval.val)=(yyvsp[0].val); }
#line 3091 "parser.tab.c"
    break;


#line 3095 "parser.tab.c"

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
#line 525 "parser.y"


void yyerror(string str){
    fprintf(stderr, "Error: %s at line number %d offending token: %s\n", str.c_str(), yylineno, yytext);
    print_ast();
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
    print_ast();
    fclose(yyin); 
    return 0;

}
