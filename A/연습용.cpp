//시작
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "Arr.h"


	// 가변 배열
	// 왜 배열에는 변수로 선언이 안 될까?
	/*
	만약 변수를 내가 입력을 받아버린다면?
	-> 크기를 확정할 수 없어서 배열에 쓸 수 없는 것
	main함수가 크기를 얼마나 할당시켜놔야할지 모르니까
	변수로 선언할 때 변수를 1억으로 scanf 받으면 어떻게 하게 ㅋㅋ
	( main 함수의 크기를 선언해둘 수가 없다는 뜻 ! ) -> 컴파일 단계에서 정보가 명확하지 않음 (확정 X)
	그래서 변수로 선언이 불가능한 것

	*/



int main()
{
	tArr s;
	

	InitArr(&s); // 주소를 넘겨줘야지, 변수만 넘겨주면 초기화가 되겠니

	return 0;
}

