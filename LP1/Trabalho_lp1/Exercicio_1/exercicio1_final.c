#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 30


typedef struct//Estrutura de registro de cada usuario
{
	char nome[40];
	char data[11];
	char horaLOGIN[6];
	char horaLOGOUT[6];
} LOGIN;

typedef struct//estrutura para criação da lista
{
	LOGIN item[max];
	int inicio, fim;
} TIPOLISTA;

void InicializaLista(TIPOLISTA *l)//função para inicializar lista
{
	l->inicio = 0;
	l->fim = 0;
}

int comparaDatas(char *data1, char * data2)//função para comparar datas, para ordenar a lista
{
	int d, m, a;
	int d2, m2, a2;

	sscanf(data1, "%d/%d/%d", &d, &m,  &a);
	sscanf(data2, "%d/%d/%d", &d2, &m2, &a2);

	int ano = a - a2;
	if(ano != 0)
		return ano;//retorna diferença do ano

	int mes = m - m2;
	if(mes != 0)
		return mes;//retorna a diferença do mês

	int dia = d - d2;
	return dia;//retorna a diferença do dia

}

int comparaHoras(char *hora1, char *hora2)//função para comparar horas
{
	int h, m;
	int h2, m2;

	sscanf(hora1, "%d:%d", &h, &m);
	sscanf(hora2, "%d:%d", &h2, &m2);

	int hora = h - h2;
	if(hora != 0)
		return hora;
	int minuto = m - m2;
	return minuto;
}

int inserirLista(TIPOLISTA *l, LOGIN *usuario)
{
	int i, j;

	for(i = 0; i < l->fim; i++) //encontra na lista onde se deve inserir o usuario
	{
		if(comparaDatas(usuario->data, l->item[i].data) < 0)
		{
			//interrompe se encontra na litsa uma data de login posterior a do usuario a ser inserido
			//o i sai valendo a posição na lista que o novo usuario deve ocupar
			break;
		}

	}
	for(j = l->fim; j > i; j--)
	{
		l->item[j] = l->item[j - 1]; //desloca todos que estiverem depois
	}
	l->item[i] = *usuario;// insere o usuario na posição certa
	l->fim++;

}


void ler_Arquivo(TIPOLISTA * l)//função para ler o arquivo .bin
{


	LOGIN usuario;
	int i;
	FILE *arq;

	arq = fopen ("LOGIN.bin", "rb");
	if(arq == NULL)
	{
		printf("Erro na Leitura");
		system("pause");
		exit(0);
	}

	else
		while(fread(&usuario, sizeof(LOGIN), 1, arq))
		{
			inserirLista(l, &usuario);//insere o conteudo na lista
		}
	fclose(arq);
}

void imprimeLista(TIPOLISTA *l)//imprime cada campo da lista
{

	int i;
	for(i = 0; i < l->fim; i++)
	{
		printf("\nNome Usuario: %s", l->item[i].nome);
		printf(" - Data: %s", l->item[i].data);
		printf(" - Hora Login: %s", l->item[i].horaLOGIN);
		printf(" - Hora Logout: %s", l->item[i].horaLOGOUT);

	}



}

void mostrarUsuario(TIPOLISTA *l)//mostra todos os usuarios, sem repiti-los(caso apareçam mais de uma vez na lista)
{
	int i, j;
	char aux[max][40];
	int fimaux = 0;

	for(i = 0; i < l->fim; i++)//percorre toda a lista
	{
		for(j = 0; j < fimaux; j++)//compara um nome da lista com toda a lista
		{
			if(strcmp(l->item[i].nome, aux[j]) == 0)//se achar nome iguais,para o laço
				break;

		}
		if(j == fimaux)
		{
			strcpy ( aux[fimaux], l->item[i].nome);
			fimaux++;//copia item nome para aux
		}

	}
	for(i = 0; i < fimaux; i++)
	{
		printf("\n%s", aux[i]);//imrpime o aux
	}

}


