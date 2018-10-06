#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
	printf("%d\n", MAX(3, 5));
	system("pause");
	return 0;
}