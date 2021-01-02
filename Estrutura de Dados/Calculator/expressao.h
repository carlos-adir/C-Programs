#include <ctype.h>

void menu_expressao()
{	
	limpa_tela();;
	printf("\n\n");
	printf("    ███████╗███╗ ███╗██████╗ ██████╗ ███████╗ ██████╗ ██████╗ █████╗ ███████╗ ██████╗ \n");
	printf("    ██╔════╝  ████╔═╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝██╔══██╗██╔════╝██╔════╝ \n");
	printf("    █████╗     ██╔╝  ██████╔╝██████╔╝█████╗   █████╗  █████╗ ██║  ██║█████╗   █████╗  \n");
	printf("    ██╔══╝    ████╗  ██╔═══╝ ██╔══██╗██╔══╝       ██╗     ██╗██║  ██║██╔══╝       ██╗ \n");
	printf("    ███████╗███╔═███╗██║     ██║  ██║███████╗██████╔╝██████╔╝ █████╔╝███████╗██████╔╝ \n");
	printf("    ╚══════╝╚══╝ ╚══╝╚═╝     ╚═╝  ╚═╝╚══════╝╚═════╝ ╚═════╝  ╚════╝ ╚══════╝╚═════╝  \n");
}

char simbolo(char c)
{
	if(c == '\0')
		return 1;
	if(c == '+')
		return 1;
	if(c == '-')
		return 1;
	if(c == '*')
		return 1;
	if(c == '/')
		return 1;
	if(c == '(')
		return 1;
	if(c == ')')
		return 1;
	return 0;
}

char prioridade(char c)
{
	if(c == '\0')
		return 0;
	if(c == '+')
		return 1;
	if(c == '-')
		return 1;
	if(c == '*')
		return 3;
	if(c == '/')
		return 3;
	return 5;
}
/*
void imprime_estado(PILHA_NUM **l, PILHA_CHAR **p)
{
	if(l == NULL)
		printf("l == NULL   \t");
	else
		printf("l == NONULL \t");
	if(p == NULL)	
		printf("p == NULL  \n");
	else
		printf("p == NONULL\n");
}
*/
int pilhas_ja_criadas(PILHA_NUM **l, PILHA_CHAR **p)
{
	if(l == NULL || p == NULL)
		return 0;
	return 1;
}

int possivel_criar_pilhas(PILHA_NUM ***l, PILHA_CHAR ***p)
{
	*l = create_PILHA_NUM();
	*p = create_PILHA_CHAR();
	if(!pilhas_ja_criadas(*l, *p)) /* Testa se foi possivel alocar as pilhas */
	{
		if(*l != NULL)
		{
			free(*l);
			/* printf("Deu ruim e liberou nnumerico!\n"); DEBUGAR */
			*l = NULL;
		}
		if(*p != NULL)
		{
			free(*p);
			/* printf("Deu ruim e liberou caracter!\n"); DEBUGAR */
			*p = NULL;
		}
		return 0;
	}
	return 1;
}



int imprime_ambas_pilhas(PILHA_NUM **l, PILHA_CHAR **p)
{
	int i, tamanho_l = 0, tamanho_p = 0;
	PILHA_NUM **l_aux = NULL;
	PILHA_CHAR **p_aux = NULL;;
	if(l == NULL)
		return 0;
	if(p == NULL)
		return 0;
	if(!possivel_criar_pilhas(&l_aux, &p_aux))
		return 0;
	/* Chegando aqui, ja se tem tudo alocado */
	/* Aqui passa todos os elementos de uma pilha para outra e conta a quantidade */
	while(trade_PILHA_NUM(l, l_aux))
	{
		tamanho_l += 1;
		if(tamanho_l == PILHA_PROF)
			break;
	}
	/* Aqui passa todos os elementos de uma pilha para outra e conta a quantidade */
	while(trade_PILHA_CHAR(p, p_aux))
	{
		tamanho_p += 1;
		if(tamanho_p == PILHA_PROF)
			break;
	}
	menu_expressao();
	printf("    PILHA_NUM\tPILHA_CHAR\n\n");
	for(i = 0; i < PILHA_PROF; i++) /* Aqui imprime a lista ja colocando os elementos de volta na pilha original */
	{
		printf("  %02d: ", PILHA_PROF-i);
		if(i > PILHA_PROF - tamanho_l - 1)
		{
			imprime_DATA((*l_aux)->info);
			trade_PILHA_NUM(l_aux, l);
		}
		else
		{
			printf("\t");
		}
		printf("\t");
		if(i > PILHA_PROF - tamanho_p - 1)
		{
			putchar((*p_aux)->c);
			trade_PILHA_CHAR(p_aux, p);
		}
		printf("\n");
	}
	free(p_aux);
	free(l_aux);
	/* printf("Liberado pilhas auxiliares numerica e char!\n"); DEBUGAR */
	return 1;
	
}

