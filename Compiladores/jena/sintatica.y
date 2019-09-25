%{
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

#define YYSTYPE atributos

using namespace std;
int global = 0, linha = 1;

struct atributos
{
	string label;
	string traducao;
	int tipo;
};

struct tabela
{
	int tipo;
	bool ativo;
};

unordered_map<string, tabela> tab_simb;
string tokenToType(int token);
int yylex(void);
void yyerror(string);
string genLabel();
void findAtribuicao(string);
%}

%token TK_NUM TK_CHAR TK_BOOL
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL
%token TK_FIM TK_ERROR

%start S

%right '='
%left '+' 

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\n#define true 1\n#define false 0\n\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
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
			{
				$$.traducao = $1.traducao;
				$$.tipo = $1.tipo;
			}
			| ATRIBUICAO';'
			{
				$$.tipo = $1.tipo;
				$$.traducao = $1.traducao;
			}
			;

E 			: E '+' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
				$$.tipo = $1.tipo;
			}
			| E '-' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
				$$.tipo = $1.tipo;
			}
			| E '*' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
				$$.tipo = $1.tipo;
			}
			| E '/' E
			{
				$$.label = genLabel();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
				$$.tipo = $1.tipo;
			}
			| '(' E ')'
			{
				$$.label = $2.label;
				$$.traducao = $2.traducao;
				$$.tipo = $2.tipo;
			}
			| TK_NUM
			{
				$$.label = genLabel();
				$$.traducao = "\t" + tokenToType($1.tipo) + " " + $$.label + " = " + $1.traducao + ";\n";
				$$.tipo = $1.tipo;

			}
			| TK_CHAR
			{
				$$.label = genLabel();
				$$.traducao = "\t" + tokenToType($1.tipo) + " " + $$.label + " = " + $1.traducao + ";\n";
				$$.tipo = $1.tipo;
			}
			| TK_BOOL
			{
				$$.label = genLabel();
				$$.traducao = "\t" + tokenToType($1.tipo) + " " + $$.label + " = " + $1.traducao + ";\n";
				$$.tipo = $1.tipo;
			}
			| TK_ID
			{
				findAtribuicao($1.label);
				$$.tipo = tab_simb[$1.label].tipo;
				$$.traducao = "";
			}
			;

ATRIBUICAO:	 TK_ID '=' E
			{	
				$$.traducao = $3.traducao + "\t" + tokenToType($3.tipo) +" "+ $1.label + " = " + $3.label + ";\n";
				tab_simb[$1.label] = {$3.tipo, true};
				$1.tipo = $3.tipo;
			}
			;


%%

#include "lex.yy.c"
#include <unordered_map>
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

string genLabel(){

	string s = "$_temp";
	s = s + to_string(global);
	global++;

	return s;
}

void findAtribuicao(string s){
	if(tab_simb.find(s) == tab_simb.end()){
		yyerror("Erro na linha " + to_string(linha) + ": variavel " + s + " not declared");
	}

}

string tokenToType(int token){

	string str;

	switch (token)
	{
		case TK_TIPO_INT:
		case TK_TIPO_BOOL:		str = "int"; 		break;
		case TK_TIPO_FLOAT: 	str = "float"; 		break;
		case TK_TIPO_CHAR: 		str = "char"; 		break;
		default:				str = "undefined";	break;
	}

	return str;
}