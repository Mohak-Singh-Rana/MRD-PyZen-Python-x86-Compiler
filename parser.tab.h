/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    RANGE = 258,                   /* RANGE  */
    NEWLINE = 259,                 /* NEWLINE  */
    INDENT = 260,                  /* INDENT  */
    DEDENT = 261,                  /* DEDENT  */
    ASSIGN_OPERATOR = 262,         /* ASSIGN_OPERATOR  */
    POWER_OPERATOR = 263,          /* POWER_OPERATOR  */
    SHIFT_OPER = 264,              /* SHIFT_OPER  */
    FLOOR_DIV_OPER = 265,          /* FLOOR_DIV_OPER  */
    ARROW_OPER = 266,              /* ARROW_OPER  */
    TYPE_HINT = 267,               /* TYPE_HINT  */
    NAME = 268,                    /* NAME  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    ELIF = 271,                    /* ELIF  */
    WHILE = 272,                   /* WHILE  */
    FOR = 273,                     /* FOR  */
    IN = 274,                      /* IN  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    NOT = 277,                     /* NOT  */
    BREAK = 278,                   /* BREAK  */
    CONTINUE = 279,                /* CONTINUE  */
    RETURN = 280,                  /* RETURN  */
    CLASS = 281,                   /* CLASS  */
    DEF = 282,                     /* DEF  */
    GLOBAL = 283,                  /* GLOBAL  */
    ATOM_KEYWORDS = 284,           /* ATOM_KEYWORDS  */
    STRING = 285,                  /* STRING  */
    OPEN_BRACKET = 286,            /* OPEN_BRACKET  */
    CLOSE_BRACKET = 287,           /* CLOSE_BRACKET  */
    EQUAL = 288,                   /* EQUAL  */
    SEMI_COLON = 289,              /* SEMI_COLON  */
    COLON = 290,                   /* COLON  */
    COMMA = 291,                   /* COMMA  */
    PLUS = 292,                    /* PLUS  */
    MINUS = 293,                   /* MINUS  */
    MULTIPLY = 294,                /* MULTIPLY  */
    DIVIDE = 295,                  /* DIVIDE  */
    REMAINDER = 296,               /* REMAINDER  */
    ATTHERATE = 297,               /* ATTHERATE  */
    NEGATION = 298,                /* NEGATION  */
    BIT_AND = 299,                 /* BIT_AND  */
    BIT_OR = 300,                  /* BIT_OR  */
    BIT_XOR = 301,                 /* BIT_XOR  */
    DOT = 302,                     /* DOT  */
    CURLY_OPEN = 303,              /* CURLY_OPEN  */
    CURLY_CLOSE = 304,             /* CURLY_CLOSE  */
    SQUARE_OPEN = 305,             /* SQUARE_OPEN  */
    SQUARE_CLOSE = 306,            /* SQUARE_CLOSE  */
    LESS_THAN = 307,               /* LESS_THAN  */
    GREATER_THAN = 308,            /* GREATER_THAN  */
    EQUAL_EQUAL = 309,             /* EQUAL_EQUAL  */
    GREATER_THAN_EQUAL = 310,      /* GREATER_THAN_EQUAL  */
    LESS_THAN_EQUAL = 311,         /* LESS_THAN_EQUAL  */
    NOT_EQUAL_ARROW = 312,         /* NOT_EQUAL_ARROW  */
    NOT_EQUAL = 313,               /* NOT_EQUAL  */
    IS = 314,                      /* IS  */
    TRUE = 315,                    /* TRUE  */
    FALSE = 316,                   /* FALSE  */
    NUMBER = 317,                  /* NUMBER  */
    NONE = 318,                    /* NONE  */
    LEN = 319,                     /* LEN  */
    PRINT = 320,                   /* PRINT  */
    D_MAIN = 321,                  /* D_MAIN  */
    D_NAME = 322,                  /* D_NAME  */
    SELF = 323                     /* SELF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 78 "parser.y"

    struct node *elem;

#line 136 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
