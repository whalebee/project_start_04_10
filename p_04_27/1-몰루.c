#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
#pragma region �ڷᱸ�� - Ʈ��
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ���� Ž��Ʈ��
	typedef struct node
	{
		int data;
		struct node* leftChild;
		struct node* rightChild;
	}NODE;


	NODE* insertNode(NODE * root, int data);
	NODE* searchNode(NODE * root, int data);

	void preorder(NODE * root);
	void inorder(NODE * root);
	void postorder(NODE * root);

	NODE* findMinNode(NODE * root); // �ּ�
	NODE* rightFindMinNode(NODE * root); // ������ ����Ʈ�� �ּ�

	NODE* deleteNode_practice(NODE * root, int value);
	NODE* deleteNode(NODE * root, int data);

	void freeAll(NODE * root);

	// ������ȸ preorder ��Ʈ -> ���� -> ������
	// ������ȸ inorder ���� -> ��Ʈ -> ������
	// ������ȸ postorder ���� -> ������ -> ��Ʈ

	int main()
	{
		NODE* root = NULL;

		root = insertNode(root, 30);
		//printf("ó�� ��� %p\n", root);
		root = insertNode(root, 17);
		root = insertNode(root, 48);

		root = insertNode(root, 5);
		root = insertNode(root, 23);
		root = insertNode(root, 37);
		root = insertNode(root, 50);

		/*
		�ߺ�Ȯ��
		root = insertNode(root, 40);
		root = insertNode(root, 40);
		*/

		/*
		NODE�ڷ��� ����Ʈ ���� root�� NULL�� �ʱ�ȭ�Ͽ� ����

		ù��° ����
		NULL������ �ʱ�ȭ �Ǿ��ִ� root�� insertnode �Լ��� ���

		insertnode�� �� ��
		�Ű������� root : NULL �� 30
		if�� ������ root == NULL�� �����Ͽ� �ɸ��� ��
		root�� malloc���� �Ҵ��� �޸��� ù��° �ּҰ��� ����
		root->data�� �Ű����� data���� ����
		malloc�� �ּҸ� ���� root�� ����


		�ι�° ����
		insertnode�� �� ��
		�Ű����� root : ���� ���� malloc�� �ּ�, 48
		if�� ������ root == NULL�� �ɸ��� �ʾƼ� else������ ����
		data == root->data�� �ɸ��� ����


		*/





		puts(" ");
		printf("preorder ");	// ��Ʈ -> ���� -> ������
		preorder(root);			// 

		puts(" ");
		root = deleteNode(root, 17);
		printf("���� �� �� : ");
		preorder(root);


		puts(" ");
		puts(" ");
		printf("inorder ");	// ���� -> ��Ʈ -> ������
		inorder(root);			// 




		puts(" ");
		puts(" ");
		printf("postorder ");	// ���� -> ������ -> ��Ʈ
		postorder(root);		// 15 25 20 40 48 30








		puts(" ");
		NODE* find = NULL;
		find = searchNode(root, 40);
		printf("%p \n", find);


		NODE* minNode = findMinNode(root);
		printf("�ּ� : %d \n", minNode->data);


		NODE* rightminNode = rightFindMinNode(root);
		printf("�ּ� : %d \n", rightminNode->data);




		freeAll(root);
		// ��带 �����ߴٸ� �ּҰ��� �ٸ� �� �ִ� !
		return 0;
	}


	NODE* insertNode(NODE * root, int data)
	{
		// 48�� �Է����� ��
		// NULL�� 48�� ������ ���� ��


		// Ʈ����� ����� ����
		if (root == NULL)
		{
			while (root == NULL)
			{
				root = (NODE*)malloc(sizeof(NODE));
				printf("���� %p\n", root);
			}

			root->data = data;
			printf("%d \n", data);
			root->leftChild = NULL;
			root->rightChild = NULL;
			return root;
		}
		// ���⼭���� ����Լ� ����
		else
		{
			if (data == root->data)
			{
				printf("�Էµ� ���� �ߺ��� �� �� �����̴�. \n");
				return root;
			}

			// root�� data�� �Էµ� data���� ������ ���ʿ� �߰�
			if (data < root->data)
			{
				// ����Լ�
				root->leftChild = insertNode(root->leftChild, data);
				// ����Լ��� ������ �ٽ� ����� ���Ե�
			}
			else
			{
				// �����ʿ� �߰�
				root->rightChild = insertNode(root->rightChild, data);
			}
		}


		return root;
	}


	NODE* searchNode(NODE * root, int data)
	{
		if (root == NULL) return NULL; // ��尡 ���ų� ���� ã�� ���� ����

		if (root->data == data) // ���� ã�� ���� ����?
		{
			return root; // ���� �����
		}
		else if (data < root->data) // �ƴϸ� ���� ã�� ���� �� �۾�?
		{
			// return �� ���� ���� �� ���� ���� ���̴�? ���� �ӵ��ƴұ�?
			return searchNode(root->leftChild, data);
		}
		else if (data > root->data) // �ƴϸ� ũ��?
		{
			return searchNode(root->rightChild, data);
		}
	}

	void preorder(NODE * root)
	{
		if (root == NULL)
		{
			return;
		}
		printf("%d ", root->data);	// ��Ʈ
		preorder(root->leftChild);	// ���� ����Ʈ��
		preorder(root->rightChild); // ������ ����Ʈ��
	}


	void inorder(NODE * root)
	{
		if (root == NULL)
		{
			return;
		}

		inorder(root->leftChild);	// ����
		printf("%d ", root->data);	// ��Ʈ
		inorder(root->rightChild);	// ������
	}


	void postorder(NODE * root)
	{
		if (root == NULL)
		{
			return;
		}

		// �̸� ����� ���
		postorder(root->leftChild);		// ����
		postorder(root->rightChild);	// ������
		printf("%d ", root->data);		// ��Ʈ
	}



	NODE* findMinNode(NODE * root)
	{
		while (root->leftChild != NULL)
		{
			root = root->leftChild;
		}
		return root;
	}

	NODE* rightFindMinNode(NODE * root)
	{
		NODE* temp = NULL;
		while (root->rightChild != NULL)
		{
			temp = root;
			root = root->rightChild;
		}
		return root;
	}


	NODE* deleteNode_practice(NODE * root, int value)
	{
		// ��� �����ϸ� ������?
		// to-do-list
		// 1. �����ϰ� ���� ��� ���� ã��
		// 
		// 
		// 
		// 
		// 2.�����ϰ� ���� ����� ����
		// 1) ����Ʈ���� �ϳ��� ���� ��� (�ڽ�)
		// 1-1) �����ϰ� ���� ��尡 �θ������ ���ʰ� ������ �߿� ���
		// 1-2) �θ��尡 ���� ��? -> �׷� ù��° ���ϱ� �׳� ����
		// 
		// 
		// 2) ����Ʈ���� 1���� ��� (�ڽ�)
		// 2-1) ������ ���� Ʈ���� ������ �ּ� ��
		// ( ������ ���� �� ����, ������ ������ �װ� �ּҰ����״ϱ� )
		// 
		// 2-2) �θ�
		// 2-2-1) �θ���� ����, ������
		// 
		// 
		// 3) ����Ʈ���� 2���� ��� (�ڽ�)
		// 3-1) ������ �ּ� �ƴϸ� ���� �ּ� �� ã��
		//
		// 3-2) �θ�
		// 3-2-1) �θ� ���� ����, ������
		// 



		// 1-1) �����ϰ� ���� ��尡 �θ������ ���ʰ� ������ �߿� ���
		NODE* parents = NULL;

		// 1. �����ϰ� ���� ��� ���� ã��
		NODE* remove = NULL;

		remove = root;
		if (remove == NULL)
		{
			printf("NULL���� �Էµ� -> �������� �ʴ� Ű \n");
			return root;
		}
		while (remove != NULL)
		{
			if (value == remove->data)
			{
				break; // ã������ �ݺ��� �׸� ���� �ּ� ��
			}

			// Ž��
			if (value < remove->data)
			{
				remove = remove->leftChild;
			}
			else
			{
				remove = remove->rightChild;
			}
		}

		// ���� ã������ parents ���
		parents = remove;

		// 2.�����ϰ� ���� ����� ����
		// 1) ����Ʈ���� �ϳ��� ���� ��� (�ڽ�)
		if (remove->leftChild == NULL &&
			remove->rightChild == NULL)
		{
			// 1-1) �����ϰ� ���� ��尡 �θ������ ���ʰ� ������ �߿� ���
			if (parents == NULL) // �θ��尡 ���� �� -> ù��° ����� ��
			{
				root = NULL; // ���ֹ���
			}
			else // �θ��尡 ���� �� �������� ����������
			{
				// ����
				if (parents->leftChild == remove)
				{
					// �θ��� �ڽ��� ��������� ..���� �� ������ ���̳� ����
					parents->leftChild = NULL;
				}
				else // ������
				{
					parents->rightChild = NULL;
				}
			}
		}
		// 2) ����Ʈ���� 1���� ��� (�ڽ�)
		else if (remove->leftChild == NULL || remove->rightChild == NULL)
		{
			// 2-1) ������ ���� Ʈ���� ������ �ּ� ��
			// ( ������ ���� �� ����, ������ ������ �װ� �ּҰ����״ϱ� )

		}



		return root;
	}



	NODE* deleteNode(NODE * root, int data) {
		NODE* node = NULL;
		if (root == NULL) return NULL;

		if (root->data > data)
			root->leftChild = deleteNode(root->leftChild, data);
		else if (root->data < data)
			root->rightChild = deleteNode(root->rightChild, data);
		else {
			if (root->leftChild != NULL && root->rightChild != NULL) {
				node = findMinNode(root->rightChild);
				root->data = node->data;
				root->rightChild = deleteNode(root->rightChild, node->data);
			}
			else {
				node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;
				free(root);
				return node;
			}
		}
		return root;
	}


	void freeAll(NODE * root)
	{
		// ��尡 ����
		if (root == NULL) return;

		// ���� ��� ����
		freeAll(root->leftChild);

		// ������ ��� ����
		freeAll(root->rightChild);

		// ��Ʈ ��� ����
		printf("���� �� ���� �ּ� : %d, %p\n", root->data, root);
		free(root);
	}



