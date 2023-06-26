#include <stdio.h>



int main()
{
#pragma region  1번 swap
	// 1번
	// start
// #include "header.h"
#include <stdio.h>

	void swap(int v1, int v2);

	int main()
	{
		int v1, v2;
		printf("input 2 numbers: ");
		scanf_s("%d %d", &v1, &v2);

		printf("x는 %d이고 y는 %d 입니다. \n", v1, v2);
		swap(v1, v2);

		return 0;
	}

	void swap(int v1, int v2)
	{
		int temp;
		temp = v1;
		v1 = v2;
		v2 = temp;
		printf("swap을 적용한 v1은 %d, v2는 %d입니다. \n", v1, v2);
	}



#pragma endregion


#pragma region  2번 제일 큰 수 작은 수
	// start
// #include "header.h"
#include <stdio.h>

	int getMaxValue(int v1, int v2, int v3);
	int getMixValue(int v1, int v2, int v3);

	int main()
	{
		int v1, v2, v3;
		printf("input 3 numbers: ");
		scanf_s("%d %d %d", &v1, &v2, &v3);

		printf("Max Number: %d \n", getMaxValue(v1, v2, v3));
		printf("Min Number: %d \n", getMixValue(v1, v2, v3));

		return 0;
	}

	int getMaxValue(int v1, int v2, int v3)
	{
		if (v1 > v2)	return v1 > v3 ? v1 : v3;
		else			return v2 > v3 ? v2 : v3;
		// else가 없어도 됨.
	}

	int getMixValue(int v1, int v2, int v3)
	{
		if (v1 < v2)	return v1 < v3 ? v1 : v3;
		else			return v2 < v3 ? v2 : v3;
	}



#pragma endregion


#pragma region  3번 섭씨화씨
	// start
// #include "header.h"
#include <stdio.h>

	double CelToFah(double degree);
	double FahToCel(double degree);

	int main()
	{

		int sel = 0;
		double degree = 0;
		printf("1. 섭씨를 화씨로  2. 화씨를 섭씨로 \n 선택>>");
		scanf_s("%d", &sel);

		switch (sel)
		{
		case 1:
			printf("섭씨 입력: ");
			scanf_s("%f", &degree);
			printf("변화된 화씨: %.1f \n", CelToFah(degree));
			break;
		case 2:
			printf("화씨 입력: ");
			scanf_s("%f", &degree);
			printf("변화된 섭씨: %.1f \n", FahToCel(degree));
			break;
		default:
			printf("1과 2중에 선택하셔야됩니다. \n");
			break;
		}
		return 0;
	}

	double CelToFah(double degree)
	{
		return (degree * 1.8) + 32;
	}

	double FahToCel(double degree)
	{
		return (degree - 32.0) / 1.8;
	}



#pragma endregion


#pragma region  4번 피보나치수열 재귀함수 ㄴㄴ
#include <stdio.h>

	void fibo(int n);

	int main()
	{
		int n;

		printf("input: ");
		scanf_s("%d", &n);

		if (n < 1)
		{
			printf("1 이상의 값을 입력해야한다 ! \n");
			return -1;
		}

		fibo(n);

		return 0;
	}

	void fibo(int n)
	{
		int start = 0, next = 1, before, i;

		for (i = 0; i < n; i++)
		{
			printf("%d ", start);
			before = start;
			start += next;
			next = before;
		}
	}

	// 봉쌤방법
	void fibo(int n)
	{
		int f1 = 0, f2 = 1, f3, i;

		f3 = f1 + f2;
		if (num == 1) printf("%d ", f1);
		else			printf("%d %d ", f1, f2);

		for (i = 0; i < num - 2; i++)
		{
			f3 = f1 + f2;
			printf("%d ", f3);
			f1 = f2;
			f2 = f3;
		}
	}



#pragma endregion















	return 0;
}

