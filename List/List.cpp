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
	//����
	list<int> l1;		//�����l1
	list<int> l2(10, 1);		//l2�д��10��1
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	list<int> l3(arr, arr + sizeof(arr) / sizeof(arr[0]));		//arr��[begin(), end())����l3  ����ҿ�
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
	//��������������ӡlist��Ԫ��
	for (list<int> ::iterator lit = l3.begin(); lit != l3.end(); ++lit){
		cout << *lit << " ";
	}
	cout << endl;
	//��������������ӡlist��Ԫ��
	for (list<int> ::reverse_iterator lit = l3.rbegin(); lit != l3.rend(); ++lit){
		cout << *lit << " ";
	}
	cout << endl;
	//const�����������
	auto clit = l3.cbegin();
	cout << *clit << endl;
	//*clit = 10;		����ʧ��clitΪconst_iterator�ĵ�����
#endif

#if 0
	//capacity
	//��Ч�ڵ����
	cout << l3.size() << endl;
	//�Ƿ�Ϊ��
	if (l1.empty()){
		cout << "list is empty" << endl;
	}

	//element access
	for (auto e : l4){
		cout << e << " ";
	}
	cout << endl;

	//list��һ�����һ�����ֵ��Ϊ10
	l4.front() = 10;
	l4.back() = 1;
	for (auto e : l4){
		cout << e << " ";
	}
	cout << endl;

	const list<int> l5(l2);
	//int& a = l5.front();	l2��const���͵�list����front()Ϊconst��������
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

	//��ȡlist�ڶ������
	auto pos = ++l.begin();
	cout << *pos << endl;

	//posǰ����ֵΪ4Ԫ��
	l.insert(pos, 4);
	PrintList(l);

	//posǰ����5��ֵΪ1��Ԫ��
	l.insert(pos, 5, 1);
	PrintList(l);

	//��posǰ����[v.begin(), v.end)�����е�Ԫ��
	vector<int> v{ 4, 5, 6 };
	l.insert(pos, v.begin(), v.end());
	PrintList(l);

	//ɾ��posλ�õ�Ԫ��
	l.erase(pos);
	PrintList(l);

	// ɾ��list��[begin, end)�����е�Ԫ�أ���ɾ��list�е�����Ԫ��
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

	//��l1��Ԫ�����ӵ�10����Ĭ��Ԫ�����
	//Ĭ��Ԫ�أ���������Ϊ0���Զ������͵���ȱʡ���캯��
	l1.resize(10);
	PrintList(l1);

	//l1Ԫ�����ӵ�15���������Ԫ����3���
	l1.resize(15, 3);
	PrintList(l1);

	//l1Ԫ�ؼ��ٵ�5��
	l1.resize(5);
	PrintList(l1);

	//����l1��l2Ԫ��
	vector<int> v{ 6, 6, 6 };
	list<int> l2(v.begin(), v.end());
	PrintList(l2);

	l1.swap(l2);
	PrintList(l1);
	PrintList(l2);

	//��l2Ԫ�����
	l2.clear();
	cout << l2.size() << endl;
}
#endif

#if 1
void TestListIterator1()
{	
	//������ʧЧ
	list<int> l = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto it = l.begin();
	while (it != l.end()){
		//erase()ִ�к�it��ָ�Ľڵ��ѱ�ɾ������it��Ч���´�ʹ��ǰ�������¸�ֵ
		l.erase(it);
		++it;
	}
}

void TestListIterator2()
{
	//��������ʧЧ
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