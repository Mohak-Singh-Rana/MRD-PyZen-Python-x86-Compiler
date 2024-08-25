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

#line 141 "parser.tab.c"

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
  YYSYMBOL_NUMBER = 31,                    /* NUMBER  */
  YYSYMBOL_OPEN_BRACKET = 32,              /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_BRACKET = 33,             /* CLOSE_BRACKET  */
  YYSYMBOL_EQUAL = 34,                     /* EQUAL  */
  YYSYMBOL_SEMI_COLON = 35,                /* SEMI_COLON  */
  YYSYMBOL_COLON = 36,                     /* COLON  */
  YYSYMBOL_COMMA = 37,                     /* COMMA  */
  YYSYMBOL_PLUS = 38,                      /* PLUS  */
  YYSYMBOL_MINUS = 39,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 40,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 41,                    /* DIVIDE  */
  YYSYMBOL_REMAINDER = 42,                 /* REMAINDER  */
  YYSYMBOL_ATTHERATE = 43,                 /* ATTHERATE  */
  YYSYMBOL_NEGATION = 44,                  /* NEGATION  */
  YYSYMBOL_BIT_AND = 45,                   /* BIT_AND  */
  YYSYMBOL_BIT_OR = 46,                    /* BIT_OR  */
  YYSYMBOL_BIT_XOR = 47,                   /* BIT_XOR  */
  YYSYMBOL_DOT = 48,                       /* DOT  */
  YYSYMBOL_CURLY_OPEN = 49,                /* CURLY_OPEN  */
  YYSYMBOL_CURLY_CLOSE = 50,               /* CURLY_CLOSE  */
  YYSYMBOL_SQUARE_OPEN = 51,               /* SQUARE_OPEN  */
  YYSYMBOL_SQUARE_CLOSE = 52,              /* SQUARE_CLOSE  */
  YYSYMBOL_LESS_THAN = 53,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 54,              /* GREATER_THAN  */
  YYSYMBOL_EQUAL_EQUAL = 55,               /* EQUAL_EQUAL  */
  YYSYMBOL_GREATER_THAN_EQUAL = 56,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_LESS_THAN_EQUAL = 57,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_NOT_EQUAL_ARROW = 58,           /* NOT_EQUAL_ARROW  */
  YYSYMBOL_NOT_EQUAL = 59,                 /* NOT_EQUAL  */
  YYSYMBOL_IS = 60,                        /* IS  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_M = 62,                         /* M  */
  YYSYMBOL_N = 63,                         /* N  */
  YYSYMBOL_file = 64,                      /* file  */
  YYSYMBOL_snippet = 65,                   /* snippet  */
  YYSYMBOL_funcdef = 66,                   /* funcdef  */
  YYSYMBOL_func_name = 67,                 /* func_name  */
  YYSYMBOL_func_ret_type = 68,             /* func_ret_type  */
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
  YYSYMBOL_flow_stmt = 79,                 /* flow_stmt  */
  YYSYMBOL_break_stmt = 80,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 81,             /* continue_stmt  */
  YYSYMBOL_return_stmt = 82,               /* return_stmt  */
  YYSYMBOL_global_stmt = 83,               /* global_stmt  */
  YYSYMBOL_comma_name_star = 84,           /* comma_name_star  */
  YYSYMBOL_compound_stmt = 85,             /* compound_stmt  */
  YYSYMBOL_if_stmt = 86,                   /* if_stmt  */
  YYSYMBOL_if_scope = 87,                  /* if_scope  */
  YYSYMBOL_else_scope = 88,                /* else_scope  */
  YYSYMBOL_else_if_scope = 89,             /* else_if_scope  */
  YYSYMBOL_nts_star = 90,                  /* nts_star  */
  YYSYMBOL_while_stmt = 91,                /* while_stmt  */
  YYSYMBOL_while_scope = 92,               /* while_scope  */
  YYSYMBOL_while_expr = 93,                /* while_expr  */
  YYSYMBOL_for_stmt = 94,                  /* for_stmt  */
  YYSYMBOL_for_core = 95,                  /* for_core  */
  YYSYMBOL_for_scope = 96,                 /* for_scope  */
  YYSYMBOL_range_stmt = 97,                /* range_stmt  */
  YYSYMBOL_for_test = 98,                  /* for_test  */
  YYSYMBOL_suite = 99,                     /* suite  */
  YYSYMBOL_test = 100,                     /* test  */
  YYSYMBOL_or_test = 101,                  /* or_test  */
  YYSYMBOL_and_test_star = 102,            /* and_test_star  */
  YYSYMBOL_and_test = 103,                 /* and_test  */
  YYSYMBOL_not_test_star = 104,            /* not_test_star  */
  YYSYMBOL_not_test = 105,                 /* not_test  */
  YYSYMBOL_comparison = 106,               /* comparison  */
  YYSYMBOL_comp_op = 107,                  /* comp_op  */
  YYSYMBOL_expr = 108,                     /* expr  */
  YYSYMBOL_xor_expr = 109,                 /* xor_expr  */
  YYSYMBOL_and_expr = 110,                 /* and_expr  */
  YYSYMBOL_shift_expr = 111,               /* shift_expr  */
  YYSYMBOL_arith_expr = 112,               /* arith_expr  */
  YYSYMBOL_term = 113,                     /* term  */
  YYSYMBOL_term_choice = 114,              /* term_choice  */
  YYSYMBOL_factor = 115,                   /* factor  */
  YYSYMBOL_factor_choice = 116,            /* factor_choice  */
  YYSYMBOL_power = 117,                    /* power  */
  YYSYMBOL_atom_expr = 118,                /* atom_expr  */
  YYSYMBOL_atom = 119,                     /* atom  */
  YYSYMBOL_STRING_PLUS = 120,              /* STRING_PLUS  */
  YYSYMBOL_trailer = 121,                  /* trailer  */
  YYSYMBOL_testlist = 122,                 /* testlist  */
  YYSYMBOL_testlist_list = 123,            /* testlist_list  */
  YYSYMBOL_classdef = 124,                 /* classdef  */
  YYSYMBOL_class_name = 125,               /* class_name  */
  YYSYMBOL_arglist = 126,                  /* arglist  */
  YYSYMBOL_argument_list = 127,            /* argument_list  */
  YYSYMBOL_argument = 128,                 /* argument  */
  YYSYMBOL_func_body_suite = 129,          /* func_body_suite  */
  YYSYMBOL_stmt_plus = 130                 /* stmt_plus  */
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
#define YYFINAL  79
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   457

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  276

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    92,    99,   104,   108,   111,   114,   120,
     128,   132,   136,   142,   157,   163,   170,   174,   182,   185,
     192,   196,   214,   217,   222,   225,   230,   233,   240,   243,
     246,   251,   256,   273,   276,   281,   298,   301,   309,   312,
     315,   320,   329,   335,   338,   343,   347,   353,   357,   362,
     365,   369,   373,   376,   381,   392,   404,   413,   420,   431,
     442,   452,   459,   472,   484,   499,   506,   512,   528,   553,
     571,   580,   587,   596,   603,   606,   609,   615,   621,   624,
     632,   639,   644,   647,   655,   662,   667,   673,   678,   681,
     693,   696,   699,   702,   705,   708,   711,   714,   717,   720,
     723,   728,   731,   739,   742,   750,   754,   762,   765,   773,
     776,   782,   789,   792,   801,   804,   807,   810,   813,   818,
     824,   828,   831,   834,   838,   841,   849,   852,   856,   862,
     865,   869,   872,   876,   880,   884,   888,   891,   896,   900,
     906,   910,   914,   920,   923,   928,   931,   947,   951,   968,
     972,   976,   982,   998,  1001,  1005,  1009,  1016,  1019,  1026,
    1029,  1032,  1037,  1040
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
  "RETURN", "CLASS", "DEF", "GLOBAL", "ATOM_KEYWORDS", "STRING", "NUMBER",
  "OPEN_BRACKET", "CLOSE_BRACKET", "EQUAL", "SEMI_COLON", "COLON", "COMMA",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "REMAINDER", "ATTHERATE",
  "NEGATION", "BIT_AND", "BIT_OR", "BIT_XOR", "DOT", "CURLY_OPEN",
  "CURLY_CLOSE", "SQUARE_OPEN", "SQUARE_CLOSE", "LESS_THAN",
  "GREATER_THAN", "EQUAL_EQUAL", "GREATER_THAN_EQUAL", "LESS_THAN_EQUAL",
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
  "func_body_suite", "stmt_plus", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-202)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     103,   103,  -202,  -202,  -202,  -202,   402,  -202,  -202,   402,
      14,    20,    25,  -202,    43,  -202,   333,  -202,  -202,  -202,
      30,   270,    85,  -202,  -202,   103,  -202,    10,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,   402,  -202,  -202,
    -202,   406,    47,  -202,    67,    82,    86,    89,  -202,   222,
      77,    91,    94,    12,    58,  -202,   406,  -202,    44,  -202,
    -202,  -202,   106,  -202,  -202,  -202,  -202,  -202,    -7,  -202,
     112,   108,  -202,  -202,   110,   115,  -202,  -202,    97,  -202,
    -202,  -202,    33,   114,   402,   117,   132,   402,   402,   143,
    -202,  -202,  -202,   137,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,   135,   406,   406,   406,   406,   406,   406,   406,  -202,
    -202,  -202,  -202,  -202,   406,  -202,   406,   356,   145,   402,
    -202,   402,   379,   184,    61,    23,   146,  -202,   148,  -202,
    -202,  -202,  -202,  -202,   125,  -202,  -202,   159,  -202,  -202,
     129,     9,   402,   402,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,    58,    58,  -202,  -202,  -202,   131,   133,   139,  -202,
    -202,   116,   134,   141,   136,   176,  -202,  -202,   147,    24,
      -1,  -202,   151,   170,   223,   108,  -202,   184,  -202,   184,
     154,  -202,   402,   402,   402,   166,   169,   402,  -202,   402,
    -202,   178,   184,   156,   310,   181,   170,   223,  -202,   182,
     402,  -202,   158,   191,  -202,  -202,  -202,    99,   184,   183,
     402,  -202,  -202,  -202,  -202,  -202,  -202,  -202,   184,   310,
      98,  -202,   164,  -202,  -202,  -202,   223,   310,   121,   183,
     188,    54,  -202,  -202,  -202,   198,  -202,   223,  -202,   118,
    -202,  -202,   174,   402,  -202,   190,   175,  -202,   402,  -202,
    -202,   211,  -202,  -202,   185,   189,  -202,   186,  -202,   184,
    -202,  -202,   184,  -202,  -202,   184,   184,  -202,    99,  -202,
     121,   193,  -202,  -202,   184,  -202
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,   134,    57,    65,    70,     0,    41,    42,    43,
       0,     0,     0,   137,   138,   135,     0,   121,   122,   123,
       0,     0,     0,     4,    52,     6,    22,     0,    26,    28,
      29,    38,    39,    40,    30,    23,    49,     0,    50,     2,
      51,     0,   145,    77,     0,    78,     0,    82,    87,    88,
     101,   103,   105,   107,   109,   112,     0,   120,   124,   126,
     136,    33,   143,    53,     7,    86,    44,   152,     0,    13,
       0,    45,   139,   130,   145,     0,   133,   132,     0,     1,
       8,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     2,    97,     0,    90,    91,    92,    93,    94,    95,
      96,    99,     0,     0,     0,     0,     0,     0,     0,   118,
     114,   116,   117,   115,     0,   119,     0,     0,     0,     0,
     127,   144,     0,     0,     0,     0,     0,    46,     0,   129,
     131,    24,    27,     2,     0,    66,     2,     0,    31,    34,
      36,   146,     0,     0,    98,   100,    89,   102,   104,   106,
     108,   110,   111,   113,   125,   140,   157,     0,   153,   155,
     128,     0,   147,     0,     0,     0,    74,   149,    20,     0,
       0,    16,    18,     0,     0,    47,   146,     0,     2,     0,
       0,    69,     0,     0,     0,    79,    83,     0,   141,   154,
     142,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,    14,     0,     0,   159,     9,    48,    54,     0,    67,
       0,    37,    32,    35,   158,   156,   148,   150,     0,   162,
       0,    21,     0,    11,    17,    19,     0,     0,     0,    63,
       0,     0,    73,   151,   163,     0,    75,     0,    10,     0,
      58,    59,     0,     0,    56,     0,     0,    71,     0,    76,
      12,     0,   160,     2,     0,     0,     2,     0,   161,     0,
       2,     2,     0,    72,    55,     0,     0,    68,    60,    64,
       0,     0,    61,     2,     0,    62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,   -89,  -198,  -202,    16,  -202,  -202,    22,  -202,  -202,
      21,  -202,  -179,     5,  -202,   144,  -202,  -162,  -202,  -202,
    -202,  -202,  -202,    55,  -202,  -202,  -202,  -159,  -202,   -33,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -169,    -9,
    -202,  -202,    96,  -202,    -3,   138,  -202,   -37,   152,   153,
     157,  -202,    11,  -202,   -47,  -202,  -202,  -202,  -202,   229,
    -202,     3,  -202,  -202,  -202,   127,  -202,    68,  -184,  -201
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    84,   228,    22,    23,    24,    70,   202,   125,   170,
     171,   172,    25,   166,    27,    28,    29,   139,    30,    31,
      32,    33,    34,   127,    35,    36,    37,   242,   243,   244,
      38,    39,   134,    40,    85,    41,   181,   231,   167,    42,
      43,    44,    45,    46,    47,    48,   102,    49,    50,    51,
      52,    53,    54,   114,    55,    56,    57,    58,    59,    60,
     120,    61,    62,    63,    68,   157,   158,   159,   205,   220
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,   142,   143,    65,    86,    26,    26,    74,   207,   115,
     209,   230,    74,   223,    81,   219,   183,    64,   234,    75,
     211,   106,   213,   217,    78,   122,   239,    67,    83,   123,
      26,   245,   198,    69,   173,   196,   199,   131,    71,   229,
     219,    80,   238,   184,   177,    82,     2,   179,   219,   233,
     107,   108,   116,   250,    87,     6,     7,     8,     9,   174,
     197,    12,    13,    14,    15,    16,   147,   153,   109,   154,
     270,    17,    18,    14,   168,   135,   117,    19,   138,   140,
      76,    88,    20,    89,    21,    79,   255,   247,    90,   208,
     264,   248,   118,   267,   169,   119,   268,   269,   110,   111,
     112,   113,   235,   -81,   236,   275,    91,     1,   156,   -85,
     161,   271,   162,   156,    -3,    -3,     2,     3,   151,   152,
       4,     5,   251,   103,   252,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   240,   241,   104,   105,
     186,    17,    18,   121,   124,   126,   128,    19,   129,   130,
     133,   137,    20,   136,    21,   141,   144,   145,   160,   175,
     176,   178,   180,   182,   259,   187,   188,   262,   190,   193,
     191,   265,   266,   140,   212,   140,   189,   192,   214,   204,
     156,   194,   201,   195,   274,   200,   210,   -80,   165,   -84,
     216,   225,   218,   221,   226,   168,   227,     2,    -3,    26,
     237,   232,   204,   246,   249,   240,     6,     7,     8,     9,
     253,   256,    12,    13,    14,    15,    16,   258,   222,   263,
     224,   260,    17,    18,    26,   261,   132,   203,    19,   273,
     206,   204,    26,    20,   254,    21,     2,   272,   185,   257,
     146,    92,   204,    72,    93,     6,     7,     8,     9,   164,
       0,    12,    13,    14,    15,    16,   148,   215,   149,     0,
       0,    17,    18,   150,     0,     0,     0,    19,     0,     0,
       0,     0,    20,     0,    21,    94,    95,    96,    97,    98,
      99,   100,   101,     2,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     0,     0,     0,     0,     0,    13,
      14,    15,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    20,
       0,    21,    77,     2,     3,     0,     0,     4,     5,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,     0,     2,     0,    17,    18,
       0,     0,     0,     0,    19,     6,     0,     0,     0,    20,
       0,    21,    13,    14,    15,    16,    73,     0,     0,     2,
       0,    17,    18,     0,     0,     0,     0,    19,     6,     0,
       0,     0,    20,     0,    21,    13,    14,    15,    16,   155,
       0,     0,     2,     0,    17,    18,     0,     0,     0,     0,
      19,     6,     0,     0,     0,    20,     0,    21,    13,    14,
      15,    16,   163,     0,     0,     2,     0,    17,    18,     2,
       0,     0,     0,    19,     6,     0,     0,     0,    20,     0,
      21,    13,    14,    15,    16,    13,    14,    15,    16,     0,
      17,    18,     0,     0,    17,    18,    19,     0,     0,     0,
      19,    20,     0,    21,     0,    20,     0,    21
};

