#include <stdio.h>

extern int NUM; // �ʱ�ȭ�� �ϸ� �ȵǴ� ��, �ٸ� ������ �� ������ ����

void fn_print();



int main()
{
	int NUM = 50; // �̰� int����� ���������� �ٲ����
	printf("%d \n", NUM);

	fn_print();

	printf("%d \n", NUM); // GlobalNum  �̰� ���� 50���� ���� ���������� �켱�ؼ� �а� ��

	return 0;
}




void fn_print()
{
	NUM = NUM + 10; // �̷����ϸ� ���������� ������
	printf("%d \n", NUM);
}