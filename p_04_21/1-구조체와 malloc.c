#include <stdio.h>
#include <string.h>

#define VALUE 10


int main()
{
#pragma region ���� 3�� �˾ƾ��� �͵�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
	// 2���� �迭�̶� �Ű������� �Լ��� ������ ��
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


#pragma region ���� 4�� ����ȭ
	
	
	// ���� �Է��ϴٰ� -1 ������ ������ 3���� ���� ���
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


#pragma region ����ü �⺻����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
	// ����ü ����
	// ������ ���� ;
	struct book {
		char title[MAXTITL];
		char author[MAXAUTL];
		int price;
	};

	int main()
	{
		// ����ü ���
		// ����� ���� ,
		struct book myBook = {
			.title = "Do it! C��� �Թ�",
			.author = "����",
			.price = 25000
		}; // semicolon ��ߵ�


		printf("å�̸�	: %s \n", myBook.title);
		printf("����	: %s �� \n", myBook.author);
		printf("����	: %d��\n", myBook.price);

		struct book myBook2;


		char test[100];
		// scanf("%s", test);
		// Do it! C��� �Թ� �̶�� �Է����� ��
		// scanf�� �Է´����� ȭ��Ʈ �����̽��� Do�ۿ� �ȵ�
		// printf("©���� %s", test);

		scanf("%[^\n]s", test);

		// scanf("%[^\n]s", test); ���ͱ��� �Է¹ްڴ�
		// scanf("%[^a]s", test); a���� �Է¹ްڴ�

		printf("�� ©���� %s", test);




		int a;






		return 0;
	}




#pragma endregion


#pragma region ����ü ���� 1~4�� ���� �� ��
	
	
	// 1 ~ 2 ���� ���� ����ü
	struct book myBook = {
	.title = "Do it! C��� �Թ�",
	.author = "����",
	.price = 25000
	};

	// 1��
	printf("%s \n", myBook.author);

	// 2��
	printf("%d \n", myBook.price);

	// 3��
	struct student myStudent = {
		.name = " ",
		.subject = " ",
		.score = 0
	};

	// 4��
	printf("������ �Է��� (����) \n");
	scanf("%[^\n]s", myStudent.subject);

	printf("�̸��� �Է��� (����)\n");
	scanf("%s", myStudent.name);

	printf("������ �Է��� (���� 1 ~ 100)\n");
	scanf("%d", &myStudent.score);

	// ��� Ȯ��
	printf("�̸��� : %s \n", myStudent.name);
	printf("������ : %s \n", myStudent.subject);
	printf("������ : %d \n", myStudent.score);


#pragma endregion


#pragma region ����ü ���� �����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
	// ����ü ����
	// ������ ���� ;
	struct book {
		char title[MAXTITL];
		char author[MAXAUTL];
		int price;
	};

	struct student
	{
		char name[20];
		char subject[20];
		int score;
	};

	int main()
	{
		struct book myBook;

		// 1��

		// �迭�� �̸��� ������ ����� ������ �� ����� �̷��� �־�ߵ�
		strcpy(myBook.title, "Do it! C��� �Թ�");
		strcpy(myBook.author, "����");
		myBook.price = 25000;

		// 2��
		printf("%s \n", myBook.author);
		printf("%d \n", myBook.price);


		// 3��
		struct student myStudent;
		// 4��
		printf("�̸� ��  ");
		scanf("%s", myStudent.name);

		printf("���� ��  ");
		scanf("%s", myStudent.subject);

		printf("���� ��  ");
		scanf("%d", &myStudent.score);


		printf("�̸� : %s \n���� : %s \n���� : %d",
			myStudent.name, myStudent.subject, myStudent.score);


		return 0;
	}


#pragma endregion


#pragma region ����ü �迭
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	// ������ �ƴϰ� �������� define ����� ��
#define MAXTITL 31
#define MAXAUTL 21
#define MAXARRL 3

// ����ü ����
// ������ ���� ;
	struct book {
		char title[MAXTITL];
		char author[MAXAUTL];
		int price;
	};



	int main()
	{
		struct book myBook[MAXARRL] = {
			{.title = "Do it ! C��� �Թ�", .price = 150000000, .author = "���ľ�"},
			{"���� �� �϶�������DB", "�輺�羾", 13500},
			{"�󶼴� �������� ������", "������", 3500}
		};

		printf("                                      �ּ�\n");
		for (int i = 0; i < MAXARRL; i++)
		{
			printf("å�̸�	: %-25s %p \n", myBook[i].title, &myBook[i].title);
			printf("����	: %-25s %p \n", myBook[i].author, &myBook[i].author);
			printf("����	: %-25d %p \n", myBook[i].price, &myBook[i].price);
			printf("------------------------------ \n");
		}

		return 0;
	}




#pragma endregion


#pragma region ����ü �迭 ���� 1 ~ 2��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXARRL 3
	// 1�� ���� ����ü
	struct school
	{
		char name[20];
		char school_name[20];
		int grade;
	};

	// 2�� ���� ����ü
	struct score
	{
		char subject[10];
		int grade;
	};


	int main()
	{


		// 1��
		struct school mySchool;

		printf("�̸���? ");
		scanf("%s", mySchool.name);

		printf("�б���? ");
		scanf("%s", mySchool.school_name);

		printf("�г���? ");
		scanf("%d", &mySchool.grade);

		printf("Name : %s\nSchool : %s\nGrade : %d \n", mySchool.name, mySchool.school_name, mySchool.grade);



		// 2��
		struct score myScore[MAXARRL] = {
			{0},
			{0},
			{0}
		};

		puts(" ");
		int sum = 0;
		for (int i = 0; i < MAXARRL; i++)
		{
			printf("������ �Է��ϼ��� : ");
			scanf("%s", myScore[i].subject);
			// printf("%s", myScore[i].subject);

			printf("������ �Է��ϼ��� : ");
			scanf("%d", &myScore[i].grade);
			// printf("%d", myScore[i].grade);

			sum += myScore[i].grade;
		}

		puts(" ");
		printf("������ : ");
		for (int i = 0; i < MAXARRL; i++)
		{
			printf("%s ", myScore[i].subject);
		}
		printf("\n���� ������ :");
		for (int i = 0; i < MAXARRL; i++)
		{
			printf("%d ", myScore[i].grade);
		}
		puts(" ");
		printf("������ �� ������ %d", sum);






		return 0;
	}



#pragma endregion


#pragma region ����ü �迭 3��
#include <stdio.h>
#include <string.h>


#define MAXARRL 5
	struct BookNum
	{
		char name[30];
		int number;
	};

	int main()
	{
		struct BookNum Phone[MAXARRL] = {
			{.name = "����", .number = 12341234},
			{"���Ϸ���", 44444444},
			{"���縮����", 14285700},
			{"ī����", 73976497},
			{"����", 50603842}
		};

		char get_name[30];

		printf("ã���ô� �� ���� �Է��ϼ��� : ");
		scanf("%s", get_name);
		// printf("%s", get_name);

		int exists = 0;
		for (int i = 0; i < MAXARRL; i++)
		{
			if (strcmp(&Phone[i].name, &get_name) == 0)
			{
				printf("�̸�     : %s \n��ȭ��ȣ : 010%d \n", Phone[i].name, Phone[i].number);
				exists = 1;
				break;
			}
		}
		//�׷� ����� ���ٸ�
		if (exists == 0)
		{
			printf("�׷� ��� ���� �����̴�.");
		}

		return 0;
	}



#pragma endregion


#pragma region p476 ����
#include <stdio.h>
#include <string.h>

#define MAX_COUNT 5

	typedef struct People
	{
		char name[14];
		unsigned short int age;
		float height;
		float weight;
	}Person;

	int AddFriend(Person* p_friend, int count)
	{
		if (count < MAX_COUNT)
		{
			p_friend = p_friend + count;
			printf("\n���ο� ģ�� ������ �Է��ϼ���\n");
			printf("1. �̸� : ");
			scanf("%s", p_friend->name);

			printf("2. ���� : ");
			scanf("%hu", &p_friend->age);

			printf("3. Ű : ");
			scanf("%f", &p_friend->height);

			printf("4. ������ : ");
			scanf("%f", &p_friend->weight);

			printf("�Է��� �Ϸ��߽��ϴ�. \n\n");
			return 1;
		}
		else
		{
			printf("�ִ� �ο��� �ʰ��Ͽ� �Է��� �� �� �����ϴ�. \n");
			printf("�ִ� %d������� ���� �����մϴ�. \n\n", MAX_COUNT);
		}
		return 0;
	}

	void ShowFriendList(Person* p_firend, int count)
	{
		int i;
		if (count > 0)
		{
			printf("\n��ϵ� ģ�� ���\n");
			printf("================================\n");
			for (i = 0; i < count; i++)
			{
				printf("%-14s, %3d, %6.2f, %6.2f\n", p_firend->name, p_firend->age, p_firend->height, p_firend->weight);
				p_firend++;
			}
			printf("================================\n\n");
		}
		else
		{
			printf("\n�ƽ��Դϴ�. \n\n");
		}
	}


	void main()
	{
		Person friends[MAX_COUNT];
		int count = 0, num;

		while (1)
		{
			printf("	  [ �޴� ]		\n");
			printf("===================	\n");
			printf("1. ģ�� �߰�		\n");
			printf("2. ģ�� ��� ����	\n");
			printf("3. ����				\n");
			printf("===================	\n");
			printf("��ȣ ���� : ");
			scanf("%d", &num);

			if (num == 1)
			{
				if (1 == AddFriend(friends, count)) count++;
			}
			else if (num == 2)
			{
				ShowFriendList(friends, count);
			}
			else if (num == 3)
			{
				break;
			}
			else
			{
				printf("1 ~ 3 ��ȣ�� ������ �� �ֽ��ϴ�!! \n\n");
			}
		}

	}




#pragma endregion


#pragma region malloc �⺻ ���� 1��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		char* p_name;
		// �ڵ����� �� ��ȯ������ �������� ���ִ°� ��������� ���� ��
		// �����ִ°� �ƴ�
		// ���������� �Ҵ����ش����� ù��° �ּҰ� void������ ���⶧����
		// �� void���� �ּҸ� char�� �����ͷ� ���ڴٴ� ��
		// malloc() �Լ��� ����Ͽ� �������� �޸𸮸� �Ҵ�
		p_name = (char*)malloc(32);
		// char�� �迭 32��¥���� �� �� �ְ� ��
		/*
		�� ���� 32����Ʈ�� �޸� ������ �������� �Ҵ��ϰ�,
		p_name �����Ͱ� �� ������ ù ��° �ּҸ� ����Ű���� �����մϴ�.

		if (p_name != NULL) �ٿ����� malloc() �Լ� ȣ���� ����������
		����Ǿ����� Ȯ���մϴ�. malloc() �Լ��� �޸� �Ҵ��� �����ϸ�
		NULL �����͸� ��ȯ�ϱ� �����Դϴ�.

		�� �������� ����ڷκ��� ���ڿ��� �Է¹ޱ� ���� scanf() �Լ���
		����մϴ�.
		*/

		if (p_name != NULL)
		{
			printf("your name : ");
			scanf("%s", p_name);

			printf("Hi~ %s \n", p_name);


			// heap������ �Ҵ�� �޸𸮸� ������ ��
			free(p_name);


			printf("Hi~ %s \n", p_name);
			printf("%p \n", p_name);

		}
		else
		{
			printf("Memory allocations error !");
		}







		return 0;
	}



