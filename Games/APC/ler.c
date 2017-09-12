#include <stdio.h>
#include <stdlib.h>
#define player 10
#define carac 10
#define jogos 12
#define bin "bin"
#define read "rb"
#define write "wb+"

/**      @file: 150121059.c
  *     @author: Carlos Adir Ely Murussi Leite (carlos.adir.leite@gmail.com)
  *  @matricula: 150121059
  * @disciplina: Algoritmos e Programação de Computadores
  *
  * */

typedef struct
{
	char nome[carac];
	int point[jogos], total;
} geral;
typedef struct
{
	char nome[carac];
	int valor;
} individual;
typedef struct
{
	individual w_[player];
} completo;

int ler_numero(FILE *arquivo)
{
	int numero;
	fread(&numero, sizeof(numero), 1, arquivo);
	return numero;
}
char ler_letra(FILE *arquivo)
{
	char letra;
	fread(&letra, sizeof(letra), 1, arquivo);
	return letra;
}
void imprime(geral *a_, completo *b_)
{
	int i, j;
	for(i = 0; i < player; i++)
	{
		printf("%s\n", (a_+i)->nome);
		for(j = 0; j < jogos; j++)
			printf("point: %d\n",*((a_+i)->point+j));
		printf("SOMA: %d\n\n",(a_+i)->total);
	}
	for(i = 0; i < jogos; i++)
		for(j = 0; j < player; j++)
			printf("%d, %s: %d\n", i, ((b_+i)->w_+j)->nome,((b_+i)->w_+j)->valor);
}
int importar_dados(geral *a_, completo *b_)
{
	FILE *arquivo = fopen(bin, read);
	int i, j, k;
	if(!arquivo)
		return 1;
	for(i = 0; i < player; i++)
	{
		for(j = 0; j < carac; j++)
			*((a_+i)->nome+j) = ler_letra(arquivo);
		for(j = 0; j < jogos; j++)
			*((a_+i)->point+j) = ler_numero(arquivo);
		(a_+i)->total = ler_numero(arquivo);
	}
	for(i = 0; i < jogos; i++)
		for(j = 0; j < player; j++)
		{
			for(k = 0; k < carac; k++)
				*(((b_+i)->w_+j)->nome+k) = ler_letra(arquivo);
			((b_+i)->w_+j)->valor = ler_numero(arquivo);
		}
	return 0;
	fclose(arquivo);
}
int main()
{
	geral p_[player];
	completo q_[jogos];
	importar_dados(p_, q_);
	
	/*for(i = 0; i < player; i++)
	{
		for(j = 0; j < carac; j++)
			p_[i].nome[j] = ler_letra(arquivo);
		for(j = 0; j < jogos; j++)
			p_[i].point[j] = ler_numero(arquivo);
		p_[i].total = ler_numero(arquivo);
	}
	for(i = 0; i < jogos; i++)
		for(j = 0; j < player; j++)
		{
			for(k = 0; k < carac; k++)
				q_[i].w_[j].nome[k] = ler_letra(arquivo);
			q_[i].w_[j].valor = ler_numero(arquivo);
		}
	*/
	/*arquivo = fopen(bin, read);
	
	
	fclose(arquivo);*/
	imprime(p_, q_);
	return 0;
}  