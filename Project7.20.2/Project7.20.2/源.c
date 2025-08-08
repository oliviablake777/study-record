/*#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
	ElemType* data;
	int length;
}SeqList;
//顺序表初始化动态分配内存
SeqList* initList() {
	SeqList* L = (SeqList*)malloc(sizeof(SeqList));
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	L->length = 0;
	return L;
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
	for (int i = 0; i < L->length; i++) {
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
		for (int i = L->length - 1; i >= pos - 1; i--) {
			L->data[i + 1] = L->data[i];
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
}
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
			L->data[i - 1] = L->data[i];
		}
	}
	L->length--;
	return 1;

}
//查找数据位置
int findElem(SeqList* L, ElemType e) {
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

 int main() {
	SeqList* List = initList();
	printf("初始化成功，目前长度占用%d\n", List->length);
	printf("目前占用内存%zu字节\n", sizeof(List->data));
	appendList(List, 10);
	appendList(List, 20);
	appendList(List, 30);
	appendList(List, 40);
	inserList(List, 3, 80);
	ListElem(List);
	ElemType delData;
	deleteList(List, 2, &delData);
	printf("被删除的数据为：%d\n ", delData);
	//deleteList(&List, 2);
	ListElem(List);
	printf("%d\n", findElem(List, 80));
	return 0;
}*/
#include<stdio.h>
#include<stdlib.h> 
#define MAXSIZE 100
typedef int ElemType;

// 只保留动态数组版 SeqList 定义
typedef struct {
    ElemType* data; // 动态数组
    int length;     // 当前长度
} SeqList;

// 初始化动态顺序表
/*SeqList* initList() {
    SeqList* L = (SeqList*)malloc(sizeof(SeqList));
    if (L == NULL) {
        printf("SeqList 内存分配失败！\n");
        return NULL;
    }
    L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    if (L->data == NULL) {
        printf("data 数组内存分配失败！\n");
        free(L); // 避免泄漏
        return NULL;
    }
    L->length = 0;
    return L;
}*/
//顺序表初始化动态分配内存
SeqList* initList() {
	SeqList* L = (SeqList*)malloc(sizeof(SeqList));
	L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
	L->length = 0;
	return L;
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
	for (int i = 0; i < L->length; i++) {
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
		for (int i = L->length - 1; i >= pos - 1; i--) {
			L->data[i + 1] = L->data[i];
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
			L->data[i - 1] = L->data[i];
		}
	}
	L->length--;
	return 1;

}
//查找数据位置
int findElem(SeqList* L, ElemType e) {
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

/*int main() {
    // 1. 初始化
    SeqList* List = initList();
    if (List == NULL) {
        return 1; // 初始化失败直接退出
    }
    printf("=== 初始化完成 ===\n");
    printf("初始化成功，目前长度占用%d\n", List->length);
    printf("目前占用内存 %zu 字节（动态数组实际内存）\n", sizeof(ElemType) * MAXSIZE);

    // 2. 尾部添加元素
    appendList(List, 10);
    appendList(List, 20);
    appendList(List, 30);
    appendList(List, 40);
    printf("=== 尾部添加 4 个元素 ===\n");
    ListElem(List);

    // 3. 插入元素（位置 3 插入 80）
    if (inserList(List, 3, 80)) {
        printf("=== 插入元素 80 到位置 3 ===\n");
        ListElem(List);
    }

    // 4. 删除元素（删除位置 2，保存到 delData）
    ElemType delData;
    if (deleteList(List, 2, &delData)) {
        printf("=== 删除位置 2 的元素 ===\n");
        printf("被删除的数据为：%d\n", delData);
        ListElem(List);
    }

    // 5. 查找元素（查找 80 的位置）
    int pos = findElem(List, 80);
    printf("=== 查找元素 80 ===\n");
    if (pos != 0) {
        printf("元素 80 的位置是：%d\n", pos);
    }

    // 6. 释放内存（必须执行！）
    free(List->data);
    free(List);
    printf("=== 内存已释放 ===\n");

    system("pause"); // 暂停查看结果（Windows 环境）
    return 0;
}*/
int main() {
	SeqList* List = initList();
	printf("初始化成功，目前长度占用%d\n", List->length);
	printf("目前占用内存%zu字节\n", sizeof(List->data));
	appendList(List, 10);
	appendList(List, 20);
	appendList(List, 30);
	appendList(List, 40);
	inserList(List, 3, 80);
	ListElem(List);
	ElemType delData;
	deleteList(List, 2, &delData);
	printf("被删除的数据为：%d\n ", delData);
	//deleteList(&List, 2);
	ListElem(List);
	printf("%d\n", findElem(List, 80));
	return 0;
}