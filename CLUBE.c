/* Cadastro sócios: nome, idade, salário */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOME 31

struct socio
{
	char nome[31];
	int idade;
	float salario;
};

struct socio vetSocios[30];

int sociosExcluidos = 0;
int i;

//prototipos das funcoes
int exibirMenu();
int cadastrar (int tamanho);
void listar(int tamanho);
int jahExiste(char nomeExiste[20], int tamanho );
int excluir (int &tamanho);

int main()
{
	int qntSocios = 0;
	int opcao = -1;
	while(opcao != 0)
	{

		opcao = exibirMenu();

		if (opcao == 1)
		{
			qntSocios = cadastrar(qntSocios);
		}
		else if (opcao == 2)
		{
			listar(qntSocios);
		}
		else if (opcao == 3)
		{
			int idadeLimite;
			int controle = 0;

			printf ("\n Digite uma idade limite: ");
			scanf("%d", &idadeLimite);

			for ( i = 0; i < qntSocios; i++)
			{
				if (vetSocios[i].idade > idadeLimite)
				{
					printf("\n DADOS DO SOCIO #%d", i + 1);
					printf("\n nome: %s", vetSocios[i].nome);
					printf("\n idade: %d", vetSocios[i].idade);
					printf("\n Salario: %.2f\n", vetSocios[i].salario);

					controle = 1;
				}
			}
			if (controle == 0)
			{
				printf("\n NAO EXISTE SOCIO ACIMA DA IDADE ESTIPULADA");
			}
		}
		else if (opcao == 4)
		{
			if ( excluir(qntSocios) == 1 )
			{
				printf ("\n socio excluido com sucesso !!");
			}
			else
				printf ("\n nao foi encontrado socio com esse nome na base !!");
		}
		else if (opcao == 5)
		{
			char socioAtualizar[NOME];

			printf("\n Digite o nome do socio que sera atualizado: ");
			fflush(stdin);
			scanf("%s", socioAtualizar);

			for ( i = 0; i < qntSocios; i++)
			{
				if (strcmp (socioAtualizar, vetSocios[i].nome) == 0)
				{
					char NovoNomeSocio[NOME];
					int novaIdade;
					float novoSalario;

					printf("\n Digite o NOVO nome do socio: ");
					fflush(stdin);
					scanf("%s", NovoNomeSocio);
					strcpy(vetSocios[i].nome, NovoNomeSocio);

					printf("\n Digite a NOVA idade do socio: ");
					scanf("%d", &novaIdade);
					vetSocios[i].idade = novaIdade;

					printf("\n Digite o novo salario do socio; ");
					scanf("%f", &novoSalario);
					vetSocios[i].salario = novoSalario;
				}
			}
		}
		else if (opcao == 6)
		{
			float mediaSalarios = 0;

			//Calculando a media dos salarios
			for ( i = 0; i < qntSocios; i++)
			{
				mediaSalarios = mediaSalarios + vetSocios[i].salario / (i + 1);
			}

			printf("\n Media dos salarios = %f", mediaSalarios);

			//Encontrando o maior salario
			float maiorSalario = 0;
			int socioDeMaiorSalario = 0;

			maiorSalario = vetSocios[0].salario;

			for ( i = 1; i <= qntSocios; i++)
			{
				if (maiorSalario < vetSocios[i].salario)
				{
					maiorSalario = vetSocios[i].salario;
					socioDeMaiorSalario = i;
				}
			}

			printf("\n O socio de maior salario e: %s", vetSocios[socioDeMaiorSalario].nome);

			//Encontrando o menor salario
			float menorSalario = 0;
			int socioDeMenorSalario = 0;

			menorSalario = vetSocios[0].salario;

			for( i = 1; i <= qntSocios; i++)
			{
				if (menorSalario > vetSocios[i].salario)
				{
					menorSalario = vetSocios[i].salario;
					socioDeMenorSalario = i;
				}
			}

			printf("\n A idade do socio de menor salario e: %d", vetSocios[socioDeMenorSalario].idade);
		}
		else if (opcao == 7)
		{
			printf("\n Socios excluidos: %d", sociosExcluidos);
		}
	}
	return 0;
}

int exibirMenu()
{
	int op;
	printf("\n ESCOLHA UMA OPCAO: ");
	printf("\n 0 - SAIR DO PROGRAMA ");
	printf("\n 1 - CADASTRAR SOCIO ");
	printf("\n 2 - LISTAR SOCIO(S) ");
	printf("\n 3 - LISTAR SOCIO(S) ACIMA DE DETERMINADA IDADE");
	printf("\n 4 - EXCLUIR SOCIO ");
	printf("\n 5 - ATUALIZAR SOCIO ");
	printf("\n 6 - MEDIA DOS SALARIOS, SOCIO COM MAIOR SALARIO E IDADE DO SOCIO COM MENOR SALARIO ");
	printf("\n 7 - QUANTIDADE DE SOCIOS EXCLUIDOS");
	printf("\n Opcao: ");
	scanf("%d", &op);
	return op;

}

int cadastrar (int tamanho)
{
	//declarar uma vari?vel para o poss?vel novo s?cio
	char novoSocio[31];
	printf("\n Digite o nome do novo socio que quer cadastrar : ");
	scanf("%s", novoSocio);
	if (  jahExiste (novoSocio, tamanho) == 0 ) //indica que nao existe e posso cadastrar
	{
		//copio o nome do novo s?cio no vetor
		strcpy(vetSocios[tamanho].nome, novoSocio);
		printf("\n Digite a idade do socio: ");
		scanf("%d", &vetSocios[tamanho].idade);
		printf("\n Digite o salario do socio: ");
		scanf("%f", &vetSocios[tamanho].salario);
		tamanho++;
	}
	else //indica que o socio jah esta na base
	{
		printf("\n o socio jah estah cadastrado na base !!");
	}

	return tamanho;
}

int jahExiste(char nomeExiste[20], int tamanho )
{
	//percorrer o vetor para ver se existe nome cadastrado.
	for (i = 0; i < tamanho; i++)
	{
		if (strcmp(nomeExiste, vetSocios[i].nome) == 0) //nome igual encontrado!
			return 1; //indica que o nome j? existe
	}
	return 0; //indica que o nome nao existe

}

void listar(int tamanho)
{
	for( i = 0; i < tamanho; i ++)
	{
		printf("\n DADOS DO SOCIO #%d", i + 1);
		printf("\n Nome: %s", vetSocios[i].nome);
		printf("\n Idade: %d", vetSocios[i].idade);
		printf("\n Salario: %.2f\n", vetSocios[i].salario);
	}
}

int excluir (int &tamanho) //passando o paramentro por referencia (&) e nao mais por valor

{
	int excluido = 0;
	char socioExcluir[NOME];
	printf("\n Digite o nome do socio que sera excluido: ");
	fflush(stdin);
	scanf("%s", socioExcluir);
	for ( i = 0; i < tamanho; i++)
	{
		if (strcmp(socioExcluir, vetSocios[i].nome) == 0)
		{
			int j;
			for ( j = i; j < tamanho - 1; j++)
			{
				strcpy(vetSocios[j].nome, vetSocios[j + 1].nome);
				vetSocios[j].idade = vetSocios[j + 1].idade;
				vetSocios[j].salario = vetSocios[j + 1].salario;
			}
			tamanho--;
			excluido = 1;
			sociosExcluidos++;
		}
	}
	return excluido;
}
