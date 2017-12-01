/*
Nome do programa: Supermarket Manager Master 
Autor: Matheus Ariel de Souza
Data de cria��o: 07/03/2017
Descri��o: O programa permite o cadastro de produtos, permite consultar todos os produtos em estoque,
	realizar vendas, al�m de gerenciar o o saldo em caixa.
*/

//TODAS AS BIBLIOTECAS NECESS�RIAS PARA O FUNCIONAMENTO DO PROGRAMA.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//DEFINE O TAMANHO M�XIMO DE PRODUTOS QUE PODEM SER CADASTRADOS.
#define MAX 50


//ESTRUTURA UTILIZADA PELOS PRODUTOS.
typedef struct
{
	int codigoProduto;
	char nomeProduto[30];
	int quantidadeProduto;
	float precoProduto;
} PRODUTO;


//CRIA O VETOR DE REGISTROS DO TIPO PRODUTO.
PRODUTO produtos[MAX];

//DECLARA��O DE TODAS AS FUN��ES UTILIZADAS PELO PROGRAMA.
int insereProduto(int contadorVetor, PRODUTO *produto, float *saldo);
void venda(int contadorVetor, float *saldo);
int imprimeEstoque(int contadorVetor);
void consultaSaldo(float saldoCaixa);



int main()
{
	setlocale(LC_ALL, "portuguese");

	//VARI�VEL QUE ARMAZENA O SALDO DO CAIXA, COM VALOR INICIAL DE R$3000,00.
	float saldoCaixa = 3000;

	//VAR�AVEL QUE ARMAZENA A �LTIMA POSI��O UTILIZADA NO VETOR DE REGISTROS.
	int contadorVetor = 0;

	//VAR�AVEL UTILIZADA PELO MENU PARA ESCOLHER A OP��O SELECIONADA PELO USU�RIO.
	int opcao = 0;


	do
	{

		//EXIBE O MENU PARA O USU�RIO
		printf("\n\n1 - Inserir um produto no estoque.\n");
		printf("2 - Realizar uma venda.\n");
		printf("3 - Consultar o estoque de produtos.\n");
		printf("4 - Consultar o saldo do caixa.\n");

		//ARMAZENA A ESCOLHA.
		printf ("\n\nEscolha uma op��o: \n");
		scanf("%d", &opcao);


		switch (opcao)
		{
		case 1:
			/*CHAMA A FUN��O QUE INSERE PRODUTOS, PASSANDO COMO PAR�METRO O CONTADOR COM A �LTIMA POSI��O DO VETOR,
				AS INFORMA��ES DO PRODUTO, E O SALDO EM CAIXA (PARA LA NA FUN��O ELE SER ALTERADO).
				POR FIM A FUN��O INCREMENTA E RETORNA , ASSIM ATUALIZANDO O CONTADDOR DE VETOR.*/
			contadorVetor = insereProduto(contadorVetor, &produtos[contadorVetor], &saldoCaixa);
			break;
		case 2:
			/*CHAMA A FUN��O PARA IMPRIMIR ESTOQUES (PARA MOSTRAR AO USU�RIO TODOS OS PRODUTOS EM ESTOQUE PARA VENDA)
			PASSANDO O CONTADOR DE VETOR, PARA PERCORRER SOMENTE O NECESS�RIO.
			CASO A FUN��O QUE IMPRIME RETORNAR 1, CHAMA-SE A FUN��O QUE REALIZA A VENDA, PASSANDO NOVAMENTE
			O CONTADOR DE VETOR E O SALDO PARA SER ALTERADO NA FUN��O.*/
			if(imprimeEstoque(contadorVetor) == 1)
			{
				venda(contadorVetor, &saldoCaixa);
			}
			break;
		case 3:
			/*CHAMA A FUN��O PARA IMPRIMIR ESTOQUES PASSANDO O CONTADOR DE VETOR, PARA PERCORRER SOMENTE O NECESS�RIO.*/
			imprimeEstoque(contadorVetor);
			break;
		case 4:
			/*CHAMA A FUN��O QUE EXIBE O SALDO EM CAIXA ATUAL, PASSANDO COMO PAR�METRO A VARI�VEL QUE ARMAZENA O SALDO.*/
			consultaSaldo(saldoCaixa);
			break;

		}
	}
	//ENQUANTO A OP��O ESCOLHIDA PELO USU�RIO FOR DIFERENTE DE 0, O MENU FICAR� SENDO EXIBIDO.
	while (opcao != 0);

	return 0;
}







