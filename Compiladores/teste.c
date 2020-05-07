
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
	int	TMP3;
	char**	TMP4;
	char*	TMP5;
	char*	TMP6;
	char*	TMP7;
	char*	TMP8;
	int	TMP1;
	char*	TMP2;
	int	TMP9;
	int	TMP10;
	int	TMP12;
	char**	TMP11;

	TMP0 = 4;
	VAR0 = (void**)malloc(sizeof(void*) * TMP0);
	TMP3 = 0;
	TMP5 = (char*)malloc(sizeof(char));
	strcpy(TMP5, "");
	VAR0[TMP3] = TMP5;
	TMP3 = 1;
	TMP6 = (char*)malloc(sizeof(char));
	strcpy(TMP6, "");
	VAR0[TMP3] = TMP6;
	TMP3 = 2;
	TMP7 = (char*)malloc(sizeof(char));
	strcpy(TMP7, "");
	VAR0[TMP3] = TMP7;
	TMP3 = 3;
	TMP8 = (char*)malloc(sizeof(char));
	strcpy(TMP8, "");
	VAR0[TMP3] = TMP8;
	TMP1 = 3;
	TMP2 = (char*) malloc(sizeof(char) * 2);
	strcpy(TMP2, "a");
	TMP9 = 0;
	TMP10 = TMP1 * 1;
	TMP9 = TMP9 + TMP10;
	VAR0[TMP9] = &TMP2;
	printf("(");
	TMP12 = 0;
	TMP11 = VAR0[TMP12];
	printf("%s", *TMP11);
	printf(", ");
	TMP12 = 1;
	TMP11 = VAR0[TMP12];
	printf("%s", *TMP11);
	printf(", ");
	TMP12 = 2;
	TMP11 = VAR0[TMP12];
	printf("%s", *TMP11);
	printf(", ");
	TMP12 = 3;
	TMP11 = VAR0[TMP12];
	printf("%s", *TMP11);
	printf(")");

	free(TMP5);
	free(TMP6);
	free(TMP7);
	free(TMP8);
	free(TMP2);

	return 0;
}
