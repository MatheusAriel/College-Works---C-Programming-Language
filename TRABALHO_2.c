/*
Nome do programa: Agende-c.
Autor: Matheus Ariel de Souza
Data de criação: 7/05/2017
Descrição: O programa permite o cadastro e a gravação de contatos,
permite consultar todos contatos na agenda,
consulta de contatos por nome, por letra inicial do nome, e por mês do aniverário
*/

//TODAS AS BIBLIOTECAS NECESSÁRIAS PARA O FUNCIONAMENTO DO PROGRAMA.
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


//ESTRUTURA UTILIZADA PELOS CONTATOS.
typedef struct
{
	char nome[50];
	char telefone[25];
	int diaNasc;
	int mesNasc;
} CONTATO;


//DECLARAÇÃO DE TODAS AS FUNÇÕES UTILIZADAS PELO PROGRAMA.
CONTATO *alocaMemoria(CONTATO *contatos, int tamanhoVetor);
CONTATO *realocaMemoria(CONTATO *contatos, int tamanhoVetor);
void liberaMemoria(CONTATO *contatos);
void insereContato(CONTATO *contatos);
void imprimeAgenda(CONTATO *contatos, int tamanhoVetor);
void consultaLetra(CONTATO *contatos, char letra, int tamanhoVetor);
void consultaNome(CONTATO *contatos, char nome[], int tamanhoVetor);
void consultaAniversario(CONTATO *contatos, int mesAniversario, int tamanhoVetor);


