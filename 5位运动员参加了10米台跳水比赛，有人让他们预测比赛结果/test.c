#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((1 == ((2 == b) + (3 == a))) &&
							(1 == ((2 == b) + (4 == e))) &&
							(1 == ((1 == c) + (2 == d))) &&
							(1 == ((5 == c) + (3 == d))) &&
							(1 == ((4 == e) + (1 == a))))
						{
							if (((a != b) && (a != c) && (a != d) && (a != e)) &&
								((b != c) && (b != d) && (b != e)) &&
								((c != d) && (c != e)) &&
								(d != e))//A judgment of five different values
							{
								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}
// five swimmers took part in the 10m platform diving competition and were asked to predict the results
//A contestant said: B second, I third;
//B contestants say: I am second, E fourth;
//C contestants say: I am first, D second;
//D contestants say: C finally, I am the third;
//E contestant said: I am fourth, A first;
// after the competition, each contestant said half correctly, please program to determine the ranking of the competition.