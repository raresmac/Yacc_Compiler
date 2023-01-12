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
1) implementare eval() (eval doar pt int uri)
^ plz u
astea pot si eu:
2) VAR: verificat ca id[nr]: id e vector | id: id nu e vector
3) verificat daca folosim tip_t dimensiune / numar anywhere. Probabil ar trebui pt vectori? dar nu e implementat nimic
4) la declarare vector, de verificat ca [nr] = lungimea listei (unde e cazul)
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
    int val;//crezi ca e obligatoriu sa fie float? nu de alta, dar eval da rau
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

#line 175 "y.tab.c"

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
    TIMES = 279,                   /* TIMES  */
    MINUS = 280,                   /* MINUS  */
    ADD = 281,                     /* ADD  */
    DEDUCT = 282,                  /* DEDUCT  */
    EQUAL = 283,                   /* EQUAL  */
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
#define TIMES 279
#define MINUS 280
#define ADD 281
#define DEDUCT 282
#define EQUAL 283
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
#line 104 "proiect.y"

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

#line 325 "y.tab.c"

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
  YYSYMBOL_TIMES = 24,                     /* TIMES  */
  YYSYMBOL_MINUS = 25,                     /* MINUS  */
  YYSYMBOL_ADD = 26,                       /* ADD  */
  YYSYMBOL_DEDUCT = 27,                    /* DEDUCT  */
  YYSYMBOL_EQUAL = 28,                     /* EQUAL  */
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
  YYSYMBOL_statement = 71,                 /* statement  */
  YYSYMBOL_NEWVAL = 72,                    /* NEWVAL  */
  YYSYMBOL_lista_op = 73,                  /* lista_op  */
  YYSYMBOL_operatie = 74,                  /* operatie  */
  YYSYMBOL_OP = 75,                        /* OP  */
  YYSYMBOL_apel = 76,                      /* apel  */
  YYSYMBOL_lista_arg = 77,                 /* lista_arg  */
  YYSYMBOL_arg = 78,                       /* arg  */
  YYSYMBOL_lista_cond = 79,                /* lista_cond  */
  YYSYMBOL_cond = 80,                      /* cond  */
  YYSYMBOL_OP_C = 81,                      /* OP_C  */
  YYSYMBOL_NR = 82,                        /* NR  */
  YYSYMBOL_lista_nr = 83,                  /* lista_nr  */
  YYSYMBOL_lista_lit = 84,                 /* lista_lit  */
  YYSYMBOL_bloc = 85                       /* bloc  */
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
#define YYLAST   713

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
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
       0,   132,   132,   142,   143,   144,   145,   146,   147,   148,
     150,   156,   157,   158,   165,   166,   168,   169,   176,   182,
     188,   194,   200,   206,   212,   218,   224,   228,   233,   239,
     245,   250,   256,   262,   268,   274,   281,   282,   284,   285,
     286,   287,   288,   289,   291,   292,   294,   301,   302,   304,
     306,   314,   315,   322,   323,   325,   326,   328,   334,   341,
     350,   359,   368,   380,   386,   391,   396,   401,   407,   413,
     420,   421,   422,   423,   424,   425,   426,   427,   431,   432,
     439,   443,   446,   447,   448,   449,   451,   452,   453,   455,
     456,   457,   458,   459,   461,   462,   463,   465,   466,   467,
     468,   469,   471,   476,   477,   484,   489,   495,   500,   502,
     503,   504,   505,   506,   507,   508,   510,   511,   512,   513,
     515,   516,   517,   518,   519,   520,   521,   523,   524,   525,
     526,   528,   529,   535,   536,   541
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
  "PLUS", "TIMES", "MINUS", "ADD", "DEDUCT", "EQUAL", "DIV", "MOD", "AND",
  "OR", "NOT", "XOR", "EVAL", "MAIN", "TRU", "FALS", "RET", "UTYPE", "NRI",
  "NRF", "';'", "'['", "']'", "'{'", "'}'", "'('", "')'", "','", "'.'",
  "'|'", "$accept", "progr", "optionale", "var_globale", "definitie",
  "declaratii", "declaratie", "BVAL", "TIP", "user_types", "user_type",
  "functii", "functie", "declaratie_fct", "lista_param", "param", "list",
  "VAR", "statement", "NEWVAL", "lista_op", "operatie", "OP", "apel",
  "lista_arg", "arg", "lista_cond", "cond", "OP_C", "NR", "lista_nr",
  "lista_lit", "bloc", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-181)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     487,  -181,  -181,  -181,  -181,  -181,    -2,     3,   329,    18,
      42,    53,   487,  -181,    50,   112,   119,  -181,   273,  -181,
     124,   109,    94,   155,  -181,  -181,   153,  -181,  -181,   127,
     119,   273,  -181,    10,  -181,   189,   119,  -181,   468,   493,
    -181,   -15,  -181,  -181,  -181,    44,   468,  -181,   119,   135,
     170,   507,   149,    47,   157,   169,   178,   181,   185,   367,
     140,   221,   431,   -10,  -181,   156,   196,  -181,  -181,   305,
     357,   449,  -181,  -181,  -181,   244,  -181,  -181,   218,   207,
     329,   253,    95,  -181,    70,   254,    31,    31,   468,    59,
      34,   222,   228,   232,   242,  -181,    55,  -181,  -181,  -181,
    -181,  -181,    83,  -181,   248,  -181,  -181,   244,  -181,  -181,
     270,   267,  -181,  -181,    56,   247,   298,   318,  -181,  -181,
     507,   288,   295,  -181,   679,   162,    31,   679,   679,   679,
     489,   679,   508,   296,   303,   315,   317,    34,   521,   542,
     128,   550,  -181,  -181,  -181,  -181,    83,   620,   572,   648,
     588,   636,   604,  -181,    67,   308,   333,  -181,   371,   179,
     338,  -181,  -181,   324,   336,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,   392,   384,   528,  -181,  -181,  -181,   351,
    -181,  -181,   354,    31,   358,   360,   363,   128,   558,   128,
    -181,  -181,  -181,  -181,  -181,   370,  -181,   284,   373,  -181,
    -181,   376,  -181,   664,   664,   664,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,   179,   364,  -181,  -181,    76,    87,   179,
     254,   254,  -181,  -181,  -181,  -181,   -10,  -181,   142,  -181,
     679,   468,   468,  -181,   394,  -181,  -181,  -181,   128,  -181,
    -181,  -181,  -181,  -181,  -181,   137,   220,   179,  -181,   177,
    -181,   239,   257,  -181,  -181,    70,  -181,   384,  -181,   237,
     255,   468,  -181,  -181,  -181,   294,   306,  -181,  -181,  -181,
    -181,  -181,  -181,   408,  -181,   374,  -181,  -181,   375,   372,
     468,   468,  -181,   292,   310,  -181,  -181
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
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,   128,   129,     0,
       0,     0,    18,    36,    37,     0,    34,    27,     0,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    26,    49,    56,    86,
      87,    88,     0,    46,     0,    16,    19,     0,    35,    28,
       0,     0,   135,   133,     0,     0,    30,     0,    53,    50,
       0,     0,     0,    60,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    82,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     0,     0,    21,     0,     0,
       0,    54,    52,    59,    58,   125,   126,   123,   120,   121,
     122,   124,   112,     0,     0,     0,   111,   109,   113,     0,
     114,   110,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,     0,    89,     0,     0,    92,
      91,     0,    90,     0,     0,     0,    67,    63,    65,    66,
      68,    64,    25,     0,     0,   134,   131,     0,     0,     0,
       0,     0,   119,   118,   116,   117,   105,   108,     0,   103,
       0,     0,     0,    75,     0,    81,    79,    80,     0,    76,
      94,    96,    95,    78,    77,     0,     0,     0,    29,     0,
      20,     0,     0,    62,    61,     0,   102,     0,   115,     0,
       0,     0,    93,    32,    24,     0,     0,   132,    31,    22,
     106,   107,   104,    70,    74,     0,    33,    23,     0,     0,
       0,     0,    73,     0,     0,    71,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -181,  -181,   412,  -181,    13,   -45,    29,    -3,
      74,   419,    63,  -181,  -181,   312,   -46,   -41,   -52,   215,
     -79,    49,  -181,   -82,  -181,   186,   -81,    19,  -181,   -19,
    -180,  -106,  -181
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    65,    60,   127,    61,    16,
      17,    18,    19,    20,    82,    83,    62,    63,    64,   102,
     188,   196,   197,   129,   228,   229,   175,   180,   173,   131,
     217,   114,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,   154,    21,    44,    76,   130,   132,    22,   140,    30,
      98,   139,    99,    14,    92,    36,   100,   101,    93,    98,
     150,   151,    24,   149,   108,    29,    67,    68,    48,    15,
      77,    79,    49,   245,   124,   125,   133,    23,   125,   251,
      94,    15,    25,   121,   123,   128,   128,    35,   135,   138,
     109,   111,    66,   218,    50,   140,    41,   147,    51,    41,
      35,   148,   134,    53,   204,   122,    69,   265,    73,    74,
     136,   141,    42,    43,    53,    42,    43,    49,   104,   126,
      81,    37,   137,   152,    41,   128,   124,   125,    70,    26,
      34,    84,   227,    32,    37,    41,   187,    40,    85,    50,
      42,    43,   234,   157,    34,   203,   158,   246,    41,   117,
      34,    42,    43,   252,   212,   241,    33,   158,   189,    41,
      73,    74,    34,   248,    42,    43,   249,   205,   223,     6,
     233,   146,   224,   226,   250,    42,    43,   158,    72,    38,
     216,   266,   128,   172,   119,   120,   176,   177,   178,    81,
     181,   190,   191,   192,   225,    39,   240,   193,   194,    45,
      41,     1,     2,     3,     4,     5,   176,   177,    46,   178,
      47,   181,    73,    74,     8,   227,    42,    43,   242,   253,
     254,    75,   113,    95,   263,   259,   260,   249,   199,   200,
     202,   256,   257,    52,   216,    41,     9,    51,   199,   200,
     216,   202,    41,   103,    41,    86,    84,    98,    98,   275,
     174,    42,    43,    85,   270,    78,   226,    87,    42,    43,
      42,    43,   177,   178,   181,    96,    88,   282,   216,    89,
     267,    98,    98,    90,   283,   284,   271,   199,   202,   105,
     115,    53,     1,     2,     3,     4,     5,   113,    54,   258,
      55,    56,   116,   200,   202,     8,    57,   118,    53,    53,
       1,     2,     3,     4,     5,   142,    54,   264,    55,    56,
     158,   143,    58,     8,    57,   144,    59,     9,     1,     2,
       3,     4,     5,     6,   273,   145,   268,   262,   125,   249,
      58,   153,   155,   159,    59,     9,    53,     1,     2,     3,
       4,     5,   274,    54,   269,    55,    56,   158,   106,    41,
       8,    57,   156,     9,    53,     1,     2,     3,     4,     5,
     160,    54,   161,    55,    56,    42,    43,    58,     8,    57,
      41,    59,     9,   163,     1,     2,     3,     4,     5,   285,
     164,   276,    73,    74,   249,    58,    42,    43,   183,    59,
       9,   107,   184,   277,   213,   214,   158,   286,    53,     1,
       2,     3,     4,     5,   185,    54,   186,    55,    56,     9,
      91,    53,     8,    57,   215,   220,    53,     1,     2,     3,
       4,     5,    41,    54,   219,    55,    56,   221,   125,    58,
       8,    57,    41,    59,     9,   222,    53,   231,    42,    43,
     232,   235,   110,   236,    73,    74,   237,    58,    42,    43,
     247,    59,     9,   239,   165,   166,   243,    41,   281,   244,
     278,   280,   167,   279,    28,   168,   169,   170,   171,    73,
      74,    31,   162,    42,    43,    53,     1,     2,     3,     4,
       5,   255,    54,   272,    55,    56,   261,    97,     0,     8,
      57,     0,     0,    53,     1,     2,     3,     4,     5,     0,
      54,     0,    55,    56,     0,   112,    58,     8,    57,     0,
      59,     9,    53,     1,     2,     3,     4,     5,     0,    54,
       0,    55,    56,     0,    58,     0,     8,    57,    59,     9,
       0,     0,     1,     2,     3,     4,     5,     6,     1,     2,
       3,     4,     5,    58,     7,     8,     0,    59,     9,   165,
     166,     8,     1,     2,     3,     4,     5,   167,     0,     0,
     168,   169,   170,   171,     0,    80,     0,     9,   165,   166,
       0,     0,     0,     9,     0,     0,   167,     0,   179,   168,
     169,   170,   171,     0,   190,   191,   192,     9,   165,   166,
     193,   194,     0,     0,     0,     0,   167,   182,     0,   168,
     169,   170,   171,     0,     0,   190,   191,   192,     0,     0,
     195,   193,   194,   190,   191,   192,     0,   230,     0,   193,
     194,   190,   191,   192,     0,     0,     0,   193,   194,     0,
       0,   198,   165,   166,     0,   190,   191,   192,     0,   201,
     167,   193,   194,   168,   169,   170,   171,   238,   165,   166,
       0,   190,   191,   192,     0,   207,   167,   193,   194,   168,
     169,   170,   171,     0,   165,   166,     0,   190,   191,   192,
       0,   209,   167,   193,   194,   168,   169,   170,   171,     0,
     165,   166,     0,     0,     0,     0,     0,   211,   167,     0,
       0,   168,   169,   170,   171,     0,   165,   166,     0,     0,
       0,     0,     0,   206,   167,     0,     0,   168,   169,   170,
     171,   190,   191,   192,     0,     0,     0,   193,   194,   210,
       0,     0,     0,     0,   165,   166,     0,   190,   191,   192,
       0,   208,   167,   193,   194,   168,   169,   170,   171,   165,
     166,     0,     0,     0,     0,     0,     0,   167,     0,     0,
     168,   169,   170,   171
};

