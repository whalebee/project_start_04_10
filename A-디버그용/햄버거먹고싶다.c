int main()
{
	// 1번
	char season[10] = { '봄', '여름', '가을', '겨울' };

	// end 누르면 끝
	while (1)
	{
		printf("-------- 4계절 중 한 계절 선택 (종료는 end) : ");
		scanf("%s", season);

		if (strcmp(season, "봄") == 0)
		{
			printf("봄에는 벚꽃 \n");
		}
		else if (strcmp(season, "여름") == 0)
		{
			printf("여름에는 장미 \n");
		}
		else if (strcmp(season, "가을") == 0)
		{
			printf("가을에는 코스모스 \n");
		}
		else if (strcmp(season, "겨울") == 0)
		{
			printf("겨울에는 매화 \n");
		}
		else if (strcmp(season, "end") == 0)
		{
			printf("end입력으로 죵료 \n");
			break;
		}
		else
		{
			printf("??? 다시 입력 \n");
		}
	}



	return 0;
}