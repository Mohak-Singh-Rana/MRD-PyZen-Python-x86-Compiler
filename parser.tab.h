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
    NEWLINE = 258,                 /* NEWLINE  */
    ASYNC = 259,                   /* ASYNC  */
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
    NONLOCAL = 284,                /* NONLOCAL  */
    ASSERT = 285,                  /* ASSERT  */
    ATOM_KEYWORDS = 286,           /* ATOM_KEYWORDS  */
    STRING = 287,                  /* STRING  */
    NUMBER = 288,                  /* NUMBER  */
    OPEN_BRACKET = 289,            /* OPEN_BRACKET  */
    CLOSE_BRACKET = 290,           /* CLOSE_BRACKET  */
    EQUAL = 291,                   /* EQUAL  */
    SEMI_COLON = 292,              /* SEMI_COLON  */
    COLON = 293,                   /* COLON  */
    COMMA = 294,                   /* COMMA  */
    PLUS = 295,                    /* PLUS  */
    MINUS = 296,                   /* MINUS  */
    MULTIPLY = 297,                /* MULTIPLY  */
    DIVIDE = 298,                  /* DIVIDE  */
    REMAINDER = 299,               /* REMAINDER  */
    ATTHERATE = 300,               /* ATTHERATE  */
    NEGATION = 301,                /* NEGATION  */
    BIT_AND = 302,                 /* BIT_AND  */
    BIT_OR = 303,                  /* BIT_OR  */
    BIT_XOR = 304,                 /* BIT_XOR  */
    DOT = 305,                     /* DOT  */
    CURLY_OPEN = 306,              /* CURLY_OPEN  */
    CURLY_CLOSE = 307,             /* CURLY_CLOSE  */
    SQUARE_OPEN = 308,             /* SQUARE_OPEN  */
    SQUARE_CLOSE = 309,            /* SQUARE_CLOSE  */
    LESS_THAN = 310,               /* LESS_THAN  */
    GREATER_THAN = 311,            /* GREATER_THAN  */
    EQUAL_EQUAL = 312,             /* EQUAL_EQUAL  */
    GREATER_THAN_EQUAL = 313,      /* GREATER_THAN_EQUAL  */
    LESS_THAN_EQUAL = 314,         /* LESS_THAN_EQUAL  */
    NOT_EQUAL_ARROW = 315,         /* NOT_EQUAL_ARROW  */
    NOT_EQUAL = 316,               /* NOT_EQUAL  */
    IS = 317                       /* IS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 66 "parser.y"

    struct node *elem;

#line 130 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
