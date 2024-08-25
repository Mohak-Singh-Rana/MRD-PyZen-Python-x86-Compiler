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

#line 161 "parser.tab.c"

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
  YYSYMBOL_T = 75,                         /* T  */
  YYSYMBOL_func_name = 76,                 /* func_name  */
  YYSYMBOL_func_ret_type = 77,             /* func_ret_type  */
  YYSYMBOL_parameters = 78,                /* parameters  */
  YYSYMBOL_typedargslist = 79,             /* typedargslist  */
  YYSYMBOL_typedarg = 80,                  /* typedarg  */
  YYSYMBOL_tfpdef = 81,                    /* tfpdef  */
  YYSYMBOL_stmt = 82,                      /* stmt  */
  YYSYMBOL_simple_stmt = 83,               /* simple_stmt  */
  YYSYMBOL_small_stmt_list = 84,           /* small_stmt_list  */
  YYSYMBOL_small_stmt = 85,                /* small_stmt  */
  YYSYMBOL_expr_stmt = 86,                 /* expr_stmt  */
  YYSYMBOL_eq_testlist_star_expr_plus = 87, /* eq_testlist_star_expr_plus  */
  YYSYMBOL_flow_stmt = 88,                 /* flow_stmt  */
  YYSYMBOL_break_stmt = 89,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 90,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 91,               /* return_stmt  */
  YYSYMBOL_global_stmt = 92,               /* global_stmt  */
  YYSYMBOL_comma_name_star = 93,           /* comma_name_star  */
  YYSYMBOL_compound_stmt = 94,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 95,                   /* if_stmt  */
  YYSYMBOL_if_expr = 96,                   /* if_expr  */
  YYSYMBOL_d_expr = 97,                    /* d_expr  */
  YYSYMBOL_if_scope = 98,                  /* if_scope  */
  YYSYMBOL_else_scope = 99,                /* else_scope  */
  YYSYMBOL_else_if_scope = 100,            /* else_if_scope  */
  YYSYMBOL_nts_star = 101,                 /* nts_star  */
  YYSYMBOL_while_stmt = 102,               /* while_stmt  */
  YYSYMBOL_while_scope = 103,              /* while_scope  */
  YYSYMBOL_while_expr = 104,               /* while_expr  */
  YYSYMBOL_for_stmt = 105,                 /* for_stmt  */
  YYSYMBOL_for_core = 106,                 /* for_core  */
  YYSYMBOL_for_scope = 107,                /* for_scope  */
  YYSYMBOL_range_stmt = 108,               /* range_stmt  */
  YYSYMBOL_for_test = 109,                 /* for_test  */
  YYSYMBOL_suite = 110,                    /* suite  */
  YYSYMBOL_test = 111,                     /* test  */
  YYSYMBOL_or_test = 112,                  /* or_test  */
  YYSYMBOL_and_test_star = 113,            /* and_test_star  */
  YYSYMBOL_and_test = 114,                 /* and_test  */
  YYSYMBOL_not_test_star = 115,            /* not_test_star  */
  YYSYMBOL_not_test = 116,                 /* not_test  */
  YYSYMBOL_comparison = 117,               /* comparison  */
  YYSYMBOL_comp_op = 118,                  /* comp_op  */
  YYSYMBOL_expr = 119,                     /* expr  */
  YYSYMBOL_xor_expr = 120,                 /* xor_expr  */
  YYSYMBOL_and_expr = 121,                 /* and_expr  */
  YYSYMBOL_shift_expr = 122,               /* shift_expr  */
  YYSYMBOL_arith_expr = 123,               /* arith_expr  */
  YYSYMBOL_term = 124,                     /* term  */
  YYSYMBOL_term_choice = 125,              /* term_choice  */
  YYSYMBOL_factor = 126,                   /* factor  */
  YYSYMBOL_factor_choice = 127,            /* factor_choice  */
  YYSYMBOL_power = 128,                    /* power  */
  YYSYMBOL_atom_expr = 129,                /* atom_expr  */
  YYSYMBOL_S = 130,                        /* S  */
  YYSYMBOL_atom = 131,                     /* atom  */
  YYSYMBOL_STRING_PLUS = 132,              /* STRING_PLUS  */
  YYSYMBOL_trailer = 133,                  /* trailer  */
  YYSYMBOL_testlist = 134,                 /* testlist  */
  YYSYMBOL_testlist_list = 135,            /* testlist_list  */
  YYSYMBOL_classdef = 136,                 /* classdef  */
  YYSYMBOL_class_declare = 137,            /* class_declare  */
  YYSYMBOL_class_body_suite = 138,         /* class_body_suite  */
  YYSYMBOL_funcdef_plus = 139,             /* funcdef_plus  */
  YYSYMBOL_arglist = 140,                  /* arglist  */
  YYSYMBOL_argument_list = 141,            /* argument_list  */
  YYSYMBOL_argument = 142,                 /* argument  */
  YYSYMBOL_stmt_plus = 143                 /* stmt_plus  */
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
#define YYFINAL  87
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   743

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  181
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  313

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
       0,   106,   106,   112,   119,   126,   130,   133,   136,   143,
     171,   194,   214,   236,   240,   296,   300,   306,   323,   337,
     350,   359,   382,   385,   417,   429,   468,   471,   476,   479,
     484,   487,   499,   502,   505,   510,   549,   610,   632,   635,
     690,   745,   786,   789,   817,   820,   823,   828,   840,   846,
     850,   863,   869,   876,   881,   887,   890,   894,   898,   901,
     906,   926,   943,   956,   966,   971,   983,   991,  1002,  1013,
    1028,  1041,  1059,  1076,  1098,  1106,  1114,  1147,  1178,  1203,
    1213,  1224,  1237,  1244,  1247,  1250,  1256,  1261,  1264,  1277,
    1289,  1294,  1297,  1310,  1322,  1327,  1338,  1351,  1356,  1363,
    1367,  1398,  1401,  1404,  1407,  1410,  1413,  1416,  1419,  1422,
    1426,  1429,  1435,  1438,  1475,  1478,  1515,  1519,  1556,  1559,
    1597,  1600,  1640,  1681,  1684,  1728,  1731,  1734,  1737,  1740,
    1745,  1764,  1768,  1771,  1774,  1778,  1781,  1802,  1805,  1987,
    2027,  2099,  2135,  2149,  2179,  2185,  2189,  2195,  2212,  2219,
    2225,  2254,  2260,  2263,  2270,  2281,  2287,  2297,  2305,  2311,
    2317,  2330,  2336,  2350,  2360,  2390,  2410,  2472,  2494,  2513,
    2532,  2595,  2599,  2605,  2608,  2636,  2643,  2654,  2675,  2680,
    2696,  2699
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
  "snippet", "funcdef", "T", "func_name", "func_ret_type", "parameters",
  "typedargslist", "typedarg", "tfpdef", "stmt", "simple_stmt",
  "small_stmt_list", "small_stmt", "expr_stmt",
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

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-263)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-95)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     112,   112,  -263,  -263,  -263,  -263,   635,  -263,  -263,   635,
      11,    33,    82,  -263,    73,   415,  -263,  -263,  -263,    66,
    -263,  -263,  -263,  -263,  -263,    78,    86,    71,   127,  -263,
    -263,   112,  -263,     9,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,   459,  -263,  -263,  -263,   675,    46,  -263,
     107,   110,   113,   124,  -263,     3,    87,    99,   102,    10,
      -1,  -263,   675,  -263,     4,  -263,  -263,  -263,   111,  -263,
    -263,  -263,  -263,   117,   116,  -263,   121,   118,  -263,  -263,
     122,   129,  -263,   503,   635,   635,   140,  -263,  -263,  -263,
     220,   105,   128,   130,  -263,   635,   131,   137,   635,   635,
     318,  -263,  -263,  -263,   145,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,   146,   675,   675,   675,   675,   675,   675,   675,
    -263,  -263,  -263,  -263,  -263,   675,  -263,   675,   547,   154,
     635,  -263,   635,   591,   165,    -5,    53,   157,  -263,   159,
    -263,  -263,   132,   147,   149,  -263,  -263,  -263,   148,  -263,
     274,   150,  -263,  -263,   179,  -263,  -263,   151,    35,    60,
     635,   635,  -263,  -263,  -263,  -263,  -263,  -263,  -263,    -1,
      -1,  -263,  -263,  -263,    51,   153,   155,  -263,   152,  -263,
     138,   156,  -263,   158,   187,  -263,   160,   182,    64,    65,
    -263,   161,     8,   274,   118,  -263,  -263,  -263,  -263,  -263,
     274,   191,  -263,  -263,  -263,   274,   166,  -263,   635,   635,
     635,   635,   635,   177,   184,  -263,   635,   635,  -263,   635,
    -263,   194,  -263,   185,   199,     8,   180,  -263,   203,  -263,
     203,   635,  -263,  -263,   183,  -263,  -263,    21,   371,   274,
     202,   635,  -263,  -263,  -263,  -263,  -263,   188,  -263,  -263,
    -263,  -263,    22,  -263,  -263,   274,    70,  -263,  -263,   274,
      69,   371,    88,   202,   204,    72,  -263,  -263,   215,  -263,
    -263,   190,  -263,  -263,  -263,  -263,  -263,   192,   635,  -263,
    -263,   217,  -263,   213,   195,  -263,   635,  -263,   274,  -263,
     196,  -263,   200,  -263,   197,  -263,   274,  -263,  -263,   274,
    -263,  -263,   274,   274,  -263,    21,  -263,    69,   201,  -263,
    -263,   274,  -263
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,   150,    66,    74,    79,     0,    47,    48,    49,
       0,     0,     0,   153,   155,     0,   132,   133,   134,     0,
     144,    97,    98,   151,   154,     0,     0,     0,     0,     4,
      58,     6,    26,     0,    30,    32,    33,    44,    45,    46,
      34,    27,    55,     0,    56,     2,    57,     0,   163,    86,
       0,    87,     0,    91,    96,    99,   112,   114,   116,   118,
     120,   123,     0,   131,   135,   137,   152,    38,   161,    59,
       7,    95,    50,   168,     0,    14,     0,    51,   156,   146,
     163,     0,   149,     0,     0,     0,     0,     1,     8,    29,
       0,     0,     0,     0,    64,     0,     0,     0,     0,     0,
       0,     2,     2,   108,     0,   101,   102,   103,   104,   105,
     106,   107,   110,     0,     0,     0,     0,     0,     0,     0,
     129,   125,   127,   128,   126,     0,   130,     0,     0,     0,
       0,   138,   162,     0,     0,     0,     0,     0,    52,     0,
     145,   148,     0,     0,     0,   143,    28,    31,     0,     2,
       0,     0,    75,     2,     0,    35,    39,    42,   164,     0,
       0,     0,   109,   111,   100,   113,   115,   117,   119,   121,
     122,   124,   136,   157,     0,   178,     0,   175,   176,   140,
       0,   165,   169,     0,     0,   167,    24,    13,     0,     0,
      20,    22,     0,     0,    53,   164,   147,   141,   142,    65,
       0,     0,    83,    63,     2,     0,     0,    78,     0,     0,
       0,     0,     0,    88,    92,   160,     0,     0,   158,     0,
     139,     0,   170,     0,     0,     0,     0,    19,     0,    17,
       0,     0,    15,    16,     0,     9,    54,    60,     0,     0,
      76,     0,    43,    36,    40,    37,    41,     0,   179,   177,
     166,   173,     0,    25,    13,     0,     0,    21,    23,     0,
       0,   180,     0,    72,     0,     0,    82,   159,     0,   171,
     174,     0,    11,    18,    10,    67,    68,     0,     0,    62,
     181,     0,    84,     0,     0,    80,     0,   172,     0,     2,
       0,    85,     0,     2,     0,    12,     0,     2,     2,     0,
      81,    61,     0,     0,    77,    69,    73,     0,     0,    70,
       2,     0,    71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -263,   -84,  -233,  -263,    13,  -200,   -20,  -263,    12,  -263,
      18,    17,  -263,  -156,     1,  -263,   162,  -263,  -179,  -263,
    -263,  -263,  -263,  -263,    44,  -263,  -263,   -38,  -263,  -263,
    -262,  -263,   -66,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
     -33,  -189,    -9,  -263,  -263,    94,  -263,    -3,   142,  -263,
     -37,   141,   143,   144,  -263,    -7,  -263,   -47,  -263,  -263,
    -263,  -263,  -263,   246,  -263,   -10,  -263,  -263,  -263,  -263,
    -263,    48,    47,   134,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    95,   260,    28,    29,    30,   226,    76,   234,   136,
     189,   190,   191,    31,   202,    33,    34,    35,   156,    36,
      37,    38,    39,    40,   138,    41,    42,    92,    93,    43,
     277,   278,   279,    44,    45,   151,    46,    96,    47,   207,
     265,   203,    48,    49,    50,    51,    52,    53,    54,   113,
      55,    56,    57,    58,    59,    60,   125,    61,    62,    63,
      64,    83,    65,    66,   131,    67,    68,    69,    74,   185,
     252,   176,   177,   178,   262
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,    32,    32,    71,   235,    81,    80,   264,   186,   120,
      97,   237,   127,    89,    70,   126,   240,   160,   161,   117,
     232,   292,   103,   251,    73,   104,   268,   187,   269,   242,
     283,   244,    32,   246,    94,   128,    -3,    -3,   121,   122,
     123,   124,   209,    90,    88,   308,    75,   118,   119,    11,
     263,   129,   270,    98,   130,   105,   106,   107,   108,   109,
     110,   111,   112,   188,   192,   200,   272,   211,   210,   205,
     274,   233,   307,   142,    80,   143,   144,   165,   171,    99,
     172,   100,   261,   215,   275,   276,   152,   216,   193,   155,
     157,   159,   281,   212,   282,    77,   227,   229,    86,   295,
     228,   230,   273,    14,   285,   261,   230,   301,   286,    84,
     304,   169,   170,   305,   306,    82,     1,    85,    86,   175,
     239,   180,   312,   181,   175,     2,     3,    87,   101,     4,
       5,   -90,   114,   102,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,   -94,   115,   116,   132,   133,    16,
      17,   134,   135,   145,   137,    18,   154,   139,   214,   148,
      19,   140,    20,   149,   162,   150,   153,   179,   163,   184,
     194,   195,    21,    22,    23,    24,    25,    26,   199,   197,
      27,   198,   206,   196,   208,   204,   217,   218,   219,   220,
     222,   221,   223,   225,   231,   224,   238,   241,   -89,   157,
     243,   157,   245,   157,   -93,   296,   250,   175,   248,   299,
     175,   253,    11,   302,   303,   255,   186,    -3,   259,   284,
     267,   287,   258,   291,   146,   288,   311,   289,   275,   300,
     293,   297,   266,     2,   271,   298,   310,   254,   236,    32,
     290,   309,     6,     7,     8,     9,   256,   257,    12,    13,
      14,    15,   147,   294,   213,   164,   166,    16,    17,   167,
      78,   168,    32,    18,   247,     0,   249,   183,    19,    94,
      20,     0,     0,     0,     0,   280,     0,   266,   201,     0,
      21,    22,    23,    24,    25,    26,     0,     2,    27,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     8,     9,
       0,     0,    12,    13,    14,    15,     0,     0,     0,     0,
       0,    16,    17,     0,     0,     0,     0,    18,     0,     0,
       0,     0,    19,     0,    20,     0,     0,     0,     0,     0,
     158,     2,     0,     0,    21,    22,    23,    24,    25,    26,
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
       0,     0,     0,     0,    13,    14,    15,    79,     0,     0,
       0,     0,    16,    17,     0,     0,     0,     0,    18,     0,
       0,     0,     0,    19,     0,    20,     0,     0,     0,     0,
       0,     0,     2,     0,     0,    21,    22,    23,    24,    25,
      26,     6,     0,    27,     0,     0,     0,     0,    13,    14,
      15,     0,     0,     0,     0,     0,    16,    17,     0,     0,
       0,     0,    18,     0,     0,     0,     0,    19,     0,    20,
       0,     0,     0,     0,     0,     0,     2,     0,     0,    21,
      22,    23,    24,    25,    26,     6,    91,    27,     0,     0,
       0,     0,    13,    14,    15,     0,     0,     0,     0,     0,
      16,    17,     0,     0,     0,     0,    18,     0,     0,     0,
       0,    19,     0,    20,   141,     0,     0,     0,     0,     0,
       2,     0,     0,    21,    22,    23,    24,    25,    26,     6,
       0,    27,     0,     0,     0,     0,    13,    14,    15,   173,
       0,     0,     0,     0,    16,    17,     0,     0,     0,     0,
      18,     0,     0,     0,     0,    19,     0,    20,     0,     0,
       0,     0,     0,     0,     2,     0,     0,    21,    22,    23,
      24,    25,    26,     6,     0,   174,     0,     0,     0,     0,
      13,    14,    15,   182,     0,     0,     0,     0,    16,    17,
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
       9,     0,     1,     6,   193,    15,    15,   240,    13,    10,
      47,   200,     8,     4,     1,    62,   205,   101,   102,     9,
      12,   283,    19,   223,    13,    22,     4,    32,     6,   208,
     263,   210,    31,   212,    43,    31,    15,    16,    39,    40,
      41,    42,     7,    34,    31,   307,    13,    37,    38,    27,
     239,    47,   252,     7,    50,    52,    53,    54,    55,    56,
      57,    58,    59,    68,    11,   149,   255,     7,    33,   153,
     259,    63,   305,    83,    83,    84,    85,   114,   125,    33,
     127,    35,   238,    32,    15,    16,    95,    36,    35,    98,
      99,   100,     4,    33,     6,    13,    32,    32,    47,   288,
      36,    36,    32,    30,    32,   261,    36,   296,    36,    31,
     299,   118,   119,   302,   303,    49,     4,    31,    47,   128,
     204,   130,   311,   132,   133,    13,    14,     0,    21,    17,
      18,    21,    45,    20,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    20,    46,    44,    36,    31,    37,
      38,    35,    31,    13,    36,    43,    19,    35,   161,    54,
      48,    32,    50,    35,    19,    35,    35,    13,    22,     4,
      13,    12,    60,    61,    62,    63,    64,    65,    30,    32,
      68,    32,     3,    51,    33,    35,    33,    32,    36,    51,
      32,    35,     5,    11,    33,    35,     5,    31,    21,   208,
     209,   210,   211,   212,    20,   289,    12,   216,   217,   293,
     219,    12,    27,   297,   298,    35,    13,    15,    35,    15,
      32,     6,   231,     6,     4,    35,   310,    35,    15,    32,
      35,    35,   241,    13,   254,    35,    35,   225,   194,   238,
     278,   307,    22,    23,    24,    25,   228,   230,    28,    29,
      30,    31,    90,   286,   160,   113,   115,    37,    38,   116,
      14,   117,   261,    43,   216,    -1,   219,   133,    48,   278,
      50,    -1,    -1,    -1,    -1,   261,    -1,   286,     4,    -1,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    13,    14,    17,    18,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    37,    38,    43,    48,
      50,    60,    61,    62,    63,    64,    65,    68,    72,    73,
      74,    82,    83,    84,    85,    86,    88,    89,    90,    91,
      92,    94,    95,    98,   102,   103,   105,   107,   111,   112,
     113,   114,   115,   116,   117,   119,   120,   121,   122,   123,
     124,   126,   127,   128,   129,   131,   132,   134,   135,   136,
      73,   116,   111,    13,   137,    13,    76,    13,   132,    32,
     111,   134,    49,   130,    31,    31,    47,     0,    73,     4,
      34,    67,    96,    97,   111,    70,   106,   119,     7,    33,
      35,    21,    20,    19,    22,    52,    53,    54,    55,    56,
      57,    58,    59,   118,    45,    46,    44,     9,    37,    38,
      10,    39,    40,    41,    42,   125,   126,     8,    31,    47,
      50,   133,    36,    31,    35,    31,    78,    36,    93,    35,
      32,    51,   134,   111,   111,    13,     4,    85,    54,    35,
      35,   104,   111,    35,    19,   111,    87,   111,    12,   111,
      70,    70,    19,    22,   117,   119,   120,   121,   122,   124,
     124,   126,   126,    32,    68,   111,   140,   141,   142,    13,
     111,   111,    32,   142,     4,   138,    13,    32,    68,    79,
      80,    81,    11,    35,    13,    12,    51,    32,    32,    30,
      70,     4,    83,   110,    35,    70,     3,   108,    33,     7,
      33,     7,    33,   114,   116,    32,    36,    33,    32,    36,
      51,    35,    32,     5,    35,    11,    75,    32,    36,    32,
      36,    33,    12,    63,    77,   110,    93,   110,     5,    70,
     110,    31,    87,   111,    87,   111,    87,   140,   111,   141,
      12,    74,   139,    12,    77,    35,    79,    80,   111,    35,
      71,    82,   143,   110,    71,   109,   111,    32,     4,     6,
      74,    75,   110,    32,   110,    15,    16,    99,   100,   101,
     143,     4,     6,    71,    15,    32,    36,     6,    35,    35,
      96,     6,    99,    35,   109,   110,    70,    35,    35,    70,
      32,   110,    70,    70,   110,   110,   110,    71,    99,   101,
      35,    70,   110
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    72,    73,    73,    73,    73,    74,
      74,    74,    74,    75,    76,    77,    77,    78,    78,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    88,    88,    88,    89,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    94,
      95,    95,    95,    95,    96,    97,    98,    99,   100,   101,
     101,   101,   102,   102,   103,   104,   105,   105,   106,   107,
     108,   108,   109,   110,   110,   110,   111,   112,   112,   113,
     113,   114,   114,   115,   115,   116,   116,   116,   116,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   124,   124,   125,   125,   125,   125,   125,
     126,   126,   127,   127,   127,   128,   128,   129,   129,   129,
     129,   129,   129,   129,   130,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   132,   132,   133,   133,   133,
     133,   134,   134,   135,   135,   135,   135,   136,   137,   137,
     137,   138,   138,   139,   139,   140,   141,   141,   142,   142,
     143,   143
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     2,     2,     5,
       7,     7,     9,     0,     1,     1,     1,     3,     5,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     3,     2,
       1,     3,     1,     1,     1,     3,     5,     5,     1,     3,
       5,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     2,     3,     1,     1,     1,     1,     1,
       5,    10,     7,     4,     1,     3,     1,     1,     1,     5,
       7,    10,     6,    11,     1,     1,     5,    10,     3,     1,
       4,     6,     1,     1,     4,     5,     1,     1,     4,     4,
       1,     1,     4,     4,     1,     2,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     3,     1,     2,     4,
       3,     4,     4,     3,     0,     3,     2,     4,     3,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     5,
       3,     1,     2,     1,     3,     3,     5,     4,     1,     3,
       4,     4,     5,     1,     2,     1,     1,     3,     1,     3,
       1,     2
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
#line 106 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal M");
        (yyval.elem)->ins = instCount+1;
}
#line 1621 "parser.tab.c"
    break;

  case 3: /* N: %empty  */
