#pragma once


typedef struct _tabArr
{
	int* pInt;
	int iCount;
	int iMaxCount;
}tArr;


// ���� ���Ǵ� �� �Լ��� �������°� ����
// ������ ������� �Լ��� �������� �ʴ´�. -> �ߺ��� �Ǵϱ�
// �׷��� ���� ������ Arr.cpp �� �����س��� ����
// ����Ű Ctrl		+		'+',		 '.' -> �������� ����
void InitArr(tArr* _pArr);