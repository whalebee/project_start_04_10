#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
#pragma region 링크드 리스트 노가다 버전
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	typedef struct node {
		int number;
		struct node* p_next;
	}NODE;

	int main()
	{
		// 링크드 리스트 노가다버전 ( 이렇게 잘 안 씀 )

		// 스택영역에 링크드 리스트에 접근할 포인터 변수 선언 -> NULL 포인터로 초기화
		NODE* p_head = NULL;

		p_head = (NODE*)malloc(sizeof(NODE));
		if (p_head == NULL)
		{
			printf("동적할당 오류");
			return 1;
		}
		// 첫번째 노드
		p_head->number = 12;
		// (*p_head).number = 12;
		p_head->p_next = NULL;


		// 두번째 노드
		p_head->p_next = (NODE*)malloc(sizeof(NODE));
		if (p_head->p_next == NULL)
		{
			free(p_head);
			return 1;
		}
		p_head->p_next->number = 20;
		p_head->p_next->p_next = NULL;


		p_head->p_next->p_next = (NODE*)malloc(sizeof(NODE));
		if (p_head->p_next->p_next == NULL)
		{
			free(p_head->p_next);
			free(p_head);
			return 1;
		}
		p_head->p_next->p_next->number = 30;
		p_head->p_next->p_next->p_next = NULL;




		// 메모리 할당 해제
		free(p_head->p_next->p_next);
		free(p_head->p_next);
		free(p_head);


		return 0;
	}




#pragma endregion


#pragma region 링크드 리스트 함수 버전
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	typedef struct node {
		int number;
		struct node* p_next;
	}NODE;


	void append(NODE**, int);
	void show_list(NODE* p);
	void free_memory(NODE* p);
	void append_first(NODE*, int);


	int main()
	{
		// 링크드 리스트

		// 스택영역에 링크드 리스트에 접근할 포인터 변수 선언 -> NULL 포인터로 초기화
		NODE* p_head = NULL;
		// printf("첫 header의 주소는? %p \n", &p_head);

		append(&p_head, 10);
		append(&p_head, 20);
		append(&p_head, 30);
		append(&p_head, 40);
		append(&p_head, 50);
		append(&p_head, 60);
		append_first(&p_head, 100);


		// 노드의 값을 보여준다 !
		show_list(p_head);

		// 메모리 할당 해제 -> 있다고 생각
		free_memory(p_head);

		return 0;
	}


	// 1차원 포인터 변수의 주소를 받을 수 있는 2차원 포인터 변수를 매개변수로 설정
	void append(NODE** pp_header, int number)
	{
		// 새로운 노드 생성(임시 포인터에 주소대입)
		// 임시 포인터 temp
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		printf("할당받은 번지 %p \n", temp);
		if (temp == NULL)
		{
			printf("할당오류");
			return 1;
		}

		temp->number = number;
		// printf("할당받은 값 %d \n", temp->number);

		temp->p_next = NULL;

		// 첫번째 노드일 경우
		if (*pp_header == NULL) // 첫번째 노드면 주소값에 새로 만든 임시 주소값 넣어주기
		{
			*pp_header = temp;
		}
		else // 그게 아니라면 다음 노드를 가리키게
		{
			// 선생님이 말한 다음 노드를 찾을 때 새로운 변수 만들기
			NODE* p_find = *pp_header;

			// 넣어준 주소가 NULL값이 아닐 때 -> 즉, 마지막 노드가 아닐 때
			// (*p_find).p_next 를 줄인 것
			while (p_find->p_next != NULL)
			{
				p_find = p_find->p_next; // 다음 주소 넣어줘서 반복시키기
			}

			p_find->p_next = temp;
		}
	}

	void show_list(NODE* p)
	{
		int i = 1;
		while (p != NULL) {
			printf("%d번째 할당받은 값 : %d \n", i, p->number);
			p = p->p_next;
			i++;
		}
		printf("\n");
	}

	void free_memory(NODE* p)
	{
		NODE* temp;
		while (p != NULL)
		{
			printf("해제 전 주소 %p \n", p->p_next);
			temp = p->p_next;
			free(p);
			printf("해제 후 주소 %p \n", p->p_next);
			p = temp;
		}
	}

	void append_first(NODE** pp, int number) // 몰루..
	{
		NODE* temp = malloc(sizeof(NODE));
		if (temp == NULL)
		{
			printf("할당오류");
			return;
		}
		temp->number = number;
		temp->p_next = *pp;  // 새로운 노드의 다음 노드로 기존의 헤더 노드를 지정
		*pp = temp;  // pp가 가리키는 주소값을 새로운 노드의 주소값으로 변경


	}



