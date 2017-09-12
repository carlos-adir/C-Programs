#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define player 10
#define carac 10
#define jogos 12
#define bin "ranking"
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

void escreve_numero(int numero, FILE *arquivo)
{
	fwrite(&numero, sizeof(numero), 1, arquivo);
}
void escreve_letra(char letra, FILE *arquivo)
{
	fwrite(&letra, sizeof(letra), 1, arquivo);
}
void troca_inteiro(int *p, int *q)
{
  int aux = *p;
  *p = *q;
  *q = aux;
}
void troca_nomes(char *str1, char *str2)
{
  char c;
  int i;
  for(i = 0; i < carac; i++)
  {
    c = *(str1+i);
    *(str1+i) = *(str2+i);
    *(str2+i) = c;
  }
}

void organizar_geral(geral *a_)
{
  int i, j, posicaomaior, maior;
  for(i = 0; i < player; i++)
  {
    posicaomaior = i;
    maior = (a_+i)->total;
    for(j = i+1; j< player; j++)
    {
      if((a_+j)->total > maior)
      {
        maior = (a_+j)->total;
        posicaomaior = j;
      }
    }
    if(maior != (a_+i)->total)
    {
      troca_nomes((a_+i)->nome, (a_+posicaomaior)->nome);
      troca_inteiro(&(a_+i)->total, &(a_+posicaomaior)->total);
      for(j = 0; j < jogos; j++)
        troca_inteiro((a_+i)->point+j, (a_+posicaomaior)->point+j);
    }
  }
}

void copia(char *str, char *pq, int maximo)
{
	int i = -1;
	do
	{
		i++;
		*(pq+i) = *(str+i);
	}while(*(str+i) != '\0');
	i++;
	while(i != maximo)
	{
		*(pq+i) = '-';
		i++;
	}
}

void escreve_tudo(geral *a_, completo *b_)
{
	FILE *arquivo;
	arquivo = fopen(bin, write);
	int i, j, k;
	for(i = 0; i < player; i++)
	{
		for(j = 0; j < carac; j++)
			escreve_letra(*((a_+i)->nome+j), arquivo);
		for(j = 0; j < jogos; j++)
			escreve_numero(*((a_+i)->point+j), arquivo);
		escreve_numero((a_+i)->total, arquivo);
	}
	for(i = 0; i < jogos; i++)
		for(j = 0; j < player; j++)
		{
			for(k = 0; k < carac; k++)
				escreve_letra(*(((b_+i)->w_+j)->nome+k), arquivo);
			escreve_numero(((b_+i)->w_+j)->valor, arquivo);
		}
	fclose(arquivo);
}
int main()
{
	geral p_[player];
	completo q_[jogos];
	srand((unsigned)time(NULL));
	FILE *arquivo = fopen(bin, write);
	if(!arquivo)
		return 1;
	else
		fclose(arquivo);
	int i, j, n;
	for(i = 0; i < player; i++)
	{
		n = 0;
		for(j = 0; j < jogos; j++)
		{
			p_[i].point[j] = rand()%15;
			n += p_[i].point[j];
		}
		p_[i].total = n;
	}
	for(i = 0; i < jogos; i++)
		for(j = 0; j < player; j++)
			q_[i].w_[j].valor = rand()%15;
	copia("Carlos", p_[0].nome, carac);
	copia("Joao", p_[1].nome, carac);
	copia("Daniel", p_[2].nome, carac);
	copia("Rei", p_[3].nome, carac);
	copia("Mariana", p_[4].nome, carac);
	copia("Gleyciane", p_[5].nome, carac);
	copia("Alan", p_[6].nome, carac);
	copia("Marisa", p_[7].nome, carac);
	copia("Pedro", p_[8].nome, carac);
	copia("Rodrigo", p_[9].nome, carac);
	for(i = 0; i < jogos; i++)  
	{
		copia("Carlos", q_[i].w_[0].nome, carac);
		copia("Joao", q_[i].w_[1].nome, carac);
		copia("Daniel", q_[i].w_[2].nome, carac);
		copia("Rei", q_[i].w_[3].nome, carac);
		copia("Mariana", q_[i].w_[4].nome, carac);
		copia("Gleyciane", q_[i].w_[5].nome, carac);
		copia("Alan", q_[i].w_[6].nome, carac);
		copia("Marisa", q_[i].w_[7].nome, carac);
		copia("Pedro", q_[i].w_[8].nome, carac);
		copia("Rodrigo", q_[i].w_[9].nome, carac);
	}
	organizar_geral(p_);
	for(i = 0; i < 10; i++)
		printf("%s\n", p_[i].nome);
	escreve_tudo(p_, q_);
	printf("\n\nTerminei\n");
	return 0;
}  