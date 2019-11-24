
/*Compilador Ç*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int main(void)
{
	void**	VAR0;
	int	TMP0;
	char*	TMP2;
	int	TMP1;
	int	TMP3;
	char**	TMP4;
	char*	TMP5;
	char*	TMP6;
	char*	TMP7;
	char*	TMP8;
	char*	TMP9;
	char*	TMP10;
	int*	TMP11;
	int	TMP12;
	int	TMP13;
	char*	TMP14;
	void*	TMP15;
	char**	TMP16;
	char*	TMP17;

	TMP0 = 5;
	VAR0 = (void**)malloc(sizeof(void*) * TMP0);
	TMP2 = (char*) malloc(sizeof(char) * 4);
	strcpy(TMP2, "asd");
	TMP1 = 1;
	TMP3 = 0;
	TMP5 = (char*)malloc(sizeof(char)*2);
	strcpy(TMP5, "a");
	VAR0[TMP3] = TMP5;
	TMP3 = 1;
	TMP6 = (char*)malloc(sizeof(char)*2);
	strcpy(TMP6, "a");
	VAR0[TMP3] = TMP6;
	TMP3 = 2;
	TMP7 = (char*)malloc(sizeof(char)*2);
	strcpy(TMP7, "a");
	VAR0[TMP3] = TMP7;
	TMP3 = 3;
	TMP8 = (char*)malloc(sizeof(char)*2);
	strcpy(TMP8, "a");
	VAR0[TMP3] = TMP8;
	TMP3 = 4;
	TMP9 = (char*)malloc(sizeof(char)*2);
	strcpy(TMP9, "a");
	VAR0[TMP3] = TMP9;
	TMP12 = 3;
	TMP11 = VAR0[TMP1];
	TMP11 = (char*)realloc(TMP11, TMP12);
	strcpy(TMP11, TMP2);
	TMP13 = 5;
	TMP15 = VAR0[TMP13];
	TMP16 = (char**)TMP15;
	TMP14 = TMP16;
	printf("%s", TMP14);

	free(VAR0);
	free(TMP5);
	free(TMP6);
	free(TMP7);
	free(TMP8);
	free(TMP9);

	return 0;
}
