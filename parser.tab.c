/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NEWLINE = 3,                    /* NEWLINE  */
  YYSYMBOL_INDENT = 4,                     /* INDENT  */
  YYSYMBOL_DEDENT = 5,                     /* DEDENT  */
  YYSYMBOL_ASSIGN_OPERATOR = 6,            /* ASSIGN_OPERATOR  */
  YYSYMBOL_POWER_OPERATOR = 7,             /* POWER_OPERATOR  */
  YYSYMBOL_SHIFT_OPER = 8,                 /* SHIFT_OPER  */
  YYSYMBOL_FLOOR_DIV_OPER = 9,             /* FLOOR_DIV_OPER  */
  YYSYMBOL_ARROW_OPER = 10,                /* ARROW_OPER  */
  YYSYMBOL_TYPE_HINT = 11,                 /* TYPE_HINT  */
  YYSYMBOL_NAME = 12,                      /* NAME  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_ELIF = 15,                      /* ELIF  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_IN = 18,                        /* IN  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_BREAK = 22,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 23,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_CLASS = 25,                     /* CLASS  */
  YYSYMBOL_DEF = 26,                       /* DEF  */
  YYSYMBOL_GLOBAL = 27,                    /* GLOBAL  */
  YYSYMBOL_ATOM_KEYWORDS = 28,             /* ATOM_KEYWORDS  */
  YYSYMBOL_STRING = 29,                    /* STRING  */
  YYSYMBOL_NUMBER = 30,                    /* NUMBER  */
  YYSYMBOL_OPEN_BRACKET = 31,              /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_BRACKET = 32,             /* CLOSE_BRACKET  */
  YYSYMBOL_EQUAL = 33,                     /* EQUAL  */
  YYSYMBOL_SEMI_COLON = 34,                /* SEMI_COLON  */
  YYSYMBOL_COLON = 35,                     /* COLON  */
  YYSYMBOL_COMMA = 36,                     /* COMMA  */
  YYSYMBOL_PLUS = 37,                      /* PLUS  */
  YYSYMBOL_MINUS = 38,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 39,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 40,                    /* DIVIDE  */
  YYSYMBOL_REMAINDER = 41,                 /* REMAINDER  */
  YYSYMBOL_ATTHERATE = 42,                 /* ATTHERATE  */
  YYSYMBOL_NEGATION = 43,                  /* NEGATION  */
  YYSYMBOL_BIT_AND = 44,                   /* BIT_AND  */
  YYSYMBOL_BIT_OR = 45,                    /* BIT_OR  */
  YYSYMBOL_BIT_XOR = 46,                   /* BIT_XOR  */
  YYSYMBOL_DOT = 47,                       /* DOT  */
  YYSYMBOL_CURLY_OPEN = 48,                /* CURLY_OPEN  */
  YYSYMBOL_CURLY_CLOSE = 49,               /* CURLY_CLOSE  */
  YYSYMBOL_SQUARE_OPEN = 50,               /* SQUARE_OPEN  */
  YYSYMBOL_SQUARE_CLOSE = 51,              /* SQUARE_CLOSE  */
  YYSYMBOL_LESS_THAN = 52,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 53,              /* GREATER_THAN  */
  YYSYMBOL_EQUAL_EQUAL = 54,               /* EQUAL_EQUAL  */
  YYSYMBOL_GREATER_THAN_EQUAL = 55,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_LESS_THAN_EQUAL = 56,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_NOT_EQUAL_ARROW = 57,           /* NOT_EQUAL_ARROW  */
  YYSYMBOL_NOT_EQUAL = 58,                 /* NOT_EQUAL  */
  YYSYMBOL_IS = 59,                        /* IS  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_M = 61,                         /* M  */
  YYSYMBOL_N = 62,                         /* N  */
  YYSYMBOL_file = 63,                      /* file  */
  YYSYMBOL_snippet = 64,                   /* snippet  */
  YYSYMBOL_funcdef = 65,                   /* funcdef  */
  YYSYMBOL_parameters = 66,                /* parameters  */
  YYSYMBOL_typedargslist = 67,             /* typedargslist  */
  YYSYMBOL_typedarg = 68,                  /* typedarg  */
  YYSYMBOL_tfpdef = 69,                    /* tfpdef  */
  YYSYMBOL_stmt = 70,                      /* stmt  */
  YYSYMBOL_simple_stmt = 71,               /* simple_stmt  */
  YYSYMBOL_small_stmt_list = 72,           /* small_stmt_list  */
  YYSYMBOL_small_stmt = 73,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 74,                 /* expr_stmt  */
  YYSYMBOL_annassign = 75,                 /* annassign  */
  YYSYMBOL_flow_stmt = 76,                 /* flow_stmt  */
  YYSYMBOL_break_stmt = 77,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 78,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 79,               /* return_stmt  */
  YYSYMBOL_global_stmt = 80,               /* global_stmt  */
  YYSYMBOL_compound_stmt = 81,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 82,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 83,                /* while_stmt  */
  YYSYMBOL_for_stmt = 84,                  /* for_stmt  */
  YYSYMBOL_suite = 85,                     /* suite  */
  YYSYMBOL_nts_star = 86,                  /* nts_star  */
  YYSYMBOL_test = 87,                      /* test  */
  YYSYMBOL_or_test = 88,                   /* or_test  */
  YYSYMBOL_and_test_star = 89,             /* and_test_star  */
  YYSYMBOL_and_test = 90,                  /* and_test  */
  YYSYMBOL_not_test_star = 91,             /* not_test_star  */
  YYSYMBOL_not_test = 92,                  /* not_test  */
  YYSYMBOL_comparison = 93,                /* comparison  */
  YYSYMBOL_comp_op = 94,                   /* comp_op  */
  YYSYMBOL_expr = 95,                      /* expr  */
  YYSYMBOL_xor_expr = 96,                  /* xor_expr  */
  YYSYMBOL_and_expr = 97,                  /* and_expr  */
  YYSYMBOL_shift_expr = 98,                /* shift_expr  */
  YYSYMBOL_arith_expr = 99,                /* arith_expr  */
  YYSYMBOL_term = 100,                     /* term  */
  YYSYMBOL_term_choice = 101,              /* term_choice  */
  YYSYMBOL_factor = 102,                   /* factor  */
  YYSYMBOL_factor_choice = 103,            /* factor_choice  */
  YYSYMBOL_power = 104,                    /* power  */
  YYSYMBOL_atom_expr = 105,                /* atom_expr  */
  YYSYMBOL_atom = 106,                     /* atom  */
  YYSYMBOL_STRING_PLUS = 107,              /* STRING_PLUS  */
  YYSYMBOL_trailer = 108,                  /* trailer  */
  YYSYMBOL_testlist = 109,                 /* testlist  */
  YYSYMBOL_testlist_list = 110,            /* testlist_list  */
  YYSYMBOL_classdef = 111,                 /* classdef  */
  YYSYMBOL_arglist = 112,                  /* arglist  */
  YYSYMBOL_argument_list = 113,            /* argument_list  */
  YYSYMBOL_argument = 114,                 /* argument  */
  YYSYMBOL_func_body_suite = 115,          /* func_body_suite  */
  YYSYMBOL_stmt_plus = 116                 /* stmt_plus  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   437

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  243

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
       0,   133,   133,   139,   146,   151,   154,   157,   160,   165,
     169,   172,   175,   180,   186,   189,   194,   197,   202,   205,
     210,   213,   218,   221,   226,   229,   234,   237,   240,   245,
     248,   251,   254,   261,   264,   269,   272,   275,   280,   284,
     288,   291,   296,   299,   304,   307,   310,   313,   316,   321,
     327,   334,   342,   351,   361,   365,   369,   372,   375,   380,
     386,   393,   402,   409,   412,   416,   419,   424,   427,   431,
     434,   439,   442,   448,   451,   463,   466,   469,   472,   475,
     478,   481,   484,   487,   490,   493,   498,   501,   506,   509,
     514,   518,   523,   527,   532,   536,   539,   543,   547,   552,
     555,   558,   561,   564,   569,   572,   577,   580,   583,   587,
     591,   596,   600,   603,   608,   611,   614,   617,   620,   623,
     627,   630,   633,   636,   640,   643,   648,   651,   654,   659,
     662,   666,   669,   674,   677,   680,   685,   688,   692,   695,
     700,   703,   707,   710,   713,   718,   721
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NEWLINE", "INDENT",
  "DEDENT", "ASSIGN_OPERATOR", "POWER_OPERATOR", "SHIFT_OPER",
  "FLOOR_DIV_OPER", "ARROW_OPER", "TYPE_HINT", "NAME", "IF", "ELSE",
  "ELIF", "WHILE", "FOR", "IN", "AND", "OR", "NOT", "BREAK", "CONTINUE",
  "RETURN", "CLASS", "DEF", "GLOBAL", "ATOM_KEYWORDS", "STRING", "NUMBER",
  "OPEN_BRACKET", "CLOSE_BRACKET", "EQUAL", "SEMI_COLON", "COLON", "COMMA",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "REMAINDER", "ATTHERATE",
  "NEGATION", "BIT_AND", "BIT_OR", "BIT_XOR", "DOT", "CURLY_OPEN",
  "CURLY_CLOSE", "SQUARE_OPEN", "SQUARE_CLOSE", "LESS_THAN",
  "GREATER_THAN", "EQUAL_EQUAL", "GREATER_THAN_EQUAL", "LESS_THAN_EQUAL",
  "NOT_EQUAL_ARROW", "NOT_EQUAL", "IS", "$accept", "M", "N", "file",
  "snippet", "funcdef", "parameters", "typedargslist", "typedarg",
  "tfpdef", "stmt", "simple_stmt", "small_stmt_list", "small_stmt",
  "expr_stmt", "annassign", "flow_stmt", "break_stmt", "continue_stmt",
  "return_stmt", "global_stmt", "compound_stmt", "if_stmt", "while_stmt",
  "for_stmt", "suite", "nts_star", "test", "or_test", "and_test_star",
  "and_test", "not_test_star", "not_test", "comparison", "comp_op", "expr",
  "xor_expr", "and_expr", "shift_expr", "arith_expr", "term",
  "term_choice", "factor", "factor_choice", "power", "atom_expr", "atom",
  "STRING_PLUS", "trailer", "testlist", "testlist_list", "classdef",
  "arglist", "argument_list", "argument", "func_body_suite", "stmt_plus", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-188)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-71)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     122,   122,  -188,  -188,   387,  -188,     8,   387,  -188,  -188,
     387,    11,    12,    21,  -188,    28,  -188,   318,  -188,  -188,
    -188,    35,   254,    63,  -188,  -188,   122,  -188,     9,  -188,
    -188,  -188,  -188,  -188,  -188,    51,  -188,  -188,  -188,  -188,
       7,  -188,    76,    81,    86,    92,  -188,    14,    68,    71,
      78,    39,    50,  -188,     8,  -188,     3,  -188,  -188,  -188,
    -188,    88,   387,   108,  -188,  -188,   -20,    97,  -188,  -188,
    -188,  -188,    98,    96,  -188,  -188,    80,  -188,  -188,  -188,
     190,   117,   387,   387,   387,  -188,   387,   387,  -188,   118,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,   116,     8,     8,
       8,     8,     8,     8,     8,  -188,  -188,  -188,  -188,  -188,
       8,  -188,     8,   341,   128,   387,  -188,  -188,   107,   387,
     364,   220,    48,    20,  -188,   387,  -188,  -188,  -188,  -188,
    -188,  -188,   121,   135,   137,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,    50,    50,  -188,  -188,  -188,   124,   109,   125,
    -188,  -188,   111,   220,  -188,   123,   129,   131,   162,  -188,
    -188,   138,    65,    62,  -188,   141,   164,   250,  -188,   387,
     387,  -188,   387,  -188,    93,   220,   220,   220,   142,   295,
     165,   167,   250,  -188,   168,   387,   146,   179,  -188,  -188,
    -188,  -188,  -188,    95,   171,   172,  -188,   220,   295,    94,
    -188,   152,  -188,  -188,  -188,   250,   295,   153,   387,  -188,
     175,   155,  -188,  -188,   186,  -188,   250,  -188,    99,  -188,
     157,   159,   220,  -188,  -188,   191,  -188,   220,  -188,  -188,
    -188,  -188,  -188,   220,   220,    93,  -188,   106,   160,  -188,
    -188,   220,  -188
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,   123,   119,     0,     2,     0,     0,    38,    39,
      40,     0,     0,     0,   122,   124,   120,     0,   106,   107,
     108,     0,     0,     0,     4,    47,     6,    20,     0,    24,
      26,    27,    35,    36,    37,    28,    21,    44,    45,    46,
      31,    62,     0,    63,     0,    67,    72,    73,    86,    88,
      90,    92,    94,    97,     0,   105,   109,   111,   121,    48,
       7,     0,     0,     0,    71,    41,     0,     0,    42,   125,
     115,   131,     0,   129,   118,   117,     0,     1,     8,    23,
       0,     0,     0,     0,     0,    29,     0,     0,    82,     0,
      75,    76,    77,    78,    79,    80,    81,    84,     0,     0,
       0,     0,     0,     0,     0,   103,    99,   101,   102,   100,
       0,   104,     0,     0,     0,     0,   112,     2,     0,     0,
       0,     0,     0,     0,   114,   130,   116,    22,    25,    43,
      30,    32,    33,    64,    68,    83,    85,    74,    87,    89,
      91,    93,    95,    96,    98,   110,   126,   140,     0,   136,
     138,   113,     0,     0,     2,     0,     0,     0,     0,    56,
     133,    18,     0,     0,    14,    16,     0,     0,   132,     0,
       0,   127,   137,   128,    49,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,   142,     9,
      34,   141,   139,     0,    52,    54,   134,     0,   145,     0,
      19,     0,    12,    15,    17,     0,     0,     0,     0,    51,
       0,     0,   135,   146,     0,    57,     0,    10,     0,     2,
       0,     0,     0,    58,    11,     0,   143,     0,     2,     2,
      55,   144,    50,     0,     0,    59,    53,     0,     0,    60,
       2,     0,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -113,  -187,  -188,    77,  -188,  -188,  -188,    13,  -188,
    -154,     0,  -188,   119,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -148,   -37,    -1,  -188,  -188,
     136,  -188,     1,   105,  -188,    -4,   104,   114,   127,  -188,
     -86,  -188,   -48,  -188,  -188,  -188,  -188,   193,  -188,   187,
    -188,  -188,    90,  -188,    52,  -151,  -184
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    62,   193,    23,    24,    25,   123,   163,   164,   165,
      26,   159,    28,    29,    30,    85,    31,    32,    33,    34,
      35,    36,    37,    38,    39,   160,   209,    40,    41,    42,
      43,    44,    45,    46,    98,    47,    48,    49,    50,    51,
      52,   110,    53,    54,    55,    56,    57,    58,   116,    72,
      73,    59,   148,   149,   150,   189,   199
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    27,    63,    61,   153,   174,   111,   210,    64,    65,
     112,   120,    79,    82,   213,   121,    71,   142,   143,     2,
       3,    71,   218,    66,    67,   198,    27,   194,   195,   196,
     166,   202,    88,    68,   113,    89,    14,    15,    16,    17,
      83,   175,    84,    80,   198,    18,    19,   102,   237,   212,
     114,    20,   198,   115,   217,   167,    21,    15,    22,   105,
     161,   118,   144,    77,   145,   224,    90,    91,    92,    93,
      94,    95,    96,    97,   230,   181,   103,   104,    60,   232,
     162,   130,   131,   132,    74,   235,   236,    81,   134,   106,
     107,   108,   109,   242,   183,   138,    86,   214,   184,   215,
     182,   -66,   225,    78,   226,    87,   227,    -3,    -3,   207,
     208,   -70,   147,    99,   152,   233,   234,   100,   155,   147,
     238,   208,   101,   117,   168,     1,   119,   241,   122,   129,
     124,   126,   125,     2,     3,     4,   135,   136,     5,     6,
     151,   171,   154,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,   169,   -65,   -69,   170,   176,    18,
      19,   172,   173,   178,   177,    20,   179,   188,   190,   191,
      21,   147,    22,   180,   185,   186,   200,   197,   201,    27,
     161,   205,   188,   206,   204,    -3,   211,   216,   219,   221,
     222,   223,   228,   127,   229,   240,   231,   203,    27,   128,
     239,     2,     3,   137,   139,   188,    27,   220,    69,    76,
     157,     7,     8,     9,    10,   140,   188,    13,    14,    15,
      16,    17,   133,   158,   192,     0,     0,    18,    19,   141,
       0,     2,     3,    20,     0,     0,     0,     0,    21,     0,
      22,     7,     8,     9,    10,     0,     0,    13,    14,    15,
      16,    17,     0,   187,     0,     0,     0,    18,    19,     0,
       0,     2,     3,    20,     0,     2,     3,     0,    21,     0,
      22,     7,     8,     9,    10,     7,     0,    13,    14,    15,
      16,    17,    14,    15,    16,    17,     0,    18,    19,     0,
       0,    18,    19,    20,     0,     0,     0,    20,    21,     0,
      22,     0,    21,     0,    22,    75,     2,     3,     4,     0,
       0,     5,     6,     0,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,     2,
       3,     0,    18,    19,     0,     0,     0,     0,    20,     7,
       0,     0,     0,    21,     0,    22,    14,    15,    16,    17,
      70,     0,     2,     3,     0,    18,    19,     0,     0,     0,
       0,    20,     7,     0,     0,     0,    21,     0,    22,    14,
      15,    16,    17,   146,     0,     2,     3,     0,    18,    19,
       0,     0,     0,     0,    20,     7,     0,     0,     0,    21,
       0,    22,    14,    15,    16,    17,   156,     0,     2,     3,
       0,    18,    19,     0,     0,     0,     0,    20,     7,     0,
       0,     0,    21,     0,    22,    14,    15,    16,    17,     0,
       0,     0,     0,     0,    18,    19,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    21,     0,    22
};

static const yytype_int16 yycheck[] =
{
       0,     1,     6,     4,   117,   153,    54,   194,     7,    10,
       7,    31,     3,     6,   198,    35,    17,   103,   104,    11,
      12,    22,   206,    12,    12,   179,    26,   175,   176,   177,
      10,   182,    18,    12,    31,    21,    28,    29,    30,    31,
      33,   154,    35,    34,   198,    37,    38,     8,   235,   197,
      47,    43,   206,    50,   205,    35,    48,    29,    50,     9,
      12,    62,   110,     0,   112,   216,    52,    53,    54,    55,
      56,    57,    58,    59,   222,    10,    37,    38,     1,   227,
      32,    82,    83,    84,    49,   233,   234,    36,    87,    39,
      40,    41,    42,   241,    32,    99,    20,     3,    36,     5,
      35,    20,     3,    26,     5,    19,   219,    14,    15,    14,
      15,    19,   113,    45,   115,   228,   229,    46,   119,   120,
      14,    15,    44,    35,   125,     3,    18,   240,    31,    12,
      32,    51,    36,    11,    12,    13,    18,    21,    16,    17,
      12,    32,    35,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    33,    20,    19,    33,    35,    37,
      38,    36,    51,    32,    35,    43,     4,   167,   169,   170,
      48,   172,    50,    35,    33,    11,    11,    35,    11,   179,
      12,    35,   182,     4,   185,    14,    14,    35,    35,    14,
      35,     5,    35,     3,    35,    35,     5,   184,   198,    80,
     237,    11,    12,    98,   100,   205,   206,   208,    15,    22,
     120,    21,    22,    23,    24,   101,   216,    27,    28,    29,
      30,    31,    86,     3,   172,    -1,    -1,    37,    38,   102,
      -1,    11,    12,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    21,    22,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,    -1,     3,    -1,    -1,    -1,    37,    38,    -1,
      -1,    11,    12,    43,    -1,    11,    12,    -1,    48,    -1,
      50,    21,    22,    23,    24,    21,    -1,    27,    28,    29,
      30,    31,    28,    29,    30,    31,    -1,    37,    38,    -1,
      -1,    37,    38,    43,    -1,    -1,    -1,    43,    48,    -1,
      50,    -1,    48,    -1,    50,    51,    11,    12,    13,    -1,
      -1,    16,    17,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    11,
      12,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,    21,
      -1,    -1,    -1,    48,    -1,    50,    28,    29,    30,    31,
      32,    -1,    11,    12,    -1,    37,    38,    -1,    -1,    -1,
      -1,    43,    21,    -1,    -1,    -1,    48,    -1,    50,    28,
      29,    30,    31,    32,    -1,    11,    12,    -1,    37,    38,
      -1,    -1,    -1,    -1,    43,    21,    -1,    -1,    -1,    48,
      -1,    50,    28,    29,    30,    31,    32,    -1,    11,    12,
      -1,    37,    38,    -1,    -1,    -1,    -1,    43,    21,    -1,
      -1,    -1,    48,    -1,    50,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    11,    12,    13,    16,    17,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    37,    38,
      43,    48,    50,    63,    64,    65,    70,    71,    72,    73,
      74,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      87,    88,    89,    90,    91,    92,    93,    95,    96,    97,
      98,    99,   100,   102,   103,   104,   105,   106,   107,   111,
      64,    87,    61,    95,    92,    87,    12,    12,    12,   107,
      32,    87,   109,   110,    49,    51,   109,     0,    64,     3,
      34,    36,     6,    33,    35,    75,    20,    19,    18,    21,
      52,    53,    54,    55,    56,    57,    58,    59,    94,    45,
      46,    44,     8,    37,    38,     9,    39,    40,    41,    42,
     101,   102,     7,    31,    47,    50,   108,    35,    87,    18,
      31,    35,    31,    66,    32,    36,    51,     3,    73,    12,
      87,    87,    87,    90,    92,    18,    21,    93,    95,    96,
      97,    98,   100,   100,   102,   102,    32,    87,   112,   113,
     114,    12,    87,    61,    35,    87,    32,   112,     3,    71,
      85,    12,    32,    67,    68,    69,    10,    35,    87,    33,
      33,    32,    36,    51,    85,    61,    35,    35,    32,     4,
      35,    10,    35,    32,    36,    33,    11,     3,    71,   115,
      87,    87,   114,    62,    85,    85,    85,    35,    70,   116,
      11,    11,   115,    68,    87,    35,     4,    14,    15,    86,
      62,    14,    85,   116,     3,     5,    35,   115,   116,    35,
      87,    14,    35,     5,   115,     3,     5,    61,    35,    35,
      85,     5,    85,    61,    61,    85,    85,    62,    14,    86,
      35,    61,    85
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    64,    64,    64,    65,
      65,    65,    65,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    73,    74,
      74,    74,    74,    75,    75,    76,    76,    76,    77,    78,
      79,    79,    80,    80,    81,    81,    81,    81,    81,    82,
      82,    82,    83,    83,    84,    84,    85,    85,    85,    86,
      86,    86,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    95,    95,    96,    96,
      97,    97,    98,    98,    99,    99,    99,   100,   100,   101,
     101,   101,   101,   101,   102,   102,   103,   103,   103,   104,
     104,   105,   105,   105,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   107,   107,   108,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   112,   112,   113,   113,
     114,   114,   115,   115,   115,   116,   116
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     2,     2,     5,
       7,     8,     6,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     3,     2,     1,     3,     1,     1,     1,     2,
       3,     1,     3,     2,     4,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     1,     1,     1,     1,     5,
      10,     7,     6,    11,     6,     9,     1,     4,     5,     5,
       7,    10,     1,     1,     3,     3,     1,     1,     3,     3,
       1,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     3,     2,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     3,     1,
       2,     1,     3,     4,     6,     7,     1,     2,     1,     3,
       1,     3,     1,     4,     5,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* M: %empty  */
