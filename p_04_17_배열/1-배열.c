#include <stdio.h>
#define MONTHS 12

int main()
{

#pragma region �ε��� �⺻ ����

	// �ε���
	int max = 3;

	int array[5] = { 1, 2, 3, 4, 5 };

	for (int index = 0; index < 5; index++)
	{
		printf("%d \n", array[index]);
	}
	printf("max�� ���� array�� : %d \n", array[max]);


	int day[MONTHS] = { 31,28, 31, 30, 31, 30, 31,31,30,31,30,31 };


	for (int index = 0; index < MONTHS; index++)
	{
		printf("%d���� �� ���� %d \n", index + 1, day[index]);
	}

#pragma endregion


#pragma region ���� �� ��� �迭 ���

	int max_days[MONTHS] = { 31,28, 31, 30, 31, 30, 31,31,30,31,30,31 };
	int yy = 0, mm = 0, dd = 0, chk = 0;

	printf("enter yy mm dd \n");
	chk = scanf("%d %d %d", &yy, &mm, &dd);

	if (chk != 3 || yy <= 0 || mm < 1 || mm > 12 || dd > max_days[mm - 1]
		|| dd < 1)
	{
		printf("����");
		return 1;
	}

	printf("�Է��� ���� %d�� %d�� %d�� \n", yy, mm, dd);

	dd++;
	if (dd > max_days[mm - 1])
	{
		dd = 1;
		mm++;
		if (mm > 12)
		{
			mm = 1;
			yy++;
		}
	}
	printf("�Է��� ��¥�� ���� ��¥�� %d�� %d�� %d�� \n", yy, mm, dd);




#pragma endregion


#pragma region ���ڿ�

	//string

	char string1[6] = { 'H', 'e', 'l', 'l', 'o', 0 };			//�� 
	char string2[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };			//�� 
	char string3[] = { 'H', 'e', 'l', 'l', 'o', (char)NULL };	//�� 
	char string4[6] = "Hello";	// ��-��
	char string5[] = "Hello";	// �˾Ƽ� �� ���� NULL���ڸ� ����
	// char string6[]; �̰� �ȵ� ���̸� �����ְų� ���ڿ��� �־���ߵ�

	/*
	printf("%s \n", string1);
	printf("%s \n", string2);
	printf("%s \n", string3);
	printf("%s \n", string4);
	printf("%s \n", string5);
	*/

	char practice[10];
	strcpy(practice, "hello");
	practice[5] = '!'; // NULL �ڸ��� !�̰ɷ� �ٲ�����ϱ� �̻��ϰ� ��µ�
	printf("%s", practice);

#pragma endregion


#pragma region puts

	// puts �Լ�

	char input[50] = { 0, };
	int chk = 0;
	puts("���ڸ� �Է��ϼ���. (�ִ� 9����)");

	chk = scanf("%s", input);

	// scanf�� �ּҸ� �Ű������� �����ؾ��ϴµ�
	// �迭�� �̸��� �迭�� ù��° �ּҸ� ����
	// &input[0] == input
	// ���� �Է´����� �������� ��
	// hello hi �Է��ϸ� puts������ hello�� ���´ٴ� ��

	puts(input);


	fgets(input, 50, stdin);
	puts(input);



#pragma endregion


#pragma region while������ �ε��� ������ �˾ƺ���
	
	char string[] = "Hello";
	int index = 0;

	while(string[index] != '\0')
	{
		index++;
	} // ����� 5
	printf("1. %d", index);

	index = 0;
	while (string[index++] != '\0')
	{
		index++;
	} // ����� 6
	// ���� �� �񱳸� �ϰ� ���� while���� ���� �ʰ� ��µǱ⶧��

	printf("2. %d", index);




#pragma endregion


#pragma region ������ �˾ƺ���
	// ������ �˾ƺ���
	char string[] = "Hello";
	int arr_int[6];

	// printf("%u \n", strlen(string));

	// printf("%u \n", sizeof(string));
	// printf("%u \n", sizeof(arr_int)); // int x [6] -> 24����Ʈ

	// printf("%u", sizeof(arr_int) / sizeof(int)); // �̷��� ������ ���̰� ����


#pragma endregion
	


#pragma region ���ڿ� ���̱�

	// ���ڿ� ���̱�

	char str1[15] = "Hello";
	char str2[] = "World";

	strcat(str1, str2);
	printf("%s", str1);

#pragma endregion


#pragma region ���ڿ� ��
	// ���ڿ� ��
	char str1[15] = "Hello";
	char str2[] = "World";

	// strcat(str1, str2);

	printf("%d", strcmp(str1, "Hello"));

	if (!strcmp(str1, "Hello"))
	{
		printf("����");
	}


#pragma endregion


#pragma region 3��

#define VALUE 10

	int main()
	{
		int arr1[VALUE] = { 1,2,3,4,55,6,7,8,9,10 };
		int max_arr1 = arr1[0];

		for (int i = 0; i < VALUE; i++)
		{
			printf("�ε����� %d��° ���� : %d \n", i, arr1[i]);

			if (arr1[i] > max_arr1)
			{
				max_arr1 = arr1[i];
			}
		}
		printf("�ε����� �� ���� ū ���� %d \n", max_arr1);
		
		return 0;
	}

#pragma endregion


#pragma region 4��

	double arr1[VALUE] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10 };
	double max_arr1 = arr1[0];
	int max_index = 0; // �ε��� �� ���� ���� �߰�

	for (int i = 0; i < VALUE; i++)
	{
		// printf("�ε����� %d��° ���� : %.2lf \n", i, arr1[i]);

		if (arr1[i] > max_arr1)
		{
			max_arr1 = arr1[i];
			max_index = i;
		}
	}
	// printf("���� ū ���� %.2lf \n", max_arr1);
	printf("���� ū ���� ������ �ε����� %d \n", max_index);



