#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i < col - 1)
			printf("---|---|---\n");
	}
}

void PalyerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("Please input coordinates:\n");
		scanf("%d%d", &x, &y);
		if (((1 <= x) && (x <= 3)) && ((1 <= y) && (y <= 3)))
		{
			if (' ' == board[x - 1][y - 1])
			{
				board[x - 1][y - 1] = 'O';
				printf("Player move:\n");
				break;
			}
			else
			{
				printf("Input coordinates are occupied. Please re-enter!\n");
			}
		}
		else
		{
			printf("Input coordinates do not exist. Please re-enter!\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int x = 0;
	int y = 0;
	printf("Computer move:\n");
	while (1)
	{
		x = rand() % ROW+1;
		y = rand() % COL+1;
		if ((1 <= x <= 3) && (1 <= x <= 3) && (' ' == board[x - 1][y - 1]))
		{
			board[x - 1][y - 1] = 'X';
			break;
		}
	}
}

int CheckWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (((board[i][0] == 'X' && board[i][1] == 'X') && board[i][2] == 'X') ||
			((board[0][i] == 'X' && board[1][i] == 'X') && board[2][i] == 'X') ||
			((board[0][0] == 'X' && board[1][1] == 'X') && board[2][2] == 'X') ||
			((board[2][0] == 'X' && board[1][1] == 'X') && board[0][2] == 'X'))
		{
			printf("You lose!\n");
			return 1;
		}
		if (((board[i][0] == 'O' && board[i][1] == 'O') && board[i][2] == 'O') ||
			((board[0][i] == 'O' && board[1][i] == 'O') && board[2][i] == 'O') ||
			((board[0][0] == 'O' && board[1][1] == 'O') && board[2][2] == 'O') ||
			((board[2][0] == 'O' && board[1][1] == 'O') && board[0][2] == 'O'))
		{
			printf("You win!\n");
			return 1;
		}
	}
	return 0;
}

int CheckFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	printf("Tie!\n");
	return 1;
}