#include <stdio.h>

int returnNum()
{
	int num = 5;
	return num;
}

void main()
{

	int num = returnNum();
	// ���������� �� �� ������ printf�� �ִ� num������ �������ֱ�
	// �ű⿡ returnNum �Լ���  ����� �ֱ�
	printf("%d", num);

	return 0;
}