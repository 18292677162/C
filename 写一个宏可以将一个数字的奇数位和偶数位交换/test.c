#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

#define SWAPOE(num) ((((num)&0X55555555)<<1) | (((num)&0XAAAAAAAA)>>1))

int main()
{
	printf("%d\n", SWAPOE(10));
	system("pause");
	return 0;
}