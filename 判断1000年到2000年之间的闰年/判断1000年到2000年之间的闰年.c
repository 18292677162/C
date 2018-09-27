#include<stdio.h>
int main()
{
	int i=1000;
	int count = 0;
	for (i; i <= 2000; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)//Judge a leap year
		{
			count++;//Counter
			printf("%d ", i);
		}
	}
	printf("\ncount=%d\n", count);
	system("pause");
	return 0;
}