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