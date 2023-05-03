#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
#pragma region ��ũ�� ����Ʈ �밡�� ����
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	typedef struct node {
		int number;
		struct node* p_next;
	}NODE;

	int main()
	{
		// ��ũ�� ����Ʈ �밡�ٹ��� ( �̷��� �� �� �� )

		// ���ÿ����� ��ũ�� ����Ʈ�� ������ ������ ���� ���� -> NULL �����ͷ� �ʱ�ȭ
		NODE* p_head = NULL;

		p_head = (NODE*)malloc(sizeof(NODE));
		if (p_head == NULL)
		{
			printf("�����Ҵ� ����");
			return 1;
		}
		// ù��° ���
		p_head->number = 12;
		// (*p_head).number = 12;
		p_head->p_next = NULL;


		// �ι�° ���
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




		// �޸� �Ҵ� ����
		free(p_head->p_next->p_next);
		free(p_head->p_next);
		free(p_head);


		return 0;
	}




#pragma endregion


#pragma region ��ũ�� ����Ʈ �Լ� ����
	//����
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
		// ��ũ�� ����Ʈ

		// ���ÿ����� ��ũ�� ����Ʈ�� ������ ������ ���� ���� -> NULL �����ͷ� �ʱ�ȭ
		NODE* p_head = NULL;
		// printf("ù header�� �ּҴ�? %p \n", &p_head);

		append(&p_head, 10);
		append(&p_head, 20);
		append(&p_head, 30);
		append(&p_head, 40);
		append(&p_head, 50);
		append(&p_head, 60);
		append_first(&p_head, 100);


		// ����� ���� �����ش� !
		show_list(p_head);

		// �޸� �Ҵ� ���� -> �ִٰ� ����
		free_memory(p_head);

		return 0;
	}


	// 1���� ������ ������ �ּҸ� ���� �� �ִ� 2���� ������ ������ �Ű������� ����
	void append(NODE** pp_header, int number)
	{
		// ���ο� ��� ����(�ӽ� �����Ϳ� �ּҴ���)
		// �ӽ� ������ temp
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		printf("�Ҵ���� ���� %p \n", temp);
		if (temp == NULL)
		{
			printf("�Ҵ����");
			return 1;
		}

		temp->number = number;
		// printf("�Ҵ���� �� %d \n", temp->number);

		temp->p_next = NULL;

		// ù��° ����� ���
		if (*pp_header == NULL) // ù��° ���� �ּҰ��� ���� ���� �ӽ� �ּҰ� �־��ֱ�
		{
			*pp_header = temp;
		}
		else // �װ� �ƴ϶�� ���� ��带 ����Ű��
		{
			// �������� ���� ���� ��带 ã�� �� ���ο� ���� �����
			NODE* p_find = *pp_header;

			// �־��� �ּҰ� NULL���� �ƴ� �� -> ��, ������ ��尡 �ƴ� ��
			// (*p_find).p_next �� ���� ��
			while (p_find->p_next != NULL)
			{
				p_find = p_find->p_next; 
				// ���� �ּ� �־��༭ ������ ��尡 ���� ������ �ݺ���Ű��
			}

			// ������ ��� ������ ���� ���� temp�� ����
			p_find->p_next = temp;
		}
	}

	void show_list(NODE* p)
	{
		int i = 1;
		while (p != NULL) {
			printf("%d��° �Ҵ���� �� : %d \n", i, p->number);
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
			printf("���� �� �ּ� %p \n", p->p_next);
			temp = p->p_next;
			free(p);
			printf("���� �� �ּ� %p \n", p->p_next);
			p = temp;
		}
	}

	void append_first(NODE** pp, int number) 
	{
		NODE* temp = malloc(sizeof(NODE));
		if (temp == NULL)
		{
			printf("�Ҵ����");
			return;
		}
		temp->number = number;
		temp->p_next = *pp;  // ���ο� ����� ���� ���� ������ ��� ��带 ����
		// ����� ������ �־��� p_next�� �޴� ��

		*pp = temp;  // pp�� ����Ű�� �ּҰ��� ���ο� ����� �ּҰ����� ����


	}



