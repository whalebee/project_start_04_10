#include <stdio.h>
#include <string.h>

#define VALUE 10


int main()
{
#pragma region �迭�� �⺻����
	int main()
	{
		// �迭 �⺻
		int arr_int[5] = { 1,2,3,4,5 };
		int where = 0;
		int num = 0;
		int count = 0;
		count = sizeof(arr_int) / sizeof(int);

		// ����ϰ� ���
		printf("%d \n", arr_int[0]);
		printf("%d \n", arr_int[1]);
		printf("%d \n", arr_int[2]);
		printf("%d \n", arr_int[3]);
		printf("%d \n", arr_int[4]);

		// �Է¹޾Ƽ� ���
		printf("�� ��° ���� ����? ( 0���� ������ ) \n");
		printf("������ 0 ~ %zd���� �־� \n", (sizeof(arr_int) / sizeof(int)) - 1);
		scanf("%d", &where);
		printf("%d��°�� ��ġ���ִ� ���� %d \n", where, arr_int[where]);

		// ù��° �ڸ����� ���ڸ� ����
		for (int i = 0; i < count; i++)
		{
			printf("%d \n", arr_int[i]);
		}

		puts(" ");

		// ���ڸ����� ù��° �ڸ�����
		for (; count > 0; count--)
		{
			printf("%d \n", arr_int[count - 1]);
		}

		return 0;
	}


#pragma endregion


#pragma region ������ �迭
	// ������ �迭

	int arr1[2][3] = { 10, 20, 30, 40, 50, 60 };

	// �ٸ��� ǥ��
	int arr2[2][3] =
	{
		{10, 20, 30 }
		,{40, 50, 60 }
	};

	// �迭�� ����
	printf("arr1�� �迭�� ���̴� : %zd \n", sizeof(arr1) / sizeof(int));
	int a = 0;
	int* ptr_a = &a;
	printf("���� a�� ������� : %d \n", sizeof(ptr_a));


	// �迭�� �ּ�
	printf("arr1 �迭�� �ּҴ� : %p \n", arr1);
	printf("arr2 �迭�� �ּҴ� : %p \n", &arr2);
	// ���� �� �� �ǳ�

	// �ּҰ� �������� ���� �ٴ� ���� Ȯ���� �� ����
	// ���ڸ��� 34 38 3C �� ���� Ȯ�� -> ������� Ȯ�ΰ��� int���̴ϱ��
	int arr3[3] = { 1,2,3 };
	for (int col = 0; col < 3; col++)
	{
		printf("arr3[%d] ��:%d �ּ�:%p \n", col, arr3[col], &arr3[col]);
	}


#pragma endregion


#pragma region ������ �迭 ������ ���ϱ�
	// �ּҰ� �������� ���� �ٴ� ���� Ȯ���� �� ����
	// ���ڸ��� 34 38 3C �� ���� Ȯ�� -> ������� Ȯ�ΰ��� int���̴ϱ��
	int arr1[2][3] = { 1,2,3,4,5,6 };
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			printf("arr1[%d][%d] ��:%d �ּ�:%p \n", row, col, arr1[row][col], &arr1[row][col]);
		}
		printf("------------------------------- \n");
	}

	// ������ �迭�� [][] �̷������� ���� �Ұ���
	// ���� ������ ������ߵ� [][3] �̷� �� ���� -> ������������ �׳ɤ���
	// [2][] �̰� �� �ȵ� -> ���������� �׳ľƾ�

	puts(" ");
	puts(" ");
	// 2���� �迭�� ũ�� ���ϱ�
	/*
	��ü ũ��/1���� ũ�� -> ���� ������ ����

	1���� ũ��/ �ڷ��� ũ�� -> ���� ������ ����
	*/
	int row_max = 0, col_max = 0;

	//��
	row_max = sizeof(arr1) / sizeof(arr1[0]);

	//��
	// sizeof(arr1[0][0])�� �� �ϳ��� ��� ũ�⸦ ���ϴϱ� sizeof(int)�� ���� ����
	col_max = sizeof(arr1[0]) / sizeof(arr1[0][0]); // ��ü������� ���ϱ�
	// col_max = sizeof(arr1[0]) / sizeof(int); // ������� ���ϱ�

	// Ȯ��
	printf("arr1�� 2���� �迭 ���� : arr1[%d][%d] \n", row_max, col_max);

	// �� ��Ҿ� ����
	puts(" ");
	puts("----row_max�� col_max�� Ȯ���ϱ�----");
	for (int row = 0; row < row_max; row++)
	{
		for (int col = 0; col < col_max; col++)
		{
			printf("arr1[%d][%d] ��:%d �ּ�:%p \n", row, col, arr1[row][col], &arr1[row][col]);
		}
		printf("------------------------------- \n");
	}


