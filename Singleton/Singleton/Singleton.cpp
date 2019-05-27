#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//程序启动时，将对象创建好
//只能创建一个对象

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	//构造函数私有
	Singleton(){};

	//防拷贝
	//C++98
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	//C++11
	Singleton(Singleton const&) = delete;
};

Singleton 
int main()
{
	return 0;
}