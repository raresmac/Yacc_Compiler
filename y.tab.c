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
1) implementare eval() (doar pt int uri)
2) free memory? vezi val1 de la lab
3) bug in care valoarea floatului nu e citita corect (vezi typeof-ul din exemplu)
OBS:
-TESTING
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
    int lg;
    struct lista_nr_t *urmator;
};

struct lista_lit_t{
    char lit;
    int lg;
    struct lista_lit_t *urmator;
};

struct lista_param_t{
    struct param_t * param;
    struct lista_param_t *urmator;
};
struct tip_t {
    char *nume;
    int dimensiune; //nr de elemente daca e vector
};
struct valnr_t {
    struct tip_t *tip;
    float val; //float poate fi castat la int, momentan merge asa
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
	struct var *param;
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
struct var *initVar(char * val, int index, struct var *param);
struct param_t *initTipParam(struct tip_t *tip, char *valm, bool cons);
struct lista_nr_t *initTipListNr(struct valnr_t* val);
struct lista_lit_t *initTipListLit(char* val);
struct lista_param_t *initTipListParam(struct param_t* val);
void lungimiEgale(int x, int y);
void posInt(struct valnr_t* val);
bool apelCorect(struct lista_param_t *arg, struct lista_param_t *param);
void insertConstTable(char *nume, struct tip_t *tip);
void insertVarTable(char *nume, struct tip_t *tip);
void insertVarListTable(struct lista_param_t *var);
void insertFuncTable(char *nume, struct tip_t *ret, struct lista_param_t *param);
void insertStructTable(char *nume, struct lista_param_t *param);
void printTable();
void sfarsesteProgram();
void isStruct(char * nume);
bool varDefinita(char *nume);
void funDefinita(char *nume, struct lista_param_t *arg);
void varNotConst (char *nume);
bool structDefinita(char *nume);
struct tip_t *tipVar(struct var *v);
struct tip_t *tipRetFun(char *nume);
void tipuriEgale(struct tip_t *stanga, struct tip_t *dreapta);

#line 177 "y.tab.c"

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
    TIMES = 283,                   /* TIMES  */
    DIV = 284,                     /* DIV  */
    MOD = 285,                     /* MOD  */
    AND = 286,                     /* AND  */
    OR = 287,                      /* OR  */
    NOT = 288,                     /* NOT  */
    XOR = 289,                     /* XOR  */
    EVAL = 290,                    /* EVAL  */
    MAIN = 291,                    /* MAIN  */
    TRU = 292,                     /* TRU  */
    FALS = 293,                    /* FALS  */
    RET = 294,                     /* RET  */
    UTYPE = 295,                   /* UTYPE  */
    NRI = 296,                     /* NRI  */
    NRF = 297                      /* NRF  */
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
#define TIMES 283
#define DIV 284
#define MOD 285
#define AND 286
#define OR 287
#define NOT 288
#define XOR 289
#define EVAL 290
#define MAIN 291
#define TRU 292
#define FALS 293
#define RET 294
#define UTYPE 295
#define NRI 296
#define NRF 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 106 "proiect.y"

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

#line 327 "y.tab.c"

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
  YYSYMBOL_TIMES = 28,                     /* TIMES  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_MOD = 30,                       /* MOD  */
  YYSYMBOL_AND = 31,                       /* AND  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_XOR = 34,                       /* XOR  */
  YYSYMBOL_EVAL = 35,                      /* EVAL  */
  YYSYMBOL_MAIN = 36,                      /* MAIN  */
  YYSYMBOL_TRU = 37,                       /* TRU  */
  YYSYMBOL_FALS = 38,                      /* FALS  */
  YYSYMBOL_RET = 39,                       /* RET  */
  YYSYMBOL_UTYPE = 40,                     /* UTYPE  */
  YYSYMBOL_NRI = 41,                       /* NRI  */
  YYSYMBOL_NRF = 42,                       /* NRF  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '['  */
  YYSYMBOL_45_ = 45,                       /* ']'  */
  YYSYMBOL_46_ = 46,                       /* '{'  */
  YYSYMBOL_47_ = 47,                       /* '}'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* '.'  */
  YYSYMBOL_52_ = 52,                       /* '|'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_progr = 54,                     /* progr  */
  YYSYMBOL_optionale = 55,                 /* optionale  */
  YYSYMBOL_var_globale = 56,               /* var_globale  */
  YYSYMBOL_definitie = 57,                 /* definitie  */
  YYSYMBOL_declaratii = 58,                /* declaratii  */
  YYSYMBOL_declaratie = 59,                /* declaratie  */
  YYSYMBOL_BVAL = 60,                      /* BVAL  */
  YYSYMBOL_TIP = 61,                       /* TIP  */
  YYSYMBOL_user_types = 62,                /* user_types  */
  YYSYMBOL_user_type = 63,                 /* user_type  */
  YYSYMBOL_functii = 64,                   /* functii  */
  YYSYMBOL_functie = 65,                   /* functie  */
  YYSYMBOL_declaratie_fct = 66,            /* declaratie_fct  */
  YYSYMBOL_lista_param = 67,               /* lista_param  */
  YYSYMBOL_param = 68,                     /* param  */
  YYSYMBOL_list = 69,                      /* list  */
  YYSYMBOL_VAR = 70,                       /* VAR  */
  YYSYMBOL_SVAR = 71,                      /* SVAR  */
  YYSYMBOL_statement = 72,                 /* statement  */
  YYSYMBOL_NEWVAL = 73,                    /* NEWVAL  */
  YYSYMBOL_lista_op = 74,                  /* lista_op  */
  YYSYMBOL_operatie = 75,                  /* operatie  */
  YYSYMBOL_OP = 76,                        /* OP  */
  YYSYMBOL_apel = 77,                      /* apel  */
  YYSYMBOL_lista_arg = 78,                 /* lista_arg  */
  YYSYMBOL_arg = 79,                       /* arg  */
  YYSYMBOL_lista_cond = 80,                /* lista_cond  */
  YYSYMBOL_cond = 81,                      /* cond  */
  YYSYMBOL_OP_C = 82,                      /* OP_C  */
  YYSYMBOL_NR = 83,                        /* NR  */
  YYSYMBOL_lista_nr = 84,                  /* lista_nr  */
  YYSYMBOL_lista_lit = 85,                 /* lista_lit  */
  YYSYMBOL_bloc = 86                       /* bloc  */
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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   750

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      48,    49,     2,     2,    50,     2,    51,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,    52,    47,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   144,   145,   146,   147,   148,   149,   150,
     152,   158,   159,   160,   167,   168,   170,   171,   178,   184,
     190,   197,   203,   216,   229,   236,   242,   246,   251,   257,
     263,   273,   285,   291,   303,   309,   316,   317,   319,   320,
     321,   322,   323,   324,   326,   327,   329,   336,   337,   339,
     341,   349,   353,   361,   362,   364,   365,   367,   368,   378,
     388,   403,   423,   428,   433,   438,   443,   449,   455,   462,
     463,   464,   465,   466,   467,   468,   469,   475,   476,   483,
     490,   493,   496,   497,   498,   499,   501,   502,   503,   505,
     506,   507,   508,   509,   511,   512,   513,   515,   516,   517,
     518,   519,   521,   526,   527,   534,   538,   543,   548,   550,
     551,   552,   553,   554,   555,   556,   558,   559,   560,   561,
     563,   564,   565,   566,   567,   568,   569,   571,   572,   573,
     574,   576,   577,   588,   589,   595
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
  "PLUS", "MINUS", "ADD", "DEDUCT", "EQUAL", "TIMES", "DIV", "MOD", "AND",
  "OR", "NOT", "XOR", "EVAL", "MAIN", "TRU", "FALS", "RET", "UTYPE", "NRI",
  "NRF", "';'", "'['", "']'", "'{'", "'}'", "'('", "')'", "','", "'.'",
  "'|'", "$accept", "progr", "optionale", "var_globale", "definitie",
  "declaratii", "declaratie", "BVAL", "TIP", "user_types", "user_type",
  "functii", "functie", "declaratie_fct", "lista_param", "param", "list",
  "VAR", "SVAR", "statement", "NEWVAL", "lista_op", "operatie", "OP",
  "apel", "lista_arg", "arg", "lista_cond", "cond", "OP_C", "NR",
  "lista_nr", "lista_lit", "bloc", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-211)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     499,  -211,  -211,  -211,  -211,  -211,    -2,    22,   413,    45,
      85,    54,   499,  -211,    59,    91,   117,  -211,   156,  -211,
      94,   103,    13,   131,  -211,  -211,   154,  -211,  -211,   142,
     117,   156,  -211,     0,  -211,   173,   117,  -211,   480,   505,
    -211,    46,  -211,  -211,  -211,    40,   480,  -211,   117,   178,
      56,   519,   162,   168,   166,   169,   181,   183,   185,   392,
     194,   236,   443,    99,   192,  -211,   384,   201,  -211,  -211,
     300,   224,   461,  -211,  -211,  -211,   244,  -211,  -211,   227,
     206,   413,   255,   134,  -211,   197,    96,    96,   480,    65,
     147,   218,   221,   234,   239,  -211,    52,  -211,  -211,  -211,
    -211,  -211,   204,   266,  -211,   240,  -211,  -211,   244,  -211,
    -211,   257,   242,  -211,  -211,   -29,   252,   279,   312,  -211,
    -211,   519,   274,   275,   405,   -15,    96,   405,   405,   405,
     531,   405,   550,   276,   282,   147,   525,   572,   620,   580,
     588,   596,   604,  -211,  -211,  -211,  -211,   204,   684,   635,
     306,   652,   699,   669,  -211,  -211,    29,   294,   310,  -211,
     342,   149,   302,  -211,  -211,  -211,  -211,  -211,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,   404,   346,   558,  -211,  -211,
    -211,   314,  -211,  -211,   348,    96,   315,   620,   612,   620,
    -211,  -211,  -211,  -211,  -211,   320,  -211,   323,   325,  -211,
    -211,   326,  -211,   333,   335,   338,   716,   716,   716,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,   149,   336,  -211,  -211,
      31,    67,   149,  -211,  -211,  -211,  -211,    99,  -211,   155,
    -211,   405,   480,   480,  -211,   509,  -211,   620,  -211,  -211,
    -211,  -211,  -211,  -211,  -211,  -211,  -211,    72,    89,   149,
    -211,   152,  -211,   107,   108,   197,  -211,   346,  -211,   249,
     267,   480,  -211,  -211,  -211,   132,   159,  -211,  -211,  -211,
    -211,  -211,  -211,   374,  -211,   349,  -211,  -211,   351,   366,
     480,   480,  -211,   286,   304,  -211,  -211
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    38,    39,    40,    42,    41,     0,     0,     0,     0,
       0,     0,     9,    11,     0,     0,     7,    44,     8,    47,
       0,     0,     0,     0,    43,     1,     0,     2,    12,     0,
       5,     6,    10,    26,    45,     0,     4,    48,     0,     0,
      15,     0,   127,   130,    14,     0,     0,    13,     3,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,    55,     0,     0,   128,   129,
       0,     0,     0,    18,    36,    37,     0,    34,    27,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    26,    49,    56,    86,
      87,    88,     0,     0,    46,     0,    16,    19,     0,    35,
      28,     0,     0,   135,   133,     0,     0,    30,     0,    53,
      50,     0,     0,     0,     0,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    82,     0,     0,     0,
       0,     0,     0,     0,    58,    17,     0,     0,     0,    21,
       0,     0,     0,    54,    52,    61,    60,   125,   126,   123,
     120,   121,   122,   124,   112,     0,     0,     0,   111,   109,
     113,     0,   114,   110,     0,     0,     0,     0,     0,     0,
      97,    99,    98,   100,   101,     0,    89,     0,     0,    92,
      91,     0,    90,     0,     0,     0,     0,     0,     0,    66,
      62,    64,    65,    67,    63,    25,     0,     0,   134,   131,
       0,     0,     0,   119,   118,   116,   117,   105,   108,     0,
     103,     0,     0,     0,    74,     0,    80,     0,    78,    94,
      96,    95,    81,    79,    75,    77,    76,     0,     0,     0,
      29,     0,    20,     0,     0,     0,   102,     0,   115,     0,
       0,     0,    93,    32,    24,     0,     0,   132,    31,    22,
     106,   107,   104,    69,    73,     0,    33,    23,     0,     0,
       0,     0,    72,     0,     0,    70,    71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -211,  -211,  -211,  -211,   387,  -211,    38,   -35,     5,    16,
     144,   388,     1,  -211,  -211,   283,   -46,   -44,   307,   -61,
     176,     3,   -78,  -211,   -82,  -211,   157,   -77,    19,  -211,
     -19,  -210,  -104,  -211
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    66,    60,   127,    61,    16,
      17,    18,    19,    20,    83,    84,    62,    63,    64,    65,
     102,   188,   196,   197,   129,   229,   230,   177,   182,   175,
     131,   220,   115,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      72,    98,    21,    44,   156,    15,   247,   138,   138,   130,
     132,    98,   253,    23,    77,    93,    40,    15,   159,    37,
     151,   160,    49,    35,    92,   152,    22,   133,    30,    85,
      78,    80,    37,   176,    36,   109,    35,    41,    14,   265,
      94,   122,   128,   128,    50,   136,   140,    48,    51,    24,
      29,   110,   112,   138,    42,    43,    82,   221,   149,   199,
     200,   202,    70,   199,   202,   207,   123,   148,   134,   125,
     139,   142,   199,   200,    49,   202,   215,    67,   250,   160,
      41,   251,   128,   153,    71,    25,   118,    68,    69,    41,
      26,   187,   137,   141,   228,    33,    50,    42,    43,   124,
     125,    79,    32,   206,   105,   150,    42,    43,   235,    38,
     199,   202,   248,   135,   252,   240,   189,   160,   254,   263,
      41,    99,   251,   234,   100,   101,    82,     6,   208,   200,
     202,   225,   227,    74,    75,    45,   264,    42,    43,   160,
     224,   128,   219,   174,   126,   266,   178,   179,   180,    39,
     183,   125,   114,   239,   268,   269,   226,   251,   160,   262,
      34,     1,     2,     3,     4,     5,     6,   178,   179,    46,
     180,    41,   183,    41,    34,   228,    41,    52,   241,   276,
      34,    73,   251,   120,   121,    47,   259,   260,    42,    43,
      42,    43,    34,    42,    43,   135,     9,   219,    98,    98,
     275,    53,    41,   219,   256,   257,   277,   124,   125,   160,
      51,   270,    85,   227,    86,    74,    75,    87,   282,    42,
      43,    41,    98,    98,    76,   179,   180,   183,    41,    88,
     219,    89,   267,    90,   283,   284,   271,    95,    42,    43,
      96,    74,    75,   103,   106,    42,    43,   114,    41,   116,
     258,   117,   147,    53,     1,     2,     3,     4,     5,   119,
      54,   143,    55,    56,   144,    42,    43,     8,    57,   111,
      53,    53,     1,     2,     3,     4,     5,   145,    54,   157,
      55,    56,   146,   155,    58,     8,    57,   158,    59,     9,
      53,     1,     2,     3,     4,     5,   273,    54,   161,    55,
      56,   162,    58,   107,     8,    57,    59,     9,    53,     1,
       2,     3,     4,     5,   274,    54,   163,    55,    56,   165,
     166,    58,     8,    57,    41,    59,     9,   125,   185,   190,
     191,   186,   217,   285,   192,   193,   194,    74,    75,    58,
     216,    42,    43,    59,     9,   218,   108,    41,   222,   211,
     125,   286,    53,     1,     2,     3,     4,     5,   236,    54,
     232,    55,    56,   238,    42,    43,     8,    57,   242,   243,
      53,     1,     2,     3,     4,     5,   244,    54,   245,    55,
      56,   246,   249,    58,     8,    57,   278,    59,     9,     1,
       2,     3,     4,     5,   233,    91,    53,   280,   279,    28,
      31,    58,     8,   255,   164,    59,     9,   223,    53,     0,
     154,     0,   281,     0,   272,     0,    41,     0,     1,     2,
       3,     4,     5,     0,     9,   167,   168,     0,    41,    74,
      75,   104,   169,    42,    43,     0,   170,   171,   172,   173,
       0,    74,    75,     0,     0,    42,    43,    53,     1,     2,
       3,     4,     5,     9,    54,     0,    55,    56,     0,    97,
       0,     8,    57,     0,     0,    53,     1,     2,     3,     4,
       5,     0,    54,     0,    55,    56,     0,   113,    58,     8,
      57,     0,    59,     9,    53,     1,     2,     3,     4,     5,
       0,    54,     0,    55,    56,     0,    58,     0,     8,    57,
      59,     9,     0,     0,     1,     2,     3,     4,     5,     6,
       1,     2,     3,     4,     5,    58,     7,     8,     0,    59,
       9,     0,     0,     8,     1,     2,     3,     4,     5,   167,
     168,     0,     0,     0,     0,     0,   169,    81,     0,     9,
     170,   171,   172,   173,     0,     9,     0,     0,   190,   191,
       0,   167,   168,   192,   193,   194,     0,     0,   169,     9,
       0,   261,   170,   171,   172,   173,     0,     0,     0,     0,
     167,   168,     0,     0,   195,     0,     0,   169,   167,   168,
     181,   170,   171,   172,   173,   169,     0,     0,     0,   170,
     171,   172,   173,     0,     0,   190,   191,     0,     0,   184,
     192,   193,   194,   190,   191,     0,     0,   231,   192,   193,
     194,   190,   191,     0,     0,     0,   192,   193,   194,   190,
     191,   198,     0,     0,   192,   193,   194,   190,   191,   201,
       0,     0,   192,   193,   194,   190,   191,   203,     0,     0,
     192,   193,   194,   190,   191,   204,     0,     0,   192,   193,
     194,     0,     0,   205,     0,   167,   168,     0,   190,   191,
       0,   237,   169,   192,   193,   194,   170,   171,   172,   173,
       0,     0,   167,   168,     0,   190,   191,     0,   210,   169,
     192,   193,   194,   170,   171,   172,   173,     0,     0,   167,
     168,     0,   190,   191,     0,   212,   169,   192,   193,   194,
     170,   171,   172,   173,   167,   168,     0,     0,     0,     0,
       0,   169,   214,     0,     0,   170,   171,   172,   173,   167,
     168,     0,     0,     0,     0,     0,   169,   209,     0,     0,
     170,   171,   172,   173,     0,     0,   167,   168,     0,   190,
     191,     0,   213,   169,   192,   193,   194,   170,   171,   172,
     173
};

