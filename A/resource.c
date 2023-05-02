#include "header.h"


#pragma region intToBin
void intToBin(int target)
{
	int remainder = target % 2; 
	target /= 2;		 
	if (target >= 2)
	{
		// 재귀함수
		intToBin(target);			
	}
	else
	{
		printf("%d ", target); // remainder 들어가면 안되지 ~ 몫 한 번 찍고		
	}
	printf("%d ", remainder);	// 그 다음 나머지 쫘아아악				
}



#pragma endregion


#pragma region fn_string
void fn_string(char* str)
{
	// 여기 안에서의 str 크기는 4 byte지~ 포인터자네 ~
	printf("fn_string : %d \n", sizeof(str));
	printf("%s \n", str);
}


#pragma endregion


#pragma region fn_string1
void fn_string1(char str[]) // str[] -> 배열이 아니라 포인터 변수로 받은 것
{
	// char const str[] 이런식으로 명확하게 받으면 더 좋을 듯

	//str = "Hi"; 
	// fn_string1 안에 있는 매개변수로 불러온 지역변수의 값 자체를 Hi로 바꾼 것이야
	// 그래서 main함수에 있는 str의 값이 변함이 없는 것
	
	// 여기 안에서의 str 크기는 4 byte지~ 포인터자네 ~
	printf("fn_string 1 : %d \n", sizeof(str));
	printf("%s \n", str);

	// *str = "Hi"; 이렇게하면 이상하게 바뀌고 난리남
	// strcpy(str, "Hi!!!");
	// 이렇게 바꾸면 main함수에서도 바뀐 값으로 출력이 됨


	printf("fn_string1 함수에서의 str : %s \n", str); // 당연히 여기서는 Hi찍히지
}
#pragma endregion


#pragma region strncpy
void fn_string_strncpy(char str[])
{
	strncpy(str, "Hi!!!", 2); // \0 (널문자)를 넣어주지 않음
	// 그래서 main에서 결과가 hillo 이렇게 나와버림
	// 그리고 사이즈 오버해버리면 오류남

	printf("fn_string1 함수에서의 str : %s \n", str); // 당연히 여기서는 Hi찍히지
}
#pragma endregion


#pragma region strcat
void fn_string_strcat(char str[])
{
	printf("%s \n", str);

	strcat(str, "World!");

	printf("%s \n", str);
}
#pragma endregion


#pragma region strcat n 버전 : strncat
void fn_string_strncat(char str[])
{
	printf("%s \n", str);

	strncat(str, "World!", 5);

	printf("%s \n", str);
}
#pragma endregion


// strcmp 사용
void fn_str1_cmp(char str1[], char str2[])
{
	// printf("%d", strcmp(str1, str2));
	if (!strcmp(str1, str2))
	{
		printf("%s (와)과 %s은(는) 같습니다. \n", str1, str2);
	}
	else
	{
		printf("%s (와)과 %s은(는) 다릅니다. \n", str1, str2);
	}
}

// strcmp n버전 : strncmp
void fn_str1_ncmp(char str1[], char str2[])
{
	if (!strncmp(str1, str2, 5))
	{
		printf("%s (와)과 %s은(는) 앞 5자리는 같습니다. \n", str1, str2);
	}
	else
	{
		printf("%s (와)과 %s은(는) 다릅니다. \n", str1, str2);
	}
}


// strchr과 strrchr
void fn_strchr(char str1[])
{
	printf("strchr : %d", strchr(str1, 'n') - str1 + 1); // 위치반환하는 strchr
	// 2 - 0 + 1 이 되는 것

	printf("strrchr : %d", strrchr(str1, 'n') - str1); 
	// r은 reverse 뒤에서부터 계산
}


// strstr 문자열 안에서 문자열 찾기
void fn_strstr(char str1[], char str2[])
{
	// str1 안에서 str2 찾기
	// 찾으면 그 위치의 포인터를 반환함 (char* 타입으로)
	printf("%s", strstr(str1, str2));
}


// 문자열 예제 3번
void test3(char str1[], char str2[])
{
	char temp[10] = "\0";
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);

	// printf("%s %s \n", str1, str2);
}