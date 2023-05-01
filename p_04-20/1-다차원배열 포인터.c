#include <stdio.h>
#include <string.h>

#define VALUE 10


int main()
{
#pragma region ����
	short data[9] = { 4, 6, 9, 8, 7, 2, 5, 1, 3 };

	// 1��
	int sum = 0, size = 0, temp = 0;

	// printf("%d \n", sizeof(data) / sizeof(short));
	size = sizeof(data) / sizeof(short);

	for (int i = 1; i < size; i += 2)
	{
		printf("%d \n", data[i]);
		sum += data[i];
	}
	printf("%d \n", sum);

	// 2��
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8 - i; j++) {
			if (data[j] > data[j + 1]) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	
	// 2�� ������ ��
	int size = sizeof(data) / sizeof(data[0]);

	short temp = 0;

	for (int index_a = 0; index_a < size; index_a++)
	{
		for (int index_b = index_a + 1; index_b < size; index_b++)
		{
			if (data[index_a] > data[index_b])
			{
				temp = data[index_a];
				data[index_a] = data[index_b];
				data[index_b] = temp;
			}
		}
	}

	// ���
	for (int i = 0; i < 9; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");



	// 3��
	// 5�� 3��° �� ù��° ���̳׿�
	short data_2[3][3] = {
		{4, 6, 9}
		,{8,7,2}
		,{5,1,3}
	};

	// 3�� �ٸ� ���
	short data[9] = { 4, 6, 9, 8, 7, 2, 5, 1, 3 };
	short data_after[3][3] = { 0 };
	int max_row = 3, max_col = 3, row = 0, col = 0;
	int size = sizeof(data) / sizeof(short);


	for (int i = 0; i < 9; i++) {
		if (col == max_col) col = 0, row++;
		data_after[row][col++] = data[i];
	}

	int index = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			data_after[i][j] = data[index++];
			if (data_after[i][j] == 5) {
				printf("2�����迭�� ���� �� 5�� after[%d][%d] �Դϴ�.", i, j);
			}

		}
	}

	// ����1-3-2 feat.�μ�
	/*
	short after[3][3];
	// 2���� �迭�� �����ؼ� ����
	for (int i = 0; i < 9; i++)
	{
		after[i / 3][i % 3] = data[i];
	}

	// ���
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", after[i][j]);
		}
		printf("\n");
	}*/


	// 4��
	int arr[4][4];
	int row_max = 4, col_max = 4;
	int value = 1;
	for (int row = 0; row < row_max; row++)
	{
		for (int col = 0; col < col_max; col++)
		{
			arr[row][col] = value++;
			printf("%d \n", arr[row][col]);
		}
	}


	// 5�� ���� ��

	int arr[4][4];
	int row_max = 4, col_max = 4, row = 0, col = 0;
	int value = 1;

	/*
	for (int row = 0; row < row_max; row++)
	{
		for (int col = 0; col < col_max; col++)
		{
			arr[row][col] = value++;
			printf("%3d ", arr[row][col]);
		}
		puts(" ");
	}
	*/

	// 5�� ���� ��

	for (row = 0; row < row_max; row++)
	{
		for (col = 0; col < col_max; col++)
		{
			arr[row][col] = value++;
		}

	}


	for (row = 0; row < 4; row++) {
		for (col = 0; col < 4; col++) {
			printf("%2d ", arr[col][row]);
		}
		printf("\n");
	}

#pragma endregion


