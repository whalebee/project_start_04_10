
#pragma region 구조체 복습
// start
// #include "header.h"
#include <stdio.h>		// printf
#include <string.h>		// strlen, strcpy 등
#include <stdlib.h>		// atoi, rand, malloc, free, EXIT_SUCCESS 등
#include <conio.h>		// 05-02 : getch
#include <errno.h>		// 05-02 : errno 사용하기 위함

#define MAX_arr 3




typedef struct student
{
	char name[30];
	char subject[30];
	int score;
}STUDENT;





int main()
{
	/*
	이름, 과목, 점수의 멤버를 가진 학생 구조쳬(student)를 만들고
	자료형으로 재정의(STUDENT) 한 후,

	STUDENT형 변수 myStudent를 선언하여
	각 멤버에 데이터를 입력받아서 출력하세요.
	*/

	/*
	struct student myStudent;

	printf("이름 입력");
	scanf("%s", myStudent.name);

	printf("과목 입력");
	scanf("%s", myStudent.subject);

	printf("점수 입력");
	scanf("%d", &myStudent.score);


	printf("이름 : %s \n과목 : %s \n점수 : %d \n", myStudent.name, myStudent.subject, myStudent.score);
	*/



	struct student Myclass[MAX_arr] = {
			{0},
			{0},
			{0}
	};

	// Put_student(Myclass);




	return 0;
}





#pragma endregion


#pragma region 배열 정렬
// start
#include "header.h"


void print_fn(int* arrange, int size);
int sort(int* arrange, int size);


int main()
{

	/*
	// 구구단 2 ~ 9 단

	int n = 0;
	printf("몇 단 부터 할래? 범위 : 2 ~ 9 \n");
	scanf("%d", &n);

	if (n < 2 && n > 9)
	{
		printf("머함 ?");
		return 0;
	}
	else
	{
		for (int i = n; i < 10; i++)
		{
			printf("---- %d단 ---- \n", i);

			for (int j = 1; j < 10; j++)
			{
				printf("%d x %d = %d \n", i, j, i * j);
			}

			puts(" ");
		}
	}
	*/

	// int i = 2, j = 1;
	/*
		for (; i < 10; ++i)
	{
		printf("----%d단----\n", i);

		for (; j < 10; ++j)
		{
			printf("%d x %d = %d \n", i, j, i * j);
		}

		j = 1;
		puts(" ");
	}
	*/

	/*
	while (i < 10)
	{
		printf("----%d단---- \n", i);

		while (j < 10)
		{
			printf("%d x %d = %d \n", i, j, i * j);
			j++;
		}

		i++;
		j = 1;
		puts(" ");
	}
	*/

	/*
	// 총합 100이어도 출력 101이상 그만
	int n = 0, sum = 0;
	for (scanf("%d", &n); n >= 0; scanf("%d", &n))
	{
		sum = sum + n;
		if (sum > 100)
		{
			break;
		}
		printf("입력된 값 : %d \n", n);
		printf("지금까지의 총합 : %d \n", sum);
	}
	printf("총합은 %d 입니다 ! 101 이상이므로 종료합니다 ! \n", sum);	*/


	// 배열
	int arr[] = { 3, 29, 38, 12, 57, 74, 40, 85 ,61 };

	// 정렬 후 : 3 12 29 38 40 57 61 74 85

	int size = sizeof(arr) / sizeof(int);
	// printf("%zd", size);



	// 정렬 전 출력 확인
	print_fn(arr, size);

	// 정렬
	sort(arr, size);

	// 출력 확인
	print_fn(arr, size);

	return 0;
}

void print_fn(int* arrange, int size)
{
	// 확인
	printf("arr[%d] = {", size);
	for (int j = 0; j < size; j++)
	{
		printf("%d", arrange[j]);
		if (j < size - 1) printf(",");
	}
	printf("}\n");
	// 반환 필요 없다 !
}

int sort(int* arrange, int size)
{
	int n = 0, first = 0;

	for (int n = 0; n < size; n++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (arrange[i] > arrange[i + 1])
			{
				first = arrange[i];
				arrange[i] = arrange[i + 1];
				arrange[i + 1] = first;
			}
		}
	}
}










// start
#include "header.h"

#define MAX_arr 3

int COUNT = 0;

typedef struct student
{
	char name[30];
	char subject[30];
	int score;
}STUDENT;


void put_student(STUDENT* myClass);
void print_student(STUDENT* myClass);