int main()
{
	setlocale(LC_ALL, "portuguese");

	//CRIA UM PONTEIRO DO TIPO CONTATO(STRUCT).
	CONTATO *contatos;

	//CRIA UM PONTEIRO DO TIPO FILE, PARA FUTURAS MANIPULAÇÕES COM O ARQUIVO.
	FILE *arq;

	//VARÍAVEL UTILIZADA PELO MENU PARA ESCOLHER A OPÇÃO SELECIONADA PELO USUÁRIO.
	int opcao = -1;


	int n = 0, i;

	//DEFINE INICIALMENTE O TAMANHO DO VETOR COMO SENDO 0.
	int tamanhoVetor = 0;

	//VARIÁVEIS PARA GUARDAR OS DADOS UTILIZADOS PELAS PESQUISAS DO USUÁRIO.
	char letra;
	char nomePesquisa[50];
	int mesAniversario = 0;

	//CASO HAJA UM ARQUIVO BINÁRIO CHAMADO contatos.bat TENTA ABRI-LO.
	if((arq = fopen("contatos.dat", "rb")) == NULL)
	{
		//CASO NÃO CONSIGA ABRIR, IMPRIME UMA MENSAGEM DE ERRO.
		printf( "\n\tERRO NA ABERTURA DO ARQUIVO");
	}
	//CASO CONSIGA.
	else
	{
		//TENTA LER O PRIMEIRO CAMPO DO ARQUIVO BINÁRIO, QUE É O
		//TAMANHO DE CONTATOS INSERIDOS NO ARQUIVO.
		if(fread(&tamanhoVetor, sizeof(int), 1, arq) != 1)
		{
			//CASO NÃO CONSIGA LER, IMPRIME UMA MENSAGEM DE ERRO.
			printf("\n\tERRO");
		}
		//CASO CONSIGA
		else
		{
			//ALOCA MEMÓRIA PARA RECEBER O VALOR DO TOTAL DE CONTATOS NO ARQUIVO.
			contatos = alocaMemoria(contatos , tamanhoVetor);

			//TENTA LER TODOS OS CONTATOS DO ARQUIVO BINÁRIO.
			if(fread(&contatos[0], sizeof(CONTATO), tamanhoVetor, arq) != tamanhoVetor)
			{
				//CASO NÃO CONSIGA LER, IMPRIME UMA MENSAGEM DE ERRO.
				printf("Erro na leitura do arquivo CONTATOS");
			}
		}
		//APÓS FEITAS TODAS AS TENTATIVAS DE LEITURAS DO ARQUIVO, DANDO
		//CERTO OU NÃO, É FECHADO O ARQUIVO.
		fclose(arq);
	}

	do
	{
		//EXIBE O MENU PARA O USUÁRIO.
		printf("\n\n**************************************************************\n");
		printf("1 - Inserir contato(s).\n");
		printf("\n**************************************************************\n");
		printf("2 - Pesquisar contato por nome.\n");
		printf("\n**************************************************************\n");
		printf("3 - Listar todos os contatos.\n");
		printf("\n**************************************************************\n");
		printf("4 - Listar todos os contatos começando por determianda letra.\n");
		printf("\n**************************************************************\n");
		printf("5 - Mostrar aniversariante(s) de um determinado mês.\n");
		printf("\n**************************************************************\n");
		printf("6 - Sair.\n");
		printf("\n**************************************************************\n");

		//ARMAZENA A ESCOLHA.
		printf ("\n\nEscolha uma opção: ");
		scanf("%d", &opcao);
		printf("\n\n");

		switch(opcao)
		{
		case 1:
			//VERIFICA SE O TOTAL DE CONTATOS É 0
			if(tamanhoVetor == 0)
			{
				//ARMAZENA O TOTAL DE CONTATOS QUE O USUÁRIO DESEJA CADASTRAR.
				printf("Informe quantos contatos deseja adicionar na agenda: ");
				scanf("%d", &n);
				/*CASO FOR, PEDE O TOTAL DE CADASTROS QUE DESEJA INSERIR NA
				AGENDA, E UTILIZA INICIALMENTE O MALLOC PARA ALOCAR MEMÓRIA
				ATRAVÉS DA FUNÇÃO alocaMemoria, QUE RETORNA UM PONTEIRO DO TIPO
				CONTATO, QUE É RECEBIDO PELO PONTEIRO TAMBÉM DO TIPO CONTATO CHAMADO
				contatos.
				*/
				contatos = alocaMemoria(contatos , n);

				//PERCORRE O NÚMERO INFORMADO PELO USUÁRIO.
				for(i = 0; i < n; i++)
				{
					//CHAMA A FUNÇÃO QUE INSERE CONTATOS, PASSANDO COMO PARÂMETRO
					//A ÚLTIMA POSIÇÃO DO VETOR DE CONTATOS.
					insereContato(&contatos[i]);
				}
				//ATUALIZA O TAMANHO DO VETOR.
				tamanhoVetor = n;
			}
			//CASO O TAMANHO DO VETOR NÃO SEJA MAIS 0, OU SEJA,
			//CASO JÁ TENHA CONTATOS CADASTRADOS NA AGENDA.
			else if(tamanhoVetor > 0)
			{
				//ARMAZENA O TOTAL DE CONTATOS QUE O USUÁRIO DESEJA ACRESCENTAR.
				printf("\n\nQuantos contatos deseja acrescentar na agenda: ");
				scanf("%d", &n);

				//VERIFICA SE O NÚMERO INFORMADO É UM NÚMERO VÁLIDO (MAIOR QUE 0).
				if(n > 0)
				{
					//j RECEBE O TAMANHO ANTIGO DO VETOR.
					int j = tamanhoVetor;
					//ATUALIZA O TAMANHO DO VETOR, SOMANDO COM O
					//VALOR DE NOVOS CONTATOS.
					tamanhoVetor = tamanhoVetor + n;

					//ALOCA MEMÓRIA PARA OS NOVOS CONTATOS, UTILIZANDO REALLOC,
					//ATRAVES DA FUNÇÃO realocaMemoria.
					contatos = realocaMemoria(contatos, tamanhoVetor);

					//PERCORRE O NÚMERO INFORMADO PELO USUÁRIO.
					for(i = j; i < tamanhoVetor; i++)
					{
						//CHAMA A FUNÇÃO QUE INSERE CONTATOS, PASSANDO COMO PARÂMETRO
						//A ÚLTIMA POSIÇÃO DO VETOR DE CONTATOS.
						insereContato(&contatos[i]);
					}
				}
			}
			break;

		case 2:
			//PEGA UM NOME PARA PESQUISAR NA AGENDA.
			printf("\n\n Informe um nome para pesquisa: ");
			fflush(stdin);
			gets(nomePesquisa);

			//PASSA TODAS AS LETRAS DO NOME PARA MAIÚSCULA
			for(i = 0; nomePesquisa[i] != '\0'; i++)
			{
				nomePesquisa[i] = toupper(nomePesquisa[i]);
			}

			//CHAMA A FUNÇÃO APRA PESQUISAR, PASSANDO O VETOR DE CONTATOS,
			//O NOME INFORMADO PARA PESQUISA, E A QUANTIDADE TODAL DE CONTATOS.
			consultaNome(contatos, nomePesquisa, tamanhoVetor);
			break;

		case 3:
			//CHAMA A FUNÇÃO QUE IMPRIME TODOS OS CONTATOS, PASSANDO O VETOR
			//DE CONTATOS, E O TAMANHO TOTAL DE CONTATOS NA AGENDA.
			imprimeAgenda(contatos, tamanhoVetor);
			break;

		case 4:
			//PEGA A LETRA PARA PESQUISAR OS NOMES COMEÇADOS POR ELA.
			fflush(stdin);
			printf("\n\n Informe uma letra: ");
			scanf("%c", &letra);
			fflush(stdin);
			//TRANSFORMA ESSA LETRA INFORMADA PELO USUÁRIO EM MAIPUSCULA
			letra = toupper(letra);
			//CHAMA A FUNÇÃO QUE PESQUISA OS NOMES COMEÇADOS PELA DETERMINADA
			//LETRA, PASSANDO O VETOR DE CONTATOS, A LETRA E O TOTAL DE CONTATOS.
			consultaLetra(contatos, letra, tamanhoVetor);
			break;

		case 5:
			//PEGA O MÊS PARA PESQUISAR OS ANIVERSARIANTES DESSE MÊS.
			printf("Informe um mês: ");
			scanf("%d", &mesAniversario);
			//CHAMA A FUNÇÃO QUE PESQUISA POR MÊS, E PASSA POR PARÂMETRO O VETOR
			//DE CONTATOS, O MÊS DESEJADO, E O TOTAL DE CONTATOS NA AGENDA.
			consultaAniversario(contatos, mesAniversario, tamanhoVetor);
			break;

		case 6:
			//TENTA ABRIR CASO EXISTA O ARQUIVO contatos.dat,CASO NÃO EXISTA ELE
			//CRIA.
			if((arq = fopen("contatos.dat", "wb+")) == NULL)
			{
				//EXIBE MENSAGEM DE ERRO CASO DÊ ALGUM ERRO NA CRIAÇÃO/ABERTURA
				//DO ARQUIVO.
				printf( "\nErro na CRIACAO  do arquivo");
				exit(0);
			}
			// PRIMEIRAMENTE ESCREVE NO ARQUIVO O TOTAL DE CONTATOS NA AGENDA.
			if(fwrite(&tamanhoVetor, sizeof(int), 1, arq) == 1)
			{
				//DEPOIS ESCREVE TODOS OS NOVOS CONTATOS NA AGENDA.
				if (fwrite(&contatos[0], sizeof (CONTATO), tamanhoVetor, arq) == tamanhoVetor)
				{
					puts("\n\tSAINDO");
				}
				else
				{
					//EXIBE MENSAGEM DE ERRO CASO NÃO CONSIGA ESCREVER OS CONTATOS.
					printf("\n\tERRO AO GRAVAR CONTATOS");
				}
			}
			else
			{
				//EXIBE MENSAGEM DE ERRO CASO NÃO CONSIGA SALVAR O TAMANHO VETOR.
				printf("\n\tERRO");
			}
			//FECHA O ARQUIVO.
			fclose(arq);
			//CHAMA A FUNÇÃO QUE LIBERA MEMÓRIA ALOCADA ANTERIORMENTE.
			liberaMemoria(contatos);
			exit(0);
			break;
		}
	}
	//ENQUANTO A OPÇÃO ESCOLHIDA PELO USUÁRIO FOR DIFERENTE DE -1, O MENU FICARÁ SENDO EXIBIDO.
	while(opcao != -1);
	return 0;
}

