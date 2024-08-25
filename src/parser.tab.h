/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    RANGE = 258,
    NEWLINE = 259,
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
    ATOM_KEYWORDS = 284,
    STRING = 285,
    OPEN_BRACKET = 286,
    CLOSE_BRACKET = 287,
    EQUAL = 288,
    SEMI_COLON = 289,
    COLON = 290,
    COMMA = 291,
    PLUS = 292,
    MINUS = 293,
    MULTIPLY = 294,
    DIVIDE = 295,
    REMAINDER = 296,
    ATTHERATE = 297,
    NEGATION = 298,
    BIT_AND = 299,
    BIT_OR = 300,
    BIT_XOR = 301,
    DOT = 302,
    CURLY_OPEN = 303,
    CURLY_CLOSE = 304,
    SQUARE_OPEN = 305,
    SQUARE_CLOSE = 306,
    LESS_THAN = 307,
    GREATER_THAN = 308,
    EQUAL_EQUAL = 309,
    GREATER_THAN_EQUAL = 310,
    LESS_THAN_EQUAL = 311,
    NOT_EQUAL_ARROW = 312,
    NOT_EQUAL = 313,
    IS = 314,
    TRUE = 315,
    FALSE = 316,
    NUMBER = 317,
    NONE = 318,
    LEN = 319,
    PRINT = 320,
    D_MAIN = 321,
    D_NAME = 322,
    SELF = 323
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 99 "parser.y"

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
