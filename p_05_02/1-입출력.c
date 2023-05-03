#include <stdio.h>
#include <string.h>
#include <stdlib.h>




#pragma region ����Լ� 10->2 ��ȯ �������� �� main�κ�
// start
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
// start
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
// start
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


#pragma region ���۰��� ����� ���ڿ� fgets
// start
#include "header.h"



int main()
{
	char input[10];
	int dummy = 0; // int�� ��������

	// stdin : ǥ���Է¹��� (�޾ƿ��� ���� �������ִ� �ڸ��� stdin�� ���� ��)
	fgets(input, sizeof(input), stdin);
	printf("%s \n", input); // 9���� ����� ������ ��

	printf("���ۿ� �����ִ� ���뤾�� : ");
	do {
		dummy = getchar(); // ���ۿ� �ִ°� ��������
		printf("%c ", dummy);
	} while (dummy != '\n');

	return 0;
}




#pragma endregion


#pragma region ���۰��� ����� ���ڿ� scanf
// start
#include "header.h"



int main()
{
	char input[10];
	int dummy = 0, chk = 0; // int�� ��������

	chk = scanf("%[^\n]s", input);
	printf("%s \n", input);

	printf("���ۿ� �����ִ� ���뤾�� : ");
	do {
		dummy = getchar(); // ���ۿ� �ִ°� ��������
		printf("%c ", dummy);
	} while (dummy != '\n');

	return 0;
}




#pragma endregion


#pragma region puts�� fputs
// start
#include "header.h"



int main()
{
	char input[10], dummy = 0;
	char chk = 0;

	// input�� �Է�
	chk = fgets(input, sizeof(input), stdin);

	puts(input); // ����(\n)�� ����
	fputs(input, stdout); // ����(\n)�� ���� 

	printf("%s \n", input);

	/*
	printf("���̿� ���� ���� : ");
	do {
		dummy = getchar();
		printf("%c ", dummy);
	} while (dummy != '\n');
	*/


	/* ��.�� �̿�
	�Է�
	getchar()		// ������ (���� �� ��)
	fgets()			// ���ڿ�


	���
	puts()
	fputs()

	*/

	return 0;
}




#pragma endregion


#pragma region �Լ� �Ű����� �߿����� ������ �ذ��� ���� �Լ��� (strcpy, strncpy ��)
// start
#include "header.h"



int main()
{
	char test[5];
	// test = "Hi"; // �̰� �� �ȵǴ��� �����غ� -> �迭�̶�
	// fn_string1�� �ִ� str = "Hi"; �� �� �ǰ� ��� �� �ȵǴ���


	char str[] = "Hello"; // �Է��� ���� �� + 1 ��������� ~
	printf("main size : %d \n", sizeof(str));
	printf("%p \n", str);
	fn_string(str);
	fn_string1(str);
	printf("main �Լ� ��� �� : %s \n", str);
	printf("%p \n", str);



	return 0;
}




#pragma endregion


#pragma region ���ڿ� �񱳿� ���ڿ����� ���ڿ� ã��
// start
#include "header.h"



int main()
{
	char str1[32] = "Hello, World!";
	char str2[32] = "Hello, C!";
	char str3[32] = "banana";


	// strstr ���ڿ����� ���ڿ�ã�� -> �Լ��� ��
	char find_str[32] = "World";
	char* result = NULL;

	result = strstr(str1, find_str);
	if (result != NULL)
	{
		printf("%s �� �ܾ �ֳ׿� \n", result);
	}
	else
	{
		printf("ã�°� ���׿�");
	}


	fn_str1_cmp(str1, str2);

	puts(" ");

	fn_str1_ncmp(str1, str2);

	fn_strchr(str3);




	return 0;
}



#pragma endregion


#pragma region ���ڿ� ���� �⺻ ����
// start
#include "header.h"



int main()
{
	// ���ڿ� ����

	char str1[] = "Hello World Welcome C Programming";
	char* result = NULL;

	result = strtok(str1, " ");

	while (result != NULL)
	{
		printf("%s \n", result);
		result = strtok(NULL, " "); // ������ #���� �ϰ� ������ ���� ���ڿ����� #�� �־����.
	}

	printf("%s", str1); // ���ڿ� ��ü�� �ٲ�����

	return 0;
}




