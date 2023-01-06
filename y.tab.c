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

int yylex();
int yyerror();

FILE *fisier_tabela;

struct expresie_str {
    char *val;
    struct expresie_str *str1, *str2;
    struct expresie_apel *apel;
    struct var *var;
};

struct expresie_bool {
    bool val;
    struct expresie_num *expr_comp_num1, *expr_comp_num2;
    struct expresie_str *expr_comp_str1, *expr_comp_str2;
    struct expresie_bool *expr_bool1, *expr_bool2;
    struct expresie_apel *apel;
    struct var *var;
};

struct expresie_num {
    float val;
    struct expresie_num *expr1, *expr2;
    struct expresie_apel *apel;
    struct var *var;
};

struct expresie {
    enum {
        EXPRESIE_NUM,
        EXPRESIE_BOOL,
        EXPRESIE_STR,
        EXPRESIE_NEW,
        EXPRESIE_APEL,
        EXPRESIE_VAR
    } tip_expr;
    struct expresie_num *num;
    struct expresie_bool *boolean;
    struct expresie_str *str;
    char *new;
    struct expresie_apel *apel;
    struct var *var;
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

struct expresie_apel {
    char *fun;
    struct lista_expresii *arg;
};

struct lista_param_t{
    struct tip_t *tip;
    char *nume;
    struct lista_param_t *urmator;
};

struct tip_t {
    char *nume;
    int dimensiune;
    int numar[1024];
};

struct info
{
    int intval;
    char strval[100];
    float floatval;
    char charval;
    int type;
    bool boolval;
};

struct param
{
	char denumire[50];
	struct info inf;
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

#line 211 "y.tab.c"

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
    WHILE = 267,                   /* WHILE  */
    FOR = 268,                     /* FOR  */
    BGIN = 269,                    /* BGIN  */
    END = 270,                     /* END  */
    DEFINE = 271,                  /* DEFINE  */
    CONST = 272,                   /* CONST  */
    TYPEOF = 273,                  /* TYPEOF  */
    NR = 274,                      /* NR  */
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
    MAIN = 290                     /* MAIN  */
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
#define WHILE 267
#define FOR 268
#define BGIN 269
#define END 270
#define DEFINE 271
#define CONST 272
#define TYPEOF 273
#define NR 274
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 141 "proiect.y"

