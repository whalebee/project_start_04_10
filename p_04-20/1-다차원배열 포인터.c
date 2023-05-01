#include <stdio.h>
#include <string.h>

#define VALUE 10


int main()
{
#pragma region 숙제
	short data[9] = { 4, 6, 9, 8, 7, 2, 5, 1, 3 };

	// 1번
	int sum = 0, size = 0, temp = 0;

	// printf("%d \n", sizeof(data) / sizeof(short));
	size = sizeof(data) / sizeof(short);

	for (int i = 1; i < size; i += 2)
	{
		printf("%d \n", data[i]);
		sum += data[i];
	}
	printf("%d \n", sum);

	// 2번
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8 - i; j++) {
			if (data[j] > data[j + 1]) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	
	// 2번 선생님 답
	int size = sizeof(data) / sizeof(data[0]);

	short temp = 0;

	for (int index_a = 0; index_a < size; index_a++)
	{
		for (int index_b = index_a + 1; index_b < size; index_b++)
		{
			if (data[index_a] > data[index_b])
			{
				temp = data[index_a];
				data[index_a] = data[index_b];
				data[index_b] = temp;
			}
		}
	}

	// 출력
	for (int i = 0; i < 9; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");



	// 3번
	// 5는 3번째 행 첫번째 열이네요
	short data_2[3][3] = {
		{4, 6, 9}
		,{8,7,2}
		,{5,1,3}
	};

	// 3번 다른 답들
	short data[9] = { 4, 6, 9, 8, 7, 2, 5, 1, 3 };
	short data_after[3][3] = { 0 };
	int max_row = 3, max_col = 3, row = 0, col = 0;
	int size = sizeof(data) / sizeof(short);


	for (int i = 0; i < 9; i++) {
		if (col == max_col) col = 0, row++;
		data_after[row][col++] = data[i];
	}

	int index = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			data_after[i][j] = data[index++];
			if (data_after[i][j] == 5) {
				printf("2차원배열로 변경 후 5는 after[%d][%d] 입니다.", i, j);
			}

		}
	}

	// 예제1-3-2 feat.민수
	/*
	short after[3][3];
	// 2차원 배열로 변경해서 저장
	for (int i = 0; i < 9; i++)
	{
		after[i / 3][i % 3] = data[i];
	}

	// 출력
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\t", after[i][j]);
		}
		printf("\n");
	}*/


	// 4번
	int arr[4][4];
	int row_max = 4, col_max = 4;
	int value = 1;
	for (int row = 0; row < row_max; row++)
	{
		for (int col = 0; col < col_max; col++)
		{
			arr[row][col] = value++;
			printf("%d \n", arr[row][col]);
		}
	}


	// 5번 변경 전

	int arr[4][4];
	int row_max = 4, col_max = 4, row = 0, col = 0;
	int value = 1;

	/*
	for (int row = 0; row < row_max; row++)
	{
		for (int col = 0; col < col_max; col++)
		{
			arr[row][col] = value++;
			printf("%3d ", arr[row][col]);
		}
		puts(" ");
	}
	*/

	// 5번 변경 후

	for (row = 0; row < row_max; row++)
	{
		for (col = 0; col < col_max; col++)
		{
			arr[row][col] = value++;
		}

	}


	for (row = 0; row < 4; row++) {
		for (col = 0; col < 4; col++) {
			printf("%2d ", arr[col][row]);
		}
		printf("\n");
	}

#pragma endregion


