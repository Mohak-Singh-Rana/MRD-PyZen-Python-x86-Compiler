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
  YYSYMBOL_ASYNC = 4,                      /* ASYNC  */
  YYSYMBOL_INDENT = 5,                     /* INDENT  */
  YYSYMBOL_DEDENT = 6,                     /* DEDENT  */
  YYSYMBOL_ASSIGN_OPERATOR = 7,            /* ASSIGN_OPERATOR  */
  YYSYMBOL_POWER_OPERATOR = 8,             /* POWER_OPERATOR  */
  YYSYMBOL_SHIFT_OPER = 9,                 /* SHIFT_OPER  */
  YYSYMBOL_FLOOR_DIV_OPER = 10,            /* FLOOR_DIV_OPER  */
  YYSYMBOL_ARROW_OPER = 11,                /* ARROW_OPER  */
  YYSYMBOL_TYPE_HINT = 12,                 /* TYPE_HINT  */
  YYSYMBOL_NAME = 13,                      /* NAME  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_ELIF = 16,                      /* ELIF  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_IN = 19,                        /* IN  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_BREAK = 23,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 24,                  /* CONTINUE  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_CLASS = 26,                     /* CLASS  */
  YYSYMBOL_DEF = 27,                       /* DEF  */
  YYSYMBOL_GLOBAL = 28,                    /* GLOBAL  */
  YYSYMBOL_NONLOCAL = 29,                  /* NONLOCAL  */
  YYSYMBOL_ASSERT = 30,                    /* ASSERT  */
  YYSYMBOL_ATOM_KEYWORDS = 31,             /* ATOM_KEYWORDS  */
  YYSYMBOL_STRING = 32,                    /* STRING  */
  YYSYMBOL_NUMBER = 33,                    /* NUMBER  */
  YYSYMBOL_OPEN_BRACKET = 34,              /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_BRACKET = 35,             /* CLOSE_BRACKET  */
  YYSYMBOL_EQUAL = 36,                     /* EQUAL  */
  YYSYMBOL_SEMI_COLON = 37,                /* SEMI_COLON  */
  YYSYMBOL_COLON = 38,                     /* COLON  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_PLUS = 40,                      /* PLUS  */
  YYSYMBOL_MINUS = 41,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 42,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 43,                    /* DIVIDE  */
  YYSYMBOL_REMAINDER = 44,                 /* REMAINDER  */
  YYSYMBOL_ATTHERATE = 45,                 /* ATTHERATE  */
  YYSYMBOL_NEGATION = 46,                  /* NEGATION  */
  YYSYMBOL_BIT_AND = 47,                   /* BIT_AND  */
  YYSYMBOL_BIT_OR = 48,                    /* BIT_OR  */
  YYSYMBOL_BIT_XOR = 49,                   /* BIT_XOR  */
  YYSYMBOL_DOT = 50,                       /* DOT  */
  YYSYMBOL_CURLY_OPEN = 51,                /* CURLY_OPEN  */
  YYSYMBOL_CURLY_CLOSE = 52,               /* CURLY_CLOSE  */
  YYSYMBOL_SQUARE_OPEN = 53,               /* SQUARE_OPEN  */
  YYSYMBOL_SQUARE_CLOSE = 54,              /* SQUARE_CLOSE  */
  YYSYMBOL_LESS_THAN = 55,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 56,              /* GREATER_THAN  */
  YYSYMBOL_EQUAL_EQUAL = 57,               /* EQUAL_EQUAL  */
  YYSYMBOL_GREATER_THAN_EQUAL = 58,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_LESS_THAN_EQUAL = 59,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_NOT_EQUAL_ARROW = 60,           /* NOT_EQUAL_ARROW  */
  YYSYMBOL_NOT_EQUAL = 61,                 /* NOT_EQUAL  */
  YYSYMBOL_IS = 62,                        /* IS  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_M = 64,                         /* M  */
  YYSYMBOL_N = 65,                         /* N  */
  YYSYMBOL_file = 66,                      /* file  */
  YYSYMBOL_snippet = 67,                   /* snippet  */
  YYSYMBOL_funcdef = 68,                   /* funcdef  */
  YYSYMBOL_parameters = 69,                /* parameters  */
  YYSYMBOL_typedargslist = 70,             /* typedargslist  */
  YYSYMBOL_typedarg = 71,                  /* typedarg  */
  YYSYMBOL_tfpdef = 72,                    /* tfpdef  */
  YYSYMBOL_stmt = 73,                      /* stmt  */
  YYSYMBOL_simple_stmt = 74,               /* simple_stmt  */
  YYSYMBOL_small_stmt_list = 75,           /* small_stmt_list  */
  YYSYMBOL_small_stmt = 76,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 77,                 /* expr_stmt  */
  YYSYMBOL_eq_testlist_star_expr_plus = 78, /* eq_testlist_star_expr_plus  */
  YYSYMBOL_annassign = 79,                 /* annassign  */
  YYSYMBOL_testlist_star_expr = 80,        /* testlist_star_expr  */
  YYSYMBOL_expr_choice_list = 81,          /* expr_choice_list  */
  YYSYMBOL_expr_choice = 82,               /* expr_choice  */
  YYSYMBOL_augassign = 83,                 /* augassign  */
  YYSYMBOL_flow_stmt = 84,                 /* flow_stmt  */
  YYSYMBOL_break_stmt = 85,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 86,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 87,               /* return_stmt  */
  YYSYMBOL_global_stmt = 88,               /* global_stmt  */
  YYSYMBOL_nonlocal_stmt = 89,             /* nonlocal_stmt  */
  YYSYMBOL_assert_stmt = 90,               /* assert_stmt  */
  YYSYMBOL_comma_name_star = 91,           /* comma_name_star  */
  YYSYMBOL_compound_stmt = 92,             /* compound_stmt  */
  YYSYMBOL_async_stmt = 93,                /* async_stmt  */
  YYSYMBOL_async_choice = 94,              /* async_choice  */
  YYSYMBOL_if_stmt = 95,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 96,                /* while_stmt  */
  YYSYMBOL_for_stmt = 97,                  /* for_stmt  */
  YYSYMBOL_suite = 98,                     /* suite  */
  YYSYMBOL_nts_star = 99,                  /* nts_star  */
  YYSYMBOL_test = 100,                     /* test  */
  YYSYMBOL_or_test = 101,                  /* or_test  */
  YYSYMBOL_and_test_star = 102,            /* and_test_star  */
  YYSYMBOL_and_test = 103,                 /* and_test  */
  YYSYMBOL_not_test_star = 104,            /* not_test_star  */
  YYSYMBOL_not_test = 105,                 /* not_test  */
  YYSYMBOL_comparison = 106,               /* comparison  */
  YYSYMBOL_comp_op = 107,                  /* comp_op  */
  YYSYMBOL_star_expr = 108,                /* star_expr  */
  YYSYMBOL_expr = 109,                     /* expr  */
  YYSYMBOL_xor_expr = 110,                 /* xor_expr  */
  YYSYMBOL_and_expr = 111,                 /* and_expr  */
  YYSYMBOL_shift_expr = 112,               /* shift_expr  */
  YYSYMBOL_arith_expr = 113,               /* arith_expr  */
  YYSYMBOL_term = 114,                     /* term  */
  YYSYMBOL_term_choice = 115,              /* term_choice  */
  YYSYMBOL_factor = 116,                   /* factor  */
  YYSYMBOL_factor_choice = 117,            /* factor_choice  */
  YYSYMBOL_power = 118,                    /* power  */
  YYSYMBOL_atom_expr = 119,                /* atom_expr  */
  YYSYMBOL_atom = 120,                     /* atom  */
  YYSYMBOL_STRING_PLUS = 121,              /* STRING_PLUS  */
  YYSYMBOL_testlist_comp = 122,            /* testlist_comp  */
  YYSYMBOL_named_or_star_list = 123,       /* named_or_star_list  */
  YYSYMBOL_named_or_star = 124,            /* named_or_star  */
  YYSYMBOL_trailer = 125,                  /* trailer  */
  YYSYMBOL_subscriptlist = 126,            /* subscriptlist  */
  YYSYMBOL_subscriptlist_list = 127,       /* subscriptlist_list  */
  YYSYMBOL_subscript = 128,                /* subscript  */
  YYSYMBOL_exprlist = 129,                 /* exprlist  */
  YYSYMBOL_expr_or_star_expr_list = 130,   /* expr_or_star_expr_list  */
  YYSYMBOL_expr_or_star_expr = 131,        /* expr_or_star_expr  */
  YYSYMBOL_testlist = 132,                 /* testlist  */
  YYSYMBOL_testlist_list = 133,            /* testlist_list  */
  YYSYMBOL_dictorsetmaker = 134,           /* dictorsetmaker  */
  YYSYMBOL_A = 135,                        /* A  */
  YYSYMBOL_A_list = 136,                   /* A_list  */
  YYSYMBOL_B = 137,                        /* B  */
  YYSYMBOL_B_list = 138,                   /* B_list  */
  YYSYMBOL_classdef = 139,                 /* classdef  */
  YYSYMBOL_arglist = 140,                  /* arglist  */
  YYSYMBOL_argument_list = 141,            /* argument_list  */
  YYSYMBOL_argument = 142,                 /* argument  */
  YYSYMBOL_comp_iter = 143,                /* comp_iter  */
  YYSYMBOL_sync_comp_for = 144,            /* sync_comp_for  */
  YYSYMBOL_comp_for = 145,                 /* comp_for  */
  YYSYMBOL_comp_if = 146,                  /* comp_if  */
  YYSYMBOL_func_body_suite = 147,          /* func_body_suite  */
  YYSYMBOL_stmt_plus = 148,                /* stmt_plus  */
  YYSYMBOL_comma_test = 149                /* comma_test  */
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
#define YYFINAL  109
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   694

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  216
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  331

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   136,   136,   142,   149,   154,   157,   160,   163,   168,
     172,   175,   178,   183,   189,   192,   197,   200,   205,   208,
     213,   216,   221,   224,   229,   232,   237,   240,   243,   246,
     249,   254,   257,   260,   265,   268,   275,   278,   283,   286,
     291,   294,   299,   302,   307,   312,   315,   318,   323,   327,
     331,   334,   339,   342,   346,   350,   355,   358,   362,   365,
     369,   372,   375,   378,   381,   384,   388,   392,   395,   400,
     408,   415,   429,   438,   448,   451,   455,   458,   461,   481,
     487,   494,   503,   510,   513,   517,   520,   525,   528,   532,
     535,   540,   543,   549,   552,   567,   570,   573,   576,   579,
     582,   585,   588,   591,   594,   597,   602,   607,   610,   615,
     618,   623,   627,   632,   636,   641,   645,   648,   652,   656,
     661,   664,   667,   670,   673,   678,   681,   686,   689,   692,
     696,   700,   705,   709,   712,   717,   720,   723,   726,   729,
     732,   735,   739,   742,   745,   748,   752,   755,   760,   763,
     766,   770,   773,   777,   780,   785,   788,   791,   796,   799,
     803,   806,   810,   813,   816,   819,   822,   826,   829,   833,
     836,   840,   843,   847,   850,   854,   857,   861,   864,   867,
     870,   873,   876,   881,   884,   888,   891,   895,   898,   902,
     905,   910,   913,   916,   921,   924,   928,   931,   936,   939,
     942,   945,   948,   953,   956,   960,   963,   967,   970,   974,
     977,   981,   984,   987,   992,   995,  1000
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
  "\"end of file\"", "error", "\"invalid token\"", "NEWLINE", "ASYNC",
  "INDENT", "DEDENT", "ASSIGN_OPERATOR", "POWER_OPERATOR", "SHIFT_OPER",
  "FLOOR_DIV_OPER", "ARROW_OPER", "TYPE_HINT", "NAME", "IF", "ELSE",
  "ELIF", "WHILE", "FOR", "IN", "AND", "OR", "NOT", "BREAK", "CONTINUE",
  "RETURN", "CLASS", "DEF", "GLOBAL", "NONLOCAL", "ASSERT",
  "ATOM_KEYWORDS", "STRING", "NUMBER", "OPEN_BRACKET", "CLOSE_BRACKET",
  "EQUAL", "SEMI_COLON", "COLON", "COMMA", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "REMAINDER", "ATTHERATE", "NEGATION", "BIT_AND", "BIT_OR",
  "BIT_XOR", "DOT", "CURLY_OPEN", "CURLY_CLOSE", "SQUARE_OPEN",
  "SQUARE_CLOSE", "LESS_THAN", "GREATER_THAN", "EQUAL_EQUAL",
  "GREATER_THAN_EQUAL", "LESS_THAN_EQUAL", "NOT_EQUAL_ARROW", "NOT_EQUAL",
  "IS", "$accept", "M", "N", "file", "snippet", "funcdef", "parameters",
  "typedargslist", "typedarg", "tfpdef", "stmt", "simple_stmt",
  "small_stmt_list", "small_stmt", "expr_stmt",
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

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-270)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-91)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     277,   277,    14,  -270,  -270,   618,  -270,    90,   618,  -270,
    -270,   572,    20,    45,    58,    72,   618,  -270,   -15,  -270,
     547,  -270,  -270,   641,  -270,    47,   521,    19,  -270,  -270,
     277,  -270,    10,  -270,  -270,  -270,     8,    75,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,    96,   105,   109,   115,  -270,  -270,     6,
      92,    93,   106,    68,   141,  -270,   641,  -270,     3,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,   117,   618,  -270,  -270,
     137,   119,  -270,  -270,  -270,     4,   126,   124,   124,   130,
    -270,  -270,  -270,  -270,   135,   133,    30,  -270,   641,  -270,
     123,  -270,   125,    30,   139,    30,   142,  -270,   134,  -270,
    -270,  -270,   179,  -270,   572,   618,  -270,   618,   572,   618,
     618,  -270,   170,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
     171,   641,   641,   641,   641,   641,   641,   641,  -270,  -270,
    -270,  -270,  -270,   641,  -270,   641,   419,   182,   595,  -270,
    -270,   158,   618,    90,   454,   309,    22,    32,   185,  -270,
    -270,   618,  -270,  -270,   572,   188,    90,  -270,  -270,  -270,
     618,  -270,  -270,   505,  -270,   572,  -270,  -270,  -270,  -270,
     164,   178,  -270,  -270,   177,  -270,   194,   197,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,   141,   141,  -270,  -270,   618,
    -270,   618,   121,   183,   184,  -270,  -270,   618,   186,   168,
     187,  -270,   309,  -270,   190,  -270,   193,   198,   229,  -270,
    -270,   200,    63,    55,  -270,   199,   224,   341,   124,  -270,
    -270,  -270,   220,  -270,   123,  -270,  -270,  -270,   572,   618,
    -270,  -270,   618,  -270,  -270,   470,  -270,   618,  -270,   595,
      81,   309,   309,   309,   203,   384,   230,   232,   341,  -270,
     233,   618,   210,   244,  -270,  -270,  -270,   618,  -270,  -270,
    -270,  -270,  -270,  -270,   118,   235,   236,  -270,   309,   384,
      89,  -270,   214,  -270,  -270,  -270,   341,   384,   176,   215,
     618,  -270,   239,   218,  -270,  -270,   251,  -270,   341,  -270,
     101,   618,  -270,  -270,  -270,  -270,   222,   223,   309,  -270,
    -270,   256,  -270,   176,   309,  -270,  -270,  -270,  -270,  -270,
    -270,   309,   309,    81,  -270,   122,   225,  -270,  -270,   309,
    -270
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,   145,   141,     0,     2,     0,     0,    48,
      49,    50,     0,     0,     0,     0,     0,   144,   146,   142,
       0,   127,   128,     0,   129,     0,     0,     0,     4,    63,
       6,    20,     0,    24,    26,    33,    34,    38,    40,    27,
      45,    46,    47,    28,    29,    30,    21,    65,    60,    61,
      62,    42,    82,     0,    83,     0,    87,    92,    43,    93,
     107,   109,   111,   113,   115,   118,     0,   126,   130,   132,
     143,    64,     7,    67,    66,    68,     0,     0,   172,   171,
       0,   167,   169,    91,    51,     0,     0,    52,    54,    56,
     147,   136,   153,   154,     0,   149,   151,   106,     0,   140,
     187,   188,     0,   185,   178,   189,   181,   138,     0,     1,
       8,    23,     0,    44,     0,     0,    31,     0,    39,     0,
       0,   102,     0,    95,    96,    97,    98,    99,   100,   101,
     104,     0,     0,     0,     0,     0,     0,     0,   124,   120,
     122,   123,   121,     0,   125,     0,     0,     0,     0,   133,
       2,     0,     0,   168,     0,     0,     0,     0,     0,    53,
      55,     0,    57,   135,   150,     0,     0,   207,   148,   184,
       0,   139,   177,   179,   180,   182,   137,    22,    25,    35,
      34,    36,   175,    32,   173,    41,    84,    88,   103,   105,
      94,   108,   110,   112,   114,   116,   117,   119,   131,     0,
     155,     0,   198,     0,   194,   196,   134,   163,   162,     0,
     158,   160,     0,     2,     0,   170,     0,     0,     0,    76,
     191,    18,     0,     0,    14,    16,     0,     0,    58,   216,
     152,   208,     0,   183,     0,   186,   187,   190,     0,   174,
     201,   202,     0,   199,   156,   195,   164,   165,   157,   159,
      69,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,   211,     9,    59,     0,    37,   176,
     200,   197,   166,   161,     0,    72,    74,   192,     0,   214,
       0,    19,     0,    12,    15,    17,     0,     0,   205,     0,
       0,    71,     0,     0,   193,   215,     0,    77,     0,    10,
       0,     0,   206,   203,   204,     2,     0,     0,     0,    78,
      11,     0,   212,   209,     0,     2,     2,    75,   213,   210,
      70,     0,     0,    79,    73,     0,     0,    80,     2,     0,
      81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,  -141,  -269,  -270,    15,   262,  -270,  -270,     5,  -270,
    -169,     0,  -270,   154,  -270,   153,  -270,    -9,  -270,   150,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,   -81,  -270,
    -270,  -270,  -270,  -270,   267,  -202,   -55,    -2,  -228,  -270,
     152,  -270,    -4,   143,  -270,     1,    13,   140,   138,   147,
    -270,    12,  -270,   -61,  -270,  -270,  -270,  -270,   257,   250,
    -270,   113,  -270,  -270,  -270,    29,   127,  -270,   131,   144,
    -270,  -270,   110,  -270,   145,  -270,  -270,   159,  -270,    40,
     -21,   132,   -74,  -270,  -246,  -196,  -270
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    77,   274,    27,    28,    29,   157,   223,   224,   225,
      30,   219,    32,    33,    34,    35,   116,    36,    37,    38,
     117,    39,    40,    41,    42,    43,    44,    45,   159,    46,
      47,    74,    48,    49,    50,   220,   291,    51,    52,    53,
      54,    55,    56,    57,   131,    58,    59,    60,    61,    62,
      63,    64,   143,    65,    66,    67,    68,    69,    70,    94,
      95,    96,   149,   209,   210,   211,    80,    81,    82,   183,
     184,   102,   103,   104,   105,   106,    71,   203,   204,   205,
     302,   167,   303,   304,   265,   280,   162
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    31,    84,    76,    83,   144,   292,   160,    78,   212,
     250,   145,   283,   111,    89,   113,    72,    18,    92,   109,
      79,    93,   168,   100,    92,   121,   101,    93,   122,   172,
      31,   174,     7,    85,   165,   221,    97,   146,   154,   288,
     299,    13,   155,   226,   114,   110,   115,   112,   166,   275,
     276,   277,   310,   147,   325,    98,   148,   222,    86,     3,
       4,   123,   124,   125,   126,   127,   128,   129,   130,     8,
     227,    87,   251,   313,   257,   151,   294,   135,    17,    18,
      19,    20,   197,   295,   198,    88,   279,    21,    22,    23,
     259,   300,   296,    24,   260,   297,    -3,    -3,    25,    99,
      26,   258,     3,     4,   311,   180,   317,   312,   136,   137,
     279,   169,   320,   181,   118,   182,   187,   119,   279,   323,
     324,    17,    18,    19,    20,   165,   -86,   330,   243,   120,
      21,    22,    23,   289,   290,   -90,    24,   326,   290,   166,
     132,    25,   133,    26,   202,   191,   208,   266,   195,   196,
     182,   138,   202,   134,    78,   150,   152,   242,   153,   229,
     156,   170,    92,   158,   314,    93,    79,    78,   233,   161,
     163,   234,   164,   236,   321,   322,   101,   171,   173,    79,
     165,   175,   177,   139,   140,   141,   142,   329,   176,   188,
     301,     3,     4,   189,   166,   206,   213,   240,   228,   241,
     114,     8,     9,    10,    11,   246,   166,    14,    15,    16,
      17,    18,    19,    20,   238,   -85,   239,   -89,   244,    21,
      22,    23,   248,   245,   247,    24,   249,   264,   252,   268,
      25,   253,    26,   254,   255,   261,   262,   269,   256,   267,
     270,   278,   281,   202,   282,   272,   221,   208,   286,   287,
      -3,   293,   298,   305,   307,    31,   308,   309,   264,   285,
     315,   316,   318,   328,    73,   284,   178,   179,   185,    75,
     327,   186,   193,   192,   190,    90,   108,   230,   273,    31,
       1,     2,   194,   235,   215,   271,   264,    31,   306,     3,
       4,     5,   319,   232,     6,     7,   214,   231,   264,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   218,   217,     0,     0,     0,    21,    22,    23,
     237,     3,     4,    24,     0,     0,     0,     0,    25,     0,
      26,     8,     9,    10,    11,     0,     0,    14,    15,    16,
      17,    18,    19,    20,   263,     0,     0,     0,     0,    21,
      22,    23,     0,     3,     4,    24,     0,     0,     0,     0,
      25,     0,    26,     8,     9,    10,    11,     0,     0,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,    21,    22,    23,     0,     0,     0,    24,     2,     0,
       0,     0,    25,     0,    26,     0,     3,     4,     5,     0,
       0,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,    21,    22,    23,   199,     0,     0,
      24,     3,     4,     0,     0,    25,     0,    26,     0,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,    20,   200,     0,     0,     0,     0,    21,
      22,   201,   199,     0,     0,    24,     3,     4,     0,     0,
      25,     0,    26,     0,     0,     0,     8,     0,   199,     0,
       0,     0,     3,     4,     0,    17,    18,    19,    20,   216,
       0,     0,     8,     0,    21,    22,   201,     0,     0,     0,
      24,    17,    18,    19,    20,    25,     0,    26,     0,     0,
      21,    22,   201,    98,     0,     0,    24,     3,     4,     0,
       0,    25,     0,    26,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     3,     4,     0,    17,    18,    19,    20,
       0,     0,     0,     8,     0,    21,    22,     0,     0,     0,
       0,    24,    17,    18,    19,    20,    25,     0,    26,     3,
       4,    21,    22,    23,     0,     0,     0,    24,     0,     8,
       0,     0,    25,     0,    26,   107,     0,     0,    17,    18,
      19,    20,    91,     0,     3,     4,     0,    21,    22,    23,
       0,     0,     0,    24,     8,     0,     0,     0,    25,     0,
      26,     0,     0,    17,    18,    19,    20,     3,     4,     0,
       0,     0,    21,    22,    23,     0,     0,     8,    24,     0,
       0,     0,     0,    25,     0,    26,    17,    18,    19,    20,
       3,     4,     0,   207,     0,    21,    22,     0,     0,     0,
       8,    24,     0,     0,     0,     0,    25,     0,    26,    17,
      18,    19,    20,     3,     4,     0,     0,     0,    21,    22,
       0,     0,     0,     0,    24,     0,     0,     0,     0,    25,
       0,    26,    17,    18,    19,    20,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,    24,     0,     0,
       0,     0,    25,     0,    26
};