    int val;
    char *strval;
    char charval;
    struct info *inf;
    struct lista_nr_t *lista_nr_t;
    struct lista_lit_t *lista_lit_t;
    struct lista_param_t *lista_param_t;
    struct param *param;
    struct expresie *expresie;
    struct var *v; 
    struct tip_t* tip;

#line 348 "y.tab.c"

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
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_BGIN = 14,                      /* BGIN  */
  YYSYMBOL_END = 15,                       /* END  */
  YYSYMBOL_DEFINE = 16,                    /* DEFINE  */
  YYSYMBOL_CONST = 17,                     /* CONST  */
  YYSYMBOL_TYPEOF = 18,                    /* TYPEOF  */
  YYSYMBOL_NR = 19,                        /* NR  */
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
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_progr = 45,                     /* progr  */
  YYSYMBOL_var_globale = 46,               /* var_globale  */
  YYSYMBOL_definitii = 47,                 /* definitii  */
  YYSYMBOL_definitie = 48,                 /* definitie  */
  YYSYMBOL_declaratii = 49,                /* declaratii  */
  YYSYMBOL_declaratie = 50,                /* declaratie  */
  YYSYMBOL_TIP = 51,                       /* TIP  */
  YYSYMBOL_user_types = 52,                /* user_types  */
  YYSYMBOL_user_type = 53,                 /* user_type  */
  YYSYMBOL_functii = 54,                   /* functii  */
  YYSYMBOL_functie = 55,                   /* functie  */
  YYSYMBOL_lista_param = 56,               /* lista_param  */
  YYSYMBOL_param = 57,                     /* param  */
  YYSYMBOL_list = 58,                      /* list  */
  YYSYMBOL_VAR = 59,                       /* VAR  */
  YYSYMBOL_statement = 60,                 /* statement  */
  YYSYMBOL_NEWVAL = 61,                    /* NEWVAL  */
  YYSYMBOL_op_list = 62,                   /* op_list  */
  YYSYMBOL_operation = 63,                 /* operation  */
  YYSYMBOL_OP = 64,                        /* OP  */
  YYSYMBOL_lista_cond = 65,                /* lista_cond  */
  YYSYMBOL_cond = 66,                      /* cond  */
  YYSYMBOL_OP_C = 67,                      /* OP_C  */
  YYSYMBOL_lista_nr = 68,                  /* lista_nr  */
  YYSYMBOL_lista_lit = 69,                 /* lista_lit  */
  YYSYMBOL_bloc = 70                       /* bloc  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      41,    42,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   169,   169,   177,   185,   193,   201,   209,   217,   225,
     234,   235,   236,   238,   239,   241,   242,   244,   245,   247,
     251,   257,   263,   269,   275,   281,   285,   291,   297,   303,
     309,   316,   317,   318,   319,   320,   322,   323,   325,   327,
     328,   330,   336,   337,   340,   341,   342,   343,   344,   346,
     347,   349,   353,   358,   364,   365,   371,   377,   378,   379,
     380,   381,   382,   383,   384,   388,   389,   390,   391,   393,
     394,   395,   397,   398,   400,   401,   402,   404,   405,   406,
     407,   409,   410,   412,   413,   414,   416,   417,   418,   419,
     420,   421,   422,   424,   425,   427,   428,   430
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
  "FLOAT", "CHAR", "BOOL", "STRING", "NEWTYPE", "IF", "WHILE", "FOR",
  "BGIN", "END", "DEFINE", "CONST", "TYPEOF", "NR", "GR", "LW", "ASSIGN",
  "PLUS", "MINUS", "ADD", "DEDUCT", "EQUAL", "DIV", "MOD", "AND", "OR",
  "NOT", "XOR", "EVAL", "MAIN", "';'", "'['", "']'", "'{'", "'}'", "'('",
  "')'", "','", "$accept", "progr", "var_globale", "definitii",
  "definitie", "declaratii", "declaratie", "TIP", "user_types",
  "user_type", "functii", "functie", "lista_param", "param", "list", "VAR",
  "statement", "NEWVAL", "op_list", "operation", "OP", "lista_cond",
  "cond", "OP_C", "lista_nr", "lista_lit", "bloc", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-176)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     221,  -176,  -176,     8,  -176,    17,    40,    57,   294,    68,
      91,   209,   276,  -176,   262,    59,   100,    28,  -176,   209,
     101,  -176,    49,    92,   138,    38,   140,   151,   164,   118,
    -176,  -176,  -176,   178,    28,   209,  -176,  -176,   262,   184,
     166,  -176,    74,  -176,  -176,    28,   171,  -176,  -176,   270,
      32,   210,   262,  -176,  -176,   237,   201,   258,   259,   256,
     268,   269,   271,   272,   228,   229,   275,   273,  -176,    28,
    -176,   103,  -176,   296,    45,   281,  -176,  -176,  -176,   278,
     295,   315,   153,   282,   280,   283,   303,    14,    14,   118,
     116,    21,  -176,   287,    33,  -176,  -176,   122,  -176,  -176,
    -176,   286,   304,   299,   321,   179,  -176,   305,   289,  -176,
      81,  -176,   307,   315,   308,   293,   245,    14,   245,   290,
    -176,   291,   298,   297,   300,   301,   125,    35,   182,   302,
    -176,  -176,   224,    35,   224,  -176,  -176,  -176,   313,   306,
     332,    67,   323,   281,   309,   315,  -176,   335,   310,   129,
     311,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,   336,
     312,   123,   162,   174,    14,   316,   317,   319,  -176,  -176,
    -176,  -176,   320,   336,   318,   322,   128,   325,   324,   326,
     327,  -176,  -176,   281,   152,   118,  -176,   315,   160,  -176,
     315,  -176,   327,  -176,   245,  -176,  -176,   118,  -176,   118,
    -176,   328,  -176,  -176,  -176,  -176,  -176,   172,  -176,  -176,
    -176,  -176,   172,   327,  -176,   169,   192,  -176,  -176,   246,
     193,  -176,   202,   220,   175,    54,    94,   118,  -176,   251,
    -176,   338,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
     329,  -176,  -176,   186,   118,  -176,   105,  -176
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    31,    32,     0,    35,     0,     0,     0,     0,     0,
       0,     0,    11,    13,    12,     0,     0,     0,    36,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    33,    34,     0,     0,     0,     8,    14,    10,     0,
       0,    17,    19,    37,     6,     0,     0,     7,    39,     0,
       0,     0,     0,    16,    15,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       5,    19,    18,     0,     0,     0,     3,    40,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,     0,     0,    70,    71,     0,    49,     2,
      20,     0,     0,     0,     0,     0,    42,     0,     0,    95,
       0,    38,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    50,     0,     0,     0,    55,    54,    53,    25,     0,
       0,    44,     0,     0,     0,     0,    24,     0,     0,     0,
       0,    52,    91,    92,    89,    86,    87,    88,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    69,     0,     0,     0,    43,     0,     0,    96,
       0,    30,     0,    85,     0,    84,    83,     0,    58,     0,
      62,     0,    68,    67,    66,    64,    76,     0,    63,    75,
      74,    65,    56,     0,    93,     0,     0,    46,    45,     0,
       0,    23,     0,     0,     0,     0,     0,     0,    73,     0,
      22,     0,    48,    41,    27,    29,    28,    82,    57,    61,
       0,    26,    94,     0,     0,    60,     0,    59
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,  -176,  -176,   339,    -6,    -9,     0,    -4,    11,
     330,    78,   176,   204,  -175,   -74,   -62,   222,   -85,   -61,
      61,   -87,   143,  -115,  -145,  -109,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,    15,    39,    17,    18,
      19,    20,   105,   106,    64,    65,    66,    97,   129,   130,
     173,   119,   120,   159,   215,   110,    21
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,   121,    93,   161,   149,    40,    38,    34,    28,   135,
     219,    33,    22,   118,   118,    45,   125,   128,    58,    33,
     134,    23,   225,   137,   226,    58,    36,   122,    43,    40,
     160,    69,    44,   116,    47,    33,   188,    58,     6,    58,
     126,    53,   174,   118,    24,    43,    82,   223,   178,    68,
      70,    79,   132,   134,   132,   117,    43,    54,    58,   134,
      76,    25,   127,     9,   101,    59,    60,    61,   229,   246,
      80,    49,    62,    40,   133,   104,   127,   201,   220,   224,
      43,   222,    29,   102,    99,   193,    50,   196,    63,   182,
     118,    30,    95,    96,   238,    41,    73,    46,    58,   206,
     198,   200,   210,   140,    42,    59,    60,    61,   183,    58,
     218,    74,    62,    46,    51,    75,    59,    60,    61,   123,
      58,   146,    58,    62,   147,    73,    58,    58,    63,    59,
      60,    61,    58,   134,   239,   124,    62,    48,   134,    63,
      74,   136,   195,   104,    55,   247,   228,   209,   168,   169,
     118,   228,    63,   170,   171,    56,    58,    93,     1,     2,
       3,     4,     5,    93,    93,   240,    58,   172,    57,   191,
       8,   217,   147,    59,    60,    61,    58,    52,    58,    58,
      62,   245,    67,   104,    93,    59,    60,    61,    71,   176,
      58,   132,    62,   111,   116,   176,    63,    59,    60,    61,
     221,   197,    72,   147,    62,   168,   169,    77,    63,   230,
     170,   171,   231,   199,     1,     2,    31,     4,    32,     6,
      63,   142,   143,    84,   175,   244,     1,     2,     3,     4,
       5,     6,    58,   234,   232,   143,   147,     7,     8,    59,
      60,    61,   235,    92,     9,   147,    62,   168,   169,    81,
      58,    94,   170,   171,    95,    96,     9,    59,    60,    61,
     236,   233,    63,   231,    62,   152,   153,     1,     2,     3,
       4,     5,   154,    78,    83,   155,   156,   157,   158,     8,
      63,     1,     2,     3,     4,     5,     1,     2,    31,     4,
      32,   241,     7,     8,   231,    85,    86,    87,   103,     1,
       2,    26,     4,    27,     1,     2,    31,     4,    32,    88,
      89,    98,    90,    91,    75,   100,   107,   108,   109,   113,
     112,   114,   115,   131,   138,   141,   139,   144,   145,   148,
     150,   151,   162,   163,   164,   179,   181,   185,   189,   165,
      58,    35,   166,   167,   177,   180,   214,   186,   187,   190,
     192,    37,   202,   203,   194,   204,   205,   242,   208,   216,
     207,   211,     0,   184,   227,   213,   212,   237,     0,     0,
       0,   243
};

static const yytype_int16 yycheck[] =
{
       0,    88,    64,   118,   113,    14,    12,    11,     8,    94,
     185,    11,     4,    87,    88,    19,    90,    91,     4,    19,
      94,     4,   197,    97,   199,     4,    11,    89,    17,    38,
     117,    35,    17,    19,    19,    35,   145,     4,    10,     4,
      19,     3,   127,   117,     4,    34,    52,   192,   133,    34,
      35,    19,    19,   127,    19,    41,    45,    19,     4,   133,
      45,     4,    41,    35,    19,    11,    12,    13,   213,   244,
      38,    22,    18,    82,    41,    75,    41,   164,   187,   194,
      69,   190,    14,    38,    69,   159,    37,   161,    34,    22,
     164,     0,    25,    26,    40,    36,    22,    19,     4,   173,
     162,   163,   176,   103,     4,    11,    12,    13,    41,     4,
     184,    37,    18,    35,    22,    41,    11,    12,    13,     3,
       4,    40,     4,    18,    43,    22,     4,     4,    34,    11,
      12,    13,     4,   207,    40,    19,    18,    36,   212,    34,
      37,    19,    19,   143,     4,    40,   207,    19,    23,    24,
     224,   212,    34,    28,    29,     4,     4,   219,     5,     6,
       7,     8,     9,   225,   226,   227,     4,    42,     4,    40,
      17,    19,    43,    11,    12,    13,     4,    39,     4,     4,
      18,   243,     4,   183,   246,    11,    12,    13,     4,   128,
       4,    19,    18,    40,    19,   134,    34,    11,    12,    13,
      40,    39,    36,    43,    18,    23,    24,    36,    34,    40,
      28,    29,    43,    39,     5,     6,     7,     8,     9,    10,
      34,    42,    43,    22,    42,    39,     5,     6,     7,     8,
       9,    10,     4,    40,    42,    43,    43,    16,    17,    11,
      12,    13,    40,    15,    35,    43,    18,    23,    24,    39,
       4,    22,    28,    29,    25,    26,    35,    11,    12,    13,
      40,    15,    34,    43,    18,    20,    21,     5,     6,     7,
       8,     9,    27,     3,    37,    30,    31,    32,    33,    17,
      34,     5,     6,     7,     8,     9,     5,     6,     7,     8,
       9,    40,    16,    17,    43,    37,    37,    41,    17,     5,
       6,     7,     8,     9,     5,     6,     7,     8,     9,    41,
      41,    36,    41,    41,    41,    19,    38,    22,     3,    39,
      38,    38,    19,    36,    38,     4,    22,    22,    39,    22,
      22,    38,    42,    42,    36,    22,     4,    14,     3,    42,
       4,    11,    42,    42,    42,    39,    19,   143,    39,    39,
      39,    12,    36,    36,    42,    36,    36,    19,    36,   183,
      42,    36,    -1,   141,    36,    39,    42,   224,    -1,    -1,
      -1,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    16,    17,    35,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    70,     4,     4,     4,     4,     7,     9,    51,    14,
       0,     7,     9,    51,    52,    54,    70,    48,    49,    51,
      50,    36,     4,    53,    70,    52,    55,    70,    36,    22,
      37,    22,    39,     3,    19,     4,     4,     4,     4,    11,
      12,    13,    18,    34,    58,    59,    60,     4,    70,    52,
      70,     4,    36,    22,    37,    41,    70,    36,     3,    19,
      38,    39,    49,    37,    22,    37,    37,    41,    41,    41,
      41,    41,    15,    60,    22,    25,    26,    61,    36,    70,
      19,    19,    38,    17,    51,    56,    57,    38,    22,     3,
      69,    40,    38,    39,    38,    19,    19,    41,    59,    65,
      66,    65,    60,     3,    19,    59,    19,    41,    59,    62,
      63,    36,    19,    41,    59,    62,    19,    59,    38,    22,
      51,     4,    42,    43,    22,    39,    40,    43,    22,    69,
      22,    38,    20,    21,    27,    30,    31,    32,    33,    67,
      65,    67,    42,    42,    36,    42,    42,    42,    23,    24,
      28,    29,    42,    64,    62,    42,    64,    42,    62,    22,
      39,     4,    22,    41,    61,    14,    57,    39,    69,     3,
      39,    40,    39,    59,    42,    19,    59,    39,    60,    39,
      60,    65,    36,    36,    36,    36,    59,    42,    36,    19,
      59,    36,    42,    39,    19,    68,    56,    19,    59,    58,
      69,    40,    69,    68,    67,    58,    58,    36,    63,    68,
      40,    43,    42,    15,    40,    40,    40,    66,    40,    40,
      60,    40,    19,    42,    39,    60,    58,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      46,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    51,    51,    51,    51,    51,    52,    52,    53,    54,
      54,    55,    56,    56,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    61,    62,    62,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    68,    68,    69,    69,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     3,     2,     2,     2,     1,
       2,     1,     1,     1,     2,     3,     3,     2,     3,     2,
       4,     4,     8,     8,     6,     5,     9,     9,     9,     9,
       7,     1,     1,     1,     1,     1,     1,     2,     5,     2,
       3,     8,     1,     3,     2,     4,     4,     3,     5,     2,
       3,     1,     4,     3,     3,     3,     5,     7,     5,    11,
       9,     7,     5,     5,     5,     5,     5,     5,     5,     1,
       1,     1,     1,     4,     3,     3,     3,     1,     1,     1,
       1,     1,     5,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     4
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
#line 169 "proiect.y"
                                             {printf("Sintaxă corectă\n");
                                             if (corect) {
                                             printf("Corect semantic\n");
                                             printTable();
                                             }
                                             else
                                             printf("Incorect semantic\n");
                                             }
#line 1579 "y.tab.c"
    break;

  case 3: /* progr: functii user_types bloc  */
#line 177 "proiect.y"
                                {printf("Sintaxă corectă\n");
                              if (corect) {
                              printf("Corect semantic\n");
                              printTable();
                              }
                              else
                              printf("Incorect semantic\n");
                              }
#line 1592 "y.tab.c"
    break;