#pragma region 예제

	// 1번
	// 4바이트

	// 2번
	// int형으로 선언한 변수 data에 값 0x12345678이 저장되어 있습니다.
	// data변수에 직접 값을 대입하지 않고 short* 형 포인터를 선언하여
	// data변수의 값을 0x12340412로 변경하는 코드를 작성하세요
	int data = 0x12345678;

	printf("data : %x \n", data);

	short* ptr_data = (short*)&data;
	printf("short형 data : %x \n", *ptr_data);
	*(ptr_data) = 0x0412;
	printf("바뀐 short형 data : %x \n", *ptr_data);

	//2번 확인 0x12340412 로 바꾸는 거
	printf("바뀐 결과 : %x \n", data);

	// 2-1번 0x78340412 로 바꾸는 거
	char* c_ptr_data = (char*)&data;
	printf("char형 data : %x \n", *c_ptr_data);
	*(c_ptr_data + 3) = 0x78;
	printf("바뀐 char형 data : %x \n", *c_ptr_data);

	//2-1번 확인 0x78340412 로 바꾸는 거
	printf("바뀐 결과 : %x \n", data);



	// 3번
	void swap(int* num1, int* num2)
	{
		int temp;
		temp = *num1;
		*num1 = *num2;
		*num2 = temp;
	}

	int a = 100, b = 200;
	swap(&a, &b);
	printf("%d %d \n", a, b); // 200 100


	// 4번
	// int형이라서 int형의 크기만큼 다음 주소부터 읽는다
	// 아무런 전제 없이 p++; 하면 쓰레기 값이나 다른 데이터의 값이 읽히겠지만
	// 예를 들어 번지수가 int형으로 1 ~ 1000까지있고 번지수 마다 1씩 증가한다는 전제하에,
	// 포인터 변수가 다음 주소로 넘어가게 되면
	// 201번지가 나올 것 같습니다.


	// 5번
	char a = 0x12, b = 0x34;
	short c = 0x5678;

	char* ptr_a = &a;
	char* ptr_b = &b;
	short* ptr_c = &c;

	int t = 0x87654321;
	int* ptr_t = &t;
	char* ptr_ch_t = (char*)&t;
	short* ptr_sh_t = (short*)&t;

	// printf("과연 %x \n", *(ptr_ch_t+3));
	*(ptr_ch_t + 3) = *ptr_a;
	// printf("바뀐 값은 %x \n", *(ptr_ch_t + 3));

	*(ptr_ch_t + 2) = *ptr_b;
	// printf("바뀐 값은 %x \n", *(ptr_ch_t + 2));

	// printf("어디를 나타내나 %x \n", *ptr_sh_t);
	*ptr_sh_t = *ptr_c;

	// 결과
	printf("새로운 변수 t의 값은 %x \n", *ptr_t);


	
#pragma endregion 
	

#pragma region 배열 포인터로 표현 방법
	int array[5] = { 1,2,3,4,5 };
	int size = sizeof(array) / sizeof(int);
	int* ptr = array;


	for (int i = 0; i < size; i++)
	{
		printf("%d %d \n", array[i], *(ptr + i));
		printf("%d %d \n", ptr[i], *(array + i)); // 이렇게 써도 됨
		//	printf("%d %d \n", *(array++), *(ptr++));
	}


#pragma endregion


