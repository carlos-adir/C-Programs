void jogo_da_memoria() /* totalmente terminado */
{
  int tamanho = 9, opcao, absi[2], orde[2], contador, final, tentativas;
  int quantidade;
  char gabarito[tamanho][tamanho], usuario[tamanho][tamanho];
  do{
    system("clear");
    printf("Digite o nível de dificuldade(entre 1 e 8):  ");
  } while(scanf("%d", &tamanho) && (tamanho < 1 || tamanho > 8));
  tamanho++;
  quantidade = (tamanho*tamanho)/2;
  int resp() /* essa funcao recolhe a entrada do usuario e retorna um número, por exemplo, resp(*a1*) = 11 */
  {
    int verificao = 0;
    char resposta[5];
    do
    {
      scanf(" %s", resposta);
      if(resposta[0] == 's' || resposta[0] == 'S')
        return 0;
      if(resposta[0] < 97 || resposta[0] > (97+tamanho)) /* Aqui verifica se o primeiro caracter é um caracter válido, a~h */
        verificao = 1;
      else if(resposta[1] < 48 || resposta[1] > (48+tamanho)) /* Aqui verifica se o segundo caracter é um caracter valido, 1~9 */
        verificao = 1;
      else if(tamanho%2 && !(((int)resposta[0]) - 96-tamanho) && !(((int)resposta[1]) - 48-tamanho)) /* Aqui verifica se em caso de tamanho impar, o ultimo termo será pego */
        verificao = 1;
      else if(usuario[(int)resposta[0] - 97][((int)resposta[1]) - 49] != '&')
        verificao = 1;
      else
        verificao = 0;
    }while(verificao);
    return (10*(((int)resposta[0]) - 96) + (((int)resposta[1]) - 48));
  }
  void menu_memoria()
  {
    system("clear");
    printf("\n");
    printf("\n");
    printf("*******************\n");
    printf("* Jogo da Memória *\n");
    printf("*******************\n");
    printf("\n");
    printf("\n");
  }
  void limpa_usuario()
  {
    int i, j;
    for(i=0; i<tamanho; i++)
      for(j = 0; j<tamanho; j++)
        usuario[i][j] = '&';
    if(tamanho%2)
      usuario[tamanho-1][tamanho-1] = ' ';
  }
  void novo_gabarito()
  {
    int i, x, y;
    char caracter = 'A';
    srand((unsigned)time(NULL));
    for(x=0; x<tamanho; x++)
      for(y = 0; y<tamanho; y++)
        gabarito[x][y] = '&';
    if(tamanho%2)
      gabarito[tamanho-1][tamanho-1] = ' ';
    for(i = 0; i < quantidade; i++)
    {
      do
      {
        x = rand()%tamanho;
        y = rand()%tamanho;
      }while(gabarito[x][y] != '&');
      gabarito[x][y] = (char)(((int)caracter) + i);
      do
      {
        x = rand()%tamanho;
        y = rand()%tamanho;
      }while(gabarito[x][y] != '&');
      gabarito[x][y] = (char)(((int)caracter) + i);
    }
  }
  void imprime()
  {
    int i, j;
    printf("\n");
    printf("   ");
    for(i = 0; i<tamanho; i++)
      printf("%d ", i+1);
    printf("\n");
    for(i = 0; i < tamanho; i++)
    {
      printf("%c  ", (char)(i+((int)'a')));
      for(j = 0; j < tamanho; j++)
        printf("%c ", usuario[i][j]);
      printf("\n");
    }
    printf("\n\n");
  }
  menu_memoria();
  printf("1) Jogar\n");
  printf("2) Sair\n");
  while(scanf("%d", &opcao) && opcao != 2)
  {
    if( opcao == 1 )
    {
      printf("Hey\n");
      tentativas = 0;
      final = 0;
      novo_gabarito();
      limpa_usuario();
      contador = 0;
      printf("Hey\n");
      do{
        printf("Hey\n");
        tentativas++;
        menu_memoria();
        imprime();
        printf("Digite o valor da casa a ser aberta: ");
        opcao = resp();
        absi[contador] = (opcao / 10) - 1;
        orde[contador] = (opcao % 10) - 1;
        if(opcao)
        {
          usuario[absi[contador]][orde[contador]] = gabarito[absi[contador]][orde[contador]];
          
        }
        if(contador)
        {
          if(usuario[absi[0]][orde[0]] != usuario[absi[1]][orde[1]])
          {
            menu_memoria();
            imprime();
            aperte_tecla(ENTER);
            usuario[absi[0]][orde[0]] = usuario[absi[1]][orde[1]] = '&';
          }
          else
            final++;
          contador = -1;
        }
        contador++;
      }while(opcao && final < quantidade);
      menu_memoria();
      imprime();
      printf("Parabéns, você conseguiu com %d tentativas!\n", tentativas/2);
      aperte_tecla(ENTER);
    }
    menu_memoria();
    printf("1) Jogar\n");
    printf("2) Sair\n");
  }
}