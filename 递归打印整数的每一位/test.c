#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

int print(n)
{
	if (n >= 10)
	{
		print(n / 10);
	}
	printf("%d", n % 10);
}
int main()
{
	print(1234);
	printf("\n");
	system("pause");
	return 0;
}