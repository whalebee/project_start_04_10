#pragma region 링크드리스트 복습 예제 1
// start
#include "header.h"

typedef struct node
{
	int data;
	struct node* left_child;
	struct node* right_child;
}NODE;

// 값을 넣는 것부터 만들자
NODE* insert_node(NODE* root, int data);

// 그 다음 찾는 것
NODE* search_node(NODE* root, int data);


// 정렬해주기
// 전위 V L R 
void preorder_node(NODE* root);
// 중위 L V R
void inorder_node(NODE* root);
// 후위 L R V
void postorder_node(NODE* root);


// 최소값 찾기 ( 왼쪽 )
NODE* find_min_node(NODE* root);
// 최대값 찾기 ( 오른쪽 )
NODE* find_max_node(NODE* root);


// 삭제 ( 특정 값 )
NODE* delete_node(NODE* root, int data);



// 해제 ( 모두 )

int main()
{
	NODE* root = NULL;

	root = insert_node(root, 10);
	root = insert_node(root, 20);
	root = insert_node(root, 30);
	root = insert_node(root, 35);
	root = insert_node(root, 15);
	root = insert_node(root, 25);
	root = insert_node(root, 5);

	/*
	// 중복확인
	root = insert_node(root, 20);

	puts(" ");
	NODE* find = NULL;
	find = search_node(root, 15);
	printf("%p \n", find);
	*/


	puts(" ");
	printf("preorder : ");
	preorder_node(root);

	puts(" ");
	printf("inorder : ");
	inorder_node(root);

	puts(" ");
	printf("postorder : ");
	postorder_node(root);


	puts(" ");
	NODE* min_node = find_min_node(root);
	printf("최소 값 : %d \n", min_node->data);

	puts(" ");
	NODE* max_node = find_max_node(root);
	printf("최대 값 : %d \n", max_node->data);

	puts(" ");
	delete_node(root, 20);

	puts(" ");
	printf("preorder : ");
	preorder_node(root);



	return 0;
}


NODE* insert_node(NODE* root, int data)
{
	// root가 NULL 일 때 만들어줘야해
	if (root == NULL)
	{
		// root가 NULL이면 계속 동적할당으로 만들어줘
		while (root == NULL)
		{
			root = (NODE*)malloc(sizeof(NODE));
			printf("말록 %p \n", root);
		}

		// 만들어줬으면 값 넣어주자
		// data 넣어주고
		root->data = data;

		// 처음만든 node니까 양 쪽 주소값에 다 NULL 넣어주기
		root->left_child = NULL;
		root->right_child = NULL;

		return root;
	}
	else
	{
		// 값이 똑같다면?
		if (data == root->data)
		{
			printf("똑같은 값을 넣으려 하고 있소. \n");
			return root;
		}

		// 넣으려는 값이 왼쪽 값보다 작으면 왼쪽으로 가야하니까
		if (data < root->data)
		{
			root->left_child = insert_node(root->left_child, data);
		}
		else
		{
			root->right_child = insert_node(root->right_child, data);
		}
	}
	// 끝나면 결과 넘겨줘야지
	return root;
}

NODE* search_node(NODE* root, int data)
{
	// 내가 찾는게 없거나 노드가 없거나 그럼 NULL
	if (root == NULL) return NULL;

	// 내가 찾는 값과 같다면?
	if (data == root->data)
	{
		return root;
	}
	// data가 원래 있던 루트의 값보다 작으면 왼쪽으로 가봐야지
	else if (data < root->data)
	{
		// 주소값이랑 데이터 같이 들고 가
		return search_node(root->left_child, data);
	}
	else
	{
		return search_node(root->right_child, data);
	}
}

void preorder_node(NODE* root)
{
	// 같으면 리턴
	if (root == NULL) return;
	// 출력해주면서 재귀함수로 순서대로 찾기 void인 것을 생각
	printf("%d ", root->data); // data를 줘야지ㅋㅋ
	preorder_node(root->left_child);
	preorder_node(root->right_child);
}

