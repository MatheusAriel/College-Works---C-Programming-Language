#include <stdio.h>
#include <conio.h>
#include <string.h>

struct paciente
{
	char nome[30];
	int idade;
};

//CRIA UM VETOR DE 20 POSICOES DA ESTRUTURA DE DADOS PACIENTE
struct paciente vetPacientes[20];

int qtddPaciente;//CONTROLA A QTDD DE PACIENTES CADASTRADOS.

int main()
{
	qtddPaciente = 0; //CONTROLA A QTDD DE PACIENTES CADASTRADOS.
	int opcao = -1;
	int i;
	int j;
	while (opcao != 0 )
	{
		printf("\n ESCOLHA UMA OPCAO: ");
		printf("\n 0 - SAIR DO PROGRAMA ");
		printf("\n 1 - cadastrar PACIENTE ");
		printf("\n 2 - LISTAR PACIENTES ");
		printf("\n 3 - LISTAR PACIENTES ACIMA DE DETERMINADA IDADE");
		printf("\n 4 - EXCLUIR PACIENTE ");
		printf("\n 5 - ATUALIZAR PACIENTE \n");
		scanf("%d", &opcao);//o valor digitado pelo usu?rio ir? para a variavel opcao

		if (opcao == 1) //SE O USUARIO ESCOLHEU A OPCAO DE CADASTRO
		{
			//PEGANDO O NOME DO PACIENTE
			char paciente[30];
			printf("\n Digite o nome do Paciente: ");
			fflush(stdin);
			gets(paciente);
			strcpy(vetPacientes[qtddPaciente].nome, paciente);

			//PEGANDO A IDADE DO PACIENTE
			printf("\n Digite a idade do Paciente: ");
			scanf("%d", &vetPacientes[qtddPaciente].idade);
			qtddPaciente++;
		}
		else if (opcao == 2) //para listar os pacientes
		{
			for(i = 0; i < qtddPaciente; i ++)
			{
				printf("\n DADOS DO PACIENTE # %d", i + 1);
				printf("\n nome: %s", vetPacientes[i].nome);
				printf("\n idade: %d\n", vetPacientes[i].idade);
			}
		}
		else if (opcao == 3)
		{
			int idade;
			printf ("\n Digite a idade limite: ");
			scanf("%d", &idade);
			int controle = 0; //controle = 0 se existir paciente acima da idade
			for ( i = 0 ; i < qtddPaciente; i++)
			{
				if (vetPacientes[i].idade > idade)
				{
					printf("\n DADOS DO PACIENTE");
					printf("\n nome: %s", vetPacientes[i].nome);
					printf("\n idade: %d", vetPacientes[i].idade);
					controle = 1;
				}
			}
			if (controle == 0)
			{
				printf("\n NAO EXISTE NINGUEM ACIMA DA IDADE ESTIPULADA");
			}

		}
		else if (opcao == 4)
		{
			char paciente[30];
			printf("\n Digite o nome do Paciente que sera excluido: ");
			fflush(stdin);
			gets(paciente);
			for (i = 0 ; i < qtddPaciente; i++)
			{
				if (strcmp(paciente, vetPacientes[i].nome) == 0) //encontrei o nome
				{

					for (j = i; j < qtddPaciente - 1; j++)
					{
						//colocar o pr?ximo paciente na posicao do atual
						strcpy(vetPacientes[j].nome, vetPacientes[j + 1].nome);
						vetPacientes[j].idade = vetPacientes[j + 1].idade;

					}
					qtddPaciente--;
				}
			}
		}
		else if (opcao == 5)
		{
			char paciente[30];
			printf("\n Digite o nome do Paciente que sera atualizado: ");
			fflush(stdin);
			gets(paciente);
			for ( i = 0 ; i < qtddPaciente; i++)
			{
				if (strcmp (paciente, vetPacientes[i].nome) == 0)	//localizei o nome
				{
					//PEGANDO O NOME DO PACIENTE
					char paciente[30];
					printf("\n Digite o NOVO nome do Paciente: ");
					fflush(stdin);
					gets(paciente);
					strcpy(vetPacientes[i].nome, paciente);

					//PEGANDO A IDADE DO PACIENTE
					printf("\n Digite a NOVA idade do Paciente: ");
					scanf("%d", &vetPacientes[i].idade);
				}
			}
		}
	}

}
