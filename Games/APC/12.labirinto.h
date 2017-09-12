int labirinto()
{
  int numero_do_usuario;
  void menu_opcoes()
  {
    system("clear");
    printf("*************\n");
    printf("* Labirinto *\n");
    printf("*************\n");
    printf("\n");
    printf("1) Jogar\n");
    printf("2) Configurações\n");
    printf("3) Instrucoes\n\n");
    printf("0) Sair\n");
    printf("\n");
    printf("Digite uma opcao:  ");
  }
  void jogar()
  {
    void menu_jogar()
    {
      system("clear");
      printf("*************\n");
      printf("* Labirinto *\n");
      printf("*************\n");
      printf("\n");
    }
  }
  int configuracoes()
  {
    void menu_configuracoes()
    {
      system("clear");
      printf("*************\n");
      printf("* Labirinto *\n");
      printf("*************\n");
      printf("\n");
      printf("1) Alterar o numero maximo(atual: %d)\n", 3);
      printf("2) Voltar ao menu alterior\n");
    }
    return 0;
  }
  void instrucoes()
  {
    system("clear");
    printf("Instrucoes!\n");
  }
  while(1)
  {
    menu_opcoes();
    numero_do_usuario = pega_algarismo(0, 3);
    if(numero_do_usuario == 1)
      jogar();
    else if(numero_do_usuario == 2)
      configuracoes();
    else if(numero_do_usuario == 3)
      instrucoes();
    else
    {
      limpa_buffer();
      return 0;
    }
  }
}