static const yytype_int16 yycheck[] =
{
      46,    62,     4,    22,   108,     0,   216,    89,    90,    86,
      87,    72,   222,     8,    49,    59,     3,    12,    47,    18,
     102,    50,    22,    18,    59,   102,     4,    88,    12,    44,
      49,    50,    31,    48,    18,    70,    31,    24,     0,   249,
      59,    85,    86,    87,    44,    89,    90,    31,    48,     4,
      12,    70,    71,   135,    41,    42,    51,   161,   102,   137,
     138,   139,    22,   141,   142,   147,    85,   102,     3,     4,
      89,    90,   150,   151,    22,   153,    47,    39,    47,    50,
      24,    50,   126,   102,    44,     0,    81,    41,    42,    24,
      36,   135,    89,    90,   176,     4,    44,    41,    42,     3,
       4,    45,    43,   147,    66,   102,    41,    42,   185,    15,
     188,   189,   216,    48,    47,   197,   135,    50,   222,    47,
      24,    22,    50,   184,    25,    26,   121,    10,   147,   207,
     208,   175,   176,    37,    38,     4,    47,    41,    42,    50,
     175,   185,   161,   124,    48,   249,   127,   128,   129,    46,
     131,     4,     3,   197,    47,    47,   175,    50,    50,   237,
      16,     5,     6,     7,     8,     9,    10,   148,   149,    15,
     151,    24,   153,    24,    30,   257,    24,     4,   197,    47,
      36,     3,    50,    49,    50,    43,   232,   233,    41,    42,
      41,    42,    48,    41,    42,    48,    40,   216,   259,   260,
     261,     4,    24,   222,    49,    50,    47,     3,     4,    50,
      48,   255,    44,   257,    48,    37,    38,    48,   279,    41,
      42,    24,   283,   284,    46,   206,   207,   208,    24,    48,
     249,    48,   251,    48,   280,   281,   255,    43,    41,    42,
       4,    37,    38,    51,    43,    41,    42,     3,    24,    22,
     231,    45,    48,     4,     5,     6,     7,     8,     9,     4,
      11,    43,    13,    14,    43,    41,    42,    18,    19,    45,
       4,     4,     5,     6,     7,     8,     9,    43,    11,    22,
      13,    14,    43,    43,    35,    18,    19,    45,    39,    40,
       4,     5,     6,     7,     8,     9,    47,    11,    46,    13,
      14,    22,    35,     3,    18,    19,    39,    40,     4,     5,
       6,     7,     8,     9,    47,    11,     4,    13,    14,    45,
      45,    35,    18,    19,    24,    39,    40,     4,    52,    23,
      24,    49,    22,    47,    28,    29,    30,    37,    38,    35,
      46,    41,    42,    39,    40,     3,    46,    24,    46,    43,
       4,    47,     4,     5,     6,     7,     8,     9,    43,    11,
      46,    13,    14,    43,    41,    42,    18,    19,    43,    43,
       4,     5,     6,     7,     8,     9,    43,    11,    43,    13,
      14,    43,    46,    35,    18,    19,    12,    39,    40,     5,
       6,     7,     8,     9,    46,     3,     4,    46,    49,    12,
      12,    35,    18,   227,   121,    39,    40,     3,     4,    -1,
     103,    -1,    46,    -1,   257,    -1,    24,    -1,     5,     6,
       7,     8,     9,    -1,    40,    20,    21,    -1,    24,    37,
      38,    47,    27,    41,    42,    -1,    31,    32,    33,    34,
      -1,    37,    38,    -1,    -1,    41,    42,     4,     5,     6,
       7,     8,     9,    40,    11,    -1,    13,    14,    -1,    16,
      -1,    18,    19,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    13,    14,    -1,    16,    35,    18,
      19,    -1,    39,    40,     4,     5,     6,     7,     8,     9,
      -1,    11,    -1,    13,    14,    -1,    35,    -1,    18,    19,
      39,    40,    -1,    -1,     5,     6,     7,     8,     9,    10,
       5,     6,     7,     8,     9,    35,    17,    18,    -1,    39,
      40,    -1,    -1,    18,     5,     6,     7,     8,     9,    20,
      21,    -1,    -1,    -1,    -1,    -1,    27,    18,    -1,    40,
      31,    32,    33,    34,    -1,    40,    -1,    -1,    23,    24,
      -1,    20,    21,    28,    29,    30,    -1,    -1,    27,    40,
      -1,    52,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      20,    21,    -1,    -1,    49,    -1,    -1,    27,    20,    21,
      49,    31,    32,    33,    34,    27,    -1,    -1,    -1,    31,
      32,    33,    34,    -1,    -1,    23,    24,    -1,    -1,    49,
      28,    29,    30,    23,    24,    -1,    -1,    49,    28,    29,
      30,    23,    24,    -1,    -1,    -1,    28,    29,    30,    23,
      24,    49,    -1,    -1,    28,    29,    30,    23,    24,    49,
      -1,    -1,    28,    29,    30,    23,    24,    49,    -1,    -1,
      28,    29,    30,    23,    24,    49,    -1,    -1,    28,    29,
      30,    -1,    -1,    49,    -1,    20,    21,    -1,    23,    24,
      -1,    49,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    20,    21,    -1,    23,    24,    -1,    43,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    20,
      21,    -1,    23,    24,    -1,    43,    27,    28,    29,    30,
      31,    32,    33,    34,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,    43,    -1,    -1,    31,    32,    33,    34,    20,
      21,    -1,    -1,    -1,    -1,    -1,    27,    43,    -1,    -1,
      31,    32,    33,    34,    -1,    -1,    20,    21,    -1,    23,
      24,    -1,    43,    27,    28,    29,    30,    31,    32,    33,
      34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    17,    18,    40,
      54,    55,    56,    57,    59,    61,    62,    63,    64,    65,
      66,     4,     4,    61,     4,     0,    36,    86,    57,    59,
      62,    64,    43,     4,    63,    61,    62,    65,    15,    46,
       3,    24,    41,    42,    83,     4,    15,    43,    62,    22,
      44,    48,     4,     4,    11,    13,    14,    19,    35,    39,
      59,    61,    69,    70,    71,    72,    58,    59,    41,    42,
      22,    44,    69,     3,    37,    38,    46,    60,    83,    45,
      83,    18,    61,    67,    68,    44,    48,    48,    48,    48,
      48,     3,    60,    70,    83,    43,     4,    16,    72,    22,
      25,    26,    73,    51,    47,    59,    43,     3,    46,    60,
      83,    45,    83,    16,     3,    85,    22,    45,    61,     4,
      49,    50,    70,    83,     3,     4,    48,    60,    70,    77,
      80,    83,    80,    72,     3,    48,    70,    74,    77,    83,
      70,    74,    83,    43,    43,    43,    43,    48,    60,    70,
      74,    77,    80,    83,    71,    43,    85,    22,    45,    47,
      50,    46,    22,     4,    68,    45,    45,    20,    21,    27,
      31,    32,    33,    34,    81,    82,    48,    80,    81,    81,
      81,    49,    81,    81,    49,    52,    49,    70,    74,    83,
      23,    24,    28,    29,    30,    49,    75,    76,    49,    75,
      75,    49,    75,    49,    49,    49,    70,    77,    83,    43,
      43,    43,    43,    43,    43,    47,    46,    22,     3,    83,
      84,    85,    46,     3,    60,    70,    83,    70,    77,    78,
      79,    49,    46,    46,    72,    80,    43,    49,    43,    70,
      77,    83,    43,    43,    43,    43,    43,    84,    85,    46,
      47,    50,    47,    84,    85,    73,    49,    50,    81,    69,
      69,    52,    75,    47,    47,    84,    85,    83,    47,    47,
      70,    83,    79,    47,    47,    72,    47,    47,    12,    49,
      46,    46,    72,    69,    69,    47,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    61,    61,    61,    62,    62,    63,    64,    64,    65,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    73,    74,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    76,
      76,    76,    77,    78,    78,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    81,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      83,    84,    84,    85,    85,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     2,     1,     1,     1,
       2,     1,     2,     3,     3,     3,     2,     3,     4,     5,
       8,     6,     9,    10,     9,     7,     2,     4,     5,     8,
       5,     9,     9,    10,     4,     5,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     5,     1,     2,     4,
       5,     1,     3,     2,     3,     1,     2,     1,     3,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     2,     7,
      11,    11,     9,     7,     5,     5,     5,     5,     5,     5,
       5,     5,     3,     3,     3,     3,     1,     1,     1,     2,
       2,     2,     2,     4,     2,     2,     2,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     3,     3,     1,     2,
       2,     2,     2,     2,     2,     4,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     3,     1,     3,     4
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
  case 2: /* progr: optionale bloc  */
#line 134 "proiect.y"
                      {
                       printf("Sintaxa corecta\n");
                       if (corect) {
                         printf("Corect semantic\n");
                         printTable();
                       }
                       else
                       printf("Incorect semantic\n");
                   }
#line 1679 "y.tab.c"
    break;

  case 3: /* optionale: var_globale functii user_types  */
#line 144 "proiect.y"
                                           {functie_curenta="main";}
#line 1685 "y.tab.c"
    break;

  case 4: /* optionale: functii user_types  */
#line 145 "proiect.y"
                           {functie_curenta="main";}
#line 1691 "y.tab.c"
    break;

  case 5: /* optionale: var_globale user_types  */
#line 146 "proiect.y"
                                {functie_curenta="main";}
#line 1697 "y.tab.c"
    break;

  case 6: /* optionale: var_globale functii  */
#line 147 "proiect.y"
                             {functie_curenta="main";}
#line 1703 "y.tab.c"
    break;

  case 7: /* optionale: user_types  */
#line 148 "proiect.y"
                   {functie_curenta="main";}
#line 1709 "y.tab.c"
    break;

  case 8: /* optionale: functii  */
#line 149 "proiect.y"
                {functie_curenta="main";}
#line 1715 "y.tab.c"
    break;

  case 9: /* optionale: var_globale  */
#line 150 "proiect.y"
                    {functie_curenta="main";}
#line 1721 "y.tab.c"
    break;

  case 10: /* var_globale: declaratie ';'  */
#line 152 "proiect.y"
                             { 
                      if((yyvsp[-1].param_t)->cons) 
                          insertConstTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip); 
                      else
                           insertVarTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip);
            }
