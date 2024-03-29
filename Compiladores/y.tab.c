/* A Bison parser, made by GNU Bison 3.4.1.  */

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
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatica.y"

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


#line 230 "y.tab.c"

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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  213

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
       0,   179,   179,   192,   191,   205,   208,   208,   223,   223,
     240,   247,   254,   255,   259,   266,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   293,
     299,   307,   312,   319,   338,   360,   374,   392,   420,   441,
     452,   468,   557,   617,   617,   645,   668,   669,   717,   718,
     741,   762,   783,   808,   809,   827,   828,   839,   840,   906,
     907,   917,   918,   928,   929,   939,   940,   950,   952,   994,
    1088,  1116,  1146,  1164,  1182,  1203,  1226,  1232,  1240,  1247,
    1255,  1270,  1302,  1326,  1338,  1356,  1387,  1425,  1425,  1468,
    1468,  1501,  1500,  1561,  1560,  1593,  1603,  1610,  1650,  1661,
    1678,  1686,  1693,  1693,  1718,  1737,  1816,  1820,  1824,  1825
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
  "COMANDO_EXTERNO", "COMANDOS", "COMANDO", "COMANDOS_FOR", "COMANDO_FOR",
  "LISTA_PARAM", "LISTA_DCL_PARAM", "EXP_SIMPLES", "$@4", "EXP_POSFIXA",
  "EXP_UNARIA", "EXP_NOT", "EXP_ARITMETICA_MUL", "EXP_ARITMETICA_ADD",
  "EXP_RELACIONAL", "EXP_IGUALDADE", "EXP_LOGICAL_AND", "EXP_LOGICAL_OR",
  "EXPRESSAO", "ATRIBUICAO", "CMD_UNARIO", "CMD_DECLARACOES",
  "LIST_DECLARACOES", "DECLARACAO", "DCL_ENDERECO", "CMD_IF", "CMD_WHILE",
  "$@5", "CMD_DOWHILE", "$@6", "CMD_FOR", "@7", "CMD_SWITCH", "$@8",
  "BLOCO_SWITCH", "EXP_CASE", "CMD_RETORNO", "CMD_BREAK", "CMD_CONTINUE",
  "CMD_FUNCAO", "$@9", "CMD_OUT", "OP_RELACIONAL", YY_NULLPTR
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

