#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int killer = 0;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if (3 == (('a' != killer) + ('c' == killer) + ('d' == killer) + ('d' != killer)))
			printf("killer = %c\n", killer);
	}
	system("pause");
	return 0;
}