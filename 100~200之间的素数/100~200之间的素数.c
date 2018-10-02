#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	int j = 0;
	int n = 0;
	int count = 0;
	for (i = 101; i <= 200; i += 2)//Cut the program's calculations in half
	{
		n = sqrt(i);
		for (j = 2; j <= n; j++)
		{
			if (0 == i%j)
			{
				break;
			}
		}
		if (j > n)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n");
	printf("count=%d\n", count);
	system("pause");
	return 0;
}
