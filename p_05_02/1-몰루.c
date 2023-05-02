#include <stdio.h>
#include <string.h>
#include <stdlib.h>




#pragma region 재귀함수 10->2 변환 나머지와 몫 main부분
// start
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
// start
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
// start
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


#pragma region 버퍼관련 입출력 문자열 fgets
// start
#include "header.h"



int main()
{
	char input[10];
	int dummy = 0; // int로 받을거임

	// stdin : 표준입력버퍼 (받아오는 곳을 지정해주는 자리에 stdin이 쓰인 것)
	fgets(input, sizeof(input), stdin);
	printf("%s \n", input); // 9개의 결과가 나오게 됨

	printf("버퍼에 남아있는 내용ㅎㅎ : ");
	do {
		dummy = getchar(); // 버퍼에 있는거 가져와잉
		printf("%c ", dummy);
	} while (dummy != '\n');

	return 0;
}




#pragma endregion


#pragma region 버퍼관련 입출력 문자열 scanf
// start
#include "header.h"



int main()
{
	char input[10];
	int dummy = 0, chk = 0; // int로 받을거임

	chk = scanf("%[^\n]s", input);
	printf("%s \n", input);

	printf("버퍼에 남아있는 내용ㅎㅎ : ");
	do {
		dummy = getchar(); // 버퍼에 있는거 가져와잉
		printf("%c ", dummy);
	} while (dummy != '\n');

	return 0;
}




#pragma endregion


#pragma region puts와 fputs
// start
#include "header.h"



int main()
{
	char input[10], dummy = 0;
	char chk = 0;

	// input에 입력
	chk = fgets(input, sizeof(input), stdin);

	puts(input); // 개행(\n)이 있음
	fputs(input, stdout); // 개행(\n)이 없음 

	printf("%s \n", input);

	/*
	printf("더미에 남은 것은 : ");
	do {
		dummy = getchar();
		printf("%c ", dummy);
	} while (dummy != '\n');
	*/


	/* ㅡ.ㅡ 미완
	입력
	getchar()		// 문자형 (문자 한 개)
	fgets()			// 문자열


	출력
	puts()
	fputs()

	*/

	return 0;
}




#pragma endregion


#pragma region 함수 매개변수 중에서의 함정과 해결을 위한 함수들 (strcpy, strncpy 등)
// start
#include "header.h"



int main()
{
	char test[5];
	// test = "Hi"; // 이거 왜 안되는지 생각해봐 -> 배열이라서
	// fn_string1에 있는 str = "Hi"; 는 왜 되고 얘는 왜 안되는지


	char str[] = "Hello"; // 입력한 글자 수 + 1 만들어지지 ~
	printf("main size : %d \n", sizeof(str));
	printf("%p \n", str);
	fn_string(str);
	fn_string1(str);
	printf("main 함수 출력 후 : %s \n", str);
	printf("%p \n", str);



	return 0;
}




#pragma endregion


#pragma region 문자열 비교와 문자열에서 문자열 찾기
// start
#include "header.h"



int main()
{
	char str1[32] = "Hello, World!";
	char str2[32] = "Hello, C!";
	char str3[32] = "banana";


	// strstr 문자열에서 문자열찾기 -> 함수로 빼
	char find_str[32] = "World";
	char* result = NULL;

	result = strstr(str1, find_str);
	if (result != NULL)
	{
		printf("%s 이 단어가 있네요 \n", result);
	}
	else
	{
		printf("찾는게 없네용");
	}


	fn_str1_cmp(str1, str2);

	puts(" ");

	fn_str1_ncmp(str1, str2);

	fn_strchr(str3);




	return 0;
}



#pragma endregion


#pragma region 문자열 구분 기본 개념
// start
#include "header.h"



int main()
{
	// 문자열 구분

	char str1[] = "Hello World Welcome C Programming";
	char* result = NULL;

	result = strtok(str1, " ");

	while (result != NULL)
	{
		printf("%s \n", result);
		result = strtok(NULL, " "); // 공백대신 #으로 하고 싶으면 위의 문자열에도 #을 넣어야해.
	}

	printf("%s", str1); // 문자열 자체가 바뀌어버림

	return 0;
}




