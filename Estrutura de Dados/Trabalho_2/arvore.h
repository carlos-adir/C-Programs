// Carlos Adir Ely Murussi Leite
// 150121059
#ifndef ARVORE
#define ARVORE

#include "lista.h"

struct no
{
	int global;
	unsigned short int pos;
	professor *prof;
	struct no *menor, *maior;
};
typedef struct no raiz;

void free_arvore(raiz *n);
raiz *aloca_arvore(const int tamanho);
void poe_elementos(professor **p, const unsigned short int *y, int *indice, raiz *n);

// Para a primeira opcao
int altura(raiz *n);
int numero_nos(raiz *n);

// Para segunda opcao
double get_sum(raiz *n, const int t);

double get_postura(info *p);
double get_atuacao(info *p);
double get_autoava(info *p);

#endif