#pragma endregion


#pragma region ���ڿ� �񱳿� ���̰��
// start
#include "header.h"



int main()
{
	// ���ڿ��� �񱳿� ���� ���
	char str1[16] = "I'm 25years old";
	char str2[16] = { '\0', };

	char pattern[] = "0123456789";

	size_t sIndex = 0, sLength = 0;

	// strlen : �迭�� ���̰� �ƴ϶� ���ڿ��� ����
	printf("sizeof : %d, strlen : %d \n", sizeof(str1), strlen(str1));

	sIndex = strcspn(str1, pattern);
	// sIndex�� strcspn : ���ڿ� str1�� pattern�� ���Ͽ� pattern�� �ش��ϴ� ���ڰ� ������ �������� ���� ��ȯ
	// i'm �������, 2���� ���� 4�� ��ȯ�ϰ� ��

	// printf("%d \n", sIndex);

	if (sIndex > 0 && strlen(str1) != sIndex)
	{
		// str1 + sIndex�� �ϸ� ���ڿ� str1���� 25years old�� �ҷ����� �ǰ�
		// �ҷ��� ���ڿ��� pattern�� ������ ��
		// pattern ���ڿ��� �ش��ϴ� ���ڰ� 2���̹Ƿ� sLength�� 2�� �����ϰ� ��
		sLength = strspn(str1 + sIndex, pattern);
		if (sLength > 0)
		{
			// ���ڿ� str2���ٰ� str1+sIndex -> 25years old�� ������ ���ڿ��� sLength��ŭ(2��ŭ) ����
			strncpy(str2, str1 + sIndex, sLength);
			printf("���� %s���Դϴ�. \n", str2);
		}

	}
	else
	{
		printf("ã�� ������ �����ϴ�.");
	}

	return 0;
}




#pragma endregion


#pragma region atoi �Լ�
// start
#include "header.h"



int main()
{
	char str1[] = "10";
	// printf("%d \n", str1[0]);
	printf("%d \n", atoi(str1) * 5); // 10 * 5 = 50

	return 0;
}



#pragma endregion


#pragma region ���ڿ� ���� 1��
// start
#include "header.h"



int main()
{
	// 1��
	char season[10] = { '\0', };

	// end ������ ��
	while (1)
	{
		printf("-------- 4���� �� �� ���� ���� (����� end) : ");
		scanf("%s", season);

		if (strcmp(season, "��") == 0)
		{
			printf("������ ������ \n");
		}
		else if (strcmp(season, "����") == 0)
		{
			printf("�������� ��� \n");
		}
		else if (strcmp(season, "����") == 0)
		{
			printf("�������� �ڽ��� \n");
		}
		else if (strcmp(season, "�ܿ�") == 0)
		{
			printf("�ܿ￡�� ��ȭ \n");
		}
		else if (strcmp(season, "end") == 0)
		{
			printf("end�Է����� �շ� \n"); // �շᰡ ���� �շᰡ��������
			break;
		}
		else
		{
			printf("??? �ٽ� �Է� \n");
		}
	}



	return 0;
}




#pragma endregion


#pragma region ���ڿ� ���� 2�� �ϼ�
// start
#include <stdio.h>

int main()
{
	char last_name[10] = "\0";
	char first_name[10] = "\0";
	char full_name[20] = "\0";

	int chk_l = 0, chk_f = 0;


	printf("���� �Է��ϼ���. \n");
	chk_l = scanf("%s", last_name);

	printf("�̸��� �Է��ϼ���. \n");
	chk_f = scanf("%s", first_name);

	// ���� cpy����ϳ�?
	// cpy �� =, cat�� +, cmp�� == ��� ���� �� ��
	strcpy(full_name, last_name);

	// strcat(full_name, " "); -> �ѱ۷� ���Ÿ� �� ���°� ���� ��

	strcat(full_name, first_name);


	printf("���� : %s", full_name);

	return 0;
}




#pragma endregion


//�������� �� �Ŷ� ����ϱ� ������ ���� ���������� ���� �ʰڼ� !!
#pragma region ���ڿ� ���� 3�� ( ĸ�Ķ����� �Լ��� �����ؿ� )
// start
#include "header.h"

