#include <stdio.h>
#include <string.h>

#define VALUE 10


int main()
{
#pragma region 2���� ������
//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		// 2���� ������
		int a = 10;
		int* ptr = NULL, ** ptr2 = NULL;

		ptr = &a;
		ptr2 = &ptr; // 2���� �����Ϳ��� ������ ������ ��밡��

		printf("a�� �ּ�	: %p,		a��	��: %d \n", &a, a);

		printf("ptr�� �ּ�	: %p,		ptr��	��: %p, �����ϰ� �ִ� �ּ��� �� : %d \n", &ptr, ptr, *ptr);

		printf("ptr2�� �ּ�	: %p,		ptr2��	��: %p, \n", &ptr2, ptr2);

		printf("ptr2 ù ��° ���� �޸��� �� : %p \n", *ptr2); // ptr �ּҸ� ��Ÿ��
		printf("ptr2 �� ��° ���� �޸��� �� : %d \n", **ptr2); // ptr�� �������� ������ ��

		return 0;
	}



#pragma endregion


#pragma region ���� �����Ϳ� 2���� �迭
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		// 2�� ������ ��� -> �𸣰���
		short** pp;
		pp = (short**)malloc(sizeof(short*)); // ���Ⱑ malloc �Լ��� ���� heap������ ���� ������ ��
		// short* -> ������ ������ 4����Ʈ -> �ü���� ���� �ٸ����� �⺻ 4����Ʈ
		// ������ ������ �⺻ 4����Ʈ�� �׷��ɱ� -> �¾ƿ�

		if (pp != NULL) {
			*pp = (short*)malloc(sizeof(short)); // malloc �Լ��� ���� heap������ ���� ������ ��
			// short 2����Ʈ
			if (*pp != NULL)
			{
				**pp = 10;
				/*
				printf("**pp : %d \n", **pp);

				printf("pp�� �� %d \n", pp); // ???

				printf("*pp�� �ּ� : %p \n", &pp);
				printf("*pp�� �� : %hu \n", *pp);
				*/
				free(*pp);
			}
			free(pp);
		}


		// ���� �����Ͱ� ������� ��� �迭�� ǥ�� ���� ��
		int limit_table[3] = { 4,2,3 };
		int* ptr[3];

		int grade = 0;

		for (grade = 0; grade < 3; grade++)
		{
			ptr[grade] = (int*)malloc(sizeof(int) * limit_table[grade]);
			printf("%p \n", ptr[grade]);
		}

		for (grade = 0; grade < 3; grade++)
		{
			free(ptr[grade]);

		}

		return 0;
	}




#pragma endregion


#pragma region ���� ���ͳݿ��� ã�� ����
	//����
	// https://man-25-1.tistory.com/46
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		int row, col;
		scanf("%d %d", &col, &row);
		char** d_Array;
		char n = 'a' - 1;

		d_Array = (char*)malloc(sizeof(char) * col);

		for (int i = 0; i < row; i++)
		{
			d_Array[i] = (char*)malloc(sizeof(char) * col);
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				n++;
				d_Array[i][j] = n;
				printf("%c ", d_Array[i][j]);
				if (n == 'z')
				{
					n = 'A' - 1;
				}
				else if (n == 'Z') n = 'a' - 1;
			}
			printf("\n");
		}

		for (int i = 0; i < row; i++)
		{
			free(d_Array[i]);
		}
		free(d_Array);


		return 0;
	}




#pragma endregion


