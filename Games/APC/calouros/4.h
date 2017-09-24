int em_cima_de_item(char c)
{
	if(c == 'm' || c == 'w' || c == 'a' || c == 'p')
		return 1;
	return 0;
}
ITEM item_aleatorio()
{
	ITEM a[5][4];
	a[0][0] = new_ITEM('m', 80, 5, 20);
	a[0][1] = new_ITEM('m', 60, 5, 16);
	a[0][2] = new_ITEM('m', 40, 5, 12);
	a[0][3] = new_ITEM('m', 20, 5, 8);
	a[1][0] = new_ITEM('a', 80, 25, 20);
	a[1][1] = new_ITEM('a', 60, 23, 16);
	a[1][2] = new_ITEM('a', 40, 19, 13);
	a[1][3] = new_ITEM('a', 20, 12, 8);
	a[2][0] = new_ITEM('w', 20, 12, 32);
	a[2][1] = new_ITEM('w', 15, 9, 26);
	a[2][2] = new_ITEM('w', 10, 7, 20);
	a[2][3] = new_ITEM('w', 5, 5, 14);
	a[3][0] = new_ITEM('p', 1, 1, 2);
	a[3][1] = new_ITEM('p', 2, 1, 2);
	a[3][2] = new_ITEM('p', 3, 1, 2);
	a[3][3] = new_ITEM('p', 4, 1, 2);
	a[4][0] = new_ITEM('$', 4, 0, 0);
	a[4][1] = new_ITEM('$', 8, 0, 0);
	a[4][2] = new_ITEM('$', 12, 0, 0);
	a[4][3] = new_ITEM('$', 16, 0, 0);
	return a[rand()%5][rand()%4];
}
void cria_todos_itens(MAPA *mapas, ITEM *itens, int q)
{
	int i, x, y;
	for(i = 0; i < q; i++)
	{
		*(itens+i) = item_aleatorio();
		do
		{
			x = rand()%C_X;
			y = rand()%C_Y;
		}while(mapas->m[y][x] != ' ');
		(itens+i)->x = x;
		(itens+i)->y = y;
	}
}
void coloca_itens_na_tela(MAPA *mapas, ITEM *itens, int q)
{
	int i;
	for(i = 0; i < q; i++)
		mapas->m[(itens+i)->y][(itens+i)->x] = (itens+i)->simb;
}
void set_item(ITEM i, VAMPIRO *v);
int pega_item(ITEM *item, VAMPIRO *v)
{
	ITEM a;
	if(item->simb == 'w')
		a = v->weapon;
	else if(item->simb == 'a')
		a = v->armor;
	else if(item->simb == 'm')
		a = v->mask;
	else
		a = none_ITEM();
	set_item(*item, v);
	*item = a;
	return 1;
}

void coloca_vampiros_na_tela(MAPA *mapas, VAMPIRO *inimigos, int q)
{
	int i;
	for(i = 0; i < q; i++)
	{
		mapas->m[(inimigos+i)->y][(inimigos+i)->x] = 'V';
	}
}

void respawn(MAPA *mapas, VAMPIRO *inimigos, int q)
{
	int i;
	for(i = 0; i < q; i++)
	{
		if((inimigos+i)->cont == 3)
		{
			(mapas)->m[(inimigos+i)->y][(inimigos+i)->x] = 'V';
			(inimigos+i)->hp = (inimigos+i)->hpmax;
		}
		(inimigos+i)->cont += 1;
	}
}



char to_NPC(char a, char b, char c, char d)
{
	if(a == 'M' || b == 'M' || c == 'M' || d == 'M')
		return 'M';
	if(a == 'W' || b == 'W' || c == 'W' || d == 'W')
		return 'W';
	if(a == 'A' || b == 'A' || c == 'A' || d == 'A')
		return 'A';
	if(a == 'P' || b == 'P' || c == 'P' || d == 'P')
		return 'P';
	if(a == 'B' || b == 'B' || c == 'B' || d == 'B')
		return 'B';
	return ' ';
}

char Weapon(VAMPIRO *v)
{

}

char Armor(VAMPIRO *v)
{

}

char Potion(VAMPIRO *v)
{

}

char Mask(VAMPIRO *v)
{

}