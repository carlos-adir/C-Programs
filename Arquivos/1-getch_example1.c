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