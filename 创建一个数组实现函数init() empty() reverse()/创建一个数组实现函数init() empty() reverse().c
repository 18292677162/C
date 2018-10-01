#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int init(int arr[], int sz)//Init array
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

int reverse(int arr[], int sz)//The elements are reversed
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < sz / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[sz - i - 1];
		arr[sz - i - 1] = tmp;
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

int empty(int arr[], int sz)//Empty array
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}


int main()
{
	int arr[10];
	int sz = sizeof(arr)/sizeof(arr[0]);
	init(arr, sz);
	reverse(arr, sz);
	empty(arr, sz);
	system("pause");
	return 0;
}