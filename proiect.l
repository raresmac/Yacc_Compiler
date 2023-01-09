%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"//".*
"Eval" {yylval.strval=strdup(yytext); return EVAL;}
"TypeOf" {yylval.strval=strdup(yytext); return TYPEOF;}
"nou tip"|"new type" {yylval.strval=strdup(yytext); return NEWTYPE;}
"int" {yylval.strval=strdup(yytext); return INT;}
"float" {yylval.strval=strdup(yytext); return FLOAT;}
"char" {yylval.strval=strdup(yytext); return CHAR;}
"string" {yylval.strval=strdup(yytext); return STRING;}
"bool" {yylval.strval=strdup(yytext); return BOOL;}
"if"|"daca" {yylval.strval=strdup(yytext); return IF;}
"for"|"pentru" {yylval.strval=strdup(yytext); return FOR;}
"while"|"cat timp" {yylval.strval=strdup(yytext); return WHILE;}
"incepe"|"begin" {yylval.strval=strdup(yytext); return BGIN;}
"termina"|"end" {yylval.strval=strdup(yytext); return END;}
"DEFINESTE"|"DEFINE" {yylval.strval=strdup(yytext); return DEFINE;}
"const" {yylval.strval=strdup(yytext); return CONST;}
":="|"devine" {yylval.strval=strdup(yytext); return ASSIGN;}
"cu"|"plus"|"+" {yylval.strval=strdup(yytext); return PLUS;}
"+="|"adauga" {yylval.strval=strdup(yytext); return ADD;}
"fara"|"minus"|"-" {yylval.strval=strdup(yytext); return MINUS;}
"-="|"scade" {yylval.strval=strdup(yytext); return DEDUCT;}
"/"|"div"|"impartit_cat" {yylval.strval=strdup(yytext); return DIV;}
"%"|"mod"|"impartit_rest" {yylval.strval=strdup(yytext); return MOD;}
"=="|"egal" {yylval.strval=strdup(yytext); return EQUAL;}
"<"|"mai mic" {yylval.strval=strdup(yytext); return LW;}
">"|"mai mare" {yylval.strval=strdup(yytext); return GR;}
"si"|"&&" {yylval.strval=strdup(yytext); return AND;}
"sau"|"||" { yylval.strval=strdup(yytext); return OR;}
"NU E"|"!=" {yylval.strval=strdup(yytext); return NOT;}
"xor"|"^" {yylval.strval=strdup(yytext); return XOR;}
"main:" {yylval.strval=strdup(yytext); return MAIN;}
"adevarat" {yylval.strval=strdup(yytext); return TRU;}
"fals" {yylval.strval=strdup(yytext); return FALS;}
[_a-zA-Z][_a-zA-Z0-9]* {yylval.strval=strdup(yytext); return ID;}
[0-9]+|\-[0-9]+ {yylval.vali=atoi(yytext); return NRI;}
[0-9]+"."[0-9]+|\-[0-9]+"."[0-9]+ {yylval.valf=atoi(yytext); return NRF;}
\'[0-9a-zA-Z_=+\[\]{};':",./<>?-]\' {yylval.strval=strdup(yytext); return LIT;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
