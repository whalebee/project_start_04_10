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
