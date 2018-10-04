#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

int main()
{
	int arr[] = { 3, 5, 9, 2, 5, 3, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int find = 0;
	for (i = 0; i < sz; i++)
	{
		find ^= arr[i];//Loop to perform an exclusive or operation
	}
	printf("%d\n", find);
	system("pause");
	return 0;
}