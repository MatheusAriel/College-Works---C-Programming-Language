#include <stdlib.h>
#include <stdio.h>

int matriz_produto(int m[][3])//passagem por referencia
{
	int i, prod=1;
	
	for(i=0;i<3;i++)
	{
		   prod = prod * m[i][2-i];	   	
	}
	
}

int main(void)
{
	int m[3][3]=  rand()%30;
	printf("%d",matriz_produto(m));
	return 0;
}

