#include <stdio.h>
#include <string.h>

#define VALUE 10


int main()
{
#pragma region 2차원 포인터
//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		// 2차원 포인터
		int a = 10;
		int* ptr = NULL, ** ptr2 = NULL;

		ptr = &a;
		ptr2 = &ptr; // 2차원 포인터에는 포인터 변수만 사용가능

		printf("a의 주소	: %p,		a의	값: %d \n", &a, a);

		printf("ptr의 주소	: %p,		ptr의	값: %p, 참조하고 있는 주소의 값 : %d \n", &ptr, ptr, *ptr);

		printf("ptr2의 주소	: %p,		ptr2의	값: %p, \n", &ptr2, ptr2);

		printf("ptr2 첫 번째 참조 메모리의 값 : %p \n", *ptr2); // ptr 주소를 나타냄
		printf("ptr2 두 번째 참조 메모리의 값 : %d \n", **ptr2); // ptr의 참조값이 나오게 됨

		return 0;
	}



#pragma endregion


#pragma region 이중 포인터와 2차원 배열
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		// 2중 포인터 사용 -> 모르겠음
		short** pp;
		pp = (short**)malloc(sizeof(short*)); // 여기가 malloc 함수를 통해 heap영역에 행을 선언한 것
		// short* -> 포인터 변수는 4바이트 -> 운영체제에 따라 다르지만 기본 4바이트
		// 포인터 변수는 기본 4바이트라 그런걸까 -> 맞아용

		if (pp != NULL) {
			*pp = (short*)malloc(sizeof(short)); // malloc 함수를 통해 heap영역에 열을 선언한 것
			// short 2바이트
			if (*pp != NULL)
			{
				**pp = 10;
				/*
				printf("**pp : %d \n", **pp);

				printf("pp의 값 %d \n", pp); // ???

				printf("*pp의 주소 : %p \n", &pp);
				printf("*pp의 값 : %hu \n", *pp);
				*/
				free(*pp);
			}
			free(pp);
		}


		// 이중 포인터가 어려워서 잠시 배열로 표현 했을 때
		int limit_table[3] = { 4,2,3 };
		int* ptr[3];

		int grade = 0;

		for (grade = 0; grade < 3; grade++)
		{
			ptr[grade] = (int*)malloc(sizeof(int) * limit_table[grade]);
			printf("%p \n", ptr[grade]);
		}

		for (grade = 0; grade < 3; grade++)
		{
			free(ptr[grade]);

		}

		return 0;
	}




#pragma endregion


#pragma region 내가 인터넷에서 찾은 문제
	//시작
	// https://man-25-1.tistory.com/46
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		int row, col;
		scanf("%d %d", &col, &row);
		char** d_Array;
		char n = 'a' - 1;

		d_Array = (char*)malloc(sizeof(char) * col);

		for (int i = 0; i < row; i++)
		{
			d_Array[i] = (char*)malloc(sizeof(char) * col);
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				n++;
				d_Array[i][j] = n;
				printf("%c ", d_Array[i][j]);
				if (n == 'z')
				{
					n = 'A' - 1;
				}
				else if (n == 'Z') n = 'a' - 1;
			}
			printf("\n");
		}

		for (int i = 0; i < row; i++)
		{
			free(d_Array[i]);
		}
		free(d_Array);


		return 0;
	}




#pragma endregion


