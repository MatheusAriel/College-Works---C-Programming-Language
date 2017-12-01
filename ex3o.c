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

	if((p = fopen("arquivo.dat", "wb+")) == NULL)
	{
		printf( "Erro na CRIACAO  do arquivo");
		exit(0);
	}




	for(i = 0; i < MAX; i++)
	{

		fflush(stdin);
		printf("Informe o prontuario: ");
		scanf("%d", &alunos[i].prontuario);
		fflush(stdin);
		printf("Informe o nome: ");
		gets(alunos[i].nome);
		fflush(stdin);

		printf("Informe a primeira nota: ");
		scanf("%f", &alunos[i].nota_p1);

		printf("Informe a segunda nota: ");
		scanf("%f", &alunos[i].nota_p2);

		alunos[i].mediaFinal = (alunos[i].nota_p1 + alunos[i].nota_p2) / 2;

		printf("%2.1f", alunos[i].mediaFinal);
		
		if (fwrite( &alunos[i], sizeof ( ALUNO), 1, p) != 1)
		{
			puts("Erro na escrita.");
		}

	}

	rewind(p);

	fclose(p);
	return 0;
}