#line 1732 "y.tab.c"
    break;

  case 13: /* var_globale: var_globale declaratie ';'  */
#line 160 "proiect.y"
                                         { 
                      if((yyvsp[-1].param_t)->cons) 
                          insertConstTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip); 
                      else
                           insertVarTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip);
            }
#line 1743 "y.tab.c"
    break;

  case 14: /* definitie: DEFINE ID NR  */
#line 167 "proiect.y"
                         { insertConstTable((yyvsp[-1].strval),(yyvsp[0].valnr)->tip); }
#line 1749 "y.tab.c"
    break;

  case 15: /* definitie: DEFINE ID LIT  */
#line 168 "proiect.y"
                          { struct tip_t *tip_expr=initTip_t("char"); insertConstTable((yyvsp[-1].strval),tip_expr); }
#line 1755 "y.tab.c"
    break;

  case 16: /* declaratii: declaratie ';'  */
#line 170 "proiect.y"
                            {(yyval.lista_param_t) = initTipListParam((yyvsp[-1].param_t));}
#line 1761 "y.tab.c"
    break;

  case 17: /* declaratii: declaratii declaratie ';'  */
#line 171 "proiect.y"
                                      {
                               (yyval.lista_param_t)=(yyvsp[-2].lista_param_t);
                               while((yyvsp[-2].lista_param_t)->urmator)
                                   (yyvsp[-2].lista_param_t)=(yyvsp[-2].lista_param_t)->urmator;
                               (yyvsp[-2].lista_param_t)->urmator=initTipListParam((yyvsp[-1].param_t));
                             }
