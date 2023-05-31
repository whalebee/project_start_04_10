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
