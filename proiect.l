%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"int" {return INT;}
"float" {return FLOAT;}
"char" {return CHAR;}
"string" {return STRING;}
"bool" {return BOOL;}
"if" {return IF;}
"for" {return FOR;}
"while" {return WHILE;}
"si" {return AND;}
"sau" {return OR;}
"NU E" {return NOT;}
"xor" {return XOR;}
"incepe" {return BEGIN_F;}
"termina" {return END_F;}
"begin_progr" {return BGIN;}
"end_progr" {return END;}
@[_a-zA-Z][_a-zA-Z0-9]* {return ID;}
":=" {return ASSIGN;}
[0-9]+ {return NR;}
[a-zA-Z]+ {return LIT;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
