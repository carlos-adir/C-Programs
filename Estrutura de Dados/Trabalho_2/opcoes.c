// Carlos Adir Ely Murussi Leite
// 150121059

#include "opcoes.h"

void free_list(cont_prof **lista)
{
	cont_prof *aux;
	aux = *lista;
	while(aux != NULL)
	{
		aux = aux->next;
		free(*lista);
		*lista = aux;
	}
}

void av()
{
	system("clear");
	printf("\n\n\n\n");
	printf("\t\t\t █████╗ ██╗  ██╗ █████╗ ██╗    ████╗ █████╗ ███████╗ █████╗  █████╗  \n");
	printf("\t\t\t██╔══██╗██║  ██║██╔══██╗██║    ╚██╔╝██╔══██╗██╔════╝██╔══██╗██╔══██╗ \n");
	printf("\t\t\t███████║ ██║██╔╝███████║██║     ██║ ███████║██║     ███████║██║  ██║ \n");
	printf("\t\t\t██╔══██║ ██║██║ ██╔══██║██║     ██║ ██╔══██║██║     ██╔══██║██║  ██║ \n");
	printf("\t\t\t██║  ██║ ╚███╔╝ ██║  ██║██████╗████╗██║  ██║███████╗██║  ██║ █████╔╝ \n");
	printf("\t\t\t╚═╝  ╚═╝  ╚══╝  ╚═╝  ╚═╝╚═════╝╚═══╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚════╝  \n");
	printf("\t\t\t  ██████╗  █████╗ ███████╗███████╗███╗ ██╗████████╗███████╗ ██████╗\n");
	printf("\t\t\t  ██╔══██╗██╔══██╗██╔════╝██╔════╝████╗██║╚══██╔══╝██╔════╝██╔════╝\n");
	printf("\t\t\t  ██║  ██║██║  ██║██║     █████╗  ███████║   ██║   █████╗   █████╗ \n");
	printf("\t\t\t  ██║  ██║██║  ██║██║     ██╔══╝  ██╔████║   ██║   ██╔══╝       ██╗\n");
	printf("\t\t\t  ██████╔╝ █████╔╝███████╗███████╗██║╚███║   ██║   ███████╗██████╔╝\n");
	printf("\t\t\t  ╚═════╝  ╚════╝ ╚══════╝╚══════╝╚═╝ ╚══╝   ╚═╝   ╚══════╝╚═════╝ \n");
	printf("\n\n\n\n");
	
}

void opcao1(raiz *postura, raiz *atuacao, raiz *autoava)
{
	// printf("1) Informação de cada raiz\n");
	int high[3], nos[3], left[3], right[3];
	int i;
	KEY k;
	raiz *n;
	info *w;
	for(i = 0; i < 3; i++)
	{
		if(i == 0)
			n = postura;
		else if(i == 1)
			n = atuacao;
		else if(i == 2)
			n = autoava;
		high[i] = altura(n);
		left[i] = numero_nos(n->menor);
		right[i] = numero_nos(n->maior);
		nos[i] = left[i]+right[i]+1;
	}
	i = 0;
	while(1)
	{
		if(i == 0)
			n = postura;
		else if(i == 1)
			n = atuacao;
		else if(i == 2)
			n = autoava;
		w = *(n->prof->list+n->pos);
		av();
		if(i == 0)
			printf("  Na arvore de chave    POSTURA    media:\n\n");
		else if(i == 1)
			printf("  Na arvore de chave    ATUACAO    media:\n\n");
		else if(i == 2)
			printf("  Na arvore de chave AUTOAVALIACAO media:\n\n");
		printf("          Numero total de nos: %d\n", nos[i]);
		printf("       Numero de nos esquerda: %d\n", left[i]);
		printf("        Numero de nos direita: %d\n", right[i]);
		printf("             Altura da arvore: %d\n", high[i]);
		printf("\n");
		printf("  Informacoes do no:\n");
		printf("                           ID: %d\n", n->prof->ID);
		printf("                    Professor: %s\n", n->prof->name);
		printf("                        Turma: %d\n", w->t);
		printf("                          Ano: %d\n", w->a);
		printf("                      Periodo: %d\n", w->p);
		printf("                       Alunos: %d\n", w->q);
		//printf("                      Posicao: %d\n", n->global);
		printf("\n");
		printf("  Estatisticas: | Media | Desvio |\n");
		printf("       Postura: |%s%.2lf |  %.2lf  |\n", w->postura.med >= 10 ? " " : "  ", w->postura.med, w->postura.dp);
		printf("       Atuacao: |%s%.2lf |  %.2lf  |\n", w->atuacao.med >= 10 ? " " : "  ", w->atuacao.med, w->atuacao.dp);
		printf(" Autoavaliacao: |%s%.2lf |  %.2lf  |\n", w->autoava.med >= 10 ? " " : "  ", w->autoava.med, w->autoava.dp);
		printf("\n\n\n");

		printf("Aperte as setas, ou ENTER para sair...");
		do
		{
			k = get_key();
		}while(!( key_is_equal(k, "ENTER") || key_is_equal(k, "ESC")  || key_is_equal(k, "LEFT_KEY") || key_is_equal(k, "RIGHT_KEY") ));
		if(key_is_equal(k, "ENTER"))
			break;
		else if(key_is_equal(k, "ESC"))
			break;
		else if(key_is_equal(k, "LEFT_KEY"))
			i = i == 0 ? 0 : i-1;
		else if(key_is_equal(k, "RIGHT_KEY"))
			i = i == 2 ? 2 : i+1;
	}

}

