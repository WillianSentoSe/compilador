%{
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
	string tmpTamanho;
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
void novoSimbolo(string, string, int, string tmpTamanho = "");
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

%}

%token TK_LITERAL TK_ID
%token TK_MAIN TK_VAR TK_TIPO TK_IF TK_ELSE TK_WHILE TK_DO TK_FOR TK_SWITCH TK_CASE TK_BREAK TK_CONTINUE TK_DEFAULT
%token TK_OP_IGUALDADE TK_OP_DESIGUALDADE TK_OP_MAIORIGUAL TK_OP_MENORIGUAL TK_OP_NOT TK_OP_LOGICAL_AND TK_OP_AND TK_OP_LOGICAL_OR TK_OP_XOR TK_OP_IOR TK_OP_ADD TK_OP_MUL TK_OP_SUB
%token TK_TIPO_INDEFINIDO TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_TIPO_STRING
%token TK_CLASSE_VARIAVEL TK_CLASSE_FUNCAO
%token TK_FIM TK_ERROR
%token TK_CTX_BLOCO TK_CTX_IF TK_CTX_WHILE TK_CTX_FOR TK_CTX_CASE
%token TK_OUT TK_IN

%start S

%right '='
%left '+' '-'
%left '*' '/'

%%

S 					: TK_TIPO TK_MAIN '(' ')' BLOCO
					{
						cout << "\n/*Compilador Ç*/\n";
						cout << "\n#include <stdio.h>";
						cout << "\n#include <stdlib.h>";
						cout << "\n#include <string.h>\n\n";
						cout << "#define true 1\n#define false 0\n\n";
						cout << "int main(void)\n{\n" << $5.declaracao + "\n" + $5.traducao + $5.desalocacao << "\n\treturn 0;\n}\n"; 
					}
					;

BLOCO				: '{'
					{
						$1.lblInicio = contextoAtual->lblInicio;
						$1.lblFim = contextoAtual->lblFim;
					}
					COMANDOS '}'
					{
						$$.lblInicio = $1.lblInicio;
						$$.lblFim = $1.lblFim;

						$$.traducao = $3.traducao;
						$$.declaracao = $3.declaracao;
						$$.desalocacao = "\n" + $3.desalocacao;
					}
					;

COMANDOS			: COMANDO COMANDOS
					{
						$$.declaracao = $1.declaracao + $2.declaracao;
						$$.traducao = $1.traducao + $2.traducao;
						$$.desalocacao = $1.desalocacao + $2.desalocacao;
					}
					|
					{
						$$.traducao = "";
						$$.declaracao = "";
					}
					;

COMANDO 			: CMD_DECLARACOES ';'
					| CMD_IF
					| CMD_WHILE
					| CMD_DOWHILE
					| CMD_FOR
					| CMD_SWITCH
					| CMD_BREAK
					| CMD_CONTINUE
					| CMD_OUT
					| '#'
					{
						$$.traducao = "";
						$$.declaracao = "";
						imprimirContexto(true);
					}
					;

