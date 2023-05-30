#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
#pragma region 자료구조 - 트리
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 이진 탐색트리
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

	NODE* findMinNode(NODE * root); // 최소
	NODE* rightFindMinNode(NODE * root); // 오른쪽 서브트리 최소

	NODE* deleteNode_practice(NODE * root, int value);
	NODE* deleteNode(NODE * root, int data);

	void freeAll(NODE * root);

	// 전위순회 preorder 루트 -> 왼쪽 -> 오른쪽
	// 중위순회 inorder 왼쪽 -> 루트 -> 오른쪽
	// 후위순회 postorder 왼쪽 -> 오른쪽 -> 루트

	int main()
	{
		NODE* root = NULL;

		root = insertNode(root, 30);
		//printf("처음 결과 %p\n", root);
		root = insertNode(root, 17);
		root = insertNode(root, 48);

		root = insertNode(root, 5);
		root = insertNode(root, 23);
		root = insertNode(root, 37);
		root = insertNode(root, 50);

		/*
		중복확인
		root = insertNode(root, 40);
		root = insertNode(root, 40);
		*/

		/*
		NODE자료형 포인트 변수 root를 NULL로 초기화하여 선언

		첫번째 실행
		NULL값으로 초기화 되어있는 root에 insertnode 함수를 사용

		insertnode에 들어갈 때
		매개변수는 root : NULL 와 30
		if문 조건인 root == NULL에 적합하여 걸리게 됨
		root에 malloc으로 할당한 메모리의 첫번째 주소값을 대입
		root->data에 매개변수 data값을 대입
		malloc의 주소를 받은 root를 리턴


		두번째 실행
		insertnode에 들어갈 때
		매개변수 root : 전에 받은 malloc의 주소, 48
		if문 조건인 root == NULL에 걸리지 않아서 else문으로 진입
		data == root->data에 걸리지 않음


		*/





		puts(" ");
		printf("preorder ");	// 루트 -> 왼쪽 -> 오른쪽
		preorder(root);			// 

		puts(" ");
		root = deleteNode(root, 17);
		printf("삭제 후 값 : ");
		preorder(root);


		puts(" ");
		puts(" ");
		printf("inorder ");	// 왼쪽 -> 루트 -> 오른쪽
		inorder(root);			// 




		puts(" ");
		puts(" ");
		printf("postorder ");	// 왼쪽 -> 오른쪽 -> 루트
		postorder(root);		// 15 25 20 40 48 30








		puts(" ");
		NODE* find = NULL;
		find = searchNode(root, 40);
		printf("%p \n", find);


		NODE* minNode = findMinNode(root);
		printf("최소 : %d \n", minNode->data);


		NODE* rightminNode = rightFindMinNode(root);
		printf("최소 : %d \n", rightminNode->data);




		freeAll(root);
		// 노드를 삭제했다면 주소값이 다를 수 있다 !
		return 0;
	}


	NODE* insertNode(NODE * root, int data)
	{
		// 48을 입력했을 때
		// NULL과 48을 가지고 오게 됨


		// 트리노드 만들기 위함
		if (root == NULL)
		{
			while (root == NULL)
			{
				root = (NODE*)malloc(sizeof(NODE));
				printf("말록 %p\n", root);
			}

			root->data = data;
			printf("%d \n", data);
			root->leftChild = NULL;
			root->rightChild = NULL;
			return root;
		}
		// 여기서부터 재귀함수 영역
		else
		{
			if (data == root->data)
			{
				printf("입력된 값이 중복이 될 것 같소이다. \n");
				return root;
			}

			// root의 data가 입력된 data보다 작으면 왼쪽에 추가
			if (data < root->data)
			{
				// 재귀함수
				root->leftChild = insertNode(root->leftChild, data);
				// 재귀함수가 끝나면 다시 여기로 오게됨
			}
			else
			{
				// 오른쪽에 추가
				root->rightChild = insertNode(root->rightChild, data);
			}
		}


		return root;
	}


	NODE* searchNode(NODE * root, int data)
	{
		if (root == NULL) return NULL; // 노드가 없거나 내가 찾는 값이 없어

		if (root->data == data) // 내가 찾는 값과 같아?
		{
			return root; // ㅇㅇ 여기야
		}
		else if (data < root->data) // 아니면 내가 찾는 값이 더 작아?
		{
			// return 을 써줄 때와 안 써줄 때의 차이는? 연산 속도아닐까?
			return searchNode(root->leftChild, data);
		}
		else if (data > root->data) // 아니면 크나?
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
		printf("%d ", root->data);	// 루트
		preorder(root->leftChild);	// 왼쪽 서브트리
		preorder(root->rightChild); // 오른쪽 서브트리
	}


	void inorder(NODE * root)
	{
		if (root == NULL)
		{
			return;
		}

		inorder(root->leftChild);	// 왼쪽
		printf("%d ", root->data);	// 루트
		inorder(root->rightChild);	// 오른쪽
	}


	void postorder(NODE * root)
	{
		if (root == NULL)
		{
			return;
		}

		// 이름 제대로 써라
		postorder(root->leftChild);		// 왼쪽
		postorder(root->rightChild);	// 오른쪽
		printf("%d ", root->data);		// 루트
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
		// 어떻게 삭제하면 좋을까?
		// to-do-list
		// 1. 삭제하고 싶은 노드 기준 찾기
		// 
		// 
		// 
		// 
		// 2.삭제하고 싶은 노드의 유형
		// 1) 서브트리가 하나도 없는 노드 (자식)
		// 1-1) 삭제하고 싶은 노드가 부모노드기준 왼쪽과 오른쪽 중에 어디
		// 1-2) 부모노드가 없을 때? -> 그럼 첫번째 노드니까 그냥 삭제
		// 
		// 
		// 2) 서브트리가 1개인 노드 (자식)
		// 2-1) 오른쪽 서브 트리가 있으면 최소 값
		// ( 왼쪽은 있을 수 없음, 왼쪽이 있으면 그게 최소값일테니까 )
		// 
		// 2-2) 부모
		// 2-2-1) 부모기준 왼쪽, 오른쪽
		// 
		// 
		// 3) 서브트리가 2개인 노드 (자식)
		// 3-1) 오른쪽 최소 아니면 왼쪽 최소 값 찾기
		//
		// 3-2) 부모
		// 3-2-1) 부모 기준 왼쪽, 오른쪽
		// 



		// 1-1) 삭제하고 싶은 노드가 부모노드기준 왼쪽과 오른쪽 중에 어디
		NODE* parents = NULL;

		// 1. 삭제하고 싶은 노드 기준 찾기
		NODE* remove = NULL;

		remove = root;
		if (remove == NULL)
		{
			printf("NULL값이 입력됨 -> 존재하지 않는 키 \n");
			return root;
		}
		while (remove != NULL)
		{
			if (value == remove->data)
			{
				break; // 찾았으면 반복문 그만 돌고 주소 줘
			}

			// 탐색
			if (value < remove->data)
			{
				remove = remove->leftChild;
			}
			else
			{
				remove = remove->rightChild;
			}
		}

		// 기준 찾기위해 parents 사용
		parents = remove;

		// 2.삭제하고 싶은 노드의 유형
		// 1) 서브트리가 하나도 없는 노드 (자식)
		if (remove->leftChild == NULL &&
			remove->rightChild == NULL)
		{
			// 1-1) 삭제하고 싶은 노드가 부모노드기준 왼쪽과 오른쪽 중에 어디
			if (parents == NULL) // 부모노드가 없을 때 -> 첫번째 노드일 때
			{
				root = NULL; // 없애버려
			}
			else // 부모노드가 있을 때 왼쪽인지 오른쪽인지
			{
				// 왼쪽
				if (parents->leftChild == remove)
				{
					// 부모의 자식을 없애줘야지 ..뭔가 좀 잔인한 말이네 ㅋㅋ
					parents->leftChild = NULL;
				}
				else // 오른쪽
				{
					parents->rightChild = NULL;
				}
			}
		}
		// 2) 서브트리가 1개인 노드 (자식)
		else if (remove->leftChild == NULL || remove->rightChild == NULL)
		{
			// 2-1) 오른쪽 서브 트리가 있으면 최소 값
			// ( 왼쪽은 있을 수 없음, 왼쪽이 있으면 그게 최소값일테니까 )

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
		// 노드가 없소
		if (root == NULL) return;

		// 왼쪽 노드 해제
		freeAll(root->leftChild);

		// 오른쪽 노드 해제
		freeAll(root->rightChild);

		// 루트 노드 해제
		printf("해제 된 값과 주소 : %d, %p\n", root->data, root);
		free(root);
	}



#pragma endregion


#pragma region 함수포인터
	//시작
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


		// print_hello() 이렇게 하면 함수를 호출하는 것이고
		// 이름만 쓰면 주소를 볼 수 있어
		int* address = print_hello;
		printf("함수의 주소 : %p \n", print_hello);
		printf("address가 가리키는 주소는? : %p \n", address);


		// 함수포인터
		// void (*fp)();
		int (*fp[4])(int, int);
		// fp = print_hello;
		// printf("함수의 주소 : %p \n", print_hello);

		// fp = add;
		// printf("%d \n", fp(10, 20));
		// void (*fp)(); 일 때는 불가능했었음
		// fp 포인터 변수를 int (*fp)(int, int); 이렇게 바꿔야 가능

		fp[0] = add;
		fp[1] = sub;
		fp[2] = mul;
		fp[3] = division;

		/*for (int i = 0; i < 4; i++)
		{
			printf("배열[%d] 함수의 실행 값 : %d \n", i, fp[i](10,20));
		}*/

		int select = -1; // 0은 더하기니까 0으로 초기화하지마 ㅋㅋ
		int v1 = 0, v2 = 0, chk = 0;
		char cal = NULL;

		// printf("%d \n", select);


		if (select == 0) cal = '+';
		else if (select == 1) cal = '-';
		else if (select == 2) cal = '*';
		else if (select == 3) cal = '/';

		while (select != 9)
		{
			printf("계산 종류를 선택하세요. \n");
			printf("0. 더하기, 1.빼기, 2.곱하기, 3. 나누기, 9. 끝내기 \n");
			chk = scanf("%d", &select);
			if (select == 9) return 0;
			printf("정수 두 개를 입력하세요. : \n ");
			chk = scanf("%d %d", &v1, &v2);
			// printf("%d %d \n", v1, v2);
			fp[select](v1, v2);

			puts(" ");
			puts("계산결과");
			printf("%d %c %d = %d  입니다 ! \n", v1, cal, v2, fp[select](v1, v2));
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