#line 112 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal N");
        (yyval.elem)->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
#line 1631 "parser.tab.c"
    break;

  case 4: /* file: snippet  */
#line 119 "parser.y"
              {
                (yyval.elem) = (yyvsp[0].elem);
                endline = instCount+1;
                create_ins(0, "EOF", "", "", "");
            }
#line 1641 "parser.tab.c"
    break;

  case 5: /* snippet: NEWLINE  */
#line 126 "parser.y"
                 {
       (yyval.elem)=(yyvsp[0].elem);
	   (yyval.elem)->ins = instCount+1;
    }
#line 1650 "parser.tab.c"
    break;

  case 6: /* snippet: stmt  */
#line 130 "parser.y"
            { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1658 "parser.tab.c"
    break;

  case 7: /* snippet: NEWLINE snippet  */
#line 133 "parser.y"
                       { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1666 "parser.tab.c"
    break;

  case 8: /* snippet: stmt snippet  */
#line 136 "parser.y"
                   {  
        (yyval.elem) = create_node(3, "snippet", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
    }
#line 1676 "parser.tab.c"
    break;

  case 9: /* funcdef: DEF func_name parameters COLON suite  */
#line 143 "parser.y"
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
#line 1709 "parser.tab.c"
    break;

  case 10: /* funcdef: DEF func_name parameters ARROW_OPER func_ret_type COLON suite  */
#line 171 "parser.y"
                                                                        {
            (yyval.elem) = create_node(8, "funcdef", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));

            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-5].elem)->addr, (yyvsp[-4].elem)->num_params, (yyvsp[-6].elem)->lineno, 1,(yyvsp[-2].elem)->addr);
            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Stackpointer -"+to_string(funcOffset),"","","");
            funcOffset=0;
            create_ins(0,"goto","ra","","");
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
#line 1737 "parser.tab.c"
    break;

  case 11: /* funcdef: DEF func_name OPEN_BRACKET CLOSE_BRACKET T COLON suite  */
