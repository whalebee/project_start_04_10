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
        printf("1. 성적 입력\n");
        printf("2. 성적 확인\n");
        printf("3. 종료\n");
        printf("-------------\n");
        printf("선택 ( 1 ~ 3 ) : ");
        scanf("%d", &num);
        getchar();

        if (num == 1)
        {
            if (writing_info(&head) == 1)
            {
                printf("입력이 완료되었습니다.\n");
            }
            else
            {
                printf("최대 인원 초과 !\n");
                printf("최대 인원은 현재 %d명으로 설정되어 있습니다.\n", MAX_INFO);
            }
        }
        else if (num == 2)
        {
            show_info(head);
        }
        else if (num == 3)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else
        {
            printf("잘못된 입력입니다. 번호를 다시 입력해주세요.\n");
        }
    }

    // 메모리 해제
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
    printf("1번 메뉴 선택 시 입력\n");
    printf("######################\n");

    if (*p_head == NULL)
    {
        *p_head = (MYCLASS*)malloc(sizeof(MYCLASS));
        if (*p_head == NULL)
        {
            printf("메모리 할당 오류!\n");
            return 0;
        }

        printf("1번째 학생의 이름: ");
        scanf("%s", (*p_head)->name);
        getchar();

        printf("국어 점수: ");
        scanf("%u", &(*p_head)->korean_score);

        printf("영어 점수: ");
        scanf("%u", &(*p_head)->english_score);

        printf("수학 점수: ");
        scanf("%u", &(*p_head)->math_score);

        (*p_head)->next = NULL;
    }
    else
    {
        MYCLASS* temp = (MYCLASS*)malloc(sizeof(MYCLASS));
        if (temp->next == NULL)
        {
            printf("메모리 할당 오류!\n");
            return 0;
        }

        MYCLASS* current = *p_head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = temp;
        

        printf("%d번째 학생의 이름: ", current->korean_score + current->english_score + current->math_score);
        scanf("%s", current->next->name);
        getchar();

        printf("국어 점수: ");
        scanf("%u", &current->next->korean_score);

        printf("영어 점수: ");
        scanf("%u", &current->next->english_score);

        printf("수학 점수: ");
        scanf("%u", &current->next->math_score);

        current->next->next = NULL;
    }

    return 1;
}

void show_info(MYCLASS* head)
{
    printf("######################\n");
    printf("2번 메뉴 선택 시 출력\n");
    printf("######################\n\n");

    if (head == NULL)
    {
        printf("등록된 학생 정보가 없습니다.\n");
        return;
    }

    printf("---------------------------------------------------------------\n");
    printf("이름\t\t국어\t영어\t수학\t총점\t평균\t등수\n");
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
