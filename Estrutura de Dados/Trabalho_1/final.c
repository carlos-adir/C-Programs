#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define espaco 10000
#define delay 50*espaco

void usleep(unsigned int t);
void limpa_tela()
{
	/* system("clear"); */
	printf("\n");
}

#include "entrada.h" 		/* Funcoes para entrada de dados, contem o necessario para os 'keys' utilizados*/
#include "data.h"			/* Toda as operacoes do tipo DATA, inclui a estrutura DATA e as operacoes de soma, subtracao, divisao e multiplicacao */
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
void menu_rpn(PILHA_NUM **l);
int soma_PILHA_NUM(PILHA_NUM **l);
int sub_PILHA_NUM(PILHA_NUM **l);
int mult_PILHA_NUM(PILHA_NUM **l);
int div_PILHA_NUM(PILHA_NUM **l);


/* Informacoes uteis do header "pilha_char.h" */
struct PILHA_CHAR;
PILHA_CHAR ** create_PILHA_CHAR();
char vazia_PILHA_CHAR(PILHA_CHAR **p);
int append_PILHA_CHAR(char c, PILHA_CHAR **p);
PILHA_CHAR *remove_PILHA_CHAR(PILHA_CHAR **p);
char get_last_PILHA_CHAR(PILHA_CHAR **p);
int libera_PILHA_CHAR(PILHA_CHAR **p);
int trade_PILHA_CHAR(PILHA_CHAR **p, PILHA_CHAR **p_aux);

/* Informacoes uteis do header "expressao.h" */
void menu_expressao();
int pilhas_ja_criadas(PILHA_NUM **l, PILHA_CHAR **p);
int possivel_criar_pilhas(PILHA_NUM ***l, PILHA_CHAR ***p);
int imprime_ambas_pilhas(PILHA_NUM **l, PILHA_CHAR **p);
int imprime_quatro_pilhas(PILHA_NUM **l, PILHA_CHAR **p, PILHA_NUM **le, PILHA_CHAR **pe);
int trata_expressao(char *str, PILHA_NUM **l, PILHA_CHAR **p);
int inverte_pilha(PILHA_NUM ***l, PILHA_CHAR ***p);
int resolve(double *value, PILHA_NUM **le, PILHA_CHAR **pe);


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
					printf("Temos agora nossa entrada e mostrada acima.\n");
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
void instrucoes()
{
	int pag = 1, pagmax = 5, change = 1;
	KEY k;
	while(1)
	{
		if(change)
		{
			menu_instrucoes();
			printf("\n\n");
			if(pag == 1)
			{
				printf("\t ________________________________________________________________________ \n");
				printf("\t|                                                                        |\n");
				printf("\t| Ola, voce esta nas instrucoes. Na utilizacao dessa parte, e necessario |\n");
				printf("\t| algumas informacoes de como navegar neste menu. As unicas teclas que   |\n");
				printf("\t| funcionam sao as:                                                      |\n");
				printf("\t|                                                                        |\n");
				printf("\t|       ESC) Caso voce queira sair e voltar ao menu principal            |\n");
				printf("\t|  LEFT_KEY) Caso voce queira voltar uma pagina                          |\n");
				printf("\t| RIGHT_KEY) Caso voce queira avançar uma pagina                         |\n");
				printf("\t|                                                                        |\n");
				printf("\t| Assim como aqui, no menu principal a tecla ESC faz o usuario sair do   |\n");
				printf("\t| programa.                                                              |\n");
				printf("\t|                                                                        |\n");
				printf("\t| Utilize a seta para a direita para ir para a proxima instrucao.        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|________________________________________________________________________|\n");
				printf("\n");
				printf("\t                                    1/5                 Proxima pagina -->\n");	
			}
			else if(pag == 2)
			{
				printf("\t ________________________________________________________________________ \n");
				printf("\t|                                                                        |\n");
				printf("\t| Quando se executa o programa, aparece uma tela indicando a calculadora |\n");
				printf("\t| e suas opcoes. Para sair deste modo, aperte ESC.                       |\n");
				printf("\t|                                                                        |\n");
				printf("\t| Os botoes validos para quando se esta no menu principal sao:           |\n");
				printf("\t|                                                                        |\n");
				printf("\t| 1) Acessa a calculadora de expressao, em que voce entra com uma expres-|\n");
				printf("\t|    como por exemplo (3+2*2)*5-7 e entao seu valor e calculado. Mais de-|\n");
				printf("\t|    talhes sao explicados na proxima pagina.                            |\n");
				printf("\t| 2) Acessa a calculadora no modo RPN, em que voce entra com numeros e as|\n");
				printf("\t|    opcoes de soma, subtracao, multiplicacao e divisao sao validas. Mais|\n");
				printf("\t|    detalhes sao explicados daqui a duas paginas                        |\n");
				printf("\t| 3) Menu instrucoes, a maneira com que voce chegou nessa parte foi atra-|\n");
				printf("\t|    ves disso. Nao sera explicado mais para frente.                     |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|________________________________________________________________________|\n");
				printf("\n");
				printf("\t<-- Pagina anterior                 2/5                 Proxima pagina -->\n");
			}
			else if(pag == 3)
			{
				printf("\t ________________________________________________________________________ \n");
				printf("\t|                                                                        |\n");
				printf("\t| Aqui sao mostradas as instrucoes para quando voce acessa a calculadora |\n");
				printf("\t| de expressoes. Primeiro, para sair desse modo, basta digitar a frase   |\n");
				printf("\t| \"exit\" sem as aspas e apertar ENTER.                                   |\n");
				printf("\t|                                                                        |\n");
				printf("\t| Neste voce digita uma expressao como por exemplo (3+2*2)*5-7 cujo valor|\n");
				printf("\t| e dado por 28. Este e um exemplo de entrada valida, e o valor calcula- |\n");
				printf("\t| do sendo mostrado a utilizacao de pilhas.                              |\n");
				printf("\t|                                                                        |\n");
				printf("\t|            ENTRADA VALIDA:  (3+2*2)*5-7                                |\n");
				printf("\t|                             3*(4-7*2/(4+3))-9*4                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t| cujos valores sao 28 e -30, respectivamente. Abaixo tem exemplo de duas|\n");
				printf("\t| entradas invalidas, sendo a primeira invalida por falta de parenteses  |\n");
				printf("\t| e a segunda invalida pois a quantidade de operandos e insuficiente.    |\n");
				printf("\t|                                                                        |\n");
				printf("\t|          ENTRADA INVALIDA: 3*(4-7*2/(4+3)-9*4                          |\n");
				printf("\t|                            3*(4-7*2/(4+3))-9*                          |\n");
				printf("\t|                                                                        |\n");
				printf("\t| Neste modo, sao utilizados duas pilhas numericas e duas pilhas de char |\n");
				printf("\t| Como a maneira utilizada e didatica, foi estipulado um tempo entre uma |\n");
				printf("\t| execucao e outra. Para isso, mude os valores de delay e wait dentro do |\n");
				printf("\t| arquivo \"final.c\" para variar esse tempo.                              |\n");
				printf("\t|________________________________________________________________________|\n");
				printf("\n");
				printf("\t<-- Pagina anterior                 3/5                 Proxima pagina -->\n");
			}
			else if(pag == 4)
			{
				printf("\t ________________________________________________________________________ \n");
				printf("\t|                                                                        |\n");
				printf("\t| Aqui sao mostradas as instrucoes para quando voce acessa a calculadora |\n");
				printf("\t| no modo RPN. Este modo e muito utilizado por calculadoras pois precisa |\n");
				printf("\t| de de menor quantidade de termos a serem digitados pois nao e necessa- |\n");
				printf("\t| rio abrir ou fechar parentes. Contudo, ate esse metodo ser aprendido,  |\n");
				printf("\t| demora-se um pouco de tempo.                                           |\n");
				printf("\t|                                                                        |\n");
				printf("\t| Neste modo, voce faz as operacoes sempre com os dois elementos mostra- |\n");
				printf("\t| dos na pilha pelas posicoes 1 e 2. Por exemplo, digite o numero 3, te- |\n");
				printf("\t| cle ENTER, depois o numero 2, ENTER e depois o simbolo de menos('-').  |\n");
				printf("\t| Neste caso, teremos que o numero 1 sera mostrado na posicao 1 e os nu- |\n");
				printf("\t| meros 3 e 2 digitados somem.                                           |\n");
				printf("\t|                                                                        |\n");
				printf("\t| Da mesma maneira, tem-se as operacoes de +, -, * e /. Teste alguns nu- |\n");
				printf("\t| meros e suas operacoes. Voce vera que ao tentar dividir por zero, nao  |\n");
				printf("\t| conseguira e sera informado uma mensagem de erro. Caso o usuario tente |\n");
				printf("\t| fazer uma operacao e nao tenha a quantidade de elementos, o programa   |\n");
				printf("\t| informara ao usuario a impossibilidade da operacao.                    |\n");
				printf("\t|                                                                        |\n");
				printf("\t| Vale lembrar que embora mostre apenas 15 numeros, caso seja digitados  |\n");
				printf("\t| mais de 15, ainda continuarao disponíveis ao usuario.                  |\n");
				printf("\t| Dica: Digite 2, depois ENTER algumas vezes. Dessa maneira e possivel   |\n");
				printf("\t| repetir a ultima entrada. O mesmo vale para operacoes                  |\n");
				printf("\t|________________________________________________________________________|\n");
				printf("\n");
				printf("\t<-- Pagina anterior                 4/5                 Proxima pagina -->\n");
			}
			else if(pag == 5)
			{
				printf("\t ________________________________________________________________________ \n");
				printf("\t|                                                                        |\n");
				printf("\t|                                  CONTATO                               |\n");
				printf("\t|                                                                        |\n");
				printf("\t|    AUTOR: Carlos Adir Ely                                              |\n");
				printf("\t|                                                                        |\n");
				printf("\t|    EMAIL: carlos.adir.leite@gmail.com                                  |\n");
				printf("\t|                                                                        |\n");
				printf("\t|     LINK: github.com/CarlosAdir/C-Programs/tree/master/                |\n");
				printf("\t|                      Estrutura%%20de%%20Dados                            |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|    Duvidas, sugestoes ou criticas, contate o autor deste.              |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|                                                                        |\n");
				printf("\t|________________________________________________________________________|\n");
				printf("\n");
				printf("\t<-- Pagina anterior                 5/5                                   \n");
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
			if(w == 0 && entrada[0]){}
			else
			{
				resposta = append_PILHA_NUM(create_DATA(w), l);
				if(resposta == 0)
				{
					printf("Nao e possivel adicionar outro elemento na pilha!\n");
					sleep(wait);
				}
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
		}while(! (key_is_equal(k, "1") || key_is_equal(k, "2") || key_is_equal(k, "3") || key_is_equal(k, "ESC")));
		buffer_clear();
		if(key_is_equal(k, "1"))
			inicia_expressao();
		else if(key_is_equal(k, "2"))
			printf("%d\n", inicia_rpn());
		else if(key_is_equal(k, "3"))
			instrucoes();
		else if(key_is_equal(k, "ESC"))
			break;	
	}
	limpa_tela();
	return 0;
}