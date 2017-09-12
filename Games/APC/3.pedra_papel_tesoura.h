int pedra_papel_tesoura(completo *record, geral *dado, int *posicao)
{
	int numero_do_usuario;
	char pedra = 'p', papel = 'P', tesoura = 'T', jogador[3];
	void menu_opcoes()
	{
		system("clear");
		printf("***********************\n");
		printf("* Pedra Papel Tesoura *\n");
		printf("***********************\n");
		printf("\n");
		printf("1) Jogar\n");
		printf("2) Configurações\n");
		printf("3) Instrucoes\n");
		printf("4) 'Nao sei o que colocar aqui'\n\n");
		printf("0) Sair\n");
		printf("\n");
		printf("Digite uma opcao:  ");
	}
	void jogar()
	{
		int i, terminar;
		void menu_jogar()
		{
			system("clear");
			printf("\t***********************\n");
			printf("\t* Pedra Papel Tesoura *\n");
			printf("\t***********************\n");
			printf("\n");
			printf("\t Pedra  - %c\n", pedra);
			printf("\t Papel  - %c\n", papel);
			printf("\tTesoura - %c\n\n", tesoura);
		}
		int verifica_vencedor()
		{
			if(!jogador[0] || !jogador[1] || !jogador[2])
				return 4;
			if(jogador[0] != jogador[1] && jogador[0] != jogador[2] && jogador[1] != jogador[2])
				return 0;
			if(jogador[0] == jogador[1] && jogador[0] == jogador[2])
				return 0;
			if(jogador[0] == jogador[1])
			{
				if(jogador[2] == pedra && jogador[1] == tesoura)
					return 3;
				else if(jogador[2] == papel && jogador[1] == pedra)
					return 3;
				else if(jogador[2] == tesoura && jogador[1] == papel)
					return 3;
			}
			else if(jogador[1] == jogador[2])
			{
				if(jogador[0] == pedra && jogador[2] == tesoura)
					return 1;
				else if(jogador[0] == papel && jogador[2] == pedra)
					return 1;
				else if(jogador[0] == tesoura && jogador[2] == papel)
					return 1;
			}
			else if(jogador[0] == jogador[2])
			{
				if(jogador[1] == pedra && jogador[2] == tesoura)
					return 2;
				else if(jogador[1] == papel && jogador[2] == pedra)
					return 2;
				else if(jogador[1] == tesoura && jogador[2] == papel)
					return 2;
			}
			return 0;
		}
		int nao_terminou()
		{
			int vencedor = verifica_vencedor();
			if(vencedor)
				return 0;
			return 1;
		}
		char pega_entrada(char a, char b, char c)
		{
			char caracter;
			do
			{
				caracter = getch();
			}while(caracter != a && caracter != b && caracter != c && caracter != ESC);
			if(caracter == ESC)
				return 0;
			return caracter;
		}
		jogador[0] = jogador[1] = jogador[2] = 'a';
		terminar = nao_terminou();
		while(terminar)
		{
			for(i = 0; i<3 && jogador[0] && jogador[1] && jogador[2]; i++)
			{
				menu_jogar();
				printf("Jogador %d, o que deseja jogar?  ", i+1);
				jogador[i] = pega_entrada(pedra, papel, tesoura);
			}
			terminar = nao_terminou();
			printf("\n\nResultado:\n");
			printf("Jogador 1: %s\n", (jogador[0] == pedra ? "Pedra" : (jogador[0] == papel ? "Papel" : "Tesoura")));
			printf("Jogador 2: %s\n", (jogador[1] == pedra ? "Pedra" : (jogador[1] == papel ? "Papel" : "Tesoura")));
			printf("Jogador 3: %s\n", (jogador[2] == pedra ? "Pedra" : (jogador[2] == papel ? "Papel" : "Tesoura")));
			if(terminar)
			{
				printf("\n\nHouve empate, denovo!");
				aperte_tecla(ENTER);
			}
		}
		terminar = verifica_vencedor();
		if(terminar != 4)
		{
			printf("\n\nParabéns ao Jogador %d por ter ganho a partida!\n\n", terminar);
			aperte_tecla(ENTER);
		}
	}
	int configuracoes()
	{
		void menu_configuracoes()
		{
			system("clear");
			printf("***********************\n");
			printf("* Pedra Papel Tesoura *\n");
			printf("***********************\n");
			printf("\n");
			printf("1) Alterar os caracteres de cada opcao:\n Pedra  - %c\n Papel  - %c\nTesoura - %c\n\n", pedra, papel, tesoura);
			printf("0) Voltar ao menu alterior\n");
		}
		while(1)
		{
			menu_configuracoes();
			numero_do_usuario = pega_algarismo(0, 1);
			if(numero_do_usuario == 1)
			{
				menu_configuracoes();
				printf("\nDigite o caracter da pedra:  ");
				pedra = pega_letra('a', 'z', 'A', 'Z');
				putchar(pedra);
				printf("\nDigite o caracter do papel:  ");
				papel = pega_letra('a', 'z', 'A', 'Z');
				putchar(papel);
				printf("\nDigite o caracter da tesoura:  ");
				tesoura = pega_letra('a', 'z', 'A', 'Z');
				putchar(tesoura);
				if(papel == pedra || papel == tesoura || pedra == tesoura)
				{
					printf("\nNão é possivel que duas opcoes tenham os mesmo caracteres. Padrões originais restaurados.");
					pedra = 'p';
					papel = 'P';
					tesoura = 'T';
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
	}
	void rank_jogo()
	{
	  int i;
	  system("clear");
	  printf("*****************************************************\n");
	  printf("* Bem vindo à sala dos 'Nao sei o que colocar aqui' *\n");
	  printf("*****************************************************\n");
	  printf("\n");
	  for(i = 0; i < player; i++)
	  {
	    printf("%dº Lugar - ", i+1);
	    imprime_string(((record+2)->w_+i)->nome,espaco);
	    printf(": %d\n", ((record+2)->w_+i)->valor );
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
		*(posicao+3) = organiza_posicao_completo(record, dado, *(posicao+3), 3);
	}
}