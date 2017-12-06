// Carlos Adir Ely Murussi Leite
// 150121059

#include <stdio.h>
#include "input.h"
#include "organiza.h"

int main()
{
	bool rate;
	char data[] = "avaliacao_docentes/avaliacao_docentes.csv";
	char orga[] = "organized.bin"
	l_prof **lista;
	rate = get_data(data, &lista);
	//if(1)
	if(rate == SUCESS)
	{
		printf("Sucesso!\n");
		//loading();
		organize(lista, orga);
		printf("Saiu!\n");
		free_lista(lista);
		lista = NULL;
	}
	else
	{
		system("clear");
		printf("Falha!\n");
		return 1;
	}
	//free_lista(lista);
	return 0;
}