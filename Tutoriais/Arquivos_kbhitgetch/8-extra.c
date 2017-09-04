#include "funcoes_extras.h"

int main()
{
	KEY t;
	do
	{
		buffer_clear();
		t = get_key();
		printf("Foi apertado %s\n", key_to_str(t));
	}while(!key_is_equal(t, "ENTER"));
	return 0;
}