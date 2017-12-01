#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
	char sexo;
	char fumante; //STRUCT PARA ARMAZENAR AS ENTREVISTAS
	int idade;
} ENTREVISTADO;

void percentual_fumantes()//FUNÇÃO QUE SOMA A QUANTIDADE TOTAL DE FUMANTES
{
	FILE *arq;
	int total_fumantes = 0, total_pessoas = 0;
	ENTREVISTADO pessoa;
	arq = fopen("respostas.bin", "rb");
	if(arq == NULL)
	{
		printf("Erro na leitura do arquivo");//MENSAGEM DE ERRO CASO NÃO CONSIGA ABRIR O ARQUIVO
		system("pause");
		exit(0);
	}
	else
	{
		while(fread(&pessoa, sizeof(ENTREVISTADO), 1, arq))
			//SAI DO LOOPING QUANDO FREAD DER ERRO, SOMENTE DA ERRO QUANDO TENTAR LER APÓS O ARQUIVO
			//(LE O ARQUVIO ATÉ O FIM DELE
		{
			total_pessoas++;//FAZ UMA CONTAGEM DO TOTAL DE PESSOAS ENTREVISTADAS

			if(pessoa.fumante == 's')
			{
				total_fumantes++;//SE A PESSOA FOR FUMANTE ELE SOMA AQUI
			}
		}

		fclose(arq);//FECHA O ARQUIVO APÓS A LEITURA

		printf("O percentual de fumantes em relacao ao numero total\n");
		printf("de pessoa entrevistadas eh: %d%%\n", (total_fumantes * 100) / total_pessoas);
		//EXIBE O PERCENTUAL TOTAL DE FUMANTES

		printf("\nTotal de pessoas entrevistadas: %d\n", total_pessoas);
		//EXIBE O TOTAL DE PESSOAS ENTREVISTADAS

		printf("\nTotal de fumantes: %d\n", total_fumantes);
		//EXIBE QUANTOS FUMANTES A ENTREVISTA POSSUI

	}
}

void percentual_homens_nao_fumantes()//FUNÇÃO PARA CALCULAR O TOTAL DE HOMENS ABAIXO DE 40 ANOS
//NNÃO FUMANTES
{
	FILE *arq;
	int total_homens = 0;
	int total_homens_nao_fumantes = 0;
	ENTREVISTADO pessoa;

	arq = fopen("respostas.bin", "rb");
	if(arq == NULL)
	{
		printf("Erro na leitura do arquvio: ");//MENSAGEM DE ERRO CASO NÃO CONSIGA LER O ARQUIVO
		system("pause");
		exit(0);
	}

	else
	{
		while(fread(&pessoa, sizeof(ENTREVISTADO), 1, arq))//SAI DO LOOPING QUANDO FREAD DER ERRO,
			// SOMENTE DA ERRO QUANDO TENTAR LER APÓS O ARQUIVO (LE O ARQUVIO ATÉ O FIM DELE)
		{
			if(pessoa.sexo == 'm')
				//VERIFICA SE O SEXO É MASCULINO
			{
				total_homens++;//CONTABILIZA O TOTAL DE HOMENS

				if(pessoa.idade < 40 && (pessoa.fumante == 'n'))
					//CASO SEJA HOMEM ELE ENTRA E VERIFICA SE: IDADE EH MENOR QUE 40 E SE NÃO EH FUMANTE
					total_homens_nao_fumantes++;//SE ATENDER AS REGRAS ELE SOMA
			}
		}
		fclose(arq);//FECHA O ARQUIVO APÓS EFETUAR A LEITURA

		printf("\nO percentual de homens nao fumantes abaixo de 40 anos em relacao ao \n");
		printf("numero total de homens entrevistados eh: %d%%\n", (total_homens_nao_fumantes * 100) / total_homens);
		//CALCULA O PERCENTUAL E O EXIBE
	}
}


void percentual_mulheres_fumantes()//FUNÇÃO QUE CALCULA O PERCENTUAL DE MULHERES
//ACIMA DE 40 ANOS FUMANTES
{
	FILE *arq;
	ENTREVISTADO pessoa;
	int total_mulheres_fumantes = 0;
	int  total_mulheres = 0;


	arq = fopen("respostas.bin", "rb");
	if(arq == NULL)
	{
		printf("Erro na leitura do arquivo");//EXIBE MENSAGEM DE ERRO CASO NÃO ABRA O ARQUIVO
		system("pause");
		exit(0);
	}
	else
	{
		while(fread(&pessoa, sizeof(ENTREVISTADO), 1, arq))//SAI DO LOOPING QUANDO FREAD DER ERRO,
			// SOMENTE DA ERRO QUANDO TENTAR LER APÓS O ARQUIVO (LE O ARQUVIO ATÉ O FIM DELE)
		{
			if(pessoa.sexo == 'f')//VERIFICA SE O SEXO É FEMININO
			{
				total_mulheres++;//CONTABILIZA O TOTAL DE MULHERES

				if(pessoa.idade > 40 && pessoa.fumante == 's')
					//SE TIVER MAIS QUE 40 ANOS E FOR FUMANTE ELE CONTABILIZA
					total_mulheres_fumantes++;
			}
		}
		fclose(arq);//FECHA O ARQUIVO APÓS EFETUAR A LEITURA

		if(total_mulheres != 0)
		{
			printf("\nO percentual de mulheres fumantes acima de 40 anos em relacao ao \n");
			printf("numero total de mulheres entrevistadas eh: %d%%\n", (total_mulheres_fumantes * 100) / total_mulheres);
			//CALCULA O PERCENTUAL E O EXIBE
		}
		else
		{
			printf("nao há mulheres na pesquisa");
		}

	}
}


int main()
{
	int opcao;


	do
	{
		printf("==============================================================\n");

		printf("\nDigite 1 para saber o percentual de fumantes\n");
		printf("em relacao ao numero total de pessoa entrevistadas\n");

		printf("\nDigite 2 para saber o percentual de homens nao \n");
		printf("fumantes abaixo de 40 anos em relacao ao numero total de homens entrevistados\n");

		printf("\nDigite 3 para saber o percentual de mulheres\n");
		printf("fumantes acima de 40 anos em relacao ao numero total de mulheres entrevistadas\n");
		printf("\n======================================================================\n");
		scanf("%d", &opcao);
	}
	while(opcao != 1 && opcao != 2 && opcao != 3);
	//EXIBE O MENU E CASO O USUARIO COLOQUE UMA OPÇÃO INVALIDA ELE VOLTA A MOSTRAR O MENU
	//ATÉ A OPÇÃO SER VÁLIDA


	switch(opcao)
	{
	case 1:
		percentual_fumantes();// CHAMA A FUNÇÃO QUE EXIBE O PERCENTUAL DE FUMANTES
		break;

	case 2:
		percentual_homens_nao_fumantes();//CHAMA A FUNÇÃO QUE EXIBE O PERCENTUAL DE HOMENS
		//ABAIXO DE 40 ANOS NÃO FUMANTES
		break;

	case 3:
		percentual_mulheres_fumantes();//CHEMA A FUNÇÃO QUE EXIBE O PERCENTUAL DE MULHERES
		//ACIMA DE 40 ANOS FUMANTES
		break;
	
	}

	system("pause");
	return 0;
}

