#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;
// 继承方式
//1.单继承

// 2.多继承
#if 1
class B1
{
public:
	int _b1;
};

class B2
{
public:
	int _b2;
};

class D : public B2, public B1
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	system("pause");
	return 0;
}
#endif

// 3.菱形继承
#if 1
class B
{
public:
	int _b;
};

class C1 : public B
{
public:
	int _c1;
};

class C2 : public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;
	D d;
	// 菱形继承的二义性
	//d._b = 1;
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;
	
	d._d = 5;
	system("pause");
	return 0;
}
#endif

// 虚拟继承
#if 1
class B
{
public:
	int _b;
};

// 虚拟继承
/*
虚拟继承和单继承的区别？
编译器给虚拟继承的类生成了一个默认的构造函数，有两个参数：1，对象空间的地址
将偏移量表格的地址放到对象的前4个字节中
参数1：用来区分是普通继承还是虚拟继承
1和0比较--->相等--->跳过：给对象前4个字节赋值 语句
				  不相等--->不会跳过
*/

class D : virtual public B
{
public:
	int _d;
};


int main()
{
	cout << sizeof(D) << endl;
	D d;
	d._b = 1;
	d._d = 2;
	system("pause");
	return 0;
}

#endif

//菱形虚拟继承: 解决菱形虚拟二义性
#if 1
class B
{
public:
	void TestFunc()
	{}
public:
	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};

class C2 : virtual public B
{
public:
	int _c2;
};

class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;
	D d;
	d._b = 1;
	d._c1 = 2;
	d._c2 = 3;
	d._d = 4;

	C1& c1 = d;
	C2& c2 = d;

	c1._b = 1;
	c2._b = 2;

	cout << c1._b << endl;

	d.TestFunc();
	system("pause");
	return 0;
}
#endif