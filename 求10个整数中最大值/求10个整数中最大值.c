#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = { 6, 7, 2, 3, 9, 5, 6, 15, 8, 14 };
	int i = 0;
	int max = arr[0];
	for (i = 0; i<10; i++)
	{
		if (arr[i + 1]>max)
		{
			max = arr[i + 1];
		}
	}
	printf("max=%d\n", max);
	system("pause");
	return 0;
}