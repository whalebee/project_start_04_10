#include "header.h"


int main()
{

	// n단트리 for문 2번만 사용해서

	int n = 3;

	for (int row = 1; row < n; row++)
	{

		for (int col = 1; col < n + row; col++)
		{
			if (col < n - row)
			{
				printf("* ");
			}
			else
			{
				printf("g");
			}
		}
	}


	return 0;
}