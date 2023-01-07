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
//ar trebui verificat ca o val const sa nu se schimbe ?
int yylex();
int yyerror();

FILE *fisier_tabela;

struct expresie {
    enum {
        EXPRESIE_NUM,
        EXPRESIE_BOOL,
        EXPRESIE_STR,
        EXPRESIE_LIT,
        EXPRESIE_LISTNR,
        EXPRESIE_LISTLIT,
        EXPRESIE_APEL,
    } tip_expr;
    float valnr;
    char vallit;
    char *valname;
    struct lista_nr_t *urmatornr;
    struct lista_lit_t *urmatorlit;
};

struct lista_nr_t{
    int nr;
    struct lista_nr_t *urmator;
};

struct lista_lit_t{
    char lit;
    struct lista_lit_t *urmator;
};

struct lista_expresii {
    struct expresie *expr;
    struct lista_expresii *urmator;
};

struct expresie_apel { //nu inteleg unde folosim
    char *fun;
    struct lista_expresii *arg;
};

struct lista_param_t{
    struct param_t * param;
    struct lista_param_t *urmator;
};

struct tip_t {
    char *nume;
    int dimensiune;
    int numar[1024];
};

struct param_t
{
        struct tip_t *tip;
	char *nume;
	float valnr;
	char vallit;
	char *valstr;
};

struct var{
	int index;
	char *nume;
};

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
}SymbolTable[1024];

int nrSimboluri = 0;
struct tip_t *initTip_t(char * val);
struct var *initVar(char * val, int index);
struct param_t *initTipParam(struct tip_t *tip, char *val);
struct lista_nr_t *initTipListNr(float val);
struct lista_lit_t *initTipListLit(char* val);
struct lista_param_t *initTipListParam(struct param_t* val);
void insertVarTable(char *nume, struct tip_t *tip);
void insertFuncTable(char *nume, struct tip_t *ret, struct lista_param_t *param);
void printTable();
void varDefinita(char *nume);
void funDefinita(char *nume);
void structDefinita(char *nume);
struct tip_t *tipVar(struct var *v);
struct tip_t *tipRetFun(char *nume);
struct tip_t *tipExpr(struct expresie *expr);
void tipuriEgale(struct tip_t *stanga, struct tip_t *dreapta);
void apelCorect(struct expresie_apel *apel);
%}

%union{
    float val;
    char *strval;
    struct lista_nr_t *lista_nr_t;
    struct lista_lit_t *lista_lit_t;
    struct lista_param_t *lista_param_t;
    struct param_t *param_t;
    struct expresie *expresie;
    struct var *v; 
    struct tip_t* tip;
};

%token <strval> LIT ID INT FLOAT CHAR BOOL STRING NEWTYPE IF WHILE FOR BGIN END DEFINE CONST TYPEOF GR LW ASSIGN PLUS MINUS ADD DEDUCT EQUAL DIV MOD AND OR NOT XOR EVAL MAIN
%token <val> NR
%type <tip> TIP lista_op operatie
%type <lista_param_t> lista_param
%type <param_t> param
%type <v> VAR
%type <lista_nr_t> lista_nr
%type <lista_lit_t> lista_lit

%start progr

%%
progr : declaratii functii user_types bloc  {printf("Sintaxă corectă\n");
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
      | declaratii user_types bloc {printf("Sintaxă corectă\n");
                                   if (corect) {
                                   printf("Corect semantic\n");
                                   printTable();
                                   }
                                   else
                                   printf("Incorect semantic\n");
                                   }
      | declaratii functii bloc {printf("Sintaxă corectă\n");
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
      | declaratii bloc {printf("Sintaxă corectă\n");
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
definitie : DEFINE ID NR
          | DEFINE ID LIT
          ; 
declaratii :  declaratie ';'
	   | declaratii declaratie ';'
	   ;
declaratie : TIP ID ASSIGN LIT{
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, $1);
                              insertVarTable($2,tip_expr);
                              }
           | TIP ID '[' ']' ASSIGN '{' lista_lit '}'{
                              struct tip_t *tip_expr=initTip_t("char");  //not sure
                              tipuriEgale(tip_expr, $1);
                              insertVarTable($2, tip_expr);
                              }
           | TIP ID ASSIGN '{' lista_lit '}'{
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, $1);
                              insertVarTable($2, tip_expr);
                              }
           | TIP ID '[' NR ']' ASSIGN '{' lista_lit '}'{
                              struct tip_t *tip_expr=initTip_t("char");  //not sure
                              tipuriEgale(tip_expr, $1);
                              insertVarTable($2, tip_expr);
                              }
           | CONST TIP ID '[' ']' ASSIGN '{' lista_lit '}'{
                              struct tip_t *tip_expr=initTip_t("char");  //not sure  
                              tipuriEgale(tip_expr, $2);
                              insertVarTable($3, tip_expr);
                              }
           | CONST TIP ID ASSIGN '{' lista_lit '}'{
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, $2);
                              insertVarTable($3, tip_expr);
                              }
           | TIP ID {
                    structDefinita($1->nume);
                    insertVarTable($2, $1);
                    }
           | TIP ID ASSIGN NR {
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("float");
                              tipuriEgale(tip_expr, $1);
                              insertVarTable($2, $1);
                              }
           
           | TIP ID '[' ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("float");
                              tipuriEgale(tip_expr,$1);
                              insertVarTable($2, $1);
                              }      
           | TIP ID '[' NR ']'{
                              structDefinita($1->nume);
                              insertVarTable($2, $1);
                              }
           | TIP ID '[' NR ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("float");
                              tipuriEgale(tip_expr, $1);
                              insertVarTable($2, $1);
                              }
           | CONST TIP ID '[' ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($2->nume);
                              struct tip_t *tip_expr=initTip_t("float");
                              tipuriEgale(tip_expr, $2);
                              insertVarTable($3, $2);
                              }
           | definitie
           ;
