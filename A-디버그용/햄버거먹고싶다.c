#include "header.h"



int main()
{
	// �ҹ��� �빮��
	// �������� ����
	// ����ȭ

	/*
	1. limit_student�� �����Ҵ��� �� �Ǿ����� üũ�� ���߰�							-ch
	2. �����Ҵ��� ���� �����ߴ��� free�Լ��� ���� �ڵ��Ǿ� �ֳ׿�.			return ���� �����Ŵ
	3. ���� �ƶ����� �Ҵ��� ������ ��쿡�� ���� Ȯ���� �ϰ� ����.					return ���� �����Ŵ
	4. sum/avg�� ���� �� ������ ���� �ʿ�� �����ϴ�.								g
	5. sum/avg�� int������ ǥ���ϴ� ���� ���� �� ���ٴ� ��.							g
	6. �迭ǥ���� ������ ǥ���� ȥ������ ���ð� ��ġ��Ű�� �� ���� �� �����ϴ�.		-ch
	*/

	// �ݼ�(����)�� �� �б��� �ο�(����)�� ���� �Է� �޾� ������ �����͸� �����Ҵ��ϰ�,
	// �� �л��� ������ �Է� �޾Ƽ� �б޺� ����� ����ϼ���.

	// �ݼ� -> ��
	// �б��� �ο� -> ��

	int limit_grade = 0, score = 0;

	int** myClass = 0;
	int* limit_student = 0;
	int* sum = 0;
	int* avg = 0;


	printf("�� �ݱ��� �ֳ�? :");
	scanf("%d", &limit_grade);

	myClass = (int**)malloc(sizeof(int*) * limit_grade); // ��
	limit_student = (int*)malloc(sizeof(int) * limit_grade); // ����� ��¿�
	sum = (int*)malloc(sizeof(int) * limit_grade);
	avg = (int*)malloc(sizeof(int) * limit_grade);


	if (myClass != NULL && sum != NULL && avg != NULL && limit_student != NULL)
	{
		for (int i = 0; i < limit_grade; i++)
		{
			printf("%d�г� �л� ���� �Է� : \n", i + 1);
			scanf("%d", limit_student + i);

			myClass[i] = (int*)malloc(sizeof(int) * limit_student[i]); // ��

			if (myClass[i] != NULL)
			{
				sum[i] = 0; // �ջ��� ���� �迭 �ʱ�ȭ
				for (int j = 0; j < limit_student[i]; j++)
				{
					printf("%d�г� %d��° �л��� ������ �Է� : ", i + 1, j + 1);
					scanf("%d", &score);
					myClass[i][j] = score;
					sum[i] += score;
				}
			}
			else
			{
				printf("�Ҵ��� �ȵǾ���.  \n");
				return 0;
			}

			// printf("%d �г��� ���� : %d \n", i+1, sum[i]);
			avg[i] = sum[i] / limit_student[i];
		}

	}
	else
	{
		printf("myClass �޸� �Ҵ� ���� ! \n");
		return 0;
	}


	// Ȯ��
	for (int i = 0; i < limit_grade; i++)
	{
		printf("%d�г��� ���� %d ,", i + 1, sum[i]);
		printf("��� %d , ", avg[i]);
		printf("%d�г� ��ü ���� : ", i + 1);
		for (int j = 0; j < limit_student[i]; j++)
		{
			printf("%d�� ", myClass[i][j]);
		}
		puts(" ");
	}


	// ����
	printf("�޸� �Ҵ� ���� ���� \n");

	// 2���� ����
	for (int f = 0; f < limit_grade; f++)
	{
		free(myClass[f]);
	}

	// 1���� ����
	free(myClass);
	free(limit_student);
	free(sum);
	free(avg);


	return 0;
}