#pragma region static

#include <stdio.h>

void simpleFunc();

int main()
{
	/*
	main
	: simpleFunc �Լ� 3�� ȣ��. ����x
	3�� ȣ���̸� �ݺ��� ��� �� ��������

	simpleFunc �Լ�
	- num1. 0���� ������(??) ( ��, num1�� static ���� )
	- num2. 0���� ������(???)
	- num1, num2 1�� ����
	- num1, num2 ���
	*/
	int i;
	for (i = 0; i < 3; i++)
		simpleFunc();

	return 0;
}

void simpleFunc()
{
	static int num1 = 0;
	// ȣ���� ���� �ʾƵ� static�� ������ �� ( ������ �ٵ� ���� �ȿ����� ��ϱ� ���� ������� )
	int num2 = 0;
	num1++;
	num2++;
	printf("num1: %d, num2 : %d \n", num1, num2);
}



#pragma endregion


#pragma region factorial ����Լ� (����)
#include <stdio.h>

int fac(int value);

int main()
{
	int num;
	printf("input: ");
	scanf_s("%d", &num);
	if (num < 0) return -1;
	printf("%d! : %d ", num, fac(num));

	return 0;
}

int fac(int value)
{
	if (value == 0) return 1;
	return value * fac(value - 1);
}


#pragma endregion



#pragma region 3�� ���� ��Ǯ�� -> while�� Ǫ��
// start
// #include "header.h"
#include <stdio.h>

// start
// #include "header.h"
#include <stdio.h>

int GCD(int v1, int v2);

int main()
{
	// �� ���� ���� �Է¹޾Ƽ� �ִ� ������� ���ϴ� ���α׷� �ۼ�
	// 6�� 9�� �Է��ϸ� 3�� ���;���.
	// 12 : 1 2 3 4 6 12
	// 16 : 1 2 4 8 16
	// ������ �� 0 �̶���� -> ��Ʈ��

	int v1, v2;
	printf("�� ���� ���� �Է� : ");
	scanf_s("%d %d", &v1, &v2);

	printf("gcd : %d \n", GCD(v1, v2));


	return 0;
}

int GCD(int v1, int v2)
{
	// int i, gcd;
	int result;
	// ���� �ؿ� 4��?	 �ϴ� �̾Ƴ�����

	// �ʹ� ����� �̰� �³�
	// �ٸ� ���� result <= v1 > v2 ? v1+1 : v2+1
	result = v1 > v2 ? v1 : v2;
	for (; result <= v1 || result <= v2; result--)
		if (v1 % result == 0 && v2 % result == 0) return result;
}





#pragma endregion



#pragma region 1���� 2��
#include <stdio.h>

void gugudan(int n1, int n2);

int main()
{
	// 16����
	/*
	int num = 0;
	printf("input: ");
	scanf_s("%d", &num);
	printf("16����ȭ: %x", num);
	*/



	// 2��
	// ���� 4���� �ؾ���
	// int num1 = 0, num2 = 0, j, temp;
	int num1 = 0, num2 = 0, i, j;

	printf("input 2 numbers: ");
	scanf_s("%d %d", &num1, &num2);


	// �Լ� �ƴ� ��
	// 1. 3,5 �� �� ( �ϴ� 5,3 �����ϰ� Ʋ �������� )
	// 2. ���� 5,3 �� ��쵵 �־���� -> swap����� ����? �ֳ��� ����
	// swap ������
	for (i = num1; i < 10; i++)
	{
		if (i > num2) break;
		for (j = 1; j < 10; j++) printf("%d x %d = %d \n", i, j, i * j);
		printf("\n");
	}


	// �Լ� �������� ���� �� -> �Լ� �ƴϿ��� ��
	// int num1 = 0, num2 = 0;
	// gugudan(num1, num2);


	return 0;
}




void gugudan(int n1, int n2)
{
	int temp, j = 0;

	if (n1 > n2)
	{
		temp = n1;
		n1 = n2;
		n2 = temp;
	}
	for (; n1 < 10; n1++)
	{
		if (n1 > n2) break;
		for (j = 1; j < 10; j++)
			printf("%d x %d = %d \n", n1, j, n1 * j);
		printf("\n");
	}
}





#pragma endregion



#pragma region 4�� �ݺ������� ����� ���� �ʴ´ٳ�
// start
// #include "header.h"
#include <stdio.h>



