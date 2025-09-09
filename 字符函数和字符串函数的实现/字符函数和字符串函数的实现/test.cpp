#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
#include<assert.h>
//模拟实现strlen
//1.计数器方式
/*int my_strlen(const char* str)
{
	int count = 0;
	assert(str);
	while (*str) {
		count++;
		str++;
	}
	return count++;
}
//不能创建临时变量计数器
int my_strlen(const char* str) {
	assert(str);
	if (*str == '\0') {
		return 0;
	}
	else
	{
		return 1 + my_strlen(str + 1);
	}
}
//指针-指针的方式
int my_strlen(char* s) {
	assert(s);
	char* p = s;
	while (p != '\0') {
		p++;
	}
	return p - s;
}*/
//模拟实现strcpy
/*char* my_strcpy(char* dest, char* scr)
{
	assert(dest != NULL);
	assert(scr != NULL);
	char* ret = dest;
	while ((*dest++ = *scr++))
	{
	;
	}
	return ret;
}*/
//模拟实现strcat
 char* my_strcat(char* dest, char* scr)
{
	 char* ret = dest;
	 assert(dest != NULL);
	 assert(scr != NULL);
	 while (*dest)
	 {
		 dest++;
	 }
	 while (*dest++ = *scr++) 
	 {
		 ;
	 }
	 return ret;
}