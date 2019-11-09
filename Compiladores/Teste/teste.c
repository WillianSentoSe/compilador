#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int main(void)
{
	char*	TMP0;
	char*	VAR0;

	TMP0 = (char*)malloc(sizeof(char) * 29);
	TMP0[0] = 'v';
	TMP0[1] = 'i';
	TMP0[2] = 'n';
	TMP0[3] = 'i';
	TMP0[4] = 'c';
	TMP0[5] = 'i';
	TMP0[6] = 'u';
	TMP0[7] = 's';
	TMP0[8] = ' ';
	TMP0[9] = 'p';
	TMP0[10] = 'a';
	TMP0[11] = 'r';
	TMP0[12] = 'e';
	TMP0[13] = ' ';
	TMP0[14] = 'd';
	TMP0[15] = 'e';
	TMP0[16] = ' ';
	TMP0[17] = 'm';
	TMP0[18] = 'e';
	TMP0[19] = ' ';
	TMP0[20] = 'b';
	TMP0[21] = 'i';
	TMP0[22] = 'l';
	TMP0[23] = 'i';
	TMP0[24] = 's';
	TMP0[25] = 'k';
	TMP0[26] = '\\';
	TMP0[27] = 'n';
	TMP0[28] = '\0';
	VAR0 = TMP0;
	printf("%s", VAR0);

	return 0;
}
