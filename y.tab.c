/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "proiect.y"

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

#line 176 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 324 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LIT = 3,                        /* LIT  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_STRING = 9,                     /* STRING  */
  YYSYMBOL_NEWTYPE = 10,                   /* NEWTYPE  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_BGIN = 15,                      /* BGIN  */
  YYSYMBOL_END = 16,                       /* END  */
  YYSYMBOL_DEFINE = 17,                    /* DEFINE  */
  YYSYMBOL_CONST = 18,                     /* CONST  */
  YYSYMBOL_TYPEOF = 19,                    /* TYPEOF  */
  YYSYMBOL_GR = 20,                        /* GR  */
  YYSYMBOL_LW = 21,                        /* LW  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_ADD = 25,                       /* ADD  */
  YYSYMBOL_DEDUCT = 26,                    /* DEDUCT  */
  YYSYMBOL_EQUAL = 27,                     /* EQUAL  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_MOD = 29,                       /* MOD  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_NOT = 32,                       /* NOT  */
  YYSYMBOL_XOR = 33,                       /* XOR  */
  YYSYMBOL_EVAL = 34,                      /* EVAL  */
  YYSYMBOL_MAIN = 35,                      /* MAIN  */
  YYSYMBOL_TRU = 36,                       /* TRU  */
  YYSYMBOL_FALS = 37,                      /* FALS  */
  YYSYMBOL_RET = 38,                       /* RET  */
  YYSYMBOL_UTYPE = 39,                     /* UTYPE  */
  YYSYMBOL_NRI = 40,                       /* NRI  */
  YYSYMBOL_NRF = 41,                       /* NRF  */
  YYSYMBOL_42_ = 42,                       /* ';'  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* ','  */
  YYSYMBOL_50_ = 50,                       /* '.'  */
  YYSYMBOL_51_ = 51,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_progr = 53,                     /* progr  */
  YYSYMBOL_var_globale = 54,               /* var_globale  */
  YYSYMBOL_definitie = 55,                 /* definitie  */
  YYSYMBOL_declaratii = 56,                /* declaratii  */
  YYSYMBOL_declaratie = 57,                /* declaratie  */
  YYSYMBOL_BVAL = 58,                      /* BVAL  */
  YYSYMBOL_TIP = 59,                       /* TIP  */
  YYSYMBOL_user_types = 60,                /* user_types  */
  YYSYMBOL_user_type = 61,                 /* user_type  */
  YYSYMBOL_functii = 62,                   /* functii  */
  YYSYMBOL_functie = 63,                   /* functie  */
  YYSYMBOL_declaratie_fct = 64,            /* declaratie_fct  */
  YYSYMBOL_lista_param = 65,               /* lista_param  */
  YYSYMBOL_param = 66,                     /* param  */
  YYSYMBOL_list = 67,                      /* list  */
  YYSYMBOL_VAR = 68,                       /* VAR  */
  YYSYMBOL_statement = 69,                 /* statement  */
  YYSYMBOL_NEWVAL = 70,                    /* NEWVAL  */
  YYSYMBOL_lista_op = 71,                  /* lista_op  */
  YYSYMBOL_operatie = 72,                  /* operatie  */
  YYSYMBOL_OP = 73,                        /* OP  */
  YYSYMBOL_apel = 74,                      /* apel  */
  YYSYMBOL_lista_arg = 75,                 /* lista_arg  */
  YYSYMBOL_arg = 76,                       /* arg  */
  YYSYMBOL_lista_cond = 77,                /* lista_cond  */
  YYSYMBOL_cond = 78,                      /* cond  */
  YYSYMBOL_OP_C = 79,                      /* OP_C  */
  YYSYMBOL_NR = 80,                        /* NR  */
  YYSYMBOL_lista_nr = 81,                  /* lista_nr  */
  YYSYMBOL_lista_lit = 82,                 /* lista_lit  */
  YYSYMBOL_bloc = 83                       /* bloc  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   716

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  292

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    48,     2,     2,    49,     2,    50,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    51,    46,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   133,   133,   141,   149,   157,   165,   173,   181,   189,
     198,   204,   205,   206,   213,   214,   216,   217,   224,   231,
     238,   245,   251,   258,   265,   271,   277,   281,   286,   292,
     297,   303,   310,   315,   322,   328,   335,   336,   338,   339,
     340,   341,   342,   343,   345,   346,   348,   355,   356,   358,
     360,   368,   369,   376,   377,   379,   380,   382,   390,   398,
     408,   417,   426,   438,   444,   449,   454,   459,   465,   471,
     478,   479,   480,   481,   482,   483,   484,   485,   489,   490,
     494,   496,   498,   499,   500,   501,   503,   504,   505,   507,
     508,   509,   510,   511,   513,   514,   515,   517,   518,   519,
     520,   522,   527,   528,   535,   540,   546,   551,   553,   554,
     555,   556,   557,   558,   559,   561,   562,   563,   564,   566,
     567,   568,   569,   570,   571,   572,   574,   575,   576,   577,
     579,   580,   586,   587,   592
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LIT", "ID", "INT",
  "FLOAT", "CHAR", "BOOL", "STRING", "NEWTYPE", "IF", "ELSE", "WHILE",
  "FOR", "BGIN", "END", "DEFINE", "CONST", "TYPEOF", "GR", "LW", "ASSIGN",
  "PLUS", "MINUS", "ADD", "DEDUCT", "EQUAL", "DIV", "MOD", "AND", "OR",
  "NOT", "XOR", "EVAL", "MAIN", "TRU", "FALS", "RET", "UTYPE", "NRI",
  "NRF", "';'", "'['", "']'", "'{'", "'}'", "'('", "')'", "','", "'.'",
  "'|'", "$accept", "progr", "var_globale", "definitie", "declaratii",
  "declaratie", "BVAL", "TIP", "user_types", "user_type", "functii",
  "functie", "declaratie_fct", "lista_param", "param", "list", "VAR",
  "statement", "NEWVAL", "lista_op", "operatie", "OP", "apel", "lista_arg",
  "arg", "lista_cond", "cond", "OP_C", "NR", "lista_nr", "lista_lit",
  "bloc", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-167)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     474,  -167,  -167,  -167,  -167,  -167,    19,    21,   215,    50,
      73,    82,   474,  -167,    49,    94,    68,  -167,   480,  -167,
      85,  -167,    60,    56,   106,   459,  -167,  -167,  -167,    70,
      68,   480,  -167,  -167,    93,  -167,  -167,   140,    68,  -167,
    -167,   459,   494,  -167,    31,  -167,  -167,  -167,   -17,    20,
      95,    99,   101,   108,   124,   255,   162,   201,   420,   249,
    -167,  -167,  -167,    68,  -167,   308,   245,   499,   159,  -167,
     437,   194,   172,  -167,  -167,   319,   364,   123,   212,   113,
     113,   459,     7,    26,   176,  -167,  -167,   183,   184,   185,
    -167,   -10,  -167,  -167,  -167,  -167,  -167,   121,  -167,  -167,
     235,  -167,  -167,   219,   208,   215,   253,   130,  -167,  -167,
    -167,   220,  -167,  -167,   235,  -167,  -167,   260,   239,   246,
     250,  -167,   683,   192,   113,   683,   683,   683,   519,   683,
     527,   277,   292,   294,   299,    26,   553,   555,   498,   562,
    -167,  -167,  -167,  -167,   121,   639,   593,   576,   609,   653,
     625,  -167,   -29,   307,   315,   350,  -167,  -167,   499,  -167,
      86,   316,   335,   313,   321,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,   374,   358,   541,  -167,  -167,  -167,   328,
    -167,  -167,   361,   113,   334,   339,   348,   498,   564,   498,
    -167,  -167,  -167,  -167,   351,  -167,   170,   352,  -167,  -167,
     359,  -167,   669,   669,   669,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,   399,   148,   362,  -167,  -167,  -167,   148,   368,
     212,   212,  -167,  -167,  -167,  -167,   249,  -167,   138,  -167,
     683,   459,   459,  -167,   504,  -167,  -167,  -167,   498,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,   127,   149,   148,
     238,   261,   148,  -167,  -167,   123,  -167,   358,  -167,   242,
     259,   459,  -167,  -167,   189,  -167,   266,   278,  -167,  -167,
     289,   290,  -167,  -167,  -167,   391,  -167,   370,  -167,  -167,
    -167,  -167,  -167,   375,   378,   459,   459,  -167,   295,   312,
    -167,  -167
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    38,    39,    40,    42,    41,     0,     0,     0,     0,
       0,     0,     0,    11,     0,     0,     0,    44,     0,    47,
       0,     9,     0,     0,     0,     0,    43,     1,    12,     0,
       0,     0,     8,    10,    26,    45,     6,     0,     0,    48,
       7,     0,     0,    15,     0,   126,   129,    14,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    13,     4,     0,     5,     0,     0,     0,     0,     3,
       0,     0,     0,   127,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,     0,     0,     0,
      69,    26,   134,    56,    86,    87,    88,     0,     2,    18,
       0,    34,    27,     0,     0,     0,     0,     0,    51,    49,
      46,     0,    16,    19,     0,    35,    28,     0,     0,     0,
       0,    60,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,    84,    85,    82,     0,     0,     0,     0,     0,     0,
       0,   132,     0,     0,    30,     0,    53,    50,     0,    17,
       0,     0,     0,    59,    58,   124,   125,   122,   119,   120,
     121,   123,   111,     0,     0,     0,   110,   108,   112,     0,
     113,   109,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,     0,    89,     0,     0,    92,    91,
       0,    90,     0,     0,     0,    67,    63,    65,    66,    68,
      64,    21,     0,     0,     0,    54,    52,    25,     0,     0,
       0,     0,   118,   117,   115,   116,   104,   107,     0,   102,
       0,     0,     0,    75,     0,    81,    79,    80,     0,    76,
      94,    96,    95,    78,    77,   133,   130,     0,     0,     0,
       0,     0,     0,    62,    61,     0,   101,     0,   114,     0,
       0,     0,    93,    29,     0,    20,     0,     0,    32,    24,
       0,     0,   105,   106,   103,    70,    74,     0,   131,    31,
      22,    33,    23,     0,     0,     0,     0,    73,     0,     0,
      71,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,   397,  -167,    16,   -51,     1,   165,    11,
     407,    33,  -167,  -167,   263,   -41,   -40,   -52,   196,   -76,
     -19,  -167,   -75,  -167,   173,   -44,   -37,  -167,   -21,  -166,
    -111,    63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,    12,    13,    71,    56,   125,    57,    16,    17,
      18,    19,    20,   107,   108,    58,    59,    60,    97,   188,
     195,   196,   127,   228,   229,   175,   180,   173,   129,   247,
     152,    21
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,    15,    47,   160,    87,    75,    93,   137,   138,    24,
     132,    49,    65,    15,   101,    88,    14,   211,    93,    37,
     212,   147,   148,    22,   115,    23,    76,    35,    29,   131,
     123,    44,    37,    66,    89,   128,   130,   119,   121,   126,
     126,    35,   133,   136,   102,   104,   145,    45,    46,    35,
      44,    39,   250,   149,   116,   118,   120,   146,    72,    43,
     138,   134,   139,    77,    39,    25,    45,    46,   106,   203,
      78,    73,    74,   135,    35,    32,   150,    26,     6,    36,
      44,    40,    27,   266,   126,   172,   270,   111,   176,   177,
     178,    33,   181,    62,    64,   187,    45,    46,    34,   227,
      41,    69,   248,     9,   202,    42,   155,   251,   176,   177,
      48,   178,    61,   181,   189,    65,   122,   123,   198,   199,
     201,   241,   223,   204,   122,   123,    98,    49,   198,   199,
     233,   201,   217,   224,   226,   212,    66,    44,   267,   234,
      67,   271,    79,   126,    68,    44,    80,    44,    81,    85,
      86,   151,   225,    45,    46,    82,   240,    85,    86,   106,
     124,    45,    46,    45,    46,   177,   178,   181,   144,   198,
     201,    83,    44,   263,   123,   242,   264,    30,   157,   158,
     253,   254,   227,    38,   199,   201,   256,   257,    45,    46,
     259,   260,   246,   258,    44,   265,    63,   246,   212,     1,
       2,     3,     4,     5,    90,    91,    67,    93,    93,   277,
      45,    46,     8,    44,   112,   272,    49,   226,   140,   262,
       1,     2,     3,     4,     5,   141,   142,   143,   246,    45,
      46,   246,   287,    10,   273,    77,    93,    93,   151,   174,
     110,   153,    78,   278,   288,   289,    49,     1,     2,     3,
       4,     5,   154,    50,    10,    51,    52,   156,    84,    49,
       8,    53,   159,    49,     1,     2,     3,     4,     5,    44,
      50,    94,    51,    52,    95,    96,    54,     8,    53,    44,
      55,    10,   161,   162,   268,    45,    46,   264,   275,   103,
     163,    85,    86,    54,   164,    45,    46,    55,    10,    49,
       1,     2,     3,     4,     5,   276,    50,   269,    51,    52,
     212,    99,   279,     8,    53,   264,    49,     1,     2,     3,
       4,     5,   113,    50,   280,    51,    52,   212,   183,    54,
       8,    53,    44,    55,    10,   281,   282,   214,   264,   212,
     184,   290,   185,    44,    85,    86,    54,   186,    45,    46,
      55,    10,   213,   100,   215,    85,    86,   219,   291,    45,
      46,   218,   123,   220,   114,    49,     1,     2,     3,     4,
       5,   221,    50,   231,    51,    52,   235,   222,    49,     8,
      53,   236,    49,     1,     2,     3,     4,     5,    44,    50,
     237,    51,    52,   239,   243,    54,     8,    53,    44,    55,
      10,   244,   245,   283,    45,    46,   232,   249,   117,    28,
      85,    86,    54,   252,    45,    46,    55,    10,   284,    31,
     285,   216,   255,   286,    49,     1,     2,     3,     4,     5,
     274,    50,     0,    51,    52,     0,    92,     0,     8,    53,
       0,    49,     1,     2,     3,     4,     5,     0,    50,     0,
      51,    52,     0,   109,    54,     8,    53,     0,    55,    10,
       0,     0,     0,    49,     1,     2,     3,     4,     5,     0,
      50,    54,    51,    52,     0,    55,    10,     8,    53,     1,
       2,     3,     4,     5,     6,     1,     2,     3,     4,     5,
       6,     7,     8,    54,     0,     0,     0,    55,    10,     1,
       2,     3,     4,     5,     1,     2,     3,     4,     5,     9,
       0,     0,     8,    10,     0,     9,     0,   105,     0,    10,
       0,   190,   191,     0,   165,   166,   192,   193,     0,     0,
       0,   167,     0,    10,   168,   169,   170,   171,    10,   165,
     166,     0,     0,     0,     0,     0,   167,   165,   166,   168,
     169,   170,   171,     0,   167,   261,     0,   168,   169,   170,
     171,   165,   166,     0,     0,     0,     0,   179,   167,     0,
       0,   168,   169,   170,   171,   182,   190,   191,   190,   191,
       0,   192,   193,   192,   193,   190,   191,   190,   191,   230,
     192,   193,   192,   193,     0,     0,     0,     0,     0,   190,
     191,   194,     0,   197,   192,   193,     0,     0,     0,     0,
     200,     0,   238,   165,   166,     0,   190,   191,   207,     0,
     167,   192,   193,   168,   169,   170,   171,     0,     0,   165,
     166,     0,   190,   191,     0,   206,   167,   192,   193,   168,
     169,   170,   171,     0,     0,   165,   166,     0,   190,   191,
       0,   208,   167,   192,   193,   168,   169,   170,   171,   165,
     166,     0,     0,     0,     0,     0,   167,   210,     0,   168,
     169,   170,   171,   165,   166,     0,     0,     0,     0,     0,
     167,   205,     0,   168,   169,   170,   171,     0,     0,   165,
     166,     0,   190,   191,     0,   209,   167,   192,   193,   168,
     169,   170,   171,   165,   166,     0,     0,     0,     0,     0,
     167,     0,     0,   168,   169,   170,   171
};

static const yytype_int16 yycheck[] =
{
      41,     0,    23,   114,    55,    22,    58,    83,    83,     8,
       3,     4,    22,    12,    65,    55,     0,    46,    70,    18,
      49,    97,    97,     4,    75,     4,    43,    16,    12,    81,
       4,    24,    31,    43,    55,    79,    80,    77,    78,    79,
      80,    30,    82,    83,    65,    66,    97,    40,    41,    38,
      24,    18,   218,    97,    75,    76,    77,    97,    42,     3,
     135,    82,    83,    43,    31,    15,    40,    41,    67,   144,
      50,    40,    41,    47,    63,    12,    97,     4,    10,    16,
      24,    18,     0,   249,   124,   122,   252,    71,   125,   126,
     127,    42,   129,    30,    31,   135,    40,    41,     4,   174,
      15,    38,   213,    35,   144,    45,   105,   218,   145,   146,
       4,   148,    42,   150,   135,    22,     3,     4,   137,   138,
     139,   196,   173,   144,     3,     4,    63,     4,   147,   148,
     182,   150,    46,   173,   174,    49,    43,    24,   249,   183,
      47,   252,    47,   183,     4,    24,    47,    24,    47,    36,
      37,     3,   173,    40,    41,    47,   196,    36,    37,   158,
      47,    40,    41,    40,    41,   202,   203,   204,    47,   188,
     189,    47,    24,    46,     4,   196,    49,    12,    48,    49,
     220,   221,   257,    18,   203,   204,    48,    49,    40,    41,
     231,   232,   213,   230,    24,    46,    31,   218,    49,     5,
       6,     7,     8,     9,    42,     4,    47,   259,   260,   261,
      40,    41,    18,    24,    42,   255,     4,   257,    42,   238,
       5,     6,     7,     8,     9,    42,    42,    42,   249,    40,
      41,   252,   284,    39,   255,    43,   288,   289,     3,    47,
      46,    22,    50,   264,   285,   286,     4,     5,     6,     7,
       8,     9,    44,    11,    39,    13,    14,     4,     3,     4,
      18,    19,    42,     4,     5,     6,     7,     8,     9,    24,
      11,    22,    13,    14,    25,    26,    34,    18,    19,    24,
      38,    39,    22,    44,    46,    40,    41,    49,    46,    44,
      44,    36,    37,    34,    44,    40,    41,    38,    39,     4,
       5,     6,     7,     8,     9,    46,    11,    46,    13,    14,
      49,     3,    46,    18,    19,    49,     4,     5,     6,     7,
       8,     9,     3,    11,    46,    13,    14,    49,    51,    34,
      18,    19,    24,    38,    39,    46,    46,    22,    49,    49,
      48,    46,    48,    24,    36,    37,    34,    48,    40,    41,
      38,    39,    45,    45,     4,    36,    37,    22,    46,    40,
      41,    45,     4,    50,    45,     4,     5,     6,     7,     8,
       9,    50,    11,    45,    13,    14,    42,     3,     4,    18,
      19,    42,     4,     5,     6,     7,     8,     9,    24,    11,
      42,    13,    14,    42,    42,    34,    18,    19,    24,    38,
      39,    42,     3,    12,    40,    41,    45,    45,    44,    12,
      36,    37,    34,    45,    40,    41,    38,    39,    48,    12,
      45,   158,   226,    45,     4,     5,     6,     7,     8,     9,
     257,    11,    -1,    13,    14,    -1,    16,    -1,    18,    19,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    -1,
      13,    14,    -1,    16,    34,    18,    19,    -1,    38,    39,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    -1,
      11,    34,    13,    14,    -1,    38,    39,    18,    19,     5,
       6,     7,     8,     9,    10,     5,     6,     7,     8,     9,
      10,    17,    18,    34,    -1,    -1,    -1,    38,    39,     5,
       6,     7,     8,     9,     5,     6,     7,     8,     9,    35,
      -1,    -1,    18,    39,    -1,    35,    -1,    18,    -1,    39,
      -1,    23,    24,    -1,    20,    21,    28,    29,    -1,    -1,
      -1,    27,    -1,    39,    30,    31,    32,    33,    39,    20,
      21,    -1,    -1,    -1,    -1,    -1,    27,    20,    21,    30,
      31,    32,    33,    -1,    27,    51,    -1,    30,    31,    32,
      33,    20,    21,    -1,    -1,    -1,    -1,    48,    27,    -1,
      -1,    30,    31,    32,    33,    48,    23,    24,    23,    24,
      -1,    28,    29,    28,    29,    23,    24,    23,    24,    48,
      28,    29,    28,    29,    -1,    -1,    -1,    -1,    -1,    23,
      24,    48,    -1,    48,    28,    29,    -1,    -1,    -1,    -1,
      48,    -1,    48,    20,    21,    -1,    23,    24,    42,    -1,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    20,
      21,    -1,    23,    24,    -1,    42,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    20,    21,    -1,    23,    24,
      -1,    42,    27,    28,    29,    30,    31,    32,    33,    20,
      21,    -1,    -1,    -1,    -1,    -1,    27,    42,    -1,    30,
      31,    32,    33,    20,    21,    -1,    -1,    -1,    -1,    -1,
      27,    42,    -1,    30,    31,    32,    33,    -1,    -1,    20,
      21,    -1,    23,    24,    -1,    42,    27,    28,    29,    30,
      31,    32,    33,    20,    21,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    17,    18,    35,
      39,    53,    54,    55,    57,    59,    60,    61,    62,    63,
      64,    83,     4,     4,    59,    15,     4,     0,    55,    57,
      60,    62,    83,    42,     4,    61,    83,    59,    60,    63,
      83,    15,    45,     3,    24,    40,    41,    80,     4,     4,
      11,    13,    14,    19,    34,    38,    57,    59,    67,    68,
      69,    42,    83,    60,    83,    22,    43,    47,     4,    83,
      67,    56,    57,    40,    41,    22,    43,    43,    50,    47,
      47,    47,    47,    47,     3,    36,    37,    58,    68,    80,
      42,     4,    16,    69,    22,    25,    26,    70,    83,     3,
      45,    58,    80,    44,    80,    18,    59,    65,    66,    16,
      46,    57,    42,     3,    45,    58,    80,    44,    80,    68,
      80,    68,     3,     4,    47,    58,    68,    74,    77,    80,
      77,    69,     3,    68,    80,    47,    68,    71,    74,    80,
      42,    42,    42,    42,    47,    58,    68,    71,    74,    77,
      80,     3,    82,    22,    44,    59,     4,    48,    49,    42,
      82,    22,    44,    44,    44,    20,    21,    27,    30,    31,
      32,    33,    78,    79,    47,    77,    78,    78,    78,    48,
      78,    78,    48,    51,    48,    48,    48,    68,    71,    80,
      23,    24,    28,    29,    48,    72,    73,    48,    72,    72,
      48,    72,    68,    74,    80,    42,    42,    42,    42,    42,
      42,    46,    49,    45,    22,     4,    66,    46,    45,    22,
      50,    50,     3,    58,    68,    80,    68,    74,    75,    76,
      48,    45,    45,    69,    77,    42,    42,    42,    48,    42,
      68,    74,    80,    42,    42,     3,    80,    81,    82,    45,
      81,    82,    45,    68,    68,    70,    48,    49,    78,    67,
      67,    51,    72,    46,    49,    46,    81,    82,    46,    46,
      81,    82,    68,    80,    76,    46,    46,    69,    80,    46,
      46,    46,    46,    12,    48,    45,    45,    69,    67,    67,
      46,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    55,    55,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    62,    62,    63,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    70,    70,    71,
      71,    71,    71,    71,    72,    72,    72,    73,    73,    73,
      73,    74,    75,    75,    76,    76,    76,    76,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    80,    80,    80,    80,
      81,    81,    82,    82,    83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     3,     2,     2,     2,     1,
       2,     1,     2,     3,     3,     3,     2,     3,     4,     5,
       8,     6,     9,    10,     9,     7,     2,     4,     5,     8,
       5,     9,     9,    10,     4,     5,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     5,     1,     2,     4,
       5,     1,     3,     2,     3,     1,     2,     1,     4,     4,
       3,     6,     6,     4,     4,     4,     4,     4,     4,     2,
       7,    11,    11,     9,     7,     5,     5,     5,     5,     5,
       5,     5,     3,     3,     3,     3,     1,     1,     1,     2,
       2,     2,     2,     4,     2,     2,     2,     1,     1,     1,
       1,     4,     1,     3,     1,     3,     3,     1,     2,     2,
       2,     2,     2,     2,     4,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     3,     1,     3,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* progr: var_globale functii user_types bloc  */
