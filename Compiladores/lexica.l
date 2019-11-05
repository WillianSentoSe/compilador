%{
#include <string>

%}

ESPACO 		[ \t]
DGT 		[0-9]
LETRA 		[A-Za-z_]

DELIM 		{ESPACO}+

INT 		[1-9]{DGT}*
INT_8 		0[0-7]*
INT_16		0x[1-9a-fA-F]+
FLOAT 		{DGT}*\.{DGT}+|{DGT}+\.[DGT]*

CHAR 		'(\\)?.'
BOOL		(true|false)
ID 			{LETRA}({LETRA}|{DGT})*

%%

"\n"							{ linha++;																		}

{DELIM} 						{																				}

"main"							{ return TK_MAIN; 																}
"if"							{ return TK_IF; 																}
"var"							{ return TK_VAR; 																}
"else"							{ return TK_ELSE;																}
"while"							{ return TK_WHILE;																}
"do"							{ return TK_DO;																	}
"for"							{ return TK_FOR;																}
"switch"						{ return TK_SWITCH;																}
"case"							{ return TK_CASE;																}
"default"						{ return TK_DEFAULT;															}

"break"							{ return TK_BREAK;																}
"continue"						{ return TK_CONTINUE;															}

"int"							{ yylval.tipo = TK_TIPO_INT; 	return TK_TIPO;									}
"float"							{ yylval.tipo = TK_TIPO_FLOAT; 	return TK_TIPO;									}
"char"							{ yylval.tipo = TK_TIPO_CHAR; 	return TK_TIPO;									}
"bool"							{ yylval.tipo = TK_TIPO_BOOL; 	return TK_TIPO;									}
"string"						{ yylval.tipo = TK_TIPO_STRING;	return TK_TIPO;									}

">="							{ yylval.traducao = yytext; return TK_OP_MAIORIGUAL;							}
"<="							{ yylval.traducao = yytext; return TK_OP_MENORIGUAL;							}
"=="|"!="						{ yylval.traducao = yytext; return TK_OP_IGUALDADE;								}

"and"							{ yylval.traducao = "&&"; 	return TK_OP_LOGICAL_AND;							}
"or"							{ yylval.traducao = "||"; 	return TK_OP_LOGICAL_OR;							}
[!]								{ yylval.traducao = "!";	return TK_OP_NOT;									}

[()[\];,<>:]					{ return *yytext; 																}
[{]								{ empilharContexto();		return *yytext; 									}
[}]								{ desempilharContexto();	return *yytext; 									}


[=]								{ yylval.traducao = yytext; return *yytext; 									}
[+-]							{ yylval.traducao = yytext; return TK_OP_ADD; 									}
[*/]							{ yylval.traducao = yytext; return TK_OP_MUL; 									}

{INT}|{INT_8}|{INT_16}			{ yylval.traducao = yytext; yylval.tipo = TK_TIPO_INT; 	return TK_LITERAL; 		}
{FLOAT}							{ yylval.traducao = yytext; yylval.tipo = TK_TIPO_FLOAT;return TK_LITERAL; 		}
{CHAR}							{ yylval.traducao = yytext; yylval.tipo = TK_TIPO_CHAR; return TK_LITERAL; 		}
{BOOL}							{ yylval.traducao = yytext; yylval.tipo = TK_TIPO_BOOL; return TK_LITERAL; 		}

{ID}							{ yylval.label = yytext; yylval.tipo = TK_TIPO_INDEFINIDO; return TK_ID; 		}

.								{ *yytext; 																		}

%%