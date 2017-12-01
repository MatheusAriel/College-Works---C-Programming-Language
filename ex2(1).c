#include <stdio.h>
#include <stdlib.h>
#define MAX 2

int somamatriz();


int main(int argc, char** argv)
{
	int matrizA[MAX][MAX], matrizB[MAX][MAX], i,j;
	printf("\n preencha a matriz A posicao: \n");
	for(i = 0; i < MAX; i++)
	{
		for(j = 0; j < MAX; j++)
		{
			
			scanf("%d", &matrizA[i][j]);
		}
	}
	
	printf("\n preencha a matriz B posicao: \n");
	for(i = 0; i < MAX; i++)
	{
		for(j = 0; j < MAX; j++)
		{
			
			scanf("%d", &matrizB[i][j]);
		}
	}

	somamatriz(matrizA, matrizB);


	return 0;
}

int somamatriz(int matrizA[][MAX], int matrizB[][MAX])
{
	int matrizC[MAX][MAX], i, j, auxa, auxb;

	for(i = 0; i < MAX; i++)
	{
		for(j = 0; j < MAX; j++)
		{
			matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
		}
	}
    printf("Matriz C = Soma das posicoes de A e B \n");
	for(i = 0; i < MAX; i++)
	{
		printf ("\n");
		
		for(j = 0; j < MAX; j++)
		{
			
			printf (" %d \t", matrizC[ i ][ j ]);
		}
	}
}
