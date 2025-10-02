#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<stdbool.h>
#define WALL L'□' 
#define BODY L'●' 
#define POS_X 24
#define POS_Y 5
#define FOOD L'★'

//相关数据
//蛇的方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};
//蛇的状态
enum SNAKE_STATUS
{
	OK,
	KILL_BY_WALL,
	KILL_BY_SELF,
	END_NORMAL
};
//蛇身节点指针
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;
//贪吃蛇
typedef struct Snake
{
	pSnakeNode _pSnake;//指向蛇头的指针
	pSnakeNode _pFood;//指向食物的指针
	enum DIRECTION dir;//蛇的方向
	enum SNAKE_STATUS status;//蛇的状态
	int food_score;//食物分数
	int score;//总分数
	int sleep_time;//休息时间
}Snake,*pSnake;
//函数声明
//定位光标的位置
void SetPos(short x, short y);
//设置欢迎页面
void WelcomeToGame();
//打印墙体
void CreatMap();
//初始化贪吃蛇
void InitSnake(pSnake ps);
//初始化食物
void CreatFood(pSnake ps);
//游戏开始
void GameStart(pSnake ps);
//游戏运行
void GameRun(pSnake ps);
//打印帮助信息
void PrintHelpInfo();
//游戏暂停
void Pause();
//蛇移动
void SnakeMove(pSnake ps);
//检测下一个坐标是不是食物
int NextIsFood(pSnakeNode pn, pSnake ps);
//吃食物
void EatFood(pSnakeNode pn, pSnake ps);
//没有食物
void NoFood(pSnakeNode pn, pSnake ps);
//撞墙
int KillByWall(pSnake ps);
//撞自己
int KillBySelf(pSnake ps);
//游戏结束
void GameOver(pSnake ps);