#line 133 "proiect.y"
                                             {printf("Sintaxă corectă\n");
                                             if (corect) {
                                             printf("Corect semantic\n");
                                             printTable();
                                             }
                                             else
                                             printf("Incorect semantic\n");
                                             }
#line 1667 "y.tab.c"
    break;

  case 3: /* progr: functii user_types bloc  */
#line 141 "proiect.y"
                                {printf("Sintaxă corectă\n");
                              if (corect) {
                              printf("Corect semantic\n");
                              printTable();
                              }
                              else
                              printf("Incorect semantic\n");
                              }
#line 1680 "y.tab.c"
    break;

  case 4: /* progr: var_globale user_types bloc  */
#line 149 "proiect.y"
                                     {printf("Sintaxă corectă\n");
                                   if (corect) {
                                   printf("Corect semantic\n");
                                   printTable();
                                   }
                                   else
                                   printf("Incorect semantic\n");
                                   }
#line 1693 "y.tab.c"
    break;

  case 5: /* progr: var_globale functii bloc  */
#line 157 "proiect.y"
                                  {printf("Sintaxă corectă\n");
                                   if (corect) {
                                   printf("Corect semantic\n");
                                   printTable();
                                   }
                                   else
                                   printf("Incorect semantic\n");
                                   }
#line 1706 "y.tab.c"
    break;

  case 6: /* progr: user_types bloc  */
