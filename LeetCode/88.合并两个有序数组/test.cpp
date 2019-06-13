#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int num = m + n;
		while (num > 0){
			if (m <= 0 || n <= 0){
				while (n > 0 && m == 0){
					nums1[n - 1] = nums2[n - 1];
					n--;
					num--;
				}
				break;
			}
			if (nums1[m - 1] < nums2[n - 1]){
				nums1[num - 1] = nums2[n - 1];
				n--;
				num--;
			}
			else{
				nums1[num - 1] = nums1[m - 1];
				m--;
				num--;
			}
		}
	}
};

int main()
{
	vector<int> nums1 = { 1, 2, 4, 6, 6 };
	nums1.resize(10);
	vector<int> nums2 = { 2, 3, 5, 7, 9 };
	Solution S;
	S.merge(nums1, 5, nums2, 5);
	return 0;
}