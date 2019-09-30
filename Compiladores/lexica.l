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
"new"							{ return TK_VAR; 																}

"int"							{ yylval.tipo = TK_TIPO_INT; return TK_TIPO;									}
"float"							{ yylval.tipo = TK_TIPO_FLOAT; return TK_TIPO;									}
"char"							{ yylval.tipo = TK_TIPO_CHAR; return TK_TIPO;									}
"bool"							{ yylval.tipo = TK_TIPO_BOOL; return TK_TIPO;									}
"string"						{ yylval.tipo = TK_TIPO_STRING; return TK_TIPO;									}

">="							{ yylval.traducao = yytext; return TK_OP_MAIORIGUAL;							}
"<="							{ yylval.traducao = yytext; return TK_OP_MENORIGUAL;							}
"=="							{ yylval.traducao = yytext; return TK_OP_IGUALDADE;								}
"!="							{ yylval.traducao = yytext; return TK_OP_DESIGUALDADE;							}

[(){}[\];,]						{ return *yytext; 																}

[+\-*/=<>]						{ yylval.traducao = yytext; return *yytext; 									}

{INT}|{INT_8}|{INT_16}			{ yylval.traducao = yytext; yylval.tipo = TK_TIPO_INT; return TK_LITERAL; 		}
{FLOAT}							{ yylval.traducao = yytext; yylval.tipo = TK_TIPO_FLOAT; return TK_LITERAL; 	}
{CHAR}							{ yylval.traducao = yytext; yylval.tipo = TK_TIPO_CHAR; return TK_LITERAL; 		}
{BOOL}							{ yylval.traducao = yytext; yylval.tipo = TK_TIPO_BOOL; return TK_LITERAL; 		}

{ID}							{ yylval.label = yytext; yylval.tipo = TK_TIPO_INDEFINIDO; return TK_ID; 		}

.								{ *yytext; 																		}

%%