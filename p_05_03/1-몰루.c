
#pragma region ����� Ŀ���� �̿��� �ֱ��� ����
// start
#include "header.h"



int main()
{
	// fputc() : ���� ���
	// fputs() : ���ڿ� ���
	// fprintf() : ������ �����Ͽ� �پ��� ���ڿ� ���

	/*
	fgets(read, sizeof(read), p_file);
	printf("%s", read);
	*/


	// a+ �߰� �б� ����, w+�б�;���->������ ����, r+ �б�/���� -> ���Ͼ����� ��
	FILE* p_file = fopen("test.txt", "w+");
	char read[50];
	char here[10] = "��õ��";

	if (NULL != p_file)
	{
		// ���� ���� (���)
		fputs("���ع��� ��λ��� ������ �⵵�� \n", p_file);
		fputs("�ϴ����� �����ϻ� �츮���� ����. \n", p_file);
		fputs("����ȭ ��õ�� ȭ������ \n", p_file);
		fputs("���ѻ�� �������� ���� �����ϼ�. ", p_file);


		// Ʋ�������� ���� ���� ������ ó���������� Ŀ�� �̵�
		// fseek(p_file, 69, SEEK_SET);
		// �̰� ���� �ݺ������� ��õ�� ã���� �ȵ�?  -> �ȵǴ°� �����
		// �ܾ�� ã�� ���� ��õ�� ��� �ܾ ã�Ƽ�.. ��õ�� ���������
		int i = 0;
		while (1)
		{
			fseek(p_file, i, SEEK_SET);
			fgets(read, sizeof(read), p_file);


			// �̰ɷ� ��õ�� �ִ� ù �ּҰ� �޾ƿ�
			char* cor = strstr(read, here);

			// �� ù �ּҰ����� ������ ������ �ϳ� -> strlen
			if (cor != NULL)
			{
				strncpy(cor, "��õ��", strlen("��õ��"));

				// ������ֱ�
				fseek(p_file, i, SEEK_SET);
				fputs(read, p_file);
				break;
			}

			i++;
		}

		// ���� �б� (�Է�) 
		fseek(p_file, 0, SEEK_SET);
		// feof �Լ��� ������ ���� �����ϸ� 0�� �ƴ� ���� ��ȯ, enter�� ���๮�ڷ� �ν��Ͽ� �ٹٲ�
		while (!feof(p_file)) // ������� ��� �о�� ( �������� enterġ�� �ȵ� )
		{
			fgets(read, sizeof(read), p_file);
			printf("%s", read);
		}

		fclose(p_file);
	}
	else
	{
		printf("ERR(%d) : %s \n", errno, strerror(errno));
	}




	return 0;
}




#pragma endregion


#pragma region �ֱ��� ���� ����
// start
#include "header.h"



int main()
{
	FILE* p_file = fopen("test.txt", "w+");
	if (p_file != NULL) {

		fputs("���ع��� ��λ��� ������ �⵵��\n", p_file);
		fputs("�ϴ����� �����ϻ� �츮���� ����\n", p_file);
		fputs("����ȭ ��õ�� ȭ������\n", p_file);
		fputs("���ѻ�� �������� ���� �����ϼ�\n", p_file);

		fseek(p_file, 0, SEEK_SET);

		// �����б�(�Է�)
		char readline[100] = { '\0' };
		char* chk = NULL;
		char* p = NULL;

		while (!feof(p_file)) {

			chk = fgets(readline, sizeof(readline), p_file);
			if (chk == NULL) break;

			// ��õ���� ���Ե� �����̶��
			p = strstr(readline, "��õ��");
			if (p != NULL) {

				// ��ü ���̿��� ��õ�� ���� ��ġ�� ����
				// ���� Ŀ���κ��� �̵��� �Ÿ��� ���.
				// \r������ +1 ( �ϱ� ������ mode�� binary�� )
				int offset = (strlen(readline) - (p - readline) + 1);

				fseek(p_file, -offset, SEEK_CUR);
				fputs("��õ��", p_file);
				fseek(p_file, offset - sizeof("��õ��"), SEEK_CUR);

			}
		}
		fclose(p_file);
	}
	else {
		printf("%d : %s\n", errno, strerror(errno));
	}
	return 0;

}




