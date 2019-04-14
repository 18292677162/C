#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = (int)array.size();
		int col = (int)array[0].size();
		if (0 == row || 0 == col) {
			return false;
		}
		if (target<array[0][0] || target>array[row - 1][col - 1]) {
			return false;
		}
		int i = 0;
		int j = col - 1;
		while (i < row && j >= 0) {
			if (array[i][j] > target) {
				j--;
			}
			else if (array[i][j] < target) {
				i++;
			}
			else {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	vector<vector<int> > array = {
		{ 1, 3, 7, 9 },
		{ 3, 5, 9, 11 },
		{ 6, 6, 12, 14 },
		{ 9, 10, 15, 17 } };
	Solution test;
	cout << test.Find(13, array) << endl;
	system("pause");
	return 0;
}