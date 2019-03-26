#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

/*
双向
循环
带头
*/

typedef struct DListNode {
	struct DListNode *prev;
	struct DListNode *next;
	DataType data;
}	DListNode;

void DListInit(DListNode **ppHead)
{
	assert(ppHead != NULL);
	DListNode *pHead = (DListNode *)malloc(sizeof(DListNode));

	pHead->next = pHead;
	pHead->prev = pHead;

	*ppHead = pHead;
}

//保留头结点
void DListClear(DListNode *pHead)
{
	DListNode *cur = pHead->next;
	DListNode *next;
	while (cur != pHead){
		next = cur->next;
		pHead->next = next;
		next->prev = pHead;
		free(cur);
		cur = pHead->next;
	}

	pHead->next = pHead;
	pHead->prev = pHead;
}

//销毁头结点
void DListDestroy(DListNode **ppHead)
{
	DListClear(*ppHead);
	free(*ppHead);
	*ppHead = NULL;
}

// 任意位置插入 
void DListInsert(DListNode *pHead, DListNode *pos, DataType data)
{
	DListNode *node = (DListNode *)malloc(sizeof(DListNode));
	node->data = data;

	node->prev = pos->prev;
	node->next = pos;

	pos->prev->next = node;
	pos->prev = node;
}

// 双向链表的尾插 
void DListPushBack(DListNode *pHead, DataType data)
{
	DListInsert(pHead, pHead, data);
}

// 双向链表的头插 
void DListPushFront(DListNode* pHead, DataType data)
{
	DListInsert(pHead, pHead, data);
}

// 任意位置删除 
void DListErase(DListNode *pHead, DListNode *pos)
{
	//pos非头
	assert(pos != pHead);

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

// 双向链表的尾删 
void DListPopBack(DListNode *pHead)
{
	DListErase(pHead, pHead->prev);
}

// 双向链表的头删 
void DListPopFront(DListNode* pHead)
{
	DListErase(pHead, pHead->next);
}

// 查找值为data的结点 
DListNode *DListFind(DListNode *pHead, DataType data)
{
	for (DListNode *cur = pHead; cur != NULL; cur = cur->next){
		if (data == cur->data){
			return cur;
		}
	}
	return NULL;
}

void DListPrint(DListNode *pHead)
{
	assert(pHead != NULL);
		for (DListNode *cur = pHead; cur->next != pHead; cur = cur->next){
		printf("%d ", cur->next->data);
	}
	printf("Head\n");
}

DlistTest()
{
	ListNode *pHead;
	DListInit(&pHead);
	DListPrint(pHead);

	DListPushBack(pHead, 1);
	DListPushBack(pHead, 2);
	DListPushBack(pHead, 3);
	DListPushBack(pHead, 4);
	DListPrint(pHead);
	DListPushFront(pHead, 5);
	DListPushFront(pHead, 6);
	DListPushFront(pHead, 7);
	DListPushFront(pHead, 8);
	DListPrint(pHead);

	DListPopFront(pHead);
	DListPopBack(pHead);
	DListPrint(pHead);

	DListNode *result = DListFind(pHead, 5);
	DListErase(pHead, result);
	DListPrint(pHead);
	result = DListFind(pHead, 6);
	DListInsert(pHead, result, 0);
	DListPrint(pHead);

	DListClear(pHead);
	DListPrint(pHead);
	DListDestroy(&pHead);

}