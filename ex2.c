#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct
{

	char titulo[30];
	char autor[15];
	int ano;
} LIVRO;


LIVRO livros[MAX];

int main()
{
	int tamanhoCadastro;
	int i;


	FILE *p;

	if((p = fopen("livros.bat", "wb+")) == NULL)
	{
		printf( "Erro na abertura do arquivo");
		exit(0); // aborta a execução do programa
	}

	printf("Informe o quantos livros deseja cadastrar: ");
	scanf("%d", &tamanhoCadastro);




	for(i = 0; i < tamanhoCadastro; i++)
	{

		fflush(stdin);
		printf("\n\nInforme o titulo do livro %d: ", i + 1);
		gets(livros[i].titulo);
		fflush(stdin);

		printf("Informe o autor: ");
		gets(livros[i].autor);
		fflush(stdin);

		printf("Informe o ano: ");
		scanf("%d", &livros[i].ano);

		if (fwrite( &livros[i], sizeof ( LIVRO), 1, p) != 1)
		{
			puts("Erro na escrita...");
		}
		//fprintf(p, "\n\Livro %d: - Titulo: %s - Autor: %s - Ano: %d", i + 1, livros[i].titulo, livros[i].autor, livros[i].ano);
	}
	rewind(p);


	for (i = 0; i < tamanhoCadastro; i++)
	{
		if (fread(&livros[i], sizeof (LIVRO), 1, p) == 1)
		{
			
			printf("\n\n========================================\n");
			printf("\nTitulo: %s", livros[i].titulo);
			printf("\nAutor: %s", livros[i].autor);
			printf("\nAno: %d",livros[i].ano);
			printf("\n========================================\n\n");
			
		}
	}
	fclose(p);

	return 0;
}