#pragma endregion


#pragma region 링크드 리스트 함수 버전 ( 선생님 답안지 )
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	typedef struct node {
		int number;
		struct node* p_next;
	}NODE;


	void append(NODE**, int);
	void show_list(NODE* p);
	void free_memory(NODE* p);
	void append_first(NODE*, int);


	int main()
	{
		// 링크드 리스트

		// 스택영역에 링크드 리스트에 접근할 포인터 변수 선언 -> NULL 포인터로 초기화
		NODE* p_head = NULL;
		// printf("첫 header의 주소는? %p \n", &p_head);

		append(&p_head, 10);
		append(&p_head, 20);
		append(&p_head, 30);
		append(&p_head, 40);
		append(&p_head, 50);
		append(&p_head, 60);
		append_first(&p_head, 100);


		// 노드의 값을 보여준다 ! : 100 10 20 30 40 50 60
		show_list(p_head);

		// 메모리 할당 해제 
		free_memory(p_head);

		return 0;
	}


	// 1차원 포인터 변수의 주소를 받을 수 있는 2차원 포인터 변수를 매개변수로 설정
	void append(NODE** pp_header, int number)
	{
		// 새로운 노드 생성(임시 포인터에 주소대입)
		NODE* temp = NULL;
		while (temp == NULL)
		{
			temp = (NODE*)malloc(sizeof(NODE));
			printf("할당받은 번지 : %p \n", temp);
		}
		temp->number = number;
		temp->p_next = NULL; // 내가 끝이야 !


		// 첫번째 노드일 경우
		if (*pp_header == NULL) // 첫번째 노드면 주소값에 새로 만든 임시 주소값 넣어주기
		{
			*pp_header = temp;
		}
		else // 그게 아니라면 다음 노드를 가리키게
		{
			// 선생님이 말한 다음 노드를 찾을 때 새로운 변수 만들기
			NODE* current = *pp_header;

			// (*p_find).p_next 를 줄인 것
			while (current->p_next != NULL)
			{
				current = current->p_next; // 다음 주소 넣어줘서 반복시키기
			}

			current->p_next = temp; // 막 생성한 temp를 가리키게 하는 것
		}
	}

	void show_list(NODE* p)
	{
		int i = 1;
		while (p != NULL) {
			printf("%d번째 할당받은 값 : %d \n", i, p->number);
			p = p->p_next;
			i++;
		}
		printf("\n");
	}

	void free_memory(NODE* p)
	{
		NODE* temp;
		while (p != NULL)
		{
			printf("해제 전 주소 %p \n", p->p_next);
			temp = p->p_next;
			free(p);
			printf("해제 후 주소 %p \n", p->p_next);
			p = temp;
		}
	}

	void append_first(NODE** pp, int number)
	{
		NODE* temp = NULL;

		while (temp == NULL)
		{
			temp = (NODE*)malloc(sizeof(NODE));
		}

		printf("할당받은 번지 : %p \n", temp);
		temp->number = number;
		temp->p_next = NULL;
		if (*pp != NULL)
		{
			temp->p_next = *pp; // 새로운 노드의 다음 노드로 기존의 헤더 노드를 지정
		}
		*pp = temp;  // pp가 가리키는 주소값을 새로운 노드의 주소값으로 변경
	}



#pragma endregion


