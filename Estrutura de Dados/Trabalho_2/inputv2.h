#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define SUCESS 1
#define FAIL 0
#define not !
#define and &&
#define or ||

//FILE *error;

typedef unsigned char bool;

typedef struct
{
	double med, dp;
}estatistica;
estatistica new_estatistica(double m, double d)
{
	estatistica novo;
	novo.med = m;
	novo.dp = d;
	return novo;
}


typedef struct
{
	int t; // turma
	int a; // ano
	int p; // periodo
	int q; // quantidade
	estatistica postura;
	estatistica atuacao;
	estatistica autoava;
}info;
info *new_info(int tu, int ano, int pe, int qu, estatistica pos, estatistica atu, estatistica autoa)
{
	info *novo;
	novo = (info *) malloc(sizeof(info));
	if(novo == NULL) // Deu errado a alocacao
		return NULL;
	//printf("Foi feito um malloc para nova_info: %p\n", novo);
	novo->t = tu;
	novo->a = ano;
	novo->p = pe;
	novo->q = qu;
	novo->postura = pos;
	novo->atuacao = atu;
	novo->autoava = autoa;
	return novo;
}
void free_info(info *i)
{
	free(i);
	//printf("Foi dado um free na info: %p\n", i);
}




typedef struct
{
	int ID;
	char *name;
	int q; // quantidade armazenada na lista
	int t; // Tamanho do nome do individuo
	info **list;	
} professor;
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




bool get_line(FILE *arq, char *name, int *ID, info **novo) // Return SUCESS or FAIL
{
	int turma, ano, periodo, quantidade; // Quantidade de alunos(discentes)
	estatistica postura, atuacao, autoavaliacao;
	double pm, pd; // Postura
	double am, ad; // Atuacao
	double um, ud; // Autoavaliacao
	info *nova_info;

	if(arq == NULL)
		return FAIL;
	if(feof(arq))
		return FAIL;
	// Leia as linhas
	fscanf(arq, "%d,%[^,],", ID, name);
	fscanf(arq, "%d,%d,%d,%d,", &turma, &ano, &periodo, &quantidade);
	fscanf(arq, "%lf,%lf,%lf,%lf,%lf,%lf\n", &pm, &pd, &am, &ad, &um, &ud);
	// Transforma para estatistica
	postura = new_estatistica(pm, pd);
	atuacao = new_estatistica(am, ad);
	autoavaliacao = new_estatistica(um, ud);
	
	nova_info = new_info(turma, ano, periodo, quantidade, postura, atuacao, autoavaliacao);

	*novo = nova_info;
	if(nova_info == NULL)
	{
		return FAIL;
	}
	// Agora mudamos o novo
	return SUCESS;
}


struct lista_professores
{
	professor prof;
	struct lista_professores *next;
};
typedef struct lista_professores l_prof;

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
		//fprintf(error, "Falha na abertura do arquivo.\n");
		return FAIL;
	}
	// Para limpar o arquivo
	while(fgetc(arq) != '\n');
	lista = (l_prof **) malloc(sizeof(l_prof *));
	//printf("Foi feito um malloc no get_data para todas a lista de professores. %p\n", lista);
	if(lista == NULL) // Nao conseguiu alocar a memoria
	{
		//fprintf(error, "Falha na alocacao de memoria para college.\n");
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