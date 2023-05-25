#include <stdio.h>

// int returnfalse(int); �Ķ������ �ڷ����� ������Ѵٴ� �� !

int main()
{
#pragma region while

	int num = 5;

	/*
	while (num < 5)
	{
		printf("%d \n", ++num);
	}
	*/

	// do while ����
	do
	{
		printf("%d \n", ++num);
	} while (num < 5);

	printf("�ݺ�����");

	/* �̷������ε� ���� ( ������ �幰�� )
	int i = 1;

	for (��� �� ���� ������; i <= 5; ++i)
	{
		printf("%d \n", i);
	}
	*/

	/* �̷������ε� ���� 2 ( ������ ������ �幰�� ���� ���� )
	int num = 0;
	for ( ; ; )
	{
		printf("%d \n", ++num);
		if (num == 100) break;
	}
	*/

	// 1���� 10������ ���� ��� -> 1���� -> 1�����̶�� �� for���� ������ ����϶�°Ű�
	// i�� �ǵ帱 �ʿ䰡 ������ ������ 10�� �������ϴϱ�
	// �ٵ� �� ���ڵ��� ���� ���� ������ ���� ����������
	int sum = 0;

	for (int i = 1; i <= 10; i++)
	{
		sum += i;
	}
	printf("for���� �հ�� : %d \n", sum);

#pragma endregion


#pragma region while�� ����ؼ� ��� ���ϱ�

	int num = 1;
	int sum_w = 0;
	while (num <= 10)
	{
		sum_w += num;
		num++;
		// 1�� �־�����ϴµ� 2���� �־���� ������ ��� 54�� ���Ծ���
		// �ذ����� sum_w += num; �� �ڸ���ġ���� !
	}
	printf("while���� �հ�� : %d \n", sum_w);

#pragma endregion


#pragma region �ݺ����� ������ ���������� �غ���, �Է��ؼ� �ݺ�������

	// ���������� ���ǵ�
	for (int i = 0, j = 1; i < 10 && j < 10; i++, j++)
	{
		printf("i�� %d , j�� %d \n", i, j);
	}

	int num = 0;
	for (printf("�����Է�\n"); num != 9; scanf("%d", &num))
	{
		printf("%d \n", num);
	}

#pragma endregion


#pragma region ���ǽĿ� �Լ�����(�ؿ��Լ�)

	// ���ǽĿ� �Լ��� �����ϱ���
	for (int i = 1; returnfalse(i); i++)
	{
		printf("%d \n", i);
	}


#pragma endregion


#pragma region �ݺ������� ������
	// for������ 2~9��
	// result���� ���������� �׳� printf���� i * j �� �� ���� �����
	for (int i = 2; i < 10; i++)
	{
		printf("for��: %d�� \n", i);
		for (int j = 1; j < 10; j++)
		{
			printf("%d x %d = %d \n", i, j, i * j);
		}
		printf("\n");
	}


	// while������ 2~9��
	int i = 2;
	int j = 1;
	while (i < 10)
	{
		j = 1;
		printf("while��: %d�� \n", i);
		while (j < 10)
		{
			printf("%d x %d = %d \n", i, j, i * j);
			j++;
		}
		i++;
		printf("\n");
	}


#pragma endregion


#pragma region �ݺ������� ���� �߰�
	for (char ch = 'A'; ch <= 'Z'; ch++)
	{
		printf("%c \n", ch);
		if (ch == 'E')
		{
			break;
		}
	}

#pragma endregion


#pragma region �ݺ������� �������� �� return
	// 2x4������ �ϰ� �ƿ� ��������
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (i * j == 10) return;
			printf("%d x %d = %d \n", i, j, i * j);
		}
		printf("----------\n");
	}


#pragma endregion


#pragma region 2-2��
// ����Ʈ ũ�Ⱑ �� �¾Ƽ� ������ ���ٰ� ��������..


#pragma endregion

#pragma region 3�� 
	/*
	#include <stdio.h>


	int fn_three(long);

	int main()
	{
		printf("%d", fn_three(6));

		return 0;
	}

	int fn_three(int a)
	{
		long result = a *= a;
		return result;
	}
	*/
	
	



#pragma endregion

#pragma region 4��
	/*
	������� �� ����ϴ°���
	������� �ؼ��϶�°��� ���� �� �� ����ϴ�
	
	�ؼ�
	1 = �ȳ�!
	k=1
	k�� k�� ������ �� ( k�� ������) 26���� ���� ����
	���� ��ü���� k�� 1�̴�

	�ݺ��� ������ k�� 2�� �����Ѵ�
	������ ��
	���� k�� 3 (�̷������� �˷��ش�)
	
	5�� ������ 25�̶�
	���� ��ü���� k�� 5 ��� ������ ������

	2�� ������ k=7����
	������ü��� printf ���� ������ �ʰ�
	����ȴ�

	�����
	1: �ȳ�!
	k=1
	���� ��ü���� k�� 1
	���� k�� 3
	k=3
	���� ��ü���� k�� 3
	���� k�� 5
	k=5
	���� ��ü���� k�� 5
	���� k�� 7
	k=7
	*/
