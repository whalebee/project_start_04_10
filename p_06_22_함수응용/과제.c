#include <stdio.h>

void howToUseThisProg();
int add(int n1, int n2);
void showAddResult(int result);
int readNum();

int main()
{
	int result = 0, num1 = 0, num2 = 0;

	// howToUseThisProg �Լ� ȣ��

	// readNum �Լ� ( ����ڷκ��� ���� �ϳ� �Է� �޴� �뵵 )

	// add �Լ� ( ���޹��� �� ������ ���� ��ȯ�ϴ� �Լ� )

	// showAddResult �Լ� ( ���޹��� ������� ����ϴ� �Լ� )

	howToUseThisProg();
	num1 = readNum();
	num2 = readNum();
	result = add(num1, num2);
	showAddResult(result);

	return 0;
}

// howToUseThisProg �Լ� ȣ��
void howToUseThisProg()
{
	printf("�� �� ������ �Է��ϸ� ���� ��� ��µ˴ϴ� \n");
	printf("�� �� ������ �Է��ϼ��� \n");
}

// add �Լ� ( ���޹��� �� ������ ���� ��ȯ�ϴ� �Լ� )
int add(int n1, int n2)
{
	return n1 + n2;
}

// readNum �Լ� ( ����ڷκ��� ���� �ϳ� �Է� �޴� �뵵 )
// �Ű������� �ִ°� �ƴ϶� scanf_s�� ����ؼ� ���� �Է��ϸ� �� �Է°��� �������ֶ�� �� ����
int readNum()
{
	int num;
	scanf_s("%d", &num);
	return num;
}


// showAddResult �Լ� ( ���޹��� ������� ����ϴ� �Լ� )
void showAddResult(int result)
{
	printf("%d", result);
}