#pragma endregion


#pragma region ���� �� �� ������
	// float rainfall[60];
	// float rainfall[5][12];

	float rainfall[5][12] =
	{
	{8.5,29.6,49.5,130.3,222,171.5,185.6,202.6,68.5,120.5,79.1,16.4},
	{0,23.8,26.8,47.3,37.8,74,194.4,190.5,139.8,55.5,78.8,22.6},
	{60.5,53.1,16.3,16.9,112.4,139.6,270.4,675.7,181.5,0,120.1,4.6},
	{18.9,7.1,110.9,124.1,183.1,104.6,168.3,211.2,131,57,62.4,7.9},
	{5.5,4.7,102.6,20.4,7.5,393.8,252.3,564.8,201.5,124.1,84.5,13.6}
	};

	int row_max = 0, col_max = 0;

	// ��
	row_max = sizeof(rainfall) / sizeof(rainfall[0]);
	printf("�� Ȯ�� : %d \n", row_max);

	// ��
	col_max = sizeof(rainfall[0]) / sizeof(rainfall[0][0]);
	printf("�� Ȯ�� : %d \n", col_max);

	// �ٽ� �˻�
	printf("Ȯ����? rainfall[%d][%d] \n", row_max, col_max);


	puts(" ");
	for (int row = 0; row <= row_max; row++)
	{
		if (row == 0)
		{
			for (int count = 0; count <= 12; count++)
			{
				if (count == 0)
				{
					printf("  �⵵");
				}
				else
				{
					printf("%5d��", count);
				}
			}
		}
		else
		{
			printf("\n");

			for (int col = 0; col <= col_max; col++)
			{
				if (col == 0)
				{
					printf("%d�� ", col + 2017 + row);
				}
				else
				{
					printf("%6.1f ", rainfall[row - 1][col - 1]);
				}
			}
			printf("\n");
		}

	}
	


#pragma endregion


#pragma region ���� 2�� : ���� �Ǿ��ִ� �迭�� �� �־��ֱ�
	int array[5][5];
	int value = 1;

	for (int row = 0; row < 5; row++)
	{
		if (row % 2 == 0)
		{
			for (int col = 0; col < 5; col++)
			{
				array[row][col] = value++;
			}
		}
		else
		{
			// row�� 0���� �����ϴϱ� �̷��� �ؾ� 2��° ��, 4��° ��, ¦�� ����� ������ ����
			for (int col = 4; col >= 0; col--)
			{
				array[row][col] = value++;
			}
		}
	}

	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			printf("%3d", array[row][col]);
		}
		printf("\n");
	}


#pragma endregion


#pragma region ���̵� 3�� : ������ ���ص�
	int array[5][5];
	int value = 1;
	// while �ϳ�, for 2���� �ε����� �ٲ㼭 -> ����

	int start_row = 0, start_col = 0, max_col = 4, max_row = 4;

	for (int row = 0; row <= max_row; row++)
	{
		if (row == 0)
		{
			for (int col = 0; col <= max_col; col++)
			{
				array[row][col] = value++;
			}
		}
		else if (row >= 1 && row < 4)
		{
			for (int col = 4; col >= max_col; col--)
			{
				array[row][max_col] = value++;
			}
		}
		else if (row == max_row)
		{
			for (int col = 4; col >= 0; col--)
			{
				array[row][col] = value++;
			}
		}
	}

	for (int row = 3; row > 0; row--)
	{
		array[row][0] = value++;
	}

	���̽ù� �𸣰ڴ�


		// ���Ȯ��
		for (int row = 0; row < 5; row++)
		{
			for (int col = 0; col < 5; col++)
			{
				printf("%3d", array[row][col]);
			}
			printf("\n");
		}


