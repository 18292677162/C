#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

#include <queue>
#include <functional>

using namespace std;

// 大小堆
#if 0
int main()
{
	int array[] = { 3, 2, 6, 8, 1, 0, 9, 5, 7, 4 };
	// 默认less(小于)比较 创建大堆，默认递减
	priority_queue<int> q(array, array + sizeof(array) / sizeof(array[0]));
	cout << q.top() << endl;

	// 小堆
	priority_queue<int, vector<int>, greater<int>> q1(array, array + sizeof(array) / sizeof(array[0]));
	cout << q1.top() << endl;
	system("pause");
	return 0;
}
#endif


//  自定义类型
#if 0
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d) const
	{
		return _day < d._day;
	}

	bool operator>(const Date& d) const
	{
		return _day > d._day;
	}

protected:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018, 12, 2);
	Date d2(2018, 12, 1);
	Date d3(2018, 12, 3);
	//  小堆
	//  默认 less--- <   大堆
	//  可以将 < 重载为 > 即可为小堆（但违背原则，不推荐）

	priority_queue<Date, vector<Date>, greater<Date>> q;
	q.push(d1);
	q.push(d2);
	q.push(d3);

	system("pause");
	return 0;
}
#endif