COMANDOS_FOR		: COMANDO_FOR ',' COMANDOS_FOR
					{
						$$.declaracao = $1.declaracao + $3.declaracao;
						$$.traducao = $1.traducao + $3.traducao;
						$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
					| COMANDO_FOR
					{
						$$.declaracao = $1.declaracao;
						$$.traducao = $1.traducao;
						$$.desalocacao = $1.desalocacao;
					}
					;

COMANDO_FOR 		: ATRIBUICAO
					{
						$$.traducao = $1.traducao;
						$$.declaracao = $1.declaracao;
					}
					;


EXP_SIMPLES			: TK_LITERAL
					{	
						// EXPERIMENTAL (ATRIBUICAO DIRETA)
						// $$.label = $1.traducao;
						// $$.traducao = "";

						$$.label = nextTMP();
						$$.declaracao = dcl($1.tipo, $$.label);

						if ($1.tipo != TK_TIPO_STRING)
						{
							$$.traducao = cmd($$.label + " = " + $1.traducao);
						}
						else
						{
							int tamanho = $1.tamanho + 1;						// Necessário incluir \0
							string s = $1.traducao;
							int i = 0;

							$$.traducao = cmd($$.label + " = (char*) malloc(sizeof(char) * " + to_string(tamanho) + ")");
							//$$.traducao += cmd($$.label + " = " + $1.traducao);
							$$.traducao += cmd("strcpy(" + $$.label + ", " + $1.traducao + ")");
							$$.desalocacao = cmd("free(" + $$.label + ")");
						}

						$$.tipo = $1.tipo;
					}
					| TK_ID
					{
						checkLabel($1.label);
						$$.tipo = getTipo($1.label);

						if ($$.tipo == TK_TIPO_INDEFINIDO)
						{
							yyerror("A variável '" + $1.label + "' possui valor indefinido.");
						}

						//$$.tamanho = getSimbolo($1.label)->tamanho;
						$$.label = getLabel($1.label);
						$$.declaracao = "";
						$$.traducao = "";
						$$.desalocacao = "";
					}
					| '(' EXPRESSAO ')'
					{
						$$.label = $2.label;
						$$.declaracao = $2.declaracao;
						$$.traducao = $2.traducao;
						$$.tipo = $2.tipo;
						$$.desalocacao = $2.desalocacao;
					}
					| TK_TIPO '(' EXPRESSAO ')'
					{
						int out;

						verificarTipos($1.tipo, $3.tipo, &out);
						$$.tipo = $1.tipo;

						string newLabel = nextTMP();
						$$.declaracao = $3.declaracao + dcl($1.tipo, newLabel);
						$$.traducao = $3.traducao + cst(newLabel, $1.tipo, $3.label);
						$$.label = newLabel;
						$$.desalocacao = $3.desalocacao;
					}
					| TK_IN '(' TK_TIPO ')'
					{
						string aux = "";
						int tipo = $3.tipo;

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
						$$.declaracao += dcl(tipo, tmp);

						if (tipo != TK_TIPO_STRING)
						{
							$$.traducao = cmd("scanf(\"" + aux + "\", &" + tmp + ");");
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

							$$.declaracao += dcl(TK_TIPO_INT, tmpCount);
							$$.declaracao += dcl(TK_TIPO_CHAR, tmpChar);
							$$.declaracao += dcl(TK_TIPO_INT, tmpUm);
							$$.declaracao += dcl(TK_TIPO_CHAR, tmpN);
							$$.declaracao += dcl(TK_TIPO_BOOL, tmpComp);
							$$.declaracao += dcl(TK_TIPO_STRING, tmpBuffer);
							$$.declaracao += dcl(TK_TIPO_CHAR, tmp0);

							$$.traducao = "";
							$$.traducao += cmd(tmpCount + " = 0");
							$$.traducao += cmd(tmpUm + " = 1");
							$$.traducao += cmd(tmpN + " = '\\n'");
							$$.traducao += cmd(tmp0 + " = '\\0'");
							$$.traducao += cmd(tmpBuffer + " = (char*)malloc(sizeof(char) * " + tmpUm + ")");
							$$.traducao += lbl(lblLoop);
							$$.traducao += cmd("scanf(\"%c\", &" + tmpChar + " )");
							$$.traducao += cmd(tmpComp + " = " + tmpChar + " == " + tmpN);
							$$.traducao += cmd("if (" + tmpComp + ") goto " + lblFim);
							$$.traducao += cmd(tmpCount + " = " + tmpCount + " + " + tmpUm);
							$$.traducao += cmd(tmpBuffer + " = (char*)realloc(" + tmpBuffer + ", sizeof(char) * " + tmpCount + ")");
							$$.traducao += cmd("strncat(" + tmpBuffer + ", &" + tmpChar + ", " + tmpUm + ")");
							$$.traducao += cmd("goto " + lblLoop);
							$$.traducao += lbl(lblFim);

							$$.traducao += cmd(tmpCount + " = " + tmpCount + " + " + tmpUm);
							$$.traducao += cmd("strncat(" + tmpBuffer + ", &" + tmp0 + ", " + tmpUm + ")");
							//$$.traducao += cmd("fseek(stdin, -" + tmpCount + ", SEEK_CUR)");

							$$.traducao += cmd(tmp + " = (char*) malloc(sizeof(char) * " + tmpCount + ")");
							$$.traducao += cmd("strcpy(" + tmp + ", " + tmpBuffer + ")");
							//$$.traducao += cmd("fgets(" + tmp + ", " + tmpCount + ", stdin)");
						}

						$$.tipo = tipo;
						$$.label = tmp;
					}
					;
					
EXP_UNARIA			: EXP_SIMPLES
					| TK_OP_ADD EXP_SIMPLES
					{
						int tipo = $2.tipo;

						if (tipo != TK_TIPO_INT && tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador [-] inválido para o tipo (" + typeName(tipo) + ")");
						}

						string tmp = nextTMP();
						$$.declaracao = $2.declaracao;
						$$.declaracao += dcl(tipo, tmp);

						$$.traducao = $2.traducao;
						$$.traducao += cmd(tmp + " = -" + $2.label);

						$$.tipo = tipo;
						$$.label = tmp;

						$$.desalocacao = $2.desalocacao;
					}
					;

EXP_NOT				: EXP_UNARIA
					| TK_OP_NOT EXP_NOT
					{

						if ($2.tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName($2.tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						$$.label = nextTMP();
						$$.tipo = TK_TIPO_BOOL;
						$$.declaracao = $2.declaracao + dcl($$.tipo, $$.label);
						$$.traducao = $2.traducao + cmd($$.label + " = !" + $2.label);
						$$.desalocacao = $2.desalocacao;
						//$$.traducao = $2.traducao + "\t" + declaracao + $$.label + " = !" + $2.label + ";\n";
					}

EXP_ARITMETICA_MUL	: EXP_NOT
					| EXP_ARITMETICA_MUL TK_OP_MUL EXP_NOT
					{
						$$.label = nextTMP();
						converterTipos(&$$, &$1, &$3, $2.traducao[0]);
						$$.traducao = $1.traducao + $3.traducao + cmd ($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
						$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
					;

EXP_ARITMETICA_ADD	: EXP_ARITMETICA_MUL
					| EXP_ARITMETICA_ADD TK_OP_ADD EXP_ARITMETICA_MUL
					{
						$$.label = nextTMP();
						converterTipos(&$$, &$1, &$3, $2.traducao[0]);

						$$.traducao = $1.traducao;
						$$.traducao += $3.traducao;

						if ($$.tipo != TK_TIPO_STRING)
						{
							$$.traducao += cmd ($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
						}
						else
						{
							string tmp = nextTMP();
							int tamanhoFinal = $1.tamanho + $2.tamanho + 1;

							$$.declaracao += dcl(TK_TIPO_STRING, tmp);

							$$.traducao += cmd(tmp + " = (char*) malloc(sizeof(char) * " + to_string(tamanhoFinal) + ")");
							$$.traducao += cmd("strcpy(" + tmp + ", " + $1.label + ")");
							$$.traducao += cmd("strcat(" + tmp + ", " + $3.label + ")");
							$$.traducao += cmd($$.label + " = " + tmp);

							$$.desalocacao += cmd("free(" + tmp + ")");
							$$.desalocacao += cmd("free(" + $$.label + ")");
						}

						$$.desalocacao += $1.desalocacao + $3.desalocacao;
					}
					;

EXP_RELACIONAL		: EXP_ARITMETICA_ADD
					| EXP_RELACIONAL OP_RELACIONAL EXP_ARITMETICA_ADD
					{
						$$.label = nextTMP();
						converterTipos(&$$, &$1, &$3, '>', TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
						$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
					;

EXP_IGUALDADE		: EXP_RELACIONAL
					| EXP_IGUALDADE TK_OP_IGUALDADE EXP_RELACIONAL
					{
						$$.label = nextTMP();
						converterTipos(&$$, &$1, &$3, '=', TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
						$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
					;

EXP_LOGICAL_AND  	: EXP_IGUALDADE
					| EXP_LOGICAL_AND TK_OP_LOGICAL_AND EXP_IGUALDADE
					{
						$$.label = nextTMP();
						converterTipos(&$$, &$1, &$3, '&', TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
						$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
					;

EXP_LOGICAL_OR		: EXP_LOGICAL_AND
					| EXP_LOGICAL_OR TK_OP_LOGICAL_OR EXP_LOGICAL_AND
					{
						$$.label = nextTMP();
						converterTipos(&$$, &$1, &$3, '|', TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
						$$.desalocacao = $1.desalocacao + $3.desalocacao;
					}
					;

EXPRESSAO			: EXP_LOGICAL_OR
					;

ATRIBUICAO			: TK_ID '=' EXPRESSAO
					{
						if (!isDeclared($1.label))
						{
							yyerror("Variável '" + $1.label + "' nao declarada.");
						}

						$1.tipo = getTipo($1.label);
						$$.declaracao = $3.declaracao;
						$$.traducao = $3.traducao;

						if ($1.tipo == TK_TIPO_INDEFINIDO)
						{
							$1.tipo = $3.tipo;
							setTipo($1.label, $1.tipo);
							$$.declaracao += dcl($1.tipo, getLabel($1.label));
						}

						converterTipo(&$$, $1.tipo, &$3);
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

						$$.traducao += cmd(getSimbolo($1.label)->tmpTamanho + " = " + to_string($3.tamanho));
						$1.label = getLabel($1.label);
						$$.traducao += cmd($1.label + " = " + $3.label);
						$$.desalocacao = $3.desalocacao;
					}
					;

CMD_DECLARACOES		: TK_VAR LIST_DECLARACOES
					{
						$$.declaracao = $2.declaracao;
						$$.traducao = $2.traducao;
						$$.desalocacao = $2.desalocacao;
					}
					| ATRIBUICAO
					{
						$$.declaracao = $1.declaracao;
						$$.traducao = $1.traducao;
						$$.desalocacao = $1.desalocacao;
					}
					;

LIST_DECLARACOES	: DECLARACAO ',' LIST_DECLARACOES
					{
						//Tinha + $3 declaracao e traducao
						$$.declaracao = $1.declaracao;
						$$.traducao = $1.traducao;
						$$.desalocacao = $1.desalocacao;
					}
					| DECLARACAO
					{
						$$.declaracao = $1.declaracao;
						$$.traducao = $1.traducao;
						$$.desalocacao = $1.desalocacao;
					}
					;

DECLARACAO 			: TK_ID
					{
						if (getSimbolo($1.label, contextoAtual) != NULL)
							yyerror("Variável '" + $1.label + "' já foi declarada nesse contexto.");

						string var = nextVAR();
						novoSimbolo($1.label, var, TK_TIPO_INDEFINIDO);
						//tabela_simbolos[$1.label] = {TK_TIPO_INDEFINIDO, -1, -1, true, newLabel};
						$1.label = var;

						//$$.traducao = "";
					}
					| TK_ID '=' EXPRESSAO
					{
						if (getSimbolo($1.label, contextoAtual) != NULL)
							yyerror("Variável '" + $1.label + "' já foi declarada nesse contexto.");

						$1.tipo = $3.tipo;
						string declaracao = typeName($1.tipo) + " " + $1.label + ";\n";

						string newLabel = nextVAR();
						string tmpTamanho = "";

						if ($3.tipo == TK_TIPO_STRING)
						{
							tmpTamanho = nextLBL();
						}

						novoSimbolo($1.label, newLabel, $1.tipo, tmpTamanho);
						$1.label = newLabel;

						$$.declaracao = $3.declaracao;
						$$.declaracao += dcl($1.tipo, $1.label);
						$$.traducao = $3.traducao;
						$$.traducao += cmd($1.label + " = " + $3.label);
						$$.desalocacao = $3.desalocacao;

						if ($3.tipo == TK_TIPO_STRING)
						{
							$$.declaracao += dcl(TK_TIPO_INT, tmpTamanho);
							$$.traducao += cmd(tmpTamanho + " = " + to_string($3.tamanho));
						}
					}
					;

CMD_IF				: TK_IF '(' EXPRESSAO ')' BLOCO
					{
						if ($3.tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName($2.tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo novo Label de Fim
						string lblFim = nextLBL();

						// Imprimir Traducão e Declaracão da Expressão
						$$.traducao = $3.traducao;
						$$.declaracao = $3.declaracao;
						$$.desalocacao = $3.desalocacao;

						// Negar valor da Expressão
						string newLabel = nextTMP();
						$$.declaracao += dcl(TK_TIPO_BOOL, newLabel);
						$$.traducao += cmd(newLabel + " = !" + $3.label);

						// Imprimir Goto para Label de Fim
						$$.traducao += cmd("if (" + newLabel + ") goto " + lblFim);

						// Imprimir Bloco
						$$.declaracao += $5.declaracao;
						$$.traducao += $5.traducao;
						$$.desalocacao += $5.desalocacao;

						// Imprimir Label de Fim
						$$.traducao += lbl(lblFim);
					}
					| TK_IF '(' EXPRESSAO ')' BLOCO TK_ELSE BLOCO
					{
						if ($3.tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName($2.tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo novo Label de Fim
						string lblFim = nextLBL();

						// Imprimir Traducão e Declaracão da Expressão
						$$.traducao = $3.traducao;
						$$.declaracao = $3.declaracao ;
						$$.desalocacao = $3.desalocacao;

						// Negar valor da Expressão
						string newLabel = nextTMP();
						$$.declaracao += dcl(TK_TIPO_BOOL, newLabel);
						$$.traducao += cmd(newLabel + " = !" + $3.label);

						// Imprimir Goto para Label de Fim
						$$.traducao += cmd("if (" + newLabel + ") goto " + lblFim);

						// Imprimir Bloco If
						$$.declaracao += $5.declaracao;
						$$.traducao += $5.traducao;
						$$.desalocacao += $5.desalocacao;

						// Imprimir Label de Fim
						$$.traducao += lbl(lblFim);

						// Imprimindo Bloco Else
						$$.declaracao += $7.declaracao;
						$$.traducao += $7.traducao;
						$$.desalocacao += $7.desalocacao;
					}
					;

CMD_WHILE			: TK_WHILE '(' EXPRESSAO ')' { proximoContexto = TK_CTX_WHILE; } BLOCO
					{

						//imprimirContexto(true);
						if ($3.tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName($2.tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo novos Labels
						string lblInicio = $6.lblInicio;
						string lblFim = $6.lblFim;

						// Imprimir Label de Inicio
						$$.traducao = lbl(lblInicio);

						// Obter Tradução e Declaração da Expressão
						$$.declaracao += $3.declaracao;
						$$.traducao += $3.traducao;
						$$.desalocacao = $3.desalocacao;

						// Negar Expressão
						string tmpExpNegada = nextTMP();
						$$.declaracao += dcl(TK_TIPO_BOOL, tmpExpNegada);
						$$.traducao += cmd(tmpExpNegada + " = !" + $3.label);

						// Imprimir Salto Condicional para o Fim
						$$.traducao += cmd("if (" + tmpExpNegada + ") goto " + lblFim);

						// Imprimir Bloco
						$$.declaracao += $6.declaracao;
						$$.traducao += $6.traducao;
						$$.desalocacao += $6.desalocacao;

						// Imprimir Salto Incondicional para o Inicio
						$$.traducao += cmd("goto " + lblInicio);

						// Imprimir Label de Fim
						$$.traducao += lbl(lblFim);

					}
					;

CMD_DOWHILE			: TK_DO {proximoContexto = TK_CTX_WHILE;} BLOCO TK_WHILE '(' EXPRESSAO ')'
					{
						if ($6.tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName($6.tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo Label Inicio
						string lblInicio = $3.lblInicio;
						string lblFim = $3.lblFim;

						// Imprimindo Label Inicio
						$$.traducao = lbl(lblInicio);

						// Imprimir Bloco
						$$.declaracao = $3.declaracao;
						$$.traducao += $3.traducao;
						$$.desalocacao = $3.desalocacao;

						// Imprimir Expressão
						$$.declaracao += $6.declaracao;
						$$.traducao += $6.traducao;
						$$.desalocacao += $6.desalocacao;

						// Imprimir Salto Condicional para Label Inicio
						$$.traducao += cmd("if (" + $6.label + ") goto " + lblInicio);

						// Imprimindo Label Fim
						$$.traducao += lbl(lblFim);
					}
					;

CMD_FOR				: TK_FOR
					{
						empilharContexto(TK_CTX_FOR);
					}
					'(' CMD_DECLARACOES ';' EXPRESSAO ';' COMANDOS_FOR ')' BLOCO
					{
						if ($6.tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName($3.tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo Label Inicio e Fim
						string lblInicioIt = nextLBL();					// Cria um label para o inicio da iteração
						string lblFimIt = contextoAtual->lblInicio;		// Uso o label do inicio do bloco no fim da iteracao -- CONTINUE
						string lblFim = contextoAtual->lblFim;			// Pego o label Fim do bloco FOR exterior (fim do laço) -- BREAK

						desempilharContexto();

						// Imprimindo Expressão 1
						$$.declaracao = $4.declaracao;
						$$.traducao = $4.traducao;
						$$.desalocacao = $4.desalocacao;

						// Imprimindo Label Inicio Iteracao
						$$.traducao += lbl(lblInicioIt);

						// Imprimindo Expressao 2
						$$.declaracao += $6.declaracao;
						$$.traducao += $6.traducao;
						$$.desalocacao = $6.desalocacao;

						// Negando Expressao 2
						string tmpExpNegada = nextTMP();
						$$.declaracao += dcl(TK_TIPO_BOOL, tmpExpNegada);
						$$.traducao += cmd(tmpExpNegada + " = !" + $6.label);

						// Imprimir Salto Condicional para Label Fim
						$$.traducao += cmd("if (" + tmpExpNegada + ") goto " + lblFim);

						// Imprimir Bloco
						$$.declaracao += $10.declaracao;
						$$.traducao += $10.traducao;
						$$.desalocacao += $10.desalocacao;

						// Imprimir label Fim Iteracao
						$$.traducao += lbl(lblFimIt);

						// Imprimir Expressao 3
						$$.declaracao += $8.declaracao;
						$$.traducao += $8.traducao;
						$$.desalocacao += $2.desalocacao;

						// Imprimir Salto Incondicional para Inicio
						$$.traducao += cmd("goto " + lblInicioIt);

						// Imprimir Label Fim
						$$.traducao += lbl(lblFim);
					}
					;

CMD_SWITCH			: TK_SWITCH '(' TK_ID ')'
					{
						simbolo* s = getSimboloPilha($3.label);

						if (s == NULL)
						{
							yyerror("Variável '" + $3.label + "' não declarada");
						}

						if (s->tipo == TK_TIPO_INDEFINIDO)
						{
							yyerror("Variável '" + $3.label + "' possui valor indefinido");
						}

						string lblFim = nextLBL();

						empilharAlternador(s->label, lblFim, s->tipo);
					} 
					'{' BLOCO_SWITCH '}'
					{
						string lblAux = alternador_atual->lblDefault == ""? alternador_atual->lblFim : alternador_atual->lblDefault;

						$$.declaracao = $7.declaracao;
						$$.traducao = $7.traducaoAlternativa;
						$$.traducao += cmd("goto " + lblAux);
						$$.traducao += $7.traducao;
						$$.desalocacao = $7.desalocacao;

						$$.traducao += lbl(alternador_atual->lblFim);
						desempilharAlternador();
					}
					;

BLOCO_SWITCH		: BLOCO_SWITCH EXP_CASE
					{
						$$.declaracao = $1.declaracao + $2.declaracao;
						$$.traducao = $1.traducao + $2.traducao;

						$$.tipo += $2.tipo;
						$$.traducaoAlternativa += $2.traducaoAlternativa;
						$$.desalocacao = $2.desalocacao;
					}
					| 
					{
						$$.declaracao = "";
						$$.traducao = "";
						$$.desalocacao = "";
					}
					;
				
EXP_CASE			: TK_CASE EXPRESSAO BLOCO
					{
						$$.traducaoAlternativa = "";
						$$.traducao = "";
						$$.declaracao = $3.declaracao;

						// Definir Label do Case
						string lblCase = nextLBL();

						// Definir Temporária para igualdade
						string tmpIgualdade = nextTMP();

						// Imprimir Expressao (Será impresso no início do Switch, antes dos blocos Case e Default)
						$$.traducaoAlternativa += $2.traducao;
						$$.declaracao += $2.declaracao;
						$$.desalocacao = $2.desalocacao;

						// Verificar e Converter tipos
						converterTipo(&$$, alternador_atual->tipo, &$2, true);
						$$.tipo = $2.tipo;

						// Declarar Temporária para igualdade
						$$.declaracao += dcl(TK_TIPO_BOOL, tmpIgualdade);

						// Imprimir Tradução Antecipada (Será impresso no início do Switch, antes dos blocos Case e Default)
						$$.traducaoAlternativa += cmd(tmpIgualdade + " = " + $2.label + " == " + alternador_atual->label);
						$$.traducaoAlternativa += cmd("if (" + tmpIgualdade + ") goto " + lblCase);

						// Imprimir Label do Case
						$$.traducao += lbl(lblCase);

						// Imprimir Bloco
						$$.traducao += $3.traducao;
						$$.declaracao += $3.declaracao;
						$$.desalocacao += $3.desalocacao;

						// Imprimir Goto Fim do Switch
						$$.traducao += cmd("goto " + alternador_atual->lblFim);

					}
					| TK_DEFAULT BLOCO
					{
						string lblDefault = nextLBL();
						$$.traducao = lbl(lblDefault) + $2.traducao;
						$$.declaracao = $2.declaracao;
						$$.desalocacao += $2.desalocacao;

						alternador_atual->lblDefault = lblDefault;
					}
					;

CMD_BREAK			: TK_BREAK ';'
					{
						Contexto* laco = procurarContextoLaco();
						$$.traducao = cmd("goto " + laco->lblFim);
						//desempilharContextoAte(laco);
					}
					;

CMD_CONTINUE		: TK_CONTINUE ';'
					{
						Contexto* laco = procurarContextoLaco();
						$$.traducao = cmd("goto " + laco->lblInicio);
					}
					;

CMD_OUT  			: TK_OUT '(' EXPRESSAO ')' ';'
					{
						/*
						if ($3.tipo != TK_TIPO_STRING && $3.tipo != TK_TIPO_CHAR)
						{
							yyerror("Expressão esperada do tipo (" + typeName(TK_TIPO_STRING, true) + ").");
						}
						*/
						int tipo = $3.tipo;
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
						$$.traducao = $3.traducao;
						$$.declaracao = $3.declaracao;
						$$.desalocacao = $3.desalocacao;

						// Imprimir comando de saida
						$$.traducao += cmd((string)"printf(\"\%" + aux + "\", " + $3.label + ")");
					}
					;

OP_RELACIONAL		: '<'
					{
						$$.traducao = "<";
					}
					| '>'
					{
						$$.traducao = ">";
					}
					| TK_OP_MAIORIGUAL
					| TK_OP_MENORIGUAL
					;

%%

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


void novoSimbolo(string id, string lbl, int tipo, string tmpTamanho)
{
	simbolo novoSimbolo;

	novoSimbolo.label = lbl;
	novoSimbolo.tipo = tipo;
	novoSimbolo.tmpTamanho = tmpTamanho;

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