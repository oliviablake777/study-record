#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<algorithm>
int main() {
    int n, m;
    cin >> n >> m;
    int a[201][201];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int maxSum = INT_MIN;

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            int sum = a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1] + a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2];
            if (sum > maxSum) maxSum = sum;
        }
    }

    cout << maxSum << endl;
    return 0;
}

//bool isLucky(int x) {
//    int bits[32];
//    int len = 0;
//
//    while (x > 0) {
//        bits[len++] = x & 1;
//        x >>= 1;
//    }
//
//    if (len == 1) return false;
//
//    for (int i = 0; i < len; i++) {
//        bool ok = false;
//
//        if (i > 0 && bits[i] == bits[i - 1]) ok = true;
//
//        if (i < len - 1 && bits[i] == bits[i + 1]) ok = true;
//
//        if (!ok) return false;
//    }
//
//    return true;
//}
//int main() {
//    int a, b;
//    cin >> a >> b;
//
//    int count = 0;
//    for (int i = a; i <= b; i++) {
//        if (isLucky(i)) {
//            count++;
//        }
//    }
//
//    cout << count;
//    return 0;
//}


//int bitSum(int n)//返回n这个数每一位上的平方和
//{
//	int sum = 0;
//	while (n)
//	{
//		int t = n % 10;
//		sum += t * t;
//		n/= 10;
//	}
//	return sum;
//}
//int main()
//{
//	//判断链表是否有环->快慢双指针
//	int n;
//	cin >> n;
//	int slow = n, fast = bitSum(n);
//	while (slow != fast)
//	{
//		slow = bitSum(slow);
//		fast = bitSum(bitSum(fast));
//	}
//	bool flag = slow == 1 ? true : false;
//	cout << boolalpha << flag << endl;
//	return 0;
//}