#pragma region 링크드 리스트 예제 1~2번 포함한 것 (get_list, insert)
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	typedef struct node {
		int number;
		struct node* p_next;
	}NODE;


	void append(NODE**, int);
	void show_list(NODE* p);
	void free_memory(NODE* p);
	void append_first(NODE*, int);

	// 과제
	int get_node_length(NODE* ptr);
	void insert(NODE** ptr, int position, int NewData);


	int main()
	{
		// 링크드 리스트

		// 스택영역에 링크드 리스트에 접근할 포인터 변수 선언 -> NULL 포인터로 초기화
		NODE* p_head = NULL;
		// printf("첫 header의 주소는? %p \n", &p_head);

		append(&p_head, 10);
		append(&p_head, 20);
		append(&p_head, 30);
		append(&p_head, 40);
		append(&p_head, 50);
		append(&p_head, 60);
		// insert(&p_head, 1, 77);
		append_first(&p_head, 100);

		// 1의 기준은 헤더 다음
		// append_first와의 우선순위는 나중에 입력된 함수가 우선순위를 가짐
		insert(&p_head, 1, 77);
		insert(&p_head, 5, 45);


		// 노드의 값을 보여준다 ! : 100 10 20 30 40 50 60
		show_list(p_head);


		// 노드의 총 개수
		get_node_length(p_head);



		// 메모리 할당 해제 
		free_memory(p_head);

		return 0;
	}


	// 1차원 포인터 변수의 주소를 받을 수 있는 2차원 포인터 변수를 매개변수로 설정
	void append(NODE** pp_header, int number)
	{
		// 새로운 노드 생성(임시 포인터에 주소대입)
		NODE* temp = NULL;
		while (temp == NULL)
		{
			temp = (NODE*)malloc(sizeof(NODE));
			printf("할당받은 번지 : %p \n", temp);
		}
		temp->number = number;
		temp->p_next = NULL; // 내가 끝이야 !


		// 첫번째 노드일 경우
		if (*pp_header == NULL) // 첫번째 노드면 주소값에 새로 만든 임시 주소값 넣어주기
		{
			*pp_header = temp;
		}
		else // 그게 아니라면 다음 노드를 가리키게
		{
			// 선생님이 말한 다음 노드를 찾을 때 새로운 변수 만들기
			NODE* current = *pp_header;

			// (*p_find).p_next 를 줄인 것
			while (current->p_next != NULL)
			{
				current = current->p_next; // 다음 주소 넣어줘서 반복시키기
			}

			current->p_next = temp; // 막 생성한 temp를 가리키게 하는 것
		}
	}

	void show_list(NODE* p)
	{
		int i = 1;
		while (p != NULL) {
			printf("%d번째 할당받은 값 : %d \n", i, p->number);
			p = p->p_next;
			i++;
		}
		printf("\n");
	}

	void free_memory(NODE* p)
	{
		NODE* temp;
		while (p != NULL)
		{
			printf("해제 전 주소 %p \n", p->p_next);
			temp = p->p_next;
			free(p);
			printf("해제 후 주소 %p \n", p->p_next);
			p = temp;
		}
	}

	void append_first(NODE** pp, int number)
	{
		NODE* temp = NULL;

		while (temp == NULL)
		{
			temp = (NODE*)malloc(sizeof(NODE));
		}

		printf("할당받은 번지 : %p \n", temp);
		temp->number = number;
		temp->p_next = NULL;
		if (*pp != NULL)
		{
			temp->p_next = *pp; // 새로운 노드의 다음 노드로 기존의 헤더 노드를 지정
		}
		*pp = temp;  // pp가 가리키는 주소값을 새로운 노드의 주소값으로 변경
	}


	int get_node_length(NODE* ptr)
	{
		NODE* temp_ptr = ptr;
		int count = 0;

		while (temp_ptr != NULL)
		{
			temp_ptr = temp_ptr->p_next;
			count++;
		}

		printf("총 노드 수는 : %d개 \n", count);
		return count;
	}



	void insert(NODE** ptr, int position, int NewData)
	{
		// 새 노드 만들기
		NODE* temp_ptr = (NODE*)malloc(sizeof(NODE));
		if (temp_ptr == NULL)
		{
			printf("할당오류");
			return;
		}
		temp_ptr->number = NewData;
		temp_ptr->p_next = NULL;

		// 위치를 세기위해 변수 선언
		int count = 1;

		// 선생님이 말씀해주신 다음 노드를 찾을 때 새로운 변수 만들기
		NODE* current = *ptr;

		// 만든 노드를 추가하기 위해 위치 파악하기
		// 1이면 헤더 바로 앞
		if (position == count)
		{
			temp_ptr->p_next = current; // 새로운 노드가 원래 헤드가 가르키던 곳을 가르키게 하고
			*ptr = temp_ptr; // 헤더는 새로운 노드를 바라보게 한다
		}
		else
		{
			// 1이 아닐 때
			while (position != count)
			{
				// ex) 3이면 노드가 3번째로 와야하니까
				if (position - 1 == count)
				{
					temp_ptr->p_next = current->p_next; // 현재 노드가 가르키는 주소(다음 노드 주소)를 temp_ptr이 가지고
					current->p_next = temp_ptr; // 현재 노드는 temp_ptr을 바라보게
				}

				// 다음 노드로 넘어가기 위한 변수 current의 다음 노드 주소 대입
				current = current->p_next;
				count++;
			}
		}
	}