#line 165 "proiect.y"
                        {printf("Sintaxă corectă\n");
                         if (corect) {
                         printf("Corect semantic\n");
                         printTable();
                         }
                         else
                         printf("Incorect semantic\n");
                         }
#line 1719 "y.tab.c"
    break;

  case 7: /* progr: functii bloc  */
#line 173 "proiect.y"
                     {printf("Sintaxă corectă\n");
                    if (corect) {
                    printf("Corect semantic\n");
                    printTable();
                    }
                    else
                    printf("Incorect semantic\n");
                    }
#line 1732 "y.tab.c"
    break;

  case 8: /* progr: var_globale bloc  */
#line 181 "proiect.y"
                          {printf("Sintaxă corectă\n");
                         if (corect) {
                         printf("Corect semantic\n");
                         printTable();
                         }
                         else
                         printf("Incorect semantic\n");
                         }
#line 1745 "y.tab.c"
    break;

  case 9: /* progr: bloc  */
#line 189 "proiect.y"
             {printf("Sintaxă corectă\n");
              if (corect) {
               printf("Corect semantic\n");
               printTable();
               }
               else
               printf("Incorect semantic\n");
               }
#line 1758 "y.tab.c"
    break;

  case 10: /* var_globale: declaratie ';'  */
#line 198 "proiect.y"
                             { 
                      if((yyvsp[-1].param_t)->cons) 
                          insertConstTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip); 
                      else
                           insertVarTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip);
            }
