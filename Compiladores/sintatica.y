%{
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

%}

%token TK_LITERAL TK_ID
%token TK_MAIN TK_VAR TK_DEF TK_TIPO TK_IF TK_ELSE TK_WHILE TK_DO TK_FOR TK_SWITCH TK_CASE TK_BREAK TK_CONTINUE TK_RETORNO TK_DEFAULT
%token TK_OP_IGUALDADE TK_OP_DESIGUALDADE TK_OP_MAIORIGUAL TK_OP_MENORIGUAL TK_OP_NOT TK_OP_LOGICAL_AND TK_OP_AND TK_OP_LOGICAL_OR TK_OP_XOR TK_OP_IOR TK_OP_ADD TK_OP_MUL TK_OP_SUB 
%token TK_OP_UN_ADD TK_OP_UN_SUB
%token TK_TIPO_INDEFINIDO TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_TIPO_STRING TK_TIPO_VETOR TK_TIPO_VOID
%token TK_CLASSE_VARIAVEL TK_CLASSE_FUNCAO
%token TK_FIM TK_ERROR
%token TK_CTX_BLOCO TK_CTX_IF TK_CTX_WHILE TK_CTX_FOR TK_CTX_CASE
%token TK_OUT TK_IN

%start S

%right '='
%left '+' '-'
%left '*' '/'

%%

S 					: COMANDOS_EXTERNOS TK_TIPO TK_MAIN '(' ')' BLOCO
					{
						cout << "\n/*Compilador Ç*/\n";
						cout << "\n#include <stdio.h>";
						cout << "\n#include <stdlib.h>";
						cout << "\n#include <string.h>\n\n";
						cout << "#define true 1\n#define false 0\n\n";
						cout << $1.declaracao + "\n" << $1.traducao << $1.desalocacao;
						cout << "int main(void)\n{\n" << $6.declaracao + "\n" + $6.traducao + $6.desalocacao << "\n\treturn 0;\n}\n";
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
					| COMANDO
					;

DCL_FUNCAO			: TK_DEF TK_ID '(' ')' { empilharNovaFuncao($2.label); } BLOCO
					{

						if (funcaoAtual == NULL) yyerror("NÃO ERA PRA ISSO TER ACONTECIDO AAAAA...");

						$$.tipo = funcaoAtual->tipo;
						$$.label = funcaoAtual->identificador;

						//addFuncao($2.label, funcaoAtual);

						$$.declaracao = typeName($$.tipo) + " " + $$.label + " ();\n";

						$$.traducao = typeName($$.tipo) + " " + $$.label + " ()\n{\n";
						$$.traducao += $6.declaracao + $6.traducao + "\treturn;\n}\n\n";
					}
					| TK_DEF TK_ID '(' { empilharNovaFuncao($2.label); empilharContexto(TK_CTX_BLOCO);} LISTA_DCL_PARAM ')' BLOCO
					{
						if (funcaoAtual == NULL) yyerror("NÃO ERA PRA ISSO TER ACONTECIDO AAAAA...");

						$$.tipo = funcaoAtual->tipo;
						$$.label = funcaoAtual->identificador;

						//addFuncao($2.label, funcaoAtual);
						$$.declaracao = typeName($$.tipo) + " " + $$.label + " (" + $5.traducao + ");\n";

						$$.traducao = typeName($$.tipo) + " " + $$.label + " (" + $5.traducao + ")\n{\n";
						$$.traducao += $7.declaracao + $7.traducao + "\treturn;\n}\n\n";

						desempilharContexto();
					}
					;

COMANDOS_EXTERNOS	: COMANDO_EXTERNO COMANDOS_EXTERNOS
					{
						$$.declaracao = $1.declaracao + $2.declaracao;
						$$.traducao = $1.traducao + $2.traducao;
						$$.desalocacao = $1.desalocacao + $2.desalocacao;
					}
					|
					{
						$$.traducao = "";
						$$.declaracao = "";
						$$.desalocacao = "";
					}
					;

COMANDO_EXTERNO 	: DCL_FUNCAO
					| COMANDOS
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
						$$.desalocacao = "";
					}
					;

COMANDO 			: CMD_DECLARACOES ';'
					| CMD_FUNCAO
					| CMD_RETORNO
					| CMD_IF
					| CMD_WHILE
					| CMD_DOWHILE
					| CMD_FOR
					| CMD_SWITCH
					| CMD_BREAK
					| CMD_CONTINUE
					| CMD_OUT
					| CMD_UNARIO ';'
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
					| CMD_UNARIO
					{
						$$.traducao = $1.traducao;
						$$.declaracao = $1.declaracao;
					}
					;

