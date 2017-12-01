#include <stdio.h>
#include <stdlib.h>
#define MAX 2


typedef struct
{
	int prontuario;
	char nome[30];
	float nota_p1;
	float nota_p2;
	float mediaFinal;

} ALUNO;

ALUNO alunos[MAX];



int main(int argc, char** argv)
{
	int i;
	FILE *p;

	if((p = fopen("arquivo.dat", "rb")) == NULL)
	{
		printf( "Erro na CRIACAO  do arquivo");
		exit(0); // aborta a execução do programa
	}

	rewind(p);
	for (i = 0; i < MAX; i++)
	{
		if (fread(&alunos[i], sizeof (ALUNO), 1, p) != 1)
		{
			puts("Erro na escrita.");
			if (feof(p)) break;
			puts("Erro na leitura.");
		}
	}


	//puts("Imprimindo os dados lidos do arquivo.");
	for (i = 0; i < MAX; i++)
	{
		if(alunos[i].mediaFinal >= 6)
		{
			printf("\n\n==================================================\n");
			printf("\nProntuario: = %d\n\n", alunos[i].prontuario);
			printf("\nNome = %s\n\n", alunos[i].nome);
			printf("\nNOTA P1: = %1.2f\n\n", alunos[i].nota_p1);
			printf("\nNOTA P2: = %1.2f\n\n", alunos[i].nota_p2);
			printf("\nMedia Final: = %1.2f\n\n", alunos[i].mediaFinal);
			printf("\n\n==================================================\n");
		}

	}
	fclose(p);
	return 0;
}
