#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

// 模拟实现 C++11 lock_guard 守卫锁
template<class Mutex>
class LockGuard
{
public:
	LockGuard(Mutex& mtx)
		: _mutex(mtx)
	{
		_mutex.lock();
	}
	
	~LockGuard()
	{
		_mutex.unlock();
	}

	LockGuard(const LockGuard<Mutex>&) = delete;

private:
	// 采用引用，保证锁是互斥量对象
	Mutex& _mutex;
};

mutex mtx;
static int n = 0;

void Func()
{
	for (size_t i = 0; i < 1000000; ++i)
	{
		LockGuard<mutex> lock(mtx);
		++n;
	}
}

int main()
{
	int begin = clock();
	thread t1(Func);
	thread t2(Func);

	t1.join();
	t2.join();

	int end = clock();

	cout << n << endl;
	cout << "time :" << end - begin << endl;
	system("pause");
	return 0;
}
