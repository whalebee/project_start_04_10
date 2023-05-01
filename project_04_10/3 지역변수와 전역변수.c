#include <stdio.h>

extern int NUM; // 초기화를 하면 안되는 것, 다른 곳에서 값 변경은 가능

void fn_print();



int main()
{
	int NUM = 50; // 이거 int지우면 전역변수를 바꿔버림
	printf("%d \n", NUM);

	fn_print();

	printf("%d \n", NUM); // GlobalNum  이거 쓰면 50으로 읽음 지역변수를 우선해서 읽게 됨

	return 0;
}




void fn_print()
{
	NUM = NUM + 10; // 이렇게하면 전역변수도 수정됨
	printf("%d \n", NUM);
}