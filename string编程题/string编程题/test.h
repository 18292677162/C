#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	//翻转字符串
	string reverseStringAll(string s){
		if (s.empty())
			return s;

		size_t start = 0;
		size_t end = s.size() - 1;

		while (start < end){
			swap(s[start], s[end]);
			start++;
			end--;
		}
		return s;
	}

	//区间部分翻转
	string reverseStringK(string s, int k) {

	}

	//翻转字符串中的单词
	string reverseWords(string s) {

	}

	//找字符串中第一个只出现一次的字符
	int firstUniqChar(string s){
		//空间换时间
		//定义一个哈希表（外部空间），其键值（Key）是字符，而值（Value）是该字符出现的次数
		//数组模拟
		//统计每个字符串出现次数，一个char=8bit 共有256种可能
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i < size; i++){
			count[s[i]] += 1;
		}

		//遍历查找
		for (int i = 0; i < size; i++){
			if (1 == count[s[i]]){
				return i;
			}
		}
		return -1;
	}

	//字符串里面最后一个单词的长度
	int lastWordSize(string s){
		size_t pos = s.rfind(' ');
		cout << s.size() - pos - 1 << endl;
		return 0;
	}

	//验证一个字符串是否是回文
	bool isPalindrome(string s){
		if (s.empty()){
			return true;
		}

		int begin = 0;
		int end = s.size() - 1;

		char* p = (char*)s.c_str();
		while (begin != end&&begin < end){
			//从前往后找一个数字或字母
			while (begin < end){
				if (isNumberOrLetter(s[begin])){
					break;
				}
				begin++;
			}

			//从后往前找一个数字或字母
			while (begin < end){
				if (isNumberOrLetter(s[end])){
					break;
				}
				end--;
			}

			if (begin < end){
				//start和end字符是否相等 || 不区分大小的相等  防止0除
				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32){
					return false;
				}
				begin++;
				end--;
			}
		}
		return true;
	}

	bool isNumberOrLetter(char a){
		if (a >= '0'&&a <= '9' ||
			a >= 'a'&&a <= 'z' ||
			a >= 'A'&&a <= 'Z'){
			return true;
		}
		return false;
	}

	//字符串相加  '0'的ASCII码为48, '1'为49  s[i]-'0'的实质就是将单个字符转化为单个数字
	string addStrings(string num1, string num2) {
		int LSize = num1.size();
		int RSize = num2.size();
		int Left = LSize - 1;
		int Right = RSize - 1;
		int carry = 0;
		string res = "";
		while (Left >= 0 || Right >= 0){
			int a = Left >= 0 ? num1[Left--] - '0' : 0;
			int b = Right >= 0 ? num2[Right--] - '0' : 0;
			int sum = a + b + carry;
			res.insert(res.begin(), sum % 10 + '0');
			carry = sum / 10;
		}
		return carry ? '1' + res : res;
	}

	//字符串相乘
	string multiplyStrings(string num1, string num2) {
		int LSize = num1.size();
		int RSize = num2.size();

		/*if (LSize < RSize){
			swap(num1, num2);
			swap(LSize, RSize);
		}*/

};


void Test()
{
	Solution test;

	string s("abbcdcaefg");
	cout << s << endl;
	cout << test.reverseStringAll(s) << endl;
	cout << test.firstUniqChar(s) << endl;
	test.lastWordSize(s);

	string h("abc ddcba");
	cout << test.isPalindrome(h) << endl;

	string num1 = "1093";
	string num2 = "9017";
	cout << test.addStrings(num1, num2) << endl;

	string num3 = "5";
	string num4 = "2";
	cout << test.multiplyStrings(num3, num4) << endl;
	
}