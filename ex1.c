#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct
{

	char marca[15];
	int ano;
	float preco;
} CARRO;


CARRO carros[MAX];

int main()
{
	int tamanhoCadastro;
	int i;


	FILE *p;

	if((p = fopen("carros.txt", "w+")) == NULL)
	{
		printf( "Erro na abertura do arquivo");
		exit(0); // aborta a execução do programa
	}

	printf("Informe o quantos carros deseja cadastrar: ");
	scanf("%d", &tamanhoCadastro);




	for(i = 0; i < tamanhoCadastro; i++)
	{

		fflush(stdin);
		printf("\n\nInforme a marca do carro %d: ", i + 1);
		gets(carros[i].marca);
		fflush(stdin);

		printf("Informe o ano do carro: ");
		scanf("%d", &carros[i].ano);

		printf("Informe o preco do carro: ");
		scanf("%d", &carros[i].preco);




		fprintf(p, "\n\nCarro %d: - Marca: %s - Ano: %d - Preco: %2.1f",i+1, carros[i].marca, carros[i].ano, carros[i].preco);

	}
	fclose(p);





	return 0;
}