#line 1769 "y.tab.c"
    break;

  case 13: /* var_globale: var_globale declaratie ';'  */
#line 206 "proiect.y"
                                         { 
                      if((yyvsp[-1].param_t)->cons) 
                          insertConstTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip); 
                      else
                           insertVarTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip);
            }
#line 1780 "y.tab.c"
    break;

  case 14: /* definitie: DEFINE ID NR  */
#line 213 "proiect.y"
                         { insertConstTable((yyvsp[-1].strval),(yyvsp[0].valnr)->tip); }
#line 1786 "y.tab.c"
    break;

  case 15: /* definitie: DEFINE ID LIT  */
#line 214 "proiect.y"
                          { struct tip_t *tip_expr=initTip_t("char"); insertConstTable((yyvsp[-1].strval),tip_expr); }
#line 1792 "y.tab.c"
    break;

  case 16: /* declaratii: declaratie ';'  */
#line 216 "proiect.y"
                            {(yyval.lista_param_t) = initTipListParam((yyvsp[-1].param_t));}
#line 1798 "y.tab.c"
    break;

  case 17: /* declaratii: declaratii declaratie ';'  */
#line 217 "proiect.y"
                                      {
                               (yyval.lista_param_t)=(yyvsp[-2].lista_param_t);
                               while((yyvsp[-2].lista_param_t)->urmator)
                                   (yyvsp[-2].lista_param_t)=(yyvsp[-2].lista_param_t)->urmator;
                               (yyvsp[-2].lista_param_t)->urmator=initTipListParam((yyvsp[-1].param_t));
                             }
#line 1809 "y.tab.c"
    break;

  case 18: /* declaratie: TIP ID ASSIGN LIT  */
