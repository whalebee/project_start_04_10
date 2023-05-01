#include <stdio.h>
#include <string.h>

#define VALUE 10


int main()
{
#pragma region 예제 3번 알아야할 것들
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
	// 2차원 배열이란 매개변수를 함수로 던지는 것
	void fn_sum(const int(*)[5], int);

	int main()
	{
		// 3번
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

		//확인
		for (int i = 0; i < size; i++)
		{
			printf("%d번째 총액은 : %d \n", i + 1, total[i]);
		}
	}



#pragma endregion


#pragma region 예제 4번 최적화
	
	
	// 숫자 입력하다가 -1 나오면 마지막 3개의 숫자 출력
	// 4번 답안지
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

	// 음수 인덱스가 나오는 것을 방지하기 위해
	int start = i - 3 < 0 ? 0 : i - 3;

	for (int j = start; j < i; j++)
	{
		printf("%d ", value[j]);
	}



#pragma endregion


#pragma region 구조체 기본개념
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
	// 구조체 정의
	// 정의할 때는 ;
	struct book {
		char title[MAXTITL];
		char author[MAXAUTL];
		int price;
	};

	int main()
	{
		// 구조체 사용
		// 사용할 때는 ,
		struct book myBook = {
			.title = "Do it! C언어 입문",
			.author = "김상식",
			.price = 25000
		}; // semicolon 써야됨


		printf("책이름	: %s \n", myBook.title);
		printf("저자	: %s 씨 \n", myBook.author);
		printf("가격	: %d원\n", myBook.price);

		struct book myBook2;


		char test[100];
		// scanf("%s", test);
		// Do it! C언어 입문 이라고 입력했을 때
		// scanf는 입력단위가 화이트 스페이스라서 Do밖에 안들어감
		// printf("짤려욧 %s", test);

		scanf("%[^\n]s", test);

		// scanf("%[^\n]s", test); 엔터까지 입력받겠다
		// scanf("%[^a]s", test); a까지 입력받겠다

		printf("안 짤리는 %s", test);




		int a;






		return 0;
	}




#pragma endregion


#pragma region 구조체 예제 1~4번 내가 한 것
	
	
	// 1 ~ 2 번을 위한 구조체
	struct book myBook = {
	.title = "Do it! C언어 입문",
	.author = "김상식",
	.price = 25000
	};

	// 1번
	printf("%s \n", myBook.author);

	// 2번
	printf("%d \n", myBook.price);

	// 3번
	struct student myStudent = {
		.name = " ",
		.subject = " ",
		.score = 0
	};

	// 4번
	printf("과목을 입력해 (문자) \n");
	scanf("%[^\n]s", myStudent.subject);

	printf("이름을 입력해 (문자)\n");
	scanf("%s", myStudent.name);

	printf("점수를 입력해 (숫자 1 ~ 100)\n");
	scanf("%d", &myStudent.score);

	// 결과 확인
	printf("이름은 : %s \n", myStudent.name);
	printf("과목은 : %s \n", myStudent.subject);
	printf("점수는 : %d \n", myStudent.score);


#pragma endregion


#pragma region 구조체 예제 답안지
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
	// 구조체 정의
	// 정의할 때는 ;
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

		// 1번

		// 배열의 이름은 포인터 상수라서 선언할 때 말고는 이렇게 넣어야됨
		strcpy(myBook.title, "Do it! C언어 입문");
		strcpy(myBook.author, "김상식");
		myBook.price = 25000;

		// 2번
		printf("%s \n", myBook.author);
		printf("%d \n", myBook.price);


		// 3번
		struct student myStudent;
		// 4번
		printf("이름 써  ");
		scanf("%s", myStudent.name);

		printf("과목 써  ");
		scanf("%s", myStudent.subject);

		printf("점수 써  ");
		scanf("%d", &myStudent.score);


		printf("이름 : %s \n과목 : %s \n점수 : %d",
			myStudent.name, myStudent.subject, myStudent.score);


		return 0;
	}


#pragma endregion


#pragma region 구조체 배열
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	// 강제는 아니고 까먹을까봐 define 사용한 것
#define MAXTITL 31
#define MAXAUTL 21
#define MAXARRL 3

// 구조체 정의
// 정의할 때는 ;
	struct book {
		char title[MAXTITL];
		char author[MAXAUTL];
		int price;
	};



	int main()
	{
		struct book myBook[MAXARRL] = {
			{.title = "Do it ! C언어 입문", .price = 150000000, .author = "김상식씨"},
			{"공부 좀 하란마리아DB", "김성당씨", 13500},
			{"라떼는 리눅스도 없었어", "김부장님", 3500}
		};

		printf("                                      주소\n");
		for (int i = 0; i < MAXARRL; i++)
		{
			printf("책이름	: %-25s %p \n", myBook[i].title, &myBook[i].title);
			printf("저자	: %-25s %p \n", myBook[i].author, &myBook[i].author);
			printf("가격	: %-25d %p \n", myBook[i].price, &myBook[i].price);
			printf("------------------------------ \n");
		}

		return 0;
	}




#pragma endregion


#pragma region 구조체 배열 예제 1 ~ 2번
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXARRL 3
	// 1번 문제 구조체
	struct school
	{
		char name[20];
		char school_name[20];
		int grade;
	};

	// 2번 문제 구조체
	struct score
	{
		char subject[10];
		int grade;
	};


	int main()
	{


		// 1번
		struct school mySchool;

		printf("이름은? ");
		scanf("%s", mySchool.name);

		printf("학교는? ");
		scanf("%s", mySchool.school_name);

		printf("학년은? ");
		scanf("%d", &mySchool.grade);

		printf("Name : %s\nSchool : %s\nGrade : %d \n", mySchool.name, mySchool.school_name, mySchool.grade);



		// 2번
		struct score myScore[MAXARRL] = {
			{0},
			{0},
			{0}
		};

		puts(" ");
		int sum = 0;
		for (int i = 0; i < MAXARRL; i++)
		{
			printf("과목을 입력하세요 : ");
			scanf("%s", myScore[i].subject);
			// printf("%s", myScore[i].subject);

			printf("점수를 입력하세요 : ");
			scanf("%d", &myScore[i].grade);
			// printf("%d", myScore[i].grade);

			sum += myScore[i].grade;
		}

		puts(" ");
		printf("과목은 : ");
		for (int i = 0; i < MAXARRL; i++)
		{
			printf("%s ", myScore[i].subject);
		}
		printf("\n과목별 점수는 :");
		for (int i = 0; i < MAXARRL; i++)
		{
			printf("%d ", myScore[i].grade);
		}
		puts(" ");
		printf("과목의 총 점수는 %d", sum);






		return 0;
	}



#pragma endregion


#pragma region 구조체 배열 3번
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
			{.name = "김상식", .number = 12341234},
			{"사일러스", 44444444},
			{"아펠리오스", 14285700},
			{"카리나", 73976497},
			{"윈터", 50603842}
		};

		char get_name[30];

		printf("찾으시는 분 성함 입력하세요 : ");
		scanf("%s", get_name);
		// printf("%s", get_name);

		int exists = 0;
		for (int i = 0; i < MAXARRL; i++)
		{
			if (strcmp(&Phone[i].name, &get_name) == 0)
			{
				printf("이름     : %s \n전화번호 : 010%d \n", Phone[i].name, Phone[i].number);
				exists = 1;
				break;
			}
		}
		//그런 사람이 없다면
		if (exists == 0)
		{
			printf("그런 사람 여기 없소이다.");
		}

		return 0;
	}



#pragma endregion


