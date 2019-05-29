#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

struct ListNode {
	int val;
	struct ListNode *next;
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		/*
		·ÇµÝ¹é
		vector<int> out;
		stack<ListNode*> nodes;
		ListNode* pNode = head;
		while (pNode != NULL){
			nodes.push(pNode);
			pNode = pNode->next;
		}
		while (!nodes.empty()){
			pNode = nodes.top();
			out.push_back(pNode->val);
			nodes.pop();
		}
		*/

		//µÝ¹é
		if (head != NULL){
			if (head->next != NULL){
				printListFromTailToHead(head->next);
			}
			printf("%d ", head->val);
		}
		/*
		vector<int> out;
		vector<int> printListFromTailToHead(ListNode* head) {
		if (head != NULL){
		if (head->next != NULL){
		printListFromTailToHead(head->next);
		}
		out.push_back(head->val)
		}
		return out;
		}
		*/
	}
};

int main()
{
	system("pause");
	return 0;
}