#line 194 "parser.y"
                                                                 {
            (yyval.elem) = create_node(8, "funcdef", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-5].elem)->addr, 0, (yyvsp[-6].elem)->lineno, 1);

            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Stackpointer -"+to_string(funcOffset),"","","");
            funcOffset=0;
            create_ins(0,"goto","ra","","");
            create_ins(0,"EndFunc","","","");

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[0].elem)->stack_width;
            current_ste->stack_width = (yyval.elem)->stack_width;
            current_ste->offset_map = offset_map;
            stack_offset = 16;
            offset_map.clear();
            //m3 end
        }
#line 1762 "parser.tab.c"
    break;

  case 12: /* funcdef: DEF func_name OPEN_BRACKET CLOSE_BRACKET ARROW_OPER func_ret_type T COLON suite  */
#line 214 "parser.y"
                                                                                         {
            (yyval.elem) = create_node(10, "funcdef", (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem),(yyvsp[-3].elem),(yyvsp[-2].elem),(yyvsp[-1].elem),(yyvsp[0].elem));
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-7].elem)->addr, 0, (yyvsp[-8].elem)->lineno, 1,(yyvsp[-3].elem)->addr);

            // thisTemps.pop();
			// create_ins(0,$2->return_func,"=","PopParam","");
            create_ins(0,"Stackpointer -"+to_string(funcOffset),"","","");
            funcOffset=0;
            create_ins(0,"goto","ra","","");
            create_ins(0,"EndFunc","","","");

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[0].elem)->stack_width;
            current_ste->stack_width = (yyval.elem)->stack_width;
            current_ste->offset_map = offset_map;
            stack_offset = 16;
            offset_map.clear();
            //m3 end
        }
