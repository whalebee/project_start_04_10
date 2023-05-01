#include <stdio.h>

// int returnfalse(int); 파라미터의 자료형도 써줘야한다는 것 !

int main()
{
#pragma region while

	int num = 5;

	/*
	while (num < 5)
	{
		printf("%d \n", ++num);
	}
	*/

	// do while 문법
	do
	{
		printf("%d \n", ++num);
	} while (num < 5);

	printf("반복종료");

	/* 이런식으로도 가능 ( 하지만 드물다 )
	int i = 1;

	for (없어도 됨 위에 있으면; i <= 5; ++i)
	{
		printf("%d \n", i);
	}
	*/

	/* 이런식으로도 가능 2 ( 하지만 굉장히 드물다 없는 수준 )
	int num = 0;
	for ( ; ; )
	{
		printf("%d \n", ++num);
		if (num == 100) break;
	}
	*/

	// 1부터 10까지의 합을 출력 -> 1번만 -> 1번만이라는 건 for문을 나가서 출력하라는거고
	// i는 건드릴 필요가 없을듯 어차피 10번 돌려야하니까
	// 근데 그 숫자들의 합을 넣을 변수를 새로 만들어줘야해
	int sum = 0;

	for (int i = 1; i <= 10; i++)
	{
		sum += i;
	}
	printf("for문의 합계는 : %d \n", sum);

#pragma endregion


#pragma region while문 사용해서 모두 더하기

	int num = 1;
	int sum_w = 0;
	while (num <= 10)
	{
		sum_w += num;
		num++;
		// 1도 넣어줘야하는데 2부터 넣어줬기 때문에 계속 54가 나왔었음
		// 해결방법은 sum_w += num; 이 자리배치때문 !
	}
	printf("while문의 합계는 : %d \n", sum_w);

#pragma endregion


#pragma region 반복문에 조건을 여러가지로 해보기, 입력해서 반복문쓰기

	// 여러가지의 조건들
	for (int i = 0, j = 1; i < 10 && j < 10; i++, j++)
	{
		printf("i는 %d , j는 %d \n", i, j);
	}

	int num = 0;
	for (printf("정수입력\n"); num != 9; scanf("%d", &num))
	{
		printf("%d \n", num);
	}

#pragma endregion


#pragma region 조건식에 함수쓰기(밑에함수)

	// 조건식에 함수도 가능하군용
	for (int i = 1; returnfalse(i); i++)
	{
		printf("%d \n", i);
	}


#pragma endregion


#pragma region 반복문으로 구구단
	// for문으로 2~9단
	// result변수 만들지말고 그냥 printf에서 i * j 를 한 번에 계산해
	for (int i = 2; i < 10; i++)
	{
		printf("for문: %d단 \n", i);
		for (int j = 1; j < 10; j++)
		{
			printf("%d x %d = %d \n", i, j, i * j);
		}
		printf("\n");
	}


	// while문으로 2~9단
	int i = 2;
	int j = 1;
	while (i < 10)
	{
		j = 1;
		printf("while문: %d단 \n", i);
		while (j < 10)
		{
			printf("%d x %d = %d \n", i, j, i * j);
			j++;
		}
		i++;
		printf("\n");
	}


#pragma endregion


#pragma region 반복문으로 문자 추가
	for (char ch = 'A'; ch <= 'Z'; ch++)
	{
		printf("%c \n", ch);
		if (ch == 'E')
		{
			break;
		}
	}

#pragma endregion


#pragma region 반복문으로 구구단할 때 return
	// 2x4까지만 하고 아예 끝내버림
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (i * j == 10) return;
			printf("%d x %d = %d \n", i, j, i * j);
		}
		printf("----------\n");
	}


#pragma endregion


#pragma region 2-2번
// 바이트 크기가 안 맞아서 오류가 난다고 제출했음..


#pragma endregion

#pragma region 3번 
	/*
	#include <stdio.h>


	int fn_three(long);

	int main()
	{
		printf("%d", fn_three(6));

		return 0;
	}

	int fn_three(int a)
	{
		long result = a *= a;
		return result;
	}
	*/
	
	



#pragma endregion

