#include <stdio.h>
#include <stdlib.h>
#define MAX 2


typedef struct
{
	char nome[30];
	float nota1;
	float nota2;
	float media;

} REGlp;



void escrever(REGlp *dados)
{
	int i;

	//fflush(stdin);
	printf("\nInforme o nome do aluno: ");
	fflush(stdin);
	gets(dados->nome);

	printf("Informe a primeira nota: ");
	scanf("%f", &dados->nota1);

	printf("Informe a segunda nota: ");
	scanf("%f", &dados->nota2);

	dados->media = (dados->nota1 + dados->nota2) / 2;



	//printf("Media: %f",mediaAluno);


}


void mediaAluno(REGlp *dados)
{
	if(dados->media >= 6)
	{
		printf("\n\nAprovado");

	}
	if(dados->media >= 4 && dados->media < 6)
	{

		printf("\n\nEXAME");
	}
	else if(dados->media < 4)
	{
		printf("\n\nREPROVADO");
	}

}


int main(int argc, char** argv)
{
	REGlp registro[MAX];
	int i;

	for (i = 0; i < MAX; i++)
	{
		escrever(&registro[i]);
		mediaAluno(&registro[i]);
	}






		return 0;
}