#pragma region ����

	// 1��
	// 4����Ʈ

	// 2��
	// int������ ������ ���� data�� �� 0x12345678�� ����Ǿ� �ֽ��ϴ�.
	// data������ ���� ���� �������� �ʰ� short* �� �����͸� �����Ͽ�
	// data������ ���� 0x12340412�� �����ϴ� �ڵ带 �ۼ��ϼ���
	int data = 0x12345678;

	printf("data : %x \n", data);

	short* ptr_data = (short*)&data;
	printf("short�� data : %x \n", *ptr_data);
	*(ptr_data) = 0x0412;
	printf("�ٲ� short�� data : %x \n", *ptr_data);

	//2�� Ȯ�� 0x12340412 �� �ٲٴ� ��
	printf("�ٲ� ��� : %x \n", data);

	// 2-1�� 0x78340412 �� �ٲٴ� ��
	char* c_ptr_data = (char*)&data;
	printf("char�� data : %x \n", *c_ptr_data);
	*(c_ptr_data + 3) = 0x78;
	printf("�ٲ� char�� data : %x \n", *c_ptr_data);

	//2-1�� Ȯ�� 0x78340412 �� �ٲٴ� ��
	printf("�ٲ� ��� : %x \n", data);



	// 3��
	void swap(int* num1, int* num2)
	{
		int temp;
		temp = *num1;
		*num1 = *num2;
		*num2 = temp;
	}

	int a = 100, b = 200;
	swap(&a, &b);
	printf("%d %d \n", a, b); // 200 100


	// 4��
	// int���̶� int���� ũ�⸸ŭ ���� �ּҺ��� �д´�
	// �ƹ��� ���� ���� p++; �ϸ� ������ ���̳� �ٸ� �������� ���� ����������
	// ���� ��� �������� int������ 1 ~ 1000�����ְ� ������ ���� 1�� �����Ѵٴ� �����Ͽ�,
	// ������ ������ ���� �ּҷ� �Ѿ�� �Ǹ�
	// 201������ ���� �� �����ϴ�.


	// 5��
	char a = 0x12, b = 0x34;
	short c = 0x5678;

	char* ptr_a = &a;
	char* ptr_b = &b;
	short* ptr_c = &c;

	int t = 0x87654321;
	int* ptr_t = &t;
	char* ptr_ch_t = (char*)&t;
	short* ptr_sh_t = (short*)&t;

	// printf("���� %x \n", *(ptr_ch_t+3));
	*(ptr_ch_t + 3) = *ptr_a;
	// printf("�ٲ� ���� %x \n", *(ptr_ch_t + 3));

	*(ptr_ch_t + 2) = *ptr_b;
	// printf("�ٲ� ���� %x \n", *(ptr_ch_t + 2));

	// printf("��� ��Ÿ���� %x \n", *ptr_sh_t);
	*ptr_sh_t = *ptr_c;

	// ���
	printf("���ο� ���� t�� ���� %x \n", *ptr_t);


	
#pragma endregion 
	

#pragma region �迭 �����ͷ� ǥ�� ���
	int array[5] = { 1,2,3,4,5 };
	int size = sizeof(array) / sizeof(int);
	int* ptr = array;


	for (int i = 0; i < size; i++)
	{
		printf("%d %d \n", array[i], *(ptr + i));
		printf("%d %d \n", ptr[i], *(array + i)); // �̷��� �ᵵ ��
		//	printf("%d %d \n", *(array++), *(ptr++));
	}


#pragma endregion


