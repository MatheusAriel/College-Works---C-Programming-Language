#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define max 10


//Matheus Ariel de Souza 140211-1
//Victor Akira Okuno Bueno 140198-x
// Exercicio 2

typedef struct		//estrutura da lista
{
	int item[max];
	int inicio, fim;
} lista;

typedef struct		//estrutura para função geraL2Registro(exercicio g)
{
	int elem;
	int count;
} ELEMENTO;

typedef struct				//estrutura para a lista de geraL2Registro
{
	ELEMENTO item[max];
	int inicio, fim;
} listaExtra;


void inicializar_lista(lista *pl)
{
	pl->inicio = 0;
	pl->fim = 0;
}

int verificar_vazia(lista *l)
{
	if(l->fim == 0)
		return 1;
	else
		return 0;
}

int inserir(lista *l, int pos, int elem)
{
	int i;
	if(verificar_vazia(l))
	{
		l->item[l->fim] = elem; // indica posicao 0, pq fim foi inicializado com 0 !
		l->fim++;
		return 1;
	}
	else if (l->fim == max || pos > l->fim ) return 0; // se a posicao é valida ou se há espaço na lista !
	else if ((pos == l->fim))		
	{								//incluir o elemento no fim da lista
		l->item[l->fim] = elem;
		l->fim++;
		return 1;
	}
	else
	{												//incluir elemento no meio da lista com deslocamento
		for(i = l->fim ; i > pos; i--)
			l->item[i] = l->item[i - 1];
		l->item[pos] = elem;
		l->fim++;
		return 1;
	}
}



int remover (lista *l, int pos, int *elem)
{
	int aux;
	if(!verificar_vazia(l) && pos < l->fim)
	{
		*elem = l->item[pos];						//para guardar o elemento eliminado
		for(aux = pos; aux < l->fim; aux++)
			l->item[aux] = l->item[aux + 1];		//remoção com deslocamento
		l->fim--;									//diminui lista
		return 1;
	}
	else return 0;
}


void imprimir (lista *l)
{
	int i;
	for(i = 0; i < l->fim; i++)
		printf("%d ", l->item[i]);
	printf("\n");
}

int troca_posicao(lista *l, int pos1, int pos2)			//exercicio anterior na sala de aula
{

	int elem;

	if(pos1 < l->fim && pos2 < l->fim && pos1 != pos2)		//verificações neceçarias para fazer a troca
	{
		remover(l, pos1, &elem);					//remove posição 1
		if(pos2 < pos1)
		{
			inserir(l, pos2, elem);					//insere na posição 2 se posição 2 for menor q posição 1

		}
		else
		{
			inserir(l, pos2 - 1, elem);				//e se pos2 for maior que pos1 inserirno elemento anterior por causa da remoção feita
		}
		return 1;
	}
	else
	{
		return 0;
	}
}


int inserir_NC(lista *l, int item, int pos, int nrcopias)	//inserção de n copias a partir de uma posição manualmente
{

	int i = 0;
	int aux;
	if (verificar_vazia(l))
	{
		while(nrcopias > i && l->fim < max)
		{
			l->item[l->fim] = item;
			i++;
			l->fim++;
		}
		return 1;
	}
	if(l->fim == max || pos > l->fim)
	{
		return 0;
	}
	else
	{
		i = 0;
		while(i < nrcopias && l->fim < max && max - l->fim < nrcopias) 
		{
			for (aux = l->fim; aux > pos; aux--)
			{
				l->item[aux] = l->item[aux - 1];
			}
			l->fim++;
			i++;
			return 1;
		}
		return 0;
	}
}

int remove_NC(lista *l, int pos, int qtd)		//remoção de n elementos a partir de uma posição
{

	int aux;
	int i;

	if(pos < l->fim && pos + qtd - 1 < l->fim)
	{
		if(pos + qtd < l->fim)
		{
			for(i = pos; i < pos + qtd; i++)
			{
				if(i + qtd >= l->fim)break;
				l->item[i] = l->item[i + qtd];
			}
		}
		l->fim = l->fim - qtd;
		return 1;
	}
	else
	{
		return 0;
	}
}

int verificaOrdem(lista *l)
{
	int i, asc = 1, desc = 1;

	for(i = 0; i < l->fim - 1; i++)
	{
		if(l->item[i] > l->item[i + 1])	//verifica par a par
		{
			asc = 0;	// se o próximo de um item não for em ordem crescente asc =0
		}
		if(l->item[i] < l->item[i + 1])	//verifica par a par
		{
			desc = 0;	//se o próximo de um item não for em ordem decrescente desc =0
		}
	}
	if(asc != 0 )	//retorna 1 se for crescente
		return 1;
	if(desc != 0)
		return -1;	//retorna -1 para decrecente
	else
	{
		return 0;
	}
}