#pragma endregion


#pragma region p.476페이지였나 거기 문제 -> 망함
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



	typedef struct student
	{
		char name[12];
		int kor_score;
		int eng_score;
		int math_score;
		int sum_score;
		float avg_score;
		struct student* p_next;
	}STUDENT;


	int print_menu();
	void input_score(STUDENT**);
	void print_score(STUDENT*);
	int get_length(STUDENT*);
	int get_rank(STUDENT*);


	int main()
	{
		// 헤드 만들기
		STUDENT* p_head = NULL;


		// 메뉴를 출력할 수 있게 하는 함수 만들기
		int menu = 0;

		while ((menu = print_menu()) != 3)
		{
			if (menu == 1)
			{
				input_score(&p_head);
			}
			else if (menu == 2)
			{
				print_score(p_head);
			}
		}
		printf("프로그램 종료.");


		return 0;
	}





	int print_menu()
	{
		int menu = 0;
		printf("[Menu]\n");
		printf("1. 성적 입력 \n");
		printf("2. 성적 확인 \n");
		printf("3. 종료 \n");
		printf("-------------- \n");
		printf("1번 ~ 3번 선택 \n");

		while (scanf("%d", &menu) != 1)
		{
			while (getchar() != '\n');
			printf("잘못입력했자너 ~ 다시하시오 \n");
		}

		return menu;
	}


	void input_score(STUDENT** pp_head)
	{
		STUDENT* new_node = NULL;
		int chk = 0;
		while (new_node == NULL) {
			new_node = (STUDENT*)malloc(sizeof(STUDENT));
		}

		printf("%d 번째 학생 이름 : ", get_length(*pp_head) + 1);
		chk = scanf("%s", new_node->name);

		printf("국어점수 : ");
		chk = scanf("%d", &new_node->kor_score);

		printf("영어점수 : ");
		chk = scanf("%d", &new_node->eng_score);

		printf("수학점수 : ");
		chk = scanf("%d", &new_node->math_score);

		new_node->sum_score = new_node->kor_score + new_node->eng_score + new_node->math_score;
		new_node->avg_score = (float)new_node->sum_score / 3;
		new_node->p_next = NULL;

		// for link
		if (*pp_head == NULL)
		{
			*pp_head = new_node;
		}
		else
		{
			STUDENT* cur = *pp_head;
			while (cur->p_next != NULL)
			{
				cur = cur->p_next;
			}
			cur->p_next = new_node;
		}
	}




	// 2. 출력 함수
	void print_score(STUDENT* p_head)
	{
		printf("-----------------------------------\n");
		printf("%6s%6s%6s%6s%6s  %6s %6s \n", "이름", "국어", "영어", "수학", "총점", "평균", "등수");
		printf("-----------------------------------\n");

		STUDENT* temp = p_head;

		while (p_head != NULL)
		{
			printf("%6s%6d%6d%6d%6d  %6.2f%4d등\n", p_head->name, p_head->kor_score, p_head->eng_score,
				p_head->math_score, p_head->sum_score, p_head->avg_score, get_rank(temp));

			temp = p_head->p_next;
		}
	}



	// 길이 반환
	int get_length(STUDENT* p_head)
	{
		STUDENT* temp = p_head;
		int cnt = 0;
		while (p_head != NULL)
		{
			p_head = p_head->p_next;
			cnt++;
		}
		p_head = temp;
		return cnt;
	}

	int get_rank(STUDENT* p_head)
	{
		//정보가 들어오면 그 정보를 토대로 반복문을 돌려서 서로 비교후에 등수 매기기

		int length = get_length(p_head);


		// 여러 개의 정보를 담을 가변 배열 만들기
		int* score = NULL;
		score = (int*)malloc(sizeof(int) * length); // length 안 써주니까 계속 오버런이라 하지
		//검사
		if (score == NULL)
		{
			printf("할당오류");
			return 1;
		}

		// score에 값 넣어주기
		int i = 0;
		STUDENT* temp = p_head;
		while (p_head != NULL)
		{
			score[i] = p_head->sum_score;
			printf("%d \n", score[i]);
			p_head = p_head->p_next;
			i++;
		}

		p_head = temp;


		// p_head = p_head->p_next;
		while (p_head != NULL)
		{
			int rank = 1;
			for (i = 0; i < length; i++)
			{
				if (p_head->sum_score < score[i])
				{
					rank++;
				}
				else
				{
					p_head = p_head->p_next;
					return rank;
				}
			}
			// printf("%s의 등수는 %d입니다.\n", p_head->name, rank);
		}


		// 메모리 해제
		free(score);
	}



