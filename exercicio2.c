#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char string1[50] = "";
	char string2[50] = "";
	char concatenacao[100] = "";
	
	printf("Digite o primera string\n");
	gets(string1);
	
	printf("\nDigite a segunda string\n");
	gets(string2);

	
	if(strcmp(string1, string2) == 0)
	{
		printf("Strings iguais\n");
	}
	else
	{
		strcat(concatenacao, string1);
		strcat(concatenacao, string2);
		printf("\nStrings diferentes\n");
		printf("\n%s",concatenacao);
	}
	return 0;
}
