// start
// #include "header.h"
#include <stdio.h>

#define H 60*60
#define M 60

void secondToHMS(int sec);



int main()
{
	/*
	초(second)를 입력 받은 후에 이를 [시, 분, 초]의 형태로 출력하는 프로그램 작성

	ex) 초(second) 입력: 3615
		[h:1, m:0, s:15]
	*/
	int sec;
	printf("초(second) 입력: ");
	scanf_s("%d", &sec);
	secondToHMS(sec);

	return 0;
}

void secondToHMS(int sec)
{
	int h,m,s;
	h = sec / h
	

	printf("[h:%d, m:%d, s:%d]", h,m,s);
}