static const yytype_int16 yycheck[] =
{
      46,   107,     4,    22,    49,    86,    87,     4,    90,    12,
      62,    90,    22,     0,    59,    18,    26,    27,    59,    71,
     102,   102,     4,   102,    69,    12,    41,    42,    31,     0,
      49,    50,    22,   213,     3,     4,    88,     8,     4,   219,
      59,    12,     0,    84,    85,    86,    87,    18,    89,    90,
      69,    70,    39,   159,    44,   137,    25,   102,    48,    25,
      31,   102,     3,     4,   146,    84,    22,   247,    37,    38,
      89,    90,    41,    42,     4,    41,    42,    22,    65,    48,
      51,    18,    48,   102,    25,   126,     3,     4,    44,    36,
      16,    44,   174,    43,    31,    25,   137,     3,    51,    44,
      41,    42,   183,    47,    30,   146,    50,   213,    25,    80,
      36,    41,    42,   219,    47,   197,     4,    50,   137,    25,
      37,    38,    48,    47,    41,    42,    50,   146,   173,    10,
     182,    48,   173,   174,    47,    41,    42,    50,     3,    15,
     159,   247,   183,   124,    49,    50,   127,   128,   129,   120,
     131,    23,    24,    25,   173,    46,   197,    29,    30,     4,
      25,     5,     6,     7,     8,     9,   147,   148,    15,   150,
      43,   152,    37,    38,    18,   257,    41,    42,   197,   220,
     221,    46,     3,    43,    47,   231,   232,    50,   139,   140,
     141,    49,    50,     4,   213,    25,    40,    48,   149,   150,
     219,   152,    25,    47,    25,    48,    44,   259,   260,   261,
      48,    41,    42,    51,   255,    45,   257,    48,    41,    42,
      41,    42,   203,   204,   205,     4,    48,   279,   247,    48,
     249,   283,   284,    48,   280,   281,   255,   188,   189,    43,
      22,     4,     5,     6,     7,     8,     9,     3,    11,   230,
      13,    14,    45,   204,   205,    18,    19,     4,     4,     4,
       5,     6,     7,     8,     9,    43,    11,    47,    13,    14,
      50,    43,    35,    18,    19,    43,    39,    40,     5,     6,
       7,     8,     9,    10,    47,    43,    47,   238,     4,    50,
      35,    43,    22,    46,    39,    40,     4,     5,     6,     7,
       8,     9,    47,    11,    47,    13,    14,    50,     3,    25,
      18,    19,    45,    40,     4,     5,     6,     7,     8,     9,
      22,    11,     4,    13,    14,    41,    42,    35,    18,    19,
      25,    39,    40,    45,     5,     6,     7,     8,     9,    47,
      45,    47,    37,    38,    50,    35,    41,    42,    52,    39,
      40,    46,    49,    47,    46,    22,    50,    47,     4,     5,
       6,     7,     8,     9,    49,    11,    49,    13,    14,    40,
       3,     4,    18,    19,     3,    51,     4,     5,     6,     7,
       8,     9,    25,    11,    46,    13,    14,    51,     4,    35,
      18,    19,    25,    39,    40,     3,     4,    46,    41,    42,
      46,    43,    45,    43,    37,    38,    43,    35,    41,    42,
      46,    39,    40,    43,    20,    21,    43,    25,    46,    43,
      12,    46,    28,    49,    12,    31,    32,    33,    34,    37,
      38,    12,   120,    41,    42,     4,     5,     6,     7,     8,
       9,   226,    11,   257,    13,    14,    52,    16,    -1,    18,
      19,    -1,    -1,     4,     5,     6,     7,     8,     9,    -1,
      11,    -1,    13,    14,    -1,    16,    35,    18,    19,    -1,
      39,    40,     4,     5,     6,     7,     8,     9,    -1,    11,
      -1,    13,    14,    -1,    35,    -1,    18,    19,    39,    40,
      -1,    -1,     5,     6,     7,     8,     9,    10,     5,     6,
       7,     8,     9,    35,    17,    18,    -1,    39,    40,    20,
      21,    18,     5,     6,     7,     8,     9,    28,    -1,    -1,
      31,    32,    33,    34,    -1,    18,    -1,    40,    20,    21,
      -1,    -1,    -1,    40,    -1,    -1,    28,    -1,    49,    31,
      32,    33,    34,    -1,    23,    24,    25,    40,    20,    21,
      29,    30,    -1,    -1,    -1,    -1,    28,    49,    -1,    31,
      32,    33,    34,    -1,    -1,    23,    24,    25,    -1,    -1,
      49,    29,    30,    23,    24,    25,    -1,    49,    -1,    29,
      30,    23,    24,    25,    -1,    -1,    -1,    29,    30,    -1,
      -1,    49,    20,    21,    -1,    23,    24,    25,    -1,    49,
      28,    29,    30,    31,    32,    33,    34,    49,    20,    21,
      -1,    23,    24,    25,    -1,    43,    28,    29,    30,    31,
      32,    33,    34,    -1,    20,    21,    -1,    23,    24,    25,
      -1,    43,    28,    29,    30,    31,    32,    33,    34,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    43,    28,    -1,
      -1,    31,    32,    33,    34,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    43,    28,    -1,    -1,    31,    32,    33,
      34,    23,    24,    25,    -1,    -1,    -1,    29,    30,    43,
      -1,    -1,    -1,    -1,    20,    21,    -1,    23,    24,    25,
      -1,    43,    28,    29,    30,    31,    32,    33,    34,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    17,    18,    40,
      54,    55,    56,    57,    59,    61,    62,    63,    64,    65,
      66,     4,     4,    61,     4,     0,    36,    85,    57,    59,
      62,    64,    43,     4,    63,    61,    62,    65,    15,    46,
       3,    25,    41,    42,    82,     4,    15,    43,    62,    22,
      44,    48,     4,     4,    11,    13,    14,    19,    35,    39,
      59,    61,    69,    70,    71,    58,    59,    41,    42,    22,
      44,    69,     3,    37,    38,    46,    60,    82,    45,    82,
      18,    61,    67,    68,    44,    51,    48,    48,    48,    48,
      48,     3,    60,    70,    82,    43,     4,    16,    71,    22,
      26,    27,    72,    47,    59,    43,     3,    46,    60,    82,
      45,    82,    16,     3,    84,    22,    45,    61,     4,    49,
      50,    70,    82,    70,     3,     4,    48,    60,    70,    76,
      79,    82,    79,    71,     3,    70,    82,    48,    70,    73,
      76,    82,    43,    43,    43,    43,    48,    60,    70,    73,
      76,    79,    82,    43,    84,    22,    45,    47,    50,    46,
      22,     4,    68,    45,    45,    20,    21,    28,    31,    32,
      33,    34,    80,    81,    48,    79,    80,    80,    80,    49,
      80,    80,    49,    52,    49,    49,    49,    70,    73,    82,
      23,    24,    25,    29,    30,    49,    74,    75,    49,    74,
      74,    49,    74,    70,    76,    82,    43,    43,    43,    43,
      43,    43,    47,    46,    22,     3,    82,    83,    84,    46,
      51,    51,     3,    60,    70,    82,    70,    76,    77,    78,
      49,    46,    46,    71,    79,    43,    43,    43,    49,    43,
      70,    76,    82,    43,    43,    83,    84,    46,    47,    50,
      47,    83,    84,    70,    70,    72,    49,    50,    80,    69,
      69,    52,    74,    47,    47,    83,    84,    82,    47,    47,
      70,    82,    78,    47,    47,    71,    47,    47,    12,    49,
      46,    46,    71,    69,    69,    47,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    61,    61,    61,    62,    62,    63,    64,    64,    65,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72,    72,    73,
      73,    73,    73,    73,    74,    74,    74,    75,    75,    75,
      75,    75,    76,    77,    77,    78,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    80,    80,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    82,    82,    82,
      82,    83,    83,    84,    84,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     2,     1,     1,     1,
       2,     1,     2,     3,     3,     3,     2,     3,     4,     5,
       8,     6,     9,    10,     9,     7,     2,     4,     5,     8,
       5,     9,     9,    10,     4,     5,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     5,     1,     2,     4,
       5,     1,     3,     2,     3,     1,     2,     1,     4,     4,
       3,     6,     6,     4,     4,     4,     4,     4,     4,     2,
       7,    11,    11,     9,     7,     5,     5,     5,     5,     5,
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
#line 132 "proiect.y"
                      {
                        printf("Sintaxă corectă\n");
                        if (corect) {
                            printf("Corect semantic\n");
                            printTable();
                        }
                        else
                            printf("Incorect semantic\n");
                   }
#line 1668 "y.tab.c"
    break;

  case 3: /* optionale: var_globale functii user_types  */
#line 142 "proiect.y"
                                           {functie_curenta="main";}
#line 1674 "y.tab.c"
    break;

  case 4: /* optionale: functii user_types  */
#line 143 "proiect.y"
                           {functie_curenta="main";}
#line 1680 "y.tab.c"
    break;

  case 5: /* optionale: var_globale user_types  */
#line 144 "proiect.y"
                                {functie_curenta="main";}
#line 1686 "y.tab.c"
    break;

  case 6: /* optionale: var_globale functii  */
#line 145 "proiect.y"
                             {functie_curenta="main";}
#line 1692 "y.tab.c"
    break;

  case 7: /* optionale: user_types  */
#line 146 "proiect.y"
                   {functie_curenta="main";}
#line 1698 "y.tab.c"
    break;

  case 8: /* optionale: functii  */
#line 147 "proiect.y"
                {functie_curenta="main";}
#line 1704 "y.tab.c"
    break;

  case 9: /* optionale: var_globale  */
#line 148 "proiect.y"
                    {functie_curenta="main";}
#line 1710 "y.tab.c"
    break;

  case 10: /* var_globale: declaratie ';'  */
#line 150 "proiect.y"
                             { 
                      if((yyvsp[-1].param_t)->cons) 
                          insertConstTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip); 
                      else
                           insertVarTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip);
            }
