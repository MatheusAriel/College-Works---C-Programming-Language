#include <stdlib.h>
#include <stdio.h>
#define MAX 2


typedef struct
{
	int codigo;
	char nome[30];
} PROFISSAO;

PROFISSAO profissoes[MAX];



int main(int argc, char** argv)
{
	int i;
	FILE *p;
	int cod;

	if((p = fopen("PROFISSOES.dat", "rb")) == NULL)
	{
		printf( "Erro na CRIACAO  do arquivo");
		exit(0); // aborta a execução do programa
	}


	rewind(p);
	for (i = 0; i < MAX; i++)
	{
		if (fread(&profissoes[i], sizeof (PROFISSAO), 1, p) != 1)
		{
			puts("Erro na escrita.");
			if (feof(p)) break;
			puts("Erro na leitura.");
		}
	}


	printf("Innforme o codigo Desejado: ");
	scanf("%d",&cod);

	
	for (i = 0; i < MAX; i++)
	{
		if(profissoes[i].codigo == cod)
		{
			printf("\n\n==================================================\n");
			printf("\nCodigo: = %d\n\n", profissoes[i].codigo);
			printf("\nNome = %s\n\n", profissoes[i].nome);
			printf("\n\n==================================================\n");
		}
		else
		{
			cod = -10;
		}

	}
	
	if(cod == -10)
	{
		printf("Codigo invalido");
	}
	fclose(p);
	return 0;

}
