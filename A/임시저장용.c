
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



		// �׺�
		
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

