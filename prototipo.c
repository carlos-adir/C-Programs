#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kbhitgetch.h"

#define HEAL_POTION 20
#define PROB_ATORDO 75
#define HEAL_BASE 10

typedef struct
{
	int vida, pocoes;
	const int ataque, vida_max;
	const char lifesteal, precisao;
	char estado; /* Recebe 1 se for ataque rapido,
					Recebe 2 se for ataque forte, 
					Recebe 3 se for defender, 
					Recebe 4 se for usar pocao,
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

typedef struct
{
	char acao1, resposta1; /* Acao e resposta do jogador 1 */
	char acao2, resposta2; /* Acao e resposta do jogador 2 */
}relatorio;

vampiro set_vampiro(int vida_max, int pocoes, int ataque, char lifesteal, char precisao)
{
	vampiro v = {vida_max, pocoes, ataque, vida_max, lifesteal, precisao, 0};
	return v;
}



/* Para o programa dos alunos, não precisa da função, é somente para */
/* Função para calcular a probabilidade do vampiro v1 vencer o vampiro v2 */
double prob_vencer(vampiro *v1, vampiro *v2)
{
	return 1;
}

relatorio combate(vampiro *v1, vampiro *v2)
{
	int ale1 = rand()%101; /* Variavel para verificar a chance de atordoar */
	int ale2 = rand()%101; /* Variavel para a acao do jogador 1 */
	int ale3 = rand()%101; /* Variavel para a acao do jogador 2 */
	relatorio re = {v1->estado, 0, v2->estado, 0};
	/* Um vetor para indicar se obteve sucesso no ataque escolhido, bem como as opções */
	
	if(v1->estado == 1) 
	{
		if(v2->estado == 1) /* Dois ataques rapidos */
		{
			if(ale2 < v1->precisao) /* Se o primeiro jogador acerta o golpe */
			{
				v2->vida -= v1->ataque;
				v1->vida += v1->ataque*v1->lifesteal/100;
				re.resposta1 = 1;
				printf("hamam");
			}
			if(ale3 < v2->precisao)/* Se o segundo jogador acerta o golpe */
			{
				v1->vida -= v2->ataque;
				v2->vida += v2->ataque*v2->lifesteal/100;
				re.resposta2 = 1;
			}
		}
		else if(v2->estado == 2) /* Ataque rapido com ataque forte */
		{
			if(ale2 < v1->precisao) /* Se o primeiro jogador acerta o golpe */
			{
				v2->vida -= v1->ataque;
				v1->vida += v1->ataque*v1->lifesteal/100;
				if(ale1 > PROB_ATORDO)
					v2->estado = 9;
				re.resposta1 = 1;
			}
			if(ale3 < v2->precisao) /* Se o segundo jogador acerta o golpe */
			{
				v1->vida -= 2*v2->ataque;
				re.resposta2 = 1;
			}
		}
		else if(v2->estado == 3) /* Ataque rapido contra defesa */
		{
			if(ale2 < v1->precisao)
			{
				v2->vida -= v1->ataque/2;
				v1->vida += v1->ataque*v1->lifesteal/200;
				re.resposta1 = 1;
			}
			if(ale1 > PROB_ATORDO) /* Se o segundo jogador acerta o golpe */
				v1->estado = 9;
			re.resposta2 = 1;
		}
		else if(v2->estado == 4)
		{
			if(ale2 < v1->precisao)
			{
				v1->vida += v1->ataque*v1->lifesteal/100;
				v2->vida -= v1->ataque;
				re.resposta1 = 1;
			}
			re.resposta2 = 1;
		}
		else
		{
			v1->vida += v1->ataque*v1->lifesteal/100;
			v2->vida -= v1->ataque;	
			re.resposta1 = re.resposta2 = 1;
		}
	}
	else if(v1->estado == 2)
	{
		if(v2->estado == 1) /* Ataque forte com ataque rapido */
		{
			if(ale2 < v1->precisao)
			{
				v2->vida -= 2*v1->ataque;
				re.resposta1 = 1;
			}
			if(ale3 < v2->precisao)
			{
				v1->vida -= v2->ataque;
				v2->vida += v2->ataque*v2->lifesteal/100;
				re.resposta2 = 1;
				if(ale1 > PROB_ATORDO) /* probabilidade de ser atordoado */
					v1->estado = 9;	
			}
		}
		else if(v2->estado == 2) /* Ataque forte com ataque forte */
		{
			if(ale2 < v1->precisao)
			{
				v2->vida -= 2*v1->ataque;
				re.resposta1 = 1;
			}
			if(ale3 < v2->precisao)
			{
				v1->vida -= 2*v2->ataque;
				re.resposta2 = 1;
			}
		}
		else if(v2->estado == 3) /* Ataque forte com defesa */
		{
			if(ale2 < v1->precisao)
			{
				v2->vida -= v1->ataque/2;
				re.resposta1 = 1;
			}
			v1->estado = 9;
			re.resposta2 = 1;
		}
		else if(v2->estado == 4)
		{
			if(ale2 < v1->precisao)
			{
				v2->vida -= 2*v1->ataque;
				re.resposta1 = 1;
			}
			re.resposta2 = 1;
		}
		else
		{
			v2->vida -= 2*v1->ataque;
			re.resposta1 = re.resposta2 = 1;
		}
	}
	else if(v1->estado == 3)
	{
		if(v2->estado == 1)
		{
			if(ale3 < v2->precisao)
			{
				v1->vida -= v2->ataque/2;
				v2->vida += v2->ataque*v2->lifesteal/200;
				re.resposta2 = 1;
			}
			if(ale1 > PROB_ATORDO)
				v2->estado = 9;
			re.resposta1 = 1;	
		}
		else if(v2->estado == 2)
		{
			if(ale3 < v2->precisao)
			{
				v1->vida -= v2->ataque/2;
				re.resposta2 = 1;
			}
			v2->estado = 9;
			re.resposta1 = 1;
		}
		else if(v2->estado == 3)
		{
			v1->vida += HEAL_BASE;
			v2->vida += HEAL_BASE;
			re.resposta1 = re.resposta2 = 1;
		}
		else if(v2->estado == 4)
		{
			v1->vida += HEAL_BASE;
			re.resposta1 = re.resposta2 = 1;
		}
	}
	else if(v1->estado == 4)
	{
		if(v2->estado == 1)
		{
			if(ale3 < v2->precisao)
			{
				v1->vida -= v2->ataque;
				v2->vida += v2->ataque*v2->lifesteal/100;
				re.resposta2 = 1;
			}
			re.resposta1 = 1;
		}
		else if(v2->estado == 2)
		{
			if(ale3 < v2->precisao)
			{
				v1->vida -= 2*v2->ataque;
				re.resposta2 = 1;
			}
			re.resposta1 = 1;
		}
		else if(v2->estado == 3)
		{
			v2->vida += HEAL_BASE;
			re.resposta1 = re.resposta2 = 1;
		}
	}
	else
	{
		if(v2->estado == 1)
		{
			v1->vida -= v2->ataque;
			v2->vida += v2->ataque*v2->lifesteal/100;
			re.resposta1 = re.resposta2 = 1;
		}
		else if(v2->estado == 2)
		{
			v1->vida -= 2*v2->ataque;
			re.resposta1 = re.resposta2 = 1;
		}
		else if(v2->estado == 3)
		{
			v2->vida += HEAL_BASE;
			re.resposta1 = re.resposta2 = 1;
		}
		else
			re.resposta1 = re.resposta2 = 1;
	}
	if(v1->estado == 4)
	{
		v1->vida += HEAL_POTION;
		v1->pocoes -= 1;
	}
	if(v2->estado == 4)
	{
		v2->vida += HEAL_POTION;
		v2->pocoes -= 1;
	}
	if(v1->estado != 9) /* Verifica se está atordoado para a proxima jogada */
		v1->estado = 0;
	if(v2->estado != 9) /* Verifica se está atordoado para a proxima jogada */
		v2->estado = 0;
	if(v1->vida < 0)
		v1->vida = 0;
	else if(v1->vida > v1->vida_max)
		v1->vida = v1->vida_max;
	if(v2->vida < 0)
		v2->vida = 0;
	else if(v2->vida > v2->vida_max)
		v2->vida = v2->vida_max;
	return re;
}

