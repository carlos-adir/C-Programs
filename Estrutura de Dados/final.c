#include <time.h>
#include "entrada_dados.h" 	/* Funcoes para entrada de dados, contem o necessario para os 'keys' utilizados*/
#include "data.h"			/* Toda as operações do tipo DATA, inclui a estrutura DATA e as operacoes de soma, subtracao, divisao e multiplicacao */
#include "pilha_num.h"		/* Toda a estrutura de dados para utilizacao de pilha, insercao, remocao, impressao etc */
#include "rpn.h"			/* As operacoes de uma calculadora RPN */
/*#include "pilha_var.h"*/

#define wait 2

/* Informações uteis do header "entrada_dados.h" */
char getch();
int kbhit();
struct KEY;
void buffer_clear();
void aperte_tecla(char tecla);
KEY get_key();
KEY to_key(char *str);
char key_is_equal(KEY t, char *str);

/* Informacoes uteis do header "data.h" */
struct DATA;
DATA create_DATA(double t);
void imprime_DATA(DATA t);
char equal_DATA(DATA t1, DATA t2);
DATA soma_DATA(DATA t1, DATA t2);
DATA sub_DATA(DATA t1, DATA t2);
DATA mult_DATA(DATA t1, DATA t2);
DATA div_DATA(DATA t1, DATA t2);

/* Informacoes uteis do header "pilha_num.h" */
struct PILHA_NUM;
PILHA_NUM ** create_PILHA_NUM();
int size_PILHA_NUM(PILHA_NUM **l);
char at_least_PILHA_NUM(PILHA_NUM **l, int q);
void imprime_PILHA_NUM(PILHA_NUM **l);
int append_PILHA_NUM(DATA t, PILHA_NUM **l);
PILHA_NUM *remove_PILHA_NUM(PILHA_NUM **l);
int libera_PILHA_NUM(PILHA_NUM **l);
void abre_toda_lista_numerica(PILHA_NUM **l);

/* Informacoes uteis do header "rpn.h" */
int soma_PILHA_NUM(PILHA_NUM **l);
int sub_PILHA_NUM(PILHA_NUM **l);
int mult_PILHA_NUM(PILHA_NUM **l);
int div_PILHA_NUM(PILHA_NUM **l);

/* Programa principal e menus */
void menu_principal()
{
	printf("******************************************************\n");
	printf("*                                                    *\n");
	printf("*                                                    *\n");
	printf("*                                                    *\n");
	printf("*                                                    *\n");
	printf("*                                                    *\n");
	printf("******************************************************\n");
	printf("\n");
	printf("   Digite sua opcao:\n");
	printf("\n");
	printf("   1) Calculadora de Expressoes\n");
	printf("   2) Calculadora modo RPN\n");
	printf("   3) Instrucoes\n");
	printf("   4) Sair\n");
	printf("\n");
	printf("\n");
	printf(">  ");
}

void menu_expressao()
{	
	/* system("clear"); */
	printf("*****************************\n");
	printf("* CALCULADORA DE EXPRESSOES *\n");
	printf("*****************************\n");
	printf("\n");
	printf("  Digite a expressao:\n");
	printf("\n");
	printf("> ");
}

void menu_rpn(PILHA_NUM **l)
{
	/* system("clear"); */
	printf("************************\n");
	printf("* CALCULADORA MODO RPN *\n");
	printf("************************\n");
	printf("\n");
	imprime_PILHA_NUM(l);
	printf("\n");
	printf("\n");
	printf("> ");
}

void inicia_expressao()
{
	PILHA_NUM **l = create_PILHA_NUM();
	while(1)
	{
		menu_expressao();
	}
}

void instrucoes()
{
	printf("")
}

void inicia_rpn()
{
	PILHA_NUM **l = create_PILHA_NUM();
	char entrada[100];
	double w;
	char resposta;
	while(1)
	{
		menu_rpn(l);
		scanf("%[^\n]", entrada);
		while(getchar() != '\n');
		if(!strcmp(entrada, "exit"))
			break;
		else if(!strcmp(entrada, "num"))
		{
			abre_toda_lista_numerica(l);
		}
		else if(!strcmp(entrada, "+"))
		{
			resposta = soma_PILHA_NUM(l);
			if(!resposta)
			{
				printf("Faltam elementos para efetuar a soma!\n");
				sleep(wait);
			}
		}
		else if(!strcmp(entrada, "-"))
		{
			resposta = sub_PILHA_NUM(l);
			if(!resposta)
			{
				printf("Faltam elementos para efetuar a subtracao!\n");
				sleep(wait);
			}
		}
		else if(!strcmp(entrada, "*"))
		{
			resposta = mult_PILHA_NUM(l);
			if(!resposta)
			{
				printf("Faltam elementos para efetuar a multiplicacao!\n");
				sleep(wait);
			}
		}
		else if(!strcmp(entrada, "/"))
		{
			resposta = div_PILHA_NUM(l);
			if(resposta == 0)
			{
				printf("Faltam elementos para efetuar a divisao!\n");
				sleep(wait);
			}
			else if(resposta == -1)
			{
				printf("Nao e possivel dividir por zero!\n");
				sleep(wait);
			}
		}
		else
		{
			w = atof(entrada);
			append_PILHA_NUM(create_DATA(w), l);
		}
	}
	libera_PILHA_NUM(l);
}

int main()
{
	KEY k;
	while(1)
	{
		menu_principal();
		k = get_key();
		if(key_is_equal(k, "1"))
			inicia_expressao();
		else if(key_is_equal(k, "2"))
			inicia_rpn();
		else if(key_is_equal(k, "3"))
			instrucoes();
		else if(key_is_equal(k, "4"))
			break;	
	}
	return 0;
}