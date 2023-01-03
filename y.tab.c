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

#line 116 "y.tab.c"

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
    ID = 258,                      /* ID  */
    NR = 259,                      /* NR  */
    LIT = 260,                     /* LIT  */
    NEWTYPE = 261,                 /* NEWTYPE  */
    INT = 262,                     /* INT  */
    CHAR = 263,                    /* CHAR  */
    FLOAT = 264,                   /* FLOAT  */
    BOOL = 265,                    /* BOOL  */
    STRING = 266,                  /* STRING  */
    IF = 267,                      /* IF  */
    WHILE = 268,                   /* WHILE  */
    FOR = 269,                     /* FOR  */
    BGIN = 270,                    /* BGIN  */
    END = 271,                     /* END  */
    DEFINE = 272,                  /* DEFINE  */
    CONST = 273,                   /* CONST  */
    ASSIGN = 274,                  /* ASSIGN  */
    PLUS = 275,                    /* PLUS  */
    MINUS = 276,                   /* MINUS  */
    ADD = 277,                     /* ADD  */
    DEDUCT = 278,                  /* DEDUCT  */
    EQUAL = 279,                   /* EQUAL  */
    DIV = 280,                     /* DIV  */
    MOD = 281,                     /* MOD  */
    AND = 282,                     /* AND  */
    OR = 283,                      /* OR  */
    NOT = 284,                     /* NOT  */
    XOR = 285,                     /* XOR  */
    MAIN = 286,                    /* MAIN  */
    EVAL = 287,                    /* EVAL  */
    TYPEOF = 288                   /* TYPEOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define NR 259
#define LIT 260
#define NEWTYPE 261
#define INT 262
#define CHAR 263
#define FLOAT 264
#define BOOL 265
#define STRING 266
#define IF 267
#define WHILE 268
#define FOR 269
#define BGIN 270
#define END 271
#define DEFINE 272
#define CONST 273
#define ASSIGN 274
#define PLUS 275
#define MINUS 276
#define ADD 277
#define DEDUCT 278
#define EQUAL 279
#define DIV 280
#define MOD 281
#define AND 282
#define OR 283
#define NOT 284
#define XOR 285
#define MAIN 286
#define EVAL 287
#define TYPEOF 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NR = 4,                         /* NR  */
  YYSYMBOL_LIT = 5,                        /* LIT  */
  YYSYMBOL_NEWTYPE = 6,                    /* NEWTYPE  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_STRING = 11,                    /* STRING  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_BGIN = 15,                      /* BGIN  */
  YYSYMBOL_END = 16,                       /* END  */
  YYSYMBOL_DEFINE = 17,                    /* DEFINE  */
  YYSYMBOL_CONST = 18,                     /* CONST  */
  YYSYMBOL_ASSIGN = 19,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 20,                      /* PLUS  */
  YYSYMBOL_MINUS = 21,                     /* MINUS  */
  YYSYMBOL_ADD = 22,                       /* ADD  */
  YYSYMBOL_DEDUCT = 23,                    /* DEDUCT  */
  YYSYMBOL_EQUAL = 24,                     /* EQUAL  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_XOR = 30,                       /* XOR  */
  YYSYMBOL_MAIN = 31,                      /* MAIN  */
  YYSYMBOL_EVAL = 32,                      /* EVAL  */
  YYSYMBOL_TYPEOF = 33,                    /* TYPEOF  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_progr = 43,                     /* progr  */
  YYSYMBOL_var_globale = 44,               /* var_globale  */
  YYSYMBOL_definitii = 45,                 /* definitii  */
  YYSYMBOL_definitie = 46,                 /* definitie  */
  YYSYMBOL_declaratii = 47,                /* declaratii  */
  YYSYMBOL_declaratie = 48,                /* declaratie  */
  YYSYMBOL_TIP = 49,                       /* TIP  */
  YYSYMBOL_user_types = 50,                /* user_types  */
  YYSYMBOL_user_type = 51,                 /* user_type  */
  YYSYMBOL_functii = 52,                   /* functii  */
  YYSYMBOL_functie = 53,                   /* functie  */
  YYSYMBOL_lista_param = 54,               /* lista_param  */
  YYSYMBOL_param = 55,                     /* param  */
  YYSYMBOL_list = 56,                      /* list  */
  YYSYMBOL_VAR = 57,                       /* VAR  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_NEWVAL = 59,                    /* NEWVAL  */
  YYSYMBOL_op_list = 60,                   /* op_list  */
  YYSYMBOL_operation = 61,                 /* operation  */
  YYSYMBOL_OP = 62,                        /* OP  */
  YYSYMBOL_lista_cond = 63,                /* lista_cond  */
  YYSYMBOL_cond = 64,                      /* cond  */
  YYSYMBOL_OP_C = 65,                      /* OP_C  */
  YYSYMBOL_lista_nr = 66,                  /* lista_nr  */
  YYSYMBOL_lista_lit = 67,                 /* lista_lit  */
  YYSYMBOL_bloc = 68                       /* bloc  */
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
#define YYLAST   357

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  239

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      39,    40,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    56,    64,    72,    80,    88,    96,   104,
     113,   114,   115,   117,   118,   120,   121,   123,   124,   126,
     130,   137,   144,   151,   158,   165,   172,   179,   186,   194,
     195,   196,   197,   198,   200,   201,   203,   205,   206,   208,
     214,   215,   218,   219,   220,   221,   222,   224,   225,   227,
     228,   230,   231,   232,   239,   246,   253,   254,   255,   256,
     257,   258,   259,   260,   265,   266,   267,   268,   270,   271,
     272,   274,   275,   277,   278,   279,   281,   282,   283,   284,
     286,   287,   289,   290,   291,   293,   294,   295,   296,   297,
     299,   300,   302,   303,   305
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NR", "LIT",
  "NEWTYPE", "INT", "CHAR", "FLOAT", "BOOL", "STRING", "IF", "WHILE",
  "FOR", "BGIN", "END", "DEFINE", "CONST", "ASSIGN", "PLUS", "MINUS",
  "ADD", "DEDUCT", "EQUAL", "DIV", "MOD", "AND", "OR", "NOT", "XOR",
  "MAIN", "EVAL", "TYPEOF", "';'", "'['", "']'", "'{'", "'}'", "'('",
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

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     230,    17,  -166,    36,  -166,  -166,    39,    48,   273,    54,
      80,    57,   242,  -166,   247,    53,    79,    30,  -166,    57,
      60,  -166,    63,    13,    87,   100,   121,   139,   165,   202,
    -166,  -166,  -166,   172,    30,    57,  -166,  -166,   247,   176,
     160,  -166,    93,  -166,  -166,    30,   166,  -166,  -166,   247,
     178,   171,   174,  -166,  -166,   184,   194,   229,    27,   224,
     232,   237,   252,   265,   190,   271,   272,   266,  -166,    30,
    -166,   129,  -166,   295,    21,   259,  -166,  -166,   180,  -166,
     288,   303,   274,   275,   277,   306,   307,    19,    19,   202,
      34,   293,  -166,   280,    50,  -166,  -166,   110,  -166,  -166,
    -166,   279,   297,   278,   314,   119,  -166,  -166,   281,  -166,
     -23,   300,   303,   301,  -166,   285,   287,   197,    19,   197,
     283,  -166,   284,   291,   101,    56,   114,   286,  -166,   289,
     290,   292,  -166,   253,    56,   253,  -166,  -166,  -166,  -166,
     294,   324,   223,   313,   259,   303,  -166,   328,   298,   154,
     302,  -166,  -166,  -166,  -166,  -166,  -166,   331,   296,   169,
     133,   149,    19,  -166,  -166,  -166,  -166,   304,   331,   305,
     308,   181,   309,   310,   312,   315,   311,   333,  -166,  -166,
     259,   228,   202,  -166,   179,  -166,   303,  -166,   333,  -166,
     197,  -166,  -166,   202,  -166,   202,  -166,   316,  -166,  -166,
     240,  -166,  -166,  -166,  -166,  -166,  -166,  -166,   240,  -166,
     192,   260,  -166,  -166,   196,  -166,   234,   254,   299,    78,
     105,   202,  -166,  -166,   336,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,   317,  -166,   164,   202,  -166,   117,  -166
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    29,     0,    30,    33,     0,     0,     0,     0,
       0,     0,    11,    13,    12,     0,     0,     0,    34,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    31,    32,     0,     0,     0,     8,    14,    10,     0,
       0,    17,    19,    35,     6,     0,     0,     7,    37,     0,
       0,     0,     0,    15,    16,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       5,    19,    18,     0,     0,     0,     3,    38,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,    69,    70,     0,    47,     2,
      20,     0,     0,     0,     0,     0,    40,    36,     0,    92,
       0,     0,     0,     0,    53,     0,    49,     0,     0,     0,
       0,    80,     0,     0,     0,     0,     0,     0,    71,     0,
       0,     0,    48,     0,     0,     0,    54,    52,    51,    25,
       0,     0,    42,     0,     0,     0,    24,     0,     0,     0,
       0,    50,    88,    85,    86,    87,    89,     0,     0,     0,
       0,     0,     0,    76,    77,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    68,
       0,     0,     0,    41,     0,    93,     0,    28,     0,    84,
       0,    83,    82,     0,    57,     0,    61,     0,    63,    75,
       0,    62,    74,    73,    64,    66,    67,    65,    55,    90,
       0,     0,    44,    43,     0,    23,     0,     0,     0,     0,
       0,     0,    72,    22,     0,    46,    39,    27,    26,    81,
      56,    60,     0,    91,     0,     0,    59,     0,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,  -166,   329,     1,    -7,     0,    90,     7,
     337,   134,   167,   208,  -165,   -85,   -63,   211,   -78,  -101,
     -33,   -84,   136,  -105,   168,  -102,    10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,    15,    39,    17,    18,
      19,    20,   105,   106,    64,    65,    66,    97,   127,   128,
     168,   120,   121,   157,   210,   110,    21
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    93,   119,   119,   122,   126,   131,    40,    28,   135,
     149,    33,   138,    38,   159,   146,   136,   214,   147,    33,
      22,    36,   116,   117,    43,   101,   123,    44,   219,    47,
     220,    40,    50,   119,   158,    33,     1,   116,   124,    23,
     135,    43,    24,   184,    68,    70,    85,   169,    51,   135,
      78,    25,    43,   116,   133,    76,   176,   102,   118,   116,
     133,     9,    86,     1,     2,    31,     4,     5,    32,    29,
     237,    40,   189,   125,   192,   104,    43,   119,   197,    99,
      30,    58,    42,   199,   216,   218,   203,    41,     9,   134,
      59,    60,    61,   171,    48,   125,   213,   194,   196,   222,
      49,    34,   171,   141,    53,    54,    52,   222,    58,    45,
      62,    63,    73,   116,   137,   135,   230,    59,    60,    61,
      58,   163,   164,   135,    55,    69,   165,   166,    74,    59,
      60,    61,    75,   119,   163,   164,    58,    62,    63,   165,
     166,   167,    56,   231,   104,    59,    60,    61,    73,    62,
      63,    93,    58,    46,   170,   238,    93,    93,   232,   143,
     144,    59,    60,    61,    74,    62,    63,    58,    57,    46,
     193,   236,   116,   191,    93,    67,    59,    60,    61,    71,
     104,    62,    63,    79,   116,   202,   195,     2,     3,     4,
       5,     6,   187,    58,    72,   147,    62,    63,     8,    58,
      77,   235,    59,    60,    61,    58,    92,    80,    59,    60,
      61,    81,   226,    83,    59,    60,    61,   215,   107,    82,
     147,   152,    62,    63,   153,   154,   155,   156,    62,    63,
     223,   116,   212,   224,    62,    63,     1,     2,     3,     4,
       5,     6,   179,   116,   133,    95,    96,     7,     8,     2,
       3,     4,     5,     6,     2,     3,     4,     5,     6,     7,
       8,     9,   180,    87,    84,     8,     2,    31,     4,     5,
      32,    88,   227,   163,   164,   147,    89,   103,   165,   166,
       2,    26,     4,     5,    27,     2,    31,     4,     5,    32,
      94,    90,   228,    95,    96,   224,   116,   129,   130,   100,
     225,   144,   116,   117,    91,    75,    98,   108,   109,   114,
     111,   115,   112,   113,   132,   139,   140,   142,   145,   148,
     150,   151,    86,   160,   161,   162,   172,   178,   182,   173,
     174,   177,   175,   185,   116,   186,   190,   209,   198,   188,
     233,    37,   201,   204,   205,   200,   206,   211,    35,   207,
     221,   208,   183,   181,   229,     0,   217,   234
};

