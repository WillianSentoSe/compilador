/*Compilador Ç*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int main(void)
{
	char*	TMP0;
	char*	TMP1;
	int	TMP2;
	char	TMP3;
	int	TMP4;
	char	TMP6;
	int	TMP5;
	char*	VAR0;
	char*	TMP7;
	char*	TMP8;
	char*	TMP9;

	TMP0 = (char*) malloc(sizeof(char) * 15);
	TMP0 = "digite algo:\n";
	printf("%s", TMP0);
	TMP2 = 0;
	TMP4 = 1;
	TMP6 = '\n';
	LBL2:
	scanf("%c", &TMP3 );
	TMP5 = TMP3 == TMP6;
	if (TMP5) goto LBL3;
	TMP2 = TMP2 + TMP4;
	goto LBL2;
	LBL3:
	TMP2 = TMP2 + TMP4;
	fseek(stdin, -TMP2, SEEK_CUR);
	TMP1 = (char*) malloc(sizeof(char) * TMP2);
	//fgets(TMP1, TMP2, stdin);
	TMP1[0] = fgetc(stdin);
	VAR0 = TMP1;
	TMP7 = (char*) malloc(sizeof(char) * 7);
	TMP7 = "str = ";
	TMP9 = (char*) malloc(sizeof(char) * 13);
	strcpy(TMP9, TMP7);
	strcat(TMP9, VAR0);
	TMP8 = TMP9;
	printf("%s", TMP8);

	return 0;
}