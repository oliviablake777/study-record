#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Date
{
public:
	// 1.无参构造函数
	/*Date()
	{
	_year = 1;
	_month = 1;
    _day = 1;
    }*/
	
	// 2.带参构造函数
	/*Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/

	// 3.全缺省构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1();
	d1.Print();
	//
	//Date d2(2024, 7, 10);
	//d2.Print();


	//Date func();
	//func.Print();

	return 0;
}