void consultaLogin(TIPOLISTA *l, char *dataLogin, char *aposHora)//mostra acessos em determinado dia e apos certa hora
{
	int i;


	for(i = 0; i < l->fim; i++)//percorre a lista
	{
		if(comparaDatas(l->item[i].data, dataLogin) == 0)//compara data com a fornecida pelo usuario
		{
			if(comparaHoras(l->item[i].horaLOGIN, aposHora) > 0)//compara hora com a fornecida pelo usuario
			{
				printf("\n%s - %s - %s", l->item[i].nome, l->item[i].data, l->item[i].horaLOGIN);
				//imprime os dados
			}
		}

	}

}

void acessoUsuario (TIPOLISTA *l, char *nomeUsuario)//mostra todos os acessos de determinado usuario
{
	int i;

	for(i = 0; i < l->fim; i++)//percorre a lista
	{
		if(strcmp(l->item[i].nome, nomeUsuario) == 0)//compara o nome com o fornecido pelo usuario
			printf("\nNome:%s - %s - %s - %s", l->item[i].nome, l->item[i].horaLOGIN, l->item[i].horaLOGOUT, l->item[i].data);
			//imprime os dados do login 
	}

}

void removeUsuario(TIPOLISTA *l, char *nome, char *datalogin, char *Horas)// um acesso de um usuario da lista
{
	int i, j;

	for(i = l->fim - 1; i >= 0; i--)//percorre a lista de trás para frente
	{
		if(strcmp(l->item[i].nome, nome) == 0)//compara os nome da lista com o fornecido pelo usuario
		{
			if(strcmp(l->item[i].data, datalogin ) == 0)//compara as datas da lista com a fornecida pelo usuario
			{
				if(strcmp(l->item[i].horaLOGIN, Horas ) == 0)//compara as horas da lista com a fornecida pelo usuario
				{
					for(j = i; j < l->fim - 1; j++)// efetua o deslocamento a partir do dados removido
					{
						l->item[j] = l->item[j + 1];

					}
					l->fim--;//diminui a lista
				}
			}
		}
	}

}


int main()
{

	TIPOLISTA l;
	char consultadata[11];
	char consultahora[6];
	char nome[40];
	int opcao;

	InicializaLista(&l);
	ler_Arquivo(&l);


	do
	{
		system("cls");
		printf("1- Imprimir lista");
		printf("\n2- Mostrar nomes dos usuarios cadastrados");
		printf("\n3- Mostrar acesso em determinado dia e apos hora");
		printf("\n4- Mostrar todos os acessos de um determinado usuario");
		printf("\n5- Remover acesso de um usuario");
		printf("\nDigite 0 para sair");
		printf("\n\n");
		scanf("%d", &opcao);


		switch(opcao)
		{
		case 1:
			system("cls");
			imprimeLista(&l);
			getch();
			break;

		case 2:
			system("cls");
			mostrarUsuario(&l);
			getch();
			break;

		case 3:
			fflush(stdin);
			printf("Informe o dia desejado (dd/mm/aaaa): ");
			gets(consultadata);
			printf("\nInforme A hora desejada (hh:mm): ");
			gets(consultahora);
			consultaLogin(&l, consultadata, consultahora );
			getch();
			break;

		case 4:
			printf("Informe o nome do usuario desejado: ");
			gets(nome);
			acessoUsuario(&l, nome);
			getch();
			break;

		case 5:
			fflush(stdin);
			printf("Informe o nome do usuario desejado: ");
			gets(nome);
			printf("\nInforme o dia desejado (dd/mm/aaaa): ");
			gets(consultadata);
			printf("\nInforme A hora desejada (hh:mm): ");
			gets(consultahora);
			removeUsuario(&l, nome, consultadata, consultahora);
			getch();
		}
	}
	while(opcao != 0);

	return 0;
}
