// start
#include "header.h"

/*
	완성했음 -> ㄴㄴ 해제 안 했음
*/


// 구조체 선언
typedef struct my_class
{
	char name[20];
	unsigned int korean_score;
	unsigned int english_score;
	unsigned int math_score;
	unsigned int sum_score;
	float avg_score;
	struct my_class* next;
}MYCLASS;



// 입력 함수만들기 -> void형으로 만들어도 될 듯? -> int형으로 return을 써서 잘 되는지 확인해보자
// 매개변수는 어떻게 할까 -> 주소값을 사용해야하니까 이중으로 받아야 할 듯
int writing_info(MYCLASS** p_info);

// 출력 함수만들기
void show_info(MYCLASS* p_info);

// 등수 함수만들기 -> 매개변수는?
int get_rank(MYCLASS* p_info, unsigned int sum);


int main()
{
	/*
	[menu]
	1. 성적 입력
	2. 성적 확인
	3. 종료
	-------------
	선택(1~3) :

	######################
	1번 메뉴 선택 시 입력
	######################
	n번째 학생이름 :
	국어 점수 :
	영어 점수 :
	수학 점수 :

	######################
	2번 메뉴 선택 시 출력
	######################

	---------------------------------------------------------
	이름		국어	영어	수학	총점	평균	등수
	---------------------------------------------------------
	김완종		100		100		100		300		100		1



	평균은 소수점을.. 정수를...? 어떻게 처리할까 평균은 중요하니까 float로 하자
	등수..... 예전에 총점을 같이 넘겨줘서 편하게 했었던게 기억이 나는데에...흐으으음...
	*/

	MYCLASS* info_head = NULL;
	int num = 0;

	while (1)
	{
		puts(" ");
		printf("[menu]\n");
		printf("1. 성적 입력\n");
		printf("2. 성적 확인\n");
		printf("3. 종료\n");
		printf("-------------\n");
		printf("선택 ( 1 ~ 3 ) : ");
		scanf("%d", &num);
		getchar(); // 숫자가 아닌 문자를 입력했을 때 무한루프를 방지하기 위한 버퍼제거 함수

		if (num == 1)
		{
			if (writing_info(&info_head) == 1)
			{
				printf("입력 완료 ! \n");
			}
		}
		else if (num == 2)
		{
			show_info(info_head);
		}
		else if (num == 3)
		{
			printf("menu를 종료합니다 :D \n");
			break;
		}
		else
		{
			printf("선택된 번호만 입력해야죠? ( 1 ~ 3 ) \n");
		}
	}




	return 0;
}

int writing_info(MYCLASS** p_info)
{
	static int count = 0; // n번째 학생을 위한
	printf("######################\n");
	printf("1번 메뉴 선택 시 입력\n");
	printf("######################\n");
	count++;

	MYCLASS* new_temp = NULL;

	new_temp = (MYCLASS*)malloc(sizeof(MYCLASS));
	if (new_temp == NULL)
	{
		printf("메모리 할당 오류 \n");
		return 0;
	}

	printf("%d번째 학생의 이름 : ", count);
	scanf("%s", new_temp->name);

	// %d 보다 %u쓰자 unsigned int 했으면.
	printf("국어 점수 : ");
	scanf("%u", &new_temp->korean_score);

	printf("영어 점수 : ");
	scanf("%u", &new_temp->english_score);

	printf("수학 점수 : ");
	scanf("%u", &new_temp->math_score);


	new_temp->sum_score = new_temp->korean_score + new_temp->english_score + new_temp->math_score;
	new_temp->avg_score = (float)new_temp->sum_score / 3.0f;
	new_temp->next = NULL;

	// 노드가 없을 때
	if (*p_info == NULL)
	{

		*p_info = new_temp;

		return 1;
	}
	else // 첫 노드가 아니면
	{

		// 맨 끝 노드까지 가기위한 current(cur) 변수
		MYCLASS* cur = *p_info;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}

		cur->next = new_temp;

		return 1;
	}


	return 0;
}

void show_info(MYCLASS* p_info)
{
	printf("###################### \n");
	printf("2번 메뉴 선택 시 출력 \n");
	printf("###################### \n");
	puts(" ");
	printf("---------------------------------------------------------------------------- \n");
	printf("이름		국어	영어	수학	총점	평균	등수\n");
	printf("---------------------------------------------------------------------------- \n");

	MYCLASS* cur = p_info;

	if (cur == NULL)
	{
		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@ 확인할 정보가 없어요 @@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	}

	while (cur != NULL)
	{
		printf("%-15s	%2u	%2u	%2u	%2u	%.1f	%2d", cur->name, cur->korean_score, cur->english_score, cur->math_score
			, cur->sum_score, cur->avg_score, get_rank(p_info, cur->sum_score));
		puts(" ");
		cur = cur->next;
	}
}

int get_rank(MYCLASS* p_info, unsigned int sum)
{
	int rank = 1;


	while (p_info != NULL)
	{
		if (p_info->sum_score > sum)
		{
			rank++;
		}

		p_info = p_info->next;
	}


	return rank;
}