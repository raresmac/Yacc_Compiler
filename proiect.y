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
1) implementare typeof() si eval() (eval doar pt int uri)
^ plz u
astea pot si eu:
2) VAR: verificat ca id[nr]: id e vector | id: id nu e vector
3) verificat daca folosim tip_t dimensiune / numar anywhere. Probabil ar trebui pt vectori? dar nu e implementat nimic
4) la declarare vector, de verificat ca [nr] = lungimea listei (unde e cazul)
5) sa se inchida programul automat daca gaseste o linie gresita (nu am testat)
OBS:
-lista_op si lista_cond sa permita paranteze cum trebuie..nu am testat prea mult
-la final, sa stergem ce nu e folositor, daca e cazul
*/
int yylex();
int yyerror();

FILE *fisier_tabela;
FILE *fisier_functii;

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
    int dimensiune; //nr de elemente daca e vector
    int numar[1024]; //elementele din vector
};
struct valnr_t {
    struct tip_t *tip;
    float val;
};
struct param_t
{
    struct tip_t *tip;
	char *nume;
	bool cons;
};

struct var{
	int index;
	char *nume;
	struct tip_t *param;
};

struct simbol{
    enum{
        SIMBOL_VARIABILA,
        SIMBOL_FUNCTIE,
        SIMBOL_STRUCTURA,
        SIMBOL_CONST
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
struct var *initVar(char * val, int index, struct tip_t *param);
struct param_t *initTipParam(struct tip_t *tip, char *valm, bool cons);
struct lista_nr_t *initTipListNr(struct valnr_t* val);
struct lista_lit_t *initTipListLit(char* val);
struct lista_param_t *initTipListParam(struct param_t* val);
bool apelCorect(struct lista_param_t *arg, struct lista_param_t *param);
void insertConstTable(char *nume, struct tip_t *tip);
void insertVarTable(char *nume, struct tip_t *tip);
void insertVarListTable(struct lista_param_t *var);
void insertFuncTable(char *nume, struct tip_t *ret, struct lista_param_t *param);
void insertStructTable(char *nume, struct lista_param_t *param);
void printTable();
void isStruct(char * nume, struct var* comp);
bool varDefinita(char *nume);
void funDefinita(char *nume, struct lista_param_t *arg);
void varNotConst (char *nume);
bool structDefinita(char *nume);
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

%token <strval> LIT ID INT FLOAT CHAR BOOL STRING NEWTYPE IF ELSE WHILE FOR BGIN END DEFINE CONST TYPEOF GR LW ASSIGN PLUS MINUS ADD DEDUCT EQUAL DIV MOD AND OR NOT XOR EVAL MAIN TRU FALS RET UTYPE
%token <vali> NRI
%token <valf> NRF
%type <vali> BVAL
%type <tip> TIP lista_op operatie apel lista_cond cond declaratie_fct statement list
%type <lista_param_t> lista_param lista_arg declaratii
%type <param_t> param arg declaratie
%type <v> VAR
%type <lista_nr_t> lista_nr
%type <lista_lit_t> lista_lit
%type <valnr> NR

%start progr

%%
progr : optionale bloc{
                       printf("Sintaxă corectă\n");
                       if (corect) {
                         printf("Corect semantic\n");
                         printTable();
                       }
                       else
                       printf("Incorect semantic\n");
                   }
      ;
optionale : var_globale functii user_types {functie_curenta="main";}
      | functii user_types {functie_curenta="main";}
      | var_globale  user_types {functie_curenta="main";}
      | var_globale  functii {functie_curenta="main";}
      | user_types {functie_curenta="main";}
      | functii {functie_curenta="main";}
      | var_globale {functie_curenta="main";}
      ;
var_globale : declaratie ';' { 
                      if($1->cons) 
                          insertConstTable($1->nume,$1->tip); 
                      else
                           insertVarTable($1->nume,$1->tip);
            }
            | definitie
            | var_globale definitie 
            | var_globale declaratie ';' { 
                      if($2->cons) 
                          insertConstTable($2->nume,$2->tip); 
                      else
                           insertVarTable($2->nume,$2->tip);
            }
            ;
definitie : DEFINE ID NR { insertConstTable($2,$3->tip); }
          | DEFINE ID LIT { struct tip_t *tip_expr=initTip_t("char"); insertConstTable($2,tip_expr); }
          ; 
declaratii :  declaratie ';'{$$ = initTipListParam($1);}
	   | declaratii declaratie ';'{
                               $$=$1;
                               while($1->urmator)
                                   $1=$1->urmator;
                               $1->urmator=initTipListParam($2);
                             }
	   ;
declaratie : TIP ID ASSIGN LIT{
                              //$1->dimensiune = 1;
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, $1);
                              $$ = initTipParam($1,$2,0);
                              }
           | CONST TIP ID ASSIGN LIT{
                              structDefinita($2->nume);                              
                              //$1->dimensiune = 1;
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, $2);
                              $$ = initTipParam($2,$3,1);
                              }
           | TIP ID '[' ']' ASSIGN '{' lista_lit '}'{
                              //$1->dimensiune = 1;
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, $1);
                              $$ = initTipParam($1,$2,0);
                              }
           | TIP ID ASSIGN '{' lista_lit '}'{
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, $1);
                              $$ = initTipParam($1,$2,0);
                              }
           | TIP ID '[' NR ']' ASSIGN '{' lista_lit '}'{
                              //$1->dimensiune = $4;
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, $1);
                              $$ = initTipParam($1,$2,0);
                              }
           | CONST TIP ID '[' NR ']' ASSIGN '{' lista_lit '}'{
                              //$2->dimensiune = $5;
                              structDefinita($2->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, $2);
                              $$ = initTipParam($2,$3,1);
                              }
           | CONST TIP ID '[' ']' ASSIGN '{' lista_lit '}'{
                              structDefinita($2->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, $2);
                              $$ = initTipParam($2,$3,1);
                              }
           | CONST TIP ID ASSIGN '{' lista_lit '}'{
                              structDefinita($2->nume);
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, $2);
                              $$ = initTipParam($2,$3,1);
                              }
           | TIP ID {
                    structDefinita($1->nume);
                    $$ = initTipParam($1,$2,0);
                    }
           | TIP ID ASSIGN NR {
                              structDefinita($1->nume);
                              tipuriEgale($4->tip, $1);
                              $$ = initTipParam($1,$2,0);
                              }
           | CONST TIP ID ASSIGN NR {
                              structDefinita($2->nume);
                              tipuriEgale($5->tip, $2);
                              $$ = initTipParam($2,$3,1);
                              }
           
           | TIP ID '[' ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($1->nume);
                              tipuriEgale($7->tip,$1);
                              $$ = initTipParam($1,$2,0);
                              }      
           | TIP ID '[' NR ']'{
                              structDefinita($1->nume);
                              $$ = initTipParam($1,$2,0);
                              //$$->numar[$$->tip->dimensiune] = $4; 
                              //$$->tip->dimensiune += 1;
                              }
           | TIP ID '[' NR ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($1->nume);
                              tipuriEgale($1, $8->tip);
                              $$ = initTipParam($1,$2,0);
                              //$$->numar[$$->tip->dimensiune] = $4; 
                              //$$->tip->dimensiune += 1;
                              }
           | CONST TIP ID '[' ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($2->nume);
                              tipuriEgale($8->tip, $2);
                              $$ = initTipParam($2,$3,1);
                              }
           | CONST TIP ID '[' NR ']' ASSIGN '{' lista_nr '}'{
                              structDefinita($2->nume);
                              tipuriEgale($9->tip, $2);
                              $$ = initTipParam($2,$3,1);
                              //$$->numar[$$->tip->dimensiune] = $5; 
                              //$$->tip->dimensiune += 1;
                              }
           | TIP ID ASSIGN BVAL{
                              structDefinita($1->nume);
                              struct tip_t *tip_expr=initTip_t("bool");
                              tipuriEgale($1, tip_expr);
                              $$ = initTipParam($1,$2,0);
                              }
           | CONST TIP ID ASSIGN BVAL{
                              structDefinita($2->nume);
                              struct tip_t *tip_expr=initTip_t("bool");
                              tipuriEgale($2, tip_expr);
                              $$ = initTipParam($2,$3,1);
                              }                
           ;