#pragma endregion


#pragma region �Լ�������
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	void print_hello();
	void recursive(int);

	int add(int a, int b);
	int sub(int a, int b);
	int mul(int a, int b);
	int division(int a, int b);


	int main()
	{
		recursive(1);


		// print_hello() �̷��� �ϸ� �Լ��� ȣ���ϴ� ���̰�
		// �̸��� ���� �ּҸ� �� �� �־�
		int* address = print_hello;
		printf("�Լ��� �ּ� : %p \n", print_hello);
		printf("address�� ����Ű�� �ּҴ�? : %p \n", address);


		// �Լ�������
		// void (*fp)();
		int (*fp[4])(int, int);
		// fp = print_hello;
		// printf("�Լ��� �ּ� : %p \n", print_hello);

		// fp = add;
		// printf("%d \n", fp(10, 20));
		// void (*fp)(); �� ���� �Ұ����߾���
		// fp ������ ������ int (*fp)(int, int); �̷��� �ٲ�� ����

		fp[0] = add;
		fp[1] = sub;
		fp[2] = mul;
		fp[3] = division;

		/*for (int i = 0; i < 4; i++)
		{
			printf("�迭[%d] �Լ��� ���� �� : %d \n", i, fp[i](10,20));
		}*/

		int select = -1; // 0�� ���ϱ�ϱ� 0���� �ʱ�ȭ������ ����
		int v1 = 0, v2 = 0, chk = 0;
		char cal = NULL;

		// printf("%d \n", select);


		if (select == 0) cal = '+';
		else if (select == 1) cal = '-';
		else if (select == 2) cal = '*';
		else if (select == 3) cal = '/';

		while (select != 9)
		{
			printf("��� ������ �����ϼ���. \n");
			printf("0. ���ϱ�, 1.����, 2.���ϱ�, 3. ������, 9. ������ \n");
			chk = scanf("%d", &select);
			if (select == 9) return 0;
			printf("���� �� ���� �Է��ϼ���. : \n ");
			chk = scanf("%d %d", &v1, &v2);
			// printf("%d %d \n", v1, v2);
			fp[select](v1, v2);

			puts(" ");
			puts("�����");
			printf("%d %c %d = %d  �Դϴ� ! \n", v1, cal, v2, fp[select](v1, v2));
		}









		return 0;
	}

	void print_hello()
	{
		printf("Hello, World! \n");
	}

	void recursive(int value)
	{
		if (value > 5) return;

		printf("%d, %p, %p \n", value, &value, recursive);
		recursive(++value);
	}


	int add(int a, int b)
	{
		return a + b;
	}

	int sub(int a, int b)
	{
		return a - b;
	}

	int mul(int a, int b)
	{
		return a * b;
	}

	int division(int a, int b)
	{
		return a / b;
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


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion



	return 0;
}


