// Carlos Adir Ely Murussi Leite
// 150121059

#include "input.h"



bool get_data(const char *arq_name, l_prof ***college) // Return SUCESS or FAIL. It only depends if the program get the data correctly
{
	FILE *arq;
	l_prof **lista; // Inseriremos no inicio da lista, assim como a pilha
	professor professor_atual;
	info *nova_info;
	bool rate;

	int ID, lastID = 0;
	char name[300];

	//error = fopen("error.txt", "w");

	arq = fopen(arq_name, "r");
	if(arq == NULL) // Nao conseguiu abrir o arquivo
	{
		printf("Falha na abertura do arquivo. Talvez não exista\n");
		return FAIL;
	}
	// Para limpar o arquivo
	//while(fgetc(arq) != '\n');
	lista = (l_prof **) malloc(sizeof(l_prof *));
	//printf("Foi feito um malloc no get_data para todas a lista de professores. %p\n", lista);
	if(lista == NULL) // Nao conseguiu alocar a memoria
	{
		printf("Falha na alocacao de memoria para a lista.\n");
		return FAIL;
	}
	*lista = NULL; // Por enquanto nao ha nenhum elemento

	*college = lista;
	
	// Assumiremos que tem mais de uma linha
	rate = get_line(arq, name, &ID, &nova_info);
	if(rate == FAIL) // Nao conseguiu ler corretamente, ou mesmo alocar memoria para nova_info
	{
		free_lista(lista);
		//free(nova_info); Nao e necessario fazer isso, pois rate e falha se e somente se nova_info for nulo
		return FAIL;
	}
	lastID = ID;
	professor_atual = new_professor(ID, name);
	rate = add_info(nova_info, &professor_atual); // Trata o caso em que nao foi possivel realocar a memoria necessaria
	if(rate == FAIL) // Professor atual e NULL, ou nova info e NULL(improvavel, pois e tratado no get_line)
	{
		free_lista(lista);
		free_professor(&professor_atual);
	}
	while(!feof(arq))
	{
		//printf("No loop\n");
		rate = get_line(arq, name, &ID, &nova_info);
		if(rate == FAIL) // Nao conseguiu ler corretamente, ou mesmo alocar memoria para nova_info
		{
			free_lista(lista);
			//free(nova_info); Nao e necessario fazer isso, pois rate e falha se e somente se nova_info for nulo
			return FAIL;
		}
		if(ID != lastID)
		{
			rate = insert(&professor_atual, lista); // O antigo professor
			if(rate == FAIL)
			{
				free_lista(lista);
				free_professor(&professor_atual);
				free_info(nova_info);		
			}
			professor_atual = new_professor(ID, name);
			if(professor_atual.ID == 0) // Ou seja, nao conseguiu alocar a memoria
			{
				free_lista(lista);
				free_info(nova_info);
				return FAIL;
			}
			lastID = ID;
		}
		rate = add_info(nova_info, &professor_atual); // Trata o caso em que nao foi possivel realocar a memoria necessaria
		if(rate == FAIL) // Professor atual e NULL, ou nova info e NULL(improvavel, pois e tratado no get_line)
		{
			//fprintf(error, "Houve problema na hora de colocar a nova informacao para o professor\n");
			free_lista(lista);
			free_info(nova_info);
			free_professor(&professor_atual);
			return FAIL;
		}
	}
	
	//fprintf(error, "Chegou no fim do arquivo\n");
	rate = insert(&professor_atual, lista); // O antigo professor
	if(rate == FAIL)
	{
		//fprintf(error, "Problema na hora de inserir professor na lista!\n");
		free_lista(lista);
		free_professor(&professor_atual);
		//free(nova_info);
		return FAIL;		
	}
	return SUCESS;
	
	fclose(arq);
	//fclose(error);
}