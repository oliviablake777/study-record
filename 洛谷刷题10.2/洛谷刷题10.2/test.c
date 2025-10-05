#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int k = 0;
    int sum = 0;
    scanf("%d", &k);
    int i = 0;
    for (i = 1; k >= i; i++)
    {
        k = k - i;
        sum += i*i;
    }
    sum = sum + k * i;
    printf("%d", sum);
    return 0;
}