void test3(char str1[], char str2[]);

int main()
{
	char str1[10] = "Hello";
	char str2[10] = "Wolrd";

	test3(str1, str2);
	printf("%s %s \n", str1, str2);

	return 0;
}

void test3(char str1[], char str2[])
{
	char temp[10] = "\0";
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);

	// printf("%s %s \n", str1, str2);
}

#pragma endregion


#pragma region ���ڿ� ���� 1�� ��������
// start
#include "header.h"



int main()
{
	char input[5] = { '\0', };
	char* season[2][4] = {
		{"��", "����", "����", "�ܿ�"},
		{"������", "���", "�ڽ���", "��ȭ"}
	};


	int chk = 0;
	printf("������ �Է�, end �Է½� ����");
	while (chk = scanf_s("%s", input, sizeof(input)), strcmp(input, "end") != 0)
	{
		int i = 0;
		for (i = 0; i < 4; i++)
		{
			if (strcmp(input, season[0][i]) == 0)
			{
				puts(season[1][i]);
				break;
			}
		}

		if (i >= 4)
		{
			puts("��, ����, ����, �ܿ� �߿� �Է���");
		}
	}

	return 0;
}




#pragma endregion


#pragma region ���ڿ� ���� 2�� ��������
// start
#include "header.h"



int main()
{
	char last_name[10] = "\0";
	char first_name[10] = "\0";
	char full_name[20] = "\0";

	puts("���� �̸��� ���� �Է��Ϸ�");

	gets_s(last_name, sizeof(last_name));
	gets_s(first_name, sizeof(first_name)); // first_name�� �����ŭ �޾ƿ���


	strcpy(full_name, last_name);
	strcat(full_name, first_name);

	printf("%s", full_name);

	return 0;
}



#pragma endregion


#pragma region ���� ����� �б�&����&����
// start
#include "header.h"



int main()
{
	//���� ���� : fopen()
	FILE* p_file = fopen("test.txt", "at"); // mode�� ���� �ٸ��� ����, at�� �̾�� wt�� ����� ~ rt�� �а� !

	char read[50];
	char haha[50];
	int chk = 0;

	if (NULL != p_file)
	{
		printf("���� ���� ���� ! \n");

		// ���� ����
		// fputs("���Ͼ���", p_file);
		// fscanf(p_file, "%[^\n]s", read);
		// fprintf(p_file, "Hello");		
		chk = scanf("%s", haha);
		fprintf(p_file, haha);


		// ���� �б�
		/*
		while (!feof(p_file)) // feof �Լ��� ������ ���� �����ϸ� 0�� �ƴ� ���� ��ȯ, enter�� ���๮�ڷ� �ν��Ͽ� �ٹٲ�
		{
			fgets(read, sizeof(read), p_file); // ������� ��� �о��
			printf("%s", read);
		}
		*/

		// fscanf�� �ٹٲ��� ���� -> �׷��� [^\n] �־��� -> �׷����� �̻�����
		/*
		while (EOF != fscanf(p_file, "%[^\n]s", &read))
		{
			printf("%s", read);
		}
		*/




		// ����Ŭ���� : fclose()
		fclose(p_file);
	}
	else
	{
		printf("ERR(%d) : %s \n", errno, strerror(errno));
	}

	return 0;
}




#pragma endregion


#pragma region ���� ����� �б�� ������ ��ġ �̵� �Լ� ( �̿� )
// start
#include "header.h"



int main()
{
	FILE* p_file = fopen("test.txt", "rt"); // at�� �ϸ� �̻��ϰ� ���ͼ� rt �б� �������� ��带 �ٲ�
	char read[50];

	if (NULL != p_file)
	{
		fgets(read, sizeof(read), p_file);
		printf("%s", read);

		fgets(read, sizeof(read), p_file);
		printf("%s", read);

		fseek(p_file, 5, SEEK_SET);	// SEEK_SET �� ó������ !
		fgets(read, sizeof(read), p_file);
		printf("%s", read);

	}
	else
	{
		printf("ERR(%d) : %s \n", errno, strerror(errno));
	}

	return 0;
}



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion





