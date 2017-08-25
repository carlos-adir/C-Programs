#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kbhitgetch.h"

#define CRITICAL 2
#define HEAL_POTION 20
#define CUSTO_ATAQUE 10
#define CUSTO_MAGIA 20

typedef struct
{
	int vida, mana;
	int porcoes;
	const int vida_max, mana_max, regen_mana;
	const int ataque, evasao, lifesteal;
	
	/*

	lifesteal é um valor entre 0 e 100(inclusive) e representa o tanto de vida que rouba
	No caso, se ataque = 10 e lifesteal = 70, então vida += 10*70/100 ---> vida += 7
	Para casos em que a divisão por 100 não seja exata(truncamento), utiliza-se o valor do truncamento(arredondamento para baixo)

	ja para evasao, valores entre 0 e 100 (inclusive) é a chance de acertar o oponente.
	Assim, se for 100 sempre desviará do golpe e caso for 0 sempre será acertado o golpe.

	*/

}vampiro;

vampiro set_vampiro(int vida_max, int mana_max, int porcoes, int regen_mana, int ataque, int evasao, int lifesteal)
{
	vampiro v = {vida_max, mana_max, porcoes, vida_max, mana_max, regen_mana, ataque, evasao, lifesteal};
	return v;
}

/* Para o programa dos alunos, não precisa da função */
/* Função para calcular a probabilidade do vampiro v1 vencer o vampiro v2 */
double prob_vencer(vampiro *v1, vampiro *v2)
{
	return 1;
}

void aperte_enter()
{
	char c;
	do
	{
		c = getchar();
	}while(c != '\n');
}

int acao(vampiro *v1, vampiro *v2, char resposta)
{
	int aleatorio = rand()%101;
	if(resposta == 'f')
		resposta = 1;
	else if(resposta == 'a')
		resposta = 2;
	else if(resposta == 'm')
		resposta = 3;
	else if(resposta == 'p')
		resposta = 4;
	else
	{
		return 9; /* Comando invalido, para imprimir a mensagem que a tecla digitada foi errada */
	}
	if(resposta == 1) /* 1 indica que é ataque forte */
	{
		if(v1->mana >= CUSTO_ATAQUE)
		{
			v1->mana -= CUSTO_ATAQUE;
			if(v2->evasao < aleatorio) /* se acertou o golpe */
			{
				v2->vida -= CRITICAL*v1->ataque;
				if(v1->vida > v1->vida_max)
					v1->vida = v1->vida_max;
				if(v2->vida < 0)
					v2->vida = 0;
				return 3; /* Executado com sucesso */
			}
			else
				return 4;
		}
		else
			return 1; /* Para o caso que não tem mana mas tentou usar a opcao */
	}
	else if(resposta == 2) /* 2 indica que é o ataque normal */
	{
		if(v2->evasao < aleatorio) /* se acertou o golpe */
		{
			v1->vida += (v1->ataque * v1->lifesteal)/100;
			v2->vida -= v1->ataque;
			if(v1->vida > v1->vida_max)
				v1->vida = v1->vida_max;
			if(v2->vida < 0)
				v2->vida = 0;
			return 5; /* Executado com sucesso */
		}
		else
			return 6;
	}
	else if(resposta == 3) /* 3 indica que é magia */
	{
		if(v1->mana >= CUSTO_MAGIA) /* A magia faz uma cura de mesmo valor do ataque do adversário e cura o adversário do seu valor de ataque */
		{
			v1->mana -= CUSTO_MAGIA;
			v1->vida += v2->ataque;
			v2->vida += v1->ataque;
			if(v1->vida > v1->vida_max)
				v1->vida = v1->vida_max;
			if(v2->vida > v2->vida_max)
				v2->vida = v2->vida_max;
			return 7;
		}
		else
			return 1;
	}
	else if(resposta == 4) /* 4 indica que é porcao */
	{
		if(v1->porcoes > 0) /* verifica se ainda tem alguma porcao */
		{
			v1->vida += HEAL_POTION; /* heal */
			if(v1->vida > v1->vida_max)
				v1->vida = v1->vida_max;
			v1->porcoes -= 1; /* diminui uma porcao */
			return 8;
		}
		else
			return 2; /* Informa que o usuario nao tem mais porcoes e pede novamente uma acao */
	}
	return 0;
}

