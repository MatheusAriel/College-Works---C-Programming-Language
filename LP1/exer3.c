#include <stdio.h>
#include <stdlib.h>
#define max 10

typedef struct 
{
	char numero_conta[6],nome_client[40];
	float saldo;
}CONTA;									//struct para armazenar as contas lidas

typedef struct 
{
	char numero_mov[6],tipo;
	float valor;
}MOVIMENTO;								//struct para armazenar os movimentos realizados pelo arquivo

void ler_contas(CONTA c[])				//funcao para ler do arquivo contas e armazenar no programa
{	FILE *arq;
	int i=0;
	arq=fopen("contas.bin","rb");
	if(arq==NULL)
	{
		printf("problema ao abrir arquivo binario");
		system("pause");
		exit(0);
	}
	while(!feof(arq))
	{	
		while(!feof(arq))
		{	
			fread(&c[i].numero_conta,sizeof(char),6,arq);
			printf("NUMERO: %s\n",c[i].numero_conta); 
			fread(&c[i].nome_client,sizeof(char),40,arq);
			printf("NOME: %s\n",c[i].nome_client);
			fread(&c[i].saldo,sizeof(float),1,arq);
			printf("SALDO: %.2f\n",c[i].saldo); 
			i++;
			printf("\n");
		}
		
		fclose(arq);
	}
}

void ler_movimentacoes(MOVIMENTO mov[])				//funcao para ler movimentacoes feitas no arquivo
{	FILE *p;
	int i;
	p=fopen("moviment.bin","rb");
	if(p==NULL)
	{
		printf("problema ao abrir arquivo binario");
		system("pause");
		exit(0);
	}
	for(i=0;i<max;i++)
	{	
		fread(&mov[i].numero_mov,sizeof(char),6,p);
		printf("NUMERO: %s\n",mov[i].numero_mov); 
		fread(&mov[i].tipo,sizeof(char),1,p);
		printf("TIPO: %c\n",mov[i].tipo); 
		fread(&mov[i].valor,sizeof(float),1,p);
		printf("VALOR: %.2f\n",mov[i].valor); 
		printf("\n");
	}
	fclose(p);
}
