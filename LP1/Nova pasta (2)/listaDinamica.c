#include <stdlib.h>
#include <stdio.h>

typedef struct SNO
{
	int elem;
	struct SNO *prox;
} NO;


void inicializa_lista(NO **lista)
{
	*lista = NULL;
}


int inserir_lista(NO **lista, int elem, int pos)
{
	if(pos < 0)
	{
		printf("posicao invalida");
		return 0;
	}

	if(pos == 0)//insercao no inicio da lista
	{
		NO *p = malloc(sizeof(NO));

		p->elem = elem;
		p->prox = *lista;
		*lista = p;
	}

	else
	{
		NO *aux = *lista;
		while(aux->prox != NULL && pos > 1)
		{
			aux = aux->prox;
			pos--;
		}

		if(pos != 1)
		{
			printf("Posicao invalida2");
			return 0;
		}

		NO *p = malloc(sizeof(NO));

		p->elem = elem;
		p->prox = aux->prox;
		aux->prox = p;

	}
	return 1;

}

int remove_lista(NO **lista, int *elem, int pos)
{
	NO *aux = *lista;
	NO *remove;

	if(pos < 0)
	{
		printf("posicao invalida");
		return 0;
	}

	if(*lista == NULL)
	{
		printf("lista vazia");
		return 0;
	}

	if(pos == 0)
	{
		remove = *lista;
		*lista = (*lista)->prox;
		free(remove);


	}

	else
	{
		while(aux->prox != NULL && pos > 1)
		{
			aux = aux->prox;
			pos--;
		}

		if(aux->prox == NULL)
		{
			printf("Posicao invalida");
			return 0;
		}

		remove = aux->prox;
		aux->prox = aux->prox->prox;

		free(remove);
	}


	return 1;

}


int remove_maior(NO **lista)
{
	NO *aux;
	int maior;
	int pos = 0;
	int i = 1;

	if(*lista == NULL)
	{
		printf("lista vazia");
		return 0;
	}

	maior = (*lista)->elem;

	aux = (*lista)->prox;

	while(aux != NULL)
	{
		if(aux->elem > maior)
		{
			pos = i;
			maior = aux->elem;
		}
		i++;
		aux = aux->prox;
	}

	return remove_lista(lista, &i, pos);

}

void mostra_lista(NO **lista)
{
	NO *aux = *lista;
	while(aux != NULL)
	{
		printf("%d ", aux->elem);
		aux = aux->prox;
	}
	printf("\n");
}

int main()
{
	int x;
	NO *lista;
	inicializa_lista(&lista);
	inserir_lista(&lista, 1, 0);
	inserir_lista(&lista, 2, 1);
	inserir_lista(&lista, 3, 2);
	inserir_lista(&lista, 90, 2);
	mostra_lista(&lista);
	remove_maior(&lista);
	mostra_lista(&lista);

	return 0;
}
