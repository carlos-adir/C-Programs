#include "funcoes_extras.h"

int main()
{
	KEY t;
	do
	{
		buffer_clear();
		t = get_key();
		printf("Foi apertado %s\n", key_to_str(t));
		/* As possibilidades sao:
			ENTER, ESC, BACKSPACE, F2, F3, F4, F5, F6, INSERT
			DELETE, PGUP, PGDN, HOME, END
			UP_KEY, DOWN_KEY, RIGHT_KEY, LEFT_KEY
		*/
	}while(!key_is_equal(t, "ENTER"));
	return 0;
}