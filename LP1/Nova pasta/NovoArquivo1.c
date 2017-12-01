#include <stdlib.h>
#include <stdio.h>
#define max 2

typedef struct 
{
char ra[20];
char nome [30];
float nota1, nota2;
}ALUNO;




void preenche_lp1(ALUNO turma[])
{	
	int i;
	char lixo[2];
	for(i=0;i<max;i++)
	{
		printf("Ra: ");
		gets(turma[i].ra);
		
		printf("Nome: ");
		gets(turma[i].nome);
		
		printf("NOTA 1: ");
		scanf("%f",&turma[i].nota1);
		
		printf("NOTA 2: ");
		scanf("%f",&turma[i].nota2);
		
		gets(lixo);
	}
	
}


void grava_arquivo (ALUNO turma[])
{
	FILE *arq;
	int i;
	arq = fopen("arquivo.txt","w");
	if(arq == NULL)
	{
		printf("Errro ao escrever o arquvio");
		system("pause");
		exit(1);
	}
	for(i=0;i<max;i++)
	{
		fprintf(arq,"%s \n%s\n %f %f\n",turma[i].ra, turma[i].nome, turma[i].nota1, turma[i].nota2);
	}
	
	fclose(arq);
}


void ler_arquivo(ALUNO turma[])
{
	FILE *arq;
	int i;
	arq = fopen("arquivo.txt","r");
	if(arq == NULL)
	{
		printf("Errro ao abrir o arquvio");
		system("pause");
		exit(1);
	}
	for(i=0;i<max;i++)
	{
		fscanf(arq,"%s %[^\n]s",turma[i].ra, turma[i].nome);
		fscanf(arq,"%f %f",&turma[i].nota1, &turma[i].nota2);
		printf("%s %s %f %f\n",turma[i].ra, turma[i].nome, turma[i].nota1, turma[i].nota2);		
	}
	
	fclose(arq);
	
	
}

int main(void)
{
	ALUNO turma[10]; 
	//preenche_lp1(turma);
	//grava_arquivo(turma);
	ler_arquivo(turma);
	
	
	return 0;
}