  case 4: /* progr: var_globale user_types bloc  */
#line 185 "proiect.y"
                                    {printf("Sintaxă corectă\n");
                                   if (corect) {
                                   printf("Corect semantic\n");
                                   printTable();
                                   }
                                   else
                                   printf("Incorect semantic\n");
                                   }
#line 1605 "y.tab.c"
    break;

  case 5: /* progr: var_globale functii bloc  */
#line 193 "proiect.y"
                                 {printf("Sintaxă corectă\n");
                                   if (corect) {
                                   printf("Corect semantic\n");
                                   printTable();
                                   }
                                   else
                                   printf("Incorect semantic\n");
                                   }
#line 1618 "y.tab.c"
    break;

  case 6: /* progr: user_types bloc  */
#line 201 "proiect.y"
                        {printf("Sintaxă corectă\n");
                         if (corect) {
                         printf("Corect semantic\n");
                         printTable();
                         }
                         else
                         printf("Incorect semantic\n");
                         }
#line 1631 "y.tab.c"
    break;

  case 7: /* progr: functii bloc  */
#line 209 "proiect.y"
                     {printf("Sintaxă corectă\n");
                    if (corect) {
                    printf("Corect semantic\n");
                    printTable();
                    }
                    else
                    printf("Incorect semantic\n");
                    }
#line 1644 "y.tab.c"
    break;

