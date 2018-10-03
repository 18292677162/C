#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

int add(int a, int b)
{
	do {
		int t = a ^ b;
		b = (a & b) << 1;
		a = t;
	} while (b != 0);
	return a;
}

int vag(int a, int b)
{
	return add(((a^b) >> 1), (a & b));
}

int main()
{
	int a = 3;
	int b = 5;
	printf("%d\n", vag(a, b));
	system("pause");
	return 0;
}