/* Mesmo algoritmo para imprimir ambas pilhas, mas com 4 pilhas */
int imprime_quatro_pilhas(PILHA_NUM **l, PILHA_CHAR **p, PILHA_NUM **le, PILHA_CHAR **pe)
{
	int i, tamanho_l = 0, tamanho_p = 0, tamanho_pe = 0, tamanho_le = 0;
	PILHA_NUM **l_aux = NULL;
	PILHA_CHAR **p_aux = NULL;
	PILHA_NUM **le_aux = NULL;
	PILHA_CHAR **pe_aux = NULL;
	if(l == NULL)
		return 0;
	if(p == NULL)
		return 0;
	if(le == NULL)
		return 0;
	if(pe == NULL)
		return 0;
	if(!possivel_criar_pilhas(&l_aux, &p_aux) || !possivel_criar_pilhas(&le_aux, &pe_aux))
	{
		if(l_aux != NULL)
			free(l_aux);
		if(p_aux != NULL)
			free(p_aux);
		if(le_aux != NULL)
			free(le_aux);
		if(pe_aux != NULL)
			free(pe_aux);
		return 0;
	}
	/* Chegando aqui, ja se tem tudo alocado */
	/* Aqui passa todos os elementos de uma pilha para outra e conta a quantidade */
	while(trade_PILHA_NUM(l, l_aux))
	{
		tamanho_l += 1;
		if(tamanho_l == PILHA_PROF)
			break;
	}
	while(trade_PILHA_CHAR(p, p_aux))
	{
		tamanho_p += 1;
		if(tamanho_p == PILHA_PROF)
			break;
	}
	while(trade_PILHA_NUM(le, le_aux))
	{
		tamanho_le += 1;
		if(tamanho_le == PILHA_PROF)
			break;
	}
	while(trade_PILHA_CHAR(pe, pe_aux))
	{
		tamanho_pe += 1;
		if(tamanho_pe == PILHA_PROF)
			break;
	}
	menu_expressao();
	printf("            ENTRADA                               RPN\n");
	printf("    PILHA_NUM      PILHA_CHAR           PILHA_NUM      PILHA_CHAR\n\n");
	for(i = 0; i < PILHA_PROF; i++) /* Aqui imprime a lista ja colocando os elementos de volta na pilha original */
	{
		printf("  %02d: ", PILHA_PROF-i);
		if(i > PILHA_PROF - tamanho_le - 1)
		{
			imprime_DATA((*le_aux)->info);
			trade_PILHA_NUM(le_aux, le);
		}
		else
		{
			printf("\t");
		}
		printf("\t");
		printf("\t");
		if(i > PILHA_PROF - tamanho_pe - 1)
		{
			putchar((*pe_aux)->c);
			trade_PILHA_CHAR(pe_aux, pe);
		}
		printf("\t");
		printf("\t");
		if(i > PILHA_PROF - tamanho_l - 1)
		{
			imprime_DATA((*l_aux)->info);
			trade_PILHA_NUM(l_aux, l);
		}
		else
		{
			printf("\t");
		}
		printf("\t");
		if(i > PILHA_PROF - tamanho_p - 1)
		{
			putchar((*p_aux)->c);
			trade_PILHA_CHAR(p_aux, p);
		}
		printf("\n");
	}
	free(p_aux);
	free(l_aux);
	free(pe_aux);
	free(le_aux);
	/* printf("Liberado pilhas auxiliares numerica e char!\n"); DEBUGAR */
	return 1;
	
}


void copia(char *para,const char *onde, int q)
{
	int i;
	for(i = 0; i < q; i++)
		*(para+i) = *(onde+i);
	*(para+i) = '\0';
}

int trata_expressao(char *str, PILHA_NUM **l, PILHA_CHAR **p)
{ /* Essa funcao simplesmente separa os simbolos dos numeros */
	int i=0, j = 0, parenteses = 0;
	char new_number[50];
	/*  printf("Na trata_expressao:\n");
	imprime_estado(l, p); DEBUGAR */ 
	if(pilhas_ja_criadas(l, p))
	{
		if(delay != 0)
		{
			imprime_ambas_pilhas(l, p);
			printf("\n\n%s\n", str+i);
			usleep(2*delay);
		}
		while(1)
		{
			if(*(str+i) == '\0')
				break;
			if(simbolo(*(str+i)))
			{
				append_PILHA_CHAR(*(str+i), p);
				if(*(str+i) == '(')
					parenteses += 1;
				else if(*(str+i) == ')')
					parenteses -= 1;
				i += 1;
			}
			else if(isdigit(*(str+i)) || *(str+i) == '.')
			{
				j = i;
				while(!simbolo(*(str+j)))
					j++;
				copia(new_number, str+i, j-i); /* Copia para new_number, o conteudo de str+i em uma quantidade de j-i chars */
				append_PILHA_CHAR('n', p);
				append_PILHA_NUM(create_DATA(atof(new_number)), l);
				i = j;
			}
			else
				return 0;
			if(delay != 0)
			{
				imprime_ambas_pilhas(l, p);
				printf("\n\n%s\n", str+i);
				usleep(delay);
			}
		}
	}
	if(parenteses)
	{
		printf("Expressão inválida! Faltam parenteses\n");
		sleep(2);
		return 0;
	}
	return 1;
}

