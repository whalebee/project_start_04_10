#include <stdio.h>
#include <string.h>

#define VALUE 10


int main()
{
#pragma region 배열의 기본개념
	int main()
	{
		// 배열 기본
		int arr_int[5] = { 1,2,3,4,5 };
		int where = 0;
		int num = 0;
		int count = 0;
		count = sizeof(arr_int) / sizeof(int);

		// 평범하게 출력
		printf("%d \n", arr_int[0]);
		printf("%d \n", arr_int[1]);
		printf("%d \n", arr_int[2]);
		printf("%d \n", arr_int[3]);
		printf("%d \n", arr_int[4]);

		// 입력받아서 출력
		printf("몇 번째 값을 원해? ( 0부터 시작해 ) \n");
		printf("범위는 0 ~ %zd까지 있어 \n", (sizeof(arr_int) / sizeof(int)) - 1);
		scanf("%d", &where);
		printf("%d번째에 위치해있는 값은 %d \n", where, arr_int[where]);

		// 첫번째 자리부터 끝자리 까지
		for (int i = 0; i < count; i++)
		{
			printf("%d \n", arr_int[i]);
		}

		puts(" ");

		// 끝자리부터 첫번째 자리까지
		for (; count > 0; count--)
		{
			printf("%d \n", arr_int[count - 1]);
		}

		return 0;
	}


#pragma endregion


#pragma region 다차원 배열
	// 다차원 배열

	int arr1[2][3] = { 10, 20, 30, 40, 50, 60 };

	// 다르게 표현
	int arr2[2][3] =
	{
		{10, 20, 30 }
		,{40, 50, 60 }
	};

	// 배열의 길이
	printf("arr1의 배열의 길이는 : %zd \n", sizeof(arr1) / sizeof(int));
	int a = 0;
	int* ptr_a = &a;
	printf("변수 a의 사이즈는 : %d \n", sizeof(ptr_a));


	// 배열의 주소
	printf("arr1 배열의 주소는 : %p \n", arr1);
	printf("arr2 배열의 주소는 : %p \n", &arr2);
	// 뭐지 둘 다 되넹

	// 주소가 차곡차곡 쌓인 다는 것을 확인할 수 있음
	// 끝자리가 34 38 3C 인 것을 확인 -> 사이즈로 확인가능 int형이니까네
	int arr3[3] = { 1,2,3 };
	for (int col = 0; col < 3; col++)
	{
		printf("arr3[%d] 값:%d 주소:%p \n", col, arr3[col], &arr3[col]);
	}


#pragma endregion


#pragma region 다차원 배열 사이즈 구하기
	// 주소가 차곡차곡 쌓인 다는 것을 확인할 수 있음
	// 끝자리가 34 38 3C 인 것을 확인 -> 사이즈로 확인가능 int형이니까네
	int arr1[2][3] = { 1,2,3,4,5,6 };
	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			printf("arr1[%d][%d] 값:%d 주소:%p \n", row, col, arr1[row][col], &arr1[row][col]);
		}
		printf("------------------------------- \n");
	}

	// 다차원 배열은 [][] 이런식으로 생략 불가능
	// 열을 무조건 정해줘야됨 [][3] 이런 건 가능 -> 생략하지마셈 그냥ㅋㅋ
	// [2][] 이건 또 안됨 -> 생략하지마 그냐아앙

	puts(" ");
	puts(" ");
	// 2차원 배열의 크기 구하기
	/*
	전체 크기/1행의 크기 -> 행의 개수가 나옴

	1행의 크기/ 자료형 크기 -> 열의 개수가 나옴
	*/
	int row_max = 0, col_max = 0;

	//행
	row_max = sizeof(arr1) / sizeof(arr1[0]);

	//열
	// sizeof(arr1[0][0])이 곧 하나의 요소 크기를 말하니까 sizeof(int)와 같은 말임
	col_max = sizeof(arr1[0]) / sizeof(arr1[0][0]); // 전체사이즈로 구하기
	// col_max = sizeof(arr1[0]) / sizeof(int); // 사이즈로 구하기

	// 확인
	printf("arr1의 2차원 배열 구조 : arr1[%d][%d] \n", row_max, col_max);

	// 한 요소씩 검증
	puts(" ");
	puts("----row_max와 col_max로 확인하기----");
	for (int row = 0; row < row_max; row++)
	{
		for (int col = 0; col < col_max; col++)
		{
			printf("arr1[%d][%d] 값:%d 주소:%p \n", row, col, arr1[row][col], &arr1[row][col]);
		}
		printf("------------------------------- \n");
	}


#pragma endregion


