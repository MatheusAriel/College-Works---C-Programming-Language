#include <stdlib.h>
#include <stdio.h>

int *retornaPonteiro(int m, int n)
{
	int *aloca;
	aloca = malloc(sizeof(int) * m * n);
	if(aloca == NULL)
	{
		printf("Erro nao há memoria disponivel");
		exit (1);
	}

	return aloca;

}

void libera (int *matriz)
{
	free(matriz);
}

int main()
{
	int m, n;
	int *matriz;
	int i, j;
	printf("Digite os numeros de linhas da matriz:");
	scanf("%d", &m);

	printf("Digite o numero de colunas da matriz: ");
	scanf("%d", &n);



	matriz = retornaPonteiro(m, n);

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d \t", matriz[i * m + j]);
		puts("");
	}

	libera(matriz);

	return 0;
}


