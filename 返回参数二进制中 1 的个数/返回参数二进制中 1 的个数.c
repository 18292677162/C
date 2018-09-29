#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int count_one_bits(unsigned int value)
{
	int count = 0;
	while (value)
	{
		if (value % 2 == 1)
		{
			count++;
		}
		value = value / 2;
	}
	return count;
}

int main()
{
	unsigned int num = 0;
	int ret = 0;
	printf("Input a number:");
	scanf("%d", &num);
	ret = count_one_bits(num);
	printf("count=%d\n", ret);
	system("pause");
	return 0;
}