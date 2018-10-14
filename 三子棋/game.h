#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<windows.h>
#include <time.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PalyerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
int CheckWin(char board[ROW][COL], int row, int col);
int CheckFull(char board[ROW][COL], int row, int col);

#endif //__GAME_H__