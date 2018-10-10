#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<string.h>

int search_string(char *str1, char *str2,int right1, int right2)
{
	int i = 0;
	int j = 0;
	char buf[20];
	strcpy(buf, str1);
	strcpy(buf + right1, str1);
	for (i = 0; i < 2 * right1; i++)
	{
		while (buf[i] == str2[j])
		{
			j++;
			if (j == right2)
				return 1;
		}
	}
	return 0;
}

void reverse_string(char *str, int left, int right)
{
	int i = right;
	int j = left;
	int num = 0;
	while (j < i)
	{
		num = str[j];
		str[j] = str[i];
		str[i]=num;
		j++;
		i--;
	}
}
int main()
{
	int n = 0;
	char arr1[10] = { "ABCDEFGH" };
	char arr2[10] = { "FGHABCDE" };
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	printf("%s\n", arr1);
	scanf("%d", &n);
	reverse_string(arr1, 0, n - 1);
	reverse_string(arr1, n, len1 - 1);
	reverse_string(arr1, 0, len1 - 1);
	printf("%s\n", arr1);
	if (1 == search_string(arr1, arr2, len1, len2))
		printf("%s is left handed\n", arr2);
	else
		printf("%s is not left handed\n", arr2);
	system("pause");
	return 0;
}