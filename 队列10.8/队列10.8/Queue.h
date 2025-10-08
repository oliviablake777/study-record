#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int QDataType;
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

// 队尾插入
void QueuePush(Queue* pq, QDataType x);
// 队头删除
void QueuePop(Queue* pq);

// 取队头和队尾的数据
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);