#pragma endregion


#pragma region �� �� �������� ��շ�, �ִ�, �ּ�
	// float rainfall[60];
	// float rainfall[5][12];

	float rainfall[5][12] =
	{
	{8.5,29.6,49.5,130.3,222,171.5,185.6,202.6,68.5,120.5,79.1,16.4},
	{0,23.8,26.8,47.3,37.8,74,194.4,190.5,139.8,55.5,78.8,22.6},
	{60.5,53.1,16.3,16.9,112.4,139.6,270.4,675.7,181.5,0,120.1,4.6},
	{18.9,7.1,110.9,124.1,183.1,104.6,168.3,211.2,131,57,62.4,7.9},
	{5.5,4.7,102.6,20.4,7.5,393.8,252.3,564.8,201.5,124.1,84.5,13.6}
	};

	int row_max = 0, col_max = 0;

	// ��
	row_max = sizeof(rainfall) / sizeof(rainfall[0]);
	printf("�� Ȯ�� : %d \n", row_max);

	// ��
	col_max = sizeof(rainfall[0]) / sizeof(rainfall[0][0]);
	printf("�� Ȯ�� : %d \n", col_max);

	// �ٽ� �˻�
	printf("Ȯ����? rainfall[%d][%d] \n", row_max, col_max);


	puts(" ");
	printf("  �⵵");
	printf("	       ����� ");
	printf("	  �ְ����� ");
	printf("	���������� ");

	for (int row = 0; row < row_max; row++)
	{
		printf("\n");
		float sum = 0;
		float max = rainfall[0][0];
		float min = rainfall[0][0];

		for (int col = 0; col <= col_max; col++)
		{
			if (col == 0)
			{
				printf("%d�� ", col + 2018 + row);
			}
			else if (col <= col_max)
			{
				sum += rainfall[row][col - 1];

				if (rainfall[row][col - 1] > max)
				{
					max = rainfall[row][col - 1];
				}
				else if (min > rainfall[row][col - 1])
				{
					min = rainfall[row][col - 1];
				}

			}
		}
		float average = sum / col_max;
		printf("%14.2f ", average);
		printf("%14.1f", max);
		printf("%14.1f", min);
		printf("\n");

	}



#pragma endregion


#pragma region ������ �����
	int ary[50][50];
	int n, max, i, j, x = 0, y = -1, z = 1, num = 1;
	scanf("%d", &n);
	max = n;

	while (max > 0) {
		for (i = 0; i < max; i++) {
			y = y + z;
			ary[x][y] = num;
			num = num + 1;
		}
		max = max - 1;

		for (i = 0; i < max; i++) {
			x = x + z;
			ary[x][y] = num;
			num = num + 1;
		}
		z *= -1; // �� �̰� �̷����ϴٴ� ������


	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%3d ", ary[i][j]);
		}
		printf("\n");
	}


#pragma endregion


