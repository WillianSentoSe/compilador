#include <stdio.h>

#define true 1
#define false 0

int main(void)
{
	int	TMP0;
	int	VAR0;
	int	TMP1;
	int	TMP2;
	int	TMP4;
	int	TMP3;
	int	TMP6;
	int	TMP5;

	TMP0 = 0;
	VAR0 = TMP0;
	TMP5 = 0;
	TMP6 = TMP5 == VAR0;
	if (TMP6) goto LBL3;
	LBL3:
	TMP1 = 10;
	VAR0 = TMP1;
	TMP3 = 11;
	TMP4 = TMP3 == VAR0;
	if (TMP4) goto LBL2;
	LBL2:
	TMP2 = 20;
	VAR0 = TMP2;
	goto LBL1;
	LBL1:
	goto LBL0;
	LBL0:
	
	printf("[%d]\n", VAR0);

	return 0;
}
