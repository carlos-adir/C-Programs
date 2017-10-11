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
	if(l != NULL)
		*l = NULL;
	return l;
}

int size_PILHA_NUM(PILHA_NUM **l) /* Retorna a quantidade de elementos da pilha */
{
	PILHA_NUM *aux;
	int size = 0;
	if(l == NULL)	/* Pilha não existe */
		return -1;
	aux = *l;
	while(aux != NULL)
	{
		size += 1;
		aux = aux->prox;
	}
	return size;
}
char at_least_PILHA_NUM(PILHA_NUM **l, int q) /* Retorna se a PILHA_NUM possui pelo menos q elementos,
										 necessário para fazer as operacoes */
{
	PILHA_NUM *aux;
	int i;
	if(l == NULL)
		return 0; /* A lista nao existe, podemos retornar outro valor se quisermos */
	aux = *l;
	for(i = 0; i < q; i++)
	{
		if(aux == NULL)
			return 0; /* Se o ponteiro fica NULL enquanto nao percorreu todos */
		aux = aux->prox;
	}
	return 1;
}

void imprime_PILHA_NUM(PILHA_NUM **l)
{
	int i, j, tamanho, max = 0;
	PILHA_NUM *aux;
	tamanho = size_PILHA_NUM(l);
	if(tamanho < PILHA_PROF)
		max = PILHA_PROF - tamanho;
	else
		tamanho = PILHA_PROF;
	for(i = 0; i < max; i++)
		printf("%d: \n", PILHA_PROF-i);
	for(i = tamanho; i > 0; i--)
	{
		printf("%d: ", i);
		aux = *l;
		for(j = 0; j < i-1; j++)
			aux = aux->prox;
		imprime_DATA(aux->info);
		printf("\n");
	}
}

int append_PILHA_NUM(DATA t, PILHA_NUM **l)
{
	PILHA_NUM *novo;
	if(l == NULL) /* Pilha nao foi iniciada */
		return -1;
	novo = (PILHA_NUM *) malloc(sizeof(PILHA_NUM));
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
	if(l == NULL)
		return 0;
	while(*l){
		aux = remove_PILHA_NUM(l);
		free(aux);
	}
	free(l);
	return 1;
}

void abre_toda_lista_numerica(PILHA_NUM **l)
{
	int i, j, tamanho, max = 0, profundidade=0;
	KEY k;
	PILHA_NUM *begin, *aux;
	tamanho = size_PILHA_NUM(l);
	max = tamanho > PILHA_PROF ? PILHA_PROF : tamanho;
	while(1)
	{
		begin = *l;
		for(i = 0; i < profundidade; i++)
			begin = begin->prox;
		system("clear");
		printf("******************\n");
		printf("* PILHA NUMERICA *\n");
		printf("******************\n");
		/* Algoritmo similar a imprimir_PILHA_NUM */
		for(i = 0; i < max; i++)
		{
			printf("%d: ", profundidade + max-i);
			aux = begin;
			for(j = 0; j < max-i-1; j++)
				aux = aux->prox;
			imprime_DATA(aux->info);
			printf("\n");
		}
		/* Fim do algoritmo */
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
}