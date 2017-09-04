/* 
*        @file: 5-kbhit_example3.c
*      @author: Carlos Adir (carlos.adir.leite@gmail.br)
* @description: This code is the fifth example shown in the file kbhitgetch.pdf and shows how the kbhit function works.
*				This program will show a number on the screen every time that you press some key.
*       		The program will finish when you press the ENTER key.
*       
*
*				Este código é o quinto exemplo mostrado no arquivo kbhitgetch.pdf e mostra como a função kbhit se comporta.
*				Este programa mostrará um número na tela toda vez que alguma tecla for pressionada.
*				O programa se encerra quando for apertado a tecla ENTER.
*
*/


#include <stdio.h>
#include "kbhitgetch.h"

int main()
{
  long long int contador = 0;
  char c = 'a';
  while(c != '\n') /* Enquanto o digitado nao for digitado o Enter */
  {
    contador += 1;
    if(kbhit()) /* Se existe entrada */
    {
      c = getch(); /* Então captura e grava em c */
      printf("contador = %lld\n", contador); /* E imprime o numero correspondente */
    }
  }
  return 0;
}