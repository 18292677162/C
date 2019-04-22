#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void	PrintList(list<int>& l)
{
	for (auto e : l){
		cout << e << " ";
	}
	cout << endl;
}

#if 0
int main()
{
	//构造
	list<int> l1;		//构造空l1
	list<int> l2(10, 1);		//l2中存放10个1
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> l3(arr, arr + sizeof(arr) / sizeof(arr[0]));		//arr的[begin(), end())构造l3  左闭右开
	list<int> l4(l3);
#if 0
	for (list<int> ::iterator lit = l3.begin(); lit != l3.end(); lit++){
		cout << *lit << " ";
	}
	cout << endl;

	for (const auto e : l3){
		cout << e << " ";
	}
	cout << endl;

	//iterator
	//正向迭代器正向打印list中元素
	for (list<int> ::iterator lit = l3.begin(); lit != l3.end(); ++lit){
		cout << *lit << " ";
	}
	cout << endl;
	//反向迭代器逆向打印list中元素
	for (list<int> ::reverse_iterator lit = l3.rbegin(); lit != l3.rend(); ++lit){
		cout << *lit << " ";
	}
	cout << endl;
	//const的正向迭代器
	auto clit = l3.cbegin();
	cout << *clit << endl;
	//*clit = 10;		编译失败clit为const_iterator的迭代器
#endif

#if 0
	//capacity
	//有效节点个数
	cout << l3.size() << endl;
	//是否为空
	if (l1.empty()){
		cout << "list is empty" << endl;
	}

	//element access
	for (auto e : l4){
		cout << e << " ";
	}
	cout << endl;

	//list第一个最后一个结点值改为10
	l4.front() = 10;
	l4.back() = 1;
	for (auto e : l4){
		cout << e << " ";
	}
	cout << endl;

	const list<int> l5(l2);
	//int& a = l5.front();	l2是const类型的list对象，front()为const引用类型
	const int& ca = l5.front();
#endif

	system("pause");
	return 0;
}
#endif

#if 0
//modifiers
//push_back/pop_back/push_front/pop_front
void TestList1()
{
	int arr[] = { 2, 3 };
	list<int> l1(arr, arr + sizeof(arr) / sizeof(arr[0]));

	l1.push_back(4);
	l1.push_back(5);
	l1.push_front(1);
	l1.push_front(0);
	PrintList(l1);

	l1.pop_front();
	l1.pop_back();
	PrintList(l1);
}

// emplace_back / emplace_front / emplace
class Date
{
public:
	Date(int year=1900,int month=1,int day=1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Data(int, int, int): " << this << endl;
	}

	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&): " << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestList2(){
	list<Date> l;
	Date d(2018, 1, 1);
	l.push_back(d);
	l.emplace_back(2018, 1, 2);
	l.emplace_back(2018, 1, 2);

}
#endif

#if 0
void TestList3()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	for (auto e : l){
		cout << e << " ";
	}
	cout << endl;

	//获取list第二个结点
	auto pos = ++l.begin();
	cout << *pos << endl;

	//pos前插入值为4元素
	l.insert(pos, 4);
	PrintList(l);

	//pos前插入5个值为1的元素
	l.insert(pos, 5, 1);
	PrintList(l);

	//在pos前插入[v.begin(), v.end)区间中的元素
	vector<int> v{ 4, 5, 6 };
	l.insert(pos, v.begin(), v.end());
	PrintList(l);

	//删除pos位置的元素
	l.erase(pos);
	PrintList(l);

	// 删除list中[begin, end)区间中的元素，即删除list中的所有元素
	l.erase(l.begin(), l.end());
	PrintList(l);
}
#endif

#if 0
// resize/swap/clear
void TestList4()
{
	list<int> l1{ 1, 2, 3, 4, 5 };
	PrintList(l1);

	//将l1中元素增加到10个，默认元素填充
	//默认元素：内置类型为0，自定义类型调用缺省构造函数
	l1.resize(10);
	PrintList(l1);

	//l1元素增加到15个，多出的元素用3填充
	l1.resize(15, 3);
	PrintList(l1);

	//l1元素减少到5个
	l1.resize(5);
	PrintList(l1);

	//交换l1和l2元素
	vector<int> v{ 6, 6, 6 };
	list<int> l2(v.begin(), v.end());
	PrintList(l2);

	l1.swap(l2);
	PrintList(l1);
	PrintList(l2);

	//将l2元素清空
	l2.clear();
	cout << l2.size() << endl;
}
#endif

#if 1
void TestListIterator1()
{	
	//迭代器失效
	list<int> l = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto it = l.begin();
	while (it != l.end()){
		//erase()执行后，it所指的节点已被删除，故it无效，下次使用前必须重新赋值
		l.erase(it);
		++it;
	}
}

void TestListIterator2()
{
	//迭代器不失效
	list<int> l = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto it = l.begin();
	while (it != l.end()){
		l.erase(it++);		//it = l.erase(it);
	}
}
#endif

int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	//TestList4();
	//TestListIterator1();
	TestListIterator2();
	system("pause");
	return 0;
}