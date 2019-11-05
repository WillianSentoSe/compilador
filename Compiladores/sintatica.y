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
	int tipo;
};

struct simbolo {
	int tipo;
	string label;
};

class Contexto
{
public:
	unordered_map<string, simbolo> simbolos;
	Contexto* anterior;
};


int countTMP = 0;
int countVAR = 0;
int countLBL = 0;
int linha = 1;
//unordered_map<string, simbolo> tabela_simbolos;
Contexto* contextoAtual;
string espacamentoDeIndexacao;

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

string cmd(string);
string dcl(int, string);
string cst (string, int, string);
string lbl(string);

void setTipo(string, int);
int getTipo(string);
int getClasse(string);
bool isAtivo(string);
string getLabel(string);
bool isDeclared(string);


void printHash();
vector<string> split(string, char);

void addSimbolo(string, simbolo);
void novoSimbolo(string, string, int);
simbolo* getSimbolo(string);
Contexto* novoContexto();
void empilharContexto();
void desempilharContexto();

%}

%token TK_LITERAL TK_ID
%token TK_MAIN TK_VAR TK_TIPO TK_IF TK_ELSE TK_WHILE TK_DO TK_FOR TK_SWITCH TK_CASE TK_BREAK TK_CONTINUE TK_DEFAULT
%token TK_OP_IGUALDADE TK_OP_DESIGUALDADE TK_OP_MAIORIGUAL TK_OP_MENORIGUAL TK_OP_NOT TK_OP_LOGICAL_AND TK_OP_AND TK_OP_LOGICAL_OR TK_OP_XOR TK_OP_IOR TK_OP_ADD TK_OP_MUL
%token TK_TIPO_INDEFINIDO TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_TIPO_STRING
%token TK_CLASSE_VARIAVEL TK_CLASSE_FUNCAO
%token TK_FIM TK_ERROR

%start S

%right '='
%left '+' '-'
%left '*' '/'

%%

S 					: TK_TIPO TK_MAIN '(' ')' BLOCO
					{
						cout << "\n/*Compilador Ç*/\n\n";
						cout << "\n#include <stdio.h>\n\n";
						cout << "#define true 1\n#define false 0\n\n";
						cout << "int main(void)\n{\n" << $5.declaracao + "\n" + $5.traducao << "\n\treturn 0;\n}\n"; 
					}
					;

BLOCO				: '{' COMANDOS '}'
					{
						$$.traducao = $2.traducao;
						$$.declaracao = $2.declaracao;
					}
					;

COMANDOS			: COMANDO COMANDOS
					{
						$$.declaracao = $1.declaracao + $2.declaracao;
						$$.traducao = $1.traducao + $2.traducao;
					}
					|
					{
						$$.traducao = "";
					}
					;

COMANDO 			: CMD_DECLARACOES ';'
					| CMD_IF
					| CMD_WHILE
					| CMD_DOWHILE
					| CMD_FOR
					| CMD_SWITCH
					;

EXP_SIMPLES			: TK_LITERAL
					{	
						// EXPERIMENTAL (ATRIBUICAO DIRETA)
						// $$.label = $1.traducao;
						// $$.traducao = "";

						$$.label = nextTMP();
						$$.declaracao = dcl($1.tipo, $$.label);
						$$.traducao = cmd($$.label + " = " + $1.traducao);
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

						$$.label = getLabel($1.label);
						$$.declaracao = "";
						$$.traducao = "";
					}
					| '(' EXPRESSAO ')'
					{
						$$.label = $2.label;
						$$.declaracao = $2.declaracao;
						$$.traducao = $2.traducao;
						$$.tipo = $2.tipo;
					}
					| TK_TIPO '(' EXPRESSAO ')'
					{
						int out;

						convertType($1.tipo, $3.tipo, &out);
						$$.tipo = $1.tipo;

						string newLabel = nextTMP();
						$$.declaracao = $3.declaracao + dcl($1.tipo, newLabel);
						$$.traducao = $3.traducao + cst(newLabel, $1.tipo, $3.label);
						$$.label = newLabel;
					}
					;
					
