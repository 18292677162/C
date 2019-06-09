#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

class Base
{
public:
	// 只能修饰类的成员函数为虚函数
	virtual void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}
};

/*
对基类中虚函数进行重写
重写和重定义区别？
重写：
	1.重写的函数在基类中一定是虚函数
	2.在派生类中重写基类的虚函数时，两个函数的原型必须完全相同
*/
class Derived : public Base
{
public:
	virtual void TestFunc()
	{
		cout << "Derived::TestFunc()" << endl;
	}
};

// 多态：同一个事物，在不同场景下表现出不同的形态
void TestVirtual(Base& b)
{
	// 编译阶段，编译器不能确定具体调用哪个类的虚函数
	// 只有在代码运行阶段才能确定到底该调用哪个类的虚函数
	b.TestFunc();
}

int main()
{
	Base b;
	Derived d;
	TestVirtual(b);
	TestVirtual(d);
	system("pause");
	return 0;
}