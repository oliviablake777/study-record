#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while(end>=0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}
//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j],&a[j + 1]);
			}
		}
	}
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//向下调整建堆
	for (int i = (n-1-1)/2; i >=0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while(end>=0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}

}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin+1; i <=end; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}
		Swap(&a[begin], &a[min]);
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}
void ShellSort(int* a, int n)
{
	int gap = n;
	while(gap>1)
	{
		gap = gap / 3 + 1;
		for (int j = 0; j < n - gap; j += gap)
		{
			int end = j;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int begin = left;
	int end = right;
	int keyi = begin;
	while (begin < end)
	{
		//右边向左找小
		while (begin < end&&a[end]>=a[keyi])
		{
			end--;
		}
		//左边向右找大
		while (begin < end && a[begin]<=a[keyi])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[keyi], &a[begin]);
	keyi = begin;
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}
int GetMid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if(a[right]>a[left])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else//a[left]>a[mid]
	{
		if (a[left] < a[right])
		{
			return left;
		}
		else if (a[right] > a[mid])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
}
int PastSort1(int* a, int left, int right)
{
	// 三数取中
	int midi = GetMid(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	int begin = left, end = right;
	while (begin < end)
	{
		// 右边找小
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}

		// 左边找大
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[keyi], &a[begin]);
	return begin;
}
//指针法
int PastSort2(int* a, int left, int right)
{
	// 三数取中
		int mid = GetMid(a, left, right);
	    Swap(&a[left], &a[mid]);
		int keyi = left;
		int prev = left;
		int cur = prev + 1;
		while (cur <= right)
		{
			if (a[cur] < a[keyi] && ++prev != cur)
			{
				Swap(&a[prev], &a[cur]);
			}
			cur++;
		}
		Swap(&a[prev], &a[keyi]);
		return prev;
}
//快排
void QuickSort2(int* a,int left,int right)
{
	if (left >= right)
	{
		return;
	}
	int keyi = PastSort2(a, left, right);
	QuickSort2(a, left, keyi - 1);
	QuickSort2(a, keyi + 1, right);
}
#include"Stack.h"
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);
	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);
		int keyi = PastSort1(a, begin, end);
		if (keyi + 1 < end)
		{
			STPush(&st,end);
			STPush(&st, keyi+1);
		}
		if (begin < keyi - 1)
		{
			STPush(&st, keyi-1);
			STPush(&st, begin);
		}
		STDestroy(&st);
	}
}
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	_MergeSort(a, tmp, begin,mid);
	_MergeSort(a, tmp,mid+1,end);
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <=a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
		while (begin1 <= end1)
		{
			tmp[i++] = a[begin1++];
		}
		while (begin2 <= end2)
		{
			tmp[i++] = a[begin2++];
		}
	}
	memcpy(a + begin, tmp + begin, (end - begin + 1)*sizeof(int));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
	tmp=NULL;
}
//非递归
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			if (begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
				while (begin1 <= end1)
				{
					tmp[j++] = a[begin1++];
				}
				while (begin2 <= end2)
				{
					tmp[j++] = a[begin2++];
				}
			}
			memcpy(a + i, tmp + i,sizeof(int)*(end2-i+1));

		}
		printf("\n");
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}
void CountSort(int* a, int n)
{
	int max=a[0], min=a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("calloc fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		count[a[i]-min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = min + i;
		}
	}
	free(count);
}














