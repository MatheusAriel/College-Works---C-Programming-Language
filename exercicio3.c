#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char string[100];
	
	printf("Digite a string");
	gets(string);
	
	int tamanho= 0;
	
	for(tamanho = strlen(string)-1; tamanho > -1; tamanho--)
	{
		 printf("%c", string[tamanho]);
	}
	return 0;
}