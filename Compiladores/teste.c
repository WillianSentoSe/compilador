
/*Compilador Ç*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0


int main(void)
{
	char*	TMP0;
	char*	VAR0;
	char*	TMP1;
	char*	TMP2;
	int	TMP5;
	int	TMP6;
	char*	TMP3;
	int	TMP4;
	int	TMP7;

	TMP0 = (char*) malloc(sizeof(char) * 4);
	strcpy(TMP0, "aaa");
	VAR0 = TMP0;
	TMP1 = (char*) malloc(sizeof(char) * 6);
	strcpy(TMP1, "bbb\n");
	TMP5 = 3;
	TMP6 = 5;
	TMP4 = 1;
	TMP7 = TMP5 + TMP6;
	TMP7 = TMP7 + TMP4;
	TMP3 = (char*) malloc(sizeof(char) * TMP7);
	strcpy(TMP3, VAR0);
	strcat(TMP3, TMP1);
	TMP2 = TMP3;
	printf("%s", TMP2);

	free(TMP0);
	free(TMP3);
	free(TMP1);

	return 0;
}