static const yytype_int16 yycheck[] =
{
       0,     1,    11,     5,     8,    66,   275,    88,     7,   150,
     212,     8,   258,     3,    16,     7,     1,    32,    20,     0,
       7,    20,    96,    25,    26,    19,    25,    26,    22,   103,
      30,   105,    18,    13,     4,    13,    23,    34,    34,   267,
     286,    27,    38,    11,    36,    30,    38,    37,    18,   251,
     252,   253,   298,    50,   323,     8,    53,    35,    13,    12,
      13,    55,    56,    57,    58,    59,    60,    61,    62,    22,
      38,    13,   213,   301,    11,    77,   278,     9,    31,    32,
      33,    34,   143,   279,   145,    13,   255,    40,    41,    42,
      35,   287,     3,    46,    39,     6,    15,    16,    51,    52,
      53,    38,    12,    13,     3,   114,   308,     6,    40,    41,
     279,    98,   314,   115,    39,   117,   120,    21,   287,   321,
     322,    31,    32,    33,    34,     4,    21,   329,   202,    20,
      40,    41,    42,    15,    16,    20,    46,    15,    16,    18,
      48,    51,    49,    53,   146,   132,   148,   228,   136,   137,
     152,    10,   154,    47,   153,    38,    19,    36,    39,   161,
      34,    38,   164,    39,   305,   164,   153,   166,   170,    39,
      35,   173,    39,   175,   315,   316,   175,    52,    39,   166,
       4,    39,     3,    42,    43,    44,    45,   328,    54,    19,
      14,    12,    13,    22,    18,    13,    38,   199,    13,   201,
      36,    22,    23,    24,    25,   207,    18,    28,    29,    30,
      31,    32,    33,    34,    36,    21,    39,    20,    35,    40,
      41,    42,    54,    39,    38,    46,    39,   227,    38,   238,
      51,    38,    53,    35,     5,    36,    12,   239,    38,    19,
     242,    38,    12,   245,    12,   247,    13,   249,    38,     5,
      15,    15,    38,    38,    15,   255,    38,     6,   258,   261,
      38,    38,     6,    38,     2,   260,   112,   114,   118,     2,
     325,   119,   134,   133,   131,    18,    26,   164,   249,   279,
       3,     4,   135,   173,   153,   245,   286,   287,   290,    12,
      13,    14,   313,   166,    17,    18,   152,   165,   298,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     3,   154,    -1,    -1,    -1,    40,    41,    42,
     175,    12,    13,    46,    -1,    -1,    -1,    -1,    51,    -1,
      53,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,     3,    -1,    -1,    -1,    -1,    40,
      41,    42,    -1,    12,    13,    46,    -1,    -1,    -1,    -1,
      51,    -1,    53,    22,    23,    24,    25,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    -1,    46,     4,    -1,
      -1,    -1,    51,    -1,    53,    -1,    12,    13,    14,    -1,
      -1,    17,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,     8,    -1,    -1,
      46,    12,    13,    -1,    -1,    51,    -1,    53,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,
      41,    42,     8,    -1,    -1,    46,    12,    13,    -1,    -1,
      51,    -1,    53,    -1,    -1,    -1,    22,    -1,     8,    -1,
      -1,    -1,    12,    13,    -1,    31,    32,    33,    34,    35,
      -1,    -1,    22,    -1,    40,    41,    42,    -1,    -1,    -1,
      46,    31,    32,    33,    34,    51,    -1,    53,    -1,    -1,
      40,    41,    42,     8,    -1,    -1,    46,    12,    13,    -1,
      -1,    51,    -1,    53,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    12,    13,    -1,    31,    32,    33,    34,
      -1,    -1,    -1,    22,    -1,    40,    41,    -1,    -1,    -1,
      -1,    46,    31,    32,    33,    34,    51,    -1,    53,    12,
      13,    40,    41,    42,    -1,    -1,    -1,    46,    -1,    22,
      -1,    -1,    51,    -1,    53,    54,    -1,    -1,    31,    32,
      33,    34,    35,    -1,    12,    13,    -1,    40,    41,    42,
      -1,    -1,    -1,    46,    22,    -1,    -1,    -1,    51,    -1,
      53,    -1,    -1,    31,    32,    33,    34,    12,    13,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    22,    46,    -1,
      -1,    -1,    -1,    51,    -1,    53,    31,    32,    33,    34,
      12,    13,    -1,    38,    -1,    40,    41,    -1,    -1,    -1,
      22,    46,    -1,    -1,    -1,    -1,    51,    -1,    53,    31,
      32,    33,    34,    12,    13,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,
      -1,    53,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    12,    13,    14,    17,    18,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    40,    41,    42,    46,    51,    53,    66,    67,    68,
      73,    74,    75,    76,    77,    78,    80,    81,    82,    84,
      85,    86,    87,    88,    89,    90,    92,    93,    95,    96,
      97,   100,   101,   102,   103,   104,   105,   106,   108,   109,
     110,   111,   112,   113,   114,   116,   117,   118,   119,   120,
     121,   139,    67,    68,    94,    97,   100,    64,   108,   109,
     129,   130,   131,   105,    80,    13,    13,    13,    13,   100,
     121,    35,   100,   108,   122,   123,   124,   109,     8,    52,
     100,   108,   134,   135,   136,   137,   138,    54,   122,     0,
      67,     3,    37,     7,    36,    38,    79,    83,    39,    21,
      20,    19,    22,    55,    56,    57,    58,    59,    60,    61,
      62,   107,    48,    49,    47,     9,    40,    41,    10,    42,
      43,    44,    45,   115,   116,     8,    34,    50,    53,   125,
      38,   100,    19,    39,    34,    38,    34,    69,    39,    91,
      91,    39,   149,    35,    39,     4,    18,   144,   145,   109,
      38,    52,   145,    39,   145,    39,    54,     3,    76,    78,
      80,   100,   100,   132,   133,    82,   103,   105,    19,    22,
     106,   109,   110,   111,   112,   114,   114,   116,   116,     8,
      35,    42,   100,   140,   141,   142,    13,    38,   100,   126,
     127,   128,    64,    38,   132,   131,    35,   140,     3,    74,
      98,    13,    35,    70,    71,    72,    11,    38,    13,   100,
     124,   144,   129,   100,   100,   135,   100,   137,    36,    39,
     100,   100,    36,   145,    35,    39,   100,    38,    54,    39,
      98,    64,    38,    38,    35,     5,    38,    11,    38,    35,
      39,    36,    12,     3,    74,   147,    91,    19,    80,   100,
     100,   142,   100,   128,    65,    98,    98,    98,    38,    73,
     148,    12,    12,   147,    71,   100,    38,     5,   101,    15,
      16,    99,    65,    15,    98,   148,     3,     6,    38,   147,
     148,    14,   143,   145,   146,    38,   100,    15,    38,     6,
     147,     3,     6,   101,    64,    38,    38,    98,     6,   143,
      98,    64,    64,    98,    98,    65,    15,    99,    38,    64,
      98
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    66,    67,    67,    67,    67,    68,
      68,    68,    68,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    76,    76,
      76,    77,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    84,    84,    84,    85,    86,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    92,    92,    92,    92,    93,    94,    94,    95,
      95,    95,    96,    96,    97,    97,    98,    98,    98,    99,
      99,    99,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   116,   116,   117,   117,   117,
     118,   118,   119,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     122,   123,   123,   124,   124,   125,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   128,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   134,
     134,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   139,   140,   140,   141,   141,   142,   142,
     142,   142,   142,   143,   143,   144,   144,   145,   145,   146,
     146,   147,   147,   147,   148,   148,   149
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     2,     2,     5,
       7,     8,     6,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     3,     2,     1,     3,     1,     1,     1,     1,
       1,     2,     3,     1,     1,     3,     2,     4,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     2,     3,     2,     3,     2,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     5,
      10,     7,     6,    11,     6,     9,     1,     4,     5,     5,
       7,    10,     1,     1,     3,     3,     1,     1,     3,     3,
       1,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     2,     3,     3,     2,     3,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     1,     3,     1,     1,     2,     3,     3,     1,     2,
       1,     3,     1,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     1,     1,     2,     1,     3,     2,     1,     2,
       2,     1,     2,     3,     2,     1,     3,     1,     1,     1,
       3,     4,     6,     7,     1,     2,     1,     3,     1,     2,
       3,     2,     2,     1,     1,     4,     5,     1,     2,     2,
       3,     1,     4,     5,     1,     2,     2
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
#line 136 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal M");
        (yyval.elem)->ins = instCount+1;
}
#line 1611 "parser.tab.c"
    break;

  case 3: /* N: %empty  */