//CRIAÇÃO DAS FUNÇÕES NECESSÁRIAS PARA O PROGRAMA:

//CONSTRUÇÃO DA FUNÇÃO QUE ALOCA MEMÓRIA.
CONTATO *alocaMemoria(CONTATO *contatos, int tamanhoVetor)
{
	//FAZ A ALOCAÇÃO PARA O TOTAL DE CONTATOS NECESSÁRIOS.
	contatos = (CONTATO *) malloc(tamanhoVetor * sizeof(CONTATO));

	//CASO NÃO CONSIGA
	if (!contatos)
	{
		//EXIBE MENSAGEM DE ERRO.
		printf ("\nErro: Memoria Insuficiente");
		exit(0);
	}
	//RETORNA O PONTEIRO DO TIPO CONTATO PARA A INSERÇÃO DE NOVOS CONTATOS
	//NA MEMÓRIA ALOCADA.
	return contatos;
}

//CONSTRUÇÃO DA FUNÇÃO QUE REALOCA MEMÓRIA.
CONTATO *realocaMemoria(CONTATO *contatos, int tamanhoVetor)
{
	//FAZ A REALOCAÇÃO PARA O TOTAL DE CONTATOS NECESSÁRIOS.
	//FAZ A CONVERSÃO DO PONTEIRO PARA O TIPO CONTATO.
	contatos = (CONTATO *) realloc(contatos, tamanhoVetor * sizeof(CONTATO));

	//CASO NÃO CONSIGA
	if (!contatos)
	{
		//EXIBE MENSAGEM DE ERRO.
		printf ("\nErro: Memoria Insuficiente");
		exit(0);
	}
	//RETORNA O PONTEIRO DO TIPO CONTATO PARA A INSERÇÃO DE NOVOS CONTATOS
	//NA MEMÓRIA ALOCADA.
	return contatos;
}

