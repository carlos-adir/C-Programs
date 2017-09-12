


int ler_numero(FILE *arquivo)
{
  int numero;
  fread(&numero, sizeof(numero), 1, arquivo);
  return numero;
}
char ler_letra(FILE *arquivo)
{
  char letra;
  fread(&letra, sizeof(letra), 1, arquivo);
  return letra;
}
void escreve_numero(int numero, FILE *arquivo)
{
  fwrite(&numero, sizeof(numero), 1, arquivo);
}
void escreve_letra(char letra, FILE *arquivo)
{
  fwrite(&letra, sizeof(letra), 1, arquivo);
}
void limpa_tudo(geral *score, completo *record)
{
  int i, j, k;
  for(i = 0; i < player; i++)
  {
    for(j = 0; j < carac; j++)
      *((score+i)->nome+j) = '\0';
    for(j = 0; j < jogos; j++)
      *((score+i)->point+j) = 0;
    (score+i)->total = 0;
  }
  for(i = 0; i < jogos; i++)
  {
    for(j = 0; j < player; j++)
    {
      for(k = 0; k < carac; k++)
        *(((record+i)->w_+j)->nome+k) = '\0';
      ((record+i)->w_+j)->valor = 0;
    }
  }
}
void limpar_um(geral *dado)
{
  int i;
  for(i = 0; i < carac; i++)
    *(dado->nome+i) = '\0';
  *(dado->nome+1) = '\0';
  for(i = 0; i < jogos; i++)
    *(dado->point+i) = 0;
  dado->total = 0;
}
int importar_dados(geral *a_, completo *b_)
{
  FILE *arquivo = fopen(bin, read);
  int i, j, k;
  if(!arquivo)
    return 1;
  for(i = 0; i < player; i++)
  {
    for(j = 0; j < carac; j++)
      *((a_+i)->nome+j) = ler_letra(arquivo);
    for(j = 0; j < jogos; j++)
      *((a_+i)->point+j) = ler_numero(arquivo);
    (a_+i)->total = ler_numero(arquivo);
  }
  for(i = 0; i < jogos; i++)
    for(j = 0; j < player; j++)
    {
      for(k = 0; k < carac; k++)
        *(((b_+i)->w_+j)->nome+k) = ler_letra(arquivo);
      ((b_+i)->w_+j)->valor = ler_numero(arquivo);
    }
  return 0;
  fclose(arquivo);
}
void escreve_tudo(geral *a_, completo *b_)
{
  FILE *arquivo;
  arquivo = fopen(bin, write);
  int i, j, k;
  for(i = 0; i < player; i++)
  {
    for(j = 0; j < carac; j++)
      escreve_letra(*((a_+i)->nome+j), arquivo);
    for(j = 0; j < jogos; j++)
      escreve_numero(*((a_+i)->point+j), arquivo);
    escreve_numero((a_+i)->total, arquivo);
  }
  for(i = 0; i < jogos; i++)
    for(j = 0; j < player; j++)
    {
      for(k = 0; k < carac; k++)
        escreve_letra(*(((b_+i)->w_+j)->nome+k), arquivo);
      escreve_numero(((b_+i)->w_+j)->valor, arquivo);
    }
  fclose(arquivo);
}
void organizar_geral(geral *a_)
{
  int i, j, posicaomaior, maior;
  for(i = 0; i < player; i++)
  {
    posicaomaior = i;
    maior = (a_+i)->total;
    for(j = i+1; j< player; j++)
    {
      if((a_+j)->total > maior)
      {
        maior = (a_+j)->total;
        posicaomaior = j;
      }
    }
    if(maior != (a_+i)->total)
    {
      troca_nomes((a_+i)->nome, (a_+posicaomaior)->nome);
      troca_inteiro(&(a_+i)->total, &(a_+posicaomaior)->total);
      for(j = 0; j < jogos; j++)
        troca_inteiro((a_+i)->point+j, (a_+posicaomaior)->point+j);
    }
  }
} /* Apagar isso */

