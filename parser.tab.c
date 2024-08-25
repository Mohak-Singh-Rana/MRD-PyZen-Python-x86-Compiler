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
    void vector_copy(vector<string> v1,vector<string> v2);
    string newTemp();
    char* str_to_ch(string s);
    int tempCount;
    fstream code_out;
    string typecast(string , string, string);

    // map<string,ste> global_sym_table;
    ste* global_sym_table = new ste;   //pointer to the head(initialising entry) of the global symbol table
    ste* current_ste = global_sym_table;   //pointer to current symbol table entry (initialised to pointer of head of the global symbol table)  
    int global_offset = 0;
    map<string, ste*> class_map;

    int inClass = 0;
    int ischild=0;
    string className;

    unordered_map <string, int> typeMap;

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

#line 148 "parser.tab.c"

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
  YYSYMBOL_RANGE = 3,                      /* RANGE  */
  YYSYMBOL_NEWLINE = 4,                    /* NEWLINE  */
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
  YYSYMBOL_ATOM_KEYWORDS = 29,             /* ATOM_KEYWORDS  */
  YYSYMBOL_STRING = 30,                    /* STRING  */
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
  YYSYMBOL_TRUE = 60,                      /* TRUE  */
  YYSYMBOL_FALSE = 61,                     /* FALSE  */
  YYSYMBOL_NUMBER = 62,                    /* NUMBER  */
  YYSYMBOL_NONE = 63,                      /* NONE  */
  YYSYMBOL_LEN = 64,                       /* LEN  */
  YYSYMBOL_PRINT = 65,                     /* PRINT  */
  YYSYMBOL_D_MAIN = 66,                    /* D_MAIN  */
  YYSYMBOL_D_NAME = 67,                    /* D_NAME  */
  YYSYMBOL_SELF = 68,                      /* SELF  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_M = 70,                         /* M  */
  YYSYMBOL_N = 71,                         /* N  */
  YYSYMBOL_file = 72,                      /* file  */
  YYSYMBOL_snippet = 73,                   /* snippet  */
  YYSYMBOL_funcdef = 74,                   /* funcdef  */
  YYSYMBOL_func_name = 75,                 /* func_name  */
  YYSYMBOL_func_ret_type = 76,             /* func_ret_type  */
  YYSYMBOL_parameters = 77,                /* parameters  */
  YYSYMBOL_typedargslist = 78,             /* typedargslist  */
  YYSYMBOL_typedarg = 79,                  /* typedarg  */
  YYSYMBOL_tfpdef = 80,                    /* tfpdef  */
  YYSYMBOL_stmt = 81,                      /* stmt  */
  YYSYMBOL_simple_stmt = 82,               /* simple_stmt  */
  YYSYMBOL_small_stmt_list = 83,           /* small_stmt_list  */
  YYSYMBOL_small_stmt = 84,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 85,                 /* expr_stmt  */
  YYSYMBOL_eq_testlist_star_expr_plus = 86, /* eq_testlist_star_expr_plus  */
  YYSYMBOL_flow_stmt = 87,                 /* flow_stmt  */
  YYSYMBOL_break_stmt = 88,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 89,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 90,               /* return_stmt  */
  YYSYMBOL_global_stmt = 91,               /* global_stmt  */
  YYSYMBOL_comma_name_star = 92,           /* comma_name_star  */
  YYSYMBOL_compound_stmt = 93,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 94,                   /* if_stmt  */
  YYSYMBOL_d_expr = 95,                    /* d_expr  */
  YYSYMBOL_if_scope = 96,                  /* if_scope  */
  YYSYMBOL_else_scope = 97,                /* else_scope  */
  YYSYMBOL_else_if_scope = 98,             /* else_if_scope  */
  YYSYMBOL_nts_star = 99,                  /* nts_star  */
  YYSYMBOL_while_stmt = 100,               /* while_stmt  */
  YYSYMBOL_while_scope = 101,              /* while_scope  */
  YYSYMBOL_while_expr = 102,               /* while_expr  */
  YYSYMBOL_for_stmt = 103,                 /* for_stmt  */
  YYSYMBOL_for_core = 104,                 /* for_core  */
  YYSYMBOL_for_scope = 105,                /* for_scope  */
  YYSYMBOL_range_stmt = 106,               /* range_stmt  */
  YYSYMBOL_for_test = 107,                 /* for_test  */
  YYSYMBOL_suite = 108,                    /* suite  */
  YYSYMBOL_test = 109,                     /* test  */
  YYSYMBOL_or_test = 110,                  /* or_test  */
  YYSYMBOL_and_test_star = 111,            /* and_test_star  */
  YYSYMBOL_and_test = 112,                 /* and_test  */
  YYSYMBOL_not_test_star = 113,            /* not_test_star  */
  YYSYMBOL_not_test = 114,                 /* not_test  */
  YYSYMBOL_comparison = 115,               /* comparison  */
  YYSYMBOL_comp_op = 116,                  /* comp_op  */
  YYSYMBOL_expr = 117,                     /* expr  */
  YYSYMBOL_xor_expr = 118,                 /* xor_expr  */
  YYSYMBOL_and_expr = 119,                 /* and_expr  */
  YYSYMBOL_shift_expr = 120,               /* shift_expr  */
  YYSYMBOL_arith_expr = 121,               /* arith_expr  */
  YYSYMBOL_term = 122,                     /* term  */
  YYSYMBOL_term_choice = 123,              /* term_choice  */
  YYSYMBOL_factor = 124,                   /* factor  */
  YYSYMBOL_factor_choice = 125,            /* factor_choice  */
  YYSYMBOL_power = 126,                    /* power  */
  YYSYMBOL_atom_expr = 127,                /* atom_expr  */
  YYSYMBOL_atom = 128,                     /* atom  */
  YYSYMBOL_STRING_PLUS = 129,              /* STRING_PLUS  */
  YYSYMBOL_trailer = 130,                  /* trailer  */
  YYSYMBOL_testlist = 131,                 /* testlist  */
  YYSYMBOL_testlist_list = 132,            /* testlist_list  */
  YYSYMBOL_classdef = 133,                 /* classdef  */
  YYSYMBOL_class_declare = 134,            /* class_declare  */
  YYSYMBOL_class_body_suite = 135,         /* class_body_suite  */
  YYSYMBOL_funcdef_plus = 136,             /* funcdef_plus  */
  YYSYMBOL_arglist = 137,                  /* arglist  */
  YYSYMBOL_argument_list = 138,            /* argument_list  */
  YYSYMBOL_argument = 139,                 /* argument  */
  YYSYMBOL_stmt_plus = 140                 /* stmt_plus  */
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
#define YYFINAL  88
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   697

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  309

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    99,   106,   111,   115,   118,   121,   127,
     146,   160,   169,   180,   229,   233,   239,   249,   258,   265,
     273,   295,   298,   319,   323,   350,   353,   358,   361,   366,
     369,   376,   379,   382,   387,   424,   478,   495,   498,   581,
     635,   654,   657,   681,   684,   687,   692,   703,   709,   712,
     720,   726,   732,   736,   741,   744,   748,   752,   755,   760,
     771,   783,   790,   796,   808,   815,   826,   837,   847,   854,
     867,   879,   894,   901,   907,   925,   950,   971,   981,   988,
     997,  1004,  1007,  1010,  1016,  1022,  1025,  1033,  1040,  1045,
    1048,  1056,  1063,  1068,  1074,  1077,  1082,  1089,  1092,  1113,
    1116,  1119,  1122,  1125,  1128,  1131,  1134,  1137,  1140,  1143,
    1148,  1151,  1184,  1187,  1220,  1224,  1257,  1260,  1293,  1296,
    1331,  1366,  1369,  1406,  1409,  1412,  1415,  1418,  1423,  1435,
    1439,  1442,  1445,  1449,  1452,  1465,  1468,  1621,  1650,  1712,
    1733,  1742,  1787,  1790,  1795,  1811,  1816,  1821,  1848,  1853,
    1856,  1862,  1873,  1879,  1888,  1895,  1901,  1907,  1919,  1924,
    1932,  1940,  1962,  1977,  2032,  2053,  2072,  2091,  2154,  2158,
    2164,  2167,  2194,  2197,  2201,  2211,  2227,  2232,  2243,  2246
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
  "\"end of file\"", "error", "\"invalid token\"", "RANGE", "NEWLINE",
  "INDENT", "DEDENT", "ASSIGN_OPERATOR", "POWER_OPERATOR", "SHIFT_OPER",
  "FLOOR_DIV_OPER", "ARROW_OPER", "TYPE_HINT", "NAME", "IF", "ELSE",
  "ELIF", "WHILE", "FOR", "IN", "AND", "OR", "NOT", "BREAK", "CONTINUE",
  "RETURN", "CLASS", "DEF", "GLOBAL", "ATOM_KEYWORDS", "STRING",
  "OPEN_BRACKET", "CLOSE_BRACKET", "EQUAL", "SEMI_COLON", "COLON", "COMMA",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "REMAINDER", "ATTHERATE",
  "NEGATION", "BIT_AND", "BIT_OR", "BIT_XOR", "DOT", "CURLY_OPEN",
  "CURLY_CLOSE", "SQUARE_OPEN", "SQUARE_CLOSE", "LESS_THAN",
  "GREATER_THAN", "EQUAL_EQUAL", "GREATER_THAN_EQUAL", "LESS_THAN_EQUAL",
  "NOT_EQUAL_ARROW", "NOT_EQUAL", "IS", "TRUE", "FALSE", "NUMBER", "NONE",
  "LEN", "PRINT", "D_MAIN", "D_NAME", "SELF", "$accept", "M", "N", "file",
  "snippet", "funcdef", "func_name", "func_ret_type", "parameters",
  "typedargslist", "typedarg", "tfpdef", "stmt", "simple_stmt",
  "small_stmt_list", "small_stmt", "expr_stmt",
  "eq_testlist_star_expr_plus", "flow_stmt", "break_stmt", "continue_stmt",
  "return_stmt", "global_stmt", "comma_name_star", "compound_stmt",
  "if_stmt", "d_expr", "if_scope", "else_scope", "else_if_scope",
  "nts_star", "while_stmt", "while_scope", "while_expr", "for_stmt",
  "for_core", "for_scope", "range_stmt", "for_test", "suite", "test",
  "or_test", "and_test_star", "and_test", "not_test_star", "not_test",
  "comparison", "comp_op", "expr", "xor_expr", "and_expr", "shift_expr",
  "arith_expr", "term", "term_choice", "factor", "factor_choice", "power",
  "atom_expr", "atom", "STRING_PLUS", "trailer", "testlist",
  "testlist_list", "classdef", "class_declare", "class_body_suite",
  "funcdef_plus", "arglist", "argument_list", "argument", "stmt_plus", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-227)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-93)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     112,   112,  -227,  -227,  -227,  -227,   629,  -227,  -227,   629,
       7,    10,    20,  -227,   -13,   409,  -227,  -227,  -227,    43,
     453,  -227,  -227,  -227,  -227,    73,    87,    54,   145,  -227,
    -227,   112,  -227,    14,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,  -227,   497,  -227,  -227,  -227,    16,    80,  -227,
     126,   132,   141,   147,  -227,    41,   123,   124,   125,     6,
      -1,  -227,    16,  -227,     5,  -227,  -227,  -227,   135,  -227,
    -227,  -227,  -227,   150,   144,  -227,   151,   142,  -227,  -227,
     149,   153,  -227,  -227,   136,   629,   629,   170,  -227,  -227,
    -227,   215,   134,   154,   155,   629,   156,   167,   629,   629,
     312,  -227,  -227,  -227,   173,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,   171,    16,    16,    16,    16,    16,    16,    16,
    -227,  -227,  -227,  -227,  -227,    16,  -227,    16,   541,   181,
     629,  -227,   629,   585,   191,    17,    72,   183,  -227,   190,
    -227,  -227,   172,   177,  -227,  -227,  -227,   182,   268,  -227,
     168,  -227,  -227,   208,  -227,  -227,   184,    18,    35,   629,
     629,  -227,  -227,  -227,  -227,  -227,  -227,  -227,    -1,    -1,
    -227,  -227,  -227,    70,   185,   189,   179,  -227,  -227,   165,
     187,  -227,   192,   218,  -227,   194,    92,    -5,    26,  -227,
     198,    -2,   268,   142,  -227,  -227,  -227,  -227,   220,  -227,
    -227,   268,  -227,   268,   196,  -227,   629,   629,   629,   629,
     629,   211,   213,  -227,   629,   629,  -227,   629,  -227,   222,
    -227,   214,   223,    -2,   268,  -227,   229,  -227,   229,   629,
    -227,  -227,   212,  -227,  -227,   365,   143,   268,   233,   629,
    -227,  -227,  -227,  -227,  -227,   217,  -227,  -227,  -227,  -227,
     127,  -227,   216,  -227,    78,  -227,  -227,   268,   365,    61,
     148,   233,   235,   120,  -227,  -227,   248,  -227,  -227,   268,
    -227,  -227,  -227,   249,  -227,  -227,  -227,   221,   629,  -227,
     242,   225,  -227,   629,  -227,  -227,  -227,  -227,   226,   227,
    -227,   232,   268,  -227,  -227,   268,  -227,  -227,   268,   268,
    -227,   143,  -227,   148,   231,  -227,  -227,   268,  -227
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,   147,    64,    72,    77,     0,    46,    47,    48,
       0,     0,     0,   150,   152,     0,   130,   131,   132,     0,
       0,    95,    96,   148,   151,     0,     0,     0,     0,     4,
      57,     6,    25,     0,    29,    31,    32,    43,    44,    45,
      33,    26,    54,     0,    55,     2,    56,     0,   160,    84,
       0,    85,     0,    89,    94,    97,   110,   112,   114,   116,
     118,   121,     0,   129,   133,   135,   149,    37,   158,    58,
       7,    93,    49,   165,     0,    13,     0,    50,   153,   143,
     160,     0,   146,   145,     0,     0,     0,     0,     1,     8,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     2,   106,     0,    99,   100,   101,   102,   103,
     104,   105,   108,     0,     0,     0,     0,     0,     0,     0,
     127,   123,   125,   126,   124,     0,   128,     0,     0,     0,
       0,   136,   159,     0,     0,     0,     0,     0,    51,     0,
     142,   144,     0,     0,   141,    27,    30,     0,     0,     2,
       0,    73,     2,     0,    34,    38,    41,   161,     0,     0,
       0,   107,   109,    98,   111,   113,   115,   117,   119,   120,
     122,   134,   154,     0,   176,     0,   172,   174,   138,     0,
     162,   166,     0,     0,   164,    23,     0,     0,     0,    19,
      21,     0,     0,    52,   161,   139,   140,    63,     0,    81,
      62,     0,     2,     0,     0,    76,     0,     0,     0,     0,
       0,    86,    90,   157,     0,     0,   155,   173,   137,     0,
     167,     0,     0,     0,     0,    18,     0,    16,     0,     0,
      14,    15,     0,     9,    53,     0,    59,     0,    74,     0,
      42,    35,    39,    36,    40,     0,   177,   175,   163,   170,
       0,    24,     0,    11,     0,    20,    22,     0,   178,     0,
       0,    70,     0,     0,    80,   156,     0,   168,   171,     0,
      17,    10,   179,     0,    82,    65,    66,     0,     0,    61,
       0,     0,    78,     0,   169,    12,    83,     2,     0,     0,
       2,     0,     0,     2,     2,     0,    79,    60,     0,     0,
      75,    67,    71,     0,     0,    68,     2,     0,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -227,   -80,  -226,  -227,    25,  -193,  -227,    44,  -227,    42,
      45,  -227,  -126,     1,  -227,   180,  -227,   -62,  -227,  -227,
    -227,  -227,  -227,    77,  -227,  -227,  -227,  -227,  -152,  -227,
     -21,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -187,
      -9,  -227,  -227,   128,  -227,    -3,   175,  -227,   -40,   169,
     178,   186,  -227,    47,  -227,   -54,  -227,  -227,  -227,  -227,
     271,  -227,     4,  -227,  -227,  -227,  -227,  -227,    75,  -227,
    -129,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    95,   260,    28,    29,    30,    76,   232,   136,   188,
     189,   190,    31,   199,    33,    34,    35,   155,    36,    37,
      38,    39,    40,   138,    41,    42,    93,    43,   277,   278,
     279,    44,    45,   150,    46,    96,    47,   205,   263,   200,
      48,    49,    50,    51,    52,    53,    54,   113,    55,    56,
      57,    58,    59,    60,   125,    61,    62,    63,    64,    65,
      66,   131,    67,    68,    69,    74,   184,   250,   175,   176,
     177,   259
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,    32,    32,    71,   182,   233,    80,    97,   126,   120,
     230,    80,   262,   127,   236,   117,   238,    14,    90,    81,
      73,   159,   160,    75,    84,   207,    70,   225,   249,     2,
     185,   226,    32,    77,    94,   280,   128,   253,   121,   122,
     123,   124,   209,   118,   119,    13,    14,    15,    91,   186,
     261,   208,   129,    16,    17,   130,    89,   268,   227,    18,
     103,   231,   228,   104,    19,   273,    20,   274,   210,   201,
     271,   170,   203,   171,   164,   303,   142,   143,    23,    24,
      25,    26,   285,   191,    27,   187,   151,    98,   247,   154,
     156,   158,    82,   105,   106,   107,   108,   109,   110,   111,
     112,    87,   213,   223,    85,   297,   214,   192,   300,   258,
     270,   301,   302,    99,   228,   100,     1,    87,    86,   174,
     308,   179,   237,   180,   174,     2,     3,   224,   289,     4,
       5,   266,   258,   267,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,   240,    88,   242,   101,   244,    16,
      17,   304,   282,   -88,    11,    18,   283,   212,    -3,    -3,
      19,   102,    20,   275,   276,   168,   169,   -92,   114,   116,
     115,   132,    21,    22,    23,    24,    25,    26,   137,   134,
      27,   133,   135,   144,   139,   140,   153,   141,   147,   148,
     149,   152,   161,   162,   178,   183,   193,   156,   241,   156,
     243,   156,   194,   202,   195,   174,   246,   292,   174,   196,
     295,   204,   197,   298,   299,   217,   218,   206,   215,   145,
     256,   216,   219,   221,   220,   235,   307,   239,     2,   222,
     264,   229,   -87,   -91,   248,   251,    32,     6,     7,     8,
       9,    11,   185,    12,    13,    14,    15,   257,    -3,   265,
     281,   269,    16,    17,   284,   286,   287,   275,    18,    32,
     290,   293,   294,    19,   296,    20,   306,   252,   254,   288,
     234,   146,   198,   255,   291,    21,    22,    23,    24,    25,
      26,     2,   305,    27,   165,    78,   272,   211,   163,   245,
       6,     7,     8,     9,   166,     0,    12,    13,    14,    15,
       0,     0,     0,   167,     0,    16,    17,     0,     0,     0,
       0,    18,     0,     0,     0,     0,    19,     0,    20,     0,
       0,     0,     0,     0,   157,     2,     0,     0,    21,    22,
      23,    24,    25,    26,     6,     0,    27,     0,     0,     0,
       0,    13,    14,    15,     0,     0,     0,     0,     0,    16,
      17,     0,     0,     0,     0,    18,     0,     0,     0,     0,
      19,     0,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,    22,    23,    24,    25,    26,     2,     3,
      27,     0,     4,     5,     0,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,    16,    17,     0,     0,     0,     0,    18,     0,
       0,     0,     0,    19,     0,    20,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    21,    22,    23,    24,    25,
      26,     6,     0,    27,     0,     0,     0,     0,    13,    14,
      15,    79,     0,     0,     0,     0,    16,    17,     0,     0,
       0,     0,    18,     0,     0,     0,     0,    19,     0,    20,
       0,     0,     0,     0,     0,     0,     2,     0,     0,    21,
      22,    23,    24,    25,    26,     6,     0,    27,     0,     0,
       0,     0,    13,    14,    15,     0,     0,     0,     0,     0,
      16,    17,     0,     0,     0,     0,    18,     0,     0,     0,
       0,    19,     0,    20,    83,     0,     0,     0,     0,     0,
       2,     0,     0,    21,    22,    23,    24,    25,    26,     6,
       0,    27,     0,     0,     0,     0,    13,    14,    15,     0,
       0,     0,     0,     0,    16,    17,     0,     0,     0,     0,
      18,     0,     0,     0,     0,    19,     0,    20,     0,     0,
       0,     0,     0,     0,     2,     0,     0,    21,    22,    23,
      24,    25,    26,     6,    92,    27,     0,     0,     0,     0,
      13,    14,    15,   172,     0,     0,     0,     0,    16,    17,
       0,     0,     0,     0,    18,     0,     0,     0,     0,    19,
       0,    20,     0,     0,     0,     0,     0,     0,     2,     0,
       0,    21,    22,    23,    24,    25,    26,     6,     0,   173,
       0,     0,     0,     0,    13,    14,    15,   181,     0,     0,
       0,     0,    16,    17,     0,     0,     0,     0,    18,     0,
       0,     0,     0,    19,     0,    20,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    21,    22,    23,    24,    25,
      26,     6,     0,    27,     0,     0,     0,     0,    13,    14,
      15,     0,     0,     0,     0,     0,    16,    17,     0,     0,
       0,     0,    18,     0,     0,     0,     0,    19,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      22,    23,    24,    25,    26,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
       9,     0,     1,     6,   133,   192,    15,    47,    62,    10,
      12,    20,   238,     8,   201,     9,   203,    30,     4,    15,
      13,   101,   102,    13,    20,     7,     1,    32,   221,    13,
      13,    36,    31,    13,    43,   261,    31,   224,    39,    40,
      41,    42,     7,    37,    38,    29,    30,    31,    34,    32,
     237,    33,    47,    37,    38,    50,    31,   250,    32,    43,
      19,    63,    36,    22,    48,     4,    50,     6,    33,   149,
     257,   125,   152,   127,   114,   301,    85,    86,    62,    63,
      64,    65,   269,    11,    68,    68,    95,     7,   217,    98,
      99,   100,    49,    52,    53,    54,    55,    56,    57,    58,
      59,    47,    32,    11,    31,   292,    36,    35,   295,   235,
      32,   298,   299,    33,    36,    35,     4,    47,    31,   128,
     307,   130,   202,   132,   133,    13,    14,    35,   280,    17,
      18,     4,   258,     6,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,   206,     0,   208,    21,   210,    37,
      38,   303,    32,    21,    27,    43,    36,   160,    15,    16,
      48,    20,    50,    15,    16,   118,   119,    20,    45,    44,
      46,    36,    60,    61,    62,    63,    64,    65,    36,    35,
      68,    31,    31,    13,    35,    32,    19,    51,    54,    35,
      35,    35,    19,    22,    13,     4,    13,   206,   207,   208,
     209,   210,    12,    35,    32,   214,   215,   287,   217,    32,
     290,     3,    30,   293,   294,    36,    51,    33,    33,     4,
     229,    32,    35,     5,    32,     5,   306,    31,    13,    35,
     239,    33,    21,    20,    12,    12,   235,    22,    23,    24,
      25,    27,    13,    28,    29,    30,    31,    35,    15,    32,
      15,    35,    37,    38,     6,     6,    35,    15,    43,   258,
      35,    35,    35,    48,    32,    50,    35,   223,   226,   278,
     193,    91,     4,   228,   283,    60,    61,    62,    63,    64,
      65,    13,   303,    68,   115,    14,   258,   159,   113,   214,
      22,    23,    24,    25,   116,    -1,    28,    29,    30,    31,
      -1,    -1,    -1,   117,    -1,    37,    38,    -1,    -1,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    60,    61,
      62,    63,    64,    65,    22,    -1,    68,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    13,    14,
      68,    -1,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    60,    61,    62,    63,    64,
      65,    22,    -1,    68,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    60,
      61,    62,    63,    64,    65,    22,    -1,    68,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    60,    61,    62,    63,    64,    65,    22,
      -1,    68,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    60,    61,    62,
      63,    64,    65,    22,    67,    68,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    -1,    -1,    68
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    13,    14,    17,    18,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    37,    38,    43,    48,
      50,    60,    61,    62,    63,    64,    65,    68,    72,    73,
      74,    81,    82,    83,    84,    85,    87,    88,    89,    90,
      91,    93,    94,    96,   100,   101,   103,   105,   109,   110,
     111,   112,   113,   114,   115,   117,   118,   119,   120,   121,
     122,   124,   125,   126,   127,   128,   129,   131,   132,   133,
      73,   114,   109,    13,   134,    13,    75,    13,   129,    32,
     109,   131,    49,    51,   131,    31,    31,    47,     0,    73,
       4,    34,    67,    95,   109,    70,   104,   117,     7,    33,
      35,    21,    20,    19,    22,    52,    53,    54,    55,    56,
      57,    58,    59,   116,    45,    46,    44,     9,    37,    38,
      10,    39,    40,    41,    42,   123,   124,     8,    31,    47,
      50,   130,    36,    31,    35,    31,    77,    36,    92,    35,
      32,    51,   109,   109,    13,     4,    84,    54,    35,    35,
     102,   109,    35,    19,   109,    86,   109,    12,   109,    70,
      70,    19,    22,   115,   117,   118,   119,   120,   122,   122,
     124,   124,    32,    68,   109,   137,   138,   139,    13,   109,
     109,    32,   139,     4,   135,    13,    32,    68,    78,    79,
      80,    11,    35,    13,    12,    32,    32,    30,     4,    82,
     108,    70,    35,    70,     3,   106,    33,     7,    33,     7,
      33,   112,   114,    32,    36,    33,    32,    36,    51,    35,
      32,     5,    35,    11,    35,    32,    36,    32,    36,    33,
      12,    63,    76,   108,    92,     5,   108,    70,   108,    31,
      86,   109,    86,   109,    86,   137,   109,   139,    12,    74,
     136,    12,    76,   108,    78,    79,   109,    35,    81,   140,
      71,   108,    71,   107,   109,    32,     4,     6,    74,    35,
      32,   108,   140,     4,     6,    15,    16,    97,    98,    99,
      71,    15,    32,    36,     6,   108,     6,    35,   109,    97,
      35,   109,    70,    35,    35,    70,    32,   108,    70,    70,
     108,   108,   108,    71,    97,    99,    35,    70,   108
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    72,    73,    73,    73,    73,    74,
      74,    74,    74,    75,    76,    76,    77,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    87,    87,    87,    88,    89,    90,    90,
      91,    91,    92,    92,    93,    93,    93,    93,    93,    94,
      94,    94,    94,    95,    96,    97,    98,    99,    99,    99,
     100,   100,   101,   102,   103,   103,   104,   105,   106,   106,
     107,   108,   108,   108,   109,   110,   110,   111,   111,   112,
     112,   113,   113,   114,   114,   114,   114,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   121,   121,
     121,   122,   122,   123,   123,   123,   123,   123,   124,   124,
     125,   125,   125,   126,   126,   127,   127,   127,   127,   127,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   129,   129,   130,   130,   130,   130,   131,   131,
     132,   132,   132,   132,   133,   134,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   140,   140
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     2,     2,     5,
       7,     6,     8,     1,     1,     1,     3,     5,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     3,     2,     1,
       3,     1,     1,     1,     3,     5,     5,     1,     3,     5,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     2,     3,     1,     1,     1,     1,     1,     5,
      10,     7,     4,     3,     1,     1,     1,     5,     7,    10,
       6,    11,     1,     1,     5,    10,     3,     1,     4,     6,
       1,     1,     4,     5,     1,     1,     4,     4,     1,     1,
       4,     4,     1,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     3,     1,     2,     4,     3,     4,
       4,     3,     3,     2,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     5,     3,     1,     2,
       1,     3,     3,     5,     4,     1,     3,     4,     4,     5,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     2
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
#line 93 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal M");
        (yyval.elem)->ins = instCount+1;
}
#line 1588 "parser.tab.c"
    break;

  case 3: /* N: %empty  */