void opcao2(raiz *postura, raiz *atuacao, raiz *autoava)
{
	//printf("2) Media das chaves das sub-arvores\n");
	double v_l[3], v_r[3];
	int q_l[3], q_r[3];
	int i, tipo;
	KEY k;
	raiz *n;
	for(i = 0; i < 3; i++)
	{
		if(i == 0)
			n = postura;
		else if(i == 1)
			n = atuacao;
		else if(i == 2)
			n = autoava;
		q_l[i] = numero_nos(n->menor);
		q_r[i] = numero_nos(n->maior);
		v_l[i] = get_sum(n->menor, i);
		v_r[i] = get_sum(n->maior, i);
	}
	av();
	printf("  Para    POSTURA    as medias das arvores são:\n\n");
	printf("       esquerda: %.4lf        direita: %.4lf\n", v_l[0]/q_l[0], v_r[0]/q_r[0]);
	printf("\n\n");
	printf("  Para    ATUACAO    as medias das arvore são:\n\n");
	printf("       esquerda: %.4lf        direita: %.4lf\n", v_l[1]/q_l[1], v_r[1]/q_r[1]);
	printf("\n\n");
	printf("  Para AUTOAVALIACAO as medias das arvores são:\n\n");
	printf("       esquerda: %.4lf        direita: %.4lf\n", v_l[2]/q_l[2], v_r[2]/q_r[2]);
	printf("\n\n");
	do
	{
		k = get_key();
	}while(!( key_is_equal(k, "ENTER") || key_is_equal(k, "ESC")));
}

void imprime_professor(professor *p, int begin)
{
	int i, max;
	info *aux;
	max = p->q - begin < 30 ? 30 : p->q-begin;
	max = max > p->q ? p->q : max;
	begin = max-30 < 0 ? 0 : max-30;

	system("clear");
	printf("\n\n");
	printf("     ID: %04d\n", p->ID);
	printf("   Nome: %s\n", p->name);
	printf("   Info:\n");
	printf("\t   ___________________________________________________________________________________________________________\n");
	printf("\t   |          |      |         |        | Postura Profissional | Atuacao Profissional |  Autoavaliacao Aluno |\n");
	printf("\t   |   Turma  |  Ano | Periodo | Alunos |   media   |  desvio  |   media   |  desvio  |   media   |  desvio  |\n");
	printf("\t   -----------------------------------------------------------------------------------------------------------\n");
	for(i = begin; i < max; i++)
	{
		aux = *(p->list+i);
		printf("  %3d/%3d  | %08d | %04d |    %01d    |   %02d   |", i+1, p->q, aux->t, aux->a, aux->p, aux->q);
		printf("%s  %.2lf   |   %.2lf   |", aux->postura.med >= 10 ? " " : "  ", aux->postura.med, aux->postura.dp);
		printf("%s  %.2lf   |   %.2lf   |", aux->atuacao.med >= 10 ? " " : "  ", aux->atuacao.med, aux->atuacao.dp);
		printf("%s  %.2lf   |   %.2lf   |", aux->autoava.med >= 10 ? " " : "  ", aux->autoava.med, aux->autoava.dp);
		printf("\n");
	}
	printf("\t   -----------------------------------------------------------------------------------------------------------\n");
	
}