#line 1772 "y.tab.c"
    break;

  case 18: /* declaratie: TIP ID ASSIGN LIT  */
#line 178 "proiect.y"
                              {
                              structDefinita((yyvsp[-3].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),0);
                              }
#line 1783 "y.tab.c"
    break;

  case 19: /* declaratie: CONST TIP ID ASSIGN LIT  */
#line 184 "proiect.y"
                                    {
                              structDefinita((yyvsp[-3].tip)->nume);                              
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),1);
                              }
#line 1794 "y.tab.c"
    break;

  case 20: /* declaratie: TIP ID '[' ']' ASSIGN '{' lista_lit '}'  */
#line 190 "proiect.y"
                                                    {
                              (yyvsp[-7].tip)->dimensiune = (yyvsp[-1].lista_lit_t)->lg;
                              structDefinita((yyvsp[-7].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),0);
                              }
#line 1806 "y.tab.c"
    break;

  case 21: /* declaratie: TIP ID ASSIGN '{' lista_lit '}'  */
#line 197 "proiect.y"
                                            {
                              structDefinita((yyvsp[-5].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, (yyvsp[-5].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-5].tip),(yyvsp[-4].strval),0);
                              }
#line 1817 "y.tab.c"
    break;

  case 22: /* declaratie: TIP ID '[' NR ']' ASSIGN '{' lista_lit '}'  */
#line 203 "proiect.y"
                                                       {
                              if((yyvsp[-5].valnr)->val < 1){
                                printf("Linia %d: Dimensiunea nu este pozitiva!\n",yylineno);
                                //exit(0);
                              }
                              posInt((yyvsp[-5].valnr));
                              lungimiEgale((yyvsp[-5].valnr)->val,(yyvsp[-1].lista_lit_t)->lg);
                              (yyvsp[-8].tip)->dimensiune = (yyvsp[-5].valnr)->val;
                              structDefinita((yyvsp[-8].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-8].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),0);
                              }
#line 1835 "y.tab.c"
    break;

  case 23: /* declaratie: CONST TIP ID '[' NR ']' ASSIGN '{' lista_lit '}'  */
#line 216 "proiect.y"
                                                             {
                              if((yyvsp[-5].valnr)->val < 1){
                                printf("Linia %d: Dimensiunea nu este pozitiva!\n",yylineno);
                                //exit(0);
                              }
                              posInt((yyvsp[-5].valnr));
                              lungimiEgale((yyvsp[-5].valnr)->val,(yyvsp[-1].lista_lit_t)->lg);
                              (yyvsp[-8].tip)->dimensiune = (yyvsp[-5].valnr)->val;
                              structDefinita((yyvsp[-8].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-8].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),1);
                              }
#line 1853 "y.tab.c"
    break;

  case 24: /* declaratie: CONST TIP ID '[' ']' ASSIGN '{' lista_lit '}'  */
#line 229 "proiect.y"
                                                          {
                              (yyvsp[-7].tip)->dimensiune = (yyvsp[-1].lista_lit_t)->lg;
                              structDefinita((yyvsp[-7].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),1);
                              }
#line 1865 "y.tab.c"
    break;

  case 25: /* declaratie: CONST TIP ID ASSIGN '{' lista_lit '}'  */
#line 236 "proiect.y"
                                                  {
                              structDefinita((yyvsp[-5].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, (yyvsp[-5].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-5].tip),(yyvsp[-4].strval),1);
                              }
#line 1876 "y.tab.c"
    break;

  case 26: /* declaratie: TIP ID  */
#line 242 "proiect.y"
                    {
                    structDefinita((yyvsp[-1].tip)->nume);
                    (yyval.param_t) = initTipParam((yyvsp[-1].tip),(yyvsp[0].strval),0);
                    }
#line 1885 "y.tab.c"
    break;

  case 27: /* declaratie: TIP ID ASSIGN NR  */
#line 246 "proiect.y"
                              {
                              structDefinita((yyvsp[-3].tip)->nume);
                              tipuriEgale((yyvsp[0].valnr)->tip, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),0);
                              }
