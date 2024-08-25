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

#line 140 "parser.tab.c"

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
  YYSYMBOL_A = 67,                         /* A  */
  YYSYMBOL_C = 68,                         /* C  */
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
  YYSYMBOL_while_stmt = 87,                /* while_stmt  */
  YYSYMBOL_for_stmt = 88,                  /* for_stmt  */
  YYSYMBOL_range_stmt = 89,                /* range_stmt  */
  YYSYMBOL_suite = 90,                     /* suite  */
  YYSYMBOL_nts_star = 91,                  /* nts_star  */
  YYSYMBOL_test = 92,                      /* test  */
  YYSYMBOL_or_test = 93,                   /* or_test  */
  YYSYMBOL_and_test_star = 94,             /* and_test_star  */
  YYSYMBOL_and_test = 95,                  /* and_test  */
  YYSYMBOL_not_test_star = 96,             /* not_test_star  */
  YYSYMBOL_not_test = 97,                  /* not_test  */
  YYSYMBOL_comparison = 98,                /* comparison  */
  YYSYMBOL_comp_op = 99,                   /* comp_op  */
  YYSYMBOL_expr = 100,                     /* expr  */
  YYSYMBOL_xor_expr = 101,                 /* xor_expr  */
  YYSYMBOL_and_expr = 102,                 /* and_expr  */
  YYSYMBOL_shift_expr = 103,               /* shift_expr  */
  YYSYMBOL_arith_expr = 104,               /* arith_expr  */
  YYSYMBOL_term = 105,                     /* term  */
  YYSYMBOL_term_choice = 106,              /* term_choice  */
  YYSYMBOL_factor = 107,                   /* factor  */
  YYSYMBOL_factor_choice = 108,            /* factor_choice  */
  YYSYMBOL_power = 109,                    /* power  */
  YYSYMBOL_atom_expr = 110,                /* atom_expr  */
  YYSYMBOL_atom = 111,                     /* atom  */
  YYSYMBOL_STRING_PLUS = 112,              /* STRING_PLUS  */
  YYSYMBOL_trailer = 113,                  /* trailer  */
  YYSYMBOL_testlist = 114,                 /* testlist  */
  YYSYMBOL_testlist_list = 115,            /* testlist_list  */
  YYSYMBOL_classdef = 116,                 /* classdef  */
  YYSYMBOL_X = 117,                        /* X  */
  YYSYMBOL_arglist = 118,                  /* arglist  */
  YYSYMBOL_argument_list = 119,            /* argument_list  */
  YYSYMBOL_argument = 120,                 /* argument  */
  YYSYMBOL_func_body_suite = 121,          /* func_body_suite  */
  YYSYMBOL_stmt_plus = 122                 /* stmt_plus  */
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
#define YYLAST   435

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

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
       0,    84,    84,    90,    97,   102,   106,   109,   112,   118,
     122,   126,   130,   136,   151,   157,   164,   168,   176,   179,
     186,   190,   208,   211,   216,   219,   224,   227,   233,   236,
     239,   255,   260,   277,   280,   285,   327,   330,   338,   341,
     344,   349,   354,   358,   361,   366,   370,   376,   380,   385,
     388,   391,   394,   397,   402,   408,   415,   423,   431,   441,
     446,   451,   452,   455,   458,   461,   466,   472,   479,   488,
     494,   497,   505,   512,   517,   520,   528,   535,   540,   546,
     551,   554,   566,   569,   572,   575,   578,   581,   584,   587,
     590,   593,   596,   601,   604,   612,   615,   623,   627,   635,
     638,   646,   649,   655,   662,   665,   674,   677,   680,   683,
     686,   691,   697,   701,   704,   707,   711,   714,   722,   725,
     729,   735,   738,   742,   745,   749,   753,   773,   777,   780,
     789,   793,   799,   803,   807,   813,   816,   821,   824,   840,
     844,   861,   865,   869,   875,   891,   894,   898,   902,   909,
     912,   919,   922,   925,   930,   933
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
  "snippet", "funcdef", "A", "C", "parameters", "typedargslist",
  "typedarg", "tfpdef", "stmt", "simple_stmt", "small_stmt_list",
  "small_stmt", "expr_stmt", "eq_testlist_star_expr_plus", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "global_stmt",
  "comma_name_star", "compound_stmt", "if_stmt", "while_stmt", "for_stmt",
  "range_stmt", "suite", "nts_star", "test", "or_test", "and_test_star",
  "and_test", "not_test_star", "not_test", "comparison", "comp_op", "expr",
  "xor_expr", "and_expr", "shift_expr", "arith_expr", "term",
  "term_choice", "factor", "factor_choice", "power", "atom_expr", "atom",
  "STRING_PLUS", "trailer", "testlist", "testlist_list", "classdef", "X",
  "arglist", "argument_list", "argument", "func_body_suite", "stmt_plus", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-203)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-78)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     114,   114,  -203,   384,  -203,   271,   384,  -203,  -203,   384,
      59,    68,    76,  -203,    25,  -203,    55,  -203,  -203,  -203,
      47,   275,   102,  -203,  -203,   114,  -203,    31,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,    83,
    -203,   112,   126,    72,   115,  -203,   236,   103,   101,   105,
      71,    81,  -203,   271,  -203,    22,  -203,  -203,  -203,   117,
    -203,  -203,   119,   384,   132,  -203,  -203,  -203,   -13,  -203,
     124,   122,  -203,  -203,   125,   127,  -203,  -203,   118,  -203,
    -203,  -203,    20,   384,   384,   150,  -203,  -203,  -203,   145,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,   144,   271,   271,
     271,   271,   271,   271,   271,  -203,  -203,  -203,  -203,  -203,
     271,  -203,   271,   338,   156,   384,  -203,   384,  -203,   135,
     170,   361,   189,    -2,    10,   164,  -203,   166,  -203,  -203,
    -203,  -203,  -203,  -203,   148,     5,   384,   384,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,    81,    81,  -203,  -203,  -203,
     149,   151,   152,  -203,  -203,   133,   154,   189,  -203,   155,
     159,   161,   165,   183,  -203,  -203,   163,    21,    41,  -203,
     158,   188,   222,   122,  -203,   384,   384,   384,   180,   184,
     384,  -203,   384,  -203,   191,     1,   189,   384,   189,   189,
     169,   315,   194,   188,   222,  -203,   195,   384,  -203,   171,
     204,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
      11,   200,    42,   207,  -203,   189,   315,    92,  -203,   174,
    -203,  -203,  -203,   222,   315,   196,   384,  -203,   215,  -203,
     384,   198,  -203,  -203,   225,  -203,   222,  -203,    99,  -203,
     201,   203,   208,   189,  -203,  -203,   237,  -203,   189,  -203,
    -203,  -203,  -203,  -203,  -203,   189,   189,     1,  -203,   110,
     206,  -203,  -203,   189,  -203
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,   126,     0,     2,     0,     0,    41,    42,    43,
       0,     0,     0,   129,   130,   127,     0,   113,   114,   115,
       0,     0,     0,     4,    52,     6,    22,     0,    26,    28,
      29,    38,    39,    40,    30,    23,    49,    50,    51,   137,
      69,     0,    70,     0,    74,    79,    80,    93,    95,    97,
      99,   101,   104,     0,   112,   116,   118,   128,    33,   135,
      53,     7,     0,     0,     0,    78,    44,   144,     0,    13,
       0,    45,   131,   122,   137,     0,   125,   124,     0,     1,
       8,    25,     0,     0,     0,     0,     2,     2,    89,     0,
      82,    83,    84,    85,    86,    87,    88,    91,     0,     0,
       0,     0,     0,     0,     0,   110,   106,   108,   109,   107,
       0,   111,     0,     0,     0,     0,   119,   136,     2,     0,
       0,     0,     0,     0,     0,     0,    46,     0,   121,   123,
      24,    27,    31,    34,    36,   138,     0,     0,    90,    92,
      81,    94,    96,    98,   100,   102,   103,   105,   117,   132,
     149,     0,   145,   147,   120,     0,   139,     0,     2,     0,
       0,     0,     0,     0,    63,   141,    20,     0,     0,    16,
      18,     0,     0,    47,   138,     0,     0,     0,    71,    75,
       0,   133,   146,   134,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,    14,     0,
       0,   151,     9,    48,    37,    32,    35,   150,   148,   140,
       0,    57,     0,    59,   142,     0,   154,     0,    21,     0,
      11,    17,    19,     0,     0,     0,     0,    56,     0,    61,
       0,     0,   143,   155,     0,    64,     0,    10,     0,     2,
       0,     0,     0,     0,    65,    12,     0,   152,     0,     2,
       2,    62,    60,   153,    55,     0,     0,    66,    58,     0,
       0,    67,     2,     0,    68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,   -82,  -201,  -203,    12,  -203,  -203,    56,  -203,  -203,
      52,  -203,  -163,     0,  -203,   175,  -203,   -64,  -203,  -203,
    -203,  -203,  -203,    86,  -203,  -203,  -203,  -203,  -203,  -148,
       3,    -1,  -203,  -203,   120,  -203,    -3,   167,  -203,     2,
     168,   162,   172,  -203,    26,  -203,   -47,  -203,  -203,  -203,
    -203,   250,  -203,    13,  -203,  -203,  -203,   146,  -203,    87,
    -176,  -202
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    63,   210,    22,    23,    24,    70,   199,   124,   168,
     169,   170,    25,   164,    27,    28,    29,   133,    30,    31,
      32,    33,    34,   126,    35,    36,    37,    38,   160,   165,
     227,    39,    40,    41,    42,    43,    44,    45,    98,    46,
      47,    48,    49,    50,    51,   110,    52,    53,    54,    55,
      56,    57,   116,    58,    59,    60,    68,   151,   152,   153,
     202,   217
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,    26,    62,    65,   136,   137,   111,    64,    66,   185,
     228,   166,   176,    61,   233,    74,    -3,    -3,   220,   121,
      74,   171,   238,   122,   130,    26,   225,   226,   216,    75,
     112,   167,   193,     2,    78,    81,   157,    80,   211,   177,
     213,   214,     6,     7,     8,     9,   172,   237,    12,    13,
      14,    15,    16,   216,   113,    14,   259,   194,    17,    18,
     245,   216,   119,   147,    19,   148,    82,   232,     2,    20,
     114,    21,    67,   115,   195,   229,   186,     6,   196,   230,
     102,    69,   132,   134,    13,    14,    15,    16,    73,    71,
      83,   105,    87,    17,    18,   252,   234,    76,   235,    19,
     254,   141,    79,   246,    20,   247,    21,   257,   258,   103,
     104,   204,   150,   206,   155,   264,   156,    84,     1,    85,
     150,   106,   107,   108,   109,   260,   226,     2,     3,   145,
     146,     4,     5,    86,   179,   -77,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   -73,   100,    99,
     101,   120,    17,    18,   117,   118,   123,   248,    19,   125,
     128,   127,   135,    20,   138,    21,   139,   255,   256,   154,
     129,   158,   201,   159,   134,   205,   134,   173,   174,   207,
     263,   150,   175,   180,   181,   183,   212,   187,   191,   182,
     184,    26,   197,   163,   201,   188,   222,   189,   190,   192,
     198,   -72,     2,   209,   -76,   215,   218,   223,   166,   224,
     236,     6,     7,     8,     9,    -3,    26,    12,    13,    14,
      15,    16,   231,   201,    26,   240,   200,    17,    18,   242,
     241,   244,   239,    19,   243,     2,   201,   249,    20,   250,
      21,   251,   262,   253,     6,     7,     8,     9,   221,   219,
      12,    13,    14,    15,    16,    88,   178,   131,    89,   203,
      17,    18,   261,   143,    72,   140,    19,   162,   142,   208,
       0,    20,     0,    21,   144,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     2,    90,
      91,    92,    93,    94,    95,    96,    97,     6,     0,     0,
      13,    14,    15,    16,    13,    14,    15,    16,     0,    17,
      18,     0,     0,    17,    18,    19,     0,     0,     0,    19,
      20,     0,    21,     0,    20,     0,    21,    77,     2,     3,
       0,     0,     4,     5,     0,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     2,     0,    17,    18,     0,     0,     0,     0,    19,
       6,     0,     0,     0,    20,     0,    21,    13,    14,    15,
      16,   149,     0,     0,     2,     0,    17,    18,     0,     0,
       0,     0,    19,     6,     0,     0,     0,    20,     0,    21,
      13,    14,    15,    16,   161,     0,     0,     2,     0,    17,
      18,     0,     0,     0,     0,    19,     6,     0,     0,     0,
      20,     0,    21,    13,    14,    15,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    20,     0,    21
};