#pragma region ���� 1��
	// ���� 1��
	int array[5] = { 1,2,3,4,5 };
	int size = sizeof(array) / sizeof(int);
	int* ptr = array;

	int v1 = 10;
	/*
	*(ptr) = 10;
	*(ptr + 1) = 20;
	*(ptr + 2) = 30;
	for (int i = 0; i < size; i++)
	{
		printf("%d \n", array[i]);
	}
	*/

	for (int i = 0; i < size; i++)
	{
		*(ptr + i) = v1 * (i + 1);
		printf("%d��° �� %d \n", i + 1, *(ptr + i));
	}

	printf("array �迭�� : ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}


#pragma endregion


#pragma region �迭�� �Լ����� �� �� ������ ������ ���δٴ� ����
	void fn_arr(int arr[]);


	int main()
	{

		int arr[5] = { 1,2,3,4,5 };
		printf("main : %d \n", sizeof(arr)); // ���� 20byte
		fn_arr(arr); // �迭�� �̸��� �迭�� ���� �ּ�

		for (int i = 0; i < 5; i++)
		{
			printf("��� : %d \n", arr[i]);
		}

		return 0;
	}

	// �迭�� �̸��� �Ű������� ���� ������ ������ ����
	// �� �����̳� ������ ���� ���������ڸ� ���� �ʾƵ� ���� �ٲ�
	// int* arr = &arr[0] �̷��� ���°���
	void fn_arr(int arr[])
	{
		printf("fn_arr : %d \n", sizeof(arr)); // ���� 4byte�� ����
		for (int i = 0; i < 5; i++)
		{
			// printf("%d", arr[i]);
			arr[i] *= 10;
		}
	}



#pragma endregion


#pragma region �迭�� �Լ� ���� 3��
	/// fn_arr1 : �������� ǥ�����·� arr_int ���
// fn_arr2 : �迭�� ǥ�����·� arr_int ���
// fn_arr3 : fn_arr3�� main�Լ��� arr_int�� �����Ͽ� fn_arr3���� �迭�� ������ ���Ͽ� main���� ���

	void fn_arr1(int*, int);		// �迭���� fn_arr1�� fn_arr2�� ���� ��
	void fn_arr2(int[], int);		// �迭���� fn_arr1�� fn_arr2�� ���� ��
	void fn_arr3(int*, int*, int);

	int main()
	{



		// �迭�� �Լ��� �� ���� ������ ������ ������ ���� �ȴ�.
		// �Լ��� �Ѱ��� �� ��縸 �迭��
		int arr_int[5] = { 1,2,3,4,5 };

		int* ptr_arr = arr_int;

		//			���� ���� ����
		// arr_int[0]	-> *(arr_int + 0)  
		// arr_int[1]	-> *(arr_int + 1)
		// arr_int[2]	-> *(arr_int + 2)
		// arr_int[3]	-> *(arr_int + 3)
		// arr_int[4]	-> *(arr_int + 4)

		int size = sizeof(arr_int) / sizeof(arr_int[0]);
		printf("%d \n", size);
		// �Լ� �ȿ��� arr_int�� ���̸� �� �� ���� ������
		// ���� �Ű������� ���� ��

		fn_arr1(arr_int, size);

		puts(" ");
		puts(" ");

		fn_arr2(arr_int, size);


		puts(" ");
		puts(" ");
		int sum_main = 0;

		fn_arr3(arr_int, &sum_main, size);
		printf("main������ ������ %d", sum_main);

		/*
		�ּҰ� ���� ������ ����� ����

		int arr[3]

		arr�� 0x01, 0x05, 0x09 ���� ����

		arr -> 0x01
		&arr -> 0x01
		---------------
		arr+1 -> 0x05
		&arr+1 -> 0x0D

		*/



		return 0;
	}

	void fn_arr1(int* arr, int size)
	{
		//int size = sizeof(arr);
		//printf("size in fn_arr1 : %d \n", size);
		// �������� ǥ�����·� arr_int ���
		for (int i = 0; i < size; i++)
		{
			printf("fn_arr1 ���� arr_int[%d] : %d \n", i, *(arr + i));
		}
	}

	void fn_arr2(int arr[], int size)
	{
		//int size = sizeof(arr);
		//printf("size in fn_arr2 : %d \n", size);
		// �迭�� ǥ�����·� arr_int ���
		for (int i = 0; i < size; i++)
		{
			arr[i];
			printf("fn_arr2 ���� arr_int[%d] : %d \n", i, arr[i]);
		}
	}

	void fn_arr3(int* arr, int* sum, int size)
	{
		// int size = sizeof(arr);
		//printf("size in fn_arr3 : %d \n", size);

		for (int i = 0; i < size; i++)
		{
			*sum += arr[i];			// �迭 ��
			// *sum = +*(arr + i);	//��������
			// printf("���ϴ� �� : %d \n", sum);
		}
	}


#pragma endregion


#pragma region �迭�� �Լ� ���� �ٸ� �� ��������� �𸣰γפ���
	void fn_arr(int*, int*);

	int main()
	{
		int arr[5] = { 1,2,3,4,5 };

		printf("%p \n", arr);
		printf("%p \n", arr + 1);
		printf("%p \n", &arr + 1);

		fn_arr(arr, &arr + 1);
		// &arr+1 -> arr �迭�� �� �ּ�



		return 0;
	}

	void fn_arr(int* start, int* end)
	{
		while (start < end)
		{
			printf("%d ", *(start++));
		}
	}



#pragma endregion


#pragma region ������ ������ ���ͷ� ���
	char arr_char[12] = "Hello Wolrd";
	char arr_char2[] = "Hello Wolrd";
	char* ptr_char = "Hello World";

	printf("%p %p %p \n", arr_char, arr_char2, ptr_char);
	printf("%s %s %s \n", arr_char, arr_char2, ptr_char);

	// ptr_char ��� ���ͷ� ����� ������ �Ǵ� �޸� ������ �ֱ� ������
	// �ּҰ� �� ȥ�� �ָ� ����


	arr_char[0] = 'A';
	printf("%s", arr_char);


	//strcpy(arr_char, "Hi World");
	//printf("strcpy : %s", arr_char);


	strcpy(arr_char, "Hi World");
	printf("strcpy : %s\n", arr_char);
	ptr_char = "Hi";
	printf(" %p \n", ptr_char);



#pragma endregion


#pragma region �迭�� �ٸ� ���� ����� �Լ�
	void fn_1(int[], int);
	void fn_2(int* start, int* end);

	int main()
	{
		int arr1[3] = { 1,2,3 };
		int arr2[] = { 4,5,6 };
		int arr1_size = sizeof(arr1) / sizeof(arr1[0]);

		fn_1(arr1, arr1_size);
		fn_2(arr2, &arr2 + 1);

		return 0;
	}

	// arr1 �迭ǥ���, ������ ���� �޾Ƽ� arr1 ��ü ���
	void fn_1(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			printf("%d", arr[i]);
		}
	}

	void fn_2(int* start, int* end)
	{
		while (start < end)
		{
			printf("%d ", *(start++));
		}
	}



