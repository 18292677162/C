#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

unsigned int ReverseBit(unsigned int value)
{
	//00000000000000000000000000011001 
	//10011000000000000000000000000000
	int len = 8 * sizeof(value);
	int tmp = 0;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		tmp |= (value & 0x01) << (len - i - 1);
		value >>= 1;
	}
	return tmp;
}

int main()
{
	int a = 25;
	ReverseBit(a);
	printf("%u", ReverseBit(a));
	system("pause");
	return 0;
}