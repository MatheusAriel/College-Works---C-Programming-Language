#include <stdlib.h>
#include <stdio.h>




void preenche_matriz(int m[][3])
{	
	int i, j;
	   for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m [i][j] = rand()%30;	
}


void imprime_matriz(int m[][3])
{	
	int i, j;
	for(i=0;i<3;i++)
	{
		   	for (j=0;j<3;j++)
				printf("%d ",m[i][j]);	
			printf("\n");
	}
		
}

int verifica (int m[][3], int num)
{
	int i, j;
	
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(num == m[i][j])
				return 1;
	return 0;		
}


int main(void)
{
	int num;
	int m[3][3];
	int i, j;
	
	preenche_matriz(m);
	imprime_matriz(m);
	

	printf("Infome um numero: ");
	scanf("%d", &num);
		
	if(verifica(m,num))
		printf("Existe o numero na matriz");
	else
	{
		printf("Nao existe o numero na matriz");
	}	
	

	
	
	return 0;
}