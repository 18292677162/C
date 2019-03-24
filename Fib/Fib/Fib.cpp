#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>

int Fib(int n)
{
	if (n < 3){
		return 1;
	}
	return Fib(n - 1) + Fib(n - 2);
}

int main()
{
	printf("%d ",Fib(20));
	system("pause");
	return 0;
}