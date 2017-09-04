/* 
*     	 @file: 4-kbhit_example2.c
*      @author: Carlos Adir (carlos.adir.leite@gmail.br)
* @description: This code is the fourth example shown in the file kbhitgetch.pdf and shows how the kbhit function works.
*				The program will show the message "Aperte uma tecla para parar" until the user press some key on the keyboard.
*				When the user press some key, the program will show on the screen the message "Voce parou o processo apertando a tecla:"
* 				and the key pressed.
*				
*
*				Este código é o quarto exemplo mostrado no arquivo kbhitgetch.pdf e mostra como a função kbhit se comporta.
*				Este programa mostrará a mensagem "Aperte uma tecla para parar" até que o usuário aperte alguma tecla no teclado.
*				Quando o usuário apertar alguma tecla, mostrará na tela a mensagem "Voce parou o processo apertando a tecla:" 
*				e a tecla pressionada.
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
	printf("Voce parou o processo apertando a tecla: [%c]!\n\n", getch());
	return 0;
}