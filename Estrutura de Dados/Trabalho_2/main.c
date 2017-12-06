// Carlos Adir Ely Murussi Leite
// 150121059

#include "main.h"



void menu()
{
	av();
	printf("1) Informação de cada raiz\n");
	printf("2) Media das chaves das sub-arvores\n");
	printf("3) Mostrar todas as avaliacoes de um professor\n");
	printf("4) Nomes docentes esquerda\n");
	printf("5) Nomes docentes direita\n");
	//printf("6) Quantidade de vezes que cada docente aparece na arvore esquerda\n");
	//printf("7) Quantidade de vezes que cada docente aparece na arvore direita\n");
	printf("\n\n");
	printf("8) Encerrar o programa\n");
}


void main_loop(l_prof **lista, raiz **postura, raiz **atuacao, raiz **autoava)
{
	KEY k;
	while(1)
	{
		menu();
		do
		{
			k = get_key();
		}while(!(key_is_equal(k, "1") || key_is_equal(k, "2") || key_is_equal(k, "3") ||
				 key_is_equal(k, "4") || key_is_equal(k, "5") || key_is_equal(k, "6") ||
				 key_is_equal(k, "7") || key_is_equal(k, "8") || key_is_equal(k, "ESC") ));
		if(key_is_equal(k, "ESC"))
			break;
		else if(key_is_equal(k, "1"))
			opcao1(*postura, *atuacao, *autoava);
		else if(key_is_equal(k, "2"))
			opcao2(*postura, *atuacao, *autoava);
		else if(key_is_equal(k, "3"))
			opcao3(lista);
		else if(key_is_equal(k, "4"))
			opcao4(*postura, *atuacao, *autoava);
		else if(key_is_equal(k, "5"))
			opcao5(*postura, *atuacao, *autoava);
		else if(key_is_equal(k, "8"))
			break;
	}
}





int main(int argc, char *argv[])
{
	char *data;
	char orga[] = "organized.bin";
	bool rate;
	l_prof **lista;
	raiz **postura, **atuacao, **autoava;

	data = argv[1];

	rate = get_data(data, &lista);
	if(rate == FAIL)
	{
		printf("Nao foi possivel ler os dados do arquivo .csv\n");
		printf("Verifique se foi passado o arquivo correto\n");
		return 1;
	}

	rate = get_3organized(orga, lista, &postura, &atuacao, &autoava);
	if(rate == FAIL)
	{
		free_lista(lista);
		lista = NULL;
		printf("Nao foi possivel criar as tres arvores.\n");
		return 2;	
	}
	main_loop(lista, postura, atuacao, autoava);
	free_arvore(*postura);
	free_arvore(*atuacao);
	free_arvore(*autoava);
	free(postura);
	free(atuacao);
	free(autoava);
	free_lista(lista);
	lista = NULL;
	return 0;
}