#pragma region 예제 월 별 강수량
	// float rainfall[60];
	// float rainfall[5][12];

	float rainfall[5][12] =
	{
	{8.5,29.6,49.5,130.3,222,171.5,185.6,202.6,68.5,120.5,79.1,16.4},
	{0,23.8,26.8,47.3,37.8,74,194.4,190.5,139.8,55.5,78.8,22.6},
	{60.5,53.1,16.3,16.9,112.4,139.6,270.4,675.7,181.5,0,120.1,4.6},
	{18.9,7.1,110.9,124.1,183.1,104.6,168.3,211.2,131,57,62.4,7.9},
	{5.5,4.7,102.6,20.4,7.5,393.8,252.3,564.8,201.5,124.1,84.5,13.6}
	};

	int row_max = 0, col_max = 0;

	// 행
	row_max = sizeof(rainfall) / sizeof(rainfall[0]);
	printf("행 확인 : %d \n", row_max);

	// 열
	col_max = sizeof(rainfall[0]) / sizeof(rainfall[0][0]);
	printf("열 확인 : %d \n", col_max);

	// 다시 검사
	printf("확실해? rainfall[%d][%d] \n", row_max, col_max);


	puts(" ");
	for (int row = 0; row <= row_max; row++)
	{
		if (row == 0)
		{
			for (int count = 0; count <= 12; count++)
			{
				if (count == 0)
				{
					printf("  년도");
				}
				else
				{
					printf("%5d월", count);
				}
			}
		}
		else
		{
			printf("\n");

			for (int col = 0; col <= col_max; col++)
			{
				if (col == 0)
				{
					printf("%d년 ", col + 2017 + row);
				}
				else
				{
					printf("%6.1f ", rainfall[row - 1][col - 1]);
				}
			}
			printf("\n");
		}

	}
	


#pragma endregion


#pragma region 고난도 2번 : 선언만 되어있는 배열에 값 넣어주기
	int array[5][5];
	int value = 1;

	for (int row = 0; row < 5; row++)
	{
		if (row % 2 == 0)
		{
			for (int col = 0; col < 5; col++)
			{
				array[row][col] = value++;
			}
		}
		else
		{
			// row가 0부터 시작하니까 이렇게 해야 2번째 행, 4번째 행, 짝수 행들이 영향을 받지
			for (int col = 4; col >= 0; col--)
			{
				array[row][col] = value++;
			}
		}
	}

	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			printf("%3d", array[row][col]);
		}
		printf("\n");
	}


#pragma endregion


#pragma region 고난이도 3번 : 달팽이 못해따
	int array[5][5];
	int value = 1;
	// while 하나, for 2개로 인덱스만 바꿔서 -> 몰라

	int start_row = 0, start_col = 0, max_col = 4, max_row = 4;

	for (int row = 0; row <= max_row; row++)
	{
		if (row == 0)
		{
			for (int col = 0; col <= max_col; col++)
			{
				array[row][col] = value++;
			}
		}
		else if (row >= 1 && row < 4)
		{
			for (int col = 4; col >= max_col; col--)
			{
				array[row][max_col] = value++;
			}
		}
		else if (row == max_row)
		{
			for (int col = 4; col >= 0; col--)
			{
				array[row][col] = value++;
			}
		}
	}

	for (int row = 3; row > 0; row--)
	{
		array[row][0] = value++;
	}

	늠이시벌 모르겠다


		// 결과확인
		for (int row = 0; row < 5; row++)
		{
			for (int col = 0; col < 5; col++)
			{
				printf("%3d", array[row][col]);
			}
			printf("\n");
		}


#pragma endregion


#pragma region 월 별 강수량의 평균량, 최대, 최소
	// float rainfall[60];
	// float rainfall[5][12];

	float rainfall[5][12] =
	{
	{8.5,29.6,49.5,130.3,222,171.5,185.6,202.6,68.5,120.5,79.1,16.4},
	{0,23.8,26.8,47.3,37.8,74,194.4,190.5,139.8,55.5,78.8,22.6},
	{60.5,53.1,16.3,16.9,112.4,139.6,270.4,675.7,181.5,0,120.1,4.6},
	{18.9,7.1,110.9,124.1,183.1,104.6,168.3,211.2,131,57,62.4,7.9},
	{5.5,4.7,102.6,20.4,7.5,393.8,252.3,564.8,201.5,124.1,84.5,13.6}
	};

	int row_max = 0, col_max = 0;

	// 행
	row_max = sizeof(rainfall) / sizeof(rainfall[0]);
	printf("행 확인 : %d \n", row_max);

	// 열
	col_max = sizeof(rainfall[0]) / sizeof(rainfall[0][0]);
	printf("열 확인 : %d \n", col_max);

	// 다시 검사
	printf("확실해? rainfall[%d][%d] \n", row_max, col_max);


	puts(" ");
	printf("  년도");
	printf("	       년평균 ");
	printf("	  최고강수량 ");
	printf("	최저강수량 ");

	for (int row = 0; row < row_max; row++)
	{
		printf("\n");
		float sum = 0;
		float max = rainfall[0][0];
		float min = rainfall[0][0];

		for (int col = 0; col <= col_max; col++)
		{
			if (col == 0)
			{
				printf("%d년 ", col + 2018 + row);
			}
			else if (col <= col_max)
			{
				sum += rainfall[row][col - 1];

				if (rainfall[row][col - 1] > max)
				{
					max = rainfall[row][col - 1];
				}
				else if (min > rainfall[row][col - 1])
				{
					min = rainfall[row][col - 1];
				}

			}
		}
		float average = sum / col_max;
		printf("%14.2f ", average);
		printf("%14.1f", max);
		printf("%14.1f", min);
		printf("\n");

	}



