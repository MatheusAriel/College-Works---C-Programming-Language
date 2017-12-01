#include <stdio.h>
#include <stdlib.h>
#define MAX 2

typedef struct
{

	int codigo;
	char nome[30];
	int quantidade;
	float preco;
} PRODUTO;

PRODUTO produtos[MAX];

int main()
{
	int i;


	FILE *p;

	if((p = fopen("produtos.bat", "wb+")) == NULL)
	{
		printf( "Erro na abertura do arquivo");
		exit(0); 
	}

	for(i = 0; i< MAX; i++)
	{

		printf("\nInforme o codigo do produto %d: ", i + 1);
		scanf("%d", &produtos[i].codigo);

		fflush(stdin);
		printf("\n\nInforme o nome: ");
		gets(produtos[i].nome);
		fflush(stdin);

		printf("\nInforme a quantidade de produto(s): ");
		scanf("%d", &produtos[i].quantidade);

		printf("\nInforme o preco unitario: ");
		scanf("%f", &produtos[i].preco);

		if (fwrite( &produtos[i], sizeof ( PRODUTO), 1, p) != 1)
		{
			puts("Erro na escrita...");
		}
		//fprintf(p, "\n\Livro %d: - Titulo: %s - Autor: %s - Ano: %d", i + 1, livros[i].titulo, livros[i].autor, livros[i].ano);
	}
	rewind(p);


	for (i = 0; i < MAX; i++)
	{
		if (fread(&produtos[i], sizeof (PRODUTO), 1, p) == 1)
		{

			printf("\n\n========================================\n");
			printf("\nCodigo: %d", produtos[i].codigo);
			printf("\nNome: %s", produtos[i].nome);
			printf("\nQuantidade: %d", produtos[i].quantidade);
			printf("\nPreco: %1.2f", produtos[i].preco);
			printf("\n========================================\n\n");

		}
	}
	fclose(p);

	return 0;
}