#pragma endregion


#pragma region 2���� �迭�� ������ ���� �����ϰ� ���
	int main()
	{
		char arr[2][3] = { 'a', 'b', 'c', 'd', 'e', 'f' };

		char* ptr1[3];
		char* ptr2 = arr;

		char(*ptr)[3] = arr; // 2���� �迭�� ������ ����
		//	ptr +1  -> ptr[1][1] �׷��� �̰� ��������
		printf("%d %d", sizeof(ptr), sizeof(ptr1));

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%c ", ptr[i][j]); // �̷��� ���°� �����ϴٴ� ��
				// printf("%c ", (*(ptr+i))[j]); //�̰͵� �������ѵ� �˾Ƹ��� ������ ��������
			}
		}


		return 0;
	}


#pragma endregion


#pragma region 2���� �迭 �Լ� ���
	// 2���� �迭�� �� ������, �� ������ �̷��� 2�� �ʿ���
// �迭 ǥ�� ����� �Լ� ����
	void fn_arr(char[][3], int, int);

	// ������ ǥ�� ����� �Լ� ����
	void fn_arr1(char(*)[3], int, int);

	// �Ϳ�
	void fn_arr2(void*, int, int);

	int main()
	{
		char arr[2][3] = { 'a', 'b', 'c', 'd', 'e', 'f' };

		char* ptr1[3];
		char* ptr2 = arr;

		char(*ptr)[3] = arr; // 2���� �迭�� ������ ����
		//	ptr +1  -> ptr[1][1] �׷��� �̰� ��������

		// fn_arr(arr, 2, 3);
		// fn_arr1(arr, 2, 3);
		fn_arr2(arr, 2, 3);

		return 0;
	}


	void fn_arr(char arr[][3], int row_len, int col_len)
	{
		for (int row = 0; row < row_len; row++)
		{
			for (int col = 0; col < col_len; col++)
			{
				printf("%c ", arr[row][col]);
			}
			puts(" ");
		}
	}

	void fn_arr1(char(*arr)[3], int row_len, int col_len)
	{
		for (int row = 0; row < row_len; row++)
		{
			for (int col = 0; col < col_len; col++)
			{
				// 2���� �迭�� ������ ǥ��� ��� ���Ĺ��� ( ���� �� �ʿ���� )
				printf("%c ", (*(arr + row))[col]);
			}
			puts(" ");
		}
	}


	void fn_arr2(void* arr, int row_len, int col_len)
	{
		int(*arr_int)[3] = arr;

		for (int row = 0; row < row_len; row++)
		{
			for (int col = 0; col < col_len; col++)
			{
				printf("%c ", arr_int[row][col]);
			}
			puts(" ");
		}
	}


#pragma endregion


#pragma region ���ڿ� ������ �Լ� ���
	void fn_string(char[]);

	int main()
	{
		char string1[] = "Hello";

		fn_string(string1);



		return 0;
	}

	// �迭�� �޾����� char�� �����ͷ� ���� ��
	void fn_string(char string1[])
	{
		printf("%s \n", string1);


		// %c�� �̱� 
		int idx = 0;
		while (string1[idx] != (char)NULL) //NULL�� 0 ���� �ᵵ �ǰ� '\0' ���� �ᵵ ��
		{
			printf("%c", string1[idx++]);
		}
	}


