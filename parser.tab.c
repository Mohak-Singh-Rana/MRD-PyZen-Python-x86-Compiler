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
  YYSYMBOL_eq_testlist_star_expr_plus = 75, /* eq_testlist_star_expr_plus  */
  YYSYMBOL_annassign = 76,                 /* annassign  */
  YYSYMBOL_flow_stmt = 77,                 /* flow_stmt  */
  YYSYMBOL_break_stmt = 78,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 79,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 80,               /* return_stmt  */
  YYSYMBOL_global_stmt = 81,               /* global_stmt  */
  YYSYMBOL_comma_name_star = 82,           /* comma_name_star  */
  YYSYMBOL_compound_stmt = 83,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 84,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 85,                /* while_stmt  */
  YYSYMBOL_for_stmt = 86,                  /* for_stmt  */
  YYSYMBOL_suite = 87,                     /* suite  */
  YYSYMBOL_nts_star = 88,                  /* nts_star  */
  YYSYMBOL_test = 89,                      /* test  */
  YYSYMBOL_or_test = 90,                   /* or_test  */
  YYSYMBOL_and_test_star = 91,             /* and_test_star  */
  YYSYMBOL_and_test = 92,                  /* and_test  */
  YYSYMBOL_not_test_star = 93,             /* not_test_star  */
  YYSYMBOL_not_test = 94,                  /* not_test  */
  YYSYMBOL_comparison = 95,                /* comparison  */
  YYSYMBOL_comp_op = 96,                   /* comp_op  */
  YYSYMBOL_expr = 97,                      /* expr  */
  YYSYMBOL_xor_expr = 98,                  /* xor_expr  */
  YYSYMBOL_and_expr = 99,                  /* and_expr  */
  YYSYMBOL_shift_expr = 100,               /* shift_expr  */
  YYSYMBOL_arith_expr = 101,               /* arith_expr  */
  YYSYMBOL_term = 102,                     /* term  */
  YYSYMBOL_term_choice = 103,              /* term_choice  */
  YYSYMBOL_factor = 104,                   /* factor  */
  YYSYMBOL_factor_choice = 105,            /* factor_choice  */
  YYSYMBOL_power = 106,                    /* power  */
  YYSYMBOL_atom_expr = 107,                /* atom_expr  */
  YYSYMBOL_atom = 108,                     /* atom  */
  YYSYMBOL_STRING_PLUS = 109,              /* STRING_PLUS  */
  YYSYMBOL_trailer = 110,                  /* trailer  */
  YYSYMBOL_testlist = 111,                 /* testlist  */
  YYSYMBOL_testlist_list = 112,            /* testlist_list  */
  YYSYMBOL_classdef = 113,                 /* classdef  */
  YYSYMBOL_arglist = 114,                  /* arglist  */
  YYSYMBOL_argument_list = 115,            /* argument_list  */
  YYSYMBOL_argument = 116,                 /* argument  */
  YYSYMBOL_func_body_suite = 117,          /* func_body_suite  */
  YYSYMBOL_stmt_plus = 118                 /* stmt_plus  */
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
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  249

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
     168,   171,   174,   179,   185,   188,   193,   196,   201,   204,
     209,   212,   217,   220,   225,   228,   233,   236,   239,   244,
     247,   250,   253,   260,   263,   270,   273,   277,   280,   283,
     288,   292,   296,   299,   304,   307,   312,   315,   319,   322,
     325,   328,   331,   336,   342,   349,   357,   365,   375,   380,
     384,   387,   390,   395,   401,   408,   417,   424,   427,   431,
     434,   439,   442,   446,   449,   454,   457,   463,   466,   479,
     482,   485,   488,   491,   494,   497,   500,   503,   506,   509,
     514,   517,   522,   525,   530,   534,   539,   543,   548,   552,
     555,   559,   563,   568,   571,   574,   577,   580,   585,   588,
     593,   596,   599,   603,   607,   612,   616,   619,   624,   627,
     630,   633,   636,   639,   643,   646,   649,   652,   656,   659,
     664,   667,   670,   675,   678,   682,   685,   690,   693,   696,
     701,   704,   708,   711,   716,   719,   724,   727,   730,   735,
     738
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
  "expr_stmt", "eq_testlist_star_expr_plus", "annassign", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "global_stmt",
  "comma_name_star", "compound_stmt", "if_stmt", "while_stmt", "for_stmt",
  "suite", "nts_star", "test", "or_test", "and_test_star", "and_test",
  "not_test_star", "not_test", "comparison", "comp_op", "expr", "xor_expr",
  "and_expr", "shift_expr", "arith_expr", "term", "term_choice", "factor",
  "factor_choice", "power", "atom_expr", "atom", "STRING_PLUS", "trailer",
  "testlist", "testlist_list", "classdef", "arglist", "argument_list",
  "argument", "func_body_suite", "stmt_plus", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-196)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     114,   114,  -196,  -196,   387,  -196,   410,   387,  -196,  -196,
     387,    11,    26,    32,  -196,    39,  -196,   318,  -196,  -196,
    -196,    12,   254,    88,  -196,  -196,   114,  -196,     9,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
      19,  -196,    73,    78,    65,    83,  -196,    18,    58,    60,
      63,    20,     8,  -196,   410,  -196,     6,  -196,  -196,  -196,
      68,  -196,  -196,    74,   387,    90,  -196,  -196,   -17,    79,
      75,  -196,  -196,  -196,    86,  -196,  -196,    70,  -196,  -196,
    -196,   178,   387,   387,   387,  -196,   387,   387,  -196,    97,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,   103,   410,   410,
     410,   410,   410,   410,   410,  -196,  -196,  -196,  -196,  -196,
     410,  -196,   410,   341,   116,   387,  -196,   387,  -196,    94,
     387,   364,   220,    10,    24,   120,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,   100,   113,   127,   129,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,     8,     8,  -196,  -196,  -196,   117,
     121,   118,  -196,  -196,    98,  -196,   220,  -196,   123,   124,
     128,   151,  -196,  -196,   126,    25,   -12,  -196,   130,   145,
     250,    75,   387,   387,   387,  -196,   387,  -196,    15,   220,
     220,   220,   131,   295,   154,   156,   250,  -196,   157,   387,
     133,   170,  -196,  -196,  -196,  -196,  -196,  -196,  -196,    64,
     162,   163,  -196,   220,   295,    59,  -196,   143,  -196,  -196,
    -196,   250,   295,   144,   387,  -196,   166,   147,  -196,  -196,
     179,  -196,   250,  -196,    84,  -196,   150,   152,   220,  -196,
    -196,   186,  -196,   220,  -196,  -196,  -196,  -196,  -196,   220,
     220,    15,  -196,    81,   158,  -196,  -196,   220,  -196
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,   127,   123,     0,     2,     0,     0,    40,    41,
      42,     0,     0,     0,   126,   128,   124,     0,   110,   111,
     112,     0,     0,     0,     4,    51,     6,    20,     0,    24,
      26,    27,    37,    38,    39,    28,    21,    48,    49,    50,
     135,    66,     0,    67,     0,    71,    76,    77,    90,    92,
      94,    96,    98,   101,     0,   109,   113,   115,   125,    31,
     133,    52,     7,     0,     0,     0,    75,    43,     0,     0,
      44,   129,   119,   135,     0,   122,   121,     0,     1,     8,
      23,     0,     0,     0,     0,    29,     0,     0,    86,     0,
      79,    80,    81,    82,    83,    84,    85,    88,     0,     0,
       0,     0,     0,     0,     0,   107,   103,   105,   106,   104,
       0,   108,     0,     0,     0,     0,   116,   134,     2,     0,
       0,     0,     0,     0,     0,     0,    45,   118,   120,    22,
      25,    30,    32,    33,    35,    68,    72,    87,    89,    78,
      91,    93,    95,    97,    99,   100,   102,   114,   130,   144,
       0,   140,   142,   117,     0,   136,     0,     2,     0,     0,
       0,     0,    60,   137,    18,     0,     0,    14,    16,     0,
       0,    46,     0,     0,     0,   131,   141,   132,    53,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,   146,     9,    47,    34,    36,   145,   143,     0,
      56,    58,   138,     0,   149,     0,    19,     0,    12,    15,
      17,     0,     0,     0,     0,    55,     0,     0,   139,   150,
       0,    61,     0,    10,     0,     2,     0,     0,     0,    62,
      11,     0,   147,     0,     2,     2,    59,   148,    54,     0,
       0,    63,    57,     0,     0,    64,     2,     0,    65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -112,  -195,  -196,    40,  -196,  -196,  -196,     4,  -196,
    -118,     0,  -196,   115,  -196,    22,  -196,  -196,  -196,  -196,
    -196,  -196,    27,  -196,  -196,  -196,  -196,  -148,   -48,    -1,
    -196,  -196,   111,  -196,     3,   105,  -196,    -2,   110,   119,
     112,  -196,    -3,  -196,   -43,  -196,  -196,  -196,  -196,   202,
    -196,   -15,  -196,  -196,   104,  -196,    42,  -171,  -185
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    64,   199,    23,    24,    25,   124,   166,   167,   168,
      26,   162,    28,    29,    30,   132,    85,    31,    32,    33,
      34,    35,   126,    36,    37,    38,    39,   163,   215,    40,
      41,    42,    43,    44,    45,    46,    98,    47,    48,    49,
      50,    51,    52,   110,    53,    54,    55,    56,    57,    58,
     116,    59,    60,    61,   150,   151,   152,   193,   205
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    27,    74,    63,    65,   216,   156,    77,   178,    67,
      66,   111,    80,   112,   121,   208,    73,   105,   122,   219,
     187,    73,   164,    68,   188,    82,    27,   224,   102,    -3,
      -3,   200,   201,   202,   169,   185,    88,   113,    69,    89,
     223,    62,   165,    81,    70,   179,   243,   106,   107,   108,
     109,   230,    83,   114,    84,   218,   115,   103,   104,   170,
     186,    75,   220,   119,   221,   204,    79,   146,    15,   147,
      90,    91,    92,    93,    94,    95,    96,    97,   213,   214,
     236,   131,   133,   134,    87,   238,   204,   231,    78,   232,
     136,   241,   242,    86,   204,   244,   214,   140,   -70,   248,
     144,   145,   -74,    99,   117,   158,   100,   101,   120,   118,
     123,   125,   149,   233,   154,   137,   155,     1,   127,    73,
     149,   128,   239,   240,   138,     2,     3,     4,   153,   157,
       5,     6,   171,   172,   247,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,   173,   -69,   -73,   177,
     174,    18,    19,   175,   176,   183,   190,    20,   180,   181,
     182,   184,    21,   189,    22,   206,   203,   207,   211,   164,
     192,   133,   196,   197,   212,   149,    -3,   217,   222,   225,
     227,   129,   228,    27,   229,   234,   192,   235,   210,     2,
       3,   237,   209,   246,   195,   245,   130,   135,   194,     7,
       8,     9,    10,   139,    27,    13,    14,    15,    16,    17,
     141,   192,    27,   226,   143,    18,    19,    71,   198,     0,
     142,    20,   192,   161,     0,   160,    21,     0,    22,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     9,    10,     0,     0,    13,    14,    15,
      16,    17,     0,   191,     0,     0,     0,    18,    19,     0,
       0,     2,     3,    20,     0,     2,     3,     0,    21,     0,
      22,     7,     8,     9,    10,     7,     0,    13,    14,    15,
      16,    17,    14,    15,    16,    17,     0,    18,    19,     0,
       0,    18,    19,    20,     0,     0,     0,    20,    21,     0,
      22,     0,    21,     0,    22,    76,     2,     3,     4,     0,
       0,     5,     6,     0,     0,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,     2,
       3,     0,    18,    19,     0,     0,     0,     0,    20,     7,
       0,     0,     0,    21,     0,    22,    14,    15,    16,    17,
      72,     0,     2,     3,     0,    18,    19,     0,     0,     0,
       0,    20,     7,     0,     0,     0,    21,     0,    22,    14,
      15,    16,    17,   148,     0,     2,     3,     0,    18,    19,
       0,     0,     0,     0,    20,     7,     0,     0,     0,    21,
       0,    22,    14,    15,    16,    17,   159,     0,     2,     3,
       0,    18,    19,     0,     0,     0,     0,    20,     7,     0,
       0,     0,    21,     0,    22,    14,    15,    16,    17,     0,
       0,     2,     3,     0,    18,    19,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    21,     0,    22,    14,    15,
      16,    17,     0,     0,     0,     0,     0,    18,    19,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    21,     0,
      22
};

