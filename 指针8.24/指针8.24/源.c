#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//找单身狗
void findDog(int arr[])
{
	int ret = 0;
	int a[2] = { 0 };
	for (int i = 0; i < 10; i++) {
		ret = arr[i];
		for (int j = 0; j < 10; j++) {
			ret = ret ^ arr[j];
		}
		for (int m = 0; m < 10; m++)
		{
			if (ret == arr[m])
				a[0] = ret;
			    a[1] = arr[i];
		}
		
	}
	printf("%d %d", a[0], a[1]);
}
int main()
{
	int arr[10] = { 1,2,3,4,5,1,2,3,4,6 };
	findDog(arr);
	return 0;
}
/*int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main() {
	int x, y;
	int input = 0;
	int ret = 0;
	int (*p[5])(int x, int y) = { 0,Add,Sub,Mul,Div };
	do {
		printf("*************************\n");
		printf(" 1:add 2:sub \n");
		printf(" 3:mul 4:div \n");
		printf(" 0:exit \n");
		printf("*************************\n");
		printf("请选择：");
		scanf("%d", &input);
		if (input >= 0 && input <= 4) {
			printf("请输入俩个数字：\n");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
			printf("ret=%d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出游戏成功\n");
			break;
		}
		else {
			printf("输入错误，请重新输入\n");
		}
	} while (input);
	return 0;
}*/