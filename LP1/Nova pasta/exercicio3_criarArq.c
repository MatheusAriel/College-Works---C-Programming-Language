#include <stdlib.h>
#include <stdio.h>
#define max 3


typedef struct
{
	char num_conta[6];
	char nome_cliente[40];
	float saldo_conta;
} CONTA;

typedef struct
{
	char num_conta_mov[6];
	char tipo_mov;
	float valor_mov;
} MOVIMENTO;


void criar_conta(CONTA cliente[])
{
	int i;
	FILE *arq;

	arq = fopen("contas.bin", "wb");
	if(arq == NULL)
	{
		printf("Erro na criacao do arquivo");
		system("pause");
		return(0);
	}

	for(i = 0; i < max; i++)
	{
		printf("\nCONTA %d", i + 1);
		
		fflush(stdin);
		printf("\nInforme o numero da conta: ");
		gets(cliente[i].num_conta);
		fwrite(&cliente[i].num_conta, sizeof(char), 6, arq);

		fflush(stdin);

		printf("Informe o nome do cliente: ");
		gets(cliente[i].nome_cliente);
		fwrite(&cliente[i].nome_cliente, sizeof(char), 40, arq);

		fflush(stdin);

		printf("Informe o saldo da conta: R$");
		scanf("%f", &cliente[i].saldo_conta);
		fwrite(&cliente[i].saldo_conta, sizeof(float), 1, arq);
		
		//fwrite(&cliente, sizeof(CONTA), 1, arq;

		fflush(stdin);
	}
	fclose(arq);
	printf("\nContas cadastradas com sucesso");
}

void movimentacao(MOVIMENTO mov[])
{
	int i;
	FILE *arq;

	arq = fopen("movimentos.bin", "wb");
	if(arq == NULL)
	{
		printf("Erro na criacao do arquivo");
		system("pause");
		exit(0);
	}

	for(i = 0; i < max; i++)
	{
		fflush(stdin);
		printf("\nInforme o numero da conta que deseja movimentar: ");
		gets(mov[i].num_conta_mov);
		fwrite(&mov[i].num_conta_mov, sizeof(char), 6, arq);

		printf("Informe o tipo de movimentacao s para saque ou d para deposito: ");
		scanf("%c", &mov[i].tipo_mov);
		fwrite(&mov[i].tipo_mov, sizeof(char), 1, arq);

		fflush(stdin);

		while(mov[i].tipo_mov != 'd' && mov[i].tipo_mov != 's')
		{
			printf("\nDigite s para saque ou d para deposito");
			printf("\nInforme o tipo de movimentacao s para saque e d para deposito: ");
			scanf("%c", &mov[i].tipo_mov);
			fwrite(&mov[i].tipo_mov, sizeof(char), 1, arq);
			fflush(stdin);
		}

		printf("Informe a quantia da movimentacao: R$ ");
		scanf("%f", &mov[i].valor_mov);
		fwrite(&mov[i].valor_mov, sizeof(float), 1, arq);

	}
	fclose(arq);
	printf("\nMovimentacoes efetuadas com sucesso");
}

int main(void)
{
	CONTA cliente[max];
	MOVIMENTO mov[max];
	int opcao;

	do
	{
		printf("====================================================\n");
		printf("DIGITE 1 PARA CRIAR CONTAS");
		printf("\nDIGITE 2 PARA CRIAR MOVIMENTACOES");
		printf("\n====================================================\n\n");
		scanf("%d", &opcao);
	}
	while(opcao !=1 && opcao!=2);


	switch(opcao)
		{
		case 1:
			criar_conta(cliente);
			break;

		case 2:
			movimentacao(mov);
			break;
		}


	return 0;
}
