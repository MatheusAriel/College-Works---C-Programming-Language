#include <stdio.h>
#include <stdlib.h>

struct Tproduto
{
	int codigo; /* Codigo do produto */
	double preco; /* Preco do produto */
	struct Tproduto *proximo;
};
typedef struct Tproduto TProduto;


void listar (TProduto *noatual)
{
	int i = 0;
	while( noatual != NULL) /* Enquanto nao chega no fim da lista */
	{
		i++;
		printf("\n\nProduto numero %d\nCodigo: %d \nPreco:R$%.2lf", i,
			   noatual->codigo, noatual->preco);
		noatual = noatual->proximo; 
	}
}

void listarTotal (TProduto *noatual)
{
	int i = 0;
	while( noatual != NULL) /* Enquanto nao chega no fim da lista */
	{
		i++;
		noatual = noatual->proximo; 
	}
	printf("Total de elementos na lista: %d",i);
}

void mediaPrecos (TProduto *noatual)
{
	int i = 0;
	double media=0;
	while( noatual != NULL) /* Enquanto nao chega no fim da lista */
	{
		i++;
		//printf("\n\nProduto numero %d\nCodigo: %d \nPreco:R$%.2lf", i,
		//	   noatual->codigo, noatual->preco);
			   media = media + noatual->preco;
		noatual = noatual->proximo; 
	}
	printf("Media: %f",media);
}


void inserir (TProduto **cabeca)
{
	TProduto *noatual, *novono;
	int cod;
	double preco;
	printf("\n Codigo do novo produto: ");
	scanf("%d", &cod);
	printf("\n Preco do produto:R$");
	scanf("%lf", &preco);
	if (*cabeca == NULL) /* Se ainda nao existe nenhum produto na lista */
	{
		/* cria o no cabeca */
		*cabeca = (TProduto *) malloc(sizeof(TProduto));
		(*cabeca)->codigo = cod;
		(*cabeca)->preco = preco;
		(*cabeca)->proximo = NULL;
	}
	else
	{
		/* Se ja existem elementos na lista, deve percorre-la ate' o seu final e inserir o
		novo elemento */
		noatual = *cabeca;
		while(noatual->proximo != NULL)
			noatual = noatual->proximo;
		novono = (TProduto *) malloc(sizeof(TProduto));
		novono->codigo = cod;
		novono->preco = preco;
		novono->proximo = NULL;
		noatual->proximo = novono; /* Faz o ultimo no apontar para o novo no */
	}
}


int main()
{
	TProduto *cabeca = NULL; /* Ponteiro para a cabeca da lista */
	TProduto *noatual; /* Ponteiro a ser usado para percorrer a lista no momento de
desalocar seus elementos*/
	char q; /* Caractere para receber a opcao do usuario */
	do
	{
		printf("\n\nOpcoes: \nI -> para inserir novo produto;\nL -> para listar os produtos;\nM-> Media preco\nN-> Total Lista \nS -> para sair \n:");
		scanf("%c", &q); /* Le a opcao do usuario */
		switch(q)
		{
		case 'i':
		case 'I':
			inserir(&cabeca);
			break;
		case 'l':
		case 'L':
			listar(cabeca);
			break;
		case 's':
		case 'S':
			break;
		case 'm':
		case 'M':
			mediaPrecos(cabeca);	
			break;
		case 'n':
		case 'N':
			listarTotal(cabeca);	
			break;
		default:
			printf("\n\n Opcao nao valida");
		}
		getchar(); /* Limpa o buffer de entrada */
	}
	while ((q != 's') && (q != 'S') );
	/* Desaloca a memoria alocada para os elementos da lista */
	noatual = cabeca;
	while (noatual != NULL)
	{
		cabeca = noatual->proximo;
		free(noatual);
		noatual = cabeca;
	}
}
