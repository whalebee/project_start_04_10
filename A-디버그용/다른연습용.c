// start
// #include "header.h"
#include <stdio.h>

int isPrime(int num);

int main()
{
	/*
	5. 양수를 하나 입력 받아 1부터 그 수까지의 소수를 출력
	1과 자기자신밖에 없는 녀석
	이걸 어떻게 구할까 
	*/

	int num, i;
	printf("양수 입력 : ");
	scanf_s("%d", &num);

	// 소수냐 아니냐만 반환을 해서 소수면 i를 출력하고 아니면 넘기고?
	for (i = 1; i < num; i++)
	{
		if (isPrime(num))
			printf("%d ", i);
		else printf("ㄴㄴ");
	}

	return 0;
}

// True False ?
int isPrime(int num)
{
	// for문 하나, if문 하나
	int i = 0;
	for (i = 2; i < num; i++)
	{
		if (num % i == 0) return 0;
		else return 1;
	}
	
	// 나머지가 0이여서 배수를 구했다.
	// 나눴을 때 나머지가 0인 녀석(본인)과 나머지가 1(소수)인 녀석
	// 

	// 소수를 어떻게 구할까
	/*
	i == j  && 나눴을 때 몫이 1?
	*/

	// 1부터 num까지 수를 일단 뽑아

}