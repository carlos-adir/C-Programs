
/**      @file: 150121059.c
  *     @author: Carlos Adir Ely Murussi Leite (carlos.adir.leite@gmail.com)
  *  @matricula: 150121059
  * @disciplina: Algoritmos e Programação de Computadores
  *
  * Esse algoritmo implementado em C é para o trabalho 2. Desde a implementação do trabalho 1, foram feitos 
  * mais dois jogos: Campo minado e Roda roda. Além que foram refeitos os jogos Senha, Charadas, Pedra-papel-tesoura e 2048. */




/* Funcoes utilizadas em todos os jogos */

void limpa_buffer()
{
    while(kbhit())
    {
        getch();
    }
}
int abs_int(int numero)
{
  return (numero < 0 ? -numero : numero);
}
void aperte_tecla(char tecla)
{
  char caracter;
  limpa_buffer();
  if(!tecla)
  {
    printf("\n\nAperte qualquer tecla para continuar...");
    getch();
  }
  else
  {
    if(tecla == ESC)
      printf("\n\nAperte ESC para continuar..."); 
    else if(tecla == ENTER)
      printf("\n\nAperte ENTER para continuar...");
    else
      printf("\n\nAperte %c para continuar...", tecla);
    do
    {
      caracter = getch();
    }while(caracter != tecla);
  }
}
int pega_algarismo(int minimo, int maximo)
{
    char caracter;
    limpa_buffer();
    do
    {
        caracter = getch();
    }while(!( caracter >= '0' + minimo && caracter <= '0' + maximo ) && caracter != ESC);
    if(caracter == ESC)
        return 0;
    return caracter - '0';
}
char pega_letra(char inicial, char final, char inicial2, char final2)
{
  char caracter;
  limpa_buffer();
  do
  {
    caracter = getch();
  }while(!(caracter <= final && caracter >= inicial) && !(caracter <= final2 && caracter >= inicial2) && caracter != ESC);
  if(caracter == ESC)
    return 0;
  return caracter;
}
int pega_numero_grande()
{
  char numero[11];
  int soma=0, contador = 0;
  scanf(" %9s", numero);
  limpa_buffer();
  do
  {
    soma*=10;
    if(!(numero[contador]>= '0' && numero[contador] <= '9'))
      return -1;
    soma+=(numero[contador] - '0');
    contador++;
  }while(numero[contador] != '\0');
  return soma;
}
void pega_palavra_no_arquivo(FILE *arquivo, char limite, char *palavra)
{
  int i = -1;
  char c;
  do
  {
    i++;
    c = fgetc(arquivo);
    *(palavra+i) = c;
  }while( c != limite);
  *(palavra+i) = '\0';
}
void copia(char *str1, char *str2)
{
  int i = -1;
  do
  {
    i++;
    *(str2+i) = *(str1+i);
  }while(*(str2+i) != '\0');
}
int pega_quatro_setas() /* Retorna CIMA = 1, BAIXO = 2, ESQUERDA = 4, DIREITA = 3.*/
{
  char car[3];
  do
  {
    do
    {
      do
      {
        car[0] = getch();
      }while(car[0] != 27);
      if(!kbhit())
        return 0;
      car[1] = getch();
    }while(car[1] != 91);
    car[2] = getch();
  }while(car[2] < 65 || car[2] > 68);
  return car[2] - 64;
}
int pega_duas_setas()
{
  char car[3];
  do
  {
    do
    {
      do
      {
        car[0] = getch();
      }while(car[0] != 27);
      if(!kbhit())
        return 0;
      car[1] = getch();
    }while(car[1] != 91);
    car[2] = getch();
  }while(car[2] < 65 || car[2] > 66);
  return car[2] - 64;
}
int mede_tamanho_string(char *string)
{
  int tamanho = 0;
  while(*(string+tamanho) != '\0')
    tamanho++;
  return tamanho;
}
void imprime_string(char *str, int tam)
{
  int i, tamanho = mede_tamanho_string(str);
  if(tamanho < espaco)
  {
    for(i = 0; i < tam - tamanho; i++)
      putchar(' ');
    printf("%s", str);
  }
}
void troca_inteiro(int *p, int *q)
{
  int aux = *p;
  *p = *q;
  *q = aux;
}
void troca_nomes(char *str1, char *str2)
{
  char c;
  int i;
  for(i = 0; i < carac; i++)
  {
    c = *(str1+i);
    *(str1+i) = *(str2+i);
    *(str2+i) = c;
  }
}
int compara_string(char *str1, char *str2) /* Retorna 1 caso sejam iguais */
{
  int i = 0;
  while(*(str1+i) == *(str2+i) && (*(str1+i) != '\0' || *(str2+i) != '\0'))
    i++;
  if(*(str1+i) == '\0' && *(str2+i) == '\0')
    return 1;
  return 0;
}
int existe_arquivo(char *str) /* Retorna 1 caso exista */
{
  FILE *arquivo = fopen(str, read);
  if(arquivo == NULL)
    return 0;
  else
    fclose(arquivo);
  return 1;
}

