#define monstro '@'
#define corpo_pacman '$'
int pacman(completo *record, geral *dado, int *posicao)
{
  FILE *arquivo;
  int numero_do_usuario, velocidade = 1, numero_mapa = 1, tamanhox, tamanhoy, x, y, quantidade, contador, direcao=0;
  char string[30]="Map.txt", mapa[32][56];
  void menu_opcoes()
  {
    system("clear");
    printf("**********\n");
    printf("* PacMan *\n");
    printf("**********\n");
    printf("\n");
    printf("1) Jogar\n");
    printf("2) Configurações\n");
    printf("3) Instrucoes\n");
    printf("4) Rank\n\n");
    printf("0) Sair\n");
    printf("\n");
    printf("Digite uma opcao:  ");
  }
  void jogar()
  {
    void menu_jogar()
    {
      system("clear");
      printf("**********\n");
      printf("* PacMan *\n");
      printf("**********\n");
      printf("\n");
    }
    void novo_mapa()
    {
      int i, j;
      if(numero_mapa == 0)
      {
        arquivo = fopen(string, "r");
        if(arquivo == NULL)
          return;
        fscanf(arquivo, "%d %d %d %d %d", &tamanhox, &tamanhoy, &y, &x, &quantidade);
        fgetc(arquivo);
        for(i = 0; i < tamanhox; i++)
        {
          for(j = 0; j < tamanhoy; j++)
            mapa[i][j] = fgetc(arquivo);
          fgetc(arquivo);
        }
        fclose(arquivo);
      }
    }
    int valor_da_pontuacao()
    {
      return velocidade;
    }
    void imprime()
    {
      int i, j;
      for(i = 0; i < tamanhox; i++)
      {
        for(j = 0; j < tamanhoy; j++)
          putchar(mapa[i][j]);
        putchar('\n');
      }
      putchar('\n');
    }
    int nao_terminou()
    {
      return quantidade-1;
    }
    void mover_pacman()
    {
      mapa[y][x] = ' ';
      if(direcao == 1)
        y--;
      else if(direcao == 2)
        y++;
      else if(direcao == 3)
        x+=2;
      else if(direcao == 4)
        x-=2;
      if(mapa[y][x] == '.' || mapa[y][x] == '*')
        quantidade--;
      else if(y < 0)
        y = tamanhox - 1;
      else if(y >= tamanhox)
        y = 0;
      else if(x < 0)
        x = tamanhoy - 1;
      else if(x >= tamanhoy)
        x = 0;
      else if(mapa[y][x] == parede)
      {
        if(direcao == 1)
          y++;
        else if(direcao == 2)
          y--;
        else if(direcao == 3)
          x-=2;
        else if(direcao == 4)
          x+=2;
        limpa_buffer();
      }
      mapa[y][x] = corpo_pacman;
    }
    void mover_monstros()
    {
      contador = 0;
    }
    novo_mapa();
    while(nao_terminou())
    {
      menu_jogar();
      imprime();
      usleep(30000);
      contador++;
      if(kbhit())
      {
        direcao = pega_quatro_setas();
        mover_pacman();
      }
      if(!contador%velocidade)
      {
        mover_monstros();
      }
    }
    aperte_tecla(0);
  }
  int configuracoes()
  {
    void menu_configuracoes()
    {
      system("clear");
      printf("*********\n");
      printf("* Snake *\n");
      printf("*********\n");
      printf("\n");
      printf("1) Alterar a velocidade(atual: %d)\n", velocidade);
      printf("2) Alterar o numero do mapa(atual: ");
      if(numero_mapa == 0)
        printf("Custom)\n");
      else
        printf("%d)\n", numero_mapa);
      printf("3) Importar mapa\n\n");
      printf("0) Voltar ao menu alterior\n");
    }
    while(1)
    {
      menu_configuracoes();
      numero_do_usuario = pega_algarismo(0, 3);
      if(numero_do_usuario == 1)
      {
        menu_configuracoes();
        printf("Digite a nova velocidade:  ");
        numero_do_usuario = pega_algarismo(1, 9);
        velocidade = numero_do_usuario ? numero_do_usuario : 1;
      }
      else if(numero_do_usuario == 2)
      {
        menu_configuracoes();
        printf("Digite o numero do mapa: ");
        numero_do_usuario = pega_algarismo(1,6);
        numero_mapa = numero_do_usuario;
      }
      else if(numero_do_usuario == 3)
      {
        menu_configuracoes();
        printf("Digite o nome do arquivo que existe o mapa:  ");
        limpa_buffer();
        scanf("%28s", string);
        limpa_buffer();
        arquivo = fopen(string, "r");
        if(arquivo != NULL)
        {
          numero_mapa = 0;
          fclose(arquivo);
        }
        else
        {
          numero_mapa = 1;
          printf("O arquivo não foi carregado, verifique se o arquivo %s realmente existe", string);
          aperte_tecla(ENTER);
        }
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
    printf("*************************************************\n");
    printf("* Bem vindo à sala dos Encatadores de Serpentes *\n");
    printf("*************************************************\n");
    printf("\n");
    for(i = 0; i < player; i++)
    {
      printf("%dº Lugar - ", i+1);
      imprime_string(((record+10)->w_+i)->nome,espaco);
      printf(": %d\n", ((record+10)->w_+i)->valor );
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
    *(posicao+11) = organiza_posicao_completo(record, dado, *(posicao+11), 11);
  }
}