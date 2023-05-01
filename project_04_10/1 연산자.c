#include <stdio.h>

void fn_print(); // 구현하지 않고 리턴형이 없는 함수 선언


int main()
{
#pragma region 연산자

	// switch 문

	int score = 100;
	char grade = ' ';

	switch (score / 10)
	{
	case 10:
		printf("축~ 하~ 합~ 니다~~ \n");
		// break 없으면 나올 때까지 계속 읽음
		// break 없으면 참이면 내려갈 때 나오는 조건 다 무시하고 계속 읽음
	case 9:
		grade = 'A';
		break;
	default: // 없어도 됨
		grade = 'F';
	}

	printf("성적은 %c학점입니다. \n", grade);





#pragma endregion

#pragma region 연산자 예제

	// 3번입니다

	// 변수
	int v1 = 0, v2 = 0;
	char cal;
	int result = 0;

	// 입력
	printf("연산에 사용할 정수 두 개와 연산자를 순서대로 입력하세요 \n");
	scanf("%d %d %c", &v1, &v2, &cal);

	// 계산
	if (cal == '+')
	{
		result = v1 + v2;
	}
	else if (cal == '-')
	{
		result = v1 - v2;
	}
	else if (cal == '*')
	{
		result = v1 * v2;
	}
	else if (cal == '/')
	{
		result = v1 / v2;
	}
	else if (cal == '%')
	{
		result = v1 % v2;
	}
	else
	{
		printf("입력이 잘못되었소. \n");
	}

	// 출력
	printf("%d %c %d = %d입니다 \n", v1, cal, v2, result);




	// 4번입니다 !

	// 변수
	int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, chk = 0, avg_result = 0;

	// 입력받기
	printf("점수 다섯개를 입력하세요. \n");
	chk = scanf("%d %d %d %d %d", &s1, &s2, &s3, &s4, &s5);

	//printf("%d", chk);

	// 평균점수 계산식
	if (chk == 5)
	{
		avg_result = (s1 + s2 + s3 + s4 + s5) / chk;
	}
	else
	{
		printf("5개의 점수를 제대로 입력해보세용 \n");
		return 1;
	}

	// 평균점수 미달 점수
	// avg_result와 비교 -> 작은 애들 출력

	printf("평균 점수는 %d점이고, 평균점수 미만은 ", avg_result);

	// 문자열 함수를 쓰지 않고서는 이런 방법밖에 없는걸까..?
	if (s1 < avg_result)
	{
		printf("%d ", s1);
	}

	if (s2 < avg_result)
	{
		printf("%d ", s2);
	}

	if (s3 < avg_result)
	{
		printf("%d ", s3);
	}

	if (s4 < avg_result)
	{
		printf("%d ", s4);
	}

	if (s5 < avg_result)
	{
		printf("%d ", s5);
	}

	// 평균점수 미만이 없을 때
	if (s1 >= avg_result && s2 >= avg_result && s3 >= avg_result && s4 >= avg_result && s5 >= avg_result)
	{
		printf("없습니다 ! \n");
	}
	else
	{
		printf("입니다. \n");
	}

	// 평균점수 미만이 없을 때를
	// count 변수 만들어서 if문 각각에다가 집어넣어가지고 count 개수로 확인하는게 나을 듯




	// 5번입니다

	// 변수지정
	int score = 0, chk_s = 0;
	char grade = 'F';

	// 입력
	printf("점수를 입력해주세요 \n");
	chk_s = scanf("%d", &score);

	// 유효성 검사
	if (chk_s != 1)
	{
		printf("머하시는거임 ㅎㅎ \n");
		return 1;
	}
	else if (score > 100 || score < 1)
	{
		printf("입력한 점수 %d가 유효범위 밖입니다 (유효범위 1 ~ 100)\n", score);
		return 1;
	}
	


	// 계산
	switch (score / 10)
	{
	case 10:
		grade = 'A';
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	}

	// 출력
	printf("입력받은 점수는 %c 학점 입니다. \n", grade);



#pragma endregion



	return 0;
}


void fn_print()
{
	int n1 = 30, n2 = 40;
	printf("%d %d \n", n1, n2);
}


