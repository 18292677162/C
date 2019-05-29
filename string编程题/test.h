#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	//��ת�ַ���
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

	//���䲿�ַ�ת
	string reverseStringK(string s, int k) {

	}

	//��ת�ַ����еĵ���
	string reverseWords(string s) {

	}

	//���ַ����е�һ��ֻ����һ�ε��ַ�
	int firstUniqChar(string s){
		//�ռ任ʱ��
		//����һ����ϣ���ⲿ�ռ䣩�����ֵ��Key�����ַ�����ֵ��Value���Ǹ��ַ����ֵĴ���
		//����ģ��
		//ͳ��ÿ���ַ������ִ�����һ��char=8bit ����256�ֿ���
		int count[256] = { 0 };
		int size = s.size();
		for (int i = 0; i < size; i++){
			count[s[i]] += 1;
		}

		//��������
		for (int i = 0; i < size; i++){
			if (1 == count[s[i]]){
				return i;
			}
		}
		return -1;
	}

	//�ַ����������һ�����ʵĳ���
	int lastWordSize(string s){
		size_t pos = s.rfind(' ');
		cout << s.size() - pos - 1 << endl;
		return 0;
	}

	//��֤һ���ַ����Ƿ��ǻ���
	bool isPalindrome(string s){
		if (s.empty()){
			return true;
		}

		int begin = 0;
		int end = s.size() - 1;

		char* p = (char*)s.c_str();
		while (begin != end&&begin < end){
			//��ǰ������һ�����ֻ���ĸ
			while (begin < end){
				if (isNumberOrLetter(s[begin])){
					break;
				}
				begin++;
			}

			//�Ӻ���ǰ��һ�����ֻ���ĸ
			while (begin < end){
				if (isNumberOrLetter(s[end])){
					break;
				}
				end--;
			}

			if (begin < end){
				//start��end�ַ��Ƿ���� || �����ִ�С�����  ��ֹ0��
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

	//�ַ������  '0'��ASCII��Ϊ48, '1'Ϊ49  s[i]-'0'��ʵ�ʾ��ǽ������ַ�ת��Ϊ��������
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

	//�ַ������
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