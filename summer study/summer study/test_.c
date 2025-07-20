#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include<assert.h>
/*int main()
{
	//printf("hello summer");
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i = 0;
	int* p = &arr[0];
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++) {
		printf("%d", *(p + i));
	}
	return 0;
}

int my_strlen(char *s)
{
	char* p = s;
	while (*p != '\0')
		p++;
	return p - s;
}

int main()
{
	printf("%d\n", my_strlen("abc"));
	return 0;
}

int my_strlen(const char* str)
{
	int count = 0;
	assert(str);
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	int len = my_strlen("abcddrgh");
	printf("%d", len);
	return 0;
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("&arr[0] = %p\n", &arr[0]);
	printf("arr = %p\n", arr);
	printf("&arr[0] = %p\n", &arr[0]);
	printf("&arr[0]+1 = %p\n", &arr[0] + 1);
	printf("arr = %p\n", arr);
	printf("arr+1 = %p\n", arr + 1);
	printf("&arr = %p\n", &arr);
	printf("&arr+1 = %p\n", &arr + 1);
	return 0;
}

int main()
{
	int arr[10] = { 0 };
		 //输? 
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//输? 
	int* p = arr;
	for (i = 0; i < sz; i++)
	{
		scanf_s("%d", p + i);
		//scanf("%d", arr+i);//也可以这样写 
	}
	//输出 
	for (i = 0; i < sz; i++)
	{
		//printf("%d ", *(p + i));
		printf("%d ", p[i]);
	}
	return 0;
}

void test(int arr[])
{
	int sz2 = sizeof(arr) / sizeof(arr[0]);
	printf("sz2 = %d\n", sz2);
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz1 = sizeof(arr) / sizeof(arr[0]);
	printf("sz1 = %d\n", sz1);
	test(arr);
	return 0;
}

void test(int arr[])//参数写成数组形式，本质上还是指针 
{
	printf("%d\n", sizeof(arr));
}
void test_(int* arr)//参数写成指针形式 
{
	printf("%d\n", sizeof(arr));//计算?个指针变量的?? 
}
//函数参数中的int arr[]等价于int* arr,退化为指针后，sizeof(arr)计算的是指针大小（在64位系统下为8）
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	test(arr);
	test_(arr);
	return 0;
}

//冒泡法(改良版)
void maopao(int arr[], int sz)
{
	int i = 0;
for( i=0;i<sz-1;i++)
{
	int flag = 1;
	int j = 0;
	for ( j = 0; j < sz-i-1; j++)
	{
		if (arr[j] > arr[j + 1])
		{
			flag = 0;
			int tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
		}
	}
	if (flag==1) 
		break;
	
}
}
int main()
{
	int arr[] = {3,2,5,6,7,8,4,1,9,0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	maopao(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;

}*/

/*void bubble_sort(int arr[], int sz)//参数接收数组元素个数 
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = { 3,1,7,5,8,9,0,2,4,6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}


int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 6,7,8,9,10 };
	int arr3[] = { 5,4,3,2,1 };
	int* app[3] = { arr1,arr2,arr3 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", app[i][j]);
		}
		printf("\n");
	}
	return 0;
}*/

/*int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	//数组名是数组?元素的地址，类型是int*的，就可以存放在parr数组中 
	int* parr[3] = { arr1, arr2, arr3 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", parr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void test(int (*p)[5], int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6},{3,4,5,6,7} };
	test(arr, 3, 5);
	return 0;

}

int add(int x, int y)
{
	return x + y;
}
int main()
{
	int (*pf1)(int, int) = add;
	int (*pf3)(int, int) = &add;
	printf("%d ", (*pf1)(1, 2));
	printf("%d ", pf3(1, 5));
	return 0;
}*/

int main() {
	printf("test");
}



