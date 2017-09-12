int charadas(completo *record, geral *dado, int *posicao)
{
	int numero_do_usuario, numero_erros_maximo = 2, tentativas, gabarito;
	void menu_opcoes()
	{
		system("clear");
		printf("************\n");
		printf("* Charadas *\n");
		printf("************\n");
		printf("\n");
		printf("1) Jogar\n");
		printf("2) Configurações\n");
		printf("3) Instrucoes\n");
		printf("4) Os coringas da vez\n\n");
		printf("0) Sair\n");
		printf("\n");
		printf("Digite uma opcao:  ");
	}
	void jogar()
	{
		void menu_jogar()
		{
			system("clear");
			printf("************\n");
			printf("* Charadas *\n");
			printf("************\n");
			printf("\n");
		}
		int charada(int numero_da_charada)
		{
			if(numero_da_charada == 1)
			{
				printf("Um \"amigo\" foi lhe visitar e levou duas de suas taças\n");
				printf("favoritas, qual o nome do filme?\n");
				printf("1) Exterminador do Futuro 2\n");
				printf("2) O roubo do Banco Central\n");
				printf("3) RoboCop 2\n");
				printf("4) Roubo a Máfia\n");
				return 3;
			}
			return 0;
		}
		tentativas = 0;
		menu_jogar();
		gabarito = charada(1);
		printf("Digite sua opcao:  ");
		numero_do_usuario = pega_algarismo(1, 4);
		while(tentativas < numero_erros_maximo && numero_do_usuario != gabarito)
		{
			menu_jogar();
			charada(1);
			tentativas++;
			printf("Errado! Como diria o profeta: \"tente outra vez\"...\n\n");
			aperte_tecla(ENTER);
			menu_jogar();
			charada(1);
			numero_do_usuario = pega_algarismo(1, 4);
		}
		menu_jogar();
		charada(1);
		if(tentativas == 2)
			printf("Você perdeu! Fora jogador!\n\n");
		else
			printf("Parabéns, você ganhou!\n\n");
		aperte_tecla(ENTER);
	}
	int configuracoes()
	{
		void menu_configuracoes()
		{
			system("clear");
			printf("************\n");
			printf("* Charadas *\n");
			printf("************\n");
			printf("\n");
			printf("1) Alterar os numero de erros maximo(atual: %d)\n\n", numero_erros_maximo);
			printf("0) Voltar ao menu alterior\n");
		}
		while(1)
		{
			menu_configuracoes();
			numero_do_usuario = pega_algarismo(0, 1);
			if(numero_do_usuario == 1)
			{
				menu_configuracoes();
				printf("Digite o novo numero maximo:  ");
				numero_do_usuario = pega_numero_grande();
				if(numero_do_usuario > 1)
					numero_erros_maximo = numero_do_usuario;
				aperte_tecla(ESC);
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
	  printf("*********************************\n");
	  printf("* Bem vindo à sala dos Coringas *\n");
	  printf("*********************************\n");
	  printf("\n");
	  for(i = 0; i < player; i++)
	  {
	    printf("%dº Lugar - ", i+1);
	    imprime_string(((record+1)->w_+i)->nome,espaco);
	    printf(": %d\n", ((record+1)->w_+i)->valor );
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
		*(posicao+2) = organiza_posicao_completo(record, dado, *(posicao+2), 2);
	}
}