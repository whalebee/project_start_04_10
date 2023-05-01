#include <stdio.h>

#pragma region 포인터와 함수
void fn_test(int);
void TEST(short);
int fn_testt(int);
#pragma endregion


#pragma region 함수사용 예제
// 매개변수와 리턴형이 모두 없는 함수 fn_1()
void fn_1();

// 매개변수 O , 리턴형 X			fn_2()
void fn_2(int a, int b);

// 매개변수 X , 리턴형 O			fn_3()
int fn_3();

// 매개변수 O , 리턴형 O			fn_4()
int fn_4(int a, int b);




#pragma endregion


int main()
{


#pragma region 포인터와 함수

	short birthday = 1018; // short형(2byte) birthday라는 변수를 1018로 초기화

	short* ptr = &birthday;
	// 포인터 변수 ptr 선언. ptr이 가리키는 주소는 short형 자료가 있다.
	//birthday의 주소를 대입

	printf("birthday는 : %hi \n", birthday);
	printf("birthday변수의 주소는 : %p \n", &birthday);
	puts("");
	printf("	ptr : %p \n", ptr);
	printf("	&ptr: %p \n", &ptr);
	printf("	*ptr: %hi \n", *ptr);


	// 참조 포인터를 사용하여  값 변경
	*ptr = 1130;
	printf("updated birthday는 : %hi \n", birthday);


	// 포인터와 함수 사용
	int value = 0;
	int* ptr_value = &value;

	fn_test(&value);

	printf("%d \n", value);


	short tips = 5;
	TEST(&tips);
	printf("%d \n", tips);

	value = fn_testt(value);
	printf("%d \n", value);
	// 포인터를 쓰지 않고 하려면
	// 먼저 함수의 자료형을 바꿔줘야함 void라면 return 을 안 쓸테니까
	// 그리고 함수의 값을 받을 변수를 지정해주고
	// 그 변수를 출력



#pragma endregion


#pragma region 함수사용 예제
	// fn_3 사용
	int value = fn_3();
	if (value == -1)
	{
		printf("입력 오류 \n");
	}
	else
	{
		printf("%d \n", value);
		// printf("%d \n", fn_3()); 이것도 가능은 함
	}


	// fn_4 사용
	int v_4 = fn_4(50, 100);
	printf("%d \n", v_4);



#pragma endregion


#pragma region 예제 1번

	// 1번
	// void 쓰셔야쥬 int를 쓰면 안되쥬
	void donut(int);

	int main()
	{
		int count_donut = 0;
		printf("필요한 도넛의 수 만큼 입력하세용 \n");
		scanf("%d", &count_donut);
		donut(count_donut);



		return 0;
	}

	int donut(int a)
	{
		for (int i = 0; i < a; i++)
		{
			printf("O");
		}
	}





#pragma endregion


#pragma region 2번

	// 2번 두 개의 int형 전달 인자를 사용하며, int형을 리턴 한다.
	// 조건 : 아무 연산이나 상관없이 int형으로 반환하면 됨
	int gear(int, int);

	int main()
	{
		int v1 = 0, v2 = 0, result;
		printf("출력하고 싶은 인자 2개 입력 \n");
		scanf("%d %d", &v1, &v2);
		printf("첫번째 매개변수 : %d \n두번째 매개변수 : %d \n%d + %d = ", v1, v2, v1, v2);
		result = gear(v1, v2);
		printf("%d \n", result);


		return 0;
	}

	int gear(int a, int b)
	{
		return a + b;
	}



#pragma endregion


#pragma region 3번

	// 3번 guess 함수를 전달 인자 없이 int형으로 리턴 한다.
	// 조건 : 아무 연산이나 상관없이 int형으로 반환하면 됨
	int guess();

	int main()
	{
		printf("%d", guess());

		return 0;
	}

	int guess()
	{
		int a = 0, b = 0, chk = 0;
		chk = scanf("%d %d", &a, &b);

		if (chk != 2)
		{
			printf("입력을 잘못하신 듯 \n");
		}

		return a + b;
	}


#pragma endregion


#pragma region 4번 
	// 4번 하나의 double형과 double형 변수의 주소를 전달 인자로 사용하여,
	// 첫 번째 값을 그 위치에 저장
	// 해석: 첫번째 값을 첫번째 변수의 주소값을 이용하여 첫번째 변수의 저장된 값에 저장
	// 아 리턴형 말이 없었으니까 리턴으로 하면 안되나봄ㅋㅋ
	// 애초에 내가 리턴형을 써도 쓸모가 없었구먼
	void stuff_id(double, double*);

	int main()
	{
		// 전달 변수
		double d_v = 5.5;
		stuff_id(d_v, &d_v);
		printf("%lf", d_v);

		return 0;
	}

	void stuff_id(double a, double* ptr_b)
	{
		*ptr_b = a + 10;
		// printf("%lf \n", cal);
		// return cal;
	}


#pragma endregion


#pragma region 5번

	// 5번 하나의 int형 전달 인자를 사용하며, char형을 리턴한다.
	// int형 값을 넣으면 char 형으로 반환이 되어야 함
	// ex) 97 -> a
	char n_to_char(int);


	int main()
	{
		int value = 0;

		scanf("%d", &value);
		// printf("value값은 : %d", value);
		// value = 97;

		char result = n_to_char(value);
		printf("%c \n", result);



		return 0;
	}

	char n_to_char(int a)
	{
		char convert = (char)a;
		return convert;
	}


#pragma endregion


#pragma region 6번
	// 6번 하나의 double형 전달 인자와 하나의 int형 전달 인자를 사용하며, int형 리턴
	// ex) 5.5151 + 15 = int형으로 20나와야됨

	int digits(double, int);

	int main()
	{
		double d_v1 = 0;
		int i_v2 = 0, result = 0;

		scanf("%lf %d", &d_v1, &i_v2);

		result = digits(d_v1, i_v2);
		printf("%d \n", result);

		return 0;
	}

	int digits(double d_a, int i_b)
	{
		int result = 0;
		result = (int)d_a + i_b;

		return result;
	}



#pragma endregion


#pragma region 7번패스 8번
	// 8번 전달인자 없고 int형 리턴 

	int main()
	{
		printf("%d \n", random());

		return 0;
	}


	int random()
	{
		int a = 0, b = 0;
		scanf("%u %u", &a, &b);

		return a + b;
	}



#pragma endregion


#pragma region 9번
	// 9번 add함수는 두 정수를 입력 받아, 두 정수의 합을 int형으로 리턴
	int add(int, int);
	int add_2();

	int main()
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		printf("%d \n", add(a, b));

		// 또는
		/*
		int result = 0;
		result = add_2();
		printf("%d \n", result);
		*/

		return 0;
	}

	int add(int a, int b)
	{
		return a + b;
	}

	int add_2()
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		return a + b;
	}



