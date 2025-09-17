#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"SeqList.h"
//通讯录的初始化
void ContactInit(Contact* con)
{
	SLInit(con);
}
//通讯录的销毁
void ContactDesTroy(Contact* con)
{
	SLDestroy(con);
}
//通讯录添加数据
void ContactAdd(Contact* con)
{
	perInfo info;
	printf("请输入要添加的联系人姓名：\n");
	scanf("%s", info.name);
	printf("请输入要添加的联系人性别：\n");
	scanf("%s", info.gender);
	printf("请输入要添加的联系人年龄：\n");
	scanf("%d", &info.age);
	printf("请输入要添加的联系人电话：\n");
	scanf("%s", info.tel);
	printf("请输入要添加的联系人地址：\n");
	scanf("%s", info.add);
	SLPushBack(con, info);

}
int FindByName(Contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (0 == strcmp(con->arr[i], name)) {
			return i;
		}
	}
	return -1;
}
//通讯录删除数据
void ContactDel(Contact* con)
{
	printf("请输入想删除人的姓名：");
		char n[NAME_MAX];
	scanf("%s", n);
	//检查数据是否存在i
	int find = FindByName(con, n);
	if (find < 0) {
		printf("要删除的联系人不存在\n");
	}
	SLErase(con, find);
	printf("删除成功\n");
}
//通讯录的修改
void ContactModify(Contact* con)
{
	printf("请输入你想修改人的姓名\n");
	char n[NAME_MAX];
	scanf("%s", n);
	int find = FindByName(con, n);
	if (find < 0)
	{
		printf("你想要修改的人不存在！\n");
		return;
	}
	printf("请输入新的名字\n");
	scanf("%s", con->arr[find].name);
	printf("请输入新的性别\n");
	scanf("%s", con->arr[find].gender);
	printf("请输入新的年龄\n");
	scanf("%d", &con->arr[find].age);
	printf("请输入新的电话\n");
	scanf("%s", con->arr[find].tel);
	printf("请输入新的地址\n");
	scanf("%s", con->arr[find].add);
	printf("修改成功\n");
}

//通讯录查找
void ContactFind(Contact* con)
{
	printf("请输入你要查找的联系人姓名\n");
	char n[NAME_MAX];
	scanf("%s", n);
	int find = FindByName(con, n);
	if (find < 0)
	{
		printf("你想要查找的联系人不存在！\n");
		return;
	}
	printf("姓名 性别 年龄 电话 地址\n");
		printf("%3s %4s %4d %4s %4s\n", con->arr[find].name, con->arr[find].gender, con->arr[find].age,
			con->arr[find].tel, con->arr[find].add);
}
//展示通讯录数据
void ContactShow(Contact* con) {
	//表头：姓名性别年龄电话地址
	printf("姓名 性别 年龄 电话 地址\n");
	for (int i = 0; i < con->size; i++)
	{
		printf("%3s %4s %4d %4s %4s\n", con->arr[i].name, con->arr[i].gender, con->arr[i].age,
			con->arr[i].tel, con->arr[i].add);
	}
}