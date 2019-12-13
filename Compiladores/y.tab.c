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
#include <vector>
#include <stdlib.h>
#include <queue>

#define YYSTYPE atributos
#define DISPLAY_COLOR false

using namespace std;

struct atributos {
	string label;
	string declaracao;
	string traducao;
	string desalocacao;
	int tipo;
	int tamanho;
	bool dinamico;
	string identificador;

	string traducaoAlternativa;

	string lblInicio;
	string lblFim;

	string tmpTamanho;

	string declaracaoDeFuncao;
	string traducaoDeFuncao;

	int indexLista;
};

struct simbolo {
	int tipo;
	string label;
	string tmpTamanho;
	int tamanho;
	int tipoElemento;
	vector<int> dimensoes;
};

struct funcao {
	int tipo;
	string identificador;
	vector<int> tipoParam;
	vector<int>::iterator it;

	int argumentosPassados;
};

unordered_map<string, funcao> ListaDeFuncoes;

struct funcao* funcaoAtual;
struct funcao* auxFuncao;

class Contexto
{
public:
	unordered_map<string, simbolo> simbolos;
	int tipo;
	string lblInicio;
	string lblFim;
	Contexto* anterior;
};

struct _case
{
	string label;
	string valor;
	int tipo;
	int linha;
};

class Pilha_alternador
{
public:
	string label;
	string lblFim;
	string lblDefault;
	int tipo;
	Pilha_alternador* anterior;
};

int countTMP = 0;
int countVAR = 0;
int countLBL = 0;
int linha = 1;
Contexto* contextoAtual;
int proximoContexto = 0;
string espacamentoDeIndexacao;

vector<int> saltos;
vector<string> tmpSaltos;
Pilha_alternador* alternador_atual = NULL;

int yylex(void);
void yyerror(string);
string nextTMP();
string nextVAR();
string nextLBL();
string typeName(int, bool = false);
bool checkTypes(int, int);
void checkLabel(string);
int verificarTipos(int, int, int*, char op = ' ');
int converterTipos (atributos*, atributos*, atributos*, char, int forceType = 0);
void converterTipo(atributos*, int, atributos*, bool antecipado = false);

string cmd(string);
string dcl(int, string, string = "");
string cst (string, int, string);
string lbl(string);
string dclVetor(int, string, string);

int tabelaOperadores (int, char, int);

void setTipo(string, int);
int getTipo(string);
int getClasse(string);
bool isAtivo(string);
string getLabel(string);
bool isDeclared(string);

vector<string> split(string, char);

void addSimbolo(string, simbolo);
void novoSimbolo(string, string, int, int tamanho = 0, string tmpTamanho = "", int tipoElemento = -1);
simbolo* getSimbolo(string, Contexto* contexto = NULL);
simbolo* getSimboloPilha(string);

funcao* getFuncao(string);
bool isFunDeclared(string);

Contexto* novoContexto();
void empilharContexto(int tipo, string = "", string = "");
void desempilharContexto();
void imprimirContexto(bool exibirLBL = false);
Contexto* procurarContextoLaco();
void desempilharContextoAte(Contexto*);

void empilharAlternador(string, string, int);
void desempilharAlternador();

void empilharCase();
void desempilharContexto();

void empilharNovaFuncao(string);
void addFuncao(string, funcao*);
void definirRetornoFuncao(int);

void declararString(atributos*, string, bool antecipado = false);
int tamanhoString(string);

string valorPadrao(int);

void printVector(vector<int> const &input);


#line 233 "y.tab.c" /* yacc.c:337  */
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
    TK_DEF = 262,
    TK_TIPO = 263,
    TK_IF = 264,
    TK_ELSE = 265,
    TK_WHILE = 266,
    TK_DO = 267,
    TK_FOR = 268,
    TK_SWITCH = 269,
    TK_CASE = 270,
    TK_BREAK = 271,
    TK_CONTINUE = 272,
    TK_RETORNO = 273,
    TK_DEFAULT = 274,
    TK_OP_IGUALDADE = 275,
    TK_OP_DESIGUALDADE = 276,
    TK_OP_MAIORIGUAL = 277,
    TK_OP_MENORIGUAL = 278,
    TK_OP_NOT = 279,
    TK_OP_LOGICAL_AND = 280,
    TK_OP_AND = 281,
    TK_OP_LOGICAL_OR = 282,
    TK_OP_XOR = 283,
    TK_OP_IOR = 284,
    TK_OP_ADD = 285,
    TK_OP_MUL = 286,
    TK_OP_SUB = 287,
    TK_OP_UN_ADD = 288,
    TK_OP_UN_SUB = 289,
    TK_TIPO_INDEFINIDO = 290,
    TK_TIPO_INT = 291,
    TK_TIPO_FLOAT = 292,
    TK_TIPO_CHAR = 293,
    TK_TIPO_BOOL = 294,
    TK_TIPO_STRING = 295,
    TK_TIPO_VETOR = 296,
    TK_TIPO_VOID = 297,
    TK_CLASSE_VARIAVEL = 298,
    TK_CLASSE_FUNCAO = 299,
    TK_FIM = 300,
    TK_ERROR = 301,
    TK_CTX_BLOCO = 302,
    TK_CTX_IF = 303,
    TK_CTX_WHILE = 304,
    TK_CTX_FOR = 305,
    TK_CTX_CASE = 306,
    TK_OUT = 307,
    TK_IN = 308
  };
#endif
/* Tokens.  */
#define TK_LITERAL 258
#define TK_ID 259
#define TK_MAIN 260
#define TK_VAR 261
#define TK_DEF 262
#define TK_TIPO 263
#define TK_IF 264
#define TK_ELSE 265
#define TK_WHILE 266
#define TK_DO 267
#define TK_FOR 268
#define TK_SWITCH 269
#define TK_CASE 270
#define TK_BREAK 271
#define TK_CONTINUE 272
#define TK_RETORNO 273
#define TK_DEFAULT 274
#define TK_OP_IGUALDADE 275
#define TK_OP_DESIGUALDADE 276
#define TK_OP_MAIORIGUAL 277
#define TK_OP_MENORIGUAL 278
#define TK_OP_NOT 279
#define TK_OP_LOGICAL_AND 280
#define TK_OP_AND 281
#define TK_OP_LOGICAL_OR 282
#define TK_OP_XOR 283
#define TK_OP_IOR 284
#define TK_OP_ADD 285
#define TK_OP_MUL 286
#define TK_OP_SUB 287
#define TK_OP_UN_ADD 288
#define TK_OP_UN_SUB 289
#define TK_TIPO_INDEFINIDO 290
#define TK_TIPO_INT 291
#define TK_TIPO_FLOAT 292
#define TK_TIPO_CHAR 293
#define TK_TIPO_BOOL 294
#define TK_TIPO_STRING 295
#define TK_TIPO_VETOR 296
#define TK_TIPO_VOID 297
#define TK_CLASSE_VARIAVEL 298
#define TK_CLASSE_FUNCAO 299
#define TK_FIM 300
#define TK_ERROR 301
#define TK_CTX_BLOCO 302
#define TK_CTX_IF 303
#define TK_CTX_WHILE 304
#define TK_CTX_FOR 305
#define TK_CTX_CASE 306
#define TK_OUT 307
#define TK_IN 308

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
       2,     2,     2,     2,     2,    64,     2,     2,     2,     2,
      59,    60,    57,    55,    65,    56,     2,    58,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    63,
      68,    54,    69,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   182,   182,   195,   194,   208,   211,   211,   226,   226,
     243,   250,   257,   258,   261,   270,   277,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     304,   310,   318,   323,   330,   349,   371,   385,   403,   431,
     452,   501,   512,   528,   617,   677,   677,   705,   728,   729,
     752,   773,   794,   819,   820,   838,   839,   850,   851,   917,
     918,   928,   929,   939,   940,   950,   951,   961,   963,  1005,
    1099,  1127,  1157,  1171,  1186,  1204,  1222,  1243,  1266,  1272,
    1280,  1287,  1295,  1310,  1342,  1342,  1371,  1387,  1402,  1433,
    1471,  1471,  1514,  1514,  1547,  1546,  1607,  1606,  1639,  1649,
    1656,  1696,  1707,  1724,  1732,  1739,  1739,  1764,  1783,  1862,
    1866,  1870,  1871
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_LITERAL", "TK_ID", "TK_MAIN",
  "TK_VAR", "TK_DEF", "TK_TIPO", "TK_IF", "TK_ELSE", "TK_WHILE", "TK_DO",
  "TK_FOR", "TK_SWITCH", "TK_CASE", "TK_BREAK", "TK_CONTINUE",
  "TK_RETORNO", "TK_DEFAULT", "TK_OP_IGUALDADE", "TK_OP_DESIGUALDADE",
  "TK_OP_MAIORIGUAL", "TK_OP_MENORIGUAL", "TK_OP_NOT", "TK_OP_LOGICAL_AND",
  "TK_OP_AND", "TK_OP_LOGICAL_OR", "TK_OP_XOR", "TK_OP_IOR", "TK_OP_ADD",
  "TK_OP_MUL", "TK_OP_SUB", "TK_OP_UN_ADD", "TK_OP_UN_SUB",
  "TK_TIPO_INDEFINIDO", "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_CHAR",
  "TK_TIPO_BOOL", "TK_TIPO_STRING", "TK_TIPO_VETOR", "TK_TIPO_VOID",
  "TK_CLASSE_VARIAVEL", "TK_CLASSE_FUNCAO", "TK_FIM", "TK_ERROR",
  "TK_CTX_BLOCO", "TK_CTX_IF", "TK_CTX_WHILE", "TK_CTX_FOR", "TK_CTX_CASE",
  "TK_OUT", "TK_IN", "'='", "'+'", "'-'", "'*'", "'/'", "'('", "')'",
  "'{'", "'}'", "';'", "'#'", "','", "'['", "']'", "'<'", "'>'", "$accept",
  "S", "BLOCO", "$@1", "DCL_FUNCAO", "$@2", "$@3", "COMANDOS_EXTERNOS",
  "COMANDO_EXTERNO", "CMD_DECLARACAO_GLB", "COMANDOS", "COMANDO",
  "COMANDOS_FOR", "COMANDO_FOR", "LISTA_PARAM", "LISTA_DCL_PARAM",
  "EXP_SIMPLES", "$@4", "EXP_UNARIA", "EXP_NOT", "EXP_ARITMETICA_MUL",
  "EXP_ARITMETICA_ADD", "EXP_RELACIONAL", "EXP_IGUALDADE",
  "EXP_LOGICAL_AND", "EXP_LOGICAL_OR", "EXPRESSAO", "ATRIBUICAO",
  "ENDERECO", "CMD_UNARIO", "CMD_DECLARACOES", "LIST_DECLARACOES",
  "DECLARACAO", "$@5", "DCL_ENDERECO", "CMD_IF", "CMD_WHILE", "$@6",
  "CMD_DOWHILE", "$@7", "CMD_FOR", "@8", "CMD_SWITCH", "$@9",
  "BLOCO_SWITCH", "EXP_CASE", "CMD_RETORNO", "CMD_BREAK", "CMD_CONTINUE",
  "CMD_FUNCAO", "$@10", "CMD_OUT", "OP_RELACIONAL", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    61,    43,    45,    42,    47,    40,
      41,   123,   125,    59,    35,    44,    91,    93,    60,    62
};
# endif

#define YYPACT_NINF -168

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-168)))

