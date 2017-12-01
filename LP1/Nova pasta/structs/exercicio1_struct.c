#include <stdlib.h>
#include <stdio.h>


typedef struct 
{
	int cod_disc;
	char nome_disc[30];
	int num_cred;
	
}DISCIPLINA;

void preenche_func(DISCIPLINA disc[], int *tamanho)
{
	int i, opcao;
	char lixo[2];
	for(i=0;i<20;i++)
	{
  	  printf("Infome o nome da disciplina: ");
      gets(disc[i].nome_disc);	
      
      printf("Informe o codigo da disciplina: ");
      scanf("%d",&disc[i].cod_disc);
      
      printf("Informe o numero de creditos: " );
      scanf("%d",&disc[i].num_cred);
      
      printf("Digite 0 se deseja parar: ");
      scanf("%d",&opcao);
      
      gets(lixo);
      
      if(opcao == 0)
      	break;
	}
	*tamanho = i+1;
}

void imprime_func(DISCIPLINA disc[], int tamanho)
{	
	int i;
	for(i=0;i<tamanho;i++)
	{
		printf("%s\t %d\t %d \n", disc[i].nome_disc, disc[i].cod_disc, disc[i].num_cred);
	}
	
}

int main(void)
{	
	int tamanho;
	DISCIPLINA disc[20];
	preenche_func(disc, &tamanho);
	imprime_func(disc, tamanho);
	return 0;
}