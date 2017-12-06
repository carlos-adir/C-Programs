// Carlos Adir Ely Murussi Leite
// 150121059

#include "info.h"



estatistica new_estatistica(double m, double d)
{
	estatistica novo;
	novo.med = m;
	novo.dp = d;
	return novo;
}



info *new_info(int tu, int ano, int pe, int qu, estatistica pos, estatistica atu, estatistica autoa)
{
	info *novo;
	novo = (info *) malloc(sizeof(info));
	if(novo == NULL) // Deu errado a alocacao
		return NULL;
	//printf("Foi feito um malloc para nova_info: %p\n", novo);
	novo->t = tu;
	novo->a = ano;
	novo->p = pe;
	novo->q = qu;
	novo->postura = pos;
	novo->atuacao = atu;
	novo->autoava = autoa;
	return novo;
}
void free_info(info *i)
{
	free(i);
	//printf("Foi dado um free na info: %p\n", i);
}


bool get_line(FILE *arq, char *name, int *ID, info **novo) // Return SUCESS or FAIL
{
	int turma, ano, periodo, quantidade; // Quantidade de alunos(discentes)
	estatistica postura, atuacao, autoavaliacao;
	int sucesso;
	double pm, pd; // Postura
	double am, ad; // Atuacao
	double um, ud; // Autoavaliacao
	info *nova_info;

	if(arq == NULL)
		return FAIL;
	if(feof(arq))
		return FAIL;
	// Leia as linhas
	sucesso = fscanf(arq, "%d,%[^,],", ID, name);
	if(sucesso != 2)
		return FAIL;
	sucesso = fscanf(arq, "%d,%d,%d,%d,", &turma, &ano, &periodo, &quantidade);
	if(sucesso != 4)
		return FAIL;
	sucesso = fscanf(arq, "%lf,%lf,%lf,%lf,%lf,%lf\n", &pm, &pd, &am, &ad, &um, &ud);
	if(sucesso != 6)
		return FAIL;
	// Transforma para estatistica
	postura = new_estatistica(pm, pd);
	atuacao = new_estatistica(am, ad);
	autoavaliacao = new_estatistica(um, ud);
	
	nova_info = new_info(turma, ano, periodo, quantidade, postura, atuacao, autoavaliacao);

	*novo = nova_info;
	if(nova_info == NULL)
	{
		return FAIL;
	}
	// Agora mudamos o novo
	return SUCESS;
}