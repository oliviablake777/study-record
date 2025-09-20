#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SListTest1()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	SLTPushFront(&plist, 5);
	SLTPushFront(&plist, 6);
	SLTPushFront(&plist, 7);
	SLTPushFront(&plist, 8);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPrint(plist);
	//查找
	//SLTNode* find = SLTFind(plist, 1);
	//pos前插入
	//SLTInsert(&plist, find, 11);
	//SLTPrint(plist);
	//pos后插入
	SLTNode* find = SLTFind(plist,1);
	SLTInsertAfter(find,18);
	SLTPrint(plist);
	//测试删除pos前
	SLTErase(&plist, find);
	SLTPrint(plist);
	//测试删除pos后
	SLTNode* find2= SLTFind(plist,7);
	SLTEraseAfter(find2);
	SLTPrint(plist);
}
int main()
{
	SListTest1();
	return 0;
}