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
void checkLabel(string);

%}

%token TK_NUM
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_DOUBLE
%token TK_FIM TK_ERROR

%start S

%right '='
%left '+' '-'
%left '*' '/'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "\n/*Compilador FOCA*/\n\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n#include <unordered_map>\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
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
				//count--;
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
				cout << "-- " + $$.label + "\n";
				$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
			}
			| TK_ID
			{
				checkLabel($1.label);
				$$.traducao = "";
			}
			;

ATRIBUICAO	: TK_ID '=' E
			{
				$$.traducao =  $3.traducao + "\t" +  $1.label + " = " + $3.label + ";\n";
				tabela_simbolos[$1.label] = $1.tipo;
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
