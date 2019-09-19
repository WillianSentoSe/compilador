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

int count = 0;
int linha = 1;
unordered_map<string, int> tabela_simbolos;

int yylex(void);
void yyerror(string);
string nextLabel();
string typeName(int);
bool checarTipo(int, int);
void checkLabel(string);

%}

%token TK_NUM TK_CHAR
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_DOUBLE TK_TIPO_STRING TK_TIPO_CHAR TK_TIPO_INDEFINIDO
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
			;

E 			: E OPERADOR E
			{
				checarTipo($1.tipo, $3.tipo);
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.label + " = " + $1.label + " " + $2.traducao + " " + $3.label + ";\n";
			}
			| '(' E ')'
			{
				$$.label = $2.label;
				$$.traducao = $2.traducao;
			}
			| TK_NUM
			{	
				$$.label = nextLabel();
				$$.traducao = "\t" + typeName($1.tipo) + " " + $$.label + " = " + $1.traducao + ";\n";
			}
			| TK_ID
			{
				checkLabel($1.label);
				$$.tipo = $1.tipo;
				$$.traducao = "";
			}
			;

ATRIBUICAO	: TK_ID '=' E
			{
				$$.traducao = $3.traducao + "\t" +  $1.label + " = " + $3.label + ";\n";
				//checarTipo($1.tipo, $3.tipo);
				tabela_simbolos[$1.label] = $3.tipo;
			}
			| TK_ID '=' TK_CHAR
			{
				$$.traducao = "\t" + typeName($3.tipo) + " " + $1.label + " = " + $3.traducao + ";\n";
				tabela_simbolos[$1.label] = $3.tipo;
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
	return "$_temp" + std::to_string(count++);
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
	unordered_map<string,int>::const_iterator busca = tabela_simbolos.find(s);

	if (busca == tabela_simbolos.end())
	{
		yyerror("\n [LINHA " + to_string(linha) + "] (!) \n | Variavel '" + s + "' nao foi declarada.\n"); 
	}
	else 
	{
		cout << "\n [LINHA " << to_string(linha) << "]\n | Variavel declarada encontrada '" << busca->first << "' do Tipo " << busca->second << ".\n";
	}
}
