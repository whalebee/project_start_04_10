#include <stdio.h>


int main()
{

	// 12일에 풀던 if문으로 다음 날 출력해주는 것
	// 답
	int year = 0, month = 0, day = 0, chk = 0, max_day = 0;

	// 날짜 입력 받기
	printf("날짜를 입력하세용. (yyyy mm dd)");
	chk = scanf("%d %d %d", &year, &month, &day);

	// 반드시 필요 !
	// 입력(유효성) 체크(년도, 월, 입력값) -> 원하는 데이터가 맞는지, 범위가 맞는지
	// 아예 따로 함수로 빼거나 소스를 따로 빼두는 경우도 있어
	if (chk != 3 || month > 12 || month < 1 || year < 1)
	{
		printf("유효성이 잘못되었소.");
		return 1;
	}

	// 입력한 월의 해당하는 MAX_day를 대입
	if (month == 2)
	{
		max_day = 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		max_day = 30;
	}
	else
	{
		max_day = 31;
	}

	// 입력(유효성) 체크(일)
	if (day > max_day)
	{
		printf("그런 날짜 없다아아아\n");
		return 1;
	}

	// 일(+하루) 증가 처리
	day++;
	if (day > max_day)
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}

	//출력
	printf("입력하신 날짜의 다음 날은 %d년 %d월 %일 입니당 \n", year, month, day);
}