BVAL : TRU { $$=1; }
     | FALS { $$=0; }
     ;
TIP : INT { $$=initTip_t($1); }
    | FLOAT { $$=initTip_t($1); }
    | CHAR { $$=initTip_t($1); }
    | STRING { $$=initTip_t($1); }
    | BOOL { $$=initTip_t($1); }
    | UTYPE ID { isStruct($2,NULL); structura_curenta=NULL; $$=initTip_t($2);}
    ;
user_types : user_type
           | user_types user_type
           ;
user_type : NEWTYPE ID '{' declaratii '}' {
                    insertStructTable($2, $4);
                    structura_curenta = $2;
                    insertVarListTable($4);
                    structura_curenta = NULL;
                }
          ;
functii : functie
        | functii functie
        ;
functie : declaratie_fct BGIN list END{ functie_curenta = NULL; tipuriEgale($1, $3);}
        ;
declaratie_fct : TIP ID '(' lista_param ')'{
               structDefinita($1->nume);
               functie_curenta = $2; 
               insertVarListTable($4);
               insertFuncTable($2, $1, $4);
               $$=$1;
           }
          ;
lista_param : param {$$ = initTipListParam($1);}
            | lista_param ',' param {
                               $$=$1;
                               while($1->urmator)
                                   $1=$1->urmator;
                               $1->urmator=initTipListParam($3);
                             }
            ;
