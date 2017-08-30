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