#pragma region 4번
	/*
	결과물을 다 써야하는건지
	결과물을 해석하라는건지 몰라서 둘 다 썼습니다
	
	해석
	1 = 안녕!
	k=1
	k와 k를 곱했을 때 ( k의 제곱이) 26보다 작을 때만
	루프 몸체에서 k는 1이다

	반복할 때마다 k는 2씩 증가한다
	증가할 때
	이제 k는 3 (이런식으로 알려준다)
	
	5의 제곱은 25이라서
	루프 몸체에서 k는 5 라고 말해준 다음에

	2가 증가한 k=7에서
	루프몸체라는 printf 문은 나오지 않고
	종료된다

	결과물
	1: 안녕!
	k=1
	루프 몸체에서 k는 1
	이제 k는 3
	k=3
	루프 몸체에서 k는 3
	이제 k는 5
	k=5
	루프 몸체에서 k는 5
	이제 k는 7
	k=7
	*/
#pragma endregion

#pragma region 5번
	/*
	// 5번 1~10까지 반복문 출력

	for (int i = 1; i <= 10; i++)
	{
		printf("%d \n", i);
	}
	*/
	
#pragma endregion

#pragma region 6번
	/*
	// 6번 10 ~ 1까지 반복문 출력

	for (int i = 10; i >= 1; i--)
	{
		printf("%d \n", i);
	}
	*/
	


#pragma endregion

#pragma region 7번

	/*
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		sum += i;
	}
	printf("for문의 1부터 10까지 총 합계 : %d", sum);


	 -------------------이건 보내지말고 위에 for문만 보내셈
	int num = 1;
	int sum_w = 0;
	while (num <= 10)
	{
		sum_w += num;
		num++;
		// 1도 넣어줘야하는데 2부터 넣어줬기 때문에 계속 54가 나왔었음
		// 해결방법은 sum_w += num; 이 자리배치때문 !
	}
	printf("while문의 1부터 10까지 총 합계 : %d \n", sum_w);
	*/
	

#pragma endregion

#pragma region 예제 8번 ~ 10번
	/* 8번 문제
	
	int i = 0;
	int j = 1;
	for (scanf("%d", &i); j < 10; j++)
	{
		printf("%d x %d = %d \n", i, j, i * j);
	}
	*/

	/* 9번
	int i = 0, j = 0, t = 0;
	scanf("%d", &t);

	// 3을 입력했으면 3번 반복해야해
	for (i=1; i <= t; i++)
	{
		// 1일 때 1번, 2일 때 2번 해야하니까 같거나 작게 (같게만 하면 못 돌지)
		for (j = 1; j <= i; j++)
		{
			// 띄어쓰기 해
			printf("* ");
		}
		printf("\n");
	}
	*/

	/* 10번
	int i = 0, j = 0, t = 0;
	scanf("%d", &t);

	// 반대로시작해야하니까 3 입력했으면 3부터 시작해야돼
	// 그래서 i = t고 1까지 내려가야하니까 조건을 1로 해주되,
	// 1보다 커야 계속 돌아가겠지
	// 1로 작아져야하니까 감소로
	for (i = t; i >= 1; i--)
	{
		for (j = 1; j <= i; j++)
		{
			// 띄어쓰기 있어
			printf("* ");
		}
		printf("\n");
	}
	*/


#pragma endregion

#pragma region 11번
	/* 11번
	int i = 0, sum = 0;

	for (scanf("%d", &i); i >= 0 ; scanf("%d", &i))
	{
		// sum에 i를 넣어서 총합 구해주기
		sum += i;

		// 확인 -> 중간에 확인하지 말자
		// printf("현재 sum의 값은 : %d \n", sum);

		// 탈출조건
		if (sum >= 100)
		{
			printf("100이 넘었으니 종료합니다 ! \n 총 합은 %d 입니다 ! \n", sum);
			break;
		}
		else
		{
			printf("숫자를 더 입력하세용 \n");
		}
	}
	*/


#pragma endregion

#pragma region 12번 - 1
	/* 
	int i = 0, j = 0;
	// int t = 0;
	// scanf("%d", &t);
	// t번 반복해야돼
	// 그림은 5니까 5로 고정

	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= i; j++)
		{
			// 2번째면 2번째칸에 * 써야하니까
			// 같지 않을 때만 공백을 써주고
			// 같으면 * 써줘야지
			// 다르면
			if (j != i)
			{
				printf(" ");
			}
			// 같으면
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	*/

#pragma endregion

#pragma region 12-1번 첫번째 피드백
// 자 12-1번 부터 다시 !

int i = 0, j = 0;

for (i = 1; i <= 5; i++) // 행
{
	for (j = 1; j <= i; j++) // 열
	{
		if (j != i)
		{
			printf(" "); // 여기에 \n이걸 쓰면 어떡하냐
		}
		else
		{
			printf("*");
		}
	}
	printf("\n"); // 열이 끝났으면 다음 행으로 가야죠?
}


