#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//使用qsort函数排序整形数据
/*int cmp(const void* p1, const void* p2)
{
	
	return (*(int*)p1 - *(int*)p2);
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int l = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, l, sizeof(arr[0]), cmp);
	for (int i = 0; i < l; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}*/
//用qsort排序结构数据
/*struct stu {
	int age;
	char name[20];
};
//按年龄排序
int cmp_age(const void* p1, const void* p2)
{
	return  (((struct stu*)p1)->age - ((struct stu*)p2)->age);
}
//按姓名排序
int cmp_name(const void* p1, const void* p2)
{
	return  strcmp(((struct stu*)p1)->name - ((struct stu*)p2)->name);
}
//按年龄排序
void test1() {
	struct stu s[] = { {12,"zhangsan"},{9,"lisi"},{28,"wangwu"} };
	int l = sizeof(s) / sizeof s[0];
	qsort(s, l, sizeof(s[0]), cmp_age);
}
//按名字排序
void test1() {
	struct stu s[] = { {12,"zhangsan"},{9,"lisi"},{28,"wangwu"} };
	int l = sizeof(s) / sizeof s[0];
	qsort(s, l, sizeof(s[0]), cmp_name);
}
int main()
{
	test1();
	test2();
	return 0;
}*/
//模仿qsort功能实现一个通用的冒泡函数
int int_cmp(const void* p1, const void* p2)
{
	return (*(int *)p1 - *(int *)p2);
}
void _swap(void* p1, void* p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char*)p1+i);
		*((char*)p1+i) = *((char*)p2+i);
		*((char*)p2+i) = tmp;
	}
}
void bubble(void* base, int count, int size, int(*cmp)(void*, void*)) {
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1) * size) > 0) {
				_swap((char*)base + j * size, (char*)base + (j + 1) * size, size);
			}
		}
	}
}
int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;
	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;

}

