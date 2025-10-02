#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"
//定位光标的位置
void SetPos(short x, short y)
{
	//获取标准输出流句柄
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//定位光标位置
	COORD pos = { x,y };
	SetConsoleCursorPosition(houtput, pos);
}
//设置欢迎页面
void WelcomeToGame()
{
	SetPos(40, 14);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(40, 25);//让按任意键出现的位置好看点
	system("pause");
	system("cls");
	SetPos(25, 12);
	printf("用 ↑ . ↓ . ← . → 分别控制蛇的移动， F3为加速，F4为减速\n");
	SetPos(25, 13);
	printf("加速能获得更高的分数\n");
	SetPos(40, 25);//让按任意键出现的位置好看点
	system("pause");
	system("cls");
}
//打印墙体
void CreatMap()
{
	SetPos(0,0);
	int i = 0;
	for (i = 0; i < 58; i += 2)
	{
		wprintf(L"%c", WALL);
	}
	SetPos(0, 26);
	for (i = 0; i < 58; i += 2)
	{
		wprintf(L"%c", WALL);
	}
	for (i = 1; i < 26; i++)
	{
		SetPos(0, i);
		wprintf(L"%c", WALL);
	}
	for (i = 1; i < 26; i++)
	{
		SetPos(56, i);
		wprintf(L"%c", WALL);
	}
	SetPos(0, 27);
}
//初始化贪吃蛇
void InitSnake(pSnake ps)
{
	pSnakeNode cul = NULL;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cul = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cul == NULL)
		{
			perror("InitSnake::malloc");
			return;
		}
		cul->next = NULL;
		cul->x = POS_X + 2 * i;
		cul->y = POS_Y;
		if (ps->_pSnake == NULL)
		{
			ps->_pSnake = cul;
		}
		//头插
		else
		{
			cul->next = ps->_pSnake;
			ps->_pSnake = cul;
		}

	}
	//打印蛇身
	cul = ps->_pSnake;
	while (cul != NULL)
	{
		SetPos(cul->x, cul->y);
		wprintf(L"%c", BODY);
		cul = cul->next;
	}
	//指向食物的指针
	//ps->_pFood = NULL;
	//蛇的方向
	ps->dir = RIGHT;
	ps->status;//蛇的状态
	ps->status = OK;
	//食物分数
	ps->food_score = 10;
	//总分数
	ps->score = 0;
	//休息时间
	ps->sleep_time = 200;
	SetPos(0, 27);
}
//初始化食物
void CreatFood(pSnake ps)
{
	int x = 0;
	int y = 0;
again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;

	} while (x % 2 != 0);
	pSnakeNode cul = ps->_pSnake;
	while (cul)
	{
		if (x == cul->x && y == cul->y)
		{
			goto again;
		}
		cul = cul->next;
	}
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;
	SetPos(x, y);
	wprintf(L"%c", FOOD);
	ps->_pFood = pFood;
}
//游戏开始
void GameStart(pSnake ps)
{
	//设置控制台窗⼝的⼤⼩，30⾏，100列 
    //mode 为DOS命令 
	system("mode con cols=100 lines=30");
	//设置cmd窗⼝名称 
	system("title 贪吃蛇");
	//获取标准输出的句柄(⽤来标识不同设备的数值) 
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//影藏光标操作 
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);//获取控制台光标信息 
	CursorInfo.bVisible = false; //隐藏控制台光标 
	SetConsoleCursorInfo(hOutput, &CursorInfo);//设置控制台光标状态
	//打印欢迎界⾯ 
	WelcomeToGame();
	//打印地图 
	CreatMap();
	//初始化蛇 
	InitSnake(ps);
	//创造第⼀个⻝物 
	CreatFood(ps);
	SetPos(0, 27);
}
//打印帮助信息
void PrintHelpInfo()
{
	// 1. 获取控制台句柄
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// 2. 存储旧颜色（以便结束后恢复）
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	WORD oldColor = csbi.wAttributes;

	// 打印前面部分帮助信息（使用默认颜色）
	SetPos(64, 14);
	wprintf(L"%ls", L"不能穿墙，不能咬到自己\n");
	SetPos(64, 16);
	wprintf(L"%ls",L"用↑.↓.←.→分别控制蛇的移动.");
	SetPos(64, 17);
	wprintf(L"%ls", L"F3 为加速，F4 为减速\n");
	SetPos(64, 18);
	wprintf(L"%ls", L"ESC ：退出游戏.space：暂停游戏.");
	SetPos(64, 20);
	// 3. 设置为绿色 (例如：亮绿色)
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	wprintf(L"%ls", L"苔藓大王制作\n");
	// 4. 恢复为旧颜色
	SetConsoleTextAttribute(hConsole, oldColor);
	SetPos(0, 27);
}
#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)
//游戏暂停
void Pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}
//检测下一个坐标是不是食物
int NextIsFood(pSnakeNode pn,pSnake ps)
{
	return (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y);
}
//吃食物
void EatFood(pSnakeNode pn, pSnake ps)
{
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;
	free(pn);
	pn = NULL;
	//打印蛇
	pSnakeNode cul = ps->_pSnake;
	while (cul)
	{
		SetPos(cul->x, cul->y);
		wprintf(L"%c", BODY);
		cul = cul->next;
	}
	//改变分数
	ps->score += ps->food_score;
	//重新生成食物
	CreatFood(ps);

}
//没有食物
void NoFood(pSnakeNode pn, pSnake ps)
{
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;
	//打印蛇
	pSnakeNode cul = ps->_pSnake;
	while (cul->next->next!=NULL)
	{
		SetPos(cul->x, cul->y);
		wprintf(L"%c",BODY);
		cul = cul->next;
	}
	SetPos(cul->next->x, cul->next->y);
	printf("  ");
	free(cul->next);
	cul->next = NULL;
}
//撞墙
int KillByWall(pSnake ps)
{
	if ((ps->_pSnake->x == 0)
		|| (ps->_pSnake->x == 56)
		|| (ps->_pSnake->y == 0)
		|| (ps->_pSnake->y == 26))
	{
		ps->status = KILL_BY_WALL;
		return 1;
	}
	return 0;
}
//撞自己
int KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur)
	{
		if ((ps->_pSnake->x == cur->x) && (ps->_pSnake->y == cur->y))
		{
			ps->status = KILL_BY_SELF;
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

//蛇移动
void SnakeMove(pSnake ps)
{
	pSnakeNode pnext = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pnext == NULL)
	{
		perror("SnakeMove::malloc()");
		return;
	}
	switch (ps->dir)
	{
	case UP:
	{
		pnext->x = ps->_pSnake->x;
		pnext->y = ps->_pSnake->y - 1;
		break;
	}
	case DOWN:
	{
		pnext->x = ps->_pSnake->x;
		pnext->y = ps->_pSnake->y + 1;
		break;
	}
	case LEFT:
	{
		pnext->x = ps->_pSnake->x - 2;
		pnext->y = ps->_pSnake->y;
		break;
	}
	case RIGHT:
	{
		pnext->x = (ps->_pSnake->x) + 2;
		pnext->y = ps->_pSnake->y;
		break;
	}
	}
	if (NextIsFood(pnext,ps))
	{
		EatFood(pnext, ps);
	}
	else
	{
		NoFood(pnext, ps);
	}
	KillByWall(ps);
	KillBySelf(ps);
}
//游戏运行
void GameRun(pSnake ps)
{
	PrintHelpInfo();
	do
	{
		SetPos(64, 10);
		printf("总分数：%d\n", ps->score);
		SetPos(64, 11);
		printf("当前食物的分数：%d\n", ps->food_score);
		if (KEY_PRESS(VK_UP) && ps->dir != DOWN)
		{
			ps->dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->dir != UP)
		{
			ps->dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->dir != RIGHT)
		{
			ps->dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->dir != LEFT)
		{
			ps->dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			ps->status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_F3))
		{
		//加速
			if (ps->sleep_time > 80)
			{
				ps->sleep_time -= 30;
				ps->food_score += 2;
			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			//减速
			if (ps->food_score>2 )
			{
				ps->sleep_time += 30;
				ps->food_score -= 2;
			}
		}
		SnakeMove(ps);
		Sleep(ps->sleep_time);
	} while (ps->status==OK);

}
//游戏结束
void GameOver(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake;
	SetPos(24, 12);
	switch (ps->status)
	{
	case END_NORMAL:
		printf("您主动退出游戏\n");
		break;
	case KILL_BY_SELF :
		printf("您撞上⾃⼰了 ,游戏结束!\n");
		break;
	case KILL_BY_WALL:
		printf("您撞墙了,游戏结束!\n");
		break;
	}
	//释放蛇⾝的节点 
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}

}
