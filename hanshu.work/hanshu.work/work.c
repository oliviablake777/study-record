#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
int get_num(int num,int n)
{
	int sum = 0;
	int a = 1;
	for (int i = 0; i < n; i++)
	{
		sum = sum + num * a;
		a = a * 10;
	}
	return sum;
}
int main()
{
	int a;
	int add = 0;
	printf("请输入a的值");
	scanf("%d", &a);
	for (int i = 1; i <=5; i++)
	{
		add = add + get_num(a, i);
	}
	printf("%d", add);
	return 0;
}

//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数”。
/*int qrt(num, n) {
	int s = num;
	if (n < 2) {
		return num;
	}
	for (int i = 0; i < n-1; i++) {
		num = num * s;
	}
	return num;
}
int get_n(num)
{
	int n = 0;
	while (num > 0)
	{
		num = num / 10;
		n++;
	}
	return n;
}
int main()
{
	for (int i = 153; i < 100000; i++)
	{
		int n = 0;
		int sum = 0;
		int a = 0;
		int b = i;
		n = get_n(b);
		while (b > 0)
		{
			a = b % 10;
		    b = b / 10;
			sum = sum + qrt(a, n);
		}
		if (sum == i) 
		{
			printf("%d ", i);
		}
	}
	return 0;
}*/
//打印菱形
/*int main()
{
	for (int i = 0; i < 13; i++)
	{
		int n = (12 - 2 * i) / 2;
		if (n < 0) {
			n = -n;
		}
		int m = 13 - 2*n;
		for (int j = 0; j < n; j++)
		{
			printf("  ");
		}
		while (m > 0)
		{
			printf("* ");
			m--;
		}
		for (int k = 0; k < n; k++)
		{
			printf("  ");
		}
		printf("\n");
	}
}*/
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水
//int main()
//{
//	int money = 20;
//	int num1 = money / 1;
//	int num2 = num1 / 2;
//	printf("可以喝%d瓶汽水\n", num1 + num2);
//	return 0;
//}
//创建一个整形数组，完成对数组的操作
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。
/*void init(int arr[10])
{
	for (int i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
}
void reverse(int arr[10])
	{
		for (int i = 0; i < 5; i++)
		{
			int tmp = arr[i];
			arr[i] = arr[9 - i];
			arr[9 - i] = tmp;
		}
	}
int main()
{
	int arr[10] = {0};
	init(arr);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	//重新初始化数组
	printf("请重新初始化数组：\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	reverse(arr);
	printf("倒置后的数组是：\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}*/
	

//实现一个函数is_prime，判断一个数是不是素数。
//利用上面实现的is_prime函数，打印100到200之间的素数。
/*void is_prime(int num)
{
	int flat = 1;
	for (int i = 2; i < num; i++)
	{
		if (num%i ==0)
		{
			flat = 0;
			break;
		}
	}
	if (flat)
	{
		printf("%d ",num);
	}
}
int main()
{
	for (int i = 100; i <= 200; i++)
	{
		is_prime(i);
	}
	

	return 0;

}*/

//函数判断闰年
/*void abc(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		printf("%d年是闰年\n", year);
	}
	else
	{
		printf("%d年不是闰年\n", year);
	}
}
int main() 
{
	int year = 0;
	printf("请输入要判断的年份：");
	scanf("%d", &year);
	abc(year);
	return 0;
}*/
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
/*void creat(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <=i; j++)
		{
			printf("%d*%d=%d ", i, j, i * j);
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	printf("请输入口诀表的行列");
	scanf("%d", &n);
	creat(n);
	return 0;
}*/