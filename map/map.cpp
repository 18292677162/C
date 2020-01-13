#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

// map insert
void TestMap()
{
	map<string, string> m;
	m.insert(pair<string, string>("张三", "大佬"));
	m.insert(make_pair("李四", "二佬"));
	m.insert(make_pair("王五", "三佬"));
	m["钱七"] = "四佬"; // 1.<钱七, ""> 2.插入

	cout << m["李四"] << endl;
	cout << m["赵六"] << endl;
	cout << m.size() << endl;
}

// map
void TestMap2()
{
	int arr[] = {2, 1, 5, 9, 0, 3, 7, 4, 8, 6};
	map<int, int> m;

	for(auto e : arr)
		m.insert(make_pair(e, e));

	map<int, int>::iterator it = m.begin();
	while(it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	for(auto& e : m)
	{
		cout << m.first << "--->" <, m.second << endl;
	}
}

// multimap
void TestMap3()
{
	int arr[] = {2, 1, 1, 5, 9, 0, 3, 3, 7, 7, 4, 8, 6};
	multimap<int, int> m;

	for(auto e : arr)
		m.insert(make_pair(e, e));

	multimap<int, int>::iterator it = m.begin();
	while(it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	for(auto& e : m)
	{
		cout << m.first << "--->" <, m.second << endl;
	}
}

// set
void TestSet1()
{
	int arr[] = {2, 1, 1, 5, 9, 0, 3, 3, 7, 7, 4, 8, 6};
	set<int> s;

	for(auto e : arr)
		s.insert(e);

	set<int>::iterator it = s.begin();
	while(it != s.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << endl;

	for(auto& e : s)
	{
		cout << e << endl;
	}
}

// multiset
void TestSet2()
{
	int arr[] = {2, 1, 1, 5, 9, 0, 3, 3, 7, 7, 4, 8, 6};
	multiset<int> s;

	for(auto e : arr)
		s.insert(e);

	multiset<int>::iterator it = s.begin();
	while(it != s.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << endl;

	for(auto& e : s)
	{
		cout << e << endl;
	}
}

int main()
{
	TestMap();
	TestMap2();
	TestMap3();
	TestSet1();
	TestSet2();
	return 0;
}