TIP : INT { $$=initTip_t($1); }
    | FLOAT { $$=initTip_t($1); }
    | CHAR { $$=initTip_t($1); }
    | STRING { $$=initTip_t($1); }
    | BOOL { $$=initTip_t($1); }
    ;
user_types : user_type
           | user_types user_type
           ;
user_type : NEWTYPE ID '{' declaratii '}' //insertStructTable(), care inca nu e facut
          ;
functii : functie ';'
        | functii functie ';' 
        ;
functie : TIP ID '(' lista_param ')' BGIN list END
                {
                    functie_curenta = $2; //not sure
                    insertFuncTable($2, $1, $4);
                    functie_curenta = NULL;
                }
        ;
lista_param : param {$$ = initTipListParam($1);}
            | lista_param ',' param {
                               $$=initTipListParam($3);
                               $1->urmator=$$;
                             }
            ;
param : TIP ID {
                   $$ = initTipParam($1,$2); 
               }
      | TIP ID NEWVAL VAR {
                   tipuriEgale(tipVar($4), $1);
                   $$ = initTipParam($1,$2);
               }
      | TIP ID NEWVAL NR {
                   struct tip_t *tip_expr=initTip_t("float");
                   tipuriEgale(tip_expr, $1);
                   $$ = initTipParam($1,$2);
               }
      | CONST TIP ID {
                   $$ = initTipParam($2,$3); 
               } //+de adaugat apeluri fct ca parametrii?
      ;
list :  statement ';' 
     | list statement ';'
     ;
VAR : ID {
         //de adaugat verificare daca e declarat si nu e vector
         $$=initVar($1, -1);
         }
    | ID '[' NR ']'{
         //de adaugat verificare daca e declarat si e vector
         $$=initVar($1, $3);
         }
    ;
statement : VAR NEWVAL VAR {
                         varDefinita($1->nume);
                         struct tip_t *tip_var1 = tipVar($3);
                         struct tip_t *tip_var2 = tipVar($1);
                         tipuriEgale(tip_var1, tip_var2);
                         }
          | VAR NEWVAL NR  //??	 
          | VAR NEWVAL lista_op{
                              varDefinita($1->nume);
                              struct tip_t *tip_var = tipVar($1);
                              tipuriEgale($3, tip_var);
                              }	
          | VAR NEWVAL '(' lista_op ')'{
                                        varDefinita($1->nume);
                                        struct tip_t *tip_var = tipVar($1);
                                        tipuriEgale($4, tip_var);
                                        }	
          | IF '(' lista_cond ')' '{' list '}'
          | IF '(' lista_cond ')' statement
          | FOR '(' statement ';' lista_cond ';' statement ')' '{' list '}'
          | FOR '(' statement ';' lista_cond ';' statement ')' statement
          | WHILE '(' lista_cond ')' '{' list '}'
          | WHILE '(' lista_cond ')' statement
          | EVAL '(' VAR ')' ';'
          | EVAL '(' NR ')' ';' {if (corect){
                                                 printf("Rezultatul expresiei din eval este %f\n", $3);
                                             }
                                             else {printf("Valorile nu sunt de tip int\n");}}
          | EVAL '(' lista_op ')' ';'
          | TYPEOF '(' VAR ')' ';'
          | TYPEOF '(' NR ')' ';'
          | TYPEOF '(' LIT ')' ';' //+de adaugat apeluri la functii
          ;
NEWVAL : ASSIGN
       | ADD
       | DEDUCT
       ;
lista_op : VAR operatie { tipuriEgale($2, tipVar($1)); $$=$2;}
         | NR operatie {tipuriEgale($2, initTip_t("float")); $$=$2;}
         | lista_op operatie {tipuriEgale($1,$2);}
         | '(' lista_op ')' operatie {tipuriEgale($2,$4); $$=$2;}
         ;
operatie : OP VAR {$$=tipVar($2);}
         | OP NR {$$=initTip_t("float");}
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
     | GR
     | LW
     ;
lista_nr : NR {$$ = initTipListNr($1);}
           | lista_nr ',' NR {
                               $$=initTipListNr($3);
                               $1->urmator=$$;
                             }
           ;
