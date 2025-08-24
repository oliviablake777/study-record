#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>

#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EAST_COUNT 10
//初始化棋盘
void Initboard(char board[ROWS][COLS], int rows, int cols, int set); 
//打印
void Displayboard(char board[ROWS][COLS], int row, int col);
//布置雷
void Setmine(char board[ROWS][COLS], int row, int col);
//排查雷
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
