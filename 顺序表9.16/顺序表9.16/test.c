#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#include"Contact.h"

/*void SLTest01() {
	SL sl;
	SLInit(&sl);
	
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(sl);//1 2 3 4
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	SLPrint(sl);
	//????
	SLPopFront(&sl);
	SLPrint(sl);
	//β??
	SLPopBack(&sl);
	SLPrint(sl);
	SLInsert(&sl, 4, 0);
	SLPrint(sl);
	SLErase(&sl, 2);
	SLPrint(sl);
	int find = SLFind(&sl, 5);
	if (find>=0)
	{
		printf("找到了，下标为%d\n",find);
	}
	else
	{
		printf("没找到\n");
	}
}*/
void menu()
{
	printf("**************************************\n");
	printf("*******1.增加联系人   2.删除联系人*******\n");
	printf("*******3.修改联系人   4.查找联系人*******\n");
	printf("*******5.展示联系人   0.退出     *******\n");
	printf("**************************************\n");
}
int main()
{
	//SLTest01();
	Contact con;
	int op = -1;
	ContactInit(&con);
	do 
	{
		menu();
		printf("请选择你的操作\n");
		scanf("%d", &op);
		switch(op)
		{
		case 1:
			ContactAdd(& con);
		  break;
		case 2:
			ContactDel(&con);
			break;
		case 3:
			ContactModify(&con);
			break;
		case 4:
			ContactFind(&con);
			break;
		case 5:

			break;
		case 0:
			ContactShow(&con);
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	} while (op!=0);
	ContactDesTroy(&con);
	return 0;
}