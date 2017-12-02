/*
Nome do programa: Supermarket Manager Master 
Autor: Matheus Ariel 
Data de criação: 07/03/2017
Descrição: O programa permite o cadastro de produtos, permite consultar todos os produtos em estoque,
	realizar vendas, além de gerenciar o o saldo em caixa.
*/

//TODAS AS BIBLIOTECAS NECESSÁRIAS PARA O FUNCIONAMENTO DO PROGRAMA.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//DEFINE O TAMANHO MÁXIMO DE PRODUTOS QUE PODEM SER CADASTRADOS.
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

//DECLARAÇÃO DE TODAS AS FUNÇÕES UTILIZADAS PELO PROGRAMA.
int insereProduto(int contadorVetor, PRODUTO *produto, float *saldo);
void venda(int contadorVetor, float *saldo);
int imprimeEstoque(int contadorVetor);
void consultaSaldo(float saldoCaixa);



int main()
{
	setlocale(LC_ALL, "portuguese");

	//VARIÁVEL QUE ARMAZENA O SALDO DO CAIXA, COM VALOR INICIAL DE R$3000,00.
	float saldoCaixa = 3000;

	//VARÍAVEL QUE ARMAZENA A ÚLTIMA POSIÇÃO UTILIZADA NO VETOR DE REGISTROS.
	int contadorVetor = 0;

	//VARÍAVEL UTILIZADA PELO MENU PARA ESCOLHER A OPÇÃO SELECIONADA PELO USUÁRIO.
	int opcao = 0;


	do
	{

		//EXIBE O MENU PARA O USUÁRIO
		printf("\n\n1 - Inserir um produto no estoque.\n");
		printf("2 - Realizar uma venda.\n");
		printf("3 - Consultar o estoque de produtos.\n");
		printf("4 - Consultar o saldo do caixa.\n");

		//ARMAZENA A ESCOLHA.
		printf ("\n\nEscolha uma opção: \n");
		scanf("%d", &opcao);


		switch (opcao)
		{
		case 1:
			/*CHAMA A FUNÇÃO QUE INSERE PRODUTOS, PASSANDO COMO PARÂMETRO O CONTADOR COM A ÚLTIMA POSIÇÃO DO VETOR,
				AS INFORMAÇÕES DO PRODUTO, E O SALDO EM CAIXA (PARA LA NA FUNÇÃO ELE SER ALTERADO).
				POR FIM A FUNÇÃO INCREMENTA E RETORNA , ASSIM ATUALIZANDO O CONTADDOR DE VETOR.*/
			contadorVetor = insereProduto(contadorVetor, &produtos[contadorVetor], &saldoCaixa);
			break;
		case 2:
			/*CHAMA A FUNÇÃO PARA IMPRIMIR ESTOQUES (PARA MOSTRAR AO USUÁRIO TODOS OS PRODUTOS EM ESTOQUE PARA VENDA)
			PASSANDO O CONTADOR DE VETOR, PARA PERCORRER SOMENTE O NECESSÁRIO.
			CASO A FUNÇÃO QUE IMPRIME RETORNAR 1, CHAMA-SE A FUNÇÃO QUE REALIZA A VENDA, PASSANDO NOVAMENTE
			O CONTADOR DE VETOR E O SALDO PARA SER ALTERADO NA FUNÇÃO.*/
			if(imprimeEstoque(contadorVetor) == 1)
			{
				venda(contadorVetor, &saldoCaixa);
			}
			break;
		case 3:
			/*CHAMA A FUNÇÃO PARA IMPRIMIR ESTOQUES PASSANDO O CONTADOR DE VETOR, PARA PERCORRER SOMENTE O NECESSÁRIO.*/
			imprimeEstoque(contadorVetor);
			break;
		case 4:
			/*CHAMA A FUNÇÃO QUE EXIBE O SALDO EM CAIXA ATUAL, PASSANDO COMO PARÂMETRO A VARIÁVEL QUE ARMAZENA O SALDO.*/
			consultaSaldo(saldoCaixa);
			break;

		}
	}
	//ENQUANTO A OPÇÃO ESCOLHIDA PELO USUÁRIO FOR DIFERENTE DE 0, O MENU FICARÁ SENDO EXIBIDO.
	while (opcao != 0);

	return 0;
}







