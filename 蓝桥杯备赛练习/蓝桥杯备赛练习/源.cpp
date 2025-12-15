#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cmath>
//using namespace std;
//int l, r;
//bool pfs(int x)
//{
//
//    if (x == 0)return false;
//    return (int)sqrt(x) == sqrt(x);
//}
//int main() {
//    cin >> l >> r;
//    for (int i = l; i <= r; i++)
//    {
//        if (pfs(i))
//        {
//            int k = 10;
//            while (k <= i * 10)
//            {
//                int x = i % k;
//                int y = i / k;
//                k *= 10;
//                if (pfs(x) && pfs(y)) {
//                    cout << i << endl;
//                    break;
//                }
//            }
//        }
//    }
//    
//    return 0;
//}
//µ¯ÖéÓÎÏ·
/*#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%d", &num);
		int a[1000] = { 0 };
		int b[1000] = { 0 };
		int sigle = 0;
		int sample = 0;
		int res = 0;
		int max = 0;
		for (int i = 0; i < num; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int m = 0; m < num; m++)
		{
			b[a[m]]++;
			if (a[m] > max)
				max = a[m];
		}
		for (int j = 0; j <= max; j++)
		{
			if (b[j] == 1)
				sigle++;
			if (b[j] != 0)
				sample++;
		}
		res = ((sigle + 1) / 2)*2 + (sample-sigle);
		printf("%d ", res);
	}

	return 0;
}*/

//#include<stdio.h>
//int main()
//{
//	int n;
//	int m;
//	int r[1000011];
//	int right = 0;
//	int flag = 0;
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <=n; i++)
//	{
//		scanf("%d", &r[i]);
//	}
//	int mark = 0;
//	while (m--)
//	{
//		mark++;
//		int day, s, t;
//		scanf("%d %d %d", &day, &s, &t);
//		for (int i = s; i <= t; i++)
//		{
//			if (r[i]<day)
//			{
//				right = -1;
//				flag = mark;
//				break;
//			}
//			else
//			{
//				r[i] -= day;
//			}
//		}
//		if (right == -1)
//		{
//			break;
//		}
//	}
//	printf("%d\n", right);
//	if (right == -1)
//	{
//		printf("%d\n", flag);
//	}
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	int num = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int flag = 1;
//		int x = i;
//		while (x)
//		{
//			if ((x % 10) % 2 == 0 || (x / 10) % 2 != 0)
//				flag = 0;
//			x = x / 100;
//		}
//		if (flag)
//			num++;
//	}
//	cout << num << endl;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	string s, t;
//	cin >> s >> t;
//	int lens = s.size();
//	int lent = t.size();
//	int min = lent;
//	for (int i = 0; i < lent; i++)
//	{
//		for (int j = 0; j < lens; j++)
//		{
//			if (s[j] == t[i])
//			{
//				int num = i;
//				int lefts = j;
//				int leftt = i;
//				while (leftt < 5)
//				{
//					if (s[lefts++] != t[leftt++])
//						num++;
//				}
//				if (num < min)
//					min = num;
//			}
//
//		}
//	}
//	cout << min;
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;

string work(string s, int l)
{
	string s2(l,' ');
	s2[0] = s[0];
	for (int i = 1; i < l; i++)
	{
		if (s[i - 1] == s[i])
			s2[i] ='0'+0;
		else
			s2[i] ='0'+1;
	}
	return s2;
}
int main()
{
	string s1;
	int n;
	long long t;
	cin >> n >> t;
	cin >> s1;
	while (t--)
	{
		s1 = work(s1, n);
	}
	cout << s1 << endl;
	return 0;
}
//enen