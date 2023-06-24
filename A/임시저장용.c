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
	int i, start = 0, next = 1, temp;
	for (i = 0; i < n; i++)
	{
		temp = start;
		start += next;
		next = temp;
		printf("%d ", start);
	}
}