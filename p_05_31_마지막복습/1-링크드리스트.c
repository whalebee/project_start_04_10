#pragma region ��ũ�帮��Ʈ ���� ���� 1
// start
#include "header.h"

typedef struct node
{
	int data;
	struct node* left_child;
	struct node* right_child;
}NODE;

// ���� �ִ� �ͺ��� ������
NODE* insert_node(NODE* root, int data);

// �� ���� ã�� ��
NODE* search_node(NODE* root, int data);


// �������ֱ�
// ���� V L R 
void preorder_node(NODE* root);
// ���� L V R
void inorder_node(NODE* root);
// ���� L R V
void postorder_node(NODE* root);


// �ּҰ� ã�� ( ���� )
NODE* find_min_node(NODE* root);
// �ִ밪 ã�� ( ������ )
NODE* find_max_node(NODE* root);


// ���� ( Ư�� �� )
NODE* delete_node(NODE* root, int data);



// ���� ( ��� )

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
	// �ߺ�Ȯ��
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
	printf("�ּ� �� : %d \n", min_node->data);

	puts(" ");
	NODE* max_node = find_max_node(root);
	printf("�ִ� �� : %d \n", max_node->data);

	puts(" ");
	delete_node(root, 20);

	puts(" ");
	printf("preorder : ");
	preorder_node(root);



	return 0;
}


NODE* insert_node(NODE* root, int data)
{
	// root�� NULL �� �� ����������
	if (root == NULL)
	{
		// root�� NULL�̸� ��� �����Ҵ����� �������
		while (root == NULL)
		{
			root = (NODE*)malloc(sizeof(NODE));
			printf("���� %p \n", root);
		}

		// ����������� �� �־�����
		// data �־��ְ�
		root->data = data;

		// ó������ node�ϱ� �� �� �ּҰ��� �� NULL �־��ֱ�
		root->left_child = NULL;
		root->right_child = NULL;

		return root;
	}
	else
	{
		// ���� �Ȱ��ٸ�?
		if (data == root->data)
		{
			printf("�Ȱ��� ���� ������ �ϰ� �ּ�. \n");
			return root;
		}

		// �������� ���� ���� ������ ������ �������� �����ϴϱ�
		if (data < root->data)
		{
			root->left_child = insert_node(root->left_child, data);
		}
		else
		{
			root->right_child = insert_node(root->right_child, data);
		}
	}
	// ������ ��� �Ѱ������
	return root;
}

NODE* search_node(NODE* root, int data)
{
	// ���� ã�°� ���ų� ��尡 ���ų� �׷� NULL
	if (root == NULL) return NULL;

	// ���� ã�� ���� ���ٸ�?
	if (data == root->data)
	{
		return root;
	}
	// data�� ���� �ִ� ��Ʈ�� ������ ������ �������� ��������
	else if (data < root->data)
	{
		// �ּҰ��̶� ������ ���� ��� ��
		return search_node(root->left_child, data);
	}
	else
	{
		return search_node(root->right_child, data);
	}
}

void preorder_node(NODE* root)
{
	// ������ ����
	if (root == NULL) return;
	// ������ָ鼭 ����Լ��� ������� ã�� void�� ���� ����
	printf("%d ", root->data); // data�� ���������
	preorder_node(root->left_child);
	preorder_node(root->right_child);
}

void inorder_node(NODE* root)
{
	// ������ ����
	if (root == NULL) return;
	inorder_node(root->left_child);
	printf("%d ", root->data);
	inorder_node(root->right_child);
}

void postorder_node(NODE* root)
{
	// ������ ����
	if (root == NULL) return;
	// L R V �������
	postorder_node(root->left_child);
	postorder_node(root->right_child);
	printf("%d ", root->data);
}

