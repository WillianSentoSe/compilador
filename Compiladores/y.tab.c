/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatica.y" /* yacc.c:337  */

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

#define YYSTYPE atributos
#define DISPLAY_COLOR false

using namespace std;


struct atributos {
	string label;
	string declaracao;
	string traducao;
	int tipo;
};

struct simbolo {
	int tipo;
	int escopo;
	int classe;
	bool ativo;
	string label;
};

int countTMP = 0;
int countVAR = 0;
int countLBL = 0;
int linha = 1;
unordered_map<string, simbolo> tabela_simbolos;

int yylex(void);
void yyerror(string);
string nextTMP();
string nextVAR();
string nextLBL();
string typeName(int, bool = false);
bool checkTypes(int, int);
void checkLabel(string);
int convertType(int, int, int*);
int neoConvertType (atributos*, atributos*, atributos*, int forceType = 0);

string cmd(string, string = "");
string dcl(int, string);
string cst (string, int, string);

void setTipo(string, int);
int getTipo(string);
int getEscopo(string);
int getClasse(string);
bool isAtivo(string);
string getLabel(string);
bool isDeclared(string);

void printHash();


#line 130 "y.tab.c" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_LITERAL = 258,
    TK_ID = 259,
    TK_MAIN = 260,
    TK_VAR = 261,
    TK_TIPO = 262,
    TK_IF = 263,
    TK_ELSE = 264,
    TK_OP_IGUALDADE = 265,
    TK_OP_DESIGUALDADE = 266,
    TK_OP_MAIORIGUAL = 267,
    TK_OP_MENORIGUAL = 268,
    TK_OP_NOT = 269,
    TK_OP_LOGICAL_AND = 270,
    TK_OP_AND = 271,
    TK_OP_LOGICAL_OR = 272,
    TK_OP_XOR = 273,
    TK_OP_IOR = 274,
    TK_OP_ADD = 275,
    TK_OP_MUL = 276,
    TK_TIPO_INDEFINIDO = 277,
    TK_TIPO_INT = 278,
    TK_TIPO_FLOAT = 279,
    TK_TIPO_CHAR = 280,
    TK_TIPO_BOOL = 281,
    TK_TIPO_STRING = 282,
    TK_CLASSE_VARIAVEL = 283,
    TK_CLASSE_FUNCAO = 284,
    TK_FIM = 285,
    TK_ERROR = 286
  };
#endif
/* Tokens.  */
#define TK_LITERAL 258
#define TK_ID 259
#define TK_MAIN 260
#define TK_VAR 261
#define TK_TIPO 262
#define TK_IF 263
#define TK_ELSE 264
#define TK_OP_IGUALDADE 265
#define TK_OP_DESIGUALDADE 266
#define TK_OP_MAIORIGUAL 267
#define TK_OP_MENORIGUAL 268
#define TK_OP_NOT 269
#define TK_OP_LOGICAL_AND 270
#define TK_OP_AND 271
#define TK_OP_LOGICAL_OR 272
#define TK_OP_XOR 273
#define TK_OP_IOR 274
#define TK_OP_ADD 275
#define TK_OP_MUL 276
#define TK_TIPO_INDEFINIDO 277
#define TK_TIPO_INT 278
#define TK_TIPO_FLOAT 279
#define TK_TIPO_CHAR 280
#define TK_TIPO_BOOL 281
#define TK_TIPO_STRING 282
#define TK_CLASSE_VARIAVEL 283
#define TK_CLASSE_FUNCAO 284
#define TK_FIM 285
#define TK_ERROR 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   54

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  71

#define YYUNDEFTOK  2
#define YYMAXUTOK   286

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,    35,    33,    42,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      43,    32,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    85,    92,    98,   103,   104,   105,   108,
     119,   133,   140,   154,   155,   170,   171,   179,   180,   188,
     189,   197,   198,   206,   207,   215,   216,   224,   227,   261,
     268,   273,   280,   291,   308,   326,   350,   354,   358,   359
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_LITERAL", "TK_ID", "TK_MAIN",
  "TK_VAR", "TK_TIPO", "TK_IF", "TK_ELSE", "TK_OP_IGUALDADE",
  "TK_OP_DESIGUALDADE", "TK_OP_MAIORIGUAL", "TK_OP_MENORIGUAL",
  "TK_OP_NOT", "TK_OP_LOGICAL_AND", "TK_OP_AND", "TK_OP_LOGICAL_OR",
  "TK_OP_XOR", "TK_OP_IOR", "TK_OP_ADD", "TK_OP_MUL", "TK_TIPO_INDEFINIDO",
  "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_CHAR", "TK_TIPO_BOOL",
  "TK_TIPO_STRING", "TK_CLASSE_VARIAVEL", "TK_CLASSE_FUNCAO", "TK_FIM",
  "TK_ERROR", "'='", "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'",
  "'}'", "';'", "','", "'<'", "'>'", "$accept", "S", "BLOCO", "COMANDOS",
  "COMANDO", "EXP_SIMPLES", "EXP_NOT", "EXP_ARITMETICA_MUL",
  "EXP_ARITMETICA_ADD", "EXP_RELACIONAL", "EXP_IGUALDADE",
  "EXP_LOGICAL_AND", "EXP_LOGICAL_OR", "EXPRESSAO", "ATRIBUICAO",
  "CMD_DECLARACOES", "LIST_DECLARACOES", "DECLARACAO", "CMD_IF",
  "OP_RELACIONAL", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    61,    43,    45,    42,    47,    40,    41,   123,
     125,    59,    44,    60,    62
};
# endif