  case 8: /* progr: var_globale bloc  */
#line 217 "proiect.y"
                         {printf("Sintaxă corectă\n");
                         if (corect) {
                         printf("Corect semantic\n");
                         printTable();
                         }
                         else
                         printf("Incorect semantic\n");
                         }
#line 1657 "y.tab.c"
    break;

  case 9: /* progr: bloc  */
#line 225 "proiect.y"
             {printf("Sintaxă corectă\n");
              if (corect) {
               printf("Corect semantic\n");
               printTable();
               }
               else
               printf("Incorect semantic\n");
               }
#line 1670 "y.tab.c"
    break;

  case 19: /* declaratie: TIP ID  */
#line 247 "proiect.y"
                    {
                    structDefinita((yyvsp[-1].tip)->nume);
                    insertVarTable((yyvsp[0].strval), (yyvsp[-1].tip));
                    }
#line 1679 "y.tab.c"
    break;

  case 20: /* declaratie: TIP ID ASSIGN NR  */
#line 251 "proiect.y"
                              {
                              structDefinita((yyvsp[-3].tip)->nume);
                              struct tip_t *tip_expr=tipExpr((yyvsp[0].val));
                              tipuriEgale(tip_expr, (yyvsp[-3].tip));
                              insertVarTable((yyvsp[-2].strval), (yyvsp[-3].tip));
                              }
#line 1690 "y.tab.c"
    break;

