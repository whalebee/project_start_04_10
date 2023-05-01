#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
#pragma region Stack
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 10 // 10���� ������ ��Ҹ� ������ stack�迭 ���� ����.
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


	// ������ ��ȭ �������� Ȯ���Ͽ� ����� ��ȯ(return)�ϴ� �Լ�
	// full			:	1	>>	true
	// not full		:	0	>>	false
	int is_full()
	{
		if (top > STACK_SIZE - 1)
		{
			// 9 �̻��� ������ full ���� ( top�� stack�� ������ �迭�� index�̹Ƿ�)
			printf("Error :Stack is Full !\n");
			return 1;
		}
		return 0;
	}// ��õ �� �� ���� Ȯ�� -> ��� ��ȯ




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
			// ������ ������ �迭�� index�� -1�̸� ����ִ� ����
			printf("Error : Stack is empty ! \n");
			return 1; // ����־�
		}
		return 0; // ������� �ʾ�.
	}

	int pop()
	{
		if (!is_empty())
		{
			// stack�� ������� ���� �� -> �����Ͱ� ���� ��
			return stack[top--];
		}
		return -1;
	}


	int peek()
	{
		if (!is_empty())
		{
			// stack�� ������� ���� �� -> �����Ͱ� ���� ��
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
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

	typedef struct queue {
		int front;
		int rear;
		int data[QUEUE_SIZE];
	}QUEUE;

	void init_queue(QUEUE*);	// ť �ʱ�ȭ
	int is_empty(QUEUE);		// ť ����ִ��� �˻� front == rear �� �������, ��������� 1, �ƴϸ� 0
	int is_full(QUEUE);			// ť ��ȭ���� �˻� front�� rear�� �̿�, rear�� front �տ� ������ �� ��
	void enqueue(QUEUE*, int);	//���� �ٲܰŶ� �����ͷ�
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

		// show_que(my_que); //Ȯ��

		printf("dequeue : %d \n", dequeue(&my_que));
		// FIFO���� 10�� ���������

		enqueue(&my_que, 50);

		// ���
		show_que(my_que);

		return 0;
	}

	// �����ͷ� ���� �ʿ䰡 ����
	// ���� �ٲ��ִ°� �ƴ϶� �׳� Ȯ�θ� �ϴ°Ŵϱ�
	int is_empty(QUEUE que)
	{
		if (que.front == que.rear)
		{
			printf("������� \n");
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
			// printf("��ȭ���� !! \n");
			return 1;
		}
		else
		{
			// printf("�� �� ������ �ʳ� \n");
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
		// �� �� �ִ��� Ȯ��
		// ������� ������ !
		if (!is_full(*p_que))
		{
			// �̷��� �� �ϸ� ���ϰ����ϴ� �ε����� �ڸ��� �̻�����
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


	// ���� ť�� ���ִ� ��ü ������ ��� front ���� rear ����
	void show_que(QUEUE my_que)
	{

		if (is_empty != 1) // is_empty�� ��������� return 1 ��
		{
			printf("--------------- \n");

			printf("ť ��ü ��� \n");

			// front+1 ������ϴ� �� front�� ��������ϱ�
			// ������ rear�� �������ε� �� �������� �����ϴϱ� +1 ���ְ�
			// �������� QUEUE_SIZE�� ��ⷯ������ ������ �ε��� �ʰ��ؼ� ���� �����̵�
			// ��ⷯ���� ó�� �����ڸ��� ������
		

			/* for�� -> dequeue �ϸ� ��� ��� �̻�����
			for (int i = my_que.front + 1; i != my_que.front; i = (i + 1) % QUEUE_SIZE)
			{
				printf("%d ", my_que.data[i]);
			}
			*/

			// for�� ��������
			for (int i = my_que.front + 1; i != my_que.rear + 1; i = (i + 1) % QUEUE_SIZE)
			{
				printf("%d ", my_que.data[i]);
			}


			/* while��
			while (my_que.front != my_que.rear)
				{
					my_que.front = (my_que.front + 1) % QUEUE_SIZE;
					printf("%d ", my_que.data[my_que.front]);
				}
			*/
		}
		else
		{
			printf("���� ������� \n");
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


