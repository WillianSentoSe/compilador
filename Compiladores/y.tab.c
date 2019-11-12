/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "sintatica.y" /* yacc.c:339  */

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>

#define YYSTYPE atributos
#define DISPLAY_COLOR true

using namespace std;

struct atributos {
	string label;
	string declaracao;
	string traducao;
	string desalocacao;
	int tipo;
	int tamanho;

	string traducaoAlternativa;

	string lblInicio;
	string lblFim;
};

struct simbolo {
	int tipo;
	string label;
};

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
string dcl(int, string);
string cst (string, int, string);
string lbl(string);

int tabelaOperadores (int, char, int);

void setTipo(string, int);
int getTipo(string);
int getClasse(string);
bool isAtivo(string);
string getLabel(string);
bool isDeclared(string);

vector<string> split(string, char);

void addSimbolo(string, simbolo);
void novoSimbolo(string, string, int);
simbolo* getSimbolo(string, Contexto* contexto = NULL);
simbolo* getSimboloPilha(string);

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

void declararString(atributos*, string, bool antecipado = false);
int tamanhoString(string);


#line 187 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
    TK_WHILE = 265,
    TK_DO = 266,
    TK_FOR = 267,
    TK_SWITCH = 268,
    TK_CASE = 269,
    TK_BREAK = 270,
    TK_CONTINUE = 271,
    TK_DEFAULT = 272,
    TK_OP_IGUALDADE = 273,
    TK_OP_DESIGUALDADE = 274,
    TK_OP_MAIORIGUAL = 275,
    TK_OP_MENORIGUAL = 276,
    TK_OP_NOT = 277,
    TK_OP_LOGICAL_AND = 278,
    TK_OP_AND = 279,
    TK_OP_LOGICAL_OR = 280,
    TK_OP_XOR = 281,
    TK_OP_IOR = 282,
    TK_OP_ADD = 283,
    TK_OP_MUL = 284,
    TK_OP_SUB = 285,
    TK_TIPO_INDEFINIDO = 286,
    TK_TIPO_INT = 287,
    TK_TIPO_FLOAT = 288,
    TK_TIPO_CHAR = 289,
    TK_TIPO_BOOL = 290,
    TK_TIPO_STRING = 291,
    TK_CLASSE_VARIAVEL = 292,
    TK_CLASSE_FUNCAO = 293,
    TK_FIM = 294,
    TK_ERROR = 295,
    TK_CTX_BLOCO = 296,
    TK_CTX_IF = 297,
    TK_CTX_WHILE = 298,
    TK_CTX_FOR = 299,
    TK_CTX_CASE = 300,
    TK_OUT = 301,
    TK_IN = 302
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
#define TK_WHILE 265
#define TK_DO 266
#define TK_FOR 267
#define TK_SWITCH 268
#define TK_CASE 269
#define TK_BREAK 270
#define TK_CONTINUE 271
#define TK_DEFAULT 272
#define TK_OP_IGUALDADE 273
#define TK_OP_DESIGUALDADE 274
#define TK_OP_MAIORIGUAL 275
#define TK_OP_MENORIGUAL 276
#define TK_OP_NOT 277
#define TK_OP_LOGICAL_AND 278
#define TK_OP_AND 279
#define TK_OP_LOGICAL_OR 280
#define TK_OP_XOR 281
#define TK_OP_IOR 282
#define TK_OP_ADD 283
#define TK_OP_MUL 284
#define TK_OP_SUB 285
#define TK_TIPO_INDEFINIDO 286
#define TK_TIPO_INT 287
#define TK_TIPO_FLOAT 288
#define TK_TIPO_CHAR 289
#define TK_TIPO_BOOL 290
#define TK_TIPO_STRING 291
#define TK_CLASSE_VARIAVEL 292
#define TK_CLASSE_FUNCAO 293
#define TK_FIM 294
#define TK_ERROR 295
#define TK_CTX_BLOCO 296
#define TK_CTX_IF 297
#define TK_CTX_WHILE 298
#define TK_CTX_FOR 299
#define TK_CTX_CASE 300
#define TK_OUT 301
#define TK_IN 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 332 "y.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   118

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    58,     2,     2,     2,     2,
      53,    54,    51,    49,    59,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
      60,    48,    61,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   151,   150,   166,   173,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   196,   202,   210,
     218,   244,   259,   267,   280,   367,   368,   391,   392,   408,
     409,   418,   419,   450,   451,   460,   461,   470,   471,   480,
     481,   490,   493,   531,   537,   545,   552,   560,   572,   591,
     622,   660,   660,   703,   703,   736,   735,   796,   795,   828,
     838,   845,   885,   896,   904,   911,   944,   948,   952,   953
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_LITERAL", "TK_ID", "TK_MAIN",
  "TK_VAR", "TK_TIPO", "TK_IF", "TK_ELSE", "TK_WHILE", "TK_DO", "TK_FOR",
  "TK_SWITCH", "TK_CASE", "TK_BREAK", "TK_CONTINUE", "TK_DEFAULT",
  "TK_OP_IGUALDADE", "TK_OP_DESIGUALDADE", "TK_OP_MAIORIGUAL",
  "TK_OP_MENORIGUAL", "TK_OP_NOT", "TK_OP_LOGICAL_AND", "TK_OP_AND",
  "TK_OP_LOGICAL_OR", "TK_OP_XOR", "TK_OP_IOR", "TK_OP_ADD", "TK_OP_MUL",
  "TK_OP_SUB", "TK_TIPO_INDEFINIDO", "TK_TIPO_INT", "TK_TIPO_FLOAT",
  "TK_TIPO_CHAR", "TK_TIPO_BOOL", "TK_TIPO_STRING", "TK_CLASSE_VARIAVEL",
  "TK_CLASSE_FUNCAO", "TK_FIM", "TK_ERROR", "TK_CTX_BLOCO", "TK_CTX_IF",
  "TK_CTX_WHILE", "TK_CTX_FOR", "TK_CTX_CASE", "TK_OUT", "TK_IN", "'='",
  "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'", "'#'",
  "','", "'<'", "'>'", "$accept", "S", "BLOCO", "$@1", "COMANDOS",
  "COMANDO", "COMANDOS_FOR", "COMANDO_FOR", "EXP_SIMPLES", "EXP_UNARIA",
  "EXP_NOT", "EXP_ARITMETICA_MUL", "EXP_ARITMETICA_ADD", "EXP_RELACIONAL",
  "EXP_IGUALDADE", "EXP_LOGICAL_AND", "EXP_LOGICAL_OR", "EXPRESSAO",
  "ATRIBUICAO", "CMD_DECLARACOES", "LIST_DECLARACOES", "DECLARACAO",
  "CMD_IF", "CMD_WHILE", "$@2", "CMD_DOWHILE", "$@3", "CMD_FOR", "$@4",
  "CMD_SWITCH", "$@5", "BLOCO_SWITCH", "EXP_CASE", "CMD_BREAK",
  "CMD_CONTINUE", "CMD_OUT", "OP_RELACIONAL", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,    61,    43,
      45,    42,    47,    40,    41,   123,   125,    59,    35,    44,
      60,    62
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       6,     1,    21,   -28,   -93,   -21,   -19,   -93,   -93,    -1,
      -9,    36,   -11,   -10,   -93,   -93,    -7,   -13,    -8,    -6,
     -93,    -4,    -1,   -93,    -3,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,    13,     0,   -93,     9,    13,    13,   -19,
       2,    46,   -93,   -93,    13,   -93,   -93,   -93,   -93,   -93,
      12,    13,    23,    16,    13,   -93,   -93,   -93,    24,    30,
       3,    38,    39,    34,   -93,    13,    36,    19,    25,    65,
      28,    26,    27,    13,   -93,   -93,    70,    29,    13,    13,
     -93,   -93,   -93,   -93,    13,    13,    13,    13,   -93,   -93,
     -19,   -93,    31,    37,   -93,    40,    32,    41,   -93,   -93,
      24,    30,     3,    38,    39,    69,   -19,    13,    13,    33,
     -93,   -93,   -93,   -19,   -93,    42,    43,   -93,   -93,   -93,
      78,     5,    44,    45,   -93,    13,   -19,   -93,   -93,   -19,
      78,   -19,   -93,   -93,   -93,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     3,     2,     6,
       0,     0,     0,     0,    53,    55,     0,     0,     0,     0,
      16,     0,     6,    44,     0,     8,     9,    10,    11,    12,
      13,    14,    15,     0,    47,    43,    46,     0,     0,     0,
       0,     0,    63,    64,     0,     4,     5,     7,    20,    21,
       0,     0,     0,     0,     0,    25,    27,    29,    31,    33,
      35,    37,    39,    41,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    26,     0,     0,     0,     0,
      68,    69,    66,    67,     0,     0,     0,     0,    48,    45,
       0,    51,     0,     0,    57,     0,     0,     0,    22,    30,
      32,    34,    36,    38,    40,    49,     0,     0,     0,     0,
      65,    23,    24,     0,    52,     0,     0,    60,    50,    54,
       0,     0,     0,    18,    19,     0,     0,    58,    59,     0,
       0,     0,    62,    56,    17,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -39,   -93,    63,   -93,   -37,   -93,    47,   -93,
     -47,    22,     7,    17,    20,    18,   -93,   -36,   -92,    48,
      49,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    21,    22,   122,   123,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    23,    24,
      35,    36,    25,    26,   106,    27,    39,    28,    40,    29,
     109,   121,   128,    30,    31,    32,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    67,    68,    10,    74,    11,     3,    12,    72,    13,
      14,    15,    16,     1,    17,    18,    48,    49,    77,   125,
      50,     4,   126,    80,    81,     5,    48,    49,   124,    88,
      50,    99,    10,     6,    11,    51,     7,    96,   124,    33,
      34,    52,    37,    38,    42,    19,    41,    44,    65,    43,
      71,   105,    45,    78,    47,    70,    85,    20,    79,    87,
      53,   127,    86,    82,    83,    73,    54,   114,    66,    76,
      53,   115,   116,    90,   118,    92,    54,    97,   113,    91,
      94,    95,    10,    98,   107,    46,   111,   132,   117,   131,
     133,   101,   135,   134,   108,   112,   119,   110,   129,    75,
     120,   100,   102,     0,   130,   104,   103,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,    93
};