LISTA_PARAM			: LISTA_PARAM ',' EXPRESSAO
					{
						$$.traducao = $1.traducao + $3.traducao;
						$$.declaracao = $1.declaracao + $3.declaracao;
						$$.desalocacao = $1.desalocacao + $3.desalocacao; 
						$$.label = $1.label + ", " + $3.label;
						$$.dinamico = $1.dinamico || $2.dinamico;

						$$.indexLista = auxFuncao->argumentosPassados++;

						if (auxFuncao->argumentosPassados > auxFuncao->tipoParam.size())
							yyerror("A Função requer " + to_string(auxFuncao->tipoParam.size()) + " argumentos. Foram passados " + to_string(auxFuncao->argumentosPassados) + " argumentos");

						if (!auxFuncao) yyerror("Funcao não declarada");
						if(auxFuncao->tipoParam[$$.indexLista] != $3.tipo)
						{
							yyerror("O tipo do argumento '" + to_string($$.indexLista + 1) + "' da função esperado é (" + typeName(auxFuncao->tipoParam[$$.indexLista]) + "). O tipo passado foi ("+ typeName($3.tipo) + ").");
						}
					}
					| EXPRESSAO
					{
						$$.traducao = $1.traducao;
						$$.declaracao = $1.declaracao;
						$$.desalocacao = $1.desalocacao; 
						$$.label = $1.label;
						$$.tipo = $1.tipo;

						if (!auxFuncao) yyerror("Funcao não declarada");

						auxFuncao->argumentosPassados = 1;
						$$.indexLista = 0;

						if(auxFuncao->tipoParam[$$.indexLista] != $1.tipo)
						{
							yyerror("O tipo do argumento '"+ to_string($$.indexLista + 1) +"' da função esperado é (" + typeName(auxFuncao->tipoParam[$$.indexLista]) + "). O tipo passado foi ("+ typeName($1.tipo) +").");
						}

						$$.dinamico = $1.dinamico;
					}
					;

LISTA_DCL_PARAM		: TK_TIPO TK_ID ',' LISTA_DCL_PARAM
					{

						if (isDeclared($2.label))
						{
							yyerror("Variável '" + $2.label + "' Já foi declarada anteriormente.");
						}

						funcaoAtual->it = funcaoAtual->tipoParam.insert(funcaoAtual->it, $1.tipo);

						string var = nextVAR();
						novoSimbolo($2.label, var, $1.tipo);
						$$.traducao = typeName($1.tipo) + " " + getLabel($2.label) + ", " + $4.traducao;
					}
					| TK_TIPO TK_ID
					{

						if (isDeclared($2.label))
						{
							yyerror("Variável '" + $2.label + "' Já foi declarada anteriormente.");
						}

						funcaoAtual->it = funcaoAtual->tipoParam.end();
						funcaoAtual->it = funcaoAtual->tipoParam.insert(funcaoAtual->it, $1.tipo);
						string var = nextVAR();
						novoSimbolo($2.label, var, $1.tipo);
						$$.traducao = typeName($1.tipo) + " " + getLabel($2.label);
						$$.tipo = $1.tipo;

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
						$$.dinamico = false;
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
						simbolo *s = getSimboloPilha($1.label);
						$$.label = s->label;
						$$.declaracao = "";
						$$.traducao = "";
						$$.desalocacao = "";
						$$.dinamico = false;
						$$.tamanho = s->tamanho;
						$$.tmpTamanho = s->tmpTamanho;
						$$.identificador = $1.label;
					}
					| '(' EXPRESSAO ')'
					{
						$$.label = $2.label;
						$$.declaracao = $2.declaracao;
						$$.traducao = $2.traducao;
						$$.tipo = $2.tipo;
						$$.desalocacao = $2.desalocacao;
						$$.dinamico = $2.dinamico;
						$$.tmpTamanho = $2.tmpTamanho;
						$$.tamanho = $2.tamanho;
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
						$$.dinamico = $3.dinamico;
						$$.tmpTamanho = $3.tmpTamanho;
						$$.tamanho = $3.tamanho;
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

							$$.traducao += cmd(tmp + " = (char*) malloc(sizeof(char) * " + tmpCount + ")");
							$$.traducao += cmd("strcpy(" + tmp + ", " + tmpBuffer + ")");

							$$.tmpTamanho = tmpCount;

							$$.desalocacao += cmd("free(" + tmpBuffer + ")");
							$$.desalocacao += cmd("free(" + tmp + ")");
						}

						$$.tipo = tipo;
						$$.label = tmp;
						$$.dinamico = true;
					}
					| TK_IN '(' ')'
					{
						string aux = "";
						int tipo = TK_TIPO_STRING;

						string tmp = nextTMP();
						$$.declaracao += dcl(tipo, tmp);

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

						$$.traducao += cmd(tmp + " = (char*) malloc(sizeof(char) * " + tmpCount + ")");
						$$.traducao += cmd("strcpy(" + tmp + ", " + tmpBuffer + ")");

						$$.tmpTamanho = tmpCount;

						$$.desalocacao += cmd("free(" + tmpBuffer + ")");
						$$.desalocacao += cmd("free(" + tmp + ")");

						$$.tipo = tipo;
						$$.label = tmp;
						$$.dinamico = true;
					}
					| TK_ID '(' { auxFuncao = getFuncao($1.label); } LISTA_PARAM ')'
					{
						if (!isFunDeclared($1.label))
						{
							yyerror("Função (" + $1.label + ") não definida.");
						}

						int qntArgs = $4.indexLista + 1;

						if (auxFuncao->tipoParam.size() != auxFuncao->argumentosPassados)
						{
							yyerror("Foram passados " + to_string(qntArgs) + " argumento(s). A Função '" + $1.label + "' requer " + to_string(auxFuncao->tipoParam.size()) + " argumento(s).");

						}

						$$.label = nextTMP();
						$$.tipo = ListaDeFuncoes[$1.label].tipo;

						$$.declaracao = $4.declaracao;
						$$.declaracao += dcl($$.tipo, $$.label);

						$$.traducao = $4.traducao;
						$$.traducao += cmd($$.label + " = " + ListaDeFuncoes[$1.label].identificador + "(" + $4.label + ")");

						$$.desalocacao = $4.desalocacao;
						$$.dinamico = $4.dinamico;
						$$.tamanho = 0;
					}
					| TK_ID '(' ')'
					{
						if (!isFunDeclared($1.label))
						{
							yyerror("Função (" + $1.label + ") não definida.");
						}

						if (ListaDeFuncoes[$1.label].tipoParam.size() != 0)
						{
							yyerror("Foram passados 0 argumento(s). A Função '" + $1.label + "' requer " + to_string(ListaDeFuncoes[$1.label].tipoParam.size()) + " argumento(s).");

						}

						$$.tipo = ListaDeFuncoes[$1.label].tipo;

						$$.declaracao = dcl($$.tipo, $$.label);

						$$.traducao = cmd($$.label + " = " + ListaDeFuncoes[$1.label].identificador + "()");

						$$.tamanho = 0;
					}
					;

