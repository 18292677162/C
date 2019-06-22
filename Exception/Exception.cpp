#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

// GetLastError()
#if 0
int main()
{
	FILE* pf = fopen("1.txt", "r");
	if (nullptr == pf){
		int err = GetLastError();
		cout << err << endl;
		return 0;
	}

	fclose(pf);
	system("pause");
	return 0;
}
#endif

// longjmp();	goto L; L:
#if 0
jmp_buf buff;

void TestFunc1()
{
	FILE* pf = fopen("1.txt", "r");
	if (nullptr == pf){
		// longjmp();
		// goto
	http://www.baidu.com;
		longjmp(buff, 1);
	}

	fclose(pf);
}

void TestFunc2()
{
	int* p = (int*)malloc(sizeof(int)* 0xffffffff);
	if (nullptr == p){
		longjmp(buff, 2);
		// ...
	}
	free(p);
}

int main()
{
	//	设置程序的跳转点，初始赋值为0
	int state = setjmp(buff);
	if (0 == state){
		TestFunc1();
		TestFunc2();
	}
	else{
		switch (state){
		case 1:
			cout << "打开文件失败" << endl;
			break;
		case 2:
			cout << "malloc申请空间失败" << endl;
			break;
		default:
			cout << "未知错误" << endl;
		}
	}
	system("pause");
	return 0;
}
#endif

// C++异常
#if 0
void TestFunc1()
{
	FILE* pf = fopen("1.txt", "r");
	if (nullptr == pf){
		throw 1;
	}
	// ...
	fclose(pf);
}

void TestFunc2()
{
	int* p = 0;
	if (nullptr == p){
		throw 'A';
	}
	free(p);
}

int main()
{
	try
	{
		TestFunc1();
		TestFunc2();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	catch (char err)
	{
		cout << err << endl;
	}
	system("pause");
	return 0;
}
#endif

// 抛出异常会生成一个异常对象的拷贝
#if 0
class Exception
{
public:
	Exception()
	{
		cout << "Eeception()" << this << endl;
	}
	Exception(const Exception& e)
	{
		cout << "Exception(const Exception&)" << this << endl;
	}
	~Exception()
	{
		cout << "~Eeception()" << this << endl;
	}
};

void TestFunc()
{
	Exception e;
	throw e;
}

int main()
{
	try
	{
		TestFunc();
	}
	catch (const Exception& e)
	{
		cout << &e << endl;
	}
	system("pause");
	return 0;
}
#endif

// ... 万能捕获
#if 0
void TestFunc2()
{
	int* p = 0;
	if (nullptr == p){
		throw 1;
	}
}

void TestFunc1()
{
	try
	{
		// 假设TestFunc1是第三方库函数--可能会抛出异常
		TestFunc2();
	}
	catch (...)	// 可以捕获任意类型异常
	{
		throw;	// 重新抛出异常
	}
}

int main()
{
	try
	{
		TestFunc1();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	system("pause");
	return 0;
}
#endif

// 基类对象的引用捕捉派生类对象
// 指针捕捉数组
#if 0
class Exception
{};

class DBException : public Exception
{};

void TestFunc()
{
	// 基类对象被派生类捕获
	DBException db;
	// throw db;

	// 数组 以指针捕获
	int array[10];
	throw array;
}

int main()
{
	try
	{
		TestFunc();
	}
	catch (const Exception& e)
	{
		cout << &e << endl;
	}
	catch (int *p)
	{
		cout << "array" << endl;
	}
	system("pause");
	return 0;
}
#endif

#if 0
void TestFunc()throw(int)
{
	throw 1;
}

int main()
{
	return 0;
}
#endif

// 异常的继承体系结构
class  Exception
{
public:
	Exception(int errID, const string& errInfo)throw()
		: _errID(errID)
		, _ErrInfo(errInfo)
	{}

	virtual void What()const = 0;

protected:
	int _errID;
	string _ErrInfo;
};

// 网络异常
class NetException : public Exception
{
public:
	NetException(int errID, const string& errInfo)
		: Exception(errID, errInfo)
	{}

	virtual void What()const
	{
		cout << _errID << "--->" << _ErrInfo << endl;
	}
};

//	数据库异常
class DBException : public Exception
{
public:
	DBException(int errID, const string& errInfo)
		: Exception(errID, errInfo)
	{}

	virtual void What()const
	{
		cout << _errID << "--->" << _ErrInfo << endl;
	}
};

void TestFunc1()
{
	NetException e(305, "网络错误");
	throw e;
}

void TestFunc2()
{
	DBException e(405, "数据库错误");
	throw e;
}

int main()
{
	try
	{
		vector<int> v(10, 5);
		v.reserve(1000000000);
		TestFunc1();
		TestFunc2();
	}
	// 自定义的异常
	catch (const Exception& e)
	{
		e.What();
	}
	// 标准库异常，捕获所有异常的父类exception即可
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	// 其他库异常
	catch (...)
	{
		cout << "未知异常" << endl;
	}
	system("pause");
	return 0;
}