#pragma endregion


#pragma region ���� ���� 1~ 2��
	// ���� 1��
	int arr[3][4] = {
	{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12}
	};

	int row_len = sizeof(arr) / sizeof(arr[0]);
	int col_len = sizeof(arr[0]) / sizeof(arr[0][0]);
	printf("%d \n", col_len);
	printf("%d \n", row_len);

	int(*ptr)[4] = &arr;

	for (int i = 0; i < row_len; i++)
	{
		for (int j = 0; j < col_len; j++)
		{
			printf("%3d ", ptr[i][j]);
			// printf("%3d ", (*(ptr+i))[j]);  // ������ ǥ���
		}
		puts(" ");
	}

	puts(" ");
	puts(" ");
	// 2��
	int* ptr_arr = &arr;
	printf("%d\n", ptr[2][1]);
	// printf("%d\n", (*(ptr+2))[1]);



#pragma endregion


#pragma region ���� 3�� ��� �Լ�����̿�������
	int main()
	{




		// 3��
		int salary[2][5] = {
			{200,300,400,500,600},
			{30,60,90,120,150}
		};

		int(*amount)[5] = &salary;
		int total[5];

		int row_len = sizeof(salary) / sizeof(salary[0]);
		int col_len = sizeof(salary[0]) / sizeof(salary[0][0]);

		/*
		for (int i = 0; i < row_len; i++)
		{
			for (int j = 0; j < col_len; j++)
			{
				printf("%d ", amount[i][j]);
			}
			puts(" ");
		}
		*/



		for (int i = 0; i < col_len; i++)
		{
			total[i] = amount[0][i] + amount[1][i];
		}

		//Ȯ��
		for (int i = 0; i < col_len; i++)
		{
			printf("%d ", total[i]);
		}

		return 0;
	}



#pragma endregion

#pragma region 3�� �Լ��� �ٽ� ����
	void fn_sum(const int(*)[5], int);

	int main()
	{
		// 3��
		int salary[2][5] = {
			{200,300,400,500,600},
			{30,60,90,120,150}
		};

		int(*amount)[5] = &salary;
		int total[5];

		int row_len = sizeof(salary) / sizeof(salary[0]);
		int col_len = sizeof(salary[0]) / sizeof(salary[0][0]);
		/*
			for (int i = 0; i < col_len; i++)
		{
			total[i] = amount[0][i] + amount[1][i];
		}
		*/

		fn_sum(salary, 5);


		return 0;
	}

	void fn_sum(int(*salary)[5], int size)
	{
		int total[5];
		for (int i = 0; i < size; i++)
		{
			total[i] = salary[0][i] + salary[1][i];
		}

		//Ȯ��
		for (int i = 0; i < size; i++)
		{
			printf("%d��° �Ѿ��� : %d \n", i + 1, total[i]);
		}
	}




#pragma endregion


#pragma region ���� 4��
	int main()
	{
		int arr[100];
		int get_num = 0, count = 0, chk = 0;
		int size = sizeof(arr) / sizeof(arr[0]);

		printf("%d \n", size);
		chk = scanf("%d", &get_num);

		for (int i = 0; i < size; i++)
		{
			chk = scanf("%d", &get_num);
			if (chk != 1)
			{
				printf("����");
				break;
			}
			else if (get_num == -1) break;

			arr[i] = get_num;
			count++;
		}

		if (count < 3)
		{
			for (int i = 0; i < count; i++)
			{
				printf("%d ", arr[i]);
			}
		}
		else
		{
			for (int i = count - 3; i < count; i++)
			{
				printf("%d ", arr[i]);
			}
		}

		return 0;
	}



#pragma endregion

#pragma region ���� 4�� �����
	// 4�� �����
	int value[100];
	int i = 0;

	while (i < 100 && scanf("%d", &value[i]) == 1)
	{
		if (value[i] == -1)
		{
			break;
		}

		i++;
	}

	// ���� �ε����� ������ ���� �����ϱ� ����
	int start = i - 3 < 0 ? 0 : i - 3;

	for (int j = start; j < i; j++)
	{
		printf("%d ", value[j]);
	}

#pragma endregion





	return 0;
}


