#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"
#include"Queue.h"
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		*pi++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*pi++];
	root->_left = BinaryTreeCreate(a,pi);
	root->_right = BinaryTreeCreate(a,pi);
	return root;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_right) + BinaryTreeLeafSize(root->_left);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (--k == 0)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left,k) + BinaryTreeLevelKSize(root->_right,k);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data)
	{
		return root;
	}
	BTNode* left = BinaryTreeFind(root->_left,x);
	BTNode* right = BinaryTreeFind(root->_right, x);
	if (left != NULL)
	{
		return left;

	}
	if (right != NULL)
	{
		return right;
	}
	return NULL;
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePrevOrder(root->_left);
	printf("%d", root->_data);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%d", root->_data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{

}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{

}
