#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void num(unsigned int value)
{
	int count = 0;
	int i = 0;
	int arr[32] = { 0 };
	while (value)
	{
		arr[i++] = value % 2;
		value /= 2;
	}
	printf("An odd number of sequences:\n");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", arr[i]);
	}
	printf("\nEven number sequence:\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int value = 11;
	num(value);
	system("pause");
	return 0;
}