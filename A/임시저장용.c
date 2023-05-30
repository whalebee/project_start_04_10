#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct my_class
{
    char name[20];
    unsigned int korean_score;
    unsigned int english_score;
    unsigned int math_score;
    struct my_class* next;
} MYCLASS;

#define MAX_INFO 14

int writing_info(MYCLASS** p_head);
void show_info(MYCLASS* head);

int main()
{
    MYCLASS* head = NULL;
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
        getchar();

        if (num == 1)
        {
            if (writing_info(&head) == 1)
            {
                printf("�Է��� �Ϸ�Ǿ����ϴ�.\n");
            }
            else
            {
                printf("�ִ� �ο� �ʰ� !\n");
                printf("�ִ� �ο��� ���� %d������ �����Ǿ� �ֽ��ϴ�.\n", MAX_INFO);
            }
        }
        else if (num == 2)
        {
            show_info(head);
        }
        else if (num == 3)
        {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }
        else
        {
            printf("�߸��� �Է��Դϴ�. ��ȣ�� �ٽ� �Է����ּ���.\n");
        }
    }

    // �޸� ����
    while (head != NULL)
    {
        MYCLASS* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

int writing_info(MYCLASS** p_head)
{
 
    printf("######################\n");
    printf("1�� �޴� ���� �� �Է�\n");
    printf("######################\n");

    if (*p_head == NULL)
    {
        *p_head = (MYCLASS*)malloc(sizeof(MYCLASS));
        if (*p_head == NULL)
        {
            printf("�޸� �Ҵ� ����!\n");
            return 0;
        }

        printf("1��° �л��� �̸�: ");
        scanf("%s", (*p_head)->name);
        getchar();

        printf("���� ����: ");
        scanf("%u", &(*p_head)->korean_score);

        printf("���� ����: ");
        scanf("%u", &(*p_head)->english_score);

        printf("���� ����: ");
        scanf("%u", &(*p_head)->math_score);

        (*p_head)->next = NULL;
    }
    else
    {
        MYCLASS* temp = (MYCLASS*)malloc(sizeof(MYCLASS));
        if (temp->next == NULL)
        {
            printf("�޸� �Ҵ� ����!\n");
            return 0;
        }

        MYCLASS* current = *p_head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = temp;
        

        printf("%d��° �л��� �̸�: ", current->korean_score + current->english_score + current->math_score);
        scanf("%s", current->next->name);
        getchar();

        printf("���� ����: ");
        scanf("%u", &current->next->korean_score);

        printf("���� ����: ");
        scanf("%u", &current->next->english_score);

        printf("���� ����: ");
        scanf("%u", &current->next->math_score);

        current->next->next = NULL;
    }

    return 1;
}

void show_info(MYCLASS* head)
{
    printf("######################\n");
    printf("2�� �޴� ���� �� ���\n");
    printf("######################\n\n");

    if (head == NULL)
    {
        printf("��ϵ� �л� ������ �����ϴ�.\n");
        return;
    }

    printf("---------------------------------------------------------------\n");
    printf("�̸�\t\t����\t����\t����\t����\t���\t���\n");
    printf("---------------------------------------------------------------\n");

    MYCLASS* current = head;
    int rank = 1;
    while (current != NULL)
    {
        unsigned int sum = current->korean_score + current->english_score + current->math_score;
        float average = (float)sum / 3.0f;

        printf("%s\t\t%u\t%u\t%u\t%u\t%.2f\t%d\n", current->name, current->korean_score, current->english_score,
            current->math_score, sum, average, rank);

        current = current->next;
        rank++;
    }
}
