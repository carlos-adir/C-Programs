void xadrez()  /* totalmente terminado */
{
  char tab[8][8], pos[8][8];
  int x, y, a, b, opcao=1, ajuste;
  void novo()
  {
    int i, j;
    for(i = 2; i<6; i++)
      for(j = 0; j<8; j++)
        tab[i][j] = ' ';
    for(j = 0; j<8; j++)
    {
      tab[1][j] = 'I';
      tab[6][j] = 'i';
    }
    tab[0][0] = tab[0][7] = 'T';
    tab[0][1] = tab[0][6] = 'C';
    tab[0][2] = tab[0][5] = 'B';
    tab[0][3] = 'Q';
    tab[0][4] = 'K';
    tab[7][0] = tab[7][7] = 't';
    tab[7][1] = tab[7][6] = 'c';
    tab[7][2] = tab[7][5] = 'b';
    tab[7][3] = 'q';
    tab[7][4] = 'k';
  }
  void limpa_pos()
  {
    int i, j;
    for(i=0; i<8; i++)
      for(j=0; j<8; j++)
        pos[i][j] = ' ';
  }
  void menu(int n)
  {
    system("clear");
    printf("\t          \n");
    printf("\t**********\n");
    printf("\t* Xadrez *\n");
    printf("\t**********\n");
    printf("\n");
    if(n == 1)
    {
      printf("K ou k = rei\t\t\t\tQ ou q = rainnha\n");
      printf("B ou b = bispo\t\t\t\tC ou c = cavalo\n");
      printf("T ou t = torre\t\t\t\tI ou i = peao\n");
    }
    else if( n==2)
    {
      printf("1) Novo jogo\n");
      printf("2) Continuar\n");
      printf("3) Sair\n");
      printf("\n");
      printf("Digite sua opcao:  ");
    }
  }
  void imprime()
  {
    int i, j;
    printf("\n       ");
    for(i = 1; i<9; i++)
      printf("   %d    ", i);
    printf("\n      +~~~~~~~+~~~~~~~+~~~~~~~+~~~~~~~+~~~~~~~+~~~~~~~+~~~~~~~+~~~~~~~+\n");
    for(i=0; i<8; i++)
    {
      printf("      |");
      for(j=0; j<8; j++)
      {
        printf(" %c%c%c%c%c |", pos[i][j], pos[i][j], pos[i][j], pos[i][j], pos[i][j]);
        /*if((j+i)%2)
          putchar('&');
        else
          putchar(' ');
        printf("%c%c%c%c%c", pos[i][j], pos[i][j], pos[i][j], pos[i][j], pos[i][j]);
        if((j+i)%2)
          putchar('&');
        else
          putchar(' ');
        putchar('|');*/
      }
      printf("\n  %c   |", (char)(i+97));
      for(j = 0; j < 8; j++)
      {
        printf(" %c %c %c |", pos[i][j], tab[i][j], pos[i][j]);
        /*if((j+i)%2)
          putchar('&');
        else
          putchar(' ');
        printf("%c %c %c", pos[i][j], tab[i][j], pos[i][j]);

        if((j+i)%2)
          putchar('&');
        else
          putchar(' ');
        putchar('|');*/
      }
      printf("\n      |");
      for(j=0; j<8; j++)
      {
        printf(" %c%c%c%c%c |", pos[i][j], pos[i][j], pos[i][j], pos[i][j], pos[i][j]);
        /*if((j+i)%2)
          putchar('&');
        else
          putchar(' ');
        printf("%c%c%c%c%c", pos[i][j], pos[i][j], pos[i][j], pos[i][j], pos[i][j]);
        if((j+i)%2)
          putchar('&');
        else
          putchar(' ');
        putchar('|'); */
      }
      printf("\n      +~~~~~~~+~~~~~~~+~~~~~~~+~~~~~~~+~~~~~~~+~~~~~~~+~~~~~~~+~~~~~~~+\n");
    }
    printf("\n\n");
  }
  void leia_usuario(int *x, int *y)
  {
    char str[10];
    while(scanf(" %s", str) && (!(str[0] >= 'a' && str[0] <= 'h') || !(str[1] >= '1' && str[1] <= '8')) && str[0] != 's' );
    *x = str[0] - 'a';
    *y = str[1] - '1';
    if(str[0] == 's')
      *x = -1;
  }
  int move_peca()
  {
    if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[a][b] <= 'z' && tab[a][b] >= 'a')
      return 0;
    if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[a][b] <= 'Z' && tab[a][b] >= 'A')
      return 0;
    
    tab[a][b] = tab[x][y];
    tab[x][y] = ' ';
    return 1;
  }
  int verifica_movimento()
  {
    int i, j;
    void ve_torre()
    {
      int i = 1, j = y-1;
      while(j >= 0 && i)
      {
        if(tab[x][j] == ' ')
          pos[x][j] = '.';
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x][j] >= 'a' && tab[x][j] <= 'z')
          i = 0;
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x][j] >= 'A' && tab[x][j] <= 'Z')
          i = 0;
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x][j] >= 'A' && tab[x][j] <= 'Z')
        {
          pos[x][j] = '!';
          i = 0;
        }
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x][j] >= 'a' && tab[x][j] <= 'z')
        {
          pos[x][j] = '!';
          i = 0;
        }
        j--;
      }
      i = 1;
      j = y+1;
      while(j < 8 && i)
      {
        if(tab[x][j] == ' ')
          pos[x][j] = '.';
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x][j] >= 'a' && tab[x][j] <= 'z')
          i = 0;
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x][j] >= 'A' && tab[x][j] <= 'Z')
          i = 0;
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x][j] >= 'A' && tab[x][j] <= 'Z')
        {
          pos[x][j] = '!';
          i = 0;
        }
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x][j] >= 'a' && tab[x][j] <= 'z')
        {
          pos[x][j] = '!';
          i = 0;
        }
        j++;
      }
      i = 1;
      j = x-1;
      while(j >= 0 && i)
      {
        if(tab[j][y] == ' ')
          pos[j][y] = '.';
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[j][y] >= 'a' && tab[j][y] <= 'z')
          i = 0;
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[j][y] >= 'A' && tab[j][y] <= 'Z')
          i = 0;
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[j][y] >= 'A' && tab[j][y] <= 'Z')
        {
          pos[j][y] = '!';
          i = 0;
        }
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[j][y] >= 'a' && tab[j][y] <= 'z')
        {
          pos[j][y] = '!';
          i = 0;
        }
        j--;
      }
      i = 1;
      j = x+1;
      while(j < 8 && i)
      {
        if(tab[j][y] == ' ')
          pos[j][y] = '.';
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[j][y] >= 'a' && tab[j][y] <= 'z')
          i = 0;
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[j][y] >= 'A' && tab[j][y] <= 'Z')
          i = 0;
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[j][y] >= 'A' && tab[j][y] <= 'Z')
        {
          pos[j][y] = '!';
          i = 0;
        }
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[j][y] >= 'a' && tab[j][y] <= 'z')
        {
          pos[j][y] = '!';
          i = 0;
        }
        j++;
      }
    }
    void ve_bispo()
    {
      int i = 1, j = -1, k=-1;
      while(x+j >= 0 && y+k >= 0 && i)
      {
        if(tab[x+j][y+k] == ' ')
          pos[x+j][y+k] = '.';
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x+j][y+k] >= 'a' && tab[x+j][y+k] <= 'z')
          i = 0;
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x+j][y+k] >= 'A' && tab[x+j][y+k] <= 'Z')
          i = 0;
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x+j][y+k] >= 'A' && tab[x+j][y+k] <= 'Z')
        {
          pos[x+j][y+k] = '!';
          i = 0;
        }
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x+j][y+k] >= 'a' && tab[x+j][y+k] <= 'z')
        {
          pos[x+j][y+k] = '!';
          i = 0;
        }
        j--;
        k--;
      }
      i = 1;
      j = 1;
      k = -1;
      while(x+j < 8 && y+k >= 0 && i)
      {
        if(tab[x+j][y+k] == ' ')
          pos[x+j][y+k] = '.';
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x+j][y+k] >= 'a' && tab[x+j][y+k] <= 'z')
          i = 0;
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x+j][y+k] >= 'A' && tab[x+j][y+k] <= 'Z')
          i = 0;
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x+j][y+k] >= 'A' && tab[x+j][y+k] <= 'Z')
        {
          pos[x+j][y+k] = '!';
          i = 0;
        }
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x+j][y+k] >= 'a' && tab[x+j][y+k] <= 'z')
        {
          pos[x+j][y+k] = '!';
          i = 0;
        }
        k--;
        j++;
      }
      i = 1;
      j = k = 1;
      while(x+j < 8 && y+k < 8 && i)
      {
        if(tab[x+j][y+k] == ' ')
          pos[x+j][y+k] = '.';
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x+j][y+k] >= 'a' && tab[x+j][y+k] <= 'z')
          i = 0;
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x+j][y+k] >= 'A' && tab[x+j][y+k] <= 'Z')
          i = 0;
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x+j][y+k] >= 'A' && tab[x+j][y+k] <= 'Z')
        {
          pos[x+j][y+k] = '!';
          i = 0;
        }
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x+j][y+k] >= 'a' && tab[x+j][y+k] <= 'z')
        {
          pos[x+j][y+k] = '!';
          i = 0;
        }
        k++;
        j++;
      }
      i = 1;
      j = -1;
      k = 1;
      while(x+j >= 0 && y+k < 8 && i)
      {
        if(tab[x+j][y+k] == ' ')
          pos[x+j][y+k] = '.';
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x+j][y+k] >= 'a' && tab[x+j][y+k] <= 'z'){
          i = 0;
        }
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x+j][y+k] >= 'A' && tab[x+j][y+k] <= 'Z')
          i = 0;
        else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x+j][y+k] >= 'A' && tab[x+j][y+k] <= 'Z')
        {
          pos[x+j][y+k] = '!';
          i = 0;
        }
        else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x+j][y+k] >= 'a' && tab[x+j][y+k] <= 'z')
        {
          pos[x+j][y+k] = '!';
          i = 0;
        }
        k++;
        j--;
      }
    }
    void ve_cavalo()
    {
      int i, j;
      for(i = -2; i<3; i++)
      {
        for(j = -2; j<3; j++)
        {
          if(j && i && abs(i) != abs(j) && (x+i) < 8 && (x+i) >= 0 && (y+j) < 8 && (y+j) >= 0)
          {
            if(tab[x+i][y+j] == ' ')
              pos[x+i][y+j] = '.';
            else if(tab[x][y] <= 'z' && tab[x][y] >= 'a' && tab[x+i][y+j] >= 'A' && tab[x+i][y+j] <= 'Z')
              pos[x+i][y+j] = '!';
            else if(tab[x][y] <= 'Z' && tab[x][y] >= 'A' && tab[x+i][y+j] >= 'a' && tab[x+i][y+j] <= 'z')
              pos[x+i][y+j] = '!';
          }
        }
      }
    }
    void ve_peao()
    {
      if(tab[x][y] == 'i')
      {
        if(tab[x-1][y] == ' ')
          pos[x-1][y]='.';
        if(x > 0 && (tab[x-1][y-1] >= 'A' && tab[x-1][y-1] <= 'Z'))
          pos[x-1][y-1] = '!';
        if(x < 7 && (tab[x-1][y+1] >= 'A' && tab[x-1][y+1] <= 'Z'))
          pos[x-1][y+1] = '!';
      }
      else if(tab[x][y] == 'I')
      {
        if(tab[x+1][y] == ' ')
          pos[x+1][y]='.';
        if(x > 0 && (tab[x+1][y-1] >= 'a' && tab[x+1][y-1] <= 'z'))
          pos[x+1][y-1] = '!';
        if(x < 7 && (tab[x+1][y+1] >= 'a' && tab[x+1][y+1] <= 'z'))
          pos[x+1][y+1] = '!';
      }
    }
    void ve_rei()
    {
      int i, j, a = 0, b = 0;
      if(tab[x][y] == 'k')
      {
        for(i = -1; i<2; i++)
          for(j=-1; j<2; j++)
            if((i || j) && (x-i) >= 0 && (x-i) < 8 && (y-j) >= 0 && (y-j) < 8)
            {
              if(tab[x-i][y-j] == ' ')
                pos[x-i][y-j]='.';
              else if(tab[x-i][y-j] >= 'A' && tab[x-i][y-j] <= 'Z')
                pos[x-i][y-j] = '!';
            }
        for(i = 0; i<8 && tab[a][b] != 'K' ; i++)
          for(j = 0; j<8 && tab[a][b] != 'K'; j++)
            if(tab[i][j] == 'K')
            {
              a = i;
              b = j;
            }
        for(i = -1; i<2; i++)
          for(j=-1; j<2; j++)
            if((a-i) >= 0 && (a-i) < 8 && (b-j) >= 0 && (b-j) < 8)
              pos[a-i][b-j] = ' ';
      }
      else if(tab[x][y] == 'K')
      {
        for(i = -1; i<2; i++)
          for(j=-1; j<2; j++)
            if((i || j) && (x-i) >= 0 && (x-i) < 8 && (y-j) >= 0 && (y-j) < 8)
            {
              if(tab[x-i][y-j] == ' ')
                pos[x-i][y-j]='.';
              else if(tab[x-i][y-j] >= 'a' && tab[x-i][y-j] <= 'z')
                pos[x-i][y-j] = '!';
            }
        for(i = 0; i<8 && tab[a][b] != 'k' ; i++)
          for(j = 0; j<8 && tab[a][b] != 'k'; j++)
            if(tab[i][j] == 'k')
            {
              a = i;
              b = j;
            }
        for(i = -1; i<2; i++)
          for(j=-1; j<2; j++)
            if((a-i) >= 0 && (a-i) < 8 && (b-j) >= 0 && (b-j) < 8)
              pos[a-i][b-j] = ' ';
      }
    }
    if(tab[x][y] == 'i' || tab[x][y] == 'I')
      ve_peao();
    else if(tab[x][y] == 'c' || tab[x][y] == 'C')
      ve_cavalo();
    else if(tab[x][y] == 'b' || tab[x][y] == 'B')
      ve_bispo();
    else if(tab[x][y] == 't' || tab[x][y] == 'T')
      ve_torre();
    else if(tab[x][y] == 'k' || tab[x][y] == 'K')
      ve_rei();
    else if(tab[x][y] == 'q' || tab[x][y] == 'Q')
    {
      ve_torre();
      ve_bispo();
    }
    for(i = 0; i<8; i++)
      for(j = 0; j<8; j++)
        if(pos[i][j] != ' ')
          return 1;
    return 0;
  }
  int rei_morto()
  {
    int i, j, a = 0;
    for(i = 0; i<8; i++)
    {
      for(j = 0; j<8; j++)
      {
        if(tab[i][j] == 'k')
          a = 1;
      }
    }
    if(!a)
      return 2;
    a = 0;
    for(i = 0; i<8; i++)
    {
      for(j = 0; j<8; j++)
      {
        if(tab[i][j] == 'K')
          a = 1;
      }
    }
    if(!a)
      return 1;
    return 0;
  }
  novo();
  menu(2);
  while(scanf("%d", &opcao) && opcao != 3)
  {
    menu(0);
    if(opcao == 1)
      novo();
    if(opcao < 3 && opcao > 0)
    {
      ajuste = 0;
      do
      {
        menu(1);
        limpa_pos();
        imprime();
        printf("Digite as casas a serem acessadas:\n");
        ajuste++;
        ajuste%=2;
        do{
          
          do
          {
            limpa_pos();
              leia_usuario(&x, &y);
              a = verifica_movimento();
          }while(tab[x][y] == ' ' || (!ajuste && !(tab[x][y] <= 'Z' && tab[x][y] >= 'A')) || (ajuste && !(tab[x][y] <= 'z' && tab[x][y] >= 'a')) || !a);
          menu(1);
          imprime();
          printf("Digite as casas a serem acessadas:\n");
          do
          {
             leia_usuario(&a, &b);
             if(pos[a][b] == ' ' && !(a == x && b == y))
               printf("Comando não valido, digite um comando valido:  ");
          }while(pos[a][b] == ' ' && !(a == x && b == y));
          if(x == a && y == b && x != -1)
          {
            opcao = 1;
            menu(1);
            limpa_pos();
            imprime();
            printf("Não foi possivel fazer tal movimento\n");
            printf("Digite as casas a serem acessadas:\n");
          }
          else
            opcao = 0;
        }while(opcao);
        move_peca();
      }while(x >= 0 && a >= 0 && !rei_morto());
      menu(1);
      limpa_pos();
      imprime();
      printf("Jogador %d ganhou!\n", rei_morto());
      aperte_tecla(ENTER);
      menu(2);
    }
    else
    {
      menu(2);
      printf("Comando não possivel, digite um comando válido:  ");
    }
  }
  
  
  
  aperte_tecla(ENTER);
}