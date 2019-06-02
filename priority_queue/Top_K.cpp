#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main()
{
	vector<int> nums = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
	int k;
	cin >> k;
	
	//  找数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素
#if 0
	if (1 <= k && k <= nums.size()){
		sort(nums.begin(), nums.end(), greater<int>());
		//vector<int>::iterator end_unique = unique(nums.begin(), nums.end());
		//nums.erase(end_unique, nums.end());
		return nums[k - 1];
	}
	else{
		return -1;
	}
	return 0;
#endif

	priority_queue<int> q(nums.begin(), nums.end());
	for (size_t i = 0; i < k - 1; i++){
		q.pop();
	}
	return q.top();
}