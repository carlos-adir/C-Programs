#include "inputv2.h"
#include <unistd.h>

typedef struct
{
	int plista;
	int pinfo;
	double value;
}data;

void free_data(data ***n, const int tamanho)
{
	int i;
	for(i = 0; i < tamanho; i++)
		free(*(*n+i));
	free(*n);
	*n = NULL;
}

data **aloca_memoria(const int tamanho)
{
	int i;
	data **n;
	n = (data **) malloc(tamanho*sizeof(data*));
	if(n == NULL)
		return FAIL;
	for(i = 0; i < tamanho; i++)
	{
		*(n+i) = (data *) malloc(sizeof(data));
		if(*(n+i) == NULL)
		{
			free_data(&n, i);	
			return NULL;
		}
	}
	return n;
}

bool alloca_tres(data **postura, data **atuacao, data **autoava, const int tamanho)
{
	postura = aloca_memoria(tamanho);
	if(postura == NULL)
		return FAIL;
	atuacao = aloca_memoria(tamanho);
	if(atuacao == NULL)
	{
		free_data(&postura, tamanho);
		return FAIL;
	}
	autoava = aloca_memoria(tamanho);
	if(autoava == NULL)
	{
		free_data(&postura, tamanho);
		free_data(&atuacao, tamanho);
		return FAIL;
	}
	return SUCESS;
}

void heapsort(data **d, const int tamanho)
{/*
	int n = tamanho;
	int i = n / 2, pai, filho;
	data *t;
	while(1)
	{
		if (i > 0)
		{
			i--;
			t = a[i];
		}
		else
		{
			n--;
			if (n == 0)
				return;
			t = a[n];
			a[n] = a[0];
			a[0] = t;
		}
		pai = i;
		filho = i * 2 + 1;
		while (filho < n)
		{
			if (filho + 1 < n)
				if (a[filho + 1] > a[filho])
					filho++;
			if (a[filho] > t)
			{
				a[pai] = a[filho];
				pai = filho;
				filho = pai * 2 + 1;
			}
			else
				break;
		}
		a[pai] = t;
	}*/
}

bool organize(l_prof **college)
{
	l_prof **lista;
	l_prof *aux;
	lista = college;
	int i, j, k, tamanho = 0;

	data **postura;
	data **atuacao;
	data **autoava;

	if(lista == NULL)
		return FAIL;
	if(*lista == NULL)
		return FAIL;

	// Para pegar a quantidade de valores totais
	aux = *lista;
	while(aux != NULL)
	{
		tamanho += aux->prof.q;
		aux = aux->next;
	}
	printf("%d\n", tamanho);
	// Para alocar as informacoes
	if(alloca_tres(postura, atuacao, autoava, tamanho) == FAIL)
		return FAIL;
	
	// Preencher os vetores alocados dinamicamente
	aux = *lista;
	i = 0;
	k = 0;
	while(aux != NULL)
	{
		printf("%d", i);
		printf(" %d", aux->prof.q);
		printf(" %p\n", aux);
		fflush(stdin);
		sleep(1);
		if(postura != NULL)
		{
			printf("ham\n");
			printf(" postura: %p\n", postura);
		}
		else
		{
			printf(" postura: NULL\n");
		}
		fflush(stdin);
		sleep(1);
		printf(" postura+k: %p\n", *(postura+k));
		for(j = 0; j < aux->prof.q; j++)
		{
			sleep(1);
			printf("h");
			(*(postura+k))->plista = i;
			printf("u");
			(*(postura+k))->pinfo = j;
			printf("e");
			(*(postura+k))->value = (*(aux->prof.list+j))->postura.med;
			usleep(10000);
			printf("h");
			(*(atuacao+k))->plista = i;
			printf("u");
			(*(atuacao+k))->pinfo = j;
			printf("e");
			(*(atuacao+k))->value = (*(aux->prof.list+j))->atuacao.med;
			usleep(10000);
			printf("h");
			(*(autoava+k))->plista = i;
			printf("u");
			(*(autoava+k))->pinfo = j;
			printf("e");
			(*(autoava+k))->value = (*(aux->prof.list+j))->autoava.med;
			usleep(10000);
			k += 1;
		}
		aux = aux->next;
		i += 1;
	}

	heapsort(postura, tamanho);
	heapsort(atuacao, tamanho);
	heapsort(autoava, tamanho);

	for(i = 0; i < tamanho; i++)
		printf("P - l: %02d i: %02d v:%.2lf\n", (*(postura+i))->plista, (*(postura+i))->pinfo, (*(postura+i))->value);
	for(i = 0; i < tamanho; i++)
		printf("A - l: %02d i: %02d v:%.2lf\n", (*(atuacao+i))->plista, (*(atuacao+i))->pinfo, (*(atuacao+i))->value);
	for(i = 0; i < tamanho; i++)
		printf("U - l: %02d i: %02d v:%.2lf\n", (*(autoava+i))->plista, (*(autoava+i))->pinfo, (*(autoava+i))->value);
	free_data(&postura, tamanho);
	free_data(&atuacao, tamanho);
	free_data(&autoava, tamanho);

	return SUCESS;
}

	