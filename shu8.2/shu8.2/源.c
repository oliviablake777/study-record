#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!线索二叉树！！！！！！！！！！！！！！！！！！！！！！！
typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode* lchild;
	struct ThreadNode* rchild;
	int ltag;
	int rtag;
}ThreadNode;
typedef ThreadNode* ThreadTree;
char str[] = "ABDH##I##EJ###CF##G##";
int idx = 0;
ThreadTree prev;
//创建树
void creatTree(ThreadTree *T) {
	ElemType ch;
	ch = str[idx++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		//ThreadTree相当于ThreadNode*
		*T = (ThreadTree)malloc(sizeof(ThreadNode));
		(*T)->data = ch;
		creatTree(&(*T)->lchild);
		if ((*T) != NULL) {
			(*T)->ltag = 0;
		}
		creatTree(&(*T)->rchild);
		if ((*T) != NULL) {
			(*T)->rtag = 0;
		}
	}
}
void inOrderThreading(ThreadTree* head, ThreadTree T) {

}
int main() {
	ThreadTree head;
	ThreadTree T;
	//创建
	creatTree(&T);
		//线索化
	inOrderThreading(&head, T);
}
//!!!!!!!!!!!!!!!!!!!!!!二叉树的前中后序遍历！！！！！！！！！！！！！！！！！！！！！！！
/*typedef struct TreeNode {
	ElemType data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;
typedef TreeNode* BiTree;
char str[] = "ABDH#K###E##CFI###G#J##";
int dex = 0;
void creatTree(BiTree* T) {
	ElemType ch;
	ch = str[dex++];
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(TreeNode));
		(*T)->data = ch;
		creatTree(&(*T)->lchild);
		creatTree(&(*T)->rchild);
	}
}
void preOrder(BiTree T) {
	if (T == NULL) {
		return;
	}
	printf("%c ", T->data);
	preOrder(T->lchild);
	preOrder(T->rchild);
}
void inOrder(BiTree T) {
	if (T == NULL) {
		return;
	}
	inOrder(T->lchild);
	printf("%c ", T->data);
	inOrder(T->rchild);
}
void postOrder(BiTree T) {
	if (T == NULL) {
		return;
	}
	postOrder(T->lchild);
	postOrder(T->rchild);
	printf("%c ", T->data);
}
int main() {
	BiTree T;
	creatTree(&T);
	preOrder(T);
	printf("\n");

	inOrder(T);
	printf("\n");

	postOrder(T);
	printf("\n");
}*/
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!层序遍历（二叉树深度）！！！！！！！！！！！！！！！！！！！！！！！！！！！！