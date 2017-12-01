#include <stdio.h>
#include <stdlib.h>
#define max 100

void calc_votos(int cod_candidato[], int votos[])		//função para ler e acumular os votos
{
	FILE *p;					//ponteiro para abrir arquivo
	int i;
	int voto;

	p = fopen("votos.txt", "r");		//abre arquivo txt em modo leitura
	if(p == NULL)						//procedimento de verificação de erro na abertura do arquivo
	{
		printf("Erro na abertura do arquivo");
		system("pause");
		exit(0);
	}
	while(!feof(p))					//ciclo para ler arquivo até seu final
	{
		fscanf(p, "%d", &voto);		//leitura do voto armazenando em voto

		printf("%d\n", voto);
		for(i = 0; i < 5; i++)			//ciclo para comparar se o item lido em voto é igual ao codigo do candidato
			if(cod_candidato[i] == voto)
				votos[i]++;				//acumula votos para cada candidato

	}
	
	fclose(p);
}

int soma_votos_nulos(int votos[])			//função para retornar soma de votos nulos
{
	int i;
	int votos_nulos = max;				//determina o valor maximo de votos para os nulos
	for(i = 0; i < 5; i++)
	{
		votos_nulos = votos_nulos - votos[i];		//decrementa do maximo de votos todos os votos computados para cada candidato
	}
	return votos_nulos;	
	
}

int soma_cand_mais_votado(int cod_candidatos[], int votos[])       //função para retornar o mais votado
{
	int i;
	int maior = 0;
	int vencedor;
	for(i = 0; i < 5; i++)
	{
		if(maior < votos[i])
		{											//se os votos computados do candidato for maior que o maior computado até o instante
			maior = votos[i];						//troca-se o valor do maior
			vencedor = i;							//vencedor recebe o índice do mais votado
		}
	}
	return vencedor;								//retorna o índice do candidato mais votado
	
}

int cand_menos_votado(int cod_candidato[], int votos[])				//função para retornar o menos votado
{
	int i;
	int menor = 900;								//inicializa-se com o maior numero possível
	int perdedor;
	for(i = 0; i < 5; i++)
	{
		if(menor > votos[i])
		{											//se os votos computados do candidato for menor que o menor computado até o instante
			menor = votos[i];						//troca-se o valor de menor
			perdedor =i;							//perdedor recebe ídice do candidato menos votado
		}

	}
	return perdedor;								//retorna o índice do candidato perdedor
	
}

int main(void)
{
	int cod_candidato[5] = {100, 200, 300, 400, 500};			//inicialização dos codigos de cada candidato para comparação
	int votos[5] = {0, 0, 0, 0, 0};								//inicialização das quantidades de votos de cada candidato para acumulação
	int i;
	int cmenosv;								//variavel a receber retorno das funções
	int cmaisv;									//variavel a receber retorno das funções
	
	calc_votos(cod_candidato, votos);							//chama função para ler arquivo com votos e acumular na variavel votos
	for(i = 0; i < 5; i++)										//ciclo para visualização dos votos computados
		printf("\n %d=%dvotos\n", cod_candidato[i], votos[i]);	
	
	printf("\nTotal de votos nulos: %d\n", soma_votos_nulos(votos));	//mostrar a soma feita pela função de votos nulos
	
	cmaisv =	soma_cand_mais_votado(cod_candidato, votos);		//recebe o índice indicado pela função do candidato mais votado
	printf("\nO candidato com mais votos foi: %d com %d votos\n", cod_candidato[cmaisv], votos[cmaisv]);
	
	
	
	cmenosv = cand_menos_votado(cod_candidato, votos);				//recebe o índice indicado pela função do candidato menos votado
	printf("\nO candidato com menos voto foi: %d com %d votos\n", cod_candidato[cmenosv], votos[cmenosv]);
	
	system("pause");
}
