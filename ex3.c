#include <stdio.h>
int mdc_recursiva(int a, int b)
{
	printf("\nchamando mdc entre %5d e %5d", a, b);
	if (a % b == 0) return b;
	return mdc_recursiva (b, a % b);
}
/* dados a e b > 0 calcular o mdc entre a e b usando mdc_recursiva */
int main()
{
	int a, b; /* dados */
	/* ler a e b */
	printf("digite os valores de a e b:");
	scanf("%d%d", &a, &b);
	/* calcule e imprima o resultado de fatorial de n */
	printf("\n\nmdc entre %5d e %5d = %5d", a, b, mdc_recursiva(a, b));
}