int copiaListas(lista *l, lista *l2)		//copia de l em l2
{
	int i;
	inicializar_lista(&l2);

	for(i = 0; i < l->fim; i++)		
	{
		l2->item[i] = l->item[i];
	}
	l2->fim = l->fim;
	return 1;
}



int copiaNaoRepitidas(lista *l, lista *l2)		//copia somente nao repitidos
{
	int i, j;
	int existe;
	
	for(i = 0; i < l->fim; i++)		//percorre a primeira lista
	{
		existe = 0;
		for(j = 0; j < l2->fim; j++)	//percorre a segunda lista
		{
			if(l->item[i] == l2->item[j]) 	//verifica se algum item da lista 1 esta na lista 2, se existe
				existe = 1;
		}
		if(existe == 0)
		{
			inserir(l2, l2->fim, l->item[i]);	//se não existe elementos iguais ele insere
		}
	}
}

int copiaListasInvertida(lista *l, lista *l2)		//copia em l2 invertida
{
	int i;

	for(i = 0; i < l->fim; i++)
	{
		l2->item[l->fim - i - 1] = l->item[i]; 	//colocaitem de L em L2 começando no indice final de l
	}
	l2->fim = l->fim;
	return 1;
}

int copiaListasInvertidaListaUnica(lista *l)		//invertidas na propria lista
{
	int i, aux;

	for(i = 0; i < l->fim / 2; i++)
	{
		aux = l->item[i]; 	//armazenando os valores de item no aux
		l->item[i] = l->item[l->fim - i - 1]; 	//altera os valores até a metade da lista para os valores de tras para frente
		l->item[l->fim - i - 1] = aux;	 //os valores auxiliares são atribuidos de tars para frente até a metade
		//OBS: os valores impares o item do meio nao se altera
	}
}

int IntercalarL1L2(lista *l, lista *l2, lista *l3)
{
	int pl = 0, pl2 = 0;		//contadores para as duas listas
	int ordem;
	if(verificaOrdem(l) == verificaOrdem(l2) && verificaOrdem(l) != 0)		//verificar se duas listas estão em mesmo sentido
	{
		if(l->fim + l2->fim <= max)	
		{
			ordem = verificaOrdem(l);	//se estão em mesma ordem e as duas listas coubem na nova lista

			while(pl < l->fim || pl2 < l2->fim)
			{
				if(ordem > 0)				//para sentido crecente
				{
					if(pl < l ->fim && l->item[pl] < l2->item[pl2] || pl2 == l2->fim)	//para item de l1 menor que item de l2
					{
						inserir(l3, l3->fim, l->item[pl]);		//inserindo item de l1 em l3
						pl++;
					}
					else		//para item de l2 menor q item de l1
					{
						inserir(l3, l3->fim, l2->item[pl2]);		//inserindo item de l2 em l3
						pl2++;
					}
				}
				else					//para sentido decrecente
				{
					if(pl < l ->fim && l->item[pl] > l2->item[pl2] || pl2 == l2->fim)
					{
						inserir(l3, l3->fim, l->item[pl]);
						pl++;
					}
					else
					{
						inserir(l3, l3->fim, l2->item[pl2]);
						pl2++;
					}
				}

			}
			return 1;
		}
	}
	return 0;
}

int geraL2Registro(listaExtra *le, lista *l)		//mostrar lista com numero de vezer de um repitido
{
	int i, j;
	le->fim = 0;
	le->inicio = 0;

	for(i = 0; i < l->fim; i++)
	{
		for(j = 0; j < le->fim; j++)
		{
			if(le->item[j].elem==l->item[i])	//manter rotina enquanto nao haver elemento de lista igual
				break;
		}
		if(j<le->fim)		//parando no indice j atual, se for menor que o fim da lista extra
		{
			le->item[j].count++;	//incrementa o contador de itens semelhantes
		}
		else
		{
			le->item[le->fim].elem= l->item[i];		//se nao, recebe o elemento do indice i
			le->item[le->fim].count=1;				//e define o contador desse item 1
			le->fim++;
		}
	}
	return 1;

}

void imprimeListaLe(listaExtra *le)		//função para imprimir lista de geraL2Registro
{
	
	int i;
	for(i=0;i<le->fim ;i++)
	{
		printf("%dx%d ",le->item[i].elem, le->item[i].count);
	}
	printf("\n");
	
	
}


