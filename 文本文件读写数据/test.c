#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include <stdio.h>  

int main()
{
	//Write the Numbers 0 to 9 into the data.txt file.
	FILE *p = fopen("data.txt", "w");
	if (p == NULL)
	{
		return 0;
	}
	for (int i = 0; i<100; i++)
		fprintf(p, "%d ", i);
	fclose(p);
	//Store the read data in the array a[10] and print it to the console
	int a[100] = { 0 };
	FILE *fpRead = fopen("data.txt", "r");
	if (fpRead == NULL)
	{
		return 0;
	}
	for (int i = 0; i<50; i++)
	{
		fscanf(fpRead, "%d ", &a[i]);
		printf("%d ", a[i]);
	}
	system("pause");

	return 1;
}