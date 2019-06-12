#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

#if 1
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
#endif

class Base
{
public:
	// 只能修饰类的成员函数为虚函数
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}

	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}

	void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}

	virtual void TestFunc4(int)
	{
		cout << "Base::TestFunc4()" << endl;
	}

	virtual int TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
		return 1;
	}

	virtual Base* TestFunc6()
	{
		cout << "Derived::TestFunc6()" << endl;
		return this;
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
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	void TestFunc2()  //也为虚函数，保持虚函数特性，因为基类中是虚函数
	{
		cout << "Derived::TestFunc2()" << endl;
	}

	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc3()" << endl;
	}

	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}

	/*
	virtual void TestFunc5()
	{
		// 返回类型与重写虚拟函数 "Base::TestFunc5" 的返回类型 "int" 既不相同，也不协变
		cout << "Derived::TestFunc5()" << endl;
		return 1;
	}
	*/

	virtual Derived* TestFunc6()
	{
		cout << "Derived::TestFunc6()" << endl;
		return this;
	}
};

void TestVirtual(Base& b)
{
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();	//不派生
	b.TestFunc4(10);	//不派生
	b.TestFunc6();
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