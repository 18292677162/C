#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

// 函数模板实例化
#if 0
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()
{
	int a1 = 10, a2 = 20;
	double b1 = 1.3, b2 = 2.2;

	// 隐式实例化
	cout << Add(a1, a2) << endl;
	cout << Add(b1, b2) << endl;
	cout << Add(double(a1), b1) << endl;

	// 显示实例化
	cout << Add<double>(a2, b2) << endl;
	system("pause");
	return 0;
}
#endif

// 函数模板匹配规则
#if 0
// 专门处理int加法函数
int Add(const int& left, const int& right)
{
	return left + right;
}

//通用加法函数1
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

//通用加法函数2
template<class T1,class T2>
T1 Add(const T1& left, const T2& right)
{
	return left + right;
}

int main()
{
	// 函数模板可以和同名的非模板函数存在，优先调用非模板函数

	//优先选择非模板函数
	cout << Add(1, 2) << endl;
	//显式实例化
	cout << Add<int>(1, 2) << endl;

	// 模板函数可以生成更加匹配的版本
	cout << Add(1, 2.2) << endl;
	system("pause");
	return 0;
}
#endif

//模板动态顺序表(vector)
#if 0
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		: _pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	// 析构函数：类中声明，类外定义
	~Vector();

	void PushBack(const T& data)
	{
		_pData[_size++] = data;
	}

	void PopBack()
	{
		--_size;
	}

	size_t Size()
	{
		return _size;
	}

	T& operator[](size_t pos)
	{
		assert(pos < _size&&pos <= _capacity);
		return _pData[pos];
	}

private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};

// 类模板函数在类外定义时，需要加模板参数列表
template<class T>
Vector<T>::~Vector()
{
	if (nullptr != _pData){
		delete[] _pData;
	}
}

int main()
{
	Vector<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PopBack();

	Vector<char> s2;
	s2.PushBack('A');
	s2.PushBack('B');
	s2.PushBack('C');

	for (size_t i = 0; i < s1.Size(); ++i){
		cout << s1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < s2.Size(); ++i){
		cout << s2[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
#endif