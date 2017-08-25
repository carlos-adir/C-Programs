#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kbhitgetch.h"

#define HEAL_POTION 20
#define PROB_ATORDO 75
#define HEAL_BASE 10

typedef struct
{
	int vida, porcoes;
	const int ataque, vida_max;
	const char lifesteal, precisao;
	char estado; /* Recebe 1 se for ataque rapido,
					Recebe 2 se for ataque forte, 
					Recebe 3 se for defender, 
					Recebe 4 se for usar porcao,
					Recebe 9 se ficar atordoado
					Recebe 0 se nao houver acao, */
	/*

	lifesteal é um valor entre 0 e 100(inclusive) e representa o tanto de vida que rouba
	No caso, se ataque = 10 e lifesteal = 70, então vida += 10*70/100 ---> vida += 7
	Para casos em que a divisão por 100 não seja exata(truncamento), utiliza-se o valor do truncamento(arredondamento para baixo)

	ja para probabilidade, valores entre 0 e 100 (inclusive) é a chance de acertar o oponente.
	Assim, se for 100 sempre acertará o golpe e caso for 0 sempre errará o golpe.

	*/
}vampiro;

vampiro set_vampiro(int vida_max, int porcoes, int ataque, char lifesteal, char precisao)
{
	vampiro v = {vida_max, porcoes, ataque, vida_max, lifesteal, precisao, 0};
	return v;
}

/* Para o programa dos alunos, não precisa da função, é somente para */
/* Função para calcular a probabilidade do vampiro v1 vencer o vampiro v2 */
double prob_vencer(vampiro *v1, vampiro *v2)
{
	return 1;
}

int combate(vampiro *v1, vampiro *v2)
{
	int aleatorio = rand()%101;
	if(v1->estado == 1) 
	{
		if(v2->estado == 1) /* Dois ataques rapidos */
		{
			v1->vida -= v2->ataque;
			v2->vida -= v1->ataque;
			v1->vida += v1->ataque*v1->lifesteal/100;
			v2->vida += v2->ataque*v2->lifesteal/100;
		}
		else if(v2->estado == 2) /* Ataque rapido com ataque forte */
		{
			v1->vida -= 2*v2->ataque;
			v1->vida += v1->ataque*v1->lifesteal/100;
			v2->vida -= v1->ataque;
			if(aleatorio > PROB_ATORDO)
				v2->estado = 9;
		}
		else if(v2->estado == 3) /* Ataque rapido contra defesa */
		{
			v2->vida -= v1->ataque/2;
			v1->vida += v1->ataque*v1->lifesteal/100;
			if(aleatorio > PROB_ATORDO)
				v1->estado = 9;
		}
		else
		{
			v1->vida += v1->ataque*v1->lifesteal/100;
			v2->vida -= v1->ataque;
		}
	}
	else if(v1->estado == 2)
	{
		if(v2->estado == 1) /* Ataque forte com ataque rapido */
		{
			v2->vida -= 2*v1->ataque;
			v1->vida -= v2->ataque;
			v2->vida += v2->ataque*v2->lifesteal/100;
			if(aleatorio > PROB_ATORDO) /* probabilidade de ser atordoado */
				v1->estado = 9;	
		}
		else if(v2->estado == 2) /* Ataque forte com ataque forte */
		{
			v1->vida -= 2*v2->ataque;
			v2->vida -= 2*v1->ataque;
		}
		else if(v2->estado == 3) /* Ataque forte com defesa */
		{
			v2->vida -= v1->ataque/2;
			v1->estado = 9;
		}
		else
		{
			v2->vida -= 2*v1->ataque;
		}
	}
	else if(v1->estado == 3)
	{
		if(v2->estado == 1)
		{
			v1->vida -= v2->ataque/2;
			v2->vida += v2->ataque*v2->lifesteal/100;
			if(aleatorio > PROB_ATORDO)
				v2->estado = 9;	
		}
		else if(v2->estado == 2)
		{
			v1->vida -= v2->ataque/2;
			v2->estado = 9;
		}
		else if(v2->estado == 3)
		{
			v1->vida += HEAL_BASE;
			v2->vida += HEAL_BASE;
		}
		else if(v2->estado == 4)
			v1->vida += HEAL_BASE;
	}
	else /* Atordoado */
	{
		if(v2->estado == 1)
		{
			v1->vida -= v2->ataque;
			v2->vida += v2->ataque*v2->lifesteal/100;
		}
		else if(v2->estado == 2)
		{
			v1->vida -= 2*v2->ataque;
		}
		else if(v2->estado == 3)
		{
			v1->vida += HEAL_BASE;
			v2->vida += HEAL_BASE;
		}
	}
	if(v1->estado == 4)
		v1->vida += HEAL_POTION;
	if(v2->estado == 4)
		v2->vida += HEAL_POTION;
	if(v1->estado != 9)
		v1->estado = 0;
	if(v2->estado != 9)
		v2->estado = 0;
	return 0;
}