void opcao3(l_prof **lista)
{
	professor *p;
	l_prof *aux;
	KEY k;
	int begin = 0;
	int i = 0, contador = 0;
	int last_begin = 1, last_contador = 1;
	aux = *lista;
	p = &(aux->prof);
	while(1)
	{
		if(last_begin != begin || last_contador != contador)
		{
			imprime_professor(p, begin);
		}
		last_begin = begin;
		last_contador = contador;
		do
		{
			k = get_key();
			if(key_is_equal(k, "ESC"))
				return;
		}while(! ( key_is_equal(k, "LEFT_KEY") || key_is_equal(k, "UP_KEY") || key_is_equal(k, "RIGHT_KEY") || key_is_equal(k, "DOWN_KEY")));
		last_begin = begin;
		if(key_is_equal(k, "UP_KEY"))
		{
			begin += 1;
			if(begin > p->q-30)
				begin -= 1;
		}
		else if(key_is_equal(k, "DOWN_KEY"))
		{
			begin -= 1;
		}
		else
		{
			
			if(key_is_equal(k, "RIGHT_KEY"))
			{
				contador += 1;
				if(aux->next != NULL)
				{
					aux = aux->next;
					p = &(aux->prof);
				}
				else
					contador -= 1;
			}
			else if(key_is_equal(k, "LEFT_KEY"))
			{
				contador -= 1;
				if(contador < 0)
					contador = 0;
				else
				{
					i = 0;
					aux = *lista;
					while(i < contador && aux->next != NULL)
					{
						i++;
						aux = aux->next;
					}
					p = &(aux->prof);
				}
			}
			
		}
		if(begin < 0)
			begin = 0;

	}
	return;
	
}

bool adiciona_cont(professor *prof, cont_prof **lista)
{
	cont_prof *aux;
	bool achou = false;
	aux = *lista;
	while(aux != NULL && achou == false)
	{
		if(prof->ID == aux->prof->ID)
		{
			achou = true;
			aux->vezes += 1;
		}
		aux = aux->next;
	}
	if(achou == false)
	{
		aux = (cont_prof *)malloc(sizeof(cont_prof));
		if(aux == NULL)
			return FAIL;
		aux->next = *lista;
		aux->prof = prof;
		aux->vezes = 1;
		*lista = aux;
	}
	return SUCESS;
}

bool nomes_docentes(raiz *n, cont_prof **lista)
{
	bool rate;
	rate = adiciona_cont(n->prof, lista);
	if(rate == FAIL)
		return FAIL;
	if(n->menor != NULL)
	{
		rate = nomes_docentes(n->menor, lista);
		if(rate == FAIL)
			return FAIL;
	}
	if(n->maior != NULL)
	{
		rate = nomes_docentes(n->maior, lista);
		if(rate == FAIL)
			return FAIL;
	}
	return SUCESS;
}

