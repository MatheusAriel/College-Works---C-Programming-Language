#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
	char sexo;
	char fumante; 
} ENTREVISTADO;

void criacao_arquivo()
{
	ENTREVISTADO pessoa;
	char resposta;
	FILE *arq;

	arq = fopen ("respostas.bin", "wb");
	if (arq == NULL)
	{
		printf("Erro na criacao do arquvio\n");
		system("pause");
		exit(0);
	}

	else
	{
		do
		{
			printf("\nInforme o sexo (m/f): ");
			scanf("%c", &pessoa.sexo);
			fflush(stdin);



			while(pessoa.sexo != 'm' && pessoa.sexo != 'f')
			{
				printf("\nPor Favor insira m para masculino ou f para feminino");
				printf("\nInforme o sexo: ");
				scanf("%c", &pessoa.sexo);
				fflush(stdin);

			}


			printf("Informe se a pessoa eh fumante (s/n): ");
			scanf("%c", &pessoa.fumante);
			fflush(stdin);

			while(pessoa.fumante != 's' && pessoa.fumante != 'n')
			{
				printf("\nPor Favor insira s para sim ou n para nao");
				printf("\nInforme se a pessoa eh fumante: ");
				scanf("%c", &pessoa.fumante);
				fflush(stdin);
			}


			printf("Informe a idade: ");
			scanf("%d", &pessoa.idade);
			fflush(stdin);

			fwrite (&pessoa, sizeof(ENTREVISTADO), 1, arq);

			printf("\n\nDeseja realizar outra entrevista (s/n): ");
			scanf("%c", &resposta);
			fflush(stdin);

			while(resposta != 's' && resposta != 'n')
				
			{
				printf("\nPor Favor insira s para sim ou n para nao");
				printf("\nInforme se deseja cadastrar outra entrevista: ");
				scanf("%c", &resposta);
				fflush(stdin);
			}


		}
		while(resposta == 's');
		

		fclose(arq);
	}
}


void percentual_fumantes()
{
	FILE *arq;
	int total_fumantes = 0, total_pessoas = 0;
	ENTREVISTADO pessoa;
	arq = fopen("respostas.bin", "rb");
	if(arq == NULL)
	{
		printf("Erro na leitura do arquivo");
		system("pause");
		exit(0);
	}
	else
	{
		while(fread(&pessoa, sizeof(ENTREVISTADO), 1, arq))	
	
		{
			total_pessoas++;

			if(pessoa.fumante == 's')
			{
				total_fumantes++;
			}
		}

		fclose(arq);//FECHA O ARQUIVO APÓS A LEITURA

		printf("O percentual de fumantes em relacao ao numero total\n");
		printf("de pessoa entrevistadas eh: %d%%\n", (total_fumantes * 100) / total_pessoas);
	

		printf("\nTotal de pessoas entrevistadas: %d\n", total_pessoas);
		

		printf("\nTotal de fumantes: %d\n", total_fumantes);
	

	}
}

void percentual_homens_nao_fumantes()
{
	FILE *arq;
	int total_homens = 0;
	int total_homens_nao_fumantes = 0;
	ENTREVISTADO pessoa;

	arq = fopen("respostas.bin", "rb");
	if(arq == NULL)
	{
		printf("Erro na leitura do arquvio: ");
		system("pause");
		exit(0);
	}

	else
	{
		while(fread(&pessoa, sizeof(ENTREVISTADO), 1, arq))
		{
			if(pessoa.sexo == 'm')

			{
				total_homens++;

				if(pessoa.idade < 40 && (pessoa.fumante == 'n'))
					
					total_homens_nao_fumantes++;
			}
		}
		fclose(arq);

		printf("\nO percentual de homens nao fumantes abaixo de 40 anos em relacao ao \n");
		printf("numero total de homens entrevistados eh: %d%%\n", (total_homens_nao_fumantes * 100) / total_homens);

	}
}


void percentual_mulheres_fumantes()
{
	FILE *arq;
	ENTREVISTADO pessoa;
	int total_mulheres_fumantes = 0;
	int  total_mulheres = 0;


	arq = fopen("respostas.bin", "rb");
	if(arq == NULL)
	{
		printf("Erro na leitura do arquivo");
		system("pause");
		exit(0);
	}
	else
	{
		while(fread(&pessoa, sizeof(ENTREVISTADO), 1, arq))
		{
			if(pessoa.sexo == 'f')
			{
				total_mulheres++;

				if(pessoa.idade > 40 && pessoa.fumante == 's')
					
					total_mulheres_fumantes++;
			}
		}
		fclose(arq);

		printf("\nO percentual de mulheres fumantes acima de 40 anos em relacao ao \n");
		printf("numero total de mulheres entrevistadas eh: %d%%\n", (total_mulheres_fumantes * 100) / total_mulheres);
		
	}
}


int main()
{
	int opcao;


	do
	{
		printf("================================================================================\n");
		printf("DIGITE 1 PARA CRIAR PESQUISA\n");

		printf("\nDIGITE 2 PARA SABER O PERCENTUAL DE FUMANTES\n");
		printf("EM RELACAO AO NUMERO TOTAL DE PESSOAS ENTREVISTADAS\n");

		printf("\nDIGITE 3 PARA SABER O PERCENTUAL DE HOMENS NAO \n");
		printf("FUMANTES EM RELACAO AO NUMERO TOTAL DE HOMENS ENTREVISTADOS\n");

		printf("\nDIGITE 4 PARA SABER O PERCENTUAL DE MULHERES\n");
		printf("FUMANTES ACIMA DE 40 ANOS EM RELACAO AO NUMERO TOTAL DE MULHERES ENTREVISTADAS\n");
		printf("\n================================================================================\n");
		scanf("%d", &opcao);
	}
	while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4);
	


	switch(opcao)
	{
	case 1:
		criacao_arquivo();
		break;

	case 2:
		percentual_fumantes();
		break;

	case 3:
		percentual_homens_nao_fumantes();
		break;

	case 4:
		percentual_mulheres_fumantes();
		break;
	}

	system("pause");
	return 0;
}

