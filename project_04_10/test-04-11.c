#include <stdio.h> // ǥ�� ����� ���̺귯��

// �ٶ���� �¹����� ������ ������ �ִ٤���

/*	
	���ϸ�		: test.c
	parameter	:
	���� ��		:
	made by		������
	���� �ۼ���	:
	���� �ۼ���	:
*/

// ���� 2�� ���ϱ� �Լ�
// ���� main���� �Ʒ��� �־��ٸ� int fn_sum(int v1, int v2);
// �̰� main�����ٰ� ���⸸ �ϸ� �ҷ�����
//int fn_sum(int v1, int v2);





int main()
{
#pragma region 04-10


	printf("Hello C \n");

	int result_main = 0;
	//result_main = fn_sum(5, 10);

	printf("fn_sum�� ����� %d �Դϴ� \n", result_main);



#pragma endregion


#pragma region 04-11


	int a = 2147483647;

	unsigned int b = 4294967295;

	int c = 'b';
	int d = b;
	char e = 'c';

	printf("%d \n", a);
	printf("%u \n", b); // ???
	printf("%d \n", c);
	printf("%d \n", d);
	printf("%c \n", e); // char ������ �̰ڴ�
	printf("%d \n", e); // ���������� �̰ڴ� -> �� ��ȯ



	int aa;
	long bb;
	char cc;

	printf("a=%zd, 5=%zd, c=%zd \n", sizeof(aa), sizeof(bb), sizeof(cc));


	signed int test = -10;
	char bbb = 'test';

	int p_result = 0;
	p_result = printf("test = %d : %u \n", test, test);

	printf("printf�� ���ϰ� : %d \n", p_result);


	/*
	int i = 5;
	int j = 7;
	float f = 3.5f;
	float g = 8.72;

	printf("1. %d \n", i, j);
	printf("2. %d %d %d \n", i);
	printf("3. %d %d \n\n", f, g);
	printf("4. %d %d %f %f \n", i, j, f, g);
	*/


	int i = 100;
	int j = 1000;
	int k = 12345;

	printf("[%d] \n", i);
	printf("[%d] \n", j);
	printf("[%d] \n", k);

	// 5�ڸ� ������ ����
	printf("[%5d] \n", i);
	printf("[%5d] \n", j);
	printf("[%5d] \n", k);

	// 5�ڸ� ���� ����
	printf("[%-5d] \n", i);
	printf("[%-5d] \n", j);
	printf("[%-5d] \n", k);

	


	float f = 3.5f;
	double pi = 3.14159265;
	// �Ҽ��� 1�ڸ������� ǥ���� !
	printf("%.1f \n", f);
	printf("%lfn \n", pi);


	// �Ҽ��� 2�ڸ����� 10�ڸ��� 0���� ä����
	//printf("%010.2lfn \n", pi);

	int Input_Value1 = 0, Chk = 0, Input_Value2 = 0;
	/*
	Chk = scanf("%d \n", &Input_Value);
	_CRT_SECURE_NO_WARNINGS -> ��� ���� ��ó���⿡ �߰�*/

	Chk = scanf("%d%d", &Input_Value1, &Input_Value2);

	printf("�Է¹��� ���� %d��(��) %d �Դϴ�. \n", Input_Value1, Input_Value2);

		// 1.
		printf("���ú��� ���� c ���α׷��� ���� \n");
		printf("���ú��� ���� c ���α׷��� ���� \n");


		// 2.
		int age = 0;

		printf("����� ���̴� ?");
		scanf("%d", &age);
		printf("����� %d ���̱���. \n", age);


		// 3.
		printf("\\    /\\  \n");
		printf(" )  ( ')  \n");
		printf("(  /  )   \n");
		printf(" \\(__)L   \n");


		// 4.
		// ���ͷ� ����� �Ҽ��� �⺻(default) double�� ����ϱ� ������ f�� �ٿ��� ��
		float cost = 12.99f;
		float percent = 80.0f;
		printf("�Ű� \"������ ������\"�� $%.2f�� �帳�ϴ�. \n", cost);
		printf("�װ��� ������ %.f%% �����Դϴ�.\n", percent);


		// 5. �̸���û -> �Է¹ް� -> �ٽ� �� ��û -> ��, �̸� ������ ���
		// 5�� �̹� Ǯ����� �׳� �����Կ� -> �׷������� -> ����
		char LastName[20];
		char FirstName[20];
		printf("�̸��� �Է����ּ��� \n");
		scanf("%s", &FirstName);
		printf("���� �Է����ּ��� \n");
		scanf("%s", &LastName);
		printf("��:%s �̸�: %s �̽ó׿� \n", LastName, FirstName);


		// 6. 
		char Name[20];

		printf("�̸��� �Է����ּ��� ! \n");
		scanf("%s", &Name);

		// 6-1�� �̸� " "�� ���α�
		printf(" \"%s\" \n", Name);

		// 6-2�� �ʵ���ü�� ū ����ǥ�� ���α�
		printf(" \"%20s\" \n", Name);

		// 6-3 �� ���� ����
		printf(" \"%-20s\" \n", Name);


		// 7���� ���϶�°��� �𸣰ڴ�
		float speed = 0;
		float FileSize = 0;

		printf("�ӵ��� �ʴ� �� �ް�����Ʈ��(MB)����? \n");
		scanf("%f", &speed);

		printf("���� ũ��� �� �ް�����Ʈ(MB)�ΰ���? \n");
		scanf("%f", &FileSize);

		float time = FileSize / speed;

		printf("�ӵ�: %.2f \n ����ũ��: %.2f \n �ٿ�ε� �ӵ�: %.2f \n", speed, FileSize, time);

#pragma endregion





	return 0;
}





int fn_sum1(int v1, int v2)
{
	int result = 0;		// Declare

	result = v1 + v2;	// Assignment : ������ �Ҵ�(����)
	return result;
}