
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
	int	TMP1;
	int	TMP2;
	int	TMP4;
	int*	TMP5;
	int	TMP6;
	int	TMP7;
	int	TMP8;
	int	TMP9;
	int	TMP10;
	int	TMP11;
	int*	TMP12;
	int	TMP14;
	int*	TMP13;

	TMP0 = 5;
	VAR0 = (void**)malloc(sizeof(void*) * TMP0);
	TMP3 = 2;
	TMP1 = 1;
	TMP2 = -TMP1;
	TMP4 = 0;
	TMP6 = 0;
	TMP5 = &TMP6;
	VAR0[TMP4] = TMP5;
	TMP4 = 1;
	TMP7 = 0;
	TMP5 = &TMP7;
	VAR0[TMP4] = TMP5;
	TMP4 = 2;
	TMP8 = 0;
	TMP5 = &TMP8;
	VAR0[TMP4] = TMP5;
	TMP4 = 3;
	TMP9 = 0;
	TMP5 = &TMP9;
	VAR0[TMP4] = TMP5;
	TMP4 = 4;
	TMP10 = 0;
	TMP5 = &TMP10;
	VAR0[TMP4] = TMP5;
	TMP11 = TMP3;
	TMP12 = &TMP11;
	VAR0[TMP2] = TMP12;
	printf("(");
	TMP14 = 0;
	TMP13 = VAR0[TMP14];
	printf("%d", *TMP13);
	printf(", ");
	TMP14 = 1;
	TMP13 = VAR0[TMP14];
	printf("%d", *TMP13);
	printf(", ");
	TMP14 = 2;
	TMP13 = VAR0[TMP14];
	printf("%d", *TMP13);
	printf(", ");
	TMP14 = 3;
	TMP13 = VAR0[TMP14];
	printf("%d", *TMP13);
	printf(", ");
	TMP14 = 4;
	TMP13 = VAR0[TMP14];
	printf("%d", *TMP13);
	printf(")");


	return 0;
}