#pragma region ���� �����Ϳ� 2���� �迭 ���� 1
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		// �ᱹ 2���� �迭�� �����Ҵ����� ����ؼ� �����Ӱ� �������� ���������͸� ����� �� �ֱ�.
		int** ptr, score = 0, chk = 0;
		int grade = 0, grade_max = 0;


		int* allcount = 0; // �л� �� ���� ����

		// �հ�� ��� ������ ���� ���� ����
		int* sum = 0; // �ϵ��ڵ��������� malloc�� ���ٸ�?
		int* avg = 0;



		// �� �г��� ���� �Է� ( �г�� �л� ���� max���� ��� �Է¹޾Ҵ� )
		printf("�� �г���� �ִ��� �Է�");
		chk = scanf("%d", &grade_max);

		// �����̶� ��� �޾ƾߵ�
		sum = (int*)malloc(sizeof(int) * grade_max);
		avg = (int*)malloc(sizeof(int) * grade_max);

		// printf("%d \n", sizeof(int));
		// printf("%d \n", sizeof(*ptr));

		ptr = (int**)malloc(sizeof(int*) * grade_max); // ��

		allcount = (int*)malloc(sizeof(int) * grade_max); // �г� �� �л����� ���� ������ ����, �����¶�����


		if (ptr != NULL && allcount != NULL && sum != NULL && avg != NULL) // üũ�����ָ� ������ �ߴٰ� ������
		{
			// �г� ��
			for (int i = 0; i < grade_max; i++)
			{
				printf("%d�г��� �л� ���� �Է� : ", i + 1);
				chk = scanf("%d", allcount + i);

				// ptr�� ���� �� �ּ�(��)�ȿ� �־��ٰŶ� *ptr
				*(ptr + i) = (int*)malloc(sizeof(int) * *(allcount + i)); // ��
				if (*(ptr + i) != NULL)
				{
					// int sumsum = 0, avgavg = 0;
					// �л� ��
					for (int j = 0; j < *(allcount + i); j++)
					{
						printf("%d�г� %d��° �л��� ������ �Է��ϼ��� : ", i + 1, j + 1);
						scanf("%d", &score);
						ptr[i][j] = score;
						sum += score;
						// sumsum += score;
					}
					// avgavg = sumsum / *(allcount + i);
					// printf("%d �г��� ���� %d : ", i+1, sumsum);
					// printf("%d �г��� ��� %d : ", i + 1, avgavg);
				}
				*(avg + i) = *(sum + i) / *(allcount + i);
			}
		}



		puts(" ");


		printf("�Է¹��� ������ ������ ��� ��� --------------------- \n");
		if (ptr != NULL && allcount != NULL && sum != NULL && avg != NULL)
		{
			for (int i = 0; i < grade_max; i++)
			{
				printf("%d�г��� ", i + 1);
				printf("���� %d ,", sum[i]);
				printf("��� %d , ", *(avg + i));
				printf("%d�г� ��ü ���� : ", i + 1);
				for (int j = 0; j < *(allcount + i); j++)
				{
					printf("%d�� ", ptr[i][j]);
				}
				puts(" ");
			}


			/*
					for (int i = 0; i < grade_max; i++)
			{
				for (int j = 0; j < *(allcount + i); j++)
				{
					printf("�� �Ҵ�Ǿ�����? ptr[%d][%d] ������ : %d \n", i, j, ptr[i][j]);
				}
				printf("�� �Ҵ�Ǿ�����? allcount[%d] : %d \n", i, allcount[i]);
				printf("�� �Ҵ�Ǿ�����? sum[%d] : %d \n", i, sum[i]);
				printf("�� �Ҵ�Ǿ�����? avg[%d] : %d \n", i, avg[i]);
				puts(" ");
			}
			*/



			printf("�޸� �Ҵ� ���� ����");
			for (int i = 0; i < grade_max; i++)
			{
				free(ptr[i]);
				puts(" ");
			}

			free(allcount);
			free(ptr);
			free(sum);
			free(avg);



			/*
			for (int i = 0; i < grade_max; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					printf("�����Ǿ�����? ptr[%d][%d] �ּҰ� : %p \n", i, j, &ptr[i][j]);
					printf("2���� �迭�� �������� ������ ����ó�� ���.. \n");
				}
				printf("�����Ǿ�����? allcount[%d] : %d \n", i, allcount[i]);
				printf("�����Ǿ�����? sum[%d] : %d \n", i, sum[i]);
				printf("�����Ǿ�����? avg[%d] : %d \n", i, avg[i]);
				puts(" ");
			}
			*/


		}



		return 0;
	}





