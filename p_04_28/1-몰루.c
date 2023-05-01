#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
#pragma region ��Ʈ ������ �⺻ ����
	//��Ʈ������ �⺻����
	int a = 0x12345678;

	printf("%p \n", &a);

	a = a << 1;
	a = a << 1;
	a = a << 2;

	printf("%x \n", a);
	/*
	printf("%d \n", a << 1);
	printf("%d \n", a << 2);
	printf("%d \n", (a << 2) + 10); // ��Ʈ ���� �� Ȧ�� ������ ¦���� ������ ���� +�� �� �� �� ���ָ� ��

										12345678
	4�� << ���ٴ� ����				   2345678 0
								���: 23 45 67 80 �� ��
	*/



	int b = 10;
	printf("%d \n", a >> 1);
	printf("%d \n", a >> 2);


#pragma endregion


#pragma region ��Ʈ ������ AND, OR ( ���� ���� )
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	typedef unsigned char u_char;
	u_char bit_to_0(u_char, u_char);
	u_char bit_to_1(u_char, u_char);

	u_char callTheRoll(u_char);

	u_char getTobit(u_char);

	u_char re_getTobit(u_char);

	int main()
	{
		// ��Ʈ�������� AND -> 0���� �ٲ��ְھ�
		u_char lamp_state = 0x7F;					// 0111 1111 : 0x7F
		printf("lamp_state : %x \n", lamp_state);

		lamp_state = bit_to_0(lamp_state, 3);		// ( 0���� �����ؼ� ) 3��° ��Ʈ�� �ٲٰڴ� !
		printf("AND ���� �� : %x \n", lamp_state);	// 0111 0111 : 0x77

		// ��Ʈ�������� OR -> 1�� �ٲ��ְھ�
		lamp_state = bit_to_1(lamp_state, 3);
		printf("OR ���� �� : %x \n", lamp_state);	// 0111 1111 : 0x7F


		// �̰� �� �غ� ����
		callTheRoll(lamp_state);


		// 10������ 2������ ��ȯ
		getTobit(10); // 00001010
		//puts(" ");
		getTobit(18); // 00010010
		//puts(" ");
		getTobit(127);


		return 0;
	}

	u_char bit_to_0(u_char dest_data, u_char bit_num)
	{
		if (bit_num < 8)
		{
			dest_data = dest_data & ~(0x01 << bit_num); // ���ϴ� ��Ʈ ������ ����Ʈ�ϰ� NOT���� ����
			// ��Ʈ ������ & �̰� AND, | �̰� OR
		}
		return dest_data;
	}

	u_char bit_to_1(u_char dest_data, u_char bit_num)
	{
		if (bit_num < 8)
		{
			dest_data = dest_data | (0x01 << bit_num);
		}
		return dest_data;
	}

	u_char callTheRoll(u_char dest_data)
	{
		u_char temp;
		for (int i = 0; i < 8; i++)
		{
			temp = dest_data & (0x01 << i);
			if (temp == 0)
			{
				printf("%d�� �л� �Ἦ.... \n", i + 1);
			}
			else
			{
				printf("%d�� �л� �⼮ ! \n", i + 1);
			}
		}
		puts(" ");
	}

	u_char getTobit(u_char dest_data)
	{
		for (int i = 7; i >= 0; i--)
		{
			//�Ųٷ� ���� -> 0���Ͱ� �ƴ϶� ��Ʈ �ִ� ũ��� - 1 ���� �ؾ��� ��
			u_char temp;
			temp = dest_data & (0x01 << i);
			if (temp == 0)
			{
				printf("0");
			}
			else
			{
				printf("1");
			}
		}
		puts(" ");
	}


	u_char re_getTobit(u_char data)
	{

	}



#pragma endregion


#pragma region ��Ʈ ������ XOR�� �̿��� ��ȣȭ
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


	int main()
	{
		char string[50];
		int key = 28;

		printf("���ڿ��� �Է��ϼ���. \n");
		scanf("%[^\n]s", string);
		getchar();

		int i = 0;
		while (string[i] != '\0')
		{
			string[i] = string[i] ^ key;
			i++;
		}
		printf("%s �� ��ȣȭ�� �Ǿ����ϴ� ! \n", string);


		i = 0;
		while (string[i] != '\0')
		{
			string[i] = string[i] ^ key;
			i++;
		}
		printf("%s �� ��ȣȭ �Ǿ����ϴ� ! \n", string);


		return 0;
	}




#pragma endregion


