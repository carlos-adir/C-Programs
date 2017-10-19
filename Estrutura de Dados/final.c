#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define espaco 10000
#define delay 50*espaco

void limpa_tela()
{
	system("clear");
	/*printf("\n");*/
}

#include "entrada.h" 		/* Funcoes para entrada de dados, contem o necessario para os 'keys' utilizados*/
#include "data.h"			/* Toda as operações do tipo DATA, inclui a estrutura DATA e as operacoes de soma, subtracao, divisao e multiplicacao */
#include "pilha_num.h"		/* Toda a estrutura de dados para utilizacao de pilha, insercao, remocao, impressao etc */
#include "rpn.h"			/* As operacoes de uma calculadora RPN */
#include "pilha_char.h"		/* Uma pilha de caracteres */
#include "expressao.h"		/* Contem as funcoes necessarias para a parte de expressoes */

#define wait 2

/* Informacoes utilizadas do header "entrada_dados.h" */
void buffer_clear();
struct KEY;
KEY get_key();
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
int append_PILHA_NUM(DATA t, PILHA_NUM **l);
PILHA_NUM *remove_PILHA_NUM(PILHA_NUM **l);
int libera_PILHA_NUM(PILHA_NUM **l);
int trade_PILHA_NUM(PILHA_NUM **l, PILHA_NUM **l_aux);
char at_least_PILHA_NUM(PILHA_NUM **l, int q);
int imprime_PILHA_NUM(PILHA_NUM **l);


/* Informacoes uteis do header "rpn.h" */
int soma_PILHA_NUM(PILHA_NUM **l);
int sub_PILHA_NUM(PILHA_NUM **l);
int mult_PILHA_NUM(PILHA_NUM **l);
int div_PILHA_NUM(PILHA_NUM **l);

