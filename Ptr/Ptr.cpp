#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <memory>
#include <assert.h>
#include <mutex>
#include <thread>

// 原子变量类
#include <atomic>

using namespace std;

// Autoptr
#if 0
// RAII + operator*() + operator->()
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	~SmartPtr()
	{
		if (_ptr) {
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator*() {
		return *_ptr;
	}

	T* operator->() {
		return _ptr;
	}

private:
	T* _ptr;
};

void TestFunc()
{
	int* p = new int;
	*p = 100;
	SmartPtr<int> sp(p);
	*sp = 200;
}

int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
// auto_ptr
// RAII + operator*() + operator->() + 资源转移
template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _owner(false)
	{
		if (_ptr)
			_owner = true;
	}

	// 资源转移
	AutoPtr(AutoPtr<T>& ap)
		: _ptr(ap._ptr)
		, _owner(ap._owner)
	{
		ap._owner = false;
	}

	// 资源转移
	AutoPtr<T>& operator=(const AutoPtr<T>& ap)
	{
		// 判断是否自己赋值
		if (this != &ap)
		{
			// 当前对象若管理资源 释放资源
			if (_ptr && _owner){
				delete _ptr;
				_owner = false;
				_ptr = nullptr;
			}
			// 资源转移
			_ptr = ap._ptr;
			_owner = ap._owner;
			ap._owner = false;
		}
		return *this;
	}

	~AutoPtr()
	{ 
		if (_ptr && _owner){
			delete _ptr;
			_owner = false;
			_ptr = nullptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
	mutable bool _owner;
};

void TestFunc()
{
	AutoPtr<int> ap1(new int);
	AutoPtr<int> ap2(ap1);

	if (true){
		// 资源释放权限从ap2全部转移到ap4，出作用域资源释放，产生野指针程序崩溃
		AutoPtr<int> ap4(ap2);
	}

	*ap1 = 10;
	*ap2 = 20;
}

int main()
{
	TestFunc();
	return 0;
}
#endif

// unique_ptr
//RAII + operator*() / operator->() + 防止被拷贝
//缺陷：多个对象之间不能共享资源
#if 0
template<class T>
class UniquePtr
{
public:
	UniquePtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	~UniquePtr()
	{
		if (_ptr){
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	// 防止被拷贝
	// C++ 98 拷贝构造函数、赋值运算符只声明不定义
	/*
private:
	UniquePtr(const UniquePtr<T>& up);
	UniquePtr<T>& operator=(const UniquePtr<T> &);
	*/

	// C++11 默认成员函数后=delete	相当于删掉该成员函数
private:
	UniquePtr(const UniquePtr<T>& up) = delete;
	UniquePtr<T>& operator=(const UniquePtr<T> &) = delete;

private:
	T* _ptr;
};

int main()
{
	UniquePtr<int> up1(new int);

	unique_ptr<int> up2(new int);
	// unique_ptr<int> up3(up2);  尝试引用已经删除的函数
	return 0;
}
#endif

//共享类型的智能指针
//RAII + operator*() / operator->() + 引用计数
//SharedPtr
#if 0
template<class T>
struct DFDef
{
	void operator()(T*& pf)
	{
		delete pf;
		pf = nullptr;
	}
};

template<class T>
struct Free
{
	void operator()(T*& p)
	{
		free(p);
		p = nullptr;
	}
};

struct FClose
{
	void operator()(FILE* pf)
	{
		fclose(pf);
		pf = nullptr;
	}
};

template<class T, class DF = DFDef<T>>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pCount(new int(1))
		, _pMutex(new mutex)
	{
		if (_ptr==nullptr) {
			*_pCount = 0;
		}
	}

	~SharedPtr()
	{
		Release();
	}

	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pCount(sp._pCount)
		, _pMutex(sp._pMutex)
	{
		if (_pCount)
			AddRef();
	}

	//sp2 = sp1   sp2与自己资源脱离关系，与sp1共享资源
	//		1.sp2没有管理资源
	//		2.sp2管理资源但没有与其他对象共享		----	 释放sp2的资源以及计数
	//		3.sp2管理资源，与其他对象共享资源		----	 sp2引用计数-1
	
	//	sp1   没有资源
	// sp2   拥有资源
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		if (this != &sp) {
			Release();

			_ptr = sp._ptr;
			_pCount = sp._pCount;
			if (_pCount)
				AddRef();
		}
		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	int GetUse()
	{
		assert(_pCount);
		return *_pCount;
	}

private:
	void Release()
	{
		if (_ptr && 0 == SubRef()){
			// delete _ptr;		无法确定要释放的资源类型
			// 利用仿函数来确定资源类型
			// 仿函数麻烦 C++11 lambda 表达式
			DF()(_ptr);
			delete _pCount;
		}
	}

	// 加锁保证引用计数的安全
	// 但是share_ptr不能保证数据的安全
	void AddRef()
	{
		_pMutex->lock();
		++(*_pCount);
		_pMutex->unlock();
	}

	int SubRef()
	{
		_pMutex->lock();
		--(*_pCount);
		_pMutex->unlock();
		return *_pCount;
	}

private:
	T* _ptr;
	int* _pCount;
	mutex* _pMutex;

	// atomic_long _i;	 ++_i;   C++11 使用原子变量 atomic 减少加锁方法的开销
};

void TestSharePtr1()
{
	SharedPtr<int> sp1(new int);
	SharedPtr<int> sp2(sp1);

	SharedPtr<int> sp3(new int);
	SharedPtr<int> sp4(sp3);

	sp4 = sp2;
	sp3 = sp2;
}

void TestSharePtr2()
{
	FILE* pf = fopen("1.txt", "w");

	SharedPtr<FILE, FClose> sp1(pf);
	SharedPtr<int, Free<int>> sp2((int*)malloc(sizeof(int)));
	SharedPtr<int> sp3(new int);
}

class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	int _year;
	int _month;
	int _day;
};

void ThreadFunc(SharedPtr<Date>& sp, size_t n)
{
	for (size_t i = 0; i < n; ++i) {
		SharedPtr<Date> copy(sp);
		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}

void TestSharePtr3()
{
	SharedPtr<Date> sp(new Date(0, 0, 0));
	thread t1(ThreadFunc, sp, 10000);
	thread t2(ThreadFunc, sp, 10000);

	t1.join();
	t2.join();
}

int main()
{
	TestSharePtr1();
	TestSharePtr2();
	
	TestSharePtr3();
	// 采用加锁的方式也有缺点，会增加程序时间和空间的开销
	return 0;
}
#endif

// 程序内资源确定只需1个对象来管理 unique_ptr
// 程序内对象需要共享资源 share_ptr

// share_ptr 缺陷：循环引用
struct ListNode
{
	ListNode(int data = 0)
		: _data(data) 
//	    : _pPre(nullptr)
// , _pNext(nullptr)
// , _data(data)
	{
		cout << "ListNode(int):" << this << endl;
	}

	~ListNode()
	{
		cout << "~ListNode():" << this << endl;
	}
	// shared_ptr<ListNode> _pPre;
	// shared_ptr<ListNode> _pNext;
	weak_ptr<ListNode> _pPre;
	weak_ptr<ListNode> _pNext;
	int _data;
};

void TestSharePtr()
{
	shared_ptr<ListNode> p1(new ListNode(10));
	shared_ptr<ListNode> p2(new ListNode(20));

	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;

	p1->_pNext = p2;
	p2->_pPre = p1;

	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;
}

int main()
{
	TestSharePtr();
	// 析构函数没有调用，内存泄漏
	system("pause");
	return 0;
}