#pragma endregion


#pragma region 책에 있는 예제 답안지
	// 염병.. ㅈㄴ 간단한거였네
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	typedef struct student
	{
		char name[12];
		int kor_score;
		int eng_score;
		int math_score;
		int sum_score;
		float avg_score;
		struct student* p_next;
	}STUDENT;

	int print_menu();
	void input_score(STUDENT**);
	void print_score(STUDENT*);
	int get_length(STUDENT*);
	int get_rank(STUDENT*, int); // 여기 매개변수가 늘어나네

	int main()
	{
		// 헤드 만들기
		STUDENT* p_head = NULL;


		// 메뉴를 출력할 수 있게 하는 함수 만들기
		int menu = 0;

		while ((menu = print_menu()) != 3)
		{
			if (menu == 1)
			{
				input_score(&p_head);
			}
			else if (menu == 2)
			{
				print_score(p_head);
			}
		}
		printf("프로그램 종료.");


		return 0;
	}

	int print_menu()
	{
		int menu = 0;
		printf("[Menu]\n");
		printf("1. 성적 입력 \n");
		printf("2. 성적 확인 \n");
		printf("3. 종료 \n");
		printf("-------------- \n");
		printf("1번 ~ 3번 선택 \n");

		while (scanf("%d", &menu) != 1)
		{
			while (getchar() != '\n');
			printf("잘못입력했자너 ~ 다시하시오 \n");
		}
		return menu;
	}

	void input_score(STUDENT** pp_head)
	{
		STUDENT* new_node = NULL;
		int chk = 0;
		while (new_node == NULL) {
			new_node = (STUDENT*)malloc(sizeof(STUDENT));
		}

		printf("%d 번째 학생 이름 : ", get_length(*pp_head) + 1);
		chk = scanf("%s", new_node->name);

		printf("국어점수 : ");
		chk = scanf("%d", &new_node->kor_score);

		printf("영어점수 : ");
		chk = scanf("%d", &new_node->eng_score);

		printf("수학점수 : ");
		chk = scanf("%d", &new_node->math_score);

		new_node->sum_score = new_node->kor_score + new_node->eng_score + new_node->math_score;
		new_node->avg_score = (float)new_node->sum_score / 3;
		new_node->p_next = NULL;

		// for link
		if (*pp_head == NULL)
		{
			*pp_head = new_node;
		}
		else
		{
			STUDENT* cur = *pp_head;
			while (cur->p_next != NULL)
			{
				cur = cur->p_next;
			}
			cur->p_next = new_node;
		}
	}

	// 2. 출력 함수
	void print_score(STUDENT* p_head)
	{
		printf("-----------------------------------\n");
		printf("%6s%6s%6s%6s%6s  %6s %6s \n", "이름", "국어", "영어", "수학", "총점", "평균", "등수");
		printf("-----------------------------------\n");

		STUDENT* temp = p_head;

		while (temp != NULL)
		{
			printf("%6s%6d%6d%6d%6d  %6.2f%4d등\n", temp->name, temp->kor_score, temp->eng_score,
				temp->math_score, temp->sum_score, temp->avg_score,
				get_rank(p_head, temp->sum_score)); // 그냥 총점만 받아가면 되지..

			temp = temp->p_next; // p_head->p_next가 아니라 temp->p_next 였어
		}
	}

	// 길이 반환
	int get_length(STUDENT* p_head)
	{
		int cnt = 0;
		while (p_head != NULL)
		{
			p_head = p_head->p_next;
			cnt++;
		}
		return cnt;
	}

	int get_rank(STUDENT* p_head, int my_score)
	{
		int rank = 1;

		while (p_head != NULL)
		{
			if (p_head->sum_score > my_score) rank++;
			p_head = p_head->p_next;
		}
		return rank;
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



	return 0;
}


