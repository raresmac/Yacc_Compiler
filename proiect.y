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
/* TO DO
1)adaugat si implementat SIMBOL_CONST pt 'variabile' const si defines
2) setarea membrilor / parametrilor user_types si functii ca fiind parte din structura / functia respectiva
3) implementare typeof() si eval() (eval doar pt int uri)
4) printarea SIMBOL_FUNCTIE in fisier separat
*/
int yylex();
int yyerror();

FILE *fisier_tabela;

struct lista_nr_t{
    struct tip_t *tip;
    int nr;
    struct lista_nr_t *urmator;
};

struct lista_lit_t{
    char lit;
    struct lista_lit_t *urmator;
};

struct lista_param_t{
    struct param_t * param;
    struct lista_param_t *urmator;
};
struct tip_t {
    char *nume;
    int dimensiune; //?
    int numar[1024]; //?
};
struct valnr_t {
    struct tip_t *tip;
    float val;
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
}SymbolTable[1024];

int nrSimboluri = 0;
struct valnr_t *InitNr(char * tip, float val);
struct tip_t *initTip_t(char * val);
struct var *initVar(char * val, int index);
struct param_t *initTipParam(struct tip_t *tip, char *val);
struct lista_nr_t *initTipListNr(struct valnr_t* val);
struct lista_lit_t *initTipListLit(char* val);
struct lista_param_t *initTipListParam(struct param_t* val);
bool apelCorect(struct lista_param_t *arg, struct lista_param_t *param);
void insertVarTable(char *nume, struct tip_t *tip);
void insertFuncTable(char *nume, struct tip_t *ret, struct lista_param_t *param);
void insertStructTable(char *nume, struct lista_param_t *param);
void printTable();
void varDefinita(char *nume);
void funDefinita(char *nume, struct lista_param_t *arg);
void structDefinita(char *nume);
struct tip_t *tipVar(struct var *v);
struct tip_t *tipRetFun(char *nume);
void tipuriEgale(struct tip_t *stanga, struct tip_t *dreapta);
%}

%union{
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
};

%token <strval> LIT ID INT FLOAT CHAR BOOL STRING NEWTYPE IF WHILE FOR BGIN END DEFINE CONST TYPEOF GR LW ASSIGN PLUS MINUS ADD DEDUCT EQUAL DIV MOD AND OR NOT XOR EVAL MAIN TRU FALS
%token <vali> NRI
%token <valf> NRF
%type <tip> TIP lista_op operatie apel
%type <lista_param_t> lista_param lista_arg declaratii
%type <param_t> param arg declaratie
%type <v> VAR
%type <lista_nr_t> lista_nr
%type <lista_lit_t> lista_lit
%type <valnr> NR

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
      | var_globale  user_types bloc {printf("Sintaxă corectă\n");
                                   if (corect) {
                                   printf("Corect semantic\n");
                                   printTable();
                                   }
                                   else
                                   printf("Incorect semantic\n");
                                   }
      | var_globale  functii bloc {printf("Sintaxă corectă\n");
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
      | var_globale  bloc {printf("Sintaxă corectă\n");
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
var_globale : declaratie ';'
            | definitie
            | var_globale definitie 
            | var_globale declaratie ';'
            ;
definitie : DEFINE ID NR //ar trebui adaugat ca constanta
          | DEFINE ID LIT
          ; 
declaratii :  declaratie ';'{$$ = initTipListParam($1);}
	   | declaratii declaratie ';'{
                               $$=initTipListParam($2);
                               $1->urmator=$$;
                             }
	   ;
declaratie : TIP ID ASSIGN LIT{
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, $1);
                              insertVarTable($2,tip_expr);
                              $$ = initTipParam($1,$2);
                              }
           | TIP ID '[' ']' ASSIGN '{' lista_lit '}'{
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, $1);
                              insertVarTable($2, tip_expr);
                              $$ = initTipParam($1,$2);
                              }
           | TIP ID ASSIGN '{' lista_lit '}'{
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, $1);
                              insertVarTable($2, tip_expr);
                              $$ = initTipParam($1,$2);
                              }
           | TIP ID '[' NR ']' ASSIGN '{' lista_lit '}'{
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, $1);
                              insertVarTable($2, $1);
                              $$ = initTipParam($1,$2);
                              }
           | CONST TIP ID '[' ']' ASSIGN '{' lista_lit '}'{
                              structDefinita($2->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, $2);
                              insertVarTable($3, $2);
                              $$ = initTipParam($2,$3);
                              }
           | CONST TIP ID ASSIGN '{' lista_lit '}'{
                              structDefinita($2->nume);
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, $2);
                              insertVarTable($3, $2);
                              $$ = initTipParam($2,$3);
                              }
           | TIP ID {
                    structDefinita($1->nume);
                    insertVarTable($2, $1);
                    $$ = initTipParam($1,$2);
                    }
           | TIP ID ASSIGN NR {
                              structDefinita($1->nume);
                              tipuriEgale($4->tip, $1);
                              insertVarTable($2, $1);
                              $$ = initTipParam($1,$2);
                              }
           
           | TIP ID '[' ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("float");
                              tipuriEgale(tip_expr,$1);
                              insertVarTable($2, $1);
                              $$ = initTipParam($1,$2);
                              }      
           | TIP ID '[' NR ']'{
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("int");
                              tipuriEgale($4->tip,tip_expr);
                              insertVarTable($2, $1);
                              $$ = initTipParam($1,$2);
                              }
           | TIP ID '[' NR ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("int");
                              tipuriEgale($4->tip, tip_expr);
                              tip_expr=initTip_t("float");
                              tipuriEgale(tip_expr, $1);
                              insertVarTable($2, $1);
                              $$ = initTipParam($1,$2);
                              }
           | CONST TIP ID '[' ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($2->nume);
                              struct tip_t *tip_expr=initTip_t("float");
                              tipuriEgale(tip_expr, $2);
                              insertVarTable($3, $2);
                              $$ = initTipParam($2,$3);
                              }
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
user_type : NEWTYPE ID '{' declaratii '}' {
                    insertStructTable($2, $4);
                    structura_curenta = $2;
                    //de schimbat SymbolTable[declaratii].structura
                    structura_curenta = NULL;
                }
          ;
