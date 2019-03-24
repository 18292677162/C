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

//在指定位置之前插入一个值 
void Insert(ListNode* ppFirst, ListNode pos, DataType d);
//指定位置删除 
void ListErase(ListNode* ppFirst, ListNode pos);
void ListRemove(ListNode* ppFirst, DataType d);
void ListRemoveAll(ListNode* ppFirst, DataType d);
void ListEraseNotTailNode(ListNode pos);
void ListPrint(ListNode ppFirst);
int GetListLength(ListNode ppFirst);
//链表面试题 

//1. 逆序打印单项链表 
void PrintTailToHead(ListNode ppFirst);