#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<algorithm>
int bitSum(int n)//返回n这个数每一位上的平方和
{
	int sum = 0;
	while (n)
	{
		int t = n % 10;
		sum += t * t;
		n/= 10;
	}
	return sum;
}
int main()
{
	//判断链表是否有环->快慢双指针
	int n;
	cin >> n;
	int slow = n, fast = bitSum(n);
	while (slow != fast)
	{
		slow = bitSum(slow);
		fast = bitSum(bitSum(fast));
	}
	bool flag = slow == 1 ? true : false;
	cout << boolalpha << flag << endl;
	return 0;
}