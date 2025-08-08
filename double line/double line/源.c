#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node* prev, * next;
}Node;
//初始化链表
Node* initList()
{
	Node * head = (Node*)malloc(sizeof(Node));
head->data = 0;
head->next = NULL;
head->prev = NULL;
return head;
}
//头插法
int inserHead(Node* L, ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->prev = L;
	p->next = L->next;
	if (L->next != NULL) {
		L->next->prev = p;
	}
	L->next = p;
	return 1;
}
//遍历
void listNode(Node* L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//获取尾节点
Node* get_tail(Node* L) {
	Node* p = L->next;
	while (p != NULL && p->next != NULL) {
		p = p->next;
	}
	return p;
}
//尾插法
Node * inserTail(Node* tail,ElemType e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->prev = tail;
	tail->next = p;
	p->next=NULL;
	return p;
}
//在指定位置插入数据
int inserNode(Node* L, int pos, ElemType e) {
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			return 0;
		}
	}
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = e;
	q->prev = p;
	q->next = p->next;
	q->next->prev = q;
	p->next = q;
	return 1;

}
//删除节点
int delteNode(Node* L,int pos) {
	Node* p = L;
	int i = 0;
	while (i < pos - 1) {
		p = p->next;
		i++;
		if (p == NULL) {
			return 0;
		}
	}//找到删除节点的前置节点p
	Node* q = p->next;//q为删除节点
	p->next = q->next;
	q->next->prev = p;
	free(q);
	return 1;
}
int main() {
	Node* list = initList();
	inserHead(list, 10);
	inserHead(list, 20);
	inserHead(list, 30);
	printf("头插法插入数据后:\n");
	listNode(list);
	Node* tail = get_tail(list);
	tail=inserTail(tail, 40);
	tail = inserTail(tail, 50);
	tail = inserTail(tail, 60);
	printf("尾插法插入数据后:\n");
	listNode(list);
	inserNode(list, 3, 55);
	printf("指定位置插入数据后:\n");
	listNode(list);
	delteNode(list, 5);
	printf("删除指定位置插入数据后:\n");
	listNode(list);
	return 0;
}