#pragma region ����� �ؼ�
	int main()
	{
		int arr[30][30];
		// ���̳� ���� ���� scanf�� �Է��� �� �ִ� �ִ� ���� ���� !
		// �ʰ��ؼ� �Է����� �� ������ �迭�� ���� ���� ����ϱ� ������ �����߻�
		// ������� �� ����� �ִ� ���ڰ� ��� ���� ���� ���� ����

		// ��ǥ ����(x: ��, y: ��, z: ����)
		// ���� ��ǥ�� x�� ���θ�, y�� ���θ� ����Ű��,
		// �迭�� ������ arr[2���� ��][1���� ��] ������ �Ǿ��־
		// ������ �þ���� �������� �þ�� �װ� �����ϸ� ������ arr[y][x] �̷������� �Ϸ��մϴ�.
		int z = 1, x = -1, y = 0;
		// ������ ���� z�� ����� ������ �Դٰ��� �ؾ��ϱ� ������ ��ȣ�� ��ȭ�� �ִ� 1�� �����
		// ���� ���� x�� �ε����� 0���� �����ϱ⶧���� -1���� ����		
		// ( 0���� �����ϸ� ���� z ������ 2��° �������� �� ���� ���� )
		
		// ���� ���� y�� 1����� �����ϱ� ������ 0���� ����				
		// ( 1���� �����ϸ� ���� z ������ 2��° �������� �� ���� ���� )

		// ���� �־��� ����(num), �ݺ��� ����(i,j)
		int num = 1, i, j;

		// �ݺ������� ����� ��� ���� �ִ� �ݺ���
		int max = 0;

		// ���Ȯ�ΰ� �迭�� ũ�⸦ ���� ����
		int get = 0, chk = 0;
		chk = scanf("%d", &get);
		if (chk != 1) // �Է� üũ
		{
			printf("�Է� ���� \n");
		}
		max = get; // max�� �ݺ������� ���� ����Ǳ⶧���� ���Ȯ���� ���� get�� ���� �ʿ��ϴ�

		// for������ while�� �� �����ϱ� ������ while�� ���
		while (max > 0)
		{
			// ������ �����ϱ� ������ ���� ���� for�� ����
			for (i = 0; i < max; i++) // i�� 0���� �����ϴϱ� max�� �� ��ŭ ���� �ȴ�
			{
				x = x + z; // 2��° �������� ������ ���� z���� ���
				arr[y][x] = num; // ��ǥ(x,y)�� Ȱ���ϱ����� �迭[��][��]�� ������ arr[x][y]�� �ƴ��� ����
				num += 1; // ���� 1�� �þ������ ����
			}
			max -= 1;
			// ������ ��ġ�� �ʰ� �ϰ�, �����ϱ� ���� ĭ�� ���� ���� �����ϱ� ������ max�� 1�� �����ؾ���
			// �Է��ϴ� ĭ�� �� ��Ģ
			// 5 4 4 3 3 2 2 1 1
			// n n-1 n-1 n-2 n-2 ... 1 1
			// �̷������� ó���� �����ϰ�� ������ �ڿ� 2�� ����ϰ� �ٽ� �����ؾ��ϱ� ������ �� ���� ��ġ

			// ��
			for (j = 0; j < max; j++)
			{
				y = y + z; // ó�� y�� 1����� �����ؾ��� -> �ʱⰪ y=0, z=1
				arr[y][x] = num;
				num += 1;
			}

			z *= -1;
			// ������ ���� ���� ��ȣ�� �ָ鼭 ���� ������ �ʴ� -1�� ��
			// �� ���� �����Ŀ� ������ ���� ��Ģ������ ���� ���� ���� �� ���� ��ġ
		}

		// ��� Ȯ��
		for (j = 0; j < get; j++)
		{
			for (i = 0; i < get; i++)
			{
				printf("%4d ", arr[j][i]); // arr[i][j] �ƴ� ���� !
			}
			puts(" ");
			// printf("\n");
		}

		return 0;
	}


#pragma endregion


