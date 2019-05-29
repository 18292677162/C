#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Solution {
public:
	//lengthΪ�ַ�����������
	void replaceSpace(char *str, int length) {
		if (nullptr == str || length <= 0){
			return;
		}
		//originalLengthΪ�ַ���ʵ�ʳ���
		int originalLength = 0;
		int numberOfBlank = 0;
		int i = 0;
		//�ո�����
		while ('\0' != str[i]){
			++originalLength;
			if (' ' == str[i]){
				++numberOfBlank;
			}
			++i;
		}
		//�ѿո��滻��%20��ĳ���
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