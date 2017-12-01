#include <stdio.h>
#include <stdlib.h>
#define MAX 2

//PROGRAMA QUE VERIFICA A IDADE DA PESSOA

typedef struct
{
	int dia, mes, ano;
} Tdata;

typedef struct
{
	char nome[30];
	Tdata nasc;

} Tpessoa;




int main(int argc, char** argv)
{
	Tpessoa pessoa[MAX];
	int i;
	int idade = 0;
	int diaAtual = 20;
	int mesAtual = 02;
	int anoAtual = 2017;


	for(i = 0; i < MAX; i++)
	{
		printf("\n\nInforme o nome da pessoa %d: ", i + 1);
		fflush(stdin);
		gets(pessoa[i].nome);

		printf("Informe o dia de nascimento: ");
		scanf("%d", &pessoa[i].nasc.dia);

		printf("Informe o mes de nascimento: ");
		scanf("%d", &pessoa[i].nasc.mes);

		printf("Informe o ano de nascimento: ");
		scanf("%d", &pessoa[i].nasc.ano);

		if(pessoa[i].nasc.mes <= mesAtual)
		{
			if(pessoa[i].nasc.dia <= diaAtual)
			{
				idade = anoAtual - pessoa[i].nasc.ano;
				printf("IDADE: %d", idade);
			}

		}
		else
		{
			idade = (anoAtual - pessoa[i].nasc.ano) - 1;
			printf("IDADE: %d", idade);
		}

	}


	return 0;
}
