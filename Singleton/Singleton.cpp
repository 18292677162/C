#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <mutex>
#include <thread>
#include <Windows.h>
using namespace std;

#if 1
//饿汉模式（线程安全，对象在使用以前已经创建出来了）
//优点：简单，线程安全
//缺点：可能导致进程启动满，且多个单例类对象实例启动顺序不确定
class Singleton
{
public:
	//提供静态公有方法，可以类名加域名访问，返回对象指针
	static Singleton* GetInstance()
	{
		return m_instance;
	}
private:
	//构造函数私有
	Singleton(){
		cout << "Sigletion()" << endl;
	};

	//防拷贝
	//C++98
	//Singleton(Singleton const&);
	//Singleton& operator=(Singleton const&);

	//C++11
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;
	
	static Singleton *m_instance;
};

//在程序入口之前完成单例对象的初始化
Singleton* Singleton::m_instance = new Singleton;

int main()
{
	cout << "main begin" << endl;

	//均无法创建实例
	//Singleton s;
	//Singleton *p = new Singleton;

	//调用共有静态成员方法
	Singleton* p1= Singleton::GetInstance();
	Singleton* p2 = Singleton::GetInstance();
	if (p1 == p2){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}

	system("pause");
	return 0;
}
#endif

#if 1
//懒汉模式（线程不安全，对象使用时再创建）
//优点：进程启动无负载，多个单例实例启动顺序自由控制
//缺点：复杂且线程不安全
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		//Double-Check方式解锁保证效率和线程安全
		//保证效率
		if (nullptr == m_instance){
			//保证线程安全
			m_mtx.lock();
			//正常检查
			if (nullptr == m_instance){
				m_instance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_instance;
	}

	//内嵌垃圾回收类
	class CGarbo{
	public:
		~CGarbo(){
			if (NULL != Singleton::m_instance){
				delete Singleton::m_instance;
			}
		}
	};

	//定义一个静态成员变量，程序结束后自动调用其析构函数释放单例对象
	static CGarbo Garbo;

private:
	//构造函数私有
	Singleton() {
		cout << "Singleton" << endl;
	};

	//防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	//单例对象指针
	static Singleton* m_instance;
	static mutex m_mtx;
};

Singleton* Singleton::m_instance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}

int main()
{
	cout << "main begin" << endl;
	
	thread t1(func, 1);
	thread t2(func, 2);

	t1.join();
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;

	system("pause");
	return 0;
}
#endif