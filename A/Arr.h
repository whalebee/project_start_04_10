#pragma once


typedef struct _tabArr
{
	int* pInt;
	int iCount;
	int iMaxCount;
}tArr;


// 자주 사용되는 건 함수로 만들어놓는게 좋다
// 하지만 헤더에는 함수를 구현하지 않는다. -> 중복이 되니까
// 그래서 실제 구현은 Arr.cpp 에 구현해놓을 예정
// 단축키 Ctrl		+		'+',		 '.' -> 원격으로 정의
void InitArr(tArr* _pArr);