#define YYPACT_NINF -52

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,     4,    10,   -23,   -52,   -22,   -19,     9,   -52,   -11,
      19,   -13,   -14,     9,   -12,   -10,   -52,    -3,    -5,   -52,
      -9,    -3,   -52,   -52,   -52,   -52,   -52,   -52,    -2,    -3,
      -3,   -52,   -52,     7,    12,    -7,    20,    23,    22,   -52,
      -3,    19,     2,    -3,   -52,     3,    -3,    -3,   -52,   -52,
     -52,   -52,    -3,    -3,    -3,    -3,   -52,   -52,   -19,     5,
     -52,   -52,     7,    12,    -7,    20,    23,    33,   -52,   -19,
     -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     2,     0,
       0,     0,     0,     5,     0,     0,     8,     0,    32,    29,
      31,     0,     3,     4,     6,     7,     9,    10,     0,     0,
       0,    13,    15,    17,    19,    21,    23,    25,    27,    28,
       0,     0,     0,     0,    14,     0,     0,     0,    38,    39,
      36,    37,     0,     0,     0,     0,    33,    30,     0,     0,
      11,    16,    18,    20,    22,    24,    26,    34,    12,     0,
      35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -51,    31,   -52,   -52,   -27,    -1,    -4,    -8,
       0,    -6,   -52,   -18,   -52,   -52,     6,   -52,   -52,   -52
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     8,    12,    13,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    14,    15,    19,    20,    16,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    27,    44,    42,    28,    48,    49,    67,     1,     3,
       4,    29,    45,     9,     5,    10,     6,    11,    70,    61,
       7,    17,    56,    18,    21,    59,    22,    40,    46,    24,
      53,    25,    47,    41,    30,    43,    50,    51,    54,    55,
      58,    60,    69,    68,    23,    64,    62,    57,    63,    66,
       0,     0,     0,     0,    65
};

static const yytype_int8 yycheck[] =
{
       3,     4,    29,    21,     7,    12,    13,    58,     7,     5,
       0,    14,    30,     4,    37,     6,    38,     8,    69,    46,
      39,    32,    40,     4,    37,    43,    40,    32,    21,    41,
      10,    41,    20,    42,    37,    37,    43,    44,    15,    17,
      38,    38,     9,    38,    13,    53,    47,    41,    52,    55,
      -1,    -1,    -1,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    46,     5,     0,    37,    38,    39,    47,     4,
       6,     8,    48,    49,    59,    60,    63,    32,     4,    61,
      62,    37,    40,    48,    41,    41,     3,     4,     7,    14,
      37,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      32,    42,    58,    37,    51,    58,    21,    20,    12,    13,
      43,    44,    64,    10,    15,    17,    58,    61,    38,    58,
      38,    51,    52,    53,    54,    55,    56,    47,    38,     9,
      47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    48,    48,    49,    49,    49,    50,
      50,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    59,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     2,     2,     1,     1,
       1,     3,     4,     1,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     2,
       3,     1,     1,     3,     5,     7,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 77 "sintatica.y" /* yacc.c:1652  */
    {
						cout << "\n/*Compilador Ç*/\n\n";
						cout << "\n#include <stdio.h>\n\n";
						cout << "#define true 1\n#define false 0\n\n";
						cout << "int main(void)\n{\n" << yyvsp[0].declaracao + "\n" + yyvsp[0].traducao << "\n\treturn 0;\n}\n"; 
					}
#line 1375 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 86 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = yyvsp[-1].traducao;
						yyval.declaracao = yyvsp[-1].declaracao;
					}
#line 1384 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 93 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[-1].declaracao + yyvsp[0].declaracao;
						yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
					}
