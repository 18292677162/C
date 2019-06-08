#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//拷贝运算符重载
#if 0
class Base
{
public:
	/*
	//不给缺省值，编译器不知道传什么值，报错
	Base(int b = 1)
		:_b(b)
	{}
	*/
	Base(int b)
		:_b(b)
	{}

	Base(const Base& b)
		: _b(b._b)
	{}

	Base& operator=(const Base& b)
	{
		cout << "Base::operator=()" << endl;
		if (this != &b){
			_b = b._b;
		}
		return *this;
	}

protected:
	int _b;
};

class Derived : public Base
{
public:
	/*
	Derived()
		: Base()
	{}
	*/
	Derived(int b,int d)
		: Base(b)
		, _d(d)
	{}

	Derived(const Derived& d)
		: Base(d._b)
		, _d(d._d)
	{}

	Derived& operator=(const Derived& d)
	{
		cout << "Derived::operator=()" << endl;
		if (this != &d){
			// 没有调用基类赋值运算符重载函数，被隐藏了
			//所以需要显示调用基类的赋值运算符重载
			Base::operator=(d);
			_d = d._d;
		}
		return *this;
	}

private:
	int _d;
};

int main()
{
	Derived d1(10, 20);
	Derived d2(d1);
	d2 = d1;
	system("pause");
	return 0;
}
#endif

//析构函数
#if 0
class Base
{
public:
	Base()
	{
		cout << "Base::Base()" << endl;
	}

	~Base()
	{
		cout << "Base::Base()" << endl;
	}
};

class Derived : public Base
{
public:
	Derived()
		: Base()
	{
		cout << "Derived::Derived()" << endl;
	}

	~Derived()
	{
		cout << "Derived::Derived()" << endl;
		//  在派生类析构函数最后一条语句后增加了调用基类析构函数的语句
		//call ~Base();
	}
};

void TestFunc()
{
	Derived d;  //创建派生类对象，调用派生类的构造函数
}

int main()
{
	TestFunc();
	system("pause");
	return 0;
}
#endif