EXP_POSFIXA			: EXP_SIMPLES
					| EXP_POSFIXA '[' TK_LITERAL ']'
					{
						if ($1.identificador == "")
						{
							yyerror("Identificador esperado antes de '[ ]'.");
						}
						$$.declaracao = $3.declaracao;
						$$.traducao = $3.traducao;

						simbolo *smb = getSimboloPilha($1.identificador);
						//$$.tipo = smb->tipo;
						$$.tamanho = smb->tamanho;

						int tipoPosicao = smb->tipoElemento; // Pegar tipo da posição aqui

						if (tipoPosicao == TK_TIPO_INDEFINIDO)
						{
							yyerror("O vetor '" + $1.identificador +"' possui tipo indefinido.");
						}

						string tmp = nextTMP();
						string tmpPonteiroVoid = nextTMP();
						string tmpPonteiro = nextTMP();
						string tmpValor = nextTMP();

						$$.declaracao += dcl(tipoPosicao, tmp);
						$$.declaracao += dcl(TK_TIPO_VOID, tmpPonteiroVoid, "*");
						$$.declaracao += dcl(tipoPosicao, tmpPonteiro, "*");
						$$.declaracao += dcl(tipoPosicao, tmpValor);

						$$.traducao += cmd(tmpPonteiroVoid + " = " + $1.label + "[" + $3.label + "]");
						$$.traducao += cmd(tmpPonteiro + " = (" + typeName(tipoPosicao) + "*)" + tmpPonteiroVoid);
						
						if (tipoPosicao != TK_TIPO_STRING)
						{
							$$.traducao += cmd(tmpValor + " = *" + tmpPonteiro);
							$$.traducao += cmd(tmp + " = " + tmpValor);
						}
						else
						{
							$$.traducao += cmd(tmp + " = " + tmpPonteiro);
						}

						$$.tipo = tipoPosicao;
						$$.label = tmp;
					}
					;
					