static const yytype_int16 yycheck[] =
{
       0,     1,     3,     6,    86,    87,    53,     5,     9,   157,
     211,    13,     7,     1,   216,    16,    15,    16,   194,    32,
      21,    11,   224,    36,     4,    25,    15,    16,   191,    16,
       8,    33,    11,    13,    21,     4,   118,    25,   186,    34,
     188,   189,    22,    23,    24,    25,    36,   223,    28,    29,
      30,    31,    32,   216,    32,    30,   257,    36,    38,    39,
     236,   224,    63,   110,    44,   112,    35,   215,    13,    49,
      48,    51,    13,    51,    33,    33,   158,    22,    37,    37,
       9,    13,    83,    84,    29,    30,    31,    32,    33,    13,
       7,    10,    20,    38,    39,   243,     4,    50,     6,    44,
     248,    99,     0,     4,    49,     6,    51,   255,   256,    38,
      39,   175,   113,   177,   115,   263,   117,    34,     4,    36,
     121,    40,    41,    42,    43,    15,    16,    13,    14,   103,
     104,    17,    18,    21,   137,    20,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    21,    47,    46,
      45,    19,    38,    39,    37,    36,    32,   239,    44,    37,
      33,    36,    12,    49,    19,    51,    22,   249,   250,    13,
      52,    36,   172,     3,   175,   176,   177,    13,    12,   180,
     262,   182,    34,    34,    33,    52,   187,    32,     5,    37,
      36,   191,    34,     4,   194,    36,   197,    36,    33,    36,
      12,    21,    13,    12,    20,    36,    12,    36,    13,     5,
      36,    22,    23,    24,    25,    15,   216,    28,    29,    30,
      31,    32,    15,   223,   224,   226,     4,    38,    39,   230,
      15,     6,    36,    44,    36,    13,   236,    36,    49,    36,
      51,    33,    36,     6,    22,    23,    24,    25,   196,   193,
      28,    29,    30,    31,    32,    19,   136,    82,    22,   173,
      38,    39,   259,   101,    14,    98,    44,   121,   100,   182,
      -1,    49,    -1,    51,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    13,    53,
      54,    55,    56,    57,    58,    59,    60,    22,    -1,    -1,
      29,    30,    31,    32,    29,    30,    31,    32,    -1,    38,
      39,    -1,    -1,    38,    39,    44,    -1,    -1,    -1,    44,
      49,    -1,    51,    -1,    49,    -1,    51,    52,    13,    14,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    13,    -1,    38,    39,    -1,    -1,    -1,    -1,    44,
      22,    -1,    -1,    -1,    49,    -1,    51,    29,    30,    31,
      32,    33,    -1,    -1,    13,    -1,    38,    39,    -1,    -1,
      -1,    -1,    44,    22,    -1,    -1,    -1,    49,    -1,    51,
      29,    30,    31,    32,    33,    -1,    -1,    13,    -1,    38,
      39,    -1,    -1,    -1,    -1,    44,    22,    -1,    -1,    -1,
      49,    -1,    51,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    49,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    13,    14,    17,    18,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    38,    39,    44,
      49,    51,    64,    65,    66,    73,    74,    75,    76,    77,
      79,    80,    81,    82,    83,    85,    86,    87,    88,    92,
      93,    94,    95,    96,    97,    98,   100,   101,   102,   103,
     104,   105,   107,   108,   109,   110,   111,   112,   114,   115,
     116,    65,    92,    62,   100,    97,    92,    13,   117,    13,
      67,    13,   112,    33,    92,   114,    50,    52,   114,     0,
      65,     4,    35,     7,    34,    36,    21,    20,    19,    22,
      53,    54,    55,    56,    57,    58,    59,    60,    99,    46,
      47,    45,     9,    38,    39,    10,    40,    41,    42,    43,
     106,   107,     8,    32,    48,    51,   113,    37,    36,    92,
      19,    32,    36,    32,    69,    37,    84,    36,    33,    52,
       4,    76,    92,    78,    92,    12,    62,    62,    19,    22,
      98,   100,   101,   102,   103,   105,   105,   107,   107,    33,
      92,   118,   119,   120,    13,    92,    92,    62,    36,     3,
      89,    33,   118,     4,    74,    90,    13,    33,    70,    71,
      72,    11,    36,    13,    12,    34,     7,    34,    95,    97,
      34,    33,    37,    52,    36,    90,    62,    32,    36,    36,
      33,     5,    36,    11,    36,    33,    37,    34,    12,    68,
       4,    74,   121,    84,    78,    92,    78,    92,   120,    12,
      63,    90,    92,    90,    90,    36,    73,   122,    12,    68,
     121,    71,    92,    36,     5,    15,    16,    91,    63,    33,
      37,    15,    90,   122,     4,     6,    36,   121,   122,    36,
      92,    15,    92,    36,     6,   121,     4,     6,    62,    36,
      36,    33,    90,     6,    90,    62,    62,    90,    90,    63,
      15,    91,    36,    62,    90
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    64,    65,    65,    65,    65,    66,
      66,    66,    66,    67,    68,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    77,    77,    77,    78,    78,    79,    79,
      79,    80,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    86,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    90,    91,    91,    91,    92,
      93,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   104,   105,   105,   106,   106,   106,   106,
     106,   107,   107,   108,   108,   108,   109,   109,   110,   110,
     110,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   112,   113,   113,   113,   114,   114,   115,   115,   115,
     115,   116,   116,   116,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   121,   122,   122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     2,     2,     5,
       7,     6,     8,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     3,     2,     1,     3,     1,     1,
       1,     3,     5,     1,     3,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     2,     3,     1,
       1,     1,     1,     1,     5,    10,     7,     6,    11,     6,
       9,     4,     6,     1,     4,     5,     5,     7,    10,     1,
       1,     4,     4,     1,     1,     4,     4,     1,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     2,
       3,     3,     2,     3,     2,     2,     1,     1,     1,     1,
       1,     2,     2,     3,     3,     1,     2,     1,     3,     3,
       5,     4,     6,     7,     1,     1,     2,     1,     3,     1,
       3,     1,     4,     5,     1,     2
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
#line 84 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal M");
        (yyval.elem)->ins = instCount+1;
}
#line 1485 "parser.tab.c"
    break;

  case 3: /* N: %empty  */
