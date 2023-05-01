#include <stdio.h>


// static : 전역변수에다가 static붙이면 이 소스에서만 보겠다는 뜻


void IncreaseNumber();

int main() {

#pragma region static

	IncreaseNumber();
	IncreaseNumber();
	IncreaseNumber();
	IncreaseNumber();
	IncreaseNumber();
	// printf("%d", number); number가 선언되어있지 않으니까 쓸 수 없지

#pragma endregion

	return 0;
}

// 지역변수에다가 static을 붙이면 함수를 나가도 그 값을 유지하고 있는 특징을 가짐
void IncreaseNumber()
{
	static int number = 0; // static을 붙이면 위에 main에서의 값이 1 2 3 4 5 가 나오는 것
	printf("%d \n", ++number);
}