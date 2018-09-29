#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char password[10] = {0};
	int i = 0;
	for(i=0; i<3; i++)
	{
		printf("Password:");
		scanf("%s", password);
		if(strcmp(password,"123456") == 0)
		{
			printf("Success!\n");
			break;
		}
		else
		{
			printf("Password error,please try again!\n");
		}
	}
	if (i == 3)
	{
		printf("Password error 3 times,exit!\n");
	}
	system("pause");
	return 0;
}