#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//基类  父类
class Base
{
public:
	void SetBase(int pri, int pro, int pub)
	{
		_priB = pri;
		_proB = pro;
		_pubB = pub;
	}

	void Print()
	{
		cout << "_priB = " << _priB << endl;
		cout << "_pro B = " << _proB << endl;
		cout << "_pubB = " << _pubB << endl;
	}
private:
	int _priB;
protected:
	int _proB;
public:
	int _pubB;
};

//公有继承
/*
继承方式：共有
基类中成员(成员变量&成员函数)已经被继承到派生类
基类中成员变量权限在派生类中权限没有改变
基类中私有的成员变量在派生类中不可访问--->不可见
*/
#if 0
//子类  派生类
class Derived : public Base
{
public:
	void SetDerived(int pri, int pro, int pub)
	{
		SetDerived(pri, pro, pub);
		_pubB = pub;
		_proB = pro;
		// 私有成员变量派生类里不可访问
		//_priB = pri;
	}
};

//验证派生类中成员变量是保护还是私有：在继承一次看子类能不能访问
class C : public Derived
{
public:
	void TestFunc()
	{
		_pubB = 10;
		_proB = 20;
		//_pri = 30;
	}
};

int main()
{
	// 派生类的大小12+基类大小12
	cout << sizeof(Derived) << endl;
	// 基类中的成员变量、成员函数已经被继承
	Derived d;
	d.SetBase(1, 2, 3);
	d.Print();
	d._pubB = 10;
	// 保护不可访问
	// d._proB = 20;
	system("pause");
	return 0;
}
#endif

//保护继承方式
/*
继承方式：保护
基类中成员(成员变量&成员函数)已经被继承到派生类
基类中public成员变量在子类中变成protected 不能直接访问
基类中protected成员变量子类依旧是protected
基类中private的成员变量在派生类中不可访问--->不可见
*/
#if 0 
class Derived : protected Base
{
public:
	void SetDerived(int pri, int pro, int pub)
	{
		SetDerived(pri, pro, pub);
		_pubB = pub;
		_proB = pro;
		// 私有成员变量派生类里不可访问
		//_priB = pri;
	}
};

//验证派生类中成员变量是保护还是私有：在继承一次看子类能不能访问
class C : public Derived
{
public:
	void TestFunc()
	{
		_pubB = 10;
		_proB = 20;
		//_pri = 30;
	}
};

int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	//d._pubB = 10;
	//d.SetBase(10, 20, 30);
	system("pause");
	return 0;
}
#endif

//私有继承方式
/*
继承方式：私有
基类中成员(成员变量&成员函数)已经被继承到派生类
基类中public成员变量在子类中变成private 不能直接访问
基类中protected成员变量子类中变成是private
基类中private的成员变量在派生类中不可访问--->不可见
*/
#if 1
class Derived : private Base
{
public:
	void SetDerived(int pri, int pro, int pub)
	{
		SetDerived(pri, pro, pub);
		_pubB = pub;
		_proB = pro;
		// 私有成员变量派生类里不可访问
		//_priB = pri;
	}
};

//验证派生类中成员变量是保护还是私有：在继承一次看子类能不能访问
class C : public Derived
{
public:
	void TestFunc()
	{
		//_pubB = 10;
		//_proB = 20;
		//_pri = 30;
	}
};

int main()
{
	cout << sizeof(Derived) << endl;
	Derived d;
	//d._pubB = 10;
	//d.SetBase(10, 20, 30);
	system("pause");
	return 0;
}
#endif