#line 90 "parser.y"
         {
        (yyval.elem) = create_node(1, "Marker Non-terminal N");
        (yyval.elem)->nextlist = makelist(instCount+1);
        create_ins(0, "goto", "", "", "");
}
#line 1495 "parser.tab.c"
    break;

  case 4: /* file: snippet  */
#line 97 "parser.y"
              {
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 1503 "parser.tab.c"
    break;

  case 5: /* snippet: NEWLINE  */
#line 102 "parser.y"
                 {
       (yyval.elem)=(yyvsp[0].elem);
	   (yyval.elem)->ins = instCount+1;
    }
#line 1512 "parser.tab.c"
    break;

  case 6: /* snippet: stmt  */
#line 106 "parser.y"
            { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1520 "parser.tab.c"
    break;

  case 7: /* snippet: NEWLINE snippet  */
#line 109 "parser.y"
                       { 
        (yyval.elem)=(yyvsp[0].elem);
    }
#line 1528 "parser.tab.c"
    break;

  case 8: /* snippet: stmt snippet  */
#line 112 "parser.y"
                   {  
        (yyval.elem) = create_node(3, "snippet", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
    }
#line 1537 "parser.tab.c"
    break;

  case 9: /* funcdef: DEF A parameters COLON func_body_suite  */
#line 118 "parser.y"
                                                {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-3].elem)->addr, (yyvsp[-1].elem)->num_params, (yyvsp[-4].elem)->lineno, 1);
        }
