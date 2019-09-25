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
	string traducao;
	int tipo;
};

struct Simbolo
{
	int tipo;
	int escopo;
	int classe;
	bool ativo;
};

int count = 0;
int linha = 1;
unordered_map<string, Simbolo> tabela_simbolos;

int yylex(void);
void yyerror(string);
string nextLabel();
string typeName(int, bool = false);
bool checarTipo(int, int);
void checkLabel(string);
int convertType(int, int);

void setTipo(string, int);
int getTipo(string);
int getEscopo(string);
int getClasse(string);
bool isAtivo(string);
bool isDeclared(string);

%}

%token TK_LITERAL TK_ID
%token TK_MAIN TK_VAR 
%token TK_TIPO_INDEFINIDO TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_TIPO_STRING
%token TK_CLASSE_VARIAVEL TK_CLASSE_FUNCAO
%token TK_FIM TK_ERROR

%start S

%right '='
%left '+' '-'
%left '*' '/'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "\n/*Compilador Ç*/\n\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#include <unordered_map>\n\n#define true 1\n#define false 0\n\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

COMANDO 	: ATRIBUICAO ';'
			| CMD_DECLARACOES ';'
			;

E 			: E OPERADOR E
			{
				//checarTipo($1.tipo, $3.tipo);
				//$$.tipo = $1.tipo;				// PROVISORIO

				$$.tipo = convertType($1.tipo, $3.tipo);
				string typeCast = "(" + typeName($$.tipo) + ")";

				$$.label = nextLabel();
				string declaracao = typeName($$.tipo, false) + " ";
				$$.traducao = $1.traducao + $3.traducao + "\t" + declaracao + $$.label + " = " + typeCast + $1.label + " " + $2.traducao + " " + typeCast + $3.label + ";\n";
			}
			| '(' E ')'
			{
				$$.label = $2.label;
				$$.traducao = $2.traducao;
				$$.tipo = $2.tipo;
			}
			| TK_LITERAL
			{	
				$$.label = nextLabel();
				$$.traducao = "\t" + typeName($1.tipo, false) + " " + $$.label + " = " + $1.traducao + ";\n";
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

				$$.traducao = "";
			}
			;

ATRIBUICAO	: TK_ID '=' E
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
					declaracao = typeName($1.tipo) + " ";
				}

				int newType = convertType($1.tipo, $3.tipo);
				checarTipo($1.tipo, newType);
				string typeCast = "(" + typeName(newType) + ")";

				$$.traducao = $3.traducao + "\t" + declaracao + $1.label + " = " + typeCast + $3.label + ";\n";
			}

CMD_DECLARACOES		: TK_VAR LIST_DECLARACOES
					{
						$$.traducao = $2.traducao;
					}
					;

LIST_DECLARACOES	: DECLARACAO ',' LIST_DECLARACOES
					{
						$$.traducao = $1.traducao + $3.traducao;
					}
					| DECLARACAO
					{
						$$.traducao = $1.traducao;
					}
					;

DECLARACAO 			: TK_ID
					{
						tabela_simbolos[$1.label] = {TK_TIPO_INDEFINIDO, -1, -1, true};
						$$.traducao = "";
					}
					| TK_ID '=' E
					{
						if (isDeclared($1.label))
						{
							yyerror("Variável '" + $1.label + "' já foi declarada.");
						}

						checarTipo($1.tipo, $3.tipo);

						$1.tipo = $3.tipo;
						string declaracao = typeName($1.tipo) + " ";

						tabela_simbolos[$1.label] = {$1.tipo, -1, -1, true};

						$$.traducao = $3.traducao + "\t" + declaracao + $1.label + " = " + $3.label + ";\n";
					}
					;

OPERADOR 	: '+'
			| '-'
			| '*'
			| '/'
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

bool checarTipo (int type1, int type2)
{
	if (type1 != TK_TIPO_INDEFINIDO && type2 != TK_TIPO_INDEFINIDO && type1 != type2)
	{
		yyerror("Conversão inválida entre (" + typeName(type1, true) + ") e (" + typeName(type2, true) +").");
	}

	return true;
}

int convertType (int type1, int type2)
{
	int typeIndex1 = type1 - TK_TIPO_INDEFINIDO;
	int typeIndex2 = type2 - TK_TIPO_INDEFINIDO;

	int newType = tab_conversao[typeIndex1][typeIndex2];

	if (newType == TK_ERROR)
	{
		yyerror("Conversão inválida entre (" + typeName(type1, true) + ") e (" + typeName(type2, true) +").");
	}

	return newType;
}

void checkLabel(string s)
{
	unordered_map<string, Simbolo>::const_iterator busca = tabela_simbolos.find(s);

	if (busca == tabela_simbolos.end())
	{
		yyerror("Variável '" + s + "' nao foi declarada."); 
	}
	else
	{
		//cout << "\n [LINHA " << to_string(linha) << "]\n | Variavel declarada encontrada '" << busca->first << "' (" << "typeName(busca->second.tipo)" << ").\n";
	}
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