#line 99 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal N");
        (yyval.elem)->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
#line 1598 "parser.tab.c"
    break;

  case 4: /* file: snippet  */
#line 106 "parser.y"
              {
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 1606 "parser.tab.c"
    break;

  case 5: /* snippet: NEWLINE  */
#line 111 "parser.y"
                 {
       (yyval.elem)=(yyvsp[0].elem);
	   (yyval.elem)->ins = instCount+1;
    }
#line 1615 "parser.tab.c"
    break;

  case 6: /* snippet: stmt  */
#line 115 "parser.y"
            { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1623 "parser.tab.c"
    break;

  case 7: /* snippet: NEWLINE snippet  */
#line 118 "parser.y"
                       { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1631 "parser.tab.c"
    break;

  case 8: /* snippet: stmt snippet  */
#line 121 "parser.y"
                   {  
        (yyval.elem) = create_node(3, "snippet", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
    }
#line 1640 "parser.tab.c"
    break;

  case 9: /* funcdef: DEF func_name parameters COLON suite  */
#line 127 "parser.y"
                                              {
            //STE code start
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-3].elem)->addr, (yyvsp[-2].elem)->num_params, (yyvsp[-4].elem)->lineno, 1);
            //STE code end
            (yyval.elem)->ins = instCount+1;

            // thisTemps.pop();
			// create_ins(0,$5->return_param,"=","PopParam","");
            create_ins(0,"goto","ra","","");
            create_ins(0,"EndFunc","","","");
            backpatch_str((yyvsp[0].elem)->nextlist, "ra");
            // thisTemps.push(reg1);

            //populate in symbol table
            populate_fun_par_type(current_ste,(yyvsp[-2].elem)->func_par_type);
            //if(current_ste->num_params)cout<<"pls "<<current_ste->func_par_type[0]<<endl;

        }
#line 1664 "parser.tab.c"
    break;

  case 10: /* funcdef: DEF func_name parameters ARROW_OPER func_ret_type COLON suite  */
#line 146 "parser.y"
                                                                        {
            current_ste = get_prev_scope(current_ste);
            //cout<<"in funcfull"<<endl;
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-5].elem)->addr, (yyvsp[-4].elem)->num_params, (yyvsp[-6].elem)->lineno, 1,(yyvsp[-2].elem)->addr);
            //cout<<current_ste->lexeme<<" "<<"funcname"<<endl;
            //cout<<"Function "<<current_ste->return_type<<" return type "<<$5->addr<<endl;
            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Goto","ra","","");
            create_ins(0,"EndFunc","","","");

            //populate in symbol table
            populate_fun_par_type(current_ste,(yyvsp[-4].elem)->func_par_type);
        }
