
#pragma region ����ü ����
// start
// #include "header.h"
#include <stdio.h>		// printf
#include <string.h>		// strlen, strcpy ��
#include <stdlib.h>		// atoi, rand, malloc, free, EXIT_SUCCESS ��
#include <conio.h>		// 05-02 : getch
#include <errno.h>		// 05-02 : errno ����ϱ� ����

#define MAX_arr 3

void Put_student(STUDENT* Myclass)
{

}


typedef struct student
{
	char name[30];
	char subject[30];
	int score;
}STUDENT;





int main()
{
	/*
	�̸�, ����, ������ ����� ���� �л� ������(student)�� �����
	�ڷ������� ������(STUDENT) �� ��,

	STUDENT�� ���� myStudent�� �����Ͽ�
	�� ����� �����͸� �Է¹޾Ƽ� ����ϼ���.
	*/

	/*
	struct student myStudent;

	printf("�̸� �Է�");
	scanf("%s", myStudent.name);

	printf("���� �Է�");
	scanf("%s", myStudent.subject);

	printf("���� �Է�");
	scanf("%d", &myStudent.score);


	printf("�̸� : %s \n���� : %s \n���� : %d \n", myStudent.name, myStudent.subject, myStudent.score);
	*/



	struct student Myclass[MAX_arr] = {
			{0},
			{0},
			{0}
	};

	// Put_student(Myclass);




	return 0;
}





#pragma endregion


#pragma region �迭 ����
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










// start
#include "header.h"

#define MAX_arr 3

int COUNT = 0;

typedef struct student
{
	char name[30];
	char subject[30];
	int score;
}STUDENT;


void put_student(STUDENT* myClass);
void print_student(STUDENT* myClass);


int main()
{
	/*
	�̸�, ����, ������ ����� ���� �л� ������(student)�� �����
	�ڷ������� ������(STUDENT) �� ��,

	STUDENT�� ���� myStudent�� �����Ͽ�
	�� ����� �����͸� �Է¹޾Ƽ� ����ϼ���.
	*/

	/*
	struct student myStudent;

	printf("�̸� �Է�");
	scanf("%s", myStudent.name);

	printf("���� �Է�");
	scanf("%s", myStudent.subject);

	printf("���� �Է�");
	scanf("%d", &myStudent.score);


	printf("�̸� : %s \n���� : %s \n���� : %d \n", myStudent.name, myStudent.subject, myStudent.score);
	*/


	struct student myClass[MAX_arr] = {
			{0},
			{0},
			{0}
	};

	// �Է�
	put_student(myClass);

	// Ȯ��
	print_student(myClass);

	return 0;
}

// 2�� �ϰ� �ʹٸ�?
void put_student(STUDENT* myClass)
{
	char check[10] = "\0";

	for (int i = 0; i < MAX_arr; i++)
	{
		printf("�̸� �Է� : ");
		scanf("%s", myClass[i].name);

		printf("���� �Է� : ");
		scanf("%s", myClass[i].subject);

		printf("���� �Է� : ");
		scanf("%d", &myClass[i].score);

		printf("�� �Է��ҷ���? y or n\n");
		scanf("%s", check);

		if (strcmp(check, "n") == 0)
		{
			COUNT = i + 1;
			return;
		}
	}

	COUNT = MAX_arr;
}

void print_student(STUDENT* myClass)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d��° myClass�� �� = {\n", i + 1);
		printf("name : %s \nsubject : %s \nscore : %d \n", myClass[i].name, myClass[i].subject, myClass[i].score);
		printf("} \n");
	}
}


#pragma endregion


#pragma region


#pragma endregion