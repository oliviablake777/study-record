#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void SLTPrint(SLTNode* phead)
{
	SLTNode* pure = phead;
	while (pure)
	{
		printf("%d->", pure->data);
		pure = pure->next;
	}
	printf("NULL\n");

}
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* nownode = (SLTNode*)malloc(sizeof(SLTNode));
	if (nownode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	nownode->next = NULL;
	nownode->data = x;
	return nownode;
}
//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}

}
//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}
//尾删
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead&&*pphead);
	SLTNode* ptail = *pphead;
	SLTNode* prev = *pphead;
	//如果链表只有一个节点
	if ((*pphead)->next==NULL)
	{
		free(ptail);
		ptail = NULL;
	}
	else
		//链表不止一个节点
	{
		while (ptail->next)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}
//头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead&&*pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//查找
/*SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;

	}
	return NULL;
}*/
//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && *pphead);
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	if (pos == *pphead) {
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		newnode->next = pos;
		prev->next = newnode;
	}
}
//在指定位置之后插入数据
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//删除pos节点
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	assert(pos);
	//pos是头节点
	if (*pphead == pos) {
		//头删
		SLTPopFront(pphead);
	}
	else {
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos= NULL;
	}
}
//删除pos之后的节点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos&&pos->next);
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
//销毁链表
void SListDesTroy(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}

