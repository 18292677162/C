#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#include<stdio.h>
#include<windows.h>
int main()
{
	PSeqList seqList;
	InitSeqList(&seqList);

	printf("β��:\n");
	PushBack(&seqList, 7);
	PushBack(&seqList, 8);
	PushBack(&seqList, 9);
	PrintSeqList(&seqList);

	printf("\nͷ��:\n");
	PushFront(&seqList, 3);
	PushFront(&seqList, 2);
	PushFront(&seqList, 1);
	PrintSeqList(&seqList);

	printf("\nָ��λ�ò���:\n");
	Insert(&seqList, 3, 4);
	Insert(&seqList, 4, 5);
	Insert(&seqList, 5, 6);
	PrintSeqList(&seqList);

	printf("\nβɾ:\n");
	PopBack(&seqList);
	PopBack(&seqList);
	PrintSeqList(&seqList);

	printf("\nͷɾ:\n");
	PopFront(&seqList);
	PopFront(&seqList);
	PrintSeqList(&seqList);

	printf("\nɾ���±�Ϊ2��Ԫ��:\n");
	Erase(&seqList, 2);
	PrintSeqList(&seqList);

	printf("\nɾ����һ��������6:\n");
	PushBack(&seqList, 3);
	PushBack(&seqList, 6);
	PushBack(&seqList, 3);
	PushBack(&seqList, 6);
	PushBack(&seqList, 6);
	PushBack(&seqList, 9);
	PrintSeqList(&seqList);
	printf("\n");
	Remove(&seqList, 6);
	PrintSeqList(&seqList);

	printf("\nɾ������������6:\n");
	RemoveAll(&seqList, 6);
	PrintSeqList(&seqList);


	printf("\nð������:\n");
	PushBack(&seqList, 1);
	PushBack(&seqList, 8);
	PushBack(&seqList, 2);
	PushBack(&seqList, 6);
	PrintSeqList(&seqList);
	printf("\n");
	BubbleSort(&seqList);
	PrintSeqList(&seqList);
	printf("\n");
	//SelectSort(&seqList);
	PrintSeqList(&seqList);

	printf("\n");
	system("pause");
	return 0;
}