#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

#if 0
class Base
{
	friend void TestFunc();
protected:
	int _b;
};

class Derived : public Base
{
protected:
	int _d;
};

void TestFunc()
{
	Base b;
	b._b = 10;

	Derived d;
	  // d._d = 10;
}

int main()
{
	system("pause");
	return 0;
}
#endif