#line 1721 "y.tab.c"
    break;

  case 13: /* var_globale: var_globale declaratie ';'  */
#line 158 "proiect.y"
                                         { 
                      if((yyvsp[-1].param_t)->cons) 
                          insertConstTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip); 
                      else
                           insertVarTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip);
            }
#line 1732 "y.tab.c"
    break;

  case 14: /* definitie: DEFINE ID NR  */
#line 165 "proiect.y"
                         { insertConstTable((yyvsp[-1].strval),(yyvsp[0].valnr)->tip); }
#line 1738 "y.tab.c"
    break;

  case 15: /* definitie: DEFINE ID LIT  */
#line 166 "proiect.y"
                          { struct tip_t *tip_expr=initTip_t("char"); insertConstTable((yyvsp[-1].strval),tip_expr); }
#line 1744 "y.tab.c"
    break;

  case 16: /* declaratii: declaratie ';'  */
#line 168 "proiect.y"
                            {(yyval.lista_param_t) = initTipListParam((yyvsp[-1].param_t));}
#line 1750 "y.tab.c"
    break;

  case 17: /* declaratii: declaratii declaratie ';'  */
#line 169 "proiect.y"
                                      {
                               (yyval.lista_param_t)=(yyvsp[-2].lista_param_t);
                               while((yyvsp[-2].lista_param_t)->urmator)
                                   (yyvsp[-2].lista_param_t)=(yyvsp[-2].lista_param_t)->urmator;
                               (yyvsp[-2].lista_param_t)->urmator=initTipListParam((yyvsp[-1].param_t));
                             }
