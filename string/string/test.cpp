#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	string s2("hello");
	string s3(10, 'A');
	string s4(s3);
	string s5("ABCDE", 3);		//stringǰ����
	string s6(s2, 3);	//��s2�������ַ���ʼ
	string s7(s2, 1, 2);		//��1��ʼ2���ַ�

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;

	system("pause");
	return 0;
}