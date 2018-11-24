#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

// create an ordinary namespace NS1
namespace ns1
{
	//Variables and functions defined in namespace
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}
}


//Create a nested type namespace NS2, NS3 nested in NS2.
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


//Multiple namespaces with the same name are allowed in the same project, and the compiler will eventually synthesize these namespaces into the same namespace
//Create a namespace with the same name as NS1.
namespace ns1
{
	int Mul(int left, int right)
	{
		return left * right;
	}
}


//Creating a namespace is equivalent to defining a new scope, and everything in the namespace is limited to that namespace.


int main()
{
	//The namespace variables under the nested namespace do not affect each other.
	cout << "ns2::ns3::a:" << ns2::ns3::a << endl;
	cout << "ns2::a:" << ns2::a << endl;

	//Use of namespace errors
	//printf("%d\n", a);
	//Compile error: unrecognized character

	//Proper use of namespaces

	//1. Use namespace name and scope qualifier.
	printf("%d\n", ns2::a);

	//2. Use using to introduce namespace members.
	using ns2::a;
	printf("%d\n", a);

	//3. Use using namespace to introduce namespaces.
	using namespace ns2;
	printf("%d\n", a);
	Add(3, 4);

	//Input / output
	int aa;
	double bb;
	char cc;

	cin >> aa;
	cin >> bb >> cc;//Equal to cin>>bc; cin>>cc;

	cout << aa << endl;
	cout << bb << " " << cc << endl;

	system("pause");
	return 0;
}