#line 1761 "y.tab.c"
    break;

  case 18: /* declaratie: TIP ID ASSIGN LIT  */
#line 176 "proiect.y"
                              {
                              structDefinita((yyvsp[-3].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),0);
                              }
#line 1772 "y.tab.c"
    break;

  case 19: /* declaratie: CONST TIP ID ASSIGN LIT  */
#line 182 "proiect.y"
                                    {
                              structDefinita((yyvsp[-3].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),1);
                              }
#line 1783 "y.tab.c"
    break;

  case 20: /* declaratie: TIP ID '[' ']' ASSIGN '{' lista_lit '}'  */
#line 188 "proiect.y"
                                                    {
                              structDefinita((yyvsp[-7].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");//nu trebuie tot string aici? la fel si mai jos
                              tipuriEgale(tip_expr, (yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),0);
                              }
#line 1794 "y.tab.c"
    break;

  case 21: /* declaratie: TIP ID ASSIGN '{' lista_lit '}'  */
#line 194 "proiect.y"
                                            {
                              structDefinita((yyvsp[-5].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, (yyvsp[-5].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-5].tip),(yyvsp[-4].strval),0);
                              }
#line 1805 "y.tab.c"
    break;

  case 22: /* declaratie: TIP ID '[' NR ']' ASSIGN '{' lista_lit '}'  */
#line 200 "proiect.y"
                                                       {
                              structDefinita((yyvsp[-8].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-8].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),0);
                              }
#line 1816 "y.tab.c"
    break;

  case 23: /* declaratie: CONST TIP ID '[' NR ']' ASSIGN '{' lista_lit '}'  */
#line 206 "proiect.y"
                                                             {
                              structDefinita((yyvsp[-8].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-8].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),1);
                              }
#line 1827 "y.tab.c"
    break;

  case 24: /* declaratie: CONST TIP ID '[' ']' ASSIGN '{' lista_lit '}'  */
