#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#pragma region 재귀함수 10->2 변환 나머지와 몫 main부분
#include "header.h"

void intToBin(int);

int main()
{
	// 한글 되나여~?
	int input = 0, chk = 0;
	printf("2진수로 변환할 10진수를 입력하세요 : ");

	while (chk != 1)
	{
		chk = scanf("%d", &input);
	}
	intToBin(input);



	return 0;
}





#pragma endregion


#pragma region getchar
#include "header.h"



int main()
{
	// 버퍼관련 입출력 문자

	char input = 0, input2 = 0, dummy = 0;

	printf("문자를 입력하세요 : ");
	input = (char)getchar();	// getchar fn receives return as int type, auto-type transformed
	printf("%c", input);

	puts("");
	do {
		dummy = (char)getchar();
	} while (dummy != '\n');	// while for evade the enter

	input2 = (char)getchar();	// do u think get typing here? omg
	printf("%c", input2);


	return 0;
}




#pragma endregion


#pragma region 버퍼관련 입출력 문자
#include "header.h"

int main()
{
	// 버퍼관련 입출력 문자

	char input = 0, input2 = 0, dummy = 0, input3 = 0, input4 = 0;

	printf("문자를 입력하세요 : ");
	input = (char)getchar();	// getchar fn receives return as int type, auto-type transformed
	printf("getchar() : %c", input);
	puts("");

	// putchar
	printf("putchar() : %d", putchar((int)input)); // putchar는 ASCII로 반환해준다

	puts("");
	/*
	do {
		dummy = (char)getchar();
	} while (dummy != '\n');	// while for evade the enter
	*/


	input2 = (char)getchar();	// do u think get typing here? omg
	printf("getchar() : %c", input2);
	puts("");


	input3 = (char)_getch(); // _getch fn is only!! print you did typing
	printf("_getch() : %c", input3);
	puts("");


	input4 = (char)_getche(); // who are u ?
	printf("_getche() : %c", input4);
	puts("");




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


#pragma region



#pragma endregion


#pragma region



#pragma endregion