#line 1393 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 98 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = "";
					}
#line 1401 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 109 "sintatica.y" /* yacc.c:1652  */
    {	
						// EXPERIMENTAL (ATRIBUICAO DIRETA)
						// $$.label = $1.traducao;
						// $$.traducao = "";

						yyval.label = nextTMP();
						yyval.declaracao = dcl(yyvsp[0].tipo, yyval.label);
						yyval.traducao = cmd(yyval.label + " = " + yyvsp[0].traducao);
						yyval.tipo = yyvsp[0].tipo;
					}
#line 1416 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 120 "sintatica.y" /* yacc.c:1652  */
    {
						checkLabel(yyvsp[0].label);
						yyval.tipo = getTipo(yyvsp[0].label);

						if (yyval.tipo == TK_TIPO_INDEFINIDO)
						{
							yyerror("A variável '" + yyvsp[0].label + "' possui valor indefinido.");
						}

						yyval.label = getLabel(yyvsp[0].label);
						yyval.declaracao = "";
						yyval.traducao = "";
					}
#line 1434 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 134 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = yyvsp[-1].label;
						yyval.declaracao = yyvsp[-1].declaracao;
						yyval.traducao = yyvsp[-1].traducao;
						yyval.tipo = yyvsp[-1].tipo;
					}
#line 1445 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 141 "sintatica.y" /* yacc.c:1652  */
    {
						int out;

						convertType(yyvsp[-3].tipo, yyvsp[-1].tipo, &out);
						yyval.tipo = yyvsp[-3].tipo;

						string newLabel = nextTMP();
						yyval.declaracao = yyvsp[-1].declaracao + dcl(yyvsp[-3].tipo, newLabel);
						yyval.traducao = yyvsp[-1].traducao + cst(newLabel, yyvsp[-3].tipo, yyvsp[-1].label);
						yyval.label = newLabel;
					}
#line 1461 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 156 "sintatica.y" /* yacc.c:1652  */
    {

						if (yyvsp[0].tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName(yyvsp[0].tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						yyval.label = nextTMP();
						yyval.tipo = TK_TIPO_BOOL;
						yyval.declaracao = yyvsp[0].declaracao + dcl(yyval.tipo, yyval.label);
						yyval.traducao = yyvsp[0].traducao + cmd(yyval.label + " = !" + yyvsp[0].label);
						//$$.traducao = $2.traducao + "\t" + declaracao + $$.label + " = !" + $2.label + ";\n";
					}
#line 1479 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 172 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						neoConvertType(&yyval, &yyvsp[-2], &yyvsp[0]);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd (yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
					}
#line 1489 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 181 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						neoConvertType(&yyval, &yyvsp[-2], &yyvsp[0]);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd (yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
					}
#line 1499 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 190 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						neoConvertType(&yyval, &yyvsp[-2], &yyvsp[0], TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
					}
#line 1509 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 199 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						neoConvertType(&yyval, &yyvsp[-2], &yyvsp[0], TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
					}
#line 1519 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 208 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						neoConvertType(&yyval, &yyvsp[-2], &yyvsp[0], TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
					}
#line 1529 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 217 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						neoConvertType(&yyval, &yyvsp[-2], &yyvsp[0], TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
					}
#line 1539 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 228 "sintatica.y" /* yacc.c:1652  */
    {
						if (!isDeclared(yyvsp[-2].label))
						{
							yyerror("Variável '" + yyvsp[-2].label + "' nao declarada.");
						}

						yyvsp[-2].tipo = getTipo(yyvsp[-2].label);
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;

						if (yyvsp[-2].tipo == TK_TIPO_INDEFINIDO)
						{
							yyvsp[-2].tipo = yyvsp[0].tipo;
							setTipo(yyvsp[-2].label, yyvsp[-2].tipo);
							yyval.declaracao += dcl(yyvsp[-2].tipo, getLabel(yyvsp[-2].label));
						}

						int out;
						int newType = convertType(yyvsp[-2].tipo, yyvsp[0].tipo, &out);
						checkTypes(yyvsp[-2].tipo, newType);

						if (out == 2){
							string newLabel = nextTMP();
							yyval.declaracao += dcl(yyvsp[-2].tipo, newLabel);
							yyval.traducao += cst(newLabel, yyvsp[-2].tipo, yyvsp[0].label);
							yyvsp[0].label = newLabel;
						}

						yyvsp[-2].label = getLabel(yyvsp[-2].label);
						yyval.traducao += cmd(yyvsp[-2].label + " = " + yyvsp[0].label);
					}
#line 1575 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 262 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;
					}
