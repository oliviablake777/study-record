#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu() {
	printf("******************\n");
	printf("***** 1.play *****\n");
	printf("***** 0.exit *****\n");
	printf("******************\n");
}
void game() {
	//定义俩个数组
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化棋盘
	//mine数组初始化为'0'
	//show数组初始化为'*'
	Initboard(mine,ROWS,COLS,'0');
	Initboard(show, ROWS, COLS, '*');
	//打印棋盘
	Displayboard(show, ROW, COL);
	//布置雷
	Setmine(mine,ROW, COL);
	//排查雷
	Findmine(mine, show, ROW, COL);

	
}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}