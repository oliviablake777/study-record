#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
void TestInsertSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestBubbleSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestHeapSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestSelectSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestShellSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestQuickSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	QuickSort(a,0,sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestGetMid()
{
	int a[] = { 9,1,2,5,7,4,6,3,8 };
	GetMid(a, 0, 8);
}
void TestQuickSort2()
{
	int a[] = { 9,1,2,5,7,4,6,3,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	QuickSort2(a,0, sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestMergeSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	MergeSort(a,sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestCountSort()
{
	int a[] = { 9,1,2,5,7,4,6,3,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
void TestMergeSortNonR()
{
	int a[] = { 9,1,2,5,7,4,6,3,8 };
	PrintArray(a, sizeof(a) / sizeof(int));
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
int main()
{
	//int a[] = { 9,1,2,5,7,4,6,3,8 };
	
	//printf("%d", GetMid(a, 0, 8));
	//TestQuickSort2();
	//TestCountSort();
	TestMergeSortNonR();
	return 0;
}