void inorder_node(NODE* root)
{
	// 같으면 리턴
	if (root == NULL) return;
	inorder_node(root->left_child);
	printf("%d ", root->data);
	inorder_node(root->right_child);
}

void postorder_node(NODE* root)
{
	// 같으면 리턴
	if (root == NULL) return;
	// L R V 순서대로
	postorder_node(root->left_child);
	postorder_node(root->right_child);
	printf("%d ", root->data);
}

NODE* find_min_node(NODE* root)
{
	// root 가 NULL이 아니면
	while (root->left_child != NULL)
	{
		root = root->left_child;
	}
	return root;
}

NODE* find_max_node(NODE* root)
{
	while (root->right_child != NULL)
	{
		root = root->right_child;
	}
	return root;
}

NODE* delete_node(NODE* root, int data)
{
	NODE* node = NULL;

	// 없으면 어케 ~
	if (root == NULL) return NULL;

	// 데이터 매개변수가 root의 data값보다 작으면 왼쪽으로 가야쥬
	if (data < root->data)
	{
		// 재귀함수로 가되, 주소랑 값 같이 가져가 ~
		root->left_child = delete_node(root->left_child, data);
	}
	// 크면 오른쪽으로 가야쥬
	else if (data > root->data)
	{
		root->right_child = delete_node(root->right_child, data);
	}
	else
	{
		// 자식 노드가 둘 다 존재할 때 어디로 가야하오
		if (root->left_child != NULL && root->right_child != NULL)
		{
			node = find_min_node(root->right_child);
			root->data = node->data;
			root->right_child = delete_node(root->right_child, node->data);
		}
		else
		{
			node = (root->left_child != NULL) ? root->left_child : root->right_child;
			free(root);
			return node;
		}

	}

	return root;
}


#pragma endregion


#pragma region 링크드리스트 복습 예제 2 내가 한 버전
// start
#include "header.h"

