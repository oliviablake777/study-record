#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Initboard(char board[ROWS][COLS], int rows, int cols, char set) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}
void Displayboard(char board[ROWS][COLS], int row, int col) {
	printf("--------扫雷游戏-------\n");
	for (int i = 0; i <= col; i++) {
		printf("%d ",i);
	}
	printf("\n");
	for (int j = 1; j <= row; j++) {
		printf("%d ", j);
		for (int m = 1; m <= col; m++) {
			printf("%c ", board[j][m]);

		}
		printf("\n");
	}
}
void Setmine(char board[ROWS][COLS], int row, int col) {
	int count=EAST_COUNT;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
		
	}
}
int GetmineCount(char mine[ROWS][COLS], int x, int y) {
	return (mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] +
		mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS],int row,int col) {
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EAST_COUNT) {
		printf("请输入你要排查的坐标：\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("很遗憾，你被炸死了\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else {
				int count = GetmineCount(mine, x, y);
				show[x][y] = count + '0';
				Displayboard(show, ROW, COL);
				win++;
			}

		}
		else {
			printf("输入坐标错误，请重新输入：\n");
		}
	}
	if (win == row * col - EAST_COUNT) {
		printf("恭喜你，排雷成功\n");
		Displayboard(mine, ROW, COL);
	}
}