void imp_mensagem(vampiro *v1, vampiro *v2, int mensagem)
{
	if(mensagem == 0)
		printf("\n\n");
	else if(mensagem == 1)
		printf("Voce nao tem mana suficiente!\n\n");
	else if(mensagem == 2)
		printf("Voce nao tem mais porcoes!\n\n");
	else if(mensagem == 3)
		printf("Voce acertou o ataque forte e causou %d de Dano!\n\n", 2*v1->ataque);
	else if(mensagem == 4)
		printf("Voce errou o ataque forte!\n\n");
	else if(mensagem == 5)
		printf("Voce acertou o ataque e causou %d de Dano se curando de %d!\n\n", v1->ataque, v1->ataque*v1->lifesteal/100);
	else if(mensagem == 6)
		printf("Voce errou o ataque!\n\n");
	else if(mensagem == 7)
		printf("Voce usou a magia e curou %d em ti e %d para o adversario!\n\n", v2->ataque, v1->ataque);
	else if(mensagem == 8)
		printf("Você usou uma porcao e curou %d\n\n", HEAL_POTION);
	else if(mensagem == 9)
		printf("Comando nao compreendido!\n\n");
	else if(mensagem == 11)
		printf("O adversario usou o ataque forte e causou %d de Dano!\n\n", 2*v2->ataque);
	else if(mensagem == 12)
		printf("O adversario errou o ataque forte!\n\n");
	else if(mensagem == 13)
		printf("O adversario acertou o ataque e causou %d de Dano e se curou %d!\n\n", v2->ataque, v2->ataque*v2->lifesteal/100);
	else if(mensagem == 14)
		printf("O adversario errou o ataque!\n\n");
	else if(mensagem == 15)
		printf("O adversario usou a magia e curou %d em ti e %d para o adversario!\n\n", v2->ataque, v1->ataque);
	else if(mensagem == 16)
		printf("O adversario usou uma porcao e se curou %d\n\n", HEAL_POTION);
}

void menu(vampiro *v1, vampiro *v2, int mensagem)
{
	fflush(stdin);
	system("clear");
	system("clear");
			
	printf("\n\n");
	printf("\t\t************\n");
	printf("\t\t* VAMPIROS *\n");
	printf("\t\t************\n");
	printf("\n\n\n");
	printf("Voce:        \t\t\tInimigo:\n");
	printf("Vida:      %03d/%03d\t\tVida:      %03d/%03d\n", v1->vida, v1->vida_max, v2->vida, v2->vida_max);
	printf("Mana:      %03d/%03d\t\tMana:      %03d/%03d\n", v1->mana, v1->mana_max, v2->mana, v2->mana_max);
	printf("Porcoes:   %02d\t\t\tPorcoes:   %02d\n", v1->porcoes, v2->porcoes);
	printf("Ataque:    %02d\t\t\tAtaque:    %02d\n", v1->ataque, v2->ataque);
	printf("Lifesteal: %02d\t\t\tLifesteal: %02d\n", (v1->ataque*v1->lifesteal)/100, (v2->ataque*v2->lifesteal)/100);
	printf("Acerto:    %03d%%\t\t\tAcerto:    %03d%%\n", 100-v2->evasao, 100-v1->evasao);

	imp_mensagem(v1, v2, mensagem);

	printf("f) Atacar forte! - ");
	if(v1->mana >= CUSTO_ATAQUE)
		printf("Usar %d de mana\n", CUSTO_ATAQUE);
	else
		printf("Sem mana suficiente\n");
	printf("a) Atacar!\n");
	printf("m) Magia!        - ");
	if(v1->mana >= CUSTO_MAGIA)
		printf("Usar %d de mana\n", CUSTO_MAGIA);
	else
		printf("Sem mana suficiente\n");
	printf("p) Potion!       - ");
	if(v1->porcoes > 0)
		printf("%d %s\n", v1->porcoes, v1->porcoes == 1 ? "disponivel" : "disponiveis");
	else
		printf("Sem porcoes\n");
	
	printf("r) Recuar!\n\n");
}

int main()
{
	char resposta = 0;
	/* vida, mana, porcao, regen_vida, regen_mana, ataque, evasao, lifesteal */
	vampiro v1 = set_vampiro(100, 20, 2, 1, 10, 70, 50);
	vampiro v2 = set_vampiro(50, 70, 1, 2, 10, 30, 80);
	srand((unsigned)time(NULL));
	while(1)
	{
		do
		{

			menu(&v1, &v2, resposta);
			printf("Digite sua opcao: ");
			resposta = getchar();
			getchar();
			if(resposta == 'r') /* Indica que quer recuar */
				return 0;
			resposta = acao(&v1, &v2, resposta);
		}while(resposta == 9 || resposta == 1 || resposta == 2); /* Para o caso em que nao tem mais porcoes ou nao tem mais mana */
		menu(&v1, &v2, resposta);
		aperte_enter();
		do
		{
			resposta = rand()%4 + 1;
			if(resposta == 1)
				resposta = 'f';
			else if(resposta == 2)
				resposta = 'a';
			else if(resposta == 3)
				resposta = 'm';
			else if(resposta == 4)
				resposta = 'p';
			resposta = acao(&v2, &v1, resposta);
		}while(resposta == 9 || resposta == 1 || resposta == 2);
		resposta += 8;
		menu(&v1, &v2, resposta);
		aperte_enter();
		resposta = 0;
	}
	menu(&v1, &v2, resposta);
	if(v1.vida == 0 || resposta == 'r')
		printf("\n\nVoce perdeu! Boa sorta na proxima vez!\n");
	else
		printf("\n\nVoce ganhou! Parabens!\n");

	return 0;
}