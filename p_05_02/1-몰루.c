#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#pragma region ����Լ� 10->2 ��ȯ �������� �� main�κ�
#include "header.h"

void intToBin(int);

int main()
{
	// �ѱ� �ǳ���~?
	int input = 0, chk = 0;
	printf("2������ ��ȯ�� 10������ �Է��ϼ��� : ");

	while (chk != 1)
	{
		chk = scanf("%d", &input);
	}
	intToBin(input);



	return 0;
}





#pragma endregion


#pragma region getchar
#include "header.h"



int main()
{
	// ���۰��� ����� ����

	char input = 0, input2 = 0, dummy = 0;

	printf("���ڸ� �Է��ϼ��� : ");
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


#pragma region ���۰��� ����� ����
#include "header.h"

int main()
{
	// ���۰��� ����� ����

	char input = 0, input2 = 0, dummy = 0, input3 = 0, input4 = 0;

	printf("���ڸ� �Է��ϼ��� : ");
	input = (char)getchar();	// getchar fn receives return as int type, auto-type transformed
	printf("getchar() : %c", input);
	puts("");

	// putchar
	printf("putchar() : %d", putchar((int)input)); // putchar�� ASCII�� ��ȯ���ش�

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





