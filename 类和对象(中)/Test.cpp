#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

#if 0
class Date
{
public:
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month; 
	int _day;
}; 

int main()
{
	Data d1, d2;
	d1.SetDate(2019, 1, 21);
	d1.Display();
	d2.SetDate(2019, 1, 24);
	d2.Display();
	system("pause");
	return 0;
}
#endif

#if 0
//����û����ʽ���幹�캯���������������޲�Ĭ�Ϲ��캯������ӡΪ���ֵ
class Date
{
public:
	/*
	// ����û���ʽ�����˹��캯��������������������
	Date (int year, int month, int day)
	{
	_year = year;
	_month = month;
	_day = day;
	}
	*/
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	// û�ж��幹�캯��������Ҳ���Դ����ɹ�����˴˴����õ��Ǳ��������ɵ�Ĭ�Ϲ��캯��
	Date d;
	d.Display();
	system("pause");
	return 0;
}
#endif

#if 0
class Date
{
public:
	//1.�޲ι��캯��
	Date()
	{}
	//2.���ι��캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;		//�����޲ι��캯��
	Date d2(2018, 1, 1);		 //���ô��ι��캯��
	d1.Display();
	d2.Display();
	
	// ע�⣺���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
	// ���´���ĺ�����������d3�������ú����޲Σ�����һ���������͵Ķ���
	Date d3();

	system("pause");
	return 0;
}
#endif

#if 0
// Ĭ�Ϲ��캯��
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
// ���²��Ժ�����ͨ��������
void Test()
{
	Date d1;
	//��Date::Date��: �����غ����ĵ��ò���ȷ
	//��Date��: ָ���˶��Ĭ�Ϲ��캯��	
}
#endif

#if 1

#endif