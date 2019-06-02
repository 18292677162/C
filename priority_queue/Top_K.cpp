#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	vector<int> nums= { 3, 2, 1, 5, 6, 6,4 };
	int k;
	cin >> k;
	if (1 <= k && k <= nums.size()){
		sort(nums.begin(), nums.end(), greater<int>());
		unique(nums.begin(), nums.end());
		cout << nums.size();
	}
	system("pause");
	return 0;
}