#pragma region 이중 포인터와 2차원 배열 예제 1
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		// 결국 2차원 배열을 동적할당으로 사용해서 자유롭게 쓰기위해 이중포인터를 사용할 수 있군.
		int** ptr, score = 0, chk = 0;
		int grade = 0, grade_max = 0;


		int* allcount = 0; // 학생 수 받을 변수

		// 합계와 평균 점수를 위한 변수 선언
		int* sum = 0; // 하드코딩하지말고 malloc을 쓴다면?
		int* avg = 0;



		// 각 학년의 점수 입력 ( 학년과 학생 수의 max값을 모두 입력받았다 )
		printf("몇 학년까지 있는지 입력");
		chk = scanf("%d", &grade_max);

		// 총점이랑 평균 받아야됨
		sum = (int*)malloc(sizeof(int) * grade_max);
		avg = (int*)malloc(sizeof(int) * grade_max);

		// printf("%d \n", sizeof(int));
		// printf("%d \n", sizeof(*ptr));

		ptr = (int**)malloc(sizeof(int*) * grade_max); // 행

		allcount = (int*)malloc(sizeof(int) * grade_max); // 학년 별 학생수를 따로 저장할 공간, 결과출력때문에


		if (ptr != NULL && allcount != NULL && sum != NULL && avg != NULL) // 체크안해주면 역참조 했다고 뭐라함
		{
			// 학년 수
			for (int i = 0; i < grade_max; i++)
			{
				printf("%d학년의 학생 수를 입력 : ", i + 1);
				chk = scanf("%d", allcount + i);

				// ptr로 만든 그 주소(행)안에 넣어줄거라서 *ptr
				*(ptr + i) = (int*)malloc(sizeof(int) * *(allcount + i)); // 열
				if (*(ptr + i) != NULL)
				{
					// int sumsum = 0, avgavg = 0;
					// 학생 수
					for (int j = 0; j < *(allcount + i); j++)
					{
						printf("%d학년 %d번째 학생의 점수를 입력하세요 : ", i + 1, j + 1);
						scanf("%d", &score);
						ptr[i][j] = score;
						sum += score;
						// sumsum += score;
					}
					// avgavg = sumsum / *(allcount + i);
					// printf("%d 학년의 총점 %d : ", i+1, sumsum);
					// printf("%d 학년의 평균 %d : ", i + 1, avgavg);
				}
				*(avg + i) = *(sum + i) / *(allcount + i);
			}
		}



		puts(" ");


		printf("입력받은 점수로 총점과 평균 출력 --------------------- \n");
		if (ptr != NULL && allcount != NULL && sum != NULL && avg != NULL)
		{
			for (int i = 0; i < grade_max; i++)
			{
				printf("%d학년의 ", i + 1);
				printf("총점 %d ,", sum[i]);
				printf("평균 %d , ", *(avg + i));
				printf("%d학년 전체 점수 : ", i + 1);
				for (int j = 0; j < *(allcount + i); j++)
				{
					printf("%d점 ", ptr[i][j]);
				}
				puts(" ");
			}


			/*
					for (int i = 0; i < grade_max; i++)
			{
				for (int j = 0; j < *(allcount + i); j++)
				{
					printf("잘 할당되었을까? ptr[%d][%d] 참조값 : %d \n", i, j, ptr[i][j]);
				}
				printf("잘 할당되었을까? allcount[%d] : %d \n", i, allcount[i]);
				printf("잘 할당되었을까? sum[%d] : %d \n", i, sum[i]);
				printf("잘 할당되었을까? avg[%d] : %d \n", i, avg[i]);
				puts(" ");
			}
			*/



			printf("메모리 할당 해제 시작");
			for (int i = 0; i < grade_max; i++)
			{
				free(ptr[i]);
				puts(" ");
			}

			free(allcount);
			free(ptr);
			free(sum);
			free(avg);



			/*
					for (int i = 0; i < grade_max; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					printf("해제되었겠지? ptr[%d][%d] 주소값 : %p \n", i, j, &ptr[i][j]);
					printf("2차원 배열은 참조값을 넣으면 예외처리 뜬다.. \n");
				}
				printf("해제되었겠지? allcount[%d] : %d \n", i, allcount[i]);
				printf("해제되었겠지? sum[%d] : %d \n", i, sum[i]);
				printf("해제되었겠지? avg[%d] : %d \n", i, avg[i]);
				puts(" ");
			}
			*/


		}



		return 0;
	}





#pragma endregion


#pragma region 2차원 배열 함수 예제
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
	이 함수에서는 메모리 동적 할당을 사용하여 메모리 블록을 할당하고, 
	이 메모리 블록의 주소를 가리키는 포인터를 반환하기 때문에 이중 포인터 int** q로 받아야 합니다.

만약 함수가 인자로 단일 포인터 int* q를 받는다면, 
함수 안에서 q 포인터에 메모리를 동적 할당하더라도 함수 호출자에게 반환되는 것은 q 포인터이며 
메모리 블록의 주소를 저장하지 않기 때문입니다. 그러므로 p가 가리키는 메모리 주소를 변경할 수 없습니다.

따라서 이중 포인터 int** q를 사용하여 
함수가 할당한 메모리 블록의 주소를 q가 가리키는 포인터 변수에 저장하면, 
함수 호출자는 메모리 블록의 주소를 참조할 수 있습니다. 
이는 메모리 블록에 저장된 값을 수정할 수 있도록 하며, 
동적 메모리 할당을 사용할 때 일반적인 관행입니다.
*/


	void GetMyData(int** q) // 여기 조심
	{
		*q = (int*)malloc(40);
	}

	int main()
	{
		int* p;
		GetMyData(&p);
		*p = 5;

		printf("%d", *p);

		free(p);

		return 0;
	}




#pragma endregion


#pragma region 2차원 선생님이 따로 내준 문제.. 아직 못 풀었음 -> 이제 풀었음
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		int row, col;
		scanf("%d %d", &row, &col);

		int number = 0;
		int* arr_avg = (int*)malloc(sizeof(int) * col);
		int* arr_sum = (int*)malloc(sizeof(int) * col);

		int dif = 0;

		arr_avg = (int*)malloc(sizeof(int) * col);
		arr_sum = (int*)malloc(sizeof(int) * col);

		int** arr;

		// 행
		arr = (int**)malloc(sizeof(int*) * row);

		if (arr != NULL)
		{
			for (int i = 0; i < row; i++)
			{

				*(arr + i) = (int*)malloc(sizeof(int) * col); // 열
				if (*(arr + i) != NULL)
				{
					int sum = 0, avg = 0;

					for (int j = 0; j < col; j++)
					{
						printf("%d행 %d열 원소 입력 ! \n", i, j);
						scanf("%d", &number);
						arr[i][j] = number;
						sum += number;
						// printf("%d행 %d열 원소 값 : %d \n", i, j, arr[i][j]);
					}
					arr_sum[i] = sum;
					printf("합계 %d \n", sum);
					arr_avg = sum / col;
					printf("평균 %d \n", avg);

					printf("\n");

					for (int j = 0; j < col; j++)
					{
						if (arr_avg[i] > arr[i][j])
						{
							printf("무엇인고 %d ", *(arr + i)[j]);
							*(arr + i)[j] = 0;

							// printf("와우 %d ", arr[i][j]);
						}
						else
						{
							printf("WTF");
						}
					}


					for (int j = 0; j < col; j++)
					{
						printf("%d ", arr[i][j]);
					}
					puts(" ");
				}



			}


		}



		return 0;
	}



	// 답@@@@@@@@@@@@@@@@@@@@@
	//시작
