#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int num = 12345;
	int arr[10] = { 0 };
	int i = 0; 
	int count = 0;
	if (num < 0)//Delete the minus sign.
	{
		num *= -1;
	}
	while (num)
	{
		arr[i++] = num % 10;
		num /= 10;
		count++;
	}
	for (i = count - 1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
//Function recursive


//void print(int n)//1234
// {
// 	if(n>9)
// 	{
// 		print(n/10);//123
// 	}
// 	printf("%d ", n%10);//4
// }
// 
// int main()
// {
// 	int num = 1234;
// 	print(num);
//	system("pause");
//	return 0;
// }
