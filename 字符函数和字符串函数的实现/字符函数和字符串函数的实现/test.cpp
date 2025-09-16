#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
#include<assert.h>
#include<string.h>
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
//模拟实现strncpy
/*char* my_strncpy(char* dest, char* scr, size_t num)
{
	assert(dest != NULL);
	assert(scr != NULL);
	char* ret = (char *)dest;
	while (num --!= 0)
	{
		if (!*scr) 
		{
			*dest = 48;
		}
		else {
			*dest++ = *scr++;
		}
	}
	return ret;
}
int main()
{
	char str1[] = "abcdef";
	char str2[] = "bcd";
	char* p = my_strncpy(str1, str2, 4);
	printf("%s",p);
}*/
//模拟实现strcat
 /*char* my_strcat(char* dest, char* scr)
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
}*/
//模拟实现strncat
/*char* my_strncat(char* dest, char* scr, size_t num)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(scr != NULL);
	while (*dest)
	{
		dest++;
	}
	while (num-- != 0)
	{
		if (!*scr) {
			*dest++ = *scr++;
			num = 0;
		}
		*dest++ = *scr++;
	}
	*dest++ = 0;
	return ret;
}
int main()
{
	char str1[20] = "abcdef";
	char str2[20] = "bcd";
	char* p = my_strncat(str1, str2, 5);
	printf("%s", p);
}*/
//模拟实现strcmp
/*int my_strcmp(const char* str1, const char* str2)
{
	int ret = 0;
		assert(str1!=NULL);
		assert(str2 != NULL);
		while (*str1 == *str2) {
			if (*str1 == '\n')
				return 0;
			str1++;
			str2++;
		}
		return *str1 - *str2;

}*/
/*int main()
{
	char str[] = "This is a simple string";
	char* p;
	p = strstr(str, "simple");
	strncpy(p, "simple", 6);
	printf("%s\n", p);
	return 0;
}*/
//模拟实现strstr
/*char* my_strstr(const void* str1, const char* str2)
{
	char* cp = (char *)str1;
	char* s1;
	char* s2;
	if (!*str2)
		return((char*)str1);
	while (*cp) {
		s1 = cp;
		s2 = (char*)str2;
		while (*s1 && *s2 && *s1 == *s2) {
			s1++;
			s2++;
		}
		if (!*str2)
			return (cp);
		cp++;
	}
	return(NULL);
}*/
/*int main()
{
	char arr[] = "192.168.6.111";
	char* sep = ".";
	char* str = NULL;
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	{
		printf("%s\n", str);
	}
	return 0;
}*/
//模拟实现memcpy
/*void* my_memcpy(void* dest, const void* scr, size_t num)
{
	void* ret = dest;
	assert(dest);
	assert(scr);
	while(num--){
		*(char*)dest = *(char*)scr;
		dest = (char*)dest + 1;
		scr = (char*)scr + 1;
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };
	my_memcpy(arr2, arr1, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}*/
//模拟实现memmove
/*void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest && src);
	void* ret = dest;
		if (dest < src) {
			//前->后
			while (count--)
			{
				*((char*)dest) = *((char*)src);
				dest = (char*)dest + 1;
				src = (char*)src + 1;
			}
		}
		else {
			while (count--) {
				*((char*)dest + count) = *((char*)src + count);
			}
		}
		return ret;
}*/

#include <stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;
	char* pc = &a;
	return 0;
}







