#include <stdio.h>

void fn_print(); // �������� �ʰ� �������� ���� �Լ� ����


int main()
{
#pragma region ������

	// switch ��

	int score = 100;
	char grade = ' ';

	switch (score / 10)
	{
	case 10:
		printf("��~ ��~ ��~ �ϴ�~~ \n");
		// break ������ ���� ������ ��� ����
		// break ������ ���̸� ������ �� ������ ���� �� �����ϰ� ��� ����
	case 9:
		grade = 'A';
		break;
	default: // ��� ��
		grade = 'F';
	}

	printf("������ %c�����Դϴ�. \n", grade);





#pragma endregion

#pragma region ������ ����

	// 3���Դϴ�

	// ����
	int v1 = 0, v2 = 0;
	char cal;
	int result = 0;

	// �Է�
	printf("���꿡 ����� ���� �� ���� �����ڸ� ������� �Է��ϼ��� \n");
	scanf("%d %d %c", &v1, &v2, &cal);

	// ���
	if (cal == '+')
	{
		result = v1 + v2;
	}
	else if (cal == '-')
	{
		result = v1 - v2;
	}
	else if (cal == '*')
	{
		result = v1 * v2;
	}
	else if (cal == '/')
	{
		result = v1 / v2;
	}
	else if (cal == '%')
	{
		result = v1 % v2;
	}
	else
	{
		printf("�Է��� �߸��Ǿ���. \n");
	}

	// ���
	printf("%d %c %d = %d�Դϴ� \n", v1, cal, v2, result);




	// 4���Դϴ� !

	// ����
	int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, chk = 0, avg_result = 0;

	// �Է¹ޱ�
	printf("���� �ټ����� �Է��ϼ���. \n");
	chk = scanf("%d %d %d %d %d", &s1, &s2, &s3, &s4, &s5);

	//printf("%d", chk);

	// ������� ����
	if (chk == 5)
	{
		avg_result = (s1 + s2 + s3 + s4 + s5) / chk;
	}
	else
	{
		printf("5���� ������ ����� �Է��غ����� \n");
		return 1;
	}

	// ������� �̴� ����
	// avg_result�� �� -> ���� �ֵ� ���

	printf("��� ������ %d���̰�, ������� �̸��� ", avg_result);

	// ���ڿ� �Լ��� ���� �ʰ��� �̷� ����ۿ� ���°ɱ�..?
	if (s1 < avg_result)
	{
		printf("%d ", s1);
	}

	if (s2 < avg_result)
	{
		printf("%d ", s2);
	}

	if (s3 < avg_result)
	{
		printf("%d ", s3);
	}

	if (s4 < avg_result)
	{
		printf("%d ", s4);
	}

	if (s5 < avg_result)
	{
		printf("%d ", s5);
	}

	// ������� �̸��� ���� ��
	if (s1 >= avg_result && s2 >= avg_result && s3 >= avg_result && s4 >= avg_result && s5 >= avg_result)
	{
		printf("�����ϴ� ! \n");
	}
	else
	{
		printf("�Դϴ�. \n");
	}

	// ������� �̸��� ���� ����
	// count ���� ���� if�� �������ٰ� ����־���� count ������ Ȯ���ϴ°� ���� ��




	// 5���Դϴ�

	// ��������
	int score = 0, chk_s = 0;
	char grade = 'F';

	// �Է�
	printf("������ �Է����ּ��� \n");
	chk_s = scanf("%d", &score);

	// ��ȿ�� �˻�
	if (chk_s != 1)
	{
		printf("���Ͻô°��� ���� \n");
		return 1;
	}
	else if (score > 100 || score < 1)
	{
		printf("�Է��� ���� %d�� ��ȿ���� ���Դϴ� (��ȿ���� 1 ~ 100)\n", score);
		return 1;
	}
	


	// ���
	switch (score / 10)
	{
	case 10:
		grade = 'A';
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	}

	// ���
	printf("�Է¹��� ������ %c ���� �Դϴ�. \n", grade);



#pragma endregion



	return 0;
}


void fn_print()
{
	int n1 = 30, n2 = 40;
	printf("%d %d \n", n1, n2);
}