EXP_UNARIA			: EXP_POSFIXA
					| TK_OP_ADD EXP_POSFIXA
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
						$$.dinamico = $2.dinamico;
						$$.tmpTamanho = $2.tmpTamanho;
					}
					| TK_OP_UN_ADD EXP_POSFIXA
					{

						if ($2.tipo != TK_TIPO_INT && $2.tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + $1.traducao + "] para o tipo (" + typeName($2.tipo) + ").");
						}

						string tmpUm = nextTMP();

						$$.declaracao = dcl($2.tipo, tmpUm);
						$$.declaracao += $2.declaracao;

						$$.traducao = $2.traducao;
						$$.traducao += cmd(tmpUm + " = 1");
						$$.traducao += cmd($2.label + " = " + $2.label + " + " + tmpUm);

						$$.tipo = $2.tipo;
						$$.label = $2.label;
						$$.desalocacao = $2.desalocacao;
					}
					| TK_OP_UN_SUB EXP_POSFIXA
					{

						if ($2.tipo != TK_TIPO_INT && $2.tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + $1.traducao + "] para o tipo (" + typeName($2.tipo) + ").");
						}

						string tmpUm = nextTMP();

						$$.declaracao = dcl($2.tipo, tmpUm);
						$$.declaracao += $2.declaracao;

						$$.traducao = $2.traducao;
						$$.traducao += cmd(tmpUm + " = 1");
						$$.traducao += cmd($2.label + " = " + $2.label + " - " + tmpUm);

						$$.tipo = $2.tipo;
						$$.label = $2.label;
						$$.desalocacao = $2.desalocacao;
					}
					| EXP_POSFIXA TK_OP_UN_ADD
					{
						if ($1.tipo != TK_TIPO_INT && $1.tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + $2.traducao + "] para o tipo (" + typeName($1.tipo) + ").");
						}

						string tmpUm = nextTMP();
						string tmp = nextTMP();

						$$.declaracao = dcl($1.tipo, tmpUm);
						$$.declaracao += $1.declaracao;
						$$.declaracao += dcl($1.tipo, tmp);

						$$.traducao = $1.traducao;
						$$.traducao += cmd(tmp + " = " + $1.label);
						$$.traducao += cmd(tmpUm + " = 1");
						$$.traducao += cmd($1.label + " = " + $1.label + " + " + tmpUm);

						$$.tipo = $1.tipo;
						$$.label = tmp;
						$$.desalocacao = $1.desalocacao;
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
						$$.dinamico = $2.dinamico;
						$$.tmpTamanho = $2.tmpTamanho;
						//$$.traducao = $2.traducao + "\t" + declaracao + $$.label + " = !" + $2.label + ";\n";
					}

EXP_ARITMETICA_MUL	: EXP_NOT
					| EXP_ARITMETICA_MUL TK_OP_MUL EXP_NOT
					{
						$$.label = nextTMP();
						converterTipos(&$$, &$1, &$3, $2.traducao[0]);
						$$.traducao = $1.traducao + $3.traducao + cmd ($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
						$$.desalocacao = $1.desalocacao + $3.desalocacao;
						$$.dinamico = $1.dinamico || $2.dinamico;
						$$.tmpTamanho = $1.tmpTamanho;
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
							string tmpTamanho1 = $1.tmpTamanho;
							string tmpTamanho2 = $3.tmpTamanho;
							string tmpUm = nextTMP();

							if (tmpTamanho1 == "")
							{
								// Expressão esquerda é estática. Devo declarar temporária
								tmpTamanho1 = nextTMP();
								$$.declaracao += dcl(TK_TIPO_INT, tmpTamanho1);
								$$.traducao += cmd(tmpTamanho1 + " = " + to_string($1.tamanho));
							}

							if (tmpTamanho2 == "")
							{
								// Expressão direita é estática. Devo declarar temporária
								tmpTamanho2 = nextTMP();
								$$.declaracao += dcl(TK_TIPO_INT, tmpTamanho2);
								$$.traducao += cmd(tmpTamanho2 + " = " + to_string($3.tamanho));
							}

							// Declarar String temporária
							$$.declaracao += dcl(TK_TIPO_STRING, tmp);

							// Declarar Temporiaria para 1
							$$.declaracao += dcl(TK_TIPO_INT, tmpUm);
							$$.traducao += cmd(tmpUm + " = 1");

							// Declarar Temporária para novo tamanho
							string tmpSomaTamanhos = nextTMP();
							$$.declaracao += dcl(TK_TIPO_INT, tmpSomaTamanhos);

							// Realizar soma de tamanhos
							$$.traducao += cmd(tmpSomaTamanhos + " = " + tmpTamanho1 + " + " + tmpTamanho2);
							$$.traducao += cmd(tmpSomaTamanhos + " = " + tmpSomaTamanhos + " + " + tmpUm);

							// Alocar memória e realizar concatenação
							$$.traducao += cmd(tmp + " = (char*) malloc(sizeof(char) * " + tmpSomaTamanhos + ")");
							$$.traducao += cmd("strcpy(" + tmp + ", " + $1.label + ")");
							$$.traducao += cmd("strcat(" + tmp + ", " + $3.label + ")");
							$$.traducao += cmd($$.label + " = " + tmp);

							// Desalocar temporária e string no final do bloco
							$$.desalocacao += cmd("free(" + tmp + ")");
							//$$.desalocacao += cmd("free(" + $$.label + ")");
						}

						$$.desalocacao += $3.desalocacao;
						$$.dinamico = $1.dinamico || $2.dinamico;
					}
					;