#pragma region ����Լ� ��� ����
#include <stdio.h>

	void re_getBit(int n);

	int main()
	{
		int num = 0, chk = 0;
		printf("������ �Է��ϼ��� ! \n");
		chk = scanf("%d", &num);
		if (chk == 0)
		{
			printf("�Է¿��� ! \n");
			return 1;
		}

		printf("�Է��� ������ 2���� ���� : ");
		re_getBit(num);
		return 0;
	}

	void re_getBit(int n)
	{
		// 10
		// 00001010
		// ����Լ� ���

		// �������� ���� �� if�� �־������ ��
		if (n / 2 != 0)
		{
			re_getBit(n / 2);
		}
		

		printf("%d ", n % 2);

	}





#pragma endregion


#pragma region ��Ʈ ������ ���� 1 ~ 2��
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	int revSign();

	int main()
	{
		// 1��
		revSign();

		// 2��
		puts(" ");
		int b = 3;
		printf("3*8/2 = %d \n", (b << 3) >> 1);

		return 0;
	}
	int revSign()
	{
		int num = 0, chk = 0;
		// 0000 1010
		// 2�� ���� 1111 0101
		// +1		1111 0110
		printf("������ �Է��ϼ��� : ");
		chk = scanf("%d", &num);
		if (chk == 0)
		{
			printf("�Է¿���");
			return 0;
		}
		printf("�Է��Ͻ� %d�� ��ȣ�� �ٲٸ� %d�Դϴ�. \n", num, (~num) + 1);
	}



#pragma endregion


#pragma region ��ó����
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ADD(a,b) a+b

	int add(int a, int b);

	int main()
	{
		printf("1. ADD(1,2) : %d \n", ADD(1, 2));
		printf("1. ADD(1,2) : %d \n", ADD(1, 2));

		printf("3. ADD(1,2)*2 : %d \n", ADD(1, 2) * 2); // a+b �� ġȯ�� �ϰ� �� a+b*2 �̷��� ����
		printf("4. add(1,2)*2 : %d \n", add(1, 2) * 2);

		return 0;
	}

	int add(int a, int b)
	{
		return a + b;
	}



#pragma endregion


#pragma region rand �Լ�
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define getrandom(min, max) ((rand()%(int)(((max)+1)-(min)))+(min))

	int main()
	{
		srand((unsigned int)time(NULL));

		for (int i = 0; i < 5; i++)
		{
			// �̷��� �ϸ� 45������ �ߺ��� ���� ����
			//printf("%d ", rand()%46);
			printf("%d ", getrandom(100, 150));
		}

		return 0;
	}




#pragma endregion


#pragma region ��ó���� Ȱ��
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #�ڿ� �� �� ���ڿ�ȭ �ϰڴ� ! ��� ��
#define stringer( x ) printf_s( #x "\n")
#define NAME_VALUE(target) printf("%s : %d \n", #target, target)

#define paster(n) printf_s("token" #n " = %d ", token##n)
	int token9 = 99;

#define XN(n) x ## n

	enum Days { MON, TUE, WED, THU, FRI, SAT, SUN };


	int main()
	{
		/* "" ���� �� ����� �� ( ȣ���� �ƴ϶� )
		stringer(In quotes in the printf function call);
		stringer("In quotes when printed to the screen");
		stringer("This:\" prints an escaped double quote");
		*/

		NAME_VALUE(MON);
		printf("%s : %d \n", "MON", MON);


		paster(9);
		// ## �� �����̶� token##9 -> token9�� �� ��

		puts(" ");
		int XN(1) = 10;
		int XN(2) = 20;
		// ������ ������ �� �ִ� ��ó���� Ȱ���
		printf("x1�� ���� �� ���� %d�Դϴ�. \n", x1);
		printf("x2�� ���� �� ���� %d�Դϴ�. \n", x2);

		return 0;
	}




#pragma endregion


#pragma region #undef�� #define
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define ADD(x,y) x+y

	int main()
	{
		int array[MAX];
#undef MAX //  MAX ����� !
		int array2[MAX];

		printf("%d", ADD(10, 20));
#undef ADD // ADD ��ó���� ����� !
		printf("%d", ADD(10, 20));

		return 0;
	}




#pragma endregion


#pragma region ��ó�� ������ ���� 6��
	//����
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a,b,c) ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c))

	int main()
	{
		printf("%d \n", MAX(15, 2, 5));
		printf("%d \n", MAX(15, 32, 5));
		printf("%d \n", MAX(15, 32, 58));

		return 0;
	}

	// 3��
	���� �ҽ��� �����ϸ� �ֿܼ� ��µǴ� ����� ? 5
	#define  CAL(x,y) (( x < y ) ? (x) : (y))
		void main() {
		printf("%d", CAL(10, 5));
	}

	// 4��
	Hello!world �� ��� �ǵ��� ��ũ�� �Լ��� �����ϼ���.
	#include <stdio.h>
	#define ��result(x,y) x,y
		void main() {}
	printf(�衱%s%s��, result("Hello!", "world"));




#pragma endregion


#pragma region



#pragma endregion




#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion


#pragma region



#pragma endregion



	return 0;
}


