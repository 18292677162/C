//#include<stdio.h>
//int main()
//{
//	int ch;
//	int count = 0;
//	while ((ch = getchar()) != EOF)
//		printf("%c", ch);
//	system("pause");
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int ch;
	int count = 0;//Define a counter named count
	while ((ch = getchar() != EOF))//Loop input, EOF end.
	{
		if (ch == '{')
		{
			count++;
		}		//When meeting { , counter +1
		if (ch == '}' && count == 0)
		{
			printf("Mismatch\n");
			return 0;
	}       //When you encounter}, but the counter is 0, the output does not match, that is } is in front of {.
		if (ch == '}' && count != 0)
		{
			count--;
		}       //When it is encountered } and the counter is not 0, the counter -1
	}
	if (count == 0)
	{
		printf("Matching!\n");
	}
	else
	{
		printf("Mismatch!\n");
	}          //Judgement counter named count
	system("pause");
	return 0;
}