param : TIP ID { $$ = initTipParam($1,$2,0); }
      | CONST TIP ID {  $$ = initTipParam($2,$3,1); }
      ;
list :  statement
     | list statement {if($1 && $2)tipuriEgale($1,$2); if($1) $$=$1; else if($2) $$=$2;}
     ;
VAR : ID {
         /*if($1->dimensiune > 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
         //de adaugat verificare daca nu e vector (nu am testat)
         $$=initVar($1, -1, 0);
         }
    | ID '[' NR ']'{
         //de adaugat verificare daca e vector (nu am testat)
         /*if($1->dimensiune <= 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
         $$=initVar($1, $3->val, 0);
         }
    | ID '[' VAR ']'{
         //de adaugat verificare daca e vector (nu am testat)
         /*if($1->dimensiune > 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
         struct tip_t *tip_expr=initTip_t("int");
         tipuriEgale(tip_expr, tipVar($3));
         $$=initVar($1, 1, 0);
         }
    | ID '.' VAR {
         //de adaugat verificare daca nu e vector (nu am testat)
         /*if($1->dimensiune > 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
          isStruct($1,$3);
          $$=initVar($1, -1, tipVar($3));
          structura_curenta=NULL;
         }
    | ID '[' NR ']' '.' VAR{
         //de adaugat verificare daca e vector (nu am testat)
         /*if($1->dimensiune <= 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
         isStruct($1,$6);
         $$=initVar($1, $3->val,tipVar($6));
         structura_curenta=NULL;
         }
    | ID '[' VAR ']' '.' VAR{
         //de adaugat verificare daca e vector (nu am testat)
         /*if($1->dimensiune > 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
         isStruct($1,$6);
         struct tip_t *tip_expr=initTip_t("int");
         tipuriEgale(tip_expr, tipVar($3));
         $$=initVar($1, 1,tipVar($6));
         structura_curenta=NULL;
         }
    ;
statement : VAR NEWVAL VAR ';' {
                         varDefinita($3->nume);
                         varNotConst($1->nume);
                         tipuriEgale(tipVar($3), tipVar($1));
                         $$=NULL;
                         }
          | VAR NEWVAL NR ';'  {
                         varNotConst($1->nume);
                         tipuriEgale($3->tip, tipVar($1));
                         $$=NULL;
                         }	 
          | VAR NEWVAL lista_op ';'{
                              varNotConst($1->nume);
                              tipuriEgale($3, tipVar($1));
                              $$=NULL;
                              }	
          | VAR NEWVAL apel ';' {
                                 varNotConst($1->nume);
                                 tipuriEgale(tipVar($1), $3);
                                 $$=NULL;
                          }
          | VAR NEWVAL BVAL ';' {
                                 varNotConst($1->nume);
                                 struct tip_t *tip_expr=initTip_t("bool");
                                 tipuriEgale(tipVar($1), tip_expr);    
                                 $$=NULL;
                          }
          | VAR NEWVAL lista_cond ';' {
                                 varNotConst($1->nume);
                                 struct tip_t *tip_expr=initTip_t("bool");
                                 tipuriEgale(tipVar($1), tip_expr);    
                                 $$=NULL;                           
                          }
          | declaratie	';'{ 
                      if($1->cons) 
                          insertConstTable($1->nume,$1->tip); 
                      else
                           insertVarTable($1->nume,$1->tip);
                      $$=NULL;
            }
          | IF '(' lista_cond ')' '{' list '}' {$$=$6;}
          | IF '(' lista_cond ')' '{' list '}' ELSE '{' list '}' {if($6) $$=$6; else if($10) $$=$10; else $$=NULL;}
          | FOR '(' statement '|' lista_cond '|' statement ')' '{' list '}' {$$=$10;}
          | FOR '(' statement '|' lista_cond '|' statement ')' statement {$$=$9;}
          | WHILE '(' lista_cond ')' '{' list '}' {$$=$6;}
          | WHILE '(' lista_cond ')' statement {$$=$5;}
          | EVAL '(' VAR ')' ';' {$$=NULL;}
          | EVAL '(' NR ')' ';' {if (corect){
                                                 printf("Rezultatul expresiei din eval este %f\n", $3->val);
                                             }
                                             else {printf("Valorile nu sunt de tip int\n");} $$=NULL;}
          | EVAL '(' lista_op ')' ';' {$$=NULL;}
          | TYPEOF '(' VAR ')' ';'  {
                                    $$=tipVar($3);
                                    printf("Tipul variabilei este %s",tipVar($3)->nume);
                                    }
          | TYPEOF '(' NR ')' ';' { //nu inteleg la ce faci typeof
                                  }
          | TYPEOF '(' LIT ')' ';' { //identic ca mai sus
                                    }
          | RET NR ';' { $$=$2->tip; }
          | RET LIT ';'{ struct tip_t *tip_expr=initTip_t("char"); $$=tip_expr; }
          | RET BVAL ';' { struct tip_t *tip_expr=initTip_t("bool"); $$=tip_expr; }
          | RET VAR ';' { varDefinita($2->nume); $$=tipVar($2);}
          ;
NEWVAL : ASSIGN
       | ADD
       | DEDUCT
       ;
lista_op : VAR operatie { varDefinita($1->nume); tipuriEgale($2, tipVar($1)); $$=$2;}
         | NR operatie {tipuriEgale($2, initTip_t("float")); $$=$2;}
         | apel operatie  { tipuriEgale($2, $1); }
         | lista_op operatie {tipuriEgale($1,$2);}
         | '(' lista_op ')' operatie {tipuriEgale($2,$4); $$=$2;}
         ;
operatie : OP VAR {varDefinita($2->nume);$$=tipVar($2);}
         | OP NR {$$=$2->tip;}
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
                               $$=$1;
                               while($1->urmator)
                                   $1=$1->urmator;
                               $1->urmator=initTipListParam($3);
                             }
          ;
arg : VAR { 
            varNotConst($1->nume);
            varDefinita($1->nume); 
            $$ = initTipParam(tipVar($1),$1->nume,0);
            }
    | VAR NEWVAL VAR {
                   varNotConst($1->nume);
                   varDefinita($3->nume);
                   tipuriEgale(tipVar($3), tipVar($1)); 
                   $$ = initTipParam(tipVar($1),$1->nume,0);
               }
    | VAR NEWVAL NR {
                   varNotConst($1->nume);
                   tipuriEgale($3->tip, tipVar($1));
                   $$ = initTipParam(tipVar($1),$1->nume,0);
               }
    | apel { $$ = initTipParam($1,"functie",0); } //to check is functie const
    ;
lista_cond : VAR cond { varDefinita($1->nume); tipuriEgale($2, tipVar($1)); }
           | NR cond { tipuriEgale($1->tip, $2); }
           | BVAL cond { struct tip_t *tip_expr=initTip_t("bool"); tipuriEgale(tip_expr, $2); }
           | LIT cond { struct tip_t *tip_expr=initTip_t("char"); tipuriEgale(tip_expr, $2); }
           | apel cond { tipuriEgale($2, $1); }
           | lista_cond cond {tipuriEgale($1,$2);}
           | '(' lista_cond ')' cond {tipuriEgale($2,$4); $$=$2;}
           ;
cond : OP_C VAR {varDefinita($2->nume); $$=tipVar($2);}
     | OP_C NR { $$=$2->tip; }
     | OP_C BVAL { struct tip_t *tip_expr=initTip_t("bool"); $$ = tip_expr;}
     | OP_C LIT { struct tip_t *tip_expr=initTip_t("char"); $$ = tip_expr;}
     ;
OP_C : AND
     | OR
     | NOT
     | EQUAL
     | XOR
     | GR
     | LW
     ;
NR: NRI { $$=InitNr("int",$1);}
  | MINUS NRI { $$=InitNr("int",-$2);}
  | MINUS NRF {$$=InitNr("float",-$2);}
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
            exit(0);
            break;
        }
    }
}
void insertVarListTable(struct lista_param_t *var){
    while(var!=NULL)
    {
        if(var->param->cons)
            insertConstTable(var->param->nume,var->param->tip);
        else
            insertVarTable(var->param->nume,var->param->tip);
        var=var->urmator;
    }
}
void insertConstTable(char *nume, struct tip_t *tip){
    checkTable(nume);
    
    SymbolTable[nrSimboluri].tip_simbol = SIMBOL_CONST;
    SymbolTable[nrSimboluri].nume = (char*) malloc(sizeof(char)*(strlen(nume)+1)); 
    strcpy(SymbolTable[nrSimboluri].nume,nume);
    SymbolTable[nrSimboluri].functie = functie_curenta;
    SymbolTable[nrSimboluri].structura = structura_curenta;
    SymbolTable[nrSimboluri].tip = tip;
    nrSimboluri++;
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
  fisier_functii = fopen("symbol_table_functions.txt", "w");
  for (int i = 0; i < nrSimboluri; ++i) {
      if (SymbolTable[i].tip_simbol == SIMBOL_VARIABILA || SymbolTable[i].tip_simbol == SIMBOL_CONST) {
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
          fprintf(fisier_functii, "%s\t", SymbolTable[i].nume);
          if (SymbolTable[i].tip != NULL)
              fprintf(fisier_functii, "%s", SymbolTable[i].tip->nume);
          else
              fprintf(fisier_functii, "void");
          fprintf(fisier_functii, "(");
          for (struct lista_param_t *j = SymbolTable[i].param; j != NULL; j = j->urmator) {
              printTip(fisier_functii, j->param->tip);
              if (j->urmator != NULL)
                  fprintf(fisier_functii, ", ");
          }
          fprintf(fisier_functii, ")\t");
          fprintf(fisier_functii, "\n");
      } 

  }
  fclose(fisier_tabela);
}

bool varDefinita(char *nume) {
    bool var=0;
    for (int i = 0; i < nrSimboluri; ++i) {
        if (strcmp(SymbolTable[i].nume, nume) == 0) {
            if(SymbolTable[i].tip_simbol == SIMBOL_VARIABILA) 
                var=1;
            else if (SymbolTable[i].tip_simbol == SIMBOL_CONST)
                var=0;
            else continue;
            if (SymbolTable[i].functie == NULL && SymbolTable[i].structura == NULL)
                return var;
            if (SymbolTable[i].functie == NULL && SymbolTable[i].structura != NULL &&
                structura_curenta != NULL &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0)
                return var;
            if (SymbolTable[i].functie != NULL && SymbolTable[i].structura == NULL &&
                structura_curenta == NULL && functie_curenta != NULL &&
                structura_curenta == NULL && strcmp(SymbolTable[i].functie, functie_curenta) == 0)
                return var;
            if (SymbolTable[i].functie != NULL && SymbolTable[i].structura != NULL &&
                functie_curenta != NULL && structura_curenta != NULL &&
                strcmp(SymbolTable[i].functie, functie_curenta) == 0 &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0)
                return var;
        } else if (functie_curenta != NULL &&
                   SymbolTable[i].tip_simbol == SIMBOL_FUNCTIE &&
                   strcmp(SymbolTable[i].nume, functie_curenta) == 0) {
            for (struct lista_param_t *j = SymbolTable[i].param; j != NULL; j = j->urmator) {
                if (strcmp(j->param->nume, nume) == 0)
                    return var;
            }
        }
    }
    corect = 0;
    printf("Variabila %s nu a fost definită\n", nume);
    exit(0);
    return 0;
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
    exit(0);
}
bool apelCorect(struct lista_param_t * arg, struct lista_param_t *param) {
    while (param != NULL && arg != NULL) {
        tipuriEgale(arg->param->tip, param->param->tip);
        param = param->urmator;
        arg = arg->urmator;
    }
    if (param != NULL || arg != NULL) {
        corect = 0;
        exit(0);
        return 0;
    }
    return 1;
}
bool structDefinita(char *nume) {
    if (strcmp(nume, "int") == 0 ||
        strcmp(nume, "float") == 0 ||
        strcmp(nume, "char") == 0 ||
        strcmp(nume, "string") == 0 ||
        strcmp(nume, "bool") == 0)
        return 0 ;
    for (int i = 0; i < nrSimboluri; ++i) {
        if (SymbolTable[i].tip_simbol == SIMBOL_STRUCTURA && strcmp(SymbolTable[i].nume, nume) == 0) {
            return 1;
        }
    }
    corect = 0;
    printf("Structura %s nu a fost definită\n", nume);
    exit(0);
    return 0;
}

struct tip_t *tipVar(struct var *v) {
    if(v->param)
        return v->param;
    struct tip_t *rezultat = NULL;
    for (int i = 0; i < nrSimboluri; ++i) {
        if ((SymbolTable[i].tip_simbol == SIMBOL_VARIABILA || SymbolTable[i].tip_simbol == SIMBOL_CONST)  && strcmp(SymbolTable[i].nume, v->nume) == 0) {
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
        exit(0);
    }
}
void varNotConst (char *nume){
    corect = 0;
    if(varDefinita(nume)==0 && corect)
    {
        corect=0;
        printf("Valoarea lui %s nu poate fi schimbata\n", nume);
        exit(0);
    } 
}
void isStruct(char * nume, struct var* comp){
    char * name;
    if(comp)
    {
        struct var* temp = initVar(nume, -1,0);
        struct tip_t* tip = tipVar(temp);
        name=tip->nume;
    }
    else
    {
        name=nume;
    }
    if(structDefinita(name))
    {
        if(comp)
        {
            structura_curenta=name;
            varDefinita(comp->nume);
            //structura_curenta=NULL;
            if(!corect)
            {
                printf("Variabila %s nu are membrul %s\n", nume, comp->nume);
                return;
            }    
            return;
        }
        else return;
    }
    else
    {
        if(comp)
        {
            corect=0;
            printf("Variabila %s nu are membrii. Nu e usertype\n", nume);
            exit(0);
            return;
        }
        else
        {
            corect=0;
            printf("%s nu e usertype\n", nume);
            exit(0);
            return;
        }
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
struct var * initVar(char * val, int index, struct tip_t* param)
{
    struct var* expr = (struct var*)malloc(sizeof(struct var));
    expr->nume = (char*) malloc(sizeof(char)*(strlen(val)+1)); 
    strcpy(expr->nume,val);
    expr->index=index;
    expr->param = (struct tip_t*)malloc(sizeof(param));
    expr->param = param;
    return expr;
}
struct param_t *initTipParam(struct tip_t *tip, char *val, bool cons)
{
    struct param_t* expr = (struct param_t*)malloc(sizeof(struct param_t));
    expr->nume = (char*) malloc(sizeof(char)*(strlen(val)+1)); 
    strcpy(expr->nume,val);
    expr->tip = (struct tip_t*)malloc(sizeof(tip));
    expr->tip=tip;
    expr->cons=cons;
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
