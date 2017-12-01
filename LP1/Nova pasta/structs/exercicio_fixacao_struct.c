#include <stdlib.h>
#include <stdio.h>
#define max 2
typedef struct 
{
	char cpf[11];
	char nome[40];
	char cargo[30];
	float salario;
	
}FUNCIONARIO;


void preenche_func(FUNCIONARIO func[])// pode ou nao por o tamanho do vetor -- FUNCIONARIO func[10]
{
	int i;
	char lixo[2];
	
	for(i=0;i<max;i++)
	{
		printf("\nInforme o nome do funcionario: ");
		gets(func[i].nome);
		
		printf("Infome o cpf: ");
		gets(func[i].cpf);
		
		printf("Informe o cargo: ");
		gets(func[i].cargo);
		
		printf("Informe o salario:R$ ");
		scanf("%f",&func[i].salario);
		
		gets(lixo);
	}
	
}

void imprime_func (FUNCIONARIO func[], char cpf_opc[] )
{
	int i;
	for(i=0;i<max;i++)
	{
		if(strcmp (func[i].cpf, cpf_opc)==0)
			break;
	}
	printf("%s %s %s R$%f", func[i].nome, func[i].cpf, func[i].cargo, func[i].salario);
}

int main(void)
{	
	char cpf_opc[11];
	FUNCIONARIO func[10];
	preenche_func(func);
	
	printf("\nInforme o cpf do funcionario que deseja imprimir: ");
	gets(cpf_opc);
	
	imprime_func(func, cpf_opc);
	return 0;
}