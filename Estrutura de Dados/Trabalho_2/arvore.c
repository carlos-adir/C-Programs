// Carlos Adir Ely Murussi Leite
// 150121059

#include "arvore.h"
void free_arvore(raiz *n) // Funcao recursiva
{
	if(n->menor != NULL)
	{
		free_arvore(n->menor);
		n->menor = NULL;
	}
	if(n->maior != NULL)
	{
		free_arvore(n->maior);
		n->maior = NULL;
	}
	free(n);
}

raiz *aloca_arvore(const int tamanho)
{
	raiz *novo;
	int left, right, n;
	n = tamanho-1;
	right = n/2;
	left = n-right;
	novo = (raiz *) malloc(sizeof(raiz));
	if(novo == NULL)
		return NULL;
	if(left > 0)
	{
		novo->menor = aloca_arvore(left);
		if(novo->menor == NULL) // Deu ruim
		{
			free_arvore(novo);
			return NULL;
		}
	}
	else
		novo->menor = NULL;
	if(right > 0)
	{
		novo->maior = aloca_arvore(right);
		if(novo->maior == NULL)
		{
			free_arvore(novo);
			return NULL;
		}
	}
	else
		novo->maior = NULL;
	return novo;
}

void poe_elementos(professor **p, const unsigned short int *y, int *indice, raiz *n)
{
	if(n->menor != NULL)
		poe_elementos(p, y, indice, n->menor);
	n->pos = *(y+*indice);
	n->prof = *(p+*indice);
	n->global = *indice;
	*indice += 1;
	if(n->maior != NULL)
		poe_elementos(p, y, indice, n->maior);
} 

int altura(raiz *n)
{
	int left = 0, right = 0;
	if(n->menor != NULL)
		left = altura(n->menor);
	if(n->maior != NULL)
		right = altura(n->maior);
	return left > right ? left+1 : right+1;
}
int numero_nos(raiz *n)
{
	int left = 0, right = 0;
	if(n->menor != NULL)
		left = numero_nos(n->menor);
	if(n->maior != NULL)
		right = numero_nos(n->maior);
	return left+right+1;
}


double get_sum(raiz *n, const int tipo)
{
	double left = 0, right=0, middle = 0;
	info *aux;
	if(n->menor != NULL)
		left = get_sum(n->menor, tipo);
	if(n->maior != NULL)
		right = get_sum(n->maior, tipo);
	aux = *(n->prof->list+n->pos);
	if(tipo == 0) // postura
		middle = aux->postura.med;
	else if(tipo == 1)
		middle = aux->atuacao.med;
	else if(tipo == 2)
		middle = aux->autoava.med;
	return left+middle+right;
}


//double get_value(info *i, *double func(info *))
//{
//	return func(i);
//}

