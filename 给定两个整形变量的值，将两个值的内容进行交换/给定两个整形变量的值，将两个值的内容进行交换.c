#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a = 1;
	int b = 2;
	int c = 0;
	printf("before: a=%d  b=%d\n", a, b);
	c = a;
	a = b;
	b = c;
	printf("after: a=%d  b=%d\n", a, b);
	system("pause");
	return 0;
}

