%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;

char *functie_curenta = NULL;
char *structura_curenta = NULL;
int corect = 1;

FILE *fisier_tabela;

struct simbol{
    enum{
        SIMBOL_VARIABILA,
        SIMBOL_FUNCTIE,
        SIMBOL_STRUCTURA
    }tip_simbol;
    char *nume;
    char *functie;
    char *structura;
    struct tip_t *tip;
    struct lista_param_t *param;
    struct expresie *init;
};

int nrSimboluri = 0;
struct simbol SymbolTable[1024];

void insertVarTable(char *nume, struct tip_t *tip);
void insertFuncTable(char *nume, struct tip_t *ret, struct lista_param_t *param);
void printTable();
void varDefinita(char *nume);
void funDefinita(char *nume);
void structDefinita(char *nume);
struct tip_t *tipVar(char *nume);
struct tip_t *tipRetFun(char *nume);
void tipExpr(struct expresie *expr, struct tip_t *tip);
void tipuriEgale(struct tip_t *stanga, struct tip_t *dreapta);
void apelCorect(struct expresie_apel *apel);
%}
%token ID NR LIT NEWTYPE INT CHAR FLOAT BOOL STRING IF WHILE FOR BGIN END DEFINE CONST ASSIGN PLUS MINUS ADD DEDUCT EQUAL DIV MOD AND OR NOT XOR MAIN EVAL TYPEOF
%start progr
%%
progr : var_globale functii user_types bloc  {printf("Sintaxă corectă\n");
                                             if (corect) {
                                             printf("Corect semantic\n");
                                             printTable();
                                             }
                                             else
                                             printf("Incorect semantic\n");
                                             }
      | functii user_types bloc {printf("Sintaxă corectă\n");
                              if (corect) {
                              printf("Corect semantic\n");
                              printTable();
                              }
                              else
                              printf("Incorect semantic\n");
                              }
      | var_globale user_types bloc {printf("Sintaxă corectă\n");
                                   if (corect) {
                                   printf("Corect semantic\n");
                                   printTable();
                                   }
                                   else
                                   printf("Incorect semantic\n");
                                   }
      | var_globale functii bloc {printf("Sintaxă corectă\n");
                                   if (corect) {
                                   printf("Corect semantic\n");
                                   printTable();
                                   }
                                   else
                                   printf("Incorect semantic\n");
                                   }
      | user_types bloc {printf("Sintaxă corectă\n");
                         if (corect) {
                         printf("Corect semantic\n");
                         printTable();
                         }
                         else
                         printf("Incorect semantic\n");
                         }
      | functii bloc {printf("Sintaxă corectă\n");
                    if (corect) {
                    printf("Corect semantic\n");
                    printTable();
                    }
                    else
                    printf("Incorect semantic\n");
                    }
      | var_globale bloc {printf("Sintaxă corectă\n");
                         if (corect) {
                         printf("Corect semantic\n");
                         printTable();
                         }
                         else
                         printf("Incorect semantic\n");
                         }
      | bloc {printf("Sintaxă corectă\n");
              if (corect) {
               printf("Corect semantic\n");
               printTable();
               }
               else
               printf("Incorect semantic\n");
               }
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
declaratie : TIP ID {
                    structDefinita($1->nume);
                    insertVarTable($2, $1);
                    }
           | TIP ID ASSIGN NR {
                              structDefinita($1->nume);
                              struct tip_t tip_expr;
                              tipExpr($4, &tip_expr);
                              tipuriEgale(&tip_expr, $1);
                              insertVarTable($2, $1);
                              }
           | CHAR ID ASSIGN LIT{
                              structDefinita($1->nume);
                              struct tip_t tip_expr;
                              tipExpr($4, &tip_expr);
                              tipuriEgale(&tip_expr,"char");
                              insertVarTable($2,"char");
                              }
           | TIP ID '[' ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($1->nume);
                              struct tip_t tip_expr;
                              tipExpr($7, &tip_expr);
                              tipuriEgale(&tip_expr, $1);
                              insertVarTable($2, $1);
                              }
           | CHAR ID '[' ']' ASSIGN '{' lista_lit '}'{
                              structDefinita($1->nume);
                              struct tip_t tip_expr;
                              tipExpr($7, &tip_expr);
                              tipuriEgale(&tip_expr, "char");
                              insertVarTable($2, "char");
                              }
           | STRING ID ASSIGN '{' lista_lit '}'{
                              structDefinita($1->nume);
                              struct tip_t tip_expr;
                              tipExpr($5, &tip_expr);
                              tipuriEgale(&tip_expr, "string");
                              insertVarTable($2, "string");
                              }
           | TIP ID '[' NR ']'{
                              structDefinita($1->nume);
                              struct tip_t tip_expr;
                              tipExpr($4, &tip_expr);
                              tipuriEgale(&tip_expr, $1);
                              insertVarTable($2, $1);
                              }
           | CONST TIP ID '[' ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($1->nume);
                              struct tip_t tip_expr;
                              tipExpr($4, &tip_expr);
                              tipuriEgale(&tip_expr, $1);
                              insertVarTable($2, $1);
                              }
           | CONST CHAR ID '[' ']' ASSIGN '{' lista_lit '}'{
                              structDefinita($1->nume);
                              struct tip_t tip_expr;
                              tipExpr($8, &tip_expr);
                              tipuriEgale(&tip_expr, "char");
                              insertVarTable($3, "char");
                              }
           | CONST STRING ID ASSIGN '{' lista_lit '}'{
                              structDefinita($1->nume);
                              struct tip_t tip_expr;
                              tipExpr($6, &tip_expr);
                              tipuriEgale(&tip_expr, "string");
                              insertVarTable($3, "string");
                              }
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
                {
                    insertFuncTable($3, $2, $5);
                    functie_curenta = $3;
                }
        ;
