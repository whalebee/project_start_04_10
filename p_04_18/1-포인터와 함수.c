#include <stdio.h>

#pragma region �����Ϳ� �Լ�
void fn_test(int);
void TEST(short);
int fn_testt(int);
#pragma endregion


#pragma region �Լ���� ����
// �Ű������� �������� ��� ���� �Լ� fn_1()
void fn_1();

// �Ű����� O , ������ X			fn_2()
void fn_2(int a, int b);

// �Ű����� X , ������ O			fn_3()
int fn_3();

// �Ű����� O , ������ O			fn_4()
int fn_4(int a, int b);




#pragma endregion


int main()
{


#pragma region �����Ϳ� �Լ�

	short birthday = 1018; // short��(2byte) birthday��� ������ 1018�� �ʱ�ȭ

	short* ptr = &birthday;
	// ������ ���� ptr ����. ptr�� ����Ű�� �ּҴ� short�� �ڷᰡ �ִ�.
	//birthday�� �ּҸ� ����

	printf("birthday�� : %hi \n", birthday);
	printf("birthday������ �ּҴ� : %p \n", &birthday);
	puts("");
	printf("	ptr : %p \n", ptr);
	printf("	&ptr: %p \n", &ptr);
	printf("	*ptr: %hi \n", *ptr);


	// ���� �����͸� ����Ͽ�  �� ����
	*ptr = 1130;
	printf("updated birthday�� : %hi \n", birthday);


	// �����Ϳ� �Լ� ���
	int value = 0;
	int* ptr_value = &value;

	fn_test(&value);

	printf("%d \n", value);


	short tips = 5;
	TEST(&tips);
	printf("%d \n", tips);

	value = fn_testt(value);
	printf("%d \n", value);
	// �����͸� ���� �ʰ� �Ϸ���
	// ���� �Լ��� �ڷ����� �ٲ������ void��� return �� �� ���״ϱ�
	// �׸��� �Լ��� ���� ���� ������ �������ְ�
	// �� ������ ���



#pragma endregion


#pragma region �Լ���� ����
	// fn_3 ���
	int value = fn_3();
	if (value == -1)
	{
		printf("�Է� ���� \n");
	}
	else
	{
		printf("%d \n", value);
		// printf("%d \n", fn_3()); �̰͵� ������ ��
	}


	// fn_4 ���
	int v_4 = fn_4(50, 100);
	printf("%d \n", v_4);



#pragma endregion


#pragma region ���� 1��

	// 1��
	// void ���ž��� int�� ���� �ȵ���
	void donut(int);

	int main()
	{
		int count_donut = 0;
		printf("�ʿ��� ������ �� ��ŭ �Է��ϼ��� \n");
		scanf("%d", &count_donut);
		donut(count_donut);



		return 0;
	}

	int donut(int a)
	{
		for (int i = 0; i < a; i++)
		{
			printf("O");
		}
	}





#pragma endregion


#pragma region 2��

	// 2�� �� ���� int�� ���� ���ڸ� ����ϸ�, int���� ���� �Ѵ�.
	// ���� : �ƹ� �����̳� ������� int������ ��ȯ�ϸ� ��
	int gear(int, int);

	int main()
	{
		int v1 = 0, v2 = 0, result;
		printf("����ϰ� ���� ���� 2�� �Է� \n");
		scanf("%d %d", &v1, &v2);
		printf("ù��° �Ű����� : %d \n�ι�° �Ű����� : %d \n%d + %d = ", v1, v2, v1, v2);
		result = gear(v1, v2);
		printf("%d \n", result);


		return 0;
	}

	int gear(int a, int b)
	{
		return a + b;
	}



#pragma endregion


#pragma region 3��

	// 3�� guess �Լ��� ���� ���� ���� int������ ���� �Ѵ�.
	// ���� : �ƹ� �����̳� ������� int������ ��ȯ�ϸ� ��
	int guess();

	int main()
	{
		printf("%d", guess());

		return 0;
	}

	int guess()
	{
		int a = 0, b = 0, chk = 0;
		chk = scanf("%d %d", &a, &b);

		if (chk != 2)
		{
			printf("�Է��� �߸��Ͻ� �� \n");
		}

		return a + b;
	}


#pragma endregion


#pragma region 4�� 
	// 4�� �ϳ��� double���� double�� ������ �ּҸ� ���� ���ڷ� ����Ͽ�,
	// ù ��° ���� �� ��ġ�� ����
	// �ؼ�: ù��° ���� ù��° ������ �ּҰ��� �̿��Ͽ� ù��° ������ ����� ���� ����
	// �� ������ ���� �������ϱ� �������� �ϸ� �ȵǳ�������
	// ���ʿ� ���� �������� �ᵵ ���� ��������
	void stuff_id(double, double*);

	int main()
	{
		// ���� ����
		double d_v = 5.5;
		stuff_id(d_v, &d_v);
		printf("%lf", d_v);

		return 0;
	}

	void stuff_id(double a, double* ptr_b)
	{
		*ptr_b = a + 10;
		// printf("%lf \n", cal);
		// return cal;
	}


#pragma endregion


#pragma region 5��

	// 5�� �ϳ��� int�� ���� ���ڸ� ����ϸ�, char���� �����Ѵ�.
	// int�� ���� ������ char ������ ��ȯ�� �Ǿ�� ��
	// ex) 97 -> a
	char n_to_char(int);


	int main()
	{
		int value = 0;

		scanf("%d", &value);
		// printf("value���� : %d", value);
		// value = 97;

		char result = n_to_char(value);
		printf("%c \n", result);



		return 0;
	}

	char n_to_char(int a)
	{
		char convert = (char)a;
		return convert;
	}


#pragma endregion


#pragma region 6��
	// 6�� �ϳ��� double�� ���� ���ڿ� �ϳ��� int�� ���� ���ڸ� ����ϸ�, int�� ����
	// ex) 5.5151 + 15 = int������ 20���;ߵ�

	int digits(double, int);

	int main()
	{
		double d_v1 = 0;
		int i_v2 = 0, result = 0;

		scanf("%lf %d", &d_v1, &i_v2);

		result = digits(d_v1, i_v2);
		printf("%d \n", result);

		return 0;
	}

	int digits(double d_a, int i_b)
	{
		int result = 0;
		result = (int)d_a + i_b;

		return result;
	}



#pragma endregion


#pragma region 7���н� 8��
	// 8�� �������� ���� int�� ���� 

	int main()
	{
		printf("%d \n", random());

		return 0;
	}


	int random()
	{
		int a = 0, b = 0;
		scanf("%u %u", &a, &b);

		return a + b;
	}



#pragma endregion


#pragma region 9��
	// 9�� add�Լ��� �� ������ �Է� �޾�, �� ������ ���� int������ ����
	int add(int, int);
	int add_2();

	int main()
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		printf("%d \n", add(a, b));

		// �Ǵ�
		/*
		int result = 0;
		result = add_2();
		printf("%d \n", result);
		*/

		return 0;
	}

	int add(int a, int b)
	{
		return a + b;
	}

	int add_2()
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		return a + b;
	}



