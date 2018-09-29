#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int binary_search(int arr[], int i, int left, int right)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == i)
		{
			return mid;
		}
		else if (arr[mid] < i)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i = 4;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = binary_search(arr, i, 2, 8);
	if (ret == -1)
	{
		printf("Not find it\n");
	}
	else
	{
		printf("Find it:%d\n", ret);
	}
	system("pause");
	return 0;
}