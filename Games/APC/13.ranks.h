

int ranks(geral *score)
{
	int a=0, b=3, direcao;
	void menu()
	{
		system("clear");
		printf("*********************************************\n");
		printf("*****    Você está na toca dos feras!   *****\n");
		printf("*********************************************\n");
		printf("Os controles para subir e descer são as setas\n");
		printf("*********************************************\n\n");
	}
	void imprime(int comeco, int fim)
	{
		int i;
		for(i = comeco; i < fim; i++)
		{
			printf("%dº Lugar, co%s", i+1, i == 9 ? "m" : "m ");
			if((score+i)->total < 10)
				printf("     ");
			else if((score+i)->total < 100)
				printf("    ");
			else if((score+i)->total < 1000)
				printf("   ");
			else if((score+i)->total < 10000)
				printf("  ");
			else if((score+i)->total < 100000)
				printf(" ");
			printf("%d pontos: %s\n", (score+i)->total, (score+i)->nome);
			printf("\t              Senha: %d\n", *((score+i)->point+0));
			printf("\t           Charadas: %d\n", *((score+i)->point+1));
			printf("\tPedra Papel Tesoura: %d\n", *((score+i)->point+2));
			printf("\t               2048: %d\n", *((score+i)->point+3));
			printf("\t      Jogo da Velha: %d\n", *((score+i)->point+4));
			printf("\t    Jogo da Memoria: %d\n", *((score+i)->point+5));
			printf("\t             Xadrez: %d\n", *((score+i)->point+6));
			printf("\t       Campo Minado: %d\n", *((score+i)->point+7));
			printf("\t        Roda a Roda: %d\n", *((score+i)->point+8));
			printf("\t           Cobrinha: %d\n", *((score+i)->point+9));
			printf("\t            Pac Man: %d\n", *((score+i)->point+10));
			printf("\t          Labirinto: %d\n\n", *((score+i)->point+11));
		}
	}
	do
	{
		menu();
		imprime(a, b);
		printf("Digite ESC para sair, ou as setas para subir ou descer o rank.");
		direcao = pega_duas_setas();
		if(direcao == 1)
		{
			a--;
			b--;
		}
		else
		{
			a++;
			b++;
		}
		if(a < 0)
		{
			a++;
			b++;
		}
		else if(b > player)
		{
			a--;
			b--;
		}
	}while(direcao);
	return 0;
}