#pragma endregion


#pragma region 2���� �迭 �Լ� ����
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
	�� �Լ������� �޸� ���� �Ҵ��� ����Ͽ� �޸� ����� �Ҵ��ϰ�, 
	�� �޸� ����� �ּҸ� ����Ű�� �����͸� ��ȯ�ϱ� ������ ���� ������ int** q�� �޾ƾ� �մϴ�.

���� �Լ��� ���ڷ� ���� ������ int* q�� �޴´ٸ�, 
�Լ� �ȿ��� q �����Ϳ� �޸𸮸� ���� �Ҵ��ϴ��� �Լ� ȣ���ڿ��� ��ȯ�Ǵ� ���� q �������̸� 
�޸� ����� �ּҸ� �������� �ʱ� �����Դϴ�. �׷��Ƿ� p�� ����Ű�� �޸� �ּҸ� ������ �� �����ϴ�.

���� ���� ������ int** q�� ����Ͽ� 
�Լ��� �Ҵ��� �޸� ����� �ּҸ� q�� ����Ű�� ������ ������ �����ϸ�, 
�Լ� ȣ���ڴ� �޸� ����� �ּҸ� ������ �� �ֽ��ϴ�. 
�̴� �޸� ��Ͽ� ����� ���� ������ �� �ֵ��� �ϸ�, 
���� �޸� �Ҵ��� ����� �� �Ϲ����� �����Դϴ�.
*/


	void GetMyData(int** q) // ���� ����
	{
		*q = (int*)malloc(40);
	}

	int main()
	{
		int* p;
		GetMyData(&p);
		*p = 5;

		printf("%d", *p);

		free(p);

		return 0;
	}




#pragma endregion


#pragma region 2���� �������� ���� ���� ����.. ���� �� Ǯ���� -> ���� Ǯ����
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		int row, col;
		scanf("%d %d", &row, &col);

		int number = 0;
		int* arr_avg = (int*)malloc(sizeof(int) * col);
		int* arr_sum = (int*)malloc(sizeof(int) * col);

		int dif = 0;

		arr_avg = (int*)malloc(sizeof(int) * col);
		arr_sum = (int*)malloc(sizeof(int) * col);

		int** arr;

		// ��
		arr = (int**)malloc(sizeof(int*) * row);

		if (arr != NULL)
		{
			for (int i = 0; i < row; i++)
			{

				*(arr + i) = (int*)malloc(sizeof(int) * col); // ��
				if (*(arr + i) != NULL)
				{
					int sum = 0, avg = 0;

					for (int j = 0; j < col; j++)
					{
						printf("%d�� %d�� ���� �Է� ! \n", i, j);
						scanf("%d", &number);
						arr[i][j] = number;
						sum += number;
						// printf("%d�� %d�� ���� �� : %d \n", i, j, arr[i][j]);
					}
					arr_sum[i] = sum;
					printf("�հ� %d \n", sum);
					arr_avg = sum / col;
					printf("��� %d \n", avg);

					printf("\n");

					for (int j = 0; j < col; j++)
					{
						if (arr_avg[i] > arr[i][j])
						{
							printf("�����ΰ� %d ", *(arr + i)[j]);
							*(arr + i)[j] = 0;

							// printf("�Ϳ� %d ", arr[i][j]);
						}
						else
						{
							printf("WTF");
						}
					}


					for (int j = 0; j < col; j++)
					{
						printf("%d ", arr[i][j]);
					}
					puts(" ");
				}



			}


		}



		return 0;
	}



	// ��@@@@@@@@@@@@@@@@@@@@@
	//����
