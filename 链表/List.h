#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode{
	struct ListNode *next;
	DataType data;
}	ListNode;

//初始化
void ListInit(ListNode **ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

//销毁
void ListDestroy(ListNode **ppFirst)
{
	*ppFirst = NULL;
}

//增加一个链表
static ListNode * CreateNode(DataType data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

//头插
void ListPushFront(ListNode **ppFirst, DataType data)
{
	//特殊情况链表为空
	assert(ppFirst != NULL);

	//正常情况，从堆申请空间
	//*ppFirst是指向第一个数据的地址,让data的next=*ppFirst相当于指向第二个数据的地址
	ListNode *newNode = CreateNode(data);
	newNode->next = *ppFirst;

	//让新的*ppFirst指向newNode
	*ppFirst = newNode;
}

//尾插
void ListPushBack(ListNode **ppFirst, DataType data)
{
	ListNode *newNode = CreateNode(data);

	//特殊写法链表为空
	if (*ppFirst == NULL){
		*ppFirst = newNode;
		return;
	}

	//通常情况
	ListNode *cur = *ppFirst;
	while (cur->next != NULL){
		cur = cur->next;
	}

	//cur为最后一个节点
	cur->next = newNode;
}

//尾删
void ListPopBack(ListNode **ppFirst)
{
	assert(ppFirst != NULL); //变量地址不为空
	assert(*ppFirst != NULL); //链表不为空

	//如果只有一个节点
	if ((*ppFirst)->next == NULL){
		free(*ppFirst); //malloc的空间free
		*ppFirst = NULL;
		return;
	}

	//正常情况
	ListNode *del;
	ListNode *cur = *ppFirst;

	while (cur->next->next != NULL){
		cur = cur->next;
	}

	del = cur->next;
	cur->next = NULL;
	free(del);
}

//头删
void ListPopFront(ListNode **ppFirst)
{
	assert(ppFirst != NULL);
	assert(*ppFirst != NULL);

	ListNode *del = *ppFirst;
	*ppFirst = del->next;

	free(del);
}

ListNode *ListFind(ListNode *first, DataType data)
{
	// 顺序遍历查找
	for (ListNode *cur = first; cur != NULL; cur = cur->next){
		if (data == cur->data){
			return cur;
		}
	}

	return NULL;
}

//在指定位置前插入(pos肯定在链表中&&pos不是空) 
void ListInsert(ListNode **ppFirst, ListNode *pos, DataType data)
{
	//特殊情况--头插
	if (*ppFirst == pos){
		ListPushFront(ppFirst, data);
		return;
	}

	//一般情况
	//找pos的前节点
	ListNode *cur = *ppFirst;

	while (cur->next != pos){
		cur = cur->next;
	}
	
	//插入
	ListNode *newNode = CreateNode(data);
	newNode->next = cur->next;
	cur->next = newNode;
}

//指定位置删除 (pos肯定在链表中&&pos不是空) 
void ListErase(ListNode **ppFirst, ListNode *pos)
{
	//头删
	if (*ppFirst == pos){
		ListPopFront(ppFirst);
		return;
	}

	//一般情况
	//找pos上一个节点
	ListNode *cur = *ppFirst;
	while (cur->next != pos){
		cur = cur->next;
	}
	//删除
	cur->next = pos->next;
	free(pos);
}

void ListPrint(ListNode **first)
{
	for (ListNode *cur = *first; cur != NULL; cur = cur->next){
		printf("%d ", cur->data);
	}
	printf("NULL\n");
}

int GetListLength(ListNode **ppFirst)
{
	assert(ppFirst != NULL);
	if (*ppFirst == NULL){
		return 0;
	}

	int n = 1;
	ListNode *cur = *ppFirst;
	while (cur->next != NULL){
		cur = cur->next;
		n++;
	}
	return n;
}


