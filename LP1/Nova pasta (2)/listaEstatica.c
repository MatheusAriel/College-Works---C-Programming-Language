#include <stdio.h>
#include <stdlib.h>
#define  max 5

typedef struct
{
	int elem[5];
	int inicio;
	int fim;//qtd elementos na lista
} LISTA;

void inicializa_lista(LISTA *l)
{
	l->inicio = 0;
	l->fim = 0;
}

int inserir_lista(LISTA *l, int elem, int pos)
{
	int i;

	if(l->fim == max)
	{
		printf("Errro, lista cheia");
		return 0;
	}

	if(pos < 0 || pos > l->fim)
	{
		printf("ERRO");
		return 0;
	}

	for(i = l->fim; i > pos; i--)
	{
		l->elem[i] = l->elem[i - 1];
	}

	l->elem[pos] = elem;
	l->fim++;
	return 1;
}

int remove_lisra(LISTA *l, int *elem, int pos)
{
	int i;

	if(l->fim == 0)
	{
		printf("lista vazia");
		return 0;
	}

	if(pos < 0 || pos >= l->fim)
	{
		printf("posicao invalida");
		return 0;
	}

	*elem = l->elem[pos];

	for(i = pos; i < l->fim - 1; i++)
	{
		l->elem[i] = l->elem[i + 1];
	}

	l->fim--;
}

void mostrar_lista(LISTA *l)
{
	int i;

	for(i = 0; i < l->fim; i++)
	{
		printf("%d ", l->elem[i]);
	}
}


int remove_maior(LISTA *l)
{
	int i;
	int maior = l->elem[0];
	int pos = 0;

	for(i = 0; i < l->fim; i++)
	{
		if(l->elem[i] > maior)
		{
			maior = l->elem[i];

			pos = i;
		}


	}

	return remove_lisra(l, &i, pos);



}
