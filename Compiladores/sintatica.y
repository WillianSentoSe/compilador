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
string typeName(int);
bool checarTipo(int, int);
void checkLabel(string);

void setTipo(string, int);
int getTipo(string);
int getEscopo(string);
int getClasse(string);
bool isAtivo(string);
bool isDeclared(string);

%}

%token TK_LITERAL TK_CHAR
%token TK_MAIN TK_VAR TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_DOUBLE TK_TIPO_STRING TK_TIPO_CHAR TK_TIPO_INDEFINIDO
%token TK_CLASSE_VARIAVEL TK_CLASSE_FUNCAO
%token TK_FIM TK_ERROR

%start S

%right '='
%left '+' '-'
%left '*' '/'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "\n/*Compilador Ç*/\n\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#include <unordered_map>\n\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
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

COMANDO 	: E ';'
			| ATRIBUICAO ';'
			| DECLARACAO ';'
			;

E 			: E OPERADOR E
			{
				checarTipo($1.tipo, $3.tipo);
				$$.tipo = $1.tipo;		// PROVISORIO
				$$.label = nextLabel();
				string declaracao = typeName($$.tipo) + " ";
				$$.traducao = $1.traducao + $3.traducao + "\t" + declaracao + $$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label + ";\n";
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
				$$.traducao = "\t" + typeName($1.tipo) + " " + $$.label + " = " + $1.traducao + ";\n";
				$$.tipo = $1.tipo;
			}
			| TK_ID
			{
				checkLabel($1.label);
				$$.tipo = getTipo($1.label);

				if ($$.tipo == TK_TIPO_INDEFINIDO)
				{
					yyerror("\n [LINHA " + to_string(linha) + "] (!) \n | A variável '" + $1.label + "' possui valor indefinido.\n");
				}

				$$.traducao = "";
			}
			;

ATRIBUICAO	: TK_ID '=' E
			{
				string declaracao = ""; // TEMPORARIO

				if (!isDeclared($1.label))
				{
					yyerror("\n [LINHA " + to_string(linha) + "] (!) \n | Variável '" + $1.label + "' nao declarada.\n");
				}

				if (getTipo($1.label) == TK_TIPO_INDEFINIDO)
				{
					$1.tipo = $3.tipo;
					setTipo($1.label, $1.tipo);
					declaracao = typeName($1.tipo) + " ";
				}

				$$.traducao = $3.traducao + "\t" + declaracao + $1.label + " = " + $3.label + ";\n";
			}

DECLARACAO 	: TK_VAR TK_ID
			{
				tabela_simbolos[$2.label] = {TK_TIPO_INDEFINIDO, -1, -1, true};
			}
			| TK_VAR TK_ID '=' E
			{

				if (isDeclared($1.label))
				{
					yyerror("\n [LINHA " + to_string(linha) + "] (!) \n | Variável '" + $1.label + "' já foi declarada.\n");
				}

				$2.tipo = $4.tipo;
				string declaracao = typeName($2.tipo) + " ";

				tabela_simbolos[$2.label] = {$2.tipo, -1, -1, true};

				$$.traducao = $4.traducao + "\t" + declaracao + $2.label + " = " + $4.label + ";\n";
			}
			;

OPERADOR 	: '+'
			| '-'
			| '*'
			| '/'
			;



%%

#include "lex.yy.c"
//#include <unordered_map>

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}

string nextLabel()
{
	return "$_temp" + to_string(count++);
}

string typeName (int token)
{
	string str;

	switch (token)
	{
		case TK_TIPO_INT: 		str = "int"; 		break;
		case TK_TIPO_FLOAT: 	str = "float"; 		break;
		case TK_TIPO_CHAR: 		str = "char"; 		break;
		default:				str = "undefined";	break;
	}

	return str;
}

bool checarTipo (int tipo1, int tipo2)
{
	if (tipo1 != tipo2)
	{
		yyerror("\n [LINHA " + to_string(linha) + "] (!) \n | Conversao implícita encontrada entre (" + typeName(tipo1) + ") e (" + typeName(tipo2) +").\n | É necessario explicitar uma conversão.\n");
	}

	return true;
}

void checkLabel(string s)
{
	unordered_map<string, Simbolo>::const_iterator busca = tabela_simbolos.find(s);

	if (busca == tabela_simbolos.end())
	{
		yyerror("\n [LINHA " + to_string(linha) + "] (!) \n | Variavel '" + s + "' nao foi declarada.\n"); 
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