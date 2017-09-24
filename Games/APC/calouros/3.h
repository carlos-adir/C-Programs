int pode_se_mover(char c)
{
	if(c == ' ' || c == '-' || c == 'a' || c == 'w' || c == 'm' || c == 'p' || c == '$')
		return 1;
	return 0;
}
int inimigo_lado_usuario(VAMPIRO *v, VAMPIRO *w)
{
	if(v->x == w->x)
	{
		if(v->y == w->y - 1)
			return 1;
		if(v->y == w->y + 1)
			return 1;
	}
	else if(v->y == w->y)
	{
		if(v->x == w->x - 1)
			return 1;
		if(v->x == w->x + 1)
			return 1;
	}
	return 0;
}
void set_vampiros(VAMPIRO *inimigos)
{
	*(inimigos+0 ) = new_VAMPIRO(17, 12,  1);

	*(inimigos+1 ) = new_VAMPIRO(15,  8,  3);
	*(inimigos+2 ) = new_VAMPIRO(11, 18,  3);
	
	*(inimigos+3 ) = new_VAMPIRO( 6,  5,  7);
	*(inimigos+4 ) = new_VAMPIRO(26, 13,  7);
	*(inimigos+5 ) = new_VAMPIRO( 9, 22,  7);

	*(inimigos+6 ) = new_VAMPIRO(27, 19, 11);
	*(inimigos+7 ) = new_VAMPIRO(20	,  3, 11);

	*(inimigos+8 ) = new_VAMPIRO(36, 18, 14);
	*(inimigos+9 ) = new_VAMPIRO(36,  5, 14);

	*(inimigos+10) = new_VAMPIRO(36, 12, 17);

	*(inimigos+11) = new_VAMPIRO(46,  4, 21);
	*(inimigos+12) = new_VAMPIRO(57,  4, 21);
	*(inimigos+13) = new_VAMPIRO(68,  4, 21);
	*(inimigos+14) = new_VAMPIRO(45, 21, 21);
	*(inimigos+15) = new_VAMPIRO(57, 21, 21);
	*(inimigos+16) = new_VAMPIRO(68, 21, 21);
	
	*(inimigos+17) = new_VAMPIRO(68, 12, 25);	
}
int combate(VAMPIRO *inimigo, VAMPIRO *usuario)
{
	char resposta;
	while(1)
	{
		system("clear");
		printf("O que voce quer:\n");
		printf("1) Matar o vampiro\n");
		printf("2) Morrer\n");
		resposta = getch();
		if(resposta == '1')
			return 1;
		else if(resposta == '2')
			return 2;
	}
}