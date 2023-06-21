// start
#include "header.h"

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
	unsigned int rank;
}MYCLASS;

int writing_info(MYCLASS** p_info);

void show_info(MYCLASS* p_info);

void delete_list(MYCLASS** p_info);

int main()
{

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
		getchar();

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

	delete_list(&info_head);

	return 0;
}

int writing_info(MYCLASS** p_info)
{
	static int count = 0;
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

	printf("국어 점수 : ");
	scanf("%u", &new_temp->korean_score);

	printf("영어 점수 : ");
	scanf("%u", &new_temp->english_score);

	printf("수학 점수 : ");
	scanf("%u", &new_temp->math_score);

	new_temp->sum_score = new_temp->korean_score + new_temp->english_score + new_temp->math_score;
	new_temp->avg_score = (float)new_temp->sum_score / 3.0f;
	new_temp->next = NULL;


	new_temp->rank = 1;


	// 노드가 없을 때
	if (*p_info == NULL)
	{
		*p_info = new_temp;

		return 1;
	}
	else // 첫 노드가 아니면
	{

		MYCLASS* cur = *p_info;
		MYCLASS* else_temp = NULL;
		int cur_rank = 1;


		while (cur != NULL && cur->sum_score >= new_temp->sum_score)
		{
			else_temp = cur;
			cur = cur->next;
			cur_rank++;
		}

		while (cur != NULL && cur->sum_score < new_temp->sum_score)
		{
			else_temp = cur;
			cur->rank = cur->rank + 1;
			cur = cur->next;
		}

		new_temp->rank = cur_rank;

		if (else_temp == NULL)
		{
			new_temp->next = *p_info;
			*p_info = new_temp;
		}
		else
		{
			else_temp->next = new_temp;
			new_temp->next = NULL;
		}

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
			, cur->sum_score, cur->avg_score, cur->rank);
		puts(" ");
		cur = cur->next;
	}
}

void delete_list(MYCLASS** p_info) {
	if (*p_info != NULL) {
		MYCLASS* cur = *p_info;
		MYCLASS* next = NULL;
		while (cur != NULL) {
			next = cur->next;
			free(cur);
			cur = next;
		}
	}
};