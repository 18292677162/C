#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Windows.h>

using namespace std;

// GetLastError()
#if 0
int main()
{
	FILE* pf = fopen("1.txt", "r");
	if (nullptr == pf){
		int err = GetLastError();
		cout << err << endl;
		return 0;
	}

	fclose(pf);
	system("pause");
	return 0;
}
#endif

// longjmp();	goto L; L:
#if 0
jmp_buf buff;

void TestFunc1()
{
	FILE* pf = fopen("1.txt", "r");
	if (nullptr == pf){
		// longjmp();
		// goto
		http://www.baidu.com;
		longjmp(buff, 1);
	}

	fclose(pf);
}

void TestFunc2()
{
	int* p = (int*)malloc(sizeof(int)* 0xffffffff);
	if (nullptr == p){
		longjmp(buff, 2);
		// ...
	}
	free(p);
}

int main()
{
	//	设置程序的跳转点，初始赋值为0
	int state = setjmp(buff);
	if (0 == state){
		TestFunc1();
		TestFunc2();
	}
	else{
		switch (state){
		case 1:
			cout << "打开文件失败" << endl;
			break;
		case 2:
			cout << "malloc申请空间失败" << endl;
			break;
		default:
			cout << "未知错误" << endl;
		}
	}
	system("pause");
	return 0;
}
#endif

// C++异常
#if 0
void TestFunc1()
{
	FILE* pf = fopen("1.txt", "r");
	if (nullptr == pf){
		throw 1;
	}
	// ...
	fclose(pf);
}

void TestFunc2()
{
	int* p = 0;
	if (nullptr == p){
		throw 'A';
	}
	free(p);
}

int main()
{
	try
	{
		TestFunc1();
		TestFunc2();
	}
	catch (int err)
	{
		cout << err << endl;
	}
	catch (char err)
	{
		cout << err << endl;
	}
	system("pause");
	return 0;
}
#endif

