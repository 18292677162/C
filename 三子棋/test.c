#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("***********************\n");
	printf("***  1.play  0.exit ***\n");
	printf("***********************\n");
}

void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PalyerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (1 == CheckFull(board, ROW, COL))
		{
			break;
		}
		if (1 == CheckWin(board, ROW, COL))
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (1 == CheckFull(board, ROW, COL))
		{
			break;
		}
		if (1 == CheckWin(board, ROW, COL))
		{
			break;
		}
	}
}

void test()
{
	srand((unsigned)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("Please choose:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Exit the game\n");
			break;
		default:
			printf("Input error, please re-enter.\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	system("pause");
	return 0;
}