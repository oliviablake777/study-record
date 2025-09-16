#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SLTest01() {
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
	//ͷɾ
	SLPopFront(&sl);
	SLPrint(sl);
	//βɾ
	SLPopBack(&sl);
	SLPrint(sl);
}
int main()
{
	SLTest01();
	/*SL sl;
	SLInit(&sl);

	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);
	SLPrint(sl);//1 2 3 4
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	SLPrint(sl);*/
	return 0;
}