int main()
{
	/*
	이름, 과목, 점수의 멤버를 가진 학생 구조쳬(student)를 만들고
	자료형으로 재정의(STUDENT) 한 후,

	STUDENT형 변수 myStudent를 선언하여
	각 멤버에 데이터를 입력받아서 출력하세요.
	*/

	/*
	struct student myStudent;

	printf("이름 입력");
	scanf("%s", myStudent.name);

	printf("과목 입력");
	scanf("%s", myStudent.subject);

	printf("점수 입력");
	scanf("%d", &myStudent.score);


	printf("이름 : %s \n과목 : %s \n점수 : %d \n", myStudent.name, myStudent.subject, myStudent.score);
	*/


	struct student myClass[MAX_arr] = {
			{0},
			{0},
			{0}
	};

	// 입력
	put_student(myClass);

	// 확인
	print_student(myClass);

	return 0;
}

// 2명만 하고 싶다면?
void put_student(STUDENT* myClass)
{
	char check[10] = "\0";

	for (int i = 0; i < MAX_arr; i++)
	{
		printf("이름 입력 : ");
		scanf("%s", myClass[i].name);

		printf("과목 입력 : ");
		scanf("%s", myClass[i].subject);

		printf("점수 입력 : ");
		scanf("%d", &myClass[i].score);

		printf("더 입력할래요? y or n\n");
		scanf("%s", check);

		if (strcmp(check, "n") == 0)
		{
			COUNT = i + 1;
			return;
		}
	}

	COUNT = MAX_arr;
}

void print_student(STUDENT* myClass)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d번째 myClass의 값 = {\n", i + 1);
		printf("name : %s \nsubject : %s \nscore : %d \n", myClass[i].name, myClass[i].subject, myClass[i].score);
		printf("} \n");
	}
}


#pragma endregion


#pragma region 동적할당
#include "header.h"



int main()
{
	// 소문자 대문자
	// 쓸데없는 변수
	// 최적화

	/*
	1. limit_student는 동적할당이 잘 되었는지 체크를 안했고							-ch
	2. 동적할당이 만약 실패했더라도 free함수를 들어가게 코딩되어 있네요.			return 으로 종료시킴
	3. 같은 맥락에서 할당이 실패한 경우에도 점수 확인을 하고 있음.					return 으로 종료시킴
	4. sum/avg를 굳이 다 가지고 있을 필요는 없습니다.								-ch
	5. sum/avg는 int형으로 표현하는 것이 나을 것 같다는 뜻.							-ch
	6. 배열표현과 포인터 표현을 혼용하지 마시고 일치시키는 게 좋을 것 같습니다.		-ch
	*/

	// 반수(미정)와 각 학급의 인원(미정)을 각각 입력 받아 다차원 포인터를 동적할당하고,
	// 각 학생의 점수를 입력 받아서 학급별 평균을 출력하세요.

	// 반수 -> 행
	// 학급의 인원 -> 열

	int limit_grade = 0, score = 0, sum = 0, avg = 0;

	int** myClass = 0;
	int* limit_student = 0;



	printf("몇 반까지 있나? :");
	scanf("%d", &limit_grade);

	myClass = (int**)malloc(sizeof(int*) * limit_grade); // 행
	limit_student = (int*)malloc(sizeof(int) * limit_grade); // 결과물 출력용


	if (myClass != NULL && limit_student != NULL)
	{
		for (int i = 0; i < limit_grade; i++)
		{
			printf("%d학년 학생 수를 입력 : \n", i + 1);
			scanf("%d", limit_student + i);

			myClass[i] = (int*)malloc(sizeof(int) * limit_student[i]); // 열

			if (myClass[i] != NULL)
			{

				for (int j = 0; j < limit_student[i]; j++)
				{
					printf("%d학년 %d번째 학생의 점수를 입력 : ", i + 1, j + 1);
					scanf("%d", &score);
					myClass[i][j] = score;
					// sum += score;
				}
			}
			else
			{
				printf("할당이 안되었소.  \n");
				return 0;
			}
			// printf("%d 학년의 총점 : %d \n", i+1, sum);
		}

	}
	else
	{
		printf("myClass 메모리 할당 실패 ! \n");
		return 0;
	}


	// 확인
	for (int i = 0; i < limit_grade; i++)
	{
		sum = 0;
		for (int j = 0; j < limit_student[i]; j++)
		{
			sum += myClass[i][j];
		}
		avg = sum / limit_student[i];

		printf("%d학년의 총점 %d ,", i + 1, sum);
		printf("평균 %d , ", avg);
		printf("%d학년 전체 점수 : ", i + 1);
		for (int j = 0; j < limit_student[i]; j++)
		{
			printf("%d점 ", myClass[i][j]);
		}
		puts(" ");
	}


	// 해제
	printf("메모리 할당 해제 시작 \n");

	// 2차원 해제
	for (int f = 0; f < limit_grade; f++)
	{
		free(myClass[f]);
	}

	// 1차원 해제
	free(myClass);
	free(limit_student);


	return 0;
}

#pragma endregion