#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HPPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->capacity = newcapacity;
		php->a = tmp;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a,php->size-1);
}
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	
	while (child < n)
	{
		if (child+1<n&& a[child] > a[child+1])
		{
			++child;
			//Swap(&a[child], &a[child + 1]);
		}
	   if(a[parent]>a[child]) 
	   {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
	   }
	   else
	   {
		   break;
	   }
	}
}
void HPPop(HP* php)
{
	assert(php);
	assert(php->size>0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->size = php->capacity = 0;
}
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size==0;
}
