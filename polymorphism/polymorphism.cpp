#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//	环境	VS2013  x86

//	虚函数 重写
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
重写和重定义区别?
1.重写的函数在基类中一定是虚函?
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

// 重写   重定义
#if 1
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

	virtual ~Base()
	{
		cout << "Base::~Base()" << endl;
	}
};

/*
对基类中虚函数进行重?
重写和重定义区别?
重写?
1.重写的函数在基类中一定是虚函?
2.在派生类中重写基类的虚函数时，两个函数的原型必须完全相同
*/
class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}

	void TestFunc2()  //保持虚函数特性，因为基类中是虚函数
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
		// 返回类型与重写虚函数"Base::TestFunc5" 的返回类值"int" 既不相同，也不协变
		cout << "Derived::TestFunc5()" << endl;
		return 1;
	}
	*/

	virtual Derived* TestFunc6()
	{
		cout << "Derived::TestFunc6()" << endl;
		return this;
	}

	virtual ~Derived()
	{
		cout << "Derived::~Derived()" << endl;
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

	cout << "指向基类指针" << endl;
	Base* pb = new Base;
	delete pb;

	cout << "指向派生类指针 << endl;
	pb = new Derived;
	delete pb;
	system("pause");
	return 0;
}
#endif

// 重写派生类和基类的访问权限可以不同
#if 1
class Base
{
public:
	virtual void TestFunc1() //final
	{
		cout << "Base::TestFunc1()" << endl;
	}
};

class Derived : public Base
{
private:
	virtual void TestFunc1()override	//	override强制重写
	{
		cout << "Derived::TestFunc1()" << endl;
	}
};

void TestVirtual(Base& b)
{
	b.TestFunc1();
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

// 抽象类
#if 1
class WashRoom
{
public:
	void Man()
	{
		cout << "Man" << endl;
	}
	void Woman()
	{
		cout << "Woman" << endl;
	}
};

//	抽象类：包含有纯虚函数的类
//	不能实例化对象
class Person
{
public:
	//	纯虚函数
	virtual void GoToWashRoom(WashRoom& wc) = 0;
};

class Man : public Person
{
public:
	virtual void GoToWashRoom(WashRoom& wc)
	{
		wc.Man();
	}
};

class Woman : public Person
{
public:
	virtual void GoToWashRoom(WashRoom& wc)
	{
		wc.Woman();
	}
};

void TestWC()
{
	Person* p = nullptr;
	WashRoom wc;
	for (size_t i = 0; i < 10; ++i){
		if (rand() % 2 == 0){
			p = new Man;
		}
		else{
			p = new Woman;
		}
		p->GoToWashRoom(wc);
		delete p;
		Sleep(1000);
	}
}

int main()
{
	// Person p;
	Man m;
	TestWC();
	system("pause");
	return 0;
}
#endif

//	虚函数表

/*
1.构造继承方式场景
2.验证对象模型
3.推测虚表中的内容
4.通过打印虚表内容来验证推测结果
*/

/*
什么时候默认构造函数
1.类和对象：A类有缺省构造函?B类中包含了A类的对象
2.继承：基类有缺省构造函数   派生类没有显式定义构造函数
3.虚拟继承：构造函数将指向偏移量表格的虚基表指针前移到对象的前4个字节中
4.
*/
#if 1
class Base1
{
public:
	void TestFunc()
	{
		cout << "Base::TestFunc()" << endl;
	}
	int _b;
};

class Base2
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc()1" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base::TestFunc()2" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc()3" << endl;
	}
	int _b;
};

class Derived : public Base2
{
public:
	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc()4" << endl;
	}
	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc()5" << endl;
	}
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc()1" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc()3" << endl;
	}
public:
	int _d;
};

typedef void(*PVF)();

void PrintVFT(Base2& b, string strInfo)
{
	cout << strInfo << endl;
	// 取对象的前四个字节地址
	PVF* pVF = (PVF*)(*(int*)&b);
	while (*pVF){
		(*pVF)();
		pVF++;
	}
	cout << endl;
}

int main()
{
	// 非静态成员变量+内存对齐
	// 普通	4
	cout << sizeof(Base1) << endl;
	// virtual	8
	cout << sizeof(Base2) << endl;
	Base2 b;
	b._b = 1;
	PrintVFT(b, "Base VFT: ");

	/*
	派生类虚表构建过程
	派生类和基类使用两张不同的虚表
	1.将基类虚表中的内容拷贝一份放到派生类的虚表中
	2.如果派生类重写了基类中的虚函数，用派生类自己
	   的虚函数替换派生类虚表中相同偏移量位置的基类虚函数
	3.派生类对于自己新增加的虚函数将其按照派生类中的声明次序放在虚表最后
	*/
	Derived d;
	d._b = 1;
	cout << sizeof(d) << endl;
	PrintVFT(d, "Derived VFT: ");
	system("pause");
	return 0;
}
#endif

