#include <stdlib.h>
#include <stdio.h>
#define max 3
typedef struct
{
	float salario;
	char sexo;
	int idade;
	int num_filhos;
} HABITANTES;


void preenche_habitantes(HABITANTES hab[])
{
	int i;
	char lixo[2];
	for(i = 0; i < max; i++)
	{
		printf("\nInforme o sexo: ");
		scanf("%c", &hab[i].sexo);

		printf("Informe o numero de filhos: ");
		scanf("%d", &hab[i].num_filhos);

		printf("Informe a idade: ");
		scanf("%d", &hab[i].idade);

		printf("Informe o salario:R$");
		scanf("%f", &hab[i].salario);

		gets(lixo);

	}
}

void media_salario(HABITANTES hab[])
{
	int i;
	float soma=0, media=0;
	
	for(i=0;i<max;i++)
	{
		soma = soma + hab[i].salario;
	}
	media = soma / max;
	
	printf("\nA media de salario eh: %.2f",media);
}

void media_num_filhos(HABITANTES hab[])
{
	int i;
	float soma=0, media=0;
	
	for(i=0;i<max;i++)
	{
		soma = soma + hab[i].num_filhos;
	}
	media = soma/max;
	
	printf("\nA media de filhos eh: %f",media);
}

void maior_salario(HABITANTES hab[])
{
	int i;
	float maior=0;
	
	for(i=0;i<max;i++)
	{
		if(maior<hab[i].salario)
		{
			maior = hab[i].salario;
		}
	}
	printf("\nO maior salario eh: %f",maior);
}

void salario_superior_1500 (HABITANTES hab[])
{
	int i, soma_mulheres=0, qntd_mulheres_salario_maior=0;
	float media;
	
	for(i=0;i<max;i++)
	{
		if(hab[i].sexo == 'f' || hab[i].sexo == 'F')
		{
			soma_mulheres++;
			if(hab[i].salario>1500)
			{
				qntd_mulheres_salario_maior++;
			}
			
		}
	}
	media = (qntd_mulheres_salario_maior/ (float)soma_mulheres)* 100;
	printf("O percentual de mulher com salario maior que 1500 eh: %f",media);
}


int main(void)
{
	HABITANTES hab[max];
	preenche_habitantes(hab);
	media_salario(hab);
	media_num_filhos(hab);
	maior_salario(hab);



	return 0;
}
