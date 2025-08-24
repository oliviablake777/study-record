#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//找凶手
int main()
{
	int killer = 0;
	//分别假设凶手是a,b,c,d,看谁是凶手时满足3个人说了真话，一个人说了假话
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
			printf("凶手是：%c", killer);
	}
	return 0;
}
/*int main()
{
	int n =0;
	//初始化三角形
	int arr[10][10] = { 0 };
	//填充三角形
	for (int i = 0; i < 10; i++)
	{
		arr[i][0] = 1;
		for (int j = 1; j <=i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j]!=0) {
				printf("%d ", arr[i][j]);
			}
			
		}
		printf("\n");
	}

	return 0;
}*/
/*int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	int a = 0;
	int find = 4;
	int result = 0;
	printf("请输入你要查找的数字:");
	scanf("%d", &a);
	for (int i = 0; i < 5; i++)
	{
		if (arr[0][i] == a)
		{
			result = 1;
		}
		if (arr[0][i] > a) 
		{
			find = i - 1;
			break;
		}
	}
	if (find < 0) {
		printf("没有该数字\n");
	}
	for (int j = 0; j < 3; j++)
	{
		if (arr[j][find] == a)
		{
			result = 1;
		}
	
	}
	if (result) {
		printf("该数字存在\n");
	}else
	{
		printf("没有该数字\n");
	}
}*/
//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
/*int Fun(char arr[])
{
	int j=0;
	int len = strlen(arr);
	int tmp = arr[0];
	for ( j = 0; j < len - 1; j++) //单次平移
	{
		arr[j] = arr[j + 1];
	}
	arr[j] = tmp;
	return arr;
}
int main()
{
	char arr1[100];
	char arr2[100];
	gets(arr1);
	gets(arr2);
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	int same = 0;
	if (len1 == len2) 
	{
		for (int i = 0; i < len1 - 1; i++) {
			Fun(arr2);
			int a=strcmp(arr1, arr2);
			if (!a) {
				same = 1;
				break;
			}
				
		}
	}
	else {
		printf("0");

	}
	if (same) {
		printf("1");
	}

	return 0;
}*/
//冒泡排序
/*int main()
{
	int arr[] = { 1,5,2,7,9,6,4,2,5,8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	int* p = arr;
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *p);
		p++;
	}
}*/
//用指针打印数组
/*int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	for (int i = 0; i < size; i++)
	{
		printf("%d ", *p);
		p++;
	}
	return 0;
}*/
//调整奇数偶数顺序
/*void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void adjust(int arr[],int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		while (left < right && arr[left] % 2 != 0) {
			left++;
		}
		while (left < right && arr[right] % 2 == 0) {
			right--;
		}
		if (left < right) {
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
}
int main()
{
	//int arr[] = { 2,4,5,77,88,66,34,56,17,14 };
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int n = sizeof(arr) / sizeof(arr[0]);
	adjust(arr, n);
	printf("调整后的数组：");
		for (int i = 0; i < 10; i++)
		{
			printf("%d ",arr[i]);
		}
	return 0;
}*/
//模拟实现库函数strlen
/*int strlen(char arr[])
{
	int count = 0;
	char* p = arr;
	while (*p != '\0') {
		p++;
		count++;
	}
	return count;
}
int main()
{
	char arr[100];
	gets(arr);
	printf("%d", strlen(arr));
	return 0;
}*/
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
/*int Fun(char arr[], int k) {
	char* p = arr + k;
	while (*p != '\0')
	{
		printf("%c", *p);
		p++;
	}
	for (int i = 0; i < k; i++)
	{
		printf("%c", arr[i]);
	}
}
int main()
{
	char arr[100];
	gets(arr);
	Fun(arr, 1);
	return 0;
}*/
/*int main() {
	char arr[10000];
	gets(arr);
	char* p = arr;
	while (*p != '\0')
	{
		p++;
	}
	p--;
	while (p >= arr) {
		printf("%c", *p);
		p--;
	}

	return 0;
}*/
//打印整数二进制的奇数位和偶数位
/*void Printf(int n, int num)
{
	if (num ==1)
	{
		num = 31;
		printf("奇数位：");

	}
	else {
		num = 30;
		printf("偶数位：");
	}
	for (int i = num; i>=0; i-=2)
	{
		if (n & (1 << i))
		{
			printf("1 ");
		}
		else
		{
			printf("0 ");
		}
	}
	printf("\n");
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	Printf(a, 1);
	Printf(a, 2);
	return 0;
}*/

//在一个整型数组中，只有一个数字出现一次，其他数组都是成对出现的，请找出那个只出现一次的数字。
/*int find(int arr[], int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		result ^= arr[i];
	}
	return result;
}
int main()
{
	int arr[] = { 1,2,2,3,3,4,5,6,5,4,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = find(arr, size);
	printf("%d", ret);
	return 0;
}*/
/*int i;
int main()
{
	i--;
	if (i > sizeof(i))
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	return 0;
}
//写一个函数返回参数二进制中 1 的个数。
int main()
{

	int num = 0;
	scanf("%d", &num);
	int count = 0;
	while (num)
	{
		num = num & (num - 1);
		count++;
	}
	/*for (int i = 0; i < 32; i++)
	{
		if (num & 1 << i)
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;
}*/
//交换俩个变量
/*int main()
{
	int a = 3;
	int b = 5;
	a= a + b;
	b= a-b;
	a=a-b;
	printf("%d %d", a, b);
	return 0;
}*/
//打印一个数的每一位
/*void Fun(int n)
{
	if (n == 0) {
		return 0;
	}
	int a = n / 10;
	int b = n % 10;
	Fun(a);
	printf("%d ", b);
	
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	Fun(n);
	return 0;
}*/
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
//递归
/*int Fun(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * Fun(n - 1);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fun(n);
	printf("%d", ret);
	return 0;
}*/
//计算一个数的每位之和（递归实现）
/*int Fun(int n)
{
	if (n == 0) {
		return 0;
	}
	int a = n / 10;
	int b = n % 10;
	int sum = b + Fun(a);
	return sum;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fun(n);
	printf("%d", ret);
	return 0;
}*/
//递归实现n的k次方
/*int Fun(int a, int b)
{
	if (b==0) 
	{
		return 1;
	}else
	return a * Fun(a, b- 1);
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n,&k);
	int ret = Fun(n, k);
	printf("%d", ret);
	return 0;
}*/