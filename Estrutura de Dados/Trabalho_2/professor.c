// Carlos Adir Ely Murussi Leite
// 150121059

#include "professor.h"

professor new_professor(int ID, const char *name)
{
	professor novo;
	int i, tamanho = 0;
	novo.ID = ID;
	// Mede o tamanho da string
	while(*(name+tamanho) != '\0')
		tamanho += 1;
	tamanho += 1;
	novo.q = 0; // Indicando que até o momento ha 0 informacoes sobre turmas e estatisticas

	novo.name = (char *) malloc(tamanho*sizeof(char)); // Aloca somente a quantidade necessaria
	if(novo.name == NULL) // Nao conseguiu alocar a memoria para armazenar o nome
	{
		//free(novo); // Libera a memoria alocada ao novo professor
		novo.t = 0;
		novo.ID = 0;
		//fprintf(error, "Liberou porque nome nao foi alocado.\n");
		return novo;
	}
	novo.list = (info **) malloc(0*sizeof(info *)); // Aloca somente a quantidade necessaria
	novo.t = tamanho;

	// Se chegou aqui, alocou todas as memórias necessarias
	// Agora gravaremos o nome
	for(i = 0; i < tamanho; i++)
		*(novo.name+i) = *(name+i);
	//printf("Foi feito o malloc do professor:  %s\n", name);
	//printf("Foi feito o malloc da lista info: %p\n", novo.list);
	return novo;
}
void free_professor(professor *individuo)
{
	int i;
	//printf("Foi dado um free no nome: %s\n", individuo->name);
	free(individuo->name);
	for(i = 0; i < individuo->q; i++)
	{
		free_info(*(individuo->list+i));
	}
	//printf("Foi feito o free das infos: %p\n", individuo->list);
	free(individuo->list);
}
bool add_info(info *novo, professor *individuo)
{
	info **aux;
	if(novo == NULL)
		return FAIL;
	if(individuo == NULL)
		return FAIL;
	aux = (info **) realloc(individuo->list, (individuo->q+1)*sizeof(info*));
	if(aux == NULL) // Nao conseguiu realocar a memoria
		return FAIL;
	//printf("Foi feito o realoc de %p para %p do professor %s\n", individuo->list, aux, individuo->name);
	individuo->list = aux;
	*(individuo->list+individuo->q) = novo;
	individuo->q += 1;
	return SUCESS;
}