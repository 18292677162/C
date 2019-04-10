#include <iostream>
#include <string>
using namespace std;

void Test1()
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
}

//size/length/clear/resize
void Test2()
{
	//֧��ֱ��cin cout�������
	string s("goodbye");
	cout << s.length() << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//���s���ַ�����ֻ��size��0�����ı�ײ�ռ��С
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//����Ч�ַ��������ӵ�10�������λ���á�A�����
	// ��AAAAAAAAAA��
	s.resize(10, 'A');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//����Ч�ַ��������ӵ�20�������λ����ȱʡֵ'\0'���
	//'AAAAAAAAAA\0\0\0\0\0\0\0\0\0\0'
	//string�ڴ���䰴��:(n*16-1)����
	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	//����Ч�ַ�������С��5��
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
	// s2[0] = 'h'; �������ʧ�ܣ���Ϊconst���Ͷ������޸�
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
	cout << s.c_str() << endl;	//��C���Է�ʽ��ӡ�ַ���

	string file("test.txt");
	int pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;

	// npos��string�����һ����̬��Ա����
	// static const size_t npos = -1;
	// ȡ��url�е�����
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

	// ɾ��url��Э��ǰ׺
	pos = url.find("://");
	url.erase(0, pos + 3);	//��pos��ʼɾ��n��
	cout << url << endl;
}

// ����reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���
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