int main()
{
	/*
	3500���� ������ ����(500��), ��ī�ݶ�(700��), ���(400��)�� ����Ѵ�.
	�ܵ��� �� ����� �� ������ ������ �ϳ� �̻� �ݵ�� �����Ϸ���
	��� ���Ÿ� �����ؾ� �ϴ°�?
	�������� ����� ���� �����ٵ� �����غ���

	ex
	���� �����ݾ� 3500��
	���� 1��, ��ī�ݶ� 2��, �� �� 4��
	���� 2��, ��ī�ݶ� 3��, �� �� 1��
	���� 4��, ��ī�ݶ� 1��, �� �� 2��

	��� �����ҷ���?
	*/
	// A Z ��Ʈ




	// ������ ��Ʈ�� A Z ��� �� �̰� �������������� õõ�� �����غ���
	// AZ�� printf���� �峭ġ�� �������µ�
	// �׷� ���⿡��?

	// printf("���� %d��, ��ī�ݶ� %d��, �� �� %d�� \n", );

	// 124 231 412 �̰� ���� ���� �� ������
	// �׷� �� ���� ��� ã�ƾ��ϳ�??

	// 500		1400	1600
	// 1000		2100	400
	// 2000		700		800

	// 1		2		4
	// 2		3		1
	// 4		1		2

	// A������ Z������?

	int basic = 0, x, y, z;
	int mac = 500, coke = 700, coou = 400;
	printf("���� ����� �����ϰ� �ִ� �ݾ� : ");
	scanf_s("%d", &basic);
	// �� ������ �ƴ϶� ������ ������
	for (x = 1; x < basic / mac; x++)
	{
		for (y = 1; y <= basic / coke; y++)
		{
			for (z = 1; z <= basic / coou; z++)
			{
				if (basic == (x * mac) + (y * coke) + (z * coou))
					printf("��	�� %d��,  ��ī�ݶ� %d��,  ��	�� %d�� \n", x, y, z);
			}
		}
	}






	return 0;
}







	return 0;
}





#pragma endregion



#pragma region 5�� �� Ǯ�� �� �ù��� ���� ���� �� Ǯ����, 2���γ� �� ��Ƶ� Ǯ����
// start
// #include "header.h"
#include <stdio.h>

int isPrime(int i, int num);


int main()
{
	/*
	5. ����� �ϳ� �Է� �޾� 1���� �� �������� �Ҽ��� ���
	1�� �ڱ��ڽŹۿ� ���� �༮
	�̰� ��� ���ұ�
	*/

	int num, i;
	printf("��� �Է� : ");
	scanf_s("%d", &num);

	// �Ҽ��� �ƴϳĸ� ��ȯ�� �ؼ� �Ҽ��� i�� ����ϰ� �ƴϸ� �ѱ��?
	for (i = 1; i < num; i++)
	{
		if (isPrime(i, num))
			printf("�Ҽ�: %d \n", i);
	}


	return 0;
}

// True False ?
int isPrime(int i, int num)
{
	// for�� �ϳ�, if�� �ϳ�
	
	if (num % i == 0 || ) return 0;
	else return 1;
	// �������� 0�̿��� ����� ���ߴ�.
	// ������ �� �������� 0�� �༮(����)�� �������� 1(�Ҽ�)�� �༮
	// 

	// �Ҽ��� ��� ���ұ�
	/*
	i == j  && ������ �� ���� 1?
	*/

	// 1���� num���� ���� �ϴ� �̾�

}



#pragma endregion



#pragma region 6��
// start
// #include "header.h"
#include <stdio.h>

#define H 3600
#define M 60

void secondToHMS(int sec);



int main()
{
	/*
	��(second)�� �Է� ���� �Ŀ� �̸� [��, ��, ��]�� ���·� ����ϴ� ���α׷� �ۼ�

	ex) ��(second) �Է�: 3615
		[h:1, m:0, s:15]
	*/
	int sec;
	printf("��(second) �Է�: ");
	scanf_s("%d", &sec);
	secondToHMS(sec);

	return 0;
}

void secondToHMS(int sec)
{
	int s = 1, cal_h, cal_m;
	cal_h = sec % H;
	cal_m = sec % M;

	printf("[h:%d, m:%d, s:%d]", sec / H, cal_h / M, cal_m / s);
}



#pragma endregion




#pragma region 




#pragma endregion




#pragma region 




#pragma endregion