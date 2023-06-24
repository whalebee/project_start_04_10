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
	int start = 0, next = 1, before, i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", start);
		before  = start;
		start += next;
		next = before;
	}
}