#pragma region ������ ������ ����
	int value = 0x12345678;
	char* ptr = (char*)&value; // value�� int���̴ϱ� �� ��ȯ

	printf("%c \n", *ptr); // 16���� 7 8 �� 10������ �ٲ� ASCII��(120(10)) x ������ ��

	printf("%x \n", *ptr); // 16���� �̴� ���Ĺ��� %x
	ptr++;
	printf("%x \n", *ptr);
	ptr++;
	printf("%x \n", *ptr);
	ptr++;
	printf("%x \n", *ptr);


	int s_v = 0x12345678;
	short* prt_s = (short*)&s_v; // �� ��ȯ
	printf("%10x %p \n", *prt_s, prt_s); // 16���� �̴� ���Ĺ��� %x
	prt_s += 1;
	printf("%10x %p \n", *prt_s, prt_s); // �̰ɺ��� ++�� ������ ������ �ڷ��� ũ�⸸ŭ �ö�
	prt_s += 1;
	printf("%10x %p \n", *prt_s, prt_s);
	prt_s += 1;
	printf("%10x %p \n", *prt_s, prt_s);

	//prt_s += 1;	// �̷������� ���� ���� short���� ���ڴ� �̷��� 1������ �ƴ϶�
					// �ڷ����� ũ�⸸ŭ ������ ���ڴ� !


#pragma endregion


#pragma region ������ ���� ���� 2
	// ������ ���� ����
	int value[2] = { 10, 20 };

	int* ptr = &value[0];
	// �Ǵ� int* ptr = value; -> �̷��� �Ȱ���
	// �迭�� �̸��� �迭�� ���� �ּҸ� ����Ű�°� ����!, �׳� ������ �̷��� ����
	printf("%p \n", value);

	printf("%d \n", *ptr);
	printf("%d \n", (*ptr) + 1);
	printf("%d \n", *(ptr + 1));

	puts(" ");
	// ������ ������ �迭ó�� ����
	printf("%d \n", ptr[0]);
	printf("%d \n", ptr[1]);

	puts(" ");
	// �迭�� �����ͺ���ó�� ���°ǵ� �̷��� ���� �򰥷��� �ȵ�
	printf("%d \n", *value);
	printf("%d \n", *(value + 1));


#pragma endregion


#pragma region ������ ���� ���� 3
	int value = 10;
	char* ptr = (char*)&value;

	for (int i = 0; i < sizeof(value); i++)
	{
		printf("%d \n", *ptr++);
	}

	puts(" ");
	int v1 = 0x12345678;
	char* ptr_v = (char*)&v1;

	for (int i = 0; i < sizeof(v1); i++)
	{
		printf("%x \n", *ptr_v++); // ����� ���� �̻��ϳ� ���Ĺ��ڸ� int������ �߾����ϱ�..����
	}

	puts(" ");
	int v2 = 10;
	void* ptr_v2 = &v2;
	// printf("%d \n", *ptr_v2); //���� ��
	// �׷��� �ؿ�ó�� �ڷ��� �����ͷ� �ٲ���ߵ�
	printf("%d \n", *(int*)ptr_v2);



	puts(" ");
	int v3 = 0x12345678;
	void* ptr_v3 = &v3;
	printf("%x \n", *(int*)ptr_v3);		//12345678
	printf("%x \n", *(short*)ptr_v3);	//5678
	printf("%x \n", *(char*)ptr_v3);	//78



#pragma endregion


#pragma region void ������
	void MyFunc(void* p, char flag)
	{
		if (flag == 0) *(char*)p = 1;
		else if (flag == 1) *(short*)p = 1;
		else *(int*)p = 1;
	}


	int main()
	{
		short data = 5;
		MyFunc(&data, 1);

		// �迭�� ���ڿ��� call by value ��ü�� �ȵ�



		return 0;
	}


#pragma endregion


#pragma region �Լ� ȣ�� ����
	void swap_v(int a, int b);
	void swap(int*, int*);


	int main()
	{
		int a = 20, b = 60;
		printf("%p \n", &a);

		swap_v(a, b);
		printf("call by value %d %d \n", a, b);

		swap(&a, &b);
		printf("call by reference %d %d \n", a, b);



		return 0;
	}

	// �̷� ���°� call by value
	void swap_v(int a, int b)
	{
		printf("%p \n", &a);
		int temp = a;
		a = b;
		b = temp;
	}

	// �̷� ���°� call by reference
	void swap(int* a, int* b)
	{
		printf("%p \n", &a);
		int temp = *a;
		*a = *b;
		*b = temp;
	}



#pragma endregion

	return 0;
}