functii : functie ';'
        | functii functie ';' 
        ;
functie : TIP ID '(' lista_param ')' BGIN list END
                {
                    insertFuncTable($2, $1, $4);
                    functie_curenta = $2; //not sure
                    //de schimbat SymbolTable[lista_param].functie
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
                   tipuriEgale($4->tip, $1);
                   $$ = initTipParam($1,$2);
               }
      | CONST TIP ID {
                   $$ = initTipParam($2,$3); 
               }
      ;
list :  statement
     | list statement
     ;
VAR : ID {
         //de adaugat verificare daca nu e vector
         $$=initVar($1, -1);
         }
    | ID '[' NR ']'{
         //de adaugat verificare daca e vector
         $$=initVar($1, $3->val);
         }
    ;
statement : VAR NEWVAL VAR ';' {
                         varDefinita($1->nume);
                         struct tip_t *tip_var1 = tipVar($3);
                         struct tip_t *tip_var2 = tipVar($1);
                         tipuriEgale(tip_var1, tip_var2);
                         }
          | VAR NEWVAL NR ';'  {
                         varDefinita($1->nume);
                         struct tip_t *tip_var1 = $3->tip;
                         struct tip_t *tip_var2 = tipVar($1);
                         tipuriEgale(tip_var1, tip_var2);
                         }	 
          | VAR NEWVAL lista_op ';'{
                              varDefinita($1->nume);
                              struct tip_t *tip_var = tipVar($1);
                              tipuriEgale($3, tip_var);
                              }	
          | VAR NEWVAL '(' lista_op ')' ';' {
                                        varDefinita($1->nume);
                                        struct tip_t *tip_var = tipVar($1);
                                        tipuriEgale($4, tip_var);
                                        }	
          | IF '(' lista_cond ')' '{' list '}' 
          | IF '(' lista_cond ')' statement ';'
          | FOR '(' statement ';' lista_cond ';' statement ')' '{' list '}'
          | FOR '(' statement ';' lista_cond ';' statement ')' statement ';'
          | WHILE '(' lista_cond ')' '{' list '}'
          | WHILE '(' lista_cond ')' statement ';'
          | EVAL '(' VAR ')' ';'
          | EVAL '(' NR ')' ';' {if (corect){
                                                 printf("Rezultatul expresiei din eval este %f\n", $3->val);
                                             }
                                             else {printf("Valorile nu sunt de tip int\n");}}
          | EVAL '(' lista_op ')' ';'
          | TYPEOF '(' VAR ')' ';'
          | TYPEOF '(' NR ')' ';'
          | TYPEOF '(' LIT ')' ';'
          ;
NEWVAL : ASSIGN
       | ADD
       | DEDUCT
       ;
lista_op : VAR operatie { tipuriEgale($2, tipVar($1)); $$=$2;}
         | NR operatie {tipuriEgale($2, initTip_t("float")); $$=$2;}
         | apel //default return ok
         | lista_op operatie {tipuriEgale($1,$2);}
         | '(' lista_op ')' operatie {tipuriEgale($2,$4); $$=$2;}
         ;
operatie : OP VAR {$$=initTip_t("float");$$=tipVar($2);}
         | OP NR {$$=initTip_t("float");}
         | OP apel {$$=$2;}
         ;
OP : PLUS
   | MINUS
   | DIV
   | MOD
   ;
apel : ID '(' lista_arg ')' { 
                         funDefinita($1,$3);
                         $$=tipRetFun($1);
                         }
     ;
lista_arg : arg {$$ = initTipListParam($1);}
          | lista_arg ',' arg {
                               $$=initTipListParam($3);
                               $1->urmator=$$;
                             }
          ;
