
#pragma region 재귀함수 예제 1 ~ 4번
// start
#include "header.h"

int fn_recursive1(int x)
{
	if (x < 5)return(3 * x);
	else
	{
		return(2 * fn_recursive1(x - 5) + 7);
	}
}


int fn_recursive35(int x, int y)
{
	if (x > y) return (-4);
	else return (fn_recursive35(y - x, x - 3) + y);
}


// 3번
int number(int a)
{
	if (a <= 0) return 0;

	number(a - 1);

	printf("%d ", a);
}

// 4번
int factoiral(int a)
{
	if (a == 1 || a == 0)
	{
		return 1;
	}

	return a * factoiral(a - 1);
}


int main()
{

	printf("%d \n", fn_recursive1(4));
	printf("%d \n", fn_recursive1(10));
	printf("%d \n", fn_recursive1(12));



	printf("%d ", fn_recursive35(2, 7));
	printf("%d ", fn_recursive35(5, 3));
	printf("%d ", fn_recursive35(15, 3));


	number(20);

	printf("%d ", factoiral(5));



	return 0;
}




#pragma endregion


#pragma region 피보나치
// start
#include "header.h"

int Fibonacci(int a);

int main()
{
	int phase = 0;

	printf("몇 단계 까지 할래?");
	scanf("%d", &phase);

	for (int i = 1; i <= phase; i++)
	{
		printf("%d ", Fibonacci(i));
	}

	return 0;
}

int Fibonacci(int a)
{
	if (a == 0) return 0;
	else if (a <= 1) return 1;
	else
	{
		return Fibonacci(a - 1) + Fibonacci(a - 2);
	}
}


#pragma endregion


#pragma region 미스터 하노이씨
// start
#include "header.h"

void hanoi_tower(int n, char from, char temp, char to);

int main()
{
	hanoi_tower(3, 'A', 'B', 'C');

	return 0;
}


void hanoi_tower(int n, char from, char temp, char to)
{
	if (n == 1)
	{
		printf("1번째 원판은 %c에서 %c로 움직입니다. \n", from, to);
	}
	else
	{
		hanoi_tower(n - 1, from, to, temp);
		printf("%d번째 원판이 %c에서 %c로 움직입니다 \n", n, from, to);
		hanoi_tower(n - 1, temp, from, to);
	}
}



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion




#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion





