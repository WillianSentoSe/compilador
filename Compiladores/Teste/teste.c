/*Compilador Ç*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int main(void)
{
	char*	TMP0;
	int	TMP1;
	int	VAR0;

	TMP0 = (char*) malloc(sizeof(char) * 19);
	TMP0 = "Digite um valor:\n";
	printf("%s", TMP0);
	scanf("%d", &TMP1);;
	VAR0 = TMP1;

	return 0;
}