#line 224 "proiect.y"
                              {
                              //$1->dimensiune = 1;
                              structDefinita((yyvsp[-3].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),0);
                              }
#line 1821 "y.tab.c"
    break;

  case 19: /* declaratie: CONST TIP ID ASSIGN LIT  */
#line 231 "proiect.y"
                                    {
                              structDefinita((yyvsp[-3].tip)->nume);                              
                              //$1->dimensiune = 1;
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),1);
                              }
#line 1833 "y.tab.c"
    break;

  case 20: /* declaratie: TIP ID '[' ']' ASSIGN '{' lista_lit '}'  */
#line 238 "proiect.y"
                                                    {
                              //$1->dimensiune = 1;
                              structDefinita((yyvsp[-7].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),0);
                              }
#line 1845 "y.tab.c"
    break;

  case 21: /* declaratie: TIP ID ASSIGN '{' lista_lit '}'  */
#line 245 "proiect.y"
                                            {
                              structDefinita((yyvsp[-5].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, (yyvsp[-5].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-5].tip),(yyvsp[-4].strval),0);
                              }
#line 1856 "y.tab.c"
    break;

  case 22: /* declaratie: TIP ID '[' NR ']' ASSIGN '{' lista_lit '}'  */
#line 251 "proiect.y"
                                                       {
                              //$1->dimensiune = $4;
                              structDefinita((yyvsp[-8].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-8].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),0);
                              }
#line 1868 "y.tab.c"
    break;

  case 23: /* declaratie: CONST TIP ID '[' NR ']' ASSIGN '{' lista_lit '}'  */
#line 258 "proiect.y"
                                                             {
                              //$2->dimensiune = $5;
                              structDefinita((yyvsp[-8].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-8].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),1);
                              }
#line 1880 "y.tab.c"
    break;

  case 24: /* declaratie: CONST TIP ID '[' ']' ASSIGN '{' lista_lit '}'  */
#line 265 "proiect.y"
                                                          {
                              structDefinita((yyvsp[-7].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),1);
                              }
#line 1891 "y.tab.c"
    break;

  case 25: /* declaratie: CONST TIP ID ASSIGN '{' lista_lit '}'  */
#line 271 "proiect.y"
                                                  {
                              structDefinita((yyvsp[-5].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, (yyvsp[-5].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-5].tip),(yyvsp[-4].strval),1);
                              }
#line 1902 "y.tab.c"
    break;

  case 26: /* declaratie: TIP ID  */
#line 277 "proiect.y"
                    {
                    structDefinita((yyvsp[-1].tip)->nume);
                    (yyval.param_t) = initTipParam((yyvsp[-1].tip),(yyvsp[0].strval),0);
                    }
#line 1911 "y.tab.c"
    break;

  case 27: /* declaratie: TIP ID ASSIGN NR  */
#line 281 "proiect.y"
                              {
                              structDefinita((yyvsp[-3].tip)->nume);
                              tipuriEgale((yyvsp[0].valnr)->tip, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),0);
                              }
#line 1921 "y.tab.c"
    break;

  case 28: /* declaratie: CONST TIP ID ASSIGN NR  */
#line 286 "proiect.y"
                                    {
                              structDefinita((yyvsp[-3].tip)->nume);
                              tipuriEgale((yyvsp[0].valnr)->tip, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),1);
                              }
#line 1931 "y.tab.c"
    break;

  case 29: /* declaratie: TIP ID '[' ']' ASSIGN '{' lista_nr '}'  */
#line 292 "proiect.y"
                                                   {
                              structDefinita((yyvsp[-7].tip)->nume);
                              tipuriEgale((yyvsp[-1].lista_nr_t)->tip,(yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),0);
                              }
#line 1941 "y.tab.c"
    break;

  case 30: /* declaratie: TIP ID '[' NR ']'  */
#line 297 "proiect.y"
                              {
                              structDefinita((yyvsp[-4].tip)->nume);
                              (yyval.param_t) = initTipParam((yyvsp[-4].tip),(yyvsp[-3].strval),0);
                              //$$->numar[$$->tip->dimensiune] = $4; 
                              //$$->tip->dimensiune += 1;
                              }
#line 1952 "y.tab.c"
    break;

  case 31: /* declaratie: TIP ID '[' NR ']' ASSIGN '{' lista_nr '}'  */
#line 303 "proiect.y"
                                                      {
                              structDefinita((yyvsp[-8].tip)->nume);
                              tipuriEgale((yyvsp[-8].tip), (yyvsp[-1].lista_nr_t)->tip);
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),0);
                              //$$->numar[$$->tip->dimensiune] = $4; 
                              //$$->tip->dimensiune += 1;
                              }
#line 1964 "y.tab.c"
    break;

  case 32: /* declaratie: CONST TIP ID '[' ']' ASSIGN '{' lista_nr '}'  */
#line 310 "proiect.y"
                                                         {
                              structDefinita((yyvsp[-7].tip)->nume);
                              tipuriEgale((yyvsp[-1].lista_nr_t)->tip, (yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),1);
                              }
#line 1974 "y.tab.c"
    break;

  case 33: /* declaratie: CONST TIP ID '[' NR ']' ASSIGN '{' lista_nr '}'  */
#line 315 "proiect.y"
                                                            {
                              structDefinita((yyvsp[-8].tip)->nume);
                              tipuriEgale((yyvsp[-1].lista_nr_t)->tip, (yyvsp[-8].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),1);
                              //$$->numar[$$->tip->dimensiune] = $5; 
                              //$$->tip->dimensiune += 1;
                              }
#line 1986 "y.tab.c"
    break;

  case 34: /* declaratie: TIP ID ASSIGN BVAL  */
#line 322 "proiect.y"
                               {
                              structDefinita((yyvsp[-3].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("bool");
                              tipuriEgale((yyvsp[-3].tip), tip_expr);
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),0);
                              }
#line 1997 "y.tab.c"
    break;

  case 35: /* declaratie: CONST TIP ID ASSIGN BVAL  */
#line 328 "proiect.y"
                                     {
                              structDefinita((yyvsp[-3].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("bool");
                              tipuriEgale((yyvsp[-3].tip), tip_expr);
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),1);
                              }
#line 2008 "y.tab.c"
    break;

  case 36: /* BVAL: TRU  */
#line 335 "proiect.y"
           { (yyval.vali)=1; }
#line 2014 "y.tab.c"
    break;

  case 37: /* BVAL: FALS  */
#line 336 "proiect.y"
            { (yyval.vali)=0; }
#line 2020 "y.tab.c"
    break;

  case 38: /* TIP: INT  */