void menu(vampiro *v1, vampiro *v2)
{
	system("clear");
	printf("************\n");
	printf("* VAMPIROS *\n");
	printf("************\n");
	printf("\n\n\n");
	printf("Voce:        \t\t\tInimigo:\n");
	printf("Vida:      %03d/%03d\t\tVida:      %03d/%03d\n", v1->vida, v1->vida_max, v2->vida, v2->vida_max);
	printf("Porcoes:   %02d\t\t\tPorcoes:   %02d\n", v1->porcoes, v2->porcoes);
	printf("Ataque:    %02d\t\t\tAtaque:    %02d\n", v1->ataque, v2->ataque);
	printf("Lifesteal: %02d\t\t\tLifesteal: %02d\n", (v1->ataque*v1->lifesteal)/100, (v2->ataque*v2->lifesteal)/100);
	printf("Acerto:    %03d%%\t\t\tAcerto:    %03d%%\n\n", v1->precisao, v2->precisao);
	
	if(v1->estado == 9)
		printf("  *** ATORDOADO ***             ");
	else if(v1->estado == 1)
		printf("        RAPIDO                  ");
	else if(v1->estado == 2)
		printf("        FORTE                   ");
	else if(v1->estado == 3)
		printf("      DEFENDER                  ");
	else if(v1->estado == 4)
		printf("       PORCAO                   ");
	else
		printf("                                ");
	if(v2->estado == 9)
		printf("  *** ATORDOADO ***\n\n");
	else if(v2->estado == 1)
		printf("        RAPIDO\n\n");
	else if(v2->estado == 2)
		printf("        FORTE\n\n");
	else if(v2->estado == 3)
		printf("      DEFENDER\n\n");
	else if(v2->estado == 4)
		printf("       PORCAO\n\n");
	else
		printf("\n\n\n");

	printf("r) Ataque rapido!\n");
	printf("f) Ataque forte!\n");
	printf("d) Defender!\n");
	printf("p) Porcao!\n");
	printf("s) Sair!\n\n");
	printf("Digite sua opcao: ");
}

int main()
{
	char resposta = ' ';
	vampiro v1 = set_vampiro(100, 1, 10, 70, 50);
	vampiro v2 = set_vampiro(50, 1, 10, 30, 80);
	srand((unsigned)time(NULL));
	while(resposta != 's')
	{
		while(v1.estado == 0)
		{ /* Captura a resposta do usuario*/
			menu(&v1, &v2);
			resposta = getchar();
			getchar();
			if(resposta == 's')
			{
				printf("\n\nVoce perdeu! Boa sorta na proxima vez!\n");
				return 0;
			}
			else if(resposta == 'r')
				v1.estado = 1;
			else if(resposta == 'f')
				v1.estado = 2;
			else if(resposta == 'd')
				v1.estado = 3;
			else if(resposta == 'p' && v1.porcoes > 0)
				v1.estado = 4;
		}
		if(v1.estado == 9)
			v1.estado = 0;
		/* Sorteia uma jogada do computador */
		while(v2.estado == 0)
		{
			v2.estado = rand()%4 + 1;
			if(v2.estado == 4 && v2.porcoes <= 0)
				v2.estado = 0;
		}
		if(v2.estado == 9)
			v2.estado = 0; /* Zero estado passivo, faz nada */
		/* Combate */
		resposta = combate(&v1, &v2);

	}
	menu(&v1, &v2);
	if(v1.vida == 0)
		printf("\n\nVoce perdeu! Boa sorta na proxima vez!\n");
	else
		printf("\n\nVoce ganhou! Parabens!\n");

	return 0;
}