// 虚函数调用
#if 1
class Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc()1" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base::TestFunc()2" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc()3" << endl;
	}
	int _b;
};

class Derived : public Base
{
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc()1" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Derived::TestFunc()3" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc()4" << endl;
	}
	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc()5" << endl;
	}
public:
	int _d;
};

// 编译期间，b按静态类型编译
void TestVirtual(Base& b)
{
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
}

int main()
{
	Base b;
	Derived d;
	TestVirtual(b);
	TestVirtual(d);

	// 调用的是虚函数，因为强转后虽然当成基类对象解析
	// 但是派生类虚表中已经被重写，所以会调用派生类虚函数
	Base* pb = (Base*)&d;
	pb->TestFunc1();

	// 一个类只有一份公共虚表
	// b1, b2虚表地址相同
	Base b1, b2;
	system("pause");
	return 0;
}
#endif

// 包含虚函数的多继承
#if 1
class B1
{
public:
	virtual void TestFunc1()
	{
		cout << "B1::TestFunc1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "B1::TestFunc2()" << endl;
	}
	int _b1;
};

class B2
{
public:
	virtual void TestFunc3()
	{
		cout << "B2::TestFunc3()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "B2::TestFunc4()" << endl;
	}
	int _b2;
};

class D : public B1, public B2
{
public:
	virtual void TestFunc1()
	{
		cout << "D::TestFunc1()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "D::TestFunc4()" << endl;
	}
	virtual void TestFunc5()
	{
		cout << "D::TestFunc5()" << endl;
	}
	int _d;
};

typedef void (*PVFT) ();
// PVFT定义成一个新函数指针类型
//	指针且指向一个返回值void没有参数的函数

void PrintVFT1(B1& b, string str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)*(int*)&b;
	while (*pVFT){
		(*pVFT)();
		pVFT++;
	}
	cout << endl;
}

void PrintVFT2(B2& b, string str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)*(int*)&b;
	while (*pVFT){
		(*pVFT)();
		pVFT++;
	}
	cout << endl;
}

int main()
{
	cout << sizeof(D) << endl;
	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;

	//	派生类新增加的虚函数放到第一张虚表（最靠前的虚表）最后
	//	调用方便
	PrintVFT1(d, "D继承自B1 VTF: ");
	PrintVFT2(d, "D继承自B2 VTF: ");

	B1& b1 = d;
	B2& b2 = d;
	system("pause");
	return 0;
}
#endif

// 包含有虚函数的菱形继承&菱形继承虚拟继承
class B
{
public:
	virtual void TestFunc1()
	{
		cout << "B::TestFunc1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "B::TestFunc2()" << endl;
	}
};

class C1 : public B
{
public:
	virtual void TestFunc1()
	{
		cout << "C1::TestFunc1()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "C1::TestFunc3()" << endl;
	}
	int _c1;
};

class C2 : public B
{
public:
	virtual void TestFunc2()
	{
		cout << "C2::TestFunc2()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "C2::TestFunc4()" << endl;
	}
	int _c2;
};

class D : public C1, public C2
{
public:
	virtual void TestFunc1()
	{
		cout << "D::TestFunc1()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "D::TestFunc3()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "D::TestFunc4()" << endl;
	}
	virtual void TestFunc5()
	{
		cout << "D::TestFunc5()" << endl;
	}
	int _d;
};

typedef void(*PVFT) ();
// PVFT定义成一个新函数指针类型
//	指针且指向一个返回值void没有参数的函数

void PrintVFT(B& b, string str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)*(int*)&b;
	while (*pVFT){
		(*pVFT)();
		pVFT++;
	}
	cout << endl;
}

void PrintVFT_D1(C1& b, string str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)*(int*)&b;
	while (*pVFT){
		(*pVFT)();
		pVFT++;
	}
	cout << endl;
}

void PrintVFT_D2(C2& b, string str)
{
	cout << str << endl;
	PVFT* pVFT = (PVFT*)*(int*)&b;
	while (*pVFT){
		(*pVFT)();
		pVFT++;
	}
	cout << endl;
}

int main()
{
	B b;
	C1 c1;
	c1._c1 = 1;
	C2 c2;
	c2._c2 = 2;
	D d;
	d._d = 3;

	PrintVFT(b, "B VFT: ");
	PrintVFT(c1, "C1 VFT: ");
	PrintVFT(c2, "C2 VFT: ");
	PrintVFT_D1(d, "D_C1 VFT: ");
	PrintVFT_D2(d, "D_C2 VFT: ");
	system("pause");
	return 0;
}