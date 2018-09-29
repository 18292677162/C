#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int swap(int a, int b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
	printf("a=%d b=%d\n", a, b);
	return 0;
}

int main()
{
	int a = 6;
	int b = 2;
	swap(a, b);
	system("pause");
	return 0;
}