arg : VAR { $$ = initTipParam(tipVar($1),$1->nume); }
    | VAR NEWVAL VAR {
                   tipuriEgale(tipVar($3), tipVar($1));
                   $$ = initTipParam(tipVar($1),$1->nume);
               }
    | VAR NEWVAL NR {
                   tipuriEgale($3->tip, tipVar($1));
                   $$ = initTipParam(tipVar($1),$1->nume);
               }
    | apel { $$ = initTipParam($1,"functie"); }
    ;
lista_cond : cond
           | '(' lista_cond ')' OP_C cond
           ;
cond : VAR OP_C VAR {varDefinita($1->nume); varDefinita($3->nume); tipuriEgale(tipVar($3), tipVar($1));}
     | VAR OP_C NR {varDefinita($1->nume);tipuriEgale(tipVar($1), $3->tip);};
     | NR OP_C VAR {varDefinita($3->nume);tipuriEgale(tipVar($3), $1->tip);};
     ;
OP_C : AND
     | OR
     | NOT
     | EQUAL
     | XOR
     | GR
     | LW
     ;
NR: NRI {$$=InitNr("int",$1);}
  | NRF {$$=InitNr("float",$1);}
  ;
lista_nr : NR {$$ = initTipListNr($1);}
           | lista_nr ',' NR {
                               tipuriEgale($1->tip,$3->tip);
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
    for(int i = 0; i < nrSimboluri; i++){
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
    SymbolTable[nrSimboluri].nume = (char*) malloc(sizeof(char)*(strlen(nume)+1)); 
    strcpy(SymbolTable[nrSimboluri].nume,nume);
    SymbolTable[nrSimboluri].functie = functie_curenta;
    SymbolTable[nrSimboluri].structura = structura_curenta;
    SymbolTable[nrSimboluri].tip = tip;
    nrSimboluri++;
}

void insertFuncTable(char *nume, struct tip_t *ret, struct lista_param_t *param){
    checkTable(nume);
    SymbolTable[nrSimboluri].tip_simbol = SIMBOL_FUNCTIE;
    SymbolTable[nrSimboluri].nume = (char*) malloc(sizeof(char)*(strlen(nume)+1)); 
    strcpy(SymbolTable[nrSimboluri].nume,nume);
    SymbolTable[nrSimboluri].functie = functie_curenta;
    SymbolTable[nrSimboluri].structura = structura_curenta;
    SymbolTable[nrSimboluri].tip = ret;
    SymbolTable[nrSimboluri].param = param;
    nrSimboluri++;
}
void insertStructTable(char *nume, struct lista_param_t *param)
{
    checkTable(nume);
    SymbolTable[nrSimboluri].tip_simbol = SIMBOL_STRUCTURA;
    SymbolTable[nrSimboluri].nume = (char*) malloc(sizeof(char)*(strlen(nume)+1)); 
    strcpy(SymbolTable[nrSimboluri].nume,nume);
    SymbolTable[nrSimboluri].functie = functie_curenta;
    SymbolTable[nrSimboluri].structura = structura_curenta;
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


void funDefinita(char *nume, struct lista_param_t *arg) {
    for (int i = 0; i < nrSimboluri; ++i) {
        if (SymbolTable[i].tip_simbol == SIMBOL_FUNCTIE && strcmp(SymbolTable[i].nume, nume) == 0) {
            if ((SymbolTable[i].structura != NULL && structura_curenta != NULL &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0)||SymbolTable[i].structura == NULL)
                 if(!apelCorect(arg,SymbolTable[i].param))
                     printf("În apelul funcției %s numărul de argumente este greșit\n", nume);
                 else
                     return;
                     
        }
    }
    corect = 0;
    printf("Funcția %s nu a fost definită\n", nume);
}
bool apelCorect(struct lista_param_t * arg, struct lista_param_t *param) {
    while (param != NULL && arg != NULL) {
        tipuriEgale(arg->param->tip, param->param->tip);
        param = param->urmator;
        arg = arg->urmator;
    }
    if (param != NULL || arg != NULL) {
        corect = 0;
        return 0;
    }
    return 1;
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

struct tip_t *tipVar(struct var *v) {
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

void tipuriEgale(struct tip_t *stanga, struct tip_t *dreapta) {
    int egale = 1;
    if(stanga != NULL && dreapta != NULL){
        if(strcmp(stanga->nume, dreapta->nume)){
            egale = 0;
        }
    } 
    else {
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
struct lista_nr_t *initTipListNr(struct valnr_t * val)
{
    struct lista_nr_t* expr = (struct lista_nr_t*)malloc(sizeof(struct lista_nr_t));
    expr->urmator=NULL;
    expr->nr=val->val;
    expr->tip = (struct tip_t*)malloc(sizeof(val->tip));
    expr->tip=val->tip;
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
struct valnr_t *InitNr(char * tip, float val)
{
    struct valnr_t * expr = (struct valnr_t*)malloc(sizeof(struct valnr_t));
    struct tip_t* tip_expr=initTip_t(tip);
    expr->tip=(struct tip_t*)malloc(sizeof(tip_expr));
    expr->tip=tip_expr;
    expr->val=val;
    return expr;
}
int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
}