static const yytype_int16 yycheck[] =
{
       0,    64,    87,    88,    88,    90,    91,    14,     8,    94,
     112,    11,    97,    12,   119,    38,    94,   182,    41,    19,
       3,    11,     3,     4,    17,     4,    89,    17,   193,    19,
     195,    38,    19,   118,   118,    35,     6,     3,     4,     3,
     125,    34,     3,   145,    34,    35,    19,   125,    35,   134,
      49,     3,    45,     3,     4,    45,   134,    36,    39,     3,
       4,    31,    35,     6,     7,     8,     9,    10,    11,    15,
     235,    78,   157,    39,   159,    75,    69,   162,   162,    69,
       0,     3,     3,   168,   186,   190,   171,    34,    31,    39,
      12,    13,    14,   126,    34,    39,   181,   160,   161,   200,
      37,    11,   135,   103,     4,     5,    19,   208,     3,    19,
      32,    33,    19,     3,     4,   200,    38,    12,    13,    14,
       3,    20,    21,   208,     3,    35,    25,    26,    35,    12,
      13,    14,    39,   218,    20,    21,     3,    32,    33,    25,
      26,    40,     3,    38,   144,    12,    13,    14,    19,    32,
      33,   214,     3,    19,    40,    38,   219,   220,   221,    40,
      41,    12,    13,    14,    35,    32,    33,     3,     3,    35,
      37,   234,     3,     4,   237,     3,    12,    13,    14,     3,
     180,    32,    33,     5,     3,     4,    37,     7,     8,     9,
      10,    11,    38,     3,    34,    41,    32,    33,    18,     3,
      34,    37,    12,    13,    14,     3,    16,    36,    12,    13,
      14,    37,    16,    19,    12,    13,    14,    38,    38,    35,
      41,    24,    32,    33,    27,    28,    29,    30,    32,    33,
      38,     3,     4,    41,    32,    33,     6,     7,     8,     9,
      10,    11,    19,     3,     4,    22,    23,    17,    18,     7,
       8,     9,    10,    11,     7,     8,     9,    10,    11,    17,
      18,    31,    39,    39,    35,    18,     7,     8,     9,    10,
      11,    39,    38,    20,    21,    41,    39,    18,    25,    26,
       7,     8,     9,    10,    11,     7,     8,     9,    10,    11,
      19,    39,    38,    22,    23,    41,     3,     4,     5,     4,
      40,    41,     3,     4,    39,    39,    34,    19,     5,     3,
      36,     4,    37,    36,    34,    36,    19,     3,    37,    19,
      19,    36,    35,    40,    40,    34,    40,     3,    15,    40,
      40,    37,    40,     5,     3,    37,    40,     4,    34,    37,
       4,    12,    34,    34,    34,    40,    34,   180,    11,    34,
      34,    40,   144,   142,   218,    -1,   188,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    11,    17,    18,    31,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    68,     3,     3,     3,     3,     8,    11,    49,    15,
       0,     8,    11,    49,    50,    52,    68,    46,    47,    49,
      48,    34,     3,    51,    68,    50,    53,    68,    34,    37,
      19,    35,    19,     4,     5,     3,     3,     3,     3,    12,
      13,    14,    32,    33,    56,    57,    58,     3,    68,    50,
      68,     3,    34,    19,    35,    39,    68,    34,    47,     5,
      36,    37,    35,    19,    35,    19,    35,    39,    39,    39,
      39,    39,    16,    58,    19,    22,    23,    59,    34,    68,
       4,     4,    36,    18,    49,    54,    55,    38,    19,     5,
      67,    36,    37,    36,     3,     4,     3,     4,    39,    57,
      63,    64,    63,    58,     4,    39,    57,    60,    61,     4,
       5,    57,    34,     4,    39,    57,    60,     4,    57,    36,
      19,    49,     3,    40,    41,    37,    38,    41,    19,    67,
      19,    36,    24,    27,    28,    29,    30,    65,    63,    65,
      40,    40,    34,    20,    21,    25,    26,    40,    62,    60,
      40,    62,    40,    40,    40,    40,    60,    37,     3,    19,
      39,    59,    15,    55,    67,     5,    37,    38,    37,    57,
      40,     4,    57,    37,    58,    37,    58,    63,    34,    57,
      40,    34,     4,    57,    34,    34,    34,    34,    40,     4,
      66,    54,     4,    57,    56,    38,    67,    66,    65,    56,
      56,    34,    61,    38,    41,    40,    16,    38,    38,    64,
      38,    38,    58,     4,    40,    37,    58,    56,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      44,    44,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    49,    49,    49,    50,    50,    51,    52,    52,    53,
      54,    54,    55,    55,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    60,    60,    61,    61,    61,    62,    62,    62,    62,
      63,    63,    64,    64,    64,    65,    65,    65,    65,    65,
      66,    66,    67,    67,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     3,     2,     2,     2,     1,
       2,     1,     1,     1,     2,     3,     3,     2,     3,     2,
       4,     4,     8,     8,     6,     5,     9,     9,     7,     1,
       1,     1,     1,     1,     1,     2,     5,     2,     3,     8,
       1,     3,     2,     4,     4,     3,     5,     2,     3,     1,
       4,     3,     3,     3,     3,     5,     7,     5,    11,     9,
       7,     5,     5,     5,     5,     5,     5,     5,     1,     1,
       1,     1,     4,     3,     3,     3,     1,     1,     1,     1,
       1,     5,     3,     3,     3,     1,     1,     1,     1,     1,
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
#line 48 "proiect.y"
                                             {printf("Sintaxă corectă\n");
                                             if (corect) {
                                             printf("Corect semantic\n");
                                             printTable();
                                             }
                                             else
                                             printf("Incorect semantic\n");
                                             }
#line 1451 "y.tab.c"
    break;

  case 3: /* progr: functii user_types bloc  */
#line 56 "proiect.y"
                                {printf("Sintaxă corectă\n");
                              if (corect) {
                              printf("Corect semantic\n");
                              printTable();
                              }
                              else
                              printf("Incorect semantic\n");
                              }
#line 1464 "y.tab.c"
    break;

  case 4: /* progr: var_globale user_types bloc  */
#line 64 "proiect.y"
                                    {printf("Sintaxă corectă\n");
                                   if (corect) {
                                   printf("Corect semantic\n");
                                   printTable();
                                   }
                                   else
                                   printf("Incorect semantic\n");
                                   }
#line 1477 "y.tab.c"
    break;

  case 5: /* progr: var_globale functii bloc  */
#line 72 "proiect.y"
                                 {printf("Sintaxă corectă\n");
                                   if (corect) {
                                   printf("Corect semantic\n");
                                   printTable();
                                   }
                                   else
                                   printf("Incorect semantic\n");
                                   }
#line 1490 "y.tab.c"
    break;

  case 6: /* progr: user_types bloc  */
#line 80 "proiect.y"
                        {printf("Sintaxă corectă\n");
                         if (corect) {
                         printf("Corect semantic\n");
                         printTable();
                         }
                         else
                         printf("Incorect semantic\n");
                         }
#line 1503 "y.tab.c"
    break;

  case 7: /* progr: functii bloc  */
#line 88 "proiect.y"
                     {printf("Sintaxă corectă\n");
                    if (corect) {
                    printf("Corect semantic\n");
                    printTable();
                    }
                    else
                    printf("Incorect semantic\n");
                    }
#line 1516 "y.tab.c"
    break;

  case 8: /* progr: var_globale bloc  */
#line 96 "proiect.y"
                         {printf("Sintaxă corectă\n");
                         if (corect) {
                         printf("Corect semantic\n");
                         printTable();
                         }
                         else
                         printf("Incorect semantic\n");
                         }
#line 1529 "y.tab.c"
    break;

  case 9: /* progr: bloc  */
#line 104 "proiect.y"
             {printf("Sintaxă corectă\n");
              if (corect) {
               printf("Corect semantic\n");
               printTable();
               }
               else
               printf("Incorect semantic\n");
               }
#line 1542 "y.tab.c"
    break;

  case 19: /* declaratie: TIP ID  */
#line 126 "proiect.y"
                    {
                    structDefinita(yyvsp[-1]->nume);
                    insertVarTable(yyvsp[0], yyvsp[-1]);
                    }
#line 1551 "y.tab.c"
    break;

  case 20: /* declaratie: TIP ID ASSIGN NR  */
#line 130 "proiect.y"
                              {
                              structDefinita(yyvsp[-3]->nume);
                              struct tip_t tip_expr;
                              tipExpr(yyvsp[0], &tip_expr);
                              tipuriEgale(&tip_expr, yyvsp[-3]);
                              insertVarTable(yyvsp[-2], yyvsp[-3]);
                              }
#line 1563 "y.tab.c"
    break;

  case 21: /* declaratie: CHAR ID ASSIGN LIT  */
#line 137 "proiect.y"
                               {
                              structDefinita(yyvsp[-3]->nume);
                              struct tip_t tip_expr;
                              tipExpr(yyvsp[0], &tip_expr);
                              tipuriEgale(&tip_expr,"char");
                              insertVarTable(yyvsp[-2],"char");
                              }
#line 1575 "y.tab.c"
    break;

  case 22: /* declaratie: TIP ID '[' ']' ASSIGN '{' lista_nr '}'  */
#line 144 "proiect.y"
                                                   {
                              structDefinita(yyvsp[-7]->nume);
                              struct tip_t tip_expr;
                              tipExpr(yyvsp[-1], &tip_expr);
                              tipuriEgale(&tip_expr, yyvsp[-7]);
                              insertVarTable(yyvsp[-6], yyvsp[-7]);
                              }
#line 1587 "y.tab.c"
    break;

  case 23: /* declaratie: CHAR ID '[' ']' ASSIGN '{' lista_lit '}'  */
#line 151 "proiect.y"
                                                     {
                              structDefinita(yyvsp[-7]->nume);
                              struct tip_t tip_expr;
                              tipExpr(yyvsp[-1], &tip_expr);
                              tipuriEgale(&tip_expr, "char");
                              insertVarTable(yyvsp[-6], "char");
                              }
#line 1599 "y.tab.c"
    break;

  case 24: /* declaratie: STRING ID ASSIGN '{' lista_lit '}'  */
#line 158 "proiect.y"
                                               {
                              structDefinita(yyvsp[-5]->nume);
                              struct tip_t tip_expr;
                              tipExpr(yyvsp[-1], &tip_expr);
                              tipuriEgale(&tip_expr, "string");
                              insertVarTable(yyvsp[-4], "string");
                              }
#line 1611 "y.tab.c"
    break;

  case 25: /* declaratie: TIP ID '[' NR ']'  */
#line 165 "proiect.y"
                              {
                              structDefinita(yyvsp[-4]->nume);
                              struct tip_t tip_expr;
                              tipExpr(yyvsp[-1], &tip_expr);
                              tipuriEgale(&tip_expr, yyvsp[-4]);
                              insertVarTable(yyvsp[-3], yyvsp[-4]);
                              }
#line 1623 "y.tab.c"
    break;

  case 26: /* declaratie: CONST TIP ID '[' ']' ASSIGN '{' lista_nr '}'  */
#line 172 "proiect.y"
                                                         {
                              structDefinita(yyvsp[-8]->nume);
                              struct tip_t tip_expr;
                              tipExpr(yyvsp[-5], &tip_expr);
                              tipuriEgale(&tip_expr, yyvsp[-8]);
                              insertVarTable(yyvsp[-7], yyvsp[-8]);
                              }
#line 1635 "y.tab.c"
    break;

  case 27: /* declaratie: CONST CHAR ID '[' ']' ASSIGN '{' lista_lit '}'  */
#line 179 "proiect.y"
                                                           {
                              structDefinita(yyvsp[-8]->nume);
                              struct tip_t tip_expr;
                              tipExpr(yyvsp[-1], &tip_expr);
                              tipuriEgale(&tip_expr, "char");
                              insertVarTable(yyvsp[-6], "char");
                              }
#line 1647 "y.tab.c"
    break;

  case 28: /* declaratie: CONST STRING ID ASSIGN '{' lista_lit '}'  */
#line 186 "proiect.y"
                                                     {
                              structDefinita(yyvsp[-6]->nume);
                              struct tip_t tip_expr;
                              tipExpr(yyvsp[-1], &tip_expr);
                              tipuriEgale(&tip_expr, "string");
                              insertVarTable(yyvsp[-4], "string");
                              }
#line 1659 "y.tab.c"
    break;

  case 39: /* functie: TIP ID '(' lista_param ')' BGIN list END  */
#line 209 "proiect.y"
                {
                    insertFuncTable(yyvsp[-5], yyvsp[-6], yyvsp[-3]);
                    functie_curenta = yyvsp[-5];
                }
#line 1668 "y.tab.c"
    break;

  case 53: /* statement: ID ASSIGN ID  */
#line 232 "proiect.y"
                         {
                         varDefinita(yyvsp[-2]);
                         struct tip_t tip_expr;
                         tipExpr(yyvsp[0], &tip_expr);
                         struct tip_t *tip_var = tipVar(yyvsp[-2]);
                         tipuriEgale(&tip_expr, tip_var);
                         }
#line 1680 "y.tab.c"
    break;

  case 54: /* statement: VAR ASSIGN op_list  */
#line 239 "proiect.y"
                              {
                              varDefinita(yyvsp[-2]);
                              struct tip_t tip_expr;
                              tipExpr(yyvsp[0], &tip_expr);
                              struct tip_t *tip_var = tipVar(yyvsp[-2]);
                              tipuriEgale(&tip_expr, tip_var);
                              }
#line 1692 "y.tab.c"
    break;

  case 55: /* statement: VAR ASSIGN '(' op_list ')'  */
#line 246 "proiect.y"
                                      {
                                        varDefinita(yyvsp[-4]);
                                        struct tip_t tip_expr;
                                        tipExpr(yyvsp[-2], &tip_expr);
                                        struct tip_t *tip_var = tipVar(yyvsp[-4]);
                                        tipuriEgale(&tip_expr, tip_var);
                                        }
#line 1704 "y.tab.c"
    break;

  case 63: /* statement: EVAL '(' NR ')' ';'  */
#line 260 "proiect.y"
                                {if (corect){
                                             if((int)yyvsp[-2]->val == yyvsp[-2]->val){
                                                  printf("Rezultatul expresiei din eval este %d\n", (int)yyvsp[-2]->val);
                                             }
                                             else {printf("Valorile nu sunt de tip int\n");}}}
#line 1714 "y.tab.c"
    break;


#line 1718 "y.tab.c"

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

#line 309 "proiect.y"

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
