#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
//顺序表的定义
typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SeqList;
//顺序表初始化定义
void initList(SeqList* L) {
	L->length=0;
}
//尾部添加元素
int appendList(SeqList* L, ElemType e)
{
	if (L->length >= MAXSIZE) {
		printf("顺序表已满\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}
//遍历
void ListElem(SeqList* L) {
	for (int i = 0; i <L->length; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
	printf("此时元素长度为：%d", L->length);
	printf("\n");
}
//插入元素
int inserList(SeqList* L, int pos, ElemType e) {
	if (L->length >= MAXSIZE) {
		printf("顺序表已满\n");
		return 0;
	}
	if (pos<1 || pos>L->length) {
		printf("插入位置错误\n");
		return 0;
	}
	if (pos <= L->length) {
		for (int i = L->length-1; i >=pos-1; i--) {
			L->data[i+1] = L->data[i];
		}
		L->data[pos - 1] = e;
		L->length++;
	}
	return 1;
}
//删除元素(自写)
/*int deleteList(SeqList* L, int pos) {
	if (pos<1 || pos>L->length) {
		printf("删除元素位置有误\n");
		return 0;
	}
	for (int i = pos - 1; i <L->length-1; i++)
	{
		L->data[i] = L->data[i + 1];
	}
	L->length--;
	return 1;
}*/
//删除元素
int deleteList(SeqList* L, int pos, ElemType* e) {
	if (L->length == 0) {
		printf("该表为空表\n");
		return 0;
	}
	if (pos<1 || pos>L->length) {
		printf("删除元素位置有误\n");
		return 0;
	}
	*e = L->data[pos - 1];
	if (pos < L->length) {
		for (int i = pos; i < L->length; i++) {
			L->data[i-1] = L->data[i];
		}
	}
		L->length--;
		return 1;
	
}
//查找数据位置
int findElem(SeqList *L, ElemType e) {
	if (L->length == 0) {
		printf("该表为空表\n");
		return 0;
	}
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}

int main()
{
	SeqList List;
	initList(&List);
	printf("初始化成功，目前长度占用%d\n", List.length);
	printf("目前占用内存%zu字节\n", sizeof(List.data));
	appendList(&List, 10);
	appendList(&List, 20);
	appendList(&List, 30);
	appendList(&List, 40);
	inserList(&List, 3, 80);
	ListElem(&List);
	int delData;
	deleteList(&List, 2,&delData);
	printf("被删除的数据为：%d\n ", delData);
	//deleteList(&List, 2);
	ListElem(&List);
	printf("%d\n", findElem(&List, 80));
	return 0;
}