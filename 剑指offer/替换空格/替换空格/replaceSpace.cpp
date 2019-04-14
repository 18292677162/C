#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Solution {
public:
	//length为字符数组总容量
	void replaceSpace(char *str, int length) {
		if (nullptr == str || length <= 0){
			return;
		}
		//originalLength为字符串实际长度
		int originalLength = 0;
		int numberOfBlank = 0;
		int i = 0;
		//空格数量
		while ('\0' != str[i]){
			++originalLength;
			if (' ' == str[i]){
				++numberOfBlank;
			}
			++i;
		}
		//把空格替换成%20后的长度
		int newLength = originalLength + 2 * numberOfBlank;
		if (newLength > length){
			return;
		}
		int indexOfOriginal = originalLength;
		int indexOfNew = newLength;
		while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
			if (' ' == str[indexOfOriginal]){
				str[indexOfNew--] = '0';
				str[indexOfNew--] = '2';
				str[indexOfNew--] = '%';
			}
			else{
				str[indexOfNew--] = str[indexOfOriginal];
			}
			--indexOfOriginal;
		}
	}
};

int main()
{
	Solution s;
	char str[30] = "We are happy.";
	int size = 30;
	s.replaceSpace(str, size);
	system("pause");
	return 0;
}