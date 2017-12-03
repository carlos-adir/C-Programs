#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "inputv2.h"
#include "entrada.h"
#define tempo 1000*1000*3 // para ficar no maximo 100 segundos

unsigned long int func(int x) // Funcao normalizada
{
	double s;
	double k = x/100.0;
	s = -1.785714;
	s = s*k + 7.02381;
	s = s*k - 6.83929;
	s = s*k + 2.60119;
	s = s*k; // Ate aqui, s <= 1
	//printf("s = %lf\n", s*100*1000);
	return s*tempo;
}

void menu_carregando(int m)
{
	/*
	limpa_tela();;
	printf("\n\n");
	printf("    ███████╗███╗ ███╗██████╗ ██████╗ ███████╗ ██████╗ ██████╗ █████╗ ███████╗ ██████╗ \n");
	printf("    ██╔════╝  ████╔═╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██╔══██╗██╔════╝██╔════╝ \n");
	printf("    █████╗     ██╔╝  ██████╔╝██████╔╝█████╗   █████╗  █████╗ ██║  ██║█████╗   █████╗  \n");
	printf("    ██╔══╝    ████╗  ██╔═══╝ ██╔══██╗██╔══╝       ██╗     ██╗██║  ██║██╔══╝       ██╗ \n");
	printf("    ███████╗███╔═███╗██║     ██║  ██║███████╗██████╔╝██████╔╝ █████╔╝███████╗██████╔╝ \n");
	printf("    ╚══════╝╚══╝ ╚══╝╚═╝     ╚═╝  ╚═╝╚══════╝╚═════╝ ╚═════╝  ╚════╝ ╚══════╝╚═════╝  \n");
	printf("        ███╗   ███╗ █████╗ ██████╗  █████╗         ██████╗ ██████╗ ███╗ ██╗ \n");
	printf("        ████╗ ████║██╔══██╗██╔══██╗██╔══██╗        ██╔══██╗██╔══██╗████╗██║ \n");
	printf("        ██╔████╔██║██║  ██║██║  ██║██║  ██║        ██████╔╝██████╔╝███████║ \n");
	printf("        ██║╚██╔╝██║██║  ██║██║  ██║██║  ██║        ██╔══██╗██╔═══╝ ██╔████║ \n");
	printf("        ██║ ╚═╝ ██║ █████╔╝██████╔╝ █████╔╝        ██║  ██║██║     ██║╚███║ \n");
	printf("        ╚═╝     ╚═╝ ╚════╝ ╚═════╝  ╚════╝         ╚═╝  ╚═╝╚═╝     ╚═╝ ╚══╝ \n");
	printf("   ███████╗ █████╗ ██╗    ███████╗██╗  ██╗██╗     █████╗ ██████╗  █████╗ ██████╗  █████╗  \n");
	printf("   ██╔════╝██╔══██╗██║    ██╔════╝██║  ██║██║    ██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗ \n");
	printf("   ██║     ███████║██║    ██║     ██║  ██║██║    ███████║██║  ██║██║  ██║██████╔╝███████║ \n");
	printf("   ██║     ██╔══██║██║    ██║     ██║  ██║██║    ██╔══██║██║  ██║██║  ██║██╔══██╗██╔══██║ \n");
	printf("   ███████╗██║  ██║██████╗███████╗███████║██████╗██║  ██║██████╔╝ █████╔╝██║  ██║██║  ██║ \n");
	printf("   ╚══════╝╚═╝  ╚═╝╚═════╝╚══════╝╚══════╝╚═════╝╚═╝  ╚═╝╚═════╝  ╚════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ \n");
	printf("      ██╗███╗ ██╗ ██████╗████████╗██████╗ ██╗  ██╗███████╗ █████╗ ███████╗ ██████╗ \n");
	printf("      ██║████╗██║██╔════╝╚══██╔══╝██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝██╔════╝ \n");
	printf("      ██║███████║ █████╗    ██║   ██████╔╝██║  ██║██║     ██║  ██║█████╗   █████╗  \n");
	printf("      ██║██╔████║     ██╗   ██║   ██╔══██╗██║  ██║██║     ██║  ██║██╔══╝       ██╗ \n");
	printf("      ██║██║╚███║██████╔╝   ██║   ██║  ██║╚█████╔╝███████╗ █████╔╝███████╗██████╔╝ \n");
	printf("      ╚═╝╚═╝ ╚══╝╚═════╝    ╚═╝   ╚═╝  ╚═╝  ╚═══╝ ╚══════╝ ╚════╝ ╚══════╝╚═════╝  \n");
	printf("\n\n");
	printf("     ██╗     █████╗  █████╗ ██████╗ ██╗███╗ ██╗███████╗ \n");
	printf("     ██║    ██╔══██╗██╔══██╗██╔══██╗██║████╗██║██╔════╝ \n");
	printf("     ██║    ██║  ██║███████║██║  ██║██║███████║██║████╗ \n");
	printf("     ██║    ██║  ██║██╔══██║██║  ██║██║██╔████║██║╚═██║ \n");
	printf("     ██████╗ █████╔╝██║  ██║██████╔╝██║██║╚███║███████║ \n");
	printf("     ╚═════╝ ╚════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝╚═╝ ╚══╝╚══════╝ \n");
	*/
	int j;
	system("clear");
	printf("\n\n\n\n");
	printf("\t\t\t██╗     █████╗  █████╗ ██████╗ ████╗███╗ ██╗███████╗ \n");
	printf("\t\t\t██║    ██╔══██╗██╔══██╗██╔══██╗╚██╔╝████╗██║██╔════╝ \n");
	printf("\t\t\t██║    ██║  ██║███████║██║  ██║ ██║ ███████║██║████╗ \n");
	printf("\t\t\t██║    ██║  ██║██╔══██║██║  ██║ ██║ ██╔████║██║╚═██║ \n");
	printf("\t\t\t██████╗ █████╔╝██║  ██║██████╔╝████╗██║╚███║███████║ \n");
	printf("\t\t\t╚═════╝ ╚════╝ ╚═╝  ╚═╝╚═════╝ ╚═══╝╚═╝ ╚══╝╚══════╝ \n");
	printf("\n\n\n\n");
	//printf("Loading bar: ");
	printf("   ");
	for(j = 0; j < m; j++)
		printf("█");
	for(j = m; j < 100; j++)
		printf(".");
	printf(" - [%02d/100]\n", m);
}

