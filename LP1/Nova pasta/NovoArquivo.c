#include <stdio.h>
#include <stdlib.h>


int *alocaNumero(int num)
{
	float *memoria;
	int i;
	
	memoria = malloc(sizeof(float)*num);
	
	for(i=0;i<num;i++)
	{
		printf("\n[%d]numero: ",i+1);
		scanf("%f",&memoria[i]);
	}
	
	return memoria;
	
	
}

float mediaNumero(float *memoria, int num)
{
	float media=0;
	int i;
	
	for(i=0;i<num;i++)
	{
		media= media+memoria[i];
	}
	
	return media/num;
}

void exibeNum( float *memoria, int num)
{
	int i;
	for(i=0;i<num;i++)
	{
		printf("\n%d",memoria[i]);
	}
}



int main(void)
{
	int num;
	float *numero;
	
	printf("Informe a media de quantos numeros: ");
	scanf("%d", &num);
	
	numero= alocaNumero(num);
	
	printf("\nMedia: %2.f", mediaNumero(numero, num));
	
	
	
}