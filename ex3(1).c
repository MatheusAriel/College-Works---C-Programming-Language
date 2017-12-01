#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	char nome[40];
	char email[40];
	int dia, mes, ano;

} PESSOA;

PESSOA *aloca()
{
	PESSOA *pessoa;
	pessoa = (PESSOA *) malloc(sizeof(PESSOA));
	
	return pessoa;
	
}


void inserePessoa(PESSOA *pessoa)
{
	printf("Informe o nome da Pessoa: \n");
	fflush(stdin);
	gets(&pessoa->nome);
	
	printf("Informe o email da Pessoa: \n");
	fflush(stdin);
	gets(&pessoa->email);
	
	
	printf("Infome o dia de nascimento: \n");
	scanf("%d",&pessoa->dia);
	
	printf("Infome o mes de nascimento: \n");
	scanf("%d",&pessoa->mes);
	
	printf("Infome o ano de nascimento: \n");
	scanf("%d",&pessoa->ano);
}

void mostraPessoa(PESSOA *pessoa)
{
	printf("\n\nNOME: %s",pessoa->nome);
	printf("\nEMAIL: %s",pessoa->email);
	printf("\nDATA NASCIMENTO: %d/%d/%d ",pessoa->dia,pessoa->mes,pessoa->ano);
}

int main()
{
	PESSOA *pessoa = aloca();
	
	inserePessoa(&pessoa);
	mostraPessoa(&pessoa);

	return 0;
}