/* Programa principal e menus */
void menu_principal()
{
	limpa_tela();
	printf("\n\n");
	printf("   ███████╗ █████╗ ██╗    ███████╗██╗  ██╗██╗     █████╗ ██████╗  █████╗ ██████╗  █████╗  \n");
	printf("   ██╔════╝██╔══██╗██║    ██╔════╝██║  ██║██║    ██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗ \n");
	printf("   ██║     ███████║██║    ██║     ██║  ██║██║    ███████║██║  ██║██║  ██║██████╔╝███████║ \n");
	printf("   ██║     ██╔══██║██║    ██║     ██║  ██║██║    ██╔══██║██║  ██║██║  ██║██╔══██╗██╔══██║ \n");
	printf("   ███████╗██║  ██║██████╗███████╗███████║██████╗██║  ██║██████╔╝ █████╔╝██║  ██║██║  ██║ \n");
	printf("   ╚══════╝╚═╝  ╚═╝╚═════╝╚══════╝╚══════╝╚═════╝╚═╝  ╚═╝╚═════╝  ╚════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ \n");
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

void inicia_expressao()
{
	PILHA_NUM **l = NULL;
	PILHA_CHAR **p = NULL;
	char entrada[500];
	double w;
	char resposta;
	while(1)
	{
		menu_expressao();
		printf("\n");
		printf("  Digite a expressao:\n");
		printf("\n");
		printf("> ");
		scanf("%99[^\n]", entrada);
		while(getchar()!='\n');
		if(!strcmp(entrada, "exit"))
			break;	
		else if(!strcmp(entrada, "options"))
			break;
		else
		{
			if(!possivel_criar_pilhas(&l, &p))
			{
				printf("Nao foi possivel criar as pilhas!\n");
				continue;
			}
			/* Aqui as pilhas ja estao alocadas */
			/* printf("Em cima de trata_expressao:\n");
			imprime_estado(l, p); DEBUGAR */
			if(!trata_expressao(entrada, l, p))
			{
				printf("Entrada invalida!\n");
			}
			else
			{
				if(delay != 0)
				{
					imprime_ambas_pilhas(l, p);
					printf("Temos agora nossa entrada é mostrada acima.\n");
					usleep(2*delay);
				}
				inverte_pilha(&l, &p); /* Invertemos pois queremos os primeiros numeros no topo da lista */
				if(delay != 0)
				{
					imprime_ambas_pilhas(l, p);
					printf("Invertemos a nossa entrada.\n");
					usleep(2*delay);
				}
				resposta = resolve(&w, l, p);
				if(!resposta)
				{
					printf("Entrada invalida!\n");
				}
			}
			libera_PILHA_NUM(l);
			libera_PILHA_CHAR(p);
			sleep(5);
			/*imprime_ambas_pilhas(p, l);*/
			/* printf("Em baixo de trata_expressao:\n");
			imprime_estado(l, p); DEBUGAR */
		}
	}
}

void instrucoes()
{
	int pag = 1, pagmax = 5, change = 1;
	KEY k;
	while(1)
	{
		if(change)
		{
			limpa_tela();
			printf("\n\n");
			if(pag == 1)
			{

			}
			else if(pag == 2)
			{

			}
			else if(pag == 3)
			{
				
			}
			else if(pag == 4)
			{
				
			}
			else if(pag == 5)
			{
				
			}
		}
		do
		{
			k = get_key();
		}while(! (key_is_equal(k, "RIGHT_KEY") || key_is_equal(k, "LEFT_KEY") || key_is_equal(k, "ESC")));
		if(key_is_equal(k, "RIGHT_KEY"))
		{
			if(pag != pagmax)
			{
				pag += 1;
				change = 1;
			}
			else
				change = 0;
		}
		else if(key_is_equal(k, "LEFT_KEY"))
		{
			if(pag != 1)
			{
				pag -= 1;
				change = 1;
			}
			else
				change = 0;
		}	
		else if(key_is_equal(k, "ESC"))
			break;
	}
}

void menu_instrucoes()
{
	limpa_tela();
	printf("\n\n");
	printf("      ██╗███╗ ██╗ ██████╗████████╗██████╗ ██╗  ██╗███████╗ █████╗ ███████╗ ██████╗ \n");
	printf("      ██║████╗██║██╔════╝╚══██╔══╝██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝██╔════╝ \n");
	printf("      ██║███████║ █████╗    ██║   ██████╔╝██║  ██║██║     ██║  ██║█████╗   █████╗  \n");
	printf("      ██║██╔████║     ██╗   ██║   ██╔══██╗██║  ██║██║     ██║  ██║██╔══╝       ██╗ \n");
	printf("      ██║██║╚███║██████╔╝   ██║   ██║  ██║╚█████╔╝███████╗ █████╔╝███████╗██████╔╝ \n");
	printf("      ╚═╝╚═╝ ╚══╝╚═════╝    ╚═╝   ╚═╝  ╚═╝  ╚═══╝ ╚══════╝ ╚════╝ ╚══════╝╚═════╝  \n");
}

int inicia_rpn()
{
	printf("Antes\n");
	fflush(stdin);
	PILHA_NUM **l = create_PILHA_NUM();
	printf("Antes2\n");
	fflush(stdin);
	char entrada[100];
	double w;
	char resposta;
	if(l == NULL)
		return 0;
	while(1)
	{
		menu_rpn(l);
		buffer_clear();
		scanf("%[^\n]", entrada);
		while(getchar() != '\n');
		if(!strcmp(entrada, "exit"))
			break;
		else if(!strcmp(entrada, "num"))
		{
			/*abre_toda_lista_numerica(l);*/
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
			resposta = append_PILHA_NUM(create_DATA(w), l);
			if(resposta == 0)
			{
				printf("Nao e possivel adicionar outro elemento na pilha!\n");
				sleep(wait);
			}
		}
	}
	libera_PILHA_NUM(l);
	return 1;
}

int main()
{
	KEY k;
	while(1)
	{
		menu_principal();
		do
		{
			k = get_key();
		}while(! (key_is_equal(k, "1") || key_is_equal(k, "2") || key_is_equal(k, "3") || key_is_equal(k, "4")));
		buffer_clear();
		if(key_is_equal(k, "1"))
			inicia_expressao();
		else if(key_is_equal(k, "2"))
			printf("%d\n", inicia_rpn());
		else if(key_is_equal(k, "3"))
			instrucoes();
		else if(key_is_equal(k, "4"))
			break;	
	}
	limpa_tela();
	return 0;
}