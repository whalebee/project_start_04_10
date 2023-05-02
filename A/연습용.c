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
