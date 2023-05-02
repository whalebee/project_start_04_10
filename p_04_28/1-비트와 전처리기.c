#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
#pragma region 비트 연산자 기본 개념
	//비트연산자 기본개념
	int a = 0x12345678;

	printf("%p \n", &a);

	a = a << 1;
	a = a << 1;
	a = a << 2;

	printf("%x \n", a);
	/*
	printf("%d \n", a << 1);
	printf("%d \n", a << 2);
	printf("%d \n", (a << 2) + 10); // 비트 연산 중 홀수 연산은 짝수로 곱해준 다음 +수 를 한 번 해주면 됨

										12345678
	4번 << 갔다는 전제				   2345678 0
								결과: 23 45 67 80 이 됨
	*/



	int b = 10;
	printf("%d \n", a >> 1);
	printf("%d \n", a >> 2);


#pragma endregion


#pragma region 비트 연산자 AND, OR ( 과제 있음 )
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	typedef unsigned char u_char;
	u_char bit_to_0(u_char, u_char);
	u_char bit_to_1(u_char, u_char);

	u_char callTheRoll(u_char);

	u_char getTobit(u_char);

	u_char re_getTobit(u_char);

	int main()
	{
		// 비트연산자의 AND -> 0으로 바꿔주겠어
		u_char lamp_state = 0x7F;					// 0111 1111 : 0x7F
		printf("lamp_state : %x \n", lamp_state);

		lamp_state = bit_to_0(lamp_state, 3);		// ( 0부터 시작해서 ) 3번째 비트를 바꾸겠다 !
		printf("AND 연산 후 : %x \n", lamp_state);	// 0111 0111 : 0x77

		// 비트연산자의 OR -> 1로 바꿔주겠어
		lamp_state = bit_to_1(lamp_state, 3);
		printf("OR 연산 후 : %x \n", lamp_state);	// 0111 1111 : 0x7F


		// 이건 걍 해봄 ㅋㅋ
		callTheRoll(lamp_state);


		// 10진수를 2진수로 변환
		getTobit(10); // 00001010
		//puts(" ");
		getTobit(18); // 00010010
		//puts(" ");
		getTobit(127);


		return 0;
	}

	u_char bit_to_0(u_char dest_data, u_char bit_num)
	{
		if (bit_num < 8)
		{
			dest_data = dest_data & ~(0x01 << bit_num); // 원하는 비트 수까지 시프트하고 NOT으로 반전
			// 비트 연산은 & 이게 AND, | 이게 OR
		}
		return dest_data;
	}

	u_char bit_to_1(u_char dest_data, u_char bit_num)
	{
		if (bit_num < 8)
		{
			dest_data = dest_data | (0x01 << bit_num);
		}
		return dest_data;
	}

	u_char callTheRoll(u_char dest_data)
	{
		u_char temp;
		for (int i = 0; i < 8; i++)
		{
			temp = dest_data & (0x01 << i);
			if (temp == 0)
			{
				printf("%d번 학생 결석.... \n", i + 1);
			}
			else
			{
				printf("%d번 학생 출석 ! \n", i + 1);
			}
		}
		puts(" ");
	}

	u_char getTobit(u_char dest_data)
	{
		for (int i = 7; i >= 0; i--)
		{
			//거꾸로 나옴 -> 0부터가 아니라 비트 최대 크기수 - 1 부터 해야할 듯
			u_char temp;
			temp = dest_data & (0x01 << i);
			if (temp == 0)
			{
				printf("0");
			}
			else
			{
				printf("1");
			}
		}
		puts(" ");
	}


	u_char re_getTobit(u_char data)
	{

	}



#pragma endregion


#pragma region 비트 연산자 XOR을 이용한 암호화
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		char string[50];
		int key = 28;

		printf("문자열을 입력하세요. \n");
		scanf("%[^\n]s", string);
		getchar();

		int i = 0;
		while (string[i] != '\0')
		{
			string[i] = string[i] ^ key;
			i++;
		}
		printf("%s 로 암호화가 되었습니다 ! \n", string);


		i = 0;
		while (string[i] != '\0')
		{
			string[i] = string[i] ^ key;
			i++;
		}
		printf("%s 로 복호화 되었습니다 ! \n", string);


		return 0;
	}




#pragma endregion


