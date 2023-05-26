// start
// #include "header.h"
#include <stdio.h>		// printf
#include <string.h>		// strlen, strcpy 등
#include <stdlib.h>		// atoi, rand, malloc, free, EXIT_SUCCESS 등
#include <conio.h>		// 05-02 : getch
#include <errno.h>		// 05-02 : errno 사용하기 위함

#define MAX_arr 3

void Put_student(STUDENT* Myclass)
{

}


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