lista_param : param
            | lista_param ',' param
            ;

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
          | ID ASSIGN ID {
                         varDefinita($1);
                         struct tip_t tip_expr;
                         tipExpr($3, &tip_expr);
                         struct tip_t *tip_var = tipVar($1);
                         tipuriEgale(&tip_expr, tip_var);
                         }	 
          | VAR ASSIGN op_list{
                              varDefinita($1);
                              struct tip_t tip_expr;
                              tipExpr($3, &tip_expr);
                              struct tip_t *tip_var = tipVar($1);
                              tipuriEgale(&tip_expr, tip_var);
                              }	
          | VAR ASSIGN '(' op_list ')'{
                                        varDefinita($1);
                                        struct tip_t tip_expr;
                                        tipExpr($3, &tip_expr);
                                        struct tip_t *tip_var = tipVar($1);
                                        tipuriEgale(&tip_expr, tip_var);
                                        }	
          | IF '(' lista_cond ')' '{' list '}'
          | IF '(' lista_cond ')' statement
          | FOR '(' statement ';' lista_cond ';' statement ')' '{' list '}'
          | FOR '(' statement ';' lista_cond ';' statement ')' statement
          | WHILE '(' lista_cond ')' '{' list '}'
          | WHILE '(' lista_cond ')' statement
          | EVAL '(' VAR ')' ';'
          | EVAL '(' NR ')' ';' {if (corect){
                                             if((int)$3->val == $3->val){
                                                  printf("Rezultatul expresiei din eval este %d\n", (int)$3->val);
                                             }
                                             else {printf("Valorile nu sunt de tip int\n");}}}
          | EVAL '(' op_list ')' ';'
          | TYPEOF '(' VAR ')' ';'
          | TYPEOF '(' NR ')' ';'
          | TYPEOF '(' LIT ')' ';'
          ;
NEWVAL : ASSIGN
       | ADD
       | DEDUCT
       ;
op_list : operation
        | '(' op_list ')' operation
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
     | XOR
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

