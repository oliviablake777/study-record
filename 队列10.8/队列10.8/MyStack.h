#pragma once
#include"Queue.h"
typedef struct {
    Queue q1;
    Queue q2;
} MyStack;
MyStack* myStackCreate();
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);
int myStackTop(MyStack* obj);
bool myStackEmpty(MyStack* obj);
void myStackFree(MyStack* obj);