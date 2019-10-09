%{
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string declaracao;
	string traducao;
	int tipo;
};

struct simbolo
{
	int tipo;
	int escopo;
	int classe;
	bool ativo;
};

int count = 0;
int linha = 1;
unordered_map<string, simbolo> tabela_simbolos;

int yylex(void);
void yyerror(string);
string nextLabel();
string typeName(int, bool = false);
bool checkTypes(int, int);
void checkLabel(string);
int convertType(int, int, int*);
void neoConvertType (atributos*, atributos*, atributos*);

string cmd(string);
string dcl(int, string);
string cst (string, int, string);

void setTipo(string, int);
int getTipo(string);
int getEscopo(string);
int getClasse(string);
bool isAtivo(string);
bool isDeclared(string);

%}

%token TK_LITERAL TK_ID
%token TK_MAIN TK_VAR TK_TIPO
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
						cout << "int main(void)\n{\n" << $5.traducao << "\treturn 0;\n}\n"; 
					}
					;

BLOCO				: '{' COMANDOS '}'
					{
						$$.traducao = $2.declaracao + "\n" + $2.traducao;
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

COMANDO 			: ATRIBUICAO ';'
					| CMD_DECLARACOES ';'
					;

EXP_SIMPLES			: TK_LITERAL
					{	
						$$.label = nextLabel();
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

						string newLabel = nextLabel();
						$$.declaracao = $3.declaracao + dcl($1.tipo, newLabel);
						$$.traducao = $3.traducao + cst(newLabel, $1.tipo, $3.label);
						$$.label = newLabel;
					}
					;
					
EXP_NOT				: EXP_SIMPLES
					| TK_OP_NOT EXP_NOT
					{
						$$.label = nextLabel();
						$$.tipo = TK_TIPO_BOOL;
						string declaracao = typeName($$.tipo, false) + " ";
						$$.traducao = $2.traducao + "\t" + declaracao + $$.label + " = !" + $2.label + ";\n";
					}

EXP_ARITMETICA_MUL	: EXP_NOT
					| EXP_ARITMETICA_MUL TK_OP_MUL EXP_NOT
					{
						$$.label = nextLabel();
						neoConvertType(&$$, &$1, &$3);
						$$.traducao = $1.traducao + $3.traducao + cmd ($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_ARITMETICA_ADD	: EXP_ARITMETICA_MUL
					| EXP_ARITMETICA_ADD TK_OP_ADD EXP_ARITMETICA_MUL
					{
						$$.label = nextLabel();
						neoConvertType(&$$, &$1, &$3);
						$$.traducao = $1.traducao + $3.traducao + cmd ($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_RELACIONAL		: EXP_ARITMETICA_ADD
					| EXP_RELACIONAL OP_RELACIONAL EXP_ARITMETICA_ADD
					{
						/*
						int out;

						int newType = convertType($1.tipo, $3.tipo, &out);
						string typeCast1 = (out == 1)? "(" + typeName(newType) + ")" : "";
						string typeCast2 = (out == 2)? "(" + typeName(newType) + ")" : "";

						$$.tipo = TK_TIPO_BOOL;
						$$.label = nextLabel();
						$$.declaracao = $1.declaracao + $3.declaracao + dcl($$.tipo, $$.label);

						*/

						$$.label = nextLabel();
						neoConvertType(&$$, &$1, &$3);
						$$.tipo = TK_TIPO_BOOL;
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_IGUALDADE		: EXP_RELACIONAL
					| EXP_IGUALDADE TK_OP_IGUALDADE EXP_RELACIONAL
					{
						/*
						int out;

						int newType = convertType($1.tipo, $3.tipo, &out);
						string typeCast1 = (out == 1)? "(" + typeName(newType) + ")" : "";
						string typeCast2 = (out == 2)? "(" + typeName(newType) + ")" : "";
						
						$$.tipo = TK_TIPO_BOOL;
						$$.label = nextLabel();
						$$.declaracao = $1.declaracao + $3.declaracao + dcl($$.tipo, $$.label);
						*/

						$$.label = nextLabel();
						neoConvertType(&$$, &$1, &$3);
						$$.tipo = TK_TIPO_BOOL;
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_AND 			: EXP_IGUALDADE
					| EXP_AND TK_OP_AND EXP_IGUALDADE
					{
						int out;

						$$.tipo = convertType($1.tipo, $3.tipo, &out);
						string typeCast1 = (out == 1)? "(" + typeName($$.tipo) + ")" : "";
						string typeCast2 = (out == 2)? "(" + typeName($$.tipo) + ")" : "";

						$$.tipo = TK_TIPO_BOOL;
						$$.label = nextLabel();
						$$.declaracao = $1.declaracao + $3.declaracao + dcl($$.tipo, $$.label);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_XOR				: EXP_AND
					| EXP_XOR TK_OP_XOR EXP_AND
					{
						int out;

						$$.tipo = convertType($1.tipo, $3.tipo, &out);
						string typeCast1 = (out == 1)? "(" + typeName($$.tipo) + ")" : "";
						string typeCast2 = (out == 2)? "(" + typeName($$.tipo) + ")" : "";

						$$.tipo = TK_TIPO_BOOL;
						$$.label = nextLabel();
						$$.declaracao = $1.declaracao + $3.declaracao + dcl($$.tipo, $$.label);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_IOR				: EXP_XOR
					| EXP_IOR TK_OP_IOR EXP_XOR
					{
						int out;

						$$.tipo = convertType($1.tipo, $3.tipo, &out);
						string typeCast1 = (out == 1)? "(" + typeName($$.tipo) + ")" : "";
						string typeCast2 = (out == 2)? "(" + typeName($$.tipo) + ")" : "";

						$$.tipo = TK_TIPO_BOOL;
						$$.label = nextLabel();
						$$.declaracao = $1.declaracao + $3.declaracao + dcl($$.tipo, $$.label);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_LOGICAL_AND  	: EXP_IOR
					| EXP_LOGICAL_AND TK_OP_LOGICAL_AND EXP_IOR
					{
						int out;

						$$.tipo = convertType($1.tipo, $3.tipo, &out);
						string typeCast1 = (out == 1)? "(" + typeName($$.tipo) + ")" : "";
						string typeCast2 = (out == 2)? "(" + typeName($$.tipo) + ")" : "";

						$$.tipo = TK_TIPO_BOOL;
						$$.label = nextLabel();
						$$.declaracao = $1.declaracao + $3.declaracao + dcl($$.tipo, $$.label);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXP_LOGICAL_OR		: EXP_LOGICAL_AND
					| EXP_LOGICAL_OR TK_OP_LOGICAL_OR EXP_LOGICAL_AND
					{
						int out;

						$$.tipo = convertType($1.tipo, $3.tipo, &out);
						string typeCast1 = (out == 1)? "(" + typeName($$.tipo) + ")" : "";
						string typeCast2 = (out == 2)? "(" + typeName($$.tipo) + ")" : "";

						$$.tipo = TK_TIPO_BOOL;
						$$.label = nextLabel();
						$$.declaracao = $1.declaracao + $3.declaracao + dcl($$.tipo, $$.label);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
					}
					;

EXPRESSAO			: EXP_LOGICAL_OR
					{
						$$.declaracao = $1.declaracao;
						$$.traducao = $1.traducao;
						$$.label = $1.label;
						$$.tipo = $1.tipo;
					}
					;

ATRIBUICAO			: TK_ID '=' EXPRESSAO
					{
						string declaracao = ""; // TEMPORARIO

						if (!isDeclared($1.label))
						{
							yyerror("Variável '" + $1.label + "' nao declarada.");
						}

						$1.tipo = getTipo($1.label);

						if ($1.tipo == TK_TIPO_INDEFINIDO)
						{
							$1.tipo = $3.tipo;
							setTipo($1.label, $1.tipo);
							declaracao = typeName($1.tipo) + " " + $2.label + ";\n\t";
						}

						int out;

						int newType = convertType($1.tipo, $3.tipo, &out);
						checkTypes($1.tipo, newType);
						string typeCast = (out == 2) ? "(" + typeName(newType) + ")" : "";

						$$.declaracao = $3.declaracao + dcl($1.tipo, $1.label);
						$$.traducao = $3.traducao + cmd($1.label + " = " + $3.label);

						/***$$.traducao = $3.traducao + "\t" + declaracao + $1.label + " = " + typeCast + $3.label + ";\n";***/
					}
					;

CMD_DECLARACOES		: TK_VAR LIST_DECLARACOES
					{
						$$.declaracao = $2.declaracao;
						$$.traducao = $2.traducao;
					}
					;

LIST_DECLARACOES	: DECLARACAO ',' LIST_DECLARACOES
					{
						$$.declaracao = $1.declaracao + $3.declaracao;
						$$.traducao = $1.traducao + $3.traducao;
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

						tabela_simbolos[$1.label] = {TK_TIPO_INDEFINIDO, -1, -1, true};
						//$$.traducao = "";
					}
					| TK_ID '=' EXPRESSAO
					{
						if (isDeclared($1.label))
							yyerror("Variável '" + $1.label + "' já foi declarada.");

						$1.tipo = $3.tipo;
						string declaracao = typeName($1.tipo) + " " + $1.label + ";\n";

						tabela_simbolos[$1.label] = {$1.tipo, -1, -1, true};

						$$.declaracao = $3.declaracao + dcl($1.tipo, $1.label);
						$$.traducao = $3.traducao + cmd($1.label + " = " + $3.label);
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

						/*	TK_TIPO_INDEFINIDO	, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_TIPO_BOOL		*/
int tab_conversao[5][5] = 	{	
							{TK_TIPO_INDEFINIDO	, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_TIPO_BOOL		}, /* TK_TIPO_INDEFINIDO 	*/
							{TK_ERROR			, TK_TIPO_INT		, TK_TIPO_FLOAT		, TK_TIPO_CHAR		, TK_ERROR			}, /* TK_TIPO_INT 			*/
							{TK_ERROR			, TK_TIPO_FLOAT		, TK_TIPO_FLOAT		, TK_ERROR			, TK_ERROR			}, /* TK_TIPO_FLOAT 		*/
							{TK_ERROR			, TK_TIPO_CHAR		, TK_ERROR			, TK_TIPO_CHAR		, TK_ERROR			}, /* TK_TIPO_CHAR 			*/
							{TK_ERROR			, TK_TIPO_INT		, TK_ERROR			, TK_ERROR			, TK_TIPO_BOOL		}, /* TK_TIPO_BOOL 			*/
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

string nextLabel()
{
	return "$_temp" + to_string(count++);
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

void neoConvertType (atributos* $$,atributos* $1, atributos* $2)
{
	int out;
	int numTipo = convertType($1->tipo, $2->tipo, &out);
	string declaracaoConvertida = "";

	// Se algum valor precisar ser convertido
	if (out != 0)
	{
		string tipo = typeName(numTipo);
		string label = nextLabel();
		declaracaoConvertida = dcl(numTipo, label);

		//Caso $1 precise ser convertido
		if (out == 1)
		{
			$1->traducao = $1->traducao + cmd(label + " = (" + tipo + ")" + $1->label);
			$1->label = label;
		}

		//Caso $2 precise ser convertido
		if (out == 2)
		{
			$2->traducao = $2->traducao + cmd(label + " = (" + tipo + ")" + $2->label);
			$2->label = label;
		}
	}

	//Declara todas as variáveis
	$$->tipo = numTipo;
	$$->declaracao = $1->declaracao + $2->declaracao + dcl($$->tipo, $$->label) + declaracaoConvertida;
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

string cmd (string s)
{
	return "\t" + s + ";\n";
}

string dcl (int tipo, string label)
{
	return cmd(typeName(tipo) + "\t" + label);
}

string cst (string label1, int tipo, string label2)
{
	return cmd(label1 + " = " + "(" + typeName(tipo) + ")" + label2);
}

void setTipo(string label, int tipo)
{
	tabela_simbolos[label].tipo = tipo;
}

int getTipo(string label)
{
	return tabela_simbolos[label].tipo;
}

int getEscopo(string label)
{
	return tabela_simbolos[label].escopo;
}

int getClasse(string label)
{
	return tabela_simbolos[label].classe;
}

bool isAtivo(string label)
{
	return tabela_simbolos[label].ativo;
}

bool isDeclared(string label)
{
	return tabela_simbolos.find(label) != tabela_simbolos.end();
}