#define YYTABLE_NINF -85

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      52,     5,    26,    43,  -168,    42,    52,   -11,     0,     2,
    -168,    70,  -168,  -168,    76,    20,    25,  -168,  -168,    84,
      46,     1,    78,    49,     1,    74,    98,    44,    53,  -168,
    -168,    54,    51,    57,    93,   117,   118,    65,  -168,  -168,
    -168,  -168,  -168,    62,    68,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,    67,     1,  -168,    80,    81,
    -168,  -168,    93,    82,    93,    83,   -50,  -168,    71,    93,
      93,     1,    79,   140,  -168,  -168,  -168,   -20,    86,    93,
      19,    19,    19,    88,    93,   120,  -168,  -168,   119,   124,
      -2,   135,   132,   131,    96,  -168,  -168,    93,    77,  -168,
    -168,    84,  -168,    93,    93,  -168,    97,    93,    94,    93,
      93,    99,    98,   102,   103,   153,    22,   106,   108,  -168,
      93,  -168,  -168,  -168,  -168,    -5,   109,  -168,    93,    93,
    -168,  -168,  -168,  -168,    93,    93,    93,    93,  -168,   110,
     111,    77,  -168,  -168,  -168,  -168,     3,  -168,   105,  -168,
    -168,   169,  -168,  -168,     1,  -168,   116,    -6,   113,  -168,
    -168,    93,   121,   122,  -168,  -168,  -168,   119,   124,    -2,
     135,   132,   114,  -168,  -168,   115,    93,  -168,   112,   170,
       1,    93,    93,   125,     9,  -168,  -168,  -168,  -168,  -168,
      99,     1,  -168,   123,   127,  -168,  -168,  -168,  -168,  -168,
       7,    23,    85,   128,   126,  -168,  -168,    93,     1,  -168,
    -168,     1,     7,     1,  -168,  -168,  -168,  -168
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     0,     0,    12,     0,    11,     0,     0,     0,
       1,     0,    10,    13,     0,     8,     0,    14,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      94,     0,     0,     0,     0,     0,     0,     0,     3,    29,
       7,     5,    79,     0,     0,    20,    21,    22,    23,    24,
      19,    25,    26,    18,    27,    37,     0,     2,     0,     0,
      76,    77,     0,   105,     0,     0,    82,    78,    81,     0,
       0,     0,     0,     0,   103,   104,    38,    39,     0,     0,
       0,     0,     0,     0,     0,    48,    53,    55,    57,    59,
      61,    63,    65,    67,     0,    74,    75,     0,    16,    28,
      17,     0,     9,     0,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    45,    40,
       0,    54,    49,    50,    51,     0,     0,    52,     0,     0,
     111,   112,   109,   110,     0,     0,     0,     0,   102,     0,
       0,    16,    36,    70,    71,   107,     0,    35,    73,    69,
      83,     0,    85,    80,     0,    90,     0,     0,     0,    96,
      47,     0,     0,     0,    44,    41,    56,    58,    60,    62,
      64,    66,     0,     4,    15,     0,     0,    72,     0,    88,
       0,     0,     0,     0,     0,    42,    43,   108,   106,    34,
      87,     0,    91,     0,     0,    99,    46,    86,    89,    93,
       0,     0,     0,     0,    31,    32,    33,     0,     0,    97,
      98,     0,     0,     0,   101,    95,    30,   100
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,   -24,  -168,  -168,  -168,  -168,   179,  -168,  -168,
      55,   -92,   -19,  -168,    31,   100,    18,  -168,  -168,   -71,
      66,    60,    63,    61,    69,  -168,   -33,  -167,   -75,  -156,
      87,    90,  -168,  -168,    10,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,  -168,
    -168,  -168,  -168
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    40,    98,     4,    21,    19,     5,     6,     7,
     140,    41,   203,   204,   146,    23,    85,   161,    86,    87,
      88,    89,    90,    91,    92,    93,   147,    42,    65,    43,
      44,    67,    68,   111,   152,    45,    46,   180,    47,    71,
      48,    72,    49,   183,   201,   210,    50,    51,    52,    53,
     107,    54,   134
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    94,   119,   163,   110,    25,   141,    26,   121,     8,
      27,   202,    28,    29,    30,    31,   -84,    32,    33,    34,
     130,   131,    76,    77,    58,    59,   157,    78,    26,   105,
       9,   108,   102,   205,    35,    36,   113,   114,   207,   118,
      35,    36,   208,    10,   206,   205,    64,   115,    62,   141,
      11,   126,    13,    37,    14,   164,   206,   166,     1,     2,
      64,    15,    38,   175,   139,    39,   132,   133,   176,   196,
     143,   144,    83,   177,   176,    16,   149,   150,    84,    17,
      18,    25,    55,    26,    20,   209,    27,   162,    28,    29,
      30,    31,    22,    32,    33,    34,    76,    77,   122,   123,
     124,    78,    66,    69,    58,    59,    24,    60,    61,    56,
      35,    36,    70,    73,    74,    58,    59,    79,    60,    61,
      75,    95,    96,    80,    97,    99,    81,    82,    62,    37,
     179,   100,   101,    63,   103,   104,   112,   109,   116,    62,
      64,    39,   106,   189,   117,   120,    83,   125,   193,   194,
     128,    64,    84,   127,   129,   135,   192,   136,   137,   138,
     145,   148,   154,   155,   156,   151,   159,   198,   160,   165,
     172,    64,   178,   173,   213,   181,   182,   187,   188,   190,
     191,   185,   186,   199,   214,    12,   195,   215,   211,   217,
     200,   212,   184,   216,   168,   167,   174,   170,   169,     0,
     197,   142,   153,   158,     0,     0,   171
};

static const yytype_int16 yycheck[] =
{
      24,    34,    77,     8,    54,     4,    98,     6,    79,     4,
       9,     4,    11,    12,    13,    14,    66,    16,    17,    18,
      22,    23,     3,     4,    30,    31,     4,     8,     6,    62,
       4,    64,    56,   200,    33,    34,    69,    70,    15,    59,
      33,    34,    19,     0,   200,   212,    66,    71,    54,   141,
       8,    84,    63,    52,    54,    60,   212,   128,     6,     7,
      66,    59,    61,    60,    97,    64,    68,    69,    65,    60,
     103,   104,    53,   148,    65,     5,   109,   110,    59,     3,
      60,     4,     4,     6,    59,    62,     9,   120,    11,    12,
      13,    14,     8,    16,    17,    18,     3,     4,    80,    81,
      82,     8,     4,    59,    30,    31,    60,    33,    34,    60,
      33,    34,    59,    59,    63,    30,    31,    24,    33,    34,
      63,     4,     4,    30,    59,    63,    33,    34,    54,    52,
     154,    63,    65,    59,    54,    54,    65,    54,    59,    54,
      66,    64,    60,   176,     4,    59,    53,    59,   181,   182,
      31,    66,    59,    33,    30,    20,   180,    25,    27,    63,
      63,    67,    60,    60,    11,    66,    60,   191,    60,    60,
      60,    66,     3,    62,   207,    59,    63,    63,    63,    67,
      10,    60,    60,    60,   208,     6,    61,   211,    60,   213,
      63,    65,   161,   212,   134,   129,   141,   136,   135,    -1,
     190,   101,   112,   116,    -1,    -1,   137
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    71,    74,    77,    78,    79,     4,     4,
       0,     8,    77,    63,    54,    59,     5,     3,    60,    76,
      59,    75,     8,    85,    60,     4,     6,     9,    11,    12,
      13,    14,    16,    17,    18,    33,    34,    52,    61,    64,
      72,    81,    97,    99,   100,   105,   106,   108,   110,   112,
     116,   117,   118,   119,   121,     4,    60,    72,    30,    31,
      33,    34,    54,    59,    66,    98,     4,   101,   102,    59,
      59,   109,   111,    59,    63,    63,     3,     4,     8,    24,
      30,    33,    34,    53,    59,    86,    88,    89,    90,    91,
      92,    93,    94,    95,    96,     4,     4,    59,    73,    63,
      63,    65,    72,    54,    54,    96,    60,   120,    96,    54,
      54,   103,    65,    96,    96,    72,    59,     4,    59,    98,
      59,    89,    86,    86,    86,    59,    96,    33,    31,    30,
      22,    23,    68,    69,   122,    20,    25,    27,    63,    96,
      80,    81,    85,    96,    96,    63,    84,    96,    67,    96,
      96,    66,   104,   101,    60,    60,    11,     4,   100,    60,
      60,    87,    96,     8,    60,    60,    89,    90,    91,    92,
      93,    94,    60,    62,    80,    60,    65,    98,     3,    72,
     107,    59,    63,   113,    84,    60,    60,    63,    63,    96,
      67,    10,    72,    96,    96,    61,    60,   104,    72,    60,
      63,   114,     4,    82,    83,    97,    99,    15,    19,    62,
     115,    60,    65,    96,    72,    72,    82,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    73,    72,    72,    75,    74,    76,    74,
      77,    77,    78,    78,    79,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    87,    86,    86,    88,    88,
      88,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    95,    96,    97,    97,
      97,    97,    98,    98,    99,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   102,   104,   104,   105,   105,
     107,   106,   109,   108,   111,   110,   113,   112,   114,   114,
     115,   115,   116,   117,   118,   120,   119,   119,   121,   122,
     122,   122,   122
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     4,     1,     0,     6,     0,     7,
       2,     0,     1,     2,     4,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     3,     1,     4,     2,     1,     1,
       2,     3,     4,     4,     3,     0,     5,     3,     1,     2,
       2,     2,     2,     1,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     4,
       4,     4,     4,     3,     2,     2,     2,     2,     2,     1,
       3,     1,     1,     3,     0,     3,     4,     3,     5,     7,
       0,     6,     0,     7,     0,    10,     0,     8,     2,     0,
       3,     2,     3,     2,     2,     0,     6,     4,     5,     1,
       1,     1,     1
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
#line 183 "sintatica.y" /* yacc.c:1652  */
    {
						cout << "\n/*Compilador Ç*/\n";
						cout << "\n#include <stdio.h>";
						cout << "\n#include <stdlib.h>";
						cout << "\n#include <string.h>\n\n";
						cout << "#define true 1\n#define false 0\n\n";
						cout << yyvsp[-5].declaracao + "\n" << yyvsp[-5].traducao << yyvsp[-5].desalocacao;
						cout << "int main(void)\n{\n" << yyvsp[0].declaracao + "\n" + yyvsp[0].traducao + yyvsp[0].desalocacao << "\n\treturn 0;\n}\n";
					}
#line 1643 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 195 "sintatica.y" /* yacc.c:1652  */
    {
						yyvsp[0].lblInicio = contextoAtual->lblInicio;
						yyvsp[0].lblFim = contextoAtual->lblFim;
					}
#line 1652 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 200 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.lblInicio = yyvsp[-3].lblInicio;
						yyval.lblFim = yyvsp[-3].lblFim;

						yyval.traducao = yyvsp[-1].traducao;
						yyval.declaracao = yyvsp[-1].declaracao;
						yyval.desalocacao = "\n" + yyvsp[-1].desalocacao;
					}
#line 1665 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 211 "sintatica.y" /* yacc.c:1652  */
    { empilharNovaFuncao(yyvsp[-2].label); }
#line 1671 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 212 "sintatica.y" /* yacc.c:1652  */
    {

						if (funcaoAtual == NULL) yyerror("NÃO ERA PRA ISSO TER ACONTECIDO AAAAA...");

						yyval.tipo = funcaoAtual->tipo;
						yyval.label = funcaoAtual->identificador;

						//addFuncao($2.label, funcaoAtual);

						yyval.declaracao = typeName(yyval.tipo) + " " + yyval.label + " ();\n";

						yyval.traducao = typeName(yyval.tipo) + " " + yyval.label + " ()\n{\n";
						yyval.traducao += yyvsp[0].declaracao + yyvsp[0].traducao + "\treturn;\n}\n\n";
					}
#line 1690 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 226 "sintatica.y" /* yacc.c:1652  */
    { empilharNovaFuncao(yyvsp[-1].label); empilharContexto(TK_CTX_BLOCO);}
#line 1696 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 227 "sintatica.y" /* yacc.c:1652  */
    {
						if (funcaoAtual == NULL) yyerror("NÃO ERA PRA ISSO TER ACONTECIDO AAAAA...");

						yyval.tipo = funcaoAtual->tipo;
						yyval.label = funcaoAtual->identificador;

						//addFuncao($2.label, funcaoAtual);
						yyval.declaracao = typeName(yyval.tipo) + " " + yyval.label + " (" + yyvsp[-2].traducao + ");\n";

						yyval.traducao = typeName(yyval.tipo) + " " + yyval.label + " (" + yyvsp[-2].traducao + ")\n{\n";
						yyval.traducao += yyvsp[0].declaracao + yyvsp[0].traducao + "\treturn;\n}\n\n";

						desempilharContexto();
					}
#line 1715 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 244 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[-1].declaracao + yyvsp[0].declaracao;
						yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[-1].desalocacao + yyvsp[0].desalocacao;
					}
#line 1725 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 250 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = "";
						yyval.declaracao = "";
						yyval.desalocacao = "";
					}
