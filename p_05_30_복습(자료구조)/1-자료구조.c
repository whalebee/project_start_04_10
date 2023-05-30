// start
#include "header.h"

#define STACK_SIZE 10
#define EMPTY -1

int stack[STACK_SIZE];
int top = EMPTY;

// FULL�� EMPTY ���� �Լ����� ������.
int stack_full();
int stack_empty();
void stack_push(int);

// Ȯ���� ���� list ���� �Լ��� ������.
void show_stack_list();

// �����ϴ� extinguish
int stack_extinguish();
// �� ���� �׸� Ȯ�� -> peek
int stack_peek();

int main()
{
	stack_push(1);
	stack_push(2);
	stack_push(3);
	stack_push(4);
	stack_push(5);

	// show_stack_list();
	// ������� Ȯ��
	puts(" ");
	printf("peek�� ���� : %d \n", stack_peek());

	printf("���� �������� ! : %d \n", stack_extinguish());

	show_stack_list();

	printf("peek�� ���� : %d \n", stack_peek());

	return 0;
}

// �Ű����� ��������� !
void stack_push(int data)
{
	// FULL�� �ƴ� �� ���� �־��ٰž�
	// FULL �� �� -> return 1 ����
	// �ƴϸ� return 0 �� ������ ������
	// ! ���� �� �־������
	if (!stack_full())
	{
		stack[++top] = data;
	}
}

int stack_full()
{
	// top�� STACK_SIZE - 1 ���� ũ�ٸ� !
	if (top > STACK_SIZE - 1)
	{
		printf("Stack is full !! \n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int stack_empty()
{
	// top�� EMPTY�� ���ٸ� ! -> ����ִ� ��
	if (top == EMPTY)
	{
		printf("Stack is empty !! \n");
		return 1;
	}
	else
	{
		return 0;
	}
}

void show_stack_list()
{
	// ������ �׸��� �״� ����� ����ϴϱ�
	// �Ųٷ� �ұ�? ��� ���� ������ �� ����
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", stack[i]);
	}
}


int stack_extinguish()
{
	// ������� ���� �� ����
	// ������� �� 1�� �����ϱ� ��
	if (!stack_empty())
	{
		return stack[top--];
	}
	else
	{
		return -1; // ��������� �� -1 �ִ°���
	}
}

int stack_peek()
{
	// ������� ���� �� ���� �����ϴϱ�
	if (!stack_empty())
	{
		return stack[top];
	}
	else
	{
		return -1;
	}
}