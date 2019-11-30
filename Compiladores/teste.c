
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
	int	TMP4;
	int*	TMP5;
	int	TMP6;
	int	TMP7;
	int	TMP8;
	int	TMP9;
	int	TMP1;
	int	TMP2;
	int	TMP3;
	int	TMP10;
	int	TMP11;
	int	TMP12;
	int	TMP13;
	int	TMP14;
	int	TMP15;
	int	TMP16;
	int*	TMP17;

	TMP0 = 4;
	VAR0 = (void**)malloc(sizeof(void*) * TMP0);
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
	TMP1 = 1;
	TMP2 = 1;
	TMP3 = 2;
	TMP10 = 0;
	TMP11 = TMP2 * 1;
	TMP10 = TMP10 + TMP11;
	TMP11 = TMP1 * 2;
	TMP10 = TMP10 + TMP11;
	VAR0[TMP10] = &TMP3;
	TMP12 = 1;
	TMP13 = 1;
	TMP14 = 0;
	TMP15 = TMP13 * 1;
	TMP14 = TMP14 + TMP15;
	TMP15 = TMP12 * 2;
	TMP14 = TMP14 + TMP15;
	TMP17 = VAR0[TMP14];
	TMP16 = *TMP17;
	printf("%d", TMP16);


	return 0;
}
