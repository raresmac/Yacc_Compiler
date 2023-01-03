%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"Eval" {return EVAL;}
"TypeOf" {return TYPEOF;}
"nou tip"|"new type" {return NEWTYPE;}
"int" {return INT;}
"float" {return FLOAT;}
"char" {return CHAR;}
"string" {return STRING;}
"bool" {return BOOL;}
"if"|"daca" {return IF;}
"for"|"pentru" {return FOR;}
"while"|"cat timp" {return WHILE;}
"incepe"|"begin" {return BGIN;}
"termina"|"end" {return END;}
"DEFINESTE"|"DEFINE" {return DEFINE;}
"const" {return CONST;}
":="|"devine" {return ASSIGN;}
"cu"|"plus"|"+" {return PLUS;}
"+="|"adauga" {return ADD;}
"fara"|"minus"|"-" {return MINUS;}
"-="|"scade" {return DEDUCT;}
"/"|"div"|"impartit_cat" {return DIV;}
"%"|"mod"|"impartit_rest" {return MOD;}
"=="|"egal" {return EQUAL;}
"si"|"&&" {return AND;}
"sau"|"||" {return OR;}
"NU E"|"!=" {return NOT;}
"xor"|"^" {return XOR;}
"main:" {return MAIN;}
[_a-zA-Z][_a-zA-Z0-9]* {return ID;}
[0-9]+ {return NR;}
'[a-zA-Z]' {return LIT;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
