#include <stdio.h>


int main()
{

	// 12�Ͽ� Ǯ�� if������ ���� �� ������ִ� ��
	// ��
	int year = 0, month = 0, day = 0, chk = 0, max_day = 0;

	// ��¥ �Է� �ޱ�
	printf("��¥�� �Է��ϼ���. (yyyy mm dd)");
	chk = scanf("%d %d %d", &year, &month, &day);

	// �ݵ�� �ʿ� !
	// �Է�(��ȿ��) üũ(�⵵, ��, �Է°�) -> ���ϴ� �����Ͱ� �´���, ������ �´���
	// �ƿ� ���� �Լ��� ���ų� �ҽ��� ���� ���δ� ��쵵 �־�
	if (chk != 3 || month > 12 || month < 1 || year < 1)
	{
		printf("��ȿ���� �߸��Ǿ���.");
		return 1;
	}

	// �Է��� ���� �ش��ϴ� MAX_day�� ����
	if (month == 2)
	{
		max_day = 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		max_day = 30;
	}
	else
	{
		max_day = 31;
	}

	// �Է�(��ȿ��) üũ(��)
	if (day > max_day)
	{
		printf("�׷� ��¥ ���پƾƾ�\n");
		return 1;
	}

	// ��(+�Ϸ�) ���� ó��
	day++;
	if (day > max_day)
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}

	//���
	printf("�Է��Ͻ� ��¥�� ���� ���� %d�� %d�� %�� �Դϴ� \n", year, month, day);
}