#pragma endregion


#pragma region 달팽이 답안지
	int ary[50][50];
	int n, max, i, j, x = 0, y = -1, z = 1, num = 1;
	scanf("%d", &n);
	max = n;

	while (max > 0) {
		for (i = 0; i < max; i++) {
			y = y + z;
			ary[x][y] = num;
			num = num + 1;
		}
		max = max - 1;

		for (i = 0; i < max; i++) {
			x = x + z;
			ary[x][y] = num;
			num = num + 1;
		}
		z *= -1; // 와 이걸 이렇게하다니 오졌다


	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%3d ", ary[i][j]);
		}
		printf("\n");
	}


#pragma endregion


#pragma region 답안지 해석
	int main()
	{
		int arr[30][30];
		// 행이나 열의 수가 scanf로 입력할 수 있는 최대 값을 뜻함 !
		// 초과해서 입력했을 시 지정된 배열의 범위 밖을 사용하기 때문에 에러발생
		// 출력했을 때 가운데에 있는 숫자가 행과 열을 곱한 수를 뜻함

		// 좌표 변수(x: 열, y: 행, z: 역행)
		// 원래 좌표는 x가 가로를, y가 세로를 가리키나,
		// 배열의 구조가 arr[2차원 행][1차원 열] 구조로 되어있어서
		// 차원이 늘어날수록 왼쪽으로 늘어나니 그걸 생각하며 구조도 arr[y][x] 이런식으로 하려합니다.
		int z = 1, x = -1, y = 0;
		// 역행을 위한 z는 양수와 음수를 왔다갔다 해야하기 때문에 부호만 변화가 있는 1로 줘야함
		// 열을 위한 x는 인덱스가 0부터 시작하기때문에 -1부터 시작		
		// ( 0부터 시작하면 역행 z 변수를 2번째 루프부터 쓸 수가 없음 )
		
		// 행을 위한 y는 1행부터 시작하기 때문에 0부터 시작				
		// ( 1부터 시작하면 역행 z 변수를 2번째 루프부터 쓸 수가 없음 )

		// 값을 넣어줄 변수(num), 반복문 변수(i,j)
		int num = 1, i, j;

		// 반복문에서 사용할 행과 열의 최대 반복값
		int max = 0;

		// 출력확인과 배열의 크기를 정할 변수
		int get = 0, chk = 0;
		chk = scanf("%d", &get);
		if (chk != 1) // 입력 체크
		{
			printf("입력 오류 \n");
		}
		max = get; // max는 반복문에서 값이 변경되기때문에 출력확인을 위한 get이 따로 필요하다

		// for문보다 while이 더 간편하기 때문에 while문 사용
		while (max > 0)
		{
			// 열부터 시작하기 때문에 열을 위한 for문 시작
			for (i = 0; i < max; i++) // i를 0부터 시작하니까 max의 값 만큼 돌게 된다
			{
				x = x + z; // 2번째 루프부터 역행을 위한 z변수 사용
				arr[y][x] = num; // 좌표(x,y)를 활용하기위한 배열[행][열]로 했으니 arr[x][y]가 아님을 주의
				num += 1; // 값이 1씩 늘어기위한 대입
			}
			max -= 1;
			// 대입이 겹치지 않게 하고, 대입하기 위한 칸의 수가 점점 감소하기 때문에 max가 1씩 감소해야함
			// 입력하는 칸의 수 규칙
			// 5 4 4 3 3 2 2 1 1
			// n n-1 n-1 n-2 n-2 ... 1 1
			// 이런식으로 처음을 제외하고는 감소한 뒤에 2번 사용하고 다시 감소해야하기 때문에 이 곳에 위치

			// 행
			for (j = 0; j < max; j++)
			{
				y = y + z; // 처음 y는 1행부터 시작해야함 -> 초기값 y=0, z=1
				arr[y][x] = num;
				num += 1;
			}

			z *= -1;
			// 역행을 위한 음수 부호를 주면서 값은 변하지 않는 -1을 곱
			// 한 번의 루프후에 역행을 도는 규칙때문에 열과 행이 끝난 이 곳에 위치
		}

		// 출력 확인
		for (j = 0; j < get; j++)
		{
			for (i = 0; i < get; i++)
			{
				printf("%4d ", arr[j][i]); // arr[i][j] 아님 주의 !
			}
			puts(" ");
			// printf("\n");
		}

		return 0;
	}


