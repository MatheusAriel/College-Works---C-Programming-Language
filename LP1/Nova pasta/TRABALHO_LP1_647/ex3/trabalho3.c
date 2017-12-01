#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void ler_movimentacoes(MOVIMENTO mov[])				//funcao para ler movimentacoes feitas no arquivo
{	FILE *p;										//cria ponteiro para o arquivo
	int i;
	p=fopen("moviment.bin","rb");					//abre o arquivo em modo de leitura
	if(p==NULL)
	{
		printf("problema ao abrir arquivo binario");
		system("pause");
		exit(0);
	}
	
	printf("\t====================MOVIMENTOS====================\n");
	for(i=0;i<max;i++)								//ciclo para armazenar dados do arquivo na struct
	{	
		fread(&mov[i].numero_mov,sizeof(char),6,p);			//leitura e armazenamento dos dados
		printf("NUMERO: %s\n",mov[i].numero_mov); 
		fread(&mov[i].tipo,sizeof(char),1,p);
		printf("TIPO: %c\n",mov[i].tipo); 
		fread(&mov[i].valor,sizeof(float),1,p);
		printf("VALOR: R$%.2f\n",mov[i].valor); 
		printf("\n");
	}
	printf("\nMovimentos computados!\n\n");
	fclose(p);
	system("pause");
}

void ler_contas(CONTA c[])				//funcao para ler do arquivo contas e armazenar no programa
{	FILE *arq;							//cria ponteiro para arquivo
	int i=0;
	arq=fopen("contas.bin","rb");		//abre o arquivo em modo leitura
	if(arq==NULL)						//procedimento para verificaçao de erro de leitura
	{
		printf("problema ao abrir arquivo binario");
		system("pause");
		exit(0);
	}
		printf("\t====================CONTAS====================\n");
	for(i=0;i<max;i++)					//ciclo para armazenar dados no struct
	{	
		fread(&c[i].numero_conta,sizeof(char),6,arq);			//leitura e armazenamento dos dados
		printf("NUMERO: %s\n",c[i].numero_conta); 
		fread(&c[i].nome_client,sizeof(char),40,arq);
		printf("NOME: %s\n",c[i].nome_client);
		fread(&c[i].saldo,sizeof(float),1,arq);
		printf("SALDO: R$%.2f\n",c[i].saldo); 
		printf("\n");
	}
	printf("\nContas computadas!\n\n");
	fclose(arq);
	system("pause");
}

void alterar_contas(CONTA c[],MOVIMENTO mov[])			//funçao de realizaçao de operações e alteraçoes das contas
{	FILE *fp;
	int i,j;
	fp=fopen("contas_update.bin","wb");//CRIA UM NOVO ARQUIVO PARA NÃO MODIFICAR O EXISTENTE(PARA TESTE)
	//OBS: PARA SOBRESCREVER CONTA, BASTA MUDAR O NOME DO ARQUIVO PARA CONTAS.BIN 
		printf("\t====================SALDOS ATUALIZADOS====================\n");
	for(i=0;i<max;i++)									//contador duplo para manipulação das structs
		for(j=0;j<max;j++)
 	  	  if((strcmp(mov[i].numero_mov,c[j].numero_conta))==0)		//se comparação dos numeros de conta for verdadeira
			 {														//realiza alteração dos dados da struct
			 printf("Altera conta %s\n",c[j].numero_conta);
			 if(mov[i].tipo=='s' || mov[i].tipo=='S') 				//verifica o tipo da movimentação
				 {c[j].saldo -= mov[i].valor;						//realiza a operação
				  printf("%.2f\n",c[j].saldo);}
			 if(mov[i].tipo=='d'||mov[i].tipo=='D')					//verifica o tipo da movimentação
				 {c[j].saldo += mov[i].valor;						//realiza a operação
				 	 printf("R$%.2f\n",c[j].saldo);}
			 }
	for(i=0;i<max;i++)												//envia os dados atualizados para o arquivo
	{	
		fwrite(&c[i].numero_conta,sizeof(char),6,fp);
		fwrite(&c[i].nome_client,sizeof(char),40,fp);
		fwrite(&c[i].saldo,sizeof(float),1,fp);
	}		 
	printf("\n Alteracoe finalizadas!\n");
	fclose(fp);		 											//fecha o arquivo ao terminar
}

int main()
{	CONTA c[max];					//criação de um vetor de registros de conta
	MOVIMENTO mov[max];				//criação de um vetor de registros de movimentações
	ler_contas(c);					//chama função de leitura de arquivo
	ler_movimentacoes(mov);			//chama função de leitura de arquivo
	alterar_contas(c,mov);			//modifica contas
	return 0;
}