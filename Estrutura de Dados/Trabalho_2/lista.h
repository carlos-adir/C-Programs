// Carlos Adir Ely Murussi Leite
// 150121059

#ifndef LISTA
#define LISTA

#include "professor.h"



struct lista_professores
{
	professor prof;
	struct lista_professores *next;
};
typedef struct lista_professores l_prof;

bool insert(professor *individuo, l_prof **lista);
void free_lista(l_prof **lista);

#endif