#line 212 "proiect.y"
                                                          {
                              structDefinita((yyvsp[-7].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("char");
                              tipuriEgale(tip_expr, (yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),1);
                              }
#line 1838 "y.tab.c"
    break;

  case 25: /* declaratie: CONST TIP ID ASSIGN '{' lista_lit '}'  */
#line 218 "proiect.y"
                                                  {
                              structDefinita((yyvsp[-5].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("string");
                              tipuriEgale(tip_expr, (yyvsp[-5].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-5].tip),(yyvsp[-4].strval),1);
                              }
#line 1849 "y.tab.c"
    break;

  case 26: /* declaratie: TIP ID  */
#line 224 "proiect.y"
                    {
                    structDefinita((yyvsp[-1].tip)->nume);
                    (yyval.param_t) = initTipParam((yyvsp[-1].tip),(yyvsp[0].strval),0);
                    }
#line 1858 "y.tab.c"
    break;

  case 27: /* declaratie: TIP ID ASSIGN NR  */
#line 228 "proiect.y"
                              {
                              structDefinita((yyvsp[-3].tip)->nume);
                              tipuriEgale((yyvsp[0].valnr)->tip, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),0);
                              }
#line 1868 "y.tab.c"
    break;

  case 28: /* declaratie: CONST TIP ID ASSIGN NR  */
#line 233 "proiect.y"
                                    {
                              structDefinita((yyvsp[-3].tip)->nume);
                              tipuriEgale((yyvsp[0].valnr)->tip, (yyvsp[-3].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),1);
                              }
#line 1878 "y.tab.c"
    break;

  case 29: /* declaratie: TIP ID '[' ']' ASSIGN '{' lista_nr '}'  */
#line 239 "proiect.y"
                                                   {
                              structDefinita((yyvsp[-7].tip)->nume);
                              (yyvsp[-7].tip)->dimensiune=(yyvsp[-1].lista_nr_t)->nr;
                              tipuriEgale((yyvsp[-1].lista_nr_t)->tip,(yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),0);
                              }
#line 1889 "y.tab.c"
    break;

  case 30: /* declaratie: TIP ID '[' NR ']'  */
#line 245 "proiect.y"
                              {
                              structDefinita((yyvsp[-4].tip)->nume);
                              (yyvsp[-4].tip)->dimensiune=(yyvsp[-1].valnr)->val;
                              (yyval.param_t) = initTipParam((yyvsp[-4].tip),(yyvsp[-3].strval),0);
                              }
#line 1899 "y.tab.c"
    break;

  case 31: /* declaratie: TIP ID '[' NR ']' ASSIGN '{' lista_nr '}'  */
#line 250 "proiect.y"
                                                      {
                              structDefinita((yyvsp[-8].tip)->nume);
                              (yyvsp[-8].tip)->dimensiune=(yyvsp[-5].valnr)->val;
                              tipuriEgale((yyvsp[-8].tip), (yyvsp[-1].lista_nr_t)->tip);
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),0);
                              }
#line 1910 "y.tab.c"
    break;

  case 32: /* declaratie: CONST TIP ID '[' ']' ASSIGN '{' lista_nr '}'  */
#line 256 "proiect.y"
                                                         {
                              structDefinita((yyvsp[-7].tip)->nume);
                              (yyvsp[-7].tip)->dimensiune=(yyvsp[-1].lista_nr_t)->nr;
                              tipuriEgale((yyvsp[-1].lista_nr_t)->tip, (yyvsp[-7].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-7].tip),(yyvsp[-6].strval),1);
                              }
#line 1921 "y.tab.c"
    break;

  case 33: /* declaratie: CONST TIP ID '[' NR ']' ASSIGN '{' lista_nr '}'  */
#line 262 "proiect.y"
                                                            {
                              structDefinita((yyvsp[-8].tip)->nume);
                              (yyvsp[-8].tip)->dimensiune=(yyvsp[-5].valnr)->val;
                              tipuriEgale((yyvsp[-1].lista_nr_t)->tip, (yyvsp[-8].tip));
                              (yyval.param_t) = initTipParam((yyvsp[-8].tip),(yyvsp[-7].strval),1);
                              }
#line 1932 "y.tab.c"
    break;

  case 34: /* declaratie: TIP ID ASSIGN BVAL  */
#line 268 "proiect.y"
                               {
                              structDefinita((yyvsp[-3].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("bool");
                              tipuriEgale((yyvsp[-3].tip), tip_expr);
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),0);
                              }
#line 1943 "y.tab.c"
    break;

  case 35: /* declaratie: CONST TIP ID ASSIGN BVAL  */
#line 274 "proiect.y"
                                     {
                              structDefinita((yyvsp[-3].tip)->nume);
                              struct tip_t *tip_expr=initTip_t("bool");
                              tipuriEgale((yyvsp[-3].tip), tip_expr);
                              (yyval.param_t) = initTipParam((yyvsp[-3].tip),(yyvsp[-2].strval),1);
                              }
#line 1954 "y.tab.c"
    break;

  case 36: /* BVAL: TRU  */
#line 281 "proiect.y"
           { (yyval.vali)=1; }
#line 1960 "y.tab.c"
    break;

  case 37: /* BVAL: FALS  */
#line 282 "proiect.y"
            { (yyval.vali)=0; }
#line 1966 "y.tab.c"
    break;

  case 38: /* TIP: INT  */
