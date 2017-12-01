/*
Nome do programa: Agende-c.
Autor: Matheus Ariel de Souza
Data de cria��o: 7/05/2017
Descri��o: O programa permite o cadastro e a grava��o de contatos,
permite consultar todos contatos na agenda,
consulta de contatos por nome, por letra inicial do nome, e por m�s do aniver�rio
*/

//TODAS AS BIBLIOTECAS NECESS�RIAS PARA O FUNCIONAMENTO DO PROGRAMA.
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


//DECLARA��O DE TODAS AS FUN��ES UTILIZADAS PELO PROGRAMA.
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

	//CRIA UM PONTEIRO DO TIPO FILE, PARA FUTURAS MANIPULA��ES COM O ARQUIVO.
	FILE *arq;

	//VAR�AVEL UTILIZADA PELO MENU PARA ESCOLHER A OP��O SELECIONADA PELO USU�RIO.
	int opcao = -1;


	int n = 0, i;

	//DEFINE INICIALMENTE O TAMANHO DO VETOR COMO SENDO 0.
	int tamanhoVetor = 0;

	//VARI�VEIS PARA GUARDAR OS DADOS UTILIZADOS PELAS PESQUISAS DO USU�RIO.
	char letra;
	char nomePesquisa[50];
	int mesAniversario = 0;

	//CASO HAJA UM ARQUIVO BIN�RIO CHAMADO contatos.bat TENTA ABRI-LO.
	if((arq = fopen("contatos.dat", "rb")) == NULL)
	{
		//CASO N�O CONSIGA ABRIR, IMPRIME UMA MENSAGEM DE ERRO.
		printf( "\n\tERRO NA ABERTURA DO ARQUIVO");
	}
	//CASO CONSIGA.
	else
	{
		//TENTA LER O PRIMEIRO CAMPO DO ARQUIVO BIN�RIO, QUE � O
		//TAMANHO DE CONTATOS INSERIDOS NO ARQUIVO.
		if(fread(&tamanhoVetor, sizeof(int), 1, arq) != 1)
		{
			//CASO N�O CONSIGA LER, IMPRIME UMA MENSAGEM DE ERRO.
			printf("\n\tERRO");
		}
		//CASO CONSIGA
		else
		{
			//ALOCA MEM�RIA PARA RECEBER O VALOR DO TOTAL DE CONTATOS NO ARQUIVO.
			contatos = alocaMemoria(contatos , tamanhoVetor);

			//TENTA LER TODOS OS CONTATOS DO ARQUIVO BIN�RIO.
			if(fread(&contatos[0], sizeof(CONTATO), tamanhoVetor, arq) != tamanhoVetor)
			{
				//CASO N�O CONSIGA LER, IMPRIME UMA MENSAGEM DE ERRO.
				printf("Erro na leitura do arquivo CONTATOS");
			}
		}
		//AP�S FEITAS TODAS AS TENTATIVAS DE LEITURAS DO ARQUIVO, DANDO
		//CERTO OU N�O, � FECHADO O ARQUIVO.
		fclose(arq);
	}

	do
	{
		//EXIBE O MENU PARA O USU�RIO.
		printf("\n\n**************************************************************\n");
		printf("1 - Inserir contato(s).\n");
		printf("\n**************************************************************\n");
		printf("2 - Pesquisar contato por nome.\n");
		printf("\n**************************************************************\n");
		printf("3 - Listar todos os contatos.\n");
		printf("\n**************************************************************\n");
		printf("4 - Listar todos os contatos come�ando por determianda letra.\n");
		printf("\n**************************************************************\n");
		printf("5 - Mostrar aniversariante(s) de um determinado m�s.\n");
		printf("\n**************************************************************\n");
		printf("6 - Sair.\n");
		printf("\n**************************************************************\n");

		//ARMAZENA A ESCOLHA.
		printf ("\n\nEscolha uma op��o: ");
		scanf("%d", &opcao);
		printf("\n\n");

		switch(opcao)
		{
		case 1:
			//VERIFICA SE O TOTAL DE CONTATOS � 0
			if(tamanhoVetor == 0)
			{
				//ARMAZENA O TOTAL DE CONTATOS QUE O USU�RIO DESEJA CADASTRAR.
				printf("Informe quantos contatos deseja adicionar na agenda: ");
				scanf("%d", &n);
				/*CASO FOR, PEDE O TOTAL DE CADASTROS QUE DESEJA INSERIR NA
				AGENDA, E UTILIZA INICIALMENTE O MALLOC PARA ALOCAR MEM�RIA
				ATRAV�S DA FUN��O alocaMemoria, QUE RETORNA UM PONTEIRO DO TIPO
				CONTATO, QUE � RECEBIDO PELO PONTEIRO TAMB�M DO TIPO CONTATO CHAMADO
				contatos.
				*/
				contatos = alocaMemoria(contatos , n);

				//PERCORRE O N�MERO INFORMADO PELO USU�RIO.
				for(i = 0; i < n; i++)
				{
					//CHAMA A FUN��O QUE INSERE CONTATOS, PASSANDO COMO PAR�METRO
					//A �LTIMA POSI��O DO VETOR DE CONTATOS.
					insereContato(&contatos[i]);
				}
				//ATUALIZA O TAMANHO DO VETOR.
				tamanhoVetor = n;
			}
			//CASO O TAMANHO DO VETOR N�O SEJA MAIS 0, OU SEJA,
			//CASO J� TENHA CONTATOS CADASTRADOS NA AGENDA.
			else if(tamanhoVetor > 0)
			{
				//ARMAZENA O TOTAL DE CONTATOS QUE O USU�RIO DESEJA ACRESCENTAR.
				printf("\n\nQuantos contatos deseja acrescentar na agenda: ");
				scanf("%d", &n);

				//VERIFICA SE O N�MERO INFORMADO � UM N�MERO V�LIDO (MAIOR QUE 0).
				if(n > 0)
				{
					//j RECEBE O TAMANHO ANTIGO DO VETOR.
					int j = tamanhoVetor;
					//ATUALIZA O TAMANHO DO VETOR, SOMANDO COM O
					//VALOR DE NOVOS CONTATOS.
					tamanhoVetor = tamanhoVetor + n;

					//ALOCA MEM�RIA PARA OS NOVOS CONTATOS, UTILIZANDO REALLOC,
					//ATRAVES DA FUN��O realocaMemoria.
					contatos = realocaMemoria(contatos, tamanhoVetor);

					//PERCORRE O N�MERO INFORMADO PELO USU�RIO.
					for(i = j; i < tamanhoVetor; i++)
					{
						//CHAMA A FUN��O QUE INSERE CONTATOS, PASSANDO COMO PAR�METRO
						//A �LTIMA POSI��O DO VETOR DE CONTATOS.
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

			//PASSA TODAS AS LETRAS DO NOME PARA MAI�SCULA
			for(i = 0; nomePesquisa[i] != '\0'; i++)
			{
				nomePesquisa[i] = toupper(nomePesquisa[i]);
			}

			//CHAMA A FUN��O APRA PESQUISAR, PASSANDO O VETOR DE CONTATOS,
			//O NOME INFORMADO PARA PESQUISA, E A QUANTIDADE TODAL DE CONTATOS.
			consultaNome(contatos, nomePesquisa, tamanhoVetor);
			break;

		case 3:
			//CHAMA A FUN��O QUE IMPRIME TODOS OS CONTATOS, PASSANDO O VETOR
			//DE CONTATOS, E O TAMANHO TOTAL DE CONTATOS NA AGENDA.
			imprimeAgenda(contatos, tamanhoVetor);
			break;

		case 4:
			//PEGA A LETRA PARA PESQUISAR OS NOMES COME�ADOS POR ELA.
			fflush(stdin);
			printf("\n\n Informe uma letra: ");
			scanf("%c", &letra);
			fflush(stdin);
			//TRANSFORMA ESSA LETRA INFORMADA PELO USU�RIO EM MAIPUSCULA
			letra = toupper(letra);
			//CHAMA A FUN��O QUE PESQUISA OS NOMES COME�ADOS PELA DETERMINADA
			//LETRA, PASSANDO O VETOR DE CONTATOS, A LETRA E O TOTAL DE CONTATOS.
			consultaLetra(contatos, letra, tamanhoVetor);
			break;

		case 5:
			//PEGA O M�S PARA PESQUISAR OS ANIVERSARIANTES DESSE M�S.
			printf("Informe um m�s: ");
			scanf("%d", &mesAniversario);
			//CHAMA A FUN��O QUE PESQUISA POR M�S, E PASSA POR PAR�METRO O VETOR
			//DE CONTATOS, O M�S DESEJADO, E O TOTAL DE CONTATOS NA AGENDA.
			consultaAniversario(contatos, mesAniversario, tamanhoVetor);
			break;

		case 6:
			//TENTA ABRIR CASO EXISTA O ARQUIVO contatos.dat,CASO N�O EXISTA ELE
			//CRIA.
			if((arq = fopen("contatos.dat", "wb+")) == NULL)
			{
				//EXIBE MENSAGEM DE ERRO CASO D� ALGUM ERRO NA CRIA��O/ABERTURA
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
					//EXIBE MENSAGEM DE ERRO CASO N�O CONSIGA ESCREVER OS CONTATOS.
					printf("\n\tERRO AO GRAVAR CONTATOS");
				}
			}
			else
			{
				//EXIBE MENSAGEM DE ERRO CASO N�O CONSIGA SALVAR O TAMANHO VETOR.
				printf("\n\tERRO");
			}
			//FECHA O ARQUIVO.
			fclose(arq);
			//CHAMA A FUN��O QUE LIBERA MEM�RIA ALOCADA ANTERIORMENTE.
			liberaMemoria(contatos);
			exit(0);
			break;
		}
	}
	//ENQUANTO A OP��O ESCOLHIDA PELO USU�RIO FOR DIFERENTE DE -1, O MENU FICAR� SENDO EXIBIDO.
	while(opcao != -1);
	return 0;
}

//CRIA��O DAS FUN��ES NECESS�RIAS PARA O PROGRAMA:

//CONSTRU��O DA FUN��O QUE ALOCA MEM�RIA.
CONTATO *alocaMemoria(CONTATO *contatos, int tamanhoVetor)
{
	//FAZ A ALOCA��O PARA O TOTAL DE CONTATOS NECESS�RIOS.
	contatos = (CONTATO *) malloc(tamanhoVetor * sizeof(CONTATO));

	//CASO N�O CONSIGA
	if (!contatos)
	{
		//EXIBE MENSAGEM DE ERRO.
		printf ("\nErro: Memoria Insuficiente");
		exit(0);
	}
	//RETORNA O PONTEIRO DO TIPO CONTATO PARA A INSER��O DE NOVOS CONTATOS
	//NA MEM�RIA ALOCADA.
	return contatos;
}

//CONSTRU��O DA FUN��O QUE REALOCA MEM�RIA.
CONTATO *realocaMemoria(CONTATO *contatos, int tamanhoVetor)
{
	//FAZ A REALOCA��O PARA O TOTAL DE CONTATOS NECESS�RIOS.
	//FAZ A CONVERS�O DO PONTEIRO PARA O TIPO CONTATO.
	contatos = (CONTATO *) realloc(contatos, tamanhoVetor * sizeof(CONTATO));

	//CASO N�O CONSIGA
	if (!contatos)
	{
		//EXIBE MENSAGEM DE ERRO.
		printf ("\nErro: Memoria Insuficiente");
		exit(0);
	}
	//RETORNA O PONTEIRO DO TIPO CONTATO PARA A INSER��O DE NOVOS CONTATOS
	//NA MEM�RIA ALOCADA.
	return contatos;
}

//CONSTRU��O DA FUN��O QUE LIBERA A MEM�RIA ALOCADA PELO PROGRAMA.
void liberaMemoria(CONTATO *contatos)
{
	//LIBERA A MEM�RIA ALOCADA, PASSANDO O PONTEIRO DE CONTATOS.
	free (contatos);
}

//CONSTRU��O DA FUN��O QUE INSERE OS CONTATOS.
void insereContato(CONTATO *contatos)
{
	int i;
	//PEDE E ARMAZENA NA MEM�RIA TODAS AS INFORMA��ES DO CONTATO.
	printf ("\nInforme o nome: ");
	fflush(stdin);
	gets(&contatos->nome);

	//TRANFORMA O NOME INFORMADO EM LETRA MAI�SCULA.
	for(i = 0; contatos->nome[i] != '\0'; i++)
	{
		contatos->nome[i] = toupper(contatos->nome[i]);
	}

	printf ("\nInforme o telefone: ");
	fflush(stdin);
	gets(&contatos->telefone);

	printf("\nInforme o dia do aniversario: ");
	scanf("%d", &contatos->diaNasc);

	printf("\nInforme o m�s do aniversario: ");
	scanf("%d", &contatos->mesNasc);

	printf("\n\n\tContato: %s CADASTRADO COM SUCESSO !", contatos->nome);
}

//CONSTRU��O DA FUN��O QUE IMPRIME OS CONTATOS NA AGENDA.
void imprimeAgenda(CONTATO *contatos, int tamanhoVetor)
{
	int i;
	//CASO N�O HAJA CONTATOS NA AGENDA EXIBE MENSAGEM.
	if(tamanhoVetor <= 0)
	{
		printf("\n****** - Sem contatos cadastrados na agenda - ******");
	}
	//CASO EXISTA.
	else
	{
		//PERCORRE O VETOR DE CONTATOS E EXIBE OS CONTATOS COM TODAS AS INFORMA��ES.
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

//CONSTRU��O DA FUN��O QUE PESQUISA NA AGENDA CONTATOS COME�ADOS POR DETERMINADA LETRA.
void consultaLetra(CONTATO *contatos, char letra, int tamanhoVetor)
{
	int i;
	int resultado = 0;
	
	//PERCORRE O VETOR DE CONTATOS.
	for(i = 0; i < tamanhoVetor; i++)
	{
		//CASO A LETRA INFORMADA PELO USU�RIO FOR IGUAL A PRIMEIRA LETRA DE 
		//DETERMINADO NOME, ELE EXIBE TODAS AS INFORMA��ES DESSE CONTATO(S).
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
	//CASO N�O HAJA NENHUM CONTATO COM A LETRA, ELE EXIBE UMA MENSAGEM.
	if(resultado == 0)
	{
		printf("Nenhum contato come�ado com a letra: %c", letra);
	}
}

//CONSTRU��O DA FUN��O QUE PESQUISA NA AGENDA CONTATOS COM DETERMINADO NOME.
void consultaNome(CONTATO *contatos, char nome[], int tamanhoVetor)
{
	int i;
	int resultado = 0;
	//PERCORRE O VETOR DE CONTATOS.
	for(i = 0; i < tamanhoVetor; i++)
	{
		//CASO O NOME INFORMADO PELO USU�RIO, FOR EXATAMENTE IGUAL A ALGUM NOME
		//DA AGENDA, ELE EXIBE AS INFORMA��ES DESSE(S) CONTATO(S).
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
	//CASO N�O HAJA NENHUM CONTATO COM ESSE NOME, EXIBE-SE UMA MENSAGEM AO USU�RIO.
	if(resultado == 0)
	{
		printf("Nenhum contato com o nome : %s", nome);
	}
}


//CONSTRU��O DA FUN��O QUE PESQUISA USU�RIOS ANIVERSARIANTES DE DETERMINADO M�S.
void consultaAniversario(CONTATO *contatos, int mesAniversario, int tamanhoVetor)
{
	int i;
	int resultado = 0;
	//PERCORRE O VETOR DE CONTATOS.
	for(i = 0; i < tamanhoVetor; i++)
	{
		//CASO O M�S INFORMADO PELO USU�RIO FOR IGUAL AO M�S DE NASCIMENTO 
		//ELE EXIBE TODAS AS INFORMA��ES DESSE(S) CONTATO(S).
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
		//CASO N�O HAJA NENHUM CONTATO ANIVERSARIANTE NESSE M�S, 
		//EXIBE-SE UMA MENSAGEM AO USU�RIO.
		printf("Nenhum aniversariante no m�s: %d", mesAniversario);
	}
}