//CRIA��O DAS FUN��ES NECESS�RIAS PARA O PROGRAMA:



//CONSTRU��O DA FUN��O QUE INSERE OS PRODUTOS.
int insereProduto(int contadorVetor, PRODUTO *produto, float *saldo)
{
	//INCREMTENTA O CONTADOOR DE VETOR EM +1.
	contadorVetor++;

	//PEDE E ARMAZENA TODAS AS INFORMA��ES DO PRODUTO.
	printf ("\n\nInforme o c�digo do produto: \n");
	scanf("%d", &produto->codigoProduto);

	printf("Informe o nome do produto: \n");
	fflush(stdin);
	gets(&produto->nomeProduto);

	printf("Informe a quantidade de produto(s): \n");
	scanf("%d", &produto->quantidadeProduto);

	printf("Informe o pre�o unit�rio do produto: \nR$ ");
	scanf("%f", &produto->precoProduto);

	//O SALDO � ATUALIZADO, TIRANDO DO SALDO A QUANTIDADE INFORMADA * PRE�O UNIT�RIO.
	*saldo = *saldo - (produto->precoProduto * produtos->quantidadeProduto);

	//EXIBE UMA MENSAGEM QUE O PRODUTO X FOI CADASTRADO.
	printf("\n\n\tPRODUTO: %s CADASTRADO COM SUCESSO !", produto->nomeProduto);

	//POR FIM � RETORNADO O CONTADOR DE VETOR, PARA ELE SER ATUALIZADO.
	return contadorVetor;

}



//CONSTRU��O DA FUN��O QUE REALIZA A VENDA DE PRODUTOS.
void venda(int contadorVetor, float *saldo)
{

	//VARI�VEL QUE ARMAZENA O C�DIGO DO PRODUTO INFORMADO PELO USU�RIO.
	int cod = 0;
	
	//VARI�VEL QUE ARMAZENA A QUANTIDADE DE PRODUTO(S) INFORMADO PELO USU�RIO.
	int qtd = 0;
	
	//CONTADOR PARA PERCORRER O VETOR.
	int i;
	
	//VARI�VEL PARA CALCULAR O PRE�O DE VENDA.
	float precoVenda = 0;


	//PRIMEIRO � PERGUNTADO QUAL O C�DIGO DO PRODUTO PARA VENDA.
	printf("\nInforme o c�digo: ");
	scanf("%d", &cod);

	
	//PERCORRE O VETOR ENQUANTO TIVER PRODUTOS NO VETOR DE REGISTROS.
	for(i = 0; i < contadorVetor; i++)
	{
		//CASSO O C�DIGO INFORMADO SEJA V�LIDO.
		if(cod == produtos[i].codigoProduto)
		{
			//� PERGUNTADO QUAL A QUANTIDADE NECESS�RIA.
			printf("Informe a quantidade: ");
			scanf("%d", &qtd);

			//CASO A QUANTIDADE INFORMADA PELO USU�RIO SEJA MAIOR DO QUE A QUE TENHA EM ESTOQUE.
			
			if (qtd > produtos[i].quantidadeProduto )
			{
				//� INFORMADO AO USU�RIO QUE N�O H� QUANTIA SUFICIENTE PARA A REALIZA��O DA VENDA, PORTANTO SAINDO DA FUN��O.
				printf("\nESTOQUE INSULFICIENTE! ");
				printf("\nH� somente %d em estoque do produto %s", produtos[i].quantidadeProduto, produtos[i].nomeProduto);
				break;
			}
			//CASO O C�DIGO E A QUANTIDADE SEJAM V�LIDOS.
			else
			{
				//PRE�O PARA VENDA RECEBE O PRE�O UNIT�RIO DE CADA PRODUTO *0.25 + PRE�O DO PRODUTO UNIT�RIO * QUANTIDADE.
				precoVenda = ((produtos[i].precoProduto * 0.25) + (produtos[i].precoProduto * qtd));
				
				//O SALDO TOTAL DO CAIXA � ATUALIZADO COM O VALOR DESSA VENDA.
				*saldo = *saldo + precoVenda;
				
				//� RETIRADO DO ESTOQUE A QUANTIDADE DAQUELE PRODUTO.
				produtos[i].quantidadeProduto  = produtos[i].quantidadeProduto - qtd;

				//EMISS�O DA NOTA FISCAL, COM C�DIGO DO PRODUTO, PRE�O UNIT�RIO, PRE�O TOTAL, DATA E HORA DA COMPRA.
				printf("\n\tCOD: %d - NOME: %s - PRE�O UNIT�RIO: R$ %1.2f - PRE�O TOTAL: R$ %1.2f "
					   , produtos[i].codigoProduto, produtos[i].nomeProduto, produtos[i].precoProduto, precoVenda);
				printf("\nVENDIDO COM SUCESSO  - DATA : %s HORA: %s", __DATE__, __TIME__);
			}
		}
		//CASSO O C�DIGO INFORMADO SEJA INV�LIDO.
		else
		{
			//A FUN��O FAZ COM QUE QUANTIDADE SEJA AUTOMATICAMENTE 0.
			qtd = 0;
		}

	}
	//� FEITA UMA VERIFICA��O PARA VER SE QUANTIDADE FOR ZERO PARA DAR UMA MENSAGEM DE C�DIGO INV�LIDO.
	if(qtd == 0)
	{
		printf("\n\tC�DIGO INV�LIDO");
	}
}