#line 1735 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 262 "sintatica.y" /* yacc.c:1652  */
    {
						string var = nextVAR();
						yyval.traducao = cmd(typeName(yyvsp[0].tipo) + " " + var + " = " + yyvsp[0].traducao);
						novoSimbolo(yyvsp[-2].label, var, yyvsp[0].tipo);
					}
#line 1745 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 271 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[-1].declaracao + yyvsp[0].declaracao;
						yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[-1].desalocacao + yyvsp[0].desalocacao;
					}
#line 1755 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 277 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = "";
						yyval.declaracao = "";
						yyval.desalocacao = "";
					}
#line 1765 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 297 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = "";
						yyval.declaracao = "";
						imprimirContexto(true);
					}
#line 1775 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 305 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[-2].declaracao + yyvsp[0].declaracao;
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
					}
#line 1785 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 311 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 1795 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 319 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = yyvsp[0].traducao;
						yyval.declaracao = yyvsp[0].declaracao;
					}
#line 1804 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 324 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = yyvsp[0].traducao;
						yyval.declaracao = yyvsp[0].declaracao;
					}
#line 1813 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 331 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
						yyval.declaracao = yyvsp[-2].declaracao + yyvsp[0].declaracao;
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao; 
						yyval.label = yyvsp[-2].label + ", " + yyvsp[0].label;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;

						yyval.indexLista = auxFuncao->argumentosPassados++;

						if (auxFuncao->argumentosPassados > auxFuncao->tipoParam.size())
							yyerror("A Função requer " + to_string(auxFuncao->tipoParam.size()) + " argumentos. Foram passados " + to_string(auxFuncao->argumentosPassados) + " argumentos");

						if (!auxFuncao) yyerror("Funcao não declarada");
						if(auxFuncao->tipoParam[yyval.indexLista] != yyvsp[0].tipo)
						{
							yyerror("O tipo do argumento '" + to_string(yyval.indexLista + 1) + "' da função esperado é (" + typeName(auxFuncao->tipoParam[yyval.indexLista]) + "). O tipo passado foi ("+ typeName(yyvsp[0].tipo) + ").");
						}
					}
#line 1836 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 350 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = yyvsp[0].traducao;
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.desalocacao = yyvsp[0].desalocacao; 
						yyval.label = yyvsp[0].label;
						yyval.tipo = yyvsp[0].tipo;

						if (!auxFuncao) yyerror("Funcao não declarada");

						auxFuncao->argumentosPassados = 1;
						yyval.indexLista = 0;

						if(auxFuncao->tipoParam[yyval.indexLista] != yyvsp[0].tipo)
						{
							yyerror("O tipo do argumento '"+ to_string(yyval.indexLista + 1) +"' da função esperado é (" + typeName(auxFuncao->tipoParam[yyval.indexLista]) + "). O tipo passado foi ("+ typeName(yyvsp[0].tipo) +").");
						}

						yyval.dinamico = yyvsp[0].dinamico;
					}
#line 1860 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 372 "sintatica.y" /* yacc.c:1652  */
    {

						if (isDeclared(yyvsp[-2].label))
						{
							yyerror("Variável '" + yyvsp[-2].label + "' Já foi declarada anteriormente.");
						}

						funcaoAtual->it = funcaoAtual->tipoParam.insert(funcaoAtual->it, yyvsp[-3].tipo);

						string var = nextVAR();
						novoSimbolo(yyvsp[-2].label, var, yyvsp[-3].tipo);
						yyval.traducao = typeName(yyvsp[-3].tipo) + " " + getLabel(yyvsp[-2].label) + ", " + yyvsp[0].traducao;
					}
#line 1878 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 386 "sintatica.y" /* yacc.c:1652  */
    {

						if (isDeclared(yyvsp[0].label))
						{
							yyerror("Variável '" + yyvsp[0].label + "' Já foi declarada anteriormente.");
						}

						funcaoAtual->it = funcaoAtual->tipoParam.end();
						funcaoAtual->it = funcaoAtual->tipoParam.insert(funcaoAtual->it, yyvsp[-1].tipo);
						string var = nextVAR();
						novoSimbolo(yyvsp[0].label, var, yyvsp[-1].tipo);
						yyval.traducao = typeName(yyvsp[-1].tipo) + " " + getLabel(yyvsp[0].label);
						yyval.tipo = yyvsp[-1].tipo;

					}
#line 1898 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 404 "sintatica.y" /* yacc.c:1652  */
    {	
						// EXPERIMENTAL (ATRIBUICAO DIRETA)
						// $$.label = $1.traducao;
						// $$.traducao = "";

						yyval.label = nextTMP();
						yyval.declaracao = dcl(yyvsp[0].tipo, yyval.label);

						if (yyvsp[0].tipo != TK_TIPO_STRING)
						{
							yyval.traducao = cmd(yyval.label + " = " + yyvsp[0].traducao);
						}
						else
						{
							int tamanho = yyvsp[0].tamanho + 1;						// Necessário incluir \0
							string s = yyvsp[0].traducao;
							int i = 0;

							yyval.traducao = cmd(yyval.label + " = (char*) malloc(sizeof(char) * " + to_string(tamanho) + ")");
							//$$.traducao += cmd($$.label + " = " + $1.traducao);
							yyval.traducao += cmd("strcpy(" + yyval.label + ", " + yyvsp[0].traducao + ")");
							yyval.desalocacao = cmd("free(" + yyval.label + ")");
						}

						yyval.tipo = yyvsp[0].tipo;
						yyval.dinamico = false;
					}
#line 1930 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 432 "sintatica.y" /* yacc.c:1652  */
    {
						checkLabel(yyvsp[0].label);
						yyval.tipo = getTipo(yyvsp[0].label);

						if (yyval.tipo == TK_TIPO_INDEFINIDO)
						{
							yyerror("A variável '" + yyvsp[0].label + "' possui valor indefinido.");
						}

						//$$.tamanho = getSimbolo($1.label)->tamanho;
						simbolo *s = getSimboloPilha(yyvsp[0].label);
						yyval.label = s->label;
						yyval.declaracao = "";
						yyval.traducao = "";
						yyval.desalocacao = "";
						yyval.dinamico = false;
						yyval.tamanho = s->tamanho;
						yyval.tmpTamanho = s->tmpTamanho;
						yyval.identificador = yyvsp[0].label;
					}
#line 1955 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 453 "sintatica.y" /* yacc.c:1652  */
    {
						simbolo *smb = getSimboloPilha(yyvsp[-1].label);

						int tipo = smb->tipoElemento;

						yyval.tipo = tipo;
						yyval.tamanho = smb->tamanho;

						string tmpSalto = nextTMP();
						string tmpAux = nextTMP();
						string tmp = nextTMP();
						string tmpEndereco = nextTMP();

						yyval.declaracao = yyvsp[0].declaracao;
						yyval.declaracao += dcl(TK_TIPO_INT, tmpSalto);
						yyval.declaracao += dcl(TK_TIPO_INT, tmpAux);
						yyval.declaracao += dcl(tipo, tmp);
						yyval.declaracao += dcl(tipo, tmpEndereco, "*");

						yyval.traducao = yyvsp[0].traducao;
						yyval.traducao += cmd(tmpSalto + " = 0");

						yyval.desalocacao = yyvsp[0].desalocacao;
						yyval.tmpTamanho = smb->tmpTamanho;
						yyval.identificador = yyvsp[-1].label;
						yyval.dinamico = false;

						for (int i = 0; i < tmpSaltos.size(); i++)
						{
							string aux = tmpSaltos.at(i);

							int multiplicador = 1;

							for (int j = i; j >= 0; j--)
							{
								multiplicador *= smb->dimensoes.at(j);
							}

							yyval.traducao += cmd(tmpAux + " = " + aux + " * " + to_string(multiplicador));
							yyval.traducao += cmd(tmpSalto + " = " + tmpSalto + " + " + tmpAux);
						}

						tmpSaltos.clear();

						yyval.traducao += cmd(tmpEndereco + " = " + smb->label + "[" + tmpSalto + "]");
						yyval.traducao += cmd(tmp + " = *" + tmpEndereco);
						yyval.label = tmp;
					}
#line 2008 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 502 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = yyvsp[-1].label;
						yyval.declaracao = yyvsp[-1].declaracao;
						yyval.traducao = yyvsp[-1].traducao;
						yyval.tipo = yyvsp[-1].tipo;
						yyval.desalocacao = yyvsp[-1].desalocacao;
						yyval.dinamico = yyvsp[-1].dinamico;
						yyval.tmpTamanho = yyvsp[-1].tmpTamanho;
						yyval.tamanho = yyvsp[-1].tamanho;
					}
#line 2023 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 513 "sintatica.y" /* yacc.c:1652  */
    {
						int out;

						verificarTipos(yyvsp[-3].tipo, yyvsp[-1].tipo, &out);
						yyval.tipo = yyvsp[-3].tipo;

						string newLabel = nextTMP();
						yyval.declaracao = yyvsp[-1].declaracao + dcl(yyvsp[-3].tipo, newLabel);
						yyval.traducao = yyvsp[-1].traducao + cst(newLabel, yyvsp[-3].tipo, yyvsp[-1].label);
						yyval.label = newLabel;
						yyval.desalocacao = yyvsp[-1].desalocacao;
						yyval.dinamico = yyvsp[-1].dinamico;
						yyval.tmpTamanho = yyvsp[-1].tmpTamanho;
						yyval.tamanho = yyvsp[-1].tamanho;
					}
#line 2043 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 529 "sintatica.y" /* yacc.c:1652  */
    {
						string aux = "";
						int tipo = yyvsp[-1].tipo;

						switch (tipo)
						{
							case TK_TIPO_INT:
								aux = "%d";
								break;
							case TK_TIPO_FLOAT:
								aux = "%f";
								break;
							case TK_TIPO_CHAR:
								aux = "%c";
								break;
							case TK_TIPO_BOOL:
								aux = "%d";
								break;
							case TK_TIPO_STRING:
								aux = "%s";
								break;
							default:
								yyerror("Tipo inválido para a operação IN.");
								break;
						}

						string tmp = nextTMP();
						yyval.declaracao += dcl(tipo, tmp);

						if (tipo != TK_TIPO_STRING)
						{
							yyval.traducao = cmd("scanf(\"" + aux + "\", &" + tmp + ");");
						}
						else
						{
							int tamanho = 100;
							string buffer = "";

							string tmpCount = nextTMP();
							string tmpChar = nextTMP();
							string tmpUm = nextTMP();
							string tmpComp = nextTMP();
							string tmpBuffer = nextTMP();
							string tmpN = nextTMP();
							string tmp0 = nextTMP();
							string lblLoop = nextLBL();
							string lblFim = nextLBL();

							yyval.declaracao += dcl(TK_TIPO_INT, tmpCount);
							yyval.declaracao += dcl(TK_TIPO_CHAR, tmpChar);
							yyval.declaracao += dcl(TK_TIPO_INT, tmpUm);
							yyval.declaracao += dcl(TK_TIPO_CHAR, tmpN);
							yyval.declaracao += dcl(TK_TIPO_BOOL, tmpComp);
							yyval.declaracao += dcl(TK_TIPO_STRING, tmpBuffer);
							yyval.declaracao += dcl(TK_TIPO_CHAR, tmp0);

							yyval.traducao = "";
							yyval.traducao += cmd(tmpCount + " = 0");
							yyval.traducao += cmd(tmpUm + " = 1");
							yyval.traducao += cmd(tmpN + " = '\\n'");
							yyval.traducao += cmd(tmp0 + " = '\\0'");
							yyval.traducao += cmd(tmpBuffer + " = (char*)malloc(sizeof(char) * " + tmpUm + ")");
							yyval.traducao += lbl(lblLoop);
							yyval.traducao += cmd("scanf(\"%c\", &" + tmpChar + " )");
							yyval.traducao += cmd(tmpComp + " = " + tmpChar + " == " + tmpN);
							yyval.traducao += cmd("if (" + tmpComp + ") goto " + lblFim);
							yyval.traducao += cmd(tmpCount + " = " + tmpCount + " + " + tmpUm);
							yyval.traducao += cmd(tmpBuffer + " = (char*)realloc(" + tmpBuffer + ", sizeof(char) * " + tmpCount + ")");
							yyval.traducao += cmd("strncat(" + tmpBuffer + ", &" + tmpChar + ", " + tmpUm + ")");
							yyval.traducao += cmd("goto " + lblLoop);
							yyval.traducao += lbl(lblFim);

							yyval.traducao += cmd(tmpCount + " = " + tmpCount + " + " + tmpUm);
							yyval.traducao += cmd("strncat(" + tmpBuffer + ", &" + tmp0 + ", " + tmpUm + ")");

							yyval.traducao += cmd(tmp + " = (char*) malloc(sizeof(char) * " + tmpCount + ")");
							yyval.traducao += cmd("strcpy(" + tmp + ", " + tmpBuffer + ")");

							yyval.tmpTamanho = tmpCount;

							yyval.desalocacao += cmd("free(" + tmpBuffer + ")");
							yyval.desalocacao += cmd("free(" + tmp + ")");
						}

						yyval.tipo = tipo;
						yyval.label = tmp;
						yyval.dinamico = true;
					}