#pragma endregion


#pragma region 10번
	void salami(int num)
	{
		int count = 0;
		for (count = 1; count <= num; count++)
		{
			printf(" 0 salami mio ! \n");
		}
	}
	매개변수를 받아줄 때 자료형이 없어서 써줬습니다
		num이 2번 정의되어서 빼줬습니다
		num++ 로 되어있으면 무한루프에 빠져서 count로 수정했습니다


#pragma endregion


#pragma region const개념
	int v1 = 0;
	int v2 = 0;

	const int* ptr = &v1; //가능
	// int* const ptr = &v1; // 불가능
	// 양쪽 다 쓸바에 전역변수 쓰셈

	printf("v1의 값은 : %d \n", v1);
	printf("ptr의 값은 : %d \n", *ptr);

	ptr = &v2;


	v1 += 10;
	printf("바뀐 v1의 값은 : %d \n", v1);
	printf("바뀐 ptr의 값은 : %d \n", *ptr);


#pragma endregion






	return 0;
}


#pragma region 포인터와 함수
void fn_test(int* value)
{
	*value += 5;

}

int fn_testt(int value)
{
	value += 5;
	return value;
}

void TEST(short* ptr)
{
	*ptr = 3;
}


#pragma endregion


#pragma region 함수사용 예제
void fn_1()
{
	int value = 5;
	value += 10;

	printf("정수를 입력하세요.");
	scanf("%d", &value);


	printf("fn_1입니다. 입력받은 숫자는 %d입니다. \n", value);
}

void fn_2(int a, int b)
{
	int result = 0;
	result = a + b;
	if (result > 100)
	{
		return; // 출력 안하고 즉시 종료 break와 비슷함
	}
	printf("매개변수로 전달받은 a:%d와 b:%d의 합은 %d입니다. \n", a, b, result);
}


int fn_3()
{
	printf("fn_3 start \n");
	unsigned int a = 0, b = 0, chk = 0;
	chk = scanf("%u %u", &a, &b);

	if (chk != 2)
	{
		return -1;
	}

	printf("fn_3 end \n");
	return a + b;
}

int fn_4(int a, int b)
{
	printf("입력받은 매개변수는 a:%d, b:%d \n", a, b);
	printf("%d + %d = ", a, b);
	return a + b;
}


#pragma endregion
