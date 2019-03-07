#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

//创建一个普通命名空间ns1
namespace ns1
{
	//命名空间中定义的变量和函数
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}
}


//创建一个嵌套类型的命名空间ns2，ns3嵌套在ns2当中
namespace ns2
{
	int a = 1;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace ns3
	{
		int a = 2;
		int c;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}


//在同一个工程中允许存在多个相同名称的命名空间，编译器最后会将这些命名空间合成到同一个命名空间中
//创建一个名称同为ns1的命名空间
namespace ns1
{
	int Mul(int left, int right)
	{
		return left * right;
	}
}


//创建一个命名空间相当于定义了一个新的作用域，命名空间中的所有内容都只局限于该命名空间中


int main()
{
	//嵌套命名空间下同名变量不互相影响
	cout << "ns2::ns3::a:" << ns2::ns3::a << endl;
	cout << "ns2::a:" << ns2::a << endl;

	//命名空间错误的使用
	//printf("%d\n", a);
	//编译出错：无法识别的字符
	
	//命名空间正确使用
	
	//1、使用命名空间名称及作用域限定符
	printf("%d\n", ns2::a);

	//2、使用using引入命名空间成员
	using ns2::a;
	printf("%d\n", a);

	//3、使用using namespace引入命名空间
	using namespace ns2;
	printf("%d\n", a);
	Add(3, 4);

	//输入&输出
	int aa;
	double bb;
	char cc;

	cin >> aa;
	cin >> bb >> cc;//等于cin>>bc; cin>>cc;

	cout << aa << endl;
	cout << bb << " " << cc << endl;

	system("pause");
	return 0;
}