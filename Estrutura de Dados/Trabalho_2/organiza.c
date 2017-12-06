// Carlos Adir Ely Murussi Leite
// 150121059

#include <unistd.h>
#include "organiza.h"

typedef struct
{
	unsigned short int plista;
	unsigned short int pinfo;
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

bool alloca_tres(data ***postura, data ***atuacao, data ***autoava, const int tamanho)
{
	*postura = aloca_memoria(tamanho);
	if(*postura == NULL)
		return FAIL;
	*atuacao = aloca_memoria(tamanho);
	if(*atuacao == NULL)
	{
		free_data(postura, tamanho);
		return FAIL;
	}
	*autoava = aloca_memoria(tamanho);
	if(*autoava == NULL)
	{
		free_data(postura, tamanho);
		free_data(atuacao, tamanho);
		return FAIL;
	}
	return SUCESS;
}
void grava_data(FILE *f, data **n, const int tamanho)
{
	int i;
	for(i = 0; i < tamanho; i++)
	{
		fwrite(&(*(n+i))->plista, sizeof(unsigned short int), 1, f);
		fwrite(&(*(n+i))->pinfo,  sizeof(unsigned short int), 1, f);
	}
}

void heapsort_(data **a, const int tamanho)
{
	int n = tamanho;
	int i = n / 2, pai, filho;
	data *t;
	while(1)
	{
		if (i > 0)
		{
			i--;
			t = *(a+i);
		}
		else
		{
			n--;
			if (n == 0)
				return;
			t = *(a+n);
			*(a+n) = *(a+0);
			*(a+0) = t;
		}
		pai = i;
		filho = i * 2 + 1;
		while (filho < n)
		{
			if (filho + 1 < n)
				if ((*(a+filho + 1))->value > (*(a+filho))->value)
					filho++;
			if ((*(a+filho))->value > t->value)
			{
				*(a+pai) = *(a+filho);
				pai = filho;
				filho = pai * 2 + 1;
			}
			else
				break;
		}
		*(a+pai) = t;
	}
}

bool organize(l_prof **college, const char *orga)
{
	FILE *f = fopen(orga, "wb");
	l_prof **lista;
	l_prof *aux;
	lista = college;
	int i, j, k, tamanho = 0;

	data **postura;
	data **atuacao;
	data **autoava;

	if(f == NULL)
		return FAIL;
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
	//printf("%d\n", tamanho);
	// Para alocar as informacoes
	if(alloca_tres(&postura, &atuacao, &autoava, tamanho) == FAIL)
		return FAIL;
	
	// Preencher os vetores alocados dinamicamente
	aux = *lista;
	i = 0;
	k = 0;
	while(aux != NULL)
	{
		for(j = 0; j < aux->prof.q; j++)
		{
			//printf("h");
			(*(postura+k))->plista = i;
			//printf("u");
			(*(postura+k))->pinfo = j;
			//printf("e");
			(*(postura+k))->value = (*(aux->prof.list+j))->postura.med;
			//printf("h");
			(*(atuacao+k))->plista = i;
			//printf("u");
			(*(atuacao+k))->pinfo = j;
			//printf("e");
			(*(atuacao+k))->value = (*(aux->prof.list+j))->atuacao.med;
			//usleep(10000);
			//printf("h");
			(*(autoava+k))->plista = i;
			//printf("u");
			(*(autoava+k))->pinfo = j;
			//printf("e");
			(*(autoava+k))->value = (*(aux->prof.list+j))->autoava.med;
			//printf("\n");
			k += 1;
		}
		aux = aux->next;
		i += 1;
	}

	heapsort_(postura, tamanho);
	heapsort_(atuacao, tamanho);
	heapsort_(autoava, tamanho);
	fwrite(&tamanho,sizeof(int),1,f);
	grava_data(f, postura, tamanho);
	grava_data(f, atuacao, tamanho);
	grava_data(f, autoava, tamanho);
	fclose(f);
	free_data(&postura, tamanho);
	free_data(&atuacao, tamanho);
	free_data(&autoava, tamanho);

	return SUCESS;
}


bool get_organized(FILE *f, l_prof **lista, raiz ***n, const int tamanho)
{
	l_prof *aux;
	professor *subs[tamanho];
	unsigned short int x[tamanho], y[tamanho];
	int i, j;
	*n = (raiz **) malloc(sizeof(raiz*));
	if(*n == NULL)
		return FAIL;
	**n = aloca_arvore(tamanho);
	if(**n == NULL)
	{
		free(*n);
		return FAIL;
	}
	for(i = 0; i < tamanho; i++)
	{
		fread(x+i, sizeof(unsigned short int), 1, f);
		fread(y+i, sizeof(unsigned short int), 1, f);
	}
	aux = *lista;
	i   = 0;
	while(aux != NULL)
	{
		for(j = 0; j < tamanho; j++)
			if(x[j] == i)
				subs[j] = &(aux->prof);
		i += 1;
		aux = aux->next;
	}
	i = 0;
	poe_elementos(subs, y, &i, **n);
	return SUCESS;
}

bool get_3organized(const char *orga, l_prof **lista, raiz ***postura, raiz ***atuacao, raiz ***autoava)
{
	FILE *f = fopen(orga, "rb");
	bool rate;
	int tamanho;
	if(f == NULL)
	{
		organize(lista, orga);
		f = fopen(orga, "rb");
		if(f == NULL)
			return FAIL;
	}
	fread(&tamanho, sizeof(int), 1, f);
	rate = get_organized(f, lista, postura, tamanho);
	if(rate == FAIL)
	{
		fclose(f);
		return FAIL;
	}
	rate = get_organized(f, lista, atuacao, tamanho);
	if(rate == FAIL)
	{
		fclose(f);
		free_arvore(**postura);
		return FAIL;
	}
	rate = get_organized(f, lista, autoava, tamanho);
	if(rate == FAIL)
	{
		fclose(f);
		free_arvore(**postura);
		free_arvore(**atuacao);
		return FAIL;
	}
	fclose(f);
	return SUCESS;
}


	/*for(i = 0; i < tamanho; i++)
		printf("P - l: %02d i: %02d v:%.2lf\n", (*(postura+i))->plista, (*(postura+i))->pinfo, (*(postura+i))->value);
	for(i = 0; i < tamanho; i++)
		printf("A - l: %02d i: %02d v:%.2lf\n", (*(atuacao+i))->plista, (*(atuacao+i))->pinfo, (*(atuacao+i))->value);
	for(i = 0; i < tamanho; i++)
		printf("U - l: %02d i: %02d v:%.2lf\n", (*(autoava+i))->plista, (*(autoava+i))->pinfo, (*(autoava+i))->value);*/