#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>

using namespace std;

//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型

class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (0 == stack2.size()){
			while (stack1.size() > 0){
				int data = stack1.top();
				stack1.pop();
				stack2.push(data);
			}
		}
		if (0 == stack2.size()){
			throw ("queue is empty");
		}
		int head = stack2.top();
		stack2.pop();

		return head;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Solution s;
	s.push(1);
	s.push(2);
	s.push(5);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	system("pause");
	return 0;
}