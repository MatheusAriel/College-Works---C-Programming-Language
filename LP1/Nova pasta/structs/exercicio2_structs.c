#include <stdlib.h>
#include <stdio.h>
#define max 2

typedef struct
{
	int cod_prod;
	int qntd_prod;
	char nome_prod[30];
	float preco_prod;

} PRODUTOS;

void preenche_produtos(PRODUTOS prod[])
{
	int i;
	char lixo[2];

	for(i = 0; i < max; i++)
	{
		printf("+++PRODUTO %d+++\n", i + 1);

		printf("Informe o nome do produto: ");
		gets(prod[i].nome_prod);

		printf("Informe q quantidade do produto: ");
		scanf("%d", &prod[i].qntd_prod);

		printf("Informe o codigo do produto: ");
		scanf("%d", &prod[i].cod_prod);

		printf("Informe o preco do produto: R$ ");
		scanf("%f", &prod[i].preco_prod);

		gets(lixo);
	}
}

void menu_opcoe_produtos(PRODUTOS prod[])
{
	int i, opcao, opcao_cod ;
	float soma, media;

	while(1)
	{
		printf("Digite 1 - para aumentar o preco do produto em 10%\n");
		printf("Digite 2 - para diminuir 1 unidade do estoque\n");
		printf("Digite 3 - para imprimir os produtos que estejam acima da media\n");
		scanf("%d", &opcao);



		switch (opcao)
		{
		case 1:
			printf("Informe qual o produto que deseja aumentar em 10% o valor: " );
			scanf("%d", &opcao_cod);

			for(i = 0; i < max; i++)
			{
				if(opcao_cod == prod[i].cod_prod)
					break;
			}
			if (i < max)
			{
				prod[i].preco_prod = prod[i].preco_prod * 1.1;
				printf("O produto %d foi aumentado em 10%\n",prod[i].cod_prod);
			}
			else
			{
				printf("produto nao encontrado");
			}
			break;

		case 2:
			printf("Infome qual o produto que deseja subtrair uma unidade: ");
			scanf("%d", &opcao_cod);

			for (i = 0; i < max; i++)
			{
				if (opcao_cod == prod[i].cod_prod)
					break;
			}
			if (i < max)
			{
				if(prod[i].qntd_prod > 0)
				{
					prod[i].qntd_prod = prod[i].qntd_prod - 1;
					printf("O produto %d foi diminuido em 1 unidade\n",prod[i].cod_prod);
					
				}

			}
			break;

		case 3:
			soma = 0;
			for(i = 0; i < max; i++)
			{
				soma = soma + prod[i].preco_prod;

			}
			media = soma / max;


			for(i = 0; i < max; i++)
			{
				if(prod[i].preco_prod > media)
				{
					printf("%s\n", prod[i].nome_prod);
					printf("%d\n", prod[i].cod_prod);
				}

			}
			break;
		default :
			return;
		}
	}


}



int main(void)
{
	PRODUTOS prod[max];

	preenche_produtos(prod);
	menu_opcoe_produtos(prod);
	return 0;
}
