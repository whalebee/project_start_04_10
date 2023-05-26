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
	
	// int i = 2, j = 1;
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

	/*
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
	*/
	
	/*
	// 총합 100이어도 출력 101이상 그만
	int n = 0, sum = 0;
	for (scanf("%d", &n); n >= 0; scanf("%d", &n))
	{
		sum = sum + n;
		if (sum > 100)
		{
			break;
		}
		printf("입력된 값 : %d \n", n);
		printf("지금까지의 총합 : %d \n", sum);
	}
	printf("총합은 %d 입니다 ! 101 이상이므로 종료합니다 ! \n", sum);	*/

	

	

	// 배열
	int arr[] = { 3, 29, 38, 12, 57, 74, 40, 85 ,61 };
	
	// 정렬 후 : 3 12 29 38 40 57 61 74 85

	int size = sizeof(arr) / sizeof(int);
	// printf("%zd", size);

	int n = 0, first = 0;


	for (int n = 0; n < size; n++)
	{
		for (int i = 0; i < size -1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				first = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = first;
			}
		}
	}
	

	// 확인
	printf("arr[] = {");
	for (int j = 0; j < size; j++)
	{
		if (j == size - 1)
		{
			printf("%d", arr[j]);
			break;
		}
		printf("%d, ", arr[j]);
		
	}
	printf("}");
	



	return 0;
}
