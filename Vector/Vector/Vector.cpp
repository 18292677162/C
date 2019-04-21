#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include<string>
using namespace std;

void PrintV(const vector<int>& v2)
{
	//vector<int>::const_iterator vit = v.begin();
	auto vit = v2.begin();
	while (vit != v2.end()){
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
}

#if 0
int main()
{
	/*
	vector<int> v;
	vector<int> v2(10, 8);
	vector<int> v3(v2.begin(), v2.end());
	string s("hello");

	//ֻҪ������������֮�������һ�£��Ϳ��Ե���������
	vector<char> v4(s.begin(), s.end());

	vector<int>::iterator vit = v2.begin();
	while (vit != v2.end()){
		cout << *vit << " ";
		++vit;
	}
	cout << endl;

	for (const auto& e : v2){
		cout << e << " ";
	}
	cout << endl;

	for (int i = 0; i < v2.size(); i++){
		cout << v2[i] << " ";
	}
	cout << endl;
	*/

	vector<int>v7;
	v7.push_back(1);
	v7.push_back(2);
	v7.push_back(3);
	v7.push_back(4);
	auto vit = v7.begin();
	cout << *vit << endl;
	//insert�����������ʧЧ�����ݵ���ԭ��ָ��Ŀռ��Ѿ����ͷţ�������ָ���λ�÷Ƿ�
	//v7.insert(v7.begin() + 3, 0);//12304
	//�����������ɺ����»�ȡ������
	vit = v7.begin();
	cout << *vit << endl;
	//v7.insert(v7.end() - 2, 5);//123504
	//erase���ر�������Ԫ�غ������λ�ã����ܵ��µ���������Խ��
	/*
	��һ���ᱨ��ȡ���ڲ���ϵͳ
	vector<int>::iterator vit = v7.begin();
	while (vit != v7.end()){
		if (*vit % 2 == 0){
			v7.erase(vit);
		}
		vit++;
	}
	1 2 3 4 5����δ���		vit��5ʱ����ɾ����ͣ����
	1 2 3 4��δ���	vit��4ʱɾ������ƶ���Խ��
	*/
	//v7.erase(vit);
	//�����ɾ�����ȡerase����ֵ�����µ�������ֵ
	vit = v7.erase(vit);
	cout << *vit << endl;
	v7.clear();
	cout << v7.size() << endl;
	cout << v7.capacity() << endl;
	PrintV(v7);
	system("pause");
	return 0;
}
#endif;

#if 0
int main()
{
	//���ݣ���ͬƽ̨ʵ�ֲ�һ����vs2013��1.5��		linux��2��
	vector<int> v;
	//v.reserve(200);
	size_t capa = v.capacity();
	cout << "init capacity: " << capa << endl;
	for (int i = 0; i < 200; i++){
		v.push_back(i);
		if (capa != v.capacity()){
			capa = v.capacity();
			cout << capa << endl;
		}
	}
	system("pause");
	return 0;
}
#endif

class Date
{
public:
	Date(int y, int month, int day)
		:_year(y)
	{
		cout << "Date(int)" << endl;
	}

	Date(const Date& d)
		:_year(d._year)
	{
		cout << "Date(const Date&)" << endl;
	}
private:
	int _year;
};

int main()
{
	vector<Date> v;
	v.insert(v.begin(), Date(2018, 4, 3));
	cout << "emplace: " << endl;
	//emplace   emplace_back  ���첢����
	v.emplace(v.begin(), 2018, 4, 3);

	vector<Date> v2;
	int a = 10; int b = 20;
	swap(a, b);
	//��Աswap�ͷǳ�Աswap�����߼���ͬ���ǳ�Աswap�ڲ�����swap��ɽ���
	swap(v, v2);		//v.swap(v2);
	v.swap(v2);

	system("pause");
	return 0;
}