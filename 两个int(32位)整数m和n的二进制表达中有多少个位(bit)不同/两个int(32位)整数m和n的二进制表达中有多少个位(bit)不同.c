#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int a = 1999;
	int b = 2299;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if ((a & 1) != (b & 1))
		{
			count++;
		}
		a >>= 1;
		b >>= 1;
	}
	printf("count=%d\n", count);
	system("pause");
	return 0;
}
// int main()
// {
// 	int m = 1999;
// 	int n = 2299;
// 	int tmp = m^n;
// 	int count = 0;
// 	while(tmp)
// 	{
// 		tmp = tmp & (tmp-1);
// 		count++;
// 	}
// 	printf("%d\n", count);
// 	return 0;
// }