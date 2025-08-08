#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
//！！！！！！！！！！栈的顺序结构！！！！！！！！！！
/*typedef struct {
	ElemType data[MAXSIZE];
	int top;
}Stack;
//栈初始化
void initStack(Stack* s) {
	s->top=- 1;
}
//判断栈是否为空
int isEmpty(Stack* s) {
	if (s->top == -1) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}
//进栈/压栈
int push(Stack* s, ElemType e) {
	if (s->top == MAXSIZE - 1) {
		printf("满了\n");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}
//出栈
int pop(Stack* s, ElemType* e) {
	if (s->top == -1) {
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}
//获取栈顶元素
int getTop(Stack* s, ElemType* e) {
	if (s->top == -1) {
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}
int main()
{
	Stack s;
	initStack(&s);
	isEmpty(&s);
	push(&s, 10);
	push(&s, 20);
	push(&s, 30);
	isEmpty(&s);
	ElemType e;
	pop(&s, &e);
	printf("%d\n", e);
	getTop(&s, &e);
	printf("%d\n", e);
	return 0;
}*/
/*typedef struct
{
	ElemType* data;
	int top;
}Stack;
//！！！！！！！！！！！！！！！动态内存分配初始化！！！！！！！！！！！！
Stack* initStack() {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	s->top = -1;
	return s;
}
//判断栈是否为空
int isEmpty(Stack* s) {
	if (s->top == -1) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}
//进栈/压栈
int push(Stack* s, ElemType e) {
	if (s->top == MAXSIZE - 1) {
		printf("满了\n");
		return 0;
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}

//出栈
int pop(Stack* s, ElemType* e) {
	if (s->top == -1) {
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}

//获取栈顶元素
int getTop(Stack* s, ElemType* e) {
	if (s->top == -1) {
		printf("空的\n");
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}
int main()
{
	Stack *s=initStack();
	isEmpty(s);
	push(s, 10);
	push(s, 20);
	push(s, 30);
	isEmpty(s);
	ElemType e;
	pop(s, &e);
	printf("%d\n", e);
	getTop(s, &e);
	printf("%d\n", e);
	return 0;
}*/
//！！！！！！！！！！！！！！！栈的链式结构！！！！！！！！！！！！！！！
/*typedef struct stack {
	ElemType data;
	struct stack* next;
}Stack;
//初始化
Stack* initStack()
{
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->data = 0;
	s->next = NULL;
	return s;
}
//判断是否为空
int isEmpty(Stack* s) {
	if (s->next == NULL) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}
//进栈（头插法）
int push(Stack* s, ElemType e) {
	Stack* p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return 1;
}
//出栈（删除头结点后一个节点数据）
int pop(Stack* s, ElemType* e) {
	if (s->next == NULL) {
		printf("空的\n");
		return 0;
	}
	*e = s->next->data;
	Stack* q = s->next;
	s->next = q->next;
	free(q);
	return 1;
}
//获取栈顶元素
int getTop(Stack* s, ElemType* e) {
	if (s->next == NULL) {
		printf("空的\n");
		return 0;
	}
	*e = s->next->data;
	return 1;
}
int main()
{
	Stack* s = initStack();
	isEmpty(s);
	push(s, 10);
	push(s, 20);
	push(s, 30);
	ElemType e;
	pop(s, &e);
	printf("%d\n", e);
	getTop(s, &e);
	printf("%d\n", e);
	return 0;
}*/
//！！！！！！！！！！！！！！！队列！！！！！！！！！！！！！！！
/*typedef struct {
	ElemType data[MAXSIZE];
	int front;
	int rear;
}Queue;
//初始化
void initQueue(Queue* Q) {
	Q->front = 0;
	Q->rear = 0;
}
//判断是否为空
int isEmpty(Queue *Q) {
	if (Q->front==Q->rear) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}
//出队
ElemType deQueue(Queue* Q) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 0;
	}
	ElemType e = Q->data[Q->front];
	Q->front++;
	return e;
}
//对尾满了，调整队列
int queueFull(Queue* Q) {
	if (Q->front > 0) {
		int step = Q->front;
		for (int i = Q->front; i <= Q->rear; i++) {
			Q->data[i - step] = Q->data[i];
		}
		Q->front = 0;
		Q->rear = Q->rear - step;
		return 1;
	}
	else {
		printf("真的满了\n");
		return 0;
	}
}
//入队
int eQueue(Queue* Q, ElemType e) {
	if (Q->rear >= MAXSIZE) {
		if (!queueFull(Q))
			return 0;
	}
	Q->data[Q->rear] = e;
	Q->rear++;
	return 1;

}
//获取队头数据
int getHead(Queue* Q, ElemType* e) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	return 1;
}
int main()
{
	Queue q;
	initQueue(&q);
	eQueue(&q, 10);
	eQueue(&q, 20);
	eQueue(&q, 30);
	eQueue(&q, 40);
	eQueue(&q, 50);
	printf("%d\n", deQueue(&q));
	printf("%d\n", deQueue(&q));
	ElemType e;
	getHead(&q, &e);
	printf("%d\n", e);
	return 0;
}*/
//！！！！！！！！！！！！！！！队列动态分配内存！！！！！！！！！！！！！！！
/*typedef struct {
	ElemType* data;
	int front;
	int rear;
}Queue;
//初始化
Queue* initQueue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	q->front = 0;
	q->rear = 0;
	return q;
}
//判断是否为空
int isEmpty(Queue* Q) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}
//循环队列—入队
int eQueue(Queue* Q, ElemType e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		printf("满了\n");
		return 0;
	}
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return 1;

}
//循环队列-出队
int deQueue(Queue* Q, ElemType *e) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return 1;
}
//获取队头数据
int getHead(Queue* Q, ElemType* e) {
	if (Q->front == Q->rear) {
		printf("空的\n");
		return 0;
	}
	*e = Q->data[Q->front];
	return 1;
}
int main()
{
	Queue *q=initQueue();
	eQueue(q, 10);
	eQueue(q, 20);
	eQueue(q, 30);
	eQueue(q, 40);
	eQueue(q, 50);

	ElemType e;
	deQueue(q, &e);
	printf("%d\n", e);
	deQueue(q, &e);
	printf("%d\n", e);


	getHead(q, &e);
	printf("%d\n", e);
	return 0;
}
*/
//！！！！！！！！！！！！！！！队列的链式结构！！！！！！！！！！！！！！！
//定义
typedef struct QueueNode {
	ElemType data;
	struct QueueNode* next;
}QueueNode;
typedef struct {
	QueueNode* front;
	QueueNode* rear;
}Queue;
//初始化
Queue* initQueue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QueueNode* node = (QueueNode*)malloc(sizeof(Queue));
	node->data = 0;
	node->next = NULL;
	q->front = node;
	q->rear = node;
	return q;
}
//插入（尾插)
void eQueue(Queue* q, ElemType e) {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = e;
	node->next = NULL;
	q->rear->next = node;
	q->rear = node;
}
//出队（出头结点后一个）
int deQueue(Queue* q, ElemType* e) {
	if (isEmpty(q)) {
		printf("空的\n");
		return 0;
	}
	QueueNode* node = q->front->next;
	*e = node->data;
	q->front->next = node->next;
	//当要删除的节点是尾节点时
	if (node == q->rear) {
		q->rear = q->front;
	}
	free(node);
	return 1;
}
//判断是否为空
int isEmpty(Queue* q) {
	if (q->front == q->rear) {
		printf("空的\n");
		return 1;
	}
	else {
		return 0;
	}
}
//获取头元素
ElemType getFront(Queue* q) {
	if (isEmpty(q)) {
		printf("空的\n");
		return 0;
	}
	return q->front->next->data;
}
int main()
{
	Queue* q = initQueue();
	eQueue(q, 10);
	eQueue(q, 20);
	eQueue(q, 30);
	eQueue(q, 40);
	eQueue(q, 50);

	ElemType e;
	deQueue(q, &e);
	printf("出队 %d\n", e);
	deQueue(q, &e);
	printf("出队 %d\n", e);

	printf("%d\n", getFront(q));
	return 0;
}

