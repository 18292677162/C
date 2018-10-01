#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int judge_year(int year)
{
	if ((year % 400 == 0) || (year % 4 == 0))
	{
		printf("%d is a leap year\n", year);
	}
	else
	{
		printf("%d is not a leap year\n", year);
	}
	return 0;
}

int main()
{
	int year = 0;
	scanf("%d", &year);
	judge_year(year);
	system("pause");
	return 0;
}