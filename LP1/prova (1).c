//Matheus Ariel de Souza RA: 140211-1

#include <stdlib.h>
#include <stdio.h>


typedef struct
{
	char nome[40];
	char sexo;
	char cor_olhos[30];
	int idade;
	float peso;
	float altura;
} MODELOS;



void escrever_arquivo()
{
	int i;
	char resposta;
	FILE *arq;
	MODELOS pessoa;



	arq = fopen("modelos.bin", "wb");
	if(arq == NULL)
	{
		printf("ERRO NA CRIACAO DO ARQUIVO");
		system("pause");
		exit(0);
	}

	do
	{

		fflush(stdin);
		printf("\nInforme o nome do modelo: ");
		gets(pessoa.nome);



		fflush(stdin);

		printf("Informe o sexo (m/f): ");
		scanf("%c", &pessoa.sexo);
		fflush(stdin);
		while(pessoa.sexo != 'm' && pessoa.sexo != 'f')
		{
			printf("\nPor favor digite m ou f");
			printf("\nInforme o sexo (m/f): ");
			scanf("%c", &pessoa.sexo);
			fflush(stdin);
		}


		fflush(stdin);

		printf("\nInforme a cor dos olhos: ");
		gets(pessoa.cor_olhos);

		printf("\nInforme a idade: ");
		scanf("%d", &pessoa.idade);

		fflush(stdin);

		printf("\nInforme o peso (kg): ");
		scanf("%f", &pessoa.peso);

		fflush(stdin);

		printf("\nInforme a altura (cm): ");
		scanf("%f", &pessoa.altura);

		fflush(stdin);

		fwrite(&pessoa, sizeof(MODELOS), 1, arq);


		printf("MODELO CADASTRADO COM SUCESSO");
		printf("\n================================\n");



		fflush(stdin);
		printf("\n\nDeseja cadastrar outro modelo (s/n): ");
		scanf("%c", &resposta);
	}
	while(resposta != 'n');
	fclose(arq);

}


void ler_arquivos()
{
	int i;
	FILE *arq;
	MODELOS pessoa;
	int total_mulheres = 0;
	int total_homens = 0;
	int total_idade = 0;
	float total_altura = 0;
	float total_peso = 0;
	FILE *h;
	FILE *m;

	arq = fopen("modelos.bin", "rb");
	if(arq == NULL)
	{
		printf("ERRO NA LEITURA DO ARQUIVO");
		system("pause");
		exit(0);
	}

	while(fread(&pessoa, sizeof(MODELOS), 1, arq))
	{

		printf("\n\nNome: %s\n", pessoa.nome);

		printf("Sexo: %c\n", pessoa.sexo);

		printf("Cor dos olhos: %s\n", pessoa.cor_olhos);

		printf("Idade: %d\n", pessoa.idade);

		printf("Peso: %.2f\n", pessoa.peso);

		printf("Altura: %.2f", pessoa.altura);

		if(pessoa.sexo == 'f')
		{
			total_mulheres++;

			m = fopen("mulheres.txt", "a+");
			if(m == NULL)
			{
				printf("\nERRO NA CRIACAO DO ARQUIVO\n");
				system("pause");
				exit(0);
			}
			else
			{
				/*
				fprintf(m, "Nome: %s\n", pessoa.nome);
				fprintf(m, "sexo: %c\n", pessoa.sexo);
				fprintf(m, "Cor dos olhos: %s\n", pessoa.cor_olhos);
				fprintf(m, "Idade: %d\n", pessoa.idade);
				fprintf(m, "Peso: %.2f\n", pessoa.peso);
				fprintf(m, "Altura: %.2f\n", pessoa.altura);
				*/
				fprintf(m, "%s %c %s %d %.2fKG %.2fCM\n", pessoa.nome, pessoa.sexo, pessoa.cor_olhos, pessoa.idade, pessoa.peso, pessoa.altura);

			}
		}


		if(pessoa.sexo == 'm')
		{
			total_homens++;

			h = fopen("homens.txt", "a+");
			if(h == NULL)
			{
				printf("\nERRO NA CRIACAO DO ARQUIVO\n");
				system("pause");
				exit(0);
			}
			else
			{

				/*
				fprintf(h, "Nome: %s\n", pessoa.nome);
				fprintf(h, "sexo: %c\n", pessoa.sexo);
				fprintf(h, "Cor dos olhos: %s\n", pessoa.cor_olhos);
				fprintf(h, "Idade: %d\n", pessoa.idade);
				fprintf(h, "Peso: %.2f\n", pessoa.peso);
				fprintf(h, "Altura: %.2f\n", pessoa.altura);
				*/
				fprintf(h, "%s %c %s %d %.2fKG %.2fCM\n", pessoa.nome, pessoa.sexo, pessoa.cor_olhos, pessoa.idade, pessoa.peso, pessoa.altura);
			}

		}

	}

	if(pessoa.idade)
		total_idade = total_idade + pessoa.idade;
	if(pessoa.altura)
		total_altura = total_altura + pessoa.altura;
	if(pessoa.peso)
		total_peso = total_peso + pessoa.peso;

	printf("\n\nMedia idade: %d", (total_idade) / (total_mulheres + total_homens));
	printf("\n\nMedia altura: %.2f", (total_altura) / (total_mulheres + total_homens));
	printf("\n\nMedia peso: %.2f", (total_peso) / (total_mulheres + total_homens));
	fprintf(h, "Total homens: %d\n", total_homens);
	fprintf(m, "Total mulheres: %d\n", total_mulheres);
	fclose(m);
	fclose(h);
	fclose(arq);
}











int main(void)
{


	//ler_arquivos();
	escrever_arquivo();


	return 0;
}