#line 284 "proiect.y"
          { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 1972 "y.tab.c"
    break;

  case 39: /* TIP: FLOAT  */
#line 285 "proiect.y"
            { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 1978 "y.tab.c"
    break;

  case 40: /* TIP: CHAR  */
#line 286 "proiect.y"
           { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 1984 "y.tab.c"
    break;

  case 41: /* TIP: STRING  */
#line 287 "proiect.y"
             { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 1990 "y.tab.c"
    break;

  case 42: /* TIP: BOOL  */
#line 288 "proiect.y"
           { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 1996 "y.tab.c"
    break;

  case 43: /* TIP: UTYPE ID  */
#line 289 "proiect.y"
               { isStruct((yyvsp[0].strval),NULL); structura_curenta=NULL; (yyval.tip)=initTip_t((yyvsp[0].strval));}
#line 2002 "y.tab.c"
    break;

  case 46: /* user_type: NEWTYPE ID '{' declaratii '}'  */
#line 294 "proiect.y"
                                          {
                    insertStructTable((yyvsp[-3].strval), (yyvsp[-1].lista_param_t));
                    structura_curenta = (yyvsp[-3].strval);
                    insertVarListTable((yyvsp[-1].lista_param_t));
                    structura_curenta = NULL;
                }
#line 2013 "y.tab.c"
    break;

  case 49: /* functie: declaratie_fct BGIN list END  */
#line 304 "proiect.y"
                                      { functie_curenta = NULL; tipuriEgale((yyvsp[-3].tip), (yyvsp[-1].tip));}
#line 2019 "y.tab.c"
    break;

  case 50: /* declaratie_fct: TIP ID '(' lista_param ')'  */
#line 306 "proiect.y"
                                           {
               structDefinita((yyvsp[-4].tip)->nume);
               functie_curenta = (yyvsp[-3].strval); 
               insertVarListTable((yyvsp[-1].lista_param_t));
               insertFuncTable((yyvsp[-3].strval), (yyvsp[-4].tip), (yyvsp[-1].lista_param_t));
               (yyval.tip)=(yyvsp[-4].tip);
           }
#line 2031 "y.tab.c"
    break;

  case 51: /* lista_param: param  */
#line 314 "proiect.y"
                    {(yyval.lista_param_t) = initTipListParam((yyvsp[0].param_t));}
#line 2037 "y.tab.c"
    break;

  case 52: /* lista_param: lista_param ',' param  */
#line 315 "proiect.y"
                                    {
                               (yyval.lista_param_t)=(yyvsp[-2].lista_param_t);
                               while((yyvsp[-2].lista_param_t)->urmator)
                                   (yyvsp[-2].lista_param_t)=(yyvsp[-2].lista_param_t)->urmator;
                               (yyvsp[-2].lista_param_t)->urmator=initTipListParam((yyvsp[0].param_t));
                             }
#line 2048 "y.tab.c"
    break;

  case 53: /* param: TIP ID  */
#line 322 "proiect.y"
               { (yyval.param_t) = initTipParam((yyvsp[-1].tip),(yyvsp[0].strval),0); }
#line 2054 "y.tab.c"
    break;

  case 54: /* param: CONST TIP ID  */
#line 323 "proiect.y"
                     {  (yyval.param_t) = initTipParam((yyvsp[-1].tip),(yyvsp[0].strval),1); }
#line 2060 "y.tab.c"
    break;

  case 56: /* list: list statement  */
#line 326 "proiect.y"
                      {if((yyvsp[-1].tip) && (yyvsp[0].tip))tipuriEgale((yyvsp[-1].tip),(yyvsp[0].tip)); if((yyvsp[-1].tip)) (yyval.tip)=(yyvsp[-1].tip); else if((yyvsp[0].tip)) (yyval.tip)=(yyvsp[0].tip);}
#line 2066 "y.tab.c"
    break;

  case 57: /* VAR: ID  */
#line 328 "proiect.y"
         {
         if(structDefinita((yyvsp[0].strval)) == 0){//nu sunt sigur daca am inteles ce e struct. daca e si vector, presupun ca merge aici
            (yyval.v)=initVar((yyvsp[0].strval), -1, 0);
         }
         else (yyval.v)=NULL;
         }
#line 2077 "y.tab.c"
    break;

  case 58: /* VAR: ID '[' NR ']'  */
#line 334 "proiect.y"
                   {
         if(structDefinita((yyvsp[-3].strval))){
            (yyval.v)=initVar((yyvsp[-3].strval), -1, 0);
         }
         else (yyval.v)=NULL;
         (yyval.v)=initVar((yyvsp[-3].strval), (yyvsp[-1].valnr)->val, 0);
         }
#line 2089 "y.tab.c"
    break;

  case 59: /* VAR: ID '[' VAR ']'  */
#line 341 "proiect.y"
                    {
         if(structDefinita((yyvsp[-3].strval))){
            (yyval.v)=initVar((yyvsp[-3].strval), -1, 0);
         }
         else (yyval.v)=NULL;
         struct tip_t *tip_expr=initTip_t("int");
         tipuriEgale(tip_expr, tipVar((yyvsp[-1].v)));
         (yyval.v)=initVar((yyvsp[-3].strval), 1, 0);
         }
#line 2103 "y.tab.c"
    break;

  case 60: /* VAR: ID '.' VAR  */
#line 350 "proiect.y"
                 {
         if(structDefinita((yyvsp[-2].strval)) == 0){
            (yyval.v)=initVar((yyvsp[-2].strval), -1, 0);
         }
         else (yyval.v)=NULL;
          isStruct((yyvsp[-2].strval),(yyvsp[0].v));
          (yyval.v)=initVar((yyvsp[-2].strval), -1, tipVar((yyvsp[0].v)));
          structura_curenta=NULL;
         }
#line 2117 "y.tab.c"
    break;

  case 61: /* VAR: ID '[' NR ']' '.' VAR  */
#line 359 "proiect.y"
                           {
         if(structDefinita((yyvsp[-5].strval))){
            (yyval.v)=initVar((yyvsp[-5].strval), -1, 0);
         }
         else (yyval.v)=NULL;
         isStruct((yyvsp[-5].strval),(yyvsp[0].v));
         (yyval.v)=initVar((yyvsp[-5].strval), (yyvsp[-3].valnr)->val,tipVar((yyvsp[0].v)));
         structura_curenta=NULL;
         }
#line 2131 "y.tab.c"
    break;

  case 62: /* VAR: ID '[' VAR ']' '.' VAR  */
#line 368 "proiect.y"
                            {
         if(structDefinita((yyvsp[-5].strval))){
            (yyval.v)=initVar((yyvsp[-5].strval), -1, 0);
         }
         else (yyval.v)=NULL;
         isStruct((yyvsp[-5].strval),(yyvsp[0].v));
         struct tip_t *tip_expr=initTip_t("int");
         tipuriEgale(tip_expr, tipVar((yyvsp[-3].v)));
         (yyval.v)=initVar((yyvsp[-5].strval), 1,tipVar((yyvsp[0].v)));
         structura_curenta=NULL;
         }
#line 2147 "y.tab.c"
    break;

  case 63: /* statement: VAR NEWVAL VAR ';'  */
#line 380 "proiect.y"
                               {
                         varDefinita((yyvsp[-1].v)->nume);
                         varNotConst((yyvsp[-3].v)->nume);
                         tipuriEgale(tipVar((yyvsp[-1].v)), tipVar((yyvsp[-3].v)));
                         (yyval.tip)=NULL;
                         }
#line 2158 "y.tab.c"
    break;

  case 64: /* statement: VAR NEWVAL NR ';'  */
#line 386 "proiect.y"
                               {
                         varNotConst((yyvsp[-3].v)->nume);
                         tipuriEgale((yyvsp[-1].valnr)->tip, tipVar((yyvsp[-3].v)));
                         (yyval.tip)=NULL;
                         }
#line 2168 "y.tab.c"
    break;

  case 65: /* statement: VAR NEWVAL lista_op ';'  */
#line 391 "proiect.y"
                                   {
                              varNotConst((yyvsp[-3].v)->nume);
                              tipuriEgale((yyvsp[-1].tip), tipVar((yyvsp[-3].v)));
                              (yyval.tip)=NULL;
                              }
#line 2178 "y.tab.c"
    break;

  case 66: /* statement: VAR NEWVAL apel ';'  */
#line 396 "proiect.y"
                                {
                                 varNotConst((yyvsp[-3].v)->nume);
                                 tipuriEgale(tipVar((yyvsp[-3].v)), (yyvsp[-1].tip));
                                 (yyval.tip)=NULL;
                          }
#line 2188 "y.tab.c"
    break;

  case 67: /* statement: VAR NEWVAL BVAL ';'  */
#line 401 "proiect.y"
                                {
                                 varNotConst((yyvsp[-3].v)->nume);
                                 struct tip_t *tip_expr=initTip_t("bool");
                                 tipuriEgale(tipVar((yyvsp[-3].v)), tip_expr);    
                                 (yyval.tip)=NULL;
                          }
#line 2199 "y.tab.c"
    break;

  case 68: /* statement: VAR NEWVAL lista_cond ';'  */
#line 407 "proiect.y"
                                      {
                                 varNotConst((yyvsp[-3].v)->nume);
                                 struct tip_t *tip_expr=initTip_t("bool");
                                 tipuriEgale(tipVar((yyvsp[-3].v)), tip_expr);    
                                 (yyval.tip)=NULL;                           
                          }
#line 2210 "y.tab.c"
    break;

  case 69: /* statement: declaratie ';'  */
#line 413 "proiect.y"
                           { 
                      if((yyvsp[-1].param_t)->cons) 
                          insertConstTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip); 
                      else
                           insertVarTable((yyvsp[-1].param_t)->nume,(yyvsp[-1].param_t)->tip);
                      (yyval.tip)=NULL;
            }
#line 2222 "y.tab.c"
    break;

  case 70: /* statement: IF '(' lista_cond ')' '{' list '}'  */
#line 420 "proiect.y"
                                               {(yyval.tip)=(yyvsp[-1].tip);}
#line 2228 "y.tab.c"
    break;

  case 71: /* statement: IF '(' lista_cond ')' '{' list '}' ELSE '{' list '}'  */
#line 421 "proiect.y"
                                                                 {if((yyvsp[-5].tip)) (yyval.tip)=(yyvsp[-5].tip); else if((yyvsp[-1].tip)) (yyval.tip)=(yyvsp[-1].tip); else (yyval.tip)=NULL;}
#line 2234 "y.tab.c"
    break;

  case 72: /* statement: FOR '(' statement '|' lista_cond '|' statement ')' '{' list '}'  */
#line 422 "proiect.y"
                                                                            {(yyval.tip)=(yyvsp[-1].tip);}
#line 2240 "y.tab.c"
    break;

  case 73: /* statement: FOR '(' statement '|' lista_cond '|' statement ')' statement  */
#line 423 "proiect.y"
                                                                         {(yyval.tip)=(yyvsp[0].tip);}
#line 2246 "y.tab.c"
    break;

  case 74: /* statement: WHILE '(' lista_cond ')' '{' list '}'  */
#line 424 "proiect.y"
                                                  {(yyval.tip)=(yyvsp[-1].tip);}
#line 2252 "y.tab.c"
    break;

  case 75: /* statement: WHILE '(' lista_cond ')' statement  */
#line 425 "proiect.y"
                                               {(yyval.tip)=(yyvsp[0].tip);}
#line 2258 "y.tab.c"
    break;

  case 76: /* statement: EVAL '(' VAR ')' ';'  */
#line 426 "proiect.y"
                                 {(yyval.tip)=NULL;}
#line 2264 "y.tab.c"
    break;

  case 77: /* statement: EVAL '(' NR ')' ';'  */
#line 427 "proiect.y"
                                {if (corect){
                                                 printf("Rezultatul expresiei din eval este %d\n", (yyvsp[-2].valnr)->val);
                                             }
                                             else {printf("Valorile nu sunt de tip int\n");} (yyval.tip)=NULL;}
#line 2273 "y.tab.c"
    break;

  case 78: /* statement: EVAL '(' lista_op ')' ';'  */
#line 431 "proiect.y"
                                      {(yyval.tip)=NULL;}
#line 2279 "y.tab.c"
    break;

  case 79: /* statement: TYPEOF '(' VAR ')' ';'  */
#line 432 "proiect.y"
                                    {
                                    if(varDefinita((yyvsp[-2].v)->nume)){
                                        (yyval.tip)=tipVar((yyvsp[-2].v));
                                        printf("Tipul variabilei este %s\n",tipVar((yyvsp[-2].v))->nume);
                                    }
                                    else (yyval.tip)=NULL; //crezi ca e ok asa?
                                    }
#line 2291 "y.tab.c"
    break;

  case 80: /* statement: TYPEOF '(' NR ')' ';'  */
#line 439 "proiect.y"
                                  {
                                    (yyval.tip)=NULL;
                                    printf("Tipul variabilei este %s\n",(yyvsp[-2].valnr)->tip->nume);
                                  }
#line 2300 "y.tab.c"
    break;

  case 81: /* statement: TYPEOF '(' LIT ')' ';'  */
#line 443 "proiect.y"
                                   {(yyval.tip)=NULL;
                                           printf("Tipul variabilei este char\n");
                                           }
#line 2308 "y.tab.c"
    break;

  case 82: /* statement: RET NR ';'  */
#line 446 "proiect.y"
                       { (yyval.tip)=(yyvsp[-1].valnr)->tip; }
#line 2314 "y.tab.c"
    break;

  case 83: /* statement: RET LIT ';'  */
#line 447 "proiect.y"
                       { struct tip_t *tip_expr=initTip_t("char"); (yyval.tip)=tip_expr; }
#line 2320 "y.tab.c"
    break;

  case 84: /* statement: RET BVAL ';'  */
#line 448 "proiect.y"
                         { struct tip_t *tip_expr=initTip_t("bool"); (yyval.tip)=tip_expr; }
#line 2326 "y.tab.c"
    break;

  case 85: /* statement: RET VAR ';'  */
#line 449 "proiect.y"
                        { varDefinita((yyvsp[-1].v)->nume); (yyval.tip)=tipVar((yyvsp[-1].v));}
#line 2332 "y.tab.c"
    break;

  case 89: /* lista_op: VAR operatie  */
#line 455 "proiect.y"
                        { varDefinita((yyvsp[-1].v)->nume); tipuriEgale((yyvsp[0].tip), tipVar((yyvsp[-1].v))); (yyval.tip)=(yyvsp[0].tip);}
#line 2338 "y.tab.c"
    break;

  case 90: /* lista_op: NR operatie  */
#line 456 "proiect.y"
                       {tipuriEgale((yyvsp[0].tip), initTip_t("float")); (yyval.tip)=(yyvsp[0].tip);}
#line 2344 "y.tab.c"
    break;

  case 91: /* lista_op: apel operatie  */
#line 457 "proiect.y"
                          { tipuriEgale((yyvsp[0].tip), (yyvsp[-1].tip)); }
#line 2350 "y.tab.c"
    break;

  case 92: /* lista_op: lista_op operatie  */
#line 458 "proiect.y"
                             {tipuriEgale((yyvsp[-1].tip),(yyvsp[0].tip));}
#line 2356 "y.tab.c"
    break;

  case 93: /* lista_op: '(' lista_op ')' operatie  */
#line 459 "proiect.y"
                                     {tipuriEgale((yyvsp[-2].tip),(yyvsp[0].tip)); (yyval.tip)=(yyvsp[-2].tip);}
#line 2362 "y.tab.c"
    break;

  case 94: /* operatie: OP VAR  */
#line 461 "proiect.y"
                  {varDefinita((yyvsp[0].v)->nume);(yyval.tip)=tipVar((yyvsp[0].v));}
#line 2368 "y.tab.c"
    break;

  case 95: /* operatie: OP NR  */
#line 462 "proiect.y"
                 {(yyval.tip)=(yyvsp[0].valnr)->tip;}
#line 2374 "y.tab.c"
    break;

  case 96: /* operatie: OP apel  */
#line 463 "proiect.y"
                   {(yyval.tip)=(yyvsp[0].tip);}
#line 2380 "y.tab.c"
    break;

  case 102: /* apel: ID '(' lista_arg ')'  */
#line 471 "proiect.y"
                            {
                         funDefinita((yyvsp[-3].strval),(yyvsp[-1].lista_param_t));
                         (yyval.tip)=tipRetFun((yyvsp[-3].strval));
                         }
#line 2389 "y.tab.c"
    break;

  case 103: /* lista_arg: arg  */
#line 476 "proiect.y"
                {(yyval.lista_param_t) = initTipListParam((yyvsp[0].param_t));}
#line 2395 "y.tab.c"
    break;

  case 104: /* lista_arg: lista_arg ',' arg  */
#line 477 "proiect.y"
                              {
                               (yyval.lista_param_t)=(yyvsp[-2].lista_param_t);
                               while((yyvsp[-2].lista_param_t)->urmator)
                                   (yyvsp[-2].lista_param_t)=(yyvsp[-2].lista_param_t)->urmator;
                               (yyvsp[-2].lista_param_t)->urmator=initTipListParam((yyvsp[0].param_t));
                             }
#line 2406 "y.tab.c"
    break;

  case 105: /* arg: VAR  */
#line 484 "proiect.y"
         { 
        varNotConst((yyvsp[0].v)->nume);
        varDefinita((yyvsp[0].v)->nume); 
        (yyval.param_t) = initTipParam(tipVar((yyvsp[0].v)),(yyvsp[0].v)->nume,0);
        }
#line 2416 "y.tab.c"
    break;

  case 106: /* arg: VAR NEWVAL VAR  */
#line 489 "proiect.y"
                     {
                   varNotConst((yyvsp[-2].v)->nume);
                   varDefinita((yyvsp[0].v)->nume);
                   tipuriEgale(tipVar((yyvsp[0].v)), tipVar((yyvsp[-2].v))); 
                   (yyval.param_t) = initTipParam(tipVar((yyvsp[-2].v)),(yyvsp[-2].v)->nume,0);
               }
#line 2427 "y.tab.c"
    break;

  case 107: /* arg: VAR NEWVAL NR  */
#line 495 "proiect.y"
                    {
                   varNotConst((yyvsp[-2].v)->nume);
                   tipuriEgale((yyvsp[0].valnr)->tip, tipVar((yyvsp[-2].v)));
                   (yyval.param_t) = initTipParam(tipVar((yyvsp[-2].v)),(yyvsp[-2].v)->nume,0);
               }
#line 2437 "y.tab.c"
    break;

  case 108: /* arg: apel  */
#line 500 "proiect.y"
           { (yyval.param_t) = initTipParam((yyvsp[0].tip),"functie",0); }
#line 2443 "y.tab.c"
    break;

  case 109: /* lista_cond: VAR cond  */
#line 502 "proiect.y"
                      { varDefinita((yyvsp[-1].v)->nume); tipuriEgale((yyvsp[0].tip), tipVar((yyvsp[-1].v))); }
#line 2449 "y.tab.c"
    break;

  case 110: /* lista_cond: NR cond  */
#line 503 "proiect.y"
                     { tipuriEgale((yyvsp[-1].valnr)->tip, (yyvsp[0].tip)); }
#line 2455 "y.tab.c"
    break;

  case 111: /* lista_cond: BVAL cond  */
#line 504 "proiect.y"
                       { struct tip_t *tip_expr=initTip_t("bool"); tipuriEgale(tip_expr, (yyvsp[0].tip)); }
#line 2461 "y.tab.c"
    break;

  case 112: /* lista_cond: LIT cond  */
#line 505 "proiect.y"
                      { struct tip_t *tip_expr=initTip_t("char"); tipuriEgale(tip_expr, (yyvsp[0].tip)); }
#line 2467 "y.tab.c"
    break;

  case 113: /* lista_cond: apel cond  */
#line 506 "proiect.y"
                       { tipuriEgale((yyvsp[0].tip), (yyvsp[-1].tip)); }
#line 2473 "y.tab.c"
    break;

  case 114: /* lista_cond: lista_cond cond  */
#line 507 "proiect.y"
                             {tipuriEgale((yyvsp[-1].tip),(yyvsp[0].tip));}
#line 2479 "y.tab.c"
    break;

  case 115: /* lista_cond: '(' lista_cond ')' cond  */
#line 508 "proiect.y"
                                     {tipuriEgale((yyvsp[-2].tip),(yyvsp[0].tip)); (yyval.tip)=(yyvsp[-2].tip);}
#line 2485 "y.tab.c"
    break;

  case 116: /* cond: OP_C VAR  */
#line 510 "proiect.y"
                {varDefinita((yyvsp[0].v)->nume); (yyval.tip)=tipVar((yyvsp[0].v));}
#line 2491 "y.tab.c"
    break;

  case 117: /* cond: OP_C NR  */
#line 511 "proiect.y"
               { (yyval.tip)=(yyvsp[0].valnr)->tip; }
#line 2497 "y.tab.c"
    break;

  case 118: /* cond: OP_C BVAL  */
#line 512 "proiect.y"
                 { struct tip_t *tip_expr=initTip_t("bool"); (yyval.tip) = tip_expr;}
#line 2503 "y.tab.c"
    break;

  case 119: /* cond: OP_C LIT  */
#line 513 "proiect.y"
                { struct tip_t *tip_expr=initTip_t("char"); (yyval.tip) = tip_expr;}
#line 2509 "y.tab.c"
    break;

  case 127: /* NR: NRI  */
#line 523 "proiect.y"
        { (yyval.valnr)=InitNr("int",(yyvsp[0].vali));}
#line 2515 "y.tab.c"
    break;

  case 128: /* NR: MINUS NRI  */
#line 524 "proiect.y"
              { (yyval.valnr)=InitNr("int",-(yyvsp[0].vali));}
#line 2521 "y.tab.c"
    break;

  case 129: /* NR: MINUS NRF  */
#line 525 "proiect.y"
              {(yyval.valnr)=InitNr("float",-(yyvsp[0].valf));}
#line 2527 "y.tab.c"
    break;

  case 130: /* NR: NRF  */
#line 526 "proiect.y"
        {(yyval.valnr)=InitNr("float",(yyvsp[0].valf));}
#line 2533 "y.tab.c"
    break;

  case 131: /* lista_nr: NR  */
#line 528 "proiect.y"
              {(yyval.lista_nr_t) = initTipListNr((yyvsp[0].valnr));}
#line 2539 "y.tab.c"
    break;

  case 132: /* lista_nr: lista_nr ',' NR  */
#line 529 "proiect.y"
                             {
                               tipuriEgale((yyvsp[-2].lista_nr_t)->tip,(yyvsp[0].valnr)->tip);
                               (yyval.lista_nr_t)=initTipListNr((yyvsp[0].valnr));
                               (yyvsp[-2].lista_nr_t)->urmator=(yyval.lista_nr_t);
                             }
#line 2549 "y.tab.c"
    break;

  case 133: /* lista_lit: LIT  */
#line 535 "proiect.y"
                 {(yyval.lista_lit_t) = initTipListLit((yyvsp[0].strval));}
#line 2555 "y.tab.c"
    break;

  case 134: /* lista_lit: lista_lit ',' LIT  */
#line 536 "proiect.y"
                               {
                               (yyval.lista_lit_t)=initTipListLit((yyvsp[0].strval));
                               (yyvsp[-2].lista_lit_t)->urmator=(yyval.lista_lit_t);
                             }
#line 2564 "y.tab.c"
    break;


#line 2568 "y.tab.c"

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

#line 545 "proiect.y"

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
    int var=0;
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
        } 
        else if (functie_curenta != NULL &&
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
void varNotConst (char *nume){
    if(varDefinita(nume)==0 && corect)
    {
        corect=0;
        printf("Valoarea lui %s nu poate fi schimbata\n", nume);
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
            return;
        }
        else
        {
            corect=0;
            printf("%s nu e usertype\n", nume);
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