lista_lit :  LIT {$$ = initTipListLit($1);}
           | lista_lit ',' LIT {
                               $$=initTipListLit($3);
                               $1->urmator=$$;
                             }
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
        for (int j = 0; j < tip->dimensiune; ++j) //nu inteleg dimensiune si nr..later
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
        if ( SymbolTable[i].functie == NULL)
            fprintf(fisier_tabela, "globala\t");
        if (SymbolTable[i].functie != NULL)
        {   
            fprintf(fisier_tabela, "locala\t");
            fprintf(fisier_tabela, "în func %s\t", SymbolTable[i].functie);
            fprintf(fisier_tabela, "\n");
        }
      } 
      else if (SymbolTable[i].tip_simbol == SIMBOL_FUNCTIE) {
          fprintf(fisier_tabela, "%s\t", SymbolTable[i].nume);
          if (SymbolTable[i].tip != NULL)
              fprintf(fisier_tabela, "%s", SymbolTable[i].tip->nume);
          else
              fprintf(fisier_tabela, "void");
          fprintf(fisier_tabela, "(");
          for (struct lista_param_t *j = SymbolTable[i].param; j != NULL; j = j->urmator) {
              printTip(fisier_tabela, j->param->tip);
              if (j->urmator != NULL)
                  fprintf(fisier_tabela, ", ");
          }
          fprintf(fisier_tabela, ")\t");
          fprintf(fisier_tabela, "func\t");
          fprintf(fisier_tabela, "\n");
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
                if (strcmp(j->param->nume, nume) == 0)
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

struct tip_t *tipVar(struct var *v) { //trebuie adaptata la struct var
    struct tip_t *rezultat = NULL;
    for (int i = 0; i < nrSimboluri; ++i) {
        if (SymbolTable[i].tip_simbol == SIMBOL_VARIABILA && strcmp(SymbolTable[i].nume, v->nume) == 0) {
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
                if (strcmp(j->param->nume, v->nume) == 0)
                    rezultat = j->param->tip;
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
struct tip_t *tipExpr(struct expresie *expr) {
    struct tip_t *tip;
    if (expr->tip_expr == EXPRESIE_NUM) {
        tip->nume = "int";
        tip->dimensiune = 0;
    } else if (expr->tip_expr == EXPRESIE_BOOL) {
        tip->nume = "bool";
        tip->dimensiune = 0;
    } else if (expr->tip_expr == EXPRESIE_STR) {
        tip->nume = "string";
        tip->dimensiune = 0;
    }
    return tip;
}

void tipuriEgale(struct tip_t *stanga, struct tip_t *dreapta) {
    int egale = 1;
    if(stanga != NULL && dreapta != NULL){
        if(strcmp(stanga->nume, dreapta->nume)){
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
        struct tip_t *tip_expr = tipExpr(arg->expr);
        tipuriEgale(tip_expr, param->param->tip);
        param = param->urmator;
        arg = arg->urmator;
    }
    if (param != NULL || arg != NULL) {
        corect = 0;
        printf("În apelul funcției %s numărul de argumente este greșit\n", apel->fun);
    }
}
struct tip_t * initTip_t(char * val)
{
    struct tip_t* expr = (struct tip_t*)malloc(sizeof(struct tip_t));
    expr->nume = (char*) malloc(sizeof(char)*(strlen(val)+1)); 
    strcpy(expr->nume, val);
    expr->dimensiune=0;
    expr->numar[0]=0;
    return expr;
}
struct var * initVar(char * val, int index)
{
    struct var* expr = (struct var*)malloc(sizeof(struct var));
    expr->nume = (char*) malloc(sizeof(char)*(strlen(val)+1)); 
    strcpy(expr->nume,val);
    expr->index=index;
    return expr;
}
struct param_t *initTipParam(struct tip_t *tip, char *val)
{
    struct param_t* expr = (struct param_t*)malloc(sizeof(struct param_t));
    expr->nume = (char*) malloc(sizeof(char)*(strlen(val)+1)); 
    strcpy(expr->nume,val);
    expr->tip = (struct tip_t*)malloc(sizeof(tip));
    expr->tip=tip;
    return expr;
}
struct lista_nr_t *initTipListNr(float val)
{
    struct lista_nr_t* expr = (struct lista_nr_t*)malloc(sizeof(struct lista_nr_t));
    expr->urmator=NULL;
    expr->nr=val;
    return expr;
}
struct lista_lit_t *initTipListLit(char* val)
{
    struct lista_lit_t* expr = (struct lista_lit_t*)malloc(sizeof(struct lista_lit_t));
    expr->urmator=NULL;
    expr->lit=val[1];
    return expr;
}
struct lista_param_t *initTipListParam(struct param_t* val)
{
    struct lista_param_t* expr = (struct lista_param_t*)malloc(sizeof(struct lista_param_t));
    expr->urmator=NULL;
    expr->param = (struct param_t*)malloc(sizeof(val));
    expr->param=val;
    return expr;
}
int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
}