#pragma region 재귀함수 사용 과제
#include <stdio.h>

	void re_getBit(int n);

	int main()
	{
		int num = 0, chk = 0;
		printf("정수를 입력하세요 ! \n");
		chk = scanf("%d", &num);
		if (chk == 0)
		{
			printf("입력오류 ! \n");
			return 1;
		}

		printf("입력한 정수의 2진수 값은 : ");
		re_getBit(num);
		return 0;
	}

	void re_getBit(int n)
	{
		// 10
		// 00001010
		// 재귀함수 사용

		// 무한으로 도는 듯 if문 넣어줘야할 듯
		if (n / 2 != 0)
		{
			re_getBit(n / 2);
		}
		

		printf("%d ", n % 2);

	}





#pragma endregion


#pragma region 비트 연산자 예제 1 ~ 2번
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	int revSign();

	int main()
	{
		// 1번
		revSign();

		// 2번
		puts(" ");
		int b = 3;
		printf("3*8/2 = %d \n", (b << 3) >> 1);

		return 0;
	}
	int revSign()
	{
		int num = 0, chk = 0;
		// 0000 1010
		// 2의 보수 1111 0101
		// +1		1111 0110
		printf("정수를 입력하세요 : ");
		chk = scanf("%d", &num);
		if (chk == 0)
		{
			printf("입력오류");
			return 0;
		}
		printf("입력하신 %d의 부호를 바꾸면 %d입니다. \n", num, (~num) + 1);
	}



#pragma endregion


#pragma region 전처리기
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ADD(a,b) a+b

	int add(int a, int b);

	int main()
	{
		printf("1. ADD(1,2) : %d \n", ADD(1, 2));
		printf("1. ADD(1,2) : %d \n", ADD(1, 2));

		printf("3. ADD(1,2)*2 : %d \n", ADD(1, 2) * 2); // a+b 로 치환을 하게 됨 a+b*2 이렇게 읽음
		printf("4. add(1,2)*2 : %d \n", add(1, 2) * 2);

		return 0;
	}

	int add(int a, int b)
	{
		return a + b;
	}



#pragma endregion


#pragma region rand 함수
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define getrandom(min, max) ((rand()%(int)(((max)+1)-(min)))+(min))

	int main()
	{
		srand((unsigned int)time(NULL));

		for (int i = 0; i < 5; i++)
		{
			// 이렇게 하면 45이하의 중복된 수가 나옴
			//printf("%d ", rand()%46);
			printf("%d ", getrandom(100, 150));
		}

		return 0;
	}




#pragma endregion


#pragma region 전처리기 활용
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #뒤에 온 건 문자열화 하겠다 ! 라는 뜻
#define stringer( x ) printf_s( #x "\n")
#define NAME_VALUE(target) printf("%s : %d \n", #target, target)

#define paster(n) printf_s("token" #n " = %d ", token##n)
	int token9 = 99;

#define XN(n) x ## n

	enum Days { MON, TUE, WED, THU, FRI, SAT, SUN };


	int main()
	{
		/* "" 까지 다 출력이 됨 ( 호출이 아니라서 )
		stringer(In quotes in the printf function call);
		stringer("In quotes when printed to the screen");
		stringer("This:\" prints an escaped double quote");
		*/

		NAME_VALUE(MON);
		printf("%s : %d \n", "MON", MON);


		paster(9);
		// ## 은 연결이라서 token##9 -> token9로 된 것

		puts(" ");
		int XN(1) = 10;
		int XN(2) = 20;
		// 변수를 선언할 수 있는 전처리기 활용법
		printf("x1에 저장 된 값은 %d입니다. \n", x1);
		printf("x2에 저장 된 값은 %d입니다. \n", x2);

		return 0;
	}




#pragma endregion


#pragma region #undef와 #define
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define ADD(x,y) x+y

	int main()
	{
		int array[MAX];
#undef MAX //  MAX 사라져 !
		int array2[MAX];

		printf("%d", ADD(10, 20));
#undef ADD // ADD 전처리기 사라져 !
		printf("%d", ADD(10, 20));

		return 0;
	}




#pragma endregion


#pragma region 전처리 지시자 예제 6번
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a,b,c) ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c))

	int main()
	{
		printf("%d \n", MAX(15, 2, 5));
		printf("%d \n", MAX(15, 32, 5));
		printf("%d \n", MAX(15, 32, 58));

		return 0;
	}

	// 3번
	다음 소스를 실행하면 콘솔에 출력되는 결과는 ? 5
	#define  CAL(x,y) (( x < y ) ? (x) : (y))
		void main() {
		printf("%d", CAL(10, 5));
	}

	// 4번
	Hello!world 가 출력 되도록 매크로 함수를 정의하세요.
	#include <stdio.h>
	#define ①result(x,y) x,y
		void main() {}
	printf(②”%s%s”, result("Hello!", "world"));




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


#pragma region



#pragma endregion



	return 0;
}