static const yytype_int16 yycheck[] =
{
       0,     1,    17,     4,     6,   200,   118,    22,   156,    10,
       7,    54,     3,     7,    31,   186,    17,     9,    35,   204,
      32,    22,    12,    12,    36,     6,    26,   212,     8,    14,
      15,   179,   180,   181,    10,    10,    18,    31,    12,    21,
     211,     1,    32,    34,    12,   157,   241,    39,    40,    41,
      42,   222,    33,    47,    35,   203,    50,    37,    38,    35,
      35,    49,     3,    64,     5,   183,    26,   110,    29,   112,
      52,    53,    54,    55,    56,    57,    58,    59,    14,    15,
     228,    82,    83,    84,    19,   233,   204,     3,     0,     5,
      87,   239,   240,    20,   212,    14,    15,    99,    20,   247,
     103,   104,    19,    45,    36,   120,    46,    44,    18,    35,
      31,    36,   113,   225,   115,    18,   117,     3,    32,   120,
     121,    51,   234,   235,    21,    11,    12,    13,    12,    35,
      16,    17,    12,    33,   246,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    33,    20,    19,    51,
      33,    37,    38,    32,    36,     4,    11,    43,    35,    35,
      32,    35,    48,    33,    50,    11,    35,    11,    35,    12,
     170,   172,   173,   174,     4,   176,    14,    14,    35,    35,
      14,     3,    35,   183,     5,    35,   186,    35,   189,    11,
      12,     5,   188,    35,   172,   243,    81,    86,   171,    21,
      22,    23,    24,    98,   204,    27,    28,    29,    30,    31,
     100,   211,   212,   214,   102,    37,    38,    15,   176,    -1,
     101,    43,   222,     3,    -1,   121,    48,    -1,    50,    -1,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    -1,    -1,    27,    28,    29,
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
      -1,    11,    12,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    11,    12,    13,    16,    17,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    37,    38,
      43,    48,    50,    63,    64,    65,    70,    71,    72,    73,
      74,    77,    78,    79,    80,    81,    83,    84,    85,    86,
      89,    90,    91,    92,    93,    94,    95,    97,    98,    99,
     100,   101,   102,   104,   105,   106,   107,   108,   109,   111,
     112,   113,    64,    89,    61,    97,    94,    89,    12,    12,
      12,   109,    32,    89,   111,    49,    51,   111,     0,    64,
       3,    34,     6,    33,    35,    76,    20,    19,    18,    21,
      52,    53,    54,    55,    56,    57,    58,    59,    96,    45,
      46,    44,     8,    37,    38,     9,    39,    40,    41,    42,
     103,   104,     7,    31,    47,    50,   110,    36,    35,    89,
      18,    31,    35,    31,    66,    36,    82,    32,    51,     3,
      73,    89,    75,    89,    89,    92,    94,    18,    21,    95,
      97,    98,    99,   100,   102,   102,   104,   104,    32,    89,
     114,   115,   116,    12,    89,    89,    61,    35,   111,    32,
     114,     3,    71,    87,    12,    32,    67,    68,    69,    10,
      35,    12,    33,    33,    33,    32,    36,    51,    87,    61,
      35,    35,    32,     4,    35,    10,    35,    32,    36,    33,
      11,     3,    71,   117,    82,    75,    89,    89,   116,    62,
      87,    87,    87,    35,    70,   118,    11,    11,   117,    68,
      89,    35,     4,    14,    15,    88,    62,    14,    87,   118,
       3,     5,    35,   117,   118,    35,    89,    14,    35,     5,
     117,     3,     5,    61,    35,    35,    87,     5,    87,    61,
      61,    87,    87,    62,    14,    88,    35,    61,    87
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    64,    64,    64,    65,
      65,    65,    65,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    73,    73,    74,
      74,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      78,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    84,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    88,    88,    88,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     101,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   105,   106,   106,   107,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     110,   110,   110,   111,   111,   112,   112,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   117,   118,
     118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     2,     2,     5,
       7,     8,     6,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     3,     2,     1,     3,     1,     1,     1,     2,
       3,     1,     3,     1,     3,     2,     4,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     2,     3,     1,     1,
       1,     1,     1,     5,    10,     7,     6,    11,     6,     9,
       1,     4,     5,     5,     7,    10,     1,     1,     3,     3,
       1,     1,     3,     3,     1,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     3,     2,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     3,     1,     2,     1,     3,     4,     6,     7,
       1,     2,     1,     3,     1,     3,     1,     4,     5,     1,
       2
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
#line 1475 "parser.tab.c"
    break;

  case 3: /* N: %empty  */
#line 139 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal N");
        (yyval.elem)->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
#line 1485 "parser.tab.c"
    break;

  case 4: /* file: snippet  */
#line 146 "parser.y"
              {
                (yyval.elem) = (yyvsp[0].elem);
 }
#line 1493 "parser.tab.c"
    break;

  case 5: /* snippet: NEWLINE  */
#line 151 "parser.y"
                 {
       
    }
#line 1501 "parser.tab.c"
    break;

  case 6: /* snippet: stmt  */
#line 154 "parser.y"
            { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1509 "parser.tab.c"
    break;

  case 7: /* snippet: NEWLINE snippet  */
#line 157 "parser.y"
                       { 
        
    }
#line 1517 "parser.tab.c"
    break;

  case 8: /* snippet: stmt snippet  */
#line 160 "parser.y"
                   {  
        
    }
#line 1525 "parser.tab.c"
    break;

  case 9: /* funcdef: DEF NAME parameters COLON func_body_suite  */
#line 165 "parser.y"
                                                    {  
            
        }
#line 1533 "parser.tab.c"
    break;

  case 10: /* funcdef: DEF NAME parameters ARROW_OPER TYPE_HINT COLON func_body_suite  */
#line 168 "parser.y"
                                                                         {  
            
        }
#line 1541 "parser.tab.c"
    break;

  case 11: /* funcdef: DEF NAME OPEN_BRACKET CLOSE_BRACKET ARROW_OPER TYPE_HINT COLON func_body_suite  */
#line 171 "parser.y"
                                                                                         {  
            
        }
#line 1549 "parser.tab.c"
    break;

  case 12: /* funcdef: DEF NAME OPEN_BRACKET CLOSE_BRACKET COLON func_body_suite  */
#line 174 "parser.y"
                                                                    {
            
        }
#line 1557 "parser.tab.c"
    break;

  case 13: /* parameters: OPEN_BRACKET typedargslist CLOSE_BRACKET  */
#line 179 "parser.y"
                                                     {  
            
            
        }
#line 1566 "parser.tab.c"
    break;

  case 14: /* typedargslist: typedarg  */
#line 185 "parser.y"
                            {  
            
        }
#line 1574 "parser.tab.c"
    break;

  case 15: /* typedargslist: typedargslist COMMA typedarg  */
#line 188 "parser.y"
                                         {  
            
        }
#line 1582 "parser.tab.c"
    break;

  case 16: /* typedarg: tfpdef  */
#line 193 "parser.y"
                   {  
            
        }
#line 1590 "parser.tab.c"
    break;

  case 17: /* typedarg: tfpdef EQUAL test  */
#line 196 "parser.y"
                            {  
            
        }
#line 1598 "parser.tab.c"
    break;

  case 18: /* tfpdef: NAME  */
#line 201 "parser.y"
             {  
            
        }
#line 1606 "parser.tab.c"
    break;

  case 19: /* tfpdef: NAME COLON TYPE_HINT  */
#line 204 "parser.y"
                               {  
                
        }
#line 1614 "parser.tab.c"
    break;

  case 20: /* stmt: simple_stmt  */
#line 209 "parser.y"
                        { 

        }
#line 1622 "parser.tab.c"
    break;

  case 21: /* stmt: compound_stmt  */
#line 212 "parser.y"
                            { 
             (yyval.elem)=(yyvsp[0].elem); 
        }
#line 1630 "parser.tab.c"
    break;

  case 22: /* simple_stmt: small_stmt_list SEMI_COLON NEWLINE  */
#line 217 "parser.y"
                                                {  
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 1638 "parser.tab.c"
    break;

  case 23: /* simple_stmt: small_stmt_list NEWLINE  */
#line 220 "parser.y"
                                   {  
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 1646 "parser.tab.c"
    break;

  case 24: /* small_stmt_list: small_stmt  */
#line 225 "parser.y"
                                {   
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1654 "parser.tab.c"
    break;

  case 25: /* small_stmt_list: small_stmt_list SEMI_COLON small_stmt  */
#line 228 "parser.y"
                                                     {  
           
        }
#line 1662 "parser.tab.c"
    break;

  case 26: /* small_stmt: expr_stmt  */
#line 233 "parser.y"
                            {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1670 "parser.tab.c"
    break;

  case 27: /* small_stmt: flow_stmt  */
#line 236 "parser.y"
                        {  
           
        }
#line 1678 "parser.tab.c"
    break;

  case 28: /* small_stmt: global_stmt  */
#line 239 "parser.y"
                            {  
            
        }
#line 1686 "parser.tab.c"
    break;

  case 29: /* expr_stmt: test annassign  */
#line 244 "parser.y"
                          {

        }
#line 1694 "parser.tab.c"
    break;

  case 30: /* expr_stmt: test ASSIGN_OPERATOR test  */
#line 247 "parser.y"
                                    {

        }
#line 1702 "parser.tab.c"
    break;

  case 31: /* expr_stmt: testlist  */
#line 250 "parser.y"
                   {

        }
#line 1710 "parser.tab.c"
    break;

  case 32: /* expr_stmt: test EQUAL eq_testlist_star_expr_plus  */
#line 253 "parser.y"
                                               {
                create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
		(yyval.elem)->ins = (yyvsp[-2].elem)->ins;
		create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
        }
#line 1720 "parser.tab.c"
    break;

  case 33: /* eq_testlist_star_expr_plus: test  */
#line 260 "parser.y"
                                 {
                (yyval.elem)=(yyvsp[0].elem);
        }
#line 1728 "parser.tab.c"
    break;

  case 34: /* eq_testlist_star_expr_plus: test EQUAL eq_testlist_star_expr_plus  */
#line 263 "parser.y"
                                               {
                create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
		(yyval.elem)->ins = (yyvsp[-2].elem)->ins;
		create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
        }
#line 1738 "parser.tab.c"
    break;

  case 35: /* annassign: COLON test  */
#line 270 "parser.y"
                      {

        }
#line 1746 "parser.tab.c"
    break;

  case 36: /* annassign: COLON test EQUAL test  */
#line 273 "parser.y"
                               {
                
        }
#line 1754 "parser.tab.c"
    break;

  case 37: /* flow_stmt: break_stmt  */
#line 277 "parser.y"
                        {  
            
        }
#line 1762 "parser.tab.c"
    break;

  case 38: /* flow_stmt: continue_stmt  */
#line 280 "parser.y"
                            {  
            
        }
#line 1770 "parser.tab.c"
    break;

  case 39: /* flow_stmt: return_stmt  */
#line 283 "parser.y"
                         {  
            
        }
#line 1778 "parser.tab.c"
    break;

  case 40: /* break_stmt: BREAK  */
#line 288 "parser.y"
                    {  
            
        }
#line 1786 "parser.tab.c"
    break;

  case 41: /* continue_stmt: CONTINUE  */
#line 292 "parser.y"
                            {  
            
        }
#line 1794 "parser.tab.c"
    break;

  case 42: /* return_stmt: RETURN  */
#line 296 "parser.y"
                        {  
            
        }
#line 1802 "parser.tab.c"
    break;

  case 43: /* return_stmt: RETURN test  */
#line 299 "parser.y"
                          {  
           
        }
#line 1810 "parser.tab.c"
    break;

  case 44: /* global_stmt: GLOBAL NAME  */
#line 304 "parser.y"
                            {  
            
        }
#line 1818 "parser.tab.c"
    break;

  case 45: /* global_stmt: GLOBAL NAME comma_name_star  */
#line 307 "parser.y"
                                      {   
            
        }
#line 1826 "parser.tab.c"
    break;

  case 46: /* comma_name_star: COMMA NAME  */
#line 312 "parser.y"
                               {  
           
        }
#line 1834 "parser.tab.c"
    break;

  case 47: /* comma_name_star: COMMA NAME comma_name_star  */
#line 315 "parser.y"
                                        {  
            
        }
#line 1842 "parser.tab.c"
    break;

  case 48: /* compound_stmt: if_stmt  */
#line 319 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);  
        }
#line 1850 "parser.tab.c"
    break;

  case 49: /* compound_stmt: while_stmt  */
#line 322 "parser.y"
                       {  
           
        }
#line 1858 "parser.tab.c"
    break;

  case 50: /* compound_stmt: for_stmt  */
#line 325 "parser.y"
                       {  
            
        }
#line 1866 "parser.tab.c"
    break;

  case 51: /* compound_stmt: funcdef  */
#line 328 "parser.y"
                       {  
            
        }
#line 1874 "parser.tab.c"
    break;

  case 52: /* compound_stmt: classdef  */
#line 331 "parser.y"
                       {  
           
        }
#line 1882 "parser.tab.c"
    break;

  case 53: /* if_stmt: IF test COLON M suite  */
#line 336 "parser.y"
                                   {  
           (yyval.elem)=create_node(6, "if_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
           (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
           backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
           (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);
        }
#line 1893 "parser.tab.c"
    break;

  case 54: /* if_stmt: IF test COLON M suite N ELSE COLON M suite  */
#line 342 "parser.y"
                                                       {  
            (yyval.elem) = create_node(11, "if_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            vector<int> temp = merge((yyvsp[-5].elem)->nextlist, (yyvsp[-4].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);
        }
#line 1905 "parser.tab.c"
    break;

  case 55: /* if_stmt: IF test COLON M suite N nts_star  */
#line 349 "parser.y"
                                              {  
            (yyval.elem) = create_node(8, "if_elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);     
            vector<int> temp = merge((yyvsp[-2].elem)->nextlist, (yyvsp[-1].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);
        }
#line 1917 "parser.tab.c"
    break;

  case 56: /* while_stmt: WHILE M test COLON M suite  */
#line 357 "parser.y"
                                         {  
            (yyval.elem) = create_node(7, "while_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            backpatch((yyvsp[0].elem)->nextlist, (yyvsp[-4].elem)->ins);
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = (yyvsp[-3].elem)->falselist;
            create_ins(0, "goto", to_string((yyvsp[-4].elem)->ins), "", "");
        }
#line 1930 "parser.tab.c"
    break;

  case 57: /* while_stmt: WHILE M test COLON M suite N ELSE COLON M suite  */
#line 365 "parser.y"
                                                                   {   
			(yyval.elem) = create_node(12, "while_else_stmt", (yyvsp[-10].elem), (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-9].elem)->ins;
			backpatch((yyvsp[-4].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-5].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
			backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
			(yyval.elem)->nextlist = merge((yyvsp[-4].elem)->nextlist, (yyvsp[0].elem)->nextlist); //verify
        }
#line 1944 "parser.tab.c"
    break;

  case 58: /* for_stmt: FOR expr IN testlist COLON suite  */
#line 375 "parser.y"
                                              { 
            (yyval.elem) = create_node(7, "for_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;

        }
#line 1954 "parser.tab.c"
    break;

  case 59: /* for_stmt: FOR expr IN testlist COLON suite ELSE COLON suite  */
#line 380 "parser.y"
                                                              { 
            
        }
#line 1962 "parser.tab.c"
    break;

  case 60: /* suite: simple_stmt  */
#line 384 "parser.y"
                    { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1970 "parser.tab.c"
    break;

  case 61: /* suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 387 "parser.y"
                                            { 
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 1978 "parser.tab.c"
    break;

  case 62: /* suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 390 "parser.y"
                                                    { 
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 1986 "parser.tab.c"
    break;

  case 63: /* nts_star: ELIF test COLON M suite  */
#line 395 "parser.y"
                                    {  
            (yyval.elem)=create_node(6, "elif_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);
        }
#line 1997 "parser.tab.c"
    break;

  case 64: /* nts_star: ELIF test COLON M suite N nts_star  */
#line 401 "parser.y"
                                              {  
            (yyval.elem) = create_node(8, "elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-5].elem)->ins;
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist));
        }
#line 2009 "parser.tab.c"
    break;

  case 65: /* nts_star: ELIF test COLON M suite N ELSE COLON M suite  */
#line 408 "parser.y"
                                                        {  
            (yyval.elem) = create_node(11, "elif_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-8].elem)->ins;
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-5].elem)->nextlist, merge((yyvsp[-4].elem)->nextlist,(yyvsp[0].elem)->nextlist));
        }
#line 2021 "parser.tab.c"
    break;

  case 66: /* test: or_test  */
#line 417 "parser.y"
                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2029 "parser.tab.c"
    break;

  case 67: /* or_test: and_test  */
#line 424 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2037 "parser.tab.c"
    break;

  case 68: /* or_test: and_test_star OR and_test  */
#line 427 "parser.y"
                                       {  
            
        }
#line 2045 "parser.tab.c"
    break;

  case 69: /* and_test_star: and_test_star OR and_test  */
#line 431 "parser.y"
                                          {
            
        }
#line 2053 "parser.tab.c"
    break;

  case 70: /* and_test_star: and_test  */
#line 434 "parser.y"
                     { 
                
        }
#line 2061 "parser.tab.c"
    break;

  case 71: /* and_test: not_test  */
#line 439 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2069 "parser.tab.c"
    break;

  case 72: /* and_test: not_test_star AND not_test  */
#line 442 "parser.y"
                                        {  
            
        }
#line 2077 "parser.tab.c"
    break;

  case 73: /* not_test_star: not_test_star AND not_test  */
#line 446 "parser.y"
                                            { 
            
        }
#line 2085 "parser.tab.c"
    break;

  case 74: /* not_test_star: not_test  */
#line 449 "parser.y"
                     { 
            
        }
#line 2093 "parser.tab.c"
    break;

  case 75: /* not_test: NOT not_test  */
#line 454 "parser.y"
                         { 
            
        }
#line 2101 "parser.tab.c"
    break;

  case 76: /* not_test: comparison  */
#line 457 "parser.y"
                        { 
            (yyval.elem)=(yyvsp[0].elem);
            
        }
#line 2110 "parser.tab.c"
    break;

  case 77: /* comparison: expr  */
#line 463 "parser.y"
                  {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2118 "parser.tab.c"
    break;

  case 78: /* comparison: expr comp_op comparison  */
#line 466 "parser.y"
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
#line 2134 "parser.tab.c"
    break;

  case 79: /* comp_op: LESS_THAN  */
#line 479 "parser.y"
                    {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2142 "parser.tab.c"
    break;

  case 80: /* comp_op: GREATER_THAN  */
#line 482 "parser.y"
                    { 
       (yyval.elem) = (yyvsp[0].elem);
     }
#line 2150 "parser.tab.c"
    break;

  case 81: /* comp_op: EQUAL_EQUAL  */
#line 485 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2158 "parser.tab.c"
    break;

  case 82: /* comp_op: GREATER_THAN_EQUAL  */
#line 488 "parser.y"
                            { 
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2166 "parser.tab.c"
    break;

  case 83: /* comp_op: LESS_THAN_EQUAL  */
#line 491 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2174 "parser.tab.c"
    break;

  case 84: /* comp_op: NOT_EQUAL_ARROW  */
#line 494 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
      }
#line 2182 "parser.tab.c"
    break;

  case 85: /* comp_op: NOT_EQUAL  */
#line 497 "parser.y"
                   {
       (yyval.elem) = (yyvsp[0].elem);
     }
#line 2190 "parser.tab.c"
    break;

  case 86: /* comp_op: IN  */
#line 500 "parser.y"
            {  
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2198 "parser.tab.c"
    break;

  case 87: /* comp_op: NOT IN  */
#line 503 "parser.y"
                { 
        (yyval.elem) = create_node(3, "NOT IN", (yyvsp[-1].elem), (yyvsp[0].elem));
     }
#line 2206 "parser.tab.c"
    break;

  case 88: /* comp_op: IS  */
#line 506 "parser.y"
            { 
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2214 "parser.tab.c"
    break;

  case 89: /* comp_op: IS NOT  */
#line 509 "parser.y"
                { 
        (yyval.elem) = create_node(3, "IS NOT", (yyvsp[-1].elem), (yyvsp[0].elem));
     }
#line 2222 "parser.tab.c"
    break;

  case 90: /* expr: xor_expr  */
#line 514 "parser.y"
                  { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2230 "parser.tab.c"
    break;

  case 91: /* expr: xor_expr BIT_OR expr  */
#line 517 "parser.y"
                                  {  
            
        }
#line 2238 "parser.tab.c"
    break;

  case 92: /* xor_expr: and_expr  */
#line 522 "parser.y"
                   { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2246 "parser.tab.c"
    break;

  case 93: /* xor_expr: and_expr BIT_XOR xor_expr  */
#line 525 "parser.y"
                                       {  
            
        }
#line 2254 "parser.tab.c"
    break;

  case 94: /* and_expr: shift_expr  */
#line 530 "parser.y"
                       { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2263 "parser.tab.c"
    break;

  case 95: /* and_expr: shift_expr BIT_AND and_expr  */
#line 534 "parser.y"
                                        {  
            
        }
#line 2271 "parser.tab.c"
    break;

  case 96: /* shift_expr: arith_expr  */
#line 539 "parser.y"
                         { 
            (yyval.elem) = (yyvsp[0].elem);
                
            }
#line 2280 "parser.tab.c"
    break;

  case 97: /* shift_expr: arith_expr SHIFT_OPER shift_expr  */
#line 543 "parser.y"
                                                 { 
                
             }
#line 2288 "parser.tab.c"
    break;

  case 98: /* arith_expr: term  */
#line 548 "parser.y"
                 { 
            (yyval.elem) = (yyvsp[0].elem);
                
            }
#line 2297 "parser.tab.c"
    break;

  case 99: /* arith_expr: arith_expr PLUS term  */
#line 552 "parser.y"
                                   { 
                
            }
#line 2305 "parser.tab.c"
    break;

  case 100: /* arith_expr: arith_expr MINUS term  */
#line 555 "parser.y"
                                    { 
                
             }
#line 2313 "parser.tab.c"
    break;

  case 101: /* term: factor  */
#line 559 "parser.y"
             {
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2322 "parser.tab.c"
    break;

  case 102: /* term: term term_choice factor  */
#line 563 "parser.y"
                                  {
            
         }
#line 2330 "parser.tab.c"
    break;

  case 103: /* term_choice: MULTIPLY  */
#line 568 "parser.y"
                            { 
            
        }
#line 2338 "parser.tab.c"
    break;

  case 104: /* term_choice: ATTHERATE  */
#line 571 "parser.y"
                        { 
            
        }
#line 2346 "parser.tab.c"
    break;

  case 105: /* term_choice: DIVIDE  */
#line 574 "parser.y"
                        { 
            
        }
#line 2354 "parser.tab.c"
    break;

  case 106: /* term_choice: REMAINDER  */
#line 577 "parser.y"
                        { 
           
        }
#line 2362 "parser.tab.c"
    break;

  case 107: /* term_choice: FLOOR_DIV_OPER  */
#line 580 "parser.y"
                           { 
            
        }
#line 2370 "parser.tab.c"
    break;

  case 108: /* factor: factor_choice factor  */
#line 585 "parser.y"
                                    {  
            
        }
#line 2378 "parser.tab.c"
    break;

  case 109: /* factor: power  */
#line 588 "parser.y"
                    { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2387 "parser.tab.c"
    break;

  case 110: /* factor_choice: PLUS  */
#line 593 "parser.y"
                            {
            
        }
#line 2395 "parser.tab.c"
    break;

  case 111: /* factor_choice: MINUS  */
#line 596 "parser.y"
                     { 
            
        }
#line 2403 "parser.tab.c"
    break;

  case 112: /* factor_choice: NEGATION  */
#line 599 "parser.y"
                     { 
            
        }
#line 2411 "parser.tab.c"
    break;

  case 113: /* power: atom_expr  */
#line 603 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2420 "parser.tab.c"
    break;

  case 114: /* power: atom_expr POWER_OPERATOR factor  */
#line 607 "parser.y"
                                            { 
            
        }
#line 2428 "parser.tab.c"
    break;

  case 115: /* atom_expr: atom  */
#line 612 "parser.y"
                {  
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2437 "parser.tab.c"
    break;

  case 116: /* atom_expr: atom_expr trailer  */
#line 616 "parser.y"
                            {  
            
        }
#line 2445 "parser.tab.c"
    break;

  case 117: /* atom_expr: atom_expr DOT NAME  */
#line 619 "parser.y"
                             { 
            
        }
#line 2453 "parser.tab.c"
    break;

  case 118: /* atom: OPEN_BRACKET testlist CLOSE_BRACKET  */
#line 624 "parser.y"
                                           { 
        (yyval.elem)=(yyvsp[-1].elem);
    }
#line 2461 "parser.tab.c"
    break;

  case 119: /* atom: OPEN_BRACKET CLOSE_BRACKET  */
#line 627 "parser.y"
                                    {
        
    }
#line 2469 "parser.tab.c"
    break;

  case 120: /* atom: SQUARE_OPEN testlist SQUARE_CLOSE  */
#line 630 "parser.y"
                                           { 
        
    }
#line 2477 "parser.tab.c"
    break;

  case 121: /* atom: SQUARE_OPEN SQUARE_CLOSE  */
#line 633 "parser.y"
                                {
        
     }
#line 2485 "parser.tab.c"
    break;

  case 122: /* atom: CURLY_OPEN CURLY_CLOSE  */
#line 636 "parser.y"
                                { 
        
     }
#line 2493 "parser.tab.c"
    break;

  case 123: /* atom: NAME  */
#line 639 "parser.y"
                {
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
     }
#line 2502 "parser.tab.c"
    break;

  case 124: /* atom: NUMBER  */
#line 643 "parser.y"
                    { 
        
    }
#line 2510 "parser.tab.c"
    break;

  case 125: /* atom: STRING_PLUS  */
#line 646 "parser.y"
                        { 
       
    }
#line 2518 "parser.tab.c"
    break;

  case 126: /* atom: ATOM_KEYWORDS  */
#line 649 "parser.y"
                        { 
        
    }
#line 2526 "parser.tab.c"
    break;

  case 127: /* atom: TYPE_HINT  */
#line 652 "parser.y"
                    { 
        
     }
#line 2534 "parser.tab.c"
    break;

  case 128: /* STRING_PLUS: STRING  */
#line 656 "parser.y"
                        {
            
        }
#line 2542 "parser.tab.c"
    break;

  case 129: /* STRING_PLUS: STRING STRING_PLUS  */
#line 659 "parser.y"
                                { 
            
        }
#line 2550 "parser.tab.c"
    break;

  case 130: /* trailer: OPEN_BRACKET CLOSE_BRACKET  */
#line 664 "parser.y"
                                     { 
            
        }
#line 2558 "parser.tab.c"
    break;

  case 131: /* trailer: OPEN_BRACKET arglist CLOSE_BRACKET  */
#line 667 "parser.y"
                                              {
            
        }
#line 2566 "parser.tab.c"
    break;

  case 132: /* trailer: SQUARE_OPEN test SQUARE_CLOSE  */
#line 670 "parser.y"
                                       {

        }
#line 2574 "parser.tab.c"
    break;

  case 133: /* testlist: testlist_list  */
#line 675 "parser.y"
                           { 
            
        }
#line 2582 "parser.tab.c"
    break;

  case 134: /* testlist: testlist_list COMMA  */
#line 678 "parser.y"
                                {
            
         }
#line 2590 "parser.tab.c"
    break;

  case 135: /* testlist_list: test  */
#line 682 "parser.y"
                            {
            
        }
#line 2598 "parser.tab.c"
    break;

  case 136: /* testlist_list: testlist_list COMMA test  */
#line 685 "parser.y"
                                    { 
            
        }
#line 2606 "parser.tab.c"
    break;

  case 137: /* classdef: CLASS NAME COLON suite  */
#line 690 "parser.y"
                                      { 
            
        }
#line 2614 "parser.tab.c"
    break;

  case 138: /* classdef: CLASS NAME OPEN_BRACKET CLOSE_BRACKET COLON suite  */
#line 693 "parser.y"
                                                                 { 
            
        }
#line 2622 "parser.tab.c"
    break;

  case 139: /* classdef: CLASS NAME OPEN_BRACKET arglist CLOSE_BRACKET COLON suite  */
#line 696 "parser.y"
                                                                         { 
           
        }
#line 2630 "parser.tab.c"
    break;

  case 140: /* arglist: argument_list  */
#line 701 "parser.y"
                           { 
            
        }
#line 2638 "parser.tab.c"
    break;

  case 141: /* arglist: argument_list COMMA  */
#line 704 "parser.y"
                                 { 
           
        }
#line 2646 "parser.tab.c"
    break;

  case 142: /* argument_list: argument  */
#line 708 "parser.y"
                            { 
            
        }
#line 2654 "parser.tab.c"
    break;

  case 143: /* argument_list: argument_list COMMA argument  */
#line 711 "parser.y"
                                        { 
            
        }
#line 2662 "parser.tab.c"
    break;

  case 144: /* argument: test  */
#line 716 "parser.y"
                {
               
        }
#line 2670 "parser.tab.c"
    break;

  case 145: /* argument: test EQUAL test  */
#line 719 "parser.y"
                            { 
            
        }
#line 2678 "parser.tab.c"
    break;

  case 146: /* func_body_suite: simple_stmt  */
#line 724 "parser.y"
                                { 
            
        }
#line 2686 "parser.tab.c"
    break;

  case 147: /* func_body_suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 727 "parser.y"
                                            { 
            
        }
#line 2694 "parser.tab.c"
    break;

  case 148: /* func_body_suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 730 "parser.y"
                                                    { 
            
        }
#line 2702 "parser.tab.c"
    break;

  case 149: /* stmt_plus: stmt  */
#line 735 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2710 "parser.tab.c"
    break;

  case 150: /* stmt_plus: stmt stmt_plus  */
#line 738 "parser.y"
                            { 
            (yyval.elem)=create_node(3,"stmt_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
        }
#line 2719 "parser.tab.c"
    break;


#line 2723 "parser.tab.c"

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

#line 743 "parser.y"


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