#line 2136 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 618 "sintatica.y" /* yacc.c:1652  */
    {
						string aux = "";
						int tipo = TK_TIPO_STRING;

						string tmp = nextTMP();
						yyval.declaracao += dcl(tipo, tmp);

						int tamanho = 100;
						string buffer = "";

						string tmpCount = nextTMP();
						string tmpChar = nextTMP();
						string tmpUm = nextTMP();
						string tmpComp = nextTMP();
						string tmpBuffer = nextTMP();
						string tmpN = nextTMP();
						string tmp0 = nextTMP();
						string lblLoop = nextLBL();
						string lblFim = nextLBL();

						yyval.declaracao += dcl(TK_TIPO_INT, tmpCount);
						yyval.declaracao += dcl(TK_TIPO_CHAR, tmpChar);
						yyval.declaracao += dcl(TK_TIPO_INT, tmpUm);
						yyval.declaracao += dcl(TK_TIPO_CHAR, tmpN);
						yyval.declaracao += dcl(TK_TIPO_BOOL, tmpComp);
						yyval.declaracao += dcl(TK_TIPO_STRING, tmpBuffer);
						yyval.declaracao += dcl(TK_TIPO_CHAR, tmp0);

						yyval.traducao = "";
						yyval.traducao += cmd(tmpCount + " = 0");
						yyval.traducao += cmd(tmpUm + " = 1");
						yyval.traducao += cmd(tmpN + " = '\\n'");
						yyval.traducao += cmd(tmp0 + " = '\\0'");
						yyval.traducao += cmd(tmpBuffer + " = (char*)malloc(sizeof(char) * " + tmpUm + ")");
						yyval.traducao += lbl(lblLoop);
						yyval.traducao += cmd("scanf(\"%c\", &" + tmpChar + " )");
						yyval.traducao += cmd(tmpComp + " = " + tmpChar + " == " + tmpN);
						yyval.traducao += cmd("if (" + tmpComp + ") goto " + lblFim);
						yyval.traducao += cmd(tmpCount + " = " + tmpCount + " + " + tmpUm);
						yyval.traducao += cmd(tmpBuffer + " = (char*)realloc(" + tmpBuffer + ", sizeof(char) * " + tmpCount + ")");
						yyval.traducao += cmd("strncat(" + tmpBuffer + ", &" + tmpChar + ", " + tmpUm + ")");
						yyval.traducao += cmd("goto " + lblLoop);
						yyval.traducao += lbl(lblFim);

						yyval.traducao += cmd(tmpCount + " = " + tmpCount + " + " + tmpUm);
						yyval.traducao += cmd("strncat(" + tmpBuffer + ", &" + tmp0 + ", " + tmpUm + ")");

						yyval.traducao += cmd(tmp + " = (char*) malloc(sizeof(char) * " + tmpCount + ")");
						yyval.traducao += cmd("strcpy(" + tmp + ", " + tmpBuffer + ")");

						yyval.tmpTamanho = tmpCount;

						yyval.desalocacao += cmd("free(" + tmpBuffer + ")");
						yyval.desalocacao += cmd("free(" + tmp + ")");

						yyval.tipo = tipo;
						yyval.label = tmp;
						yyval.dinamico = true;
					}
#line 2200 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 677 "sintatica.y" /* yacc.c:1652  */
    { auxFuncao = getFuncao(yyvsp[-1].label); }
#line 2206 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 678 "sintatica.y" /* yacc.c:1652  */
    {
						if (!isFunDeclared(yyvsp[-4].label))
						{
							yyerror("Função (" + yyvsp[-4].label + ") não definida.");
						}

						int qntArgs = yyvsp[-1].indexLista + 1;

						if (auxFuncao->tipoParam.size() != auxFuncao->argumentosPassados)
						{
							yyerror("Foram passados " + to_string(qntArgs) + " argumento(s). A Função '" + yyvsp[-4].label + "' requer " + to_string(auxFuncao->tipoParam.size()) + " argumento(s).");

						}

						yyval.label = nextTMP();
						yyval.tipo = ListaDeFuncoes[yyvsp[-4].label].tipo;

						yyval.declaracao = yyvsp[-1].declaracao;
						yyval.declaracao += dcl(yyval.tipo, yyval.label);

						yyval.traducao = yyvsp[-1].traducao;
						yyval.traducao += cmd(yyval.label + " = " + ListaDeFuncoes[yyvsp[-4].label].identificador + "(" + yyvsp[-1].label + ")");

						yyval.desalocacao = yyvsp[-1].desalocacao;
						yyval.dinamico = yyvsp[-1].dinamico;
						yyval.tamanho = 0;
					}
#line 2238 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 706 "sintatica.y" /* yacc.c:1652  */
    {
						if (!isFunDeclared(yyvsp[-2].label))
						{
							yyerror("Função (" + yyvsp[-2].label + ") não definida.");
						}

						if (ListaDeFuncoes[yyvsp[-2].label].tipoParam.size() != 0)
						{
							yyerror("Foram passados 0 argumento(s). A Função '" + yyvsp[-2].label + "' requer " + to_string(ListaDeFuncoes[yyvsp[-2].label].tipoParam.size()) + " argumento(s).");

						}

						yyval.tipo = ListaDeFuncoes[yyvsp[-2].label].tipo;

						yyval.declaracao = dcl(yyval.tipo, yyval.label);

						yyval.traducao = cmd(yyval.label + " = " + ListaDeFuncoes[yyvsp[-2].label].identificador + "()");

						yyval.tamanho = 0;
					}
#line 2263 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 730 "sintatica.y" /* yacc.c:1652  */
    {
						int tipo = yyvsp[0].tipo;

						if (tipo != TK_TIPO_INT && tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador [-] inválido para o tipo (" + typeName(tipo) + ")");
						}

						string tmp = nextTMP();
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.declaracao += dcl(tipo, tmp);

						yyval.traducao = yyvsp[0].traducao;
						yyval.traducao += cmd(tmp + " = -" + yyvsp[0].label);

						yyval.tipo = tipo;
						yyval.label = tmp;

						yyval.desalocacao = yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[0].dinamico;
						yyval.tmpTamanho = yyvsp[0].tmpTamanho;
					}
#line 2290 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 753 "sintatica.y" /* yacc.c:1652  */
    {

						if (yyvsp[0].tipo != TK_TIPO_INT && yyvsp[0].tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + yyvsp[-1].traducao + "] para o tipo (" + typeName(yyvsp[0].tipo) + ").");
						}

						string tmpUm = nextTMP();

						yyval.declaracao = dcl(yyvsp[0].tipo, tmpUm);
						yyval.declaracao += yyvsp[0].declaracao;

						yyval.traducao = yyvsp[0].traducao;
						yyval.traducao += cmd(tmpUm + " = 1");
						yyval.traducao += cmd(yyvsp[0].label + " = " + yyvsp[0].label + " + " + tmpUm);

						yyval.tipo = yyvsp[0].tipo;
						yyval.label = yyvsp[0].label;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 2315 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 774 "sintatica.y" /* yacc.c:1652  */
    {

						if (yyvsp[0].tipo != TK_TIPO_INT && yyvsp[0].tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + yyvsp[-1].traducao + "] para o tipo (" + typeName(yyvsp[0].tipo) + ").");
						}

						string tmpUm = nextTMP();

						yyval.declaracao = dcl(yyvsp[0].tipo, tmpUm);
						yyval.declaracao += yyvsp[0].declaracao;

						yyval.traducao = yyvsp[0].traducao;
						yyval.traducao += cmd(tmpUm + " = 1");
						yyval.traducao += cmd(yyvsp[0].label + " = " + yyvsp[0].label + " - " + tmpUm);

						yyval.tipo = yyvsp[0].tipo;
						yyval.label = yyvsp[0].label;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 2340 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 795 "sintatica.y" /* yacc.c:1652  */
    {
						if (yyvsp[-1].tipo != TK_TIPO_INT && yyvsp[-1].tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + yyvsp[0].traducao + "] para o tipo (" + typeName(yyvsp[-1].tipo) + ").");
						}

						string tmpUm = nextTMP();
						string tmp = nextTMP();

						yyval.declaracao = dcl(yyvsp[-1].tipo, tmpUm);
						yyval.declaracao += yyvsp[-1].declaracao;
						yyval.declaracao += dcl(yyvsp[-1].tipo, tmp);

						yyval.traducao = yyvsp[-1].traducao;
						yyval.traducao += cmd(tmp + " = " + yyvsp[-1].label);
						yyval.traducao += cmd(tmpUm + " = 1");
						yyval.traducao += cmd(yyvsp[-1].label + " = " + yyvsp[-1].label + " + " + tmpUm);

						yyval.tipo = yyvsp[-1].tipo;
						yyval.label = tmp;
						yyval.desalocacao = yyvsp[-1].desalocacao;
					}
#line 2367 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 821 "sintatica.y" /* yacc.c:1652  */
    {

						if (yyvsp[0].tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName(yyvsp[0].tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						yyval.label = nextTMP();
						yyval.tipo = TK_TIPO_BOOL;
						yyval.declaracao = yyvsp[0].declaracao + dcl(yyval.tipo, yyval.label);
						yyval.traducao = yyvsp[0].traducao + cmd(yyval.label + " = !" + yyvsp[0].label);
						yyval.desalocacao = yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[0].dinamico;
						yyval.tmpTamanho = yyvsp[0].tmpTamanho;
						//$$.traducao = $2.traducao + "\t" + declaracao + $$.label + " = !" + $2.label + ";\n";
					}
#line 2388 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 840 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						converterTipos(&yyval, &yyvsp[-2], &yyvsp[0], yyvsp[-1].traducao[0]);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd (yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;
						yyval.tmpTamanho = yyvsp[-2].tmpTamanho;
					}
#line 2401 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 852 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						converterTipos(&yyval, &yyvsp[-2], &yyvsp[0], yyvsp[-1].traducao[0]);

						yyval.traducao = yyvsp[-2].traducao;
						yyval.traducao += yyvsp[0].traducao;

						if (yyval.tipo != TK_TIPO_STRING)
						{
							yyval.traducao += cmd (yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
						}
						else
						{
							string tmp = nextTMP();
							string tmpTamanho1 = yyvsp[-2].tmpTamanho;
							string tmpTamanho2 = yyvsp[0].tmpTamanho;
							string tmpUm = nextTMP();

							if (tmpTamanho1 == "")
							{
								// Expressão esquerda é estática. Devo declarar temporária
								tmpTamanho1 = nextTMP();
								yyval.declaracao += dcl(TK_TIPO_INT, tmpTamanho1);
								yyval.traducao += cmd(tmpTamanho1 + " = " + to_string(yyvsp[-2].tamanho));
							}

							if (tmpTamanho2 == "")
							{
								// Expressão direita é estática. Devo declarar temporária
								tmpTamanho2 = nextTMP();
								yyval.declaracao += dcl(TK_TIPO_INT, tmpTamanho2);
								yyval.traducao += cmd(tmpTamanho2 + " = " + to_string(yyvsp[0].tamanho));
							}

							// Declarar String temporária
							yyval.declaracao += dcl(TK_TIPO_STRING, tmp);

							// Declarar Temporiaria para 1
							yyval.declaracao += dcl(TK_TIPO_INT, tmpUm);
							yyval.traducao += cmd(tmpUm + " = 1");

							// Declarar Temporária para novo tamanho
							string tmpSomaTamanhos = nextTMP();
							yyval.declaracao += dcl(TK_TIPO_INT, tmpSomaTamanhos);

							// Realizar soma de tamanhos
							yyval.traducao += cmd(tmpSomaTamanhos + " = " + tmpTamanho1 + " + " + tmpTamanho2);
							yyval.traducao += cmd(tmpSomaTamanhos + " = " + tmpSomaTamanhos + " + " + tmpUm);

							// Alocar memória e realizar concatenação
							yyval.traducao += cmd(tmp + " = (char*) malloc(sizeof(char) * " + tmpSomaTamanhos + ")");
							yyval.traducao += cmd("strcpy(" + tmp + ", " + yyvsp[-2].label + ")");
							yyval.traducao += cmd("strcat(" + tmp + ", " + yyvsp[0].label + ")");
							yyval.traducao += cmd(yyval.label + " = " + tmp);

							// Desalocar temporária e string no final do bloco
							yyval.desalocacao += cmd("free(" + tmp + ")");
							//$$.desalocacao += cmd("free(" + $$.label + ")");
						}

						yyval.desalocacao += yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;
					}
#line 2469 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 919 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						converterTipos(&yyval, &yyvsp[-2], &yyvsp[0], '>', TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;
					}
