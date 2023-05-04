#include <stdio.h>

union data {
	char c1;
	short num1;
	int num2;
};


void main() 
{
	union data d1;
	d1.num2 = 0x12345678;
	printf("%x", d1.num1);

	return 0;
}
