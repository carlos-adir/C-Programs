#include <stdio.h>

struct noh
{
	char c;
	struct noh *prox;
};
typedef struct noh PILHA_CHAR;

PILHA_CHAR ** create_PILHA_CHAR()
{
	PILHA_CHAR **p;
	p = (PILHA_CHAR **) malloc(sizeof(PILHA_CHAR *));
	/* printf("Alocado pilha caracter\n"); DEBUGAR */
	if(p != NULL)
		*p = NULL;
	return p;
}

char vazia_PILHA_CHAR(PILHA_CHAR **p)
{
	if(p == NULL)
		return 2;
	else if(*p == NULL)
		return 1;
	return 0;
}

int append_PILHA_CHAR(char c, PILHA_CHAR **p)
{
	PILHA_CHAR *novo;
	if(p == NULL) /* Pilha nao foi iniciada */
		return -1;
	novo = (PILHA_CHAR *) malloc(sizeof(PILHA_CHAR));
	/* printf("Alocado elemento caracter\n"); DEBUGAR */
	if(novo == NULL) /* Nao foi possivel alocar o elemento */
		return 0;
	novo->prox 	= *p;
	novo->c  	= c;
	*p 			= novo;
	return 1;
}

PILHA_CHAR *remove_PILHA_CHAR(PILHA_CHAR **p) /* Retorna o ultimo elemento e remove da pilha caso possivel.
							Caso não seja possivel, retorna NULL */
{
	PILHA_CHAR *aux;
	if(p == NULL)
		return NULL;
	if(*p == NULL)
		return NULL;
	aux = *p;
	*p  = (*p)->prox;
	return aux;
}

char get_last_PILHA_CHAR(PILHA_CHAR **p)
{
	if(p == NULL)
		return '\0';
	if(*p == NULL)
		return '\0';
	return (**p).c;
}

int libera_PILHA_CHAR(PILHA_CHAR **p)
{
	PILHA_CHAR *aux;
	/* printf("Preparando para liberar pilha caracter!\n"); DEBUGAR */
	if(p == NULL)
		return 0;
	while(*p){
		aux = remove_PILHA_CHAR(p);
		free(aux);
		/* printf("Liberado elemento caracter!\n"); DEBUGAR */
	}
	free(p);
	/*  printf("Liberado pilha caracter!\n"); DEBUGAR */
	return 1;
}

int trade_PILHA_CHAR(PILHA_CHAR **p, PILHA_CHAR **p_aux)
{
	PILHA_CHAR *aux = remove_PILHA_CHAR(p);
	if(aux == NULL)
		return 0;
	aux->prox = *p_aux;
	*p_aux = aux;
	return 1;
}