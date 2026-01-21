#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
using namespace std;
void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(3);
	lt.push_back(2);
	lt.push_back(4);
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	//sort(lt.begin(), lt.end());(²»Ö§³Ö)
	string s("dabekdhsa");
	cout << s << endl;
	sort(s.begin(), s.end());
	cout << s << endl;
}

int main()
{
	test_list1();
}