//CONSTRUÇÃO DA FUNÇÃO QUE LIBERA A MEMÓRIA ALOCADA PELO PROGRAMA.
void liberaMemoria(CONTATO *contatos)
{
	//LIBERA A MEMÓRIA ALOCADA, PASSANDO O PONTEIRO DE CONTATOS.
	free (contatos);
}

//CONSTRUÇÃO DA FUNÇÃO QUE INSERE OS CONTATOS.
void insereContato(CONTATO *contatos)
{
	int i;
	//PEDE E ARMAZENA NA MEMÓRIA TODAS AS INFORMAÇÕES DO CONTATO.
	printf ("\nInforme o nome: ");
	fflush(stdin);
	gets(&contatos->nome);

	//TRANFORMA O NOME INFORMADO EM LETRA MAIÚSCULA.
	for(i = 0; contatos->nome[i] != '\0'; i++)
	{
		contatos->nome[i] = toupper(contatos->nome[i]);
	}

	printf ("\nInforme o telefone: ");
	fflush(stdin);
	gets(&contatos->telefone);

	printf("\nInforme o dia do aniversario: ");
	scanf("%d", &contatos->diaNasc);

	printf("\nInforme o mês do aniversario: ");
	scanf("%d", &contatos->mesNasc);

	printf("\n\n\tContato: %s CADASTRADO COM SUCESSO !", contatos->nome);
}

//CONSTRUÇÃO DA FUNÇÃO QUE IMPRIME OS CONTATOS NA AGENDA.
void imprimeAgenda(CONTATO *contatos, int tamanhoVetor)
{
	int i;
	//CASO NÃO HAJA CONTATOS NA AGENDA EXIBE MENSAGEM.
	if(tamanhoVetor <= 0)
	{
		printf("\n****** - Sem contatos cadastrados na agenda - ******");
	}
	//CASO EXISTA.
	else
	{
		//PERCORRE O VETOR DE CONTATOS E EXIBE OS CONTATOS COM TODAS AS INFORMAÇÕES.
		for(i = 0; i < tamanhoVetor; i++)
		{
			printf("\n############################################");
			printf("\n\tNome: %s", contatos[i].nome);
			printf("\n\tTelefone: %s", contatos[i].telefone);
			printf("\n\tANiversario: %d / %d", contatos[i].diaNasc, contatos[i].mesNasc);
			printf("\n############################################\n\n");
		}
	 	//POR FIM MOSTRA O TOTAL DE CONTATOS NA AGENDA.
		printf("\n\tTotal de contatos cadastrados na agenda: %d", tamanhoVetor);
	}
}

