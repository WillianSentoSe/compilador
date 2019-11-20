/*Compilador Ç*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int main(void)
{
	char*	TMP0;
	int	TMP1;
	char	TMP2;
	int	TMP3;
	char	TMP6;
	int	TMP4;
	char*	TMP5;
	char	TMP7;
	char*	TMP8;
	char*	TMP9;
	int	TMP12;
	char*	TMP10;
	int	TMP11;
	int	TMP13;

	TMP1 = 0;
	TMP3 = 1;
	TMP6 = '\n';
	TMP7 = '\0';
	TMP5 = (char*)malloc(sizeof(char) * TMP3);
	LBL2:
	scanf("%c", &TMP2 );
	TMP4 = TMP2 == TMP6;
	if (TMP4) goto LBL3;
	TMP1 = TMP1 + TMP3;
	TMP5 = (char*)realloc(TMP5, sizeof(char) * TMP1);
	strncat(TMP5, &TMP2, TMP3);
	goto LBL2;
	LBL3:
	TMP1 = TMP1 + TMP3;
	strncat(TMP5, &TMP7, TMP3);
	TMP0 = (char*) malloc(sizeof(char) * TMP1);
	strcpy(TMP0, TMP5);
	TMP8 = (char*) malloc(sizeof(char) * 3);
	strcpy(TMP8, "\n");
	TMP12 = 2;
	TMP11 = 1;
	TMP13 = TMP1 + TMP12;
	TMP13 = TMP13 + TMP11;
	TMP10 = (char*) malloc(sizeof(char) * TMP13);
	strcpy(TMP10, TMP0);
	strcat(TMP10, TMP8);
	TMP9 = TMP10;
	printf("%s", TMP9);

	free(TMP5);
	free(TMP0);
	free(TMP10);
	free(TMP8);

	return 0;
}
