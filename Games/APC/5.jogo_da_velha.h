void jogo_da_velha() /* totalmente terminado */
{
  char posicao[3][3], resposta[5];
  int res, pont_1=0, pont_2=0, pont_3=0, limite=0;
  void imprime(int jogador)
  {
    system("clear");
    printf("\n");
    printf("\n");
    printf("*****************\n");
    printf("* Jogo da velha *\n");
    printf("*****************\n");
    printf("\n");
    printf("   Limite:  %d jogos\n", limite);
    printf("Jogador 1:  %d vitorias\n", pont_1);
    printf("Jogador 2:  %d vitorias\n", pont_2);
    printf("  Empates:  %d\n", pont_3);
    printf("\n");
    printf("     1     2     3\n");
    printf("        |     |    \n");
    printf("a    %c  |  %c  |  %c \n", posicao[0][0], posicao[0][1], posicao[0][2]);
    printf("        |     |    \n");
    printf("   -----+-----+-----\n");
    printf("        |     |    \n");
    printf("b    %c  |  %c  |  %c \n", posicao[1][0], posicao[1][1], posicao[1][2]);
    printf("        |     |    \n");
    printf("   -----+-----+-----\n");
    printf("        |     |    \n");
    printf("c    %c  |  %c  |  %c \n", posicao[2][0], posicao[2][1], posicao[2][2]);
    printf("        |     |    \n");
    printf("\n\n");
    if(jogador == 1)
      printf("Jogador 1, qual casa quer colocar com X?  ");
    else if(jogador == 2)
      printf("Jogador 2, qual casa quer colocar com O?  ");
  }
  void limpa()
  {
    int i, j;
    for(i=0; i<=3; i++)
      for(j=0; j<3; j++)
        posicao[i][j] = ' ';
  }
  int resultado_do_jogo()
  {
    int i, j;
    if((posicao[0][0] == posicao[1][1] && posicao[1][1] == posicao[2][2]) || (posicao[2][0] == posicao[1][1] && posicao[1][1] == posicao[0][2]))
    {
      if(posicao[1][1] == 'X')
        return 1;
      else if(posicao[1][1] == 'O')
        return 2;
    }
    for(i = 0; i<3; i++)
    {
      if(posicao[i][0] == posicao[i][1] && posicao[i][1] == posicao[i][2])
      {
        if(posicao[i][0] == 'X')
          return 1;
        else if(posicao[i][0] == 'O')
          return 2;
      }
      if(posicao[0][i] == posicao[1][i] && posicao[1][i] == posicao[2][i])
      {
        if(posicao[0][i] == 'X')
          return 1;
        else if(posicao[0][i] == 'O')
          return 2;
      }
    }
    for(i = 0; i < 3; i++)
      for(j = 0; j < 3 ; j++)
        if(posicao[i][j] == ' ')
          return 0;
    return 3;
  }
  int escreve_opcao(int jogador)
  {
    int x , y;
    if(resposta[0] == 'a')
      x = 0;
    else if(resposta[0] == 'b')
      x = 1;
    else if(resposta[0] == 'c')
      x = 2;
    else
      return 1;
    if(resposta[1] == '1')
      y = 0;
    else if(resposta[1] == '2')
      y = 1;
    else if(resposta[1] == '3')
      y = 2;
    else
      return 1;
    if(posicao[x][y] != ' ')
      return 1;
    if(jogador == 1)
      posicao[x][y] = 'X';
    else
      posicao[x][y] = 'O';
    return 0;
  }
  limpa();
  imprime(3);
  printf("Qual a quantidade de jogos limite?  ");
  scanf(" %d", &limite);
  while(pont_1 < limite && pont_2 < limite && pont_3 < limite)
  {
    do
    {
      res = resultado_do_jogo();
      if(!res)
      {
        do
        {
          imprime(1);
          scanf(" %s", resposta);
        }while(escreve_opcao(1));
      }
      res = resultado_do_jogo();
      if(!res)
      {
        do
        {
          imprime(2);
          scanf(" %s", resposta);
        }while(escreve_opcao(2));
      }
    }while(!res);
    imprime(3);
    if(res == 1)
    {
      printf("Jogador 1 venceu!\n");
      pont_1++;
    }
    else if(res == 2)
    {
      printf("Jogador 2 venceu!\n");
      pont_2++;
    }
    else
    {
      printf("Deu velha!\n");
      pont_3++;
    }
    aperte_tecla(ENTER);
    limpa();
  }
  imprime(3);
  if(pont_1 == limite)
    printf("Parabéns ao Jogador 1, ganhou %d jogos!", limite);
  else if(pont_2 == limite)
    printf("Parabéns ao Jogador 2, ganhou %d jogos!", limite);
  else
  {
    if(pont_1 > pont_2)
      printf("Parabéns ao Jogador 1, ganhou %d jogos, contra %d do Jogador 2", pont_1, pont_2);
    if(pont_2 > pont_1)
      printf("Parabéns ao Jogador 1, ganhou %d jogos, contra %d do Jogador 2", pont_2, pont_1);
    else
      printf("Empatado! Não há nenhum vencedor!\n");
  }
  aperte_tecla(ENTER);
}