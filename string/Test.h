#include <iostream>
#include <string>
using namespace std;

void Test1()
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
}

//size/length/clear/resize
void Test2()
{
	//支持直接cin cout输入输出
	string s("goodbye");
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//清空s中字符串，只将size清0，不改变底层空间大小
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//将有效字符个数增加到10个，多出位置用‘A’填充
	// “AAAAAAAAAA”
	s.resize(10, 'A');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//将有效字符个数增加到20个，多出位置用缺省值'\0'填充
	//'AAAAAAAAAA\0\0\0\0\0\0\0\0\0\0'
	//string内存分配按照:(n*16-1)分配
	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//将有效字符个数缩小到5个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

}

void Test3()
{
	string s1("hello");
	const string s2("goodbye");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H'; 
	// s2[0] = 'h'; 代码编译失败，因为const类型对象不能修改
	cout << s1 << endl;

	for (size_t i = 0; i < s1.size(); i++){
		cout << s1[i] << endl;
	}
}

void Test4()
{
	string s;
	s.push_back(' ');
	s.append("welcome");
	s += "A";
	s += 'B';
	cout << s << endl;
	cout << s.c_str() << endl;	//以C语言方式打印字符串

	string file("test.txt");
	int pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;

	// npos是string里面的一个静态成员变量
	// static const size_t npos = -1;
	// 取出url中的域名
	string url("https://www.baidu.com/?tn=98010089_dg");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos){
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;

	// 删除url的协议前缀
	pos = url.find("://");
	url.erase(0, pos + 3);	//从pos开始删除n个
	cout << url << endl;
}

// 利用reserve提高插入数据的效率，避免增容带来的开销
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow: " << endl;
	for (int i = 0; i < 100; i++){
		s += 'A';
		if (sz != s.capacity()){
			sz = s.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}
}

void TestPushBack_Quick()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow: " << endl;
	for (int i = 0; i < 100; i++){
		s += 'A';
		if (sz != s.capacity()){
			sz = s.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}
}

void TestCompare()
{
	string foo = "A";	//65
	string bar = "a";	//97

	if (foo == bar) std::cout << "foo and bar are equal\n";
	if (foo != bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

}

void Test()
{
	Test1();
	printf("\n");
	Test2();
	printf("\n");
	Test3();
	printf("\n");
	Test4();
	printf("\n");
	TestPushBack();
	printf("\n");
	TestPushBack_Quick();
	printf("\n");
	TestCompare();
}