void loading()
{
	int i;
	unsigned long int delay[101];
	for(i = 0; i < 100; i++)
		delay[i] = func(i);
	delay[100] = tempo;
	for(i = 100; i >  0; i--)
		delay[i] -= delay[i-1];
	for(i = 0; i < 100; i++)
	{
		menu_carregando(i);
		usleep(delay[i]);
	}
	menu_carregando(100);
	//for(i = 0; i < 101; i++)
	//	printf("delay[%d] = %lu\n", i, delay[i]);
}

void imprime_professor(professor *p, int begin)
{
	int i, max;
	info *aux;
	max = p->q - begin < 30 ? 30 : p->q-begin;
	max = max > p->q ? p->q : max;
	begin = max-30 < 0 ? 0 : max-30;

	system("clear");
	printf("\n\n");
	printf("     ID: %04d\n", p->ID);
	printf("   Nome: %s\n", p->name);
	printf("   Info:\n");
	printf("\t   ___________________________________________________________________________________________________________\n");
	printf("\t   |          |      |         |        | Postura Profissional | Atuacao Profissional |  Autoavaliacao Aluno |\n");
	printf("\t   |   Turma  |  Ano | Periodo | Alunos |   media   |  desvio  |   media   |  desvio  |   media   |  desvio  |\n");
	printf("\t   -----------------------------------------------------------------------------------------------------------\n");
	for(i = begin; i < max; i++)
	{
		aux = *(p->list+i);
		printf("  %3d/%3d  | %08d | %04d |    %01d    |   %02d   |", i+1, p->q, aux->t, aux->a, aux->p, aux->q);
		printf("%s  %.2lf   |   %.2lf   |", aux->postura.med >= 10 ? " " : "  ", aux->postura.med, aux->postura.dp);
		printf("%s  %.2lf   |   %.2lf   |", aux->atuacao.med >= 10 ? " " : "  ", aux->atuacao.med, aux->atuacao.dp);
		printf("%s  %.2lf   |   %.2lf   |", aux->autoava.med >= 10 ? " " : "  ", aux->autoava.med, aux->autoava.dp);
		printf("\n");
	}
	printf("\t   -----------------------------------------------------------------------------------------------------------\n");
	
}

void inicia_mostrando(l_prof **lista)
{
	professor *p;
	l_prof *aux;
	KEY k;
	int begin = 0;
	int i = 0, contador = 0;
	int last_begin = 1, last_contador = 1;
	aux = *lista;
	p = &(aux->prof);
	while(1)
	{
		if(last_begin != begin || last_contador != contador)
		{
			imprime_professor(p, begin);
		}
		last_begin = begin;
		last_contador = contador;
		do
		{
			k = get_key();
			if(key_is_equal(k, "ESC"))
				return;
		}while(! ( key_is_equal(k, "LEFT_KEY") || key_is_equal(k, "UP_KEY") || key_is_equal(k, "RIGHT_KEY") || key_is_equal(k, "DOWN_KEY")));
		last_begin = begin;
		if(key_is_equal(k, "UP_KEY"))
		{
			begin += 1;
			if(begin > p->q-30)
				begin -= 1;
		}
		else if(key_is_equal(k, "DOWN_KEY"))
		{
			begin -= 1;
		}
		else
		{
			
			if(key_is_equal(k, "RIGHT_KEY"))
			{
				contador += 1;
				if(aux->next != NULL)
				{
					aux = aux->next;
					p = &(aux->prof);
				}
				else
					contador -= 1;
			}
			else if(key_is_equal(k, "LEFT_KEY"))
			{
				contador -= 1;
				if(contador < 0)
					contador = 0;
				else
				{
					i = 0;
					aux = *lista;
					while(i < contador && aux->next != NULL)
					{
						i++;
						aux = aux->next;
					}
					p = &(aux->prof);
				}
			}
			
		}
		if(begin < 0)
			begin = 0;

	}
	return;
	
}

//(s^2+3)/(s^3+2*s^2+s+7)
int main()
{
	bool rate;
	char file_name[] = "avaliacao_docentes/avaliacao_docentes.csv";
	l_prof **lista;
	rate = get_data(file_name, &lista);
	//if(1)
	if(rate == SUCESS)
	{
		printf("Sucesso!\n");
		//loading();
		inicia_mostrando(lista);
		free_lista(lista);
		lista = NULL;
	}
	else
	{
		system("clear");
		printf("Falha!\n");
		return 1;
	}
	//free_lista(lista);
	return 0;
}