#line 1546 "parser.tab.c"
    break;

  case 10: /* funcdef: DEF A parameters ARROW_OPER C COLON func_body_suite  */
#line 122 "parser.y"
                                                              {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-5].elem)->addr, (yyvsp[-3].elem)->num_params, (yyvsp[-6].elem)->lineno, 1);
        }
#line 1555 "parser.tab.c"
    break;

  case 11: /* funcdef: DEF A OPEN_BRACKET CLOSE_BRACKET COLON func_body_suite  */
#line 126 "parser.y"
                                                                 {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-4].elem)->addr, 0, (yyvsp[-5].elem)->lineno, 1);
        }
#line 1564 "parser.tab.c"
    break;

  case 12: /* funcdef: DEF A OPEN_BRACKET CLOSE_BRACKET ARROW_OPER C COLON func_body_suite  */
#line 130 "parser.y"
                                                                             {
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "FUNCTION", (yyvsp[-6].elem)->addr, 0, (yyvsp[-7].elem)->lineno, 1);
        }
#line 1573 "parser.tab.c"
    break;

  case 13: /* A: NAME  */
#line 137 "parser.y"
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
#line 1591 "parser.tab.c"
    break;

  case 14: /* C: TYPE_HINT  */
#line 151 "parser.y"
            {
        (yyval.elem)=(yyvsp[0].elem);
        get_prev_scope(current_ste)->return_type = (yyvsp[0].elem)->addr;
    }
#line 1600 "parser.tab.c"
    break;

  case 15: /* parameters: OPEN_BRACKET typedargslist CLOSE_BRACKET  */
#line 157 "parser.y"
                                                     {  
            (yyval.elem) = create_node(4, "parameters", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[-1].elem)->num_params;
        }
#line 1610 "parser.tab.c"
    break;

  case 16: /* typedargslist: typedarg  */
#line 164 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;
        }
#line 1619 "parser.tab.c"
    break;

  case 17: /* typedargslist: typedargslist COMMA typedarg  */
#line 168 "parser.y"
                                         {  
            (yyval.elem) = create_node(4, "typedargslist", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;

            (yyval.elem)->num_params = (yyvsp[-2].elem)->num_params + 1;
        }
#line 1630 "parser.tab.c"
    break;

  case 18: /* typedarg: tfpdef  */
#line 176 "parser.y"
                   {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1638 "parser.tab.c"
    break;

  case 19: /* typedarg: tfpdef EQUAL test  */
#line 179 "parser.y"
                            {  
            (yyval.elem) = create_node(4, "typedarg", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");    //is this instruction needed?????
        }
#line 1648 "parser.tab.c"
    break;

  case 20: /* tfpdef: NAME  */
#line 186 "parser.y"
             {  
            (yyval.elem)=(yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
        }
#line 1657 "parser.tab.c"
    break;

  case 21: /* tfpdef: NAME COLON TYPE_HINT  */
#line 190 "parser.y"
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
#line 1678 "parser.tab.c"
    break;

  case 22: /* stmt: simple_stmt  */
#line 208 "parser.y"
                        { 
        	(yyval.elem)=(yyvsp[0].elem);
        }
#line 1686 "parser.tab.c"
    break;

  case 23: /* stmt: compound_stmt  */
#line 211 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem); 
        }
#line 1694 "parser.tab.c"
    break;

  case 24: /* simple_stmt: small_stmt_list SEMI_COLON NEWLINE  */
#line 216 "parser.y"
                                                {  
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 1702 "parser.tab.c"
    break;

  case 25: /* simple_stmt: small_stmt_list NEWLINE  */
#line 219 "parser.y"
                                   {  
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 1710 "parser.tab.c"
    break;

  case 26: /* small_stmt_list: small_stmt  */
#line 224 "parser.y"
                                {   
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1718 "parser.tab.c"
    break;

  case 27: /* small_stmt_list: small_stmt_list SEMI_COLON small_stmt  */
#line 227 "parser.y"
                                                     {  
           (yyval.elem) = create_node(3, "small_stmt_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
		   (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 1727 "parser.tab.c"
    break;

  case 28: /* small_stmt: expr_stmt  */
#line 233 "parser.y"
                            {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1735 "parser.tab.c"
    break;

  case 29: /* small_stmt: flow_stmt  */
#line 236 "parser.y"
                        {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1743 "parser.tab.c"
    break;

  case 30: /* small_stmt: global_stmt  */
#line 239 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1751 "parser.tab.c"
    break;

  case 31: /* expr_stmt: test ASSIGN_OPERATOR test  */
#line 255 "parser.y"
                                  { 
            (yyval.elem) = create_node(4, "expr_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            // Here add instruction 
        }
#line 1761 "parser.tab.c"
    break;

  case 32: /* expr_stmt: test COLON TYPE_HINT ASSIGN_OPERATOR test  */
#line 260 "parser.y"
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
#line 1783 "parser.tab.c"
    break;

  case 33: /* expr_stmt: testlist  */
#line 277 "parser.y"
                   {
			(yyval.elem)=(yyvsp[0].elem);
        }
#line 1791 "parser.tab.c"
    break;

  case 34: /* expr_stmt: test EQUAL eq_testlist_star_expr_plus  */
#line 280 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-2].elem)->ins;
			create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, ""); 
        }
#line 1801 "parser.tab.c"
    break;

  case 35: /* expr_stmt: test COLON TYPE_HINT EQUAL eq_testlist_star_expr_plus  */
#line 285 "parser.y"
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
#line 1821 "parser.tab.c"
    break;

  case 36: /* eq_testlist_star_expr_plus: test  */
#line 327 "parser.y"
                                 {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1829 "parser.tab.c"
    break;

  case 37: /* eq_testlist_star_expr_plus: test EQUAL eq_testlist_star_expr_plus  */
#line 330 "parser.y"
                                               {
            (yyval.elem) = create_node(4, "eq_testlist_star_expr_plus", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
            (yyval.elem)->addr = (yyvsp[-2].elem)->addr;    //x=y=z
        }
#line 1840 "parser.tab.c"
    break;

  case 38: /* flow_stmt: break_stmt  */
#line 338 "parser.y"
                        {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1848 "parser.tab.c"
    break;

  case 39: /* flow_stmt: continue_stmt  */
#line 341 "parser.y"
                            {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1856 "parser.tab.c"
    break;

  case 40: /* flow_stmt: return_stmt  */
#line 344 "parser.y"
                         {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1864 "parser.tab.c"
    break;

  case 41: /* break_stmt: BREAK  */
#line 349 "parser.y"
                    {  
            
            
        }
#line 1873 "parser.tab.c"
    break;

  case 42: /* continue_stmt: CONTINUE  */
#line 354 "parser.y"
                            {  
            
        }
#line 1881 "parser.tab.c"
    break;

  case 43: /* return_stmt: RETURN  */
#line 358 "parser.y"
                        {  
            
        }
#line 1889 "parser.tab.c"
    break;

  case 44: /* return_stmt: RETURN test  */
#line 361 "parser.y"
                          {  
            
        }
#line 1897 "parser.tab.c"
    break;

  case 45: /* global_stmt: GLOBAL NAME  */
#line 366 "parser.y"
                           {  
            (yyval.elem) = create_node(3, "global_stmt", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 1906 "parser.tab.c"
    break;

  case 46: /* global_stmt: GLOBAL NAME comma_name_star  */
#line 370 "parser.y"
                                      {   
            (yyval.elem) = create_node(4, "global_stmt", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 1915 "parser.tab.c"
    break;

  case 47: /* comma_name_star: COMMA NAME  */
#line 376 "parser.y"
                               {  
            (yyval.elem) = create_node(3, "comma_name_star", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 1924 "parser.tab.c"
    break;

  case 48: /* comma_name_star: COMMA NAME comma_name_star  */
#line 380 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "comma_name_star", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 1933 "parser.tab.c"
    break;

  case 49: /* compound_stmt: if_stmt  */
#line 385 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);  
        }
#line 1941 "parser.tab.c"
    break;

  case 50: /* compound_stmt: while_stmt  */
#line 388 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1949 "parser.tab.c"
    break;

  case 51: /* compound_stmt: for_stmt  */
#line 391 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1957 "parser.tab.c"
    break;

  case 52: /* compound_stmt: funcdef  */
#line 394 "parser.y"
                       {  
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 1965 "parser.tab.c"
    break;

  case 53: /* compound_stmt: classdef  */
#line 397 "parser.y"
                       {  
           (yyval.elem)=(yyvsp[0].elem);
        }
#line 1973 "parser.tab.c"
    break;

  case 54: /* if_stmt: IF test COLON M suite  */
#line 402 "parser.y"
                                   {  
           (yyval.elem)=create_node(6, "if_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
           (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
           backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
           (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);
        }
#line 1984 "parser.tab.c"
    break;

  case 55: /* if_stmt: IF test COLON M suite N ELSE COLON M suite  */
#line 408 "parser.y"
                                                       {  
            (yyval.elem) = create_node(11, "if_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            vector<int> temp = merge((yyvsp[-5].elem)->nextlist, (yyvsp[-4].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);
        }
#line 1996 "parser.tab.c"
    break;

  case 56: /* if_stmt: IF test COLON M suite N nts_star  */
#line 415 "parser.y"
                                              {  
            (yyval.elem) = create_node(8, "if_elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);     
            vector<int> temp = merge((yyvsp[-2].elem)->nextlist, (yyvsp[-1].elem)->nextlist);
            (yyval.elem)->nextlist = merge(temp, (yyvsp[0].elem)->nextlist);
        }
#line 2008 "parser.tab.c"
    break;

  case 57: /* while_stmt: WHILE M test COLON M suite  */
#line 423 "parser.y"
                                         {  
            (yyval.elem) = create_node(7, "while_stmt", (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-4].elem)->ins;
            backpatch((yyvsp[0].elem)->nextlist, (yyvsp[-4].elem)->ins);
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = (yyvsp[-3].elem)->falselist;
            create_ins(0, "goto", to_string((yyvsp[-4].elem)->ins), "", "");
        }
#line 2021 "parser.tab.c"
    break;

  case 58: /* while_stmt: WHILE M test COLON M suite N ELSE COLON M suite  */
#line 431 "parser.y"
                                                                   {   
			(yyval.elem) = create_node(12, "while_else_stmt", (yyvsp[-10].elem), (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-9].elem)->ins;
			backpatch((yyvsp[-4].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-5].elem)->nextlist, (yyvsp[-9].elem)->ins);
			backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
			backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
			(yyval.elem)->nextlist = merge((yyvsp[-4].elem)->nextlist, (yyvsp[0].elem)->nextlist); //verify
        }
#line 2035 "parser.tab.c"
    break;

  case 59: /* for_stmt: FOR expr IN range_stmt COLON suite  */
#line 441 "parser.y"
                                                { 
            // $$ = create_node(7, "for_stmt", $1, $2, $3, $4, $5, $6);
            // $$->ins = $2->ins;

        }
#line 2045 "parser.tab.c"
    break;

  case 60: /* for_stmt: FOR expr IN range_stmt COLON suite ELSE COLON suite  */
#line 446 "parser.y"
                                                                { 
            
        }
#line 2053 "parser.tab.c"
    break;

  case 63: /* suite: simple_stmt  */
#line 455 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2061 "parser.tab.c"
    break;

  case 64: /* suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 458 "parser.y"
                                            {
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 2069 "parser.tab.c"
    break;

  case 65: /* suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 461 "parser.y"
                                                    { 
            (yyval.elem)=(yyvsp[-2].elem);
        }
#line 2077 "parser.tab.c"
    break;

  case 66: /* nts_star: ELIF test COLON M suite  */
#line 466 "parser.y"
                                    {  
            (yyval.elem)=create_node(6, "elif_stmt", (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->nextlist);
        }
#line 2088 "parser.tab.c"
    break;

  case 67: /* nts_star: ELIF test COLON M suite N nts_star  */
#line 472 "parser.y"
                                              {  
            (yyval.elem) = create_node(8, "elif_stmt", (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-5].elem)->ins;
            backpatch((yyvsp[-5].elem)->truelist, (yyvsp[-3].elem)->ins);
            backpatch((yyvsp[-5].elem)->falselist, (yyvsp[0].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-2].elem)->nextlist, merge((yyvsp[-1].elem)->nextlist, (yyvsp[0].elem)->nextlist));
        }
#line 2100 "parser.tab.c"
    break;

  case 68: /* nts_star: ELIF test COLON M suite N ELSE COLON M suite  */
#line 479 "parser.y"
                                                        {  
            (yyval.elem) = create_node(11, "elif_else_stmt", (yyvsp[-9].elem), (yyvsp[-8].elem), (yyvsp[-7].elem), (yyvsp[-6].elem), (yyvsp[-5].elem), (yyvsp[-4].elem), (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-8].elem)->ins;
            backpatch((yyvsp[-8].elem)->truelist, (yyvsp[-6].elem)->ins);
            backpatch((yyvsp[-8].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->nextlist = merge((yyvsp[-5].elem)->nextlist, merge((yyvsp[-4].elem)->nextlist,(yyvsp[0].elem)->nextlist));
        }
#line 2112 "parser.tab.c"
    break;

  case 69: /* test: or_test  */
#line 488 "parser.y"
                { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2120 "parser.tab.c"
    break;

  case 70: /* or_test: and_test  */
#line 494 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2128 "parser.tab.c"
    break;

  case 71: /* or_test: and_test_star OR M and_test  */
#line 497 "parser.y"
                                         {  
            (yyval.elem) = create_node(5, "or_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;
        }
#line 2140 "parser.tab.c"
    break;

  case 72: /* and_test_star: and_test_star OR M and_test  */
#line 505 "parser.y"
                                            {
            (yyval.elem) = create_node(5, "and_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->falselist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->truelist = merge((yyvsp[-3].elem)->truelist, (yyvsp[0].elem)->truelist);
            (yyval.elem)->falselist = (yyvsp[0].elem)->falselist;
        }
#line 2152 "parser.tab.c"
    break;

  case 73: /* and_test_star: and_test  */
#line 512 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2160 "parser.tab.c"
    break;

  case 74: /* and_test: not_test  */
#line 517 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2168 "parser.tab.c"
    break;

  case 75: /* and_test: not_test_star AND M not_test  */
#line 520 "parser.y"
                                          {  
            (yyval.elem) = create_node(5, "and_test", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;
        }
#line 2180 "parser.tab.c"
    break;

  case 76: /* not_test_star: not_test_star AND M not_test  */
#line 528 "parser.y"
                                              { 
            (yyval.elem) = create_node(5, "not_test_star", (yyvsp[-3].elem), (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-3].elem)->ins;
            backpatch((yyvsp[-3].elem)->truelist, (yyvsp[-1].elem)->ins);
            (yyval.elem)->falselist = merge((yyvsp[-3].elem)->falselist, (yyvsp[0].elem)->falselist);
            (yyval.elem)->truelist = (yyvsp[0].elem)->truelist;
        }
#line 2192 "parser.tab.c"
    break;

  case 77: /* not_test_star: not_test  */
#line 535 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2200 "parser.tab.c"
    break;

  case 78: /* not_test: NOT not_test  */
#line 540 "parser.y"
                         { 
            (yyval.elem) = create_node(3, "not_test", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
            (yyval.elem)->truelist = (yyvsp[0].elem)->falselist;
            (yyval.elem)->falselist = (yyvsp[0].elem)->truelist;
        }
#line 2211 "parser.tab.c"
    break;

  case 79: /* not_test: comparison  */
#line 546 "parser.y"
                        { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2219 "parser.tab.c"
    break;

  case 80: /* comparison: expr  */
#line 551 "parser.y"
                  {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2227 "parser.tab.c"
    break;

  case 81: /* comparison: expr comp_op comparison  */
#line 554 "parser.y"
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
#line 2242 "parser.tab.c"
    break;

  case 82: /* comp_op: LESS_THAN  */
#line 566 "parser.y"
                    {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2250 "parser.tab.c"
    break;

  case 83: /* comp_op: GREATER_THAN  */
#line 569 "parser.y"
                    { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2258 "parser.tab.c"
    break;

  case 84: /* comp_op: EQUAL_EQUAL  */
#line 572 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2266 "parser.tab.c"
    break;

  case 85: /* comp_op: GREATER_THAN_EQUAL  */
#line 575 "parser.y"
                            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2274 "parser.tab.c"
    break;

  case 86: /* comp_op: LESS_THAN_EQUAL  */
#line 578 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2282 "parser.tab.c"
    break;

  case 87: /* comp_op: NOT_EQUAL_ARROW  */
#line 581 "parser.y"
                        {
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2290 "parser.tab.c"
    break;

  case 88: /* comp_op: NOT_EQUAL  */
#line 584 "parser.y"
                   {
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2298 "parser.tab.c"
    break;

  case 89: /* comp_op: IN  */
#line 587 "parser.y"
            {  
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2306 "parser.tab.c"
    break;

  case 90: /* comp_op: NOT IN  */
#line 590 "parser.y"
                { 
        (yyval.elem) = create_node(3, "NOT IN", (yyvsp[-1].elem), (yyvsp[0].elem));
    }
#line 2314 "parser.tab.c"
    break;

  case 91: /* comp_op: IS  */
#line 593 "parser.y"
            { 
        (yyval.elem) = (yyvsp[0].elem);
    }
#line 2322 "parser.tab.c"
    break;

  case 92: /* comp_op: IS NOT  */
#line 596 "parser.y"
                { 
        (yyval.elem) = create_node(3, "IS NOT", (yyvsp[-1].elem), (yyvsp[0].elem));
    }
#line 2330 "parser.tab.c"
    break;

  case 93: /* expr: xor_expr  */
#line 601 "parser.y"
                  { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2338 "parser.tab.c"
    break;

  case 94: /* expr: xor_expr BIT_OR expr  */
#line 604 "parser.y"
                                  {  
            (yyval.elem) = create_node(4, "expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2349 "parser.tab.c"
    break;

  case 95: /* xor_expr: and_expr  */
#line 612 "parser.y"
                   { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2357 "parser.tab.c"
    break;

  case 96: /* xor_expr: and_expr BIT_XOR xor_expr  */
#line 615 "parser.y"
                                       {  
            (yyval.elem) = create_node(4, "xor_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2368 "parser.tab.c"
    break;

  case 97: /* and_expr: shift_expr  */
#line 623 "parser.y"
                       { 
            (yyval.elem) = (yyvsp[0].elem);
            
        }
#line 2377 "parser.tab.c"
    break;

  case 98: /* and_expr: shift_expr BIT_AND and_expr  */
#line 627 "parser.y"
                                        {  
            (yyval.elem) = create_node(4, "and_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2388 "parser.tab.c"
    break;

  case 99: /* shift_expr: arith_expr  */
#line 635 "parser.y"
                         { 
                (yyval.elem) = (yyvsp[0].elem); 
            }
#line 2396 "parser.tab.c"
    break;

  case 100: /* shift_expr: arith_expr SHIFT_OPER shift_expr  */
#line 638 "parser.y"
                                                 { 
                (yyval.elem) = create_node(4, "shift_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2407 "parser.tab.c"
    break;

  case 101: /* arith_expr: term  */
#line 646 "parser.y"
                 { 
                (yyval.elem) = (yyvsp[0].elem);
            }
#line 2415 "parser.tab.c"
    break;

  case 102: /* arith_expr: arith_expr PLUS term  */
#line 649 "parser.y"
                                   { 
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2426 "parser.tab.c"
    break;

  case 103: /* arith_expr: arith_expr MINUS term  */
#line 655 "parser.y"
                                    { 
                (yyval.elem) = create_node(4, "arith_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
                (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
                (yyval.elem)->addr = str_to_ch(newTemp());
                create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
            }
#line 2437 "parser.tab.c"
    break;

  case 104: /* term: factor  */
#line 662 "parser.y"
             {
            (yyval.elem) = (yyvsp[0].elem); 
        }
#line 2445 "parser.tab.c"
    break;

  case 105: /* term: term term_choice factor  */
#line 665 "parser.y"
                                  {
            (yyval.elem) = create_node(4, "term", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        
		}
#line 2457 "parser.tab.c"
    break;

  case 106: /* term_choice: MULTIPLY  */
#line 674 "parser.y"
                            { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2465 "parser.tab.c"
    break;

  case 107: /* term_choice: ATTHERATE  */
#line 677 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2473 "parser.tab.c"
    break;

  case 108: /* term_choice: DIVIDE  */
#line 680 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2481 "parser.tab.c"
    break;

  case 109: /* term_choice: REMAINDER  */
#line 683 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2489 "parser.tab.c"
    break;

  case 110: /* term_choice: FLOOR_DIV_OPER  */
#line 686 "parser.y"
                           { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2497 "parser.tab.c"
    break;

  case 111: /* factor: factor_choice factor  */
#line 691 "parser.y"
                                    {  
            (yyval.elem) = create_node(3, "factor", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr,"", (yyvsp[0].elem)->addr);
        }
#line 2508 "parser.tab.c"
    break;

  case 112: /* factor: power  */
#line 697 "parser.y"
                    { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2516 "parser.tab.c"
    break;

  case 113: /* factor_choice: PLUS  */
#line 701 "parser.y"
                            {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2524 "parser.tab.c"
    break;

  case 114: /* factor_choice: MINUS  */
#line 704 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2532 "parser.tab.c"
    break;

  case 115: /* factor_choice: NEGATION  */
#line 707 "parser.y"
                     { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2540 "parser.tab.c"
    break;

  case 116: /* power: atom_expr  */
#line 711 "parser.y"
                        { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2548 "parser.tab.c"
    break;

  case 117: /* power: atom_expr POWER_OPERATOR factor  */
#line 714 "parser.y"
                                            { 
            (yyval.elem) = create_node(4, "power", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->addr = str_to_ch(newTemp());
            create_ins(1, (yyval.elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[-2].elem)->addr, (yyvsp[0].elem)->addr);
        }
#line 2559 "parser.tab.c"
    break;

  case 118: /* atom_expr: atom  */
#line 722 "parser.y"
                {  
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2567 "parser.tab.c"
    break;

  case 119: /* atom_expr: atom_expr trailer  */
#line 725 "parser.y"
                            {  
            (yyval.elem) = create_node(3, "atom_expr", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 2576 "parser.tab.c"
    break;

  case 120: /* atom_expr: atom_expr DOT NAME  */
#line 729 "parser.y"
                             { 
            (yyval.elem) = create_node(4, "atom_expr", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 2585 "parser.tab.c"
    break;

  case 121: /* atom: OPEN_BRACKET testlist CLOSE_BRACKET  */
#line 735 "parser.y"
                                           { 
        (yyval.elem)=(yyvsp[-1].elem);
    }
#line 2593 "parser.tab.c"
    break;

  case 122: /* atom: OPEN_BRACKET CLOSE_BRACKET  */
#line 738 "parser.y"
                                    {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 2602 "parser.tab.c"
    break;

  case 123: /* atom: SQUARE_OPEN testlist SQUARE_CLOSE  */
#line 742 "parser.y"
                                           { 
        (yyval.elem) = (yyvsp[-1].elem);
    }
#line 2610 "parser.tab.c"
    break;

  case 124: /* atom: SQUARE_OPEN SQUARE_CLOSE  */
#line 745 "parser.y"
                                {
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 2619 "parser.tab.c"
    break;

  case 125: /* atom: CURLY_OPEN CURLY_CLOSE  */
#line 749 "parser.y"
                                { 
        (yyval.elem) = create_node(3, "atom", (yyvsp[-1].elem), (yyvsp[0].elem));
        (yyval.elem)->ins = instCount+1;
    }
#line 2628 "parser.tab.c"
    break;

  case 126: /* atom: NAME  */
#line 753 "parser.y"
                {
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
     }
#line 2637 "parser.tab.c"
    break;

  case 127: /* atom: NUMBER  */
#line 773 "parser.y"
                    { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 2646 "parser.tab.c"
    break;

  case 128: /* atom: STRING_PLUS  */
#line 777 "parser.y"
                        { 
       (yyval.elem) = (yyvsp[0].elem);
    }
#line 2654 "parser.tab.c"
    break;

  case 129: /* atom: ATOM_KEYWORDS  */
#line 780 "parser.y"
                        { 
        (yyval.elem) = (yyvsp[0].elem);
        (yyval.elem)->ins = instCount+1;
    }
#line 2663 "parser.tab.c"
    break;

  case 130: /* STRING_PLUS: STRING  */
#line 789 "parser.y"
                        {
            (yyval.elem) = (yyvsp[0].elem);
			(yyval.elem)->ins = instCount+1;
        }
#line 2672 "parser.tab.c"
    break;

  case 131: /* STRING_PLUS: STRING STRING_PLUS  */
#line 793 "parser.y"
                                { 
            (yyval.elem) = create_node(3, "STRING_PLUS", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[0].elem)->ins;
        }
#line 2681 "parser.tab.c"
    break;

  case 132: /* trailer: OPEN_BRACKET CLOSE_BRACKET  */
#line 799 "parser.y"
                                     { 
            (yyval.elem) = create_node(3, "trailer", (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = instCount+1;
        }
#line 2690 "parser.tab.c"
    break;

  case 133: /* trailer: OPEN_BRACKET arglist CLOSE_BRACKET  */
#line 803 "parser.y"
                                              {
            (yyval.elem) = create_node(4, "trailer", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 2699 "parser.tab.c"
    break;

  case 134: /* trailer: SQUARE_OPEN test SQUARE_CLOSE  */
#line 807 "parser.y"
                                       {
            (yyval.elem) = create_node(4, "trailer", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem)->ins;
        }
#line 2708 "parser.tab.c"
    break;

  case 135: /* testlist: testlist_list  */
#line 813 "parser.y"
                           { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2716 "parser.tab.c"
    break;

  case 136: /* testlist: testlist_list COMMA  */
#line 816 "parser.y"
                                {
            (yyval.elem)=create_node(3,"testlist",(yyvsp[-1].elem),(yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
        }
#line 2725 "parser.tab.c"
    break;

  case 137: /* testlist_list: test  */
#line 821 "parser.y"
                            {
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2733 "parser.tab.c"
    break;

  case 138: /* testlist_list: test COLON TYPE_HINT  */
#line 824 "parser.y"
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
#line 2754 "parser.tab.c"
    break;

  case 139: /* testlist_list: testlist_list COMMA test  */
#line 840 "parser.y"
                                    { 
            (yyval.elem) = create_node(4, "testlist_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
        }
#line 2763 "parser.tab.c"
    break;

  case 140: /* testlist_list: testlist_list COMMA test COLON TYPE_HINT  */
#line 844 "parser.y"
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
#line 2783 "parser.tab.c"
    break;

  case 141: /* classdef: CLASS X COLON suite  */
#line 861 "parser.y"
                                   { 
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "CLASS", (yyvsp[-2].elem)->addr, 0, (yyvsp[-3].elem)->lineno, 1);
        }
#line 2792 "parser.tab.c"
    break;

  case 142: /* classdef: CLASS X OPEN_BRACKET CLOSE_BRACKET COLON suite  */
#line 865 "parser.y"
                                                              { 
            current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "CLASS", (yyvsp[-4].elem)->addr, 0, (yyvsp[-5].elem)->lineno, 1);
        }
#line 2801 "parser.tab.c"
    break;

  case 143: /* classdef: CLASS X OPEN_BRACKET arglist CLOSE_BRACKET COLON suite  */
#line 869 "parser.y"
                                                                      { 
           current_ste = get_prev_scope(current_ste);
            populate_new_scope(current_ste, "CLASS", (yyvsp[-5].elem)->addr, (yyvsp[-3].elem)->num_params, (yyvsp[-6].elem)->lineno, 1);
        }
#line 2810 "parser.tab.c"
    break;

  case 144: /* X: NAME  */
#line 875 "parser.y"
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
#line 2828 "parser.tab.c"
    break;

  case 145: /* arglist: argument_list  */
#line 891 "parser.y"
                           { 
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2836 "parser.tab.c"
    break;

  case 146: /* arglist: argument_list COMMA  */
#line 894 "parser.y"
                                 { 
            (yyval.elem)=(yyvsp[-1].elem);
        }
#line 2844 "parser.tab.c"
    break;

  case 147: /* argument_list: argument  */
#line 898 "parser.y"
                            { 
            (yyval.elem)=(yyvsp[0].elem);
            (yyval.elem)->num_params=1;
        }
#line 2853 "parser.tab.c"
    break;

  case 148: /* argument_list: argument_list COMMA argument  */
#line 902 "parser.y"
                                        { 
            (yyval.elem) = create_node(4, "argument_list", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            (yyval.elem)->num_params = (yyvsp[-2].elem)->num_params + 1;
        }
#line 2863 "parser.tab.c"
    break;

  case 149: /* argument: test  */
#line 909 "parser.y"
                {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2871 "parser.tab.c"
    break;

  case 150: /* argument: test EQUAL test  */
#line 912 "parser.y"
                            { 
            (yyval.elem) = create_node(4, "argument", (yyvsp[-2].elem), (yyvsp[-1].elem), (yyvsp[0].elem));
            (yyval.elem)->ins = (yyvsp[-2].elem)->ins;
            create_ins(0, (yyvsp[-2].elem)->addr, (yyvsp[-1].elem)->addr, (yyvsp[0].elem)->addr, "");
        }
#line 2881 "parser.tab.c"
    break;

  case 151: /* func_body_suite: simple_stmt  */
#line 919 "parser.y"
                                { 
            (yyval.elem) = (yyvsp[0].elem);
        }
#line 2889 "parser.tab.c"
    break;

  case 152: /* func_body_suite: NEWLINE INDENT stmt_plus DEDENT  */
#line 922 "parser.y"
                                            { 
            (yyval.elem) = (yyvsp[-1].elem);
        }
#line 2897 "parser.tab.c"
    break;

  case 153: /* func_body_suite: NEWLINE INDENT stmt_plus NEWLINE DEDENT  */
#line 925 "parser.y"
                                                    { 
            (yyval.elem) = (yyvsp[-2].elem);
        }
#line 2905 "parser.tab.c"
    break;

  case 154: /* stmt_plus: stmt  */
#line 930 "parser.y"
                    {
            (yyval.elem)=(yyvsp[0].elem);
        }
#line 2913 "parser.tab.c"
    break;

  case 155: /* stmt_plus: stmt stmt_plus  */
#line 933 "parser.y"
                            { 
            (yyval.elem)=create_node(3,"stmt_plus",(yyvsp[-1].elem),(yyvsp[0].elem));
			(yyval.elem)->ins = (yyvsp[-1].elem) -> ins;
        }
#line 2922 "parser.tab.c"
    break;


#line 2926 "parser.tab.c"

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

#line 938 "parser.y"


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