EXP_RELACIONAL		: EXP_ARITMETICA_ADD
					| EXP_RELACIONAL OP_RELACIONAL EXP_ARITMETICA_ADD
					{
						$$.label = nextTMP();
						converterTipos(&$$, &$1, &$3, '>', TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
						$$.desalocacao = $1.desalocacao + $3.desalocacao;
						$$.dinamico = $1.dinamico || $2.dinamico;
					}
					;

EXP_IGUALDADE		: EXP_RELACIONAL
					| EXP_IGUALDADE TK_OP_IGUALDADE EXP_RELACIONAL
					{
						$$.label = nextTMP();
						converterTipos(&$$, &$1, &$3, '=', TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
						$$.desalocacao = $1.desalocacao + $3.desalocacao;
						$$.dinamico = $1.dinamico || $2.dinamico;
					}
					;

EXP_LOGICAL_AND  	: EXP_IGUALDADE
					| EXP_LOGICAL_AND TK_OP_LOGICAL_AND EXP_IGUALDADE
					{
						$$.label = nextTMP();
						converterTipos(&$$, &$1, &$3, '&', TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
						$$.desalocacao = $1.desalocacao + $3.desalocacao;
						$$.dinamico = $1.dinamico || $2.dinamico;
					}
					;

EXP_LOGICAL_OR		: EXP_LOGICAL_AND
					| EXP_LOGICAL_OR TK_OP_LOGICAL_OR EXP_LOGICAL_AND
					{
						$$.label = nextTMP();
						converterTipos(&$$, &$1, &$3, '|', TK_TIPO_BOOL);
						$$.traducao = $1.traducao + $3.traducao + cmd($$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label);
						$$.desalocacao = $1.desalocacao + $3.desalocacao;
						$$.dinamico = $1.dinamico || $2.dinamico;
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

							if ($3.dinamico && $1.tipo == TK_TIPO_STRING)
							{
								// Declarar Temporaria de Tamanho
								string tmpTamanho = $3.tmpTamanho;
								//$$.declaracao += dcl(TK_TIPO_INT, tmpTamanho);
								getSimboloPilha($1.label)->tmpTamanho = tmpTamanho;
							}
						}

						if ($1.tipo == TK_TIPO_VETOR)
						{
							yyerror("Atribuicao Invalida.");
						}

						converterTipo(&$$, $1.tipo, &$3);

						if ($3.dinamico)
						{
							$$.traducao += cmd(getSimboloPilha($1.label)->tmpTamanho + " = " + to_string($3.tamanho));
						}

						$1.label = getLabel($1.label);
						$$.traducao += cmd($1.label + " = " + $3.label);
						$$.desalocacao = $3.desalocacao;
					}
					| TK_ID '[' EXPRESSAO ']' '=' EXPRESSAO
					{
						if (!isDeclared($1.label))
						{
							yyerror("Vetor '" + $1.label + "' não declarado.");
						}

						simbolo *smb = getSimboloPilha($1.label);

						string varVetor = smb->label;

						$$.declaracao = $6.declaracao;
						$$.declaracao += $3.declaracao;

						$$.traducao = $6.traducao;
						$$.traducao += $3.traducao;

						$$.tamanho = smb->tamanho;
						$1.tipo = smb->tipo;
						$1.label = varVetor;

						if ($1.tipo != TK_TIPO_VETOR)
						{
							yyerror("Atribuicão Inválida.");
						}

						if ($3.tipo != TK_TIPO_INT)
						{
							yyerror("Esperado expressão (int)");
						}

						if (smb->tipoElemento == TK_TIPO_INDEFINIDO)
						{
							smb->tipoElemento = $6.tipo;

							string tmpI = nextTMP();
							string tmpPonteiro = nextTMP();

							$$.declaracao += dcl(TK_TIPO_INT, tmpI);
							$$.declaracao += dcl(smb->tipoElemento, tmpPonteiro, "*");

							for (int i = 0; i < smb->tamanho; i++)
							{
								string tmpValor = nextTMP();
								$$.declaracao += dcl(smb->tipoElemento, tmpValor);

								$$.traducao += cmd(tmpI + " = " + to_string(i));

								if (smb->tipoElemento != TK_TIPO_STRING)
								{
									$$.traducao += cmd(tmpValor + " = " + valorPadrao(smb->tipoElemento));
									$$.traducao += cmd(tmpPonteiro + " = &" + tmpValor);
									$$.traducao += cmd(smb->label + "[" + tmpI + "] = " + tmpPonteiro);
								}
								else
								{
									$$.traducao += cmd(tmpValor + " = (char*)malloc(sizeof(char))");
									$$.traducao += cmd("strcpy(" + tmpValor + ", \"\")");
									$$.traducao += cmd(smb->label + "[" + tmpI + "] = " + tmpValor);

									$$.desalocacao += cmd("free(" + tmpValor + ")");
								}
							}
						}

						if (smb->tipoElemento != $6.tipo)
						{
							yyerror("Atribuição incompatível com o tipo do vetor (" + typeName(smb->tipoElemento) + ").");
						}

						string tmpExpressao = nextTMP();
						string tmpPonteiro = nextTMP();

						$$.declaracao += dcl($6.tipo, tmpExpressao);
						$$.declaracao += dcl(TK_TIPO_INT, tmpPonteiro, "*");

						if (smb->tipoElemento != TK_TIPO_STRING)
						{
							$$.traducao += cmd(tmpExpressao + " = " + $6.label);
							$$.traducao += cmd(tmpPonteiro + " = &" + tmpExpressao);
							$$.traducao += cmd($1.label + "[" + $3.label + "] = " + tmpPonteiro);
						}
						else
						{
							string tmpTamanho = nextTMP();

							$$.declaracao += dcl(TK_TIPO_INT, tmpTamanho);
							$$.traducao += cmd(tmpTamanho + " = " + to_string($6.tamanho));
							$$.traducao += cmd(tmpPonteiro + " = " + $1.label + "[" + $3.label + "]");
							$$.traducao += cmd(tmpPonteiro + " = (char*)realloc(" + tmpPonteiro + ", " + tmpTamanho + ")");
							$$.traducao += cmd("strcpy(" + tmpPonteiro + ", " + $6.label + ")");
						}

					}
					| TK_ID TK_OP_ADD '=' EXPRESSAO
					{
						if (!isDeclared($1.label))
						{
							yyerror("Variável '" + $1.label + "' nao declarada.");
						}

						simbolo* smb = getSimboloPilha($1.label);
						$1.tipo = smb->tipo;
						$$.declaracao = $4.declaracao;
						$$.traducao = $4.traducao;

						if ($1.tipo == TK_TIPO_INDEFINIDO)
						{
							yyerror("Variável '" + $1.label + "' possui tipo indefinido.");
						}

						if ($1.tipo == TK_TIPO_VETOR)
						{
							yyerror("Atribuição inválida.");
						}

						converterTipo(&$$, $1.tipo, &$4);

						$1.label = smb->label;
						$$.traducao += cmd($1.label + " = " + $1.label + " " + $2.traducao + " " + $4.label);
						$$.desalocacao = $3.desalocacao;
					}
					| TK_ID TK_OP_MUL '=' EXPRESSAO
					{
						if (!isDeclared($1.label))
						{
							yyerror("Variável '" + $1.label + "' nao declarada.");
						}

						simbolo* smb = getSimboloPilha($1.label);
						$1.tipo = smb->tipo;
						$$.declaracao = $4.declaracao;
						$$.traducao = $4.traducao;

						if ($1.tipo == TK_TIPO_INDEFINIDO)
						{
							yyerror("Variável '" + $1.label + "' possui tipo indefinido.");
						}

						if ($1.tipo == TK_TIPO_VETOR)
						{
							yyerror("Atribuição inválida.");
						}

						converterTipo(&$$, $1.tipo, &$4);

						$1.label = smb->label;
						$$.traducao += cmd($1.label + " = " + $1.label + " " + $2.traducao + " " + $4.label);
						$$.desalocacao = $3.desalocacao;
					}
					;

CMD_UNARIO			: TK_OP_UN_ADD TK_ID
					{
						simbolo* s = getSimboloPilha($2.label);
						$2.label = s->label;
						$2.tipo = s->tipo;

						if ($2.tipo != TK_TIPO_INT && $2.tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + $1.traducao + "] para o tipo (" + typeName($2.tipo) + ").");
						}

						string tmpUm = nextTMP();

						$$.declaracao = dcl($2.tipo, tmpUm);

						$$.traducao = cmd(tmpUm + " = 1");
						$$.traducao += cmd($2.label + " = " + $2.label + " + " + tmpUm);
					}
					| TK_OP_UN_SUB TK_ID
					{
						simbolo* s = getSimboloPilha($2.label);
						$2.label = s->label;
						$2.tipo = s->tipo;

						if ($2.tipo != TK_TIPO_INT && $2.tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + $1.traducao + "] para o tipo (" + typeName($2.tipo) + ").");
						}

						string tmpUm = nextTMP();

						$$.declaracao = dcl($2.tipo, tmpUm);

						$$.traducao = cmd(tmpUm + " = 1");
						$$.traducao += cmd($2.label + " = " + $2.label + " - " + tmpUm);
					}
					| TK_ID TK_OP_UN_ADD
					{
						simbolo* s = getSimboloPilha($1.label);
						$1.label = s->label;
						$1.tipo = s->tipo;

						if ($1.tipo != TK_TIPO_INT && $1.tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + $2.traducao + "] para o tipo (" + typeName($1.tipo) + ").");
						}

						string tmpUm = nextTMP();
						string tmp = nextTMP();

						$$.declaracao = dcl($1.tipo, tmpUm);
						$$.declaracao += dcl($1.tipo, tmp);

						$$.traducao = cmd(tmp + " = " + $1.label);
						$$.traducao += cmd(tmpUm + " = 1");
						$$.traducao += cmd($1.label + " = " + $1.label + " + " + tmpUm);
					}
					| TK_ID TK_OP_UN_SUB
					{
						simbolo* s = getSimboloPilha($1.label);
						$1.label = s->label;
						$1.tipo = s->tipo;

						if ($1.tipo != TK_TIPO_INT && $1.tipo != TK_TIPO_FLOAT)
						{
							yyerror("Operador inválido [" + $2.traducao + "] para o tipo (" + typeName($1.tipo) + ").");
						}

						string tmpUm = nextTMP();
						string tmp = nextTMP();

						$$.declaracao = dcl($1.tipo, tmpUm);
						$$.declaracao += dcl($1.tipo, tmp);

						$$.traducao = cmd(tmp + " = " + $1.label);
						$$.traducao += cmd(tmpUm + " = 1");
						$$.traducao += cmd($1.label + " = " + $1.label + " - " + tmpUm);
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
						$$.declaracao += $3.declaracao;
						$$.traducao += $3.traducao;
						$$.desalocacao += $3.desalocacao;
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
						$$.traducao = "";
						$$.declaracao = "";
						$$.desalocacao = "";

						//$$.traducao = "";
					}
					| TK_ID '=' EXPRESSAO
					{
						if (getSimbolo($1.label, contextoAtual) != NULL)
							yyerror("Variável '" + $1.label + "' já foi declarada nesse contexto.");

						$1.tipo = $3.tipo;
						//string declaracao = dcl($1.tipo, $1.label);

						string newLabel = nextVAR();
						string tmpTamanho = "";

						if ($3.dinamico && $3.tipo == TK_TIPO_STRING)
						{
							tmpTamanho = $3.tmpTamanho;
							//$$.traducao += cmd(tmpTamanho + " = " + to_string($3.tamanho));
						}

						novoSimbolo($1.label, newLabel, $1.tipo, $3.tamanho, tmpTamanho);
						$1.label = newLabel;

						$$.declaracao = $3.declaracao;
						$$.declaracao += dcl($1.tipo, $1.label);
						$$.traducao = $3.traducao;
						$$.traducao += cmd($1.label + " = " + $3.label);
						$$.desalocacao = $3.desalocacao;

						if ($3.tipo == TK_TIPO_STRING)
						{
							//$$.declaracao += dcl(TK_TIPO_INT, tmpTamanho);
							//$$.traducao += cmd(tmpTamanho + " = " + to_string($3.tamanho));
						}
					}
					| TK_ID DCL_ENDERECO
					{
						if (getSimbolo($1.label, contextoAtual) != NULL)
							yyerror("Variável '" + $1.label + "' já foi declarada nesse contexto.");

						string varVetor = nextVAR();
						string tmpTamanho = nextTMP();
						int tamanhoVetor = $2.tamanho;

						$$.declaracao = dcl(TK_TIPO_VETOR, varVetor);
						$$.declaracao += dcl(TK_TIPO_INT, tmpTamanho);

						$$.traducao = cmd(tmpTamanho + " = " + to_string($2.tamanho));
						$$.traducao += dclVetor(TK_TIPO_INDEFINIDO, varVetor, tmpTamanho);

						novoSimbolo($1.label, varVetor, TK_TIPO_VETOR, tamanhoVetor);

						$$.tipo = TK_TIPO_INDEFINIDO;
						$$.tamanho = tamanhoVetor;

						//$$.desalocacao += cmd("free(" + varVetor +")"); 
					}
					;

