#include <stdio.h>
#include <stdlib.h>
#include "kbhitgetch.h"
#include <time.h>

typedef struct 
{
	char matriz[20][10];
}matriz;

void imprime(matriz *m)
{
	int i, j;
	system("clear");
	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 10; j++)
			if(m->matriz[i][j] == 0)
				printf("  ");
			else
				printf(" *");
		printf("|\n");
	}
	for(j = 0; j < 24; j++)
		printf("-");
	printf("\n");
}

void limpa_matriz(matriz *m)
{
	int i, j;
	for(i = 0; i < 20; i++)
		for(j = 0; j < 10; j++)
			m->matriz[i][j] = 0;
}

int nao_existe_peca(matriz *m) /* verifica se existe algum valor de 2 na matriz */
{
	int i, j;
	for(i = 0; i < 20; i++)
		for(j = 0; j < 10; j++)
			if(m->matriz[i][j] == 2)
				return 0;
	return 1;
}
void poe_peca(matriz *m) /* sorteia uma peca e poe */
{
	int ale;
	srand((unsigned)time(NULL));
	ale = rand()%4;
	if(ale == 0)
	{
		m->matriz[0][4] = 2;
		m->matriz[0][5] = 2;
		m->matriz[1][4] = 2;
		m->matriz[1][5] = 2;	
	}
	else if(ale == 1)
	{
		m->matriz[0][4] = 2;
		m->matriz[1][4] = 2;
		m->matriz[2][4] = 2;
		m->matriz[1][5] = 2;
	}
	else if(ale == 2)
	{
		m->matriz[0][4] = 2;
		m->matriz[1][4] = 2;
		m->matriz[1][5] = 2;
		m->matriz[2][5] = 2;
	}
	else
	{
		m->matriz[0][4] = 2;
		m->matriz[1][4] = 2;
		m->matriz[2][4] = 2;
		m->matriz[3][4] = 2;
	}
}
void elimina_linhas(matriz *m)
{
	int i, j, k, w;
	int linhas[20];
	/* limpa o vetor linhas */
	for(i = 0; i < 20; i++)
		linhas[i] = 0;
	/* poe no vetor linhas as linhas que são para apagar */
	for(i = 19; i >= 0; i--)
	{
		k = 0;
		for(j = 0; j < 9 && !k; j++)
			if(m->matriz[i][j] == 0)
				k = 1;
		if(!k)
			linhas[i] = 1;
	}
	/* pisca pisca */
	
	for(w = 0; w < 10; w++)
	{
		usleep(50000);
		for(i = 0; i < 20; i++)
			if(linhas[i])
				for(j = 0; j < 10; j++)
					m->matriz[i][j] = 0;
		imprime(m);
		usleep(50000);
		for(i = 0; i < 20; i++)
			if(linhas[i])
				for(j = 0; j < 10; j++)
					m->matriz[i][j] = 1;
		imprime(m);
	}
	/* realmente elimina as linhas */
	for(i = 19; i > 0; i--)
		if(linhas[i])
		{
			for(k = i-1; k > 0; k--)
				for(j = 0; j < 10; j++)
					m->matriz[k+1][j] = m->matriz[k][j];
			for(j = 0; j < 10; j++)
				m->matriz[0][j] = 0;
		}
	

}
void move_peca(matriz *m)
{
	int i, j;
	char colidiu = 0;
	/* verifica se o proximo movimento há colisao */
	for(j = 0; j < 10; j++)
		if(m->matriz[19][j] == 2)
			colidiu = 1;
	for(i = 18; i >= 0; i--)
		for(j = 0; j < 10; j++)
			if(m->matriz[i][j] == 2 && m->matriz[i+1][j] == 1)
				colidiu = 1;
	/* move caso não colida*/
	if(!colidiu)
	{
		for(i = 18; i >= 0; i--)
			for(j = 0; j < 10; j++)
				if(m->matriz[i][j] == 2)
				{
					m->matriz[i+1][j] = 2;
					m->matriz[i][j] = 0;
				}
	}
	else
	{
		/* como colidiu, transforma todos os 2 em 1 */
		for(i = 0; i < 20; i++)
			for(j = 0; j < 10; j++)
				if(m->matriz[i][j] == 2)
					m->matriz[i][j] = 1;
		/* verifica se e necessario eliminar linha */
		for(i = 19; i >= 0; i--)
		{
			colidiu = 0;
			for(j = 0; j < 9; j++)
				if(m->matriz[i][j] == 0)
					colidiu = 1;
			if(!colidiu)
			{
				elimina_linhas(m);
				break;
			}
		}
	}
}

void gira_move_peca(matriz *m, char *re)
{
	int i, j, colidiu = 0;
	if(*re == 'a') /* esquerda */
	{
		for(i = 0; i < 20; i++)
		{
			if(m->matriz[i][0] == 2)
				colidiu = 1;
		}
		if(!colidiu)
		{
			for(j = 1; j<10; j++)
				for(i = 0; i<20; i++)
					if(m->matriz[i][j] == 2)
					{
						m->matriz[i][j-1] = 2;
						m->matriz[i][j] = 0;
					}
		}
	}
	else if(*re == 's') /* horario */
	{

	}
	else if(*re == 'd') /* direita */
	{
		for(i = 0; i < 20; i++)
			if(m->matriz[i][9] == 2)
				colidiu = 1;
		if(!colidiu)
		{
			for(j = 8; j>=0; j--)
				for(i = 0; i<20; i++)
					if(m->matriz[i][j] == 2)
					{
						m->matriz[i][j+1] = 2;
						m->matriz[i][j] = 0;
					}
		}
	}
	else if(*re == 'w') /* antihorario */
	{

	}
	*re = '-';
}

int main()
{
	matriz m;
	char resp;
	int i;
	limpa_matriz(&m);
	while(1)
	{
		
		for(i = 0; i < 10; i++)
		{
			imprime(&m);
			while(kbhit())
			{
				resp = getch();
				if(resp == 27)
					return 0;
				gira_move_peca(&m, &resp);
			}
			usleep(10000);
		}
		if(nao_existe_peca(&m))
		{
			poe_peca(&m);
			limpa_buffer();
		}
		else
			move_peca(&m);

	}
}