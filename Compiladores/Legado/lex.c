%{
#include <stdio.h>
#include <stdlib.h>

#define LITERAL_INTEIRO	500
#define LITERAL_OCTAL	501
#define LITERAL_HEX		502
#define LITERAL_FLOAT	503
#define LITERAL_STRING	504

#define ESPACO			550

#define I_DID_MY_BEST	600	
#define FIM				601
%}

DIG [0-9]
LETRA [a-zA-Z_áÁàÀãÃâÂéÉêÊíÍóÓôÔõÕúÚ]
SINAL [\?\.\(\)\[\]\<\>\$\^\+\*\-\|\\;,ªº%#@!]
ESP [ \t]+

%%

[1-9]{DIG}*										{ return LITERAL_INTEIRO; }
0[0-7]*											{ return LITERAL_OCTAL; }
[0-9A-Fa-f]+[hH]								{ return LITERAL_HEX; }
{DIG}*\.{DIG}+|{DIG}+\.{DIG}*					{ return LITERAL_FLOAT; }
\"({LETRA}|{DIG}|{ESP}|{SINAL})*\"				{ return LITERAL_STRING; }
[ \t]											{ return ESPACO; }
.												{ return I_DID_MY_BEST; }
<<EOF>>											{ return FIM; }

%%

void main (){
	int retorno;
	//yyin = stdin;

	while ((retorno = yylex()) != FIM){
		switch (retorno){
			case LITERAL_STRING:
				printf ("<string>");
				break;
			case LITERAL_INTEIRO:
				printf ("<int>");
				break;
			case LITERAL_FLOAT:
				printf ("<float>");
				break;
			case LITERAL_HEX:
				printf ("<hex>");
				break;
			case LITERAL_OCTAL:
				printf ("<octal>");
				break;
			case ESPACO:
				printf (" ");
				break;
			case I_DID_MY_BEST:
				printf ("[?]");
				break;
		}
	}

	printf ("\n--\n");
}