#define _CRT_SECURE_NO_WARNINGS 1
#include"MyStack.h"
int main()
{
    /*Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
    QueuePush(&q, 2);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");*/
	MyStack* obj=myStackCreate();
	myStackPush(obj, 1);
	myStackPush(obj, 2);
	myStackPush(obj, 3);
	myStackPush(obj, 4);
	printf("%d ",myStackTop(obj));
	myStackPop(obj);
	printf("%d ", myStackTop(obj));
	myStackPop(obj);
	printf("\n");
	return 0;
}