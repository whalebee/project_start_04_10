// start
#include "header.h"

#define MAX_arr 3

int count = 0;

typedef struct student
{
	char name[30];
	char subject[30];
	int score;
}STUDENT;


void Put_student(STUDENT* Myclass);
void print_student(STUDENT* Myclass);


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

	// 입력
	Put_student(Myclass);

	// 확인
	print_student(Myclass);

	return 0;
}

// 2명만 하고 싶다면?
void Put_student(STUDENT* Myclass)
{
	char check[10] = "\0";

	for (int i = 0; i < MAX_arr; i++)
	{
		printf("이름 입력 : ");
		scanf("%s", Myclass[i].name);

		printf("과목 입력 : ");
		scanf("%s", Myclass[i].subject);

		printf("점수 입력 : ");
		scanf("%d", &Myclass[i].score);

		printf("더 입력할래요? y or n\n");
		scanf("%s", check);
		
		if (strcmp(check, "n") == 0)
		{
			count = i + 1;
			return;
		}
	}

	count = MAX_arr;
}

void print_student(STUDENT* Myclass)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d번째 Myclass의 값 = {\n", i+1);
		printf("name : %s \nsubject : %s \nscore : %d \n", Myclass[i].name, Myclass[i].subject, Myclass[i].score);
		printf("} \n");
	}
}