#line 338 "proiect.y"
          { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 2026 "y.tab.c"
    break;

  case 39: /* TIP: FLOAT  */
#line 339 "proiect.y"
            { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 2032 "y.tab.c"
    break;

  case 40: /* TIP: CHAR  */
#line 340 "proiect.y"
           { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 2038 "y.tab.c"
    break;

  case 41: /* TIP: STRING  */
#line 341 "proiect.y"
             { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 2044 "y.tab.c"
    break;

  case 42: /* TIP: BOOL  */
#line 342 "proiect.y"
           { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 2050 "y.tab.c"
    break;

  case 43: /* TIP: UTYPE ID  */
#line 343 "proiect.y"
               { isStruct((yyvsp[0].strval),NULL); (yyval.tip)=initTip_t((yyvsp[0].strval));}
#line 2056 "y.tab.c"
    break;

  case 46: /* user_type: NEWTYPE ID '{' declaratii '}'  */
#line 348 "proiect.y"
                                          {
                    insertStructTable((yyvsp[-3].strval), (yyvsp[-1].lista_param_t));
                    structura_curenta = (yyvsp[-3].strval);
                    insertVarListTable((yyvsp[-1].lista_param_t));
                    structura_curenta = NULL;
                }
#line 2067 "y.tab.c"
    break;

  case 49: /* functie: declaratie_fct BGIN list END  */
#line 358 "proiect.y"
                                      { functie_curenta = NULL; tipuriEgale((yyvsp[-3].tip), (yyvsp[-1].tip));}
#line 2073 "y.tab.c"
    break;

  case 50: /* declaratie_fct: TIP ID '(' lista_param ')'  */
#line 360 "proiect.y"
                                           {
               structDefinita((yyvsp[-4].tip)->nume);
               functie_curenta = (yyvsp[-3].strval); 
               insertVarListTable((yyvsp[-1].lista_param_t));
               insertFuncTable((yyvsp[-3].strval), (yyvsp[-4].tip), (yyvsp[-1].lista_param_t));
               (yyval.tip)=(yyvsp[-4].tip);
           }
#line 2085 "y.tab.c"
    break;

  case 51: /* lista_param: param  */
#line 368 "proiect.y"
                    {(yyval.lista_param_t) = initTipListParam((yyvsp[0].param_t));}
#line 2091 "y.tab.c"
    break;

  case 52: /* lista_param: lista_param ',' param  */
#line 369 "proiect.y"
                                    {
                               (yyval.lista_param_t)=(yyvsp[-2].lista_param_t);
                               while((yyvsp[-2].lista_param_t)->urmator)
                                   (yyvsp[-2].lista_param_t)=(yyvsp[-2].lista_param_t)->urmator;
                               (yyvsp[-2].lista_param_t)->urmator=initTipListParam((yyvsp[0].param_t));
                             }
#line 2102 "y.tab.c"
    break;

  case 53: /* param: TIP ID  */
#line 376 "proiect.y"
               { (yyval.param_t) = initTipParam((yyvsp[-1].tip),(yyvsp[0].strval),0); }
#line 2108 "y.tab.c"
    break;

  case 54: /* param: CONST TIP ID  */
#line 377 "proiect.y"
                     {  (yyval.param_t) = initTipParam((yyvsp[-1].tip),(yyvsp[0].strval),1); }
#line 2114 "y.tab.c"
    break;

  case 56: /* list: list statement  */
#line 380 "proiect.y"
                      {if((yyvsp[-1].tip) && (yyvsp[0].tip))tipuriEgale((yyvsp[-1].tip),(yyvsp[0].tip)); if((yyvsp[-1].tip)) (yyval.tip)=(yyvsp[-1].tip); else if((yyvsp[0].tip)) (yyval.tip)=(yyvsp[0].tip);}
#line 2120 "y.tab.c"
    break;

  case 57: /* VAR: ID  */
#line 382 "proiect.y"
         {
         /*if($1->dimensiune > 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
         //de adaugat verificare daca nu e vector (nu am testat)
         (yyval.v)=initVar((yyvsp[0].strval), -1, 0);
         }
#line 2133 "y.tab.c"
    break;

  case 58: /* VAR: ID '[' NR ']'  */
#line 390 "proiect.y"
                   {
         //de adaugat verificare daca e vector (nu am testat)
         /*if($1->dimensiune <= 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
         (yyval.v)=initVar((yyvsp[-3].strval), (yyvsp[-1].valnr)->val, 0);
         }
#line 2146 "y.tab.c"
    break;

  case 59: /* VAR: ID '[' VAR ']'  */
#line 398 "proiect.y"
                    {
         //de adaugat verificare daca e vector (nu am testat)
         /*if($1->dimensiune > 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
         struct tip_t *tip_expr=initTip_t("int");
         tipuriEgale(tip_expr, tipVar((yyvsp[-1].v)));
         (yyval.v)=initVar((yyvsp[-3].strval), 1, 0);
         }
#line 2161 "y.tab.c"
    break;

  case 60: /* VAR: ID '.' VAR  */
#line 408 "proiect.y"
                 {
         //de adaugat verificare daca nu e vector (nu am testat)
         /*if($1->dimensiune > 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
          isStruct((yyvsp[-2].strval),(yyvsp[0].v));
          (yyval.v)=initVar((yyvsp[-2].strval), -1, tipVar((yyvsp[0].v)));
         }
#line 2175 "y.tab.c"
    break;

  case 61: /* VAR: ID '[' NR ']' '.' VAR  */
#line 417 "proiect.y"
                           {
         //de adaugat verificare daca e vector (nu am testat)
         /*if($1->dimensiune <= 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
         isStruct((yyvsp[-5].strval),(yyvsp[0].v));
         (yyval.v)=initVar((yyvsp[-5].strval), (yyvsp[-3].valnr)->val,tipVar((yyvsp[0].v)));
         }
#line 2189 "y.tab.c"
    break;

  case 62: /* VAR: ID '[' VAR ']' '.' VAR  */
#line 426 "proiect.y"
                            {
         //de adaugat verificare daca e vector (nu am testat)
         /*if($1->dimensiune > 1){
            printf("Incorect semantic!");
            exit(0);
         }*/
         isStruct((yyvsp[-5].strval),(yyvsp[0].v));
         struct tip_t *tip_expr=initTip_t("int");
         tipuriEgale(tip_expr, tipVar((yyvsp[-3].v)));
         (yyval.v)=initVar((yyvsp[-5].strval), 1,tipVar((yyvsp[0].v)));
         }
#line 2205 "y.tab.c"
    break;

  case 63: /* statement: VAR NEWVAL VAR ';'  */
#line 438 "proiect.y"
                               {
                         varDefinita((yyvsp[-1].v)->nume);
                         varNotConst((yyvsp[-3].v)->nume);
                         tipuriEgale(tipVar((yyvsp[-1].v)), tipVar((yyvsp[-3].v)));
                         (yyval.tip)=NULL;
                         }
#line 2216 "y.tab.c"
    break;

  case 64: /* statement: VAR NEWVAL NR ';'  */
#line 444 "proiect.y"
                               {
                         varNotConst((yyvsp[-3].v)->nume);
                         tipuriEgale((yyvsp[-1].valnr)->tip, tipVar((yyvsp[-3].v)));
                         (yyval.tip)=NULL;
                         }
#line 2226 "y.tab.c"
    break;

  case 65: /* statement: VAR NEWVAL lista_op ';'  */
#line 449 "proiect.y"
                                   {
                              varNotConst((yyvsp[-3].v)->nume);
                              tipuriEgale((yyvsp[-1].tip), tipVar((yyvsp[-3].v)));
                              (yyval.tip)=NULL;
                              }
#line 2236 "y.tab.c"
    break;

  case 66: /* statement: VAR NEWVAL apel ';'  */
#line 454 "proiect.y"
                                {
                                 varNotConst((yyvsp[-3].v)->nume);
                                 tipuriEgale(tipVar((yyvsp[-3].v)), (yyvsp[-1].tip));
                                 (yyval.tip)=NULL;
                          }
#line 2246 "y.tab.c"
    break;

  case 67: /* statement: VAR NEWVAL BVAL ';'  */
#line 459 "proiect.y"
                                {
                                 varNotConst((yyvsp[-3].v)->nume);
                                 struct tip_t *tip_expr=initTip_t("bool");
                                 tipuriEgale(tipVar((yyvsp[-3].v)), tip_expr);    
                                 (yyval.tip)=NULL;
                          }
#line 2257 "y.tab.c"
    break;

  case 68: /* statement: VAR NEWVAL lista_cond ';'  */
#line 465 "proiect.y"
                                      {
                                 varNotConst((yyvsp[-3].v)->nume);
                                 struct tip_t *tip_expr=initTip_t("bool");
                                 tipuriEgale(tipVar((yyvsp[-3].v)), tip_expr);    
                                 (yyval.tip)=NULL;                           
                          }
#line 2268 "y.tab.c"
    break;

  case 69: /* statement: declaratie ';'  */
#line 471 "proiect.y"
                           { 
                      if((yyvsp[-1].param_t)->cons) 
                          insertConstTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip); 
                      else
                           insertVarTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip);
                      (yyval.tip)=NULL;
            }
#line 2280 "y.tab.c"
    break;

  case 70: /* statement: IF '(' lista_cond ')' '{' list '}'  */
#line 478 "proiect.y"
                                               {(yyval.tip)=(yyvsp[-1].tip);}
#line 2286 "y.tab.c"
    break;

  case 71: /* statement: IF '(' lista_cond ')' '{' list '}' ELSE '{' list '}'  */
#line 479 "proiect.y"
                                                                 {if((yyvsp[-5].tip)) (yyval.tip)=(yyvsp[-5].tip); else if((yyvsp[-1].tip)) (yyval.tip)=(yyvsp[-1].tip); else (yyval.tip)=NULL;}
#line 2292 "y.tab.c"
    break;

  case 72: /* statement: FOR '(' statement '|' lista_cond '|' statement ')' '{' list '}'  */
#line 480 "proiect.y"
                                                                            {(yyval.tip)=(yyvsp[-1].tip);}
#line 2298 "y.tab.c"
    break;

  case 73: /* statement: FOR '(' statement '|' lista_cond '|' statement ')' statement  */
#line 481 "proiect.y"
                                                                         {(yyval.tip)=(yyvsp[0].tip);}
#line 2304 "y.tab.c"
    break;

  case 74: /* statement: WHILE '(' lista_cond ')' '{' list '}'  */
#line 482 "proiect.y"
                                                  {(yyval.tip)=(yyvsp[-1].tip);}
#line 2310 "y.tab.c"
    break;

  case 75: /* statement: WHILE '(' lista_cond ')' statement  */
#line 483 "proiect.y"
                                               {(yyval.tip)=(yyvsp[0].tip);}
#line 2316 "y.tab.c"
    break;

  case 76: /* statement: EVAL '(' VAR ')' ';'  */
#line 484 "proiect.y"
                                 {(yyval.tip)=NULL;}
#line 2322 "y.tab.c"
    break;

  case 77: /* statement: EVAL '(' NR ')' ';'  */
#line 485 "proiect.y"
                                {if (corect){
                                                 printf("Rezultatul expresiei din eval este %f\n", (yyvsp[-2].valnr)->val);
                                             }
                                             else {printf("Valorile nu sunt de tip int\n");} (yyval.tip)=NULL;}
#line 2331 "y.tab.c"
    break;

  case 78: /* statement: EVAL '(' lista_op ')' ';'  */
#line 489 "proiect.y"
                                      {(yyval.tip)=NULL;}
#line 2337 "y.tab.c"
    break;

  case 79: /* statement: TYPEOF '(' VAR ')' ';'  */
#line 490 "proiect.y"
                                    {
                                    (yyval.tip)=tipVar((yyvsp[-2].v));
                                    printf("Tipul variabilei este %s",tipVar((yyvsp[-2].v))->nume);
                                    }
#line 2346 "y.tab.c"
    break;

  case 80: /* statement: TYPEOF '(' NR ')' ';'  */
#line 494 "proiect.y"
                                  { //nu inteleg la ce faci typeof
                                  }
#line 2353 "y.tab.c"
    break;

  case 81: /* statement: TYPEOF '(' LIT ')' ';'  */
#line 496 "proiect.y"
                                   { //identic ca mai sus
                                    }
#line 2360 "y.tab.c"
    break;

  case 82: /* statement: RET NR ';'  */
#line 498 "proiect.y"
                       { (yyval.tip)=(yyvsp[-1].valnr)->tip; }
#line 2366 "y.tab.c"
    break;

  case 83: /* statement: RET LIT ';'  */
#line 499 "proiect.y"
                       { struct tip_t *tip_expr=initTip_t("char"); (yyval.tip)=tip_expr; }
#line 2372 "y.tab.c"
    break;

  case 84: /* statement: RET BVAL ';'  */
#line 500 "proiect.y"
                         { struct tip_t *tip_expr=initTip_t("bool"); (yyval.tip)=tip_expr; }
#line 2378 "y.tab.c"
    break;

  case 85: /* statement: RET VAR ';'  */
#line 501 "proiect.y"
                        { varDefinita((yyvsp[-1].v)->nume); (yyval.tip)=tipVar((yyvsp[-1].v));}
#line 2384 "y.tab.c"
    break;

  case 89: /* lista_op: VAR operatie  */
#line 507 "proiect.y"
                        { varDefinita((yyvsp[-1].v)->nume); tipuriEgale((yyvsp[0].tip), tipVar((yyvsp[-1].v))); (yyval.tip)=(yyvsp[0].tip);}
#line 2390 "y.tab.c"
    break;

  case 90: /* lista_op: NR operatie  */
#line 508 "proiect.y"
                       {tipuriEgale((yyvsp[0].tip), initTip_t("float")); (yyval.tip)=(yyvsp[0].tip);}
#line 2396 "y.tab.c"
    break;

  case 91: /* lista_op: apel operatie  */
#line 509 "proiect.y"
                          { tipuriEgale((yyvsp[0].tip), (yyvsp[-1].tip)); }
#line 2402 "y.tab.c"
    break;

  case 92: /* lista_op: lista_op operatie  */
#line 510 "proiect.y"
                             {tipuriEgale((yyvsp[-1].tip),(yyvsp[0].tip));}
#line 2408 "y.tab.c"
    break;

  case 93: /* lista_op: '(' lista_op ')' operatie  */
#line 511 "proiect.y"
                                     {tipuriEgale((yyvsp[-2].tip),(yyvsp[0].tip)); (yyval.tip)=(yyvsp[-2].tip);}
#line 2414 "y.tab.c"
    break;

  case 94: /* operatie: OP VAR  */
#line 513 "proiect.y"
                  {varDefinita((yyvsp[0].v)->nume);(yyval.tip)=tipVar((yyvsp[0].v));}
#line 2420 "y.tab.c"
    break;

  case 95: /* operatie: OP NR  */
#line 514 "proiect.y"
                 {(yyval.tip)=(yyvsp[0].valnr)->tip;}
#line 2426 "y.tab.c"
    break;

  case 96: /* operatie: OP apel  */
#line 515 "proiect.y"
                   {(yyval.tip)=(yyvsp[0].tip);}
#line 2432 "y.tab.c"
    break;

  case 101: /* apel: ID '(' lista_arg ')'  */
#line 522 "proiect.y"
                            {
                         funDefinita((yyvsp[-3].strval),(yyvsp[-1].lista_param_t));
                         (yyval.tip)=tipRetFun((yyvsp[-3].strval));
                         }
#line 2441 "y.tab.c"
    break;

  case 102: /* lista_arg: arg  */
#line 527 "proiect.y"
                {(yyval.lista_param_t) = initTipListParam((yyvsp[0].param_t));}
#line 2447 "y.tab.c"
    break;

  case 103: /* lista_arg: lista_arg ',' arg  */
#line 528 "proiect.y"
                              {
                               (yyval.lista_param_t)=(yyvsp[-2].lista_param_t);
                               while((yyvsp[-2].lista_param_t)->urmator)
                                   (yyvsp[-2].lista_param_t)=(yyvsp[-2].lista_param_t)->urmator;
                               (yyvsp[-2].lista_param_t)->urmator=initTipListParam((yyvsp[0].param_t));
                             }
#line 2458 "y.tab.c"
    break;

  case 104: /* arg: VAR  */
#line 535 "proiect.y"
          { 
            varNotConst((yyvsp[0].v)->nume);
            varDefinita((yyvsp[0].v)->nume); 
            (yyval.param_t) = initTipParam(tipVar((yyvsp[0].v)),(yyvsp[0].v)->nume,0);
            }
#line 2468 "y.tab.c"
    break;

  case 105: /* arg: VAR NEWVAL VAR  */
#line 540 "proiect.y"
                     {
                   varNotConst((yyvsp[-2].v)->nume);
                   varDefinita((yyvsp[0].v)->nume);
                   tipuriEgale(tipVar((yyvsp[0].v)), tipVar((yyvsp[-2].v))); 
                   (yyval.param_t) = initTipParam(tipVar((yyvsp[-2].v)),(yyvsp[-2].v)->nume,0);
               }
#line 2479 "y.tab.c"
    break;

  case 106: /* arg: VAR NEWVAL NR  */
#line 546 "proiect.y"
                    {
                   varNotConst((yyvsp[-2].v)->nume);
                   tipuriEgale((yyvsp[0].valnr)->tip, tipVar((yyvsp[-2].v)));
                   (yyval.param_t) = initTipParam(tipVar((yyvsp[-2].v)),(yyvsp[-2].v)->nume,0);
               }
#line 2489 "y.tab.c"
    break;

  case 107: /* arg: apel  */
#line 551 "proiect.y"
           { (yyval.param_t) = initTipParam((yyvsp[0].tip),"functie",0); }
#line 2495 "y.tab.c"
    break;

  case 108: /* lista_cond: VAR cond  */
#line 553 "proiect.y"
                      { varDefinita((yyvsp[-1].v)->nume); tipuriEgale((yyvsp[0].tip), tipVar((yyvsp[-1].v))); }
#line 2501 "y.tab.c"
    break;

  case 109: /* lista_cond: NR cond  */
#line 554 "proiect.y"
                     { tipuriEgale((yyvsp[-1].valnr)->tip, (yyvsp[0].tip)); }
#line 2507 "y.tab.c"
    break;

  case 110: /* lista_cond: BVAL cond  */
#line 555 "proiect.y"
                       { struct tip_t *tip_expr=initTip_t("bool"); tipuriEgale(tip_expr, (yyvsp[0].tip)); }
#line 2513 "y.tab.c"
    break;

  case 111: /* lista_cond: LIT cond  */
#line 556 "proiect.y"
                      { struct tip_t *tip_expr=initTip_t("char"); tipuriEgale(tip_expr, (yyvsp[0].tip)); }
#line 2519 "y.tab.c"
    break;

  case 112: /* lista_cond: apel cond  */
#line 557 "proiect.y"
                       { tipuriEgale((yyvsp[0].tip), (yyvsp[-1].tip)); }
#line 2525 "y.tab.c"
    break;

  case 113: /* lista_cond: lista_cond cond  */
#line 558 "proiect.y"
                             {tipuriEgale((yyvsp[-1].tip),(yyvsp[0].tip));}
#line 2531 "y.tab.c"
    break;

  case 114: /* lista_cond: '(' lista_cond ')' cond  */
#line 559 "proiect.y"
                                     {tipuriEgale((yyvsp[-2].tip),(yyvsp[0].tip)); (yyval.tip)=(yyvsp[-2].tip);}
#line 2537 "y.tab.c"
    break;

  case 115: /* cond: OP_C VAR  */
#line 561 "proiect.y"
                {varDefinita((yyvsp[0].v)->nume); (yyval.tip)=tipVar((yyvsp[0].v));}
#line 2543 "y.tab.c"
    break;

  case 116: /* cond: OP_C NR  */
#line 562 "proiect.y"
               { (yyval.tip)=(yyvsp[0].valnr)->tip; }
#line 2549 "y.tab.c"
    break;

  case 117: /* cond: OP_C BVAL  */
#line 563 "proiect.y"
                 { struct tip_t *tip_expr=initTip_t("bool"); (yyval.tip) = tip_expr;}
#line 2555 "y.tab.c"
    break;

  case 118: /* cond: OP_C LIT  */
#line 564 "proiect.y"
                { struct tip_t *tip_expr=initTip_t("char"); (yyval.tip) = tip_expr;}
#line 2561 "y.tab.c"
    break;

  case 126: /* NR: NRI  */
#line 574 "proiect.y"
        { (yyval.valnr)=InitNr("int",(yyvsp[0].vali));}
#line 2567 "y.tab.c"
    break;

  case 127: /* NR: MINUS NRI  */
#line 575 "proiect.y"
              { (yyval.valnr)=InitNr("int",-(yyvsp[0].vali));}
#line 2573 "y.tab.c"
    break;

  case 128: /* NR: MINUS NRF  */
#line 576 "proiect.y"
              {(yyval.valnr)=InitNr("float",-(yyvsp[0].valf));}
#line 2579 "y.tab.c"
    break;

  case 129: /* NR: NRF  */
#line 577 "proiect.y"
        {(yyval.valnr)=InitNr("float",(yyvsp[0].valf));}
#line 2585 "y.tab.c"
    break;

  case 130: /* lista_nr: NR  */
#line 579 "proiect.y"
              {(yyval.lista_nr_t) = initTipListNr((yyvsp[0].valnr));}
#line 2591 "y.tab.c"
    break;

  case 131: /* lista_nr: lista_nr ',' NR  */
#line 580 "proiect.y"
                             {
                               tipuriEgale((yyvsp[-2].lista_nr_t)->tip,(yyvsp[0].valnr)->tip);
                               (yyval.lista_nr_t)=initTipListNr((yyvsp[0].valnr));
                               (yyvsp[-2].lista_nr_t)->urmator=(yyval.lista_nr_t);
                             }
#line 2601 "y.tab.c"
    break;

  case 132: /* lista_lit: LIT  */
#line 586 "proiect.y"
                 {(yyval.lista_lit_t) = initTipListLit((yyvsp[0].strval));}
#line 2607 "y.tab.c"
    break;

  case 133: /* lista_lit: lista_lit ',' LIT  */
#line 587 "proiect.y"
                               {
                               (yyval.lista_lit_t)=initTipListLit((yyvsp[0].strval));
                               (yyvsp[-2].lista_lit_t)->urmator=(yyval.lista_lit_t);
                             }
#line 2616 "y.tab.c"
    break;


#line 2620 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 596 "proiect.y"

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