#pragma endregion


#pragma region malloc �⺻ ���� 2��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		int n = 0;
		scanf("%d", &n);
		// �迭�� ������ �ʱ�ȭ�� int array[n]; �̷��� �ȵǴϱ�
		int* ptr = (int*)malloc(n * sizeof(int));

		if (ptr != NULL)
		{
			for (int i = 0; i < n; i++)
			{
				ptr[i] = i;
				printf("%d ", ptr[i]);
			}

			free(ptr);
		}
		else
		{
			printf("Memory alloctations error !!");
		}






		return 0;
	}




#pragma endregion


#pragma region malloc �⺻ ���� 3��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		int limit = 0, chk = 0, count = 0, sum = 0;
		int* p_score = NULL; // �Ǵ� chk = 0, *p_score = NULL �̶�� �ᵵ �� 

		printf("����� �ִ� ������ �Է� :");
		chk = scanf("%d", &limit);

		if (chk != 1 || limit < 1)
		{
			printf("Error");
			return 1;
		}

		p_score = (int*)malloc(sizeof(int) * limit);
		if (p_score != NULL)
		{
			while (limit > count)
			{
				printf("������ �Է��ϼ���. (9999 �Է��ϸ� ����) : ");
				scanf("%d", p_score + count);

				if (*(p_score + count) == 9999) break;
				count++;
			}


			for (int i = 0; i < count; i++)
			{
				sum = sum + *(p_score + i);
			}

			printf("�Է¹��� ������ ������ %d�� �Դϴ�.", sum);

			free(p_score);
		}




		return 0;
	}



