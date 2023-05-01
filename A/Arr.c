#include "Arr.h"
#include <stdlib.h>

// 실제 구현 파트

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2 ); // 의도가 명확하게 int형 2개를 쓰겠어 라는 것
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;

	// _pArr->pInt = (int*)malloc(40); 일 때
	// _pArr->iMaxCount = 10;		// 40이 아니라 10이지 int형으로 40바이트가 최대 크기잖아
}
