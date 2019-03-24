#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode{
	struct ListNode *next;
	DataType data;
}	ListNode;

void ListInit(ListNode **ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}
ListNode BuyNode(DataType d);
void ListDestroy(ListNode* ppFirst);
void ListPushBack(ListNode* ppFirst, DataType d);
void ListPopBack(ListNode* ppFirst);
void ListPushFront(ListNode* ppFirst, DataType d);
void ListPopFront(ListNode* ppFirst);
ListNode Find(ListNode ppFirst, DataType d);

//��ָ��λ��֮ǰ����һ��ֵ 
void Insert(ListNode* ppFirst, ListNode pos, DataType d);
//ָ��λ��ɾ�� 
void ListErase(ListNode* ppFirst, ListNode pos);
void ListRemove(ListNode* ppFirst, DataType d);
void ListRemoveAll(ListNode* ppFirst, DataType d);
void ListEraseNotTailNode(ListNode pos);
void ListPrint(ListNode ppFirst);
int GetListLength(ListNode ppFirst);
//���������� 

//1. �����ӡ�������� 
void PrintTailToHead(ListNode ppFirst);