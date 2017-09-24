

#define HEAL_POTION 30
#define C_X 		75
#define C_Y 		25
#define ARMOR		'a'
#define WEAPON 		'w'
#define MASK 		'm'
#define POTION 		'p'
#define MONEY 		'$'
#define PERSON 		'@'
#define VAMPIRE 	'V'
#define WALL 		'#'
#define P_FECHADA 	'+'
#define P_ABERTA 	'-'
#define W_SELL 		'W'
#define M_SELL 		'M'
#define A_SELL 		'A'
#define P_SELL 		'P'

typedef struct
{
	char simb;
	int x, y;
	int atributo;
	int valor;
	int peso;
}ITEM;

typedef struct 
{
	char nome[30];
	int hp, hpmax;
	int ataque;
	int precisao;
	int lifesteal;
	int pocoes;
	int x, y;
	int xp, xpmax;
	int lvl;
	int moedas;
	int peso;
	char acao;
	int cont;
	ITEM weapon, armor, mask;
}VAMPIRO;

typedef struct
{
	char m[C_Y][C_X+1];
}MAPA;

ITEM new_ITEM(char tipo, int atributo, int peso, int valor)
{
	ITEM i;
	i.valor = valor;
	i.peso = peso;
	i.atributo = atributo;
	i.x = i.y = 0;
	i.simb = tipo;
	return i;
}

ITEM none_ITEM()
{
	return new_ITEM(' ', 0, 0, 0);
}


VAMPIRO new_VAMPIRO(int x, int y, int lvl)
{
	VAMPIRO v;
	v.lvl 			= lvl;
	v.ataque 		= 5 + lvl;
	v.hp = v.hpmax 	= 100+10*lvl;
	v.peso 			= 0;
	v.precisao 		= 100-v.peso;
	v.lifesteal 	= 0;
	v.x 			= x;
	v.y 			= y;
	v.pocoes 		= 0;
	v.moedas 		= 0;
	v.xp 			= 0;
	v.xpmax 		= 2*lvl;
	v.weapon = v.armor = v.mask = none_ITEM();
	v.cont 			= 0;
	return v;
}

void add_moeda(int q, VAMPIRO *v)
{
	v->moedas += q;
}
void add_potion(int q, VAMPIRO *v)
{
	v->pocoes += q;
	v->peso   += q;
}
void set_item(ITEM i, VAMPIRO *v) /* Sobre soltar itens*/
{
	if(i.simb == WEAPON)
	{
		v->ataque -= v->weapon.atributo;
		v->weapon = i;
		v->ataque += v->weapon.atributo;
		v->lifesteal = ((v->mask.atributo)*(v->ataque))/100;
	}
	else if(i.simb == ARMOR)
	{
		v->hpmax -= v->armor.atributo;
		v->armor = i;
		v->hpmax += v->armor.atributo;
	}
	else if(i.simb == MASK)
	{
		v->mask = i;
		v->lifesteal = ((v->mask.atributo)*(v->ataque))/100;
	}
	else if(i.simb == POTION)
	{
		v->pocoes += i.atributo;
		v->peso += i.atributo;
	}
	else if(i.simb == MONEY)
		add_moeda(i.atributo, v); 

}

void morre(VAMPIRO *v)
{
	v->lvl 	  -= v->lvl == 1 ? 0 : 1;
	v->ataque -= 1;
	v->hpmax  -= 10;
	v->xpmax  /= 2;
	v->xp      = 0;
	v->hp      = v->hpmax; 
	v->moedas /= 2;
	v->x 	   = 5;
	v->y 	   = 12;
}

void evolui_nivel(VAMPIRO *v)
{
	v->lvl += 1;
	v->xp  -= v->xpmax;
	v->xpmax *= 2;
	v->hpmax += 10;
	v->ataque += 1;
	v->lifesteal = (v->ataque*(v->weapon.atributo))/100;
}