NODE* find_min_node(NODE* root)
{
	// root �� NULL�� �ƴϸ�
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

	// ������ ���� ~
	if (root == NULL) return NULL;

	// ������ �Ű������� root�� data������ ������ �������� ������
	if (data < root->data)
	{
		// ����Լ��� ����, �ּҶ� �� ���� ������ ~
		root->left_child = delete_node(root->left_child, data);
	}
	// ũ�� ���������� ������
	else if (data > root->data)
	{
		root->right_child = delete_node(root->right_child, data);
	}
	else
	{
		// �ڽ� ��尡 �� �� ������ �� ���� �����Ͽ�
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


#pragma region ��ũ�帮��Ʈ ���� ���� 2 ���� �� ����
// start
#include "header.h"

/*
	�ϼ����� -> ���� ���� �� ����
	�Լ��� ����� �� �������
	������ �͵� ����
*/


// ����ü ����
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



// �Է� �Լ������ -> void������ ���� �� ��? -> int������ return�� �Ἥ �� �Ǵ��� Ȯ���غ���
// �Ű������� ��� �ұ� -> �ּҰ��� ����ؾ��ϴϱ� �������� �޾ƾ� �� ��
int writing_info(MYCLASS** p_info);

// ��� �Լ������
void show_info(MYCLASS* p_info);

// ��� �Լ������ -> �Ű�������?
int get_rank(MYCLASS* p_info, unsigned int sum);


int main()
{
	/*
	[menu]
	1. ���� �Է�
	2. ���� Ȯ��
	3. ����
	-------------
	����(1~3) :

	######################
	1�� �޴� ���� �� �Է�
	######################
	n��° �л��̸� :
	���� ���� :
	���� ���� :
	���� ���� :

	######################
	2�� �޴� ���� �� ���
	######################

	---------------------------------------------------------
	�̸�		����	����	����	����	���	���
	---------------------------------------------------------
	�����		100		100		100		300		100		1



	����� �Ҽ�����.. ������...? ��� ó���ұ� ����� �߿��ϴϱ� float�� ����
	���..... ������ ������ ���� �Ѱ��༭ ���ϰ� �߾����� ����� ���µ���...��������...
	*/

	MYCLASS* info_head = NULL;
	int num = 0;

	while (1)
	{
		puts(" ");
		printf("[menu]\n");
		printf("1. ���� �Է�\n");
		printf("2. ���� Ȯ��\n");
		printf("3. ����\n");
		printf("-------------\n");
		printf("���� ( 1 ~ 3 ) : ");
		scanf("%d", &num);
		getchar(); // ���ڰ� �ƴ� ���ڸ� �Է����� �� ���ѷ����� �����ϱ� ���� �������� �Լ�

		if (num == 1)
		{
			if (writing_info(&info_head) == 1)
			{
				printf("�Է� �Ϸ� ! \n");
			}
		}
		else if (num == 2)
		{
			show_info(info_head);
		}
		else if (num == 3)
		{
			printf("menu�� �����մϴ� :D \n");
			break;
		}
		else
		{
			printf("���õ� ��ȣ�� �Է��ؾ���? ( 1 ~ 3 ) \n");
		}
	}




	return 0;
}

int writing_info(MYCLASS** p_info)
{
	static int count = 0; // n��° �л��� ����
	printf("######################\n");
	printf("1�� �޴� ���� �� �Է�\n");
	printf("######################\n");
	count++;

	MYCLASS* new_temp = NULL;

	new_temp = (MYCLASS*)malloc(sizeof(MYCLASS));
	if (new_temp == NULL)
	{
		printf("�޸� �Ҵ� ���� \n");
		return 0;
	}

	printf("%d��° �л��� �̸� : ", count);
	scanf("%s", new_temp->name);

	// %d ���� %u���� unsigned int ������.
	printf("���� ���� : ");
	scanf("%u", &new_temp->korean_score);

	printf("���� ���� : ");
	scanf("%u", &new_temp->english_score);

	printf("���� ���� : ");
	scanf("%u", &new_temp->math_score);


	new_temp->sum_score = new_temp->korean_score + new_temp->english_score + new_temp->math_score;
	new_temp->avg_score = (float)new_temp->sum_score / 3.0f;
	new_temp->next = NULL;

	// ��尡 ���� ��
	if (*p_info == NULL)
	{

		*p_info = new_temp;

		return 1;
	}
	else // ù ��尡 �ƴϸ�
	{

		// �� �� ������ �������� current(cur) ����
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
	printf("2�� �޴� ���� �� ��� \n");
	printf("###################### \n");
	puts(" ");
	printf("---------------------------------------------------------------------------- \n");
	printf("�̸�		����	����	����	����	���	���\n");
	printf("---------------------------------------------------------------------------- \n");

	MYCLASS* cur = p_info;

	if (cur == NULL)
	{
		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@ Ȯ���� ������ ����� @@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
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


#pragma region ��ũ�帮��Ʈ ���� ���� 2 ������ ����
#include<stdio.h>
#include<malloc.h>

typedef struct node {
	char name[10];  // �̸�
	int kor_score;  // ��������
	int eng_score;  // ��������
	int math_score; // ��������
	int sum;		// ����
	double avg;		// ���
	struct node* p_next; // ���� ��带 ����ų ������
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
			printf("�߸��Է��߽��ϴ�.");
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
	printf("1.���� �Է�\n");
	printf("2.���� Ȯ��\n");
	printf("3.����\n");
	printf("-----------\n");
	printf("����(1~3):_");

	chk = scanf("%d", &menu);
	if (chk != 1) {
		printf("�߸��Է����ڳ�!!!\n");
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
		printf("%d��° �л� �̸� : ", index);
		chk = scanf("%s", new_node->name);

		printf("���� ���� : ");
		chk = scanf("%d", &new_node->kor_score);

		printf("���� ���� : ");
		chk = scanf("%d", &new_node->eng_score);

		printf("���� ���� : ");
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
		printf("���� ����Ʈ�� �����ϴ�.\n");
	}
	else {
		SNODE* cur = p_header;
		printf("-------------------------------------\n");
		printf("%6s%5s%5s%5s%5s%5s%5s\n", "�̸�", "����", "����", "����", "����", "���", "���");
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


#pragma region ��ũ�帮��Ʈ ���� ���� 2 �����ߴ� ��ϵ�

// cur
#include "header.h"

// ����ü ����
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



// �Է� �Լ������ -> void������ ���� �� ��? -> int������ return�� �Ἥ �� �Ǵ��� Ȯ���غ���
// �Ű������� ��� �ұ� -> �ּҰ��� ����ؾ��ϴϱ� �������� �޾ƾ� �� ��
int writing_info(MYCLASS** p_info);

// ��� �Լ������
void show_info(MYCLASS* p_info);


int main()
{
	/*
	[menu]
	1. ���� �Է�
	2. ���� Ȯ��
	3. ����
	-------------
	����(1~3) :

	######################
	1�� �޴� ���� �� �Է�
	######################
	n��° �л��̸� :
	���� ���� :
	���� ���� :
	���� ���� :

	######################
	2�� �޴� ���� �� ���
	######################

	---------------------------------------------------------
	�̸�		����	����	����	����	���	���
	---------------------------------------------------------
	�����		100		100		100		300		100		1



	����� �Ҽ�����.. ������...? ��� ó���ұ� ����� �߿��ϴϱ� float�� ����
	���..... ������ ������ ���� �Ѱ��༭ ���ϰ� �߾����� ����� ���µ���...��������...
	*/

	MYCLASS* info_head = NULL;
	int num = 0;

	while (1)
	{
		puts(" ");
		printf("[menu]\n");
		printf("1. ���� �Է�\n");
		printf("2. ���� Ȯ��\n");
		printf("3. ����\n");
		printf("-------------\n");
		printf("���� ( 1 ~ 3 ) : ");
		scanf("%d", &num);
		getchar(); // ���ڰ� �ƴ� ���ڸ� �Է����� �� ���ѷ����� �����ϱ� ���� �������� �Լ�

		if (num == 1)
		{
			if (writing_info(&info_head) == 1)
			{
				printf("�Է� �Ϸ� ! \n");
			}
		}
		else if (num == 2)
		{
			show_info(info_head);
		}
		else if (num == 3)
		{
			printf("menu�� �����մϴ� :D \n");
			break;
		}
		else
		{
			printf("���õ� ��ȣ�� �Է��ؾ���? ( 1 ~ 3 ) \n");
		}
	}




	return 0;
}

int writing_info(MYCLASS** p_info)
{
	static int count = 0; // n��° �л��� ����
	printf("######################\n");
	printf("1�� �޴� ���� �� �Է�\n");
	printf("######################\n");
	count++;

	MYCLASS* new_temp = NULL;

	new_temp = (MYCLASS*)malloc(sizeof(MYCLASS));
	if (new_temp == NULL)
	{
		printf("�޸� �Ҵ� ���� \n");
		return 0;
	}

	printf("%d��° �л��� �̸� : ", count);
	scanf("%s", new_temp->name);

	// %d ���� %u���� unsigned int ������.
	printf("���� ���� : ");
	scanf("%u", &new_temp->korean_score);

	printf("���� ���� : ");
	scanf("%u", &new_temp->english_score);

	printf("���� ���� : ");
	scanf("%u", &new_temp->math_score);




	new_temp->sum_score = new_temp->korean_score + new_temp->english_score + new_temp->math_score;
	new_temp->avg_score = (float)new_temp->sum_score / 3.0f;
	new_temp->next = NULL;



	new_temp->rank = 1;


	// ��尡 ���� ��
	if (*p_info == NULL)
	{
		*p_info = new_temp;

		return 1;
	}
	else // ù ��尡 �ƴϸ�
	{

		MYCLASS* cur = *p_info;
		MYCLASS* fin = *p_info;



		// ���� ���� ���� �ΰ���
		// �߿��� �� ������ �ʴ� ����..

		// --------------------------------------
		// rank ������Ʈ ����

		// �ּҸ� ó������ ������ ���鼭 ���԰� ���ÿ� rank�� ������ ���� ������?
		// ���ο� ��尡 ��������� �Է��� �� ������ *p_info�� �̿��ؼ� ó������ ������ ���Ѵٸ�?

		// rank�� � ������� �ο��ϸ� ������..

		// ��带 �Է��� �� ���� new_rank�� 1���� �����Ѵ�?
		int new_rank = 1;
		int count = 0;

		// 2��° ������ ( ������ ó�� ������ ���� )
		while (cur != NULL)
		{



			// ��������ó�� �Ѵٸ�?
			// �̷����ϸ�? -> ���� �ּҿ� ���ϴ� �ǵ�
			// ���� ��尡 �� ũ�� ���� ��忡 rank �ְ�
			// ���� ��带 cur�� �ֱ� ?
			if (cur->sum_score < cur->next->sum_score)
			{
				new_rank;;
				cur->rank = new_rank;

				cur = cur->next;
			}
			// ���� ��尡 �� ũ��?
			// ���� ��忡 rank �����ְ�.. �� ���� ���� �񱳤��� �����̰�
			// �׷� �� ���� ��庸�� ���� ��尡 ũ�� �� �� ���� ���� ���ؾߵ�?
			else if (cur->sum_score > cur->next->sum_score)
			{
				new_rank++;
				cur->next->rank = new_rank;

				// ����, �� ����, �ٴ� �������� ��������...��������
				count++;
				for (int i = 0; i <= count; i++)
				{
					cur = cur->next;
				}
			}





			/*
			// �̰� ���ο� ������! ���ϴ°Ű�
			if (cur->sum_score <= new_temp->sum_score) // ���� ��尡 �� ũ��?
			{
				new_rank++;
				cur->rank = new_rank; // ���� ��忡 rank �߰�
			}
			else if (cur->sum_score > new_temp->sum_score) // ���� ��尡 �� ũ��?
			{
				new_rank++;
				new_temp->rank = new_rank; // ���� ��忡 rank �߰�
			}


			cur = cur->next;

			*/



			// 30 15 40 25 �� ��
			// 1. 30�� 15 �񱳸� �ϸ�? -> 30�� �����ϱ� rank�� �׳� 1
			// 2. 15�� 40�� ���ϸ�? -> 15�� �۾Ƽ� rank�� 2�� ����
			// 3. 40�� 25�� ���ϸ�? -> 40�� �� �����Ƿ� rank�� �׳� 2 ?
			// ��, 3��° ��带 �Է��ϸ� 1 2 3 ��θ� ���ؼ� rank�� �ؾߵ�
			// 1���� 2�� 3���� �񱳸��ϰ�?
			// 1���� 2���� ���ϰ� ���� �ְ� �����ǰ�?
			// �� �����ְ� 3���� �񱳸� �ϰ� ���⼭ ���� �ְ� �ٽ� �����ǰ�?
			// �������� ���� ���� �ֵ��� rank + 1
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
	printf("2�� �޴� ���� �� ��� \n");
	printf("###################### \n");
	puts(" ");
	printf("---------------------------------------------------------------------------- \n");
	printf("�̸�		����	����	����	����	���	���\n");
	printf("---------------------------------------------------------------------------- \n");

	MYCLASS* cur = p_info;

	if (cur == NULL)
	{
		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@ Ȯ���� ������ ����� @@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
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


#pragma region ��������? �߿��� �� ������ �ʴ� ����

// cur
#include "header.h"

// ����ü ����
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



// �Է� �Լ������ -> void������ ���� �� ��? -> int������ return�� �Ἥ �� �Ǵ��� Ȯ���غ���
// �Ű������� ��� �ұ� -> �ּҰ��� ����ؾ��ϴϱ� �������� �޾ƾ� �� ��
int writing_info(MYCLASS** p_info);

// ��� �Լ������
void show_info(MYCLASS* p_info);


// �����Ҵ� ����
void delete_list(MYCLASS** p_info);

int main()
{
	/*
	[menu]
	1. ���� �Է�
	2. ���� Ȯ��
	3. ����
	-------------
	����(1~3) :

	######################
	1�� �޴� ���� �� �Է�
	######################
	n��° �л��̸� :
	���� ���� :
	���� ���� :
	���� ���� :

	######################
	2�� �޴� ���� �� ���
	######################

	---------------------------------------------------------
	�̸�		����	����	����	����	���	���
	---------------------------------------------------------
	�����		100		100		100		300		100		1



	����� �Ҽ�����.. ������...? ��� ó���ұ� ����� �߿��ϴϱ� float�� ����
	���..... ������ ������ ���� �Ѱ��༭ ���ϰ� �߾����� ����� ���µ���...��������...
	*/

	MYCLASS* info_head = NULL;
	int num = 0;

	while (1)
	{
		puts(" ");
		printf("[menu]\n");
		printf("1. ���� �Է�\n");
		printf("2. ���� Ȯ��\n");
		printf("3. ����\n");
		printf("-------------\n");
		printf("���� ( 1 ~ 3 ) : ");
		scanf("%d", &num);
		getchar(); // ���ڰ� �ƴ� ���ڸ� �Է����� �� ���ѷ����� �����ϱ� ���� �������� �Լ�

		if (num == 1)
		{
			if (writing_info(&info_head) == 1)
			{
				printf("�Է� �Ϸ� ! \n");
			}
		}
		else if (num == 2)
		{
			show_info(info_head);
		}
		else if (num == 3)
		{
			printf("menu�� �����մϴ� :D \n");
			break;
		}
		else
		{
			printf("���õ� ��ȣ�� �Է��ؾ���? ( 1 ~ 3 ) \n");
		}
	}

	// ����
	delete_list(&info_head);

	return 0;
}

int writing_info(MYCLASS** p_info)
{
	static int count = 0; // n��° �л��� ����
	printf("######################\n");
	printf("1�� �޴� ���� �� �Է�\n");
	printf("######################\n");
	count++;

	MYCLASS* new_temp = NULL;

	new_temp = (MYCLASS*)malloc(sizeof(MYCLASS));
	if (new_temp == NULL)
	{
		printf("�޸� �Ҵ� ���� \n");
		return 0;
	}

	printf("%d��° �л��� �̸� : ", count);
	scanf("%s", new_temp->name);

	// %d ���� %u���� unsigned int ������.
	printf("���� ���� : ");
	scanf("%u", &new_temp->korean_score);

	printf("���� ���� : ");
	scanf("%u", &new_temp->english_score);

	printf("���� ���� : ");
	scanf("%u", &new_temp->math_score);

	new_temp->sum_score = new_temp->korean_score + new_temp->english_score + new_temp->math_score;
	new_temp->avg_score = (float)new_temp->sum_score / 3.0f;
	new_temp->next = NULL;



	new_temp->rank = 1;

	// ��尡 ���� ��
	if (*p_info == NULL)
	{
		*p_info = new_temp;

		return 1;
	}
	else // ù ��尡 �ƴϸ�
	{

		MYCLASS* cur = *p_info;
		MYCLASS* prev = NULL;
		int cur_rank = 1;

		// �� ó�� ������ ���ο� ����� ���պ��� ũ�ų� ���� ��
		while (cur != NULL && cur->sum_score >= new_temp->sum_score)
		{
			prev = cur; // ��ũ�� �� ��ߵ� ��
			cur = cur->next; // ���� �ּҷ� ( ó������ ���ƾ��ϴϱ� )
			cur_rank++; // ũ�� ��ũ �� ���Ѿ���
		}
		// ���鼭 ������ ���� �� ��ũ���� �����ֱ� ����
		while (cur != NULL && cur->sum_score < new_temp->sum_score)
		{
			prev = cur;
			cur->rank = cur->rank + 1;
			cur = cur->next;
		}

		new_temp->rank = cur_rank;

		if (prev == NULL) // new_temp�� ù ��° �л����� ������ ���� ���
		{
			new_temp->next = *p_info;
			*p_info = new_temp;
		}
		else // �߰��̳� �������� �����ؾ� �� ���
		{
			prev->next = new_temp;
			new_temp->next = NULL;
		}

		// ���� ����
		// 1. rank up ���� -> 4�� ���� 2������ �����ؾ��ϴµ� 3������ �Ǵ� �� -> if������ �ذẸ������
		// 2. �׷��ϱ� ��ũ ������ �̻������� �ݺ������� �ذẸ����
		// �ƴپƾƤ�������������������������������������������������������������������������������������
		// ���� �߿��� �� �����̴�? ������ �ʴ� ���� !!!


		return 1;
	}


	return 0;
}

void show_info(MYCLASS* p_info)
{
	printf("###################### \n");
	printf("2�� �޴� ���� �� ��� \n");
	printf("###################### \n");
	puts(" ");
	printf("---------------------------------------------------------------------------- \n");
	printf("�̸�		����	����	����	����	���	���\n");
	printf("---------------------------------------------------------------------------- \n");

	MYCLASS* cur = p_info;

	if (cur == NULL)
	{
		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@ Ȯ���� ������ ����� @@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
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