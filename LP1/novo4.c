 #include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max 3


typedef struct
{
	char num_conta[6];
	char nome_cliente[40];
	float saldo_conta;
} CONTA;

typedef struct
{
	char num_conta_mov[5];
	char tipo_mov;
	float valor_mov;
} MOVIMENTO;

void ler_contas(CONTA cliente[])
{
	int i;
	FILE *arq;

	arq = fopen("contas.bin", "rb");
	if(arq == NULL)
	{
		printf("Erro na leitura do arquivo");
		system("pause");
		exit(0);
	}

	printf("\t\n\n=======================CONTAS=======================");

	for(i=0;i<max;i++)
	
	{
		fread(&cliente[i].num_conta, sizeof(char), 6, arq);
		printf("\n\nNumero da conta: %s", cliente[i].num_conta );

		fread(&cliente[i].nome_cliente, sizeof(char), 40, arq);
		printf("\nNome: %s", cliente[i].nome_cliente);

		fread(&cliente[i].saldo_conta, sizeof(float), 1, arq);
		printf("\nSaldo: %.2f", cliente[i].saldo_conta);
	}
	fclose(arq);
	printf("\n\nLeitura efetuadda com sucesso");
}


void ler_movimentacoes(MOVIMENTO mov[])
{
	int i;
	FILE *arq;

	arq = fopen("movimentos.bin", "rb");
	if(arq == NULL)
	{
		printf("Erro na leitura do arquivo");
		system("pause");
		exit(0);
	}

	printf("\n\n\n\t=======================MOVIMENTACOES=======================");
	for(i = 0; i < max; i++)
	{
		fread(&mov[i].num_conta_mov, sizeof(char), 6, arq);
		printf("\n\nNumero da conta: %s", mov[i].num_conta_mov);


		fread(&mov[i].tipo_mov, sizeof(char), 1, arq);
		printf("\nTipo de movimentacao: %c", mov[i].tipo_mov);

		fread(&mov[i].valor_mov, sizeof(float), 1, arq);
		printf("\nValor da movimentacao: R$%.2f \n", mov[i].valor_mov);

	}
	fclose(arq);
	printf("\nLeitura efetuadda com sucesso");

}

void atualizacao_saldo(CONTA cliente[], MOVIMENTO mov[])
{
	int i, j;
	
	FILE *arq;

	arq = fopen("contas_update.bin","wb");
	if(arq == NULL)
	{
		printf("Erro na edicao do arquivo");
		system("pause");
		exit(0);
	}
	printf("\n\n\t================ALTERACOES================");
	for(i = 0; i < max; i++)
		for(j = 0; j < max; j++)
			if((strcmp(mov[i].num_conta_mov, cliente[j].num_conta)) == 0)
			{
				printf("\n\nALTERACAO CONTA %s\n", cliente[j].num_conta);


				if(mov[i].tipo_mov == 's')
				{
					cliente[j].saldo_conta = cliente[j].saldo_conta - mov[i].valor_mov;
					
				}

				if(mov[i].tipo_mov = 'd')
				{
					cliente[j].saldo_conta = cliente[j].saldo_conta + mov[i].valor_mov;
			
				}
				
						printf("Saldo Atualizado: %.2f", cliente[j].saldo_conta);
			}
			
	for(i = 0; i < max; i++)												
	{
		fwrite(&cliente[i].num_conta, sizeof(char), 6, arq);
		fwrite(&cliente[i].nome_cliente, sizeof(char), 40, arq);
		fwrite(&cliente[i].saldo_conta, sizeof(float), 1, arq);
	}
	printf("\nALTERACOES EFETUADAS COM SUCESSO\n");
	fclose(arq);
}



/*void ler_update(CONTA cliente[])
{
	int i;
	FILE *arq;
	arq = fopen("contas_update.bin","wb");
	
	for(i=0;i<max;i++)
	{
		fread(&cliente[i].num_conta, sizeof(char), 6, arq);
		printf("\nNum conta: %s",cliente[i].num_conta);
		fread(&cliente[i].nome_cliente, sizeof(char), 40, arq);
		printf("\nNome cliente: %s",cliente[i].nome_cliente);
		fread(&cliente[i].saldo_conta, sizeof(float), 1, arq);
		printf("\nSaldo conta Atualizada: %.2f",cliente[i].saldo_conta);
	}
	
	
	
}
*/
int main(void)
{
	CONTA cliente[max];
	MOVIMENTO mov[max];

	

	//ler_update(cliente);
	ler_contas(cliente);
	
	ler_movimentacoes(mov);

	atualizacao_saldo(cliente, mov);
	

	return 0;
}
