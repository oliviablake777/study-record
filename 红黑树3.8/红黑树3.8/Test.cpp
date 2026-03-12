#define _CRT_SECURE_NO_WARNINGS 1

//#include"RBTree.h"
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
//	RBTree<int, int> t;
//	// 常规的测试用例
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	// 特殊的带有双旋场景的测试用例
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//
//	for (auto e : a)
//	{
//		t.Insert({ e, e });
//	}
//
//	t.InOrder();
//	cout << t.IsBalance() << endl;
//}
//
//int main()
//{
//	TestRBTree1();
//
//	return 0;
//}
#include"Myset.h"
#include"Mymap.h"


void Print(const bit::set<int>& s)
{
	bit::set<int>::const_iterator it = s.end();
	while (it != s.begin())
	{
		--it;
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	bit::set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(6);

	bit::set<int>::iterator sit = s.begin();
	//*sit += 10;
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	Print(s);


	bit::map<string, string> dict;
	dict.insert({ "sort", "排序" });
	dict.insert({ "left", "左边" });
	dict.insert({ "right", "右边" });

	dict["left"] = "左边，剩余";
	dict["insert"] = "插入";
	dict["string"];

	bit::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// 不能修改first，可以修改second
		//it->first += 'x';
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	return 0;
}
