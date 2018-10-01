#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int judge_prime(int n)
{
	int i = 0;
	if (n < 2)
	{
		printf("%d is not a prime number\n", n);
		return 0;
	}
	for (i = 1; i <= sqrt(n); i++)
	{ 
		 if (n%i == 0)
		{
			printf("%d is not a prime number\n", n);
			return 0;
		}
	}
	printf("%d is a prime number\n", n);
	return 0;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	judge_prime(n);
	system("pause");
	return 0;
}