#define YYPACT_NINF -181

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-181)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      80,   143,    11,    36,   -13,    -8,  -181,  -181,    -7,    -5,
       2,     8,    62,    65,    19,  -181,    74,  -181,    75,    80,
    -181,   154,  -181,     7,    22,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,    28,    34,  -181,  -181,     8,
      35,     8,   -37,  -181,    37,    46,     8,     8,   117,    47,
      95,  -181,  -181,  -181,    48,    51,     8,     0,     0,     0,
      52,     8,  -181,   -23,  -181,  -181,    81,    85,    40,    96,
      93,    92,    57,  -181,  -181,     8,  -181,   120,  -181,  -181,
    -181,  -181,     8,     8,  -181,    59,     8,    60,     8,   135,
    -181,    11,    79,    82,    83,  -181,   129,  -181,    69,    88,
      89,     8,  -181,    86,    86,    86,    -3,    94,  -181,   138,
       8,     8,  -181,  -181,  -181,  -181,     8,     8,     8,     8,
    -181,    97,   100,  -181,  -181,  -181,   -39,  -181,    91,  -181,
     108,  -181,  -181,   145,   117,  -181,   154,   102,    14,    99,
    -181,  -181,     8,   104,   119,  -181,  -181,   113,  -181,    81,
      85,    40,    96,    93,   121,   122,   123,     8,     8,   124,
     117,   179,   125,   182,   117,   127,     8,     8,   132,   -26,
    -181,  -181,  -181,  -181,   117,  -181,  -181,  -181,  -181,  -181,
     130,   117,   117,  -181,  -181,   134,   133,  -181,  -181,  -181,
     145,  -181,  -181,  -181,    15,    -6,  -181,    70,   139,   136,
    -181,  -181,     8,   117,  -181,  -181,   117,    15,   117,  -181,
    -181,  -181,  -181
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     0,     0,     0,     0,    89,    91,     0,     0,
       0,     0,     0,     0,     0,    28,     0,    12,     0,    11,
      13,    15,    77,     0,     0,    19,    20,    21,    22,    23,
      18,    24,    25,    17,    26,     0,     0,    74,    75,     0,
     102,     0,    80,    76,    79,     0,     0,     0,     0,     0,
       0,   100,   101,    37,    38,     0,     0,     0,     0,     0,
       0,     0,    46,    48,    53,    55,    57,    59,    61,    63,
      65,    67,     0,    72,    73,     0,     1,     0,    10,    14,
      27,    16,     0,     0,    68,     0,     0,     0,     0,     0,
      82,     0,     8,     0,     0,     3,     0,     5,     0,     0,
      43,     0,    54,    49,    50,    51,     0,     0,    52,     0,
       0,     0,   108,   109,   106,   107,     0,     0,     0,     0,
      99,     0,     0,    70,    71,   104,     0,    34,     0,    81,
       0,    78,     6,     0,     0,    87,    15,     0,     0,     0,
      93,    45,     0,     0,     0,    42,    39,     0,    56,    58,
      60,    62,    64,    66,     0,     0,     0,     0,     0,    84,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
      40,    41,    47,   105,     0,   103,    33,    69,    83,     7,
      36,     0,     0,    88,     4,     0,     0,    96,    44,     2,
       0,     9,    86,    90,     0,     0,    35,     0,     0,    30,
      31,    32,     0,     0,    94,    95,     0,     0,     0,    98,
      92,    29,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -127,  -181,  -181,  -181,  -181,   181,  -181,   -19,
       1,    -9,  -181,    61,    17,  -181,  -181,   -34,  -181,   -50,
     101,    98,    87,    90,   103,  -181,   -11,  -180,  -176,   107,
     126,  -181,    54,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    96,   136,    17,   160,   133,    18,    19,    20,
      97,   198,   199,   126,   162,    62,   142,    63,    64,    65,
      66,    67,    68,    69,    70,    71,   127,    22,    23,    24,
      43,    44,    90,    25,    26,   164,    27,    48,    28,    49,
      29,   168,   195,   205,    30,    31,    32,    33,    86,    34,
     116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      72,    21,    79,    53,    54,   144,   102,   163,    55,   202,
     108,    53,    54,   203,   200,    42,    55,    88,   201,   197,
      21,   156,    21,   103,   104,   105,   157,   200,    84,    89,
      87,   201,    56,   179,   188,    93,    94,   183,    57,   157,
      45,    58,    59,   109,    35,    36,    46,   189,    12,    13,
     107,    47,    50,    60,   191,   192,   204,   145,    51,    61,
     148,    60,   112,   113,   121,    52,    73,    61,    39,    74,
      80,   123,   124,   138,    76,     2,   209,   129,    75,   210,
      41,   212,    82,    77,     1,    81,     2,     3,    83,     4,
     143,     5,     6,     7,     8,    85,     9,    10,    11,    99,
      35,    36,    91,    37,    38,    92,    98,   100,   114,   115,
     101,   106,   110,    12,    13,   111,   117,   165,   118,   119,
     120,     1,   125,     2,    39,   122,     4,   128,     5,     6,
       7,     8,    14,     9,    10,    11,    41,    21,   130,   132,
     137,   147,   134,   135,    15,   158,   176,   177,   140,   141,
      12,    13,   109,   161,   146,   185,   186,   154,     1,   155,
       2,   166,   167,     4,   170,     5,     6,     7,     8,    14,
       9,    10,    11,    35,    36,   159,    37,    38,    95,   171,
     172,    15,   174,   180,   173,   181,   175,    12,    13,   184,
      89,   208,   182,   187,   193,   190,   194,    39,   211,   206,
      78,   207,    40,   169,   151,   139,    14,   196,   152,    41,
       0,     0,   149,   178,   150,     0,     0,   131,    15,     0,
       0,     0,   153
};

