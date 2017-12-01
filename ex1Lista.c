#include <stdio.h>
#include <stdlib.h>

float metroPolegada(float valor);
float polegadaMetro(float valor);
float kilometroMilha(float valor);
float milhaKilometro(float valor);
float kilogramaLibra(float valor);
float libraKilograma(float valor);




int main()
{
	int opc;
	float valor = 0, resultado = 0;

	do
	{
		printf("\n\n1 - Converter de metro para polegadas");
		printf("\n2 - Converter de polegada para metro");
		printf("\n3 - Converter de kilometro para milha");
		printf("\n4 - Converter de milha para kilometro");
		printf("\n5 - Converter de kilograma para libra");
		printf("\n6 - Converter de libra para kilograma");

		printf("\n\nEscolha a opcao desejada: ");
		scanf("%d", &opc);

		switch (opc)
		{
		case 1:

			printf("INFORME O VALOR EM METRO(S): ");
			scanf("%f", &valor);
			resultado = metroPolegada(valor);
			printf("METROS: %1.2f - POLEGADAS: %1.2f", valor, resultado);
			break;
		case 2:
			printf("INFORME O VALOR EM POLEGADA(S): ");
			scanf("%f", &valor);
			resultado = polegadaMetro(valor);
			printf("POELGADAS: %1.2f - METROS: %1.2f", valor, resultado);
			break;
		case 3:
			printf("INFORME O VALOR EM KILOMETRO(S): ");
			scanf("%f", &valor);
			resultado = kilometroMilha( valor);
			printf("KILOMETROS: %1.2f - MILHAS: %1.2f", valor, resultado);
			break;
		case 4:
			printf("INFORME O VALOR EM MILHA(S): ");
			scanf("%f", &valor);
			resultado = milhaKilometro( valor);
			printf("MILHAS: %1.2f - KILOMETROS: %1.2f", valor, resultado);
			break;
		case 5:
			printf("INFORME O VALOR EM KILOGRAMA(S): ");
			scanf("%f", &valor);
			resultado = kilogramaLibra( valor);
			printf("KILOGRAMAS: %1.2f - LIBRAS: %1.2f", valor, resultado);
			break;
		case 6:
			printf("INFORME O VALOR EM LIBRA(S): ");
			scanf("%f", &valor);
			resultado = libraKilograma( valor);
			printf("LIBRAS: %1.2f - KILOGRAMAS: %1.2f", valor, resultado);
			break;
		}

	}
	while(opc != 0);



	return 0;
}


float metroPolegada(float valor)
{
	return valor * 39.370;
}

float polegadaMetro(float valor)
{

	return valor / 39.370;
}

float kilometroMilha(float valor)
{

	return valor * 0.62137;
}

float milhaKilometro(float valor)
{

	return valor / 0.62137;
}

float kilogramaLibra(float valor)
{
	return valor * 2,20462;
	
}

float libraKilograma(float valor )
{
	
	return valor / 2.2046;
}