static const yytype_int16 yycheck[] =
{
       9,    90,    91,     6,    41,     0,     1,    16,   177,    56,
     179,   209,    21,   197,     4,   194,     7,     1,   219,    16,
     182,     9,   184,   192,    21,    32,   227,    13,    37,    36,
      25,   229,    33,    13,    11,    11,    37,     4,    13,   208,
     219,    25,   226,    34,   133,    35,    13,   136,   227,   218,
      38,    39,     8,   237,     7,    22,    23,    24,    25,    36,
      36,    28,    29,    30,    31,    32,   103,   114,    10,   116,
     268,    38,    39,    30,    13,    84,    32,    44,    87,    88,
      50,    34,    49,    36,    51,     0,   245,    33,    21,   178,
     259,    37,    48,   262,    33,    51,   265,   266,    40,    41,
      42,    43,     4,    21,     6,   274,    20,     4,   117,    20,
     119,   270,   121,   122,    15,    16,    13,    14,   107,   108,
      17,    18,     4,    46,     6,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    15,    16,    47,    45,
     143,    38,    39,    37,    32,    37,    36,    44,    33,    52,
      36,    19,    49,    36,    51,    12,    19,    22,    13,    13,
      12,    36,     3,    34,   253,    34,    33,   256,    52,    33,
      36,   260,   261,   182,   183,   184,    37,    36,   187,   174,
     189,     5,    12,    36,   273,    34,    32,    21,     4,    20,
      12,   200,    36,    12,    36,    13,     5,    13,    15,   194,
      36,   210,   197,    15,     6,    15,    22,    23,    24,    25,
      36,    36,    28,    29,    30,    31,    32,     6,   196,    33,
     199,    36,    38,    39,   219,    36,    82,     4,    44,    36,
     175,   226,   227,    49,   243,    51,    13,   270,   142,   248,
     102,    19,   237,    14,    22,    22,    23,    24,    25,   122,
      -1,    28,    29,    30,    31,    32,   104,   189,   105,    -1,
      -1,    38,    39,   106,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,    49,    -1,    51,    53,    54,    55,    56,    57,
      58,    59,    60,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    13,    14,    -1,    -1,    17,    18,    -1,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    13,    14,    17,    18,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    38,    39,    44,
      49,    51,    64,    65,    66,    73,    74,    75,    76,    77,
      79,    80,    81,    82,    83,    85,    86,    87,    91,    92,
      94,    96,   100,   101,   102,   103,   104,   105,   106,   108,
     109,   110,   111,   112,   113,   115,   116,   117,   118,   119,
     120,   122,   123,   124,    65,   105,   100,    13,   125,    13,
      67,    13,   120,    33,   100,   122,    50,    52,   122,     0,
      65,     4,    35,   100,    62,    95,   108,     7,    34,    36,
      21,    20,    19,    22,    53,    54,    55,    56,    57,    58,
      59,    60,   107,    46,    47,    45,     9,    38,    39,    10,
      40,    41,    42,    43,   114,   115,     8,    32,    48,    51,
     121,    37,    32,    36,    32,    69,    37,    84,    36,    33,
      52,     4,    76,    36,    93,   100,    36,    19,   100,    78,
     100,    12,    62,    62,    19,    22,   106,   108,   109,   110,
     111,   113,   113,   115,   115,    33,   100,   126,   127,   128,
      13,   100,   100,    33,   126,     4,    74,    99,    13,    33,
      70,    71,    72,    11,    36,    13,    12,    62,    36,    62,
       3,    97,    34,     7,    34,   103,   105,    34,    33,    37,
      52,    36,    36,    33,     5,    36,    11,    36,    33,    37,
      34,    12,    68,     4,    74,   129,    84,    99,    62,    99,
      32,    78,   100,    78,   100,   128,    12,    99,    36,    73,
     130,    12,    68,   129,    71,   100,    36,     5,    63,    99,
      63,    98,   100,    99,   130,     4,     6,    36,   129,   130,
      15,    16,    88,    89,    90,    63,    15,    33,    37,     6,
     129,     4,     6,    36,   100,    88,    36,   100,     6,    62,
      36,    36,    62,    33,    99,    62,    62,    99,    99,    99,
      63,    88,    90,    36,    62,    99
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
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
     115,   116,   116,   116,   117,   117,   118,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     121,   121,   121,   122,   122,   123,   123,   123,   123,   124,
     124,   124,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   129,   130,   130
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
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
       1,     1,     1,     1,     1,     3,     1,     2,     3,     3,
       2,     3,     2,     2,     1,     1,     1,     1,     1,     2,
       2,     3,     3,     1,     2,     1,     3,     3,     5,     4,
       6,     7,     1,     1,     2,     1,     3,     1,     3,     1,
       4,     5,     1,     2
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
#line 86 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal M");
        (yyval.elem)->ins = instCount+1;
}
#line 1507 "parser.tab.c"
    break;

  case 3: /* N: %empty  */