#pragma endregion


#pragma region 문자열 비교와 길이계산
// start
#include "header.h"



int main()
{
	// 문자열의 비교와 길이 계산
	char str1[16] = "I'm 25years old";
	char str2[16] = { '\0', };

	char pattern[] = "0123456789";

	size_t sIndex = 0, sLength = 0;

	// strlen : 배열의 길이가 아니라 문자열의 길이
	printf("sizeof : %d, strlen : %d \n", sizeof(str1), strlen(str1));

	sIndex = strcspn(str1, pattern);
	// sIndex는 strcspn : 문자열 str1과 pattern을 비교하여 pattern에 해당하는 문자가 나왔을 때까지의 수를 반환
	// i'm 공백까지, 2까지 오면 4를 반환하게 됨

	// printf("%d \n", sIndex);

	if (sIndex > 0 && strlen(str1) != sIndex)
	{
		// str1 + sIndex를 하면 문자열 str1에서 25years old를 불러오게 되고
		// 불러온 문자열과 pattern을 비교했을 때
		// pattern 문자열에 해당하는 문자가 2개이므로 sLength는 2를 대입하게 됨
		sLength = strspn(str1 + sIndex, pattern);
		if (sLength > 0)
		{
			// 문자열 str2에다가 str1+sIndex -> 25years old의 상태의 문자열을 sLength만큼(2만큼) 복사
			strncpy(str2, str1 + sIndex, sLength);
			printf("나는 %s살입니다. \n", str2);
		}

	}
	else
	{
		printf("찾는 패턴이 없습니다.");
	}

	return 0;
}




#pragma endregion


#pragma region atoi 함수
// start
#include "header.h"



int main()
{
	char str1[] = "10";
	// printf("%d \n", str1[0]);
	printf("%d \n", atoi(str1) * 5); // 10 * 5 = 50

	return 0;
}



#pragma endregion


#pragma region 문자열 예제 1번
// start
#include "header.h"



int main()
{
	// 1번
	char season[10] = { '\0', };

	// end 누르면 끝
	while (1)
	{
		printf("-------- 4계절 중 한 계절 선택 (종료는 end) : ");
		scanf("%s", season);

		if (strcmp(season, "봄") == 0)
		{
			printf("봄에는 개나리 \n");
		}
		else if (strcmp(season, "여름") == 0)
		{
			printf("여름에는 장미 \n");
		}
		else if (strcmp(season, "가을") == 0)
		{
			printf("가을에는 코스모스 \n");
		}
		else if (strcmp(season, "겨울") == 0)
		{
			printf("겨울에는 매화 \n");
		}
		else if (strcmp(season, "end") == 0)
		{
			printf("end입력으로 죵료 \n"); // 죵료가 뭐야 죵료가ㅋㅋㅋㅋ
			break;
		}
		else
		{
			printf("??? 다시 입력 \n");
		}
	}



	return 0;
}




#pragma endregion


#pragma region 문자열 예제 2번 완성
// start
#include <stdio.h>

int main()
{
	char last_name[10] = "\0";
	char first_name[10] = "\0";
	char full_name[20] = "\0";

	int chk_l = 0, chk_f = 0;


	printf("성을 입력하세요. \n");
	chk_l = scanf("%s", last_name);

	printf("이름을 입력하세요. \n");
	chk_f = scanf("%s", first_name);

	// 굳이 cpy어야하나?
	// cpy 는 =, cat은 +, cmp는 == 라고 보면 될 듯
	strcpy(full_name, last_name);

	// strcat(full_name, " "); -> 한글로 쓸거면 안 띄우는게 나은 듯

	strcat(full_name, first_name);


	printf("성명 : %s", full_name);

	return 0;
}




#pragma endregion


//선생님이 한 거랑 비슷하기 때문에 따로 센세버전은 적지 않겠소 !!
#pragma region 문자열 예제 3번 ( 캡쳐때문에 함수도 복사해옴 )
// start
#include "header.h"

