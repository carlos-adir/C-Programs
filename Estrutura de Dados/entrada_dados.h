#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

char getch()/*le um caracter da entrada padrão sem o bloqueio de entrada(nao necessita apertar enter) */
{
	int ch;
	struct termios oldt;
	struct termios newt;
	tcgetattr(STDIN_FILENO,&oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}

int kbhit()
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if(ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}
	return 0;
}

typedef struct
{
	char k[10];
}KEY;

char opcao(char *opcoes, int quantidade)
{
	
	int i = 0;
	char c = getch();
	if(quantidade < 1)
		return c;
	while(i < quantidade) /* */
	{
		if(*(opcoes+i) == c)
			return i;
		i++;
	}
	return -1;
}
void buffer_clear()
{
	/* Essa função limpa o buffer do usuário, inclusive o que foi digitado mas ainda não enviado para análise */
	while(kbhit())
		getch();
}
char opcao2(char *opcoes, int quantidade)
{
	/* Requer do usuário um caracter até que ele esteja na lista de opcoes */
	/* Retorna -1 se a quantidade for 0 ou negativo */
	char c = -1;
	if(quantidade < 1)
		return -1;
	while(c == -1)
		c = opcao(opcoes, quantidade);
	return c;
}
void aperte_tecla(char tecla)
{
	buffer_clear();
	if(!tecla)
	{
		printf("\n\nAperte qualquer tecla para continuar...");
		getch();
	}
	else
	{
		if(tecla == 27) /* Numero referente ao ESC */
		printf("\n\nAperte ESC para continuar..."); 
		else if(tecla == 10) /* Numero referente ao ENTER */
		printf("\n\nAperte ENTER para continuar...");
		else
			printf("\n\nAperte %c para continuar...", tecla);
		while(getch() != tecla);
	}
}

KEY t1(int n1)
{
	KEY t;
	t.k[0] = n1;
	t.k[1] = '\0';
	return t;
}
KEY t2(int n1, int n2)
{
	KEY t;
	t.k[0] = n1;
	t.k[1] = n2;
	t.k[2] = '\0';
	return t;
}
KEY t3(int n1, int n2, int n3)
{
	KEY t;
	t.k[0] = n1;
	t.k[1] = n2;
	t.k[2] = n3;
	t.k[3] = '\0';
	return t;
}
KEY t4(int n1, int n2, int n3, int n4)
{
	KEY t;
	t.k[0] = n1;
	t.k[1] = n2;
	t.k[2] = n3;
	t.k[3] = n4;
	t.k[4] = '\0';
	return t;
}
KEY t5(int n1, int n2, int n3, int n4, int n5)
{
	KEY t;
	t.k[0] = n1;
	t.k[1] = n2;
	t.k[2] = n3;
	t.k[3] = n4;
	t.k[4] = n5;
	t.k[5] = '\0';
	return t;
}

KEY get_key()
{
	KEY t;
	int i = 0;
	do
	{
		t.k[i] = getch();
		i += 1;
	}while(kbhit() && i < 9);
	t.k[i] = '\0';
	return t;
}
KEY to_key(char *str)
{
	/*

	\0 			= 0
	ENTER 		= 10
	ESC 		= 27
	F2 			= 27 79 81
	F3			= 27 79 82
	F4			= 27 79 83
	F5			= 27 91 49 53 126
	F6			= 27 91 49 55 126
	INSERT 		= 27 91 50 126
	DELETE 		= 27 91 51 126
	PGUP 		= 27 91 53 126
	PGDN 		= 27 91 54 126
	HOME 		= 27 91 72
	END 		= 27 91 70
	UP_KEY 		= 27 91 65
	DOWN_KEY 	= 27 91 66
	RIGHT_KEY 	= 27 91 67
	LEFT_KEY 	= 27 91 68
	BACKSPACE 	= 127

	
	*/
	if(!strcmp(str, "ENTER"))
		return t1(10);
	else if(!strcmp(str, "ESC"))
		return t1(27);
	else if(!strcmp(str, "BACKSPACE"))
		return t1(127);
	else if(!strcmp(str, "UP_KEY"))
		return t3(27, 91, 65);
	else if(!strcmp(str, "DOWN_KEY"))
		return t3(27, 91, 66);
	else if(!strcmp(str, "RIGHT_KEY"))
		return t3(27, 91, 67);
	else if(!strcmp(str, "LEFT_KEY"))
		return t3(27, 91, 68);
	else if(!strcmp(str, "F2"))
		return t3(27, 79, 81);
	else if(!strcmp(str, "F3"))
		return t3(27, 79, 82);
	else if(!strcmp(str, "F4"))
		return t3(27, 79, 83);
	else if(!strcmp(str, "F5"))
		return t5(27, 91, 49, 53, 126);
	else if(!strcmp(str, "F6"))
		return t5(27, 91, 49, 55, 126);
	else if(!strcmp(str, "INSERT"))
		return t4(27, 91, 50, 126);
	else if(!strcmp(str, "DELETE"))
		return t4(27, 91, 51, 126);
	else if(!strcmp(str, "PGUP"))
		return t4(27, 91, 53, 126);
	else if(!strcmp(str, "PGDN"))
		return t4(27, 91, 54, 126);
	else if(!strcmp(str, "HOME"))
		return t3(27, 91, 72);
	else if(!strcmp(str, "END"))
		return t3(27, 91, 70);
	else
	{
		int i = 0;
		KEY t;
		while(*(str+i) != '\0')
		{
			t.k[i] = *(str+i);
			i+=1;
		}
		return t;
	}
}
char key_is_equal(KEY t, char *str)
{
	KEY p = to_key(str);
	return strcmp(t.k, p.k) == 0 ? 1 : 0;
}
/*
static char *key_to_str(KEY t)
{
	if(key_is_equal(t, "ENTER"))
		return "ENTER";
	else if(key_is_equal(t, "ESC"))
		return "Foi apertado ESC";
	else if(key_is_equal(t, "INSERT"))
		return "INSERT";
	else if(key_is_equal(t, "DELETE"))
		return "DELETE";
	else if(key_is_equal(t, "PGUP"))
		return "PGUP";
	else if(key_is_equal(t, "PGDN"))
		return "PGDN";
	else if(key_is_equal(t, "HOME"))
		return "HOME";
	else if(key_is_equal(t, "END"))
		return "END";
	else if(key_is_equal(t, "UP_KEY"))
		return "UP_KEY";
	else if(key_is_equal(t, "DOWN_KEY"))
		return "DOWN_KEY";
	else if(key_is_equal(t, "RIGHT_KEY"))
		return "RIGHT_KEY";
	else if(key_is_equal(t, "LEFT_KEY"))
		return "LEFT_KEY";
	else if(key_is_equal(t, "BACKSPACE"))
		return "BACKSPACE";
	else if(key_is_equal(t, "F2"))
		return "F2";
	else if(key_is_equal(t, "F3"))
		return "F3";
	else if(key_is_equal(t, "F4"))
		return "F4";
	else if(key_is_equal(t, "F5"))
		return "F5";
	else if(key_is_equal(t, "F6"))
		return "F6";
	else
	{
		static char v[5];
		if(t.k[1] == '\0')
			sprintf(v, "%c", t.k[0]);
		else if(t.k[2] == '\0' && t.k[0] == 27)
			sprintf(v, "Alt+%c", t.k[1]);
		else
			sprintf(v, "%s", t.k);
		return v;
	}
}
*/