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
	char*	VAR1;
	char*	TMP2;
	char*	TMP3;

	TMP0 = (char*) malloc(sizeof(char) * 7);
	strcpy(TMP0, "hello ");
	VAR0 = TMP0;
	TMP1 = (char*) malloc(sizeof(char) * 7);
	strcpy(TMP1, "world!");
	VAR1 = TMP1;
	TMP3 = (char*) malloc(sizeof(char) * 13);
	strcpy(TMP3, VAR0);
	strcat(TMP3, VAR1);
	TMP2 = TMP3;
	printf("%s", TMP2);

	free(TMP0);
	free(TMP1);
	free(TMP3);

	return 0;
}