int procura_posicao(geral *a_, geral *b_)
{
  int i, j, controle;
  for(i = 0; i < player; i++)
  {
    controle = 1;
    if(b_->total == (a_+i)->total)
      if(compara_string(b_->nome, (a_+i)->nome))
      {
        for(j = 0; j < jogos && controle; j++)
        {
          if(*(b_->point+j) != *((a_+i)->point+j))
            controle = 0;
        }
        if(controle)
          return i + 1;
      }
  }
  return 0;
}
void copia_geral(geral *a_, geral *b_) /* A struct a_ recebe todos os dados de b */
{
  int i;
  for(i = 0; i < carac; i++)
    *(a_->nome+i) = *(b_->nome+i);
  for(i = 0; i < jogos; i++)
    *(a_->point+i) = *(b_->point+i);
  a_->total = b_->total;
}
void copia_individual(individual *a_, individual *b_)
{
  int i;
  for(i = 0; i < carac; i++)
    *(a_->nome+i) = *(b_->nome+i);
  a_->valor = b_->valor;
}
int organiza_posicao_geral(geral *score, geral *dado, int posicao_antiga) /* Tem como melhorar essa funcao */
{
  int posicao_nova = 0, i;
  if(!posicao_antiga && dado->total <= (score+player-1)->total) /* Se o dado for menor que o ultimo valor, irá retornar 0 */
    return 0;
  if(posicao_antiga /* Ver se isso é realmente necessario */ && dado->total == (score+posicao_antiga-1)->total) /* Nesse caso o total for equivalente(pois nunca sera menor), irá retornar a antiga posicao */
    return posicao_antiga;
  while((score+posicao_nova)->total >= dado->total) /* Aqui achará a posicao que for menor que tal valor de dado->total */
        posicao_nova++;
  if(posicao_antiga == 0)
    posicao_antiga = player-1;
  else
    posicao_antiga--;
  for(i = posicao_antiga; i>posicao_nova; i--)
    copia_geral(score+i, score+i-1);
  copia_geral(score+posicao_nova, dado);
  return posicao_nova+1;
}
int organiza_posicao_completo(completo *record, geral *dado, int posicao_antiga, int jogo)
{
  int posicao_nova = 0, i;
  jogo--;
  if(!posicao_antiga && *(dado->point+jogo) <= ((record+jogo)->w_+player-1)->valor)
    return 0; /* Se o dado for menor que o ultimo valor, irá retornar 0 */
  if(*(dado->point+jogo) == ((record+jogo)->w_+posicao_antiga-1)->valor)
    return posicao_antiga;
  while(((record+jogo)->w_+posicao_nova)->valor >= *(dado->point+jogo)) /* Aqui achará a posicao que for menor que tal valor de dado->total */
        posicao_nova++;
  if(posicao_antiga == 0)
    posicao_antiga = player-1;
  else
    posicao_antiga--;
  for(i = posicao_antiga; i>posicao_nova; i--)
    copia_individual((record+jogo)->w_+i, (record+jogo)->w_+i-1);
  for(i = 0; i < carac; i++)
  {
    *(((record+jogo)->w_+posicao_nova)->nome+i) = *(dado->nome+i);
  }
  ((record+jogo)->w_+posicao_nova)->valor = *(dado->point+jogo);
  return posicao_nova+1; 
}
void verifica_se_ja_jogou(geral *score, geral *dado, completo *record, char *nome, int *posicao)
{
  int i = 0, j=0;
  while(i < player)
  {
    if(compara_string((score+i)->nome, nome))
    {
      copia_geral(dado, score+i);
      *posicao = i+1;
      i = player;
      j = 1;
    }
    i++;
  }
  if(!j)
    for(i = 0; i < jogos; i++)
      for(j = 0; j < player; j++)
        if(compara_string(((record+i)->w_+j)->nome, nome))
        {
          *(posicao+i+1) = j+1;
          *(dado->point+i) = ((record+i)->w_+j)->valor;
          j = player;
        }
  else
    for(i = 0; i < jogos; i++)
      for(j = 0; j < player; j++)
        if(compara_string(((record+i)->w_+j)->nome, nome))
        {
          *(posicao+i+1) = j+1;
          j = player;
        }
}