#include <stdio.h>
#include <stdlib.h>

	int main() {
		int row, col;
		scanf("%d %d", &row, &col);

		int** arr = (int**)malloc(sizeof(int*) * row);
		if (arr == NULL)
		{
			printf("Memory allocation error");
			return -1;
		}

		for (int i = 0; i < row; i++)
		{
			arr[i] = (int*)malloc(sizeof(int) * col);
			if (arr[i] == NULL)
			{
				printf("Memory allocation error");
				return -1;
			}
		}

		for (int i = 0; i < row; i++)
		{
			int sum = 0;
			for (int j = 0; j < col; j++)
			{
				printf("%d행 %d열 원소 입력: ", i, j);
				scanf("%d", &arr[i][j]);
				sum += arr[i][j];
			}

			double avg = (double)sum / col;
			printf("합계: %d, 평균: %.2lf \n", sum, avg);

			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] < avg)
				{
					arr[i][j] = 0;
				}
			}
		}

		// 결과 출력
		puts("");
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				printf("%d ", arr[i][j]);
			}
			puts("");
		}

		// 메모리 할당 해제
		for (int i = 0; i < row; i++)
		{
			free(arr[i]);
		}
		free(arr);

		return 0;
	}



#pragma endregion


#pragma region 구조체와 공용체 기본개념
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 구조체
	struct Test
	{
		char a;		// 1바이트
		short b;		// 2바이트
		int c;			// 4바이트
	};

	// 공용체 ( share house )
	union Test2
	{
		char a;
		short b;
		int c;
	};

	int main()
	{
		// 구조체 사용
		struct Test t1;

		printf("%d \n", sizeof(t1));

		printf("%p \n", &t1.a);
		printf("%p \n", &t1.b);
		printf("%p \n", &t1.c);


		union Test2 t2;

		printf("%d \n", sizeof(t2));
		printf("%p \n", &t2.a);
		printf("%p \n", &t2.b);
		printf("%p \n", &t2.c);

		t2.c = 0x12345678;

		printf("%x \n", t2.a); // 78
		printf("%x \n", t2.b); // 5678
		printf("%x \n", t2.c); // 12345678

		return 0;
	}



#pragma endregion


#pragma region 공용체
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	typedef union comm
	{
		char buffer[5];

		struct
		{
			char version;
			char header;
			char length;
			char address;
		};
	} COMM;

	int main()
	{
		// 공용체
		COMM myComm;
		strcpy(myComm.buffer, "abcd");
		printf("version 부분은 %c \n", myComm.version);		// a
		printf("header 부분은 %c \n", myComm.header);		// b
		printf("length 부분은 %c \n", myComm.length);		// c
		printf("address 부분은 %c \n", myComm.address);	// d

		return 0;
	}



#pragma endregion


#pragma region 열거체 기본개념
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	enum Days { MON, TUE, WED, THU, FRI, SAT, SUN };

	int main()
	{
		// 열거체
		enum Days today;

		// printf("%d %d %d %d %d %d %d", MON, TUE, WED, THU, FRI, SAT, SUN);
		// 디폴트는 1씩 증가하고 수는 마음대로 정해줄 수 있음
		//enum Days { MON=10, TUE=16, WED=25, THU, FRI, SAT, SUN};


		today = MON;
		if (today >= SAT && today <= SUN) puts("오늘은 주말");
		else printf("주말까지 %d일 남았다.", SAT - today); // 이렇게 쓸 수 있음


		return 0;
	}



#pragma endregion


#pragma region 공용체 미니 예제
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	union data
	{
		char c1;
		short num1;
		int num2;
		long long int num3; // == long long
	};

	union data1
	{
		char c1;
		short num1;
		int num2;
	};



	int main()
	{
		// 8바이트
		union data t1;
		printf("%d \n", sizeof(t1));


		// 5678
		/*
		
		*/
		union data1 d1;					// 공용체 data1를 사용하여 d1변수 선언
		d1.num2 = 0x12345678;	// d1변수에 int형으로 0x12345678 을 대입
		printf("%x", d1.num1);		// d1 변수에 있는 값을 short형으로 출력

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



	return 0;
}