#pragma endregion

#pragma region 5��
	/*
	// 5�� 1~10���� �ݺ��� ���

	for (int i = 1; i <= 10; i++)
	{
		printf("%d \n", i);
	}
	*/
	
#pragma endregion

#pragma region 6��
	/*
	// 6�� 10 ~ 1���� �ݺ��� ���

	for (int i = 10; i >= 1; i--)
	{
		printf("%d \n", i);
	}
	*/
	


#pragma endregion

#pragma region 7��

	/*
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		sum += i;
	}
	printf("for���� 1���� 10���� �� �հ� : %d", sum);


	 -------------------�̰� ���������� ���� for���� ������
	int num = 1;
	int sum_w = 0;
	while (num <= 10)
	{
		sum_w += num;
		num++;
		// 1�� �־�����ϴµ� 2���� �־���� ������ ��� 54�� ���Ծ���
		// �ذ����� sum_w += num; �� �ڸ���ġ���� !
	}
	printf("while���� 1���� 10���� �� �հ� : %d \n", sum_w);
	*/
	

#pragma endregion

#pragma region ���� 8�� ~ 10��
	/* 8�� ����
	
	int i = 0;
	int j = 1;
	for (scanf("%d", &i); j < 10; j++)
	{
		printf("%d x %d = %d \n", i, j, i * j);
	}
	*/

	/* 9��
	int i = 0, j = 0, t = 0;
	scanf("%d", &t);

	// 3�� �Է������� 3�� �ݺ��ؾ���
	for (i=1; i <= t; i++)
	{
		// 1�� �� 1��, 2�� �� 2�� �ؾ��ϴϱ� ���ų� �۰� (���Ը� �ϸ� �� ����)
		for (j = 1; j <= i; j++)
		{
			// ���� ��
			printf("* ");
		}
		printf("\n");
	}
	*/

	/* 10��
	int i = 0, j = 0, t = 0;
	scanf("%d", &t);

	// �ݴ�ν����ؾ��ϴϱ� 3 �Է������� 3���� �����ؾߵ�
	// �׷��� i = t�� 1���� ���������ϴϱ� ������ 1�� ���ֵ�,
	// 1���� Ŀ�� ��� ���ư�����
	// 1�� �۾������ϴϱ� ���ҷ�
	for (i = t; i >= 1; i--)
	{
		for (j = 1; j <= i; j++)
		{
			// ���� �־�
			printf("* ");
		}
		printf("\n");
	}
	*/


#pragma endregion

#pragma region 11��
	/* 11��
	int i = 0, sum = 0;

	for (scanf("%d", &i); i >= 0 ; scanf("%d", &i))
	{
		// sum�� i�� �־ ���� �����ֱ�
		sum += i;

		// Ȯ�� -> �߰��� Ȯ������ ����
		// printf("���� sum�� ���� : %d \n", sum);

		// Ż������
		if (sum >= 100)
		{
			printf("100�� �Ѿ����� �����մϴ� ! \n �� ���� %d �Դϴ� ! \n", sum);
			break;
		}
		else
		{
			printf("���ڸ� �� �Է��ϼ��� \n");
		}
	}
	*/


#pragma endregion

#pragma region 12�� - 1
	/* 
	int i = 0, j = 0;
	// int t = 0;
	// scanf("%d", &t);
	// t�� �ݺ��ؾߵ�
	// �׸��� 5�ϱ� 5�� ����

	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= i; j++)
		{
			// 2��°�� 2��°ĭ�� * ����ϴϱ�
			// ���� ���� ���� ������ ���ְ�
			// ������ * �������
			// �ٸ���
			if (j != i)
			{
				printf(" ");
			}
			// ������
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	*/

#pragma endregion

#pragma region 12-1�� ù��° �ǵ��
// �� 12-1�� ���� �ٽ� !

int i = 0, j = 0;

for (i = 1; i <= 5; i++) // ��
{
	for (j = 1; j <= i; j++) // ��
	{
		if (j != i)
		{
			printf(" "); // ���⿡ \n�̰� ���� ��ϳ�
		}
		else
		{
			printf("*");
		}
	}
	printf("\n"); // ���� �������� ���� ������ ������?
}


#pragma endregion