#pragma region 고난도 1번
	// 고난도 1번
	int array[5] = { 1,2,3,4,5 };
	int size = sizeof(array) / sizeof(int);
	int* ptr = array;

	int v1 = 10;
	/*
	*(ptr) = 10;
	*(ptr + 1) = 20;
	*(ptr + 2) = 30;
	for (int i = 0; i < size; i++)
	{
		printf("%d \n", array[i]);
	}
	*/

	for (int i = 0; i < size; i++)
	{
		*(ptr + i) = v1 * (i + 1);
		printf("%d번째 값 %d \n", i + 1, *(ptr + i));
	}

	printf("array 배열은 : ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}


#pragma endregion


#pragma region 배열을 함수에서 쓸 때 포인터 변수로 쓰인다는 뜻은
	void fn_arr(int arr[]);


	int main()
	{

		int arr[5] = { 1,2,3,4,5 };
		printf("main : %d \n", sizeof(arr)); // 여긴 20byte
		fn_arr(arr); // 배열의 이름은 배열의 시작 주소

		for (int i = 0; i < 5; i++)
		{
			printf("결과 : %d \n", arr[i]);
		}

		return 0;
	}

	// 배열의 이름이 매개변수로 들어가면 포인터 변수로 읽힘
	// 즉 리턴이나 포인터 변수 참조연산자를 쓰지 않아도 값이 바뀜
	// int* arr = &arr[0] 이렇게 오는거임
	void fn_arr(int arr[])
	{
		printf("fn_arr : %d \n", sizeof(arr)); // 여긴 4byte로 나옴
		for (int i = 0; i < 5; i++)
		{
			// printf("%d", arr[i]);
			arr[i] *= 10;
		}
	}



#pragma endregion


#pragma region 배열과 함수 예제 3개
	/// fn_arr1 : 포인터의 표기형태로 arr_int 출력
// fn_arr2 : 배열의 표기형태로 arr_int 출력
// fn_arr3 : fn_arr3은 main함수의 arr_int를 전달하여 fn_arr3에서 배열의 총합을 구하여 main에서 출력

	void fn_arr1(int*, int);		// 배열에선 fn_arr1과 fn_arr2가 같은 뜻
	void fn_arr2(int[], int);		// 배열에선 fn_arr1과 fn_arr2가 같은 뜻
	void fn_arr3(int*, int*, int);

	int main()
	{



		// 배열을 함수로 쓸 때는 무조건 포인터 변수를 쓰게 된다.
		// 함수로 넘겨줄 때 모양만 배열임
		int arr_int[5] = { 1,2,3,4,5 };

		int* ptr_arr = arr_int;

		//			서로 같은 말임
		// arr_int[0]	-> *(arr_int + 0)  
		// arr_int[1]	-> *(arr_int + 1)
		// arr_int[2]	-> *(arr_int + 2)
		// arr_int[3]	-> *(arr_int + 3)
		// arr_int[4]	-> *(arr_int + 4)

		int size = sizeof(arr_int) / sizeof(arr_int[0]);
		printf("%d \n", size);
		// 함수 안에서 arr_int의 길이를 알 수 없기 때문에
		// 같이 매개변수로 보낸 것

		fn_arr1(arr_int, size);

		puts(" ");
		puts(" ");

		fn_arr2(arr_int, size);


		puts(" ");
		puts(" ");
		int sum_main = 0;

		fn_arr3(arr_int, &sum_main, size);
		printf("main에서의 총합은 %d", sum_main);

		/*
		주소가 붙은 포인터 연산과 차이

		int arr[3]

		arr은 0x01, 0x05, 0x09 까지 있음

		arr -> 0x01
		&arr -> 0x01
		---------------
		arr+1 -> 0x05
		&arr+1 -> 0x0D

		*/



		return 0;
	}

	void fn_arr1(int* arr, int size)
	{
		//int size = sizeof(arr);
		//printf("size in fn_arr1 : %d \n", size);
		// 포인터의 표기형태로 arr_int 출력
		for (int i = 0; i < size; i++)
		{
			printf("fn_arr1 에서 arr_int[%d] : %d \n", i, *(arr + i));
		}
	}

	void fn_arr2(int arr[], int size)
	{
		//int size = sizeof(arr);
		//printf("size in fn_arr2 : %d \n", size);
		// 배열의 표기형태로 arr_int 출력
		for (int i = 0; i < size; i++)
		{
			arr[i];
			printf("fn_arr2 에서 arr_int[%d] : %d \n", i, arr[i]);
		}
	}

	void fn_arr3(int* arr, int* sum, int size)
	{
		// int size = sizeof(arr);
		//printf("size in fn_arr3 : %d \n", size);

		for (int i = 0; i < size; i++)
		{
			*sum += arr[i];			// 배열 형
			// *sum = +*(arr + i);	//포인터형
			// printf("더하는 중 : %d \n", sum);
		}
	}


#pragma endregion


#pragma region 배열과 함수 예제 다른 답 몇번인지는 모르겄네ㅋㅋ
	void fn_arr(int*, int*);

	int main()
	{
		int arr[5] = { 1,2,3,4,5 };

		printf("%p \n", arr);
		printf("%p \n", arr + 1);
		printf("%p \n", &arr + 1);

		fn_arr(arr, &arr + 1);
		// &arr+1 -> arr 배열의 끝 주소



		return 0;
	}

	void fn_arr(int* start, int* end)
	{
		while (start < end)
		{
			printf("%d ", *(start++));
		}
	}



#pragma endregion


#pragma region 포인터 변수의 리터럴 상수
	char arr_char[12] = "Hello Wolrd";
	char arr_char2[] = "Hello Wolrd";
	char* ptr_char = "Hello World";

	printf("%p %p %p \n", arr_char, arr_char2, ptr_char);
	printf("%s %s %s \n", arr_char, arr_char2, ptr_char);

	// ptr_char 얘는 리터럴 상수가 선언이 되는 메모리 공간에 있기 때문에
	// 주소가 지 혼자 멀리 있음


	arr_char[0] = 'A';
	printf("%s", arr_char);


	//strcpy(arr_char, "Hi World");
	//printf("strcpy : %s", arr_char);


	strcpy(arr_char, "Hi World");
	printf("strcpy : %s\n", arr_char);
	ptr_char = "Hi";
	printf(" %p \n", ptr_char);



#pragma endregion


#pragma region 배열의 다른 선언 방법과 함수
	void fn_1(int[], int);
	void fn_2(int* start, int* end);

	int main()
	{
		int arr1[3] = { 1,2,3 };
		int arr2[] = { 4,5,6 };
		int arr1_size = sizeof(arr1) / sizeof(arr1[0]);

		fn_1(arr1, arr1_size);
		fn_2(arr2, &arr2 + 1);

		return 0;
	}

	// arr1 배열표기로, 사이즈 같이 받아서 arr1 전체 출력
	void fn_1(int arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			printf("%d", arr[i]);
		}
	}

	void fn_2(int* start, int* end)
	{
		while (start < end)
		{
			printf("%d ", *(start++));
		}
	}



