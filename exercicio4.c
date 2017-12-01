#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char string[100];
	char string2[100];
	char aux[100];
	int tamanho = 0;



	printf("Digite a string");
	gets(string);
	strcpy(aux, string);

	

	for(tamanho = strlen(string) - 1; tamanho > -1; tamanho--)
	{
		string[tamanho];
		strcpy(string2, string);
	}
	printf("%s", string2);

	if(strcmp(aux, string2) == 0)
	{
		printf("\n palindromo");
	}
	else
	{
		printf("\n nao palimdromo");
	}

	return 0;
}
