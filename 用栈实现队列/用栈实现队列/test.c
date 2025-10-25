#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;
// 初始化和销毁
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}
void STDestroy(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = 0;
}
// 入栈  出栈
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top);
	pst->top--;
}
// 取栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top);
	return pst->a[pst->top - 1];
}
// 判空
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}
// 获取数据个数
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}

typedef struct {
	ST s1;
	ST s2;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	STInit(&(obj->s1));
	STInit(&(obj->s2));
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	STPush(&(obj->s1), x);
}

void in2out(MyQueue* obj) {
	while (!STEmpty(&(obj->s1))) {
		STPush(&(obj->s2), STTop(&(obj->s1)));
		STPop(&(obj->s1));
	}
}

int myQueuePop(MyQueue* obj) {
	if (STEmpty(&(obj->s2)))
	{
		in2out(obj);
	}
	int x = STTop(&(obj->s2));
	STPop(&(obj->s2));
	return x;
}

int myQueuePeek(MyQueue* obj) {
	if (STEmpty(&(obj->s2)))
	{
		in2out(obj);
	}
	return STTop(&(obj->s2));
}

bool myQueueEmpty(MyQueue* obj) {
	return STEmpty(&(obj->s1)) && STEmpty(&(obj->s2));
}

void myQueueFree(MyQueue* obj) {
	STDestroy(&(obj->s1));
	STDestroy(&(obj->s2));
}