DCL_ENDERECO		: '[' TK_LITERAL ']' DCL_ENDERECO
					{
						if ($2.tipo != TK_TIPO_INT)
							yyerror("Tipo int esperado para tamanho do vetor.");

						int tamanho = stoi($2.traducao);

						if (tamanho < 1)
							yyerror("Um vetor deve ter tamanho >= 1.");

						$$.tamanho = $4.tamanho * tamanho;
					}
					| '[' TK_LITERAL ']'
					{
						if ($2.tipo != TK_TIPO_INT)
							yyerror("Tipo int esperado para tamanho do vetor.");

						int tamanho = stoi($2.traducao);

						if (tamanho < 1)
							yyerror("Um vetor deve ter tamanho >= 1.");

						$$.tamanho = tamanho;

						$$.traducao = "";
						$$.declaracao = "";
						$$.desalocacao = "";
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

CMD_RETORNO			: TK_RETORNO EXPRESSAO ';'
					{
						$$.declaracao = $2.declaracao;
						$$.traducao = $2.traducao;
						$$.desalocacao = $2.desalocacao;

						$$.tipo = $2.tipo;

						if (funcaoAtual == NULL) yyerror("Comando Inválido.");

						if (funcaoAtual->tipo == TK_TIPO_VOID) funcaoAtual->tipo = $$.tipo;
						else if (funcaoAtual->tipo != $$.tipo) yyerror("Impossivel converter (" + typeName(funcaoAtual->tipo, true) + ") para (" + typeName($$.tipo, true) + ").");

						$$.traducao += cmd("return " + $2.label);
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

CMD_FUNCAO			: TK_ID '(' { auxFuncao = getFuncao($1.label); } LISTA_PARAM ')' ';'
					{
						if (!isFunDeclared($1.label))
						{
							yyerror("Função (" + $1.label + ") não definida.");
						}

						int qntArgs = $4.indexLista + 1;

						if (auxFuncao->tipoParam.size() != qntArgs)
						{
							yyerror("Foram passados " + to_string(qntArgs) + " argumento(s). A Função '" + $1.label + "' requer " + to_string(auxFuncao->tipoParam.size()) + " argumento(s).");
						}

						$$.tipo = ListaDeFuncoes[$1.label].tipo;

						$$.declaracao = $4.declaracao;

						$$.traducao = $4.traducao;
						$$.traducao += cmd(ListaDeFuncoes[$1.label].identificador + "(" + $4.label + ")");

						$$.desalocacao = $4.desalocacao;
						$$.dinamico = $4.dinamico;
						$$.tamanho = 0;
					}
					| TK_ID '(' ')' ';'
					{
						if (!isFunDeclared($1.label))
						{
							yyerror("Função (" + $1.label + ") não definida.");
						}

						if (ListaDeFuncoes[$1.label].tipoParam.size() != 0)
						{
							yyerror("Foram passados 0 argumento(s). A Função '" + $1.label + "' requer " + to_string(ListaDeFuncoes[$1.label].tipoParam.size()) + " argumento(s).");
						}

						$$.tipo = ListaDeFuncoes[$1.label].tipo;
						$$.traducao = cmd(ListaDeFuncoes[$1.label].identificador + "()");

						$$.tamanho = 0;
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
						int tipo = ($3.tipo != TK_TIPO_VETOR)? $3.tipo : getSimboloPilha($3.identificador)->tipoElemento;

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

						if ($3.tipo != TK_TIPO_VETOR)
						{
							// Imprimir declaracao e tradução da Expressão
							$$.traducao = $3.traducao;
							$$.declaracao = $3.declaracao;
							$$.desalocacao = $3.desalocacao;

							// Imprimir comando de saida
							$$.traducao += cmd((string)"printf(\"\%" + aux + "\", " + $3.label + ")");
						}
						else
						{
							$$.traducao = $3.traducao;
							$$.declaracao = $3.declaracao;
							$$.desalocacao = $3.desalocacao;

							string tmpPointeiro = nextTMP();
							string tmpI = nextTMP();

							$$.declaracao += dcl(TK_TIPO_INT, tmpI);
							if (tipo != TK_TIPO_INDEFINIDO)
								$$.declaracao += dcl(tipo, tmpPointeiro, "*");

							$$.traducao += cmd("printf(\"(\")");


							for (int i = 0; i < $3.tamanho; i++)
							{
								$$.traducao += cmd(tmpI + " = " + to_string(i));

								if (tipo != TK_TIPO_INDEFINIDO)
									$$.traducao += cmd(tmpPointeiro + " = " + $3.label + "[" + tmpI + "]");

								if (tipo != TK_TIPO_STRING && tipo != TK_TIPO_INDEFINIDO)
								{
									$$.traducao += cmd((string)"printf(\"%" + aux + "\", *" + tmpPointeiro + ")");
								}
								else if (tipo == TK_TIPO_INDEFINIDO)
								{
									$$.traducao += cmd((string)"printf(\"?\")");
								}
								else 
								{
									$$.traducao += cmd((string)"printf(\"%" + aux + "\", " + tmpPointeiro + ")");
								}

								if (i < $3.tamanho - 1)
								{
									$$.traducao += cmd("printf(\", \")");
								}
							}

							$$.traducao += cmd("printf(\")\")");
						}
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