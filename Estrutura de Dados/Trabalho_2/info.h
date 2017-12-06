// Carlos Adir Ely Murussi Leite
// 150121059

#ifndef INFO
#define INFO

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define SUCESS 1
#define FAIL 0
#define not !
#define and &&
#define or ||

typedef unsigned char bool;


typedef struct
{
	double med, dp;
}estatistica;
estatistica new_estatistica(double m, double d);

typedef struct
{
	int t; // turma
	int a; // ano
	int p; // periodo
	int q; // quantidade
	estatistica postura;
	estatistica atuacao;
	estatistica autoava;
}info;
info *new_info(int tu, int ano, int pe, int qu, estatistica pos, estatistica atu, estatistica autoa);
void free_info(info *i);

bool get_line(FILE *arq, char *name, int *ID, info **novo);

#endif