#line 92 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal N");
        (yyval.elem)->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
#line 1517 "parser.tab.c"
    break;

  case 4: /* file: snippet  */
#line 99 "parser.y"
              {
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 1525 "parser.tab.c"
    break;

  case 5: /* snippet: NEWLINE  */
#line 104 "parser.y"
                 {
       (yyval.elem)=(yyvsp[0].elem);
	   (yyval.elem)->ins = instCount+1;
    }
#line 1534 "parser.tab.c"
    break;

  case 6: /* snippet: stmt  */
#line 108 "parser.y"
            { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1542 "parser.tab.c"
    break;

  case 7: /* snippet: NEWLINE snippet  */
#line 111 "parser.y"
                       { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1550 "parser.tab.c"
    break;

  case 8: /* snippet: stmt snippet  */
#line 114 "parser.y"
                   {  
        (yyval.elem) = create_node(3, "snippet", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
    }
#line 1559 "parser.tab.c"
    break;

  case 9: /* funcdef: DEF func_name parameters COLON func_body_suite  */
#line 120 "parser.y"
                                                        {
            //STE code start
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-3].elem)->addr, (yyvsp[-1].elem)->num_params, (yyvsp[-4].elem)->lineno, 1);
            //STE code end


        }
#line 1572 "parser.tab.c"
    break;

  case 10: /* funcdef: DEF func_name parameters ARROW_OPER func_ret_type COLON func_body_suite  */
#line 128 "parser.y"
                                                                                  {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-5].elem)->addr, (yyvsp[-3].elem)->num_params, (yyvsp[-6].elem)->lineno, 1);
        }
