#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
//只在栈上创建，就是不能在堆上创建
class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}

	StackOnly()
	{
		cout << "call construct function" << endl;
	}

	~StackOnly()
	{
		cout << "call destruction function" << endl;
	}

private:
	void* operator new(size_t size){}
	void* operator new[](size_t size) {}
	void operator delete(void* p) {}
	void operator delete[](void* p) {}
};


int main()
{
	//StackOnly* parrStack = new StackOnly[10];
	//StackOnly* pStack = new StackOnly;

	StackOnly stack;
	system("pause");
	return 0;
}
#endif