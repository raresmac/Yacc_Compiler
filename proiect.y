%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID NR LIT NEWTYPE INT CHAR FLOAT BOOL STRING IF WHILE FOR BGIN END DEFINE CONST ASSIGN PLUS MINUS ADD DEDUCT EQUAL DIV MOD AND OR NOT XOR MAIN
%start progr
%%
progr : var_globale functii user_types bloc {printf("program corect sintactic\n");}
      | functii user_types bloc {printf("program corect sintactic\n");}
      | var_globale user_types bloc {printf("program corect sintactic\n");}
      | var_globale functii bloc {printf("program corect sintactic\n");}
      | user_types bloc {printf("program corect sintactic\n");}
      | functii bloc {printf("program corect sintactic\n");}
      | var_globale bloc {printf("program corect sintactic\n");}
      ;   
var_globale : definitii declaratii
            | definitii
            | declaratii
            ;
definitii : definitie
          | definitii definitie
          ;
definitie : DEFINE ID NR
          | DEFINE ID LIT
          ; 
declaratii :  declaratie ';'
	   | declaratii declaratie ';'
	   ;
declaratie : TIP ID 
           | TIP ID ASSIGN NR
           | CHAR ID ASSIGN LIT
           | TIP ID '[' ']' ASSIGN '{' lista_nr '}'
           | CHAR ID '[' ']' ASSIGN '{' lista_lit '}'
           | STRING ID ASSIGN '{' lista_lit '}'
           | TIP ID '[' NR ']'
           | CONST TIP ID '[' ']' ASSIGN '{' lista_nr '}'
           | CONST CHAR ID '[' ']' ASSIGN '{' lista_lit '}'
           | CONST STRING ID ASSIGN '{' lista_lit '}'         
           ;
TIP : INT
    | FLOAT
    | CHAR
    | STRING
    | BOOL
    ;
user_types : user_type
           | user_types user_type
           ;
user_type : NEWTYPE ID '{' declaratii '}'
          ;
functii : functie ';'
        | functii functie ';' 
        ;
functie : TIP ID '(' lista_param ')' BGIN list END
        ;
lista_param : param
            | lista_param ',' param
            ;
//nu inteleg nici eu dc, dar asa scrie in enunt " function calls which can have as parameters: expressions, other function calls, identifiers,constants,etc "
param : TIP ID
      | TIP ID NEWVAL VAR
      | TIP ID NEWVAL NR
      | CONST TIP ID
      | TIP ID '(' lista_param ')'
      ;
list :  statement ';' 
     | list statement ';'
     ;
VAR : ID
    | ID '[' NR ']'
    ;
statement : VAR NEWVAL VAR
          | VAR NEWVAL NR
          | ID ASSIGN ID  		 
          | VAR ASSIGN operation
          | VAR ASSIGN '(' operation ')'
          | IF '(' lista_cond ')' '{' list '}'
          | IF '(' lista_cond ')' statement
          | FOR '(' list ';' lista_cond ';' list ')' '{' list '}'
          | FOR '(' list ';' lista_cond ';' list ')' statement
          | WHILE '(' lista_cond ')' '{' list '}'
          | WHILE '(' lista_cond ')' statement
          ;
NEWVAL : ASSIGN
       | ADD
       | DEDUCT
       ;
operation : VAR OP VAR
          | VAR OP NR
          | NR OP VAR  
          ;
OP : PLUS
   | MINUS
   | DIV
   | MOD
   ;
lista_cond : cond
           | '(' lista_cond ')' OP_C cond
           ;
cond : VAR OP_C VAR
     | VAR OP_C NR
     | NR OP_C VAR
     ;
OP_C : AND
     | OR
     | NOT
     | EQUAL
     ;
lista_nr : NR
           | lista_nr ',' NR
           ;
lista_lit : LIT
           | lista_lit ',' LIT
           ;
bloc : MAIN BGIN list END
     ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
}