#include<stdio.h>
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
}*/
int my_strlen(char *s)
{
	 char *p = s;
	 while (*p != '\0')
	 p++;
	 return p - s;
	}

int main()
{
	 printf("%d\n", my_strlen("abc"));
		 return 0;
	}