  case 21: /* declaratie: CHAR ID ASSIGN LIT  */
#line 257 "proiect.y"
                               {
                              struct tip_t *tip_expr=tipExpr((yyvsp[0].charval));
                              struct tip_t *tip_expr2=initTip_t("char");
                              tipuriEgale(tip_expr,tip_expr2);
                              insertVarTable((yyvsp[-2].strval),tip_expr2);
                              }
#line 1701 "y.tab.c"
    break;

  case 22: /* declaratie: TIP ID '[' ']' ASSIGN '{' lista_nr '}'  */
#line 263 "proiect.y"
                                                   {
                              structDefinita((yyvsp[-7].tip)->nume);
                              struct tip_t *tip_expr=tipExpr((yyvsp[-1].expresie));
                              tipuriEgale(tip_expr,(yyvsp[-7].tip));
                              insertVarTable((yyvsp[-6].strval), (yyvsp[-7].tip));
                              }
#line 1712 "y.tab.c"
    break;

  case 23: /* declaratie: CHAR ID '[' ']' ASSIGN '{' lista_lit '}'  */
#line 269 "proiect.y"
                                                     {
                              struct tip_t *tip_expr=tipExpr((yyvsp[-1].expresie));
                              struct tip_t *tip_expr2=initTip_t("char");
                              tipuriEgale(tip_expr,tip_expr2);
                              insertVarTable((yyvsp[-6].strval), tip_expr2);
                              }
#line 1723 "y.tab.c"
    break;