#pragma endregion


#pragma region 12 - 2 고정 버전 찍는 곳이 j != i 조건 이용
/*
	int i = 0, j = 0;
	// int t = 0;
	// scanf("%d", &t);
	// t번 반복해야돼
	// 그림은 5니까 5로 고정

	for (i = 1; i <= 5; i++)
	{
		for (j = 5; j >= i; j--)
		{
			// 이건 시작부터가 5여야하니까
			// 다르면
			if (j != i)
			{
				printf(" ");
			}
			// 같으면
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
*/



#pragma endregion


#pragma region 12-2번 첫번째 피드백 j > i 이용
// 자 이제 12-2 번 !
int i = 0, j = 0, n = 5;

for (i = 1; i <= n; i++) // 행
{
	// (1,5) (2,4) (3,3) (4,2) (5,1)
	for (j = n; j >= i; j--) //열 2번째 자리가 작아지니까 감소시켜야쥬?
	{
		if (j > i) // >= 이걸로 해버리면 찍는 곳이 사라지잖아ㅋㅋ
		{
			printf(" ");
		}
		else
		{
			printf("*");
		}
	}
	printf("\n"); // 다음 행으로 넘어가셔야죠?
}



#pragma endregion


#pragma region 12 - 2 scanf 버전
/*
int i = 0, j = 0;
int t = 0;
scanf("%d", &t);
// t번 반복해야돼

for (i = 1; i <= t; i++)
{
	for (j = t; j >= i; j--)
	{
		// 이건 시작부터가 5여야하니까
		// 다르면
		if (j != i)
		{
			printf(" ");
		}
		// 같으면
		else
		{
			printf("*");
		}
	}
	printf("\n");
}
*/


#pragma endregion

#pragma region 13번
/*
	int i = 0, j = 0, b = 0;
	// 그림은 5단 트리로 고정되어있고 입력받는 다는 얘기는 없으니까

	// 12-2 여기서부터 채워서 하나씩 해보자

	for (i = 1; i <= 5; i++) // 행 5번 돌리겠다는 뜻이고
	{
		// 자 이제서야 왼쪽 다 채웠다
		for (j = 1; j <= 5; j++) // 열 얘도 5번 돌리겠다는 뜻이고
		{
			// j가 5일 때 별이 있어야해 
			// - i 해준 이 부분 때문에 5번째 열에서 별로 가는거야
			if (j <= 5 - i)  // 공백
			{
				printf(" ");
			}
			else // 별 5(열) <= 5 - 1 (1행) 별 줘
			{
				printf("*");
			}
		}
		// 이제 오른쪽이야
		// 첫번째 행 한칸 띄워야된다
		for (j = 1; j <= 5; j++) // 열
		{
			// j가 1일 때 별이 있어야하고
			// j가 5일 때 별은 없어야해
			// i가 1 일 때 첫번째를 제외하고 모두 공백이되어야한다면?
			// = 을 붙여야 첫번째칸이 비워지면서 마지막 별이 한 개씩 사라지지
			if (j >= i)  // 공백
			{
				printf(" ");
			}
			else // 별
			{
				printf("*");
			}
		}
		printf("\n");
	}
*/


#pragma endregion

#pragma region 14번
	/*
	// 9줄짜리 X
	int i = 0, j = 0;

	for (i = 1; i <= 9; i++) // 행
	{
		// 1행에서 열은 1~9까지 간다
		// 열의 조건이 끝나야 다음 행으로 이동하니까
		// 그렇다면 별의 위치는?
		// 1행에서 1열, 9열 체크
		// 2행에서 2열, 8열 체크
		// 3행에서 3열, 7열 체크
		for (j = 1; j <= 9; j++) // 열
		{
			// 열이 행과 같을 때 마다 별을 출력해야하고
			// (1,1) (2,2) (3,3) (4,4) (5,5) ... (9,9) 이 조건은 j == i 인데
			// (1,9) (2,8) (3,7) (4,6) (5,5) ... (9,1) 이건 어떻게 할까
			// OR써서 가운데 별이 중복되지 않게 해야하니까
			// 이것도 열과 행의 값이 같을 때의 조건으로 체크해줘야됨
			// 1행 == 9(총 열) - 9(현재 열) 흠..
			// 총 열 - 현재 열 해보면 행 보다 1 모자르니까
			// 총 열 - 현재 열 + 1 해주면 행과 같네
			if (j == i || 9 - j + 1 == i)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");

	}
*/



#pragma endregion







	return 0;
}

