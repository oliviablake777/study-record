#define _CRT_SECURE_NO_WARNINGS 1
#include"BTree.h"
#include"Queue.h"
void TestHeap3()
{
	int k;
	printf("请输入k>:");
	scanf("%d", &k);
	int* kminheap = (int*)malloc(sizeof(int) * k);
	if (kminheap == NULL)
	{
		perror("malloc fail");
		return;
	}
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	// 读取文件中前k个数
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &kminheap[i]);
	}

	// 建K个数的小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kminheap, k, i);
	}

	// 读取剩下的N-K个数
	int x = 0;
	while (fscanf(fout, "%d", &x) > 0)
	{
		if (x > kminheap[0])
		{
			kminheap[0] = x;
			AdjustDown(kminheap, k, 0);
		}
	}

	printf("最大前%d个数：", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", kminheap[i]);
	}
	printf("\n");
}
int main()
{
    // 用前序遍历数组创建二叉树
   /* char arr[] = "ABD##E##CF##G##";
    int i = 0;
    BTNode* root = BinaryTreeCreate(arr, &i);

    printf("二叉树节点个数: %d\n", BinaryTreeSize(root));
    printf("二叉树叶子节点个数: %d\n", BinaryTreeLeafSize(root));
    printf("第3层节点个数: %d\n", BinaryTreeLevelKSize(root, 3));

    BTNode* find = BinaryTreeFind(root, 'E');
    if (find)
        printf("找到了节点 E\n");
    else
        printf("未找到节点 E\n");

    printf("前序遍历: ");
    BinaryTreePrevOrder(root);
    printf("\n中序遍历: ");
    BinaryTreeInOrder(root);
    printf("\n后序遍历: ");
    BinaryTreePostOrder(root);
    printf("\n层序遍历: ");
    BinaryTreeLevelOrder(root);
    printf("\n");

    bool complete = BinaryTreeComplete(root);
    printf("该二叉树是否为完全二叉树: %s\n", complete ? "true" : "false");

    BinaryTreeDestory(root);
    return 0;
    */
}