#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdarg.h>

int my_average(int n, ...)
{
	va_list(arg);
	int i = 0;
	int sum = 0;
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);
	}
	va_end(arg);
	return sum / n;
}

int my_max(int n, ...)
{
	va_list(arg);
	int i = 0;
	int max = 0;
	int tmp = 0;
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		tmp = va_arg(arg, int);
		if (tmp > max)
		{
			max = tmp;
		}
	}
	va_end(arg);
	return max;
}
int main()
{
	printf("%d\n", my_average(5, 1, 2, 3, 4, 5));
	printf("%d\n", my_max(5, 1, 2, 3, 4, 5));
	system("pause");
	return 0;
}