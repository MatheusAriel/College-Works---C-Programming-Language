#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nome[40];
	char sexo;
	char cor_olhos[20];
	int idade;
	float altura;
	float peso;

} DADOS;


void escreve_arquivo()
{
	DADOS modelo;
	FILE *arq;
	char resposta;

	arq = fopen("MODELOS.bin", "ab");
	if(arq == NULL)
	{
		printf("ERRO NA CRIACAO DO ARQUIVO");
		system("pause");
		exit(0);
	}


	do
	{
		printf("Informe o nome do modelo: ");
		gets(modelo.nome);

		fflush(stdin);

		printf("\nInforme o sexo do modelo(m/f): ");
		scanf("%c", &modelo.sexo);

		fflush(stdin);

		printf("\nInforme a cor dos olhos: ");
		gets(modelo.nome);

		fflush(stdin);

		printf("\nInforme a idade: ");
		scanf("%d", &modelo.idade);

		printf("\nInforme a altura: ");
		scanf("%f", &modelo.altura);

		printf("\nInforme o peso: ");
		scanf("%f", &modelo.peso);

		fflush(stdin);

		fwrite(&modelo, sizeof(MODELOS), 1, arq);
		//para txt eh assim fprintf(arq,"%s, %c, %s, %d, %f, %f",modelo.nome);


		printf("MODELO CADASTRADO COM SUCESSO");

		printf("\n\nDeseja cadastrar mais modelos?: ");
		scanf("%c", &resposta);

		fflush(stdin);

	}
	while(resposta == 'S');
	fclose(arq);
}

void ler_arquivo()
{
	
	
	
	
}



int main(void)
{
	escreve_arquivo();
	return 0;
}
