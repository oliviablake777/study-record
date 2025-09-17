#define _CRT_SECURE_NO_WARNINGS 1
//顺序表初始化
#include"SeqList.h"
void SLInit(SL* ps) {
	ps->arr = NULL;
	ps->size =ps-> capacity = 0;
}
//顺序表的销毁
void SLDestroy(SL* ps)
{
	//先判断顺序表是否为空
	if (ps->arr) {
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//顺序表的打印
void SLPrint(SL s)
{
	for (int i = 0; i < s.size ; i++) {
		printf("%d ", s.arr[i]);
	}
	printf("\n");
}
//检查内存
void SLCheckCapacity(SL* ps) 
{
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : 2 *ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr,newcapacity * sizeof(SLDataType));
		if (tmp==NULL) {
			perror("realloc fail!");
			exit(1);//直接退出程序，不再继续执行
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	   
}
//头部插入
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	//让所有数据往后一个位置
	for (int i=ps->size;i>0;i--)
	{
		ps->arr[i] = ps->arr[i-1];
	}
	ps->arr[0] = x;
	//ps->size++;//
	++ps->size;
}
//尾部插入
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}
//头部删除
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->arr);
	//把数据往前移一个
	for (int i = 0; i < ps->size -1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	//ps->size--;
	--ps->size;
}
//尾部删除
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->arr);
	//ps->size--;俩个都可以
	--ps->size;
}
//在指定位置之前插入数据
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size; i >pos; i--)
	{
		ps->arr[i] = ps->arr[i-1];
	}
	ps->arr[pos] = x;
	ps->size++;
}
//指定位置删除数据
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(ps->arr);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//查找数据是否存在
/*int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x) {
			return i;
		}
	}
	return -1;
}*/