#line 1584 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 269 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[-2].declaracao + yyvsp[0].declaracao;
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
					}
#line 1593 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 274 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;
					}
#line 1602 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 281 "sintatica.y" /* yacc.c:1652  */
    {
						if (isDeclared(yyvsp[0].label))
							yyerror("Variável '" + yyvsp[0].label + "' já foi declarada.");

						string newLabel = nextVAR();
						tabela_simbolos[yyvsp[0].label] = {TK_TIPO_INDEFINIDO, -1, -1, true, newLabel};
						yyvsp[0].label = newLabel;

						//$$.traducao = "";
					}
#line 1617 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 292 "sintatica.y" /* yacc.c:1652  */
    {
						if (isDeclared(yyvsp[-2].label))
							yyerror("Variável '" + yyvsp[-2].label + "' já foi declarada.");

						yyvsp[-2].tipo = yyvsp[0].tipo;
						string declaracao = typeName(yyvsp[-2].tipo) + " " + yyvsp[-2].label + ";\n";

						string newLabel = nextVAR();
						tabela_simbolos[yyvsp[-2].label] = {yyvsp[-2].tipo, -1, -1, true, newLabel};
						yyvsp[-2].label = newLabel;

						yyval.declaracao = yyvsp[0].declaracao + dcl(yyvsp[-2].tipo, yyvsp[-2].label);
						yyval.traducao = yyvsp[0].traducao + cmd(yyvsp[-2].label + " = " + yyvsp[0].label);
					}
