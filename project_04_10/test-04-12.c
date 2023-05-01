#include <stdio.h>
#define FORMAT "%s! C는 멋지다! \n"

int main()
{

#pragma region 연산자
	
	
	// 정수계산과 실수계산
	printf("%f \n", (float)(10 / 3)); // 3.000000 정수형들끼리의 계산은 소수점을 버려버림
	printf("%f \n", (float)(10.0 / 3.0)); // 3.333333
	// 혼합하면 부동소수점(실수)으로 계산을 해버림

	// 나머지
	printf("%d \n", 10 % 3);
	

	int a = 10;
	printf("%d \n", ++a); // 1. 11
	printf("%d \n", a++); // 2. 11 -> a는 12로 되어있지만 결과만 11로 나옴

	if (a == 10)
	{
		printf("a는 %d입니당. ", a);
	}
	else
	{
		printf("a는 10이 아니오. a는 %d(으)로 되어있소. \n", a);
	}

	/*
	if (a = 0)
	{
		여기에 올 수가 없음
		0만 아니면 모두 참, 음수나 소수 모두 참으로 나옴
	}
	else
	{
		!가 붙는 거 아닌 이상 무조건 여기임 왜 ? 조건이 FALSE가 나오니까
	}
	*/

	double d = 10;
	int i = 10.12345;

	char c = 10;
	short s = 20;

	double sum = 10 + 10.123;

	double cast_sum = (int)1.6 + (int)1.7;
	double cast_sum1 = (int)(1.6 + 1.7);

	double impicit_cast = 1.6 + 1.7; 

	printf("%.2lf, %.2lf \n", cast_sum, cast_sum1);



	// 검증

	int x = 22.0 * 3 / 5;
	printf("x는 %d \n", x);

	int y = x = (2+3)/4;
	printf("y는 %d \n", y);
	printf("x는 %d \n", x);
	int num = 10;
	printf(FORMAT, FORMAT);





	int value1 = 0;
	int value2 = 0;
	
	printf("첫번째 숫자를 입력하세요 \n");
	scanf("%d", &value1);
	printf("첫번째 숫자는 %d 입니다 \n", value1);

	printf("두번째 숫자를 입력하세요 \n");
	scanf("%d", &value2);
	printf("두번째 숫자는 %d 입니다 \n", value1);

	int sum_value = value1 + value2;
	printf("%d 와 %d 의 합은 %d 입니다 ! \n", value1, value2, sum_value);


	int A = 0;
	int B = 0;

	printf("첫번째 숫자를 입력하세요 \n");
	scanf("%d", &A);
	printf("첫번째 숫자는 %d 입니다 \n", A);

	printf("두번째 숫자를 입력하세요 \n");
	scanf("%d", &B);
	printf("두번째 숫자는 %d 입니다 \n", B);

	int Sum_AB = A + B; // 더하기
	printf("A + B = %d \n", Sum_AB);

	int Sub_AB = A - B; // 빼기
	printf("A - B = %d \n", Sub_AB);

	int Mul_AB = A * B; // 곱하기
	printf("A * B = %d \n", Mul_AB);

	int Div_AB = A / B; // 나누기
	printf("A / B = %d \n", Div_AB);

	int Mod_AB = A % B; // 모듈러스
	printf("A % B = %d \n", Mod_AB);

	/* scanf로 문자열 여러개 받기
	5 3 이런식으로 입력하면 됨
	int t1, t2;
	printf("숫자를 두 번 입력하십쇼 !");
	scanf("%d%d", &t1, &t2);
	printf("%d, %d", t1, t2);
	*/


	int number = 15;
	// 정신 좀 차려라 ㅋㅋ else로 가는게 말이되냐 이 짜식아
	if (number > 6) 
	{
		if (number < 12)
			printf("두 번째 if문 \n");
	}
	else {
		printf("몇 번째 if문의 짝일까? \n");
	}
			

	int delivery_charges = 5000;
	int amount = 0;

	// 총 구매금액을 입력받아오거라~
	printf("구매금액을 입력하시오! \n");
	scanf("%d", &amount);
	printf("총 구매금액은 %d원이올시다! \n", amount);

	// if문
	/*
	if (amount >= 50000)
	{
		delivery_charges = 0;
	}
	else
	{
		delivery_charges = 3000;
	}
	*/


	// 삼항 연산자
	delivery_charges = (amount >= 50000 ) ? 0 : 3000;


	printf("배송료는 %d원 입니당. \n", delivery_charges);

	


	/*

	// 년, 월, 일 입력하세용
	int Year = 0;
	int Month = 0;
	int Day = 0;

	printf("4글자로 년도를 입력하세요 \n");
	scanf("%d", &Year);

	printf("2글자로 월을 입력하세요 \n");
	scanf("%d", &Month);

	printf("2글자로 일을 입력하세요 \n");
	scanf("%d", &Day);

	Day++;

	// 2월 일 때
	if (Month == 2)
	{
		// 28일 이면서 2월일 때
		if (Day > 27)
		{
			Day = 1;
			Month++;
		}
	}
	//2월이 아닐 때
	else if (Month != 2 && Day > 31)
	{
		Day = 1;
		Month++;
	}
	else
		printf("제대로 입력하셈\n");

	if (Month == 12)
	{
		Month = 1;
		Year++;
	}

	printf("연습 %d년 %d월 %d일", Year, Month, Day);
	*/


	// 년, 월, 일 입력하세용
	int Year = 0;
	int Month = 0;
	int Day = 0;
	int result = 1; // 비정상일 때 결과나오지 않게 하기 위한

	printf("년도를 입력하세요 ex) 2023 \n");
	scanf("%d", &Year);

	printf("월을 입력하세요 \n");
	scanf("%d", &Month);

	printf("일을 입력하세요 \n");
	scanf("%d", &Day);


	//Month 12월 이하
	if (Month <= 12)
	{
		//2월일 때
		if (Month == 2)
		{
			//28일이라서 넘어가야할 때
			if (Day == 28)
			{
				Day = 1;
				Month++;
			}
		}
		//4월 6월 9월 11월 일 때
		else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
		{
			// 30일이라 넘어가야할 때
			if (Day == 30)
			{
				Day = 1;
				Month++;
			}
		}
		//12월 일 때
		else if (Month == 12)
		{
			// 년도 바꾸기
			if (Day == 31)
			{
				Day = 1;
				Month = 1;
				Year++;
			}
		}
		// 나머지 달 ( 1, 3, 4, 5, 7, 8, 10 )
		else
		{
			// 31일이라서 넘어가야할 때
			if (Day == 31)
			{
				Day = 1;
				Month++;
			}
			// 30일 이하
			else if (Day <= 30)
			{
				Day++;
			}
			// 비정상
			else
			{
				printf("그런 날짜 없 그 등? \n");
				result = 0;
			}
		}
	}
	//13월 이상
	else
	{
		//아웃
		printf("%d월은 없다 아아!! \n", Month);
		result = 0;
	}

	// 결과
	if (result)
	{
		printf("결과 : %d년 %d월 %d일", Year, Month, Day);
	}

	// 필수 테스트 
	/*
	2월 25일 o
	28일 o
	12월 31일 o
	6월 30일 o
	31일 o
	10월 30일 o
	31일 o
	32일 o
	*/







#pragma endregion


	




	return 0;
}