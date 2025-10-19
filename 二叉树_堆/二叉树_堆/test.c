#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h";
//对数组进行堆排序
void HeapSort(int* a, int n)
{
	//降序，建小堆
	for (int i = (n - 1 - 1) / 2; i >=0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end >0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
void TestHeap2()
{
	int a[] = { 4,2,8,1,5,6,9,7,2,7,9 };
	HeapSort(a, sizeof(a) / sizeof(int));
}
int main()
{
	/*int a[] = {4,2,8,1,5,6,9,7,3,2,23,55,232,66,222,33,7,1,66,3333,999};
	HP hp;
	HPInit(&hp);
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HPPush(&hp, a[i]);
	}

	int i = 0;
	while (!HPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		//a[i++] = HPTop(&hp);
		HPPop(&hp);
	}
	printf("\n");
	*/
	// 找出最大的前k个
	/*int k = 0;
	scanf("%d", &k);
	while (k--)
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}
	printf("\n");*/
	TestHeap2();

	return 0;
	//HPDestroy(&hp);

}