  case 24: /* declaratie: STRING ID ASSIGN '{' lista_lit '}'  */
#line 275 "proiect.y"
                                               {
                              struct tip_t *tip_expr=tipExpr((yyvsp[-1].expresie));
                               struct tip_t *tip_expr2=initTip_t("string");
                              tipuriEgale(tip_expr,tip_expr2);
                              insertVarTable((yyvsp[-4].strval), tip_expr2);
                              }
#line 1734 "y.tab.c"
    break;

  case 25: /* declaratie: TIP ID '[' NR ']'  */
#line 281 "proiect.y"
                              {
                              structDefinita((yyvsp[-4].tip)->nume);
                              insertVarTable((yyvsp[-3].strval), (yyvsp[-4].tip));
                              }
#line 1743 "y.tab.c"
    break;

  case 26: /* declaratie: TIP ID '[' NR ']' ASSIGN '{' lista_nr '}'  */
#line 285 "proiect.y"
                                                      {
                              structDefinita((yyvsp[-8].tip)->nume);
                              struct tip_t *tip_expr=tipExpr((yyvsp[-1].expresie));
                              tipuriEgale(tip_expr, (yyvsp[-8].tip));
                              insertVarTable((yyvsp[-7].strval), (yyvsp[-8].tip));
                              }
#line 1754 "y.tab.c"
    break;