#pragma endregion


#pragma region ��ũ�� ����Ʈ �Լ� ���� ( ������ ����� )
	//����
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
		// ��ũ�� ����Ʈ

		// ���ÿ����� ��ũ�� ����Ʈ�� ������ ������ ���� ���� -> NULL �����ͷ� �ʱ�ȭ
		NODE* p_head = NULL;
		// printf("ù header�� �ּҴ�? %p \n", &p_head);

		append(&p_head, 10);
		append(&p_head, 20);
		append(&p_head, 30);
		append(&p_head, 40);
		append(&p_head, 50);
		append(&p_head, 60);
		append_first(&p_head, 100);


		// ����� ���� �����ش� ! : 100 10 20 30 40 50 60
		show_list(p_head);

		// �޸� �Ҵ� ���� 
		free_memory(p_head);

		return 0;
	}


	// 1���� ������ ������ �ּҸ� ���� �� �ִ� 2���� ������ ������ �Ű������� ����
	void append(NODE** pp_header, int number)
	{
		// ���ο� ��� ����(�ӽ� �����Ϳ� �ּҴ���)
		NODE* temp = NULL;
		while (temp == NULL)
		{
			temp = (NODE*)malloc(sizeof(NODE));
			printf("�Ҵ���� ���� : %p \n", temp);
		}
		temp->number = number;
		temp->p_next = NULL; // ���� ���̾� !


		// ù��° ����� ���
		if (*pp_header == NULL) // ù��° ���� �ּҰ��� ���� ���� �ӽ� �ּҰ� �־��ֱ�
		{
			*pp_header = temp;
		}
		else // �װ� �ƴ϶�� ���� ��带 ����Ű��
		{
			// �������� ���� ���� ��带 ã�� �� ���ο� ���� �����
			NODE* current = *pp_header;

			// (*p_find).p_next �� ���� ��
			while (current->p_next != NULL)
			{
				current = current->p_next; // ���� �ּ� �־��༭ �ݺ���Ű��
			}

			current->p_next = temp; // �� ������ temp�� ����Ű�� �ϴ� ��
		}
	}

	void show_list(NODE* p)
	{
		int i = 1;
		while (p != NULL) {
			printf("%d��° �Ҵ���� �� : %d \n", i, p->number);
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
			printf("���� �� �ּ� %p \n", p->p_next);
			temp = p->p_next;
			free(p);
			printf("���� �� �ּ� %p \n", p->p_next);
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

		printf("�Ҵ���� ���� : %p \n", temp);
		temp->number = number;
		temp->p_next = NULL;
		if (*pp != NULL)
		{
			temp->p_next = *pp; // ���ο� ����� ���� ���� ������ ��� ��带 ����
		}
		*pp = temp;  // pp�� ����Ű�� �ּҰ��� ���ο� ����� �ּҰ����� ����
	}



#pragma endregion


#pragma region ��ũ�� ����Ʈ ���� 1~2�� ������ �� (get_list, insert)
	//����
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

	// ����
	int get_node_length(NODE* ptr);
	void insert(NODE** ptr, int position, int NewData);


	int main()
	{
		// ��ũ�� ����Ʈ

		// ���ÿ����� ��ũ�� ����Ʈ�� ������ ������ ���� ���� -> NULL �����ͷ� �ʱ�ȭ
		NODE* p_head = NULL;
		// printf("ù header�� �ּҴ�? %p \n", &p_head);

		append(&p_head, 10);
		append(&p_head, 20);
		append(&p_head, 30);
		append(&p_head, 40);
		append(&p_head, 50);
		append(&p_head, 60);
		// insert(&p_head, 1, 77);
		append_first(&p_head, 100);

		// 1�� ������ ��� ����
		// append_first���� �켱������ ���߿� �Էµ� �Լ��� �켱������ ����
		insert(&p_head, 1, 77);
		insert(&p_head, 5, 45);


		// ����� ���� �����ش� ! : 100 10 20 30 40 50 60
		show_list(p_head);


		// ����� �� ����
		get_node_length(p_head);



		// �޸� �Ҵ� ���� 
		free_memory(p_head);

		return 0;
	}


	// 1���� ������ ������ �ּҸ� ���� �� �ִ� 2���� ������ ������ �Ű������� ����
	void append(NODE** pp_header, int number)
	{
		// ���ο� ��� ����(�ӽ� �����Ϳ� �ּҴ���)
		NODE* temp = NULL;
		while (temp == NULL)
		{
			temp = (NODE*)malloc(sizeof(NODE));
			printf("�Ҵ���� ���� : %p \n", temp);
		}
		temp->number = number;
		temp->p_next = NULL; // ���� ���̾� !


		// ù��° ����� ���
		if (*pp_header == NULL) // ù��° ���� �ּҰ��� ���� ���� �ӽ� �ּҰ� �־��ֱ�
		{
			*pp_header = temp;
		}
		else // �װ� �ƴ϶�� ���� ��带 ����Ű��
		{
			// �������� ���� ���� ��带 ã�� �� ���ο� ���� �����
			NODE* current = *pp_header;

			// (*p_find).p_next �� ���� ��
			while (current->p_next != NULL)
			{
				current = current->p_next; // ���� �ּ� �־��༭ �ݺ���Ű��
			}

			current->p_next = temp; // �� ������ temp�� ����Ű�� �ϴ� ��
		}
	}

	void show_list(NODE* p)
	{
		int i = 1;
		while (p != NULL) {
			printf("%d��° �Ҵ���� �� : %d \n", i, p->number);
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
			printf("���� �� �ּ� %p \n", p->p_next);
			temp = p->p_next;
			free(p);
			printf("���� �� �ּ� %p \n", p->p_next);
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

		printf("�Ҵ���� ���� : %p \n", temp);
		temp->number = number;
		temp->p_next = NULL;
		if (*pp != NULL)
		{
			temp->p_next = *pp; // ���ο� ����� ���� ���� ������ ��� ��带 ����
		}
		*pp = temp;  // pp�� ����Ű�� �ּҰ��� ���ο� ����� �ּҰ����� ����
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

		printf("�� ��� ���� : %d�� \n", count);
		return count;
	}



	void insert(NODE** ptr, int position, int NewData)
	{
		// �� ��� �����
		NODE* temp_ptr = (NODE*)malloc(sizeof(NODE));
		if (temp_ptr == NULL)
		{
			printf("�Ҵ����");
			return;
		}
		temp_ptr->number = NewData;
		temp_ptr->p_next = NULL;

		// ��ġ�� �������� ���� ����
		int count = 1;

		// �������� �������ֽ� ���� ��带 ã�� �� ���ο� ���� �����
		NODE* current = *ptr;

		// ���� ��带 �߰��ϱ� ���� ��ġ �ľ��ϱ�
		// 1�̸� ��� �ٷ� ��
		if (position == count)
		{
			temp_ptr->p_next = current; // ���ο� ��尡 ���� ��尡 ����Ű�� ���� ����Ű�� �ϰ�
			*ptr = temp_ptr; // ����� ���ο� ��带 �ٶ󺸰� �Ѵ�
		}
		else
		{
			// 1�� �ƴ� ��
			while (position != count)
			{
				// ex) 3�̸� ��尡 3��°�� �;��ϴϱ�
				if (position - 1 == count)
				{
					temp_ptr->p_next = current->p_next; // ���� ��尡 ����Ű�� �ּ�(���� ��� �ּ�)�� temp_ptr�� ������
					current->p_next = temp_ptr; // ���� ���� temp_ptr�� �ٶ󺸰�
				}

				// ���� ���� �Ѿ�� ���� ���� current�� ���� ��� �ּ� ����
				current = current->p_next;
				count++;
			}
		}
	}



#pragma endregion


#pragma region p.476���������� �ű� ���� -> ����
	//����
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
		// ��� �����
		STUDENT* p_head = NULL;


		// �޴��� ����� �� �ְ� �ϴ� �Լ� �����
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
		printf("���α׷� ����.");


		return 0;
	}





	int print_menu()
	{
		int menu = 0;
		printf("[Menu]\n");
		printf("1. ���� �Է� \n");
		printf("2. ���� Ȯ�� \n");
		printf("3. ���� \n");
		printf("-------------- \n");
		printf("1�� ~ 3�� ���� \n");

		while (scanf("%d", &menu) != 1)
		{
			while (getchar() != '\n');
			printf("�߸��Է����ڳ� ~ �ٽ��Ͻÿ� \n");
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

		printf("%d ��° �л� �̸� : ", get_length(*pp_head) + 1);
		chk = scanf("%s", new_node->name);

		printf("�������� : ");
		chk = scanf("%d", &new_node->kor_score);

		printf("�������� : ");
		chk = scanf("%d", &new_node->eng_score);

		printf("�������� : ");
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




	// 2. ��� �Լ�
	void print_score(STUDENT* p_head)
	{
		printf("-----------------------------------\n");
		printf("%6s%6s%6s%6s%6s  %6s %6s \n", "�̸�", "����", "����", "����", "����", "���", "���");
		printf("-----------------------------------\n");

		STUDENT* temp = p_head;

		while (p_head != NULL)
		{
			printf("%6s%6d%6d%6d%6d  %6.2f%4d��\n", p_head->name, p_head->kor_score, p_head->eng_score,
				p_head->math_score, p_head->sum_score, p_head->avg_score, get_rank(temp));

			temp = p_head->p_next;
		}
	}



	// ���� ��ȯ
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
		//������ ������ �� ������ ���� �ݺ����� ������ ���� ���Ŀ� ��� �ű��

		int length = get_length(p_head);


		// ���� ���� ������ ���� ���� �迭 �����
		int* score = NULL;
		score = (int*)malloc(sizeof(int) * length); // length �� ���ִϱ� ��� �������̶� ����
		//�˻�
		if (score == NULL)
		{
			printf("�Ҵ����");
			return 1;
		}

		// score�� �� �־��ֱ�
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
			// printf("%s�� ����� %d�Դϴ�.\n", p_head->name, rank);
		}


		// �޸� ����
		free(score);
	}



#pragma endregion


#pragma region å�� �ִ� ���� �����
	// ����.. ���� �����Ѱſ���
	//����
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
	int get_rank(STUDENT*, int); // ���� �Ű������� �þ��

	int main()
	{
		// ��� �����
		STUDENT* p_head = NULL;


		// �޴��� ����� �� �ְ� �ϴ� �Լ� �����
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
		printf("���α׷� ����.");


		return 0;
	}

	int print_menu()
	{
		int menu = 0;
		printf("[Menu]\n");
		printf("1. ���� �Է� \n");
		printf("2. ���� Ȯ�� \n");
		printf("3. ���� \n");
		printf("-------------- \n");
		printf("1�� ~ 3�� ���� \n");

		while (scanf("%d", &menu) != 1)
		{
			while (getchar() != '\n');
			printf("�߸��Է����ڳ� ~ �ٽ��Ͻÿ� \n");
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

		printf("%d ��° �л� �̸� : ", get_length(*pp_head) + 1);
		chk = scanf("%s", new_node->name);

		printf("�������� : ");
		chk = scanf("%d", &new_node->kor_score);

		printf("�������� : ");
		chk = scanf("%d", &new_node->eng_score);

		printf("�������� : ");
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

	// 2. ��� �Լ�
	void print_score(STUDENT* p_head)
	{
		printf("-----------------------------------\n");
		printf("%6s%6s%6s%6s%6s  %6s %6s \n", "�̸�", "����", "����", "����", "����", "���", "���");
		printf("-----------------------------------\n");

		STUDENT* temp = p_head;

		while (temp != NULL)
		{
			printf("%6s%6d%6d%6d%6d  %6.2f%4d��\n", temp->name, temp->kor_score, temp->eng_score,
				temp->math_score, temp->sum_score, temp->avg_score,
				get_rank(p_head, temp->sum_score)); // �׳� ������ �޾ư��� ����..

			temp = temp->p_next; // p_head->p_next�� �ƴ϶� temp->p_next ����
		}
	}

	// ���� ��ȯ
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


