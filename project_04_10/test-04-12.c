#include <stdio.h>
#define FORMAT "%s! C�� ������! \n"

int main()
{

#pragma region ������
	
	
	// �������� �Ǽ����
	printf("%f \n", (float)(10 / 3)); // 3.000000 �������鳢���� ����� �Ҽ����� ��������
	printf("%f \n", (float)(10.0 / 3.0)); // 3.333333
	// ȥ���ϸ� �ε��Ҽ���(�Ǽ�)���� ����� �ع���

	// ������
	printf("%d \n", 10 % 3);
	

	int a = 10;
	printf("%d \n", ++a); // 1. 11
	printf("%d \n", a++); // 2. 11 -> a�� 12�� �Ǿ������� ����� 11�� ����

	if (a == 10)
	{
		printf("a�� %d�Դϴ�. ", a);
	}
	else
	{
		printf("a�� 10�� �ƴϿ�. a�� %d(��)�� �Ǿ��ּ�. \n", a);
	}

	/*
	if (a = 0)
	{
		���⿡ �� ���� ����
		0�� �ƴϸ� ��� ��, ������ �Ҽ� ��� ������ ����
	}
	else
	{
		!�� �ٴ� �� �ƴ� �̻� ������ ������ �� ? ������ FALSE�� �����ϱ�
	}
	*/

	double d = 10;
	int i = 10.12345;

	char c = 10;
	short s = 20;

	double sum = 10 + 10.123;

	double cast_sum = (int)1.6 + (int)1.7;
	double cast_sum1 = (int)(1.6 + 1.7);

	double impicit_cast = 1.6 + 1.7; 

	printf("%.2lf, %.2lf \n", cast_sum, cast_sum1);



	// ����

	int x = 22.0 * 3 / 5;
	printf("x�� %d \n", x);

	int y = x = (2+3)/4;
	printf("y�� %d \n", y);
	printf("x�� %d \n", x);
	int num = 10;
	printf(FORMAT, FORMAT);





	int value1 = 0;
	int value2 = 0;
	
	printf("ù��° ���ڸ� �Է��ϼ��� \n");
	scanf("%d", &value1);
	printf("ù��° ���ڴ� %d �Դϴ� \n", value1);

	printf("�ι�° ���ڸ� �Է��ϼ��� \n");
	scanf("%d", &value2);
	printf("�ι�° ���ڴ� %d �Դϴ� \n", value1);

	int sum_value = value1 + value2;
	printf("%d �� %d �� ���� %d �Դϴ� ! \n", value1, value2, sum_value);


	int A = 0;
	int B = 0;

	printf("ù��° ���ڸ� �Է��ϼ��� \n");
	scanf("%d", &A);
	printf("ù��° ���ڴ� %d �Դϴ� \n", A);

	printf("�ι�° ���ڸ� �Է��ϼ��� \n");
	scanf("%d", &B);
	printf("�ι�° ���ڴ� %d �Դϴ� \n", B);

	int Sum_AB = A + B; // ���ϱ�
	printf("A + B = %d \n", Sum_AB);

	int Sub_AB = A - B; // ����
	printf("A - B = %d \n", Sub_AB);

	int Mul_AB = A * B; // ���ϱ�
	printf("A * B = %d \n", Mul_AB);

	int Div_AB = A / B; // ������
	printf("A / B = %d \n", Div_AB);

	int Mod_AB = A % B; // ��ⷯ��
	printf("A % B = %d \n", Mod_AB);

	/* scanf�� ���ڿ� ������ �ޱ�
	5 3 �̷������� �Է��ϸ� ��
	int t1, t2;
	printf("���ڸ� �� �� �Է��Ͻʼ� !");
	scanf("%d%d", &t1, &t2);
	printf("%d, %d", t1, t2);
	*/


	int number = 15;
	// ���� �� ������ ���� else�� ���°� ���̵ǳ� �� ¥�ľ�
	if (number > 6) 
	{
		if (number < 12)
			printf("�� ��° if�� \n");
	}
	else {
		printf("�� ��° if���� ¦�ϱ�? \n");
	}
			

	int delivery_charges = 5000;
	int amount = 0;

	// �� ���űݾ��� �Է¹޾ƿ��Ŷ�~
	printf("���űݾ��� �Է��Ͻÿ�! \n");
	scanf("%d", &amount);
	printf("�� ���űݾ��� %d���̿ýô�! \n", amount);

	// if��
	/*
	if (amount >= 50000)
	{
		delivery_charges = 0;
	}
	else
	{
		delivery_charges = 3000;
	}
	*/


	// ���� ������
	delivery_charges = (amount >= 50000 ) ? 0 : 3000;


	printf("��۷�� %d�� �Դϴ�. \n", delivery_charges);

	


	/*

	// ��, ��, �� �Է��ϼ���
	int Year = 0;
	int Month = 0;
	int Day = 0;

	printf("4���ڷ� �⵵�� �Է��ϼ��� \n");
	scanf("%d", &Year);

	printf("2���ڷ� ���� �Է��ϼ��� \n");
	scanf("%d", &Month);

	printf("2���ڷ� ���� �Է��ϼ��� \n");
	scanf("%d", &Day);

	Day++;

	// 2�� �� ��
	if (Month == 2)
	{
		// 28�� �̸鼭 2���� ��
		if (Day > 27)
		{
			Day = 1;
			Month++;
		}
	}
	//2���� �ƴ� ��
	else if (Month != 2 && Day > 31)
	{
		Day = 1;
		Month++;
	}
	else
		printf("����� �Է��ϼ�\n");

	if (Month == 12)
	{
		Month = 1;
		Year++;
	}

	printf("���� %d�� %d�� %d��", Year, Month, Day);
	*/


	// ��, ��, �� �Է��ϼ���
	int Year = 0;
	int Month = 0;
	int Day = 0;
	int result = 1; // �������� �� ��������� �ʰ� �ϱ� ����

	printf("�⵵�� �Է��ϼ��� ex) 2023 \n");
	scanf("%d", &Year);

	printf("���� �Է��ϼ��� \n");
	scanf("%d", &Month);

	printf("���� �Է��ϼ��� \n");
	scanf("%d", &Day);


	//Month 12�� ����
	if (Month <= 12)
	{
		//2���� ��
		if (Month == 2)
		{
			//28���̶� �Ѿ���� ��
			if (Day == 28)
			{
				Day = 1;
				Month++;
			}
		}
		//4�� 6�� 9�� 11�� �� ��
		else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
		{
			// 30���̶� �Ѿ���� ��
			if (Day == 30)
			{
				Day = 1;
				Month++;
			}
		}
		//12�� �� ��
		else if (Month == 12)
		{
			// �⵵ �ٲٱ�
			if (Day == 31)
			{
				Day = 1;
				Month = 1;
				Year++;
			}
		}
		// ������ �� ( 1, 3, 4, 5, 7, 8, 10 )
		else
		{
			// 31���̶� �Ѿ���� ��
			if (Day == 31)
			{
				Day = 1;
				Month++;
			}
			// 30�� ����
			else if (Day <= 30)
			{
				Day++;
			}
			// ������
			else
			{
				printf("�׷� ��¥ �� �� ��? \n");
				result = 0;
			}
		}
	}
	//13�� �̻�
	else
	{
		//�ƿ�
		printf("%d���� ���� �ƾ�!! \n", Month);
		result = 0;
	}

	// ���
	if (result)
	{
		printf("��� : %d�� %d�� %d��", Year, Month, Day);
	}

	// �ʼ� �׽�Ʈ 
	/*
	2�� 25�� o
	28�� o
	12�� 31�� o
	6�� 30�� o
	31�� o
	10�� 30�� o
	31�� o
	32�� o
	*/







#pragma endregion


	




	return 0;
}