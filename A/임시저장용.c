// start
#include "header.h"


void print_fn(int* arrange, int size);
int sort(int* arrange, int size);


int main()
{

	/*
	// ������ 2 ~ 9 ��

	int n = 0;
	printf("�� �� ���� �ҷ�? ���� : 2 ~ 9 \n");
	scanf("%d", &n);

	if (n < 2 && n > 9)
	{
		printf("���� ?");
		return 0;
	}
	else
	{
		for (int i = n; i < 10; i++)
		{
			printf("---- %d�� ---- \n", i);

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
		printf("----%d��----\n", i);

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
		printf("----%d��---- \n", i);

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
	// ���� 100�̾ ��� 101�̻� �׸�
	int n = 0, sum = 0;
	for (scanf("%d", &n); n >= 0; scanf("%d", &n))
	{
		sum = sum + n;
		if (sum > 100)
		{
			break;
		}
		printf("�Էµ� �� : %d \n", n);
		printf("���ݱ����� ���� : %d \n", sum);
	}
	printf("������ %d �Դϴ� ! 101 �̻��̹Ƿ� �����մϴ� ! \n", sum);	*/


	// �迭
	int arr[] = { 3, 29, 38, 12, 57, 74, 40, 85 ,61 };

	// ���� �� : 3 12 29 38 40 57 61 74 85

	int size = sizeof(arr) / sizeof(int);
	// printf("%zd", size);



	// ���� �� ��� Ȯ��
	print_fn(arr, size);

	// ����
	sort(arr, size);

	// ��� Ȯ��
	print_fn(arr, size);

	return 0;
}

void print_fn(int* arrange, int size)
{
	// Ȯ��
	printf("arr[%d] = {", size);
	for (int j = 0; j < size; j++)
	{
		printf("%d", arrange[j]);
		if (j < size - 1) printf(",");
	}
	printf("}\n");
	// ��ȯ �ʿ� ���� !
}

int sort(int* arrange, int size)
{
	int n = 0, first = 0;

	for (int n = 0; n < size; n++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (arrange[i] > arrange[i + 1])
			{
				first = arrange[i];
				arrange[i] = arrange[i + 1];
				arrange[i + 1] = first;
			}
		}
	}
}