#pragma endregion


#pragma region ���� �޸� �Ҵ� ���� 1~4��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		// 1��
		short data = (short*)malloc(sizeof(short) * 8);

		// 2��
		// �� ��ȯ�� �̷������ ������ void������ �Ҵ�� �ּҸ� ��ȯ������
		// �� ��ȯ�� �̷�������� ��������� ���ֶ�� �ϼ̽��ϴ�

		// 3��
		// Stack , Heap

		// 4��
		int limit = 0, chk = 0, count = 0, sum = 0, average = 0;

		int* p_toeic = NULL;

		printf("����� �ִ� ������? :");
		chk = scanf("%d", &limit);

		if (chk != 1 || limit < 1)
		{
			printf("Error");
			return 1;
		}

		p_toeic = (int*)malloc(sizeof(int) * limit);

		if (p_toeic != NULL)
		{
			while (limit > count)
			{
				printf("������ �Է��ϼ���. (991�� �̻� �Է��ϸ� ����) :");
				scanf("%d", p_toeic + count);

				if (*(p_toeic + count) > 990) break;
				count++;
			}

			for (int i = 0; i < count; i++)
			{
				sum = sum + *(p_toeic + i);
			}
			average = sum / count;
			printf("�Է¹��� ���� ������ �հ�� %d�� �̾� \n", sum);
			printf("�̹� ���� ������ ���� %d�� �̱�. \n", count);
			printf("�Է¹��� ���� ������ ����� %d�� �̾� \n", average);

			free(p_toeic);
		}
		else
		{
			printf("Memory allocations error !");
		}


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
	return 0;
}