#line 1683 "parser.tab.c"
    break;

  case 11: /* funcdef: DEF func_name OPEN_BRACKET CLOSE_BRACKET COLON suite  */
#line 160 "parser.y"
                                                               {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-4].elem)->addr, 0, (yyvsp[-5].elem)->lineno, 1);

            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Goto","ra","","");
            create_ins(0,"EndFunc","","","");
        }
#line 1697 "parser.tab.c"
    break;

  case 12: /* funcdef: DEF func_name OPEN_BRACKET CLOSE_BRACKET ARROW_OPER func_ret_type COLON suite  */
#line 169 "parser.y"
                                                                                       {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-6].elem)->addr, 0, (yyvsp[-7].elem)->lineno, 1,(yyvsp[-2].elem)->addr);

            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Goto","ra","","");
            create_ins(0,"EndFunc","","","");
        }
#line 1711 "parser.tab.c"
    break;

  case 13: /* func_name: NAME  */
#line 181 "parser.y"
    {   
        (yyval.elem)=(yyvsp[0].elem);

        if(inClass==0) create_ins(0,chartostring((yyvsp[0].elem)->addr)+":","","","");
        else create_ins(0,className+"."+chartostring((yyvsp[0].elem)->addr)+":","","","");

        create_ins(0,"BeginFunc","","","");
        // paramStack.pop(); //popping return address
        create_ins(0,"ra","=","PopParam","");

        //STE code start
        ste* lookup_ste = current_ste;
        //here I am adding it should not be init
        if(lookup(lookup_ste, (yyvsp[0].elem)->addr) == NULL || chartostring((yyvsp[0].elem)->addr) == "__init__"){
            current_ste = insert_entry_new_scope(current_ste);
            ste* help = current_ste->prev_scope;
            populate_new_scope(help, "FUNCTION", (yyvsp[0].elem)->addr, 0, 0, 1);
        }
        else{ //print_ste(global_sym_table, 0);
            cerr<<"Error: Function "<<(yyvsp[0].elem)->addr<<" already declared\n";
            exit(1);
        }
        //STE code end
    }
#line 1740 "parser.tab.c"
    break;

  case 14: /* func_ret_type: TYPE_HINT  */
#line 229 "parser.y"
                        {
        (yyval.elem)=(yyvsp[0].elem);
        get_prev_scope(current_ste)->return_type = (yyvsp[0].elem)->addr;
    }
#line 1749 "parser.tab.c"
    break;

  case 15: /* func_ret_type: NONE  */
#line 233 "parser.y"
          {
        (yyval.elem)=(yyvsp[0].elem);
        get_prev_scope(current_ste)->return_type = "None";
    }
#line 1758 "parser.tab.c"
    break;

  case 16: /* parameters: OPEN_BRACKET typedargslist CLOSE_BRACKET  */
#line 239 "parser.y"
                                                     {  
            (yyval.elem) = create_node(4, "parameters", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[-1].elem)->num_params;
            // cout<<"parameterts done"<<endl;

            //handle vector of par type 
            (yyval.elem)->func_par_type = (yyvsp[-1].elem)->func_par_type;
            // cout<<"par: "<<$$->func_par_type.size() <<" "<< $2->func_par_type.size() <<endl;
        }
#line 1773 "parser.tab.c"
    break;

  case 17: /* parameters: OPEN_BRACKET SELF COMMA typedargslist CLOSE_BRACKET  */
#line 249 "parser.y"
                                                              {
            //cout<<"in self para"<<endl;
            (yyval.elem) = create_node(6, "parameters", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[-1].elem)->num_params;

            //handle vector of par type 
            (yyval.elem)->func_par_type = (yyvsp[-1].elem)->func_par_type;
        }
#line 1787 "parser.tab.c"
    break;

  case 18: /* parameters: OPEN_BRACKET SELF CLOSE_BRACKET  */
#line 258 "parser.y"
                                          {
            (yyval.elem) = create_node(3, "parameters", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
            (yyval.elem)->num_params = 0;
        }
#line 1797 "parser.tab.c"
    break;

  case 19: /* typedargslist: typedarg  */
#line 265 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;
            (yyval.elem)->ins = instCount+1;
            
            // paramStack.pop();
			create_ins(0,(yyvsp[0].elem)->addr,"=","PopParam","");
        }
#line 1810 "parser.tab.c"
    break;

  case 20: /* typedargslist: typedargslist COMMA typedarg  */