void opcao4(raiz *postura, raiz *atuacao, raiz *autoava)
{
	//printf("4) Nomes docentes esquerda\n");
	cont_prof **lista, *aux;
	bool rate;
	KEY k;
	int i=0;
	lista = (cont_prof **) malloc(3*sizeof(cont_prof *));
	if(lista == NULL)
	{
		av();
		printf("Nao foi possivel alocar a memoria necessaria para fazer essa operacao.\n");
		get_key();
		return;
	}
	*lista = NULL;
	*(lista+1) = NULL;
	*(lista+2) = NULL;
	rate = nomes_docentes(postura->menor, lista);
	if(rate == FAIL)
	{
		av();
		printf("Nao foi possivel alocar a memoria necessaria para fazer essa operacao.\n");
		get_key();
		free(lista);
		return;
	}
	rate = nomes_docentes(atuacao->menor, lista+1);
	if(rate == FAIL)
	{
		av();
		printf("Nao foi possivel alocar a memoria necessaria para fazer essa operacao.\n");
		get_key();
		free_list(lista);
		free(lista);
		return;
	}
	rate = nomes_docentes(autoava->menor, lista+2);
	if(rate == FAIL)
	{
		av();
		printf("Nao foi possivel alocar a memoria necessaria para fazer essa operacao.\n");
		get_key();
		free_list(lista);
		free_list(lista+1);
		free(lista);
		return;
	}
	while(1)
	{
		av();
		printf("    Professor na sub-arvore %s esquerda:\n\n", i == 0 ? "   POSTURA   " : (i == 1 ? "   ATUACAO   " : "AUTOAVALIACAO"));
		printf("  | Quantidade | Nome\n");
		printf("  |            |     \n");
		aux = *(lista+i);
		while(aux != NULL)
		{
			printf("  |     %02d     | %s \n", aux->vezes, aux->prof->name);
			aux = aux->next;
		}
		do
		{
			k = get_key();
		}while(!(key_is_equal(k, "LEFT_KEY") || key_is_equal(k, "RIGHT_KEY") || key_is_equal(k, "ENTER") || key_is_equal(k, "ESC")));
		if(key_is_equal(k, "ESC"))
			break;
		else if(key_is_equal(k, "ENTER"))
			break;
		else if(key_is_equal(k, "LEFT_KEY"))
			i = i == 0 ? 0 : i-1;
		else if(key_is_equal(k, "RIGHT_KEY"))
			i = i == 2 ? 2 : i+1;
	}
	free_list(lista);
	free_list(lista+1);
	free_list(lista+2);
	free(lista);
}

void opcao5(raiz *postura, raiz *atuacao, raiz *autoava)
{
	//printf("4) Nomes docentes esquerda\n");
	cont_prof **lista, *aux;
	bool rate;
	KEY k;
	int i=0;
	lista = (cont_prof **) malloc(3*sizeof(cont_prof *));
	if(lista == NULL)
	{
		av();
		printf("Nao foi possivel alocar a memoria necessaria para fazer essa operacao.\n");
		get_key();
		return;
	}
	*lista = NULL;
	*(lista+1) = NULL;
	*(lista+2) = NULL;
	rate = nomes_docentes(postura->maior, lista);
	if(rate == FAIL)
	{
		av();
		printf("Nao foi possivel alocar a memoria necessaria para fazer essa operacao.\n");
		get_key();
		free(lista);
		return;
	}
	rate = nomes_docentes(atuacao->maior, lista+1);
	if(rate == FAIL)
	{
		av();
		printf("Nao foi possivel alocar a memoria necessaria para fazer essa operacao.\n");
		get_key();
		free_list(lista);
		free(lista);
		return;
	}
	rate = nomes_docentes(autoava->maior, lista+2);
	if(rate == FAIL)
	{
		av();
		printf("Nao foi possivel alocar a memoria necessaria para fazer essa operacao.\n");
		get_key();
		free_list(lista);
		free_list(lista+1);
		free(lista);
		return;
	}
	while(1)
	{
		av();
		printf("    Professor na sub-arvore direita de %s:\n\n", i == 0 ? "   POSTURA   " : (i == 1 ? "   ATUACAO   " : "AUTOAVALIACAO"));
		printf("  | Quantidade | Nome\n");
		printf("  |            |     \n");
		aux = *(lista+i);
		while(aux != NULL)
		{
			printf("  |     %02d     | %s \n", aux->vezes, aux->prof->name);
			aux = aux->next;
		}
		do
		{
			k = get_key();
		}while(!(key_is_equal(k, "LEFT_KEY") || key_is_equal(k, "RIGHT_KEY") || key_is_equal(k, "ENTER") || key_is_equal(k, "ESC")));
		if(key_is_equal(k, "ESC"))
			break;
		else if(key_is_equal(k, "ENTER"))
			break;
		else if(key_is_equal(k, "LEFT_KEY"))
			i = i == 0 ? 0 : i-1;
		else if(key_is_equal(k, "RIGHT_KEY"))
			i = i == 2 ? 2 : i+1;
	}
	free_list(lista);
	free_list(lista+1);
	free_list(lista+2);
	free(lista);
}
