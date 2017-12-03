#include <stdio.h>
#include "organiza.h"

int main()
{
	bool rate;
	char file_name[] = "avaliacao_docentes/avaliacao_docentes.csv";
	l_prof **lista;
	rate = get_data(file_name, &lista);
	//if(1)
	if(rate == SUCESS)
	{
		printf("Sucesso!\n");
		//loading();
		organize(lista);
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