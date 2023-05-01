#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
#pragma region Stack
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 10 // 10개의 정수형 요소를 가지는 stack배열 변수 선언.
#define EMPTY -1

	int stack[STACK_SIZE];
	int top = EMPTY;

	int is_full();
	void push(int);
	int pop();
	int is_empty();
	int peek();
	void show_list();


	int main()
	{
		push(1);
		push(2);
		push(3);
		push(4);
		push(5);



		printf("pop : %d \n", pop());
		printf("pop : %d \n", pop());
		printf("peek : %d \n", peek());


		show_list();

		return 0;
	}


	// 스택이 포화 상태인지 확인하여 결과를 반환(return)하는 함수
	// full			:	1	>>	true
	// not full		:	0	>>	false
	int is_full()
	{
		if (top > STACK_SIZE - 1)
		{
			// 9 이상은 스팩은 full 상태 ( top은 stack을 구현한 배열의 index이므로)
			printf("Error :Stack is Full !\n");
			return 1;
		}
		return 0;
	}// 추천 꽉 찬 상태 확인 -> 결과 반환




	void push(int data)
	{
		if (!is_full())
		{
			stack[++top] = data;
		}
	}

	int is_empty()
	{
		if (top == EMPTY)
		{
			// 스택을 구현한 배열의 index가 -1이면 비어있는 상태
			printf("Error : Stack is empty ! \n");
			return 1; // 비어있어
		}
		return 0; // 비어있지 않아.
	}

	int pop()
	{
		if (!is_empty())
		{
			// stack이 비어있지 않을 때 -> 데이터가 있을 때
			return stack[top--];
		}
		return -1;
	}


	int peek()
	{
		if (!is_empty())
		{
			// stack이 비어있지 않을 때 -> 데이터가 있을 때
			return stack[top];
		}
		return -1;
	}


	void show_list()
	{
		for (int i = 0; i <= top; i++)
		{
			printf("%d ", stack[i]);
			printf(" ");
		}
	}


#pragma endregion


#pragma region QUEUE
	//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

	typedef struct queue {
		int front;
		int rear;
		int data[QUEUE_SIZE];
	}QUEUE;

	void init_queue(QUEUE*);	// 큐 초기화
	int is_empty(QUEUE);		// 큐 비어있는지 검사 front == rear 면 비어있음, 비어있으면 1, 아니면 0
	int is_full(QUEUE);			// 큐 포화상태 검사 front와 rear가 이웃, rear가 front 앞에 있으면 꽉 참
	void enqueue(QUEUE*, int);	//값을 바꿀거라서 포인터로
	int dequeue(QUEUE*);
	void show_que(QUEUE);

	int main()
	{
		QUEUE my_que;

		init_queue(&my_que);

		enqueue(&my_que, 10);
		enqueue(&my_que, 20);
		enqueue(&my_que, 30);
		enqueue(&my_que, 40);

		// show_que(my_que); //확인

		printf("dequeue : %d \n", dequeue(&my_que));
		// FIFO으로 10이 사라져야해

		enqueue(&my_que, 50);

		// 결과
		show_que(my_que);

		return 0;
	}

	// 포인터로 받을 필요가 없어
	// 값을 바꿔주는게 아니라 그냥 확인만 하는거니까
	int is_empty(QUEUE que)
	{
		if (que.front == que.rear)
		{
			printf("비어있음 \n");
			return 1;
		}
		else
		{
			return 0;
		}
	}


	int is_full(QUEUE que)
	{
		if ((que.rear + 1) % QUEUE_SIZE == que.front)
		{
			// printf("포화상태 !! \n");
			return 1;
		}
		else
		{
			// printf("꽉 차 있지는 않네 \n");
			return 0;
		}

	}

	void init_queue(QUEUE* p_que)
	{
		p_que->front = 0;
		p_que->rear = 0;
	}

	void enqueue(QUEUE* p_que, int value)
	{
		// 꽉 차 있는지 확인
		// 비어있지 않으면 !
		if (!is_full(*p_que))
		{
			// 이렇게 안 하면 구하고자하는 인덱스의 자리가 이상해짐
			p_que->rear = (p_que->rear + 1) % QUEUE_SIZE;
			p_que->data[p_que->rear] = value;
		}
	}


	int dequeue(QUEUE* p_que)
	{
		int value = 0;
		if (!is_empty(*p_que))
		{
			p_que->front = (p_que->front + 1) % QUEUE_SIZE;
			value = p_que->data[p_que->front];
		}
		return value;
	}


	// 원형 큐에 들어가있는 전체 데이터 출력 front 부터 rear 까지
	void show_que(QUEUE my_que)
	{

		if (is_empty != 1) // is_empty가 비어있으면 return 1 줌
		{
			printf("--------------- \n");

			printf("큐 전체 출력 \n");

			// front+1 해줘야하는 건 front는 비어있으니까
			// 조건은 rear가 마지막인데 그 다음까지 봐야하니까 +1 해주고
			// 증감식은 QUEUE_SIZE로 모듈러스하지 않으면 인덱스 초과해서 값이 엉망이됨
			// 모듈러스로 처음 원형자리로 가야해
		

			/* for문 -> dequeue 하면 출력 결과 이상해짐
			for (int i = my_que.front + 1; i != my_que.front; i = (i + 1) % QUEUE_SIZE)
			{
				printf("%d ", my_que.data[i]);
			}
			*/

			// for문 수정버전
			for (int i = my_que.front + 1; i != my_que.rear + 1; i = (i + 1) % QUEUE_SIZE)
			{
				printf("%d ", my_que.data[i]);
			}


			/* while문
			while (my_que.front != my_que.rear)
				{
					my_que.front = (my_que.front + 1) % QUEUE_SIZE;
					printf("%d ", my_que.data[my_que.front]);
				}
			*/
		}
		else
		{
			printf("값이 비어있음 \n");
		}
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


