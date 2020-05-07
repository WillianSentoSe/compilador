/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_LITERAL = 258,
    TK_ID = 259,
    TK_MAIN = 260,
    TK_VAR = 261,
    TK_DEF = 262,
    TK_TIPO = 263,
    TK_IF = 264,
    TK_ELSE = 265,
    TK_WHILE = 266,
    TK_DO = 267,
    TK_FOR = 268,
    TK_SWITCH = 269,
    TK_CASE = 270,
    TK_BREAK = 271,
    TK_CONTINUE = 272,
    TK_RETORNO = 273,
    TK_DEFAULT = 274,
    TK_OP_IGUALDADE = 275,
    TK_OP_DESIGUALDADE = 276,
    TK_OP_MAIORIGUAL = 277,
    TK_OP_MENORIGUAL = 278,
    TK_OP_NOT = 279,
    TK_OP_LOGICAL_AND = 280,
    TK_OP_AND = 281,
    TK_OP_LOGICAL_OR = 282,
    TK_OP_XOR = 283,
    TK_OP_IOR = 284,
    TK_OP_ADD = 285,
    TK_OP_MUL = 286,
    TK_OP_SUB = 287,
    TK_OP_UN_ADD = 288,
    TK_OP_UN_SUB = 289,
    TK_TIPO_INDEFINIDO = 290,
    TK_TIPO_INT = 291,
    TK_TIPO_FLOAT = 292,
    TK_TIPO_CHAR = 293,
    TK_TIPO_BOOL = 294,
    TK_TIPO_STRING = 295,
    TK_TIPO_VETOR = 296,
    TK_TIPO_VOID = 297,
    TK_CLASSE_VARIAVEL = 298,
    TK_CLASSE_FUNCAO = 299,
    TK_FIM = 300,
    TK_ERROR = 301,
    TK_CTX_BLOCO = 302,
    TK_CTX_IF = 303,
    TK_CTX_WHILE = 304,
    TK_CTX_FOR = 305,
    TK_CTX_CASE = 306,
    TK_OUT = 307,
    TK_IN = 308
  };
#endif
/* Tokens.  */
#define TK_LITERAL 258
#define TK_ID 259
#define TK_MAIN 260
#define TK_VAR 261
#define TK_DEF 262
#define TK_TIPO 263
#define TK_IF 264
#define TK_ELSE 265
#define TK_WHILE 266
#define TK_DO 267
#define TK_FOR 268
#define TK_SWITCH 269
#define TK_CASE 270
#define TK_BREAK 271
#define TK_CONTINUE 272
#define TK_RETORNO 273
#define TK_DEFAULT 274
#define TK_OP_IGUALDADE 275
#define TK_OP_DESIGUALDADE 276
#define TK_OP_MAIORIGUAL 277
#define TK_OP_MENORIGUAL 278
#define TK_OP_NOT 279
#define TK_OP_LOGICAL_AND 280
#define TK_OP_AND 281
#define TK_OP_LOGICAL_OR 282
#define TK_OP_XOR 283
#define TK_OP_IOR 284
#define TK_OP_ADD 285
#define TK_OP_MUL 286
#define TK_OP_SUB 287
#define TK_OP_UN_ADD 288
#define TK_OP_UN_SUB 289
#define TK_TIPO_INDEFINIDO 290
#define TK_TIPO_INT 291
#define TK_TIPO_FLOAT 292
#define TK_TIPO_CHAR 293
#define TK_TIPO_BOOL 294
#define TK_TIPO_STRING 295
#define TK_TIPO_VETOR 296
#define TK_TIPO_VOID 297
#define TK_CLASSE_VARIAVEL 298
#define TK_CLASSE_FUNCAO 299
#define TK_FIM 300
#define TK_ERROR 301
#define TK_CTX_BLOCO 302
#define TK_CTX_IF 303
#define TK_CTX_WHILE 304
#define TK_CTX_FOR 305
#define TK_CTX_CASE 306
#define TK_OUT 307
#define TK_IN 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
