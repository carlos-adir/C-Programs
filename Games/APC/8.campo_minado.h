int campo_minado(completo *record, geral *dado, int *posicao)
{
	int numero_do_usuario, dificuldade=1, tamanho = 8, bombas = 2, fim, x, y, i, j;
	char gabarito[32][32], campo[32][32];
	void menu_opcoes()
	{
		system("clear");
		printf("****************\n");
		printf("* Campo Minado *\n");
		printf("****************\n");
		printf("\n");
		printf("1) Jogar\n");
		printf("2) Configurações\n");
		printf("3) Instrucoes\n");
		printf("4) Desarmadores de Bombas\n\n");
		printf("0) Sair\n");
		printf("\n");
		printf("Digite uma opcao:  ");
	}
	void jogar()
	{
		int coordenada[2] = {1,1};
		void menu_jogar()
		{
			system("clear");
			printf("****************\n");
			printf("* Campo Minado *\n");
			printf("****************\n");
			printf("\n");
		}
		void novo_campo()
		{
			srand((unsigned)time(NULL));
			for(i = 0; i<32; i++)
				for(j = 0; j<32; j++)
					campo[i][j] = '&';
			for(i = 0; i<32; i++)
				for(j = 0; j<32; j++)
					gabarito[i][j] = '0';
			i = 0;
			while(i < bombas)
			{
				do
				{
					x = rand()%tamanho;
					y = rand()%tamanho;
				}while(gabarito[x][y] == 'X');
				gabarito[x][y] = 'X';
				i++;
			}
			for(i = 0; i < tamanho; i++)
				for(j = 0; j < tamanho; j++)
					if(gabarito[i][j] == 'X')
						for(x = -1; x < 2; x++)
							for(y = -1; y < 2; y++)
								if(i + x >= 0 && i + x < tamanho)
									if(j + y >= 0 && j + y < tamanho)
										if(gabarito[i+x][j+y] != 'X')
											gabarito[i+x][j+y]++;
		}
		void imprimir()
		{
			printf("\n y x");
			for(i = 0; i<tamanho; i++)
			{
				if(i < 9)
					printf("  %d  ", i+1);
				else
					printf("  %d ", i+1);
			}
			printf("\n\n");
			for(i = 0; i < tamanho; i++)
			{
				if(i < 9)
					printf(" %d  ", i+1);
				else
					printf(" %d ", i+1);
				for(j = 0; j < tamanho; j++)
					printf("  %c  ", campo[i][j]);
				printf("\n\n");
			}
			printf("\n");
		}
		void liberar(int a, int b)
		{
			int w, z;
			if(campo[a][b] == '&')
			{
				campo[a][b] = gabarito[a][b];
				if(gabarito[a][b] == '0')
					for(w = -1; w<2; w++)
						for(z = -1; z<2; z++)
							if(a + z >= 0 && a + z < tamanho && b + w >= 0 && b + w < tamanho)
								liberar(a+z, b+w);
			}
		}
		int terminou() /* Retorna 2 caso tenha explodido, retorna 1 caso tenha ganhado, e 0 caso não tenha terminado */
		{
			int i, j, contador_de_bombas = 0;
			for(i = 0; i<tamanho; i++)
				for(j = 0; j < tamanho; j++)
				{
					if(campo[i][j] == 'X')
						return 2;
					if(campo[i][j] == '&')
						contador_de_bombas++;
				}
			if(contador_de_bombas == bombas)
				return 1;
			return 0;
		}
		novo_campo();
		do
		{
			menu_jogar();
			imprimir();
			if(coordenada[0] > 0 && coordenada[0] <= tamanho && coordenada[1] > 0 && coordenada[1] <= tamanho)
				printf("\n");
			else
				printf("As entradas são invalidas, coloque somente coordenadas validas(entre 1 e %d)\n", tamanho);
			printf("Digite a coordenada X:  ");
			coordenada[1] = pega_numero_grande();
			printf("Digite a coordenada Y:  ");
			coordenada[0] = pega_numero_grande();
			if(coordenada[0] > 0 && coordenada[0] <= tamanho && coordenada[1] > 0 && coordenada[1] <= tamanho)
				liberar(coordenada[0]-1, coordenada[1]-1);
			fim = terminou();
		}while(!fim);
		for(i = 0; i < tamanho; i++)
			for(j = 0; j < tamanho; j++)
				campo[i][j] = gabarito[i][j];
		if(fim == 2)
		{
			menu_jogar();
			imprimir();
			printf("Você perdeu! Que pena!");
		}
		else
		{
			menu_jogar();
			imprimir();
			printf("Parabéns, você ganhou!");
		}
		aperte_tecla(ENTER);
	}
	int configuracoes()
	{
		void menu_configuracoes()
		{
			system("clear");
			printf("****************\n");
			printf("* Campo Minado *\n");
			printf("****************\n");
			printf("\n");
			printf("1) Alterar a dificuldade(atual: %d)\n\n", dificuldade);
			printf("0) Voltar ao menu alterior\n");
		}
		while(1)
		{
			menu_configuracoes();
			numero_do_usuario = pega_algarismo(0, 1);
			if(numero_do_usuario == 1)
			{
				menu_configuracoes();
				printf("\nDigite a nova dificuldade(entre 1 e 4):  ");
				numero_do_usuario = pega_algarismo(0, 4);
				if(numero_do_usuario)
				{
					dificuldade = numero_do_usuario;
					tamanho = 4 + 4*dificuldade;
					bombas = 5 + 5*dificuldade;
				}
				aperte_tecla(ENTER);
			}
			else
				return 0;
		}
	}
	void instrucoes()
	{
		system("clear");
	    printf("Instrucoes!\n");
	    aperte_tecla(ENTER);
	}
	void rank_jogo()
	{
	  int i;
	  system("clear");
	  printf("***********************************************\n");
	  printf("* Bem vindo à sala dos Desarmadores de Bombas *\n");
	  printf("***********************************************\n");
	  printf("\n");
	  for(i = 0; i < player; i++)
	  {
	    printf("%dº Lugar - ", i+1);
	    imprime_string(((record+7)->w_+i)->nome,espaco);
	    printf(": %d\n", ((record+7)->w_+i)->valor );
	  }
	  aperte_tecla(0);
	}
	while(1)
	{
		menu_opcoes();
		numero_do_usuario = pega_algarismo(0, 4);
		if(numero_do_usuario == 1)
			jogar();
		else if(numero_do_usuario == 2)
			configuracoes();
		else if(numero_do_usuario == 3)
			instrucoes();
		else if(numero_do_usuario == 4)
			rank_jogo();
		else
		{
			limpa_buffer();
			return 0;
		}
		*(posicao+8) = organiza_posicao_completo(record, dado, *(posicao+8), 8);
	}
}