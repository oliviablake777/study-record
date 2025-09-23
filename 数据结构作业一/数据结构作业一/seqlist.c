#define _CRT_SECURE_NO_WARNINGS 1
//在一个从小到大排列的顺序表插入一个值后依旧从小到大排序
//单链表，输入一个值，删除单链表中与这个值相同的
#include<stdio.h>
#define maxsize 100
typedef int elemtype;
typedef struct {
	elemtype elem[maxsize];
	int length;
}seqlist;
void InserSqelist(seqlist *L,int n)
{
	assert(L);
	int pos = 0;
	for(int i = 0;i < L->length;i++)
	{
		if (L->elem[i] > n) {
			break;
		}
		pos++;
	}
	for (int j = L->length; j > pos; j--)
	{
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[pos] = n;
	L->length++;
	
}
typedef struct node
{
	elemtype data;
	struct node* next;
}linklist;
struct linklist* deletesame(linklist* head,int n)
{
	// 处理头节点可能为目标值的情况
	while (head != NULL && head->data==n) {
		head = head->next;  // 删除头节点
	}

	linklist* prev = head;
	linklist* pcur = prev ? prev->next : NULL;  // 从新的头节点的下一个开始遍历
	while (pcur != NULL)
	{
		if (pcur->data == n)
		{
			prev->next = pcur->next;
			free(pcur);
			pcur = prev->next;
		}
		else
		{
			prev = pcur;
		}
		pcur = pcur->next;
	}
	return head;
}