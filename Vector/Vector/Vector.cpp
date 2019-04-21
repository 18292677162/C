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

	//只要迭代器解引用之后的类型一致，就可以迭代器传参
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
	//insert会引起迭代器失效，增容导致原有指向的空间已经被释放：迭代器指向的位置非法
	//v7.insert(v7.begin() + 3, 0);//12304
	//解决：插入完成后重新获取迭代器
	vit = v7.begin();
	cout << *vit << endl;
	//v7.insert(v7.end() - 2, 5);//123504
	//erase返回被擦除的元素后面的新位置，可能导致迭代器访问越界
	/*
	不一定会报错，取决于操作系统
	vector<int>::iterator vit = v7.begin();
	while (vit != v7.end()){
		if (*vit % 2 == 0){
			v7.erase(vit);
		}
		vit++;
	}
	1 2 3 4 5不会段错误		vit到5时不用删除，停下来
	1 2 3 4会段错误	vit到4时删除向后移动，越界
	*/
	//v7.erase(vit);
	//解决：删除后获取erase返回值，更新迭代器的值
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
	//增容：不同平台实现不一样：vs2013：1.5倍		linux：2倍
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
	//emplace   emplace_back  构造并插入
	v.emplace(v.begin(), 2018, 4, 3);

	vector<Date> v2;
	int a = 10; int b = 20;
	swap(a, b);
	//成员swap和非成员swap内在逻辑相同，非成员swap内部调用swap完成交换
	swap(v, v2);		//v.swap(v2);
	v.swap(v2);

	system("pause");
	return 0;
}