#line 273 "parser.y"
                                         {  
            (yyval.elem) = create_node(4, "typedargslist", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;

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
#line 1830 "parser.tab.c"
    break;

  case 21: /* typedarg: tfpdef  */
#line 295 "parser.y"
                   {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1838 "parser.tab.c"
    break;

  case 22: /* typedarg: tfpdef EQUAL test  */
#line 298 "parser.y"
                            {  
            (yyval.elem) = create_node(4, "typedarg", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");    //is this instruction needed?????

            //typecheck
            //curretnly doing only for LHS, checked for LHS
            if(lookup(current_ste, (yyvsp[-2].elem)->addr) == NULL){
                cerr<<"Error: Variable "<<(yyvsp[-2].elem)->addr<<" not declared\n";
                exit(1);
            }
            else{
                //Type_checking
            }
            //typecheck end

            //handle vector of par type 
            (yyval.elem)->func_par_type = (yyvsp[-2].elem)->func_par_type;
        }
#line 1862 "parser.tab.c"
    break;

  case 23: /* tfpdef: NAME  */
#line 319 "parser.y"
             {  
            (yyval.elem)=(yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
        }
#line 1871 "parser.tab.c"
    break;

  case 24: /* tfpdef: NAME COLON TYPE_HINT  */
#line 323 "parser.y"
                               {  
            (yyval.elem) = create_node(4, "tfpdef", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem)); 
			(yyval.elem)->ins = instCount+1;
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;

            //Type check start 
            (yyvsp[-2].elem)->atom_type = (yyvsp[0].elem)->addr; //see type kya hai exactly
            (yyval.elem)->atom_type = (yyvsp[0].elem)->addr; 
            //symbol table entry me type niche daal dia hai
            //Type check end

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

            //handle vector of par type 
            (yyval.elem)->func_par_type.push_back(chartostring((yyvsp[0].elem)->addr));
        }
#line 1901 "parser.tab.c"
    break;

  case 25: /* stmt: simple_stmt  */
#line 350 "parser.y"
                        { 
        	(yyval.elem)=(yyvsp[0].elem);
        }
#line 1909 "parser.tab.c"
    break;

  case 26: /* stmt: compound_stmt  */
#line 353 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem); 
        }
#line 1917 "parser.tab.c"
    break;

  case 27: /* simple_stmt: small_stmt_list SEMI_COLON NEWLINE  */
#line 358 "parser.y"
                                                {  
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 1925 "parser.tab.c"
    break;

  case 28: /* simple_stmt: small_stmt_list NEWLINE  */
#line 361 "parser.y"
                                   {  
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 1933 "parser.tab.c"
    break;

  case 29: /* small_stmt_list: small_stmt  */
#line 366 "parser.y"
                                {   
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1941 "parser.tab.c"
    break;

  case 30: /* small_stmt_list: small_stmt_list SEMI_COLON small_stmt  */
#line 369 "parser.y"
                                                     {  
           (yyval.elem) = create_node(3, "small_stmt_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
		   (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
           (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, (yyvsp[0].elem)->nextlist);
        }
#line 1951 "parser.tab.c"
    break;

  case 31: /* small_stmt: expr_stmt  */
#line 376 "parser.y"
                            {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1959 "parser.tab.c"
    break;

  case 32: /* small_stmt: flow_stmt  */
#line 379 "parser.y"
                        {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1967 "parser.tab.c"
    break;

  case 33: /* small_stmt: global_stmt  */
#line 382 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1975 "parser.tab.c"
    break;

  case 34: /* expr_stmt: test ASSIGN_OPERATOR test  */
#line 387 "parser.y"
                                     { 
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            // Here add instruction 
            string oper="";
            int i=0;
            while((yyvsp[-1].elem)->addr[i]!='='){
                oper.push_back((yyvsp[-1].elem)->addr[i]);
                i++;
            }
            // string temp = newTemp();
            // create_ins(1, temp, oper, $1->addr, $3->addr);
            // create_ins(0, $1->addr, "=", temp, "");

            //typecheck
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,(yyvsp[-1].elem)->addr);
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch1a in assignment\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    string temp = newTemp();
                    create_ins(1, temp, oper, "("+ret_type+")"+chartostring((yyvsp[0].elem)->addr),chartostring((yyvsp[-2].elem)->addr));
                    create_ins(0, (yyvsp[-2].elem)->addr, "=", temp, "");
                }
                else if(ret_type != (yyvsp[-2].elem)->atom_type){
                    string temp = newTemp();
                    create_ins(1, temp, oper, "("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr),chartostring((yyvsp[0].elem)->addr));
                    create_ins(0, (yyvsp[-2].elem)->addr, "=", temp, "");
                }
                else{
                    string temp = newTemp();
                    create_ins(1, temp, oper, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
                    create_ins(0, (yyvsp[-2].elem)->addr, "=", temp, "");
                }
            //typecheck done
        }
#line 2017 "parser.tab.c"
    break;

  case 35: /* expr_stmt: test COLON TYPE_HINT ASSIGN_OPERATOR test  */
#line 424 "parser.y"
                                                    { // Is this rule really required?
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            // Here add instruction 
            string oper="";
            int i=0;
            while((yyvsp[-3].elem)->addr[i]!='='){
                oper.push_back((yyvsp[-3].elem)->addr[i]);
                i++;
            }
            // string temp = newTemp();
            // create_ins(1, temp, oper, $1->addr, $5->addr);
            // create_ins(0, $1->addr, "=", temp, "");

            //Type checking
            (yyvsp[-4].elem)->atom_type = (yyvsp[-2].elem)->addr;
            //Type checking end

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

            //typecheck
                string ret_type=typecast((yyvsp[-4].elem)->atom_type,(yyvsp[0].elem)->atom_type,(yyvsp[-3].elem)->addr);
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch1a in assignment\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    string temp = newTemp();
                    create_ins(1, temp, oper, "("+ret_type+")"+chartostring((yyvsp[0].elem)->addr),chartostring((yyvsp[-4].elem)->addr));
                    create_ins(0, (yyvsp[-4].elem)->addr, "=", temp, "");
                }
                else if(ret_type != (yyvsp[-4].elem)->atom_type){
                    string temp = newTemp();
                    create_ins(1, temp, oper, "("+ret_type+")"+chartostring((yyvsp[-4].elem)->addr),chartostring((yyvsp[0].elem)->addr));
                    create_ins(0, (yyvsp[-4].elem)->addr, "=", temp, "");
                }
                else{
                    string temp = newTemp();
                    create_ins(1, temp, oper, (yyvsp[-4].elem)->addr, (yyvsp[0].elem)->addr);
                    create_ins(0, (yyvsp[-4].elem)->addr, "=", temp, "");
                }
            //typecheck done


        }
#line 2076 "parser.tab.c"
    break;

  case 36: /* expr_stmt: test COLON test ASSIGN_OPERATOR test  */
#line 478 "parser.y"
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
#line 2098 "parser.tab.c"
    break;

  case 37: /* expr_stmt: testlist  */
#line 495 "parser.y"
                   {
			(yyval.elem)=(yyvsp[0].elem);
        }
#line 2106 "parser.tab.c"
    break;

  case 38: /* expr_stmt: test EQUAL eq_testlist_star_expr_plus  */
#line 498 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-2].elem)->ins;
			// create_ins(0, $1->addr, $2->addr, $3->addr, ""); 

//this works for test a.b type only
            //Type_checking
            // if(chartostring($1->type)=="self_call"){ // this is to get atom type of self.len and I am not going to next scope
            //     ste* lookup_ste = lookup(current_ste, "self");
            //     string temp="";
            //     while(lookup_ste!=NULL){
            //         if(lookup_ste->type==$1->class_param){
            //             temp = lookup_ste->lexeme;
            //             break;
            //         }
            //         lookup_ste = lookup_ste->next;
            //     }
            //     $1->atom_type = temp;
            // }
            // if(chartostring($3->type)=="self_call"){ // this is to get atom type of self.len and I am not going to next scope
            //     ste* lookup_ste = lookup(current_ste, "self");
            //     string temp="";
            //     while(lookup_ste!=NULL){
            //         if(lookup_ste->type==$3->class_param){
            //             temp = lookup_ste->lexeme;
            //             break;
            //         }
            //         lookup_ste = lookup_ste->next;
            //     }
            //     $3->atom_type = temp; //ye kya hai atom_type hamesha int float hona chahiye na
            // }
            // if(chartostring($1->type)=="class_call"){ // this is to get atom type of self.len and I am not going to next scope
            //     string c_name="";
            //     int i=0;
            //     while($1->addr[i]!='.'){
            //         c_name.push_back($1->addr[i]);
            //         i++;
            //     }
            //     ste* lookup_ste = lookup(current_ste, c_name);
            //     string temp="";
            //     while(lookup_ste!=NULL){
            //         if(lookup_ste->type==$1->class_param){
            //             temp = lookup_ste->lexeme;
            //             break;
            //         }
            //         lookup_ste = lookup_ste->next;
            //     }
            //     $1->atom_type = temp; //ye kya hai atom_type hamesha int float hona chahiye na
            // }
            // if(chartostring($3->type)=="class_call"){ // this is to get atom type of self.len and I am not going to next scope
            //     string c_name="";
            //     int i=0;
            //     while($1->addr[i]!='.'){
            //         c_name.push_back($1->addr[i]);
            //         i++;
            //     }
            //     ste* lookup_ste = lookup(current_ste, c_name);
            //     string temp="";
            //     while(lookup_ste!=NULL){
            //         if(lookup_ste->type==$3->class_param){
            //             temp = lookup_ste->lexeme;
            //             break;
            //         }
            //         lookup_ste = lookup_ste->next;
            //     }
            //     $3->atom_type = temp;
            // }
                //cout<< "test EQUAL eQtest: "<<$1->atom_type << " "<< $3->atom_type << endl;
            //typecheck
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"=");
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch1a in assignment\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    create_ins(0, (yyvsp[-2].elem)->addr, "=", "("+ret_type+")"+chartostring((yyvsp[0].elem)->addr),"");
                }
                else{
                    create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
                }
            //typecheck done
        }
#line 2193 "parser.tab.c"
    break;

  case 39: /* expr_stmt: test COLON TYPE_HINT EQUAL eq_testlist_star_expr_plus  */
#line 581 "parser.y"
                                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem));
			(yyval.elem)->ins = (yyvsp[-4].elem)->ins;
			//create_ins(0, $1->addr, $4->addr, $5->addr, ""); 
            cout<<(yyvsp[-4].elem)->class_param<<endl;
            (yyvsp[-4].elem)->atom_type = (yyvsp[-2].elem)->addr;
            cout<<"check in expr_stmt: "<<(yyvsp[-4].elem)->class_param<<endl;
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
                    string ret_type=typecast((yyvsp[-4].elem)->atom_type,(yyvsp[0].elem)->atom_type,"=");
                    cout<<(yyvsp[-4].elem)->atom_type<<" "<<(yyvsp[0].elem)->atom_type<<" "<<ret_type<<endl;
                    if(ret_type == "Error"){
                        cerr<<"Error: Type mismatch1b in assignment\n";
                        exit(1);
                    }
                    if(ret_type != (yyvsp[0].elem)->atom_type){
                        create_ins(0, (yyvsp[-4].elem)->addr, "=", "("+ret_type+")"+chartostring((yyvsp[0].elem)->addr),"");
                    }
                    else{
                        create_ins(0, (yyvsp[-4].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
                    }
                }
                else{
                    cerr<<"Error: Variable "<<(yyvsp[-4].elem)->addr<<" already declared\n";
                    exit(1);
                }
            }
            //STE code end

            //typecheck
                string ret_type=typecast((yyvsp[-4].elem)->atom_type,(yyvsp[0].elem)->atom_type,"=");
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch1a in assignment\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    create_ins(0, (yyvsp[-4].elem)->addr, "=", "("+ret_type+")"+chartostring((yyvsp[0].elem)->addr),"");
                }
                else{
                    create_ins(0, (yyvsp[-4].elem)->addr, "=", (yyvsp[0].elem)->addr, "");
                }
            //typecheck done
        }
#line 2252 "parser.tab.c"
    break;

  case 40: /* expr_stmt: test COLON test EQUAL eq_testlist_star_expr_plus  */
#line 635 "parser.y"
                                                          {  //ye karna bhi hai? ha bhecnchod
            cout<<"in tctee"<<endl;
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem));
			(yyval.elem)->ins = (yyvsp[-4].elem)->ins;
			create_ins(0, (yyvsp[-4].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, ""); 
            //STE code start
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[-4].elem)->addr) == NULL){//iska type check karo mkc
                current_ste = insert_entry_same_scope(current_ste, "OBJECT", (yyvsp[-4].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[-4].elem)->lineno, 1, (yyvsp[0].elem)->list_size);
            }
            else{
                cerr<<"Error: Variable "<<(yyvsp[-4].elem)->addr<<" already declared\n";
                exit(1);
            }
            //STE code end
        }
#line 2273 "parser.tab.c"
    break;

  case 41: /* eq_testlist_star_expr_plus: test  */
#line 654 "parser.y"
                                 {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2281 "parser.tab.c"
    break;

  case 42: /* eq_testlist_star_expr_plus: test EQUAL eq_testlist_star_expr_plus  */
#line 657 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            //create_ins(0, $1->addr, $2->addr, $3->addr, "");
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;    //x=y=z
            //typecheking start
                (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"=");
                cout<<(yyvsp[-2].elem)->atom_type<<" "<<(yyvsp[0].elem)->atom_type<<" "<<ret_type<<endl;
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch2a in assignment\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    create_ins(0, (yyvsp[-2].elem)->addr, "=", "("+ret_type+")"+chartostring((yyvsp[0].elem)->addr),"");
                }
                else{
                    create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
                }
            //typecheck done
        }
#line 2308 "parser.tab.c"
    break;

  case 43: /* flow_stmt: break_stmt  */
