#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//  实现一个不能继承的类

//	C++98 构造函数私有化，派生类掉不到基类的构造函数，无法被继承
#if 1
class NonInherit
{
public:
	static NonInherit GetStackInstance()
	{
		return NonInherit();
	}

	static NonInherit* GetHeapInstance()
	{
		return new NonInherit;
	}
private:
	NonInherit()
	{}
};

//不可被继承
//class Test : public NonInherit
//{};

int main()
{
	NonInherit::GetHeapInstance;
	NonInherit::GetStackInstance;
	return 0;
}
#endif

//C++11	final禁止继承
#if 1
class NonInherit final
{
public:
	NonInherit()
	{}
};

class Test : public NonInherit
{};

int main()
{
	return 0;
}
#endif