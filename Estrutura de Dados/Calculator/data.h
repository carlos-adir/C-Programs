#include <stdio.h>
#include <stdlib.h>

struct Data
{
	double d;
};
typedef struct Data DATA;

DATA create_DATA(double t)
{
	DATA info;
	info.d = t;
	return info;
}
void imprime_DATA(DATA t)
{
	printf("%lf", t.d);
}
char equal_DATA(DATA t1, DATA t2)
{
	if(t1.d == t2.d)
		return 1;
	return 0;
}
DATA soma_DATA(DATA t1, DATA t2)
{
	DATA re;
	re.d = t1.d + t2.d;
	return re;
}
DATA sub_DATA(DATA t1, DATA t2)
{
	DATA re;
	re.d = t1.d - t2.d;
	return re;
}
DATA mult_DATA(DATA t1, DATA t2)
{
	DATA re;
	re.d = t1.d * t2.d;
	return re;
}
DATA div_DATA(DATA t1, DATA t2)
{
	DATA re;
	re.d = t1.d / t2.d;
	return re;
}
