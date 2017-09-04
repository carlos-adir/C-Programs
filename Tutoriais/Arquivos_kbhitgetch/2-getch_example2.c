/* 
*     	 @file: 2-getch_example2.c
*      @author: Carlos Adir (carlos.adir.leite@gmail.br)
* @description: This code is the second example shown in the file kbhitgetch.pdf.
*				The program will get each character which the type on the keyboard without press ENTER and will show the character '*' on the screen.
*				The program will finish when you press the button ENTER.
*
*				Este código é o segundo exemplo mostrado no arquivo kbhitgetch.pdf.
*				O programa capturará cada caracter que o usuário digitar no teclado sem pressionar ENTER e mostrará o caracter '*' na tela.
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
		putchar('*'); 
	}while(c != '\n');
	return 0;
}