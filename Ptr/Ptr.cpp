#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

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

// auto_ptr
// RAII + operator*() + operator->() + 资源转移

template<class T>
class AutoPtr
{
public:
	AutoPtr(T* ptr = nullptr)
		: _ptr(ptr)
	{}

	// 资源转移
	AutoPtr(AutoPtr<T>& ap)
		: _ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}

	// 资源转移
	AutoPtr<T>& operator=(AutoPtr<T>& sp)
	{
		// 判断是否自己赋值
		if (this != &sp)
		{
			// 当前对象若管理资源 释放资源
			if (_ptr)
				delete _ptr;
			// 资源转移
			_ptr = sp._ptr;
			sp._ptr = nullptr;
		}
		return *this;
	}

	~AutoPtr()
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

private:
	T* _ptr;
};

void TestFunc()
{
	AutoPtr<int> sp1(new int);
	*sp1 = 1;

	AutoPtr<int> sp2(sp1);
}

int main()
{
	TestFunc();
	return 0;
}