int inverte_pilha(PILHA_NUM ***l, PILHA_CHAR ***p)
{
	PILHA_CHAR **p_aux;
	PILHA_NUM  **l_aux;
	if(p == NULL || l == NULL)
		return 0;
	if(*p == NULL || *l== NULL)
		return 0;
	else
	{
		p_aux = create_PILHA_CHAR();
		if(p_aux == NULL)
			return 0;
		l_aux = create_PILHA_NUM();
		if(l_aux == NULL)
		{
			free(p_aux);
			return 0;
		}
		while(trade_PILHA_NUM(*l, l_aux));
		while(trade_PILHA_CHAR(*p, p_aux));
		free(*l);
		free(*p);
		*p = p_aux;
		*l = l_aux;
	}
	return 1;
}

int resolve(double *value, PILHA_NUM **le, PILHA_CHAR **pe)
{
	PILHA_NUM **l;
	PILHA_CHAR **p;
	PILHA_CHAR *aux, *aux2;
	char opa = '\0', operacao = '\0';
	char pos_fixo[500];
	pos_fixo[0] = '\0';
	if(!possivel_criar_pilhas(&l, &p))
		return 0;
	while(1)
	{
		if(opa == '\0') 
		{
			aux = remove_PILHA_CHAR(pe);
			if(aux == NULL)
			{
				opa = ')'; /* Indica que e para sair pois nao há mais operacao */
			}
			else if(aux->c == 'n')
			{
				trade_PILHA_NUM(le, l);
				sprintf(pos_fixo, "%s %lf", pos_fixo, ((*l)->info).d);
				free(aux);
				operacao = ' ';
			}
			else if(aux->c == '(') /* Para adicionar isso na segunda pilha. Podemos utilizar o append, mas este e mais eficiente */
			{
				aux->prox = *p;
				*p = aux;
				operacao = ' ';
			}
			else if(aux->c == ')')
			{
				opa = ')';
				free(aux);
				operacao = ' ';
			}
			else
			{
				if(prioridade(aux->c) < prioridade(get_last_PILHA_CHAR(p)) && get_last_PILHA_CHAR(p) != '(')
				{
					aux2 = remove_PILHA_CHAR(p);
					operacao = aux2->c;
					free(aux2);
				}
				else
				{
					operacao = ' ';
				}
				aux->prox = *p;
				*p = aux;
			}
			if(delay != 0)
			{
				imprime_quatro_pilhas(l, p, le, pe);
				usleep(delay);
			}
		}
		else /* ou opa == ')' */ /* Significa que achou um fecha parenteses e que tem operacoes a fazer */
		{
			aux = remove_PILHA_CHAR(p);
			if(aux == NULL)
			{
				/* Impossivel de acontecer isso... Mas por precaucao...  E possivel de acontecer caso seja uma expressão invalida */
				if(at_least_PILHA_NUM(l, 2) || *pe != NULL || *le != NULL)
				{
					libera_PILHA_NUM(l);
					libera_PILHA_CHAR(p);
					return 0;
				}
				/* Entra aqui se estiver no final */
				break;
			}
			/* aux->c nunca sera ')' */
			if(aux->c == '(') /* Para finalizar a procura*/
			{
				opa = '\0';
				operacao = ' ';
			}
			else
			{
				operacao = aux->c;
			}
			free(aux);

		}
		if(operacao == ' '){}
		else{
			if(operacao == '+')
			{
				operacao = soma_PILHA_NUM(l);
				sprintf(pos_fixo, "%s %c", pos_fixo, '+');	
			}
			else if(operacao == '-')
			{
				operacao = sub_PILHA_NUM(l);
				sprintf(pos_fixo, "%s %c", pos_fixo, '-');
			}
			else if(operacao == '*')
			{
				operacao = mult_PILHA_NUM(l);
				sprintf(pos_fixo, "%s %c", pos_fixo, '*');
			}
			else if(operacao == '/')
			{
				operacao = div_PILHA_NUM(l);
				sprintf(pos_fixo, "%s %c", pos_fixo, '/');
			}
			if(!operacao)
			{
				libera_PILHA_NUM(l);
				libera_PILHA_CHAR(p);
				return 0;
			}
			if(delay != 0)
			{
				imprime_quatro_pilhas(l, p, le, pe);
				usleep(delay);
			}
		}
		
	}
	limpa_tela();;
	imprime_quatro_pilhas(l, p, le, pe);
	sprintf(pos_fixo, "%s %c", pos_fixo, '\0');
	*value = ((*l)->info).d;
	printf("Notacao pos-fixa:\n");
	printf("%s\n", pos_fixo);
	printf("\n");
	printf("Valor final:\n");
	printf("%lf\n", *value);
	libera_PILHA_NUM(l);
	libera_PILHA_CHAR(p);
	return 1;	
}