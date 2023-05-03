
#pragma region 입출력 커서를 이용한 애국가 예제
// start
#include "header.h"



int main()
{
	// fputc() : 문자 출력
	// fputs() : 문자열 출력
	// fprintf() : 서식을 지정하여 다양한 문자열 출력

	/*
	fgets(read, sizeof(read), p_file);
	printf("%s", read);
	*/


	// a+ 추가 읽기 쓰기, w+읽기와쓰기->없으면 만듦, r+ 읽기/쓰기 -> 파일없으면 끝
	FILE* p_file = fopen("test.txt", "w+");
	char read[50];
	char here[10] = "이천리";

	if (NULL != p_file)
	{
		// 파일 쓰기 (출력)
		fputs("동해물과 백두산이 마르고 닳도록 \n", p_file);
		fputs("하느님이 보우하사 우리나라 만세. \n", p_file);
		fputs("무궁화 이천리 화려강산 \n", p_file);
		fputs("대한사람 대한으로 길이 보전하세. ", p_file);


		// 틀린곳으로 가기 위해 파일의 처음에서부터 커서 이동
		// fseek(p_file, 69, SEEK_SET);
		// 이거 말고 반복문으로 이천리 찾으면 안됨?  -> 안되는게 어딨음
		// 단어별로 찾고 싶음 이천리 라는 단어를 찾아서.. 이천리 어디있을까
		int i = 0;
		while (1)
		{
			fseek(p_file, i, SEEK_SET);
			fgets(read, sizeof(read), p_file);


			// 이걸로 이천리 있는 첫 주소값 받아옴
			char* cor = strstr(read, here);

			// 그 첫 주소값에서 어디까지 변경을 하나 -> strlen
			if (cor != NULL)
			{
				strncpy(cor, "삼천리", strlen("삼천리"));

				// 출력해주기
				fseek(p_file, i, SEEK_SET);
				fputs(read, p_file);
				break;
			}

			i++;
		}

		// 파일 읽기 (입력) 
		fseek(p_file, 0, SEEK_SET);
		// feof 함수는 파일의 끝에 도달하면 0이 아닌 값을 반환, enter를 개행문자로 인식하여 줄바꿈
		while (!feof(p_file)) // 공백까지 모두 읽어옴 ( 마지막에 enter치면 안돼 )
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


#pragma region 애국가 센세 버전
// start
#include "header.h"



int main()
{
	FILE* p_file = fopen("test.txt", "w+");
	if (p_file != NULL) {

		fputs("동해물과 백두산이 마르고 닳도록\n", p_file);
		fputs("하느님이 보우하사 우리나라 만세\n", p_file);
		fputs("무궁화 이천리 화려강산\n", p_file);
		fputs("대한사람 대한으로 길이 보전하세\n", p_file);

		fseek(p_file, 0, SEEK_SET);

		// 파일읽기(입력)
		char readline[100] = { '\0' };
		char* chk = NULL;
		char* p = NULL;

		while (!feof(p_file)) {

			chk = fgets(readline, sizeof(readline), p_file);
			if (chk == NULL) break;

			// 이천리가 포함된 라인이라면
			p = strstr(readline, "이천리");
			if (p != NULL) {

				// 전체 길이에서 이천리 시작 위치를 빼서
				// 현재 커서로부터 이동할 거리를 계산.
				// \r문제로 +1 ( 하기 싫으면 mode를 binary로 )
				int offset = (strlen(readline) - (p - readline) + 1);

				fseek(p_file, -offset, SEEK_CUR);
				fputs("삼천리", p_file);
				fseek(p_file, offset - sizeof("삼천리"), SEEK_CUR);

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


#pragma region main함수의 사용
// start
#include "header.h"


// main 사용
// char* argv[] -> 2차원 포인터
// 프로젝트 속성에서 함수 인자에 text.txt 줘야해
int main(int argc, char* argv[])
{
	int ch = 0;
	FILE* fp = NULL;


	unsigned long count = 0;


	if (argc != 2)
	{
		printf("사용법 : %s filename \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("%s 파일을 열 수 없습니다. \n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("%s 파일은 %ld bytes의 문자가 들어있습니다. \n", argv[1], count);




	return 0;
}



#pragma endregion


#pragma region 1~4번 예제
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
		printf("오류");
		return 1;
	}
	char read[50];

	int chk = 0;
	char name[30] = "이성란";
	char rrn[15] = "810815-2000000";
	char p_n[15] = "010-9000-8000";

	char food[30] = "떡볶이, 찜닭";
	char hobby[30] = "아들이랑 여행가기";

	INFO NEW[10] = {
		{0},
	};

	// 비주얼 스튜디오에서 하드코딩한 거 출력
	fprintf(p_file, "# 이름 : %s \n# 주민번호 : %s \n# 전화번호 : %s \n# 즐겨먹는 음식 : %s \n# 취미 : %s \n", name, rrn, p_n, food, hobby);


	// 입력한 것들 출력
	for (int i = 0; i < 10; i++)
	{
		printf("이름?");
		chk = scanf("%s", NEW[i].name);
		printf("전화번호?");
		chk = scanf("%s", NEW[i].tel);

		if (strcmp(NEW[i].name, "end") == 0 || strcmp(NEW[i].tel, "end") == 0)
		{
			break;
		}

		fprintf(p_file, "이름 : %s   전화번호 : %s \n", NEW[i].name, NEW[i].tel);
	}



	// 파일 포인터를 파일의 맨 처음으로 이동
	fseek(p_file, 0, SEEK_SET);

	// 파일 안에 있는 내용 출력
	while (fgets(read, sizeof(read), p_file) != NULL)
	{
		printf("%s", read);
	}
	// feof 로 조건을 주려고 했는데말이징.. 자꾸 마지막 줄이 중복돼서 2번나와 ㅋㅋ

	fclose(p_file);

	return 0;
}




#pragma endregion


#pragma region 1~4번 센세 버전
#include<stdio.h>
#include<errno.h>
#include<string.h>
#define MAX_NUMBER 3

struct info {
	char name[20];
	char phone_number[20];
};

int main() {
	// 전화번호부 입력
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

		// 파일에 출력.
		for (int i = 0; i < MAX_NUMBER; i++) {
			fprintf(fp, "%s : %s\n", myPhoneBook[i].name, myPhoneBook[i].phone_number);
		}

		fseek(fp, 0, SEEK_SET);

		printf("===============파일에 입력된 전화번호부 출력===============\n");

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





