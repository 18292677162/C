#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("***************************\n");
	printf("******     1. play       ******\n");
	printf("******     0. exit        ******\n");
	printf("***************************\n");
}

void game()
{
	printf("PLAY GAME\n");
	//1. Generating random number
	int ret = 0;
	int num = 0;
	ret = rand()%100;//Call the rand function to get one or a series of random Numbers, and take the remainder of 100 to get two digits.
	//printf("%d\n", ret);
	//2. Guess the number
	while(1)
	{
		printf("Please guess the number:");
		scanf("%d", &num);
		if(num == ret)
		{
			printf("Congratulations, you guessed it\n");
			break;
		}
		else if(num>ret)
		{
			printf("It's too big\n");
		}
		else
		{
			printf("It's too small\n");
		}
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));// Call srand(time(NULL)) to set the random number seed unsigned integer type 0~32767 to not waste memory
	do 
	{
		menu();
		printf("Please select:");
		scanf("%d", &input);
		switch(input)
		{
		case 0:
			printf("Quit the game\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("The wrong choice\n");
			break;
		}
	} 
	while (input);
	system("pause");
	return 0;
}

//The rand function is to obtain a pseudo-random number (the concept of pseudo-random Numbers is described below).
//1. Function name:
//rand ();
// 2. Statement:
//int rand ();
// 3. Header file:
//stdlib. H
// 4. Functions:
// returns a pseudo-random number. It is a pseudo-random number because, in the absence of any other operation, each time the program is executed, the sequence of random Numbers obtained by the call rand is fixed (not truly "random").
// 5. In order to make the result of rand more "true", that is, to make its return value more random (uncertain), C language also provides srand function in stdlib.h, through which a random number seed can be set, usually with the number of milliseconds of the current time as the parameter. The millisecond value of the current time(which is located in time.h) can be obtained by time(NULL).
// 6. The process of using rand can be summarized as follows:
//1 calls srand(time(NULL)) to set the seed of random number.
//2 calls the rand function to get one or a series of random Numbers.
// it is important to note that srand only needs to be called once before all rand calls, and there is no need to be called more than once.
// 7 the following is an example of randomly obtaining 10 integer values and output to facilitate understanding.
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//int main()
//{
//	int i;
//	srand(time(NULL));//Set random number seed.
//	for (i = 0; i < 10; i++)//Run 10 times.
//		printf("%d\n", rand());//Get one random number at a time and output.
//	return 0;
//}