/*
	완성했음 -> ㄴㄴ 해제 안 했음
	함수를 만드신 것 같더라고
	선생님 것도 있음
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


#pragma endregion


#pragma region 링크드리스트 복습 예제 2 선생님 버전
#include<stdio.h>
#include<malloc.h>

typedef struct node {
	char name[10];  // 이름
	int kor_score;  // 국어점수
	int eng_score;  // 영어점수
	int math_score; // 수학점수
	int sum;		// 총점
	double avg;		// 평균
	struct node* p_next; // 다음 노드를 가리킬 포인터
} SNODE;

int printMenu();
void appendStudent(SNODE**, SNODE**, int);
void showStudent(SNODE*);
int getRank(SNODE*, int);
void deleteList(SNODE**);

int main() {

	SNODE* p_header = NULL, * p_tail = NULL;
	int menu = 0, index = 1;

	do {
		menu = printMenu();
		switch (menu) {
		case 1:
			appendStudent(&p_header, &p_tail, index);
			index++;
			break;
		case 2:
			showStudent(p_header);
			break;
		case 3:
			break;
		default:
			printf("잘못입력했습니다.");
			break;
		}
	} while (menu != 3);

	deleteList(&p_header);

	return 0;
}

int printMenu() {

	int chk = 0, menu = 0;
	char dummy = 0;
	printf("[Menu]\n");
	printf("1.성적 입력\n");
	printf("2.성적 확인\n");
	printf("3.종료\n");
	printf("-----------\n");
	printf("선택(1~3):_");

	chk = scanf("%d", &menu);
	if (chk != 1) {
		printf("잘못입력했자너!!!\n");
		while (dummy != '\n') {
			dummy = getchar();
		}
	}
	return menu;
}


void appendStudent(SNODE** pp_header, SNODE** pp_tail, int index) {

	SNODE* new_node = (SNODE*)malloc(sizeof(SNODE));
	if (new_node != NULL) {
		int chk = 0;
		printf("%d번째 학생 이름 : ", index);
		chk = scanf("%s", new_node->name);

		printf("국어 점수 : ");
		chk = scanf("%d", &new_node->kor_score);

		printf("영어 점수 : ");
		chk = scanf("%d", &new_node->eng_score);

		printf("수학 점수 : ");
		chk = scanf("%d", &new_node->math_score);

		new_node->sum = new_node->kor_score + new_node->eng_score + new_node->math_score;
		new_node->avg = new_node->sum / 3.0;
		new_node->p_next = NULL;

		if (*pp_header == NULL) {
			*pp_header = new_node;
		}
		else {
			(*pp_tail)->p_next = new_node;
		}
		*pp_tail = new_node;
	}
}

void showStudent(SNODE* p_header) {

	if (p_header == NULL) {
		printf("연결 리스트가 없습니다.\n");
	}
	else {
		SNODE* cur = p_header;
		printf("-------------------------------------\n");
		printf("%6s%5s%5s%5s%5s%5s%5s\n", "이름", "국어", "영어", "수학", "총점", "평균", "등수");
		printf("-------------------------------------\n");
		while (cur != NULL) {
			printf("%6s%5d%5d%5d%5d%5.1f%5d \n", cur->name, cur->kor_score, cur->eng_score, cur->math_score, cur->sum, cur->avg, getRank(p_header, cur->sum));
			cur = cur->p_next;
		}
	}
}

int getRank(SNODE* p_header, int score) {
	int rank = 1;
	while (1) {
		if (score < p_header->sum) rank++;
		if (p_header->p_next == NULL) {
			break;
		}
		p_header = p_header->p_next;
	}
	return rank;
}

void deleteList(SNODE** pp_header) {
	if (*pp_header != NULL) {
		SNODE* cur = *pp_header;
		SNODE* next = NULL;
		while (cur != NULL) {
			next = cur->p_next;
			free(cur);
			cur = next;
		}
	}
};

#pragma endregion


#pragma region 링크드리스트 복습 예제 2 실패했던 기록들

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



		// ㅋㅋ 내가 졌다 두고보자
		// 중요한 건 꺾이지 않는 마음..

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



#pragma endregion


#pragma region ㅋㅋ됐죠? 중요한 건 꺾이지 않는 마음

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


// 동적할당 해제
void delete_list(MYCLASS** p_info);

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

	// 해제
	delete_list(&info_head);

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
		MYCLASS* prev = NULL;
		int cur_rank = 1;

		// 맨 처음 총합이 새로운 노드의 총합보다 크거나 같을 때
		while (cur != NULL && cur->sum_score >= new_temp->sum_score)
		{
			prev = cur; // 링크할 때 써야될 것
			cur = cur->next; // 다음 주소로 ( 처음부터 돌아야하니까 )
			cur_rank++; // 크면 랭크 업 시켜야지
		}
		// 돌면서 총합이 작을 때 랭크업을 시켜주기 위한
		while (cur != NULL && cur->sum_score < new_temp->sum_score)
		{
			prev = cur;
			cur->rank = cur->rank + 1;
			cur = cur->next;
		}

		new_temp->rank = cur_rank;

		if (prev == NULL) // new_temp가 첫 번째 학생보다 점수가 높을 경우
		{
			new_temp->next = *p_info;
			*p_info = new_temp;
		}
		else // 중간이나 마지막에 삽입해야 할 경우
		{
			prev->next = new_temp;
			new_temp->next = NULL;
		}

		// 현재 문제
		// 1. rank up 관련 -> 4번 이후 2번부터 적용해야하는데 3번부터 되는 중 -> if문으로 해결보려했음
		// 2. 그러니까 링크 연결이 이상해져서 반복문으로 해결보려함
		// 됐다아아ㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏ
		// 역시 중요한 건 무엇이다? 꺾이지 않는 마음 !!!


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


#pragma endregion