#line 1581 "parser.tab.c"
    break;

  case 11: /* funcdef: DEF func_name OPEN_BRACKET CLOSE_BRACKET COLON func_body_suite  */
#line 132 "parser.y"
                                                                         {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-4].elem)->addr, 0, (yyvsp[-5].elem)->lineno, 1);
        }
#line 1590 "parser.tab.c"
    break;

  case 12: /* funcdef: DEF func_name OPEN_BRACKET CLOSE_BRACKET ARROW_OPER func_ret_type COLON func_body_suite  */
#line 136 "parser.y"
                                                                                                 {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-6].elem)->addr, 0, (yyvsp[-7].elem)->lineno, 1);
        }
#line 1599 "parser.tab.c"
    break;

  case 13: /* func_name: NAME  */
#line 143 "parser.y"
    {   
        (yyval.elem)=(yyvsp[0].elem);
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
#line 1617 "parser.tab.c"
    break;

  case 14: /* func_ret_type: TYPE_HINT  */
#line 157 "parser.y"
                        {
        (yyval.elem)=(yyvsp[0].elem);
        get_prev_scope(current_ste)->return_type = (yyvsp[0].elem)->addr;
    }
#line 1626 "parser.tab.c"
    break;

  case 15: /* parameters: OPEN_BRACKET typedargslist CLOSE_BRACKET  */
#line 163 "parser.y"
                                                     {  
            (yyval.elem) = create_node(4, "parameters", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[-1].elem)->num_params;
        }
#line 1636 "parser.tab.c"
    break;

  case 16: /* typedargslist: typedarg  */
#line 170 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;
        }
#line 1645 "parser.tab.c"
    break;

  case 17: /* typedargslist: typedargslist COMMA typedarg  */
