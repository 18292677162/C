#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 14, b = 32, c = 25;
	int i = 0;
	printf("比较前：%d  %d  %d\n", a, b, c);
	i = a;
	if (i < b)
	{
		a = b;
		b = i;
		i = b;
	}
	if (b < c)
	{
		b = c;
		c = i;
		i = a;
	}
	if (a < b)
	{
		a = b;
		b = i;
	}
	printf("比较后：%d  %d  %d\n", a, b, c);
	system("pause");
	return 0;
}