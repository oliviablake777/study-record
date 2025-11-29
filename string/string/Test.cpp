#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class string
//{
//private:
//	char _buff[16];
//	char*  _str;
//
//	size_t _size;
//	size_t _capacity;
//}；

//void test_string1()
//{
//	string s1;
//	string s2("hello world");
//	cout << s1 << s2 << endl;
//	s2[0] = 'x';
//	cout << s1 << s2 << endl;
//	//1.下标+[]
//	for (size_t i = 0; i < s2.size(); i++)
//	{
//		cout << s2[i] << " ";
//	}
//	cout << endl;
//	//2.迭代器
//	string::iterator it = s2.begin();
//	while (it != s2.end())
//	{
//		*it += 2;
//		cout << *it <<" ";
//		++it;
//	}
//	cout << endl;
	/*list<int> lt = { 1,2,3,4,5,6,7 };
	list<int>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;*/
	//3.字符赋值，自动迭代，自动判断结束
	//// 底层就是迭代器
	//for (auto ch : s2)
//	for(auto& ch:s2)
//	{
//		ch -= 2;
//		cout << ch << " ";
//	}
//	cout << endl;
//	cout << s2 << endl;
//}
//void test_string2()
//{
//	string s2("hello world");
//	string::iterator it = s2.begin();
//	while (it != s2.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	//反向迭代器
//	string::reverse_iterator rit = s2.rbegin();
//	while (rit != s2.rend())
//	{
//		//*rit+=2;
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	const string s3("hello world");
//	//string::const_iterator cit = s3.begin();
//	auto cit = s3.begin();
//	while (cit != s3.end())
//	{
//		//*cit += 2;
//		cout << *cit << " ";
//		++cit;
//	}
//	cout << endl;
//
//	//string::const_reverse_iterator rcit = s3.rbegin();
//	auto rcit = s3.rbegin();
//	while (rcit != s3.rend())
//	{
//		// *rcit += 2;
//		cout << *rcit << " ";
//		++rcit;
//	}
//	cout << endl;
//}
//void TestPushBack()
//{
//	// reverse 反转  逆置
//	// reserve 保留、预留
//	string s;
//	// 提前开空间，避免扩容，提高效率
//	s.reserve(100);
//	size_t sz = s.capacity();
//	cout << "capacity changed: " << sz << '\n';
//
//	cout << "making s grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}
//void test_string3()
//{
//	string s2("hello world");
//	cout << s2.length() << endl;
//	cout << s2.size() << endl;
//
//	cout << s2.max_size() << endl;
//
//	cout << s2.capacity() << endl;
//	TestPushBack();
//
//	string s3("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
//	//cout << sizeof(s2) << endl;
//	//cout << sizeof(s3) << endl;//这俩个结果一样
//}
//void test_string4()
//{
//	string s2("hello worldxxxxxxxxxxxxx");
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl << endl;
//
//	s2.reserve(20);
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl << endl;
//
//	s2.reserve(28);
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl << endl;
//
//	s2.reserve(40);
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl << endl;
//
//	s2.clear();
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl << endl;
//
//	cout << typeid(string::iterator).name() << endl;
//	cout << typeid(string::reverse_iterator).name() << endl;
//
//}
//int main()
//{
//	test_string4();
//	return 0;
//}
//int main()
//{
//	test_string1();
//	return 0;
//}
//int func1()
//{
//	return 10;
//}
//不能做参数
//void func2(auto a)
//{}
//auto可以做返回值，谨慎使用
//auto func3()
//{
//	return 3;
//}
//int main()
//{
	//int a = 10;
	//auto b = a;
	//auto c = 'a';
	//auto d = func1();
	// 编译报错:rror C3531: “e”: 类型包含“auto”的符号必须具有初始值设定项
	//auto e;
	//auto不能定义数组

	/*cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;*/
	//范围for适用于容器和数组
	//auto array[] = { 4, 5, 6 };

	//auto ret = func3();

	//int array[] = { 1, 2, 3, 4, 5 };
	//// C++98的遍历
	//for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
	//{
	//	array[i] *= 2;
	//}
	//for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
	//{
	//	cout << array[i] << endl;
	//}
	//
	//// yyds
	//// 范围for适用于容器 和 数组
	//// C++11的遍历
	//for (auto& e : array)
	//	e *= 2;

	//for (auto e : array)
	//	cout << e << " " << endl;
	//return 0;
//}
#include"Date.h"

void TestDate1()
{
	Date d1(2024, 7, 12);
	Date d2 = d1 + 100;
	//Date d3(d1 + 100);
	d1.Print();
	d2.Print();

	//d1 += 100;
	//d1.Print();

	d1 += 30000;
	d1.Print();
}

void TestDate2()
{
	/*Date d1(2024, 7, 13);
	d1 -= 30000;
	d1.Print();*/

	Date d1(2024, 7, 13);
	Date ret1 = d1++;
	ret1.Print();
	d1.Print();

	Date d2(2024, 7, 13);
	Date ret2 = ++d2;
	ret2.Print();
	d2.Print();
}

void TestDate3()
{
	Date d1(2024, 7, 12);
	d1 += -100;
	d1.Print();

	d1 -= -100;
	d1.Print();
}

void TestDate4()
{
	Date d1(2034, 10, 1);
	Date d2(2024, 6, 31);

	cout << d1 - d2 << endl;
}

void TestDate5()
{
	Date d1, d2;
	cin >> d1 >> d2;
	cout << d1 << d2;

	cout << d1 - d2 << endl;

	//cout << d1;
	//operator<<(cout, d1);

	//cout << d1 << d2;

	// 倒反天罡
	//d1 << cout;
	//d1.operator<<(cout);
}

void TestDate6()
{
	const Date d1(2024, 7, 13);
	d1.Print();

	Date d2(2024, 7, 13);
	d2.Print();

	cout << &d1 << endl;
	cout << &d2 << endl;
}

//int main()
//{
//	TestDate1();
//
//	return 0;
//}
//#include<iostream>
//using namespace std;
class A
{
public:
	//explicit A(int a = 0)
	A(int a = 0)
	{
		_a1 = a;
	}

	A(const A& aa)
	{
		_a1 = aa._a1;
	}

	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{
	}

	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a1;
	int _a2;
};

class Stack
{
public:
	void Push(const A& aa)
	{
		//...
	}
private:
	A _arr[10];
	int _top;
};

int main()
{
	A aa1(1);
	aa1.Print();

	// 隐式类型转换
	// 2构造一个A的临时对象，再用这个临时对象拷贝构造aa2
	// 编译器遇到连续构造+拷贝构造->优化为直接构造
	A aa2 = 2;
	aa2.Print();

	A& raa1 = aa2;
	const A& raa2 = 2;

	int i = 1;
	double d = i;
	const double& rd = i;

	Stack st;

	A aa3(3);
	st.Push(aa3);

	st.Push(3);

	// C++11
	A aa5 = { 1, 1 };
	const A& raa6 = { 2,2 };
	st.Push(aa5);
	st.Push({ 2,2 });

	return 0;
}

