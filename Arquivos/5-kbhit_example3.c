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