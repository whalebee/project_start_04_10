#include "header.h"



int add(int a, int b)
{
	return a + b;
}



void sub(int a, int b)
{
	printf("%d ", a - b);
}


int MAX(int a, int b, int c)
{
	printf("%d ", ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c)));
}