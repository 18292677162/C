#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

/*
˫��
ѭ��
��ͷ
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

//����ͷ���
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

//����ͷ���
void DListDestroy(DListNode **ppHead)
{
	DListClear(*ppHead);
	free(*ppHead);
	*ppHead = NULL;
}

// ����λ�ò��� 
void DListInsert(DListNode *pHead, DListNode *pos, DataType data)
{
	DListNode *node = (DListNode *)malloc(sizeof(DListNode));
	node->data = data;

	node->prev = pos->prev;
	node->next = pos;

	pos->prev->next = node;
	pos->prev = node;
}

// ˫�������β�� 
void DListPushBack(DListNode *pHead, DataType data)
{
	DListInsert(pHead, pHead, data);
}

// ˫�������ͷ�� 
void DListPushFront(DListNode* pHead, DataType data)
{
	DListInsert(pHead, pHead, data);
}

// ����λ��ɾ�� 
void DListErase(DListNode *pHead, DListNode *pos)
{
	//pos��ͷ
	assert(pos != pHead);

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

// ˫�������βɾ 
void DListPopBack(DListNode *pHead)
{
	DListErase(pHead, pHead->prev);
}

// ˫�������ͷɾ 
void DListPopFront(DListNode* pHead)
{
	DListErase(pHead, pHead->next);
}

// ����ֵΪdata�Ľ�� 
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