void msg(vampiro *v1, vampiro *v2, relatorio *re)
{
	if(re->acao1 == 1)
		printf("   Comando: Ataque Rapido! - Resultado: %s\n", re->resposta1 == 1 ? "Sucesso" : "Falha");
	else if(re->acao1 == 2)
		printf("   Comando: Ataque Forte!  - Resultado: %s\n", re->resposta1 == 1 ? "Sucesso" : "Falha");
	else if(re->acao1 == 3)
		printf("   Comando: Defesa!        - Resultado: %s\n", v2->estado == 9 ? "Você atordoou o adversário" : "Sofreu somente menos dano");
	else if(re->acao1 == 4)
		printf("   Comando: Pocao!         - Resultado: Curou %d de vida\n", HEAL_POTION);
	else
		printf("\n");
	if(re->acao2 == 1)
		printf("   Comando: Ataque Rapido! - Resultado: %s\n\n", re->resposta2 == 1 ? "Sucesso" : "Falha");
	else if(re->acao2 == 2)
		printf("   Comando: Ataque Forte!  - Resultado: %s\n\n", re->resposta2 == 1 ? "Sucesso" : "Falha");
	else if(re->acao2 == 3)
		printf("   Comando: Defesa!        - Resultado: %s\n\n", v1->estado == 9 ? "Atordoou você" : "Sofreu somente menos dano");
	else if(re->acao2 == 4)
		printf("   Comando: Pocao!         - Resultado: Curou %d de vida\n\n", HEAL_POTION);
	else
		printf("\n\n");
}

