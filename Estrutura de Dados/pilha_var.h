#include <stdio.h>
#include <string.h>

#define SIZE_NOME 6

struct var
{
	DATA info;
	char nome[SIZE_NOME]; /* Tamanho da variavel de no maximo 5 caracteres */
	struct var *prox;
};
typedef struct var PILHA_VAR;

void imprime_VAR(PILHA_VAR *aux)
{
	int i, tamanho = strlen(aux->nome);
	printf("%s", aux->nome);
	for(i = 0; i<SIZE_NOME-tamanho+1; i++)
		putchar(' ');
	printf("= ");
	imprime_DATA(aux->info);
}


PILHA_VAR ** create_PILHA_VAR()
{
	PILHA_VAR **v;
	v = (PILHA_VAR **) malloc(sizeof(PILHA_VAR *));
	if(v != NULL)
		*v = NULL;
	return v;
}

PILHA_VAR *get_var(char *str) /* Retorna nulo caso o formato nao seja: "$nome_var = $value" */
{
	int i = 0;
	char name[6];
	double w;
	PILHA_VAR *aux;
	while(*(str+i) != '=' && *(str+i) != '\0')
		i++;
	if(*(str+i) == '\0') /* Indica que na verdade e uma entrada padrao e nao e para criar variavel */
		return NULL;
	i++;
	while(*(str+i) != '=' && *(str+i) != '\0')
		i++;
	if(*(str+i) == '=') /* Isso garante que haja somente um igual */
		return NULL;
	i = 0;
	while(*(str+i) != '=')
		i++;
	if(i > 6) /* Isso garante que o nome da variavel seja menor ou igual a 5 */
		return NULL;
	i = sscanf(str, "%s = %lf", name, &w); /* Isso so funciona porque DATA e o mesmo que inteiro */
	if(i != 2)
		return NULL;
	aux = (PILHA_VAR *) malloc(sizeof(PILHA_VAR));
	if(aux == NULL) /* Alocacao de memoria nao deu certo */
		return NULL;
	strcpy(aux->nome, name);
	aux->info = create_DATA(w);
	return aux;

}
int size_PILHA_VAR(PILHA_VAR **v) /* Retorna a quantidade de elementos da pilha */
{
	PILHA_VAR *aux;
	int size = 0;
	if(v == NULL)	/* Pilha não existe */
		return -1;
	aux = *v;
	while(aux != NULL)
	{
		size += 1;
		aux = aux->prox;
	}
	return size;
}
void imprime_PILHA_VAR(PILHA_VAR **v)
{
	int i, j, tamanho, max = 0;
	PILHA_VAR *aux;
	tamanho = size_PILHA_VAR(v);
	if(tamanho < 9)
		max = 9 - tamanho;
	else
		tamanho = 9;
	for(i = 0; i < max; i++)
		printf("%d: \n", 9-i);
	for(i = tamanho; i > 0; i--)
	{
		printf("%d: ", i);
		aux = *v;
		for(j = 0; j < i-1; j++)
			aux = aux->prox;
		imprime_VAR(aux);
		printf("\n");
	}
}

int append_PILHA_VAR(PILHA_VAR *novo, PILHA_VAR **v)
{
	if(v == NULL) /* Pilha nao foi iniciada */
	{
		if(novo != NULL) /* Se a memoria para auxiliar foi alocada, desalocamos pois nao temos onde colocar */
			free(novo); 
		return -1;
	}
	if(novo == NULL) /* Nao foi possivel alocar o elemento */
		return 0;
	novo->prox 	= *v;
	*v 			= novo;
	return 1;
}

PILHA_VAR *remove_PILHA_VAR(PILHA_VAR **v) /* Retorna o ultimo elemento e remove da pilha caso possivel.
							Caso não seja possivel, retorna NULL */
{
	PILHA_VAR *aux;
	if(v == NULL)
		return NULL;
	if(*v == NULL)
		return NULL;
	aux = *v;
	*v  = (*v)->prox;
	return aux;
}

int libera_PILHA_VAR(PILHA_VAR **l)
{
	PILHA_VAR *aux;
	if(l == NULL)
		return 0;
	while(*l != NULL){
		aux = remove_PILHA_VAR(l);
		free(aux);
	}
	free(l);
	return 1;
}