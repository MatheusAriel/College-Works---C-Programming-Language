#include <stdlib.h>
#include <stdio.h>

int *aloca(int n)
{
	int *v;
	int i;
	v = (int *) malloc (n * sizeof (int));
	return v;
}

void liberaMemoria(int *v)
{
	free (v);
	printf("\n Memoria Liberada!!! \n");
}

void imprime(int *v, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf ("\n %d \n", *v++);

}
int main()
{
	int *v, *aux, n, i;
	printf("Informe o tamanho do vetor: ");
	scanf ("%d", &n);
	v = aloca(n);
	aux = v;

	if (v != NULL)
	{
		for (i = 0; i < n; i++)
		{
			printf("v[%d]: ", i);
			scanf ("%d", aux++);
		}

		aux = v;
	}

	imprime(v, n);
	liberaMemoria(*v);


	return 0;
}
