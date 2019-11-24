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
	int	TMP2;
	int	TMP1;
	int	TMP3;
	int*	TMP4;
	int	TMP5;
	int	TMP6;
	void*	TMP7;
	int*	TMP8;
	int	TMP9;

	TMP0 = 5;
	VAR0 = (void**)malloc(sizeof(void*) * TMP0);
	TMP2 = 3;
	TMP1 = 1;
	TMP3 = TMP2;
	TMP4 = &TMP3;
	VAR0[TMP1] = TMP4;
	TMP5 = 2;
	TMP7 = VAR0[TMP5];
	TMP8 = (int*)TMP7;
	TMP9 = *TMP8;
	TMP6 = TMP9;
	printf("%d", TMP6);

	free(VAR0);

	return 0;
}
