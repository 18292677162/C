#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 12, b = 15, i = 0;
	printf("%d  %d\n", a, b);
	for (i = a; i > 0; i--)
	{
		if (b%i == 0 && a%i == 0)
		{
			printf("Greatest common divisor: %d\n", i);
			break;
		}
	}
	system("pause");
	return 0;
}