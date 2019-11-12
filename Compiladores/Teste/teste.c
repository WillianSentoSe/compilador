/*Compilador Ç*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int main(void)
{
	int	TMP0;
	int	VAR0;
	int	TMP1;
	int	TMP2;
	int	TMP6;
	int	TMP5;
	int	VAR1;
	int	TMP3;
	int	TMP4;

	TMP0 = 1;
	VAR0 = TMP0;
	LBL6:
	TMP1 = 10;
	TMP2 = VAR0 < TMP1;
	TMP6 = !TMP2;
	if (TMP6) goto LBL3;
	TMP5 = 1;
	VAR1 = TMP5;
	LBL2:
	TMP3 = 1;
	TMP4 = VAR0 + TMP3;
	VAR0 = TMP4;
	goto LBL6;
	LBL3:

	return 0;
}
