#include <stdio.h>
#define MONTHS 12

int main()
{

#pragma region 인덱스 기본 개념

	// 인덱스
	int max = 3;

	int array[5] = { 1, 2, 3, 4, 5 };

	for (int index = 0; index < 5; index++)
	{
		printf("%d \n", array[index]);
	}
	printf("max로 뽑은 array는 : %d \n", array[max]);


	int day[MONTHS] = { 31,28, 31, 30, 31, 30, 31,31,30,31,30,31 };


	for (int index = 0; index < MONTHS; index++)
	{
		printf("%d월은 말 일이 %d \n", index + 1, day[index]);
	}

#pragma endregion


#pragma region 다음 날 출력 배열 사용

	int max_days[MONTHS] = { 31,28, 31, 30, 31, 30, 31,31,30,31,30,31 };
	int yy = 0, mm = 0, dd = 0, chk = 0;

	printf("enter yy mm dd \n");
	chk = scanf("%d %d %d", &yy, &mm, &dd);

	if (chk != 3 || yy <= 0 || mm < 1 || mm > 12 || dd > max_days[mm - 1]
		|| dd < 1)
	{
		printf("오류");
		return 1;
	}

	printf("입력한 값은 %d년 %d월 %d일 \n", yy, mm, dd);

	dd++;
	if (dd > max_days[mm - 1])
	{
		dd = 1;
		mm++;
		if (mm > 12)
		{
			mm = 1;
			yy++;
		}
	}
	printf("입력한 날짜의 다음 날짜는 %d년 %d월 %d일 \n", yy, mm, dd);




#pragma endregion


#pragma region 문자열

	//string

	char string1[6] = { 'H', 'e', 'l', 'l', 'o', 0 };			//굳 
	char string2[6] = { 'H', 'e', 'l', 'l', 'o', '\0' };			//굳 
	char string3[] = { 'H', 'e', 'l', 'l', 'o', (char)NULL };	//굳 
	char string4[6] = "Hello";	// 편-안
	char string5[] = "Hello";	// 알아서 맨 끝에 NULL문자를 넣음
	// char string6[]; 이건 안됨 길이를 정해주거나 문자열을 넣어줘야됨

	/*
	printf("%s \n", string1);
	printf("%s \n", string2);
	printf("%s \n", string3);
	printf("%s \n", string4);
	printf("%s \n", string5);
	*/

	char practice[10];
	strcpy(practice, "hello");
	practice[5] = '!'; // NULL 자리를 !이걸로 바꿔버리니까 이상하게 출력됨
	printf("%s", practice);

#pragma endregion


#pragma region puts

	// puts 함수

	char input[50] = { 0, };
	int chk = 0;
	puts("문자를 입력하세요. (최대 9글자)");

	chk = scanf("%s", input);

	// scanf는 주소를 매개변수로 전달해야하는데
	// 배열의 이름은 배열의 첫번째 주소를 뜻함
	// &input[0] == input
	// 문자 입력단위는 공란으로 봄
	// hello hi 입력하면 puts에서는 hello만 나온다는 뜻

	puts(input);


	fgets(input, 50, stdin);
	puts(input);



#pragma endregion


#pragma region while문으로 인덱스 사이즈 알아보기
	
	char string[] = "Hello";
	int index = 0;

	while(string[index] != '\0')
	{
		index++;
	} // 결과가 5
	printf("1. %d", index);

	index = 0;
	while (string[index++] != '\0')
	{
		index++;
	} // 결과가 6
	// 증감 후 비교를 하고 나서 while문에 들어가지 않고 출력되기때문

	printf("2. %d", index);




#pragma endregion


#pragma region 사이즈 알아보기
	// 사이즈 알아보기
	char string[] = "Hello";
	int arr_int[6];

	// printf("%u \n", strlen(string));

	// printf("%u \n", sizeof(string));
	// printf("%u \n", sizeof(arr_int)); // int x [6] -> 24바이트

	// printf("%u", sizeof(arr_int) / sizeof(int)); // 이러면 본래의 길이가 나옴


#pragma endregion
	


#pragma region 문자열 붙이기

	// 문자열 붙이기

	char str1[15] = "Hello";
	char str2[] = "World";

	strcat(str1, str2);
	printf("%s", str1);

#pragma endregion


#pragma region 문자열 비교
	// 문자열 비교
	char str1[15] = "Hello";
	char str2[] = "World";

	// strcat(str1, str2);

	printf("%d", strcmp(str1, "Hello"));

	if (!strcmp(str1, "Hello"))
	{
		printf("같다");
	}


#pragma endregion


#pragma region 3번

#define VALUE 10

	int main()
	{
		int arr1[VALUE] = { 1,2,3,4,55,6,7,8,9,10 };
		int max_arr1 = arr1[0];

		for (int i = 0; i < VALUE; i++)
		{
			printf("인덱스의 %d번째 값은 : %d \n", i, arr1[i]);

			if (arr1[i] > max_arr1)
			{
				max_arr1 = arr1[i];
			}
		}
		printf("인덱스들 중 가장 큰 값은 %d \n", max_arr1);
		
		return 0;
	}

#pragma endregion


#pragma region 4번

	double arr1[VALUE] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10 };
	double max_arr1 = arr1[0];
	int max_index = 0; // 인덱스 값 받을 변수 추가

	for (int i = 0; i < VALUE; i++)
	{
		// printf("인덱스의 %d번째 값은 : %.2lf \n", i, arr1[i]);

		if (arr1[i] > max_arr1)
		{
			max_arr1 = arr1[i];
			max_index = i;
		}
	}
	// printf("가장 큰 값은 %.2lf \n", max_arr1);
	printf("가장 큰 값을 가지는 인덱스는 %d \n", max_index);