//CONSTRUÇÃO DA FUNÇÃO QUE PESQUISA NA AGENDA CONTATOS COMEÇADOS POR DETERMINADA LETRA.
void consultaLetra(CONTATO *contatos, char letra, int tamanhoVetor)
{
	int i;
	int resultado = 0;
	
	//PERCORRE O VETOR DE CONTATOS.
	for(i = 0; i < tamanhoVetor; i++)
	{
		//CASO A LETRA INFORMADA PELO USUÁRIO FOR IGUAL A PRIMEIRA LETRA DE 
		//DETERMINADO NOME, ELE EXIBE TODAS AS INFORMAÇÕES DESSE CONTATO(S).
		if(letra == contatos[i].nome[0])
		{
			resultado ++;
			printf("\n############################################");
			printf("\n\tNome: %s", contatos[i].nome);
			printf("\n\tTelefone: %s", contatos[i].telefone);
			printf("\n\tANiversario: %d / %d", contatos[i].diaNasc, contatos[i].mesNasc);
			printf("\n############################################\n\n");
		}
	}
	//CASO NÃO HAJA NENHUM CONTATO COM A LETRA, ELE EXIBE UMA MENSAGEM.
	if(resultado == 0)
	{
		printf("Nenhum contato começado com a letra: %c", letra);
	}
}

//CONSTRUÇÃO DA FUNÇÃO QUE PESQUISA NA AGENDA CONTATOS COM DETERMINADO NOME.
void consultaNome(CONTATO *contatos, char nome[], int tamanhoVetor)
{
	int i;
	int resultado = 0;
	//PERCORRE O VETOR DE CONTATOS.
	for(i = 0; i < tamanhoVetor; i++)
	{
		//CASO O NOME INFORMADO PELO USUÁRIO, FOR EXATAMENTE IGUAL A ALGUM NOME
		//DA AGENDA, ELE EXIBE AS INFORMAÇÕES DESSE(S) CONTATO(S).
		if( strcmp(nome, contatos[i].nome) == 0 )
		{
			resultado ++;
			printf("\n############################################");
			printf("\n\tNome: %s", contatos[i].nome);
			printf("\n\tTelefone: %s", contatos[i].telefone);
			printf("\n\tANiversario: %d / %d", contatos[i].diaNasc, contatos[i].mesNasc);
			printf("\n############################################\n\n");
		}
	}
	//CASO NÃO HAJA NENHUM CONTATO COM ESSE NOME, EXIBE-SE UMA MENSAGEM AO USUÁRIO.
	if(resultado == 0)
	{
		printf("Nenhum contato com o nome : %s", nome);
	}
}


//CONSTRUÇÃO DA FUNÇÃO QUE PESQUISA USUÁRIOS ANIVERSARIANTES DE DETERMINADO MÊS.
void consultaAniversario(CONTATO *contatos, int mesAniversario, int tamanhoVetor)
{
	int i;
	int resultado = 0;
	//PERCORRE O VETOR DE CONTATOS.
	for(i = 0; i < tamanhoVetor; i++)
	{
		//CASO O MÊS INFORMADO PELO USUÁRIO FOR IGUAL AO MÊS DE NASCIMENTO 
		//ELE EXIBE TODAS AS INFORMAÇÕES DESSE(S) CONTATO(S).
		if(mesAniversario == contatos[i].mesNasc)
		{
			resultado ++;
			printf("\n############################################");
			printf("\n\tNome: %s", contatos[i].nome);
			printf("\n\tTelefone: %s", contatos[i].telefone);
			printf("\n\tANiversario: %d / %d", contatos[i].diaNasc, contatos[i].mesNasc);
			printf("\n############################################\n\n");
		}
	}
	if(resultado == 0)
	{
		//CASO NÃO HAJA NENHUM CONTATO ANIVERSARIANTE NESSE MÊS, 
		//EXIBE-SE UMA MENSAGEM AO USUÁRIO.
		printf("Nenhum aniversariante no mês: %d", mesAniversario);
	}
}