EXP_NOT				: EXP_SIMPLES
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
						//$$.traducao = $2.traducao + "\t" + declaracao + $$.label + " = !" + $2.label + ";\n";
					}

EXP_ARITMETICA_MUL	: EXP_NOT
					| EXP_ARITMETICA_MUL TK_OP_MUL EXP_NOT
					{
						$$.label = nextTMP();
						neoConvertType(&$$, &$1, &$3);
						$$.traducao = $1.traducao + $3.traducao + cmd ($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_ARITMETICA_ADD	: EXP_ARITMETICA_MUL
					| EXP_ARITMETICA_ADD TK_OP_ADD EXP_ARITMETICA_MUL
					{
						$$.label = nextTMP();
						neoConvertType(&$$, &$1, &$3);
						$$.traducao = $1.traducao + $3.traducao + cmd ($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_RELACIONAL		: EXP_ARITMETICA_ADD
					| EXP_RELACIONAL OP_RELACIONAL EXP_ARITMETICA_ADD
					{
						$$.label = nextTMP();
						neoConvertType(&$$, &$1, &$3, TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_IGUALDADE		: EXP_RELACIONAL
					| EXP_IGUALDADE TK_OP_IGUALDADE EXP_RELACIONAL
					{
						$$.label = nextTMP();
						neoConvertType(&$$, &$1, &$3, TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_LOGICAL_AND  	: EXP_IGUALDADE
					| EXP_LOGICAL_AND TK_OP_LOGICAL_AND EXP_IGUALDADE
					{
						$$.label = nextTMP();
						neoConvertType(&$$, &$1, &$3, TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_LOGICAL_OR		: EXP_LOGICAL_AND
					| EXP_LOGICAL_OR TK_OP_LOGICAL_OR EXP_LOGICAL_AND
					{
						$$.label = nextTMP();
						neoConvertType(&$$, &$1, &$3, TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
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

						int out;
						int newType = convertType($1.tipo, $3.tipo, &out);
						checkTypes($1.tipo, newType);

						if (out == 2){
							string newLabel = nextTMP();
							$$.declaracao += dcl($1.tipo, newLabel);
							$$.traducao += cst(newLabel, $1.tipo, $3.label);
							$3.label = newLabel;
						}

						$1.label = getLabel($1.label);
						$$.traducao += cmd($1.label + " = " + $3.label);
					}
					;

CMD_DECLARACOES		: TK_VAR LIST_DECLARACOES
					{
						$$.declaracao = $2.declaracao;
						$$.traducao = $2.traducao;
					}
					| ATRIBUICAO
					{
						$$.declaracao = $1.declaracao;
						$$.traducao = $1.traducao;
					}
					;

LIST_DECLARACOES	: DECLARACAO ',' LIST_DECLARACOES
					{
						//Tinha + $3 declaracao e traducao
						$$.declaracao = $1.declaracao;
						$$.traducao = $1.traducao;
					}
					| DECLARACAO
					{
						$$.declaracao = $1.declaracao;
						$$.traducao = $1.traducao;
					}
					;

DECLARACAO 			: TK_ID
					{
						if (isDeclared($1.label))
							yyerror("Variável '" + $1.label + "' já foi declarada.");

						string var = nextVAR();
						novoSimbolo($1.label, var, TK_TIPO_INDEFINIDO);
						//tabela_simbolos[$1.label] = {TK_TIPO_INDEFINIDO, -1, -1, true, newLabel};
						$1.label = var;

						//$$.traducao = "";
					}
					| TK_ID '=' EXPRESSAO
					{
						if (isDeclared($1.label))
							yyerror("Variável '" + $1.label + "' já foi declarada.");

						$1.tipo = $3.tipo;
						string declaracao = typeName($1.tipo) + " " + $1.label + ";\n";

						string newLabel = nextVAR();
						novoSimbolo($1.label, newLabel, $1.tipo);
						//tabela_simbolos[$1.label] = {$1.tipo, -1, -1, true, newLabel};
						$1.label = newLabel;

						$$.declaracao = $3.declaracao + dcl($1.tipo, $1.label);
						$$.traducao = $3.traducao + cmd($1.label + " = " + $3.label);
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

						// Negar valor da Expressão
						string newLabel = nextTMP();
						$$.declaracao += dcl(TK_TIPO_BOOL, newLabel);
						$$.traducao += cmd(newLabel + " = !" + $3.label);

						// Imprimir Goto para Label de Fim
						$$.traducao += cmd("if (" + newLabel + ") goto " + lblFim);

						// Imprimir Bloco
						$$.declaracao += $5.declaracao;
						$$.traducao += $5.traducao;

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
						$$.declaracao = $3.declaracao;

						// Negar valor da Expressão
						string newLabel = nextTMP();
						$$.declaracao += dcl(TK_TIPO_BOOL, newLabel);
						$$.traducao += cmd(newLabel + " = !" + $3.label);

						// Imprimir Goto para Label de Fim
						$$.traducao += cmd("if (" + newLabel + ") goto " + lblFim);

						// Imprimir Bloco If
						$$.declaracao += $5.declaracao;
						$$.traducao += $5.traducao;

						// Imprimir Label de Fim
						$$.traducao += lbl(lblFim);

						// Imprimindo Bloco Else
						$$.declaracao += $7.declaracao;
						$$.traducao += $7.traducao;

						/*
						$$.traducao = $3.traducao;
						$$.declaracao = $3.declaracao;
						string newLabel = nextTMP();
						string labelGoto = nextLBL();
						$$.declaracao += dcl(TK_TIPO_BOOL, newLabel);
						$$.traducao += cmd(newLabel + " = !" + $3.label);
						$$.traducao += cmd("if (" + newLabel + ") goto " + labelGoto);
						$$.declaracao += $5.declaracao;
						$$.traducao += $5.traducao;
						$$.traducao += lbl(labelGoto);

						$$.declaracao += $7.declaracao;
						$$.traducao += $7.traducao;
						*/
					}
					;

CMD_WHILE			: TK_WHILE '(' EXPRESSAO ')' BLOCO
					{
						if ($3.tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName($2.tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo novos Labels
						string lblInicio = nextLBL();
						string lblFim = nextLBL();

						// Imprimir Label de Inicio
						$$.traducao = lbl(lblInicio);

						// Obter Tradução e Declaração da Expressão
						$$.declaracao += $3.declaracao;
						$$.traducao += $3.traducao;

						// Negar Expressão
						string tmpExpNegada = nextTMP();
						$$.declaracao += dcl(TK_TIPO_BOOL, tmpExpNegada);
						$$.traducao += cmd(tmpExpNegada + " = !" + $3.label);

						// Imprimir Salto Condicional para o Fim
						$$.traducao += cmd("if (" + tmpExpNegada + ") goto " + lblFim);

						// Imprimir Bloco
						$$.declaracao += $5.declaracao;
						$$.traducao += $5.traducao;

						// Imprimir Salto Incondicional para o Inicio
						$$.traducao += cmd("goto " + lblInicio);

						// Imprimir Label de Fim
						$$.traducao += lbl(lblFim);
					}
					;

CMD_DOWHILE			: TK_DO BLOCO TK_WHILE '(' EXPRESSAO ')'
					{
						if ($5.tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName($2.tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo Label Inicio
						string lblInicio = nextLBL();

						// Imprimindo Label Inicio
						$$.traducao = lbl(lblInicio);

						// Imprimir Bloco
						$$.declaracao = $2.declaracao;
						$$.traducao += $2.traducao;

						// Imprimir Expressão
						$$.declaracao += $5.declaracao;
						$$.traducao += $5.traducao;

						// Imprimir Salto Condicional para Label Inicio
						$$.traducao += cmd("if (" + $5.label + ") goto " + lblInicio);
					}
					;

CMD_FOR				: TK_FOR '(' CMD_DECLARACOES ';' EXPRESSAO ';' CMD_DECLARACOES ')' BLOCO
					{
						if ($5.tipo != TK_TIPO_BOOL)
						{
							yyerror("Conversão inválida entre (" + typeName($2.tipo, true) + ") e (" + typeName(TK_TIPO_BOOL, true) + ")");
						}

						// Definindo Label Inicio e Fim
						string lblInicio = nextLBL();
						string lblFim = nextLBL();

						// Imprimindo Expressão 1
						$$.declaracao = $3.declaracao;
						$$.traducao = $3.traducao;

						// Imprimindo Label Inicio
						$$.traducao += lbl(lblInicio);

						// Imprimindo Expressao 2
						$$.declaracao += $5.declaracao;
						$$.traducao += $5.traducao;

						// Negando Expressao 2
						string tmpExpNegada = nextTMP();
						$$.declaracao += dcl(TK_TIPO_BOOL, tmpExpNegada);
						$$.traducao += cmd(tmpExpNegada + " = !" + $5.label);

						// Imprimir Salto Condicional para Label Fim
						$$.traducao += cmd("if (" + tmpExpNegada + ") goto " + lblFim);

						// Imprimir Bloco
						$$.declaracao += $9.declaracao;
						$$.traducao += $9.traducao;

						// Imprimir Expressao 3
						$$.declaracao += $7.declaracao;
						$$.traducao += $7.traducao;

						// Imprimir Salto Incondicional para Inicio
						$$.traducao += cmd("goto " + lblInicio);

						// Imprimir Label Fim
						$$.traducao += lbl(lblFim);

					}
					| TK_FOR TK_ID '(' EXPRESSAO ',' OP_COMPARATIVOS EXPRESSAO ')' BLOCO
					{
						// !!! EXPERIMENTAL !!! //

						string var = "";

						// Declarar Váriavel caso necessário
						if (!isDeclared($2.label))
						{
							var = nextVAR();
							novoSimbolo($2.label, var, TK_TIPO_INDEFINIDO);
							//tabela_simbolos[$2.label] = {TK_TIPO_INDEFINIDO, -1, -1, true, var};
						} else
						{
							$2.tipo = getTipo($2.label);
							var = getLabel($2.label);
						}

						// Definindo Labels
						string lblInicio = nextLBL();
						string lblFim = nextLBL();

						// Imprimir Expressao 1
						$$.declaracao = $4.declaracao;
						$$.traducao = $4.traducao;

						// Declarar Variável caso necessário
						if ($2.tipo == TK_TIPO_INDEFINIDO)
						{
							$2.tipo = $4.tipo;
							setTipo($2.label, $2.tipo);
							$$.declaracao += dcl($2.tipo, var);
						}

						int out;
						int newType = convertType($2.tipo, $4.tipo, &out);
						checkTypes($2.tipo, newType);

						if (out == 2){
							string newLabel = nextTMP();
							$$.declaracao += dcl($2.tipo, newLabel);
							$$.traducao += cst(newLabel, $2.tipo, $4.label);
							$4.label = newLabel;
						}

						// Atribuir a Variável o valor da Expressão 1
						//$1.label = getLabel($1.label);
						$$.traducao += cmd(var + " = " + $4.label);

						// Imprimir Label Inicio
						$$.traducao += lbl(lblInicio);

						// Imprimir Expressao 2
						$$.declaracao += $7.declaracao;
						$$.traducao += $7.traducao;

						// Imprimir Comparacao
						string tmpExp = nextTMP();
						$$.declaracao += dcl(TK_TIPO_BOOL, tmpExp);
						$$.traducao += cmd(tmpExp + " = " + var + " " + $6.traducao + " " + $7.label);

						// Negando Expressão
						string tmpExpNegada = nextTMP();
						$$.declaracao += dcl(TK_TIPO_BOOL, tmpExpNegada);
						$$.traducao += cmd(tmpExpNegada + " = !" + tmpExp);

						// Imprimir Salto Condicional para Label Fim
						$$.traducao += cmd("if (" + tmpExpNegada + ") goto " + lblFim);

						// Imprimir Bloco
						$$.declaracao += $9.declaracao;
						$$.traducao += $9.traducao;

						// Criar Temporária de Incremento
						string tmpIncremento = nextTMP();
						$$.declaracao += dcl($2.tipo, tmpIncremento);
						$$.traducao += cmd (tmpIncremento + " = 1");

						// Realizar soma
						string tmpSoma = nextTMP();
						$$.declaracao += dcl($2.tipo, tmpSoma);
						$$.traducao += cmd (tmpSoma + " = " + var + " + " + tmpIncremento);

						// Incrementar Variável
						$$.traducao += cmd (var + " = " + tmpSoma);

						// Salto Incondicional para Label Inicio
						$$.traducao += cmd ("goto " + lblInicio);

						// Imprimir Label Fim
						$$.traducao += lbl(lblFim);

					} 
					;

CMD_SWITCH			: TK_SWITCH '(' TK_ID ')' '{' BLOCO_SWITCH '}'
					{
						$$.declaracao = $6.declaracao;
						$$.traducao = $6.traducao;

						vector<string> s = split($6.label, '&');

						cout << "\n ->" + $6.label + "\n";

						for (int i = 0; i < s.size(); i++)
						{
							cout << "----> " + s[i] + "\n";
						}
					}
					;

BLOCO_SWITCH		: BLOCO_SWITCH EXP_CASE
					{
						$$.declaracao = $1.declaracao + $2.declaracao;
						$$.traducao = $1.traducao + $2.traducao;

						$$.tipo = $2.tipo;
						$$.label = $1.label + $2.label + "&";
					}
					| 
					;
				
EXP_CASE			: TK_CASE TK_LITERAL BLOCO
					{
						$$.declaracao = $3.declaracao;

						string lblCase = nextLBL();
						$$.traducao = lbl(lblCase);
						$$.traducao += $3.traducao;

						$$.tipo = $2.tipo;
						$$.label = $2.traducao + "@" + lblCase;
						
					}
					| TK_DEFAULT BLOCO
					{
						$$.traducao = lbl(nextLBL()) + $2.traducao;
						$$.declaracao = $2.declaracao;
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

OP_COMPARATIVOS		: OP_RELACIONAL
					{
						$$.traducao = $1.traducao;
					}
					| TK_OP_IGUALDADE
					| TK_OP_DESIGUALDADE
					;



%%

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
	simbolo* simbolo = getSimbolo(s);

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
	return espacamentoDeIndexacao + label + ":\n";
}

string cst (string label1, int tipo, string label2)
{
	return cmd(label1 + " = " + "(" + typeName(tipo) + ")" + label2);
}

void setTipo(string id, int tipo)
{
	getSimbolo(id)->tipo = tipo;
}


int getTipo(string id)
{
	return getSimbolo(id)->tipo;
}

string getLabel(string id)
{
	return getSimbolo(id)->label;
}

bool isDeclared(string id)
{
	return getSimbolo(id) != NULL;
}


void novoSimbolo(string id, string lbl, int tipo)
{
	simbolo novoSimbolo;

	novoSimbolo.label = lbl;
	novoSimbolo.tipo = tipo;

	addSimbolo(id, novoSimbolo);
}

void printHash()
{
	unordered_map<string, simbolo>:: iterator itr;
	Contexto* aux = contextoAtual;

	cout << "\n== Pilha de Contexto ======== \n"; 

	while (aux != NULL){
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
			it = aux.insert(it, palavra);
			palavra = "";
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

void empilharContexto()
{
	espacamentoDeIndexacao.append("\t");

	Contexto* novoCtx = novoContexto();

	novoCtx->anterior = contextoAtual;

	contextoAtual = novoCtx;
}

void desempilharContexto()
{

	espacamentoDeIndexacao = espacamentoDeIndexacao.substr(0, espacamentoDeIndexacao.size() - 1);

	Contexto* aux = contextoAtual->anterior;

	free(contextoAtual);

	contextoAtual = aux;
}

void addSimbolo(string id, simbolo s)
{
	contextoAtual->simbolos[id] = s;
}

simbolo* getSimbolo(string id)
{
	
	Contexto* it = contextoAtual;

	while (it != NULL)
	{

		if (it->simbolos.find(id) != it->simbolos.end())
		{
			return &(it->simbolos[id]);
		} 
		else
		{
			it = it->anterior;
		}
	}


	//yyerror("Variável '" + id + "' nao declarada.");
	return NULL;
}