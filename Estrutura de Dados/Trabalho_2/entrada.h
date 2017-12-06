// Carlos Adir Ely Murussi Leite
// 150121059

#ifndef ENTRADA
#define ENTRADA

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct
{
	char k[10];
}KEY;

void buffer_clear();
KEY get_key();
char key_is_equal(KEY t, char *str);
void press_key(char *str);

/* static char *key_to_str(KEY t) */

#endif