#pragma endregion


#pragma region 5��
	double arr1[VALUE] = { 1.1,2.2,3.3,4.4,5.5,6.6,76.7,8.8,9.9,55.10 };
	double max_arr1 = arr1[0];
	double min_arr1 = arr1[0]; // �ּҰ��� ���� ���� �߰�


	for (int i = 0; i < VALUE; i++)
	{
		// printf("�ε����� %d��° ���� : %.2lf \n", i, arr1[i]);

		if (arr1[i] > max_arr1)
		{
			max_arr1 = arr1[i];

		}
		else if (arr1[i] < min_arr1) // if�� else if������ ���ÿ� �����ϴ� ���� �����ϱ� else if���� ��
		{
			min_arr1 = arr1[i];
		}

	}
	// printf("���� ū ���� %.2lf \n", max_arr1);
	// printf("���� ���� ���� %.2lf \n", min_arr1);

	printf("%.2lf - %.2lf = %.2lf", max_arr1, min_arr1, max_arr1 - min_arr1);


#pragma endregion


#pragma region 6��
	int arr1[VALUE] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[VALUE] = { 31,32,33,34,35,36,37,38,39,40 };

	int add_arr[VALUE] = { 0, };


	for (int i = 0; i < VALUE; i++)
	{
		add_arr[i] = arr1[i] + arr2[i];
		printf("%d + %d = %d \n", arr1[i], arr2[i], add_arr[i]);

	}

	for (int i = 0; i < VALUE; i++)
	{
		printf("%d ", add_arr[i]);
	}


#pragma endregion


#pragma region 8��
	char say[] = "hi";
	char s_a_y[] = { 'h', 'i', '\0' };
	char say_null[] = { 'h', 'i', (char)NULL };
	char say_zero[] = { 'h', 'i', 0 };

	printf("%s \n", say);
	printf("%s \n", s_a_y);
	printf("%s \n", say_null);
	printf("%s \n", say_zero);


#pragma endregion


#pragma region 9��
	int arr1[] = { 3, 29, 38, 12, 57, 74, 40, 85, 61 };

	int max_arr1 = arr1[0];
	int index_arr1 = 0;

	// �迭 ������ Ȯ��
	int arr_size = sizeof(arr1) / sizeof(int);
	// printf("�迭�� ������� %u \n", sizeof(arr1)/sizeof(int));

	for (int i = 0; i < arr_size; i++)
	{
		if (arr1[i] > max_arr1)
		{
			max_arr1 = arr1[i];
			index_arr1 = i + 1;
		}
	}

	printf("�ִ밪�� %d, �ִ밪�� ��ġ�� %d��° �Դϴ�. \n", max_arr1, index_arr1);


#pragma endregion


#pragma region 10��
	char str1[20] = "kakao";
	char str2[] = "talk";
	strcat(str1, str2);

	printf("%s", str1);



#pragma endregion





















	return 0;
}




