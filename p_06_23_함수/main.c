// start
// #include "header.h"
#include <stdio.h>

int absoCompare(int num1, int num2);
int getAbsoValue(int num1);


int main()
{
	int num1, num2;
	/*
	num1 = readNum();
	num2 = readNum();
	*/
	printf("���� 2�� �Է�: ");
	scanf_s("%d, %d", &num1, &num2);
	printf("%d �� %d �� ���밪�� ū ����: %d \n", num1, num2, absoCompare(num1, num2));

	return 0;
}

//int readNum(void)
//{
//	int num;
//	printf("�����Է�: ");
//	scanf_s("%d", &num);
//	return num;
//}

int absoCompare(int num1, int num2)
{
	return getAbsoValue(num1) > getAbsoValue(num2) ? num1 : num2;
}

int getAbsoValue(int num1)
{
	return num1 < 0 ? ~(num1)+1 : num1;
}