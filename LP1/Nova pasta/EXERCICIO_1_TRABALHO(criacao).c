#include <stdlib.h>
#include <stdio.h>
#define max 3
typedef struct
{
	char nome[40];
	char data[11];
	char horaLOGIN[6];
	char horaLOGOUT[6];
} LOGIN;

void criaArquivo()
{
	LOGIN usuario;
	int i;
	FILE *arq;

	arq = fopen("LOGIN.bin", "ab");
	if(arq == NULL)
	{
		printf("Erro!!!");
		system("pause");
		exit(0);
	}


	for(i = 0; i < max; i++)
	{
		fflush(stdin);
		printf("\n\nInforme o nome do usuario: ");
		gets(usuario.nome);
		fflush(stdin);

		printf("\nInforme a data do login: ");
		gets(usuario.data);
		fflush(stdin);

		printf("\nInforme a hora de Login: ");
		gets(usuario.horaLOGIN);
		fflush(stdin);

		printf("\nInforme a hora de Logout: ");
		gets(usuario.horaLOGOUT);
		fflush(stdin);

		printf("******************************************");


		fwrite (&usuario, sizeof(LOGIN), 1, arq);
	}
	fclose(arq);

}


void ler_Arquivo()
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
			printf("\nNome Usuario: %s", usuario.nome);
			printf("\nData: %s", usuario.data);
			printf("\nHora Login: %s",usuario.horaLOGIN);
			printf("\nHora Logout: %s", usuario.horaLOGOUT);
			printf("\n\n*********************************************");
			
		}
		fclose(arq);
}




int main(void)
{
	LOGIN usuario;
	//criaArquivo();
	//ler_Arquivo();
	return 0;
}