#line 1636 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 309 "sintatica.y" /* yacc.c:1652  */
    {
						if (yyvsp[-2].tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName(yyvsp[-3].tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						yyval.traducao = yyvsp[-2].traducao;
						yyval.declaracao = yyvsp[-2].declaracao;
						string newLabel = nextTMP();
						string labelGoto = nextLBL();
						yyval.declaracao += dcl(TK_TIPO_BOOL, newLabel);
						yyval.traducao += cmd(newLabel + " = !" + yyvsp[-2].label);
						yyval.traducao += cmd("if (" + newLabel + ") goto " + labelGoto);
						yyval.declaracao += yyvsp[0].declaracao;
						yyval.traducao += yyvsp[0].traducao;
						yyval.traducao += '\t' + labelGoto + ":\n";
					}
#line 1658 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 327 "sintatica.y" /* yacc.c:1652  */
    {
						if (yyvsp[-4].tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName(yyvsp[-5].tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						yyval.traducao = yyvsp[-4].traducao;
						yyval.declaracao = yyvsp[-4].declaracao;
						string newLabel = nextTMP();
						string labelGoto = nextLBL();
						yyval.declaracao += dcl(TK_TIPO_BOOL, newLabel);
						yyval.traducao += cmd(newLabel + " = !" + yyvsp[-4].label);
						yyval.traducao += cmd("if (" + newLabel + ") goto " + labelGoto);
						yyval.declaracao += yyvsp[-2].declaracao;
						yyval.traducao += yyvsp[-2].traducao;
						yyval.traducao += '\t' + labelGoto + ":\n";

						yyval.declaracao += yyvsp[0].declaracao;
						yyval.traducao += yyvsp[0].traducao;
					}
#line 1683 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 351 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = "<";
					}
#line 1691 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 355 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = ">";
					}
#line 1699 "y.tab.c" /* yacc.c:1652  */
    break;


#line 1703 "y.tab.c" /* yacc.c:1652  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 364 "sintatica.y" /* yacc.c:1918  */


#include "lex.yy.c"

						/*	TK_TIPO_INDEFINIDO	, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_TIPO_BOOL		*/
int tab_conversao[5][5] = 	{	
							{TK_TIPO_INDEFINIDO	, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_TIPO_BOOL		}, /* TK_TIPO_INDEFINIDO 	*/
							{TK_ERROR			, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_ERROR			}, /* TK_TIPO_INT 			*/
							{TK_ERROR			, TK_TIPO_FLOAT		, TK_TIPO_FLOAT		, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_FLOAT 		*/
							{TK_ERROR			, TK_TIPO_CHAR		, TK_ERROR			, TK_TIPO_CHAR		, TK_ERROR			}, /* TK_TIPO_CHAR 			*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_TIPO_BOOL		}, /* TK_TIPO_BOOL 			*/
							};

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << "\n [LINHA " << to_string(linha) << "] (!)\n";
	cout << " | " << MSG << "\n\n";
	exit (0);
}

string nextTMP()
{
	string tmp = "TMP" + to_string(countTMP++);

	if (DISPLAY_COLOR) 
		return "\033[1;35m" + tmp + "\033[0m";
	else 
		return tmp;
}

string nextVAR()
{
	string var = "VAR" + to_string(countVAR++);

	if (DISPLAY_COLOR) 
		return "\033[1;34m" + var + "\033[0m";
	else 
		return var;
}

string nextLBL()
{
	string lbl = "LBL" + to_string(countLBL++);

	if (DISPLAY_COLOR) 
		return "\033[1;33m" + lbl + "\033[0m";
	else 
		return lbl;
}

string typeName (int token, bool debug)
{
	string str;

	switch (token)
	{
		case TK_TIPO_INT: 		str = "int"; 						break;
		case TK_TIPO_FLOAT: 	str = "float"; 						break;
		case TK_TIPO_CHAR: 		str = "char"; 						break;
		case TK_TIPO_BOOL:		str = (debug)? "boolean" : "int";	break;
		default:				str = "undefined";					break;
	}

	return str;
}

bool checkTypes (int type1, int type2)
{
	if (type1 != TK_TIPO_INDEFINIDO && type2 != TK_TIPO_INDEFINIDO && type1 != type2)
	{
		yyerror("Conversão inválida entre (" + typeName(type1, true) + ") e (" + typeName(type2, true) +").");
	}

	return true;
}

int convertType (int type1, int type2, int *x)
{
	int typeIndex1 = type1 - TK_TIPO_INDEFINIDO;
	int typeIndex2 = type2 - TK_TIPO_INDEFINIDO;

	*x = 0;

	int newType = tab_conversao[typeIndex1][typeIndex2];

	if (newType == TK_ERROR)
	{
		yyerror("Conversão inválida entre (" + typeName(type1, true) + ") e (" + typeName(type2, true) +").");
	}
	else if (newType != type1)
	{
		//Se for necessario converter o primeiro elemento
		*x = 1;
	}
	else if (newType != type2)
	{
		//Se for necessario converter o segundo elemento
		*x = 2;
	}

	return newType;
}

int neoConvertType (atributos* $$,atributos* $1, atributos* $2, int forceType)
{
	int out;
	int numTipo = convertType($1->tipo, $2->tipo, &out);
	string declaracaoConvertida = "";

	// Se algum valor precisar ser convertido
	if (out != 0)
	{
		string tipo = typeName(numTipo);
		string label = nextTMP();
		declaracaoConvertida = dcl(numTipo, label);

		// Caso $1 precise ser convertido
		if (out == 1)
		{
			$1->traducao = $1->traducao + cmd(label + " = (" + tipo + ")" + $1->label);
			$1->label = label;
		}

		// Caso $2 precise ser convertido
		if (out == 2)
		{
			$2->traducao = $2->traducao + cmd(label + " = (" + tipo + ")" + $2->label);
			$2->label = label;
		}
	}

	// Declara todas as variáveis
	$$->tipo = (forceType > 0)? forceType : numTipo;
	$$->declaracao = $1->declaracao + $2->declaracao + dcl($$->tipo, $$->label) + declaracaoConvertida;

	// Retorna o tipo
	return numTipo;
}

void checkLabel(string s)
{
	unordered_map<string, simbolo>::const_iterator busca = tabela_simbolos.find(s);

	if (busca == tabela_simbolos.end())
	{
		yyerror("Variável '" + s + "' nao foi declarada."); 
	}
	else
	{
		//cout << "\n [LINHA " << to_string(linha) << "]\n | Variavel declarada encontrada '" << busca->first << "' (" << "typeName(busca->second.tipo)" << ").\n";
	}
}

string cmd (string s, string c)
{
	c = (c == "")? "" : "\t\t//" + c;
	return "\t" + s + ";" + c + "\n";
}

string dcl (int tipo, string label)
{
	return cmd(typeName(tipo) + "\t" + label);
}

string cst (string label1, int tipo, string label2)
{
	return cmd(label1 + " = " + "(" + typeName(tipo) + ")" + label2);
}

void setTipo(string id, int tipo)
{
	tabela_simbolos[id].tipo = tipo;
}

int getTipo(string id)
{
	return tabela_simbolos[id].tipo;
}

int getEscopo(string id)
{
	return tabela_simbolos[id].escopo;
}

int getClasse(string id)
{
	return tabela_simbolos[id].classe;
}

bool isAtivo(string id)
{
	return tabela_simbolos[id].ativo;
}

string getLabel(string id)
{
	return tabela_simbolos[id].label;
}

bool isDeclared(string id)
{
	return tabela_simbolos.find(id) != tabela_simbolos.end();
}

void printHash()
{
	for (auto& it: tabela_simbolos) {
    // Do stuff
    cout << it.first;
	}
}
