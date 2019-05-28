#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//程序启动时，将对象创建好
//只能创建一个对象

//饿汉模式
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	//构造函数私有
	Singleton(){
		cout << "call" << endl;
	};

	//防拷贝
	//C++98
	//Singleton(Singleton const&);
	//Singleton& operator=(Singleton const&);

	//C++11
	Singleton(Singleton const&) = delete;
	
	static Singleton m_instance;
};

Singleton Singleton::m_instance;

int main()
{
	cout << "run" << endl;
	Singleton::GetInstance();
	system("pause");
	return 0;
}