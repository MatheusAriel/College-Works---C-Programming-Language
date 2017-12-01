#include <stdio.h>
#include <stdlib.h>
#define max 100

void calc_votos(int cod_candidato[], int votos[])
{
	FILE *p;
	int i;
	int voto;

	

	p = fopen("votos.txt", "r");
	if(p == NULL)
	{
		printf("Erro na abertura do arquivo");
		system("pause");
		exit(0);
	}
	while(!feof(p))
	{
		fscanf(p, "%d", &voto);

		printf("%d\n", voto);
		for(i = 0; i < 5; i++)
			if(cod_candidato[i] == voto)
				votos[i]++;

	}
	
	fclose(p);
}

int soma_votos_nulos(int votos[])
{
	int i;
	int votos_nulos = max;
	for(i = 0; i < 5; i++)
	{
		votos_nulos = votos_nulos - votos[i];

	}
	return votos_nulos;
	
}

int soma_cand_mais_votado(int cod_candidatos[], int votos[])
{
	int i;
	int maior = 0;
	int vencedor;
	for(i = 0; i < 5; i++)
	{
		if(maior < votos[i])
		{
			maior = votos[i];
			vencedor = i;
		}
	}
	return vencedor;
	
}

int cand_menos_votado(int cod_candidato[], int votos[])
{
	int i;
	int menor = 900;
	int perdedor;
	for(i = 0; i < 5; i++)
	{
		if(menor > votos[i])
		{
			menor = votos[i];
			perdedor =i;
		}

	}
	return perdedor;
	
}

int main(void)
{
	int cod_candidato[5] = {100, 200, 300, 400, 500};
	int votos[5] = {0, 0, 0, 0, 0};
	int i;
	int cmenosv;
	int cmaisv;
	

	calc_votos(cod_candidato, votos);
	for(i = 0; i < 5; i++)
		printf("\n %d=%dvotos\n", cod_candidato[i], votos[i]);
	
	printf("\nTotal de votos nulos: %d\n", soma_votos_nulos(votos));
	
	cmaisv =	soma_cand_mais_votado(cod_candidato, votos);
	printf("\nO candidato com mais votos foi: %d com %d votos\n", cod_candidato[cmaisv], votos[cmaisv]);
	
	cmenosv = cand_menos_votado(cod_candidato, votos);	
	printf("\nO candidato com menos voto foi: %d com %d votos\n", cod_candidato[cmenosv], votos[cmenosv]);
	
	system("pause");
}
