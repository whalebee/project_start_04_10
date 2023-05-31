
// cur
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



// 입력 함수만들기 -> void형으로 만들어도 될 듯? -> int형으로 return을 써서 잘 되는지 확인해보자
// 매개변수는 어떻게 할까 -> 주소값을 사용해야하니까 이중으로 받아야 할 듯
int writing_info(MYCLASS** p_info);

// 출력 함수만들기
void show_info(MYCLASS* p_info);


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
		MYCLASS* fin = *p_info;



		// 항복
		
		// --------------------------------------
		// rank 업데이트 구문

		// 주소를 처음부터 끝까지 돌면서 비교함과 동시에 rank를 조절할 수는 없을까?
		// 새로운 노드가 만들어지고 입력이 될 때마다 *p_info를 이용해서 처음부터 끝까지 비교한다면?

		// rank는 어떤 방식으로 부여하면 좋을까..

		// 노드를 입력할 때 마다 new_rank가 1부터 시작한다?
		int new_rank = 1;
		int count = 0;

		// 2번째 노드부터 ( 어차피 처음 노드부터 비교함 )
		while (cur != NULL)
		{

			

			// 버블정렬처럼 한다면?
			// 이렇게하면? -> 다음 주소와 비교하는 건데
			// 다음 노드가 더 크면 현재 노드에 rank 주고
			// 다음 노드를 cur에 넣기 ?
			if (cur->sum_score < cur->next->sum_score)
			{
				new_rank;;
				cur->rank = new_rank;

				cur = cur->next;
			}
			// 현재 노드가 더 크면?
			// 다음 노드에 rank 업해주고.. 다 다음 노드랑 비교ㅋㅋ 뭐야이게
			// 그럼 다 다음 노드보다 현재 노드가 크면 다 다 다음 노드랑 비교해야됨?
			else if (cur->sum_score > cur->next->sum_score)
			{
				new_rank++;
				cur->next->rank = new_rank;

				// 다음, 다 다음, 다다 다음으로 가기위한...ㅋㅋㅋㅋ
				count++;
				for (int i = 0; i <= count; i++)
				{
					cur = cur->next;
				}
			}





			/*
			// 이건 새로운 노드랑만! 비교하는거고
			if (cur->sum_score <= new_temp->sum_score) // 다음 노드가 더 크면?
			{
				new_rank++;
				cur->rank = new_rank; // 현재 노드에 rank 추가
			}
			else if (cur->sum_score > new_temp->sum_score) // 현재 노드가 더 크면?
			{
				new_rank++;
				new_temp->rank = new_rank; // 다음 노드에 rank 추가
			}


			cur = cur->next;

			*/



			// 30 15 40 25 일 때
			// 1. 30과 15 비교를 하면? -> 30이 높으니까 rank는 그냥 1
			// 2. 15와 40을 비교하면? -> 15가 작아서 rank가 2로 증가
			// 3. 40과 25를 비교하면? -> 40이 더 높으므로 rank는 그냥 2 ?
			// 즉, 3번째 노드를 입력하면 1 2 3 모두를 비교해서 rank를 해야됨
			// 1번은 2번 3번과 비교를하고?
			// 1번이 2번과 비교하고 높은 애가 지정되고?
			// 그 높은애가 3번과 비교를 하고 여기서 높은 애가 다시 지정되고?
			// 지정되지 않은 낮은 애들은 rank + 1
			// 

	}

	// --------------------------------------
	






		while (fin->next != NULL)
		{
			fin = fin->next;
		}
		fin->next = new_temp;







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

