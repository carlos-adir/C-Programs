int soma_PILHA_NUM(PILHA_NUM **l)
{
	PILHA_NUM *aux;
	if(at_least_PILHA_NUM(l, 2))
	{
		/* Operacao de soma */
		aux = remove_PILHA_NUM(l);
		(*l)->info = soma_DATA((*l)->info, aux->info);
		free(aux);
		return 1;
	}
/*	else if(at_least_PILHA_NUM(l, 1))
		return 0; */
	else
		return 0;
}
int sub_PILHA_NUM(PILHA_NUM **l)
{
	PILHA_NUM *aux;
	if(at_least_PILHA_NUM(l, 2))
	{
		/* Operacao de soma */
		aux = remove_PILHA_NUM(l);
		(*l)->info = sub_DATA(aux->info, (*l)->info);
		free(aux);
		return 1;
	}
/*	else if(at_least_PILHA_NUM(l, 1))
		return 0; */
	else
		return 0;
}
int mult_PILHA_NUM(PILHA_NUM **l)
{
	PILHA_NUM *aux;
	if(at_least_PILHA_NUM(l, 2))
	{
		/* Operacao de soma */
		aux = remove_PILHA_NUM(l);
		(*l)->info = mult_DATA((*l)->info, aux->info);
		free(aux);
		return 1;
	}
/*	else if(at_least_PILHA_NUM(l, 1))
		return 0; */
	else
		return 0;
}
int div_PILHA_NUM(PILHA_NUM **l)
{
	PILHA_NUM *aux;
	if(at_least_PILHA_NUM(l, 2))
	{
		/* Operacao de soma */
		aux = remove_PILHA_NUM(l);
		if(equal_DATA(aux->info, create_DATA(0)))
		{
			free(aux);
			append_PILHA_NUM(create_DATA(0), l);
			return -1;
		}
		(*l)->info = div_DATA(aux->info, (*l)->info);
		free(aux);
		return 1;
	}
/*	else if(at_least_PILHA_NUM(l, 1))
		return 0; */
	else
		return 0;
}