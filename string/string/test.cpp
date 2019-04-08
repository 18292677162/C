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
	string s5("ABCDE", 3);		//string前三个
	string s6(s2, 3);	//从s2第三个字符开始
	string s7(s2, 1, 2);		//从1开始2个字符

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;

	system("pause");
	return 0;
}