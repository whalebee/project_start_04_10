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

