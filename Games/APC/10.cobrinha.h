#define tele1 '='
#define tele2 '|'
#define parede '&'
#define comida 'k'
#define corpo '@'
#define x_m 50
#define y_m 30
int cobrinha(completo *record, geral *dado, int *posicao)
{
  int numero_do_usuario, velocidade = 1, numero_mapa=1, dificuldade = 1, tamanhox, tamanhoy, i, j, pontuacao = 0;
  char string[30], mapa[y_m][x_m];
  FILE *arquivo;
  void menu_opcoes()
  {
    system("clear");
    printf("*********\n");
    printf("* Snake *\n");
    printf("*********\n");
    printf("\n");
    printf("1) Jogar\n");
    printf("2) Configurações\n");
    printf("3) Instrucoes\n");
    printf("4) Os encatadores de serpentes\n\n");
    printf("0) Sair\n");
    printf("\n");
    printf("Digite uma opcao:  ");
  }
  void jogar()
  {
    int direcao, tamanho=5, auxiliar, terminou;
    int a[x_m*y_m], b[x_m*y_m]; /* a representa a coordenada x, b representa a coordenada y*/
    int valor_da_pontuacao()
    {
      return velocidade;
    }
    void novo_mapa()
    {
      if(numero_mapa == 0)
      {
        arquivo = fopen(string, "r");
        fscanf(arquivo, "%d %d %d", &tamanhox, &tamanhoy, &dificuldade);
        fgetc(arquivo);
        for(i = 0; i < tamanhox; i++)
        {
          for(j = 0; j < tamanhoy; j++)
            mapa[i][j] = fgetc(arquivo);
          fgetc(arquivo);
        }
        fclose(arquivo);
      }
      else if(numero_mapa == 1)
      {
        tamanhox = y_m;
        tamanhoy = x_m;
        for(i = 0; i<tamanhox; i++)
          for(j=0; j<tamanhoy; j++)
            mapa[i][j] = ' ';
      }
      else if(numero_mapa == 2)
      {
        tamanhox = y_m;
        tamanhoy = x_m;
        for(j = 0; j<tamanhoy; j++)
          mapa[0][j] = mapa[tamanhox-1][j] = parede;
        for(i = 1; i<tamanhox-1; i++)
        {
          mapa[i][0] = mapa[i][tamanhoy-1] = parede;
          for(j = 1; j<tamanhoy-1; j++)
            mapa[i][j] = ' ';
        }
      }
      else if(numero_mapa == 3)
      {
        tamanhox = y_m;
        tamanhoy = x_m;
        for(i = 0; i<tamanhox; i++)
          for(j=0; j<tamanhoy; j++)
            mapa[i][j] = ' ';
        for(j = 10; j < 40; j++)
        {
          mapa[tamanhox/3-1][j] = mapa[2*tamanhox/3][j] = parede;
        }
      }
      else if(numero_mapa == 4)
      {
        tamanhox = y_m;
        tamanhoy = x_m;
        for(i = 0; i<tamanhox; i++)
          for(j=0; j<tamanhoy; j++)
            mapa[i][j] = ' ';
        for(i=0; i<4; i++)
        {
          mapa[i+6][12] = mapa[i+6][25] = mapa[i+6][37] = parede;
          mapa[23-i][12] = mapa[23-i][25] = mapa[23-i][37] = parede;
        }
      }
    }
    void menu_jogar()
    {
      system("clear");
      printf("*********\n");
      printf("* Snake *\n");
      printf("*********\n");
      printf("\n");
    }
    void imprime_mapa()
    {
      for(j = 0; j<2*tamanhoy+2; j++)
        putchar(tele1);
      putchar('\n');
      for(i = 0; i<tamanhox; i++)
      {
        putchar(tele2);
        for(j = 0; j<tamanhoy-1; j++)
        {
          putchar(mapa[i][j]);
          putchar(' ');
        }
        putchar(mapa[i][j]);
        putchar(tele2);
        putchar('\n');
      }
      for(j = 0; j<2*tamanhoy+2; j++)
        putchar(tele1);
      printf("\n\n");
    }
    void colocar_comida()
    {
      int i_, j_;
      do
      {
        i_ = rand()%tamanhox;
        j_ = rand()%tamanhoy;
      }while(mapa[i_][j_] == corpo || mapa[i_][j_] == parede);
      mapa[i_][j_] = comida;
    }
    int mover()
    {
      int i_;
      mapa[b[tamanho-2]][a[tamanho-2]] = ' ';
      for(i_=tamanho-1; i_>0; i_--)
      {
        a[i_] = a[i_-1];
        b[i_] = b[i_-1];
      }
      if(direcao == 1)
        b[0]--;
      else if(direcao == 2)
        b[0]++;
      else if(direcao == 3)
        a[0]++;
      else if(direcao == 4)
        a[0]--;
      if(a[0] == -1)
        a[0] = tamanhoy-1;
      else if(a[0] == tamanhoy)
        a[0] = 0;
      if(b[0] == -1)
        b[0] = tamanhox-1;
      else if(b[0] == tamanhox)
        b[0] = 0;
      if(mapa[b[0]][a[0]] == parede || !direcao || mapa[b[0]][a[0]] == corpo)
      {
        mapa[b[tamanho-1]][a[tamanho-1]] = corpo;
        return 1;
      }
      else if(mapa[b[0]][a[0]] == comida)
      {
        tamanho++;
        pontuacao += valor_da_pontuacao();
        colocar_comida();
      }
      mapa[b[0]][a[0]] = corpo;
      return 0;
    }
    novo_mapa();
    do
    {
      b[0] = rand()%tamanhox;
      a[0] = rand()%tamanhoy;
    }while(mapa[b[0]][a[0]] != ' ');
    for(auxiliar = 1; auxiliar < tamanho; auxiliar++)
    {
      b[auxiliar] = b[0];
      a[auxiliar] = a[0];
    }
    pontuacao = 0;
    auxiliar = direcao = 5;
    colocar_comida();
    do
    {
      menu_jogar();
      imprime_mapa();
      terminou = mover();
      usleep(300000/velocidade);
      if(kbhit())
      {
        direcao = pega_quatro_setas();
        if(direcao == 1 && auxiliar == 2)
          direcao = 2;
        else if(direcao == 2 && auxiliar == 1)
          direcao = 1;
        else if(direcao == 3 && auxiliar == 4)
          direcao = 4;
        else if(direcao == 4 && auxiliar == 3)
          direcao = 3;
        else 
          auxiliar = direcao;
      }
    }while(!terminou);
    system("clear");
    if(pontuacao > *(dado->point+9)){
      dado->total -= *(dado->point+9);
      *(dado->point+9) = pontuacao;
      dado->total += pontuacao;
    }
    menu_jogar();
    imprime_mapa();
    printf("Game Over!! Você fez %d pontos!\n", pontuacao);
    aperte_tecla(ENTER);
    system("clear");
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
        numero_do_usuario = pega_algarismo(1,4);
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
    aperte_tecla(ENTER);
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
      imprime_string(((record+9)->w_+i)->nome,espaco);
      printf(": %d\n", ((record+9)->w_+i)->valor );
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
    *(posicao+10) = organiza_posicao_completo(record, dado, *(posicao+10), 10);
  }
}