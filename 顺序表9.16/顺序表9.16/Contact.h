#pragma once
//定义联系人数据 结构
//姓名 性别 年龄 电话 地址
#define NAME_MAX 20
#define GENDER_MAX 10 
#define TEL_MAX 20
#define ADDR_MAX 100
typedef struct personInfo {
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char add[ADDR_MAX];
}perInfo;

typedef struct SeqList Contact;
//通讯录的初始化
void ContactInit(Contact* con);
//通讯录的销毁
void ContactDesTroy(Contact* con);
//通讯录添加数据
void ContactAdd(Contact* con);
//通讯录删除数据
void ContactDel(Contact* con);
//通讯录的修改
void ContactModify(Contact* con);
//通讯录查找
void ContactFind(Contact* con);
//展示通讯录数据
void ContactShow(Contact* con);

