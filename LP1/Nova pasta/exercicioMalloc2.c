#include <stdlib.h>
#include <stdio.h>


int *alocaMemoria(int n)
{
	int *memoria;
	
	memoria= malloc(sizeof(int)*n);
	if(memoria==NULL)
	{
		printf("Erro na locacao de memoria");
		exit(0);
	}
	return memoria;
}

void imprime(int *vetor, int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d - endereço: %d\n",i+1, &vetor[i]);
}

void liberaMemoria(int *vetor)
{
	free(vetor);
}

int main()
{
	int n;
	int *vetor;
	
	
	printf("Informe quanto de memoria deseja reservar: ");
	scanf("%d",&n);
	
	vetor = alocaMemoria(n);
	 imprime(vetor, n);
	 liberaMemoria(vetor);
	
	
	return 0;
}