#include <stdio.h>



int main()
{
#pragma region  1�� swap
	// 1��
	// start
// #include "header.h"
#include <stdio.h>

	void swap(int v1, int v2);

	int main()
	{
		int v1, v2;
		printf("input 2 numbers: ");
		scanf_s("%d %d", &v1, &v2);

		printf("x�� %d�̰� y�� %d �Դϴ�. \n", v1, v2);
		swap(v1, v2);

		return 0;
	}

	void swap(int v1, int v2)
	{
		int temp;
		temp = v1;
		v1 = v2;
		v2 = temp;
		printf("swap�� ������ v1�� %d, v2�� %d�Դϴ�. \n", v1, v2);
	}



#pragma endregion


#pragma region  2�� ���� ū �� ���� ��
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
		else				return v2 > v3 ? v2 : v3;
	}

	int getMixValue(int v1, int v2, int v3)
	{
		if (v1 < v2)	return v1 < v3 ? v1 : v3;
		else				return v2 < v3 ? v2 : v3;
	}



#pragma endregion


#pragma region  3�� ����ȭ��
	// start
// #include "header.h"
#include <stdio.h>

	double CelToFah(double degree);
	double FahToCel(double degree);

	int main()
	{

		int sel = 0;
		double degree = 0;
		printf("1. ������ ȭ����  2. ȭ���� ������ \n ����>>");
		scanf_s("%d", &sel);

		switch (sel)
		{
		case 1:
			printf("���� �Է�: ");
			scanf_s("%lf", &degree);
			printf("��ȭ�� ȭ��: %.1lf \n", CelToFah(degree));
			break;
		case 2:
			printf("ȭ�� �Է�: ");
			scanf_s("%lf", &degree);
			printf("��ȭ�� ����: %.1lf \n", FahToCel(degree));
			break;
		default:
			printf("1�� 2�߿� �����ϼžߵ˴ϴ�. \n");
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


#pragma region  4�� �Ǻ���ġ���� ����Լ� ����
#include <stdio.h>

	void fibo(int n);

	int main()
	{
		int n;

		printf("input: ");
		scanf_s("%d", &n);

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



#pragma endregion















	return 0;
}

