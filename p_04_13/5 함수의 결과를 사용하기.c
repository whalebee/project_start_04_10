#include <stdio.h>

int returnNum()
{
	int num = 5;
	return num;
}

void main()
{

	int num = returnNum();
	// 전역변수를 쓸 수 없으면 printf에 있는 num변수를 선언해주기
	// 거기에 returnNum 함수의  결과를 넣기
	printf("%d", num);

	return 0;
}