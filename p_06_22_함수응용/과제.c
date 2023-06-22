#include <stdio.h>

void howToUseThisProg();
int add(int n1, int n2);
void showAddResult(int result);
int readNum();

int main()
{
	int result = 0, num1 = 0, num2 = 0;

	// howToUseThisProg 함수 호출

	// readNum 함수 ( 사용자로부터 값을 하나 입력 받는 용도 )

	// add 함수 ( 전달받은 두 정수의 합을 반환하는 함수 )

	// showAddResult 함수 ( 전달받은 결과값을 출력하는 함수 )

	howToUseThisProg();
	num1 = readNum();
	num2 = readNum();
	result = add(num1, num2);
	showAddResult(result);

	return 0;
}

// howToUseThisProg 함수 호출
void howToUseThisProg()
{
	printf("두 개 정수를 입력하면 덧셈 결과 출력됩니다 \n");
	printf("두 개 정수를 입력하세요 \n");
}

// add 함수 ( 전달받은 두 정수의 합을 반환하는 함수 )
int add(int n1, int n2)
{
	return n1 + n2;
}

// readNum 함수 ( 사용자로부터 값을 하나 입력 받는 용도 )
// 매개변수로 주는게 아니라 scanf_s를 사용해서 값을 입력하면 그 입력값을 리턴해주라는 뜻 같음
int readNum()
{
	int num;
	scanf_s("%d", &num);
	return num;
}


// showAddResult 함수 ( 전달받은 결과값을 출력하는 함수 )
void showAddResult(int result)
{
	printf("%d", result);
}