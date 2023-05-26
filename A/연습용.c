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
			scanf("%d", limit_student+i);

			myClass[i] = (int*)malloc(sizeof(int) * limit_student[i]); // 열

			if (myClass[i] != NULL)
			{
				
				for(int j = 0; j < limit_student[i]; j++)
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