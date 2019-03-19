#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#include<stdio.h>
#include<windows.h>
int main()
{
	PSeqList seqList;
	InitSeqList(&seqList);

	printf("尾插:\n");
	PushBack(&seqList, 7);
	PushBack(&seqList, 8);
	PushBack(&seqList, 9);
	PrintSeqList(&seqList);

	printf("\n头插:\n");
	PushFront(&seqList, 3);
	PushFront(&seqList, 2);
	PushFront(&seqList, 1);
	PrintSeqList(&seqList);

	printf("\n指定位置插入:\n");
	Insert(&seqList, 3, 4);
	Insert(&seqList, 4, 5);
	Insert(&seqList, 5, 6);
	PrintSeqList(&seqList);

	printf("\n尾删:\n");
	PopBack(&seqList);
	PopBack(&seqList);
	PrintSeqList(&seqList);

	printf("\n头删:\n");
	PopFront(&seqList);
	PopFront(&seqList);
	PrintSeqList(&seqList);

	printf("\n删除下标为2的元素:\n");
	Erase(&seqList, 2);
	PrintSeqList(&seqList);

	printf("\n删除第一个遇到的6:\n");
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

	printf("\n删除所有遇到的6:\n");
	RemoveAll(&seqList, 6);
	PrintSeqList(&seqList);


	printf("\n冒泡排序:\n");
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