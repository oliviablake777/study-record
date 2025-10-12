#define _CRT_SECURE_NO_WARNINGS 1
#include"MyStack.h"
MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&(obj->q1));
    QueueInit(&(obj->q2));
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    if (!QueueEmpty(&(obj->q1)))
    {
        QueuePush(&(obj->q1), x);
    }
    else {
        QueuePush(&(obj->q2), x);
    }
}

int myStackPop(MyStack* obj) {
    Queue* Empty = &(obj->q1);
    Queue* NoEmpty = &(obj->q2);
    if (!QueueEmpty(&(obj->q1))) {
        Empty = &(obj->q2);
        NoEmpty = &(obj->q1);
    }
    while (!QueueEmpty(NoEmpty)>1)
    {
        QueuePush(Empty, QueueFront(NoEmpty));
        QueuePop(NoEmpty);
    }
    QDataType a = QueueFront(NoEmpty);
    QueuePop(NoEmpty);
    return a;
}

int myStackTop(MyStack* obj) {
    if (!QueueEmpty(&(obj->q1)))
    {
        return QueueBack(&(obj->q1));
    }
    else {
        return QueueBack(&(obj->q2));
    }
}

bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2));
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&(obj->q1));
    QueueDestroy(&(obj->q2));
    free(obj);
}
