#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

//����һ����ͨ�����ռ�ns1
namespace ns1
{
	//�����ռ��ж���ı����ͺ���
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}
}


//����һ��Ƕ�����͵������ռ�ns2��ns3Ƕ����ns2����
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


//��ͬһ��������������ڶ����ͬ���Ƶ������ռ䣬���������Ὣ��Щ�����ռ�ϳɵ�ͬһ�������ռ���
//����һ������ͬΪns1�������ռ�
namespace ns1
{
	int Mul(int left, int right)
	{
		return left * right;
	}
}


//����һ�������ռ��൱�ڶ�����һ���µ������������ռ��е��������ݶ�ֻ�����ڸ������ռ���


int main()
{
	//Ƕ�������ռ���ͬ������������Ӱ��
	cout << "ns2::ns3::a:" << ns2::ns3::a << endl;
	cout << "ns2::a:" << ns2::a << endl;

	//�����ռ�����ʹ��
	//printf("%d\n", a);
	//��������޷�ʶ����ַ�
	
	//�����ռ���ȷʹ��
	
	//1��ʹ�������ռ����Ƽ��������޶���
	printf("%d\n", ns2::a);

	//2��ʹ��using���������ռ��Ա
	using ns2::a;
	printf("%d\n", a);

	//3��ʹ��using namespace���������ռ�
	using namespace ns2;
	printf("%d\n", a);
	Add(3, 4);

	//����&���
	int aa;
	double bb;
	char cc;

	cin >> aa;
	cin >> bb >> cc;//����cin>>bc; cin>>cc;

	cout << aa << endl;
	cout << bb << " " << cc << endl;

	system("pause");
	return 0;
}