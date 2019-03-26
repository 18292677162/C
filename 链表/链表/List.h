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

//��ʼ��
void ListInit(ListNode **ppFirst)
{
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}

//����
void ListDestroy(ListNode **ppFirst)
{
	*ppFirst = NULL;
}

//����һ������
static ListNode * CreateNode(DataType data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

//ͷ��
void ListPushFront(ListNode **ppFirst, DataType data)
{
	//�����������Ϊ��
	assert(ppFirst != NULL);

	//����������Ӷ�����ռ�
	//*ppFirst��ָ���һ�����ݵĵ�ַ,��data��next=*ppFirst�൱��ָ��ڶ������ݵĵ�ַ
	ListNode *newNode = CreateNode(data);
	newNode->next = *ppFirst;

	//���µ�*ppFirstָ��newNode
	*ppFirst = newNode;
}

//β��
void ListPushBack(ListNode **ppFirst, DataType data)
{
	ListNode *newNode = CreateNode(data);

	//����д������Ϊ��
	if (*ppFirst == NULL){
		*ppFirst = newNode;
		return;
	}

	//ͨ�����
	ListNode *cur = *ppFirst;
	while (cur->next != NULL){
		cur = cur->next;
	}

	//curΪ���һ���ڵ�
	cur->next = newNode;
}

//βɾ
void ListPopBack(ListNode **ppFirst)
{
	assert(ppFirst != NULL); //������ַ��Ϊ��
	assert(*ppFirst != NULL); //����Ϊ��

	//���ֻ��һ���ڵ�
	if ((*ppFirst)->next == NULL){
		free(*ppFirst); //malloc�Ŀռ�free
		*ppFirst = NULL;
		return;
	}

	//�������
	ListNode *del;
	ListNode *cur = *ppFirst;

	while (cur->next->next != NULL){
		cur = cur->next;
	}

	del = cur->next;
	cur->next = NULL;
	free(del);
}

//ͷɾ
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
	// ˳���������
	for (ListNode *cur = first; cur != NULL; cur = cur->next){
		if (data == cur->data){
			return cur;
		}
	}

	return NULL;
}

//��ָ��λ��ǰ����(pos�϶���������&&pos���ǿ�) 
void ListInsert(ListNode **ppFirst, ListNode *pos, DataType data)
{
	//�������--ͷ��
	if (*ppFirst == pos){
		ListPushFront(ppFirst, data);
		return;
	}

	//һ�����
	//��pos��ǰ�ڵ�
	ListNode *cur = *ppFirst;

	while (cur->next != pos){
		cur = cur->next;
	}
	
	//����
	ListNode *newNode = CreateNode(data);
	newNode->next = cur->next;
	cur->next = newNode;
}

//ָ��λ��ɾ�� (pos�϶���������&&pos���ǿ�) 
void ListErase(ListNode **ppFirst, ListNode *pos)
{
	//ͷɾ
	if (*ppFirst == pos){
		ListPopFront(ppFirst);
		return;
	}

	//һ�����
	//��pos��һ���ڵ�
	ListNode *cur = *ppFirst;
	while (cur->next != pos){
		cur = cur->next;
	}
	//ɾ��
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


