// start
#include "header.h"




int main()
{

	/*
	// 구구단 2 ~ 9 단

	int n = 0;
	printf("몇 단 부터 할래? 범위 : 2 ~ 9 \n");
	scanf("%d", &n);
	
	if (n < 2 && n > 9)
	{
		printf("머함 ?");
		return 0;
	}
	else
	{
		for (int i = n; i < 10; i++)
		{
			printf("---- %d단 ---- \n", i);

			for (int j = 1; j < 10; j++)
			{
				printf("%d x %d = %d \n", i, j, i * j);
			}

			puts(" ");
		}
	}
	*/
	
	int i = 2, j = 1;
	/*
		for (; i < 10; ++i)
	{
		printf("----%d단----\n", i);

		for (; j < 10; ++j)
		{
			printf("%d x %d = %d \n", i, j, i * j);
		}

		j = 1;
		puts(" ");
	}
	*/

	while (i < 10)
	{
		printf("----%d단---- \n", i);

		while (j < 10)
		{
			printf("%d x %d = %d \n", i, j, i * j);
			j++;
		}

		i++;
		j = 1;
		puts(" ");
	}

//gg





	return 0;
}
