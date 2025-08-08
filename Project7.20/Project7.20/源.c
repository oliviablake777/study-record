#include<stdio.h>
#include<stdlib.h>//动态内存分布的相关函数依赖这个
#define MAXSIZE 100
typedef int ElemType;
//顺序表的定义
/*typedef struct {
	ElemType data[MAXSIZE];
	int length;
}SeqList;
//顺序表初始化定义
void initList(SeqList* L) {
	L->length=0;
}*/
/*typedef struct {
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
/*int deleteList(SeqList* L, int pos, ElemType* e) {
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
}*/

/*int main()
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
}*/
/*int main() {
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
//链表的定义
typedef struct node {
	ElemType data;
	struct node* next;
}Node;
Node* initList() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0;
	head->next = NULL;
	return head;
}
//头插法
Node* inserHead(Node* L, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
	return p;
}
//尾插法
Node* inserTail(Node* tail, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	tail->next = p;//不能=p->next,p是刚创建的结点，p->还没有赋值；
	p->next = NULL;
	return p;
}
//遍历
void ListNode(Node* L) {
	Node* p = L->next;//从链表第一个真正存数据的节点开始遍历
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//获得尾节点
Node* get_tail(Node* L) {
	Node* p = L->next;//从头结点L开始遍历，会把头结点包含在内
	while (p != NULL&&p->next!=NULL) //前判断当前节点p是否有效，后判断节点p的后继是否有效
	{
		p = p->next;
	}
	return p;
}
//指定位置插入数据
int inserNode(Node* L, int pos, ElemType e)
{
	//用来保存插入位置的前驱点
	Node* p = L;
	int i = 0;
	//遍历链表找到插入位置的前驱
	while (i < pos - 1 && p->next!=NULL)
	{
		p = p->next;
		i++;
	}
	if (i != pos - 1) {
		return 0;
	}
	//要插入的新节点
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->next = p->next;
	p->next = q;
	return 1;
}
//删除节点
//找到删除节点的前置节点p
//用指针q记录要删除的节点
//通过改变p的后继节点实现删除
//释放删除节点的空间
int deleteNode(Node* L, int pos) {
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			return 0;
		}
	}
	if (p->next == NULL) {
		printf("删除位置有误\n");
	}
	//q指向要删除的节点
	Node* q = p->next;
	//让要删除节点的前驱指向要删除节点的后继
	p->next = q->next;
	//释放要删除节点的内存空间
	free(q);
	return 1;
}
//获取链表长度(包括头指针)
int ListLength(Node* L) {
	Node* p = L;
	int len = 0;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}
//释放链表(头结点不释放)
void freeList(Node* L) 
{
	Node* p = L->next;
	Node* q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}
//使用双指针找到倒数第k个节点(slow->next代表slow对应数值的下一个数值地址)
int findNodeFS(Node* L, int k) {
	Node* fast = L->next;
	Node* slow = L->next;
	for (int i = 0; i < k; i++) {
		fast = fast->next;
	}
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	printf("倒数第%d个节点的值为%d\n", k, slow->data);
	return 1;
}
//倒置链表
Node* reverseList(Node* head) {
	Node* first = NULL;
	Node* second = head->next;
	Node* third;
	while (second != NULL) {
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}
	Node* hd = initList();
	hd->next = first;
	return hd;
}
//删除中间节点
int delMiddleNode(Node* L) {
	if (L == NULL || L->next == NULL) {
		return 0;
	}
	Node* fast = L->next;
	Node* slow = L;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* q = slow->next;
	slow->next = q->next;
	free(q);
	return 1;
}
//链表重新排序
void reOrderList(Node* head) {
	Node* fast = head->next;
	Node* slow = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* first = NULL;
	Node* second = slow->next;
	slow->next = NULL;
	Node* third = NULL;
	while (second != NULL) {
		third = second->next;
		second->next = first;
		first = second;
		second = third;
	}
	Node* p1 = head->next;
	Node* q1 = first;
	Node* p2;
	Node* q2;
	while (p1 != NULL && q1 != NULL) {
		p2 = p1->next;
		q2 = q1->next;
		p1->next = q1;
		q1->next = p2;
		p1 = p2;
		q1 = q2;

	}

}
int main() {
	Node* List = initList();
	inserHead(List, 10);
	inserHead(List, 20);
	ListNode(List);
	Node* tail = get_tail(List);
	tail = inserTail(tail, 50);
	tail = inserTail(tail, 60);
	tail = inserTail(tail, 70);
	ListNode(List);
	inserNode(List, 2, 15);
	printf("插入数据后的链表为：\n");
	ListNode(List);
	printf("-------------------------------\n");
	/*deleteNode(List, 3);
	printf("删除数据后的链表为：\n");
	ListNode(List);
	printf("-------------------------------\n");
	printf("链表的长度为：");
	printf("%d ", ListLength(List));
	printf("\n");
	printf("-------------------------------\n");
	//freeList(List);
	//printf("%d ", ListLength(List));
	findNodeFS(List,3);
	printf("-------------------------------\n");
	//printf("倒置后的链表为：\n");
	//ListNode(reverseList(List));
	//printf("-------------------------------\n");
	//删除中间节点
	delMiddleNode(List);
	//遍历链表
	printf("删除中间节点后的链表：\n");
	ListNode(List);
	
	printf("-------------------------------\n");*/
	reOrderList(List);
	printf("重新排序后的链表：\n");
	ListNode(List);
	printf("-------------------------------\n");
	return 0;
}