#pragma region 12 - 2 ���� ���� ��� ���� j != i ���� �̿�
/*
	int i = 0, j = 0;
	// int t = 0;
	// scanf("%d", &t);
	// t�� �ݺ��ؾߵ�
	// �׸��� 5�ϱ� 5�� ����

	for (i = 1; i <= 5; i++)
	{
		for (j = 5; j >= i; j--)
		{
			// �̰� ���ۺ��Ͱ� 5�����ϴϱ�
			// �ٸ���
			if (j != i)
			{
				printf(" ");
			}
			// ������
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
*/



#pragma endregion


#pragma region 12-2�� ù��° �ǵ�� j > i �̿�
// �� ���� 12-2 �� !
int i = 0, j = 0, n = 5;

for (i = 1; i <= n; i++) // ��
{
	// (1,5) (2,4) (3,3) (4,2) (5,1)
	for (j = n; j >= i; j--) //�� 2��° �ڸ��� �۾����ϱ� ���ҽ��Ѿ���?
	{
		if (j > i) // >= �̰ɷ� �ع����� ��� ���� ������ݾƤ���
		{
			printf(" ");
		}
		else
		{
			printf("*");
		}
	}
	printf("\n"); // ���� ������ �Ѿ�ž���?
}



#pragma endregion


#pragma region 12 - 2 scanf ����
/*
int i = 0, j = 0;
int t = 0;
scanf("%d", &t);
// t�� �ݺ��ؾߵ�

for (i = 1; i <= t; i++)
{
	for (j = t; j >= i; j--)
	{
		// �̰� ���ۺ��Ͱ� 5�����ϴϱ�
		// �ٸ���
		if (j != i)
		{
			printf(" ");
		}
		// ������
		else
		{
			printf("*");
		}
	}
	printf("\n");
}
*/


#pragma endregion

#pragma region 13��
/*
	int i = 0, j = 0, b = 0;
	// �׸��� 5�� Ʈ���� �����Ǿ��ְ� �Է¹޴� �ٴ� ���� �����ϱ�

	// 12-2 ���⼭���� ä���� �ϳ��� �غ���

	for (i = 1; i <= 5; i++) // �� 5�� �����ڴٴ� ���̰�
	{
		// �� �������� ���� �� ä����
		for (j = 1; j <= 5; j++) // �� �굵 5�� �����ڴٴ� ���̰�
		{
			// j�� 5�� �� ���� �־���� 
			// - i ���� �� �κ� ������ 5��° ������ ���� ���°ž�
			if (j <= 5 - i)  // ����
			{
				printf(" ");
			}
			else // �� 5(��) <= 5 - 1 (1��) �� ��
			{
				printf("*");
			}
		}
		// ���� �������̾�
		// ù��° �� ��ĭ ����ߵȴ�
		for (j = 1; j <= 5; j++) // ��
		{
			// j�� 1�� �� ���� �־���ϰ�
			// j�� 5�� �� ���� �������
			// i�� 1 �� �� ù��°�� �����ϰ� ��� �����̵Ǿ���Ѵٸ�?
			// = �� �ٿ��� ù��°ĭ�� ������鼭 ������ ���� �� ���� �������
			if (j >= i)  // ����
			{
				printf(" ");
			}
			else // ��
			{
				printf("*");
			}
		}
		printf("\n");
	}
*/


#pragma endregion

#pragma region 14��
	/*
	// 9��¥�� X
	int i = 0, j = 0;

	for (i = 1; i <= 9; i++) // ��
	{
		// 1�࿡�� ���� 1~9���� ����
		// ���� ������ ������ ���� ������ �̵��ϴϱ�
		// �׷��ٸ� ���� ��ġ��?
		// 1�࿡�� 1��, 9�� üũ
		// 2�࿡�� 2��, 8�� üũ
		// 3�࿡�� 3��, 7�� üũ
		for (j = 1; j <= 9; j++) // ��
		{
			// ���� ��� ���� �� ���� ���� ����ؾ��ϰ�
			// (1,1) (2,2) (3,3) (4,4) (5,5) ... (9,9) �� ������ j == i �ε�
			// (1,9) (2,8) (3,7) (4,6) (5,5) ... (9,1) �̰� ��� �ұ�
			// OR�Ἥ ��� ���� �ߺ����� �ʰ� �ؾ��ϴϱ�
			// �̰͵� ���� ���� ���� ���� ���� �������� üũ����ߵ�
			// 1�� == 9(�� ��) - 9(���� ��) ��..
			// �� �� - ���� �� �غ��� �� ���� 1 ���ڸ��ϱ�
			// �� �� - ���� �� + 1 ���ָ� ��� ����
			if (j == i || 9 - j + 1 == i)
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
*/



#pragma endregion







	return 0;
}

