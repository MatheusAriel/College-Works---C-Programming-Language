#include <stdlib.h>
#include <stdio.h>
#define MAX 3


void retornaVetor(int *v1, int *v2)
{
	int i, j;
	int v3[MAX * 2];
	int aux;

	for(i = 0; i < MAX; i++)
	{
		v3[i] = v1[i];
	}
	int k = i;

	for(i = 0; i < MAX; i++)
	{
		aux = 0;
		for(j = 0; j < MAX; j++)
		{

			if(v2[i] == v1[j])
			{
				aux = 1;
			}

		}
		if(aux == 0)
		{
			v3[k] = v2[i];
			k++;
		}
	}


	for(i = 0; i < k; i++)
	{
		printf("%d \t", v3[i]);

	}

}



int main()
{
	int i;
	int v1[MAX];
	int v2[MAX];

	int *pv1, *pv2;

	pv1 = v1;
	pv2 = v2;

	printf("\n\nVetor 1: ");
	for(i = 0; i < MAX; i++)
	{
		printf("Informe o elemento [%d]: ", i + 1);
		scanf("%d", &v1[i]);
	}


	printf("\n\nVetor 2: ");
	for(i = 0; i < MAX; i++)
	{
		printf("Informe o elemento [%d]: ", i + 1);
		scanf("%d", &v2[i]);
	}



	printf("\n\nRETORNO DA FUNCAO: ");

	retornaVetor(pv1, pv2);





	return 0;
}
