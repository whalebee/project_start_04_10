#include <stdio.h> // 표준 입출력 라이브러리

// 다람쥐는 쳇바퀴를 열심히 돌리고 있다ㅎㅎ

/*	
	파일명		: test.c
	parameter	:
	리턴 값		:
	made by		한직교
	최초 작성일	:
	최초 작성자	:
*/

// 인자 2개 더하기 함수
// 만약 main보다 아래에 있었다면 int fn_sum(int v1, int v2);
// 이걸 main위에다가 쓰기만 하면 불러와짐
//int fn_sum(int v1, int v2);





int main()
{
#pragma region 04-10


	printf("Hello C \n");

	int result_main = 0;
	//result_main = fn_sum(5, 10);

	printf("fn_sum의 결과는 %d 입니당 \n", result_main);



#pragma endregion


#pragma region 04-11


	int a = 2147483647;

	unsigned int b = 4294967295;

	int c = 'b';
	int d = b;
	char e = 'c';

	printf("%d \n", a);
	printf("%u \n", b); // ???
	printf("%d \n", c);
	printf("%d \n", d);
	printf("%c \n", e); // char 형으로 뽑겠다
	printf("%d \n", e); // 정수형으로 뽑겠다 -> 형 변환



	int aa;
	long bb;
	char cc;

	printf("a=%zd, 5=%zd, c=%zd \n", sizeof(aa), sizeof(bb), sizeof(cc));


	signed int test = -10;
	char bbb = 'test';

	int p_result = 0;
	p_result = printf("test = %d : %u \n", test, test);

	printf("printf의 리턴값 : %d \n", p_result);


	/*
	int i = 5;
	int j = 7;
	float f = 3.5f;
	float g = 8.72;

	printf("1. %d \n", i, j);
	printf("2. %d %d %d \n", i);
	printf("3. %d %d \n\n", f, g);
	printf("4. %d %d %f %f \n", i, j, f, g);
	*/


	int i = 100;
	int j = 1000;
	int k = 12345;

	printf("[%d] \n", i);
	printf("[%d] \n", j);
	printf("[%d] \n", k);

	// 5자리 오른쪽 정렬
	printf("[%5d] \n", i);
	printf("[%5d] \n", j);
	printf("[%5d] \n", k);

	// 5자리 왼쪽 정렬
	printf("[%-5d] \n", i);
	printf("[%-5d] \n", j);
	printf("[%-5d] \n", k);

	


	float f = 3.5f;
	double pi = 3.14159265;
	// 소수점 1자리까지만 표현해 !
	printf("%.1f \n", f);
	printf("%lfn \n", pi);


	// 소수점 2자리까지 10자리를 0으로 채워줘
	//printf("%010.2lfn \n", pi);

	int Input_Value1 = 0, Chk = 0, Input_Value2 = 0;
	/*
	Chk = scanf("%d \n", &Input_Value);
	_CRT_SECURE_NO_WARNINGS -> 경고 무시 전처리기에 추가*/

	Chk = scanf("%d%d", &Input_Value1, &Input_Value2);

	printf("입력받은 값은 %d와(과) %d 입니다. \n", Input_Value1, Input_Value2);

		// 1.
		printf("오늘부터 본격 c 프로그래밍 수업 \n");
		printf("오늘부터 본격 c 프로그래밍 수업 \n");


		// 2.
		int age = 0;

		printf("당신의 나이는 ?");
		scanf("%d", &age);
		printf("당신은 %d 살이군요. \n", age);


		// 3.
		printf("\\    /\\  \n");
		printf(" )  ( ')  \n");
		printf("(  /  )   \n");
		printf(" \\(__)L   \n");


		// 4.
		// 리터럴 상수의 소수는 기본(default) double로 취급하기 때문에 f를 붙여준 것
		float cost = 12.99f;
		float percent = 80.0f;
		printf("신간 \"불편한 편의점\"을 $%.2f에 드립니다. \n", cost);
		printf("그것은 정가의 %.f%% 가격입니다.\n", percent);


		// 5. 이름요청 -> 입력받고 -> 다시 성 요청 -> 성, 이름 순으로 출력
		// 5번 이미 풀어놔서 그냥 보낼게용 -> 그러지마라 -> ㅇㅋ
		char LastName[20];
		char FirstName[20];
		printf("이름을 입력해주세요 \n");
		scanf("%s", &FirstName);
		printf("성을 입력해주세요 \n");
		scanf("%s", &LastName);
		printf("성:%s 이름: %s 이시네요 \n", LastName, FirstName);


		// 6. 
		char Name[20];

		printf("이름을 입력해주세요 ! \n");
		scanf("%s", &Name);

		// 6-1번 이름 " "로 감싸기
		printf(" \"%s\" \n", Name);

		// 6-2번 필드전체를 큰 따옴표로 감싸기
		printf(" \"%20s\" \n", Name);

		// 6-3 번 왼쪽 정렬
		printf(" \"%-20s\" \n", Name);


		// 7번은 뭐하라는건지 모르겠당
		float speed = 0;
		float FileSize = 0;

		printf("속도가 초당 몇 메가바이트인(MB)가용? \n");
		scanf("%f", &speed);

		printf("파일 크기는 몇 메가바이트(MB)인가용? \n");
		scanf("%f", &FileSize);

		float time = FileSize / speed;

		printf("속도: %.2f \n 파일크기: %.2f \n 다운로드 속도: %.2f \n", speed, FileSize, time);

#pragma endregion





	return 0;
}





int fn_sum1(int v1, int v2)
{
	int result = 0;		// Declare

	result = v1 + v2;	// Assignment : 데이터 할당(대입)
	return result;
}