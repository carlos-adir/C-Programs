#include <stdio.h>

#define  CSI         "\x1B["
#define  RESET       "0m"
#define  BOLD_OFF    "21m"
#define  UNSCR_OFF   "24m"

int main()
{
	int i, j;
	for(i = 0; i < 100; i++)
		for(j = 0; j < 100; j++)
		{
			printf("%s%d;%dm%d %d - Um texto Qualquer.%s%s\n", CSI, i,j, i, j, CSI, RESET);
		}
	return 0;

}