#line 2481 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 930 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						converterTipos(&yyval, &yyvsp[-2], &yyvsp[0], '=', TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;
					}
#line 2493 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 941 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						converterTipos(&yyval, &yyvsp[-2], &yyvsp[0], '&', TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;
					}
#line 2505 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 952 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.label = nextTMP();
						converterTipos(&yyval, &yyvsp[-2], &yyvsp[0], '|', TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;
					}
#line 2517 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 964 "sintatica.y" /* yacc.c:1652  */
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

							if (yyvsp[0].dinamico && yyvsp[-2].tipo == TK_TIPO_STRING)
							{
								// Declarar Temporaria de Tamanho
								string tmpTamanho = yyvsp[0].tmpTamanho;
								//$$.declaracao += dcl(TK_TIPO_INT, tmpTamanho);
								getSimboloPilha(yyvsp[-2].label)->tmpTamanho = tmpTamanho;
							}
						}

						if (yyvsp[-2].tipo == TK_TIPO_VETOR)
						{
							yyerror("Atribuicao Invalida.");
						}

						converterTipo(&yyval, yyvsp[-2].tipo, &yyvsp[0]);

						if (yyvsp[0].dinamico)
						{
							yyval.traducao += cmd(getSimboloPilha(yyvsp[-2].label)->tmpTamanho + " = " + to_string(yyvsp[0].tamanho));
						}

						yyvsp[-2].label = getLabel(yyvsp[-2].label);
						yyval.traducao += cmd(yyvsp[-2].label + " = " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 2563 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 1006 "sintatica.y" /* yacc.c:1652  */
    {
						if (!isDeclared(yyvsp[-3].label))
						{
							yyerror("Variável '" + yyvsp[-3].label + "' nao declarada.");
						}

						yyvsp[-3].tipo = getTipo(yyvsp[-3].label);

						yyval.traducao = "";
						yyval.declaracao = "";

						simbolo *smb = getSimboloPilha(yyvsp[-3].label);

						if (smb->tipoElemento == TK_TIPO_INDEFINIDO)
						{
							smb->tipoElemento = yyvsp[0].tipo;

							string tmpI = nextTMP();
							string tmpPonteiro = nextTMP();

							yyval.declaracao += dcl(TK_TIPO_INT, tmpI);
							yyval.declaracao += dcl(smb->tipoElemento, tmpPonteiro, "*");

							for (int i = 0; i < smb->tamanho; i++)
							{
								string tmpValor = nextTMP();
								yyval.declaracao += dcl(smb->tipoElemento, tmpValor);

								yyval.traducao += cmd(tmpI + " = " + to_string(i));

								if (smb->tipoElemento != TK_TIPO_STRING)
								{
									yyval.traducao += cmd(tmpValor + " = " + valorPadrao(smb->tipoElemento));
									yyval.traducao += cmd(tmpPonteiro + " = &" + tmpValor);
									yyval.traducao += cmd(smb->label + "[" + tmpI + "] = " + tmpPonteiro);
								}
								else
								{
									yyval.traducao += cmd(tmpValor + " = (char*)malloc(sizeof(char))");
									yyval.traducao += cmd("strcpy(" + tmpValor + ", \"\")");
									yyval.traducao += cmd(smb->label + "[" + tmpI + "] = " + tmpValor);

									yyval.desalocacao += cmd("free(" + tmpValor + ")");
								}
							}
						}

						yyval.declaracao += yyvsp[-2].declaracao;
						yyval.declaracao += yyvsp[0].declaracao;

						yyval.traducao += yyvsp[-2].traducao;
						yyval.traducao += yyvsp[0].traducao;

						yyval.desalocacao += yyvsp[-2].desalocacao;
						yyval.desalocacao += yyvsp[0].desalocacao;

						int tipo = smb->tipoElemento;

						string tmpEndereco = nextTMP();
						string tmpAux = nextTMP();

						yyval.declaracao += dcl(TK_TIPO_INT, tmpEndereco);
						yyval.declaracao += dcl(TK_TIPO_INT, tmpAux);

						yyval.traducao += cmd(tmpEndereco + " = 0");

						for (int i = 0; i < tmpSaltos.size(); i++)
						{
							string aux = tmpSaltos.at(i);

							int multiplicador = 1;

							for (int j = i; j >= 0; j--)
							{
								multiplicador *= smb->dimensoes.at(j);
							}

							yyval.traducao += cmd(tmpAux + " = " + aux + " * " + to_string(multiplicador));
							yyval.traducao += cmd(tmpEndereco + " = " + tmpEndereco + " + " + tmpAux);
						}

						tmpSaltos.clear();

						//converterTipo(&$$, $1.tipo, &$4);

						if (yyvsp[0].dinamico)
						{
							yyval.traducao += cmd(getSimboloPilha(yyvsp[-3].label)->tmpTamanho + " = " + to_string(yyvsp[0].tamanho));
						}

						yyvsp[-3].label = getLabel(yyvsp[-3].label);
						yyval.traducao += cmd(yyvsp[-3].label + "[" + tmpEndereco + "] = &" + yyvsp[0].label);
					}
#line 2661 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 1100 "sintatica.y" /* yacc.c:1652  */
    {
						if (!isDeclared(yyvsp[-3].label))
						{
							yyerror("Variável '" + yyvsp[-3].label + "' nao declarada.");
						}

						simbolo* smb = getSimboloPilha(yyvsp[-3].label);
						yyvsp[-3].tipo = smb->tipo;
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;

						if (yyvsp[-3].tipo == TK_TIPO_INDEFINIDO)
						{
							yyerror("Variável '" + yyvsp[-3].label + "' possui tipo indefinido.");
						}

						if (yyvsp[-3].tipo == TK_TIPO_VETOR)
						{
							yyerror("Atribuição inválida.");
						}

						converterTipo(&yyval, yyvsp[-3].tipo, &yyvsp[0]);

						yyvsp[-3].label = smb->label;
						yyval.traducao += cmd(yyvsp[-3].label + " = " + yyvsp[-3].label + " " + yyvsp[-2].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-1].desalocacao;
					}
#line 2693 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 1128 "sintatica.y" /* yacc.c:1652  */
    {
						if (!isDeclared(yyvsp[-3].label))
						{
							yyerror("Variável '" + yyvsp[-3].label + "' nao declarada.");
						}

						simbolo* smb = getSimboloPilha(yyvsp[-3].label);
						yyvsp[-3].tipo = smb->tipo;
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;

						if (yyvsp[-3].tipo == TK_TIPO_INDEFINIDO)
						{
							yyerror("Variável '" + yyvsp[-3].label + "' possui tipo indefinido.");
						}

						if (yyvsp[-3].tipo == TK_TIPO_VETOR)
						{
							yyerror("Atribuição inválida.");
						}

						converterTipo(&yyval, yyvsp[-3].tipo, &yyvsp[0]);

						yyvsp[-3].label = smb->label;
						yyval.traducao += cmd(yyvsp[-3].label + " = " + yyvsp[-3].label + " " + yyvsp[-2].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-1].desalocacao;
					}
#line 2725 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 1158 "sintatica.y" /* yacc.c:1652  */
    {
						if (yyvsp[-2].tipo != TK_TIPO_INT)
						{
							yyerror("Esperado tipo (int).");
						}

						tmpSaltos.insert(tmpSaltos.end(), yyvsp[-2].label);

						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
						yyval.declaracao = yyvsp[-2].declaracao + yyvsp[0].declaracao;
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;

					}
#line 2743 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 1172 "sintatica.y" /* yacc.c:1652  */
    {
						if (yyvsp[-1].tipo != TK_TIPO_INT)
						{
							yyerror("Esperado tipo (int)");
						}

						tmpSaltos.insert(tmpSaltos.end(), yyvsp[-1].label);

						yyval.traducao = yyvsp[-1].traducao;
						yyval.declaracao = yyvsp[-1].declaracao;
						yyval.desalocacao = yyvsp[-1].desalocacao;
					}
#line 2760 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 1187 "sintatica.y" /* yacc.c:1652  */
    {
						simbolo* s = getSimboloPilha(yyvsp[0].label);
						yyvsp[0].label = s->label;
						yyvsp[0].tipo = s->tipo;

						if (yyvsp[0].tipo != TK_TIPO_INT && yyvsp[0].tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + yyvsp[-1].traducao + "] para o tipo (" + typeName(yyvsp[0].tipo) + ").");
						}

						string tmpUm = nextTMP();

						yyval.declaracao = dcl(yyvsp[0].tipo, tmpUm);

						yyval.traducao = cmd(tmpUm + " = 1");
						yyval.traducao += cmd(yyvsp[0].label + " = " + yyvsp[0].label + " + " + tmpUm);
					}
#line 2782 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 1205 "sintatica.y" /* yacc.c:1652  */
    {
						simbolo* s = getSimboloPilha(yyvsp[0].label);
						yyvsp[0].label = s->label;
						yyvsp[0].tipo = s->tipo;

						if (yyvsp[0].tipo != TK_TIPO_INT && yyvsp[0].tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + yyvsp[-1].traducao + "] para o tipo (" + typeName(yyvsp[0].tipo) + ").");
						}

						string tmpUm = nextTMP();

						yyval.declaracao = dcl(yyvsp[0].tipo, tmpUm);

						yyval.traducao = cmd(tmpUm + " = 1");
						yyval.traducao += cmd(yyvsp[0].label + " = " + yyvsp[0].label + " - " + tmpUm);
					}
#line 2804 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 1223 "sintatica.y" /* yacc.c:1652  */
    {
						simbolo* s = getSimboloPilha(yyvsp[-1].label);
						yyvsp[-1].label = s->label;
						yyvsp[-1].tipo = s->tipo;

						if (yyvsp[-1].tipo != TK_TIPO_INT && yyvsp[-1].tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + yyvsp[0].traducao + "] para o tipo (" + typeName(yyvsp[-1].tipo) + ").");
						}

						string tmpUm = nextTMP();
						string tmp = nextTMP();

						yyval.declaracao = dcl(yyvsp[-1].tipo, tmpUm);
						yyval.declaracao += dcl(yyvsp[-1].tipo, tmp);

						yyval.traducao = cmd(tmp + " = " + yyvsp[-1].label);
						yyval.traducao += cmd(tmpUm + " = 1");
						yyval.traducao += cmd(yyvsp[-1].label + " = " + yyvsp[-1].label + " + " + tmpUm);
					}
#line 2829 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 1244 "sintatica.y" /* yacc.c:1652  */
    {
						simbolo* s = getSimboloPilha(yyvsp[-1].label);
						yyvsp[-1].label = s->label;
						yyvsp[-1].tipo = s->tipo;

						if (yyvsp[-1].tipo != TK_TIPO_INT && yyvsp[-1].tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + yyvsp[0].traducao + "] para o tipo (" + typeName(yyvsp[-1].tipo) + ").");
						}

						string tmpUm = nextTMP();
						string tmp = nextTMP();

						yyval.declaracao = dcl(yyvsp[-1].tipo, tmpUm);
						yyval.declaracao += dcl(yyvsp[-1].tipo, tmp);

						yyval.traducao = cmd(tmp + " = " + yyvsp[-1].label);
						yyval.traducao += cmd(tmpUm + " = 1");
						yyval.traducao += cmd(yyvsp[-1].label + " = " + yyvsp[-1].label + " - " + tmpUm);
					}
