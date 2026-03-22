#define _CRT_SECURE_NO_WARNINGS 1
#include<unordered_set>
#include<set>
#include<unordered_map>
#include<set>
#include<iostream>
using namespace std;
int test_set2()
{
	const size_t N = 1000000;
	unordered_set<int> us;
	set<int> s;
	vector<int> v;
	v.reserve(N);
	srand(time(0));
	for (size_t i = 0; i < N; ++i)
	{
		//v.push_back(rand()); // N⽐较⼤时，重复值⽐较多 
		v.push_back(rand() + i); // 重复值相对少 
		//v.push_back(i); // 没有重复，有序 
	}
	// 21:15
	size_t begin1 = clock();
	for (auto e : v)
	{
		s.insert(e);
	}
	size_t end1 = clock();
	cout << "set insert:" << end1 - begin1 << endl;
	size_t begin2 = clock();
	us.reserve(N);
	for (auto e : v)
	{
		us.insert(e);
	}
	size_t end2 = clock();
	cout << "unordered_set insert:" << end2 - begin2 << endl;
	int m1 = 0;
	size_t begin3 = clock();
	for (auto e : v)
	{
		auto ret = s.find(e);
		if (ret != s.end())
		{
			++m1;
		}
	}
	size_t end3 = clock();
	cout << "set find:" << end3 - begin3 << "->" << m1 << endl;
	int m2 = 0;
	size_t begin4 = clock();
	for (auto e : v)
	{
		auto ret = us.find(e);
		if (ret != us.end())
		{
			++m2;
		}
	}
	size_t end4 = clock();
	cout << "unorered_set find:" << end4 - begin4 << "->" << m2 << endl;
	cout << "插入数据个数：" << s.size() << endl;
	cout << "插入数据个数：" << us.size() << endl << endl;
	size_t begin5 = clock();
	for (auto e : v)
	{
		s.erase(e);
	}
	size_t end5 = clock();
	cout << "set erase:" << end5 - begin5 << endl;
	size_t begin6 = clock();
	for (auto e : v)
	{
		us.erase(e);
	}
	size_t end6 = clock();
	cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
	return 0;
  }
void test_set3()
{
	unordered_set<string> us;
	us.insert("apple");
	us.insert("apple");
	int a = us.size();
	int b = us.count("apple");
	int c = us.count("abc");
	us.insert({ "banhe","abc","water" });
	for (auto e : us)
	{
		cout << e << endl;
	}

	cout << a << b << c << endl;
	auto atm = us.find("abc");
	if (atm != us.end())
		cout << *atm << endl;
	us.erase(atm, us.end());
	for (auto e : us)
	{
		cout << " " << e;
	}
}
void test_map1()
{
	vector<string> words = { "apple", "banana", "apple", "cherry", "banana", "apple" };
	unordered_map<string, int> um;
	for (auto e : words)
	{
		um[e]++;
	}
	for (auto m : um)
	{
		cout << m.first <<":" << m.second<<" ";
	}
	cout << endl;
	um.erase("banana");
	for (auto m : um)
	{
		cout << m.first << ":" << m.second << " ";
	}
}
#include"HashTable.h"
struct Date
{
	int _year;
	int _month;
	int _day;

	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
};

struct DateHashFunc
{
	size_t operator()(const Date& d)
	{
		size_t hash = 0;
		hash += d._year;
		hash *= 131;

		hash += d._month;
		hash *= 131;

		hash += d._day;
		hash *= 131;

		return hash;
	}
};
#include"UnorderedMap.h"
#include"UnorderedSet.h"
int main()
{
	bit::test_set1();
	bit::test_map1();

	return 0;
}