#include <stdio.h>
#include <stdlib.h>

	int main() {
		int row, col;
		scanf("%d %d", &row, &col);

		int** arr = (int**)malloc(sizeof(int*) * row);
		if (arr == NULL)
		{
			printf("Memory allocation error");
			return -1;
		}

		for (int i = 0; i < row; i++)
		{
			arr[i] = (int*)malloc(sizeof(int) * col);
			if (arr[i] == NULL)
			{
				printf("Memory allocation error");
				return -1;
			}
		}

		for (int i = 0; i < row; i++)
		{
			int sum = 0;
			for (int j = 0; j < col; j++)
			{
				printf("%d�� %d�� ���� �Է�: ", i, j);
				scanf("%d", &arr[i][j]);
				sum += arr[i][j];
			}

			double avg = (double)sum / col;
			printf("�հ�: %d, ���: %.2lf \n", sum, avg);

			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] < avg)
				{
					arr[i][j] = 0;
				}
			}
		}

		// ��� ���
		puts("");
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				printf("%d ", arr[i][j]);
			}
			puts("");
		}

		// �޸� �Ҵ� ����
		for (int i = 0; i < row; i++)
		{
			free(arr[i]);
		}
		free(arr);

		return 0;
	}



#pragma endregion


#pragma region ����ü�� ����ü �⺻����
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ����ü
	struct Test
	{
		char a;		// 1����Ʈ
		short b;		// 2����Ʈ
		int c;			// 4����Ʈ
	};

	// ����ü ( share house )
	union Test2
	{
		char a;
		short b;
		int c;
	};

	int main()
	{
		// ����ü ���
		struct Test t1;

		printf("%d \n", sizeof(t1));

		printf("%p \n", &t1.a);
		printf("%p \n", &t1.b);
		printf("%p \n", &t1.c);


		union Test2 t2;

		printf("%d \n", sizeof(t2));
		printf("%p \n", &t2.a);
		printf("%p \n", &t2.b);
		printf("%p \n", &t2.c);

		t2.c = 0x12345678;

		printf("%x \n", t2.a); // 78
		printf("%x \n", t2.b); // 5678
		printf("%x \n", t2.c); // 12345678

		return 0;
	}



#pragma endregion


#pragma region ����ü
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	typedef union comm
	{
		char buffer[5];

		struct
		{
			char version;
			char header;
			char length;
			char address;
		};
	} COMM;

	int main()
	{
		// ����ü
		COMM myComm;
		strcpy(myComm.buffer, "abcd");
		printf("version �κ��� %c \n", myComm.version);		// a
		printf("header �κ��� %c \n", myComm.header);		// b
		printf("length �κ��� %c \n", myComm.length);		// c
		printf("address �κ��� %c \n", myComm.address);	// d

		return 0;
	}



#pragma endregion


#pragma region ����ü �⺻����
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	enum Days { MON, TUE, WED, THU, FRI, SAT, SUN };

	int main()
	{
		// ����ü
		enum Days today;

		// printf("%d %d %d %d %d %d %d", MON, TUE, WED, THU, FRI, SAT, SUN);
		// ����Ʈ�� 1�� �����ϰ� ���� ������� ������ �� ����
		//enum Days { MON=10, TUE=16, WED=25, THU, FRI, SAT, SUN};


		today = MON;
		if (today >= SAT && today <= SUN) puts("������ �ָ�");
		else printf("�ָ����� %d�� ���Ҵ�.", SAT - today); // �̷��� �� �� ����


		return 0;
	}



#pragma endregion


#pragma region ����ü �̴� ����
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	union data
	{
		char c1;
		short num1;
		int num2;
		long long int num3; // == long long
	};

	union data1
	{
		char c1;
		short num1;
		int num2;
	};



	int main()
	{
		// 8����Ʈ
		union data t1;
		printf("%d \n", sizeof(t1));


		// 5678
		/*
		
		*/
		union data1 d1;					// ����ü data1�� ����Ͽ� d1���� ����
		d1.num2 = 0x12345678;	// d1������ int������ 0x12345678 �� ����
		printf("%x", d1.num1);		// d1 ������ �ִ� ���� short������ ���

		return 0;
	}



#pragma endregion


#pragma region



#pragma endregion




#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion



	return 0;
}


