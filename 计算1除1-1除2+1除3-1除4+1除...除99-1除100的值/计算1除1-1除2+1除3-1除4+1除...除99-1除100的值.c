#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	double sum = 0;
	int sign = -1;
	for (i = 1; i <= 100; i++)
	{
		sign = -sign;
		sum = sum + sign*1.0 / i;
	}
	printf("%lf\n", sum);
	system("pause");
	return 0;
}