#line 174 "parser.y"
                                         {  
            (yyval.elem) = create_node(4, "typedargslist", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;

            (yyval.elem)->num_params = (yyvsp[-2].elem)->num_params + 1;
        }
#line 1656 "parser.tab.c"
    break;

  case 18: /* typedarg: tfpdef  */
#line 182 "parser.y"
                   {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1664 "parser.tab.c"
    break;

  case 19: /* typedarg: tfpdef EQUAL test  */
#line 185 "parser.y"
                            {  
            (yyval.elem) = create_node(4, "typedarg", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");    //is this instruction needed?????
        }
#line 1674 "parser.tab.c"
    break;

  case 20: /* tfpdef: NAME  */
#line 192 "parser.y"
             {  
            (yyval.elem)=(yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
        }
#line 1683 "parser.tab.c"
    break;

  case 21: /* tfpdef: NAME COLON TYPE_HINT  */
#line 196 "parser.y"
                               {  
            (yyval.elem) = create_node(4, "tfpdef", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem)); 
			(yyval.elem)->ins = instCount+1;

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
#line 1704 "parser.tab.c"
    break;

  case 22: /* stmt: simple_stmt  */
#line 214 "parser.y"
                        { 
        	(yyval.elem)=(yyvsp[0].elem);
        }
#line 1712 "parser.tab.c"
    break;

  case 23: /* stmt: compound_stmt  */
#line 217 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem); 
        }
#line 1720 "parser.tab.c"
    break;

  case 24: /* simple_stmt: small_stmt_list SEMI_COLON NEWLINE  */
#line 222 "parser.y"
                                                {  
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 1728 "parser.tab.c"
    break;

  case 25: /* simple_stmt: small_stmt_list NEWLINE  */
#line 225 "parser.y"
                                   {  
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 1736 "parser.tab.c"
    break;

  case 26: /* small_stmt_list: small_stmt  */
#line 230 "parser.y"
                                {   
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1744 "parser.tab.c"
    break;

  case 27: /* small_stmt_list: small_stmt_list SEMI_COLON small_stmt  */
#line 233 "parser.y"
                                                     {  
           (yyval.elem) = create_node(3, "small_stmt_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
		   (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
           (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, (yyvsp[0].elem)->nextlist);
        }
#line 1754 "parser.tab.c"
    break;

  case 28: /* small_stmt: expr_stmt  */
#line 240 "parser.y"
                            {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1762 "parser.tab.c"
    break;

  case 29: /* small_stmt: flow_stmt  */
#line 243 "parser.y"
                        {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1770 "parser.tab.c"
    break;

  case 30: /* small_stmt: global_stmt  */
#line 246 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1778 "parser.tab.c"
    break;

  case 31: /* expr_stmt: test ASSIGN_OPERATOR test  */
#line 251 "parser.y"
                                     { 
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            // Here add instruction 
        }
#line 1788 "parser.tab.c"
    break;

  case 32: /* expr_stmt: test COLON TYPE_HINT ASSIGN_OPERATOR test  */
#line 256 "parser.y"
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
#line 1810 "parser.tab.c"
    break;

  case 33: /* expr_stmt: testlist  */
#line 273 "parser.y"
                   {
			(yyval.elem)=(yyvsp[0].elem);
        }
#line 1818 "parser.tab.c"
    break;

  case 34: /* expr_stmt: test EQUAL eq_testlist_star_expr_plus  */
#line 276 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-2].elem)->ins;
			create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, ""); 
        }
#line 1828 "parser.tab.c"
    break;

  case 35: /* expr_stmt: test COLON TYPE_HINT EQUAL eq_testlist_star_expr_plus  */
#line 281 "parser.y"
                                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem));
			(yyval.elem)->ins = (yyvsp[-4].elem)->ins;
			create_ins(0, (yyvsp[-4].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, ""); 
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
#line 1848 "parser.tab.c"
    break;

  case 36: /* eq_testlist_star_expr_plus: test  */
#line 298 "parser.y"
                                 {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1856 "parser.tab.c"
    break;

  case 37: /* eq_testlist_star_expr_plus: test EQUAL eq_testlist_star_expr_plus  */
#line 301 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;    //x=y=z
        }
#line 1867 "parser.tab.c"
    break;

  case 38: /* flow_stmt: break_stmt  */
#line 309 "parser.y"
                        {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1875 "parser.tab.c"
    break;

  case 39: /* flow_stmt: continue_stmt  */
#line 312 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1883 "parser.tab.c"
    break;

  case 40: /* flow_stmt: return_stmt  */
#line 315 "parser.y"
                         {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1891 "parser.tab.c"
    break;

  case 41: /* break_stmt: BREAK  */
#line 320 "parser.y"
                    {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = instCount+1;
            int temp = loopStack.top();
            loopStack.pop();
            create_ins(0, "goto", to_string(loopStack.top()), "", "");
            loopStack.push(temp);
        }
#line 1904 "parser.tab.c"
    break;

  case 42: /* continue_stmt: CONTINUE  */
#line 329 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = instCount+1;
            create_ins(0, "goto", to_string(loopStack.top()), "", "");
        }
#line 1914 "parser.tab.c"
    break;

  case 43: /* return_stmt: RETURN  */
#line 335 "parser.y"
                        {  
            
        }
#line 1922 "parser.tab.c"
    break;

  case 44: /* return_stmt: RETURN test  */
#line 338 "parser.y"
                          {  
            
        }
#line 1930 "parser.tab.c"
    break;

  case 45: /* global_stmt: GLOBAL NAME  */
#line 343 "parser.y"
                           {  
            (yyval.elem) = create_node(3, "global_stmt", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 1939 "parser.tab.c"
    break;

  case 46: /* global_stmt: GLOBAL NAME comma_name_star  */
#line 347 "parser.y"
                                      {   
            (yyval.elem) = create_node(4, "global_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 1948 "parser.tab.c"
    break;

  case 47: /* comma_name_star: COMMA NAME  */
#line 353 "parser.y"
                               {  
            (yyval.elem) = create_node(3, "comma_name_star", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 1957 "parser.tab.c"
    break;

  case 48: /* comma_name_star: COMMA NAME comma_name_star  */
#line 357 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "comma_name_star", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 1966 "parser.tab.c"
    break;

  case 49: /* compound_stmt: if_stmt  */
#line 362 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);  
        }
#line 1974 "parser.tab.c"
    break;

  case 50: /* compound_stmt: while_stmt  */
#line 365 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
            loopStack.pop();
        }
#line 1983 "parser.tab.c"
    break;

  case 51: /* compound_stmt: for_stmt  */
#line 369 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
            loopStack.pop();
        }
#line 1992 "parser.tab.c"
    break;

  case 52: /* compound_stmt: funcdef  */
#line 373 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2000 "parser.tab.c"
    break;

  case 53: /* compound_stmt: classdef  */
#line 376 "parser.y"
                       {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 2008 "parser.tab.c"
    break;

  case 54: /* if_stmt: if_scope test COLON M suite  */
#line 381 "parser.y"
                                         {  
           (yyval.elem)=create_node(6, "if_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
           (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
           backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
           (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);

            //STE code start
            current_ste = get_prev_scope(current_ste);  
            //STE code end

        }
#line 2024 "parser.tab.c"
    break;

  case 55: /* if_stmt: if_scope test COLON M suite N else_scope COLON M suite  */
#line 392 "parser.y"
                                                                   {  
            (yyval.elem) = create_node(11, "if_else_stmt", (yyvsp[-9].elem),(yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            vector<int> temp = merge((yyvsp[-5].elem)->nextlist, (yyvsp[-4].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);

            //STE code start
            current_ste = get_prev_scope(current_ste);
            //STE code end

        }
#line 2041 "parser.tab.c"
    break;

  case 56: /* if_stmt: if_scope test COLON M suite N nts_star  */
#line 404 "parser.y"
                                                    {  
            (yyval.elem) = create_node(8, "if_elif_stmt", (yyvsp[-6].elem),(yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);     
            vector<int> temp = merge((yyvsp[-2].elem)->nextlist, (yyvsp[-1].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);    
        }
#line 2053 "parser.tab.c"
    break;

  case 57: /* if_scope: IF  */
#line 413 "parser.y"
            {
        (yyval.elem)=(yyvsp[0].elem);
        current_ste = insert_entry_new_scope(current_ste);
        populate_new_scope(current_ste->prev_scope, "IF", "IF", 0, (yyvsp[0].elem)->lineno, 0);
    }
#line 2063 "parser.tab.c"
    break;

  case 58: /* else_scope: ELSE  */
#line 420 "parser.y"
                {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        current_ste = get_prev_scope(current_ste);
        current_ste = insert_entry_new_scope(current_ste);
        populate_new_scope(current_ste->prev_scope, "ELSE", "ELSE", 0, (yyvsp[0].elem)->lineno, 1);

        //STE code end
    }
#line 2077 "parser.tab.c"
    break;

  case 59: /* else_if_scope: ELIF  */
#line 431 "parser.y"
                   {
        (yyval.elem)=(yyvsp[0].elem);
        //STE code start
        current_ste = get_prev_scope(current_ste);
        current_ste = insert_entry_new_scope(current_ste);
        populate_new_scope(current_ste->prev_scope, "ELSE_IF", "ELSE_IF", 0, (yyvsp[0].elem)->lineno, 1);
        //STE code end
    }
#line 2090 "parser.tab.c"
    break;

  case 60: /* nts_star: else_if_scope test COLON M suite  */
#line 442 "parser.y"
                                             {  
            (yyval.elem)=create_node(6, "elif_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);

            //STE code start
            current_ste = get_prev_scope(current_ste);
            //STE code end
        }
#line 2105 "parser.tab.c"
    break;

  case 61: /* nts_star: else_if_scope test COLON M suite N nts_star  */
#line 452 "parser.y"
                                                       {  
            (yyval.elem) = create_node(8, "elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-5].elem)->ins;
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist));
        }
#line 2117 "parser.tab.c"
    break;

  case 62: /* nts_star: else_if_scope test COLON M suite N else_scope COLON M suite  */
#line 459 "parser.y"
                                                                       {  
            (yyval.elem) = create_node(11, "elif_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-8].elem)->ins;
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-5].elem)->nextlist, merge((yyvsp[-4].elem)->nextlist,(yyvsp[0].elem)->nextlist));

            //STE code start
            current_ste = get_prev_scope(current_ste);
            //STE code end
        }
#line 2133 "parser.tab.c"
    break;

  case 63: /* while_stmt: while_scope M while_expr COLON M suite  */
#line 472 "parser.y"
                                                     {  
            (yyval.elem) = create_node(7, "while_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            backpatch((yyvsp[0].elem)->nextlist, (yyvsp[-4].elem)->ins);
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = (yyvsp[-3].elem)->falselist;
            create_ins(0, "goto", to_string((yyvsp[-4].elem)->ins), "", "");

            //STE code start
            current_ste = get_prev_scope(current_ste);
            //STE code end
        }
#line 2150 "parser.tab.c"
    break;

  case 64: /* while_stmt: while_scope M while_expr COLON M suite N else_scope COLON M suite  */
#line 484 "parser.y"
                                                                                     {   
			(yyval.elem) = create_node(12, "while_else_stmt", (yyvsp[-10].elem), (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-9].elem)->ins;
			backpatch((yyvsp[-4].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-5].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
			backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
			(yyval.elem)->nextlist = (yyvsp[0].elem)->nextlist; //verify //verified 

            //STE code start
            current_ste = get_prev_scope(current_ste);
            //STE code end
        }
#line 2168 "parser.tab.c"
    break;

  case 65: /* while_scope: WHILE  */
#line 499 "parser.y"
                   {
        (yyval.elem)=(yyvsp[0].elem);
        current_ste = insert_entry_new_scope(current_ste);
        populate_new_scope(current_ste->prev_scope, "WHILE", "WHILE", 0, (yyvsp[0].elem)->lineno, 0);
    }
#line 2178 "parser.tab.c"
    break;

  case 66: /* while_expr: test  */
#line 506 "parser.y"
                   { 
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            loopStack.push((yyval.elem)->ins);
        }
#line 2188 "parser.tab.c"
    break;

  case 67: /* for_stmt: for_scope for_core COLON M suite  */
#line 512 "parser.y"
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
            current_ste = get_prev_scope(current_ste);
            //STE code end            
        }
#line 2209 "parser.tab.c"
    break;

  case 68: /* for_stmt: for_scope for_core COLON M suite N ELSE COLON M suite  */
#line 528 "parser.y"
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
            current_ste = get_prev_scope(current_ste);
            //STE code end
        }
#line 2237 "parser.tab.c"
    break;

  case 69: /* for_core: expr IN range_stmt  */
#line 553 "parser.y"
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
#line 2258 "parser.tab.c"
    break;

  case 70: /* for_scope: FOR  */
#line 571 "parser.y"
               {
        //STE code start
        //loopStack.push($$->ins);
        current_ste = insert_entry_new_scope(current_ste);
        populate_new_scope(current_ste->prev_scope, "FOR", "FOR", 0, (yyvsp[0].elem)->lineno, 0);
        //STE code end
    }
#line 2270 "parser.tab.c"
    break;

  case 71: /* range_stmt: RANGE OPEN_BRACKET for_test CLOSE_BRACKET  */
#line 580 "parser.y"
                                                      {
            (yyval.elem) = create_node(5, "range_stmt", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;

            (yyval.elem)->for_end = (yyvsp[-1].elem)->addr;
            (yyval.elem)->for_start = strdup("0");
        }
#line 2282 "parser.tab.c"
    break;

  case 72: /* range_stmt: RANGE OPEN_BRACKET for_test COMMA test CLOSE_BRACKET  */
#line 587 "parser.y"
                                                               {
            (yyval.elem) = create_node(7, "range_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;

            (yyval.elem)->for_end = (yyvsp[-1].elem)->addr;
            (yyval.elem)->for_start = (yyvsp[-3].elem)->addr;
        }
#line 2294 "parser.tab.c"
    break;

  case 73: /* for_test: test  */
#line 596 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            //loopStack.push($$->ins);
        }
#line 2304 "parser.tab.c"
    break;

  case 74: /* suite: simple_stmt  */
#line 603 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2312 "parser.tab.c"
    break;

  case 75: /* suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 606 "parser.y"
                                            {
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 2320 "parser.tab.c"
    break;

  case 76: /* suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 609 "parser.y"
                                                    { 
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 2328 "parser.tab.c"
    break;

  case 77: /* test: or_test  */
#line 615 "parser.y"
                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2336 "parser.tab.c"
    break;

  case 78: /* or_test: and_test  */
#line 621 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2344 "parser.tab.c"
    break;

  case 79: /* or_test: and_test_star OR M and_test  */
#line 624 "parser.y"
                                         {  
            (yyval.elem) = create_node(5, "or_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;
        }
#line 2356 "parser.tab.c"
    break;

  case 80: /* and_test_star: and_test_star OR M and_test  */
#line 632 "parser.y"
                                            {
            (yyval.elem) = create_node(5, "and_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;
        }
#line 2368 "parser.tab.c"
    break;

  case 81: /* and_test_star: and_test  */
#line 639 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2376 "parser.tab.c"
    break;

  case 82: /* and_test: not_test  */
#line 644 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2384 "parser.tab.c"
    break;

  case 83: /* and_test: not_test_star AND M not_test  */
#line 647 "parser.y"
                                          {  
            (yyval.elem) = create_node(5, "and_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;
        }
#line 2396 "parser.tab.c"
    break;

  case 84: /* not_test_star: not_test_star AND M not_test  */
#line 655 "parser.y"
                                              { 
            (yyval.elem) = create_node(5, "not_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;
        }
#line 2408 "parser.tab.c"
    break;

  case 85: /* not_test_star: not_test  */
#line 662 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2416 "parser.tab.c"
    break;

  case 86: /* not_test: NOT not_test  */
#line 667 "parser.y"
                         { 
            (yyval.elem) = create_node(3, "not_test", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->truelist = (yyvsp[0].elem)->falselist;
            (yyval.elem)->falselist = (yyvsp[0].elem)->truelist;
        }
#line 2427 "parser.tab.c"
    break;

  case 87: /* not_test: comparison  */
#line 673 "parser.y"
                        { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2435 "parser.tab.c"
    break;

  case 88: /* comparison: expr  */
#line 678 "parser.y"
                  {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2443 "parser.tab.c"
    break;

  case 89: /* comparison: expr comp_op comparison  */
#line 681 "parser.y"
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
#line 2458 "parser.tab.c"
    break;

  case 90: /* comp_op: LESS_THAN  */
#line 693 "parser.y"
                    {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2466 "parser.tab.c"
    break;

  case 91: /* comp_op: GREATER_THAN  */
#line 696 "parser.y"
                    { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2474 "parser.tab.c"
    break;

  case 92: /* comp_op: EQUAL_EQUAL  */
#line 699 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2482 "parser.tab.c"
    break;

  case 93: /* comp_op: GREATER_THAN_EQUAL  */
#line 702 "parser.y"
                            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2490 "parser.tab.c"
    break;

  case 94: /* comp_op: LESS_THAN_EQUAL  */
#line 705 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2498 "parser.tab.c"
    break;

  case 95: /* comp_op: NOT_EQUAL_ARROW  */
#line 708 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2506 "parser.tab.c"
    break;

  case 96: /* comp_op: NOT_EQUAL  */
#line 711 "parser.y"
                   {
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2514 "parser.tab.c"
    break;

  case 97: /* comp_op: IN  */
#line 714 "parser.y"
            {  
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2522 "parser.tab.c"
    break;

  case 98: /* comp_op: NOT IN  */
#line 717 "parser.y"
                { 
        (yyval.elem) = create_node(3, "NOT IN", (yyvsp[-1].elem), (yyvsp[0].elem));
    }
#line 2530 "parser.tab.c"
    break;

  case 99: /* comp_op: IS  */
#line 720 "parser.y"
            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2538 "parser.tab.c"
    break;

  case 100: /* comp_op: IS NOT  */
#line 723 "parser.y"
                { 
        (yyval.elem) = create_node(3, "IS NOT", (yyvsp[-1].elem), (yyvsp[0].elem));
    }
#line 2546 "parser.tab.c"
    break;

  case 101: /* expr: xor_expr  */
#line 728 "parser.y"
                  { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2554 "parser.tab.c"
    break;

  case 102: /* expr: xor_expr BIT_OR expr  */
#line 731 "parser.y"
                                  {  
            (yyval.elem) = create_node(4, "expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2565 "parser.tab.c"
    break;

  case 103: /* xor_expr: and_expr  */
#line 739 "parser.y"
                   { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2573 "parser.tab.c"
    break;

  case 104: /* xor_expr: and_expr BIT_XOR xor_expr  */
#line 742 "parser.y"
                                       {  
            (yyval.elem) = create_node(4, "xor_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2584 "parser.tab.c"
    break;

  case 105: /* and_expr: shift_expr  */
#line 750 "parser.y"
                       { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2593 "parser.tab.c"
    break;

  case 106: /* and_expr: shift_expr BIT_AND and_expr  */
#line 754 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "and_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2604 "parser.tab.c"
    break;

  case 107: /* shift_expr: arith_expr  */
#line 762 "parser.y"
                         { 
                (yyval.elem) = (yyvsp[0].elem); 
            }
#line 2612 "parser.tab.c"
    break;

  case 108: /* shift_expr: arith_expr SHIFT_OPER shift_expr  */
#line 765 "parser.y"
                                                 { 
                (yyval.elem) = create_node(4, "shift_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2623 "parser.tab.c"
    break;

  case 109: /* arith_expr: term  */
#line 773 "parser.y"
                 { 
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 2631 "parser.tab.c"
    break;

  case 110: /* arith_expr: arith_expr PLUS term  */
#line 776 "parser.y"
                                   { 
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2642 "parser.tab.c"
    break;

  case 111: /* arith_expr: arith_expr MINUS term  */
#line 782 "parser.y"
                                    { 
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2653 "parser.tab.c"
    break;

  case 112: /* term: factor  */
#line 789 "parser.y"
             {
            (yyval.elem) = (yyvsp[0].elem); 
        }
#line 2661 "parser.tab.c"
    break;

  case 113: /* term: term term_choice factor  */
#line 792 "parser.y"
                                  {
            (yyval.elem) = create_node(4, "term", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        
		}
#line 2673 "parser.tab.c"
    break;

  case 114: /* term_choice: MULTIPLY  */
#line 801 "parser.y"
                            { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2681 "parser.tab.c"
    break;

  case 115: /* term_choice: ATTHERATE  */
#line 804 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2689 "parser.tab.c"
    break;

  case 116: /* term_choice: DIVIDE  */
#line 807 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2697 "parser.tab.c"
    break;

  case 117: /* term_choice: REMAINDER  */
#line 810 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2705 "parser.tab.c"
    break;

  case 118: /* term_choice: FLOOR_DIV_OPER  */
#line 813 "parser.y"
                           { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2713 "parser.tab.c"
    break;

  case 119: /* factor: factor_choice factor  */
#line 818 "parser.y"
                                    {  
            (yyval.elem) = create_node(3, "factor", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr,"", (yyvsp[0].elem)->addr);
        }
#line 2724 "parser.tab.c"
    break;

  case 120: /* factor: power  */
#line 824 "parser.y"
                    { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2732 "parser.tab.c"
    break;

  case 121: /* factor_choice: PLUS  */
#line 828 "parser.y"
                            {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2740 "parser.tab.c"
    break;

  case 122: /* factor_choice: MINUS  */
#line 831 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2748 "parser.tab.c"
    break;

  case 123: /* factor_choice: NEGATION  */
#line 834 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2756 "parser.tab.c"
    break;

  case 124: /* power: atom_expr  */
#line 838 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2764 "parser.tab.c"
    break;

  case 125: /* power: atom_expr POWER_OPERATOR factor  */
#line 841 "parser.y"
                                            { 
            (yyval.elem) = create_node(4, "power", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2775 "parser.tab.c"
    break;

  case 126: /* atom_expr: atom  */
#line 849 "parser.y"
                {  
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2783 "parser.tab.c"
    break;

  case 127: /* atom_expr: atom_expr trailer  */
#line 852 "parser.y"
                            {  
            (yyval.elem) = create_node(3, "atom_expr", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 2792 "parser.tab.c"
    break;

  case 128: /* atom_expr: atom_expr DOT NAME  */
#line 856 "parser.y"
                             { 
            (yyval.elem) = create_node(4, "atom_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 2801 "parser.tab.c"
    break;

  case 129: /* atom: OPEN_BRACKET testlist CLOSE_BRACKET  */
#line 862 "parser.y"
                                           { 
        (yyval.elem)=(yyvsp[-1].elem);
    }
#line 2809 "parser.tab.c"
    break;

  case 130: /* atom: OPEN_BRACKET CLOSE_BRACKET  */
#line 865 "parser.y"
                                    {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 2818 "parser.tab.c"
    break;

  case 131: /* atom: SQUARE_OPEN testlist SQUARE_CLOSE  */
#line 869 "parser.y"
                                           { 
        (yyval.elem) = (yyvsp[-1].elem);
    }
#line 2826 "parser.tab.c"
    break;

  case 132: /* atom: SQUARE_OPEN SQUARE_CLOSE  */
#line 872 "parser.y"
                                {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 2835 "parser.tab.c"
    break;

  case 133: /* atom: CURLY_OPEN CURLY_CLOSE  */
#line 876 "parser.y"
                                { 
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 2844 "parser.tab.c"
    break;

  case 134: /* atom: NAME  */
#line 880 "parser.y"
                {
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
     }
#line 2853 "parser.tab.c"
    break;

  case 135: /* atom: NUMBER  */
#line 884 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 2862 "parser.tab.c"
    break;

  case 136: /* atom: STRING_PLUS  */
#line 888 "parser.y"
                        { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2870 "parser.tab.c"
    break;

  case 137: /* atom: ATOM_KEYWORDS  */
#line 891 "parser.y"
                        { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 2879 "parser.tab.c"
    break;

  case 138: /* STRING_PLUS: STRING  */
#line 896 "parser.y"
                        {
            (yyval.elem) = (yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
        }
#line 2888 "parser.tab.c"
    break;

  case 139: /* STRING_PLUS: STRING STRING_PLUS  */
#line 900 "parser.y"
                                { 
            (yyval.elem) = create_node(3, "STRING_PLUS", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 2897 "parser.tab.c"
    break;

  case 140: /* trailer: OPEN_BRACKET CLOSE_BRACKET  */
#line 906 "parser.y"
                                     { 
            (yyval.elem) = create_node(3, "trailer", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 2906 "parser.tab.c"
    break;

  case 141: /* trailer: OPEN_BRACKET arglist CLOSE_BRACKET  */
#line 910 "parser.y"
                                              {
            (yyval.elem) = create_node(4, "trailer", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 2915 "parser.tab.c"
    break;

  case 142: /* trailer: SQUARE_OPEN test SQUARE_CLOSE  */
#line 914 "parser.y"
                                       {
            (yyval.elem) = create_node(4, "trailer", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 2924 "parser.tab.c"
    break;

  case 143: /* testlist: testlist_list  */
#line 920 "parser.y"
                           { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2932 "parser.tab.c"
    break;

  case 144: /* testlist: testlist_list COMMA  */
#line 923 "parser.y"
                                {
            (yyval.elem)=create_node(3,"testlist",(yyvsp[-1].elem),(yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
        }
#line 2941 "parser.tab.c"
    break;

  case 145: /* testlist_list: test  */
#line 928 "parser.y"
                            {
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2949 "parser.tab.c"
    break;

  case 146: /* testlist_list: test COLON TYPE_HINT  */
#line 931 "parser.y"
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
#line 2970 "parser.tab.c"
    break;

  case 147: /* testlist_list: testlist_list COMMA test  */
#line 947 "parser.y"
                                    { 
            (yyval.elem) = create_node(4, "testlist_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 2979 "parser.tab.c"
    break;

  case 148: /* testlist_list: testlist_list COMMA test COLON TYPE_HINT  */
#line 951 "parser.y"
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
#line 2999 "parser.tab.c"
    break;

  case 149: /* classdef: CLASS class_name COLON suite  */
#line 968 "parser.y"
                                            { 
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "CLASS", (yyvsp[-2].elem)->addr, 0, (yyvsp[-3].elem)->lineno, 1);
        }
#line 3008 "parser.tab.c"
    break;

  case 150: /* classdef: CLASS class_name OPEN_BRACKET CLOSE_BRACKET COLON suite  */
#line 972 "parser.y"
                                                                       { 
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "CLASS", (yyvsp[-4].elem)->addr, 0, (yyvsp[-5].elem)->lineno, 1);
        }
#line 3017 "parser.tab.c"
    break;

  case 151: /* classdef: CLASS class_name OPEN_BRACKET arglist CLOSE_BRACKET COLON suite  */
#line 976 "parser.y"
                                                                               { 
           current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "CLASS", (yyvsp[-5].elem)->addr, (yyvsp[-3].elem)->num_params, (yyvsp[-6].elem)->lineno, 1);
        }
#line 3026 "parser.tab.c"
    break;

  case 152: /* class_name: NAME  */
#line 982 "parser.y"
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
}
#line 3044 "parser.tab.c"
    break;

  case 153: /* arglist: argument_list  */
#line 998 "parser.y"
                           { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3052 "parser.tab.c"
    break;

  case 154: /* arglist: argument_list COMMA  */
#line 1001 "parser.y"
                                 { 
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 3060 "parser.tab.c"
    break;

  case 155: /* argument_list: argument  */
#line 1005 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;
        }
#line 3069 "parser.tab.c"
    break;

  case 156: /* argument_list: argument_list COMMA argument  */
#line 1009 "parser.y"
                                        { 
            (yyval.elem) = create_node(4, "argument_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[-2].elem)->num_params + 1;
        }
#line 3079 "parser.tab.c"
    break;

  case 157: /* argument: test  */
#line 1016 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3087 "parser.tab.c"
    break;

  case 158: /* argument: test EQUAL test  */
#line 1019 "parser.y"
                            { 
            (yyval.elem) = create_node(4, "argument", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
        }
#line 3097 "parser.tab.c"
    break;

  case 159: /* func_body_suite: simple_stmt  */
#line 1026 "parser.y"
                                { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 3105 "parser.tab.c"
    break;

  case 160: /* func_body_suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 1029 "parser.y"
                                            { 
            (yyval.elem) = (yyvsp[-1].elem);
        }
#line 3113 "parser.tab.c"
    break;

  case 161: /* func_body_suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 1032 "parser.y"
                                                    { 
            (yyval.elem) = (yyvsp[-2].elem);
        }
#line 3121 "parser.tab.c"
    break;

  case 162: /* stmt_plus: stmt  */
#line 1037 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 3129 "parser.tab.c"
    break;

  case 163: /* stmt_plus: stmt stmt_plus  */
#line 1040 "parser.y"
                            { 
            (yyval.elem)=create_node(3,"stmt_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
            (yyval.elem)->nextlist = merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist);
        }
#line 3139 "parser.tab.c"
    break;


#line 3143 "parser.tab.c"

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

#line 1046 "parser.y"


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
    curr_ste = insert_entry_same_scope(curr_ste, "RETURN", "return", "RESERVED_KEYWORD", -1, -1);\
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

 /* int get_offset(node* TYPE_HINT){
    if(TYPE_HINT->addr == "int"){
        return 4;
    }
    else if(TYPE_HINT->addr == "float"){
        return 8;
    }
    else if(TYPE_HINT->addr == "bool"){
        return 1;
    }
    else if(TYPE_HINT->addr == "None"){
        return 0;
    } 
    else if(TYPE_HINT->addr == "str"){
        
    }
} */



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