#line 2854 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 1267 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 2864 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 1273 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 2874 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 1281 "sintatica.y" /* yacc.c:1652  */
    {
						//Tinha + $3 declaracao e traducao
						yyval.declaracao += yyvsp[0].declaracao;
						yyval.traducao += yyvsp[0].traducao;
						yyval.desalocacao += yyvsp[0].desalocacao;
					}
#line 2885 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 1288 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 2895 "y.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 1296 "sintatica.y" /* yacc.c:1652  */
    {
						if (getSimbolo(yyvsp[0].label, contextoAtual) != NULL)
							yyerror("Variável '" + yyvsp[0].label + "' já foi declarada nesse contexto.");

						string var = nextVAR();
						novoSimbolo(yyvsp[0].label, var, TK_TIPO_INDEFINIDO);
						//tabela_simbolos[$1.label] = {TK_TIPO_INDEFINIDO, -1, -1, true, newLabel};
						yyvsp[0].label = var;
						yyval.traducao = "";
						yyval.declaracao = "";
						yyval.desalocacao = "";

						//$$.traducao = "";
					}
#line 2914 "y.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 1311 "sintatica.y" /* yacc.c:1652  */
    {
						if (getSimbolo(yyvsp[-2].label, contextoAtual) != NULL)
							yyerror("Variável '" + yyvsp[-2].label + "' já foi declarada nesse contexto.");

						yyvsp[-2].tipo = yyvsp[0].tipo;
						//string declaracao = dcl($1.tipo, $1.label);

						string newLabel = nextVAR();
						string tmpTamanho = "";

						if (yyvsp[0].dinamico && yyvsp[0].tipo == TK_TIPO_STRING)
						{
							tmpTamanho = yyvsp[0].tmpTamanho;
							//$$.traducao += cmd(tmpTamanho + " = " + to_string($3.tamanho));
						}

						novoSimbolo(yyvsp[-2].label, newLabel, yyvsp[-2].tipo, yyvsp[0].tamanho, tmpTamanho);
						yyvsp[-2].label = newLabel;

						yyval.declaracao = yyvsp[0].declaracao;
						yyval.declaracao += dcl(yyvsp[-2].tipo, yyvsp[-2].label);
						yyval.traducao = yyvsp[0].traducao;
						yyval.traducao += cmd(yyvsp[-2].label + " = " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[0].desalocacao;

						if (yyvsp[0].tipo == TK_TIPO_STRING)
						{
							//$$.declaracao += dcl(TK_TIPO_INT, tmpTamanho);
							//$$.traducao += cmd(tmpTamanho + " = " + to_string($3.tamanho));
						}
					}
#line 2950 "y.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 1342 "sintatica.y" /* yacc.c:1652  */
    { saltos.clear(); }
#line 2956 "y.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 1343 "sintatica.y" /* yacc.c:1652  */
    {
						if (getSimbolo(yyvsp[-2].label, contextoAtual) != NULL)
							yyerror("Variável '" + yyvsp[-2].label + "' já foi declarada nesse contexto.");

						string varVetor = nextVAR();
						string tmpTamanho = nextTMP();
						int tamanhoVetor = yyvsp[0].tamanho;

						yyval.declaracao = dcl(TK_TIPO_VETOR, varVetor);
						yyval.declaracao += dcl(TK_TIPO_INT, tmpTamanho);

						yyval.traducao = cmd(tmpTamanho + " = " + to_string(tamanhoVetor));
						yyval.traducao += dclVetor(TK_TIPO_INDEFINIDO, varVetor, tmpTamanho);

						novoSimbolo(yyvsp[-2].label, varVetor, TK_TIPO_VETOR, tamanhoVetor);

						vector<int> vetorDimensoes(saltos);
						getSimbolo(yyvsp[-2].label)->dimensoes = vetorDimensoes;
						saltos.clear();

						yyval.tipo = TK_TIPO_INDEFINIDO;
						yyval.tamanho = tamanhoVetor;

						//$$.desalocacao += cmd("free(" + varVetor +")"); 

					}
#line 2987 "y.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 1372 "sintatica.y" /* yacc.c:1652  */
    {
						if (yyvsp[-2].tipo != TK_TIPO_INT)
							yyerror("Tipo int esperado para tamanho do vetor.");

						int tamanho = stoi(yyvsp[-2].traducao);

						if (tamanho < 1)
							yyerror("Um vetor deve ter tamanho >= 1.");

						yyval.tamanho = yyvsp[0].tamanho * tamanho;

						//cout << "----- " << $$.tamanho << "aaa\n";

						saltos.insert(saltos.end(), tamanho);
					}
#line 3007 "y.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 1388 "sintatica.y" /* yacc.c:1652  */
    {
						if (yyvsp[-1].tipo != TK_TIPO_INT)
							yyerror("Tipo int esperado para tamanho do vetor.");

						int tamanho = stoi(yyvsp[-1].traducao);

						if (tamanho < 1)
							yyerror("Um vetor deve ter tamanho >= 1.");

						yyval.tamanho = tamanho;
						saltos.insert(saltos.end(), 1);
					}
#line 3024 "y.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 1403 "sintatica.y" /* yacc.c:1652  */
    {
						if (yyvsp[-2].tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName(yyvsp[-3].tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo novo Label de Fim
						string lblFim = nextLBL();

						// Imprimir Traducão e Declaracão da Expressão
						yyval.traducao = yyvsp[-2].traducao;
						yyval.declaracao = yyvsp[-2].declaracao;
						yyval.desalocacao = yyvsp[-2].desalocacao;

						// Negar valor da Expressão
						string newLabel = nextTMP();
						yyval.declaracao += dcl(TK_TIPO_BOOL, newLabel);
						yyval.traducao += cmd(newLabel + " = !" + yyvsp[-2].label);

						// Imprimir Goto para Label de Fim
						yyval.traducao += cmd("if (" + newLabel + ") goto " + lblFim);

						// Imprimir Bloco
						yyval.declaracao += yyvsp[0].declaracao;
						yyval.traducao += yyvsp[0].traducao;
						yyval.desalocacao += yyvsp[0].desalocacao;

						// Imprimir Label de Fim
						yyval.traducao += lbl(lblFim);
					}
#line 3059 "y.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 1434 "sintatica.y" /* yacc.c:1652  */
    {
						if (yyvsp[-4].tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName(yyvsp[-5].tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo novo Label de Fim
						string lblFim = nextLBL();

						// Imprimir Traducão e Declaracão da Expressão
						yyval.traducao = yyvsp[-4].traducao;
						yyval.declaracao = yyvsp[-4].declaracao ;
						yyval.desalocacao = yyvsp[-4].desalocacao;

						// Negar valor da Expressão
						string newLabel = nextTMP();
						yyval.declaracao += dcl(TK_TIPO_BOOL, newLabel);
						yyval.traducao += cmd(newLabel + " = !" + yyvsp[-4].label);

						// Imprimir Goto para Label de Fim
						yyval.traducao += cmd("if (" + newLabel + ") goto " + lblFim);

						// Imprimir Bloco If
						yyval.declaracao += yyvsp[-2].declaracao;
						yyval.traducao += yyvsp[-2].traducao;
						yyval.desalocacao += yyvsp[-2].desalocacao;

						// Imprimir Label de Fim
						yyval.traducao += lbl(lblFim);

						// Imprimindo Bloco Else
						yyval.declaracao += yyvsp[0].declaracao;
						yyval.traducao += yyvsp[0].traducao;
						yyval.desalocacao += yyvsp[0].desalocacao;
					}
#line 3099 "y.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 1471 "sintatica.y" /* yacc.c:1652  */
    { proximoContexto = TK_CTX_WHILE; }
#line 3105 "y.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 1472 "sintatica.y" /* yacc.c:1652  */
    {

						//imprimirContexto(true);
						if (yyvsp[-3].tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName(yyvsp[-4].tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo novos Labels
						string lblInicio = yyvsp[0].lblInicio;
						string lblFim = yyvsp[0].lblFim;

						// Imprimir Label de Inicio
						yyval.traducao = lbl(lblInicio);

						// Obter Tradução e Declaração da Expressão
						yyval.declaracao += yyvsp[-3].declaracao;
						yyval.traducao += yyvsp[-3].traducao;
						yyval.desalocacao = yyvsp[-3].desalocacao;

						// Negar Expressão
						string tmpExpNegada = nextTMP();
						yyval.declaracao += dcl(TK_TIPO_BOOL, tmpExpNegada);
						yyval.traducao += cmd(tmpExpNegada + " = !" + yyvsp[-3].label);

						// Imprimir Salto Condicional para o Fim
						yyval.traducao += cmd("if (" + tmpExpNegada + ") goto " + lblFim);

						// Imprimir Bloco
						yyval.declaracao += yyvsp[0].declaracao;
						yyval.traducao += yyvsp[0].traducao;
						yyval.desalocacao += yyvsp[0].desalocacao;

						// Imprimir Salto Incondicional para o Inicio
						yyval.traducao += cmd("goto " + lblInicio);

						// Imprimir Label de Fim
						yyval.traducao += lbl(lblFim);

					}
#line 3150 "y.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 1514 "sintatica.y" /* yacc.c:1652  */
    {proximoContexto = TK_CTX_WHILE;}
#line 3156 "y.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 1515 "sintatica.y" /* yacc.c:1652  */
    {
						if (yyvsp[-1].tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName(yyvsp[-1].tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo Label Inicio
						string lblInicio = yyvsp[-4].lblInicio;
						string lblFim = yyvsp[-4].lblFim;

						// Imprimindo Label Inicio
						yyval.traducao = lbl(lblInicio);

						// Imprimir Bloco
						yyval.declaracao = yyvsp[-4].declaracao;
						yyval.traducao += yyvsp[-4].traducao;
						yyval.desalocacao = yyvsp[-4].desalocacao;

						// Imprimir Expressão
						yyval.declaracao += yyvsp[-1].declaracao;
						yyval.traducao += yyvsp[-1].traducao;
						yyval.desalocacao += yyvsp[-1].desalocacao;

						// Imprimir Salto Condicional para Label Inicio
						yyval.traducao += cmd("if (" + yyvsp[-1].label + ") goto " + lblInicio);

						// Imprimindo Label Fim
						yyval.traducao += lbl(lblFim);
					}
#line 3190 "y.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 1547 "sintatica.y" /* yacc.c:1652  */
    {
						empilharContexto(TK_CTX_FOR);
					}
#line 3198 "y.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 1551 "sintatica.y" /* yacc.c:1652  */
    {
						if (yyvsp[-4].tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName(yyvsp[-7].tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo Label Inicio e Fim
						string lblInicioIt = nextLBL();					// Cria um label para o inicio da iteração
						string lblFimIt = contextoAtual->lblInicio;		// Uso o label do inicio do bloco no fim da iteracao -- CONTINUE
						string lblFim = contextoAtual->lblFim;			// Pego o label Fim do bloco FOR exterior (fim do laço) -- BREAK

						desempilharContexto();

						// Imprimindo Expressão 1
						yyval.declaracao = yyvsp[-6].declaracao;
						yyval.traducao = yyvsp[-6].traducao;
						yyval.desalocacao = yyvsp[-6].desalocacao;

						// Imprimindo Label Inicio Iteracao
						yyval.traducao += lbl(lblInicioIt);

						// Imprimindo Expressao 2
						yyval.declaracao += yyvsp[-4].declaracao;
						yyval.traducao += yyvsp[-4].traducao;
						yyval.desalocacao = yyvsp[-4].desalocacao;

						// Negando Expressao 2
						string tmpExpNegada = nextTMP();
						yyval.declaracao += dcl(TK_TIPO_BOOL, tmpExpNegada);
						yyval.traducao += cmd(tmpExpNegada + " = !" + yyvsp[-4].label);

						// Imprimir Salto Condicional para Label Fim
						yyval.traducao += cmd("if (" + tmpExpNegada + ") goto " + lblFim);

						// Imprimir Bloco
						yyval.declaracao += yyvsp[0].declaracao;
						yyval.traducao += yyvsp[0].traducao;
						yyval.desalocacao += yyvsp[0].desalocacao;

						// Imprimir label Fim Iteracao
						yyval.traducao += lbl(lblFimIt);

						// Imprimir Expressao 3
						yyval.declaracao += yyvsp[-2].declaracao;
						yyval.traducao += yyvsp[-2].traducao;
						yyval.desalocacao += yyvsp[-8].desalocacao;

						// Imprimir Salto Incondicional para Inicio
						yyval.traducao += cmd("goto " + lblInicioIt);

						// Imprimir Label Fim
						yyval.traducao += lbl(lblFim);
					}
#line 3256 "y.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 1607 "sintatica.y" /* yacc.c:1652  */
    {
						simbolo* s = getSimboloPilha(yyvsp[-1].label);

						if (s == NULL)
						{
							yyerror("Variável '" + yyvsp[-1].label + "' não declarada");
						}

						if (s->tipo == TK_TIPO_INDEFINIDO)
						{
							yyerror("Variável '" + yyvsp[-1].label + "' possui valor indefinido");
						}

						string lblFim = nextLBL();

						empilharAlternador(s->label, lblFim, s->tipo);
					}
#line 3278 "y.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 1625 "sintatica.y" /* yacc.c:1652  */
    {
						string lblAux = alternador_atual->lblDefault == ""? alternador_atual->lblFim : alternador_atual->lblDefault;

						yyval.declaracao = yyvsp[-1].declaracao;
						yyval.traducao = yyvsp[-1].traducaoAlternativa;
						yyval.traducao += cmd("goto " + lblAux);
						yyval.traducao += yyvsp[-1].traducao;
						yyval.desalocacao = yyvsp[-1].desalocacao;

						yyval.traducao += lbl(alternador_atual->lblFim);
						desempilharAlternador();
					}
#line 3295 "y.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 1640 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[-1].declaracao + yyvsp[0].declaracao;
						yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;

						yyval.tipo += yyvsp[0].tipo;
						yyval.traducaoAlternativa += yyvsp[0].traducaoAlternativa;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 3308 "y.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 1649 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = "";
						yyval.traducao = "";
						yyval.desalocacao = "";
					}
#line 3318 "y.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 1657 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducaoAlternativa = "";
						yyval.traducao = "";
						yyval.declaracao = yyvsp[0].declaracao;

						// Definir Label do Case
						string lblCase = nextLBL();

						// Definir Temporária para igualdade
						string tmpIgualdade = nextTMP();

						// Imprimir Expressao (Será impresso no início do Switch, antes dos blocos Case e Default)
						yyval.traducaoAlternativa += yyvsp[-1].traducao;
						yyval.declaracao += yyvsp[-1].declaracao;
						yyval.desalocacao = yyvsp[-1].desalocacao;

						// Verificar e Converter tipos
						converterTipo(&yyval, alternador_atual->tipo, &yyvsp[-1], true);
						yyval.tipo = yyvsp[-1].tipo;

						// Declarar Temporária para igualdade
						yyval.declaracao += dcl(TK_TIPO_BOOL, tmpIgualdade);

						// Imprimir Tradução Antecipada (Será impresso no início do Switch, antes dos blocos Case e Default)
						yyval.traducaoAlternativa += cmd(tmpIgualdade + " = " + yyvsp[-1].label + " == " + alternador_atual->label);
						yyval.traducaoAlternativa += cmd("if (" + tmpIgualdade + ") goto " + lblCase);

						// Imprimir Label do Case
						yyval.traducao += lbl(lblCase);

						// Imprimir Bloco
						yyval.traducao += yyvsp[0].traducao;
						yyval.declaracao += yyvsp[0].declaracao;
						yyval.desalocacao += yyvsp[0].desalocacao;

						// Imprimir Goto Fim do Switch
						yyval.traducao += cmd("goto " + alternador_atual->lblFim);

					}
#line 3362 "y.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 1697 "sintatica.y" /* yacc.c:1652  */
    {
						string lblDefault = nextLBL();
						yyval.traducao = lbl(lblDefault) + yyvsp[0].traducao;
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.desalocacao += yyvsp[0].desalocacao;

						alternador_atual->lblDefault = lblDefault;
					}
#line 3375 "y.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 1708 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.declaracao = yyvsp[-1].declaracao;
						yyval.traducao = yyvsp[-1].traducao;
						yyval.desalocacao = yyvsp[-1].desalocacao;

						yyval.tipo = yyvsp[-1].tipo;

						if (funcaoAtual == NULL) yyerror("Comando Inválido.");

						if (funcaoAtual->tipo == TK_TIPO_VOID) funcaoAtual->tipo = yyval.tipo;
						else if (funcaoAtual->tipo != yyval.tipo) yyerror("Impossivel converter (" + typeName(funcaoAtual->tipo, true) + ") para (" + typeName(yyval.tipo, true) + ").");

						yyval.traducao += cmd("return " + yyvsp[-1].label);
					}
#line 3394 "y.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 1725 "sintatica.y" /* yacc.c:1652  */
    {
						Contexto* laco = procurarContextoLaco();
						yyval.traducao = cmd("goto " + laco->lblFim);
						//desempilharContextoAte(laco);
					}
#line 3404 "y.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 1733 "sintatica.y" /* yacc.c:1652  */
    {
						Contexto* laco = procurarContextoLaco();
						yyval.traducao = cmd("goto " + laco->lblInicio);
					}
#line 3413 "y.tab.c" /* yacc.c:1652  */
    break;

  case 105:
#line 1739 "sintatica.y" /* yacc.c:1652  */
    { auxFuncao = getFuncao(yyvsp[-1].label); }
#line 3419 "y.tab.c" /* yacc.c:1652  */
    break;

  case 106:
#line 1740 "sintatica.y" /* yacc.c:1652  */
    {
						if (!isFunDeclared(yyvsp[-5].label))
						{
							yyerror("Função (" + yyvsp[-5].label + ") não definida.");
						}

						int qntArgs = yyvsp[-2].indexLista + 1;

						if (auxFuncao->tipoParam.size() != qntArgs)
						{
							yyerror("Foram passados " + to_string(qntArgs) + " argumento(s). A Função '" + yyvsp[-5].label + "' requer " + to_string(auxFuncao->tipoParam.size()) + " argumento(s).");
						}

						yyval.tipo = ListaDeFuncoes[yyvsp[-5].label].tipo;

						yyval.declaracao = yyvsp[-2].declaracao;

						yyval.traducao = yyvsp[-2].traducao;
						yyval.traducao += cmd(ListaDeFuncoes[yyvsp[-5].label].identificador + "(" + yyvsp[-2].label + ")");

						yyval.desalocacao = yyvsp[-2].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico;
						yyval.tamanho = 0;
					}
#line 3448 "y.tab.c" /* yacc.c:1652  */
    break;

  case 107:
#line 1765 "sintatica.y" /* yacc.c:1652  */
    {
						if (!isFunDeclared(yyvsp[-3].label))
						{
							yyerror("Função (" + yyvsp[-3].label + ") não definida.");
						}

						if (ListaDeFuncoes[yyvsp[-3].label].tipoParam.size() != 0)
						{
							yyerror("Foram passados 0 argumento(s). A Função '" + yyvsp[-3].label + "' requer " + to_string(ListaDeFuncoes[yyvsp[-3].label].tipoParam.size()) + " argumento(s).");
						}

						yyval.tipo = ListaDeFuncoes[yyvsp[-3].label].tipo;
						yyval.traducao = cmd(ListaDeFuncoes[yyvsp[-3].label].identificador + "()");

						yyval.tamanho = 0;
					}
#line 3469 "y.tab.c" /* yacc.c:1652  */
    break;

  case 108:
#line 1784 "sintatica.y" /* yacc.c:1652  */
    {
						/*
						if ($3.tipo != TK_TIPO_STRING && $3.tipo != TK_TIPO_CHAR)
						{
							yyerror("Expressão esperada do tipo (" + typeName(TK_TIPO_STRING, true) + ").");
						}
						*/
						int tipo = (yyvsp[-2].tipo != TK_TIPO_VETOR)? yyvsp[-2].tipo : getSimboloPilha(yyvsp[-2].identificador)->tipoElemento;

						char aux;

						switch (tipo)
						{
							case TK_TIPO_INT: aux = 'd'; break;
							case TK_TIPO_FLOAT: aux = 'f'; break;
							case TK_TIPO_CHAR: aux = 'c'; break;
							case TK_TIPO_BOOL: aux = 'd'; break;
							case TK_TIPO_STRING: aux = 's'; break;
							default: aux = 's'; break;
						}

						if (yyvsp[-2].tipo != TK_TIPO_VETOR)
						{
							// Imprimir declaracao e tradução da Expressão
							yyval.traducao = yyvsp[-2].traducao;
							yyval.declaracao = yyvsp[-2].declaracao;
							yyval.desalocacao = yyvsp[-2].desalocacao;

							// Imprimir comando de saida
							yyval.traducao += cmd((string)"printf(\"\%" + aux + "\", " + yyvsp[-2].label + ")");
						}
						else
						{
							yyval.traducao = yyvsp[-2].traducao;
							yyval.declaracao = yyvsp[-2].declaracao;
							yyval.desalocacao = yyvsp[-2].desalocacao;

							string tmpPointeiro = nextTMP();
							string tmpI = nextTMP();

							yyval.declaracao += dcl(TK_TIPO_INT, tmpI);
							if (tipo != TK_TIPO_INDEFINIDO)
								yyval.declaracao += dcl(tipo, tmpPointeiro, "*");

							yyval.traducao += cmd("printf(\"(\")");


							for (int i = 0; i < yyvsp[-2].tamanho; i++)
							{
								yyval.traducao += cmd(tmpI + " = " + to_string(i));

								if (tipo != TK_TIPO_INDEFINIDO)
									yyval.traducao += cmd(tmpPointeiro + " = " + yyvsp[-2].label + "[" + tmpI + "]");

								if (tipo != TK_TIPO_STRING && tipo != TK_TIPO_INDEFINIDO)
								{
									yyval.traducao += cmd((string)"printf(\"%" + aux + "\", *" + tmpPointeiro + ")");
								}
								else if (tipo == TK_TIPO_INDEFINIDO)
								{
									yyval.traducao += cmd((string)"printf(\"?\")");
								}
								else 
								{
									yyval.traducao += cmd((string)"printf(\"%" + aux + "\", *" + tmpPointeiro + ")");
								}

								if (i < yyvsp[-2].tamanho - 1)
								{
									yyval.traducao += cmd("printf(\", \")");
								}
							}

							yyval.traducao += cmd("printf(\")\")");
						}
					}
#line 3550 "y.tab.c" /* yacc.c:1652  */
    break;

  case 109:
#line 1863 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = "<";
					}
#line 3558 "y.tab.c" /* yacc.c:1652  */
    break;

  case 110:
#line 1867 "sintatica.y" /* yacc.c:1652  */
    {
						yyval.traducao = ">";
					}
#line 3566 "y.tab.c" /* yacc.c:1652  */
    break;


#line 3570 "y.tab.c" /* yacc.c:1652  */
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
#line 1874 "sintatica.y" /* yacc.c:1918  */


#include "lex.yy.c"

						/*	TK_TIPO_INDEFINIDO	, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_TIPO_BOOL		, TK_TIPO_STRING	*/
int tab_conversao[6][6] = 	{	
							{TK_TIPO_INDEFINIDO	, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_TIPO_BOOL		, TK_ERROR			}, /* TK_TIPO_INDEFINIDO 	*/
							{TK_ERROR			, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_INT 			*/
							{TK_ERROR			, TK_TIPO_FLOAT		, TK_TIPO_FLOAT		, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_FLOAT 		*/
							{TK_ERROR			, TK_TIPO_CHAR		, TK_ERROR			, TK_TIPO_CHAR		, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_CHAR 			*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_TIPO_BOOL		, TK_ERROR			}, /* TK_TIPO_BOOL 			*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_TIPO_STRING	}, /* TK_TIPO_STRING		*/
							};

						/*	TK_TIPO_INDEFINIDO	, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_TIPO_BOOL		, TK_TIPO_STRING	*/
int tab_op_soma[6][6] = 	{	
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_INDEFINIDO 	*/
							{TK_ERROR			, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_INT 			*/
							{TK_ERROR			, TK_TIPO_FLOAT		, TK_TIPO_FLOAT		, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_FLOAT 		*/
							{TK_ERROR			, TK_TIPO_CHAR		, TK_ERROR			, TK_TIPO_CHAR		, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_CHAR 			*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_BOOL 			*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_TIPO_STRING	}, /* TK_TIPO_STRING		*/
							};

						/*	TK_TIPO_INDEFINIDO	, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_TIPO_BOOL		, TK_TIPO_STRING	*/
int tab_op_sub[6][6] = 		{	
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_INDEFINIDO 	*/
							{TK_ERROR			, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_INT 			*/
							{TK_ERROR			, TK_TIPO_FLOAT		, TK_TIPO_FLOAT		, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_FLOAT 		*/
							{TK_ERROR			, TK_TIPO_CHAR		, TK_ERROR			, TK_TIPO_CHAR		, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_CHAR 			*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_BOOL 			*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_STRING		*/
							};

						/*	TK_TIPO_INDEFINIDO	, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_TIPO_BOOL		, TK_TIPO_STRING	*/
int tab_op_mult[6][6] = 	{	
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_INDEFINIDO 	*/
							{TK_ERROR			, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_INT 			*/
							{TK_ERROR			, TK_TIPO_FLOAT		, TK_TIPO_FLOAT		, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_FLOAT 		*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_CHAR 			*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_BOOL 			*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_STRING		*/
							};

						/*	TK_TIPO_INDEFINIDO	, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_TIPO_BOOL		, TK_TIPO_STRING	*/
int tab_op_div[6][6] = 		{	
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_INDEFINIDO 	*/
							{TK_ERROR			, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_INT 			*/
							{TK_ERROR			, TK_TIPO_FLOAT		, TK_TIPO_FLOAT		, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_FLOAT 		*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_CHAR 			*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_BOOL 			*/
							{TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_STRING		*/
							};

int yyparse();

int main( int argc, char* argv[] )
{
	empilharContexto(TK_CTX_BLOCO);
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
		case TK_TIPO_STRING:	str = (debug)? "string" : "char*";	break;
		case TK_TIPO_VETOR:		str = (debug)? "vetor" : "void**";	break;
		case TK_TIPO_VOID:		str = "void";						break;
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

int tabelaOperadores (int tipo1, char op, int tipo2)
{
	int x = tipo1 - TK_TIPO_INDEFINIDO;
	int y = tipo2 - TK_TIPO_INDEFINIDO;

	int tipo = TK_ERROR;

	switch (op)
	{
		case '+':
			tipo = tab_op_soma[x][y];
			break;
		case '*':
			tipo = tab_op_mult[x][y];
			break;
		case '-':
			tipo = tab_op_sub[x][y];
			break;
		case '/':
			tipo = tab_op_div[x][y];
			break;
		default:
			tipo = tab_conversao[x][y];
			break;
	}

	if (tipo == TK_ERROR)
	{
		string auxOp = (op != ' ')? (string)"[" + op + "] " : "";
		yyerror((string)"Operação inválida " + auxOp + (string)"entre (" + typeName(tipo1, true) + ") e (" + typeName(tipo2, true) + ").");
	}

	return tipo;
}

int verificarTipos (int type1, int type2, int *x, char op)
{
	*x = 0;

	int newType = tabelaOperadores(type1, op, type2);

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

int converterTipos (atributos* $$, atributos* $1, atributos* $2, char op, int forceType)
{
	int out;
	int numTipo = verificarTipos($1->tipo, $2->tipo, &out, op);
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

void converterTipo(atributos* $$, int tipo, atributos* $1, bool antecipado)
{
	int out;
	int novoTipo = verificarTipos(tipo, $1->tipo, &out);
	checkTypes(tipo, novoTipo);

	if (out == 2){
		string tmp = nextTMP();
		$$->declaracao += dcl(tipo, tmp);

		if (!antecipado)
		{
			$$->traducao += cst(tmp, tipo, $1->label);
		}
		else
		{
			$$->traducaoAlternativa += cst(tmp, tipo, $1->label);
		}
		
		$1->label = tmp;
	}
}

void checkLabel(string s)
{
	simbolo* simbolo = getSimboloPilha(s);

	if (simbolo == NULL)
	{
		yyerror("Variável '" + s + "' nao foi declarada."); 
	}
	else
	{
		//cout << "\n [LINHA " << to_string(linha) << "]\n | Variavel declarada encontrada '" << busca->first << "' (" << "typeName(busca->second.tipo)" << ").\n";
	}
}

string cmd (string s)
{
	return "\t" + s + ";" + "\n";
}

string dcl (int tipo, string label, string prefixo)
{
	return cmd(typeName(tipo) + prefixo + "\t" + label);
}

string lbl (string label)
{
	return '\t' + label + ":\n";
}

string cst (string label1, int tipo, string label2)
{
	return cmd(label1 + " = " + "(" + typeName(tipo) + ")" + label2);
}

string dclVetor(int numTipo, string label, string labelContador)
{
	string tipo = typeName(numTipo);
	return cmd(label + " = " + "(void**)malloc(sizeof(void*) * " + labelContador + ")");
}

void setTipo(string id, int tipo)
{
	getSimboloPilha(id)->tipo = tipo;
}


int getTipo(string id)
{
	return getSimboloPilha(id)->tipo;
}

string getLabel(string id)
{
	return getSimboloPilha(id)->label;
}

bool isDeclared(string id)
{
	return getSimboloPilha(id) != NULL;
}

void novoSimbolo(string id, string lbl, int tipo, int tamanho, string tmpTamanho, int tipoElemento)
{
	simbolo novoSimbolo;

	if (tipoElemento == -1) tipoElemento = TK_TIPO_INDEFINIDO;

	novoSimbolo.label = lbl;
	novoSimbolo.tipo = tipo;
	novoSimbolo.tmpTamanho = tmpTamanho;
	novoSimbolo.tamanho = tamanho;
	novoSimbolo.tipoElemento = tipoElemento;

	addSimbolo(id, novoSimbolo);
}

void imprimirContexto(bool exibirLBL)
{
	unordered_map<string, simbolo>:: iterator itr;
	Contexto* aux = contextoAtual;

	cout << "\n== Pilha de Contexto ======== \n"; 

	while (aux != NULL){
		if (exibirLBL)
		{
			cout << " - inicio: " << aux->lblInicio << "\n";
			cout << " - fim   : " << aux->lblFim << "\n\n";
		}

	    for (itr = aux->simbolos.begin(); itr != aux->simbolos.end(); itr++) 
	    { 
	        cout << "   " << itr->first << " : " << itr->second.label << "\t(" << typeName(itr->second.tipo) << ")";
	        cout << "  [" + itr->second.tmpTamanho + "]\n";
	    }

	    cout << "-----------------------------\n"; 
	    aux = aux->anterior;
	}
}

vector<string> split(string s, char c)
{
	vector<string> aux;
	vector<string>::iterator it;

	it = aux.begin();

	string palavra = "";
	int i = 0;

	while (i < s.size())
	{
		if (s[i] != c)
		{
			palavra += s[i];
		}
		else
		{
			if (palavra != "")
			{
				it = aux.insert(it, palavra);
				palavra = "";
			}
		}

		i++;
	}

	return aux;
}

Contexto* novoContexto()
{
	Contexto* novoCtx = new Contexto();

	novoCtx->anterior = NULL;

	return novoCtx;
}

void empilharContexto(int tipo, string inicio, string fim)
{
	espacamentoDeIndexacao.append("\t");

	Contexto* novoCtx = novoContexto();

	if (proximoContexto != 0)
	{
		novoCtx->tipo = proximoContexto;
		proximoContexto = 0;
	}
	else
	{
		novoCtx->tipo = tipo;
	}

	novoCtx->anterior = contextoAtual;
	novoCtx->lblInicio = inicio != ""? inicio : nextLBL();
	novoCtx->lblFim = fim != ""? fim : nextLBL();

	contextoAtual = novoCtx;
}

void desempilharContexto()
{

	//espacamentoDeIndexacao = espacamentoDeIndexacao.substr(0, espacamentoDeIndexacao.size() - 1);

	if (contextoAtual->anterior != NULL)
	{
		Contexto* aux = contextoAtual->anterior;
		free(contextoAtual);
		contextoAtual = aux;
	}
}

Contexto* procurarContextoLaco()
{
	Contexto* it = contextoAtual;

	while (it != NULL)
	{
		if (it->tipo == TK_CTX_WHILE || it->tipo == TK_CTX_FOR)
		{
			return it;
		}
		else
		{
			it = it->anterior;
		}
	}

	yyerror("Não foi possivel encontrar um laço.");
	return NULL;
}

void desempilharContextoAte(Contexto* c)
{
	while (contextoAtual != c)
	{
		desempilharContexto();
	}

	desempilharContexto();
}

void addSimbolo(string id, simbolo s)
{
	contextoAtual->simbolos[id] = s;
}

simbolo* getSimbolo(string id, Contexto* contexto)
{
	if (contexto == NULL)
	{
		contexto = contextoAtual;
	}

	if (contexto->simbolos.find(id) != contexto->simbolos.end())
	{
		return &(contexto->simbolos[id]);
	} 
	else 
	{
		return NULL;
	}
}

funcao* getFuncao(string identificador)
{
	if (ListaDeFuncoes.find(identificador) != ListaDeFuncoes.end())
	{
		return &(ListaDeFuncoes[identificador]);
	}

	return NULL;
}

bool isFunDeclared(string identificador)
{
	return getFuncao(identificador) != NULL; 
}

simbolo* getSimboloPilha(string id)
{
	Contexto* it = contextoAtual;

	while (it != NULL)
	{
		simbolo* s = getSimbolo(id, it);

		if (s != NULL)
		{
			return s;
		}
		else
		{
			it = it->anterior;
		}
	}


	//yyerror("Variável '" + id + "' nao declarada.");
	return NULL;
}

void empilharAlternador(string s, string lblFim, int tipo)
{
	Pilha_alternador* alternador = new Pilha_alternador();
	alternador->tipo = tipo;
	alternador->label = s;
	alternador->lblFim = lblFim;
	alternador->lblDefault = "";
	alternador->anterior = alternador_atual;

	alternador_atual = alternador;

	//cout << "empilhei na linha " << linha << " (" << s << ", " << lblFim <<")\n";
}

void desempilharAlternador()
{
	if (alternador_atual != NULL)
	{
		Pilha_alternador* aux = alternador_atual->anterior;
		free(alternador_atual);
		alternador_atual = aux;

		//if (alternador_atual != NULL) cout << "desempilhei agora sou na linha " << linha << " (" << alternador_atual->label << ", " << alternador_atual->lblFim <<")\n";
	}
	else
	{
		cout << "=== AVISO\nTentativa de desempilhar alternador vazio.\n";
	}
}

void declararString(atributos* $$, string s, bool antecipado)
{
	//$$->label = nextTMP();
	$$->tipo = TK_TIPO_STRING;
	//$$->declaracao = dcl($$->tipo, $$->label);
	$$->tamanho = tamanhoString(s) - 2;			// Necessário remover "" da contagem
	$$->traducao = s;
	//$$->traducao = cmd($$->label + " = (char*)malloc(sizeof(char) * " + to_string($$->tamanho) + ")");
}

int tamanhoString(string s)
{
	int i = 0;
	int count = 0;

	while (s[i] != '\0')
	{
		count++;
		i++;
	}

	return count;
}

string valorPadrao(int tipo)
{
	string aux = "";

	switch (tipo){
		case TK_TIPO_INT:			aux = "0"; 		break;
		case TK_TIPO_FLOAT:			aux = "0.0";	break;
		case TK_TIPO_CHAR:			aux = "' '"; 	break;
		case TK_TIPO_STRING:		aux = "\"\""; 	break;
		default:					aux = "";  		break;
	}

	return aux;
}

void empilharNovaFuncao(string label)
{
	funcao novaFuncao;
	novaFuncao.tipo = TK_TIPO_VOID;
	novaFuncao.identificador = nextLBL();

	novaFuncao.argumentosPassados = 0;

	ListaDeFuncoes[label] = novaFuncao;
	funcaoAtual = &(ListaDeFuncoes[label]);
}

void addFuncao(string label, funcao* f)
{
	cout << "epilhei" << label << " -- " << typeName(funcaoAtual->tipo) << "\n";
	ListaDeFuncoes[label] = *f;
}

void definirRetornoFuncao(int tipo)
{
	if (funcaoAtual == NULL) yyerror("Não era pra isso ter acontecido!");

	funcaoAtual->tipo = tipo;
}

void printVector(vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++)
		cout << typeName(input.at(i)) << ' ';
}
