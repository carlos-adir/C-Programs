int jogo_2048(completo *record, geral *dado, int *posicao)
{
	int numero_do_usuario, probabilidade=0, recorde=0, pontuacao, tamanho = 6;
	int campo[10][10];
	void menu_opcoes()
	{
	    system("clear");
	    printf("\t********\n");
	    printf("\t* 2048 *\n");
	    printf("\t********\n");
	    printf("\n");
	    printf("  Recorde:  %d\n", recorde);
	    printf("\n");
	    printf("1) Iniciar novo jogo\n");
	    printf("2) Configuracoes\n");
	    printf("3) Instrucoes\n");
	    printf("4) Os Calculistas\n\n");
	    printf("0) Sair\n");
	    printf("\n");
	    printf("Digite a opcao:  ");
	}
	void jogar()
	{
		void menu_jogar()
		{
			system("clear");
			printf("\t********\n");
			printf("\t* 2048 *\n");
			printf("\t********\n");
			printf("\n");
			printf("\t Recorde:    %d\n", recorde);
			printf("\t Pontuacao:  %d\n", pontuacao);
	    }
	    void limpar()
	    {
	      int i, j;
	      for(i = 0; i<tamanho; i++)
	        for(j = 0; j<tamanho; j++)
	          campo[i][j] = 0;
	    }
	    void poe_aleatorio(int quantidade, int maximo_iteracoes)
	    {
	      int i, x, y, quantidade_iteracoes=0;
	      srand((unsigned)time(NULL));
	      for(i = 0; i<quantidade; i++)
	      {
	        do
	        {
	          x = rand()%tamanho;
	          y = rand()%tamanho;
	          quantidade_iteracoes++;
	          if(quantidade_iteracoes > maximo_iteracoes)
	          	return;
	        }while(campo[x][y] != 0);
	        campo[x][y] = (rand()%10 <= probabilidade) ? 4 : 2;
	      }
	    }
	    int pega_direcao()
	    {
	      char caracter;
	      do
	      {
	        caracter = getch();
	      }while(caracter != 'a' && caracter != 's' && caracter != 'd' && caracter != 'w' && caracter != ESC);
	      limpa_buffer();
	      if(caracter == 'a')
	        return 1;
	      else if(caracter == 's')
	        return 2;
	      else if(caracter == 'd')
	        return 3;
	      else if(caracter == 'w')
	        return 4;
	      else
	        return 0;
	    }
	    int mover(int direcao)
	    {
			int i, x, y, moveu = 1;
			if(direcao == 1) /* esquerda */
			{
				for(i = 0; i < tamanho; i++)
				{
					x = 0;
					do
					{
						while(x < tamanho && !campo[i][x])
							x++;
						y = x+1;
						while(y < tamanho && !campo[i][y])
							y++;
						if(x < tamanho && y < tamanho)
						{
							if(campo[i][x] == campo[i][y])
							{
								campo[i][x] *= 2;
								campo[i][y] = 0;
								pontuacao += campo[i][x];
								moveu++;
							}
							else
							{
								x = y;
								y ++;
							}
						}
					}while(x < tamanho && y < tamanho);
				}
				for(i = 0; i < tamanho; i++)
				{
					x = 0;
					do
					{
						while(campo[i][x] && x < tamanho)
							x++;
						y = x+1;
						while(!campo[i][y] && y < tamanho)
							y++;
						if(x < tamanho && y < tamanho && !campo[i][x] && campo[i][y])
						{
							campo[i][x] = campo[i][y];
							campo[i][y] = 0;
							moveu++;
						}
						x++;
					}while(y < tamanho && x < tamanho);
				}
			}
			else if(direcao == 2) /* baixo */
			{
				for(i = 0; i < tamanho; i++)
				{
					x = tamanho-1;
					do
					{
						while(x >= 0 && !campo[x][i])
							x--;
						y = x-1;
						while(y >= 0 && !campo[y][i])
							y--;
						if(x >= 0 && y >= 0)
						{
							if(campo[x][i] == campo[y][i])
							{
								campo[x][i] *= 2;
								campo[y][i] = 0;
								pontuacao += campo[x][i];
								moveu++;
							}
							else
							{
								x = y;
								y--;
							}
						}
					}while(x >= 0 && y >= 0);
				}
				for(i = 0; i < tamanho; i++)
				{
					x = tamanho - 1;
					do
					{
						while(campo[x][i] && x >= 0)
							x--;
						y = x-1;
						while(!campo[y][i] && y >= 0)
							y--;
						if(x >= 0 && y >= 0 && !campo[x][i] && campo[y][i])
						{
							campo[x][i] = campo[y][i];
							campo[y][i] = 0;
							moveu++;
						}
						x--;
					}while(y >= 0 && x >=0 );
				}	
			}
			else if(direcao == 3) /* direita */
			{
				for(i = 0; i < tamanho; i++)
				{
					x = tamanho-1;
					do
					{
						while(x >= 0 && !campo[i][x])
							x--;
						y = x-1;
						while(y >= 0 && !campo[i][y])
							y--;
						if(x >= 0 && y >= 0)
						{
							if(campo[i][x] == campo[i][y])
							{
								campo[i][x] *= 2;
								campo[i][y] = 0;
								pontuacao += campo[i][x];
								moveu++;
							}
							else
							{
								x = y;
								y--;
							}
						}
					}while(x >= 0 && y >= 0);
				}
				for(i = 0; i < tamanho; i++)
				{
					x = tamanho - 1;
					do
					{
						while(campo[i][x] && x >= 0)
							x--;
						y = x-1;
						while(!campo[i][y] && y >= 0)
							y--;
						if(x >= 0 && y >= 0 && !campo[i][x] && campo[i][y])
						{
							campo[i][x] = campo[i][y];
							campo[i][y] = 0;
							moveu++;
						}
						x--;
					}while(y >= 0 && x >= 0);
				}
			}
			else if(direcao == 4)/* cima */
			{
				for(i = 0; i < tamanho; i++)
				{
					x = 0;
					do
					{
						while(x < tamanho && !campo[x][i])
							x++;
						y = x+1;
						while(y < tamanho && !campo[y][i])
							y++;
						if(x < tamanho && y < tamanho)
						{
							if(campo[x][i] == campo[y][i])
							{
								campo[x][i] *= 2;
								campo[y][i] = 0;
								pontuacao += campo[x][i];
								moveu++;
							}
							else
							{
								x = y;
								y++;
							}
						}
					}while(x < tamanho && y < tamanho);
				}
				for(i = 0; i < tamanho; i++)
				{
					x = 0;
					do
					{
						while(campo[x][i] && x < tamanho)
							x++;
						y = x+1;
						while(!campo[y][i] && y < tamanho)
							y++;
						if(x < tamanho && y < tamanho && !campo[x][i] && campo[y][i])
						{
							campo[x][i] = campo[y][i];
							campo[y][i] = 0;
							moveu++;
						}
						x++;
					}while(y < tamanho && x < tamanho);
				}
			}
			else
				return 0;
			return moveu;
	    }
	    void imprime()
	    {
	      int i, j;
	      printf("\n\n");
	      for(i=0; i<tamanho; i++)
	      {
	        for(j=0; j<tamanho; j++)
	        {
	          if(campo[i][j] < 10)
	            printf("  %d  ",campo[i][j]);
	          else if(campo[i][j] < 100)
	            printf(" %d  ", campo[i][j]);
	          else if(campo[i][j] < 1000)
	            printf(" %d ", campo[i][j]);
	          else
	            printf("%d ", campo[i][j]);
	        }
	        printf("\n\n");
	      }
	      printf("\n\n");
	    }
	    int nao_terminou()
	    {
	    	int i, j;
	    	if(!numero_do_usuario)
	    		return 0;
	    	for(i = 0; i<tamanho; i++)
	    		for(j = 0; j < tamanho; j++)
	    			if(campo[i][j] == 2048)
	    				return 0;
	    	for(i = 0; i < tamanho; i++)
	    		for(j = 0; j < tamanho; j++)
	    			if(!campo[i][j])
	    				return 1;
	    	i = j = 0;
	    	if(campo[i][j] == campo[i][j+1] || campo[i][j] == campo[i+1][j])
	    		return 1;
	    	i = tamanho-1;
	    	if(campo[i][j] == campo[i][j+1] || campo[i][j] == campo[i-1][j])
	    		return 1;
	    	j = tamanho-1;
	    	if(campo[i][j] == campo[i][j-1] || campo[i][j] == campo[i-1][j])
	    		return 1;
	    	i = 0;
	    	if(campo[i][j] == campo[i][j-1] || campo[i][j] == campo[i+1][j])
	    		return 1;
	    	for(i = 1; i < tamanho-1; i++)
	    		for(j = 1; j < tamanho-1; j++)
	    		{
	    			if(campo[i][j] == campo[i][j+1] || campo[i][j] == campo[i+1][j])
	    				return 1;
	    			if(campo[i][j] == campo[i][j-1] || campo[i][j] == campo[i-1][j])
	    				return 1;
	    		}
	    	return 0;
	    }
	    void fim_de_jogo()
	    {
	    	int i, j;
	    	menu_jogar();
		    printf("\ta - Esquerda\n");
	    	printf("\td - Direita \n");
	    	printf("\tw - Subir   \n");
	    	printf("\ts - Descer  \n");
	    	printf("\tESC - Sair\n\n");
	    	numero_do_usuario = 0;
	    	for(i = 0; i<tamanho; i++)
		    		for(j = 0; j < tamanho; j++)
		    			if(campo[i][j] == 2048)
		    				numero_do_usuario = 1;
		    printf("%s", numero_do_usuario ? "Parabéns, você ganhou!" : "Que pega, você perdeu :( ");
		    printf("\nSua pontuação é %d. %s", pontuacao, pontuacao == recorde ? "Você quebrou o recorde" : "Ainda não conseguistes quebrar o recorde");
		    imprime();
		    aperte_tecla(ENTER);
	    }
	    pontuacao = 0;
	    numero_do_usuario = 2;
	    limpar();
	    poe_aleatorio(4, 100);
	    printf("%d\n", numero_do_usuario);
	    while(nao_terminou())
	    {
	    	menu_jogar();
	    	printf("\ta - Esquerda\n");
	    	printf("\td - Direita \n");
	    	printf("\tw - Subir   \n");
	    	printf("\ts - Descer  \n");
	    	printf("\tESC - Sair\n\n");
	    	printf("%s\n", numero_do_usuario == 1 ? "Nao foi possivel fazer tal movimento, digite um movimento valido" : " ");
	    	imprime();
	    	numero_do_usuario = mover(pega_direcao());
	    	limpa_buffer();
	    	if(numero_do_usuario > 1)
	    	{
		    	poe_aleatorio(1, 100);
		    	recorde = (pontuacao > recorde ? pontuacao : recorde);
	    	}
	    }
	    fim_de_jogo();
	}
	int configuracoes()
	{
		void menu_configuracoes()
		{
		  system("clear");
		  printf("\t********\n");
		  printf("\t* 2048 *\n");
		  printf("\t********\n");
		  printf("\n");
		  printf("1) Alterar a probabilidade de aparecer 4(atual: %d0%%)\n\n", probabilidade+1);
		  printf("0) Voltar ao menu alterior\n");
		}
		while(1)
		{
		  menu_configuracoes();
		  numero_do_usuario = pega_algarismo(0, 1);
		  if(numero_do_usuario == 1)
		  {
		    menu_configuracoes();
		    printf("\nDigite a nova probabilidade(entre 1 e 9):  ");
		    numero_do_usuario = pega_algarismo(0, 9);
		    if(numero_do_usuario)
		    {
		      probabilidade = numero_do_usuario;
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
	  printf("************************************\n");
	  printf("* Bem vindo à sala dos Calculistas *\n");
	  printf("************************************\n");
	  printf("\n");
	  for(i = 0; i < player; i++)
	  {
	    printf("%dº Lugar - ", i+1);
	    imprime_string(((record+3)->w_+i)->nome,espaco);
	    printf(": %d\n", ((record+3)->w_+i)->valor );
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
		*(posicao+4) = organiza_posicao_completo(record, dado, *(posicao+4), 4);
	}
}