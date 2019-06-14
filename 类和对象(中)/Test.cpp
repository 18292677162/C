#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month; 
	int _day;
}; 

int main()
{
	Data d1, d2;
	d1.SetDate(2019, 1, 21);
	d1.Display();
	d2.SetDate(2019, 1, 24);
	d2.Display();
	system("pause");
	return 0;
}
#endif

#if 0
//类中没有显式定义构造函数，编译器生成无参默认构造函数，打印为随机值
class Date
{
public:
	/*
	// 如果用户显式定义了构造函数，编译器将不再生成
	Date (int year, int month, int day)
	{
	_year = year;
	_month = month;
	_day = day;
	}
	*/
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	// 没有定义构造函数，对象也可以创建成功，因此此处调用的是编译器生成的默认构造函数
	Date d;
	d.Display();
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:
	//1.无参构造函数
	Date()
	{}
	//2.带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;		//调用无参构造函数
	Date d2(2018, 1, 1);		 //调用带参构造函数
	d1.Display();
	d2.Display();
	
	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
	Date d3();

	system("pause");
	return 0;
}
#endif

#if 0
// 默认构造函数
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
// 以下测试函数能通过编译吗？
void Test()
{
	Date d1;
	//“Date::Date”: 对重载函数的调用不明确
	//“Date”: 指定了多个默认构造函数	
}
#endif

#if 1

#endif