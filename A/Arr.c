#include "Arr.h"
#include <stdlib.h>

// ���� ���� ��Ʈ

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int) * 2 ); // �ǵ��� ��Ȯ�ϰ� int�� 2���� ���ھ� ��� ��
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;

	// _pArr->pInt = (int*)malloc(40); �� ��
	// _pArr->iMaxCount = 10;		// 40�� �ƴ϶� 10���� int������ 40����Ʈ�� �ִ� ũ���ݾ�
}