  case 27: /* declaratie: CHAR ID '[' NR ']' ASSIGN '{' lista_lit '}'  */
#line 291 "proiect.y"
                                                        {
                              struct tip_t *tip_expr=tipExpr((yyvsp[-1].expresie));
                              struct tip_t *tip_expr2=initTip_t("char");
                              tipuriEgale(tip_expr,tip_expr2);
                              insertVarTable((yyvsp[-7].strval), tip_expr2);
                              }
#line 1765 "y.tab.c"
    break;

  case 28: /* declaratie: CONST TIP ID '[' ']' ASSIGN '{' lista_nr '}'  */
#line 297 "proiect.y"
                                                         {
                              structDefinita((yyvsp[-7].tip)->nume);
                              struct tip_t *tip_expr=tipExpr((yyvsp[-1].expresie));
                              tipuriEgale(tip_expr, (yyvsp[-7].tip));
                              insertVarTable((yyvsp[-6].strval), (yyvsp[-7].tip));
                              }
#line 1776 "y.tab.c"
    break;

  case 29: /* declaratie: CONST CHAR ID '[' ']' ASSIGN '{' lista_lit '}'  */
#line 303 "proiect.y"
                                                           {
                              struct tip_t *tip_expr=tipExpr((yyvsp[-1].expresie));
                               struct tip_t *tip_expr2=initTip_t("char");
                              tipuriEgale(tip_expr,tip_expr2);
                              insertVarTable((yyvsp[-7].strval), tip_expr2);
                              }
#line 1787 "y.tab.c"
    break;

  case 30: /* declaratie: CONST STRING ID ASSIGN '{' lista_lit '}'  */
#line 309 "proiect.y"
                                                     {
                              struct tip_t *tip_expr=tipExpr((yyvsp[-1].expresie));
                               struct tip_t *tip_expr2=initTip_t("string");
                              tipuriEgale(tip_expr,tip_expr2);
                              insertVarTable((yyvsp[-5].strval), tip_expr2);
                              }
#line 1798 "y.tab.c"
    break;