#pragma endregion


#pragma region 5번
	double arr1[VALUE] = { 1.1,2.2,3.3,4.4,5.5,6.6,76.7,8.8,9.9,55.10 };
	double max_arr1 = arr1[0];
	double min_arr1 = arr1[0]; // 최소값을 구할 변수 추가


	for (int i = 0; i < VALUE; i++)
	{
		// printf("인덱스의 %d번째 값은 : %.2lf \n", i, arr1[i]);

		if (arr1[i] > max_arr1)
		{
			max_arr1 = arr1[i];

		}
		else if (arr1[i] < min_arr1) // if와 else if조건을 동시에 만족하는 경우는 없으니까 else if써준 것
		{
			min_arr1 = arr1[i];
		}

	}
	// printf("가장 큰 값은 %.2lf \n", max_arr1);
	// printf("가장 작은 값은 %.2lf \n", min_arr1);

	printf("%.2lf - %.2lf = %.2lf", max_arr1, min_arr1, max_arr1 - min_arr1);


#pragma endregion


#pragma region 6번
	int arr1[VALUE] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[VALUE] = { 31,32,33,34,35,36,37,38,39,40 };

	int add_arr[VALUE] = { 0, };


	for (int i = 0; i < VALUE; i++)
	{
		add_arr[i] = arr1[i] + arr2[i];
		printf("%d + %d = %d \n", arr1[i], arr2[i], add_arr[i]);

	}

	for (int i = 0; i < VALUE; i++)
	{
		printf("%d ", add_arr[i]);
	}


#pragma endregion


#pragma region 8번
	char say[] = "hi";
	char s_a_y[] = { 'h', 'i', '\0' };
	char say_null[] = { 'h', 'i', (char)NULL };
	char say_zero[] = { 'h', 'i', 0 };

	printf("%s \n", say);
	printf("%s \n", s_a_y);
	printf("%s \n", say_null);
	printf("%s \n", say_zero);


#pragma endregion


#pragma region 9번
	int arr1[] = { 3, 29, 38, 12, 57, 74, 40, 85, 61 };

	int max_arr1 = arr1[0];
	int index_arr1 = 0;

	// 배열 사이즈 확인
	int arr_size = sizeof(arr1) / sizeof(int);
	// printf("배열의 사이즈는 %u \n", sizeof(arr1)/sizeof(int));

	for (int i = 0; i < arr_size; i++)
	{
		if (arr1[i] > max_arr1)
		{
			max_arr1 = arr1[i];
			index_arr1 = i + 1;
		}
	}

	printf("최대값은 %d, 최대값의 위치는 %d번째 입니다. \n", max_arr1, index_arr1);


#pragma endregion


#pragma region 10번
	char str1[20] = "kakao";
	char str2[] = "talk";
	strcat(str1, str2);

	printf("%s", str1);



#pragma endregion





















	return 0;
}




