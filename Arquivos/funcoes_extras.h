#include <stdio.h>
#include "kbhitgetch.h"

unsigned long int key()
	{
	int j, i = 0;
	unsigned long int retorno = 0;
	char c[8];
	do{
		c[i] = getch();
		i++;
	}while(kbhit() && i < 8);
	for(j = 0; j < i; j++)
	{
		retorno *= 256;
		if(c[j] < 0)
			retorno += 256;
		retorno += c[j];
	}
	return retorno;
}

char opcao(char *opcoes, int quantidade)
{
	/* Esta funcao captura um caracter e verifica se é algum caracter dentre as opcoes.
	Caso esteja, retorna o indice da menor posição e caso não contenha, retorna -1 */
	/* Caso a quantidade seja menor que 1, ou seja, 0 ou negativo, ele funciona como um getch */
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
	int i = 0;
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