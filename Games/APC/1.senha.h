/*
typedef struct
{
  char nome[carac];
  int point[jogos], total;
} geral;
typedef struct
{
  char nome[carac];
  int valor;
} individual;
typedef struct
{
  individual w_[player];
} completo;

*/
int senha(completo *record, geral *dado, int *posicao)
{
  int numero_maximo = 0, pontuacao=0;
  int senha, numero_do_usuario, tentativas;
  srand((unsigned)time(NULL));
  void menu_opcoes()
  {
    system("clear");
    printf("*********\n");
    printf("* Senha *\n");
    printf("*********\n");
    printf("\n");
    printf("1) Jogar\n");
    printf("2) Configurações\n");
    printf("3) Instrucoes\n");
    printf("4) Arrombadores de cofres\n\n");
    printf("0) Sair\n");
    printf("\n");
    printf("Digite uma opcao:  ");
  }
  void jogar()
  {
    void menu_jogar()
    {
      system("clear");
      printf("*********\n");
      printf("* Senha *\n");
      printf("*********\n");
      printf("\n");
    }
    int valor_da_pontuacao(int a, int b)
    {
      return 30-b;
      int retorno;
      double auxiliar;
      auxiliar = log(a);
      auxiliar /= log(2);
      retorno = 2*ceil(auxiliar);
      retorno -= b;
      return retorno < 0 ? 0 : retorno;
    }
    tentativas = pontuacao = 0;
    senha = rand()%(numero_maximo + 1);
    menu_jogar();
    printf("Já escolhi o numero!\n\n");
    aperte_tecla(ENTER);
    menu_jogar();
    printf("Digite seu palpite:  ");
    numero_do_usuario = pega_numero_grande();
    while(numero_do_usuario >= 0 && numero_do_usuario != senha)
    {
      tentativas++;
      menu_jogar();
      if(abs_int(numero_do_usuario - senha) > numero_maximo/3)
        printf("Estás frio! ");
      else if(abs_int(numero_do_usuario - senha) > numero_maximo/9)
        printf("Estás morno! ");
      else if(abs_int(numero_do_usuario- senha) > numero_maximo/27)
        printf("Estás quente! ");
      else
        printf("Estás  muito perto! ");
      if(numero_do_usuario < senha)
        printf("O resultado está acima do valor!\n\n");
      else
        printf("O resultado está abaixo desse valor!\n\n");
      printf("Digite um valor:  ");
      numero_do_usuario = pega_numero_grande();
    }
    if(numero_do_usuario == senha)
    {
      menu_jogar();
      printf("Parabéns, a senha é %d! Como descobriu com apenas %d tentativas?\n\n", senha, tentativas+1);
      pontuacao = valor_da_pontuacao(numero_maximo, tentativas); /* Para melhorar aqui, basta mudar os valores, para teste usaremos esse */
      if(pontuacao > *(dado->point+0)){
        dado->total -= *(dado->point+0);
        *(dado->point+0) = pontuacao;
        dado->total += pontuacao;
      }
    }
    else
    {
      menu_jogar();
      printf("Que pena! Você desistiu! Vencedores não são os que nunca perdem, mas sim aqueles que nunca param de tentar.\n");
      printf("A senha era %d e foram %d tentativas no total\n\n", senha, tentativas+1);
    }
    aperte_tecla(0);
  }
  int configuracoes()
  {
    void menu_configuracoes()
    {
      system("clear");
      printf("*********\n");
      printf("* Senha *\n");
      printf("*********\n");
      printf("\n");
      printf("1) Alterar o numero maximo(atual: %d)\n\n\n\n", numero_maximo);
      printf("0) Voltar ao menu alterior\n");
    }
    while(1)
    {
      menu_configuracoes();
      numero_do_usuario = pega_algarismo(0, 1);
      if(numero_do_usuario == 1)
      {
        menu_configuracoes();
        printf("\n\nDigite o novo numero maximo:  ");
        numero_do_usuario = pega_numero_grande();
        if(numero_do_usuario > 1)
          numero_maximo = numero_do_usuario;
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
    printf("* Bem vindo à sala dos Arrombadores de Cofres *\n");
    printf("***********************************************\n");
    printf("\n");
    for(i = 0; i < player; i++)
    {
      printf("%dº Lugar - ", i+1);
      imprime_string(((record+0)->w_+i)->nome,espaco);
      printf(": %d\n", ((record+0)->w_+i)->valor );
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
    *(posicao+1) = organiza_posicao_completo(record, dado, *(posicao+1), 1);
  }
}