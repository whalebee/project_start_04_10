#include <stdio.h>


// static : �����������ٰ� static���̸� �� �ҽ������� ���ڴٴ� ��


void IncreaseNumber();

int main() {

#pragma region static

	IncreaseNumber();
	IncreaseNumber();
	IncreaseNumber();
	IncreaseNumber();
	IncreaseNumber();
	// printf("%d", number); number�� ����Ǿ����� �����ϱ� �� �� ����

#pragma endregion

	return 0;
}

// �����������ٰ� static�� ���̸� �Լ��� ������ �� ���� �����ϰ� �ִ� Ư¡�� ����
void IncreaseNumber()
{
	static int number = 0; // static�� ���̸� ���� main������ ���� 1 2 3 4 5 �� ������ ��
	printf("%d \n", ++number);
}