#pragma endregion


#pragma region 2차원 배열을 포인터 변수 선언하고 사용
	int main()
	{
		char arr[2][3] = { 'a', 'b', 'c', 'd', 'e', 'f' };

		char* ptr1[3];
		char* ptr2 = arr;

		char(*ptr)[3] = arr; // 2차원 배열의 포인터 변수
		//	ptr +1  -> ptr[1][1] 그러면 이게 가능해짐
		printf("%d %d", sizeof(ptr), sizeof(ptr1));

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%c ", ptr[i][j]); // 이렇게 쓰는게 가능하다는 것
				// printf("%c ", (*(ptr+i))[j]); //이것도 가능은한데 알아만둬 가독성 쓰레기임
			}
		}


		return 0;
	}


#pragma endregion


#pragma region 2차원 배열 함수 사용
	// 2차원 배열은 행 사이즈, 열 사이즈 이렇게 2개 필요해
// 배열 표기 사용한 함수 선언
	void fn_arr(char[][3], int, int);

	// 포인터 표기 사용한 함수 선언
	void fn_arr1(char(*)[3], int, int);

	// 와우
	void fn_arr2(void*, int, int);

	int main()
	{
		char arr[2][3] = { 'a', 'b', 'c', 'd', 'e', 'f' };

		char* ptr1[3];
		char* ptr2 = arr;

		char(*ptr)[3] = arr; // 2차원 배열의 포인터 변수
		//	ptr +1  -> ptr[1][1] 그러면 이게 가능해짐

		// fn_arr(arr, 2, 3);
		// fn_arr1(arr, 2, 3);
		fn_arr2(arr, 2, 3);

		return 0;
	}


	void fn_arr(char arr[][3], int row_len, int col_len)
	{
		for (int row = 0; row < row_len; row++)
		{
			for (int col = 0; col < col_len; col++)
			{
				printf("%c ", arr[row][col]);
			}
			puts(" ");
		}
	}

	void fn_arr1(char(*arr)[3], int row_len, int col_len)
	{
		for (int row = 0; row < row_len; row++)
		{
			for (int col = 0; col < col_len; col++)
			{
				// 2차원 배열의 포인터 표기법 사용 미쳐버려 ( 굳이 쓸 필요없음 )
				printf("%c ", (*(arr + row))[col]);
			}
			puts(" ");
		}
	}


	void fn_arr2(void* arr, int row_len, int col_len)
	{
		int(*arr_int)[3] = arr;

		for (int row = 0; row < row_len; row++)
		{
			for (int col = 0; col < col_len; col++)
			{
				printf("%c ", arr_int[row][col]);
			}
			puts(" ");
		}
	}


#pragma endregion


#pragma region 문자열 변수의 함수 사용
	void fn_string(char[]);

	int main()
	{
		char string1[] = "Hello";

		fn_string(string1);



		return 0;
	}

	// 배열로 받았으니 char형 포인터로 받은 것
	void fn_string(char string1[])
	{
		printf("%s \n", string1);


		// %c로 뽑기 
		int idx = 0;
		while (string1[idx] != (char)NULL) //NULL을 0 으로 써도 되고 '\0' 으로 써도 돼
		{
			printf("%c", string1[idx++]);
		}
	}


