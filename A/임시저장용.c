// start
// #include "header.h"
#include <stdio.h>

void fibo(int n);

int main()
{
	int n;

	printf("input: ");
	scanf_s("%d", &n);

	fibo(n);

	return 0;
}

void fibo(int n)
{
	// º¯¼ö 4°³
	int v1 = 0, v2 = 1, temp = 0, i;
	//printf("%d %d ", v1, v2);
	//for (i = 2; i < n; i++)
	//{
	//	temp = v1 + v2;
	//	v1 = v2;
	//	v2 = temp;
	//	printf("%d ", temp);
	//}
	for (i = 0; i < n; i++)
	{
		printf("%d ", v1);
		temp = v1;
		v1 += v2;
		v2 = temp;
	}
}