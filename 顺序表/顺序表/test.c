#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#include<windows.h>
int main()
{
	PSeqList seqList;
	SeqListInit(&seqList);

	printf("尾插:\n");
	SeqListPushBack(&seqList, 7);
	SeqListPushBack(&seqList, 8);
	SeqListPushBack(&seqList, 9);
	SeqListPrint(&seqList);

	printf("\n头插:\n");
	SeqListPushFront(&seqList, 3);
	SeqListPushFront(&seqList, 2);
	SeqListPushFront(&seqList, 1);
	SeqListPrint(&seqList);

	printf("\n指定位置插入:\n");
	SeqListInsert(&seqList, 3, 4);
	SeqListPrint(&seqList);

	printf("\n尾删:\n");
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPrint(&seqList);

	printf("\n头删:\n");
	SeqListPopFront(&seqList);
	SeqListPrint(&seqList);

	printf("\n删除下标为2的元素:\n");
	SeqListErase(&seqList, 2);
	SeqListPrint(&seqList);

	printf("\n删除第一个遇到的6:\n");
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 9);
	SeqListPrint(&seqList);
	printf("\n");
	SeqListRemove(&seqList, 6);
	SeqListPrint(&seqList);

	printf("\n删除所有遇到的6:\n");
	SeqListRemoveAll(&seqList, 6);
	SeqListPrint(&seqList);


	//printf("\n冒泡排序:\n");
	//SeqListPushBack(&seqList, 1);
	//SeqListPushBack(&seqList, 8);
	//SeqListPushBack(&seqList, 2);
	//SeqListPushBack(&seqList, 6);
	//SeqListPrint(&seqList);
	////BubbleSort(&seqList);
	//SeqListPrint(&seqList);
	//printf("\n选择排序:\n");
	//SelectSort(&seqList);
	//SeqListPrint(&seqList);
	//SelectSortOP(&seqList);

	printf("\n");
	system("pause");
	return 0;
}