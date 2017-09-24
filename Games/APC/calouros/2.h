void set_mapa(MAPA *mapa)
{
	strcpy(mapa->m[0 ], "###########################################################################");
	strcpy(mapa->m[1 ], "#          +                    #       #          #         #            #");
	strcpy(mapa->m[2 ], "#          #                    #       #          #         #            #");
	strcpy(mapa->m[3 ], "#          #                    #       #          #         #            #");
	strcpy(mapa->m[4 ], "#          #                    #       #          #         #            #");
	strcpy(mapa->m[5 ], "#          #                    +       #          #         #            #");
	strcpy(mapa->m[6 ], "#          ######################       #          #         #            #");
	strcpy(mapa->m[7 ], "#          #                    #       ###### ######### ########### ######");
	strcpy(mapa->m[8 ], "#          +                    #       #                                 #");
	strcpy(mapa->m[9 ], "############                    ####+####                 #################");
	strcpy(mapa->m[10], "# A    W   #########+########+###       #                 ######          #");
	strcpy(mapa->m[11], "#          #         #          #       #                 ######          #");
	strcpy(mapa->m[12], "#                    #          #       +                 ++++++          #");
	strcpy(mapa->m[13], "#          #         #          #       #                 ######          #");
	strcpy(mapa->m[14], "# M    P   #         #          #       #                 ######          #");
	strcpy(mapa->m[15], "####################+#+#############+####                 #################");
	strcpy(mapa->m[16], "#                    #          #       #                                 #");
	strcpy(mapa->m[17], "#                    #          #       ##### ########### ########### #####");
	strcpy(mapa->m[18], "#                    #          #       #          #           #          #");
	strcpy(mapa->m[19], "#                    #          #       #          #           #          #");
	strcpy(mapa->m[20], "########+#############          #       #          #           #          #");
	strcpy(mapa->m[21], "#                    #          #       #          #           #          #");
	strcpy(mapa->m[22], "#                    +          #######+#          #           #          #");
	strcpy(mapa->m[23], "#                    #                  #          #           #          #");
	strcpy(mapa->m[24], "###########################################################################");
}
void inicia_mapas(MAPA *mapas)
{
	int i, j;
	set_mapa(mapas);
	for(i = 0; i < C_Y; i++)
		for(j = 0; j < C_X; j++)
			(mapas+1)->m[i][j] = ' ';

}
void imprime_menu(MAPA *mapas, VAMPIRO *usuario, int relatorio)
{
	int i, j;
	MAPA map;
	char lateral[25][21];
	/*system("clear");*/
	printf("                                ************\n");
	printf("                                * VAMPIROS *\n");
	printf("                                ************\n\n");
	
	sprintf(lateral[0 ], " LEVEL           %02d", 		usuario->lvl);
	sprintf(lateral[1 ], " EXPERIENCE   %02d/%02d", 	usuario->xp, usuario->xpmax%100);
	sprintf(lateral[2 ], " HIT POINTS %03d/%03d", 		usuario->hp, usuario->hpmax);
	sprintf(lateral[3 ], " ATAQUE          %02d", 		usuario->ataque);
	sprintf(lateral[4 ], " LIFESTEAL       %02d", 		usuario->lifesteal);
	sprintf(lateral[5 ], " POCOES          %02d", 		usuario->pocoes);
	sprintf(lateral[6 ], " PRECISAO       %03d", 		usuario->precisao);
	sprintf(lateral[7 ], " MOEDAS         %03d",		usuario->moedas);
	sprintf(lateral[8 ], "                   ");
	for(i = 9; i < C_Y; i++)
		sprintf(lateral[i], "                   ");
	for(i = 0; i < C_Y; i++)
	{
		for(j = 0; j < C_X; j++)
		{
			if((mapas+1)->m[i][j] != ' ')
				map.m[i][j] = (mapas+1)->m[i][j];
			else
				map.m[i][j] = mapas->m[i][j];
		}
		map.m[i][j] = '\0';
	}
	system("clear");
	for(i = 0; i < C_Y; i++)
		printf("%s %s\n",lateral[i], map.m[i]);
}

void abre_porta(MAPA *mapas, int i)
{
	if(i == 0)
	{
		mapas->m[10][20] = '-';
		mapas->m[15][20] = '-';
	}
	else if(i == 1)
	{
		mapas->m[ 8][11] = '-';
		mapas->m[10][29] = '-';
	}
	else if(i == 2)
		mapas->m[20][ 8] = '-';
	else if(i == 3)
		mapas->m[ 1][11] = '-';
	else if(i == 4)
		mapas->m[15][22] = '-';
	else if(i == 5)
		mapas->m[22][21] = '-';
	else if(i == 6)
		mapas->m[22][39] = '-';
	else if(i == 7)
		mapas->m[ 5][32] = '-';
	else if(i == 8)
		mapas->m[15][36] = '-';
	else if(i == 9)
		mapas->m[ 9][36] = '-';
	else if(i == 10)
		mapas->m[12][40] = '-';
	else if(i == 11)
		mapas->m[12][58] = '-';
	else if(i == 12)
		mapas->m[12][59] = '-';
	else if(i == 13)
		mapas->m[12][60] = '-';
	else if(i == 14)
		mapas->m[12][61] = '-';
	else if(i == 15)
		mapas->m[12][62] = '-';
	else if(i == 16)
		mapas->m[12][63] = '-';
}
void fecha_portas(MAPA *mapas)
{
	int i, j;
	for(i = 0; i < C_Y; i++)
		for(j = 0; j < C_X; j++)
			if(mapas->m[i][j] == '-')
				mapas->m[i][j] = '+';
}