void checkTable(char* nume){
    int i;
    for(i = 0; i < nrSimboluri; i++){
        if (((structura_curenta == NULL && SymbolTable[i].structura == NULL) ||
             (structura_curenta != NULL && SymbolTable[i].structura != NULL &&
              strcmp(structura_curenta, SymbolTable[i].structura) == 0)) &&
            ((functie_curenta == NULL && SymbolTable[i].functie == NULL) ||
             (functie_curenta != NULL && SymbolTable[i].functie != NULL &&
              strcmp(functie_curenta, SymbolTable[i].functie) == 0)) &&
            (strcmp(SymbolTable[i].nume, nume) == 0))
        {
            printf("%s ", nume);
            if (functie_curenta != NULL)
                printf("din functia %s ", functie_curenta);
            if (structura_curenta != NULL)
                printf("din structura %s ", structura_curenta);
            printf("deja există\n");
            corect = 0;
            break;
        }
    }
}

void insertVarTable(char *nume, struct tip_t *tip){
    checkTable(nume);
    SymbolTable[nrSimboluri].tip_simbol = SIMBOL_VARIABILA;
    SymbolTable[nrSimboluri].nume = nume;
    SymbolTable[nrSimboluri].functie = functie_curenta;
    SymbolTable[nrSimboluri].structura = structura_curenta;
    SymbolTable[nrSimboluri].tip = tip;

    nrSimboluri++;
}

void insertFuncTable(char *nume, struct tip_t *ret, struct lista_param_t *param){
    checkTable(nume);
    SymbolTable[nrSimboluri].tip_simbol = SIMBOL_FUNCTIE;
    SymbolTable[nrSimboluri].nume = nume;
    SymbolTable[nrSimboluri].structura = structura_curenta;
    SymbolTable[nrSimboluri].tip = ret;
    SymbolTable[nrSimboluri].param = param;
    nrSimboluri++;
}
void printTip(FILE *f, struct tip_t *tip) {
    if (tip != NULL) {
        fprintf(f, "%s", tip->nume);
        for (int j = 0; j < tip->dimensiune; ++j)
            fprintf(f, "[%d]", tip->numar[j]);
    } 
    else{
        fprintf(f, "void");
    }
}

void printTable(){
  fisier_tabela = fopen("symbol_table.txt", "w");
  for (int i = 0; i < nrSimboluri; ++i) {
      if (SymbolTable[i].tip_simbol == SIMBOL_VARIABILA) {
        fprintf(fisier_tabela, "%s\t", SymbolTable[i].nume);
        printTip(fisier_tabela, SymbolTable[i].tip);
        fprintf(fisier_tabela, "\t");
        if (SymbolTable[i].structura == NULL &&
            SymbolTable[i].functie == NULL)
            fprintf(fisier_tabela, "globala\t");
        if (SymbolTable[i].structura != NULL &&
            SymbolTable[i].functie == NULL)
            fprintf(fisier_tabela, "membru\t");
        if (SymbolTable[i].functie != NULL)
            fprintf(fisier_tabela, "locala\t");
        if (SymbolTable[i].structura != NULL)
          fprintf(fisier_tabela, "în struct %s\t", SymbolTable[i].structura);
        if (SymbolTable[i].functie != NULL)
          fprintf(fisier_tabela, "în func %s\t", SymbolTable[i].functie);
        fprintf(fisier_tabela, "\n");
      } 
      else if (SymbolTable[i].tip_simbol == SIMBOL_FUNCTIE) {
          fprintf(fisier_tabela, "%s\t", SymbolTable[i].nume);
          if (SymbolTable[i].tip != NULL)
              fprintf(fisier_tabela, "%s", SymbolTable[i].tip->nume);
          else
              fprintf(fisier_tabela, "void");
          fprintf(fisier_tabela, "(");
          for (struct lista_param_t *j = SymbolTable[i].param; j != NULL; j = j->urmator) {
              printTip(fisier_tabela, j->tip);
              if (j->urmator != NULL)
                  fprintf(fisier_tabela, ", ");
          }
          fprintf(fisier_tabela, ")\t");
          if (SymbolTable[i].structura != NULL)
              fprintf(fisier_tabela, "metodă\tîn struct %s\t", SymbolTable[i].structura);
          else
              fprintf(fisier_tabela, "func\t");
          fprintf(fisier_tabela, "\n");
      } else {
          fprintf(fisier_tabela, "%s\tstruct\n", SymbolTable[i].nume);
      }
  }
  fclose(fisier_tabela);
}

