#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//��������ʱ�������󴴽���
//ֻ�ܴ���һ������

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	//���캯��˽��
	Singleton(){};

	//������
	//C++98
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	//C++11
	Singleton(Singleton const&) = delete;
};

Singleton 
int main()
{
	return 0;
}