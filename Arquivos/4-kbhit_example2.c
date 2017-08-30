#include <stdio.h>
#include "kbhitgetch.h"

int main()
{
	while(!kbhit()) /* Enquanto nao tem entrada */
	{
		printf("Aperte uma tecla para parar\n");
	}
	printf("Voce parou o processo apertando a tecla: [%c]!\n\n", getch());
	return 0;
}