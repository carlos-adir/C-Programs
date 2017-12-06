// Carlos Adir Ely Murussi Leite
// 150121059

#include "lista.h"

bool insert(professor *individuo, l_prof **lista)
{
	l_prof *novo;
	if(individuo == NULL)
		return FAIL;
	if(lista == NULL) // Lista nao inicializada
		return FAIL;
	novo = (l_prof *) malloc(sizeof(l_prof));
	if(novo == NULL)
		return FAIL;
	//printf("Foi feito um malloc no insert do professor: %s - %p\n", individuo->name, novo);
	novo->prof.name = individuo->name;
	novo->prof.t = individuo->t;
	novo->prof.q = individuo->q;
	novo->prof.ID = individuo->ID;
	novo->prof.list = individuo->list;

	novo->next = *lista;
	*lista = novo;

	return SUCESS;
}

void free_lista(l_prof **lista)
{
	l_prof *aux;
	if(lista == NULL)
	{
		return;
	}
	aux = *lista;
	while(aux != NULL)
	{
		aux = aux->next;
		free_professor(&((*lista)->prof));
		//printf("Foi dado um free no elemento da lista: %p\n", *lista);
		free(*lista);
		*lista = aux;
	}
	//printf("Foi dado um free na lista l_prof: %p\n", lista);
	free(lista);


}