main()
{
	int elem, pos, aux, pos1, pos2;
	lista l;
	lista l2;
	lista l3;
	listaExtra le;
	int opc, nrcopias, qtd;
	inicializar_lista(&l);
	inicializar_lista(&l2);
	inicializar_lista(&l3);

	do
	{
		system("cls");
		printf("valor de fim: %d\n\n", l.fim);
		printf("1- Insercao;\n"
			   "2- Imprimir;\n"
			   "3- Remover;\n"
			   "4- Mudar Poiscao;\n"
			   "5- Inserir Copias;\n"
			   "6- Remover n itens;\n"
			   "7- Verificar se lista esta ordenada;\n"
			   "8- Copiar em nova lista;\n"
			   "9- Copiar em nova lista eliminando repetidos;\n"
			   "10- Inverter copia de lista;\n"
			   "11- Inverter na propria lista;\n"
			   "12- Intercalar duas listas em uma nova (para listas de mesma ordem);\n"
			   "13- Gerar lista com o numero de vezes de repeticao de item;\n"
			   "\nInsira a opcao desejada: ");
		scanf("%d", &opc);
		switch(opc)
		{
		case 1:
			system("cls");
			printf("Insira o numero desejado: ");
			scanf("%d", &elem);
			printf("Insira a posicao desejada: ");
			scanf("%d", &pos);
			if(inserir(&l, pos, elem)) printf("A insercao foi possivel !\n");
			else printf("A insercao n foi possivel !\n");
			getch();
			break;
		
		case 2:
			system("cls");
			imprimir(&l);
			getch();
			break;
		
		case 3:
			system("cls");
			printf("Insire a posicao a ser removida: ");
			scanf("%d", &pos);
			if(remover(&l, pos, &aux))
				printf("O numero %d foi removido !", aux);
			else printf("Nao foi possivel remover !\n");
			getch();
			break;
		
		case 4:
			system("cls");
			printf("Insira a posição a ser trocada: ");
			scanf("%d", &pos1);
			printf("\nInsira a posição a ser armazenada: ");
			scanf("%d", &pos2);
			if(	troca_posicao(&l, pos1, pos2))
			{
				printf("A posição foi alterada com sucesso");
			}
			else
			{
				printf("Erro!!!");
			}
			getch();
			break;
		
		case 5:
			system("cls");
			printf("Insira o numero de copias: ");
			scanf("%d", &nrcopias);
			printf("\nQual o elemento: ");
			scanf("%d", &elem);
			printf("Qual a posicao inicial: ");
			scanf("%d", &pos);
			if(inserir_NC(&l, elem, pos, nrcopias))
			{
				printf("Copias inseridas !!!");
			}
			else
			{
				printf("Erro!!!");

			}
			getch();
			break;
		
		case 6:
			system("cls");
			printf("Insira a quantidade a ser removida: ");
			scanf("%d", &qtd);
			printf("Insira qual a posicao inicial a ser removida: ");
			scanf("%d", &pos);
			if(remove_NC(&l, pos, qtd))
			{
				printf("Ok!!! Foram removidos: %d", qtd);
			}
			else
				printf("Erro!!!");
			getch();
			break;
		
		case 7:
			system("cls");
			if(verificaOrdem(&l)>0)
				printf("Lista em ordem crescente\n");
			else if(verificaOrdem(&l)<0)
				printf("Lista em ordem decrescente\n");
			else 
				printf("Lista nao ordenada\n");
			getch();
			break;
		
		case 8:
			system("cls");
			if(copiaListas(&l,&l2))
			{
				printf("Lista 1: "); imprimir(&l);
				printf("Lista 2: "); imprimir(&l2);
			}
			else
				printf("Nao foi possivel fazer a copia");
			getch();
			break;
		
		case 9:
			system("cls");
			if(copiaNaoRepitidas(&l,&l2))
			{
				printf("Lista 1: "); imprimir(&l);
				printf("Lista 2: "); imprimir(&l2);
			}
			else
				printf("Nao foi possivel fazer a copia");
			getch();
			break;
		
		case 10:
			system("cls");
			if(copiaListasInvertida(&l,&l2))
			{
				printf("Lista 1: "); imprimir(&l);
				printf("Lista 2: "); imprimir(&l2);
			}
			else
				printf("Nao foi possivel fazer a copia");
			getch();
			break;
		
		case 11:
			system("cls");
			printf("Lista 1: "); imprimir(&l);
			if(copiaListasInvertidaListaUnica(&l))
			{
				printf("Lista 1 atualizada: "); imprimir(&l);
			}
			else
				printf("Nao foi possivel fazer a alteracao");
			getch();
			break;
		
		case 12:
			system("cls");
			if(IntercalarL1L2(&l,&l2,&l3))
			{
				printf("Lista 1: "); imprimir(&l);
				printf("Lista 2: "); imprimir(&l2);
				printf("Lista 3: "); imprimir(&l3);
			}
			else
				printf("Nao foi possivel fazer a copia - listas em sentido diferente");
			getch();
			break;
		
		case 13:
			system("cls");
			if(geraL2Registro(&le,&l))
			{
				printf("Lista(elementoxqtd): "); imprimeListaLe(&le);
			}
			else
				printf("Nao foi possivel gerar nova lista");
			getch();
		}
	}
	while(opc != 0);
}


