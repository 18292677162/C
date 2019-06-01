#include "List.h"

//链表面试题 
// 从尾到头打印单链表 (循环)
void PrintListReverse(ListNode *first)
{
	ListNode *end = NULL;	// 要打印结点的后一个结点

	while (end != first) {
		ListNode *cur = first;

		// 找到要打印结点
		while (cur->next != end) {
			cur = cur->next;
		}

		// 要打印的结点
		printf("%d ", cur->data);

		end = cur;
	}
	printf("\n");
}
// 从尾到头打印单链表 (递归)
void PrintListReverseRecursion(ListNode *first)
{
	if (first == NULL){
		return;
	}

	PrintListReverseRecursion(first->next);

	printf("%d ", first->data);
}


// 删除单链表的非尾结点，不能遍历链表 
void DeleteListNotTail(ListNode **ppFirst, ListNode *pos);

// 在单链表非头结点前插入新节点，要求不能遍历链表 
void InsertPosFront(ListNode *pos, DataType data);

// 用单链表模拟实现约瑟夫环 
ListNode* JosephCircle(ListNode **ppFirst, int M);

// 用冒泡排序对单链表进行排序 
void BubbleSort(ListNode **ppFirst);

// 查找单链表的中间结点，要求只能遍历一次链表 
ListNode* FindMiddleNode(ListNode **ppFirst);

// 查找单链表的倒数第K个结点，要求只能遍历一次链表 
ListNode* FindLastKNode(ListNode **ppFirst, int K);

// 单链表的逆置 
void ReverseList(ListNode **ppFirst);
ListNode* ReverseListOP(ListNode **ppFirst);

// 合并两个有序链表，合并成功后依然有序 
ListNode* MergeList(ListNode **ppFirst1, ListNode **ppFirst2);

// 检测单链表是否带环 
ListNode* HasListCircle(ListNode **ppFirst);

// 求环的长度 
int GetCircleLen(ListNode **ppFirst);

// 求环的入口点 
ListNode* GetEnterNode(ListNode **ppFirst, ListNode* pMeetNode);

// 判断两个单链表是否相交(链表不带环) 
int IsListCross(ListNode **ppFirst1, ListNode **ppFirst2);

// 若相交，求交点 
ListNode * GetCrossNode(ListNode **ppFirst1, ListNode **ppFirst2);

// 检测两个链表是否相交，链表可能带环 
int IsListCrossWithCircle(ListNode **ppFirst1, ListNode **ppFirst2);

// 复杂链表的赋值 
ListNode * CopyComplex(ListNode **ppFirst);