#line 1787 "parser.tab.c"
    break;

  case 13: /* T: %empty  */
#line 236 "parser.y"
         {
        stack_offset = 8;
}
#line 1795 "parser.tab.c"
    break;

  case 14: /* func_name: NAME  */
#line 241 "parser.y"
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
#line 1831 "parser.tab.c"
    break;

  case 15: /* func_ret_type: TYPE_HINT  */
#line 296 "parser.y"
                        {
        (yyval.elem)=(yyvsp[0].elem);
        get_prev_scope(current_ste)->return_type = (yyvsp[0].elem)->addr;
    }
#line 1840 "parser.tab.c"
    break;

  case 16: /* func_ret_type: NONE  */
#line 300 "parser.y"
          {
        (yyval.elem)=(yyvsp[0].elem);
        get_prev_scope(current_ste)->return_type = "None";
    }
#line 1849 "parser.tab.c"
    break;

  case 17: /* parameters: OPEN_BRACKET typedargslist CLOSE_BRACKET  */
#line 306 "parser.y"
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
#line 1871 "parser.tab.c"
    break;

  case 18: /* parameters: OPEN_BRACKET SELF COMMA typedargslist CLOSE_BRACKET  */
#line 323 "parser.y"
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
#line 1890 "parser.tab.c"
    break;

  case 19: /* parameters: OPEN_BRACKET SELF CLOSE_BRACKET  */
#line 337 "parser.y"
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
#line 1906 "parser.tab.c"
    break;

  case 20: /* typedargslist: typedarg  */
#line 350 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;
            (yyval.elem)->ins = instCount+1;
            
            // paramStack.pop();
			create_ins(0,(yyvsp[0].elem)->addr,"=","PopParam","");

        }
#line 1920 "parser.tab.c"
    break;

  case 21: /* typedargslist: typedargslist COMMA typedarg  */
#line 359 "parser.y"
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
#line 1941 "parser.tab.c"
    break;

  case 22: /* typedarg: tfpdef  */
#line 382 "parser.y"
                   {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1949 "parser.tab.c"
    break;

  case 23: /* typedarg: tfpdef EQUAL test  */
#line 385 "parser.y"
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
#line 1984 "parser.tab.c"
    break;

  case 24: /* tfpdef: NAME  */
#line 417 "parser.y"
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
#line 2001 "parser.tab.c"
    break;

  case 25: /* tfpdef: NAME COLON TYPE_HINT  */
#line 429 "parser.y"
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
#line 2043 "parser.tab.c"
    break;

  case 26: /* stmt: simple_stmt  */
#line 468 "parser.y"
                        { 
        	(yyval.elem)=(yyvsp[0].elem);
        }
#line 2051 "parser.tab.c"
    break;

  case 27: /* stmt: compound_stmt  */
#line 471 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem); 
        }
#line 2059 "parser.tab.c"
    break;

  case 28: /* simple_stmt: small_stmt_list SEMI_COLON NEWLINE  */