void varDefinita(char *nume) {
    for (int i = 0; i < nrSimboluri; ++i) {
        if (SymbolTable[i].tip_simbol == SIMBOL_VARIABILA && strcmp(SymbolTable[i].nume, nume) == 0) {
            if (SymbolTable[i].functie == NULL && SymbolTable[i].structura == NULL)
                return;
            if (SymbolTable[i].functie == NULL && SymbolTable[i].structura != NULL &&
                structura_curenta != NULL &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0)
                return;
            if (SymbolTable[i].functie != NULL && SymbolTable[i].structura == NULL &&
                structura_curenta == NULL && functie_curenta != NULL &&
                structura_curenta == NULL && strcmp(SymbolTable[i].functie, functie_curenta) == 0)
                return;
            if (SymbolTable[i].functie != NULL && SymbolTable[i].structura != NULL &&
                functie_curenta != NULL && structura_curenta != NULL &&
                strcmp(SymbolTable[i].functie, functie_curenta) == 0 &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0)
                return;
        } else if (functie_curenta != NULL &&
                   SymbolTable[i].tip_simbol == SIMBOL_FUNCTIE &&
                   strcmp(SymbolTable[i].nume, functie_curenta) == 0) {
            for (struct lista_param_t *j = SymbolTable[i].param; j != NULL; j = j->urmator) {
                if (strcmp(j->nume, nume) == 0)
                    return;
            }
        }
    }
    corect = 0;
    printf("Variabila %s nu a fost definită\n", nume);
}

void funDefinita(char *nume) {
    for (int i = 0; i < nrSimboluri; ++i) {
        if (SymbolTable[i].tip_simbol == SIMBOL_FUNCTIE && strcmp(SymbolTable[i].nume, nume) == 0) {
            if (SymbolTable[i].structura != NULL && structura_curenta != NULL &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0)
                return;
            if (SymbolTable[i].structura == NULL)
                return;
        }
    }
    corect = 0;
    printf("Funcția %s nu a fost definită\n", nume);
}

void structDefinita(char *nume) {
    if (strcmp(nume, "int") == 0 ||
        strcmp(nume, "float") == 0 ||
        strcmp(nume, "char") == 0 ||
        strcmp(nume, "string") == 0 ||
        strcmp(nume, "bool") == 0)
        return;
    for (int i = 0; i < nrSimboluri; ++i) {
        if (SymbolTable[i].tip_simbol == SIMBOL_STRUCTURA && strcmp(SymbolTable[i].nume, nume) == 0) {
            return;
        }
    }
    corect = 0;
    printf("Structura %s nu a fost definită\n", nume);
}

struct tip_t *tipVar(char *nume) {
    struct tip_t *rezultat = NULL;
    for (int i = 0; i < nrSimboluri; ++i) {
        if (SymbolTable[i].tip_simbol == SIMBOL_VARIABILA && strcmp(SymbolTable[i].nume, nume) == 0) {
            if (SymbolTable[i].functie == NULL && SymbolTable[i].structura == NULL)
                rezultat = SymbolTable[i].tip;
            if (SymbolTable[i].functie == NULL && SymbolTable[i].structura != NULL &&
                structura_curenta != NULL &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0)
                rezultat = SymbolTable[i].tip;
            if (SymbolTable[i].functie != NULL && SymbolTable[i].structura == NULL &&
                structura_curenta == NULL && functie_curenta != NULL &&
                structura_curenta == NULL && strcmp(SymbolTable[i].functie, functie_curenta) == 0)
                rezultat = SymbolTable[i].tip;
            if (SymbolTable[i].functie != NULL && SymbolTable[i].structura != NULL &&
                functie_curenta != NULL && structura_curenta != NULL &&
                strcmp(SymbolTable[i].functie, functie_curenta) == 0 &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0)
                rezultat = SymbolTable[i].tip;
        } else if (functie_curenta != NULL &&
                   SymbolTable[i].tip_simbol == SIMBOL_FUNCTIE &&
                   strcmp(SymbolTable[i].nume, functie_curenta) == 0) {
            for (struct lista_param_t *j = SymbolTable[i].param; j != NULL; j = j->urmator) {
                if (strcmp(j->nume, nume) == 0)
                    rezultat = j->tip;
            }
        }
    }
    return rezultat;
}