#pragma endregion


#pragma region main�Լ��� ���
// start
#include "header.h"


// main ���
// char* argv[] -> 2���� ������
// ������Ʈ �Ӽ����� �Լ� ���ڿ� text.txt �����
int main(int argc, char* argv[])
{
	int ch = 0;
	FILE* fp = NULL;


	unsigned long count = 0;


	if (argc != 2)
	{
		printf("���� : %s filename \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("%s ������ �� �� �����ϴ�. \n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("%s ������ %ld bytes�� ���ڰ� ����ֽ��ϴ�. \n", argv[1], count);




	return 0;
}



#pragma endregion


#pragma region 1~4�� ����
// start
#include "header.h"

typedef struct info
{
	char name[20];
	char tel[20];
}INFO;

int main()
{
	FILE* p_file = fopen("mystory.txt", "w+");
	if (p_file == NULL)
	{
		printf("����");
		return 1;
	}
	char read[50];

	int chk = 0;
	char name[30] = "�̼���";
	char rrn[15] = "810815-2000000";
	char p_n[15] = "010-9000-8000";

	char food[30] = "������, ���";
	char hobby[30] = "�Ƶ��̶� ���డ��";

	INFO NEW[10] = {
		{0},
	};

	// ���־� ��Ʃ������� �ϵ��ڵ��� �� ���
	fprintf(p_file, "# �̸� : %s \n# �ֹι�ȣ : %s \n# ��ȭ��ȣ : %s \n# ��ܸԴ� ���� : %s \n# ��� : %s \n", name, rrn, p_n, food, hobby);


	// �Է��� �͵� ���
	for (int i = 0; i < 10; i++)
	{
		printf("�̸�?");
		chk = scanf("%s", NEW[i].name);
		printf("��ȭ��ȣ?");
		chk = scanf("%s", NEW[i].tel);

		if (strcmp(NEW[i].name, "end") == 0 || strcmp(NEW[i].tel, "end") == 0)
		{
			break;
		}

		fprintf(p_file, "�̸� : %s   ��ȭ��ȣ : %s \n", NEW[i].name, NEW[i].tel);
	}



	// ���� �����͸� ������ �� ó������ �̵�
	fseek(p_file, 0, SEEK_SET);

	// ���� �ȿ� �ִ� ���� ���
	while (fgets(read, sizeof(read), p_file) != NULL)
	{
		printf("%s", read);
	}
	// feof �� ������ �ַ��� �ߴµ�����¡.. �ڲ� ������ ���� �ߺ��ż� 2������ ����

	fclose(p_file);

	return 0;
}




#pragma endregion


#pragma region 1~4�� ���� ����
#include<stdio.h>
#include<errno.h>
#include<string.h>
#define MAX_NUMBER 3

struct info {
	char name[20];
	char phone_number[20];
};

int main() {
	// ��ȭ��ȣ�� �Է�
	struct info myPhoneBook[MAX_NUMBER];
	int chk = 0;

	for (int i = 0; i < MAX_NUMBER; i++) {
		chk = 0;
		while (chk != 2) {
			chk = scanf("%s %s", myPhoneBook[i].name, myPhoneBook[i].phone_number);
		}
	}

	char file_name[] = "phoneBook.txt";
	FILE* fp = fopen(file_name, "w+t");

	if (fp != NULL) {
		char readLine[100] = { '\0' };

		// ���Ͽ� ���.
		for (int i = 0; i < MAX_NUMBER; i++) {
			fprintf(fp, "%s : %s\n", myPhoneBook[i].name, myPhoneBook[i].phone_number);
		}

		fseek(fp, 0, SEEK_SET);

		printf("===============���Ͽ� �Էµ� ��ȭ��ȣ�� ���===============\n");

		while (fgets(readLine, sizeof(readLine), fp) != NULL) {
			printf("%s", readLine);
		}

		fclose(fp);
	}
	else {
		printf("%d : %s", errno, strerror(errno));
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