#pragma endregion


#pragma region 숙제 예제 1~ 2번
	// 예제 1번
	int arr[3][4] = {
	{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12}
	};

	int row_len = sizeof(arr) / sizeof(arr[0]);
	int col_len = sizeof(arr[0]) / sizeof(arr[0][0]);
	printf("%d \n", col_len);
	printf("%d \n", row_len);

	int(*ptr)[4] = &arr;

	for (int i = 0; i < row_len; i++)
	{
		for (int j = 0; j < col_len; j++)
		{
			printf("%3d ", ptr[i][j]);
			// printf("%3d ", (*(ptr+i))[j]);  // 포인터 표기법
		}
		puts(" ");
	}

	puts(" ");
	puts(" ");
	// 2번
	int* ptr_arr = &arr;
	printf("%d\n", ptr[2][1]);
	// printf("%d\n", (*(ptr+2))[1]);



#pragma endregion


#pragma region 예제 3번 어라 함수사용이였음ㅋㅋ
	int main()
	{




		// 3번
		int salary[2][5] = {
			{200,300,400,500,600},
			{30,60,90,120,150}
		};

		int(*amount)[5] = &salary;
		int total[5];

		int row_len = sizeof(salary) / sizeof(salary[0]);
		int col_len = sizeof(salary[0]) / sizeof(salary[0][0]);

		/*
		for (int i = 0; i < row_len; i++)
		{
			for (int j = 0; j < col_len; j++)
			{
				printf("%d ", amount[i][j]);
			}
			puts(" ");
		}
		*/



		for (int i = 0; i < col_len; i++)
		{
			total[i] = amount[0][i] + amount[1][i];
		}

		//확인
		for (int i = 0; i < col_len; i++)
		{
			printf("%d ", total[i]);
		}

		return 0;
	}



#pragma endregion

#pragma region 3번 함수로 다시 했음
	void fn_sum(const int(*)[5], int);

	int main()
	{
		// 3번
		int salary[2][5] = {
			{200,300,400,500,600},
			{30,60,90,120,150}
		};

		int(*amount)[5] = &salary;
		int total[5];

		int row_len = sizeof(salary) / sizeof(salary[0]);
		int col_len = sizeof(salary[0]) / sizeof(salary[0][0]);
		/*
			for (int i = 0; i < col_len; i++)
		{
			total[i] = amount[0][i] + amount[1][i];
		}
		*/

		fn_sum(salary, 5);


		return 0;
	}

	void fn_sum(int(*salary)[5], int size)
	{
		int total[5];
		for (int i = 0; i < size; i++)
		{
			total[i] = salary[0][i] + salary[1][i];
		}

		//확인
		for (int i = 0; i < size; i++)
		{
			printf("%d번째 총액은 : %d \n", i + 1, total[i]);
		}
	}




#pragma endregion


#pragma region 예제 4번
	int main()
	{
		int arr[100];
		int get_num = 0, count = 0, chk = 0;
		int size = sizeof(arr) / sizeof(arr[0]);

		printf("%d \n", size);
		chk = scanf("%d", &get_num);

		for (int i = 0; i < size; i++)
		{
			chk = scanf("%d", &get_num);
			if (chk != 1)
			{
				printf("오류");
				break;
			}
			else if (get_num == -1) break;

			arr[i] = get_num;
			count++;
		}

		if (count < 3)
		{
			for (int i = 0; i < count; i++)
			{
				printf("%d ", arr[i]);
			}
		}
		else
		{
			for (int i = count - 3; i < count; i++)
			{
				printf("%d ", arr[i]);
			}
		}

		return 0;
	}



#pragma endregion

#pragma region 예제 4번 답안지
	// 4번 답안지
	int value[100];
	int i = 0;

	while (i < 100 && scanf("%d", &value[i]) == 1)
	{
		if (value[i] == -1)
		{
			break;
		}

		i++;
	}

	// 음수 인덱스가 나오는 것을 방지하기 위해
	int start = i - 3 < 0 ? 0 : i - 3;

	for (int j = start; j < i; j++)
	{
		printf("%d ", value[j]);
	}

#pragma endregion





	return 0;
}