void test3(char str1[], char str2[]);

int main()
{
	char str1[10] = "Hello";
	char str2[10] = "Wolrd";

	test3(str1, str2);
	printf("%s %s \n", str1, str2);

	return 0;
}

void test3(char str1[], char str2[])
{
	char temp[10] = "\0";
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);

	// printf("%s %s \n", str1, str2);
}

#pragma endregion


#pragma region 문자열 예제 1번 센세버전
// start
#include "header.h"



int main()
{
	char input[5] = { '\0', };
	char* season[2][4] = {
		{"봄", "여름", "가을", "겨울"},
		{"개나리", "장미", "코스모스", "매화"}
	};


	int chk = 0;
	printf("계절명 입력, end 입력시 종료");
	while (chk = scanf_s("%s", input, sizeof(input)), strcmp(input, "end") != 0)
	{
		int i = 0;
		for (i = 0; i < 4; i++)
		{
			if (strcmp(input, season[0][i]) == 0)
			{
				puts(season[1][i]);
				break;
			}
		}

		if (i >= 4)
		{
			puts("봄, 여름, 가을, 겨울 중에 입력해");
		}
	}

	return 0;
}




#pragma endregion


#pragma region 문자열 예제 2번 센세버전
// start
#include "header.h"



int main()
{
	char last_name[10] = "\0";
	char first_name[10] = "\0";
	char full_name[20] = "\0";

	puts("성과 이름을 각각 입력하렴");

	gets_s(last_name, sizeof(last_name));
	gets_s(first_name, sizeof(first_name)); // first_name에 사이즈만큼 받아오렴


	strcpy(full_name, last_name);
	strcat(full_name, first_name);

	printf("%s", full_name);

	return 0;
}



#pragma endregion


#pragma region 파일 입출력 읽기&쓰기&해제
// start
#include "header.h"



int main()
{
	//파일 오픈 : fopen()
	FILE* p_file = fopen("test.txt", "at");

	char read[50];
	char haha[50];
	int chk = 0;

	if (NULL != p_file)
	{
		printf("파일 열기 성공 ! \n");

		// 파일 쓰기
		// fputs("파일쓰기", p_file);
		// fscanf(p_file, "%[^\n]s", read);
		// fprintf(p_file, "Hello");		// mode에 따라 다르게 써짐, at면 이어쓰고 wt면 덮어쓰고 ~
		chk = scanf("%s", haha);
		fprintf(p_file, haha);


		// 파일 읽기
		/*
		while (!feof(p_file)) // feof 함수는 파일의 끝에 도달하면 0이 아닌 값을 반환, enter를 개행문자로 인식하여 줄바꿈
		{
			fgets(read, sizeof(read), p_file); // 공백까지 모두 읽어옴
			printf("%s", read);
		}
		*/

		// fscanf는 줄바꿈이 없음 -> 그래서 [^\n] 넣어줌 -> 그랬더니 이상해짐
		/*
		while (EOF != fscanf(p_file, "%[^\n]s", &read))
		{
			printf("%s", read);
		}
		*/




		// 파일클로즈 : fclose()
		fclose(p_file);
	}
	else
	{
		printf("ERR(%d) : %s \n", errno, strerror(errno));
	}

	return 0;
}




#pragma endregion


#pragma region 파일 입출력 읽기와 쓰기의 위치 이동 함수 ( 미완 )
// start
#include "header.h"



int main()
{
	FILE* p_file = fopen("test.txt", "rt"); // at로 하면 이상하게 나와서 rt 읽기 전용으로 모드를 바꿈
	char read[50];

	if (NULL != p_file)
	{
		fgets(read, sizeof(read), p_file);
		printf("%s", read);

		fgets(read, sizeof(read), p_file);
		printf("%s", read);

		fseek(p_file, 5, SEEK_SET);	// SEEK_SET 맨 처음으로 !
		fgets(read, sizeof(read), p_file);
		printf("%s", read);

	}
	else
	{
		printf("ERR(%d) : %s \n", errno, strerror(errno));
	}

	return 0;
}



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion





