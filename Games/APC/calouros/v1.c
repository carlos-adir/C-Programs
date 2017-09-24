#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "kbhitgetch.h"



#include "1.h"
ITEM new_ITEM(char tipo, int atributo, int peso, int valor);
ITEM none_ITEM();
VAMPIRO new_VAMPIRO(int x, int y, int lvl);
void add_moeda(int q, VAMPIRO *v);
void add_potion(int q, VAMPIRO *v);
void set_item(ITEM i, VAMPIRO *v);
void perde_um_level(VAMPIRO *v);

#include "2.h"
void set_mapa(MAPA *mapa);
void inicia_mapas(MAPA *mapas);
void imprime_menu(MAPA *mapas, VAMPIRO *usuario, int relatorio);
void abre_porta(MAPA *mapas, int i);
void fecha_portas(MAPA *mapas);

#include "3.h"
int pode_se_mover(char c);
int inimigo_lado_usuario(VAMPIRO *v, VAMPIRO *w);
void set_vampiros(VAMPIRO *inimigos);
int combate(VAMPIRO *inimigo, VAMPIRO *usuario);

#include "4.h"
int em_cima_de_item(char c);
ITEM item_aleatorio();
void cria_todos_itens(MAPA *mapas, ITEM *itens, int q);
void coloca_itens_na_tela(MAPA *mapas, ITEM *itens, int q);
int pega_item(ITEM *item, VAMPIRO *v);
void coloca_vampiros_na_tela(MAPA *mapas, VAMPIRO *inimigos, int q);
void respawn(MAPA *mapas, VAMPIRO *inimigos, int q);
char to_NPC(char a, char b, char c, char d);
char Weapon(VAMPIRO *v);
char Armor(VAMPIRO *v);
char Potion(VAMPIRO *v);
char Mask(VAMPIRO *v);

int main()
{
	MAPA mapas[2];
	VAMPIRO usuario;
	VAMPIRO inimigos[18];
	ITEM itens[10];
	int q_itens = 15;
	int i;
	int relatorio = 0;
	char NPC;
	char resposta = ' ';

	srand((unsigned)time(NULL));

	inicia_mapas(mapas);
	cria_todos_itens(mapas, itens, q_itens);
	coloca_itens_na_tela(mapas, itens, q_itens);

	usuario = new_VAMPIRO(5, 12, 1);
	usuario.pocoes 	= 3;
	usuario.moedas 	= 100;
	usuario.hp 		= 30;
	
	set_vampiros(inimigos);
	coloca_vampiros_na_tela(mapas, inimigos, 18);
	(mapas+1)->m[usuario.y][usuario.x] = '@';


	while(resposta != '\n')
	{
		imprime_menu(mapas, &usuario, relatorio);
		relatorio = 0;
		do
		{
			resposta = getch();
		}while(resposta != 'w' && resposta != 's' && resposta != 'd' && resposta != '\n' &&
				resposta != 'a' && resposta != 'o' && resposta != 'p' && resposta != 'c');
		if(resposta == 'w')
		{
			if(pode_se_mover(mapas->m[usuario.y-1][usuario.x]))
			{
				(mapas+1)->m[usuario.y][usuario.x] = ' ';
				usuario.y -= 1;
				(mapas+1)->m[usuario.y][usuario.x] = '@';
			}
			else
				relatorio = 1;
		}
		else if(resposta == 's')
		{
			if(pode_se_mover(mapas->m[usuario.y+1][usuario.x]))
			{
				(mapas+1)->m[usuario.y][usuario.x] = ' ';
				usuario.y += 1;
				(mapas+1)->m[usuario.y][usuario.x] = '@';
			}
			else
				relatorio = 1;
		}
		else if(resposta == 'a')
		{
			if(pode_se_mover(mapas->m[usuario.y][usuario.x-1]))
			{
				(mapas+1)->m[usuario.y][usuario.x] = ' ';
				usuario.x -= 1;
				(mapas+1)->m[usuario.y][usuario.x] = '@';
			}
			else
				relatorio = 1;
		}
		else if(resposta == 'd')
		{
			if(pode_se_mover(mapas->m[usuario.y][usuario.x+1]))
			{
				(mapas+1)->m[usuario.y][usuario.x] = ' ';
				usuario.x += 1;
				(mapas+1)->m[usuario.y][usuario.x] = '@';
			}
			else
				relatorio = 1;
		}
		else if(resposta == 'c')
		{
			i = 0;
			while(!inimigo_lado_usuario(inimigos + i, &usuario) && i < 18)
				i += 1;
			if(inimigo_lado_usuario(inimigos + i, &usuario))
			{
				if((inimigos+i)->hp > 0)
				{
					relatorio = combate(inimigos+i, &usuario);
					if(relatorio == 1) /* Usuario matou inimigo */
					{
						usuario.moedas += (inimigos+i)->lvl;
						usuario.xp 	   += (inimigos+i)->lvl;
						if(usuario.xp >= usuario.xpmax)
							evolui_nivel(&usuario);
						mapas->m[(inimigos+i)->y][(inimigos+i)->x] = 'M';
						(inimigos+i)->hp = 0;
						(inimigos+i)->cont = 0;
						abre_porta(mapas, i);
					}
					else if(relatorio == 2) /* Inimigo matou usuario */
					{
						(mapas+1)->m[usuario.y][usuario.x] = ' ';
						morre(&usuario);
						(mapas+1)->m[usuario.y][usuario.x] = '@';
						fecha_portas(mapas);
					}
					else /* Usuario fugiu do combate */
					{}
				}
				else
				{
					printf("Não pode combater um morto!\n");
					relatorio = 3;
					continue;
				}
			}
			else
				relatorio = 4;
		}
		else if(resposta == 'o')
		{
			NPC = to_NPC(mapas->m[usuario.y-1][usuario.x], mapas->m[usuario.y+1][usuario.x],
						mapas->m[usuario.y][usuario.x-1], mapas->m[usuario.y][usuario.x+1]);
			if(NPC == 'A')
				Armor(&usuario);
			else if(NPC == 'M')
				Mask(&usuario);
			else if(NPC == 'P')
				Potion(&usuario);
			else if(NPC == 'W')
				Weapon(&usuario);
			else
				relatorio = 3;
		}
		else if(resposta == 'p')
		{
			i = 0;
			/* Loop para identificar qual item o usuario esta em cima */
			while( ((itens+i)->x != usuario.x || (itens+i)->y != usuario.y) && i < q_itens) 
				i += 1;
			/* Verifica mesmo se existem o item, caso sim ele pega o item */
			if(  (itens+i)->x == usuario.x && (itens+i)->y == usuario.y && (itens+i)->simb != ' ' )
			{
				relatorio = pega_item(itens+i, &usuario);
				mapas->m[usuario.y][usuario.x] = (itens+i)->simb;
			}
			else
				relatorio = 3;
		}
		else
			continue;
		respawn(mapas, inimigos, 18);
		
	}
	return 0;
}