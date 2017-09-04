/* 
*     	 @file: 3-kbhit_example1.c
*      @author: Carlos Adir (carlos.adir.leite@gmail.br)
* @description: This code is the third example shown in the file kbhitgetch.pdf and shows how the kbhit function works.
*				The program will show the message "Aperte uma tecla para parar" until the user press some key on the keyboard.
*				The program will finish when the user press some key and will show on the screen the message "Voce parou o processo apertando alguma tecla!".
*
*				Este código é o terceiro exemplo mostrado no arquivo kbhitgetch.pdf e mostra como a função kbhit se comporta.
*				Este programa mostrará na tela a mensagem "Aperte uma tecla para parar" até que o usuário aperte alguma tecla no teclado.
*				O programa encerrará quando o usuário apertar alguma tecla e mostrará na tela a mensagem "Voce parou o processo apertando alguma tecla!".
*
*/

#include <stdio.h>
#include "kbhitgetch.h"

int main()
{
	while(!kbhit()) /* Enquanto nao tem entrada */
	{
		printf("Aperte uma tecla para parar\n");
	}
	printf("Voce parou o processo apertando alguma tecla!\n\n");
	return 0;
}