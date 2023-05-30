// start
#include "header.h"

#define STACK_SIZE 10
#define EMPTY -1

int stack[STACK_SIZE];
int top = EMPTY;

// FULL과 EMPTY 상태 함수부터 만들자.
int stack_full();
int stack_empty();
void stack_push(int);

// 확인을 위해 list 보는 함수를 만들자.
void show_stack_list();

// 제거하는 extinguish
int stack_extinguish();
// 맨 위에 그릇 확인 -> peek
int stack_peek();

int main()
{
	stack_push(1);
	stack_push(2);
	stack_push(3);
	stack_push(4);
	stack_push(5);

	// show_stack_list();
	// 여기까지 확인
	puts(" ");
	printf("peek의 값은 : %d \n", stack_peek());

	printf("값을 제거하자 ! : %d \n", stack_extinguish());

	show_stack_list();

	printf("peek의 값은 : %d \n", stack_peek());

	return 0;
}

// 매개변수 정해줘야지 !
void stack_push(int data)
{
	// FULL이 아닐 때 값을 넣어줄거야
	// FULL 일 때 -> return 1 나옴
	// 아니면 return 0 이 나오기 때문에
	// ! 으로 역 넣어줘야해
	if (!stack_full())
	{
		stack[++top] = data;
	}
}

int stack_full()
{
	// top이 STACK_SIZE - 1 보다 크다면 !
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
	// top이 EMPTY와 같다면 ! -> 비어있는 것
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
	// 스택은 그릇을 쌓는 개념과 비슷하니까
	// 거꾸로 할까? 어떻게 할지 생각이 안 나네
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", stack[i]);
	}
}


int stack_extinguish()
{
	// 비어있지 않을 때 제거
	// 비어있을 때 1이 나오니까 역
	if (!stack_empty())
	{
		return stack[top--];
	}
	else
	{
		return -1; // 비어있으면 걍 -1 주는거지
	}
}

int stack_peek()
{
	// 비어있지 않을 때 값을 봐야하니까
	if (!stack_empty())
	{
		return stack[top];
	}
	else
	{
		return -1;
	}
}