  case 31: /* TIP: INT  */
#line 316 "proiect.y"
          { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 1804 "y.tab.c"
    break;

  case 32: /* TIP: FLOAT  */
#line 317 "proiect.y"
            { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 1810 "y.tab.c"
    break;

  case 33: /* TIP: CHAR  */
#line 318 "proiect.y"
           { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 1816 "y.tab.c"
    break;

  case 34: /* TIP: STRING  */
#line 319 "proiect.y"
             { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 1822 "y.tab.c"
    break;

  case 35: /* TIP: BOOL  */
#line 320 "proiect.y"
           { (yyval.tip)=initTip_t((yyvsp[0].strval)); }
#line 1828 "y.tab.c"
    break;

  case 41: /* functie: TIP ID '(' lista_param ')' BGIN list END  */
#line 331 "proiect.y"
                {
                    insertFuncTable((yyvsp[-6].strval), (yyvsp[-7].tip), (yyvsp[-4].lista_param_t));
                    functie_curenta = (yyvsp[-6].strval);
                }
#line 1837 "y.tab.c"
    break;

  case 42: /* lista_param: param  */
#line 336 "proiect.y"
                    {(yyval.lista_param_t) = 0;}
#line 1843 "y.tab.c"
    break;

  case 43: /* lista_param: lista_param ',' param  */
#line 337 "proiect.y"
                                    {(yyval.lista_param_t) = 0;}
#line 1849 "y.tab.c"
    break;

  case 44: /* param: TIP ID  */
#line 340 "proiect.y"
               {(yyval.param) = 0;}
#line 1855 "y.tab.c"
    break;

  case 45: /* param: TIP ID NEWVAL VAR  */
#line 341 "proiect.y"
                          {(yyval.param) = 0;}
#line 1861 "y.tab.c"
    break;

  case 46: /* param: TIP ID NEWVAL NR  */
#line 342 "proiect.y"
                         {(yyval.param) = 0;}
#line 1867 "y.tab.c"
    break;

  case 47: /* param: CONST TIP ID  */
#line 343 "proiect.y"
                     {(yyval.param) = 0;}
#line 1873 "y.tab.c"
    break;

  case 48: /* param: TIP ID '(' lista_param ')'  */
#line 344 "proiect.y"
                                   {(yyval.param) = 0;}
#line 1879 "y.tab.c"
    break;

  case 51: /* VAR: ID  */
#line 349 "proiect.y"
         {
         //de adaugat verificare daca e declarat si nu e vector
         (yyval.v)=initVar((yyvsp[0].strval), -1);
         }
#line 1888 "y.tab.c"
    break;

  case 52: /* VAR: ID '[' NR ']'  */
#line 353 "proiect.y"
                   {
         //de adaugat verificare daca e declarat si e vector
         (yyval.v)=initVar((yyvsp[-3].strval), (yyvsp[-1].val));
         }
#line 1897 "y.tab.c"
    break;

  case 53: /* statement: VAR NEWVAL VAR  */
#line 358 "proiect.y"
                           {
                         varDefinita((yyvsp[-2].v)->nume);
                         struct tip_t *tip_var1 = tipVar((yyvsp[0].v));
                         struct tip_t *tip_var2 = tipVar((yyvsp[-2].v));
                         tipuriEgale(tip_var1, tip_var2);
                         }
#line 1908 "y.tab.c"
    break;

  case 55: /* statement: VAR ASSIGN op_list  */
#line 365 "proiect.y"
                              {
                              varDefinita((yyvsp[-2].v)->nume);
                              struct tip_t *tip_expr = tipExpr((yyvsp[0].expresie));
                              struct tip_t *tip_var = tipVar((yyvsp[-2].v));
                              tipuriEgale(tip_expr, tip_var);
                              }
#line 1919 "y.tab.c"
    break;

  case 56: /* statement: VAR ASSIGN '(' op_list ')'  */
#line 371 "proiect.y"
                                      {
                                        varDefinita((yyvsp[-4].v)->nume);
                                        struct tip_t *tip_expr = tipExpr((yyvsp[-1].expresie));
                                        struct tip_t *tip_var = tipVar((yyvsp[-4].v));
                                        tipuriEgale(tip_expr, tip_var);
                                        }
#line 1930 "y.tab.c"
    break;

  case 64: /* statement: EVAL '(' NR ')' ';'  */
#line 384 "proiect.y"
                                {if (corect){
                                                 printf("Rezultatul expresiei din eval este %d\n", (yyvsp[-2].val));
                                             }
                                             else {printf("Valorile nu sunt de tip int\n");}}
#line 1939 "y.tab.c"
    break;

  case 72: /* op_list: operation  */
#line 397 "proiect.y"
                    {(yyval.expresie) = 0;}
#line 1945 "y.tab.c"
    break;

  case 73: /* op_list: '(' op_list ')' operation  */
#line 398 "proiect.y"
                                    {(yyval.expresie) = 0;}
#line 1951 "y.tab.c"
    break;

  case 93: /* lista_nr: NR  */
#line 424 "proiect.y"
              {(yyval.expresie) = 0;}
#line 1957 "y.tab.c"
    break;

  case 95: /* lista_lit: LIT  */
#line 427 "proiect.y"
                {(yyval.expresie) = 0;}
#line 1963 "y.tab.c"
    break;


#line 1967 "y.tab.c"

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

#line 434 "proiect.y"

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
                if (strcmp(j->nume, v->nume) == 0)
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
    } else if (expr->tip_expr == EXPRESIE_NEW) {
        tip->nume = expr->new;
        tip->dimensiune = 0;
    } else if (expr->tip_expr == EXPRESIE_APEL) {
        tip = tipRetFun(expr->apel->fun);
    } else if (expr->tip_expr == EXPRESIE_VAR) {
        tip = tipVar(expr->var);
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
        tipuriEgale(tip_expr, param->tip);
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
    strcpy(expr->nume, val);
    expr->dimensiune=0;
    expr->numar[0]=0;
    return expr;
}
struct var * initVar(char * val, int index)
{
    struct var* expr = (struct var*)malloc(sizeof(struct var));
    strcpy(expr->nume,val);
    expr->index=index;
    return expr;
}
int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
}
