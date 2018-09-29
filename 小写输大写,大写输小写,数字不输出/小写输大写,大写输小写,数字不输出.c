#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int ch = 0;
	while((ch=getchar()) != EOF)
	{
		//islower
		//isupper
		//isdigit
		//tolower
		//toupper
		if(ch>='a' && ch<='z')
		{
			putchar(ch-('a'-'A'));
		}
		else if(ch>='A' && ch<='Z')
		{
			putchar(ch+32);
		}
		else if(ch>='0' && ch<='9')
		{
			;
		}
		else
		{
			putchar(ch);
		}
	}
	system("pause");
	return 0;
}