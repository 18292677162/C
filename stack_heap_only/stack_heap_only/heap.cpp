#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//类的构造函数私有，拷贝构造函数私有，防止拷贝构造在栈上生成对象
//提供静态成员函数，用来完成堆对象的创建
#if 0
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
	static void DestroyObject(HeapOnly* &p)
	{
		if (NULL != p) {
			delete p;
			p = nullptr;
		}
	}
	int data;
private:
	HeapOnly() {}
	~HeapOnly() {}

	//C++98只声明不实现
	//HeapOnly(const HeapOnly&);

	//C++11
	//HeapOnly(const HeapOnly&) = delete;
};

int main()
{
	//HeapOnly* parrHeap = new HeapOnly[10];
	//HeapOnly* pHeap = new HeapOnly;
	//HeapOnly heap;

	HeapOnly* pHeap = HeapOnly::CreateObject();
	if (NULL != pHeap) {
		pHeap->data = 5;
	}
	return 0;
}

#endif