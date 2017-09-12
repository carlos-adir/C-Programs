int roda_roda(completo *record, geral *dado, int *posicao)
{
  const int MAX = 10;
  int numero_do_usuario, erros_maximos = 4, erros, pontuacao;
  char palavras[7][100], letra;
  srand((unsigned)time(NULL));
  void menu_opcoes()
  {
    system("clear");
    printf("***************\n");
    printf("* Roda a Roda *\n");
    printf("***************\n");
    printf("\n");
    printf("1) Jogar\n");
    printf("2) Configurações\n");
    printf("3) Instrucoes\n");
    printf("4) Sala das Consultoras\n\n");
    printf("0) Sair\n");
    printf("\n");
    printf("Digite uma opcao:  ");
  }
  void jogar()
  {
    void menu_jogar()
    {
      system("clear");
      printf("***************\n");
      printf("* Roda a Roda *\n");
      printf("***************\n");
      printf("\n");
      printf("Erros: %d\n\n", erros);
    }
    int novas_palavras(int semente)
    {
      int a=-1, b=-2, probabilidade, i;
      if(semente == 1)
      {
        copia("Animais", &palavras[0][0]);
        for(i = 1; i<4; i++)
        {
          do
          {
            probabilidade = rand()%40; 
          }while(probabilidade == a || probabilidade == b);
          if(i == 1)
            a = probabilidade;
          else if(i == 2)
            b = probabilidade;
          switch(probabilidade)
          {
            case 0: copia("ornitorrinco", &palavras[i][0]);break;
            case 1: copia("girafa", &palavras[i][0]);break;
            case 2: copia("onca pintada", &palavras[i][0]);break;
            case 3: copia("leao", &palavras[i][0]);break;
            case 4: copia("avestruz", &palavras[i][0]);break;
            case 5: copia("aranha", &palavras[i][0]);break;
            case 6: copia("burro", &palavras[i][0]);break;
            case 7: copia("coruja", &palavras[i][0]);break;
            case 8: copia("aguia", &palavras[i][0]);break;
            case 9: copia("borboleta", &palavras[i][0]);break;
            case 10: copia("baleia", &palavras[i][0]);break;
            case 11: copia("cavalo", &palavras[i][0]);break;
            case 12: copia("corvo", &palavras[i][0]);break;
            case 13: copia("cachorro", &palavras[i][0]);break;
            case 14: copia("elefante", &palavras[i][0]);break;
            case 15: copia("esquilo", &palavras[i][0]);break;
            case 16: copia("formiga", &palavras[i][0]);break;
            case 17: copia("hipopotamo", &palavras[i][0]);break;
            case 18: copia("jacare", &palavras[i][0]);break;
            case 19: copia("lagarta", &palavras[i][0]);break;
            case 20: copia("leopardo", &palavras[i][0]);break;
            case 21: copia("urso", &palavras[i][0]);break;
            case 22: copia("macaco", &palavras[i][0]);break;
            case 23: copia("mosquito", &palavras[i][0]);break;
            case 24: copia("ovelha", &palavras[i][0]);break;
            case 25: copia("pato", &palavras[i][0]);break;
            case 26: copia("pavao", &palavras[i][0]);break;
            case 27: copia("porco", &palavras[i][0]);break;
            case 28: copia("raposa", &palavras[i][0]);break;
            case 29: copia("rato", &palavras[i][0]);break;
            case 30: copia("peru", &palavras[i][0]);break;
            case 31: copia("pombo", &palavras[i][0]);break;
            case 32: copia("rinoceronte", &palavras[i][0]);break;
            case 33: copia("sapo", &palavras[i][0]);break;
            case 34: copia("tartaruga", &palavras[i][0]);break;
            case 35: copia("texugo", &palavras[i][0]);break;
            case 36: copia("tigre", &palavras[i][0]);break;
            case 37: copia("veado", &palavras[i][0]);break;
            case 38: copia("zebra", &palavras[i][0]);break;
            case 39: copia("tucunare", &palavras[i][0]);break;
          }
        }
      }
      else if(semente == 2)
      {
        copia("Carnes", &palavras[0][0]);
        for(i = 1; i<4; i++)
        {
          do
          {
            probabilidade = rand()%30; 
          }while(probabilidade == a || probabilidade == b);
          if(i == 1)
            a = probabilidade;
          else if(i == 2)
            b = probabilidade;
          switch(probabilidade)
          {
            case 0: copia("fraudinha", &palavras[i][0]);break;
            case 1: copia("musculo", &palavras[i][0]);break;
            case 2: copia("cupim", &palavras[i][0]);break;
            case 3: copia("atum", &palavras[i][0]);break;
            case 4: copia("alcatra", &palavras[i][0]);break;
            case 5: copia("lombo", &palavras[i][0]);break;
            case 6: copia("acem", &palavras[i][0]);break;
            case 7: copia("file mignon", &palavras[i][0]);break;
            case 8: copia("picanha", &palavras[i][0]);break;
            case 9: copia("patinho", &palavras[i][0]);break;
            case 10: copia("figado", &palavras[i][0]);break;
            case 11: copia("coxao mole", &palavras[i][0]);break;
            case 12: copia("coxao duro", &palavras[i][0]);break;
            case 13: copia("figado", &palavras[i][0]);break;
            case 14: copia("mocoto", &palavras[i][0]);break;
            case 15: copia("paleta", &palavras[i][0]);break;
            case 16: copia("salsicha", &palavras[i][0]);break;
            case 17: copia("pernil", &palavras[i][0]);break;
            case 18: copia("bisteca", &palavras[i][0]);break;
            case 19: copia("costela", &palavras[i][0]);break;
            case 20: copia("coxa", &palavras[i][0]);break;
            case 21: copia("asa", &palavras[i][0]);break;
            case 22: copia("peito", &palavras[i][0]);break;
            case 23: copia("sobrecoxa", &palavras[i][0]);break;
            case 24: copia("salmao", &palavras[i][0]);break;
            case 25: copia("sardinha", &palavras[i][0]);break;
            case 26: copia("tilapia", &palavras[i][0]);break;
            case 27: copia("camarao", &palavras[i][0]);break;
            case 28: copia("lagosta", &palavras[i][0]);break;
            case 29: copia("polvo", &palavras[i][0]);break;
          }
        }
      }
      else if(semente == 3)
      {
        copia("Computador", &palavras[0][0]);
        for(i = 1; i<4; i++)
        {
          do
          {
            probabilidade = rand()%26; 
          }while(probabilidade == a || probabilidade == b);
          if(i == 1)
            a = probabilidade;
          else if(i == 2)
            b = probabilidade;
          switch(probabilidade)
          {
            case 0: copia("teclado", &palavras[i][0]);break;
            case 1: copia("impressora", &palavras[i][0]);break;
            case 2: copia("monitor", &palavras[i][0]);break;
            case 3: copia("hardware", &palavras[i][0]);break;
            case 4: copia("software", &palavras[i][0]);break;
            case 5: copia("mouse", &palavras[i][0]);break;
            case 6: copia("transistores", &palavras[i][0]);break;
            case 7: copia("internet", &palavras[i][0]);break;
            case 8: copia("servidor", &palavras[i][0]);break;
            case 9: copia("nuvem", &palavras[i][0]);break;
            case 10: copia("programacao", &palavras[i][0]);break;
            case 11: copia("portas logicas", &palavras[i][0]);break;
            case 12: copia("touchpad", &palavras[i][0]);break;
            case 13: copia("windows", &palavras[i][0]);break;
            case 14: copia("linux", &palavras[i][0]);break;
            case 15: copia("kernel", &palavras[i][0]);break;
            case 16: copia("processador", &palavras[i][0]);break;
            case 17: copia("placa mae", &palavras[i][0]);break;
            case 18: copia("placa de video", &palavras[i][0]);break;
            case 19: copia("leitor de cd", &palavras[i][0]);break;
            case 20: copia("disquete", &palavras[i][0]);break;
            case 21: copia("memoria", &palavras[i][0]);break;
            case 22: copia("armazenamento", &palavras[i][0]);break;
            case 23: copia("calculo", &palavras[i][0]);break;
            case 24: copia("wi fi", &palavras[i][0]);break;
            case 25: copia("email", &palavras[i][0]);break;
          }
        }
      }
      else if(semente == 4)
      {
        copia("Dança", &palavras[0][0]);
        for(i = 1; i<4; i++)
        {
          do
          {
            probabilidade = rand()%25; 
          }while(probabilidade == a || probabilidade == b);
          if(i == 1)
            a = probabilidade;
          else if(i == 2)
            b = probabilidade;
          switch(probabilidade)
          {
            case 0: copia("frevo", &palavras[i][0]);break;
            case 1: copia("forro", &palavras[i][0]);break;
            case 2: copia("tango", &palavras[i][0]);break;
            case 3: copia("baiao", &palavras[i][0]);break;
            case 4: copia("bolero", &palavras[i][0]);break;
            case 5: copia("capoeira", &palavras[i][0]);break;
            case 6: copia("carimbo", &palavras[i][0]);break;
            case 7: copia("danca de rua", &palavras[i][0]);break;
            case 8: copia("fandango", &palavras[i][0]);break;
            case 9: copia("funk", &palavras[i][0]);break;
            case 10: copia("free step", &palavras[i][0]);break;
            case 11: copia("hip hop", &palavras[i][0]);break;
            case 12: copia("jazz", &palavras[i][0]);break;
            case 13: copia("kuduro", &palavras[i][0]);break;
            case 14: copia("lambada", &palavras[i][0]);break;
            case 15: copia("maracatu", &palavras[i][0]);break;
            case 16: copia("merengue", &palavras[i][0]);break;
            case 17: copia("pagode", &palavras[i][0]);break;
            case 18: copia("pole dance", &palavras[i][0]);break;
            case 19: copia("danca do ventre", &palavras[i][0]);break;
            case 20: copia("salsa", &palavras[i][0]);break;
            case 21: copia("samba", &palavras[i][0]);break;
            case 22: copia("sapateado", &palavras[i][0]);break;
            case 23: copia("zouk", &palavras[i][0]);break;
            case 24: copia("zumba", &palavras[i][0]);break;
          }
        }
      }
      else if(semente == 5)
      {
        copia("Casa", &palavras[0][0]);
        for(i = 1; i<4; i++)
        {
          do
          {
            probabilidade = rand()%23; 
          }while(probabilidade == a || probabilidade == b);
          if(i == 1)
            a = probabilidade;
          else if(i == 2)
            b = probabilidade;
          switch(probabilidade)
          {
            case 0: copia("chuveiro", &palavras[i][0]);break;
            case 1: copia("cama", &palavras[i][0]);break;
            case 2: copia("cozinha", &palavras[i][0]);break;
            case 3: copia("jardim", &palavras[i][0]);break;
            case 4: copia("quintal", &palavras[i][0]);break;
            case 5: copia("banheiro", &palavras[i][0]);break;
            case 6: copia("quarto", &palavras[i][0]);break;
            case 7: copia("porao", &palavras[i][0]);break;
            case 8: copia("sotao", &palavras[i][0]);break;
            case 9: copia("chamine", &palavras[i][0]);break;
            case 10: copia("janela", &palavras[i][0]);break;
            case 11: copia("mesa", &palavras[i][0]);break;
            case 12: copia("cadeira", &palavras[i][0]);break;
            case 13: copia("televisao", &palavras[i][0]);break;
            case 14: copia("criado mudo", &palavras[i][0]);break;
            case 15: copia("estante", &palavras[i][0]);break;
            case 16: copia("quadro", &palavras[i][0]);break;
            case 17: copia("guarda roupa", &palavras[i][0]);break;
            case 18: copia("fogao", &palavras[i][0]);break;
            case 19: copia("geladeira", &palavras[i][0]);break;
            case 20: copia("pia", &palavras[i][0]);break;
            case 21: copia("churrasqueira", &palavras[i][0]);break;
            case 22: copia("sofa", &palavras[i][0]);break;
          }
        }
      }
      else if(semente == 6)
      {
        copia("Matematica", &palavras[0][0]);
        for(i = 1; i<4; i++)
        {
          do
          {
            probabilidade = rand()%35; 
          }while(probabilidade == a || probabilidade == b);
          if(i == 1)
            a = probabilidade;
          else if(i == 2)
            b = probabilidade;
          switch(probabilidade)
          {
            case 0: copia("integral", &palavras[i][0]);break;
            case 1: copia("bijetividade", &palavras[i][0]);break;
            case 2: copia("matriz", &palavras[i][0]);break;
            case 3: copia("derivada", &palavras[i][0]);break;
            case 4: copia("injetividade", &palavras[i][0]);break;
            case 5: copia("gradiente", &palavras[i][0]);break;
            case 6: copia("divergente", &palavras[i][0]);break;
            case 7: copia("rotacional", &palavras[i][0]);break;
            case 8: copia("transformada de laplace", &palavras[i][0]);break;
            case 9: copia("series", &palavras[i][0]);break;
            case 10: copia("sequencia", &palavras[i][0]);break;
            case 11: copia("funcao", &palavras[i][0]);break;
            case 12: copia("exponencial", &palavras[i][0]);break;
            case 13: copia("logaritmo", &palavras[i][0]);break;
            case 14: copia("tabuada", &palavras[i][0]);break;
            case 15: copia("multiplicacao", &palavras[i][0]);break;
            case 16: copia("soma", &palavras[i][0]);break;
            case 17: copia("divisao", &palavras[i][0]);break;
            case 18: copia("subtracao", &palavras[i][0]);break;
            case 19: copia("progressao", &palavras[i][0]);break;
            case 20: copia("ponto critico", &palavras[i][0]);break;
            case 21: copia("algebra linear", &palavras[i][0]);break;
            case 22: copia("aritmetica", &palavras[i][0]);break;
            case 23: copia("teoria dos numeros", &palavras[i][0]);break;
            case 24: copia("geometria", &palavras[i][0]);break;
            case 25: copia("numeros complexos", &palavras[i][0]);break;
            case 26: copia("triangulo", &palavras[i][0]);break;
            case 27: copia("quadrado", &palavras[i][0]);break;
            case 28: copia("pentagono", &palavras[i][0]);break;
            case 29: copia("dodecaedro", &palavras[i][0]);break;
            case 30: copia("hexaedro", &palavras[i][0]);break;
            case 31: copia("cubo", &palavras[i][0]);break;
            case 32: copia("paralelepipedo", &palavras[i][0]);break;
            case 33: copia("equacao diferencial", &palavras[i][0]);break;
            case 34: copia("soma de riemann", &palavras[i][0]);break;
          }
        }
      }
      else if(semente == 7)
      {
        copia("Fisica", &palavras[0][0]);
        for(i = 1; i<4; i++)
        {
          do
          {
            probabilidade = rand()%40; 
          }while(probabilidade == a || probabilidade == b);
          if(i == 1)
            a = probabilidade;
          else if(i == 2)
            b = probabilidade;
          switch(probabilidade)
          {
            case 0: copia("eletron", &palavras[i][0]);break;
            case 1: copia("gravitacao", &palavras[i][0]);break;
            case 2: copia("quantico", &palavras[i][0]);break;
            case 3: copia("mecanica", &palavras[i][0]);break;
            case 4: copia("eletrodinamica", &palavras[i][0]);break;
            case 5: copia("magnetismo", &palavras[i][0]);break;
            case 6: copia("inercia", &palavras[i][0]);break;
            case 7: copia("quark", &palavras[i][0]);break;
            case 8: copia("proton", &palavras[i][0]);break;
            case 9: copia("neutron", &palavras[i][0]);break;
            case 10: copia("relatividade", &palavras[i][0]);break;
            case 11: copia("ondas", &palavras[i][0]);break;
            case 12: copia("calor", &palavras[i][0]);break;
            case 13: copia("temperatura", &palavras[i][0]);break;
            case 14: copia("pressao", &palavras[i][0]);break;
            case 15: copia("deslocamento", &palavras[i][0]);break;
            case 16: copia("velocidade", &palavras[i][0]);break;
            case 17: copia("aceleracao", &palavras[i][0]);break;
            case 18: copia("pertubacao", &palavras[i][0]);break;
            case 19: copia("interferencia", &palavras[i][0]);break;
            case 20: copia("ressonancia", &palavras[i][0]);break;
            case 21: copia("difracao", &palavras[i][0]);break;
            case 22: copia("refracao", &palavras[i][0]);break;
            case 23: copia("reflexao", &palavras[i][0]);break;
            case 24: copia("momento angular", &palavras[i][0]);break;
            case 25: copia("momento linear", &palavras[i][0]);break;
            case 26: copia("massa", &palavras[i][0]);break;
            case 27: copia("spin", &palavras[i][0]);break;
            case 28: copia("carga eletrica", &palavras[i][0]);break;
            case 29: copia("foton", &palavras[i][0]);break;
            case 30: copia("buraco negro", &palavras[i][0]);break;
            case 31: copia("big bang", &palavras[i][0]);break;
            case 32: copia("astronomia", &palavras[i][0]);break;
            case 33: copia("super nova", &palavras[i][0]);break;
            case 34: copia("estrela", &palavras[i][0]);break;
            case 35: copia("resistores", &palavras[i][0]);break;
            case 36: copia("indutores", &palavras[i][0]);break;
            case 37: copia("capacitores", &palavras[i][0]);break;
            case 38: copia("leis de newton", &palavras[i][0]);break;
            case 39: copia("estrela de neutrons", &palavras[i][0]);break;
          }
        } 
      }
      else if(semente == 8)
      {
        copia("Quimica", &palavras[0][0]);
        for(i = 1; i<4; i++)
        {
          do
          {
            probabilidade = rand()%3; 
          }while(probabilidade == a || probabilidade == b);
          if(i == 1)
            a = probabilidade;
          else if(i == 2)
            b = probabilidade;
          switch(probabilidade)
          {
            case 0: copia("orbital", &palavras[i][0]);break;
            case 1: copia("equilibrio", &palavras[i][0]);break;
            case 2: copia("radioativo", &palavras[i][0]);break;
          }
        }
      }
      else if(semente == 9)
      {
        copia("Frutas", &palavras[0][0]);
        for(i = 1; i<4; i++)
        {
          do
          {
            probabilidade = rand()%31; 
          }while(probabilidade == a || probabilidade == b);
          if(i == 1)
            a = probabilidade;
          else if(i == 2)
            b = probabilidade;
          switch(probabilidade)
          {
            case 0: copia("manga", &palavras[i][0]);break;
            case 1: copia("pequi", &palavras[i][0]);break;
            case 2: copia("morango", &palavras[i][0]);break;
            case 3: copia("uva", &palavras[i][0]);break;
            case 4: copia("jambo", &palavras[i][0]);break;
            case 5: copia("tomate", &palavras[i][0]);break;
            case 6: copia("jaca", &palavras[i][0]);break;
            case 7: copia("caqui", &palavras[i][0]);break;
            case 8: copia("maca", &palavras[i][0]);break;
            case 9: copia("banana", &palavras[i][0]);break;
            case 10: copia("tamarindo", &palavras[i][0]);break;
            case 11: copia("abacate", &palavras[i][0]);break;
            case 12: copia("jamelao", &palavras[i][0]);break;
            case 13: copia("fruta do conde", &palavras[i][0]);break;
            case 14: copia("buriti", &palavras[i][0]);break;
            case 15: copia("cupuacu", &palavras[i][0]);break;
            case 16: copia("goiaba", &palavras[i][0]);break;
            case 17: copia("pinha", &palavras[i][0]);break;
            case 18: copia("umbu", &palavras[i][0]);break;
            case 19: copia("kiwi", &palavras[i][0]);break;
            case 20: copia("cereja", &palavras[i][0]);break;
            case 21: copia("mamao", &palavras[i][0]);break;
            case 22: copia("jabuticaba", &palavras[i][0]);break;
            case 23: copia("amora", &palavras[i][0]);break;
            case 24: copia("caju", &palavras[i][0]);break;
            case 25: copia("limao", &palavras[i][0]);break;
            case 26: copia("laranja", &palavras[i][0]);break;
            case 27: copia("tangerina", &palavras[i][0]);break;
            case 28: copia("mexerica", &palavras[i][0]);break;
            case 29: copia("camapu", &palavras[i][0]);break;
            case 30: copia("amexa", &palavras[i][0]);break;
          }
        }
      }
      else if(semente == 10)
      {
        copia("Ferramentas", &palavras[0][0]);
        for(i = 1; i<4; i++)
        {
          do
          {
            probabilidade = rand()%21; 
          }while(probabilidade == a || probabilidade == b);
          if(i == 1)
            a = probabilidade;
          else if(i == 2)
            b = probabilidade;
          switch(probabilidade)
          {
            case 0: copia("serrote", &palavras[i][0]);break;
            case 1: copia("martelo", &palavras[i][0]);break;
            case 2: copia("foice", &palavras[i][0]);break;
            case 3: copia("chave de fenda", &palavras[i][0]);break;
            case 4: copia("tesoura", &palavras[i][0]);break;
            case 5: copia("macaco", &palavras[i][0]);break;
            case 6: copia("jacare", &palavras[i][0]);break;
            case 7: copia("pa", &palavras[i][0]);break;
            case 8: copia("chave de boca", &palavras[i][0]);break;
            case 9: copia("ferro de solda", &palavras[i][0]);break;
            case 10: copia("parafuso", &palavras[i][0]);break;
            case 11: copia("alicate", &palavras[i][0]);break;
            case 12: copia("porca", &palavras[i][0]);break;
            case 13: copia("prego", &palavras[i][0]);break;
            case 14: copia("facao", &palavras[i][0]);break;
            case 15: copia("rede", &palavras[i][0]);break;
            case 16: copia("fresa", &palavras[i][0]);break;
            case 17: copia("torno", &palavras[i][0]);break;
            case 18: copia("cavadeira", &palavras[i][0]);break;
            case 19: copia("picareta", &palavras[i][0]);break;
            case 20: copia("machado", &palavras[i][0]);break;
            }
        } 
      }
      return semente;
    }
    void nova_categoria()
    {
      int i, j;
      novas_palavras(rand()%MAX + 1);
      copia(palavras[1], palavras[4]);
      copia(palavras[2], palavras[5]);
      copia(palavras[3], palavras[6]);
      for(i = 4; i<7; i++)
      {
        j = 0;
        do
        {
          if(palavras[i][j] != ' ')
            palavras[i][j] = '_';
          j++;
        }while(palavras[i][j] != '\0');
      }
    }
    int conta_underline()
    {
      int i, j, contador = 0;
      for(i = 4; i < 8; i++)
      {
        j = 0;
        do
        {
          if(palavras[i][j] == '_')
            contador++;
          j++;
        }while(palavras[i][j] != '\0');
      }
      return contador;
    }
    int nao_terminou()
    {
      if(erros == erros_maximos+1)
        return 0;
      return conta_underline();
    }
    void imprime()
    {
      int i, j;
      for(i = 4; i<7; i++)
      {
        j = 0;
        while(palavras[i][j] != '\0')
        {
          printf(" %c", palavras[i][j]);
          j++;
        }
        printf("\n");
      }
      printf("\nDica: %s", palavras[0]);
    }
    int coloca_letra(char qual_letra)
    {
      int i, j, t = 0;
      for(i = 4; i < 8; i++)
      {
        j = 0;
        do
        {
          if(palavras[i-3][j] == qual_letra && palavras[i][j] == '_')
          {
            palavras[i][j] = qual_letra;
            t++;
          }
          j++;
        }while(palavras[i][j] != '\0');
      }
      return t;
    }
    nova_categoria();
    erros = 0;
    numero_do_usuario = nao_terminou();
    while(numero_do_usuario)
    {
      menu_jogar();
      imprime();
      printf("\nDigite uma letra:  ");
      letra = pega_letra('a', 'z', 'A', 'Z');
      numero_do_usuario = coloca_letra(letra);
      erros += (numero_do_usuario ? 0 : 1);
      numero_do_usuario = nao_terminou();
    }
    menu_jogar();
    imprime();
    if(conta_underline())
    {
      printf("\n\nVocê perdeu!\n");
      aperte_tecla(ENTER);
    }
    else
    {
    pontuacao = 20 - erros;
    if(pontuacao > *(dado->point+8))
    {
      dado->total -= *(dado->point+8);
        *(dado->point+8) = pontuacao;
        dado->total += pontuacao;
      }
      printf("\n\nVocê ganhou!\n");
      aperte_tecla(ENTER);
    }
  }
  int configuracoes()
  {
    void menu_configuracoes()
    {
      system("clear");
      printf("***************\n");
      printf("* Roda a Roda *\n");
      printf("***************\n");
      printf("\n");
      printf("1) Alterar o numero maximo de erros(atual: %d)\n\n", erros_maximos);
      printf("0) Voltar ao menu alterior\n");
    }
    while(1)
    {
      menu_configuracoes();
      numero_do_usuario = pega_algarismo(0, 1);
      if(numero_do_usuario == 1)
      {
        menu_configuracoes();
        printf("\nDigite o novo numero de erros maximos(entre 0 e 9):  ");
        numero_do_usuario = pega_algarismo(0, 9);
        erros_maximos = numero_do_usuario;
        aperte_tecla(ENTER);
      }
      else
        return 0;
    }
  }
  void instrucoes()
  {
    system("clear");
    printf("Esse jogo é o jogo Roda a Roda. Ele consiste em um grupo de palavras\n");
    printf("que devem ser descobertos através de letras. Após pressionar uma letra\n");
    printf("caso a letra esteja em algum lugar das palavras, ela será mostrada. E\n");
    printf("caso contrário, aumentará um erro. O jogo encerra caso o numero de \n");
    printf("erros seja maior que o permitido. O numero de erros é alterado através\n");
    printf("do menu configuracoes.");
    aperte_tecla(ENTER);
  }
  void rank_jogo()
  {
    int i;
    system("clear");
    printf("*********************************************\n");
    printf("* Bem vindo à sala das Melhores Consultoras *\n");
    printf("*********************************************\n");
    printf("\n");
    for(i = 0; i < player; i++)
    {
      printf("%dº Lugar - ", i+1);
      imprime_string(((record+8)->w_+i)->nome,espaco);
      printf(": %d\n", ((record+8)->w_+i)->valor );
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
    *(posicao+9) = organiza_posicao_completo(record, dado, *(posicao+9), 9);
  }
}