#pragma endregion


#pragma region 포인터 변수의 연산
	int value = 0x12345678;
	char* ptr = (char*)&value; // value는 int형이니까 형 변환

	printf("%c \n", *ptr); // 16진수 7 8 을 10진수로 바꾼 ASCII가(120(10)) x 나오게 됨

	printf("%x \n", *ptr); // 16진수 뽑는 서식문자 %x
	ptr++;
	printf("%x \n", *ptr);
	ptr++;
	printf("%x \n", *ptr);
	ptr++;
	printf("%x \n", *ptr);


	int s_v = 0x12345678;
	short* prt_s = (short*)&s_v; // 형 변환
	printf("%10x %p \n", *prt_s, prt_s); // 16진수 뽑는 서식문자 %x
	prt_s += 1;
	printf("%10x %p \n", *prt_s, prt_s); // 이걸보면 ++은 포인터 변수의 자료형 크기만큼 올라감
	prt_s += 1;
	printf("%10x %p \n", *prt_s, prt_s);
	prt_s += 1;
	printf("%10x %p \n", *prt_s, prt_s);

	//prt_s += 1;	// 이런식으로 쓰면 다음 short형을 보겠다 이런식 1증감이 아니라
					// 자료형의 크기만큼 다음을 보겠다 !


#pragma endregion


#pragma region 포인터 변수 연산 2
	// 포인터 변수 연산
	int value[2] = { 10, 20 };

	int* ptr = &value[0];
	// 또는 int* ptr = value; -> 이래도 똑같음
	// 배열의 이름만 배열의 시작 주소를 가르키는게 가능!, 그냥 변수는 이렇지 않음
	printf("%p \n", value);

	printf("%d \n", *ptr);
	printf("%d \n", (*ptr) + 1);
	printf("%d \n", *(ptr + 1));

	puts(" ");
	// 포인터 변수를 배열처럼 쓰기
	printf("%d \n", ptr[0]);
	printf("%d \n", ptr[1]);

	puts(" ");
	// 배열을 포인터변수처럼 쓰는건데 이렇게 쓰면 헷갈려서 안됨
	printf("%d \n", *value);
	printf("%d \n", *(value + 1));


#pragma endregion


#pragma region 포인터 변수 연산 3
	int value = 10;
	char* ptr = (char*)&value;

	for (int i = 0; i < sizeof(value); i++)
	{
		printf("%d \n", *ptr++);
	}

	puts(" ");
	int v1 = 0x12345678;
	char* ptr_v = (char*)&v1;

	for (int i = 0; i < sizeof(v1); i++)
	{
		printf("%x \n", *ptr_v++); // 결과가 뭔가 이상하네 서식문자를 int형으로 했었으니까..ㅋㅋ
	}

	puts(" ");
	int v2 = 10;
	void* ptr_v2 = &v2;
	// printf("%d \n", *ptr_v2); //오류 남
	// 그래서 밑에처럼 자료형 포인터로 바꿔줘야됨
	printf("%d \n", *(int*)ptr_v2);



	puts(" ");
	int v3 = 0x12345678;
	void* ptr_v3 = &v3;
	printf("%x \n", *(int*)ptr_v3);		//12345678
	printf("%x \n", *(short*)ptr_v3);	//5678
	printf("%x \n", *(char*)ptr_v3);	//78



#pragma endregion


#pragma region void 포인터
	void MyFunc(void* p, char flag)
	{
		if (flag == 0) *(char*)p = 1;
		else if (flag == 1) *(short*)p = 1;
		else *(int*)p = 1;
	}


	int main()
	{
		short data = 5;
		MyFunc(&data, 1);

		// 배열과 문자열은 call by value 자체가 안됨



		return 0;
	}


#pragma endregion


#pragma region 함수 호출 관계
	void swap_v(int a, int b);
	void swap(int*, int*);


	int main()
	{
		int a = 20, b = 60;
		printf("%p \n", &a);

		swap_v(a, b);
		printf("call by value %d %d \n", a, b);

		swap(&a, &b);
		printf("call by reference %d %d \n", a, b);



		return 0;
	}

	// 이런 형태가 call by value
	void swap_v(int a, int b)
	{
		printf("%p \n", &a);
		int temp = a;
		a = b;
		b = temp;
	}

	// 이런 형태가 call by reference
	void swap(int* a, int* b)
	{
		printf("%p \n", &a);
		int temp = *a;
		*a = *b;
		*b = temp;
	}



#pragma endregion

	return 0;
}


