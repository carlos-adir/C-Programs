// Carlos Adir Ely Murussi Leite
// 150121059

#ifndef PROFESSOR
#define PROFESSOR

#include "info.h"

typedef struct
{
	int ID;
	char *name;
	int q; // quantidade armazenada na lista
	int t; // Tamanho do nome do individuo
	info **list;	
} professor;
professor new_professor(int ID, const char *name);
void free_professor(professor *individuo);
bool add_info(info *novo, professor *individuo);

#endif