#line 133 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal M");
        (yyval.elem)->ins = instCount+1;
}
#line 1463 "parser.tab.c"
    break;

  case 3: /* N: %empty  */
#line 139 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal N");
        (yyval.elem)->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
#line 1473 "parser.tab.c"
    break;

  case 4: /* file: snippet  */
#line 146 "parser.y"
              {
                (yyval.elem) = (yyvsp[0].elem);
 }
#line 1481 "parser.tab.c"
    break;

  case 5: /* snippet: NEWLINE  */
#line 151 "parser.y"
                 {
       
    }
#line 1489 "parser.tab.c"
    break;

  case 6: /* snippet: stmt  */
#line 154 "parser.y"
            { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1497 "parser.tab.c"
    break;

  case 7: /* snippet: NEWLINE snippet  */
#line 157 "parser.y"
                       { 
        
    }
#line 1505 "parser.tab.c"
    break;

  case 8: /* snippet: stmt snippet  */
#line 160 "parser.y"
                   {  
        
    }
#line 1513 "parser.tab.c"
    break;

  case 9: /* funcdef: DEF NAME parameters COLON func_body_suite  */
#line 165 "parser.y"
                                                    {  
            

        }
#line 1522 "parser.tab.c"
    break;

  case 10: /* funcdef: DEF NAME parameters ARROW_OPER TYPE_HINT COLON func_body_suite  */
#line 169 "parser.y"
                                                                         {  
            
        }
#line 1530 "parser.tab.c"
    break;

  case 11: /* funcdef: DEF NAME OPEN_BRACKET CLOSE_BRACKET ARROW_OPER TYPE_HINT COLON func_body_suite  */
#line 172 "parser.y"
                                                                                         {  
            
        }
#line 1538 "parser.tab.c"
    break;

  case 12: /* funcdef: DEF NAME OPEN_BRACKET CLOSE_BRACKET COLON func_body_suite  */
#line 175 "parser.y"
                                                                    {
            
        }
#line 1546 "parser.tab.c"
    break;

  case 13: /* parameters: OPEN_BRACKET typedargslist CLOSE_BRACKET  */
#line 180 "parser.y"
                                                     {  
            
            
        }
#line 1555 "parser.tab.c"
    break;

  case 14: /* typedargslist: typedarg  */
#line 186 "parser.y"
                            {  
            
        }
#line 1563 "parser.tab.c"
    break;

  case 15: /* typedargslist: typedargslist COMMA typedarg  */
#line 189 "parser.y"
                                         {  
            
        }
#line 1571 "parser.tab.c"
    break;

  case 16: /* typedarg: tfpdef  */
#line 194 "parser.y"
                   {  
            
        }
#line 1579 "parser.tab.c"
    break;

  case 17: /* typedarg: tfpdef EQUAL test  */
#line 197 "parser.y"
                            {  
            
        }
#line 1587 "parser.tab.c"
    break;

  case 18: /* tfpdef: NAME  */
#line 202 "parser.y"
             {  
            
        }
#line 1595 "parser.tab.c"
    break;

  case 19: /* tfpdef: NAME COLON TYPE_HINT  */
#line 205 "parser.y"
                               {  
                
        }
#line 1603 "parser.tab.c"
    break;

  case 20: /* stmt: simple_stmt  */
#line 210 "parser.y"
                        { 
                (yyval.elem)=(yyvsp[0].elem);
        }
#line 1611 "parser.tab.c"
    break;

  case 21: /* stmt: compound_stmt  */
#line 213 "parser.y"
                            { 
             (yyval.elem)=(yyvsp[0].elem); 
        }
#line 1619 "parser.tab.c"
    break;

  case 22: /* simple_stmt: small_stmt_list SEMI_COLON NEWLINE  */
#line 218 "parser.y"
                                                {  
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 1627 "parser.tab.c"
    break;

  case 23: /* simple_stmt: small_stmt_list NEWLINE  */
#line 221 "parser.y"
                                   {  
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 1635 "parser.tab.c"
    break;

  case 24: /* small_stmt_list: small_stmt  */
#line 226 "parser.y"
                                {   
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1643 "parser.tab.c"
    break;

  case 25: /* small_stmt_list: small_stmt_list SEMI_COLON small_stmt  */
#line 229 "parser.y"
                                                     {  
           
        }
#line 1651 "parser.tab.c"
    break;

  case 26: /* small_stmt: expr_stmt  */
#line 234 "parser.y"
                            {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1659 "parser.tab.c"
    break;

  case 27: /* small_stmt: flow_stmt  */
#line 237 "parser.y"
                        {  
           
        }
#line 1667 "parser.tab.c"
    break;

  case 28: /* small_stmt: global_stmt  */
#line 240 "parser.y"
                            {  
            
        }
#line 1675 "parser.tab.c"
    break;

  case 29: /* expr_stmt: test annassign  */
#line 245 "parser.y"
                           {   
           
        }
#line 1683 "parser.tab.c"
    break;

  case 30: /* expr_stmt: test ASSIGN_OPERATOR test  */
#line 248 "parser.y"
                                    {  
            
        }
#line 1691 "parser.tab.c"
    break;

  case 31: /* expr_stmt: test  */
#line 251 "parser.y"
              {

        }
#line 1699 "parser.tab.c"
    break;

  case 32: /* expr_stmt: test EQUAL test  */
#line 254 "parser.y"
                         {
                (yyval.elem)=create_node(4, "expr_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr,"");
        }
#line 1709 "parser.tab.c"
    break;

  case 33: /* annassign: COLON test  */
#line 261 "parser.y"
                        {  
            
        }
#line 1717 "parser.tab.c"
    break;

  case 34: /* annassign: COLON test EQUAL test  */
#line 264 "parser.y"
                                  {  
            
        }
#line 1725 "parser.tab.c"
    break;

  case 35: /* flow_stmt: break_stmt  */
#line 269 "parser.y"
                        {  
            
        }
#line 1733 "parser.tab.c"
    break;

  case 36: /* flow_stmt: continue_stmt  */
#line 272 "parser.y"
                            {  
            
        }
#line 1741 "parser.tab.c"
    break;

  case 37: /* flow_stmt: return_stmt  */
#line 275 "parser.y"
                         {  
            
        }
#line 1749 "parser.tab.c"
    break;

  case 38: /* break_stmt: BREAK  */
#line 280 "parser.y"
                    {  
            
        }
#line 1757 "parser.tab.c"
    break;

  case 39: /* continue_stmt: CONTINUE  */
#line 284 "parser.y"
                            {  
            
        }
#line 1765 "parser.tab.c"
    break;

  case 40: /* return_stmt: RETURN  */
#line 288 "parser.y"
                        {  
            
        }
#line 1773 "parser.tab.c"
    break;

  case 41: /* return_stmt: RETURN test  */
#line 291 "parser.y"
                          {  
           
        }
#line 1781 "parser.tab.c"
    break;

  case 42: /* global_stmt: GLOBAL NAME  */
#line 296 "parser.y"
                            {  
            
        }
#line 1789 "parser.tab.c"
    break;

  case 43: /* global_stmt: global_stmt COMMA NAME  */
#line 299 "parser.y"
                                {   
            
        }
#line 1797 "parser.tab.c"
    break;

  case 44: /* compound_stmt: if_stmt  */
#line 304 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);  
        }
#line 1805 "parser.tab.c"
    break;

  case 45: /* compound_stmt: while_stmt  */
#line 307 "parser.y"
                       {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1813 "parser.tab.c"
    break;

  case 46: /* compound_stmt: for_stmt  */
#line 310 "parser.y"
                       {  
            
        }
#line 1821 "parser.tab.c"
    break;

  case 47: /* compound_stmt: funcdef  */
#line 313 "parser.y"
                       {  
            
        }
#line 1829 "parser.tab.c"
    break;

  case 48: /* compound_stmt: classdef  */
#line 316 "parser.y"
                       {  
           
        }
#line 1837 "parser.tab.c"
    break;

  case 49: /* if_stmt: IF test COLON M suite  */
#line 321 "parser.y"
                                    {  
           (yyval.elem)=create_node(6, "if_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
           (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
           backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
           (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);
        }
#line 1848 "parser.tab.c"
    break;

  case 50: /* if_stmt: IF test COLON M suite N ELSE COLON M suite  */
#line 327 "parser.y"
                                                       {  
            (yyval.elem) = create_node(11, "if_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            vector<int> temp = merge((yyvsp[-5].elem)->nextlist, (yyvsp[-4].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);
        }
#line 1860 "parser.tab.c"
    break;

  case 51: /* if_stmt: IF test COLON M suite N nts_star  */
#line 334 "parser.y"
                                              {  
            (yyval.elem) = create_node(8, "if_elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);      //$7->ins is needed in place of $7->nextlist
            vector<int> temp = merge((yyvsp[-2].elem)->nextlist, (yyvsp[-1].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);
        }
#line 1872 "parser.tab.c"
    break;

  case 52: /* while_stmt: WHILE M test COLON M suite  */
#line 342 "parser.y"
                                         {  
            (yyval.elem) = create_node(7, "while_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            // cout<<"check "<<$6->nextlist.size()<<endl;
            backpatch((yyvsp[0].elem)->nextlist, (yyvsp[-4].elem)->ins);
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = (yyvsp[-3].elem)->falselist;
            create_ins(0, "goto", to_string((yyvsp[-4].elem)->ins), "", "");
        }
#line 1886 "parser.tab.c"
    break;

  case 53: /* while_stmt: WHILE M test COLON M suite N ELSE COLON M suite  */
#line 351 "parser.y"
                                                           {   
                (yyval.elem) = create_node(12, "while_else_stmt", (yyvsp[-10].elem), (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-9].elem)->ins;
                backpatch((yyvsp[-4].elem)->nextlist, (yyvsp[-9].elem)->ins);
                backpatch((yyvsp[-5].elem)->nextlist, (yyvsp[-9].elem)->ins);
                backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
                backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
                (yyval.elem)->nextlist = merge((yyvsp[-4].elem)->nextlist, (yyvsp[0].elem)->nextlist); //verify
        }
#line 1900 "parser.tab.c"
    break;

  case 54: /* for_stmt: FOR expr IN test COLON suite  */
#line 361 "parser.y"
                                          { 
            

        }
#line 1909 "parser.tab.c"
    break;

  case 55: /* for_stmt: FOR expr IN test COLON suite ELSE COLON suite  */
#line 365 "parser.y"
                                                          { 
            
        }
#line 1917 "parser.tab.c"
    break;

  case 56: /* suite: simple_stmt  */
#line 369 "parser.y"
                    { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1925 "parser.tab.c"
    break;

  case 57: /* suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 372 "parser.y"
                                            { 
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 1933 "parser.tab.c"
    break;

  case 58: /* suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 375 "parser.y"
                                                    { 
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 1941 "parser.tab.c"
    break;

  case 59: /* nts_star: ELIF test COLON M suite  */
#line 380 "parser.y"
                                    {  
            (yyval.elem)=create_node(6, "elif_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);
        }
#line 1952 "parser.tab.c"
    break;

  case 60: /* nts_star: ELIF test COLON M suite N nts_star  */
#line 386 "parser.y"
                                              {  
            (yyval.elem) = create_node(8, "elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-5].elem)->ins;
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist));
        }
#line 1964 "parser.tab.c"
    break;

  case 61: /* nts_star: ELIF test COLON M suite N ELSE COLON M suite  */
#line 393 "parser.y"
                                                        {  
            (yyval.elem) = create_node(11, "elif_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-8].elem)->ins;
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-5].elem)->nextlist, merge((yyvsp[-4].elem)->nextlist,(yyvsp[0].elem)->nextlist));
        }
#line 1976 "parser.tab.c"
    break;

  case 62: /* test: or_test  */
#line 402 "parser.y"
                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1984 "parser.tab.c"
    break;

  case 63: /* or_test: and_test  */
#line 409 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1992 "parser.tab.c"
    break;

  case 64: /* or_test: and_test_star OR and_test  */
#line 412 "parser.y"
                                       {  
            
        }
#line 2000 "parser.tab.c"
    break;

  case 65: /* and_test_star: and_test_star OR and_test  */
#line 416 "parser.y"
                                          {
            
        }
#line 2008 "parser.tab.c"
    break;

  case 66: /* and_test_star: and_test  */
#line 419 "parser.y"
                     { 
                
        }
#line 2016 "parser.tab.c"
    break;

  case 67: /* and_test: not_test  */
#line 424 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2024 "parser.tab.c"
    break;

  case 68: /* and_test: not_test_star AND not_test  */
#line 427 "parser.y"
                                        {  
            
        }
#line 2032 "parser.tab.c"
    break;

  case 69: /* not_test_star: not_test_star AND not_test  */
#line 431 "parser.y"
                                            { 
            
        }
#line 2040 "parser.tab.c"
    break;

  case 70: /* not_test_star: not_test  */
#line 434 "parser.y"
                     { 
            
        }
#line 2048 "parser.tab.c"
    break;

  case 71: /* not_test: NOT not_test  */
#line 439 "parser.y"
                         { 
            
        }
#line 2056 "parser.tab.c"
    break;

  case 72: /* not_test: comparison  */
#line 442 "parser.y"
                        { 
            (yyval.elem)=(yyvsp[0].elem);
            
        }
#line 2065 "parser.tab.c"
    break;

  case 73: /* comparison: expr  */
#line 448 "parser.y"
                  {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2073 "parser.tab.c"
    break;

  case 74: /* comparison: expr comp_op comparison  */
#line 451 "parser.y"
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
#line 2088 "parser.tab.c"
    break;

  case 75: /* comp_op: LESS_THAN  */
#line 463 "parser.y"
                    {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2096 "parser.tab.c"
    break;

  case 76: /* comp_op: GREATER_THAN  */
#line 466 "parser.y"
                    { 
       (yyval.elem) = (yyvsp[0].elem);
     }
#line 2104 "parser.tab.c"
    break;

  case 77: /* comp_op: EQUAL_EQUAL  */
#line 469 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2112 "parser.tab.c"
    break;

  case 78: /* comp_op: GREATER_THAN_EQUAL  */
#line 472 "parser.y"
                            { 
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2120 "parser.tab.c"
    break;

  case 79: /* comp_op: LESS_THAN_EQUAL  */
#line 475 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2128 "parser.tab.c"
    break;

  case 80: /* comp_op: NOT_EQUAL_ARROW  */
#line 478 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
      }
#line 2136 "parser.tab.c"
    break;

  case 81: /* comp_op: NOT_EQUAL  */
#line 481 "parser.y"
                   {
       (yyval.elem) = (yyvsp[0].elem);
     }
#line 2144 "parser.tab.c"
    break;

  case 82: /* comp_op: IN  */
#line 484 "parser.y"
            {  
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2152 "parser.tab.c"
    break;

  case 83: /* comp_op: NOT IN  */
#line 487 "parser.y"
                { 
        (yyval.elem) = create_node(3, "NOT IN", (yyvsp[-1].elem), (yyvsp[0].elem));
     }
#line 2160 "parser.tab.c"
    break;

  case 84: /* comp_op: IS  */
#line 490 "parser.y"
            { 
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2168 "parser.tab.c"
    break;

  case 85: /* comp_op: IS NOT  */
#line 493 "parser.y"
                { 
        (yyval.elem) = create_node(3, "IS NOT", (yyvsp[-1].elem), (yyvsp[0].elem));
     }
#line 2176 "parser.tab.c"
    break;

  case 86: /* expr: xor_expr  */
#line 498 "parser.y"
                  { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2184 "parser.tab.c"
    break;

  case 87: /* expr: xor_expr BIT_OR expr  */
#line 501 "parser.y"
                                  {  
            
        }
#line 2192 "parser.tab.c"
    break;

  case 88: /* xor_expr: and_expr  */
#line 506 "parser.y"
                   { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2200 "parser.tab.c"
    break;

  case 89: /* xor_expr: and_expr BIT_XOR xor_expr  */
#line 509 "parser.y"
                                       {  
            
        }
#line 2208 "parser.tab.c"
    break;

  case 90: /* and_expr: shift_expr  */
#line 514 "parser.y"
                       { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2217 "parser.tab.c"
    break;

  case 91: /* and_expr: shift_expr BIT_AND and_expr  */
#line 518 "parser.y"
                                        {  
            
        }
#line 2225 "parser.tab.c"
    break;

  case 92: /* shift_expr: arith_expr  */
#line 523 "parser.y"
                         { 
            (yyval.elem) = (yyvsp[0].elem);
                
            }
#line 2234 "parser.tab.c"
    break;

  case 93: /* shift_expr: arith_expr SHIFT_OPER shift_expr  */
#line 527 "parser.y"
                                                 { 
                
             }
#line 2242 "parser.tab.c"
    break;

  case 94: /* arith_expr: term  */
#line 532 "parser.y"
                 { 
            (yyval.elem) = (yyvsp[0].elem);
                
            }
#line 2251 "parser.tab.c"
    break;

  case 95: /* arith_expr: arith_expr PLUS term  */
#line 536 "parser.y"
                                   { 
                
            }
#line 2259 "parser.tab.c"
    break;

  case 96: /* arith_expr: arith_expr MINUS term  */
#line 539 "parser.y"
                                    { 
                
             }
#line 2267 "parser.tab.c"
    break;

  case 97: /* term: factor  */
#line 543 "parser.y"
             {
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2276 "parser.tab.c"
    break;

  case 98: /* term: term term_choice factor  */
#line 547 "parser.y"
                                  {
            
         }
#line 2284 "parser.tab.c"
    break;

  case 99: /* term_choice: MULTIPLY  */
#line 552 "parser.y"
                            { 
            
        }
#line 2292 "parser.tab.c"
    break;

  case 100: /* term_choice: ATTHERATE  */
#line 555 "parser.y"
                        { 
            
        }
#line 2300 "parser.tab.c"
    break;

  case 101: /* term_choice: DIVIDE  */
#line 558 "parser.y"
                        { 
            
        }
#line 2308 "parser.tab.c"
    break;

  case 102: /* term_choice: REMAINDER  */
#line 561 "parser.y"
                        { 
           
        }
#line 2316 "parser.tab.c"
    break;

  case 103: /* term_choice: FLOOR_DIV_OPER  */
#line 564 "parser.y"
                           { 
            
        }
#line 2324 "parser.tab.c"
    break;

  case 104: /* factor: factor_choice factor  */
#line 569 "parser.y"
                                    {  
            
        }
#line 2332 "parser.tab.c"
    break;

  case 105: /* factor: power  */
#line 572 "parser.y"
                    { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2341 "parser.tab.c"
    break;

  case 106: /* factor_choice: PLUS  */
#line 577 "parser.y"
                            {
            
        }
#line 2349 "parser.tab.c"
    break;

  case 107: /* factor_choice: MINUS  */
#line 580 "parser.y"
                     { 
            
        }
#line 2357 "parser.tab.c"
    break;

  case 108: /* factor_choice: NEGATION  */
#line 583 "parser.y"
                     { 
            
        }
#line 2365 "parser.tab.c"
    break;

  case 109: /* power: atom_expr  */
#line 587 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2374 "parser.tab.c"
    break;

  case 110: /* power: atom_expr POWER_OPERATOR factor  */
#line 591 "parser.y"
                                            { 
            
        }
#line 2382 "parser.tab.c"
    break;

  case 111: /* atom_expr: atom  */
#line 596 "parser.y"
                {  
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2391 "parser.tab.c"
    break;

  case 112: /* atom_expr: atom_expr trailer  */
#line 600 "parser.y"
                            {  
            
        }
#line 2399 "parser.tab.c"
    break;

  case 113: /* atom_expr: atom_expr DOT NAME  */
#line 603 "parser.y"
                             { 
            
        }
#line 2407 "parser.tab.c"
    break;

  case 114: /* atom: OPEN_BRACKET testlist CLOSE_BRACKET  */
#line 608 "parser.y"
                                           { 
        (yyval.elem)=(yyvsp[-1].elem);
    }
#line 2415 "parser.tab.c"
    break;

  case 115: /* atom: OPEN_BRACKET CLOSE_BRACKET  */
#line 611 "parser.y"
                                    {
        
    }
#line 2423 "parser.tab.c"
    break;

  case 116: /* atom: SQUARE_OPEN testlist SQUARE_CLOSE  */
#line 614 "parser.y"
                                           { 
        
    }
#line 2431 "parser.tab.c"
    break;

  case 117: /* atom: SQUARE_OPEN SQUARE_CLOSE  */
#line 617 "parser.y"
                                {
        
     }
#line 2439 "parser.tab.c"
    break;

  case 118: /* atom: CURLY_OPEN CURLY_CLOSE  */
#line 620 "parser.y"
                                { 
        
     }
#line 2447 "parser.tab.c"
    break;

  case 119: /* atom: NAME  */
#line 623 "parser.y"
                {
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
     }
#line 2456 "parser.tab.c"
    break;

  case 120: /* atom: NUMBER  */
#line 627 "parser.y"
                    { 
        
    }
#line 2464 "parser.tab.c"
    break;

  case 121: /* atom: STRING_PLUS  */
#line 630 "parser.y"
                        { 
       
    }
#line 2472 "parser.tab.c"
    break;

  case 122: /* atom: ATOM_KEYWORDS  */
#line 633 "parser.y"
                        { 
        
    }
#line 2480 "parser.tab.c"
    break;

  case 123: /* atom: TYPE_HINT  */
#line 636 "parser.y"
                    { 
        
     }
#line 2488 "parser.tab.c"
    break;

  case 124: /* STRING_PLUS: STRING  */
#line 640 "parser.y"
                        {
            
        }
#line 2496 "parser.tab.c"
    break;

  case 125: /* STRING_PLUS: STRING STRING_PLUS  */
#line 643 "parser.y"
                                { 
            
        }
#line 2504 "parser.tab.c"
    break;

  case 126: /* trailer: OPEN_BRACKET CLOSE_BRACKET  */
#line 648 "parser.y"
                                     { 
            
        }
#line 2512 "parser.tab.c"
    break;

  case 127: /* trailer: OPEN_BRACKET arglist CLOSE_BRACKET  */
#line 651 "parser.y"
                                              {
            
         }
#line 2520 "parser.tab.c"
    break;

  case 128: /* trailer: SQUARE_OPEN test SQUARE_CLOSE  */
#line 654 "parser.y"
                                               {
            
         }
#line 2528 "parser.tab.c"
    break;

  case 129: /* testlist: testlist_list  */
#line 659 "parser.y"
                           { 
            
        }
#line 2536 "parser.tab.c"
    break;

  case 130: /* testlist: testlist_list COMMA  */
#line 662 "parser.y"
                                {
            
         }
#line 2544 "parser.tab.c"
    break;

  case 131: /* testlist_list: test  */
#line 666 "parser.y"
                            {
            
        }
#line 2552 "parser.tab.c"
    break;

  case 132: /* testlist_list: testlist_list COMMA test  */
#line 669 "parser.y"
                                    { 
            
        }
#line 2560 "parser.tab.c"
    break;

  case 133: /* classdef: CLASS NAME COLON suite  */
#line 674 "parser.y"
                                      { 
            
        }
#line 2568 "parser.tab.c"
    break;

  case 134: /* classdef: CLASS NAME OPEN_BRACKET CLOSE_BRACKET COLON suite  */
#line 677 "parser.y"
                                                                 { 
            
        }
#line 2576 "parser.tab.c"
    break;

  case 135: /* classdef: CLASS NAME OPEN_BRACKET arglist CLOSE_BRACKET COLON suite  */
#line 680 "parser.y"
                                                                         { 
           
        }
#line 2584 "parser.tab.c"
    break;

  case 136: /* arglist: argument_list  */
#line 685 "parser.y"
                           { 
            
        }
#line 2592 "parser.tab.c"
    break;

  case 137: /* arglist: argument_list COMMA  */
#line 688 "parser.y"
                                 { 
           
        }
#line 2600 "parser.tab.c"
    break;

  case 138: /* argument_list: argument  */
#line 692 "parser.y"
                            { 
            
        }
#line 2608 "parser.tab.c"
    break;

  case 139: /* argument_list: argument_list COMMA argument  */
#line 695 "parser.y"
                                        { 
            
        }
#line 2616 "parser.tab.c"
    break;

  case 140: /* argument: test  */
#line 700 "parser.y"
                {
               
        }
#line 2624 "parser.tab.c"
    break;

  case 141: /* argument: test EQUAL test  */
#line 703 "parser.y"
                            { 
            
        }
#line 2632 "parser.tab.c"
    break;

  case 142: /* func_body_suite: simple_stmt  */
#line 707 "parser.y"
                                { 
            
        }
#line 2640 "parser.tab.c"
    break;

  case 143: /* func_body_suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 710 "parser.y"
                                            { 
            
        }
#line 2648 "parser.tab.c"
    break;

  case 144: /* func_body_suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 713 "parser.y"
                                                    { 
            
        }
#line 2656 "parser.tab.c"
    break;

  case 145: /* stmt_plus: stmt  */
#line 718 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2664 "parser.tab.c"
    break;

  case 146: /* stmt_plus: stmt stmt_plus  */
#line 721 "parser.y"
                            { 
            (yyval.elem)=create_node(3,"stmt_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
        }
#line 2673 "parser.tab.c"
    break;


#line 2677 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 726 "parser.y"


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