#line 1895 "y.tab.c"
    break;

  case 28: /* declaratie: CONST TIP ID ASSIGN NR  */
#line 251 "proiect.y"
                                    {
                              structDefinita((yyvsp[-3].tip)->nume);
                              tipuriEgale((yyvsp[0].valnr)->tip, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),1);
                              }
#line 1905 "y.tab.c"
    break;

  case 29: /* declaratie: TIP ID '[' ']' ASSIGN '{' lista_nr '}'  */
#line 257 "proiect.y"
                                                   {
                              (yyvsp[-7].tip)->dimensiune = (yyvsp[-1].lista_nr_t)->lg;
                              structDefinita((yyvsp[-7].tip)->nume);
                              tipuriEgale((yyvsp[-1].lista_nr_t)->tip,(yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),0);
                              }
#line 1916 "y.tab.c"
    break;

  case 30: /* declaratie: TIP ID '[' NR ']'  */
#line 263 "proiect.y"
                              {
                              if((yyvsp[-1].valnr)->val < 1){
                                printf("Linia %d: Dimensiunea nu este pozitiva!\n",yylineno);
                                //exit(0);
                              }
                              posInt((yyvsp[-1].valnr));
                              (yyvsp[-4].tip)->dimensiune = (yyvsp[-1].valnr)->val;
                              structDefinita((yyvsp[-4].tip)->nume);
                              (yyval.param_t) = initTipParam((yyvsp[-4].tip),(yyvsp[-3].strval),0);
                              }
#line 1931 "y.tab.c"
    break;

  case 31: /* declaratie: TIP ID '[' NR ']' ASSIGN '{' lista_nr '}'  */
#line 273 "proiect.y"
                                                      {
                              if((yyvsp[-5].valnr)->val < 1){
                                printf("Linia %d: Dimensiunea nu este pozitiva!\n",yylineno);
                                //exit(0);
                              }
                              posInt((yyvsp[-5].valnr));
                              lungimiEgale((yyvsp[-5].valnr)->val,(yyvsp[-1].lista_nr_t)->lg);
                              (yyvsp[-8].tip)->dimensiune = (yyvsp[-5].valnr)->val;
                              structDefinita((yyvsp[-8].tip)->nume);
                              tipuriEgale((yyvsp[-8].tip), (yyvsp[-1].lista_nr_t)->tip);
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),0);
                              }
#line 1948 "y.tab.c"
    break;

  case 32: /* declaratie: CONST TIP ID '[' ']' ASSIGN '{' lista_nr '}'  */
#line 285 "proiect.y"
                                                         {
                              (yyvsp[-7].tip)->dimensiune = (yyvsp[-1].lista_nr_t)->lg;
                              structDefinita((yyvsp[-7].tip)->nume);
                              tipuriEgale((yyvsp[-1].lista_nr_t)->tip, (yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),1);
                              }
#line 1959 "y.tab.c"
    break;

  case 33: /* declaratie: CONST TIP ID '[' NR ']' ASSIGN '{' lista_nr '}'  */
#line 291 "proiect.y"
                                                            {
                              if((yyvsp[-5].valnr)->val < 1){
                                printf("Linia %d: Dimensiunea nu este pozitiva!\n",yylineno);
                                //exit(0);
                              }
                              posInt((yyvsp[-5].valnr));
                              lungimiEgale((yyvsp[-5].valnr)->val,(yyvsp[-1].lista_nr_t)->lg);
                              (yyvsp[-8].tip)->dimensiune = (yyvsp[-5].valnr)->val;
                              structDefinita((yyvsp[-8].tip)->nume);
                              tipuriEgale((yyvsp[-1].lista_nr_t)->tip, (yyvsp[-8].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),1);
                              }
#line 1976 "y.tab.c"
    break;

  case 34: /* declaratie: TIP ID ASSIGN BVAL  */
#line 303 "proiect.y"
                               {
                              structDefinita((yyvsp[-3].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("bool");
                              tipuriEgale((yyvsp[-3].tip), tip_expr);
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),0);
                              }
#line 1987 "y.tab.c"
    break;

  case 35: /* declaratie: CONST TIP ID ASSIGN BVAL  */
#line 309 "proiect.y"
                                     {
                              structDefinita((yyvsp[-3].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("bool");
                              tipuriEgale((yyvsp[-3].tip), tip_expr);
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),1);
                              }
#line 1998 "y.tab.c"
    break;

  case 36: /* BVAL: TRU  */
#line 316 "proiect.y"
           { (yyval.vali)=1; }
#line 2004 "y.tab.c"
    break;

  case 37: /* BVAL: FALS  */
#line 317 "proiect.y"
            { (yyval.vali)=0; }
#line 2010 "y.tab.c"
    break;

  case 38: /* TIP: INT  */
