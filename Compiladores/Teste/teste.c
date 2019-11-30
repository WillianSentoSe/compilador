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
	int*	TMP4;
	int	TMP5;
	int	TMP6;
	int	TMP1;
	int	TMP2;
	int	TMP7;
	int	TMP8;
	int	TMP10;
	int*	TMP9;

	TMP0 = 2;
	VAR0 = (void**)malloc(sizeof(void*) * TMP0);
	TMP3 = 0;
	TMP5 = 0;
	TMP4 = &TMP5;
	VAR0[TMP3] = TMP4;
	TMP3 = 1;
	TMP6 = 0;
	TMP4 = &TMP6;
	VAR0[TMP3] = TMP4;
	TMP1 = 0;
	TMP2 = 1;
	TMP7 = 0;
	TMP8 = TMP1 * 1;
	TMP7 = TMP7 + TMP8;
	VAR0[TMP7] = &TMP2;
	printf("(");
	TMP10 = 0;
	TMP9 = VAR0[TMP10];
	printf("%d", *TMP9);
	printf(", ");
	TMP10 = 1;
	TMP9 = VAR0[TMP10];
	printf("%d", *TMP9);
	printf(")");


	return 0;
}

