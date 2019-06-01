#include "List.h"

//���������� 
// ��β��ͷ��ӡ������ (ѭ��)
void PrintListReverse(ListNode *first)
{
	ListNode *end = NULL;	// Ҫ��ӡ���ĺ�һ�����

	while (end != first) {
		ListNode *cur = first;

		// �ҵ�Ҫ��ӡ���
		while (cur->next != end) {
			cur = cur->next;
		}

		// Ҫ��ӡ�Ľ��
		printf("%d ", cur->data);

		end = cur;
	}
	printf("\n");
}
// ��β��ͷ��ӡ������ (�ݹ�)
void PrintListReverseRecursion(ListNode *first)
{
	if (first == NULL){
		return;
	}

	PrintListReverseRecursion(first->next);

	printf("%d ", first->data);
}


// ɾ��������ķ�β��㣬���ܱ������� 
void DeleteListNotTail(ListNode **ppFirst, ListNode *pos);

// �ڵ������ͷ���ǰ�����½ڵ㣬Ҫ���ܱ������� 
void InsertPosFront(ListNode *pos, DataType data);

// �õ�����ģ��ʵ��Լɪ�� 
ListNode* JosephCircle(ListNode **ppFirst, int M);

// ��ð������Ե������������ 
void BubbleSort(ListNode **ppFirst);

// ���ҵ�������м��㣬Ҫ��ֻ�ܱ���һ������ 
ListNode* FindMiddleNode(ListNode **ppFirst);

// ���ҵ�����ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 
ListNode* FindLastKNode(ListNode **ppFirst, int K);

// ����������� 
void ReverseList(ListNode **ppFirst);
ListNode* ReverseListOP(ListNode **ppFirst);

// �ϲ��������������ϲ��ɹ�����Ȼ���� 
ListNode* MergeList(ListNode **ppFirst1, ListNode **ppFirst2);

// ��ⵥ�����Ƿ���� 
ListNode* HasListCircle(ListNode **ppFirst);

// �󻷵ĳ��� 
int GetCircleLen(ListNode **ppFirst);

// �󻷵���ڵ� 
ListNode* GetEnterNode(ListNode **ppFirst, ListNode* pMeetNode);

// �ж������������Ƿ��ཻ(��������) 
int IsListCross(ListNode **ppFirst1, ListNode **ppFirst2);

// ���ཻ���󽻵� 
ListNode * GetCrossNode(ListNode **ppFirst1, ListNode **ppFirst2);

// ������������Ƿ��ཻ��������ܴ��� 
int IsListCrossWithCircle(ListNode **ppFirst1, ListNode **ppFirst2);

// ��������ĸ�ֵ 
ListNode * CopyComplex(ListNode **ppFirst);