#line 319 "proiect.y"
          { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 2016 "y.tab.c"
    break;

  case 39: /* TIP: FLOAT  */
#line 320 "proiect.y"
            { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 2022 "y.tab.c"
    break;

  case 40: /* TIP: CHAR  */
#line 321 "proiect.y"
           { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 2028 "y.tab.c"
    break;

  case 41: /* TIP: STRING  */
#line 322 "proiect.y"
             { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 2034 "y.tab.c"
    break;

  case 42: /* TIP: BOOL  */
#line 323 "proiect.y"
           { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 2040 "y.tab.c"
    break;

  case 43: /* TIP: UTYPE ID  */
#line 324 "proiect.y"
               { isStruct((yyvsp[0].strval)); structura_curenta=NULL; (yyval.tip)=initTip_t((yyvsp[0].strval));}
#line 2046 "y.tab.c"
    break;

  case 46: /* user_type: NEWTYPE ID '{' declaratii '}'  */
#line 329 "proiect.y"
                                          {
                    insertStructTable((yyvsp[-3].strval), (yyvsp[-1].lista_param_t));
                    structura_curenta = (yyvsp[-3].strval);
                    insertVarListTable((yyvsp[-1].lista_param_t));
                    structura_curenta = NULL;
                }
#line 2057 "y.tab.c"
    break;

  case 49: /* functie: declaratie_fct BGIN list END  */
#line 339 "proiect.y"
                                      { functie_curenta = NULL; tipuriEgale((yyvsp[-3].tip), (yyvsp[-1].tip));}
#line 2063 "y.tab.c"
    break;

  case 50: /* declaratie_fct: TIP ID '(' lista_param ')'  */
#line 341 "proiect.y"
                                           {
               structDefinita((yyvsp[-4].tip)->nume);
               functie_curenta = (yyvsp[-3].strval); 
               insertVarListTable((yyvsp[-1].lista_param_t));
               insertFuncTable((yyvsp[-3].strval), (yyvsp[-4].tip), (yyvsp[-1].lista_param_t));
               (yyval.tip)=(yyvsp[-4].tip);
           }
#line 2075 "y.tab.c"
    break;

  case 51: /* lista_param: param  */
#line 349 "proiect.y"
                    {
                    (yyval.lista_param_t) = initTipListParam((yyvsp[0].param_t));
                    //free($1);
                    }
#line 2084 "y.tab.c"
    break;

  case 52: /* lista_param: lista_param ',' param  */
#line 353 "proiect.y"
                                    {
                               (yyval.lista_param_t)=(yyvsp[-2].lista_param_t);
                               while((yyvsp[-2].lista_param_t)->urmator)
                                   (yyvsp[-2].lista_param_t)=(yyvsp[-2].lista_param_t)->urmator;
                               (yyvsp[-2].lista_param_t)->urmator=initTipListParam((yyvsp[0].param_t));
                               //free($3);
                             }
#line 2096 "y.tab.c"
    break;

  case 53: /* param: TIP ID  */
#line 361 "proiect.y"
               { (yyval.param_t) = initTipParam((yyvsp[-1].tip),(yyvsp[0].strval),0); }
#line 2102 "y.tab.c"
    break;

  case 54: /* param: CONST TIP ID  */
#line 362 "proiect.y"
                     {  (yyval.param_t) = initTipParam((yyvsp[-1].tip),(yyvsp[0].strval),1); }
#line 2108 "y.tab.c"
    break;

  case 56: /* list: list statement  */
#line 365 "proiect.y"
                      {if((yyvsp[-1].tip) && (yyvsp[0].tip))tipuriEgale((yyvsp[-1].tip),(yyvsp[0].tip)); if((yyvsp[-1].tip)) (yyval.tip)=(yyvsp[-1].tip); else if((yyvsp[0].tip)) (yyval.tip)=(yyvsp[0].tip);}
#line 2114 "y.tab.c"
    break;

  case 57: /* VAR: SVAR  */
#line 367 "proiect.y"
           {structura_curenta=NULL;}
#line 2120 "y.tab.c"
    break;

  case 58: /* VAR: SVAR '.' SVAR  */
#line 368 "proiect.y"
                    {
          structura_curenta=NULL;
          isStruct(tipVar((yyvsp[-2].v))->nume);
          (yyval.v)=initVar((yyvsp[-2].v)->nume, -1, (yyvsp[0].v));
          if(tipVar((yyval.v))->dimensiune){
            printf("Linia %d: %s e vector, trebuie apelat un element al lui\n",yylineno,(yyvsp[-2].v)->nume);
            //exit(0);
         }
       }
#line 2134 "y.tab.c"
    break;

  case 59: /* SVAR: ID  */
#line 378 "proiect.y"
          {
         (yyval.v)=initVar((yyvsp[0].strval), -1, 0);
         varDefinita((yyvsp[0].strval));
         if(tipVar((yyval.v))->dimensiune){
            printf("Linia %d: %s e vector, trebuie apelat un element al lui\n",yylineno,(yyvsp[0].strval));
            corect=0;
            //exit(0);
         }
         structura_curenta=tipVar((yyval.v))->nume;
         }
#line 2149 "y.tab.c"
    break;

  case 60: /* SVAR: ID '[' NR ']'  */
#line 388 "proiect.y"
                   {
         (yyval.v)=initVar((yyvsp[-3].strval), (yyvsp[-1].valnr)->val, 0);
         varDefinita((yyvsp[-3].strval));
         if(!tipVar((yyval.v))->dimensiune){
            printf("Linia %d: %s nu e vector, nu puteti apela un element al lui\n",yylineno,(yyvsp[-3].strval));
            corect=0;
            //exit(0);
         }
         posInt((yyvsp[-1].valnr));
         if(tipVar((yyval.v))->dimensiune<(yyvsp[-1].valnr)->val){
            printf("Linia %d: Lungimea vectorului %s e mai mica decat indicele dat\n",yylineno,(yyvsp[-3].strval));
            //exit(0);
         }
         structura_curenta=tipVar((yyval.v))->nume;
         }
#line 2169 "y.tab.c"
    break;

  case 61: /* SVAR: ID '[' VAR ']'  */
#line 403 "proiect.y"
                    {
         struct tip_t *tip_expr=initTip_t("int");
         tipuriEgale(tip_expr, tipVar((yyvsp[-1].v)));
         (yyval.v)=initVar((yyvsp[-3].strval), 1, 0);
         varDefinita((yyvsp[-3].strval)); 
         if(!tipVar((yyval.v))->dimensiune){
            printf("Linia %d: %s nu e vector, nu puteti apela un element al lui\n",yylineno,(yyvsp[-3].strval));
            corect=0;
            //exit(0);
         }
         else
               printf("Linia %d: Asigurati-va ca %s e positiv si <= %d \n",yylineno,(yyvsp[-1].v)->nume, tipVar((yyval.v))->dimensiune);
         /*posInt($3); but for var
         if(tipVar($$)->dimensiune<$3->val){
            printf("Linia %d: Lungimea vectorului %s e mai mica decat indicele dat\n",yylineno,$1->nume);
            //exit(0);
         }*/
         structura_curenta=tipVar((yyval.v))->nume;
         }
#line 2193 "y.tab.c"
    break;

  case 62: /* statement: VAR NEWVAL VAR ';'  */
#line 423 "proiect.y"
                               {
                         varNotConst((yyvsp[-3].v)->nume);
                         tipuriEgale(tipVar((yyvsp[-1].v)), tipVar((yyvsp[-3].v)));
                         (yyval.tip)=NULL;
                         }
#line 2203 "y.tab.c"
    break;

  case 63: /* statement: VAR NEWVAL NR ';'  */
#line 428 "proiect.y"
                               {
                         varNotConst((yyvsp[-3].v)->nume);
                         tipuriEgale((yyvsp[-1].valnr)->tip, tipVar((yyvsp[-3].v)));
                         (yyval.tip)=NULL;
                         }
#line 2213 "y.tab.c"
    break;

  case 64: /* statement: VAR NEWVAL lista_op ';'  */
#line 433 "proiect.y"
                                   {
                              varNotConst((yyvsp[-3].v)->nume);
                              tipuriEgale((yyvsp[-1].tip), tipVar((yyvsp[-3].v)));
                              (yyval.tip)=NULL;
                              }
#line 2223 "y.tab.c"
    break;

  case 65: /* statement: VAR NEWVAL apel ';'  */
#line 438 "proiect.y"
                                {
                                 varNotConst((yyvsp[-3].v)->nume);
                                 tipuriEgale(tipVar((yyvsp[-3].v)), (yyvsp[-1].tip));
                                 (yyval.tip)=NULL;
                          }
#line 2233 "y.tab.c"
    break;

  case 66: /* statement: VAR NEWVAL BVAL ';'  */
#line 443 "proiect.y"
                                {
                                 varNotConst((yyvsp[-3].v)->nume);
                                 struct tip_t *tip_expr=initTip_t("bool");
                                 tipuriEgale(tipVar((yyvsp[-3].v)), tip_expr);    
                                 (yyval.tip)=NULL;
                          }
#line 2244 "y.tab.c"
    break;

  case 67: /* statement: VAR NEWVAL lista_cond ';'  */
#line 449 "proiect.y"
                                      {
                                 varNotConst((yyvsp[-3].v)->nume);
                                 struct tip_t *tip_expr=initTip_t("bool");
                                 tipuriEgale(tipVar((yyvsp[-3].v)), tip_expr);    
                                 (yyval.tip)=NULL;                           
                          }
#line 2255 "y.tab.c"
    break;

  case 68: /* statement: declaratie ';'  */
#line 455 "proiect.y"
                           { 
                      if((yyvsp[-1].param_t)->cons) 
                          insertConstTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip); 
                      else
                           insertVarTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip);
                      (yyval.tip)=NULL;
            }
#line 2267 "y.tab.c"
    break;

  case 69: /* statement: IF '(' lista_cond ')' '{' list '}'  */
#line 462 "proiect.y"
                                               {(yyval.tip)=(yyvsp[-1].tip);}
#line 2273 "y.tab.c"
    break;

  case 70: /* statement: IF '(' lista_cond ')' '{' list '}' ELSE '{' list '}'  */
#line 463 "proiect.y"
                                                                 {if((yyvsp[-5].tip)) (yyval.tip)=(yyvsp[-5].tip); else if((yyvsp[-1].tip)) (yyval.tip)=(yyvsp[-1].tip); else (yyval.tip)=NULL;}
#line 2279 "y.tab.c"
    break;

  case 71: /* statement: FOR '(' statement '|' lista_cond '|' statement ')' '{' list '}'  */
#line 464 "proiect.y"
                                                                            {(yyval.tip)=(yyvsp[-1].tip);}
#line 2285 "y.tab.c"
    break;

  case 72: /* statement: FOR '(' statement '|' lista_cond '|' statement ')' statement  */
#line 465 "proiect.y"
                                                                         {(yyval.tip)=(yyvsp[0].tip);}
#line 2291 "y.tab.c"
    break;

  case 73: /* statement: WHILE '(' lista_cond ')' '{' list '}'  */
#line 466 "proiect.y"
                                                  {(yyval.tip)=(yyvsp[-1].tip);}
#line 2297 "y.tab.c"
    break;

  case 74: /* statement: WHILE '(' lista_cond ')' statement  */
#line 467 "proiect.y"
                                               {(yyval.tip)=(yyvsp[0].tip);}
#line 2303 "y.tab.c"
    break;

  case 75: /* statement: EVAL '(' VAR ')' ';'  */
#line 468 "proiect.y"
                                 {(yyval.tip)=NULL;}
#line 2309 "y.tab.c"
    break;

  case 76: /* statement: EVAL '(' NR ')' ';'  */
#line 469 "proiect.y"
                                {
                               struct tip_t *tip_expr=initTip_t("int");
                               tipuriEgale((yyvsp[-2].valnr)->tip, tip_expr); 
                               if (corect){ printf("Rezultatul expresiei din eval este %f\n", (yyvsp[-2].valnr)->val); }
                               else {printf("Linia %d: Valorile nu sunt de tip int\n",yylineno);} (yyval.tip)=NULL;
                               }
#line 2320 "y.tab.c"
    break;

  case 77: /* statement: EVAL '(' lista_op ')' ';'  */
#line 475 "proiect.y"
                                      {(yyval.tip)=NULL;}
#line 2326 "y.tab.c"
    break;

  case 78: /* statement: TYPEOF '(' VAR ')' ';'  */
#line 476 "proiect.y"
                                    {
                                    (yyval.tip)=NULL;
                                    if(!(yyvsp[-2].v)->param)
                                        printf("Tipul variabilei %s este %s\n", (yyvsp[-2].v)->nume, tipVar((yyvsp[-2].v))->nume);
                                    else
                                        printf("Tipul variabilei %s.%s este %s\n",(yyvsp[-2].v)->nume, (yyvsp[-2].v)->param->nume, tipVar((yyvsp[-2].v))->nume);
                                    }
#line 2338 "y.tab.c"
    break;

  case 79: /* statement: TYPEOF '(' NR ')' ';'  */
#line 483 "proiect.y"
                                  {
                                    (yyval.tip)=NULL;
                                    if(strcmp((yyvsp[-2].valnr)->tip->nume,"int")==0)
                                        printf("Tipul numarului %f este %s\n", (yyvsp[-2].valnr)->val, (yyvsp[-2].valnr)->tip->nume);
                                    else
                                        printf("Tipul numarului %d este %s\n", (int)(yyvsp[-2].valnr)->val, (yyvsp[-2].valnr)->tip->nume);
                                    }
#line 2350 "y.tab.c"
    break;

  case 80: /* statement: TYPEOF '(' LIT ')' ';'  */
#line 490 "proiect.y"
                                   { (yyval.tip)=NULL;
                                    printf("Tipul literei %s este char\n", (yyvsp[-2].strval));
                                    }
#line 2358 "y.tab.c"
    break;

  case 81: /* statement: TYPEOF '(' lista_op ')' ';'  */
#line 493 "proiect.y"
                                       { (yyval.tip)=NULL;
                                    printf("Tipul rezultatului operatiilor este %s\n", (yyvsp[-2].tip)->nume);
                                    }
#line 2366 "y.tab.c"
    break;

  case 82: /* statement: RET NR ';'  */
#line 496 "proiect.y"
                       { (yyval.tip)=(yyvsp[-1].valnr)->tip; }
#line 2372 "y.tab.c"
    break;

  case 83: /* statement: RET LIT ';'  */
#line 497 "proiect.y"
                       { struct tip_t *tip_expr=initTip_t("char"); (yyval.tip)=tip_expr; }
#line 2378 "y.tab.c"
    break;

  case 84: /* statement: RET BVAL ';'  */
#line 498 "proiect.y"
                         { struct tip_t *tip_expr=initTip_t("bool"); (yyval.tip)=tip_expr; }
#line 2384 "y.tab.c"
    break;

  case 85: /* statement: RET VAR ';'  */
#line 499 "proiect.y"
                        { (yyval.tip)=tipVar((yyvsp[-1].v));}
#line 2390 "y.tab.c"
    break;

  case 89: /* lista_op: VAR operatie  */
#line 505 "proiect.y"
                        { tipuriEgale((yyvsp[0].tip), tipVar((yyvsp[-1].v))); (yyval.tip)=(yyvsp[0].tip);}
#line 2396 "y.tab.c"
    break;

  case 90: /* lista_op: NR operatie  */
#line 506 "proiect.y"
                       {tipuriEgale((yyvsp[0].tip), initTip_t("float")); (yyval.tip)=(yyvsp[0].tip);}
#line 2402 "y.tab.c"
    break;

  case 91: /* lista_op: apel operatie  */
#line 507 "proiect.y"
                          { tipuriEgale((yyvsp[0].tip), (yyvsp[-1].tip)); }
#line 2408 "y.tab.c"
    break;

  case 92: /* lista_op: lista_op operatie  */
#line 508 "proiect.y"
                             {tipuriEgale((yyvsp[-1].tip),(yyvsp[0].tip));}
#line 2414 "y.tab.c"
    break;

  case 93: /* lista_op: '(' lista_op ')' operatie  */
#line 509 "proiect.y"
                                     {tipuriEgale((yyvsp[-2].tip),(yyvsp[0].tip)); (yyval.tip)=(yyvsp[-2].tip);}
#line 2420 "y.tab.c"
    break;

  case 94: /* operatie: OP VAR  */
#line 511 "proiect.y"
                  {(yyval.tip)=tipVar((yyvsp[0].v));}
#line 2426 "y.tab.c"
    break;

  case 95: /* operatie: OP NR  */
#line 512 "proiect.y"
                 {(yyval.tip)=(yyvsp[0].valnr)->tip;}
#line 2432 "y.tab.c"
    break;

  case 96: /* operatie: OP apel  */
#line 513 "proiect.y"
                   {(yyval.tip)=(yyvsp[0].tip);}
#line 2438 "y.tab.c"
    break;

  case 102: /* apel: ID '(' lista_arg ')'  */
#line 521 "proiect.y"
                            {
                         funDefinita((yyvsp[-3].strval),(yyvsp[-1].lista_param_t));
                         (yyval.tip)=tipRetFun((yyvsp[-3].strval));
                         }
#line 2447 "y.tab.c"
    break;

  case 103: /* lista_arg: arg  */
#line 526 "proiect.y"
                {(yyval.lista_param_t) = initTipListParam((yyvsp[0].param_t));}
#line 2453 "y.tab.c"
    break;

  case 104: /* lista_arg: lista_arg ',' arg  */
#line 527 "proiect.y"
                              {
                               (yyval.lista_param_t)=(yyvsp[-2].lista_param_t);
                               while((yyvsp[-2].lista_param_t)->urmator)
                                   (yyvsp[-2].lista_param_t)=(yyvsp[-2].lista_param_t)->urmator;
                               (yyvsp[-2].lista_param_t)->urmator=initTipListParam((yyvsp[0].param_t));
                             }
#line 2464 "y.tab.c"
    break;

  case 105: /* arg: VAR  */
#line 534 "proiect.y"
          { 
            varNotConst((yyvsp[0].v)->nume);
            (yyval.param_t) = initTipParam(tipVar((yyvsp[0].v)),(yyvsp[0].v)->nume,0);
            }
#line 2473 "y.tab.c"
    break;

  case 106: /* arg: VAR NEWVAL VAR  */
#line 538 "proiect.y"
                     {
                   varNotConst((yyvsp[-2].v)->nume);
                   tipuriEgale(tipVar((yyvsp[0].v)), tipVar((yyvsp[-2].v))); 
                   (yyval.param_t) = initTipParam(tipVar((yyvsp[-2].v)),(yyvsp[-2].v)->nume,0);
               }
#line 2483 "y.tab.c"
    break;

  case 107: /* arg: VAR NEWVAL NR  */
#line 543 "proiect.y"
                    {
                   varNotConst((yyvsp[-2].v)->nume);
                   tipuriEgale((yyvsp[0].valnr)->tip, tipVar((yyvsp[-2].v)));
                   (yyval.param_t) = initTipParam(tipVar((yyvsp[-2].v)),(yyvsp[-2].v)->nume,0);
               }
#line 2493 "y.tab.c"
    break;

  case 108: /* arg: apel  */
#line 548 "proiect.y"
           { (yyval.param_t) = initTipParam((yyvsp[0].tip),"functie",0); }
#line 2499 "y.tab.c"
    break;

  case 109: /* lista_cond: VAR cond  */
#line 550 "proiect.y"
                      { tipuriEgale((yyvsp[0].tip), tipVar((yyvsp[-1].v))); }
#line 2505 "y.tab.c"
    break;

  case 110: /* lista_cond: NR cond  */
#line 551 "proiect.y"
                     { tipuriEgale((yyvsp[-1].valnr)->tip, (yyvsp[0].tip)); }
#line 2511 "y.tab.c"
    break;

  case 111: /* lista_cond: BVAL cond  */
#line 552 "proiect.y"
                       { struct tip_t *tip_expr=initTip_t("bool"); tipuriEgale(tip_expr, (yyvsp[0].tip)); }
#line 2517 "y.tab.c"
    break;

  case 112: /* lista_cond: LIT cond  */
#line 553 "proiect.y"
                      { struct tip_t *tip_expr=initTip_t("char"); tipuriEgale(tip_expr, (yyvsp[0].tip)); }
#line 2523 "y.tab.c"
    break;

  case 113: /* lista_cond: apel cond  */
#line 554 "proiect.y"
                       { tipuriEgale((yyvsp[0].tip), (yyvsp[-1].tip)); }
#line 2529 "y.tab.c"
    break;

  case 114: /* lista_cond: lista_cond cond  */
#line 555 "proiect.y"
                             {tipuriEgale((yyvsp[-1].tip),(yyvsp[0].tip));}
#line 2535 "y.tab.c"
    break;

  case 115: /* lista_cond: '(' lista_cond ')' cond  */
#line 556 "proiect.y"
                                     {tipuriEgale((yyvsp[-2].tip),(yyvsp[0].tip)); (yyval.tip)=(yyvsp[-2].tip);}
#line 2541 "y.tab.c"
    break;

  case 116: /* cond: OP_C VAR  */
#line 558 "proiect.y"
                {(yyval.tip)=tipVar((yyvsp[0].v));}
#line 2547 "y.tab.c"
    break;

  case 117: /* cond: OP_C NR  */
#line 559 "proiect.y"
               { (yyval.tip)=(yyvsp[0].valnr)->tip; }
#line 2553 "y.tab.c"
    break;

  case 118: /* cond: OP_C BVAL  */
#line 560 "proiect.y"
                 { struct tip_t *tip_expr=initTip_t("bool"); (yyval.tip) = tip_expr;}
#line 2559 "y.tab.c"
    break;

  case 119: /* cond: OP_C LIT  */
#line 561 "proiect.y"
                { struct tip_t *tip_expr=initTip_t("char"); (yyval.tip) = tip_expr;}
#line 2565 "y.tab.c"
    break;

  case 127: /* NR: NRI  */
#line 571 "proiect.y"
        { (yyval.valnr)=InitNr("int",(yyvsp[0].vali));}
#line 2571 "y.tab.c"
    break;

  case 128: /* NR: MINUS NRI  */
#line 572 "proiect.y"
              { (yyval.valnr)=InitNr("int",-(yyvsp[0].vali));}
#line 2577 "y.tab.c"
    break;

  case 129: /* NR: MINUS NRF  */
#line 573 "proiect.y"
              {(yyval.valnr)=InitNr("float",-(yyvsp[0].valf));}
#line 2583 "y.tab.c"
    break;

  case 130: /* NR: NRF  */
#line 574 "proiect.y"
        {(yyval.valnr)=InitNr("float",(yyvsp[0].valf));}
#line 2589 "y.tab.c"
    break;

  case 131: /* lista_nr: NR  */
#line 576 "proiect.y"
              {(yyval.lista_nr_t) = initTipListNr((yyvsp[0].valnr)); (yyval.lista_nr_t)->lg=1;}
#line 2595 "y.tab.c"
    break;

  case 132: /* lista_nr: lista_nr ',' NR  */
#line 577 "proiect.y"
                             {
                               (yyval.lista_nr_t)=(yyvsp[-2].lista_nr_t);
                               (yyval.lista_nr_t)->lg=(yyvsp[-2].lista_nr_t)->lg+1;
                               while((yyvsp[-2].lista_nr_t)->urmator)
                               {
                                   (yyvsp[-2].lista_nr_t)=(yyvsp[-2].lista_nr_t)->urmator;
                                   (yyvsp[-2].lista_nr_t)->lg+=1;
                               }
                               (yyvsp[-2].lista_nr_t)->urmator=initTipListNr((yyvsp[0].valnr));
                             }
#line 2610 "y.tab.c"
    break;

  case 133: /* lista_lit: LIT  */
#line 588 "proiect.y"
                 {(yyval.lista_lit_t) = initTipListLit((yyvsp[0].strval)); (yyval.lista_lit_t)->lg=1;}
#line 2616 "y.tab.c"
    break;

  case 134: /* lista_lit: lista_lit ',' LIT  */
#line 589 "proiect.y"
                               {
                               (yyval.lista_lit_t)=initTipListLit((yyvsp[0].strval));
                               (yyval.lista_lit_t)->lg=(yyvsp[-2].lista_lit_t)->lg+1;
                               (yyvsp[-2].lista_lit_t)->urmator=(yyval.lista_lit_t);
                             }
#line 2626 "y.tab.c"
    break;


#line 2630 "y.tab.c"

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

#line 599 "proiect.y"

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
            printf("Linia %d: Variabila/Structura deja exista\n",yylineno);
            corect = 0;
            //exit(0);
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
        if(tip->dimensiune)
            fprintf(f, "[%d]", tip->dimensiune);
    } 
    else{
        fprintf(f, "void");
    }
}

void posInt(struct valnr_t* val){
    struct  tip_t* temp=initTip_t("int");
    tipuriEgale(temp,val->tip);
    if(val->val<0)
    {
        corect=0;
        printf("Linia %d: Valoarea indicelui trebuie sa fie pozitiva\n",yylineno);
    }
}
void lungimiEgale(int x, int y){
    if(x==y)
        return;
    corect=0;
    printf("Linia %d: Numarul de elemente nu este egal cu lungimea vectorului\n",yylineno); 
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
            fprintf(fisier_tabela, "in func %s\t", SymbolTable[i].functie);
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
    printf("Linia %d: Variabila %s nu a fost definita\n",yylineno,nume);
    sfarsesteProgram();
    return 0;
}


void funDefinita(char *nume, struct lista_param_t *arg) {
    for (int i = 0; i < nrSimboluri; ++i) {
        if (SymbolTable[i].tip_simbol == SIMBOL_FUNCTIE && strcmp(SymbolTable[i].nume, nume) == 0) {
            if ((SymbolTable[i].structura != NULL && structura_curenta != NULL &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0)||SymbolTable[i].structura == NULL)
                 if(!apelCorect(arg,SymbolTable[i].param)){
                     printf("Linia %d: In apelul functiei %s numarul de argumente este gresit\n",yylineno, nume);
                     //exit(0);
                 }
                 else
                     return;
                     
        }
    }
    corect = 0;
    printf("Linia %d: Functia %s nu a fost definita\n",yylineno, nume);
    sfarsesteProgram();
}
bool apelCorect(struct lista_param_t * arg, struct lista_param_t *param) {
    while (param != NULL && arg != NULL) {
        tipuriEgale(arg->param->tip, param->param->tip);
        param = param->urmator;
        arg = arg->urmator;
    }
    if (param != NULL || arg != NULL) {
        corect = 0;
        //exit(0);
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
    printf("Linia %d: Structura %s nu a fost definita\n",yylineno, nume);
    sfarsesteProgram();
    return 0;
}

struct tip_t *tipVar(struct var *v) {
    struct tip_t *rezultat = NULL;
    for (int i = 0; i < nrSimboluri; ++i) {
        if ((SymbolTable[i].tip_simbol == SIMBOL_VARIABILA || SymbolTable[i].tip_simbol == SIMBOL_CONST)  && strcmp(SymbolTable[i].nume, v->nume) == 0) {
            if (SymbolTable[i].functie == NULL && SymbolTable[i].structura == NULL)
                rezultat = SymbolTable[i].tip;
            else if (SymbolTable[i].functie == NULL && SymbolTable[i].structura != NULL &&
                structura_curenta != NULL &&
                strcmp(SymbolTable[i].structura, structura_curenta) == 0)
                rezultat = SymbolTable[i].tip;
            else if (SymbolTable[i].functie != NULL && SymbolTable[i].structura == NULL &&
                structura_curenta == NULL && functie_curenta != NULL &&
                structura_curenta == NULL && strcmp(SymbolTable[i].functie, functie_curenta) == 0)
                rezultat = SymbolTable[i].tip;
            else if (SymbolTable[i].functie != NULL && SymbolTable[i].structura != NULL &&
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
    if(v->param)
    {
        structura_curenta=rezultat->nume;
        rezultat=tipVar(v->param);
        structura_curenta=NULL;
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
        printf("Linia %d: ",yylineno);
        printTip(stdout, stanga);
        printf(" nu este compatibil cu ");
        printTip(stdout, dreapta);
        printf("\n");
        //exit(0);
    }
}
void varNotConst (char *nume){
    if(varDefinita(nume)==0 && corect)
    {
        corect=0;
        printf("Linia %d: Valoarea lui %s nu poate fi schimbata\n",yylineno, nume);
        //exit(0);
    } 
}
void isStruct(char * nume){
    if(!structDefinita(nume))
    {
        corect=0;
        printf("Linia %d: %s nu e usertype\n",yylineno, nume);
        //exit(0);
    }

}
struct tip_t * initTip_t(char * val)
{
    struct tip_t* expr = (struct tip_t*)malloc(sizeof(struct tip_t));
    expr->nume = (char*) malloc(sizeof(char)*(strlen(val)+1)); 
    strcpy(expr->nume, val);
    expr->dimensiune=0;
    return expr;
}
struct var * initVar(char * val, int index, struct var* param)
{
    struct var* expr = (struct var*)malloc(sizeof(struct var));
    expr->nume = (char*) malloc(sizeof(char)*(strlen(val)+1)); 
    strcpy(expr->nume,val);
    expr->index=index;
    expr->param = (struct var*)malloc(sizeof(param));
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

void sfarsesteProgram(){
    printf("Sintaxa corecta!\n");
    printf("O eroare fatala a fost receptionata la linia %d!\n",yylineno);
    exit(0);
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
}
