/* 
*     	 @file: 1-getch_example1.c
*      @author: Carlos Adir (carlos.adir.leite@gmail.br)
* @description: This code is the first example shown in the file kbhitgetch.pdf and shows how the getch function works.
*				The program will get each character which the type on the keyboard without press ENTER and will show it on the screen.
*				The program will finish when you press the button ENTER.
*
*				Este código é o primeiro exemplo mostrado no arquivo kbhitgetch.pdf e exemplifica como a função getch funciona.
*				O programa capturará cada caracter que o usuário digitar no teclado sem pressionar ENTER e o imprimirá na tela.
*				O programa será finalizado quando você apertar o botão ENTER.
*
*/

#include <stdio.h>
#include "kbhitgetch.h"

int main()
{
	char c;
	do{
		c = getch();
		putchar(c); 
	}while(c != '\n');
	return 0;
}