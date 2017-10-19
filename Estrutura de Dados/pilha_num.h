
#define PILHA_PROF 15

struct no
{
	DATA info;
	struct no *prox;
};
typedef struct no PILHA_NUM;

PILHA_NUM ** create_PILHA_NUM()
{
	PILHA_NUM **l;
	l = (PILHA_NUM **) malloc(sizeof(PILHA_NUM *));
	/* printf("Alocado pilha numerica\n"); DEBUGAR */
	if(l != NULL)
		*l = NULL;
	return l;
}
/* Retorna a quantidade de elementos da pilha */
/* int size_PILHA_NUM(PILHA_NUM **l) 
{
	PILHA_NUM *aux;
	int size = 0;
	if(l == NULL)
		return -1;
	aux = *l;
	while(aux != NULL)
	{
		size += 1;
		aux = aux->prox;
	}
	return size;
}*/



int append_PILHA_NUM(DATA t, PILHA_NUM **l)
{
	PILHA_NUM *novo;
	if(l == NULL) /* Pilha nao foi iniciada */
		return 0;
	novo = (PILHA_NUM *) malloc(sizeof(PILHA_NUM));
	/* printf("Alocado elemento numerico\n"); DEBUGAR */
	if(novo == NULL) /* Nao foi possivel alocar o elemento */
		return 0;
	novo->prox 	= *l;
	novo->info  = t;
	*l 			= novo;
	return 1;
}

PILHA_NUM *remove_PILHA_NUM(PILHA_NUM **l) /* Retorna o ultimo elemento e remove da pilha caso possivel.
							Caso não seja possivel, retorna NULL */
{
	PILHA_NUM *aux;
	if(l == NULL)
		return NULL;
	if(*l == NULL)
		return NULL;
	aux = *l;
	*l  = (*l)->prox;
	return aux;
}

int libera_PILHA_NUM(PILHA_NUM **l)
{
	PILHA_NUM *aux;
	/* printf("Preparando para liberar pilha numerica!\n"); DEBUGAR */
	if(l == NULL)
		return 0;
	while(*l){
		aux = remove_PILHA_NUM(l);
		free(aux);
		/* printf("Liberado elemento numerico!\n"); DEBUGAR */
	}
	free(l);
	/* printf("Liberado pilha numerica!\n"); DEBUGAR */
	return 1;
}

/* Retorna 1 caso foi possivel passar um elemento da pilha l para a pilha l_aux */
int trade_PILHA_NUM(PILHA_NUM **l, PILHA_NUM **l_aux)
{
	PILHA_NUM *aux = remove_PILHA_NUM(l);
	if(aux == NULL)
		return 0;
	aux->prox = *l_aux;
	*l_aux = aux;
	return 1;
}

char at_least_PILHA_NUM(PILHA_NUM **l, int q) /* Retorna se a PILHA_NUM possui pelo menos q elementos,
										 necessário para fazer as operacoes */
{
	PILHA_NUM **l_aux;
	int controle = 0;
	int i;
	if(l == NULL)
		return 0; /* A lista nao existe, podemos retornar outro valor se quisermos */
	l_aux = create_PILHA_NUM();
	if(l_aux == NULL)
		return 0;
	for(i = 0; i < q; i++)
	{
		controle = trade_PILHA_NUM(l, l_aux);
		if(!controle)
			break;
	}
	while(trade_PILHA_NUM(l_aux, l));
	free(l_aux);
	/* printf("Liberado pilha numerica auxiliar!\n"); DEBUGAR */
	if(!controle)
		return 0;
	return 1;
}

int imprime_PILHA_NUM(PILHA_NUM **l)
{
	int i, tamanho=0;
	PILHA_NUM **l_aux;
	if(l == NULL)
		return 0;	
	l_aux = create_PILHA_NUM();
	if(l_aux == NULL)
		return 0;
	while(trade_PILHA_NUM(l, l_aux))
	{
		tamanho += 1;
		if(tamanho == PILHA_PROF)
			break;
	}
	for(i = 0; i < PILHA_PROF; i++)
	{
		printf("  %02d: ", PILHA_PROF-i);
		if(i > PILHA_PROF - tamanho-1)
		{
			imprime_DATA((*l_aux)->info);
			trade_PILHA_NUM(l_aux, l);
		}
		printf("\n");
	}
	libera_PILHA_NUM(l_aux);
	return 1;
}

/*
void open_all_PILHA_NUM(PILHA_NUM **l)
{
	int i, tamanho, profundidade=0;
	KEY k;
	while(1)
	{
		system("clear");
		printf("******************\n");
		printf("* PILHA NUMERICA *\n");
		printf("******************\n");
		for(i = 0; i < max; i++)
		{
			printf("%d: ", profundidade + max-i);
			aux = begin;
			for(j = 0; j < max-i-1; j++)
				aux = aux->prox;
			imprime_DATA(aux->info);
			printf("\n");
		}
		printf("\n\nAperte as teclas direcionaisou ESC para sair...");
		k = get_key();
		if(key_is_equal(k, "UP_KEY"))
		{
			if(profundidade+max < tamanho)
				profundidade += 1;
		}
		else if(key_is_equal(k, "DOWN_KEY"))
		{
			if(profundidade > 0)
				profundidade -= 1;
		}
		else if(key_is_equal(k, "ESC"))
			break;
	}
}*/