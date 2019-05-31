#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

//全特化
#if 0
template<>
class Data<int, char>
{
public:
	Data() { cout << "Data<int, char>" << endl; }
private:
	int _d1;
	char _d2;
};

void Test()
{
	Data<int, int> d1;
	Data<int, char> d2;
}

int main()
{
	Test();
	system("pause");
	return 0;
}
#endif

//偏特化
#if 0
//部分特化
// 将第二个参数特化为int
template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};


//参数更进一步的限制
//两个参数偏特化为指针类型
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

//两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1 & _d1;
	const T2 & _d2;
};

void Test()
{
	Data<double, int> d1; // 调用特化的int版本
	Data<int, double> d2; // 调用基础的模板
	Data<int*, int*> d3; // 调用特化的指针版本
	Data<int&, int&> d4(1, 2); // 调用特化的指针版本
}

int main()
{
	Test();
	system("pause");
	return 0;
}
#endif

// 类型萃取
// 内置类型
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

// 自定义类型
struct FalseType
{
	static bool Get()
	{
		return false;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType IsPODType;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<short>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<long>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<long long>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<float>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<long double>
{
	typedef TrueType IsPODType;
};

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if (TypeTraits<T>::IsPODType::Get()){
		memcpy(dst, src, sizeof(T)*size);
	}
	else{
		for (size_t i = 0; i < size; ++i){
			dst[i] = src[i];
		}
	}
}

int main()
{
	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int a2[10];
	Copy(a2, a1, 10);
	string s1[] = { "111", "222", "333", "444" };
	string s2[4];
	Copy(s2, s1, 4);
	system("pause");
	return 0;
}