#pragma region p476 예제
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
			printf("\n새로운 친구 정보를 입력하세요\n");
			printf("1. 이름 : ");
			scanf("%s", p_friend->name);

			printf("2. 나이 : ");
			scanf("%hu", &p_friend->age);

			printf("3. 키 : ");
			scanf("%f", &p_friend->height);

			printf("4. 몸무게 : ");
			scanf("%f", &p_friend->weight);

			printf("입력을 완료했습니다. \n\n");
			return 1;
		}
		else
		{
			printf("최대 인원을 초과하여 입력을 할 수 없습니다. \n");
			printf("최대 %d명까지만 관리 가능합니다. \n\n", MAX_COUNT);
		}
		return 0;
	}

	void ShowFriendList(Person* p_firend, int count)
	{
		int i;
		if (count > 0)
		{
			printf("\n등록된 친구 목록\n");
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
			printf("\n아싸입니다. \n\n");
		}
	}


	void main()
	{
		Person friends[MAX_COUNT];
		int count = 0, num;

		while (1)
		{
			printf("	  [ 메뉴 ]		\n");
			printf("===================	\n");
			printf("1. 친구 추가		\n");
			printf("2. 친구 목록 보기	\n");
			printf("3. 종료				\n");
			printf("===================	\n");
			printf("번호 선택 : ");
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
				printf("1 ~ 3 번호만 선택할 수 있습니다!! \n\n");
			}
		}

	}




#pragma endregion


#pragma region malloc 기본 개념 1번
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		char* p_name;
		// 자동으로 형 변환되지만 수동으로 해주는게 명시적으로 써준 것
		// 던져주는게 아님
		// 동적영역을 할당해준다음에 첫번째 주소가 void형으로 오기때문에
		// 그 void형의 주소를 char형 포인터로 쓰겠다는 뜻
		// malloc() 함수를 사용하여 동적으로 메모리를 할당
		p_name = (char*)malloc(32);
		// char형 배열 32개짜리를 쓸 수 있게 됨
		/*
		이 줄은 32바이트의 메모리 공간을 동적으로 할당하고,
		p_name 포인터가 이 공간의 첫 번째 주소를 가리키도록 설정합니다.

		if (p_name != NULL) 줄에서는 malloc() 함수 호출이 성공적으로
		수행되었는지 확인합니다. malloc() 함수는 메모리 할당이 실패하면
		NULL 포인터를 반환하기 때문입니다.

		그 다음에는 사용자로부터 문자열을 입력받기 위해 scanf() 함수를
		사용합니다.
		*/

		if (p_name != NULL)
		{
			printf("your name : ");
			scanf("%s", p_name);

			printf("Hi~ %s \n", p_name);


			// heap영역에 할당된 메모리를 삭제한 것
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


#pragma region malloc 기본 개념 2번
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		int n = 0;
		scanf("%d", &n);
		// 배열은 변수로 초기화가 int array[n]; 이렇게 안되니까
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


#pragma region malloc 기본 개념 3번
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		int limit = 0, chk = 0, count = 0, sum = 0;
		int* p_score = NULL; // 또는 chk = 0, *p_score = NULL 이라고 써도 됨 

		printf("사용할 최대 개수를 입력 :");
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
				printf("점수를 입력하세요. (9999 입력하면 종료) : ");
				scanf("%d", p_score + count);

				if (*(p_score + count) == 9999) break;
				count++;
			}


			for (int i = 0; i < count; i++)
			{
				sum = sum + *(p_score + i);
			}

			printf("입력받은 점수의 총점은 %d점 입니다.", sum);

			free(p_score);
		}




		return 0;
	}



#pragma endregion


#pragma region 동적 메모리 할당 예제 1~4번
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		// 1번
		short data = (short*)malloc(sizeof(short) * 8);

		// 2번
		// 형 변환이 이루어지지 않으면 void형으로 할당된 주소를 반환하지만
		// 형 변환이 이루어지더라도 명시적으로 써주라고 하셨습니다

		// 3번
		// Stack , Heap

		// 4번
		int limit = 0, chk = 0, count = 0, sum = 0, average = 0;

		int* p_toeic = NULL;

		printf("사용할 최대 개수는? :");
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
				printf("점수를 입력하세요. (991점 이상 입력하면 종료) :");
				scanf("%d", p_toeic + count);

				if (*(p_toeic + count) > 990) break;
				count++;
			}

			for (int i = 0; i < count; i++)
			{
				sum = sum + *(p_toeic + i);
			}
			average = sum / count;
			printf("입력받은 토익 점수의 합계는 %d점 이야 \n", sum);
			printf("이번 시험 응시자 수는 %d명 이군. \n", count);
			printf("입력받은 토익 점수의 평균은 %d점 이야 \n", average);

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


