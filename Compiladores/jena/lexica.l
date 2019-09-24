%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
FLOAT  {DIGITO}*\.{DIGITO}+|{DIGITO}+\.[DIGITO]*
REAL {NUM}+("."{NUM}+)?
CHAR '({LETRA}|{NUM})'
BOOL (true|false)
STRING \"(\\.|[^"\\])*\"
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"				{linha++;}

{DELIM} 			{}

"main"				{return TK_MAIN;}

"int"				{return TK_TIPO_INT;}

"float"				{return TK_TIPO_FLOAT;}

"char"				{return TK_TIPO_CHAR; }				

[(){}[\];,]			{ return *yytext; }

[+\-*/=]			{ return *yytext; }

{BOOL}				{ yylval.traducao = yytext;
				      yylval.tipo = TK_TIPO_BOOL;  return TK_BOOL; }

{CHAR}				{ yylval.traducao = yytext;
				      yylval.tipo = TK_TIPO_CHAR;  return TK_CHAR; }

{FLOAT}       	    { yylval.traducao = yytext;
				      yylval.tipo = TK_TIPO_FLOAT;  return TK_NUM; }

{NUM}				{ yylval.traducao = yytext;
					  yylval.tipo = TK_TIPO_INT;  return TK_NUM; }

{ID}				{ yylval.label = yytext; return TK_ID; }

.					{ *yytext; }

%%