#line 142 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal N");
        (yyval.elem)->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
#line 1621 "parser.tab.c"
    break;

  case 4: /* file: snippet  */
#line 149 "parser.y"
              {
                (yyval.elem) = (yyvsp[0].elem);
 }
#line 1629 "parser.tab.c"
    break;

  case 5: /* snippet: NEWLINE  */
#line 154 "parser.y"
                 {
       
    }
#line 1637 "parser.tab.c"
    break;

  case 6: /* snippet: stmt  */
#line 157 "parser.y"
            { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1645 "parser.tab.c"
    break;

  case 7: /* snippet: NEWLINE snippet  */
#line 160 "parser.y"
                       { 
        
    }
#line 1653 "parser.tab.c"
    break;

  case 8: /* snippet: stmt snippet  */
#line 163 "parser.y"
                   {  
        
    }
#line 1661 "parser.tab.c"
    break;

  case 9: /* funcdef: DEF NAME parameters COLON func_body_suite  */
#line 168 "parser.y"
                                                    {  
            

        }
#line 1670 "parser.tab.c"
    break;

  case 10: /* funcdef: DEF NAME parameters ARROW_OPER TYPE_HINT COLON func_body_suite  */
#line 172 "parser.y"
                                                                         {  
            
        }
#line 1678 "parser.tab.c"
    break;

  case 11: /* funcdef: DEF NAME OPEN_BRACKET CLOSE_BRACKET ARROW_OPER TYPE_HINT COLON func_body_suite  */
#line 175 "parser.y"
                                                                                         {  
            
        }
#line 1686 "parser.tab.c"
    break;

  case 12: /* funcdef: DEF NAME OPEN_BRACKET CLOSE_BRACKET COLON func_body_suite  */
#line 178 "parser.y"
                                                                    {
            
        }
#line 1694 "parser.tab.c"
    break;

  case 13: /* parameters: OPEN_BRACKET typedargslist CLOSE_BRACKET  */
#line 183 "parser.y"
                                                     {  
            
            
        }
#line 1703 "parser.tab.c"
    break;

  case 14: /* typedargslist: typedarg  */
#line 189 "parser.y"
                            {  
            
        }
#line 1711 "parser.tab.c"
    break;

  case 15: /* typedargslist: typedargslist COMMA typedarg  */
#line 192 "parser.y"
                                         {  
            
        }
#line 1719 "parser.tab.c"
    break;

  case 16: /* typedarg: tfpdef  */
#line 197 "parser.y"
                   {  
            
        }
#line 1727 "parser.tab.c"
    break;

  case 17: /* typedarg: tfpdef EQUAL test  */
#line 200 "parser.y"
                            {  
            
        }
#line 1735 "parser.tab.c"
    break;

  case 18: /* tfpdef: NAME  */
#line 205 "parser.y"
             {  
            
        }
#line 1743 "parser.tab.c"
    break;

  case 19: /* tfpdef: NAME COLON TYPE_HINT  */
#line 208 "parser.y"
                               {  
                
        }
#line 1751 "parser.tab.c"
    break;

  case 20: /* stmt: simple_stmt  */
#line 213 "parser.y"
                        { 

        }
#line 1759 "parser.tab.c"
    break;

  case 21: /* stmt: compound_stmt  */
#line 216 "parser.y"
                            { 
             (yyval.elem)=(yyvsp[0].elem); 
        }
#line 1767 "parser.tab.c"
    break;

  case 22: /* simple_stmt: small_stmt_list SEMI_COLON NEWLINE  */
#line 221 "parser.y"
                                                {  
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 1775 "parser.tab.c"
    break;

  case 23: /* simple_stmt: small_stmt_list NEWLINE  */
#line 224 "parser.y"
                                   {  
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 1783 "parser.tab.c"
    break;

  case 24: /* small_stmt_list: small_stmt  */
#line 229 "parser.y"
                                {   
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1791 "parser.tab.c"
    break;

  case 25: /* small_stmt_list: small_stmt_list SEMI_COLON small_stmt  */
#line 232 "parser.y"
                                                     {  
           
        }
#line 1799 "parser.tab.c"
    break;

  case 26: /* small_stmt: expr_stmt  */
#line 237 "parser.y"
                            {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1807 "parser.tab.c"
    break;

  case 27: /* small_stmt: flow_stmt  */
#line 240 "parser.y"
                        {  
           
        }
#line 1815 "parser.tab.c"
    break;

  case 28: /* small_stmt: global_stmt  */
#line 243 "parser.y"
                            {  
            
        }
#line 1823 "parser.tab.c"
    break;

  case 29: /* small_stmt: nonlocal_stmt  */
#line 246 "parser.y"
                            {  
            
        }
#line 1831 "parser.tab.c"
    break;

  case 30: /* small_stmt: assert_stmt  */
#line 249 "parser.y"
                            {  
            
        }
#line 1839 "parser.tab.c"
    break;

  case 31: /* expr_stmt: testlist_star_expr annassign  */
#line 254 "parser.y"
                                         {   
           
        }
#line 1847 "parser.tab.c"
    break;

  case 32: /* expr_stmt: testlist_star_expr augassign testlist  */
#line 257 "parser.y"
                                                {  
            
        }
#line 1855 "parser.tab.c"
    break;

  case 33: /* expr_stmt: eq_testlist_star_expr_plus  */
#line 260 "parser.y"
                                     { 
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1863 "parser.tab.c"
    break;

  case 34: /* eq_testlist_star_expr_plus: testlist_star_expr  */
#line 265 "parser.y"
                                               {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1871 "parser.tab.c"
    break;

  case 35: /* eq_testlist_star_expr_plus: testlist_star_expr EQUAL eq_testlist_star_expr_plus  */
#line 268 "parser.y"
                                                               { 
			create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-2].elem)->ins;
			create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
        }
#line 1881 "parser.tab.c"
    break;

  case 36: /* annassign: COLON test  */
#line 275 "parser.y"
                        {  
            
        }
#line 1889 "parser.tab.c"
    break;

  case 37: /* annassign: COLON test EQUAL testlist_star_expr  */
#line 278 "parser.y"
                                                {  
            
        }
#line 1897 "parser.tab.c"
    break;

  case 38: /* testlist_star_expr: expr_choice_list  */
#line 283 "parser.y"
                                     {  
          (yyval.elem)=(yyvsp[0].elem);
        }
#line 1905 "parser.tab.c"
    break;

  case 39: /* testlist_star_expr: expr_choice_list COMMA  */
#line 286 "parser.y"
                                  {   
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 1913 "parser.tab.c"
    break;

  case 40: /* expr_choice_list: expr_choice  */
#line 291 "parser.y"
                                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1921 "parser.tab.c"
    break;

  case 41: /* expr_choice_list: expr_choice_list COMMA expr_choice  */
#line 294 "parser.y"
                                                { 
            
        }
#line 1929 "parser.tab.c"
    break;

  case 42: /* expr_choice: test  */
#line 299 "parser.y"
                    {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1937 "parser.tab.c"
    break;

  case 43: /* expr_choice: star_expr  */
#line 302 "parser.y"
                      {  
            
        }
#line 1945 "parser.tab.c"
    break;

  case 44: /* augassign: ASSIGN_OPERATOR  */
#line 307 "parser.y"
                            {  
           
        }
#line 1953 "parser.tab.c"
    break;

  case 45: /* flow_stmt: break_stmt  */
#line 312 "parser.y"
                        {  
            
        }
#line 1961 "parser.tab.c"
    break;

  case 46: /* flow_stmt: continue_stmt  */
#line 315 "parser.y"
                            {  
            
        }
#line 1969 "parser.tab.c"
    break;

  case 47: /* flow_stmt: return_stmt  */
#line 318 "parser.y"
                         {  
            
        }
#line 1977 "parser.tab.c"
    break;

  case 48: /* break_stmt: BREAK  */
#line 323 "parser.y"
                    {  
            
        }
#line 1985 "parser.tab.c"
    break;

  case 49: /* continue_stmt: CONTINUE  */
#line 327 "parser.y"
                            {  
            
        }
#line 1993 "parser.tab.c"
    break;

  case 50: /* return_stmt: RETURN  */
#line 331 "parser.y"
                        {  
            
        }
#line 2001 "parser.tab.c"
    break;

  case 51: /* return_stmt: RETURN testlist_star_expr  */
#line 334 "parser.y"
                                        {  
           
        }
#line 2009 "parser.tab.c"
    break;

  case 52: /* global_stmt: GLOBAL NAME  */
#line 339 "parser.y"
                            {  
            
        }
#line 2017 "parser.tab.c"
    break;

  case 53: /* global_stmt: GLOBAL NAME comma_name_star  */
#line 342 "parser.y"
                                      {   
            
        }
#line 2025 "parser.tab.c"
    break;

  case 54: /* nonlocal_stmt: NONLOCAL NAME  */
#line 346 "parser.y"
                                 { 
            
            
        }
#line 2034 "parser.tab.c"
    break;

  case 55: /* nonlocal_stmt: NONLOCAL NAME comma_name_star  */
#line 350 "parser.y"
                                        {  
            
        }
#line 2042 "parser.tab.c"
    break;

  case 56: /* assert_stmt: ASSERT test  */
#line 355 "parser.y"
                          {  
            
        }
#line 2050 "parser.tab.c"
    break;

  case 57: /* assert_stmt: ASSERT test comma_test  */
#line 358 "parser.y"
                                  {  
           
        }
#line 2058 "parser.tab.c"
    break;

  case 58: /* comma_name_star: COMMA NAME  */
#line 362 "parser.y"
                               {  
           
        }
#line 2066 "parser.tab.c"
    break;

  case 59: /* comma_name_star: COMMA NAME comma_name_star  */
#line 365 "parser.y"
                                        {  
            
        }
#line 2074 "parser.tab.c"
    break;

  case 60: /* compound_stmt: if_stmt  */
#line 369 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);  
        }
#line 2082 "parser.tab.c"
    break;

  case 61: /* compound_stmt: while_stmt  */
#line 372 "parser.y"
                       {  
           
        }
#line 2090 "parser.tab.c"
    break;

  case 62: /* compound_stmt: for_stmt  */
#line 375 "parser.y"
                       {  
            
        }
#line 2098 "parser.tab.c"
    break;

  case 63: /* compound_stmt: funcdef  */
#line 378 "parser.y"
                       {  
            
        }
#line 2106 "parser.tab.c"
    break;

  case 64: /* compound_stmt: classdef  */
#line 381 "parser.y"
                       {  
           
        }
#line 2114 "parser.tab.c"
    break;

  case 65: /* compound_stmt: async_stmt  */
#line 384 "parser.y"
                       {  
            
        }
#line 2122 "parser.tab.c"
    break;

  case 66: /* async_stmt: ASYNC async_choice  */
#line 388 "parser.y"
                                {  
            
        }
#line 2130 "parser.tab.c"
    break;

  case 67: /* async_choice: funcdef  */
#line 392 "parser.y"
                        { 
            
        }
#line 2138 "parser.tab.c"
    break;

  case 68: /* async_choice: for_stmt  */
#line 395 "parser.y"
                    {  
            
        }
#line 2146 "parser.tab.c"
    break;

  case 69: /* if_stmt: IF test COLON M suite  */
#line 400 "parser.y"
                                                                                                            {  
           // add_children($$,3,$3,$5,$6);
           (yyval.elem)=create_node(6, "if_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
           (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
        //    cout<<$$->ins<<endl;
           backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
           (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);
        }
#line 2159 "parser.tab.c"
    break;

  case 70: /* if_stmt: IF test COLON M suite N ELSE COLON M suite  */
#line 408 "parser.y"
                                                       {  
            (yyval.elem) = create_node(11, "if_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            vector<int> temp = merge((yyvsp[-5].elem)->nextlist, (yyvsp[-4].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);
        }
#line 2171 "parser.tab.c"
    break;

  case 71: /* if_stmt: IF test COLON M suite N nts_star  */
#line 415 "parser.y"
                                              {  
            (yyval.elem) = create_node(8, "if_elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);      //$7->ins is needed in place of $7->nextlist
            vector<int> temp = merge((yyvsp[-2].elem)->nextlist, (yyvsp[-1].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);
        }
#line 2183 "parser.tab.c"
    break;

  case 72: /* while_stmt: WHILE M test COLON M suite  */
#line 429 "parser.y"
                                         {  
            (yyval.elem) = create_node(7, "while_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            // cout<<"check "<<$6->nextlist.size()<<endl;
            backpatch((yyvsp[0].elem)->nextlist, (yyvsp[-4].elem)->ins);
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = (yyvsp[-3].elem)->falselist;
            create_ins(0, "goto", to_string((yyvsp[-4].elem)->ins), "", "");
        }
#line 2197 "parser.tab.c"
    break;

  case 73: /* while_stmt: WHILE M test COLON M suite N ELSE COLON M suite  */
#line 438 "parser.y"
                                                                   {   
			(yyval.elem) = create_node(12, "while_else_stmt", (yyvsp[-10].elem), (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-9].elem)->ins;
			backpatch((yyvsp[-4].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-5].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
			backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
			(yyval.elem)->nextlist = merge((yyvsp[-4].elem)->nextlist, (yyvsp[0].elem)->nextlist); //verify
        }
#line 2211 "parser.tab.c"
    break;

  case 74: /* for_stmt: FOR exprlist IN testlist COLON suite  */
#line 448 "parser.y"
                                                  { 
            
        }
#line 2219 "parser.tab.c"
    break;

  case 75: /* for_stmt: FOR exprlist IN testlist COLON suite ELSE COLON suite  */
#line 451 "parser.y"
                                                                  { 
            
        }
#line 2227 "parser.tab.c"
    break;

  case 76: /* suite: simple_stmt  */
#line 455 "parser.y"
                    { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2235 "parser.tab.c"
    break;

  case 77: /* suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 458 "parser.y"
                                            { 
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 2243 "parser.tab.c"
    break;

  case 78: /* suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 461 "parser.y"
                                                    { 
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 2251 "parser.tab.c"
    break;

  case 79: /* nts_star: ELIF test COLON M suite  */
#line 481 "parser.y"
                                    {  
            (yyval.elem)=create_node(6, "elif_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);
        }
#line 2262 "parser.tab.c"
    break;

  case 80: /* nts_star: ELIF test COLON M suite N nts_star  */
#line 487 "parser.y"
                                              {  
            (yyval.elem) = create_node(8, "elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-5].elem)->ins;
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist));
        }
#line 2274 "parser.tab.c"
    break;

  case 81: /* nts_star: ELIF test COLON M suite N ELSE COLON M suite  */
#line 494 "parser.y"
                                                        {  
            (yyval.elem) = create_node(11, "elif_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-8].elem)->ins;
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-5].elem)->nextlist, merge((yyvsp[-4].elem)->nextlist,(yyvsp[0].elem)->nextlist));
        }
#line 2286 "parser.tab.c"
    break;

  case 82: /* test: or_test  */
#line 503 "parser.y"
                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2294 "parser.tab.c"
    break;

  case 83: /* or_test: and_test  */
#line 510 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2302 "parser.tab.c"
    break;

  case 84: /* or_test: and_test_star OR and_test  */
#line 513 "parser.y"
                                       {  
            
        }
#line 2310 "parser.tab.c"
    break;

  case 85: /* and_test_star: and_test_star OR and_test  */
#line 517 "parser.y"
                                          {
            
        }
#line 2318 "parser.tab.c"
    break;

  case 86: /* and_test_star: and_test  */
#line 520 "parser.y"
                     { 
                
        }
#line 2326 "parser.tab.c"
    break;

  case 87: /* and_test: not_test  */
#line 525 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2334 "parser.tab.c"
    break;

  case 88: /* and_test: not_test_star AND not_test  */
#line 528 "parser.y"
                                        {  
            
        }
#line 2342 "parser.tab.c"
    break;

  case 89: /* not_test_star: not_test_star AND not_test  */
#line 532 "parser.y"
                                            { 
            
        }
#line 2350 "parser.tab.c"
    break;

  case 90: /* not_test_star: not_test  */
#line 535 "parser.y"
                     { 
            
        }
#line 2358 "parser.tab.c"
    break;

  case 91: /* not_test: NOT not_test  */
#line 540 "parser.y"
                         { 
            
        }
#line 2366 "parser.tab.c"
    break;

  case 92: /* not_test: comparison  */
#line 543 "parser.y"
                        { 
            (yyval.elem)=(yyvsp[0].elem);
            
        }
#line 2375 "parser.tab.c"
    break;

  case 93: /* comparison: expr  */
#line 549 "parser.y"
                  {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2383 "parser.tab.c"
    break;

  case 94: /* comparison: expr comp_op comparison  */
#line 552 "parser.y"
                                                                                                               { 
            (yyval.elem)=create_node(4, "comparison", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            /*add_children($$,3,$2,$3,$4); */
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            (yyval.elem)->truelist = makelist(instCount+1);
        //     cout<<$$->truelist.size()+5<<endl;
            (yyval.elem)->falselist = makelist(instCount+2);
            create_ins(0, "if", (yyval.elem)->addr, "goto", "");
            create_ins(0, "goto", "", "", "");
            
        }
#line 2401 "parser.tab.c"
    break;

  case 95: /* comp_op: LESS_THAN  */
#line 567 "parser.y"
                    {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2409 "parser.tab.c"
    break;

  case 96: /* comp_op: GREATER_THAN  */
#line 570 "parser.y"
                    { 
       (yyval.elem) = (yyvsp[0].elem);
     }
#line 2417 "parser.tab.c"
    break;

  case 97: /* comp_op: EQUAL_EQUAL  */
#line 573 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2425 "parser.tab.c"
    break;

  case 98: /* comp_op: GREATER_THAN_EQUAL  */
#line 576 "parser.y"
                            { 
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2433 "parser.tab.c"
    break;

  case 99: /* comp_op: LESS_THAN_EQUAL  */
#line 579 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2441 "parser.tab.c"
    break;

  case 100: /* comp_op: NOT_EQUAL_ARROW  */
#line 582 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
      }
#line 2449 "parser.tab.c"
    break;

  case 101: /* comp_op: NOT_EQUAL  */
#line 585 "parser.y"
                   {
       (yyval.elem) = (yyvsp[0].elem);
     }
#line 2457 "parser.tab.c"
    break;

  case 102: /* comp_op: IN  */
#line 588 "parser.y"
            {  
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2465 "parser.tab.c"
    break;

  case 103: /* comp_op: NOT IN  */
#line 591 "parser.y"
                { 
        (yyval.elem) = create_node(3, "NOT IN", (yyvsp[-1].elem), (yyvsp[0].elem));
     }
#line 2473 "parser.tab.c"
    break;

  case 104: /* comp_op: IS  */
#line 594 "parser.y"
            { 
        (yyval.elem) = (yyvsp[0].elem);
     }
#line 2481 "parser.tab.c"
    break;

  case 105: /* comp_op: IS NOT  */
#line 597 "parser.y"
                { 
        (yyval.elem) = create_node(3, "IS NOT", (yyvsp[-1].elem), (yyvsp[0].elem));
     }
#line 2489 "parser.tab.c"
    break;

  case 106: /* star_expr: MULTIPLY expr  */
#line 602 "parser.y"
                            { 
            
        }
#line 2497 "parser.tab.c"
    break;

  case 107: /* expr: xor_expr  */
#line 607 "parser.y"
                  { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2505 "parser.tab.c"
    break;

  case 108: /* expr: xor_expr BIT_OR expr  */
#line 610 "parser.y"
                                  {  
            
        }
#line 2513 "parser.tab.c"
    break;

  case 109: /* xor_expr: and_expr  */
#line 615 "parser.y"
                   { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2521 "parser.tab.c"
    break;

  case 110: /* xor_expr: and_expr BIT_XOR xor_expr  */
#line 618 "parser.y"
                                       {  
            
        }
#line 2529 "parser.tab.c"
    break;

  case 111: /* and_expr: shift_expr  */
#line 623 "parser.y"
                       { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2538 "parser.tab.c"
    break;

  case 112: /* and_expr: shift_expr BIT_AND and_expr  */
#line 627 "parser.y"
                                        {  
            
        }
#line 2546 "parser.tab.c"
    break;

  case 113: /* shift_expr: arith_expr  */
#line 632 "parser.y"
                         { 
            (yyval.elem) = (yyvsp[0].elem);
                
            }
#line 2555 "parser.tab.c"
    break;

  case 114: /* shift_expr: arith_expr SHIFT_OPER shift_expr  */
#line 636 "parser.y"
                                                 { 
                
             }
#line 2563 "parser.tab.c"
    break;

  case 115: /* arith_expr: term  */
#line 641 "parser.y"
                 { 
            (yyval.elem) = (yyvsp[0].elem);
                
            }
#line 2572 "parser.tab.c"
    break;

  case 116: /* arith_expr: arith_expr PLUS term  */
#line 645 "parser.y"
                                   { 
                
            }
#line 2580 "parser.tab.c"
    break;

  case 117: /* arith_expr: arith_expr MINUS term  */
#line 648 "parser.y"
                                    { 
                
             }
#line 2588 "parser.tab.c"
    break;

  case 118: /* term: factor  */
#line 652 "parser.y"
             {
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2597 "parser.tab.c"
    break;

  case 119: /* term: term term_choice factor  */
#line 656 "parser.y"
                                  {
            
         }
#line 2605 "parser.tab.c"
    break;

  case 120: /* term_choice: MULTIPLY  */
#line 661 "parser.y"
                            { 
            
        }
#line 2613 "parser.tab.c"
    break;

  case 121: /* term_choice: ATTHERATE  */
#line 664 "parser.y"
                        { 
            
        }
#line 2621 "parser.tab.c"
    break;

  case 122: /* term_choice: DIVIDE  */
#line 667 "parser.y"
                        { 
            
        }
#line 2629 "parser.tab.c"
    break;

  case 123: /* term_choice: REMAINDER  */
#line 670 "parser.y"
                        { 
           
        }
#line 2637 "parser.tab.c"
    break;

  case 124: /* term_choice: FLOOR_DIV_OPER  */
#line 673 "parser.y"
                           { 
            
        }
#line 2645 "parser.tab.c"
    break;

  case 125: /* factor: factor_choice factor  */
#line 678 "parser.y"
                                    {  
            
        }
#line 2653 "parser.tab.c"
    break;

  case 126: /* factor: power  */
#line 681 "parser.y"
                    { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2662 "parser.tab.c"
    break;

  case 127: /* factor_choice: PLUS  */
#line 686 "parser.y"
                            {
            
        }
#line 2670 "parser.tab.c"
    break;

  case 128: /* factor_choice: MINUS  */
#line 689 "parser.y"
                     { 
            
        }
#line 2678 "parser.tab.c"
    break;

  case 129: /* factor_choice: NEGATION  */
#line 692 "parser.y"
                     { 
            
        }
#line 2686 "parser.tab.c"
    break;

  case 130: /* power: atom_expr  */
#line 696 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2695 "parser.tab.c"
    break;

  case 131: /* power: atom_expr POWER_OPERATOR factor  */
#line 700 "parser.y"
                                            { 
            
        }
#line 2703 "parser.tab.c"
    break;

  case 132: /* atom_expr: atom  */
#line 705 "parser.y"
                {  
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2712 "parser.tab.c"
    break;

  case 133: /* atom_expr: atom_expr trailer  */
#line 709 "parser.y"
                            {  
            
        }
#line 2720 "parser.tab.c"
    break;

  case 134: /* atom_expr: atom_expr DOT NAME  */
#line 712 "parser.y"
                             { 
            
        }
#line 2728 "parser.tab.c"
    break;

  case 135: /* atom: OPEN_BRACKET testlist_comp CLOSE_BRACKET  */
#line 717 "parser.y"
                                                { 
        (yyval.elem)=(yyvsp[-1].elem);
    }
#line 2736 "parser.tab.c"
    break;

  case 136: /* atom: OPEN_BRACKET CLOSE_BRACKET  */
#line 720 "parser.y"
                                    {
        
    }
#line 2744 "parser.tab.c"
    break;

  case 137: /* atom: SQUARE_OPEN testlist_comp SQUARE_CLOSE  */
#line 723 "parser.y"
                                                { 
        
    }
#line 2752 "parser.tab.c"
    break;

  case 138: /* atom: SQUARE_OPEN SQUARE_CLOSE  */
#line 726 "parser.y"
                                {
        
     }
#line 2760 "parser.tab.c"
    break;

  case 139: /* atom: CURLY_OPEN dictorsetmaker CURLY_CLOSE  */
#line 729 "parser.y"
                                                { 
        
    }
#line 2768 "parser.tab.c"
    break;

  case 140: /* atom: CURLY_OPEN CURLY_CLOSE  */
#line 732 "parser.y"
                                { 
        
     }
#line 2776 "parser.tab.c"
    break;

  case 141: /* atom: NAME  */
#line 735 "parser.y"
                {
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
     }
#line 2785 "parser.tab.c"
    break;

  case 142: /* atom: NUMBER  */
#line 739 "parser.y"
                    { 
        
    }
#line 2793 "parser.tab.c"
    break;

  case 143: /* atom: STRING_PLUS  */
#line 742 "parser.y"
                        { 
       
    }
#line 2801 "parser.tab.c"
    break;

  case 144: /* atom: ATOM_KEYWORDS  */
#line 745 "parser.y"
                        { 
        
    }
#line 2809 "parser.tab.c"
    break;

  case 145: /* atom: TYPE_HINT  */
#line 748 "parser.y"
                    { 
        
     }
#line 2817 "parser.tab.c"
    break;

  case 146: /* STRING_PLUS: STRING  */
#line 752 "parser.y"
                        {
            
        }
#line 2825 "parser.tab.c"
    break;

  case 147: /* STRING_PLUS: STRING STRING_PLUS  */
#line 755 "parser.y"
                                { 
            
        }
#line 2833 "parser.tab.c"
    break;

  case 148: /* testlist_comp: named_or_star comp_for  */
#line 760 "parser.y"
                                            { 
            
        }
#line 2841 "parser.tab.c"
    break;

  case 149: /* testlist_comp: named_or_star_list  */
#line 763 "parser.y"
                                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2849 "parser.tab.c"
    break;

  case 150: /* testlist_comp: named_or_star_list COMMA  */
#line 766 "parser.y"
                                        { 
            
        }
#line 2857 "parser.tab.c"
    break;

  case 151: /* named_or_star_list: named_or_star  */
#line 770 "parser.y"
                                        { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2865 "parser.tab.c"
    break;

  case 152: /* named_or_star_list: named_or_star_list COMMA named_or_star  */
#line 773 "parser.y"
                                                    { 
            
        }
#line 2873 "parser.tab.c"
    break;

  case 153: /* named_or_star: test  */
#line 777 "parser.y"
                        { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2881 "parser.tab.c"
    break;

  case 154: /* named_or_star: star_expr  */
#line 780 "parser.y"
                        { 
            
        }
#line 2889 "parser.tab.c"
    break;

  case 155: /* trailer: OPEN_BRACKET CLOSE_BRACKET  */
#line 785 "parser.y"
                                     { 
            
        }
#line 2897 "parser.tab.c"
    break;

  case 156: /* trailer: OPEN_BRACKET arglist CLOSE_BRACKET  */
#line 788 "parser.y"
                                              {
            
         }
#line 2905 "parser.tab.c"
    break;

  case 157: /* trailer: SQUARE_OPEN subscriptlist SQUARE_CLOSE  */
#line 791 "parser.y"
                                                        {
            
         }
#line 2913 "parser.tab.c"
    break;

  case 158: /* subscriptlist: subscriptlist_list  */
#line 796 "parser.y"
                                       {
            
        }
#line 2921 "parser.tab.c"
    break;

  case 159: /* subscriptlist: subscriptlist_list COMMA  */
#line 799 "parser.y"
                                       { 
            
        }
#line 2929 "parser.tab.c"
    break;

  case 160: /* subscriptlist_list: subscript  */
#line 803 "parser.y"
                                    { 
            
        }
#line 2937 "parser.tab.c"
    break;

  case 161: /* subscriptlist_list: subscriptlist_list COMMA subscript  */
#line 806 "parser.y"
                                                { 
            
        }
#line 2945 "parser.tab.c"
    break;

  case 162: /* subscript: test  */
#line 810 "parser.y"
                    { 
            
        }
#line 2953 "parser.tab.c"
    break;

  case 163: /* subscript: COLON  */
#line 813 "parser.y"
                    {  
            
        }
#line 2961 "parser.tab.c"
    break;

  case 164: /* subscript: COLON test  */
#line 816 "parser.y"
                         { 
            
        }
#line 2969 "parser.tab.c"
    break;

  case 165: /* subscript: test COLON  */
#line 819 "parser.y"
                         { 
            
        }
#line 2977 "parser.tab.c"
    break;

  case 166: /* subscript: test COLON test  */
#line 822 "parser.y"
                              {
            
        }
#line 2985 "parser.tab.c"
    break;

  case 167: /* exprlist: expr_or_star_expr_list  */
#line 826 "parser.y"
                                   {
            
        }
#line 2993 "parser.tab.c"
    break;

  case 168: /* exprlist: expr_or_star_expr_list COMMA  */
#line 829 "parser.y"
                                        { 
            
        }
#line 3001 "parser.tab.c"
    break;

  case 169: /* expr_or_star_expr_list: expr_or_star_expr  */
#line 833 "parser.y"
                                            { 
            
        }
#line 3009 "parser.tab.c"
    break;

  case 170: /* expr_or_star_expr_list: expr_or_star_expr_list COMMA expr_or_star_expr  */
#line 836 "parser.y"
                                                            { 
            
        }
#line 3017 "parser.tab.c"
    break;

  case 171: /* expr_or_star_expr: expr  */
#line 840 "parser.y"
                                { 
            
        }
#line 3025 "parser.tab.c"
    break;

  case 172: /* expr_or_star_expr: star_expr  */
#line 843 "parser.y"
                        { 
            
        }
#line 3033 "parser.tab.c"
    break;

  case 173: /* testlist: testlist_list  */
#line 847 "parser.y"
                           { 
            
        }
#line 3041 "parser.tab.c"
    break;

  case 174: /* testlist: testlist_list COMMA  */
#line 850 "parser.y"
                                {
            
         }
#line 3049 "parser.tab.c"
    break;

  case 175: /* testlist_list: test  */
#line 854 "parser.y"
                            {
            
        }
#line 3057 "parser.tab.c"
    break;

  case 176: /* testlist_list: testlist_list COMMA test  */
#line 857 "parser.y"
                                    { 
            
        }
#line 3065 "parser.tab.c"
    break;

  case 177: /* dictorsetmaker: A comp_for  */
#line 861 "parser.y"
                             {
            
        }
#line 3073 "parser.tab.c"
    break;

  case 178: /* dictorsetmaker: A_list  */
#line 864 "parser.y"
                    { 
            
        }
#line 3081 "parser.tab.c"
    break;

  case 179: /* dictorsetmaker: A_list COMMA  */
#line 867 "parser.y"
                          { 
            
        }
#line 3089 "parser.tab.c"
    break;

  case 180: /* dictorsetmaker: B comp_for  */
#line 870 "parser.y"
                           {
           
        }
#line 3097 "parser.tab.c"
    break;

  case 181: /* dictorsetmaker: B_list  */
#line 873 "parser.y"
                       {
            
         }
#line 3105 "parser.tab.c"
    break;

  case 182: /* dictorsetmaker: B_list COMMA  */
#line 876 "parser.y"
                            { 
            
        }
#line 3113 "parser.tab.c"
    break;

  case 183: /* A: test COLON test  */
#line 881 "parser.y"
                    { 
            
        }
#line 3121 "parser.tab.c"
    break;

  case 184: /* A: POWER_OPERATOR expr  */
#line 884 "parser.y"
                            { 
            
        }
#line 3129 "parser.tab.c"
    break;

  case 185: /* A_list: A  */
#line 888 "parser.y"
             { 
            
        }
#line 3137 "parser.tab.c"
    break;

  case 186: /* A_list: A_list COMMA A  */
#line 891 "parser.y"
                            { 
            
        }
#line 3145 "parser.tab.c"
    break;

  case 187: /* B: test  */
#line 895 "parser.y"
         {
                 
        }
#line 3153 "parser.tab.c"
    break;

  case 188: /* B: star_expr  */
#line 898 "parser.y"
                        { 
               
        }
#line 3161 "parser.tab.c"
    break;

  case 189: /* B_list: B  */
#line 902 "parser.y"
            { 
            
        }
#line 3169 "parser.tab.c"
    break;

  case 190: /* B_list: B_list COMMA B  */
#line 905 "parser.y"
                            { 
            
        }
#line 3177 "parser.tab.c"
    break;

  case 191: /* classdef: CLASS NAME COLON suite  */
#line 910 "parser.y"
                                      { 
            
        }
#line 3185 "parser.tab.c"
    break;

  case 192: /* classdef: CLASS NAME OPEN_BRACKET CLOSE_BRACKET COLON suite  */
#line 913 "parser.y"
                                                                 { 
            
        }
#line 3193 "parser.tab.c"
    break;

  case 193: /* classdef: CLASS NAME OPEN_BRACKET arglist CLOSE_BRACKET COLON suite  */
#line 916 "parser.y"
                                                                         { 
           
        }
#line 3201 "parser.tab.c"
    break;

  case 194: /* arglist: argument_list  */
#line 921 "parser.y"
                           { 
            
        }
#line 3209 "parser.tab.c"
    break;

  case 195: /* arglist: argument_list COMMA  */
#line 924 "parser.y"
                                 { 
           
        }
#line 3217 "parser.tab.c"
    break;

  case 196: /* argument_list: argument  */
#line 928 "parser.y"
                            { 
            
        }
#line 3225 "parser.tab.c"
    break;

  case 197: /* argument_list: argument_list COMMA argument  */
#line 931 "parser.y"
                                        { 
            
        }
#line 3233 "parser.tab.c"
    break;

  case 198: /* argument: test  */
#line 936 "parser.y"
                {
               
        }
#line 3241 "parser.tab.c"
    break;

  case 199: /* argument: test comp_for  */
#line 939 "parser.y"
                            {
            
        }
#line 3249 "parser.tab.c"
    break;

  case 200: /* argument: test EQUAL test  */
#line 942 "parser.y"
                            { 
            
        }
#line 3257 "parser.tab.c"
    break;

  case 201: /* argument: POWER_OPERATOR test  */
#line 945 "parser.y"
                                { 
            
        }
#line 3265 "parser.tab.c"
    break;

  case 202: /* argument: MULTIPLY test  */
#line 948 "parser.y"
                            {  
            
        }
#line 3273 "parser.tab.c"
    break;

  case 203: /* comp_iter: comp_for  */
#line 953 "parser.y"
                        { 
            
        }
#line 3281 "parser.tab.c"
    break;

  case 204: /* comp_iter: comp_if  */
#line 956 "parser.y"
                    { 
            
        }
#line 3289 "parser.tab.c"
    break;

  case 205: /* sync_comp_for: FOR exprlist IN or_test  */
#line 960 "parser.y"
                                            {
           
        }
#line 3297 "parser.tab.c"
    break;

  case 206: /* sync_comp_for: FOR exprlist IN or_test comp_iter  */
#line 963 "parser.y"
                                                { 
            
        }
#line 3305 "parser.tab.c"
    break;

  case 207: /* comp_for: sync_comp_for  */
#line 967 "parser.y"
                            {
            
        }
#line 3313 "parser.tab.c"
    break;

  case 208: /* comp_for: ASYNC sync_comp_for  */
#line 970 "parser.y"
                                { 
            
        }
#line 3321 "parser.tab.c"
    break;

  case 209: /* comp_if: IF or_test  */
#line 974 "parser.y"
                            {
            
        }
#line 3329 "parser.tab.c"
    break;

  case 210: /* comp_if: IF or_test comp_iter  */
#line 977 "parser.y"
                                { 
           
        }
#line 3337 "parser.tab.c"
    break;

  case 211: /* func_body_suite: simple_stmt  */
#line 981 "parser.y"
                                { 
            
        }
#line 3345 "parser.tab.c"
    break;

  case 212: /* func_body_suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 984 "parser.y"
                                            { 
            
        }
#line 3353 "parser.tab.c"
    break;

  case 213: /* func_body_suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 987 "parser.y"
                                                    { 
            
        }
#line 3361 "parser.tab.c"
    break;

  case 214: /* stmt_plus: stmt  */
#line 992 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3369 "parser.tab.c"
    break;

  case 215: /* stmt_plus: stmt stmt_plus  */
#line 995 "parser.y"
                            { 
            (yyval.elem)=create_node(3,"stmt_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
        }
#line 3378 "parser.tab.c"
    break;

  case 216: /* comma_test: COMMA test  */
#line 1000 "parser.y"
                        {
            
        }
#line 3386 "parser.tab.c"
    break;


#line 3390 "parser.tab.c"

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

#line 1004 "parser.y"


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
