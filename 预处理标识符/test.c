#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main()
{
	printf("FILE:%s\nLINE:%d\nDATE:%s\nTIME:%s\n", __FILE__, __LINE__, __DATE__, __TIME__);
	system("pause");
	return 0;
}