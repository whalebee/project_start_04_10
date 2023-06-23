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
	printf("정수 2개 입력: ");
	scanf_s("%d, %d", &num1, &num2);
	printf("%d 와 %d 중 절대값이 큰 정수: %d \n", num1, num2, absoCompare(num1, num2));

	return 0;
}

//int readNum(void)
//{
//	int num;
//	printf("정수입력: ");
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