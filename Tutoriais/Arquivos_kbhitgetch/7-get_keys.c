/* 
*        @file: 7-get_keys.c
*      @author: Carlos Adir (carlos.adir.leite@gmail.br)
* @description: This code is the seventh example shown in the file kbhitgetch.pdf.
*				It will show a number sequence on the screen every time that you press some key.
*				The number depends of the key pressed and each key has its own number sequence.
*				For example, if you press UP_KEY, it will show on the screen the numbers 27 91 65.
*       		The program will finish when you press the ENTER key.
*       
*
*				Este código é o sétimo exemplo mostrado no arquivo kbhitgetch.pdf.
*				Ele mostrará uma sequência de números na tela toda vez que você apertar alguma tecla.
*				O numero depende da tecla apertada e cada tecla tem sua própria sequência de números. 
*				Por exemplo, se você apertar UP_KEY, será mostrado na tela os números 27 91 65.
*				O programa se encerra quando for apertado a tecla ENTER.
*
*/

#include <stdio.h>
#include "kbhitgetch.h"

int main()
{
	char c;
	do{
		do
		{
			c = getch();
			printf("%d;", c);
		}while(kbhit());
		printf("\n");
	}while(c != '\n');
	return 0;
}