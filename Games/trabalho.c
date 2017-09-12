/* funcoes */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include "kbhitgetch.h"
#define ENTER 10
#define ESC 27
#define SAIR 0
#define espaco 20
/* rank */
/* leitura escrita */
#define player 10
#define carac 10
#define jogos 12
#define bin "bin"
#define read "rb"
#define write "wb+"
/* Outras bibliotecas */

void h()
{

}
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

#include "0.funcoes.h"
#include "leitura_escrita.h"
#include "13.ranks.h"
#include "1.senha.h" 
#include "2.charadas.h"
#include "3.pedra_papel_tesoura.h"
#include "4.2048.h"
#include "5.jogo_da_velha.h"
#include "6.jogo_da_memoria.h"
#include "7.xadrez.h"
#include "8.campo_minado.h"
#include "9.roda_roda.h"
#include "10.cobrinha.h"
#include "11.pacman.h"
#include "12.labirinto.h"


int main()
{
	int opcao, posicao[jogos];
	char string[20];
	geral score[player], dado;
	completo record[jogos];
	void menu_principal()
	{
		system("clear");
		printf("\n");
		printf("\t***********************\n");
		printf("\t* A Taverna de Mangix *\n");
		printf("\t***********************\n");
		printf("\n");
		printf("Menu:\n");
		printf("    a) Senha\n");
		printf("    b) Charadas!\n");
		printf("    c) PTP\n");
		printf("    d) 2048\n");
		printf("    e) Jogo da Velha\n");
		printf("    f) Jogo da Memória\n");
		printf("    g) Xadrez!\n");
		printf("    h) Campo minado\n");
		printf("    i) Roda a roda\n");
		printf("    j) Cobrinha\n");
		printf("    k) Pac-Man\n");
		printf("    l) Labirinto\n");
		printf("    z) Toca dos Feras!\n\n");
		printf("    ESC) Sair\n");
		printf("\n");
		printf(" Digite sua opcao: ");
	}
	void boas_vindas()
	{
		system("clear");
		printf("Olá %s. Seja bem vindo à Taverna de Mangix, o Mestre Cervejeiro!\n\n", dado.nome);
		printf("Vê-se que és novo no jogo. Sente-se comigo e aproveite de uma cerveja!\n\n");
		printf("    wwwww                           _________________________        ____________ \n");
		printf("  </ . . \\>                        /                        /       /          /| \n");
		printf("   \\  v  /              ________  /   .   |_|    |_|       /       /          / / \n");
		printf(" ___|;;;|__            /       / /   / \\                  /       /          / / \n");
		printf("/          \\          /_______/ /    | |   |_|           /|      /          / /\n");
		printf("| /\\    /\\ |            |   |  /     |_|                / |     /          / / \n");
		printf("| ||    || |            |___| /                        /| |    /          / /  \n");
		printf("[_]/ /\\ \\[_]      ________   /________________________/ | |   /          / / \n");
		printf("  | /  \\ |       /       /    | |   | |           | |   | |  /          / / \n");                              
		printf("  / |  | \\      /_______/     | |   | |           | |   | | /          / /   \n");
		printf("  | |  | |        |   |       | |   | |           | |   | |/__________/ /   \n");
		printf(" <__]  [__>       |___|       | |   |_|           | |   |_||__________|/  \n");
		printf("                              | |                 | |         |   | /    \n");
		printf("                              |_|                 |_|         |___|/     \n");
	}
	void imp()
	{
		printf("\n\ncom");
		if(dado.total < 10)
			printf("     ");
		else if(dado.total < 100)
			printf("    ");
		else if(dado.total < 1000)
			printf("   ");
		else if(dado.total < 10000)
			printf("  ");
		else if(dado.total < 100000)
			printf(" ");
		printf("%d pontos: %s\n", dado.total, dado.nome);
		printf("\t              Senha: %d\n", *(dado.point+0));
		printf("\t           Charadas: %d\n", *(dado.point+1));
		printf("\tPedra Papel Tesoura: %d\n", *(dado.point+2));
		printf("\t               2048: %d\n", *(dado.point+3));
		printf("\t      Jogo da Velha: %d\n", *(dado.point+4));
		printf("\t    Jogo da Memoria: %d\n", *(dado.point+5));
		printf("\t             Xadrez: %d\n", *(dado.point+6));
		printf("\t       Campo Minado: %d\n", *(dado.point+7));
		printf("\t        Roda a Roda: %d\n", *(dado.point+8));
		printf("\t           Cobrinha: %d\n", *(dado.point+9));
		printf("\t            Pac Man: %d\n", *(dado.point+10));
		printf("\t          Labirinto: %d\n\n", *(dado.point+11));
		aperte_tecla(ENTER);
	}
	limpar_um(&dado);
	limpa_tudo(score, record);
	system("clear");
	printf("Digite seu nome: ");
	scanf("%19[^\n]", string);
	opcao = -1;
	do
	{
		opcao++;
		dado.nome[opcao] = string[opcao];
	}while(string[opcao] != '\0');
	for(opcao = 0; opcao < jogos; opcao++)
		posicao[opcao] = 0;
	if(!existe_arquivo(bin))
	{
		boas_vindas();
		aperte_tecla(ENTER);
	}
	else
	{
		if(importar_dados(score, record))
			return 1;
		verifica_se_ja_jogou(score, &dado, record, string, posicao);
	}
	while(1)
	{
		menu_principal();
		opcao = pega_letra('a', 'l', 'z', 'z') - 'a' + 1;
		if(opcao == 1)
			senha(record, &dado, posicao);
		else if(opcao == 2)
			charadas(record, &dado, posicao);
		else if(opcao == 3)
			pedra_papel_tesoura(record, &dado, posicao);
		else if(opcao == 4)
			jogo_2048(record, &dado, posicao);
		else if(opcao == 5)
			jogo_da_velha(/*record*/);
		else if(opcao == 6)
			jogo_da_memoria(/*record*/);
		else if(opcao == 7)
			xadrez(/*record*/);
		else if(opcao == 8)
			campo_minado(record, &dado, posicao);
		else if(opcao == 9)
			roda_roda(record, &dado, posicao);
		else if(opcao == 10)
			cobrinha(record, &dado, posicao);
		else if(opcao == 11)
			pacman(record, &dado, posicao);
		else if(opcao == 12)
			labirinto(/*record, &dados_do_jogador*/);
		else if(opcao == 'z' - 'a' + 1)
			ranks(score);
		else if(opcao == 1 - 'a')
		{
			organizar_geral(score);
			escreve_tudo(score, record);
			printf("\n\n");
			return 0;
		}
		posicao[0] = organiza_posicao_geral(score, &dado, posicao[0]);
	}
}