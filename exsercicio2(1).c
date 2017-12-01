#include <stdio.h>
#include <stdlib.h>
#define MAX 2

typedef struct
{
	int codigo;
	char nome[30];
} Rreg;


int main(int argc, char** argv)
{
	int i;
	Rreg registro[MAX];
	int codigo;

	for(i = 0; i < MAX; i++)
	{
		printf("\nInforme o codigo: ");
		scanf("%d", &registro[i].codigo);

		printf("Informe o nome: ");
		fflush(stdin);
		gets(registro[i].nome);

	}


	printf("\n\nInforme o codigo desejado: ");
	scanf("%d", &codigo);


	for(i = 0; i < MAX; i++)
	{
		if(codigo == registro[i].codigo)
		{
			printf("\n\n%s", registro[i].nome);
		}
		/*
		else if(codigo != registro[i].codigo)
		{
			printf("Nao tem nenhuma profissao com esse codigo");
		}
		*/
		
		
		

	}



	return 0;
}