#line 681 "parser.y"
                        {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2316 "parser.tab.c"
    break;

  case 44: /* flow_stmt: continue_stmt  */
#line 684 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2324 "parser.tab.c"
    break;

  case 45: /* flow_stmt: return_stmt  */
#line 687 "parser.y"
                         {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2332 "parser.tab.c"
    break;

  case 46: /* break_stmt: BREAK  */
#line 692 "parser.y"
                    {  
            // cout<<"break entered"<<endl;
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = instCount+1;
            int temp = loopStack.top();
            loopStack.pop();
            if(loopStack.size()!=0)create_ins(0, "goto", to_string(loopStack.top()), "", "");
            loopStack.push(temp);
            // cout<<"break ended"<<endl;
        }
#line 2347 "parser.tab.c"
    break;

  case 47: /* continue_stmt: CONTINUE  */
#line 703 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = instCount+1;
            create_ins(0, "goto", to_string(loopStack.top()), "", "");
        }
#line 2357 "parser.tab.c"
    break;

  case 48: /* return_stmt: RETURN  */
#line 709 "parser.y"
                        {  
            create_ins(0,"return","","","");
        }
#line 2365 "parser.tab.c"
    break;

  case 49: /* return_stmt: RETURN test  */
#line 712 "parser.y"
                          {  
            (yyval.elem)->return_param = str_to_ch(newTemp());
            create_ins(0,(yyval.elem)->return_param,"=",(yyvsp[0].elem)->addr,"");
            // paramStack.push($$->return_param);
            create_ins(0,"return",(yyval.elem)->return_param,"","");
        }
#line 2376 "parser.tab.c"
    break;

  case 50: /* global_stmt: GLOBAL NAME  */
#line 720 "parser.y"
                           {  
            (yyval.elem) = create_node(3, "global_stmt", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;

            
        }
#line 2387 "parser.tab.c"
    break;

  case 51: /* global_stmt: GLOBAL NAME comma_name_star  */
#line 726 "parser.y"
                                      {   
            (yyval.elem) = create_node(4, "global_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 2396 "parser.tab.c"
    break;

  case 52: /* comma_name_star: COMMA NAME  */
#line 732 "parser.y"
                               {  
            (yyval.elem) = create_node(3, "comma_name_star", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 2405 "parser.tab.c"
    break;

  case 53: /* comma_name_star: COMMA NAME comma_name_star  */
#line 736 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "comma_name_star", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 2414 "parser.tab.c"
    break;

  case 54: /* compound_stmt: if_stmt  */
#line 741 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);  
        }
#line 2422 "parser.tab.c"
    break;

  case 55: /* compound_stmt: while_stmt  */
#line 744 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
            loopStack.pop();
        }
#line 2431 "parser.tab.c"
    break;

  case 56: /* compound_stmt: for_stmt  */
#line 748 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
            loopStack.pop();
        }
#line 2440 "parser.tab.c"
    break;

  case 57: /* compound_stmt: funcdef  */
#line 752 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2448 "parser.tab.c"
    break;

  case 58: /* compound_stmt: classdef  */
#line 755 "parser.y"
                       {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 2456 "parser.tab.c"
    break;

  case 59: /* if_stmt: if_scope test COLON M suite  */
#line 760 "parser.y"
                                         {  
           (yyval.elem)=create_node(6, "if_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
           (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
           backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
           (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);

            //STE code start
            // current_ste = get_prev_scope(current_ste);  
            //STE code end

        }
#line 2472 "parser.tab.c"
    break;

  case 60: /* if_stmt: if_scope test COLON M suite N else_scope COLON M suite  */
#line 771 "parser.y"
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
#line 2489 "parser.tab.c"
    break;

  case 61: /* if_stmt: if_scope test COLON M suite N nts_star  */
#line 783 "parser.y"
                                                    {  
            (yyval.elem) = create_node(8, "if_elif_stmt", (yyvsp[-6].elem),(yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);     
            vector<int> temp = merge((yyvsp[-2].elem)->nextlist, (yyvsp[-1].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);    
        }
#line 2501 "parser.tab.c"
    break;

  case 62: /* if_stmt: if_scope d_expr COLON suite  */
#line 790 "parser.y"
                                      {
            (yyval.elem) = create_node(5, "if_stmt", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 2510 "parser.tab.c"
    break;

  case 63: /* d_expr: D_NAME EQUAL_EQUAL STRING  */
#line 796 "parser.y"
                                   {
            string dunder = chartostring((yyvsp[0].elem)->addr);
            cout<<(yyvsp[0].elem)->addr<<endl;
            if(dunder != "\"__main__\""){
                cerr<<"Error: Dunder name should be __main__\n";
                exit(1);
            }
            else{
                (yyval.elem)->ins = instCount;
            }
        }
#line 2526 "parser.tab.c"
    break;

  case 64: /* if_scope: IF  */
#line 808 "parser.y"
            {
        (yyval.elem)=(yyvsp[0].elem);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "IF", "IF", 0, $1->lineno, 0);
    }
#line 2536 "parser.tab.c"
    break;

  case 65: /* else_scope: ELSE  */
#line 815 "parser.y"
                {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        // current_ste = get_prev_scope(current_ste);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "ELSE", "ELSE", 0, $1->lineno, 1);

        //STE code end
    }
#line 2550 "parser.tab.c"
    break;

  case 66: /* else_if_scope: ELIF  */
#line 826 "parser.y"
                   {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        // current_ste = get_prev_scope(current_ste);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "ELSE_IF", "ELSE_IF", 0, $1->lineno, 1);
        //STE code end
    }
#line 2563 "parser.tab.c"
    break;

  case 67: /* nts_star: else_if_scope test COLON M suite  */
#line 837 "parser.y"
                                             {  
            (yyval.elem)=create_node(6, "elif_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end
        }
#line 2578 "parser.tab.c"
    break;

  case 68: /* nts_star: else_if_scope test COLON M suite N nts_star  */
#line 847 "parser.y"
                                                       {  
            (yyval.elem) = create_node(8, "elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-5].elem)->ins;
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist));
        }
#line 2590 "parser.tab.c"
    break;

  case 69: /* nts_star: else_if_scope test COLON M suite N else_scope COLON M suite  */
#line 854 "parser.y"
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
#line 2606 "parser.tab.c"
    break;

  case 70: /* while_stmt: while_scope M while_expr COLON M suite  */
#line 867 "parser.y"
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
#line 2623 "parser.tab.c"
    break;

  case 71: /* while_stmt: while_scope M while_expr COLON M suite N else_scope COLON M suite  */
#line 879 "parser.y"
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
#line 2641 "parser.tab.c"
    break;

  case 72: /* while_scope: WHILE  */
#line 894 "parser.y"
                   {
        (yyval.elem)=(yyvsp[0].elem);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "WHILE", "WHILE", 0, $1->lineno, 0);
    }
#line 2651 "parser.tab.c"
    break;

  case 73: /* while_expr: test  */
#line 901 "parser.y"
                   { 
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            loopStack.push((yyval.elem)->ins);
        }
#line 2661 "parser.tab.c"
    break;

  case 74: /* for_stmt: for_scope for_core COLON M suite  */
#line 907 "parser.y"
                                              { 
            (yyval.elem) = create_node(6, "for_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;

            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = (yyvsp[-3].elem)->falselist;   //check this filling //checked

            // create_ins(1, $2->for_it, "+", $2->for_it, "1");
            // backpatch($5->nextlist, instCount); //suite nextlist will be patched to update statement of for loop
            backpatch((yyvsp[0].elem)->nextlist, (yyvsp[-3].elem)->ins); //suite nextlist will be patched to update statement of for loop
            create_ins(0, "goto", to_string((yyvsp[-3].elem)->ins), "", "");
            // cout<<"for ended"<<endl; 

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end   
                 
        }
#line 2684 "parser.tab.c"
    break;

  case 75: /* for_stmt: for_scope for_core COLON M suite N ELSE COLON M suite  */
#line 925 "parser.y"
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
#line 2712 "parser.tab.c"
    break;

  case 76: /* for_core: expr IN range_stmt  */
#line 950 "parser.y"
                               { 
            // cout<<"for entered"<<endl;
            
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
#line 2736 "parser.tab.c"
    break;

  case 77: /* for_scope: FOR  */
#line 971 "parser.y"
               {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        //loopStack.push($$->ins);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "FOR", "FOR", 0, $1->lineno, 0);
        //STE code end
    }
#line 2749 "parser.tab.c"
    break;

  case 78: /* range_stmt: RANGE OPEN_BRACKET for_test CLOSE_BRACKET  */
#line 981 "parser.y"
                                                      {
            (yyval.elem) = create_node(5, "range_stmt", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;

            (yyval.elem)->for_end = (yyvsp[-1].elem)->addr;
            (yyval.elem)->for_start = strdup("0");
        }
#line 2761 "parser.tab.c"
    break;

  case 79: /* range_stmt: RANGE OPEN_BRACKET for_test COMMA test CLOSE_BRACKET  */
#line 988 "parser.y"
                                                               {
            (yyval.elem) = create_node(7, "range_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;

            (yyval.elem)->for_end = (yyvsp[-1].elem)->addr;
            (yyval.elem)->for_start = (yyvsp[-3].elem)->addr;
        }
#line 2773 "parser.tab.c"
    break;

  case 80: /* for_test: test  */
#line 997 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            //loopStack.push($$->ins);
        }
#line 2783 "parser.tab.c"
    break;

  case 81: /* suite: simple_stmt  */
#line 1004 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2791 "parser.tab.c"
    break;

  case 82: /* suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 1007 "parser.y"
                                            {
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 2799 "parser.tab.c"
    break;

  case 83: /* suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 1010 "parser.y"
                                                    { 
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 2807 "parser.tab.c"
    break;

  case 84: /* test: or_test  */
#line 1016 "parser.y"
                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2815 "parser.tab.c"
    break;

  case 85: /* or_test: and_test  */
#line 1022 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2823 "parser.tab.c"
    break;

  case 86: /* or_test: and_test_star OR M and_test  */
#line 1025 "parser.y"
                                         {  
            (yyval.elem) = create_node(5, "or_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;
        }
#line 2835 "parser.tab.c"
    break;

  case 87: /* and_test_star: and_test_star OR M and_test  */
#line 1033 "parser.y"
                                            {
            (yyval.elem) = create_node(5, "and_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;
        }
#line 2847 "parser.tab.c"
    break;

  case 88: /* and_test_star: and_test  */
#line 1040 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2855 "parser.tab.c"
    break;

  case 89: /* and_test: not_test  */
#line 1045 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2863 "parser.tab.c"
    break;

  case 90: /* and_test: not_test_star AND M not_test  */
#line 1048 "parser.y"
                                          {  
            (yyval.elem) = create_node(5, "and_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;
        }
#line 2875 "parser.tab.c"
    break;

  case 91: /* not_test_star: not_test_star AND M not_test  */
#line 1056 "parser.y"
                                              { 
            (yyval.elem) = create_node(5, "not_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;
        }
#line 2887 "parser.tab.c"
    break;

  case 92: /* not_test_star: not_test  */
#line 1063 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2895 "parser.tab.c"
    break;

  case 93: /* not_test: NOT not_test  */
#line 1068 "parser.y"
                         { 
            (yyval.elem) = create_node(3, "not_test", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->truelist = (yyvsp[0].elem)->falselist;
            (yyval.elem)->falselist = (yyvsp[0].elem)->truelist;
        }
#line 2906 "parser.tab.c"
    break;

  case 94: /* not_test: comparison  */
#line 1074 "parser.y"
                        { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2914 "parser.tab.c"
    break;

  case 95: /* not_test: TRUE  */
#line 1077 "parser.y"
              {
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->truelist = makelist(instCount+1);
            create_ins(0, "goto", "", "", "");
        }
#line 2924 "parser.tab.c"
    break;

  case 96: /* not_test: FALSE  */
#line 1082 "parser.y"
               {
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->falselist = makelist(instCount+2);
            create_ins(0, "goto", "", "", "");
        }
#line 2934 "parser.tab.c"
    break;

  case 97: /* comparison: expr  */
#line 1089 "parser.y"
                  {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2942 "parser.tab.c"
    break;

  case 98: /* comparison: expr comp_op comparison  */
#line 1092 "parser.y"
                                   { 
            (yyval.elem)=create_node(4, "comparison", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            (yyval.elem)->truelist = makelist(instCount+1);
            (yyval.elem)->falselist = makelist(instCount+2);

            //typechecking error
            
               if(((yyvsp[-2].elem)->atom_type == "str" && (yyvsp[0].elem)->atom_type != "str") || ((yyvsp[-2].elem)->atom_type != "str" && (yyvsp[0].elem)->atom_type == "str")){
                    cerr<<"Error: Type mismatch in comparison\n";
                    exit(1);
               }
            //typechecking error end
            create_ins(0, "if", (yyval.elem)->addr, "goto", "");
            create_ins(0, "goto", "", "", "");
        }
#line 2965 "parser.tab.c"
    break;

  case 99: /* comp_op: LESS_THAN  */
#line 1113 "parser.y"
                    {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2973 "parser.tab.c"
    break;

  case 100: /* comp_op: GREATER_THAN  */
#line 1116 "parser.y"
                    { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2981 "parser.tab.c"
    break;

  case 101: /* comp_op: EQUAL_EQUAL  */
#line 1119 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2989 "parser.tab.c"
    break;

  case 102: /* comp_op: GREATER_THAN_EQUAL  */
#line 1122 "parser.y"
                            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2997 "parser.tab.c"
    break;

  case 103: /* comp_op: LESS_THAN_EQUAL  */
#line 1125 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3005 "parser.tab.c"
    break;

  case 104: /* comp_op: NOT_EQUAL_ARROW  */
#line 1128 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3013 "parser.tab.c"
    break;

  case 105: /* comp_op: NOT_EQUAL  */
#line 1131 "parser.y"
                   {
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 3021 "parser.tab.c"
    break;

  case 106: /* comp_op: IN  */
#line 1134 "parser.y"
            {  
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3029 "parser.tab.c"
    break;

  case 107: /* comp_op: NOT IN  */
#line 1137 "parser.y"
                { 
        (yyval.elem) = create_node(3, "NOT IN", (yyvsp[-1].elem), (yyvsp[0].elem));
    }
#line 3037 "parser.tab.c"
    break;

  case 108: /* comp_op: IS  */
#line 1140 "parser.y"
            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3045 "parser.tab.c"
    break;

  case 109: /* comp_op: IS NOT  */
#line 1143 "parser.y"
                { 
        (yyval.elem) = create_node(3, "IS NOT", (yyvsp[-1].elem), (yyvsp[0].elem));
    }
#line 3053 "parser.tab.c"
    break;

  case 110: /* expr: xor_expr  */
#line 1148 "parser.y"
                  { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3061 "parser.tab.c"
    break;

  case 111: /* expr: xor_expr BIT_OR expr  */
#line 1151 "parser.y"
                                  {  
            (yyval.elem) = create_node(4, "expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            //$$->addr = str_to_ch(newTemp());
            //create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);

            //type_checking
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"|");
                //cout<<$1->atom_type<<" "<<$3->atom_type<<" "<<ret_type<<endl;
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch2b in assignment\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "|", str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)),(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
                else if(ret_type != (yyvsp[-2].elem)->atom_type){
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "|", str_to_ch("("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr)),(yyvsp[0].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
                }
                else{
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "|", (yyvsp[0].elem)->addr,(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
            //typecheck end
        }
#line 3097 "parser.tab.c"
    break;

  case 112: /* xor_expr: and_expr  */
#line 1184 "parser.y"
                   { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3105 "parser.tab.c"
    break;

  case 113: /* xor_expr: and_expr BIT_XOR xor_expr  */
#line 1187 "parser.y"
                                       {  
            (yyval.elem) = create_node(4, "xor_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            //$$->addr = str_to_ch(newTemp());
            //create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);

            //type_checking
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"^");
                //cout<<$1->atom_type<<" "<<$3->atom_type<<" "<<ret_type<<endl;
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch2c in assignment\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "^", str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)),(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
                else if(ret_type != (yyvsp[-2].elem)->atom_type){
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "^", str_to_ch("("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr)),(yyvsp[0].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
                }
                else{
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "^", (yyvsp[0].elem)->addr,(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
            //typecheck end
        }
#line 3141 "parser.tab.c"
    break;

  case 114: /* and_expr: shift_expr  */
#line 1220 "parser.y"
                       { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 3150 "parser.tab.c"
    break;

  case 115: /* and_expr: shift_expr BIT_AND and_expr  */
#line 1224 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "and_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            //$$->addr = str_to_ch(newTemp());
            //create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);
            
            //type_checking
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"&");
                //cout<<$1->atom_type<<" "<<$3->atom_type<<" "<<ret_type<<endl;
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch2d in assignment\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "&", str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)),(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
                else if(ret_type != (yyvsp[-2].elem)->atom_type){
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "&", str_to_ch("("+ret_type+")"+chartostring((yyvsp[-2].elem)->addr)),(yyvsp[0].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
                }
                else{
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "&", (yyvsp[0].elem)->addr,(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
            //typecheck end
        }
#line 3186 "parser.tab.c"
    break;

  case 116: /* shift_expr: arith_expr  */
#line 1257 "parser.y"
                         { 
                (yyval.elem) = (yyvsp[0].elem); 
            }
#line 3194 "parser.tab.c"
    break;

  case 117: /* shift_expr: arith_expr SHIFT_OPER shift_expr  */
#line 1260 "parser.y"
                                                 { 
                (yyval.elem) = create_node(4, "shift_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                // $$->addr = str_to_ch(newTemp());
                // create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);

                //type_checking
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,(yyvsp[-1].elem)->addr);
                //cout<<$1->atom_type<<" "<<$3->atom_type<<" "<<ret_type<<endl;
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch2e in assignment\n";
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
            }
#line 3230 "parser.tab.c"
    break;

  case 118: /* arith_expr: term  */
#line 1293 "parser.y"
                 { 
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 3238 "parser.tab.c"
    break;

  case 119: /* arith_expr: arith_expr PLUS term  */
#line 1296 "parser.y"
                                   { 
                
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                //$$->addr = str_to_ch(newTemp());
                //create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);
                //type_checking
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"+");
                // cout<<$1->addr<<" yo "<<endl;
                cout<<(yyvsp[-2].elem)->atom_type<<" "<<(yyvsp[0].elem)->atom_type<<" "<<ret_type<<endl;
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch2f in assignment\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    //string temp = newTemp(); 
                    (yyval.elem)->addr = str_to_ch(newTemp()); 
                    create_ins(1, (yyval.elem)->addr, "+", str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)),(yyvsp[-2].elem)->addr);
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
                    create_ins(1, (yyval.elem)->addr, "+", (yyvsp[0].elem)->addr,(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
            //typecheck end
            }
#line 3278 "parser.tab.c"
    break;

  case 120: /* arith_expr: arith_expr MINUS term  */
#line 1331 "parser.y"
                                    { 
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                //$$->addr = str_to_ch(newTemp());
                //create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);

                //type_checking
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,"-");
                //cout<<$1->atom_type<<" "<<$3->atom_type<<" "<<ret_type<<endl;
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch2g in assignment\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    //string temp = newTemp();
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, "-", str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)),(yyvsp[-2].elem)->addr);
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
                    create_ins(1, (yyval.elem)->addr, "-", (yyvsp[0].elem)->addr,(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
            //typecheck end
            }
#line 3317 "parser.tab.c"
    break;

  case 121: /* term: factor  */
#line 1366 "parser.y"
             {
            (yyval.elem) = (yyvsp[0].elem); 
        }
#line 3325 "parser.tab.c"
    break;

  case 122: /* term: term term_choice factor  */
#line 1369 "parser.y"
                                  {
            (yyval.elem) = create_node(4, "term", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            // $$->addr = str_to_ch(newTemp());
            // create_ins(1, $$->addr, $2->addr, $1->addr, $3->addr);

            //type_checking
                //Type_checking
                string ret_type=typecast((yyvsp[-2].elem)->atom_type,(yyvsp[0].elem)->atom_type,(yyvsp[-1].elem)->addr);
                //cout<<$1->atom_type<<" "<<$3->atom_type<<" "<<ret_type<<endl;
                if(ret_type == "Error"){
                    cerr<<"Error: Type mismatch2h in assignment\n";
                    exit(1);
                }
                if(ret_type != (yyvsp[0].elem)->atom_type){
                    //string temp = newTemp();
                    (yyval.elem)->addr = str_to_ch(newTemp());
                    create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, str_to_ch("("+ret_type+")"+chartostring((yyvsp[0].elem)->addr)),(yyvsp[-2].elem)->addr);
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
                    create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr,(yyvsp[-2].elem)->addr);
                    (yyval.elem)->atom_type = (yyvsp[-2].elem)->atom_type;
                }
            //typecheck end
        
		}
#line 3365 "parser.tab.c"
    break;

  case 123: /* term_choice: MULTIPLY  */
#line 1406 "parser.y"
                            { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3373 "parser.tab.c"
    break;

  case 124: /* term_choice: ATTHERATE  */
#line 1409 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3381 "parser.tab.c"
    break;

  case 125: /* term_choice: DIVIDE  */
#line 1412 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3389 "parser.tab.c"
    break;

  case 126: /* term_choice: REMAINDER  */
#line 1415 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3397 "parser.tab.c"
    break;

  case 127: /* term_choice: FLOOR_DIV_OPER  */
#line 1418 "parser.y"
                           { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3405 "parser.tab.c"
    break;

  case 128: /* factor: factor_choice factor  */
#line 1423 "parser.y"
                                    {  
            (yyval.elem) = create_node(3, "factor", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            (yyval.elem)->atom_type = (yyvsp[0].elem)->atom_type;
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr,"", (yyvsp[0].elem)->addr);

            if((yyvsp[0].elem)->atom_type=="str"){
                cerr<<"Error: Type mismatch in assignment\n";
                exit(1);
            }
        }
#line 3422 "parser.tab.c"
    break;

  case 129: /* factor: power  */
#line 1435 "parser.y"
                    { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3430 "parser.tab.c"
    break;

  case 130: /* factor_choice: PLUS  */
#line 1439 "parser.y"
                            {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3438 "parser.tab.c"
    break;

  case 131: /* factor_choice: MINUS  */
#line 1442 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3446 "parser.tab.c"
    break;

  case 132: /* factor_choice: NEGATION  */
#line 1445 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3454 "parser.tab.c"
    break;

  case 133: /* power: atom_expr  */
#line 1449 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3462 "parser.tab.c"
    break;

  case 134: /* power: atom_expr POWER_OPERATOR factor  */
#line 1452 "parser.y"
                                            { 
            (yyval.elem) = create_node(4, "power", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);

            if((yyvsp[-2].elem)->atom_type=="str" || (yyvsp[0].elem)->atom_type=="str"){
                cerr<<"Error: Type mismatch in assignment\n";
                exit(1);
            }
        }
#line 3478 "parser.tab.c"
    break;

  case 135: /* atom_expr: atom  */
#line 1465 "parser.y"
                {  
            (yyval.elem) = (yyvsp[0].elem);  
        }
#line 3486 "parser.tab.c"
    break;

  case 136: /* atom_expr: atom_expr trailer  */
#line 1468 "parser.y"
                            {   //this is function call
            (yyval.elem) = create_node(3, "atom_expr", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;

            string temp = newTemp();
            (yyval.elem)->addr = str_to_ch(temp);
            create_ins(0, temp, "=" ,"call "+chartostring((yyvsp[-1].elem)->addr), "");
            create_ins(0, "PopParam", temp, "", "");
            backpatch((yyvsp[0].elem)->nextlist, instCount);

            ste* function_ste;

            if(chartostring((yyvsp[-1].elem)->type) == "self_call"){
                ste* lookup_ste = lookup(current_ste, (yyvsp[-1].elem)->class_param);
                function_ste=lookup_ste;
                //print_ste(global_sym_table,0);
                if(lookup_ste == NULL){
                    cerr<<"Error: Function in selfcall "<<(yyvsp[-1].elem)->class_param<<" not declared in class\n";
                    exit(1);
                }
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
                    cerr<<"Error: Class "<<class_name<<" not declared\n";
                    exit(1);
                }
                ste* class_ste = class_map[class_name];
                    cout<<"atom_exprr: class call "<<class_name<<endl;
            
                  //here
                    ste* lookup_ste = single_rev_lookup(class_ste->next_scope, (yyvsp[-1].elem)->class_param); 
                    if(lookup_ste == NULL){
                        cerr<<"Error: Function "<<(yyvsp[-1].elem)->class_param<<" not declared in class "<<class_name<<endl;
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
                    cerr<<"Error: Class "<<lookup_ste->type<<" not declared\n";
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
                
                //single rev matlab usi scope me dekhega, hume usi me chahiye kyuki
                lookup_ste = lookup_ste->next_scope;
                ste* lookup_ste2 = single_rev_lookup(lookup_ste, func_name);
                if(lookup_ste2 == NULL){
                    cerr<<"Error: Function "<<func_name<<" not declared in object "<<object_name<<endl;
                    exit(1);
                }
                else{
                    if(lookup_ste2->type != "FUNCTION"){
                        cerr<<"Error: "<<func_name<<" is not a function\n";
                        exit(1);
                    }
                    function_ste=lookup_ste;
                    (yyval.elem)->atom_type = lookup_ste2->return_type;
                }

            }
            else if(chartostring((yyvsp[-1].elem)->type) == "class_constructor"){ //LALRparser(self,"abc") is type wale
                (yyval.elem)->type = str_to_ch("class_constructor");
                (yyval.elem)->atom_type = "object";
                //add 3ac for calling constructor if required// I think it will be in test colon test equal eqtes

                //see that the parameters passed are correct and type checking
                ste* lookup_ste;
                if(class_map.find(chartostring((yyvsp[-1].elem)->addr))==class_map.end()){
                    cerr<<"Error: Class "<<(yyvsp[-1].elem)->addr<<" not declared\n";
                }
                else{
                    lookup_ste=class_map[chartostring((yyvsp[-1].elem)->addr)];
                }
                lookup_ste=single_rev_lookup(lookup_ste->next_scope,"__init__");
                function_ste=lookup_ste;
            }
            else{
            //typecheck
                (yyval.elem)->type = str_to_ch("function_call");
                ste* lookup_ste = lookup(current_ste, (yyvsp[-1].elem)->addr);
                if(lookup_ste == NULL){ //print_ste(current_ste,2);
                    cerr<<"Error: Function "<<(yyvsp[-1].elem)->addr<<" not declared\n";
                    exit(1);
                } //else wala part is by chatgpt
                else{
                    //Type_checking
                    cout<<lookup_ste->type<<endl;
                    if(lookup_ste->type != "FUNCTION"){
                        cerr<<"Error: "<<(yyvsp[-1].elem)->addr<<" is not a function\n";
                        exit(1);
                    }
                    function_ste=lookup_ste;
                    (yyval.elem)->atom_type = lookup_ste->return_type;
                    //cout<<$$->atom_type<<endl;
                }
            }
            //endtypecheck


            //function ke parameters ka type check idhar 
            cout<<(yyvsp[0].elem)->func_par_type.size()<<" "<<function_ste->func_par_type.size()<<endl;
            if(function_ste->num_params != (yyvsp[0].elem)->num_params){
                cerr<<"Error: Number of parameters mismatch\n";
                exit(1);
            }
            cout<<"para check start"<<endl;
            for(int i=0;i< (yyvsp[0].elem)->func_par_type.size();i++){
                cout<<(yyvsp[0].elem)->func_par_type[i]<<" "<< function_ste->func_par_type[i]<<endl;
                if((yyvsp[0].elem)->func_par_type[i] != function_ste->func_par_type[i]){
                    cerr<<"Error: Mismatch of a parameter in function: "<<function_ste->lexeme<<"\n";
                    exit(1);
                }
            }
            cout<<"para check end"<<endl;

        }
#line 3644 "parser.tab.c"
    break;

  case 137: /* atom_expr: atom_expr SQUARE_OPEN test SQUARE_CLOSE  */
#line 1621 "parser.y"
                                                 {   //array access
            cout<<"ENTER YOU FUCKING BITCH"<<endl;
            (yyval.elem) = create_node(5, "atom_expr", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            //$$->atom_type= $1->atom_type; //check this
            (yyval.elem)->addr = str_to_ch(newTemp());
            //cout<<"in atom_expr "<<temp<<endl;
            create_ins(1, (yyval.elem)->addr, "*", (yyvsp[-1].elem)->addr, to_string(get_width(lookup(current_ste, (yyvsp[-3].elem)->addr)->type)));
            (yyval.elem)->addr = str_to_ch(chartostring((yyvsp[-3].elem)->addr) + "["+chartostring((yyval.elem)->addr)+"]");

            //typechecking handle and $$->atom_type also

            (yyval.elem)->type= str_to_ch("array_element");
            ste* lookup_ste = lookup(current_ste, (yyvsp[-3].elem)->addr);
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
            (yyval.elem)->atom_type = array_type;
            cout<<(yyval.elem)->atom_type<<endl;
             //check this suppose a[2] hai to hum a ka type dekhenge

        }
#line 3678 "parser.tab.c"
    break;

  case 138: /* atom_expr: atom_expr DOT NAME  */
#line 1650 "parser.y"
                             { 
            // cout<<"symbol table in atom_expr"<<endl; 
            // print_ste(global_sym_table,0);
            (yyval.elem) = create_node(4, "atom_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(chartostring((yyvsp[-2].elem)->addr) + "." + chartostring((yyvsp[0].elem)->addr));

            //typechecking handle and $$->addtype also

            //for objects like in sirs testcase3 obj.print_name() or obj.x 
            ste*  lookup_ste = lookup(current_ste, (yyvsp[-2].elem)->addr);
            if(lookup_ste == NULL){
                cerr<<"Error: Object "<<(yyvsp[-2].elem)->addr<<" not declared\n";
                exit(1);
            }
            if(lookup_ste -> token == "OBJECT"){
                (yyval.elem)->type = str_to_ch("object_call");
                //see what else to do
            }
            //here it ends
            else{
                (yyval.elem)->type = str_to_ch("class_call");
                //cout<<$1->addr<<endl; 
                //print_ste(global_sym_table,0);
                //here also should I check using class map? may be no because abhi jaha current_ste hai waha se kuch class shyd access na ho paye 
                ste* lookup_ste = lookup(current_ste, (yyvsp[-2].elem)->addr);
                if(lookup_ste == NULL){
                    cerr<<"Error: Class "<<(yyvsp[-2].elem)->addr<<" not declared\n";
                    exit(1);
                } //else wala part is by chatgpt
                else{
                    //Type_checking
                    if(lookup_ste->type != "CLASS"){ //public3 wala part me lalrparser ka type yaha khali aa rha check
                        cout<<"check "<<lookup_ste->lexeme<<" "<<lookup_ste->type<<endl;
                        lookup_ste = lookup(current_ste, lookup_ste->type);
                        cout<<"check lexeme "<<lookup_ste->lexeme<<endl;
                        //why we are setting $$->addr again
                        (yyval.elem)->addr = str_to_ch(lookup_ste->lexeme + "." + chartostring((yyvsp[0].elem)->addr));
                    }
                    (yyval.elem)->class_param = ((yyvsp[0].elem)->addr);
                }
            }


            //we need to get atom_type here, //it will be only for already defined
            //function wale ka to upar trailer me jaake set ho jayega, yaha pe hume sirf normal wale ka nikalna hoga (kisi object ka)
            ste* lookup_ste2 = lookup(current_ste,(yyvsp[-2].elem)->addr);
            if(lookup_ste2 ->token == "OBJECT"){
                string classname= lookup_ste2 -> type;
                lookup_ste2 = class_map[classname]; //symboltable entry of class
                ste* attribute = lookup(lookup_ste2,(yyvsp[0].elem)->addr);
                if(attribute == NULL){
                    attribute = single_rev_lookup(lookup_ste2->next_scope,(yyvsp[0].elem)->addr);
                }
                if(attribute!= NULL){ 
                    (yyval.elem)->atom_type = attribute->type;
                }
                //error condition daal sakte
            //cout<< "atom expr dot name: "<<$$->atom_type<<endl;
            }

        }
#line 3745 "parser.tab.c"
    break;

  case 139: /* atom_expr: LEN OPEN_BRACKET test CLOSE_BRACKET  */
#line 1712 "parser.y"
                                              { 
            (yyval.elem) = create_node(5, "atom_expr", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            //$$->addr = str_to_ch("len("+chartostring($3->addr)+")");
            (yyval.elem)->atom_type = "int";
            int list_size;

            // if($3->type == str_to_ch("NAME")){
            //     ste* lookup_ste = lookup(current_ste, $3->addr);
            //     list_size = lookup_ste->list_size;
            // }
            // else{
            //     list_size = $3->list_size;
            // }

            create_ins(0, "PushParam", (yyvsp[-1].elem)->addr, "", "");
            create_ins(0, "call", "len", "", "");
            string temp = newTemp();
            create_ins(0, temp, "=", "PopParam", "");
            (yyval.elem)->addr = str_to_ch(temp);
        }
#line 3771 "parser.tab.c"
    break;

  case 140: /* atom_expr: PRINT OPEN_BRACKET test CLOSE_BRACKET  */
#line 1733 "parser.y"
                                                { 
            (yyval.elem) = create_node(5, "atom_expr", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            //$$->addr = str_to_ch("print("+chartostring($3->addr)+")");
            (yyval.elem)->atom_type = "None";
            create_ins(0, "PushParam", (yyvsp[-1].elem)->addr, "", "");
            create_ins(0, "call", "print", "", "");
            create_ins(0, "PopParam", "1", "", "");
        }
#line 3785 "parser.tab.c"
    break;

  case 141: /* atom_expr: SELF DOT NAME  */
#line 1742 "parser.y"
                        {
            (yyval.elem) = create_node(4, "atom_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
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
            ste* attribute = lookup(lookup_ste2,(yyvsp[0].elem)->addr);
            if(attribute == NULL){
                attribute = single_rev_lookup(lookup_ste2->next_scope,(yyvsp[0].elem)->addr);
            }
            if(attribute!= NULL){ 
                (yyval.elem)->atom_type = attribute->type;
            }
            // cout<<"self dot name: "<< $$->atom_type<<endl;

        }
#line 3816 "parser.tab.c"
    break;

  case 142: /* atom: OPEN_BRACKET testlist CLOSE_BRACKET  */
#line 1787 "parser.y"
                                         { 
        (yyval.elem)=(yyvsp[-1].elem);
    }
#line 3824 "parser.tab.c"
    break;

  case 143: /* atom: OPEN_BRACKET CLOSE_BRACKET  */
#line 1790 "parser.y"
                                    {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 3833 "parser.tab.c"
    break;

  case 144: /* atom: SQUARE_OPEN testlist SQUARE_CLOSE  */
#line 1795 "parser.y"
                                           { 
        cout<<"hello"<<endl;
        (yyval.elem) = (yyvsp[-1].elem);
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
        create_ins(0,"HeapAlloc", to_string(get_width(type)) + "*" + to_string((yyvsp[-1].elem)->list_size), "", "");
    }
#line 3854 "parser.tab.c"
    break;

  case 145: /* atom: SQUARE_OPEN SQUARE_CLOSE  */
#line 1811 "parser.y"
                                {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 3863 "parser.tab.c"
    break;

  case 146: /* atom: CURLY_OPEN CURLY_CLOSE  */
#line 1816 "parser.y"
                                { 
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 3872 "parser.tab.c"
    break;

  case 147: /* atom: NAME  */
#line 1821 "parser.y"
              {
        (yyval.elem)->type = str_to_ch("NAME");  //is this required?
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;

        //cout<< $1->addr<<endl;
        //here we are adding the atom_type if it exists in the symbol table
        ste* lookup_ste = lookup(current_ste, (yyvsp[0].elem)->addr);
        //cout<< $1->addr<<endl;
        if(lookup_ste ){
            if(lookup_ste->is_func_class){
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
            (yyval.elem)->atom_type = "object";
        }
    }
#line 3904 "parser.tab.c"
    break;

  case 148: /* atom: NUMBER  */
#line 1848 "parser.y"
                   { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
        // cout<<$$->atom_type<<endl;
    }
#line 3914 "parser.tab.c"
    break;

  case 149: /* atom: STRING_PLUS  */
#line 1853 "parser.y"
                        { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 3922 "parser.tab.c"
    break;

  case 150: /* atom: ATOM_KEYWORDS  */
#line 1856 "parser.y"
                        { 
        (yyval.elem)->atom_type="bool";
        (yyval.elem)->type=str_to_ch("bool");
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 3933 "parser.tab.c"
    break;

  case 151: /* atom: NONE  */
#line 1862 "parser.y"
                { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
        (yyval.elem)->atom_type="None";
    }
#line 3943 "parser.tab.c"
    break;

  case 152: /* STRING_PLUS: STRING  */
#line 1873 "parser.y"
                        {
            (yyval.elem) = (yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
            (yyval.elem)->type=str_to_ch("str");
            (yyval.elem)->atom_type="str";
        }
#line 3954 "parser.tab.c"
    break;

  case 153: /* STRING_PLUS: STRING STRING_PLUS  */
#line 1879 "parser.y"
                                { 
            (yyval.elem) = create_node(3, "STRING_PLUS", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->atom_type="str";
            (yyval.elem)->type=str_to_ch("str");

        }
#line 3966 "parser.tab.c"
    break;

  case 154: /* trailer: OPEN_BRACKET CLOSE_BRACKET  */
#line 1888 "parser.y"
                                     { 
            (yyval.elem) = create_node(3, "trailer", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;

            create_ins(0, "PushParam", "", "", "");
            (yyval.elem)->nextlist = makelist(instCount);
        }
#line 3978 "parser.tab.c"
    break;

  case 155: /* trailer: OPEN_BRACKET arglist CLOSE_BRACKET  */
#line 1895 "parser.y"
                                              {
            (yyval.elem)=(yyvsp[-1].elem);

            //func_par_type
            (yyval.elem)->func_par_type = (yyvsp[-1].elem)->func_par_type;
        }
#line 3989 "parser.tab.c"
    break;

  case 156: /* trailer: OPEN_BRACKET SELF COMMA arglist CLOSE_BRACKET  */
#line 1901 "parser.y"
                                                         {
            (yyval.elem)=(yyvsp[-1].elem);

            //func_par_type
            (yyval.elem)->func_par_type = (yyvsp[-1].elem)->func_par_type;
        }
#line 4000 "parser.tab.c"
    break;

  case 157: /* trailer: OPEN_BRACKET SELF CLOSE_BRACKET  */
#line 1907 "parser.y"
                                          {
            (yyval.elem) = create_node(4, "trailer", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 4009 "parser.tab.c"
    break;

  case 158: /* testlist: testlist_list  */
#line 1919 "parser.y"
                           { 
            //cout<<$1->atom_type<<endl; 
            (yyval.elem) = (yyvsp[0].elem);
            (yyval.elem)-> addr = str_to_ch(chartostring((yyvsp[0].elem)->addr) + "]");
        }
#line 4019 "parser.tab.c"
    break;

  case 159: /* testlist: testlist_list COMMA  */
#line 1924 "parser.y"
                                {
            (yyval.elem)=create_node(3,"testlist",(yyvsp[-1].elem),(yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
            (yyval.elem)->list_size = (yyvsp[-1].elem)->list_size;
            (yyval.elem)->atom_type = (yyvsp[-1].elem)->atom_type;
            (yyval.elem)-> addr = str_to_ch(chartostring((yyvsp[-1].elem)->addr) + "]");
        }
#line 4031 "parser.tab.c"
    break;

  case 160: /* testlist_list: test  */
#line 1932 "parser.y"
                            {
            (yyval.elem) = (yyvsp[0].elem);
            (yyval.elem)->list_size = 1;
            (yyval.elem)-> addr = str_to_ch( "[" + chartostring((yyvsp[0].elem)->addr));

            // //function parameters check 
            // $$->func_par_type.push_back($1->atom_type);
        }
#line 4044 "parser.tab.c"
    break;

  case 161: /* testlist_list: test COLON TYPE_HINT  */
#line 1940 "parser.y"
                              {
            (yyval.elem) = create_node(4, "testlist_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
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
                cerr<<"Error: Variable "<<(yyvsp[-2].elem)->addr<<" already declared\n";
                exit(1);
            }
            //STE code end

            // //function parameters check 
            // $$->func_par_type.push_back(chartostring($3->addr));

        }
#line 4071 "parser.tab.c"
    break;

  case 162: /* testlist_list: testlist_list COMMA test  */
#line 1962 "parser.y"
                                    { 
            (yyval.elem) = create_node(4, "testlist_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
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
        }
#line 4091 "parser.tab.c"
    break;

  case 163: /* testlist_list: testlist_list COMMA test COLON TYPE_HINT  */
#line 1977 "parser.y"
                                                   { 
            (yyval.elem) = create_node(6, "testlist_list", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;

            (yyvsp[-2].elem)->atom_type = (yyvsp[0].elem)->addr;
            (yyval.elem)->atom_type = "list["+(yyvsp[-2].elem)->atom_type+"]";

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

            // //function parameters check 
            // $$->func_par_type = $1->func_par_type;
            // $$->func_par_type.push_back(chartostring($5->addr));
        }
#line 4118 "parser.tab.c"
    break;

  case 164: /* classdef: CLASS class_declare COLON class_body_suite  */
#line 2032 "parser.y"
                                                    {
            (yyval.elem) = create_node(5, "classdef", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem),(yyvsp[0].elem));
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
        }
#line 4142 "parser.tab.c"
    break;

  case 165: /* class_declare: NAME  */
#line 2053 "parser.y"
                     {
            (yyval.elem)=(yyvsp[0].elem);
            inClass=1;
            className = chartostring((yyvsp[0].elem)->addr);


            //STE code start
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[0].elem)->addr) == NULL){
                current_ste = insert_entry_new_scope(current_ste);
                class_map[chartostring((yyvsp[0].elem)->addr)]=current_ste->prev_scope;
                current_ste = insert_entry_same_scope(current_ste,chartostring((yyvsp[0].elem)->addr),"self","CLASS",(yyvsp[0].elem)->lineno,0);
            }
            else{
                cerr<<"Error: Class "<<(yyvsp[0].elem)->addr<<" already declared\n";
                exit(1);
            }
            //STE code end 
        }
#line 4166 "parser.tab.c"
    break;

  case 166: /* class_declare: NAME OPEN_BRACKET CLOSE_BRACKET  */
#line 2072 "parser.y"
                                         {
            (yyval.elem)=(yyvsp[-2].elem);
            inClass=1;
            className = chartostring((yyvsp[-2].elem)->addr);


            //STE code start
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[-2].elem)->addr) == NULL){
                current_ste = insert_entry_new_scope(current_ste);
                class_map[chartostring((yyvsp[-2].elem)->addr)]=current_ste->prev_scope;
                current_ste = insert_entry_same_scope(current_ste,chartostring((yyvsp[-2].elem)->addr),"self","CLASS",(yyvsp[-2].elem)->lineno,0);
            }
            else{
                cerr<<"Error: Class "<<(yyvsp[-2].elem)->addr<<" already declared\n";
                exit(1);
            }
            //STE code end 
        }
#line 4190 "parser.tab.c"
    break;

  case 167: /* class_declare: NAME OPEN_BRACKET argument CLOSE_BRACKET  */
#line 2091 "parser.y"
                                                  {
            (yyval.elem) = create_node(5, "class_declare", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->addr = (yyvsp[-3].elem)->addr;
            inClass=1;
            ischild=1; 
            className = chartostring((yyvsp[-3].elem)->addr);
            // cout<<"in class dec: "<<chartostring($3->addr)<<endl;
            if(class_map.find(chartostring((yyvsp[-1].elem)->addr)) == class_map.end()){
                cerr<<"Error: Class "<<(yyvsp[-1].elem)->addr<<" not declared\n";
                exit(1);
            }
            else{
                current_ste = class_map[chartostring((yyvsp[-1].elem)->addr)];
                current_ste = current_ste->next_scope;
            }
            if(current_ste== NULL){
                cerr<<"Error: Class "<<(yyvsp[-1].elem)->addr<<" not declared\n";
                exit(1);
            }
            while(current_ste->next!=NULL){
                current_ste = current_ste->next;
            }
            ste* lookup_ste = current_ste;
            if(lookup(lookup_ste, (yyvsp[-3].elem)->addr) == NULL){
                current_ste = insert_entry_new_scope(current_ste);
                class_map[chartostring((yyvsp[-3].elem)->addr)]=current_ste->prev_scope;
                current_ste = insert_entry_same_scope(current_ste,chartostring((yyvsp[-3].elem)->addr),"self","CLASS",(yyvsp[-3].elem)->lineno,0);
            }
            else{
                cerr<<"Error: Class "<<(yyvsp[-3].elem)->addr<<" already declared\n";
                exit(1);
            }
            
        }
#line 4230 "parser.tab.c"
    break;

  case 168: /* class_body_suite: NEWLINE INDENT funcdef_plus DEDENT  */
#line 2154 "parser.y"
                                                        { 
            (yyval.elem)=(yyvsp[-1].elem);
            inClass=0;
        }
#line 4239 "parser.tab.c"
    break;

  case 169: /* class_body_suite: NEWLINE INDENT funcdef_plus NEWLINE DEDENT  */
#line 2158 "parser.y"
                                                        { 
            (yyval.elem)=(yyvsp[-2].elem);
            inClass=0;
        }
#line 4248 "parser.tab.c"
    break;

  case 170: /* funcdef_plus: funcdef  */
#line 2164 "parser.y"
                       { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 4256 "parser.tab.c"
    break;

  case 171: /* funcdef_plus: funcdef_plus funcdef  */
#line 2167 "parser.y"
                                 { 
            (yyval.elem)=create_node(3,"funcdef_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 4265 "parser.tab.c"
    break;

  case 172: /* arglist: argument_list  */
#line 2194 "parser.y"
                           { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 4273 "parser.tab.c"
    break;

  case 173: /* arglist: argument_list COMMA  */
#line 2197 "parser.y"
                                 { 
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 4281 "parser.tab.c"
    break;

  case 174: /* argument_list: argument  */
#line 2201 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;

            (yyval.elem)->ins = instCount+1;
            (yyval.elem)->nextlist = makelist(instCount+1);
            create_ins(0, "PushParam", "", "", "");
            create_ins(0, "PushParam", (yyvsp[0].elem)->addr, "", "");
        
        }
#line 4296 "parser.tab.c"
    break;

  case 175: /* argument_list: argument_list COMMA argument  */
#line 2211 "parser.y"
                                        { 
            (yyval.elem) = create_node(4, "argument_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[-2].elem)->num_params + 1;

            create_ins(0, "PushParam", (yyvsp[0].elem)->addr, "", "");
            (yyval.elem)->nextlist = (yyvsp[-2].elem)->nextlist;

            //function par type
            (yyval.elem)->func_par_type = (yyvsp[-2].elem)->func_par_type;
            for(int i=0;i< (yyvsp[0].elem)->func_par_type.size();i++){
                (yyval.elem)->func_par_type.push_back((yyvsp[0].elem)->func_par_type[i]);
            }
        }
#line 4315 "parser.tab.c"
    break;

  case 176: /* argument: test  */
#line 2227 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
            //for function parameter typecheck
            (yyval.elem)->func_par_type.push_back((yyvsp[0].elem)->atom_type);
        }
#line 4325 "parser.tab.c"
    break;

  case 177: /* argument: test EQUAL test  */
#line 2232 "parser.y"
                            { 
            (yyval.elem) = create_node(4, "argument", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");

            //for function parameter typecheck
            (yyval.elem)->func_par_type.push_back((yyvsp[-2].elem)->atom_type);
        }
#line 4338 "parser.tab.c"
    break;

  case 178: /* stmt_plus: stmt  */
#line 2243 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 4346 "parser.tab.c"
    break;

  case 179: /* stmt_plus: stmt stmt_plus  */
#line 2246 "parser.y"
                            { 
            (yyval.elem)=create_node(3,"stmt_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
            (yyval.elem)->nextlist = merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist);
        }
#line 4356 "parser.tab.c"
    break;


#line 4360 "parser.tab.c"

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

#line 2252 "parser.y"


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
			return "boolean";
		}
		else
		{
			if (typ1==typ2)
				return "boolean";
			else
				return "Error";
		}
	}
	if (op=="&&" || op=="||")
	{
		if (typ1==typ2 && typ1=="boolean")
			return "boolean";
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
	if (op=="&" || op=="|" || op=="^" || op=="<<" || op==">>" || op==">>>")
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
			if (typ1=="String")
				return "String";
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

void typechecking_assign(NODE* a, NODE* b, string op){
    string a_type = chartostring(a->type);
    string b_type = chartostring(b->type);

    /* string b_atype = "";
    if(b_type == "int" || b_type == "float" || b_type == "str" || b_type == "bool"){
        b_atype = b_type;
    }
    else if (b_type == "list[int]" || b_type == "list[float]" || b_type == "list[str]" || b_type == "list[bool]"){
        int i=0;
    }

    //int float str bool
    if(a_type == "int" || a_type == "float" || a_type == "str" || a_type == "bool"){
        cerr<<"Error: Wrong assignment\n";
        exit(1);
    }
    //Variable
    if(a_type == "NAME"){
        ste* lookup_ste = lookup(current_ste, a->addr);
        if(lookup_ste == NULL){
            cerr<<"Error: Variable "<<a->addr<<" not declared\n";
            exit(1);
        }
        //string type = typecheck(lookup_ste->type, b_type, op);
    } */
    //list[int] ......
    //
}



int main(int argc, char* argv[]){    
    /* cout<<"Hello\n"; */
    FILE* yyin = fopen(argv[1],"r");
    yyrestart(yyin); 

    /* bool inset = false, outset = false; */
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
