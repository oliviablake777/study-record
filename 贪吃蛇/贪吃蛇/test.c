#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"
#include<locale.h>
void test()
{
	int ch = 0;
	do
	{
		system("cls");
		Snake snake = { 0 };
		GameStart(&snake);
		GameRun(&snake);
		GameOver(&snake);
		SetPos(20, 15);
		printf("再来一局嘛?(Y/y)：\n");
		SetPos(0, 27);
		ch = getchar();
		while (getchar() != '\n');
	} while (ch=='Y'||ch=='y');
	SetPos(0, 27);
}
int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));
	test();
	return 0;
}