static const yytype_int16 yycheck[] =
{
      39,    37,    38,     4,    51,     6,     5,     8,    44,    10,
      11,    12,    13,     7,    15,    16,     3,     4,    54,    14,
       7,     0,    17,    20,    21,    53,     3,     4,   120,    65,
       7,    78,     4,    54,     6,    22,    55,    73,   130,    48,
       4,    28,    53,    53,    57,    46,    53,    53,    48,    57,
       4,    90,    56,    29,    57,    53,    18,    58,    28,    25,
      47,    56,    23,    60,    61,    53,    53,   106,    59,    53,
      47,   107,   108,    54,   113,    10,    53,     7,     9,    54,
      54,    54,     4,    54,    53,    22,    54,   126,    55,   125,
     129,    84,   131,   130,    57,    54,    54,    57,    54,    52,
      57,    79,    85,    -1,    59,    87,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    63,     5,     0,    53,    54,    55,    64,    65,
       4,     6,     8,    10,    11,    12,    13,    15,    16,    46,
      58,    66,    67,    80,    81,    84,    85,    87,    89,    91,
      95,    96,    97,    48,     4,    82,    83,    53,    53,    88,
      90,    53,    57,    57,    53,    56,    66,    57,     3,     4,
       7,    22,    28,    47,    53,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    48,    59,    79,    79,    64,
      53,     4,    79,    53,    72,    70,    53,    79,    29,    28,
      20,    21,    60,    61,    98,    18,    23,    25,    79,    82,
      54,    54,    10,    81,    54,    54,    79,     7,    54,    72,
      73,    74,    75,    76,    77,    64,    86,    53,    57,    92,
      57,    54,    54,     9,    64,    79,    79,    55,    64,    54,
      57,    93,    68,    69,    80,    14,    17,    56,    94,    54,
      59,    79,    64,    64,    68,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    65,    64,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    86,    85,    88,    87,    90,    89,    92,    91,    93,
      93,    94,    94,    95,    96,    97,    98,    98,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     4,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     4,     4,     1,     2,     1,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     1,     3,     1,     1,     3,     5,
       7,     0,     6,     0,     7,     0,    10,     0,     8,     2,
       0,     3,     2,     2,     2,     5,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
| yyreduce -- Do a reduction.  |
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
#line 140 "sintatica.y" /* yacc.c:1646  */
    {
						cout << "\n/*Compilador Ç*/\n\n";
						cout << "\n#include <stdio.h>";
						cout << "\n#include <stdlib.h>";
						cout << "\n#include <string.h>\n\n";
						cout << "#define true 1\n#define false 0\n\n";
						cout << "int main(void)\n{\n" << (yyvsp[0]).declaracao + "\n" + (yyvsp[0]).traducao + (yyvsp[0]).desalocacao << "\n\treturn 0;\n}\n"; 
					}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 151 "sintatica.y" /* yacc.c:1646  */
    {
						(yyvsp[0]).lblInicio = contextoAtual->lblInicio;
						(yyvsp[0]).lblFim = contextoAtual->lblFim;
					}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 156 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).lblInicio = (yyvsp[-3]).lblInicio;
						(yyval).lblFim = (yyvsp[-3]).lblFim;

						(yyval).traducao = (yyvsp[-1]).traducao;
						(yyval).declaracao = (yyvsp[-1]).declaracao;
						//$$.desalocacao = "\n" + $3.desalocacao;
					}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 167 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).declaracao = (yyvsp[-1]).declaracao + (yyvsp[0]).declaracao;
						(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;
						//$$.desalocacao = $1.desalocacao + $2.desalocacao;
					}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 173 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducao = "";
						(yyval).declaracao = "";
					}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 189 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducao = "";
						(yyval).declaracao = "";
						imprimirContexto(true);
					}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 197 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).declaracao = (yyvsp[-2]).declaracao + (yyvsp[0]).declaracao;
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao;
						//$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 203 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).declaracao = (yyvsp[0]).declaracao;
						(yyval).traducao = (yyvsp[0]).traducao;
						//$$.desalocacao = $1.desalocacao;
					}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 211 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducao = (yyvsp[0]).traducao;
						(yyval).declaracao = (yyvsp[0]).declaracao;
					}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 219 "sintatica.y" /* yacc.c:1646  */
    {	
						// EXPERIMENTAL (ATRIBUICAO DIRETA)
						// $$.label = $1.traducao;
						// $$.traducao = "";

						(yyval).label = nextTMP();
						(yyval).declaracao = dcl((yyvsp[0]).tipo, (yyval).label);

						if ((yyvsp[0]).tipo != TK_TIPO_STRING)
						{
							(yyval).traducao = cmd((yyval).label + " = " + (yyvsp[0]).traducao);
						}
						else
						{
							int tamanho = (yyvsp[0]).tamanho + 1;						// Necessário incluir \0
							string s = (yyvsp[0]).traducao;
							int i = 0;

							(yyval).traducao = cmd((yyval).label + " = (char*) malloc(sizeof(char) * " + to_string(tamanho) + ")");
							(yyval).traducao += cmd((yyval).label + " = " + (yyvsp[0]).traducao);
							//$$.desalocacao = cmd("free(" + $$.label + ")");
						}

						(yyval).tipo = (yyvsp[0]).tipo;
					}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 245 "sintatica.y" /* yacc.c:1646  */
    {
						checkLabel((yyvsp[0]).label);
						(yyval).tipo = getTipo((yyvsp[0]).label);

						if ((yyval).tipo == TK_TIPO_INDEFINIDO)
						{
							yyerror("A variável '" + (yyvsp[0]).label + "' possui valor indefinido.");
						}

						(yyval).label = getLabel((yyvsp[0]).label);
						(yyval).declaracao = "";
						(yyval).traducao = "";
						//$$.desalocacao = "";
					}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 260 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = (yyvsp[-1]).label;
						(yyval).declaracao = (yyvsp[-1]).declaracao;
						(yyval).traducao = (yyvsp[-1]).traducao;
						(yyval).tipo = (yyvsp[-1]).tipo;
						//$$.desalocacao = $2.desalocacao;
					}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 268 "sintatica.y" /* yacc.c:1646  */
    {
						int out;

						verificarTipos((yyvsp[-3]).tipo, (yyvsp[-1]).tipo, &out);
						(yyval).tipo = (yyvsp[-3]).tipo;

						string newLabel = nextTMP();
						(yyval).declaracao = (yyvsp[-1]).declaracao + dcl((yyvsp[-3]).tipo, newLabel);
						(yyval).traducao = (yyvsp[-1]).traducao + cst(newLabel, (yyvsp[-3]).tipo, (yyvsp[-1]).label);
						(yyval).label = newLabel;
						//$$.desalocacao = $3.desalocacao;
					}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 281 "sintatica.y" /* yacc.c:1646  */
    {
						string aux = "";
						int tipo = (yyvsp[-1]).tipo;

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
						(yyval).declaracao += dcl(tipo, tmp);

						if (tipo != TK_TIPO_STRING)
						{
							(yyval).traducao = cmd("scanf(\"" + aux + "\", &" + tmp + ");");
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

							(yyval).declaracao += dcl(TK_TIPO_INT, tmpCount);
							(yyval).declaracao += dcl(TK_TIPO_CHAR, tmpChar);
							(yyval).declaracao += dcl(TK_TIPO_INT, tmpUm);
							(yyval).declaracao += dcl(TK_TIPO_CHAR, tmpN);
							(yyval).declaracao += dcl(TK_TIPO_BOOL, tmpComp);
							(yyval).declaracao += dcl(TK_TIPO_STRING, tmpBuffer);
							(yyval).declaracao += dcl(TK_TIPO_CHAR, tmp0);

							(yyval).traducao = "";
							(yyval).traducao += cmd(tmpCount + " = 0");
							(yyval).traducao += cmd(tmpUm + " = 1");
							(yyval).traducao += cmd(tmpN + " = '\\n'");
							(yyval).traducao += cmd(tmp0 + " = '\\0'");
							(yyval).traducao += cmd(tmpBuffer + " = (char*)malloc(sizeof(char) * " + tmpUm + ")");
							(yyval).traducao += lbl(lblLoop);
							(yyval).traducao += cmd("scanf(\"%c\", &" + tmpChar + " )");
							(yyval).traducao += cmd(tmpComp + " = " + tmpChar + " == " + tmpN);
							(yyval).traducao += cmd("if (" + tmpComp + ") goto " + lblFim);
							(yyval).traducao += cmd(tmpCount + " = " + tmpCount + " + " + tmpUm);
							(yyval).traducao += cmd(tmpBuffer + " = (char*)realloc(" + tmpBuffer + ", sizeof(char) * " + tmpCount + ")");
							(yyval).traducao += cmd("strncat(" + tmpBuffer + ", &" + tmpChar + ", " + tmpUm + ")");
							(yyval).traducao += cmd("goto " + lblLoop);
							(yyval).traducao += lbl(lblFim);

							(yyval).traducao += cmd(tmpCount + " = " + tmpCount + " + " + tmpUm);
							(yyval).traducao += cmd("strncat(" + tmpBuffer + ", &" + tmp0 + ", " + tmpUm + ")");
							//$$.traducao += cmd("fseek(stdin, -" + tmpCount + ", SEEK_CUR)");

							(yyval).traducao += cmd(tmp + " = (char*) malloc(sizeof(char) * " + tmpCount + ")");
							(yyval).traducao += cmd("strcpy(" + tmp + ", " + tmpBuffer + ")");
							//$$.traducao += cmd("fgets(" + tmp + ", " + tmpCount + ", stdin)");
						}

						(yyval).tipo = tipo;
						(yyval).label = tmp;
					}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 369 "sintatica.y" /* yacc.c:1646  */
    {
						int tipo = (yyvsp[0]).tipo;

						if (tipo != TK_TIPO_INT && tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador [-] inválido para o tipo (" + typeName(tipo) + ")");
						}

						string tmp = nextTMP();
						(yyval).declaracao = (yyvsp[0]).declaracao;
						(yyval).declaracao += dcl(tipo, tmp);

						(yyval).traducao = (yyvsp[0]).traducao;
						(yyval).traducao += cmd(tmp + " = -" + (yyvsp[0]).label);

						(yyval).tipo = tipo;
						(yyval).label = tmp;

						//$$.desalocacao = $2.desalocacao;
					}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 393 "sintatica.y" /* yacc.c:1646  */
    {

						if ((yyvsp[0]).tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName((yyvsp[0]).tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						(yyval).label = nextTMP();
						(yyval).tipo = TK_TIPO_BOOL;
						(yyval).declaracao = (yyvsp[0]).declaracao + dcl((yyval).tipo, (yyval).label);
						(yyval).traducao = (yyvsp[0]).traducao + cmd((yyval).label + " = !" + (yyvsp[0]).label);
						//$$.desalocacao = $2.desalocacao;
						//$$.traducao = $2.traducao + "\t" + declaracao + $$.label + " = !" + $2.label + ";\n";
					}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 410 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = nextTMP();
						converterTipos(&(yyval), &(yyvsp[-2]), &(yyvsp[0]), (yyvsp[-1]).traducao[0]);
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + cmd ((yyval).label + " = " + (yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label);
						//$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 420 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = nextTMP();
						converterTipos(&(yyval), &(yyvsp[-2]), &(yyvsp[0]), (yyvsp[-1]).traducao[0]);

						(yyval).traducao = (yyvsp[-2]).traducao;
						(yyval).traducao += (yyvsp[0]).traducao;

						if ((yyval).tipo != TK_TIPO_STRING)
						{
							(yyval).traducao += cmd ((yyval).label + " = " + (yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label);
						}
						else
						{
							string tmp = nextTMP();
							int tamanhoFinal = (yyvsp[-2]).tamanho + (yyvsp[-1]).tamanho + 1;

							(yyval).declaracao += dcl(TK_TIPO_STRING, tmp);

							(yyval).traducao += cmd(tmp + " = (char*) malloc(sizeof(char) * " + to_string(tamanhoFinal) + ")");
							(yyval).traducao += cmd("strcpy(" + tmp + ", " + (yyvsp[-2]).label + ")");
							(yyval).traducao += cmd("strcat(" + tmp + ", " + (yyvsp[0]).label + ")");
							(yyval).traducao += cmd((yyval).label + " = " + tmp);

							//$$.desalocacao += cmd("free(" + tmp + ")");
						}

						//$$.desalocacao += $1.desalocacao + $3.desalocacao;
					}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 452 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = nextTMP();
						converterTipos(&(yyval), &(yyvsp[-2]), &(yyvsp[0]), '>', TK_TIPO_BOOL);
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + cmd((yyval).label + " = " + (yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label);
						//$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 462 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = nextTMP();
						converterTipos(&(yyval), &(yyvsp[-2]), &(yyvsp[0]), '=', TK_TIPO_BOOL);
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + cmd((yyval).label + " = " + (yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label);
						//$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 472 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = nextTMP();
						converterTipos(&(yyval), &(yyvsp[-2]), &(yyvsp[0]), '&', TK_TIPO_BOOL);
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + cmd((yyval).label + " = " + (yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label);
						//$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 482 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).label = nextTMP();
						converterTipos(&(yyval), &(yyvsp[-2]), &(yyvsp[0]), '|', TK_TIPO_BOOL);
						(yyval).traducao = (yyvsp[-2]).traducao + (yyvsp[0]).traducao + cmd((yyval).label + " = " + (yyvsp[-2]).label + " " + (yyvsp[-1]).traducao + " " + (yyvsp[0]).label);
						//$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 494 "sintatica.y" /* yacc.c:1646  */
    {
						if (!isDeclared((yyvsp[-2]).label))
						{
							yyerror("Variável '" + (yyvsp[-2]).label + "' nao declarada.");
						}

						(yyvsp[-2]).tipo = getTipo((yyvsp[-2]).label);
						(yyval).declaracao = (yyvsp[0]).declaracao;
						(yyval).traducao = (yyvsp[0]).traducao;

						if ((yyvsp[-2]).tipo == TK_TIPO_INDEFINIDO)
						{
							(yyvsp[-2]).tipo = (yyvsp[0]).tipo;
							setTipo((yyvsp[-2]).label, (yyvsp[-2]).tipo);
							(yyval).declaracao += dcl((yyvsp[-2]).tipo, getLabel((yyvsp[-2]).label));
						}

						converterTipo(&(yyval), (yyvsp[-2]).tipo, &(yyvsp[0]));
						/*
						int out;
						int newType = verificarTipos($1.tipo, $3.tipo, &out);
						checkTypes($1.tipo, newType);

						if (out == 2){
							string newLabel = nextTMP();
							$$.declaracao += dcl($1.tipo, newLabel);
							$$.traducao += cst(newLabel, $1.tipo, $3.label);
							$3.label = newLabel;
						}
						*/

						(yyvsp[-2]).label = getLabel((yyvsp[-2]).label);
						(yyval).traducao += cmd((yyvsp[-2]).label + " = " + (yyvsp[0]).label);
						//$$.desalocacao = $3.desalocacao;
					}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 532 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).declaracao = (yyvsp[0]).declaracao;
						(yyval).traducao = (yyvsp[0]).traducao;
						//$$.desalocacao = $2.desalocacao;
					}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 538 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).declaracao = (yyvsp[0]).declaracao;
						(yyval).traducao = (yyvsp[0]).traducao;
						//$$.desalocacao = $1.desalocacao;
					}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 546 "sintatica.y" /* yacc.c:1646  */
    {
						//Tinha + $3 declaracao e traducao
						(yyval).declaracao = (yyvsp[-2]).declaracao;
						(yyval).traducao = (yyvsp[-2]).traducao;
						//$$.desalocacao = $1.desalocacao;
					}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 553 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).declaracao = (yyvsp[0]).declaracao;
						(yyval).traducao = (yyvsp[0]).traducao;
						//$$.desalocacao = $1.desalocacao;
					}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 561 "sintatica.y" /* yacc.c:1646  */
    {
						if (getSimbolo((yyvsp[0]).label, contextoAtual) != NULL)
							yyerror("Variável '" + (yyvsp[0]).label + "' já foi declarada nesse contexto.");

						string var = nextVAR();
						novoSimbolo((yyvsp[0]).label, var, TK_TIPO_INDEFINIDO);
						//tabela_simbolos[$1.label] = {TK_TIPO_INDEFINIDO, -1, -1, true, newLabel};
						(yyvsp[0]).label = var;

						//$$.traducao = "";
					}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 573 "sintatica.y" /* yacc.c:1646  */
    {
						if (getSimbolo((yyvsp[-2]).label, contextoAtual) != NULL)
							yyerror("Variável '" + (yyvsp[-2]).label + "' já foi declarada nesse contexto.");

						(yyvsp[-2]).tipo = (yyvsp[0]).tipo;
						string declaracao = typeName((yyvsp[-2]).tipo) + " " + (yyvsp[-2]).label + ";\n";

						string newLabel = nextVAR();
						novoSimbolo((yyvsp[-2]).label, newLabel, (yyvsp[-2]).tipo);
						//tabela_simbolos[$1.label] = {$1.tipo, -1, -1, true, newLabel};
						(yyvsp[-2]).label = newLabel;

						(yyval).declaracao = (yyvsp[0]).declaracao + dcl((yyvsp[-2]).tipo, (yyvsp[-2]).label);
						(yyval).traducao = (yyvsp[0]).traducao + cmd((yyvsp[-2]).label + " = " + (yyvsp[0]).label);
						//$$.desalocacao = $3.desalocacao;
					}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 592 "sintatica.y" /* yacc.c:1646  */
    {
						if ((yyvsp[-2]).tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName((yyvsp[-3]).tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo novo Label de Fim
						string lblFim = nextLBL();

						// Imprimir Traducão e Declaracão da Expressão
						(yyval).traducao = (yyvsp[-2]).traducao;
						(yyval).declaracao = (yyvsp[-2]).declaracao;
						//$$.desalocacao = $3.desalocacao;

						// Negar valor da Expressão
						string newLabel = nextTMP();
						(yyval).declaracao += dcl(TK_TIPO_BOOL, newLabel);
						(yyval).traducao += cmd(newLabel + " = !" + (yyvsp[-2]).label);

						// Imprimir Goto para Label de Fim
						(yyval).traducao += cmd("if (" + newLabel + ") goto " + lblFim);

						// Imprimir Bloco
						(yyval).declaracao += (yyvsp[0]).declaracao;
						(yyval).traducao += (yyvsp[0]).traducao;
						//$$.desalocacao += $5.desalocacao;

						// Imprimir Label de Fim
						(yyval).traducao += lbl(lblFim);
					}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 623 "sintatica.y" /* yacc.c:1646  */
    {
						if ((yyvsp[-4]).tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName((yyvsp[-5]).tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo novo Label de Fim
						string lblFim = nextLBL();

						// Imprimir Traducão e Declaracão da Expressão
						(yyval).traducao = (yyvsp[-4]).traducao;
						(yyval).declaracao = (yyvsp[-4]).declaracao ;
						//$$.desalocacao = $3.desalocacao;

						// Negar valor da Expressão
						string newLabel = nextTMP();
						(yyval).declaracao += dcl(TK_TIPO_BOOL, newLabel);
						(yyval).traducao += cmd(newLabel + " = !" + (yyvsp[-4]).label);

						// Imprimir Goto para Label de Fim
						(yyval).traducao += cmd("if (" + newLabel + ") goto " + lblFim);

						// Imprimir Bloco If
						(yyval).declaracao += (yyvsp[-2]).declaracao;
						(yyval).traducao += (yyvsp[-2]).traducao;
						//$$.desalocacao += $5.desalocacao;

						// Imprimir Label de Fim
						(yyval).traducao += lbl(lblFim);

						// Imprimindo Bloco Else
						(yyval).declaracao += (yyvsp[0]).declaracao;
						(yyval).traducao += (yyvsp[0]).traducao;
						//$$.desalocacao += $7.desalocacao;
					}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 660 "sintatica.y" /* yacc.c:1646  */
    { proximoContexto = TK_CTX_WHILE; }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 661 "sintatica.y" /* yacc.c:1646  */
    {

						//imprimirContexto(true);
						if ((yyvsp[-3]).tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName((yyvsp[-4]).tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo novos Labels
						string lblInicio = (yyvsp[0]).lblInicio;
						string lblFim = (yyvsp[0]).lblFim;

						// Imprimir Label de Inicio
						(yyval).traducao = lbl(lblInicio);

						// Obter Tradução e Declaração da Expressão
						(yyval).declaracao += (yyvsp[-3]).declaracao;
						(yyval).traducao += (yyvsp[-3]).traducao;
						//$$.desalocacao = $3.desalocacao;

						// Negar Expressão
						string tmpExpNegada = nextTMP();
						(yyval).declaracao += dcl(TK_TIPO_BOOL, tmpExpNegada);
						(yyval).traducao += cmd(tmpExpNegada + " = !" + (yyvsp[-3]).label);

						// Imprimir Salto Condicional para o Fim
						(yyval).traducao += cmd("if (" + tmpExpNegada + ") goto " + lblFim);

						// Imprimir Bloco
						(yyval).declaracao += (yyvsp[0]).declaracao;
						(yyval).traducao += (yyvsp[0]).traducao;
						//$$.desalocacao += $6.desalocacao;

						// Imprimir Salto Incondicional para o Inicio
						(yyval).traducao += cmd("goto " + lblInicio);

						// Imprimir Label de Fim
						(yyval).traducao += lbl(lblFim);

					}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 703 "sintatica.y" /* yacc.c:1646  */
    {proximoContexto = TK_CTX_WHILE;}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 704 "sintatica.y" /* yacc.c:1646  */
    {
						if ((yyvsp[-1]).tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName((yyvsp[-1]).tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo Label Inicio
						string lblInicio = (yyvsp[-4]).lblInicio;
						string lblFim = (yyvsp[-4]).lblFim;

						// Imprimindo Label Inicio
						(yyval).traducao = lbl(lblInicio);

						// Imprimir Bloco
						(yyval).declaracao = (yyvsp[-4]).declaracao;
						(yyval).traducao += (yyvsp[-4]).traducao;
						//$$.desalocacao = $3.desalocacao;

						// Imprimir Expressão
						(yyval).declaracao += (yyvsp[-1]).declaracao;
						(yyval).traducao += (yyvsp[-1]).traducao;
						//$$.desalocacao += $6.desalocacao;

						// Imprimir Salto Condicional para Label Inicio
						(yyval).traducao += cmd("if (" + (yyvsp[-1]).label + ") goto " + lblInicio);

						// Imprimindo Label Fim
						(yyval).traducao += lbl(lblFim);
					}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 736 "sintatica.y" /* yacc.c:1646  */
    {
						empilharContexto(TK_CTX_FOR);
					}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 740 "sintatica.y" /* yacc.c:1646  */
    {
						if ((yyvsp[-4]).tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName((yyvsp[-7]).tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo Label Inicio e Fim
						string lblInicioIt = nextLBL();					// Cria um label para o inicio da iteração
						string lblFimIt = contextoAtual->lblInicio;		// Uso o label do inicio do bloco no fim da iteracao -- CONTINUE
						string lblFim = contextoAtual->lblFim;			// Pego o label Fim do bloco FOR exterior (fim do laço) -- BREAK

						desempilharContexto();

						// Imprimindo Expressão 1
						(yyval).declaracao = (yyvsp[-6]).declaracao;
						(yyval).traducao = (yyvsp[-6]).traducao;
						//$$.desalocacao = $4.desalocacao;

						// Imprimindo Label Inicio Iteracao
						(yyval).traducao += lbl(lblInicioIt);

						// Imprimindo Expressao 2
						(yyval).declaracao += (yyvsp[-4]).declaracao;
						(yyval).traducao += (yyvsp[-4]).traducao;
						//$$.desalocacao = $6.desalocacao;

						// Negando Expressao 2
						string tmpExpNegada = nextTMP();
						(yyval).declaracao += dcl(TK_TIPO_BOOL, tmpExpNegada);
						(yyval).traducao += cmd(tmpExpNegada + " = !" + (yyvsp[-4]).label);

						// Imprimir Salto Condicional para Label Fim
						(yyval).traducao += cmd("if (" + tmpExpNegada + ") goto " + lblFim);

						// Imprimir Bloco
						(yyval).declaracao += (yyvsp[0]).declaracao;
						(yyval).traducao += (yyvsp[0]).traducao;
						//$$.desalocacao += $10.desalocacao;

						// Imprimir label Fim Iteracao
						(yyval).traducao += lbl(lblFimIt);

						// Imprimir Expressao 3
						(yyval).declaracao += (yyvsp[-2]).declaracao;
						(yyval).traducao += (yyvsp[-2]).traducao;
						//$$.desalocacao += $2.desalocacao;

						// Imprimir Salto Incondicional para Inicio
						(yyval).traducao += cmd("goto " + lblInicioIt);

						// Imprimir Label Fim
						(yyval).traducao += lbl(lblFim);
					}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 796 "sintatica.y" /* yacc.c:1646  */
    {
						simbolo* s = getSimboloPilha((yyvsp[-1]).label);

						if (s == NULL)
						{
							yyerror("Variável '" + (yyvsp[-1]).label + "' não declarada");
						}

						if (s->tipo == TK_TIPO_INDEFINIDO)
						{
							yyerror("Variável '" + (yyvsp[-1]).label + "' possui valor indefinido");
						}

						string lblFim = nextLBL();

						empilharAlternador(s->label, lblFim, s->tipo);
					}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 814 "sintatica.y" /* yacc.c:1646  */
    {
						string lblAux = alternador_atual->lblDefault == ""? alternador_atual->lblFim : alternador_atual->lblDefault;

						(yyval).declaracao = (yyvsp[-1]).declaracao;
						(yyval).traducao = (yyvsp[-1]).traducaoAlternativa;
						(yyval).traducao += cmd("goto " + lblAux);
						(yyval).traducao += (yyvsp[-1]).traducao;
						//$$.desalocacao = $7.desalocacao;

						(yyval).traducao += lbl(alternador_atual->lblFim);
						desempilharAlternador();
					}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 829 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).declaracao = (yyvsp[-1]).declaracao + (yyvsp[0]).declaracao;
						(yyval).traducao = (yyvsp[-1]).traducao + (yyvsp[0]).traducao;

						(yyval).tipo += (yyvsp[0]).tipo;
						(yyval).traducaoAlternativa += (yyvsp[0]).traducaoAlternativa;
						//$$.desalocacao = $2.desalocacao;
					}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 838 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).declaracao = "";
						(yyval).traducao = "";
						//$$.desalocacao = "";
					}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 846 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducaoAlternativa = "";
						(yyval).traducao = "";
						(yyval).declaracao = (yyvsp[0]).declaracao;

						// Definir Label do Case
						string lblCase = nextLBL();

						// Definir Temporária para igualdade
						string tmpIgualdade = nextTMP();

						// Imprimir Expressao (Será impresso no início do Switch, antes dos blocos Case e Default)
						(yyval).traducaoAlternativa += (yyvsp[-1]).traducao;
						(yyval).declaracao += (yyvsp[-1]).declaracao;
						//$$.desalocacao = $2.desalocacao;

						// Verificar e Converter tipos
						converterTipo(&(yyval), alternador_atual->tipo, &(yyvsp[-1]), true);
						(yyval).tipo = (yyvsp[-1]).tipo;

						// Declarar Temporária para igualdade
						(yyval).declaracao += dcl(TK_TIPO_BOOL, tmpIgualdade);

						// Imprimir Tradução Antecipada (Será impresso no início do Switch, antes dos blocos Case e Default)
						(yyval).traducaoAlternativa += cmd(tmpIgualdade + " = " + (yyvsp[-1]).label + " == " + alternador_atual->label);
						(yyval).traducaoAlternativa += cmd("if (" + tmpIgualdade + ") goto " + lblCase);

						// Imprimir Label do Case
						(yyval).traducao += lbl(lblCase);

						// Imprimir Bloco
						(yyval).traducao += (yyvsp[0]).traducao;
						(yyval).declaracao += (yyvsp[0]).declaracao;
						//$$.desalocacao += $3.desalocacao;

						// Imprimir Goto Fim do Switch
						(yyval).traducao += cmd("goto " + alternador_atual->lblFim);

					}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 886 "sintatica.y" /* yacc.c:1646  */
    {
						string lblDefault = nextLBL();
						(yyval).traducao = lbl(lblDefault) + (yyvsp[0]).traducao;
						(yyval).declaracao = (yyvsp[0]).declaracao;
						//$$.desalocacao += $2.desalocacao;

						alternador_atual->lblDefault = lblDefault;
					}
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 897 "sintatica.y" /* yacc.c:1646  */
    {
						Contexto* laco = procurarContextoLaco();
						(yyval).traducao = cmd("goto " + laco->lblFim);
						//desempilharContextoAte(laco);
					}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 905 "sintatica.y" /* yacc.c:1646  */
    {
						Contexto* laco = procurarContextoLaco();
						(yyval).traducao = cmd("goto " + laco->lblInicio);
					}
#line 2384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 912 "sintatica.y" /* yacc.c:1646  */
    {
						/*
						if ($3.tipo != TK_TIPO_STRING && $3.tipo != TK_TIPO_CHAR)
						{
							yyerror("Expressão esperada do tipo (" + typeName(TK_TIPO_STRING, true) + ").");
						}
						*/
						int tipo = (yyvsp[-2]).tipo;
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

						//char aux = ($3.tipo == TK_TIPO_STRING)? 's' : 'c';

						// Imprimir declaracao e tradução da Expressão
						(yyval).traducao = (yyvsp[-2]).traducao;
						(yyval).declaracao = (yyvsp[-2]).declaracao;
						//$$.desalocacao = $3.desalocacao;

						// Imprimir comando de saida
						(yyval).traducao += cmd((string)"printf(\"\%" + aux + "\", " + (yyvsp[-2]).label + ")");
					}
#line 2419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 945 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducao = "<";
					}
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 949 "sintatica.y" /* yacc.c:1646  */
    {
						(yyval).traducao = ">";
					}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2439 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 956 "sintatica.y" /* yacc.c:1906  */


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

string dcl (int tipo, string label)
{
	return cmd(typeName(tipo) + "\t" + label);
}

string lbl (string label)
{
	return '\t' + label + ":\n";
}

string cst (string label1, int tipo, string label2)
{
	return cmd(label1 + " = " + "(" + typeName(tipo) + ")" + label2);
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


void novoSimbolo(string id, string lbl, int tipo)
{
	simbolo novoSimbolo;

	novoSimbolo.label = lbl;
	novoSimbolo.tipo = tipo;

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
	        cout << "   " << itr->first << " : " << itr->second.label << "\t(" << typeName(itr->second.tipo) << ")\n"; 
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
