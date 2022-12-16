%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID TIP BGIN END ASSIGN NR 
%start progr
%%
progr: var_globale functii user_types bloc {printf("program corect sintactic\n");}
     ;

var_globale :  declaratie ';'
	   | declaratii declaratie ';'
	   ;
declaratie : TIP ID 
           | TIP ID '[' ']' ASSIGN '{' lista_nr '}'
           | CHAR ID '[' ']' ASSIGN '{' lista_lit '}'
           | STRING ID ASSIGN '{' lista_lit '}'
           | TIP ID '[' NR ']'
           ;
TIP : INT
    | FLOAT
    | CHAR
    | STRING
    | BOOL
    | user_type
    ;
/* bloc */
functii : functie ';'
        | functii functie ';'  
        ;
functie: TIP ID '(' lista_param ')' BEGIN_F list END_F ;
lista_param : TIP ID
            | lista_param ',' TIP ID
            ;
/* lista instructiuni */
list :  statement ';' 
     | list statement ';'
     ;

/* instructiune */
statement: ID ASSIGN ID
         | ID ASSIGN NR  		 
         | //TO DO
         ;
        
lista_nr : NR
           | lista_nr ',' NR
           ;
lista_lit : LIT
           | lista_lit ',' LIT
           ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
}