#pragma endregion


#pragma region 10��
	void salami(int num)
	{
		int count = 0;
		for (count = 1; count <= num; count++)
		{
			printf(" 0 salami mio ! \n");
		}
	}
	�Ű������� �޾��� �� �ڷ����� ��� ������ϴ�
		num�� 2�� ���ǵǾ ������ϴ�
		num++ �� �Ǿ������� ���ѷ����� ������ count�� �����߽��ϴ�


#pragma endregion


#pragma region const����
	int v1 = 0;
	int v2 = 0;

	const int* ptr = &v1; //����
	// int* const ptr = &v1; // �Ұ���
	// ���� �� ���ٿ� �������� ����

	printf("v1�� ���� : %d \n", v1);
	printf("ptr�� ���� : %d \n", *ptr);

	ptr = &v2;


	v1 += 10;
	printf("�ٲ� v1�� ���� : %d \n", v1);
	printf("�ٲ� ptr�� ���� : %d \n", *ptr);


#pragma endregion






	return 0;
}


#pragma region �����Ϳ� �Լ�
void fn_test(int* value)
{
	*value += 5;

}

int fn_testt(int value)
{
	value += 5;
	return value;
}

void TEST(short* ptr)
{
	*ptr = 3;
}


#pragma endregion


#pragma region �Լ���� ����
void fn_1()
{
	int value = 5;
	value += 10;

	printf("������ �Է��ϼ���.");
	scanf("%d", &value);


	printf("fn_1�Դϴ�. �Է¹��� ���ڴ� %d�Դϴ�. \n", value);
}

void fn_2(int a, int b)
{
	int result = 0;
	result = a + b;
	if (result > 100)
	{
		return; // ��� ���ϰ� ��� ���� break�� �����
	}
	printf("�Ű������� ���޹��� a:%d�� b:%d�� ���� %d�Դϴ�. \n", a, b, result);
}


int fn_3()
{
	printf("fn_3 start \n");
	unsigned int a = 0, b = 0, chk = 0;
	chk = scanf("%u %u", &a, &b);

	if (chk != 2)
	{
		return -1;
	}

	printf("fn_3 end \n");
	return a + b;
}

int fn_4(int a, int b)
{
	printf("�Է¹��� �Ű������� a:%d, b:%d \n", a, b);
	printf("%d + %d = ", a, b);
	return a + b;
}


#pragma endregion