//CRIAÇÃO DAS FUNÇÕES NECESSÁRIAS PARA O PROGRAMA:



//CONSTRUÇÃO DA FUNÇÃO QUE INSERE OS PRODUTOS.
int insereProduto(int contadorVetor, PRODUTO *produto, float *saldo)
{
	//INCREMTENTA O CONTADOOR DE VETOR EM +1.
	contadorVetor++;

	//PEDE E ARMAZENA TODAS AS INFORMAÇÕES DO PRODUTO.
	printf ("\n\nInforme o código do produto: \n");
	scanf("%d", &produto->codigoProduto);

	printf("Informe o nome do produto: \n");
	fflush(stdin);
	gets(&produto->nomeProduto);

	printf("Informe a quantidade de produto(s): \n");
	scanf("%d", &produto->quantidadeProduto);

	printf("Informe o preço unitário do produto: \nR$ ");
	scanf("%f", &produto->precoProduto);

	//O SALDO É ATUALIZADO, TIRANDO DO SALDO A QUANTIDADE INFORMADA * PREÇO UNITÁRIO.
	*saldo = *saldo - (produto->precoProduto * produtos->quantidadeProduto);

	//EXIBE UMA MENSAGEM QUE O PRODUTO X FOI CADASTRADO.
	printf("\n\n\tPRODUTO: %s CADASTRADO COM SUCESSO !", produto->nomeProduto);

	//POR FIM É RETORNADO O CONTADOR DE VETOR, PARA ELE SER ATUALIZADO.
	return contadorVetor;

}



//CONSTRUÇÃO DA FUNÇÃO QUE REALIZA A VENDA DE PRODUTOS.
void venda(int contadorVetor, float *saldo)
{

	//VARIÁVEL QUE ARMAZENA O CÓDIGO DO PRODUTO INFORMADO PELO USUÁRIO.
	int cod = 0;
	
	//VARIÁVEL QUE ARMAZENA A QUANTIDADE DE PRODUTO(S) INFORMADO PELO USUÁRIO.
	int qtd = 0;
	
	//CONTADOR PARA PERCORRER O VETOR.
	int i;
	
	//VARIÁVEL PARA CALCULAR O PREÇO DE VENDA.
	float precoVenda = 0;


	//PRIMEIRO É PERGUNTADO QUAL O CÓDIGO DO PRODUTO PARA VENDA.
	printf("\nInforme o código: ");
	scanf("%d", &cod);

	
	//PERCORRE O VETOR ENQUANTO TIVER PRODUTOS NO VETOR DE REGISTROS.
	for(i = 0; i < contadorVetor; i++)
	{
		//CASSO O CÓDIGO INFORMADO SEJA VÁLIDO.
		if(cod == produtos[i].codigoProduto)
		{
			//É PERGUNTADO QUAL A QUANTIDADE NECESSÁRIA.
			printf("Informe a quantidade: ");
			scanf("%d", &qtd);

			//CASO A QUANTIDADE INFORMADA PELO USUÁRIO SEJA MAIOR DO QUE A QUE TENHA EM ESTOQUE.
			
			if (qtd > produtos[i].quantidadeProduto )
			{
				//É INFORMADO AO USUÁRIO QUE NÃO HÁ QUANTIA SUFICIENTE PARA A REALIZAÇÃO DA VENDA, PORTANTO SAINDO DA FUNÇÃO.
				printf("\nESTOQUE INSULFICIENTE! ");
				printf("\nHá somente %d em estoque do produto %s", produtos[i].quantidadeProduto, produtos[i].nomeProduto);
				break;
			}
			//CASO O CÓDIGO E A QUANTIDADE SEJAM VÁLIDOS.
			else
			{
				//PREÇO PARA VENDA RECEBE O PREÇO UNITÁRIO DE CADA PRODUTO *0.25 + PREÇO DO PRODUTO UNITÁRIO * QUANTIDADE.
				precoVenda = ((produtos[i].precoProduto * 0.25) + (produtos[i].precoProduto * qtd));
				
				//O SALDO TOTAL DO CAIXA É ATUALIZADO COM O VALOR DESSA VENDA.
				*saldo = *saldo + precoVenda;
				
				//É RETIRADO DO ESTOQUE A QUANTIDADE DAQUELE PRODUTO.
				produtos[i].quantidadeProduto  = produtos[i].quantidadeProduto - qtd;

				//EMISSÃO DA NOTA FISCAL, COM CÓDIGO DO PRODUTO, PREÇO UNITÁRIO, PREÇO TOTAL, DATA E HORA DA COMPRA.
				printf("\n\tCOD: %d - NOME: %s - PREçO UNITÁRIO: R$ %1.2f - PREçO TOTAL: R$ %1.2f "
					   , produtos[i].codigoProduto, produtos[i].nomeProduto, produtos[i].precoProduto, precoVenda);
				printf("\nVENDIDO COM SUCESSO  - DATA : %s HORA: %s", __DATE__, __TIME__);
			}
		}
		//CASSO O CÓDIGO INFORMADO SEJA INVÁLIDO.
		else
		{
			//A FUNÇÃO FAZ COM QUE QUANTIDADE SEJA AUTOMATICAMENTE 0.
			qtd = 0;
		}

	}
	//É FEITA UMA VERIFICAÇÃO PARA VER SE QUANTIDADE FOR ZERO PARA DAR UMA MENSAGEM DE CÓDIGO INVÁLIDO.
	if(qtd == 0)
	{
		printf("\n\tCÓDIGO INVÁLIDO");
	}
}


