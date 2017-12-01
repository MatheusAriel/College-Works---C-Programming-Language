#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int *p, n, i;
	printf("Quantos números deseja armazenar no vetor ? \n");
	scanf("%d", &n);
	p = (int *) malloc(n * sizeof(int)); /*
Aloca espaço para armazenar n
números inteiros.*/
	if (!p)
	{
		printf ("Erro: Memoria Insuficiente !");
		exit(0);
	}

	for (i = 0; i < n ; i++)
	{
		p[i] = i * i;
		printf("Elemento da posicao %d = %d \n", i, p[i]);
	}
	/* O tamanho de p deve ser
	modificado, por algum motivo */
	printf("Quantos números deseja armazenar agora no vetor ? \n");
	int m = n;
	scanf("%d", &n);
	p = (int *)realloc (p, n * sizeof(int));
	if(n > m)
		for (i = m; i < n ; i++)
		{
			p[i] = n * i * (i - 6);

		}

	for (i = 0; i < n ; i++)
	{
		
		printf("Elemento da posicao %d = %d\n", i, p[i]);
	}
	free(p);
}