struct tip_t *tipRetFun(char *nume) {
    struct tip_t *rezultat = NULL;
    for (int i = 0; i < nrSimboluri; ++i) {
        if (SymbolTable[i].tip_simbol == SIMBOL_FUNCTIE && strcmp(SymbolTable[i].nume, nume) == 0) {
            if (SymbolTable[i].structura != NULL && structura_curenta != NULL &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0)
                return SymbolTable[i].tip;
            if (SymbolTable[i].structura == NULL)
                rezultat = SymbolTable[i].tip;
        }
    }
    return rezultat;
}

void tipExpr(struct expresie *expr, struct tip_t *tip) {
    if (expr->tip_expr == EXPRESIE_NUM) {
        tip->nume = "int";
        tip->dimensiune = 0;
    } else if (expr->tip_expr == EXPRESIE_BOOL) {
        tip->nume = "bool";
        tip->dimensiune = 0;
    } else if (expr->tip_expr == EXPRESIE_STR) {
        tip->nume = "string";
        tip->dimensiune = 0;
    } else if (expr->tip_expr == EXPRESIE_NEW) {
        tip->nume = expr->new;
        tip->dimensiune = 0;
    } else if (expr->tip_expr == EXPRESIE_APEL) {
        tip = tipRetFun(expr->apel->fun);
    } else if (expr->tip_expr == EXPRESIE_VAR) {
        tip = tipVar(expr->var->nume);
    }
}

void tipuriEgale(struct tip_t *stanga, struct tip_t *dreapta) {
    int egale = 1;
    if (stanga != NULL && dreapta != NULL) {
        if ((strcmp(stanga->nume, dreapta->nume) == 0 ||
             (strcmp(stanga->nume, "int") == 0 && strcmp(dreapta->nume, "float") == 0) ||
             (strcmp(dreapta->nume, "int") == 0 && strcmp(stanga->nume, "float") == 0)) &&
            stanga->dimensiune == dreapta->dimensiune) {
            for (int i = 0; i < stanga->dimensiune; ++i)
                if (stanga->numar[i] == dreapta->numar[i]) {
                    egale = 0;
                    break;
                }
                else
                    egale = 0;
        } else {
            egale = 0;
        }
    } else {
        egale = 0;
    }
    if (egale == 0) {
        corect = 0;
        printTip(stdout, stanga);
        printf(" nu este compatibil cu ");
        printTip(stdout, dreapta);
        printf("\n");
    }
}

void apelCorect(struct expresie_apel *apel) {
    struct lista_param_t *param = NULL;

    for (int i = 0; i < nrSimboluri; ++i) {
        if (SymbolTable[i].tip_simbol == SIMBOL_FUNCTIE && strcmp(SymbolTable[i].nume, apel->fun) == 0) {
            if (SymbolTable[i].structura != NULL && structura_curenta != NULL &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0) {
                param = SymbolTable[i].param;
                break;
            }
            if (SymbolTable[i].structura == NULL) {
                param = SymbolTable[i].param;
                break;
            }
        }
    }

    struct lista_expresii *arg = apel->arg;

    while (param != NULL && arg != NULL) {
        struct tip_t tip_expr;
        tipExpr(arg->expr, &tip_expr);
        tipuriEgale(&tip_expr, param->tip);
        param = param->urmator;
        arg = arg->urmator;
    }
    if (param != NULL || arg != NULL) {
        corect = 0;
        printf("În apelul funcției %s numărul de argumente este greșit\n", apel->fun);
    }
}


int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
}