void menu(vampiro *v1, vampiro *v2, relatorio *re)
{
	system("clear");
	printf("\n");
	printf("   \t\t  ************\n");
	printf("   \t\t  * VAMPIROS *\n");
	printf("   \t\t  ************\n");
	printf("\n");
	printf("          Voce         |          Inimigo\n");
	printf("  Hit Points: %03d/%03d  |  Hit Points: %03d/%03d\n", v1->vida, v1->vida_max, v2->vida, v2->vida_max);
	printf("      Pocoes: %02d       |      Pocoes: %02d\n", v1->pocoes, v2->pocoes);
	printf("      Ataque: %02d       |      Ataque: %02d\n", v1->ataque, v2->ataque);
	printf("  Life-steal: %02d       |  Life-steal: %02d\n", (v1->ataque*v1->lifesteal)/100, (v2->ataque*v2->lifesteal)/100);
	printf("    Precisao: %03d%%     |    Precisao: %03d%%\n\n", v1->precisao, v2->precisao);
	
	if(v1->estado == 9)
		printf("    *** ATORDOADO ***             ");
	else if(v1->estado == 1)
		printf("          RAPIDO                  ");
	else if(v1->estado == 2)
		printf("          FORTE                   ");
	else if(v1->estado == 3)
		printf("        DEFENDER                  ");
	else if(v1->estado == 4)
		printf("         PORCAO                   ");
	else
		printf("                                  ");
	if(v2->estado == 9)
		printf("    *** ATORDOADO ***\n\n");
	else if(v2->estado == 1)
		printf("          RAPIDO\n\n");
	else if(v2->estado == 2)
		printf("          FORTE\n\n");
	else if(v2->estado == 3)
		printf("        DEFENDER\n\n");
	else if(v2->estado == 4)
		printf("         PORCAO\n\n");
	else
		printf("\n\n");

	msg(v1, v2, re);

	printf("  r) Ataque rapido!\n");
	printf("  f) Ataque forte!\n");
	printf("  d) Defender!\n");
	printf("  p) Porcao!\n");
	printf("  s) Sair!\n\n");
	printf("  Digite sua opcao: ");
}

int main()
{
	char resposta = ' ';
	relatorio re = {0, 0, 0, 0};
	vampiro v1 = set_vampiro(100, 1, 10, 70, 50);
	vampiro v2 = set_vampiro(50, 1, 10, 30, 80);
	srand((unsigned)time(NULL));
	while(resposta != 's')
	{
		while(v1.estado == 0)
		{ /* Captura a resposta do usuario*/
			menu(&v1, &v2, &re);
			resposta = getchar();
			getchar();
			if(resposta == 's')
			{
				printf("\n\n  Voce perdeu! Boa sorta na proxima vez!\n\n\n");
				return 0;
			}
			else if(resposta == 'r')
				v1.estado = 1;
			else if(resposta == 'f')
				v1.estado = 2;
			else if(resposta == 'd')
				v1.estado = 3;
			else if(resposta == 'p' && v1.pocoes > 0)
				v1.estado = 4;
		}
		if(v1.estado == 9)
			v1.estado = 0;
		/* Sorteia uma jogada do computador */
		while(v2.estado == 0)
		{
			v2.estado = rand()%4 + 1;
			if(v2.estado == 4 && v2.pocoes <= 0)
				v2.estado = 0;
		}
		if(v2.estado == 9)
			v2.estado = 0; /* Zero estado passivo, faz nada */
		/* Combate */
		re = combate(&v1, &v2);
		if(v2.vida == 0 || v1.vida == 0)
			break;
	}
	menu(&v1, &v2, &re);
	if(v1.vida == 0)
		printf("\n\n  Voce perdeu! Boa sorte na proxima vez!\n\n\n");
	else
		printf("\n\n  Voce ganhou! Parabens!\n\n\n");

	return 0;
}