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

	if((p = fopen("PROFISSOES.dat", "wb+")) == NULL)
	{
		printf( "Erro na CRIACAO  do arquivo");
		exit(0); // aborta a execução do programa
	}

	for(i = 0; i < MAX; i++)
	{

		fflush(stdin);
		printf("\n\nInforme o codigo: ");
		scanf("%d", &profissoes[i].codigo);
		fflush(stdin);
		
		printf("Informe o nome da profissao: ");
		gets(profissoes[i].nome);
		fflush(stdin);

	

		if (fwrite( &profissoes[i], sizeof (PROFISSAO), 1, p) != 1)
		{
			puts("Erro na escrita.");
		}

	}

	rewind(p);
	fclose(p);
	return 0;
}