#line 476 "parser.y"
                                                {  
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 2067 "parser.tab.c"
    break;

  case 29: /* simple_stmt: small_stmt_list NEWLINE  */
#line 479 "parser.y"
                                   {  
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 2075 "parser.tab.c"
    break;

  case 30: /* small_stmt_list: small_stmt  */
#line 484 "parser.y"
                                {   
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2083 "parser.tab.c"
    break;

  case 31: /* small_stmt_list: small_stmt_list SEMI_COLON small_stmt  */
#line 487 "parser.y"
                                                     {  
            (yyval.elem) = create_node(3, "small_stmt_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, (yyvsp[0].elem)->nextlist);
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;

            //M3 start
            (yyval.elem)->stack_width = (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //M3 end
        }
#line 2098 "parser.tab.c"
    break;

  case 32: /* small_stmt: expr_stmt  */
#line 499 "parser.y"
                            {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 2106 "parser.tab.c"
    break;

  case 33: /* small_stmt: flow_stmt  */
#line 502 "parser.y"
                        {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 2114 "parser.tab.c"
    break;

  case 34: /* small_stmt: global_stmt  */
#line 505 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2122 "parser.tab.c"
    break;

  case 35: /* expr_stmt: test ASSIGN_OPERATOR test  */
#line 510 "parser.y"
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
#line 2166 "parser.tab.c"
    break;

  case 36: /* expr_stmt: test COLON TYPE_HINT ASSIGN_OPERATOR test  */
#line 549 "parser.y"
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
#line 2232 "parser.tab.c"
    break;

  case 37: /* expr_stmt: test COLON test ASSIGN_OPERATOR test  */
#line 610 "parser.y"
                                               {  
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;
            // Here add instruction 

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

            //m3 start pending

            //m3 end

        }
#line 2259 "parser.tab.c"
    break;

  case 38: /* expr_stmt: testlist  */
#line 632 "parser.y"
                   {
			(yyval.elem)=(yyvsp[0].elem);
        }
#line 2267 "parser.tab.c"
    break;

  case 39: /* expr_stmt: test EQUAL eq_testlist_star_expr_plus  */
#line 635 "parser.y"
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
#line 2326 "parser.tab.c"
    break;

  case 40: /* expr_stmt: test COLON TYPE_HINT EQUAL eq_testlist_star_expr_plus  */
#line 690 "parser.y"
                                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem));
			(yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;
            //runtime support
            funcOffset += get_width((yyvsp[-2].elem)->addr);
            string st=str_to_ch((yyvsp[-2].elem)-> addr);
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
                }
                else{
                    create_ins(0, (yyvsp[-4].elem)->addr, "=", (yyvsp[0].elem)->addr, "");
                }
            //typecheck done

            //M3 START
            (yyval.elem)->stack_width = 8 + (yyvsp[-4].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[chartostring((yyvsp[-4].elem)->addr)] = -stack_offset;
            stack_offset+=8;
            //M3 END
        }
#line 2386 "parser.tab.c"
    break;

  case 41: /* expr_stmt: test COLON test EQUAL eq_testlist_star_expr_plus  */
#line 745 "parser.y"
                                                          {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem));
			(yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;
			create_ins(0, (yyvsp[-4].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, ""); 

            //runtime support
            // create_ins(0, "Stackpointer +xxx", "", "", "");
            // create_ins(0,"call memalloc 1","","","");
            // create_ins(0,"Stackpointer -yyy","","","");



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
                    current_ste = insert_entry_same_scope(current_ste, "OBJECT", (yyvsp[-4].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[-4].elem)->lineno, 1, (yyvsp[0].elem)->list_size);
                }
                else{
                    cerr<<"Error: Variable "<<(yyvsp[-4].elem)->addr<<" already declared on line "<<lookup(lookup_ste, (yyvsp[-4].elem)->addr)->lineno<<"\n";
                    exit(1);
                }
            }
            //m3 start pending

            //m3 end

        }
#line 2429 "parser.tab.c"
    break;

  case 42: /* eq_testlist_star_expr_plus: test  */
#line 786 "parser.y"
                                 {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2437 "parser.tab.c"
    break;

  case 43: /* eq_testlist_star_expr_plus: test EQUAL eq_testlist_star_expr_plus  */
#line 789 "parser.y"
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
#line 2468 "parser.tab.c"
    break;

  case 44: /* flow_stmt: break_stmt  */
#line 817 "parser.y"
                        {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2476 "parser.tab.c"
    break;

  case 45: /* flow_stmt: continue_stmt  */
#line 820 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2484 "parser.tab.c"
    break;

  case 46: /* flow_stmt: return_stmt  */
#line 823 "parser.y"
                         {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2492 "parser.tab.c"
    break;

  case 47: /* break_stmt: BREAK  */
#line 828 "parser.y"
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
#line 2508 "parser.tab.c"
    break;

  case 48: /* continue_stmt: CONTINUE  */
#line 840 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = instCount+1;
            create_ins(0, "goto", to_string(loopStack.top()), "", "");
        }
#line 2518 "parser.tab.c"
    break;

  case 49: /* return_stmt: RETURN  */
#line 846 "parser.y"
                        {  
            (yyval.elem)=(yyvsp[0].elem);
            create_ins(0,"return","","","");
        }
#line 2527 "parser.tab.c"
    break;

  case 50: /* return_stmt: RETURN test  */
#line 850 "parser.y"
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
#line 2543 "parser.tab.c"
    break;

  case 51: /* global_stmt: GLOBAL NAME  */
#line 863 "parser.y"
                           {  
            (yyval.elem) = create_node(3, "global_stmt", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
                       
        }
#line 2554 "parser.tab.c"
    break;

  case 52: /* global_stmt: GLOBAL NAME comma_name_star  */
#line 869 "parser.y"
                                      {   
            (yyval.elem) = create_node(4, "global_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
        }
#line 2564 "parser.tab.c"
    break;

  case 53: /* comma_name_star: COMMA NAME  */
#line 876 "parser.y"
                               {  
            (yyval.elem) = create_node(3, "comma_name_star", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
        }
#line 2574 "parser.tab.c"
    break;

  case 54: /* comma_name_star: COMMA NAME comma_name_star  */
#line 881 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "comma_name_star", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
        }
#line 2584 "parser.tab.c"
    break;

  case 55: /* compound_stmt: if_stmt  */
#line 887 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);  
        }
#line 2592 "parser.tab.c"
    break;

  case 56: /* compound_stmt: while_stmt  */
#line 890 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
            loopStack.pop();
        }
#line 2601 "parser.tab.c"
    break;

  case 57: /* compound_stmt: for_stmt  */
#line 894 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
            loopStack.pop();
        }
#line 2610 "parser.tab.c"
    break;

  case 58: /* compound_stmt: funcdef  */
#line 898 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2618 "parser.tab.c"
    break;

  case 59: /* compound_stmt: classdef  */
#line 901 "parser.y"
                       {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 2626 "parser.tab.c"
    break;

  case 60: /* if_stmt: if_scope if_expr COLON M suite  */
#line 906 "parser.y"
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
#line 2651 "parser.tab.c"
    break;

  case 61: /* if_stmt: if_scope if_expr COLON M suite N else_scope COLON M suite  */
#line 926 "parser.y"
                                                                      {  
            (yyval.elem) = create_node(11, "if_else_stmt", (yyvsp[-9].elem),(yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-9].elem)->lineno;
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            vector<int> temp = merge((yyvsp[-5].elem)->nextlist, (yyvsp[-4].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end

            //M3 start
            (yyval.elem)->stack_width = (yyvsp[-8].elem)->stack_width + (yyvsp[-5].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //M3 end

        }
#line 2673 "parser.tab.c"
    break;

  case 62: /* if_stmt: if_scope if_expr COLON M suite N nts_star  */
#line 943 "parser.y"
                                                       {  
            (yyval.elem) = create_node(8, "if_elif_stmt", (yyvsp[-6].elem),(yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            (yyval.elem)->lineno = (yyvsp[-6].elem)->lineno;
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);     
            vector<int> temp = merge((yyvsp[-2].elem)->nextlist, (yyvsp[-1].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist); 

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-5].elem)->stack_width + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width; 
              
            //m3 end
        }
#line 2691 "parser.tab.c"
    break;

  case 63: /* if_stmt: if_scope d_expr COLON suite  */
#line 956 "parser.y"
                                      {
            (yyval.elem) = create_node(5, "if_stmt", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 2704 "parser.tab.c"
    break;

  case 64: /* if_expr: test  */
#line 966 "parser.y"
             {
        (yyval.elem) = (yyvsp[0].elem);
        incheck=0;
}
#line 2713 "parser.tab.c"
    break;

  case 65: /* d_expr: D_NAME EQUAL_EQUAL STRING  */
#line 971 "parser.y"
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
#line 2729 "parser.tab.c"
    break;

  case 66: /* if_scope: IF  */
#line 983 "parser.y"
            {
        (yyval.elem)=(yyvsp[0].elem);
        incheck=1;
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "IF", "IF", 0, $1->lineno, 0);
    }
#line 2740 "parser.tab.c"
    break;

  case 67: /* else_scope: ELSE  */
#line 991 "parser.y"
                {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        // current_ste = get_prev_scope(current_ste);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "ELSE", "ELSE", 0, $1->lineno, 1);

        //STE code end
    }
#line 2754 "parser.tab.c"
    break;

  case 68: /* else_if_scope: ELIF  */
#line 1002 "parser.y"
                   {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        // current_ste = get_prev_scope(current_ste);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "ELSE_IF", "ELSE_IF", 0, $1->lineno, 1);
        //STE code end
    }
#line 2767 "parser.tab.c"
    break;

  case 69: /* nts_star: else_if_scope if_expr COLON M suite  */
#line 1013 "parser.y"
                                                {  
            (yyval.elem)=create_node(6, "elif_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-4].elem)->lineno;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end

            //M3 start
            (yyval.elem)->stack_width = (yyvsp[-3].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //M3 end
        }
#line 2787 "parser.tab.c"
    break;

  case 70: /* nts_star: else_if_scope if_expr COLON M suite N nts_star  */
#line 1028 "parser.y"
                                                          {  
            (yyval.elem) = create_node(8, "elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-5].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-6].elem)->lineno;
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist));

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-5].elem)->stack_width + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;

            //m3 end
        }
#line 2805 "parser.tab.c"
    break;

  case 71: /* nts_star: else_if_scope if_expr COLON M suite N else_scope COLON M suite  */
#line 1041 "parser.y"
                                                                          {  
            (yyval.elem) = create_node(11, "elif_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-8].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-9].elem)->lineno;
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-5].elem)->nextlist, merge((yyvsp[-4].elem)->nextlist,(yyvsp[0].elem)->nextlist));

            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-8].elem)->stack_width + (yyvsp[-5].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //m3 end
        }
#line 2826 "parser.tab.c"
    break;

  case 72: /* while_stmt: while_scope M while_expr COLON M suite  */
#line 1059 "parser.y"
                                                     {  
            (yyval.elem) = create_node(7, "while_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-5].elem)->lineno;
            backpatch((yyvsp[0].elem)->nextlist, (yyvsp[-4].elem)->ins);
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            //$$->nextlist = $3->falselist;
            create_ins(0, "goto", to_string((yyvsp[-4].elem)->ins), "", "");
            backpatch((yyvsp[-3].elem)->falselist, instCount+1);
            //STE code start
            // current_ste = get_prev_scope(current_ste);
            //STE code end

            //M3 start
            (yyval.elem)->stack_width =(yyvsp[-3].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            //M3 end
        }
#line 2848 "parser.tab.c"
    break;

  case 73: /* while_stmt: while_scope M while_expr COLON M suite N else_scope COLON M suite  */
#line 1076 "parser.y"
                                                                                     {   
			(yyval.elem) = create_node(12, "while_else_stmt", (yyvsp[-10].elem), (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-9].elem)->ins;
            // create_ins(0,$$->return_param,"=",$2->addr,"");
            // create_ins(0,"return",$$->return_param,"","");
            (yyval.elem)->lineno = (yyvsp[-10].elem)->lineno;
			backpatch((yyvsp[-4].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-5].elem)->nextlist, (yyvsp[-9].elem)->ins);
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
#line 2873 "parser.tab.c"
    break;

  case 74: /* while_scope: WHILE  */
#line 1098 "parser.y"
                   {
        (yyval.elem)=(yyvsp[0].elem);
        incheck=1;
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "WHILE", "WHILE", 0, $1->lineno, 0);
    }
#line 2884 "parser.tab.c"
    break;

  case 75: /* while_expr: test  */
#line 1106 "parser.y"
                   { 
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            loopStack.push((yyval.elem)->ins);
            incheck=0;
            // cout<<"out of while_test"<<endl;
        }
#line 2896 "parser.tab.c"
    break;

  case 76: /* for_stmt: for_scope for_core COLON M suite  */
#line 1114 "parser.y"
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
#line 2934 "parser.tab.c"
    break;

  case 77: /* for_stmt: for_scope for_core COLON M suite N ELSE COLON M suite  */
#line 1147 "parser.y"
                                                                  { 
            (yyval.elem) = create_node(11, "for_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-9].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-9].elem)->lineno;

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

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-8].elem)->stack_width + (yyvsp[-5].elem)->stack_width + (yyvsp[0].elem)->stack_width;

            //m3 end
        }
#line 2968 "parser.tab.c"
    break;

  case 78: /* for_core: expr IN range_stmt  */
#line 1178 "parser.y"
                               { 
            
            (yyval.elem) = create_node(3, "for_core", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));

            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
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

            //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-2].elem)->stack_width + (yyvsp[0].elem)->stack_width;
            offset_map[temp]=-stack_offset;
            stack_offset += 8;
            //m3 end
        }
#line 2996 "parser.tab.c"
    break;

  case 79: /* for_scope: FOR  */
#line 1203 "parser.y"
               {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        //loopStack.push($$->ins);
        // current_ste = insert_entry_new_scope(current_ste);
        // populate_new_scope(current_ste->prev_scope, "FOR", "FOR", 0, $1->lineno, 0);
        //STE code end
    }
#line 3009 "parser.tab.c"
    break;

  case 80: /* range_stmt: RANGE OPEN_BRACKET for_test CLOSE_BRACKET  */
#line 1213 "parser.y"
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
#line 3025 "parser.tab.c"
    break;

  case 81: /* range_stmt: RANGE OPEN_BRACKET for_test COMMA for_test CLOSE_BRACKET  */
#line 1224 "parser.y"
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
#line 3041 "parser.tab.c"
    break;

  case 82: /* for_test: test  */
#line 1237 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            //loopStack.push($$->ins);
        }
#line 3051 "parser.tab.c"
    break;

  case 83: /* suite: simple_stmt  */
#line 1244 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3059 "parser.tab.c"
    break;

  case 84: /* suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 1247 "parser.y"
                                            {
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 3067 "parser.tab.c"
    break;

  case 85: /* suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 1250 "parser.y"
                                                    { 
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 3075 "parser.tab.c"
    break;

  case 86: /* test: or_test  */
#line 1256 "parser.y"
                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3083 "parser.tab.c"
    break;

  case 87: /* or_test: and_test  */
#line 1261 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3091 "parser.tab.c"
    break;

  case 88: /* or_test: and_test_star OR M and_test  */
#line 1264 "parser.y"
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
#line 3108 "parser.tab.c"
    break;

  case 89: /* and_test_star: and_test_star OR M and_test  */
#line 1277 "parser.y"
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
#line 3125 "parser.tab.c"
    break;

  case 90: /* and_test_star: and_test  */
#line 1289 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3133 "parser.tab.c"
    break;

  case 91: /* and_test: not_test  */
#line 1294 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3141 "parser.tab.c"
    break;

  case 92: /* and_test: not_test_star AND M not_test  */
#line 1297 "parser.y"
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
#line 3158 "parser.tab.c"
    break;

  case 93: /* not_test_star: not_test_star AND M not_test  */
#line 1310 "parser.y"
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
#line 3175 "parser.tab.c"
    break;

  case 94: /* not_test_star: not_test  */
#line 1322 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3183 "parser.tab.c"
    break;

  case 95: /* not_test: NOT not_test  */
#line 1327 "parser.y"
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
#line 3199 "parser.tab.c"
    break;

  case 96: /* not_test: comparison  */
#line 1338 "parser.y"
                        { 
            (yyval.elem)=(yyvsp[0].elem);

            // cout<< "in comp "<<$$->addr<<endl;
            // cout<<"isatom = "<<isatom<<" "<<incheck<<" "<<yytext<<endl;
            if(isatom && incheck){
                (yyval.elem)->truelist = makelist(instCount+1);
                (yyval.elem)->falselist = makelist(instCount+2);
                create_ins(0, "if", (yyval.elem)->addr, "goto", "");
                // cout<<"checking "<<$$->addr<<endl;
                create_ins(0, "goto", "", "", "");
            }
        }
#line 3217 "parser.tab.c"
    break;

  case 97: /* not_test: TRUE  */
#line 1351 "parser.y"
              {
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->truelist = makelist(instCount+1);
            create_ins(0, "goto", "", "", "");
        }
#line 3227 "parser.tab.c"
    break;

  case 98: /* not_test: FALSE  */
#line 1356 "parser.y"
               {
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->falselist = makelist(instCount+2);
            create_ins(0, "goto", "", "", "");
        }
#line 3237 "parser.tab.c"
    break;

  case 99: /* comparison: expr  */
#line 1363 "parser.y"
                  {
            (yyval.elem)=(yyvsp[0].elem);
            
        }
#line 3246 "parser.tab.c"
    break;

  case 100: /* comparison: expr comp_op comparison  */
#line 1367 "parser.y"
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
#line 3279 "parser.tab.c"
    break;

  case 101: /* comp_op: LESS_THAN  */
#line 1398 "parser.y"
                    {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3287 "parser.tab.c"
    break;

  case 102: /* comp_op: GREATER_THAN  */
#line 1401 "parser.y"
                    { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 3295 "parser.tab.c"
    break;

  case 103: /* comp_op: EQUAL_EQUAL  */
#line 1404 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3303 "parser.tab.c"
    break;

  case 104: /* comp_op: GREATER_THAN_EQUAL  */
#line 1407 "parser.y"
                            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3311 "parser.tab.c"
    break;

  case 105: /* comp_op: LESS_THAN_EQUAL  */
#line 1410 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3319 "parser.tab.c"
    break;

  case 106: /* comp_op: NOT_EQUAL_ARROW  */
#line 1413 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3327 "parser.tab.c"
    break;

  case 107: /* comp_op: NOT_EQUAL  */
#line 1416 "parser.y"
                   {
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 3335 "parser.tab.c"
    break;

  case 108: /* comp_op: IN  */
#line 1419 "parser.y"
            {  
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3343 "parser.tab.c"
    break;

  case 109: /* comp_op: NOT IN  */
#line 1422 "parser.y"
                { 
        (yyval.elem) = create_node(3, "NOT IN", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
    }
#line 3352 "parser.tab.c"
    break;

  case 110: /* comp_op: IS  */
#line 1426 "parser.y"
            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 3360 "parser.tab.c"
    break;

  case 111: /* comp_op: IS NOT  */
#line 1429 "parser.y"
                { 
        (yyval.elem) = create_node(3, "IS NOT", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
    }
#line 3369 "parser.tab.c"
    break;

  case 112: /* expr: xor_expr  */
#line 1435 "parser.y"
                  { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3377 "parser.tab.c"
    break;

  case 113: /* expr: xor_expr BIT_OR expr  */
#line 1438 "parser.y"
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
#line 3417 "parser.tab.c"
    break;

  case 114: /* xor_expr: and_expr  */
#line 1475 "parser.y"
                   { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3425 "parser.tab.c"
    break;

  case 115: /* xor_expr: and_expr BIT_XOR xor_expr  */
#line 1478 "parser.y"
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
#line 3465 "parser.tab.c"
    break;

  case 116: /* and_expr: shift_expr  */
#line 1515 "parser.y"
                       { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 3474 "parser.tab.c"
    break;

  case 117: /* and_expr: shift_expr BIT_AND and_expr  */
#line 1519 "parser.y"
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
#line 3514 "parser.tab.c"
    break;

  case 118: /* shift_expr: arith_expr  */
#line 1556 "parser.y"
                         { 
                (yyval.elem) = (yyvsp[0].elem); 
            }
#line 3522 "parser.tab.c"
    break;

  case 119: /* shift_expr: arith_expr SHIFT_OPER shift_expr  */
#line 1559 "parser.y"
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
#line 3563 "parser.tab.c"
    break;

  case 120: /* arith_expr: term  */
#line 1597 "parser.y"
                 { 
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 3571 "parser.tab.c"
    break;

  case 121: /* arith_expr: arith_expr PLUS term  */
#line 1600 "parser.y"
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
#line 3616 "parser.tab.c"
    break;

  case 122: /* arith_expr: arith_expr MINUS term  */
#line 1640 "parser.y"
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
#line 3661 "parser.tab.c"
    break;

  case 123: /* term: factor  */
#line 1681 "parser.y"
             {
            (yyval.elem) = (yyvsp[0].elem); 
        }
#line 3669 "parser.tab.c"
    break;

  case 124: /* term: term term_choice factor  */
#line 1684 "parser.y"
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
#line 3716 "parser.tab.c"
    break;

  case 125: /* term_choice: MULTIPLY  */
#line 1728 "parser.y"
                            { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3724 "parser.tab.c"
    break;

  case 126: /* term_choice: ATTHERATE  */
#line 1731 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3732 "parser.tab.c"
    break;

  case 127: /* term_choice: DIVIDE  */
#line 1734 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3740 "parser.tab.c"
    break;

  case 128: /* term_choice: REMAINDER  */
#line 1737 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3748 "parser.tab.c"
    break;

  case 129: /* term_choice: FLOOR_DIV_OPER  */
#line 1740 "parser.y"
                           { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3756 "parser.tab.c"
    break;

  case 130: /* factor: factor_choice factor  */
#line 1745 "parser.y"
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
#line 3780 "parser.tab.c"
    break;

  case 131: /* factor: power  */
#line 1764 "parser.y"
                    { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3788 "parser.tab.c"
    break;

  case 132: /* factor_choice: PLUS  */
#line 1768 "parser.y"
                            {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3796 "parser.tab.c"
    break;

  case 133: /* factor_choice: MINUS  */
#line 1771 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3804 "parser.tab.c"
    break;

  case 134: /* factor_choice: NEGATION  */
#line 1774 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3812 "parser.tab.c"
    break;

  case 135: /* power: atom_expr  */
#line 1778 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3820 "parser.tab.c"
    break;

  case 136: /* power: atom_expr POWER_OPERATOR factor  */
#line 1781 "parser.y"
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
#line 3844 "parser.tab.c"
    break;

  case 137: /* atom_expr: atom  */
#line 1802 "parser.y"
                {  
            (yyval.elem) = (yyvsp[0].elem);  
        }
#line 3852 "parser.tab.c"
    break;

  case 138: /* atom_expr: atom_expr trailer  */
#line 1805 "parser.y"
                            {   //this is function call
            (yyval.elem) = create_node(3, "atom_expr", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
            string temp = newTemp();
            (yyval.elem)->addr = str_to_ch(temp);
            //create_ins(0, temp, "=" ,"call "+chartostring($1->addr), "");
            create_ins(0,"call",chartostring((yyvsp[-1].elem)->addr),"","");
            create_ins(0,"PopParamAll",to_string((yyvsp[0].elem)->num_params),"","");
            create_ins(0, "PopParamra", temp, "", "");
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
#line 4039 "parser.tab.c"
    break;

  case 139: /* atom_expr: atom_expr SQUARE_OPEN test SQUARE_CLOSE  */
#line 1987 "parser.y"
                                                 {   //array access
            (yyval.elem) = create_node(5, "atom_expr", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-3].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            //$$->atom_type= $1->atom_type; //check this
            string temp = str_to_ch(newTemp());
            (yyval.elem)->addr = str_to_ch(temp);
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
            if((yyvsp[-1].elem)->atom_type != "int"){
                cerr<<"Error: Array index is not an integer at line "<<(yyvsp[-3].elem)->lineno<<"\n";
                exit(1);
            }
            (yyval.elem)->atom_type = array_type;
            //cout<<$$->atom_type<<endl;
             //check this suppose a[2] hai to hum a ka type dekhenge

             //m3 start
            (yyval.elem)->stack_width = 8 + (yyvsp[-3].elem)->stack_width + (yyvsp[-1].elem)->stack_width;
            offset_map[temp]=-stack_offset;
            stack_offset += 8;
             //m3 end

        }
#line 4084 "parser.tab.c"
    break;

  case 140: /* atom_expr: atom_expr DOT NAME  */
#line 2027 "parser.y"
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
#line 4161 "parser.tab.c"
    break;

  case 141: /* atom_expr: LEN OPEN_BRACKET test CLOSE_BRACKET  */
#line 2099 "parser.y"
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

            create_ins(0, "PushParam", (yyvsp[-1].elem)->addr, "", "");
            create_ins(0, "call", "len", "", "");
            string temp = newTemp();
            create_ins(0, temp, "=", "PopParam", "");
            (yyval.elem)->addr = str_to_ch(temp);
        }
#line 4202 "parser.tab.c"
    break;

  case 142: /* atom_expr: PRINT OPEN_BRACKET test CLOSE_BRACKET  */
#line 2135 "parser.y"
                                                { 
            (yyval.elem) = create_node(5, "atom_expr", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-3].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            //$$->addr = str_to_ch("print("+chartostring($3->addr)+")");
            (yyval.elem)->atom_type = "None";
            create_ins(0, "PushParam", (yyvsp[-1].elem)->addr, "", "");
            create_ins(0, "call", "print", "", "");
            create_ins(0, "PopParamAll", "1", "", "");

            //m3 start
            (yyval.elem)->stack_width = (yyvsp[-1].elem)->stack_width;
            //m3 end
        }
#line 4221 "parser.tab.c"
    break;

  case 143: /* atom_expr: SELF DOT NAME  */
#line 2149 "parser.y"
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
#line 4254 "parser.tab.c"
    break;

  case 144: /* S: %empty  */
#line 2179 "parser.y"
            {
    isinsquare=1;
}
#line 4262 "parser.tab.c"
    break;

  case 145: /* atom: OPEN_BRACKET testlist CLOSE_BRACKET  */
#line 2185 "parser.y"
                                         { 
        (yyval.elem)=(yyvsp[-1].elem);      
        incheck=0;
    }
#line 4271 "parser.tab.c"
    break;

  case 146: /* atom: OPEN_BRACKET CLOSE_BRACKET  */
#line 2189 "parser.y"
                                    {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
        (yyval.elem)->ins = instCount+1;
    }
#line 4281 "parser.tab.c"
    break;

  case 147: /* atom: SQUARE_OPEN S testlist SQUARE_CLOSE  */
#line 2195 "parser.y"
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
        create_ins(0,"Stackpointer +", to_string(get_width(type)) + "*" + to_string((yyvsp[-1].elem)->list_size), "", "");
        funcOffset += get_width(type) * (yyvsp[-1].elem)->list_size;
    }
#line 4303 "parser.tab.c"
    break;

  case 148: /* atom: SQUARE_OPEN S SQUARE_CLOSE  */
#line 2212 "parser.y"
                                  {
        (yyval.elem) = create_node(4, "atom", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
        (yyval.elem)->ins = instCount+1;
        isinsquare=0;
    }
#line 4314 "parser.tab.c"
    break;

  case 149: /* atom: CURLY_OPEN CURLY_CLOSE  */
#line 2219 "parser.y"
                                { 
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
        (yyval.elem)->ins = instCount+1;
    }
#line 4324 "parser.tab.c"
    break;

  case 150: /* atom: NAME  */
#line 2225 "parser.y"
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
#line 4358 "parser.tab.c"
    break;

  case 151: /* atom: NUMBER  */
#line 2254 "parser.y"
                   { 
        if(incheck) isatom=1;
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
        // cout<<$$->atom_type<<endl;
    }
#line 4369 "parser.tab.c"
    break;

  case 152: /* atom: STRING_PLUS  */
#line 2260 "parser.y"
                        { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 4377 "parser.tab.c"
    break;

  case 153: /* atom: ATOM_KEYWORDS  */
#line 2263 "parser.y"
                        { 
        if(incheck) isatom=1;
        (yyval.elem)->atom_type="bool";
        (yyval.elem)->type=str_to_ch("bool");
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 4389 "parser.tab.c"
    break;

  case 154: /* atom: NONE  */
#line 2270 "parser.y"
                { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
        (yyval.elem)->atom_type="None";
    }
#line 4399 "parser.tab.c"
    break;

  case 155: /* STRING_PLUS: STRING  */
#line 2281 "parser.y"
                        {
            (yyval.elem) = (yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
            (yyval.elem)->type=str_to_ch("str");
            (yyval.elem)->atom_type="str";
        }
#line 4410 "parser.tab.c"
    break;

  case 156: /* STRING_PLUS: STRING STRING_PLUS  */
#line 2287 "parser.y"
                                { 
            (yyval.elem) = create_node(3, "STRING_PLUS", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->atom_type="str";
            (yyval.elem)->type=str_to_ch("str");

        }
#line 4423 "parser.tab.c"
    break;

  case 157: /* trailer: OPEN_BRACKET CLOSE_BRACKET  */
#line 2297 "parser.y"
                                     { 
            (yyval.elem) = create_node(3, "trailer", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
            (yyval.elem)->ins = instCount+1;

            create_ins(0, "PushParamra", "", "", "");
            (yyval.elem)->nextlist = makelist(instCount);
        }
#line 4436 "parser.tab.c"
    break;

  case 158: /* trailer: OPEN_BRACKET arglist CLOSE_BRACKET  */
#line 2305 "parser.y"
                                              {
            (yyval.elem)=(yyvsp[-1].elem);

            //func_par_type
            (yyval.elem)->func_par_type = (yyvsp[-1].elem)->func_par_type;
        }
#line 4447 "parser.tab.c"
    break;

  case 159: /* trailer: OPEN_BRACKET SELF COMMA arglist CLOSE_BRACKET  */
#line 2311 "parser.y"
                                                         {
            (yyval.elem)=(yyvsp[-1].elem);

            //func_par_type
            (yyval.elem)->func_par_type = (yyvsp[-1].elem)->func_par_type;
        }
#line 4458 "parser.tab.c"
    break;

  case 160: /* trailer: OPEN_BRACKET SELF CLOSE_BRACKET  */
#line 2317 "parser.y"
                                          {
            (yyval.elem) = create_node(4, "trailer", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-2].elem)->lineno;
            (yyval.elem)->ins = instCount+1;
        }
#line 4468 "parser.tab.c"
    break;

  case 161: /* testlist: testlist_list  */
#line 2330 "parser.y"
                           { 
            //cout<<$1->atom_type<<endl; 
            (yyval.elem) = (yyvsp[0].elem);
            if(isinsquare) (yyval.elem)-> addr = str_to_ch(chartostring((yyvsp[0].elem)->addr) + "]");
            else (yyval.elem)-> addr = (yyvsp[0].elem)->addr;
        }
#line 4479 "parser.tab.c"
    break;

  case 162: /* testlist: testlist_list COMMA  */
#line 2336 "parser.y"
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
#line 4497 "parser.tab.c"
    break;

  case 163: /* testlist_list: test  */
#line 2350 "parser.y"
                            {
            (yyval.elem) = (yyvsp[0].elem);
            (yyval.elem)->list_size = 1;
            if(isinsquare)(yyval.elem)-> addr = str_to_ch( "[" + chartostring((yyvsp[0].elem)->addr));
            else (yyval.elem)-> addr = (yyvsp[0].elem)->addr;
            

            // //function parameters check 
            // $$->func_par_type.push_back($1->atom_type);
        }
#line 4512 "parser.tab.c"
    break;

  case 164: /* testlist_list: test COLON TYPE_HINT  */
#line 2360 "parser.y"
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
#line 4547 "parser.tab.c"
    break;

  case 165: /* testlist_list: testlist_list COMMA test  */
#line 2390 "parser.y"
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
#line 4572 "parser.tab.c"
    break;

  case 166: /* testlist_list: testlist_list COMMA test COLON TYPE_HINT  */
#line 2410 "parser.y"
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
#line 4606 "parser.tab.c"
    break;

  case 167: /* classdef: CLASS class_declare COLON class_body_suite  */
#line 2472 "parser.y"
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
        }
#line 4631 "parser.tab.c"
    break;

  case 168: /* class_declare: NAME  */
#line 2494 "parser.y"
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
        }
#line 4655 "parser.tab.c"
    break;

  case 169: /* class_declare: NAME OPEN_BRACKET CLOSE_BRACKET  */
#line 2513 "parser.y"
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
        }
#line 4679 "parser.tab.c"
    break;

  case 170: /* class_declare: NAME OPEN_BRACKET argument CLOSE_BRACKET  */
#line 2532 "parser.y"
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
        }
#line 4719 "parser.tab.c"
    break;

  case 171: /* class_body_suite: NEWLINE INDENT funcdef_plus DEDENT  */
#line 2595 "parser.y"
                                                        { 
            (yyval.elem)=(yyvsp[-1].elem);
            inClass=0;
        }
#line 4728 "parser.tab.c"
    break;

  case 172: /* class_body_suite: NEWLINE INDENT funcdef_plus NEWLINE DEDENT  */
#line 2599 "parser.y"
                                                        { 
            (yyval.elem)=(yyvsp[-2].elem);
            inClass=0;
        }
#line 4737 "parser.tab.c"
    break;

  case 173: /* funcdef_plus: funcdef  */
#line 2605 "parser.y"
                       { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 4745 "parser.tab.c"
    break;

  case 174: /* funcdef_plus: funcdef_plus funcdef  */
#line 2608 "parser.y"
                                 { 
            (yyval.elem)=create_node(3,"funcdef_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
            (yyval.elem)->lineno = (yyvsp[-1].elem)->lineno;
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 4755 "parser.tab.c"
    break;

  case 175: /* arglist: argument_list  */
#line 2636 "parser.y"
                           { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 4763 "parser.tab.c"
    break;

  case 176: /* argument_list: argument  */
#line 2643 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;

            //create_ins(0, "PushParam", "RBP", "", "");
            (yyval.elem)->ins = instCount+1;
            (yyval.elem)->nextlist = makelist(instCount+1);
            create_ins(0, "PushParamra", "", "", "");
            create_ins(0, "PushParam", (yyvsp[0].elem)->addr, "", "");
        
        }
#line 4779 "parser.tab.c"
    break;

  case 177: /* argument_list: argument COMMA argument_list  */
#line 2654 "parser.y"
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
#line 4803 "parser.tab.c"
    break;

  case 178: /* argument: test  */
#line 2675 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
            //for function parameter typecheck
            (yyval.elem)->func_par_type.push_back((yyvsp[0].elem)->atom_type);
        }
#line 4813 "parser.tab.c"
    break;

  case 179: /* argument: test EQUAL test  */
#line 2680 "parser.y"
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
#line 4831 "parser.tab.c"
    break;

  case 180: /* stmt_plus: stmt  */
#line 2696 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 4839 "parser.tab.c"
    break;

  case 181: /* stmt_plus: stmt stmt_plus  */
#line 2699 "parser.y"
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
#line 4856 "parser.tab.c"
    break;


#line 4860 "parser.tab.c"

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

#line 2712 "parser.y"


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
