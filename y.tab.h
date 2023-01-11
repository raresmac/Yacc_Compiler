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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    LIT = 258,                     /* LIT  */
    ID = 259,                      /* ID  */
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    CHAR = 262,                    /* CHAR  */
    BOOL = 263,                    /* BOOL  */
    STRING = 264,                  /* STRING  */
    NEWTYPE = 265,                 /* NEWTYPE  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    WHILE = 268,                   /* WHILE  */
    FOR = 269,                     /* FOR  */
    BGIN = 270,                    /* BGIN  */
    END = 271,                     /* END  */
    DEFINE = 272,                  /* DEFINE  */
    CONST = 273,                   /* CONST  */
    TYPEOF = 274,                  /* TYPEOF  */
    GR = 275,                      /* GR  */
    LW = 276,                      /* LW  */
    ASSIGN = 277,                  /* ASSIGN  */
    PLUS = 278,                    /* PLUS  */
    MINUS = 279,                   /* MINUS  */
    ADD = 280,                     /* ADD  */
    DEDUCT = 281,                  /* DEDUCT  */
    EQUAL = 282,                   /* EQUAL  */
    DIV = 283,                     /* DIV  */
    MOD = 284,                     /* MOD  */
    AND = 285,                     /* AND  */
    OR = 286,                      /* OR  */
    NOT = 287,                     /* NOT  */
    XOR = 288,                     /* XOR  */
    EVAL = 289,                    /* EVAL  */
    MAIN = 290,                    /* MAIN  */
    TRU = 291,                     /* TRU  */
    FALS = 292,                    /* FALS  */
    RET = 293,                     /* RET  */
    UTYPE = 294,                   /* UTYPE  */
    NRI = 295,                     /* NRI  */
    NRF = 296                      /* NRF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LIT 258
#define ID 259
#define INT 260
#define FLOAT 261
#define CHAR 262
#define BOOL 263
#define STRING 264
#define NEWTYPE 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define FOR 269
#define BGIN 270
#define END 271
#define DEFINE 272
#define CONST 273
#define TYPEOF 274
#define GR 275
#define LW 276
#define ASSIGN 277
#define PLUS 278
#define MINUS 279
#define ADD 280
#define DEDUCT 281
#define EQUAL 282
#define DIV 283
#define MOD 284
#define AND 285
#define OR 286
#define NOT 287
#define XOR 288
#define EVAL 289
#define MAIN 290
#define TRU 291
#define FALS 292
#define RET 293
#define UTYPE 294
#define NRI 295
#define NRF 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 105 "proiect.y"

    struct valnr_t *valnr;
    int vali;
    float valf;
    char *strval;
    struct lista_nr_t *lista_nr_t;
    struct lista_lit_t *lista_lit_t;
    struct lista_param_t *lista_param_t;
    struct param_t *param_t;
    struct var *v; 
    struct tip_t* tip;

#line 162 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