static const yytype_int16 yycheck[] =
{
      11,     0,    21,     3,     4,     8,    56,   134,     8,    15,
      33,     3,     4,    19,   194,     4,     8,    54,   194,     4,
      19,    60,    21,    57,    58,    59,    65,   207,    39,    66,
      41,   207,    24,   160,    60,    46,    47,   164,    30,    65,
       4,    33,    34,    66,    30,    31,    59,   174,    33,    34,
      61,    59,    59,    53,   181,   182,    62,    60,    63,    59,
     110,    53,    22,    23,    75,    63,     4,    59,    54,     4,
      63,    82,    83,     4,     0,     6,   203,    88,    59,   206,
      66,   208,    54,     8,     4,    63,     6,     7,    54,     9,
     101,    11,    12,    13,    14,    60,    16,    17,    18,     4,
      30,    31,    65,    33,    34,    59,    59,    59,    68,    69,
      59,    59,    31,    33,    34,    30,    20,   136,    25,    27,
      63,     4,    63,     6,    54,     5,     9,    67,    11,    12,
      13,    14,    52,    16,    17,    18,    66,   136,     3,    60,
      11,     3,    60,    60,    64,    54,   157,   158,    60,    60,
      33,    34,    66,     8,    60,   166,   167,    60,     4,    59,
       6,    59,    63,     9,    60,    11,    12,    13,    14,    52,
      16,    17,    18,    30,    31,    67,    33,    34,    61,    60,
      67,    64,    60,     4,    63,    60,    63,    33,    34,    62,
      66,   202,    10,    61,    60,    65,    63,    54,   207,    60,
      19,    65,    59,   142,   117,    98,    52,   190,   118,    66,
      -1,    -1,   111,   159,   116,    -1,    -1,    91,    64,    -1,
      -1,    -1,   119
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     6,     7,     9,    11,    12,    13,    14,    16,
      17,    18,    33,    34,    52,    64,    71,    74,    77,    78,
      79,    80,    97,    98,    99,   103,   104,   106,   108,   110,
     114,   115,   116,   117,   119,    30,    31,    33,    34,    54,
      59,    66,     4,   100,   101,     4,    59,    59,   107,   109,
      59,    63,    63,     3,     4,     8,    24,    30,    33,    34,
      53,    59,    85,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     4,     4,    59,     0,     8,    77,    79,
      63,    63,    54,    54,    96,    60,   118,    96,    54,    66,
     102,    65,    59,    96,    96,    61,    72,    80,    59,     4,
      59,    59,    89,    87,    87,    87,    59,    96,    33,    66,
      31,    30,    22,    23,    68,    69,   120,    20,    25,    27,
      63,    96,     5,    96,    96,    63,    83,    96,    67,    96,
       3,   100,    60,    76,    60,    60,    73,    11,     4,    99,
      60,    60,    86,    96,     8,    60,    60,     3,    89,    90,
      91,    92,    93,    94,    60,    59,    60,    65,    54,    67,
      75,     8,    84,    72,   105,    79,    59,    63,   111,    83,
      60,    60,    67,    63,    60,    63,    96,    96,   102,    72,
       4,    60,    10,    72,    62,    96,    96,    61,    60,    72,
      65,    72,    72,    60,    63,   112,    84,     4,    81,    82,
      97,    98,    15,    19,    62,   113,    60,    65,    96,    72,
      72,    81,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    73,    72,    72,    75,    74,    76,    74,
      77,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    85,    85,
      85,    85,    85,    86,    85,    85,    87,    87,    88,    88,
      88,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    95,    96,    97,    97,
      97,    97,    98,    98,    98,    98,    99,    99,   100,   100,
     101,   101,   101,   102,   102,   103,   103,   105,   104,   107,
     106,   109,   108,   111,   110,   112,   112,   113,   113,   114,
     115,   116,   118,   117,   117,   119,   120,   120,   120,   120
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     4,     1,     0,     6,     0,     7,
       2,     0,     1,     1,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     1,     3,     1,     4,     2,     1,     1,     3,
       4,     4,     3,     0,     5,     3,     1,     4,     1,     2,
       2,     2,     2,     1,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     6,
       4,     4,     2,     2,     2,     2,     2,     1,     3,     1,
       1,     3,     2,     4,     3,     5,     7,     0,     6,     0,
       7,     0,    10,     0,     8,     2,     0,     3,     2,     3,
       2,     2,     0,     6,     4,     5,     1,     1,     1,     1
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
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
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
#line 180 "sintatica.y"
    {
						cout << "\n/*Compilador Ç*/\n";
						cout << "\n#include <stdio.h>";
						cout << "\n#include <stdlib.h>";
						cout << "\n#include <string.h>\n\n";
						cout << "#define true 1\n#define false 0\n\n";
						cout << yyvsp[-5].declaracao + "\n" << yyvsp[-5].traducao << yyvsp[-5].desalocacao;
						cout << "int main(void)\n{\n" << yyvsp[0].declaracao + "\n" + yyvsp[0].traducao + yyvsp[0].desalocacao << "\n\treturn 0;\n}\n";
					}
#line 1642 "y.tab.c"
    break;

  case 3:
#line 192 "sintatica.y"
    {
						yyvsp[0].lblInicio = contextoAtual->lblInicio;
						yyvsp[0].lblFim = contextoAtual->lblFim;
					}
#line 1651 "y.tab.c"
    break;

  case 4:
#line 197 "sintatica.y"
    {
						yyval.lblInicio = yyvsp[-3].lblInicio;
						yyval.lblFim = yyvsp[-3].lblFim;

						yyval.traducao = yyvsp[-1].traducao;
						yyval.declaracao = yyvsp[-1].declaracao;
						yyval.desalocacao = "\n" + yyvsp[-1].desalocacao;
					}
#line 1664 "y.tab.c"
    break;

  case 6:
#line 208 "sintatica.y"
    { empilharNovaFuncao(yyvsp[-2].label); }
#line 1670 "y.tab.c"
    break;

  case 7:
#line 209 "sintatica.y"
    {

						if (funcaoAtual == NULL) yyerror("NÃO ERA PRA ISSO TER ACONTECIDO AAAAA...");

						yyval.tipo = funcaoAtual->tipo;
						yyval.label = funcaoAtual->identificador;

						//addFuncao($2.label, funcaoAtual);

						yyval.declaracao = typeName(yyval.tipo) + " " + yyval.label + " ();\n";

						yyval.traducao = typeName(yyval.tipo) + " " + yyval.label + " ()\n{\n";
						yyval.traducao += yyvsp[0].declaracao + yyvsp[0].traducao + "\treturn;\n}\n\n";
					}
#line 1689 "y.tab.c"
    break;

  case 8:
#line 223 "sintatica.y"
    { empilharNovaFuncao(yyvsp[-1].label); empilharContexto(TK_CTX_BLOCO);}
#line 1695 "y.tab.c"
    break;

  case 9:
#line 224 "sintatica.y"
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
#line 1714 "y.tab.c"
    break;

  case 10:
#line 241 "sintatica.y"
    {
						yyval.declaracao = yyvsp[-1].declaracao + yyvsp[0].declaracao;
						yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[-1].desalocacao + yyvsp[0].desalocacao;
					}
#line 1724 "y.tab.c"
    break;

  case 11:
#line 247 "sintatica.y"
    {
						yyval.traducao = "";
						yyval.declaracao = "";
						yyval.desalocacao = "";
					}
#line 1734 "y.tab.c"
    break;

  case 14:
#line 260 "sintatica.y"
    {
						yyval.declaracao = yyvsp[-1].declaracao + yyvsp[0].declaracao;
						yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[-1].desalocacao + yyvsp[0].desalocacao;
					}
#line 1744 "y.tab.c"
    break;

  case 15:
#line 266 "sintatica.y"
    {
						yyval.traducao = "";
						yyval.declaracao = "";
						yyval.desalocacao = "";
					}
#line 1754 "y.tab.c"
    break;

  case 28:
#line 286 "sintatica.y"
    {
						yyval.traducao = "";
						yyval.declaracao = "";
						imprimirContexto(true);
					}
#line 1764 "y.tab.c"
    break;

  case 29:
#line 294 "sintatica.y"
    {
						yyval.declaracao = yyvsp[-2].declaracao + yyvsp[0].declaracao;
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
					}
#line 1774 "y.tab.c"
    break;

  case 30:
#line 300 "sintatica.y"
    {
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 1784 "y.tab.c"
    break;

  case 31:
#line 308 "sintatica.y"
    {
						yyval.traducao = yyvsp[0].traducao;
						yyval.declaracao = yyvsp[0].declaracao;
					}
#line 1793 "y.tab.c"
    break;

  case 32:
#line 313 "sintatica.y"
    {
						yyval.traducao = yyvsp[0].traducao;
						yyval.declaracao = yyvsp[0].declaracao;
					}
#line 1802 "y.tab.c"
    break;

  case 33:
#line 320 "sintatica.y"
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
#line 1825 "y.tab.c"
    break;

  case 34:
#line 339 "sintatica.y"
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
#line 1849 "y.tab.c"
    break;

  case 35:
#line 361 "sintatica.y"
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
#line 1867 "y.tab.c"
    break;

  case 36:
#line 375 "sintatica.y"
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
#line 1887 "y.tab.c"
    break;

  case 37:
#line 393 "sintatica.y"
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
#line 1919 "y.tab.c"
    break;

  case 38:
#line 421 "sintatica.y"
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
#line 1944 "y.tab.c"
    break;

  case 39:
#line 442 "sintatica.y"
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
#line 1959 "y.tab.c"
    break;

  case 40:
#line 453 "sintatica.y"
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
#line 1979 "y.tab.c"
    break;

  case 41:
#line 469 "sintatica.y"
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
#line 2072 "y.tab.c"
    break;

  case 42:
#line 558 "sintatica.y"
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
#line 2136 "y.tab.c"
    break;

  case 43:
#line 617 "sintatica.y"
    { auxFuncao = getFuncao(yyvsp[-1].label); }
#line 2142 "y.tab.c"
    break;

  case 44:
#line 618 "sintatica.y"
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
#line 2174 "y.tab.c"
    break;

  case 45:
#line 646 "sintatica.y"
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
#line 2199 "y.tab.c"
    break;

  case 47:
#line 670 "sintatica.y"
    {
						if (yyvsp[-3].identificador == "")
						{
							yyerror("Identificador esperado antes de '[ ]'.");
						}
						yyval.declaracao = yyvsp[-1].declaracao;
						yyval.traducao = yyvsp[-1].traducao;

						simbolo *smb = getSimboloPilha(yyvsp[-3].identificador);
						//$$.tipo = smb->tipo;
						yyval.tamanho = smb->tamanho;

						int tipoPosicao = smb->tipoElemento; // Pegar tipo da posição aqui

						if (tipoPosicao == TK_TIPO_INDEFINIDO)
						{
							yyerror("O vetor '" + yyvsp[-3].identificador +"' possui tipo indefinido.");
						}

						string tmp = nextTMP();
						string tmpPonteiroVoid = nextTMP();
						string tmpPonteiro = nextTMP();
						string tmpValor = nextTMP();

						yyval.declaracao += dcl(tipoPosicao, tmp);
						yyval.declaracao += dcl(TK_TIPO_VOID, tmpPonteiroVoid, "*");
						yyval.declaracao += dcl(tipoPosicao, tmpPonteiro, "*");
						yyval.declaracao += dcl(tipoPosicao, tmpValor);

						yyval.traducao += cmd(tmpPonteiroVoid + " = " + yyvsp[-3].label + "[" + yyvsp[-1].label + "]");
						yyval.traducao += cmd(tmpPonteiro + " = (" + typeName(tipoPosicao) + "*)" + tmpPonteiroVoid);
						
						if (tipoPosicao != TK_TIPO_STRING)
						{
							yyval.traducao += cmd(tmpValor + " = *" + tmpPonteiro);
							yyval.traducao += cmd(tmp + " = " + tmpValor);
						}
						else
						{
							yyval.traducao += cmd(tmp + " = " + tmpPonteiro);
						}

						yyval.tipo = tipoPosicao;
						yyval.label = tmp;
					}
#line 2249 "y.tab.c"
    break;

  case 49:
#line 719 "sintatica.y"
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
#line 2276 "y.tab.c"
    break;

  case 50:
#line 742 "sintatica.y"
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
#line 2301 "y.tab.c"
    break;

  case 51:
#line 763 "sintatica.y"
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
#line 2326 "y.tab.c"
    break;

  case 52:
#line 784 "sintatica.y"
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
#line 2353 "y.tab.c"
    break;

  case 54:
#line 810 "sintatica.y"
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
#line 2374 "y.tab.c"
    break;

  case 56:
#line 829 "sintatica.y"
    {
						yyval.label = nextTMP();
						converterTipos(&yyval, &yyvsp[-2], &yyvsp[0], yyvsp[-1].traducao[0]);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd (yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;
						yyval.tmpTamanho = yyvsp[-2].tmpTamanho;
					}
#line 2387 "y.tab.c"
    break;

  case 58:
#line 841 "sintatica.y"
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
#line 2455 "y.tab.c"
    break;

  case 60:
#line 908 "sintatica.y"
    {
						yyval.label = nextTMP();
						converterTipos(&yyval, &yyvsp[-2], &yyvsp[0], '>', TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;
					}
#line 2467 "y.tab.c"
    break;

  case 62:
#line 919 "sintatica.y"
    {
						yyval.label = nextTMP();
						converterTipos(&yyval, &yyvsp[-2], &yyvsp[0], '=', TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;
					}
#line 2479 "y.tab.c"
    break;

  case 64:
#line 930 "sintatica.y"
    {
						yyval.label = nextTMP();
						converterTipos(&yyval, &yyvsp[-2], &yyvsp[0], '&', TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;
					}
#line 2491 "y.tab.c"
    break;

  case 66:
#line 941 "sintatica.y"
    {
						yyval.label = nextTMP();
						converterTipos(&yyval, &yyvsp[-2], &yyvsp[0], '|', TK_TIPO_BOOL);
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + cmd(yyval.label + " = " + yyvsp[-2].label + " " + yyvsp[-1].traducao + " " + yyvsp[0].label);
						yyval.desalocacao = yyvsp[-2].desalocacao + yyvsp[0].desalocacao;
						yyval.dinamico = yyvsp[-2].dinamico || yyvsp[-1].dinamico;
					}
#line 2503 "y.tab.c"
    break;

  case 68:
#line 953 "sintatica.y"
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
#line 2549 "y.tab.c"
    break;

  case 69:
#line 995 "sintatica.y"
    {
						if (!isDeclared(yyvsp[-5].label))
						{
							yyerror("Vetor '" + yyvsp[-5].label + "' não declarado.");
						}

						simbolo *smb = getSimboloPilha(yyvsp[-5].label);

						string varVetor = smb->label;

						yyval.declaracao = yyvsp[0].declaracao;
						yyval.declaracao += yyvsp[-3].declaracao;

						yyval.traducao = yyvsp[0].traducao;
						yyval.traducao += yyvsp[-3].traducao;

						yyval.tamanho = smb->tamanho;
						yyvsp[-5].tipo = smb->tipo;
						yyvsp[-5].label = varVetor;

						if (yyvsp[-5].tipo != TK_TIPO_VETOR)
						{
							yyerror("Atribuicão Inválida.");
						}

						if (yyvsp[-3].tipo != TK_TIPO_INT)
						{
							yyerror("Esperado expressão (int)");
						}

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

						if (smb->tipoElemento != yyvsp[0].tipo)
						{
							yyerror("Atribuição incompatível com o tipo do vetor (" + typeName(smb->tipoElemento) + ").");
						}

						string tmpExpressao = nextTMP();
						string tmpPonteiro = nextTMP();

						yyval.declaracao += dcl(yyvsp[0].tipo, tmpExpressao);
						yyval.declaracao += dcl(TK_TIPO_INT, tmpPonteiro, "*");

						if (smb->tipoElemento != TK_TIPO_STRING)
						{
							yyval.traducao += cmd(tmpExpressao + " = " + yyvsp[0].label);
							yyval.traducao += cmd(tmpPonteiro + " = &" + tmpExpressao);
							yyval.traducao += cmd(yyvsp[-5].label + "[" + yyvsp[-3].label + "] = " + tmpPonteiro);
						}
						else
						{
							string tmpTamanho = nextTMP();

							yyval.declaracao += dcl(TK_TIPO_INT, tmpTamanho);
							yyval.traducao += cmd(tmpTamanho + " = " + to_string(yyvsp[0].tamanho));
							yyval.traducao += cmd(tmpPonteiro + " = " + yyvsp[-5].label + "[" + yyvsp[-3].label + "]");
							yyval.traducao += cmd(tmpPonteiro + " = (char*)realloc(" + tmpPonteiro + ", " + tmpTamanho + ")");
							yyval.traducao += cmd("strcpy(" + tmpPonteiro + ", " + yyvsp[0].label + ")");
						}

					}
#line 2647 "y.tab.c"
    break;

  case 70:
#line 1089 "sintatica.y"
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
#line 2679 "y.tab.c"
    break;

  case 71:
#line 1117 "sintatica.y"
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
#line 2711 "y.tab.c"
    break;

  case 72:
#line 1147 "sintatica.y"
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
#line 2733 "y.tab.c"
    break;

  case 73:
#line 1165 "sintatica.y"
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
#line 2755 "y.tab.c"
    break;

  case 74:
#line 1183 "sintatica.y"
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
#line 2780 "y.tab.c"
    break;

  case 75:
#line 1204 "sintatica.y"
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
#line 2805 "y.tab.c"
    break;

  case 76:
#line 1227 "sintatica.y"
    {
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 2815 "y.tab.c"
    break;

  case 77:
#line 1233 "sintatica.y"
    {
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 2825 "y.tab.c"
    break;

  case 78:
#line 1241 "sintatica.y"
    {
						//Tinha + $3 declaracao e traducao
						yyval.declaracao += yyvsp[0].declaracao;
						yyval.traducao += yyvsp[0].traducao;
						yyval.desalocacao += yyvsp[0].desalocacao;
					}
#line 2836 "y.tab.c"
    break;

  case 79:
#line 1248 "sintatica.y"
    {
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.traducao = yyvsp[0].traducao;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 2846 "y.tab.c"
    break;

  case 80:
#line 1256 "sintatica.y"
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
#line 2865 "y.tab.c"
    break;

  case 81:
#line 1271 "sintatica.y"
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
#line 2901 "y.tab.c"
    break;

  case 82:
#line 1303 "sintatica.y"
    {
						if (getSimbolo(yyvsp[-1].label, contextoAtual) != NULL)
							yyerror("Variável '" + yyvsp[-1].label + "' já foi declarada nesse contexto.");

						string varVetor = nextVAR();
						string tmpTamanho = nextTMP();
						int tamanhoVetor = yyvsp[0].tamanho;

						yyval.declaracao = dcl(TK_TIPO_VETOR, varVetor);
						yyval.declaracao += dcl(TK_TIPO_INT, tmpTamanho);

						yyval.traducao = cmd(tmpTamanho + " = " + to_string(yyvsp[0].tamanho));
						yyval.traducao += dclVetor(TK_TIPO_INDEFINIDO, varVetor, tmpTamanho);

						novoSimbolo(yyvsp[-1].label, varVetor, TK_TIPO_VETOR, tamanhoVetor);

						yyval.tipo = TK_TIPO_INDEFINIDO;
						yyval.tamanho = tamanhoVetor;

						//$$.desalocacao += cmd("free(" + varVetor +")"); 
					}
#line 2927 "y.tab.c"
    break;

  case 83:
#line 1327 "sintatica.y"
    {
						if (yyvsp[-2].tipo != TK_TIPO_INT)
							yyerror("Tipo int esperado para tamanho do vetor.");

						int tamanho = stoi(yyvsp[-2].traducao);

						if (tamanho < 1)
							yyerror("Um vetor deve ter tamanho >= 1.");

						yyval.tamanho = yyvsp[0].tamanho * tamanho;
					}
#line 2943 "y.tab.c"
    break;

  case 84:
#line 1339 "sintatica.y"
    {
						if (yyvsp[-1].tipo != TK_TIPO_INT)
							yyerror("Tipo int esperado para tamanho do vetor.");

						int tamanho = stoi(yyvsp[-1].traducao);

						if (tamanho < 1)
							yyerror("Um vetor deve ter tamanho >= 1.");

						yyval.tamanho = tamanho;

						yyval.traducao = "";
						yyval.declaracao = "";
						yyval.desalocacao = "";
					}
#line 2963 "y.tab.c"
    break;

  case 85:
#line 1357 "sintatica.y"
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
#line 2998 "y.tab.c"
    break;

  case 86:
#line 1388 "sintatica.y"
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
#line 3038 "y.tab.c"
    break;

  case 87:
#line 1425 "sintatica.y"
    { proximoContexto = TK_CTX_WHILE; }
#line 3044 "y.tab.c"
    break;

  case 88:
#line 1426 "sintatica.y"
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
#line 3089 "y.tab.c"
    break;

  case 89:
#line 1468 "sintatica.y"
    {proximoContexto = TK_CTX_WHILE;}
#line 3095 "y.tab.c"
    break;

  case 90:
#line 1469 "sintatica.y"
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
#line 3129 "y.tab.c"
    break;

  case 91:
#line 1501 "sintatica.y"
    {
						empilharContexto(TK_CTX_FOR);
					}
#line 3137 "y.tab.c"
    break;

  case 92:
#line 1505 "sintatica.y"
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
#line 3195 "y.tab.c"
    break;

  case 93:
#line 1561 "sintatica.y"
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
#line 3217 "y.tab.c"
    break;

  case 94:
#line 1579 "sintatica.y"
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
#line 3234 "y.tab.c"
    break;

  case 95:
#line 1594 "sintatica.y"
    {
						yyval.declaracao = yyvsp[-1].declaracao + yyvsp[0].declaracao;
						yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;

						yyval.tipo += yyvsp[0].tipo;
						yyval.traducaoAlternativa += yyvsp[0].traducaoAlternativa;
						yyval.desalocacao = yyvsp[0].desalocacao;
					}
#line 3247 "y.tab.c"
    break;

  case 96:
#line 1603 "sintatica.y"
    {
						yyval.declaracao = "";
						yyval.traducao = "";
						yyval.desalocacao = "";
					}
#line 3257 "y.tab.c"
    break;

  case 97:
#line 1611 "sintatica.y"
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
#line 3301 "y.tab.c"
    break;

  case 98:
#line 1651 "sintatica.y"
    {
						string lblDefault = nextLBL();
						yyval.traducao = lbl(lblDefault) + yyvsp[0].traducao;
						yyval.declaracao = yyvsp[0].declaracao;
						yyval.desalocacao += yyvsp[0].desalocacao;

						alternador_atual->lblDefault = lblDefault;
					}
#line 3314 "y.tab.c"
    break;

  case 99:
#line 1662 "sintatica.y"
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
#line 3333 "y.tab.c"
    break;

  case 100:
#line 1679 "sintatica.y"
    {
						Contexto* laco = procurarContextoLaco();
						yyval.traducao = cmd("goto " + laco->lblFim);
						//desempilharContextoAte(laco);
					}
#line 3343 "y.tab.c"
    break;

  case 101:
#line 1687 "sintatica.y"
    {
						Contexto* laco = procurarContextoLaco();
						yyval.traducao = cmd("goto " + laco->lblInicio);
					}
#line 3352 "y.tab.c"
    break;

  case 102:
#line 1693 "sintatica.y"
    { auxFuncao = getFuncao(yyvsp[-1].label); }
#line 3358 "y.tab.c"
    break;

  case 103:
#line 1694 "sintatica.y"
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
#line 3387 "y.tab.c"
    break;

  case 104:
#line 1719 "sintatica.y"
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
#line 3408 "y.tab.c"
    break;

  case 105:
#line 1738 "sintatica.y"
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
									yyval.traducao += cmd((string)"printf(\"%" + aux + "\", " + tmpPointeiro + ")");
								}

								if (i < yyvsp[-2].tamanho - 1)
								{
									yyval.traducao += cmd("printf(\", \")");
								}
							}

							yyval.traducao += cmd("printf(\")\")");
						}
					}
#line 3489 "y.tab.c"
    break;

  case 106:
#line 1817 "sintatica.y"
    {
						yyval.traducao = "<";
					}
#line 3497 "y.tab.c"
    break;

  case 107:
#line 1821 "sintatica.y"
    {
						yyval.traducao = ">";
					}
#line 3505 "y.tab.c"
    break;


#line 3509 "y.tab.c"

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
#line 1828 "sintatica.y"


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
