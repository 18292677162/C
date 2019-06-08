#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

// 基类定义了static静态成员，整个继承体系里面只有一个这样的成员
#if 0
class Base
{
public:
	Base()
	{
		++_count;
	}

	Base(const Base& b)
	{
		++_count;
	}

	~Base()
	{
		--_count;
	}
public:
	static int _count;
};

int Base::_count = 0;

class Derived : public Base
{
public:
	Derived()
	{}
};

int main()
{
	cout << Derived::_count << endl;
	cout << &Base::_count << " " << &Derived::_count << endl;
	
	Derived d;
	cout << Derived::_count << endl;
	system("pause");
	return 0;
}
#endif