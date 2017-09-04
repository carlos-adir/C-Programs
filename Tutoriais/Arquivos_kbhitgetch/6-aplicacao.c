/* 
*        @file: 6-aplicacao.c
*      @author: Carlos Adir (carlos.adir.leite@gmail.br)
* @description: This code is the sixth example shown in the file kbhitgetch.pdf.
*				It will show a number on the screen every time that you press some key.
*				The number which appears is the corresponding ASCII number.
*				For example, if you press 'a', it will show on the screen the number 97.
*       		The program will finish when you press the ENTER key.
*       
*
*				Este código é o sexto exemplo mostrado no arquivo kbhitgetch.pdf.
*				Ele mostrará um número na tela toda vez que você apertar alguma tecla.
*				O numero mostrado é o número do ASCII correspondente. 
*				Por exemplo, se você apertar 'a', será mostrado na tela o número 97.
*				O programa se encerra quando for apertado a tecla ENTER.
*
*/


#include <stdio.h>
#include "kbhitgetch.h"

int main()
{
  char c;
  do{
    c = getch();
    printf("%d\n", c);
  }while(c != '\n');
  return 0;
}