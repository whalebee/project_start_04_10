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
