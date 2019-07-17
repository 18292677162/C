#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <memory>

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
template<class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pCount(nullptr)
	{
		if (_ptr) {
			_pCount = new int(1);
		}
	}

	~SharedPtr()
	{
		if (_ptr&&--(*_pCount)){
			delete _ptr;
			delete _pCount;
		}
	}

	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pCount(sp._pCount)
	{
		++(*_pCount);
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
			if (*_pCount)
				--(*_pCount);
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
	int* _pCount;
};