//CONSTRUÇÃO DA FUNÇÃO QUE IMPRIME OS PRODUTOS EM ESTOQUE.
int imprimeEstoque(int contadorVetor)
{
	int i;

	//CASO HAJA AO MENOS UM PRODUTO CADASTRADO EU PERCORRO O VETOR.
	if(contadorVetor > 0)
	{

		//PERCORRE O VETOR DE REGISTROS.
		for(i = 0; i < contadorVetor; i++)
		{
			//SOMENTE É EXIBIDO AS INFORMAÇÕES DO PRODUTO, CASO HAJA AO MENOS UM EM ESTOQUE.
			if((produtos[i].quantidadeProduto) > 0)
			{

				printf("\n############################################");
				printf("\n\n\tCódigo: %d ", produtos[i].codigoProduto);
				printf("\n\tNome: %s", produtos[i].nomeProduto);
				printf("\n\tQuantidade: %d", produtos[i].quantidadeProduto);
				printf("\n\tPreço: R$%1.2f", produtos[i].precoProduto);
				printf("\n############################################\n\n");
			}
		}
		//RETORNA UM PARA CASO TENHA PRODUTOS CADASTRADOS.
		return 1;
	}
	//CASO CONTRÁRIO (CASO NÃO HAJA NENHUM PRODUTO CADASTRADO) .
	else
	{
		//EXIBI-SE UMA MENSAGEM INFORMANDO QUE NÃO HÁ NENHUM PRODUTO CADASTRADO E RETORNA 0.
		printf("\n\n\tNENHUM PRODUTO CADASTRADO !");
		return 0;
	}
}

//CONSTRUÇÃO DA FUNÇÃO QUE IMPRIME O SALDO EM CAIXA ATUALIZADO.
void consultaSaldo(float saldoCaixa)
{
	//EXIBE O VALOR TOTAL DO CAIXA, SALDO ESSE QUE A FUNÇÃO RECEBE COMO PARÂMETRO.
	printf("\n\n############################################\n\n");
	printf("\tSALDO TOTAL DO CAIXA: R$%1.2f ", saldoCaixa);
	printf("\n\n############################################\n\n");
}



