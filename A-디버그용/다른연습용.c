// start
// #include "header.h"
#include <stdio.h>

int isPrime(int num);

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
		if (isPrime(num))
			printf("%d ", i);
		else printf("����");
	}

	return 0;
}

// True False ?
int isPrime(int num)
{
	// for�� �ϳ�, if�� �ϳ�
	int i = 0;
	for (i = 2; i < num; i++)
	{
		if (num % i == 0) return 0;
		else return 1;
	}
	
	// �������� 0�̿��� ����� ���ߴ�.
	// ������ �� �������� 0�� �༮(����)�� �������� 1(�Ҽ�)�� �༮
	// 

	// �Ҽ��� ��� ���ұ�
	/*
	i == j  && ������ �� ���� 1?
	*/

	// 1���� num���� ���� �ϴ� �̾�

}