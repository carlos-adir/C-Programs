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