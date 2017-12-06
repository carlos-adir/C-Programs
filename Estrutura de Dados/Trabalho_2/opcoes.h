// Carlos Adir Ely Murussi Leite
// 150121059

#ifndef OPCOES
#define OPCOES

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include "entrada.h"

struct conta
{
	professor *prof;
	int vezes;
	struct conta *next;
};
typedef struct conta cont_prof;

void av();
void opcao1(raiz *postura, raiz *atuacao, raiz *autoava);
void opcao2(raiz *postura, raiz *atuacao, raiz *autoava);
void opcao3(l_prof **lista);
void opcao4();
void opcao5();
void opcao6();
void opcao7();

#endif