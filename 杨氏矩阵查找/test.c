#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#define ROW 3
#define COL 3 

int search_number(int arr[ROW][COL], int num)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (num == arr[i][j])
				return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[ROW][COL] = { 1, 2, 3, 2, 3, 4, 3, 4, 5 };
	int i = 0;
	int j = 0;
	int num = 0;
	printf("The array is:\n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	scanf("%d", &num);
	if (1 == search_number(arr, num))
		printf("find it!\n");
	else
		printf("not find it!\n");
	system("pause");
	return 0;
}