//CONSTRU��O DA FUN��O QUE IMPRIME OS PRODUTOS EM ESTOQUE.
int imprimeEstoque(int contadorVetor)
{
	int i;

	//CASO HAJA AO MENOS UM PRODUTO CADASTRADO EU PERCORRO O VETOR.
	if(contadorVetor > 0)
	{

		//PERCORRE O VETOR DE REGISTROS.
		for(i = 0; i < contadorVetor; i++)
		{
			//SOMENTE � EXIBIDO AS INFORMA��ES DO PRODUTO, CASO HAJA AO MENOS UM EM ESTOQUE.
			if((produtos[i].quantidadeProduto) > 0)
			{

				printf("\n############################################");
				printf("\n\n\tC�digo: %d ", produtos[i].codigoProduto);
				printf("\n\tNome: %s", produtos[i].nomeProduto);
				printf("\n\tQuantidade: %d", produtos[i].quantidadeProduto);
				printf("\n\tPre�o: R$%1.2f", produtos[i].precoProduto);
				printf("\n############################################\n\n");
			}
		}
		//RETORNA UM PARA CASO TENHA PRODUTOS CADASTRADOS.
		return 1;
	}
	//CASO CONTR�RIO (CASO N�O HAJA NENHUM PRODUTO CADASTRADO) .
	else
	{
		//EXIBI-SE UMA MENSAGEM INFORMANDO QUE N�O H� NENHUM PRODUTO CADASTRADO E RETORNA 0.
		printf("\n\n\tNENHUM PRODUTO CADASTRADO !");
		return 0;
	}
}

//CONSTRU��O DA FUN��O QUE IMPRIME O SALDO EM CAIXA ATUALIZADO.
void consultaSaldo(float saldoCaixa)
{
	//EXIBE O VALOR TOTAL DO CAIXA, SALDO ESSE QUE A FUN��O RECEBE COMO PAR�METRO.
	printf("\n\n############################################\n\n");
	printf("\tSALDO TOTAL DO CAIXA: R$%1.2f ", saldoCaixa);
	printf("\n\n############################################\n\n");
}



