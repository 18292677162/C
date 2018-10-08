#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 2; i <= sz - 2; i += 2)
	{
		int j = i;
		for (j = i; j>(i / 2); j--)
		{
			int tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
		}

	}
	for (i = 0; i < sz; i++)
		printf("%d", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}