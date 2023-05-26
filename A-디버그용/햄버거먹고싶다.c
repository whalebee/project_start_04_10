// #include "header.h"
#include <stdio.h>


int main()
{


//		  (1,3)
//	(2,3) (2,4) (2,6)


	// n단트리 for문 2번만 사용해서

	int n = 3;
	scanf("%d", &n);

	for (int row = 1; row <= n; row++)
	{

		for (int col = 1; col < n + row; col++)
		{
			if (col > n - row)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}

		printf("\n");
	}


	return 0;
}